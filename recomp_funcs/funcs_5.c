#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80041C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041C54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041C5C: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x80041C60: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80041C64: lhu         $a2, 0xA($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0XA);
    // 0x80041C68: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80041C6C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80041C70: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80041C74: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80041C78: lhu         $v1, 0x1200($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X1200);
    // 0x80041C7C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80041C80: subu        $t9, $v1, $a2
    ctx->r25 = SUB32(ctx->r3, ctx->r6);
    // 0x80041C84: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80041C88: beq         $at, $zero, L_80041C98
    if (ctx->r1 == 0) {
        // 0x80041C8C: addiu       $a1, $v1, -0x2
        ctx->r5 = ADD32(ctx->r3, -0X2);
            goto L_80041C98;
    }
    // 0x80041C8C: addiu       $a1, $v1, -0x2
    ctx->r5 = ADD32(ctx->r3, -0X2);
    // 0x80041C90: b           L_80041C9C
    // 0x80041C94: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
        goto L_80041C9C;
    // 0x80041C94: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
L_80041C98:
    // 0x80041C98: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_80041C9C:
    // 0x80041C9C: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80041CA0: bne         $at, $zero, L_80041CB4
    if (ctx->r1 != 0) {
        // 0x80041CA4: nop
    
            goto L_80041CB4;
    }
    // 0x80041CA4: nop

    // 0x80041CA8: lbu         $t0, 0x1202($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1202);
    // 0x80041CAC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80041CB0: sb          $t1, 0x1202($v0)
    MEM_B(0X1202, ctx->r2) = ctx->r9;
L_80041CB4:
    // 0x80041CB4: jal         0x80041914
    // 0x80041CB8: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    func_80041914(rdram, ctx);
        goto after_0;
    // 0x80041CB8: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    after_0:
    // 0x80041CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041CC4: jr          $ra
    // 0x80041CC8: nop

    return;
    // 0x80041CC8: nop

;}
RECOMP_FUNC void func_804C3B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3B7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C3B80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804C3B84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804C3B88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804C3B8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C3B90: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C3B94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C3B98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C3B9C: jal         0x8004921C
    // 0x804C3BA0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804C3BA0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x804C3BA4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x804C3BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C3BAC: jal         0x8004921C
    // 0x804C3BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804C3BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804C3BB4: bgez        $s2, L_804C3BC4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x804C3BB8: sra         $t2, $s2, 1
        ctx->r10 = S32(SIGNED(ctx->r18) >> 1);
            goto L_804C3BC4;
    }
    // 0x804C3BB8: sra         $t2, $s2, 1
    ctx->r10 = S32(SIGNED(ctx->r18) >> 1);
    // 0x804C3BBC: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x804C3BC0: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_804C3BC4:
    // 0x804C3BC4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804C3BC8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x804C3BCC: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x804C3BD0: sll         $t4, $s2, 6
    ctx->r12 = S32(ctx->r18 << 6);
    // 0x804C3BD4: addiu       $s0, $v0, -0x6
    ctx->r16 = ADD32(ctx->r2, -0X6);
    // 0x804C3BD8: addiu       $v1, $v1, 0x308
    ctx->r3 = ADD32(ctx->r3, 0X308);
    // 0x804C3BDC: addiu       $t0, $v1, 0x30
    ctx->r8 = ADD32(ctx->r3, 0X30);
    // 0x804C3BE0: addiu       $s2, $zero, 0x600
    ctx->r18 = ADD32(0, 0X600);
    // 0x804C3BE4: sll         $t5, $t5, 6
    ctx->r13 = S32(ctx->r13 << 6);
    // 0x804C3BE8: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x804C3BEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804C3BF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C3BF4: bgez        $v0, L_804C3C04
    if (SIGNED(ctx->r2) >= 0) {
        // 0x804C3BF8: sra         $ra, $v0, 1
        ctx->r31 = S32(SIGNED(ctx->r2) >> 1);
            goto L_804C3C04;
    }
    // 0x804C3BF8: sra         $ra, $v0, 1
    ctx->r31 = S32(SIGNED(ctx->r2) >> 1);
    // 0x804C3BFC: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x804C3C00: sra         $ra, $at, 1
    ctx->r31 = S32(SIGNED(ctx->r1) >> 1);
L_804C3C04:
    // 0x804C3C04: negu        $s1, $ra
    ctx->r17 = SUB32(0, ctx->r31);
    // 0x804C3C08: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804C3C0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_804C3C10:
    // 0x804C3C10: addu        $a1, $s1, $a2
    ctx->r5 = ADD32(ctx->r17, ctx->r6);
    // 0x804C3C14: addu        $t1, $ra, $a2
    ctx->r9 = ADD32(ctx->r31, ctx->r6);
    // 0x804C3C18: sh          $a1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r5;
    // 0x804C3C1C: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x804C3C20: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804C3C24: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x804C3C28: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x804C3C2C: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x804C3C30: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x804C3C34: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x804C3C38: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x804C3C3C: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x804C3C40: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
    // 0x804C3C44: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    // 0x804C3C48: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x804C3C4C: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x804C3C50: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x804C3C54: sh          $t5, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r13;
    // 0x804C3C58: sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // 0x804C3C5C: sb          $v0, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r2;
    // 0x804C3C60: sb          $v0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r2;
    // 0x804C3C64: sb          $v0, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r2;
    // 0x804C3C68: sh          $a1, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r5;
    // 0x804C3C6C: sh          $t2, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r10;
    // 0x804C3C70: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x804C3C74: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x804C3C78: sh          $t4, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r12;
    // 0x804C3C7C: sh          $zero, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = 0;
    // 0x804C3C80: sb          $v0, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = ctx->r2;
    // 0x804C3C84: sb          $v0, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r2;
    // 0x804C3C88: sb          $v0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r2;
    // 0x804C3C8C: sb          $v0, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r2;
    // 0x804C3C90: sh          $t2, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r10;
    // 0x804C3C94: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x804C3C98: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x804C3C9C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x804C3CA0: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x804C3CA4: sb          $v0, -0x31($t0)
    MEM_B(-0X31, ctx->r8) = ctx->r2;
    // 0x804C3CA8: sb          $v0, -0x32($t0)
    MEM_B(-0X32, ctx->r8) = ctx->r2;
    // 0x804C3CAC: sb          $v0, -0x33($t0)
    MEM_B(-0X33, ctx->r8) = ctx->r2;
    // 0x804C3CB0: sb          $v0, -0x34($t0)
    MEM_B(-0X34, ctx->r8) = ctx->r2;
    // 0x804C3CB4: sh          $t5, -0x36($t0)
    MEM_H(-0X36, ctx->r8) = ctx->r13;
    // 0x804C3CB8: sh          $t4, -0x38($t0)
    MEM_H(-0X38, ctx->r8) = ctx->r12;
    // 0x804C3CBC: sh          $zero, -0x3A($t0)
    MEM_H(-0X3A, ctx->r8) = 0;
    // 0x804C3CC0: sh          $zero, -0x3C($t0)
    MEM_H(-0X3C, ctx->r8) = 0;
    // 0x804C3CC4: bne         $a3, $s2, L_804C3C10
    if (ctx->r7 != ctx->r18) {
        // 0x804C3CC8: sh          $t1, -0x3E($t0)
        MEM_H(-0X3E, ctx->r8) = ctx->r9;
            goto L_804C3C10;
    }
    // 0x804C3CC8: sh          $t1, -0x3E($t0)
    MEM_H(-0X3E, ctx->r8) = ctx->r9;
    // 0x804C3CCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804C3CD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C3CD4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804C3CD8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804C3CDC: jr          $ra
    // 0x804C3CE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804C3CE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8056337C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056337C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80563380: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80563384: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80563388: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8056338C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80563390: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80563394: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80563398: lwc1        $f6, 0x724($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X724);
    // 0x8056339C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x805633A0: nop

    // 0x805633A4: bc1tl       L_805633B8
    if (c1cs) {
        // 0x805633A8: lw          $t9, 0x878($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X878);
            goto L_805633B8;
    }
    goto skip_0;
    // 0x805633A8: lw          $t9, 0x878($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X878);
    skip_0:
    // 0x805633AC: jal         0x805614FC
    // 0x805633B0: nop

    func_805614FC(rdram, ctx);
        goto after_0;
    // 0x805633B0: nop

    after_0:
    // 0x805633B4: lw          $t9, 0x878($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X878);
L_805633B8:
    // 0x805633B8: lw          $t6, 0x710($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X710);
    // 0x805633BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805633C0: jalr        $t9
    // 0x805633C4: sw          $t6, 0x714($s0)
    MEM_W(0X714, ctx->r16) = ctx->r14;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805633C4: sw          $t6, 0x714($s0)
    MEM_W(0X714, ctx->r16) = ctx->r14;
    after_1:
    // 0x805633C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x805633CC: lwc1        $f10, 0x724($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X724);
    // 0x805633D0: sw          $v0, 0x710($s0)
    MEM_W(0X710, ctx->r16) = ctx->r2;
    // 0x805633D4: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x805633D8: nop

    // 0x805633DC: bc1tl       L_8056341C
    if (c1cs) {
        // 0x805633E0: lwc1        $f2, 0x71C($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X71C);
            goto L_8056341C;
    }
    goto skip_1;
    // 0x805633E0: lwc1        $f2, 0x71C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X71C);
    skip_1:
    // 0x805633E4: lw          $t7, 0x708($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X708);
    // 0x805633E8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x805633EC: sw          $t8, 0x708($s0)
    MEM_W(0X708, ctx->r16) = ctx->r24;
    // 0x805633F0: bgez        $t8, L_80563400
    if (SIGNED(ctx->r24) >= 0) {
        // 0x805633F4: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80563400;
    }
    // 0x805633F4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x805633F8: addiu       $v1, $t8, 0xD8
    ctx->r3 = ADD32(ctx->r24, 0XD8);
    // 0x805633FC: sw          $v1, 0x708($s0)
    MEM_W(0X708, ctx->r16) = ctx->r3;
L_80563400:
    // 0x80563400: lwc1        $f16, 0x3C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80563404: sll         $t1, $v1, 3
    ctx->r9 = S32(ctx->r3 << 3);
    // 0x80563408: addu        $v0, $s0, $t1
    ctx->r2 = ADD32(ctx->r16, ctx->r9);
    // 0x8056340C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80563410: lwc1        $f18, 0x40($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80563414: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80563418: lwc1        $f2, 0x71C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X71C);
L_8056341C:
    // 0x8056341C: lwc1        $f0, 0x718($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X718);
    // 0x80563420: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80563424: nop

    // 0x80563428: bc1tl       L_8056349C
    if (c1cs) {
        // 0x8056342C: lw          $t2, 0x710($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X710);
            goto L_8056349C;
    }
    goto skip_2;
    // 0x8056342C: lw          $t2, 0x710($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X710);
    skip_2:
    // 0x80563430: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80563434: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80563438: bc1fl       L_80563474
    if (!c1cs) {
        // 0x8056343C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80563474;
    }
    goto skip_3;
    // 0x8056343C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_3:
    // 0x80563440: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80563444: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80563448: nop

    // 0x8056344C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80563450: swc1        $f6, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f6.u32l;
    // 0x80563454: lwc1        $f8, 0x718($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X718);
    // 0x80563458: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8056345C: nop

    // 0x80563460: bc1fl       L_8056349C
    if (!c1cs) {
        // 0x80563464: lw          $t2, 0x710($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X710);
            goto L_8056349C;
    }
    goto skip_4;
    // 0x80563464: lw          $t2, 0x710($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X710);
    skip_4:
    // 0x80563468: b           L_80563498
    // 0x8056346C: swc1        $f2, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f2.u32l;
        goto L_80563498;
    // 0x8056346C: swc1        $f2, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f2.u32l;
    // 0x80563470: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80563474:
    // 0x80563474: nop

    // 0x80563478: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8056347C: swc1        $f16, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f16.u32l;
    // 0x80563480: lwc1        $f18, 0x718($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X718);
    // 0x80563484: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80563488: nop

    // 0x8056348C: bc1fl       L_8056349C
    if (!c1cs) {
        // 0x80563490: lw          $t2, 0x710($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X710);
            goto L_8056349C;
    }
    goto skip_5;
    // 0x80563490: lw          $t2, 0x710($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X710);
    skip_5:
    // 0x80563494: swc1        $f2, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f2.u32l;
L_80563498:
    // 0x80563498: lw          $t2, 0x710($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X710);
L_8056349C:
    // 0x8056349C: beq         $t2, $zero, L_805634FC
    if (ctx->r10 == 0) {
        // 0x805634A0: nop
    
            goto L_805634FC;
    }
    // 0x805634A0: nop

    // 0x805634A4: lw          $t3, 0x714($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X714);
    // 0x805634A8: bne         $t3, $zero, L_805634FC
    if (ctx->r11 != 0) {
        // 0x805634AC: nop
    
            goto L_805634FC;
    }
    // 0x805634AC: nop

    // 0x805634B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805634B4: lwc1        $f6, 0x724($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X724);
    // 0x805634B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805634BC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x805634C0: nop

    // 0x805634C4: bc1tl       L_805634F4
    if (c1cs) {
        // 0x805634C8: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_805634F4;
    }
    goto skip_6;
    // 0x805634C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_6:
    // 0x805634CC: lw          $t4, 0x70C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X70C);
    // 0x805634D0: lw          $t6, 0x720($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X720);
    // 0x805634D4: xori        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 ^ 0X1;
    // 0x805634D8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x805634DC: sw          $t5, 0x70C($s0)
    MEM_W(0X70C, ctx->r16) = ctx->r13;
    // 0x805634E0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x805634E4: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x805634E8: b           L_805634FC
    // 0x805634EC: swc1        $f8, 0x71C($s0)
    MEM_W(0X71C, ctx->r16) = ctx->f8.u32l;
        goto L_805634FC;
    // 0x805634EC: swc1        $f8, 0x71C($s0)
    MEM_W(0X71C, ctx->r16) = ctx->f8.u32l;
    // 0x805634F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_805634F4:
    // 0x805634F4: nop

    // 0x805634F8: swc1        $f10, 0x724($s0)
    MEM_W(0X724, ctx->r16) = ctx->f10.u32l;
L_805634FC:
    // 0x805634FC: jal         0x80066E88
    // 0x80563500: lwc1        $f12, 0x718($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X718);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80563500: lwc1        $f12, 0x718($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X718);
    after_2:
    // 0x80563504: lwc1        $f16, 0x724($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X724);
    // 0x80563508: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8056350C: swc1        $f18, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f18.u32l;
    // 0x80563510: jal         0x80066DE4
    // 0x80563514: lwc1        $f12, 0x718($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X718);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80563514: lwc1        $f12, 0x718($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X718);
    after_3:
    // 0x80563518: lwc1        $f6, 0x724($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X724);
    // 0x8056351C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80563520: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80563524: swc1        $f8, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
    // 0x80563528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8056352C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80563530: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80563534: jr          $ra
    // 0x80563538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80563538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8040B6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B6F0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8040B6F4: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8040B6F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8040B6FC: beql        $t6, $zero, L_8040B720
    if (ctx->r14 == 0) {
        // 0x8040B700: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8040B720;
    }
    goto skip_0;
    // 0x8040B700: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x8040B704: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8040B708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040B70C: nop

    // 0x8040B710: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8040B714: jr          $ra
    // 0x8040B718: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8040B718: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8040B71C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8040B720:
    // 0x8040B720: nop

    // 0x8040B724: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8040B728: nop

    // 0x8040B72C: jr          $ra
    // 0x8040B730: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8040B730: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_8007C6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C6F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007C6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C6F8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007C6FC: jal         0x800825F0
    // 0x8007C700: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8007C700: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8007C704: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007C708: jal         0x8008B210
    // 0x8007C70C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadPri_recomp(rdram, ctx);
        goto after_1;
    // 0x8007C70C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8007C710: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8007C714: jal         0x80086880
    // 0x8007C718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_2;
    // 0x8007C718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8007C71C: jal         0x8008B920
    // 0x8007C720: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x8007C720: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_3:
    // 0x8007C724: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8007C728: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8007C72C: addiu       $t8, $t8, -0x1C60
    ctx->r24 = ADD32(ctx->r24, -0X1C60);
    // 0x8007C730: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007C734: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007C738: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007C73C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8007C740: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8007C744: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8007C748: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8007C74C: jal         0x8008B210
    // 0x8007C750: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    osGetThreadPri_recomp(rdram, ctx);
        goto after_4;
    // 0x8007C750: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x8007C754: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007C758: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007C75C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8007C760: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007C764: beq         $at, $zero, L_8007C824
    if (ctx->r1 == 0) {
        // 0x8007C768: sll         $t1, $t0, 3
        ctx->r9 = S32(ctx->r8 << 3);
            goto L_8007C824;
    }
    // 0x8007C768: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8007C76C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8007C770: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8007C774: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8007C778: addiu       $t2, $t2, -0x1C60
    ctx->r10 = ADD32(ctx->r10, -0X1C60);
    // 0x8007C77C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007C780: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C784: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8007C788: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8007C78C: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
    // 0x8007C790: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x8007C794: sw          $t5, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r13;
    // 0x8007C798: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8007C79C: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x8007C7A0: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8007C7A4: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8007C7A8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8007C7AC: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8007C7B0: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x8007C7B4: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x8007C7B8: addu        $t0, $at, $t6
    ctx->r8 = ADD32(ctx->r1, ctx->r14);
    // 0x8007C7BC: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8007C7C0: subu        $t4, $t0, $t2
    ctx->r12 = SUB32(ctx->r8, ctx->r10);
    // 0x8007C7C4: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x8007C7C8: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x8007C7CC: sw          $t4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r12;
    // 0x8007C7D0: subu        $t5, $t1, $t3
    ctx->r13 = SUB32(ctx->r9, ctx->r11);
    // 0x8007C7D4: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x8007C7D8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8007C7DC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007C7E0: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8007C7E4: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8007C7E8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C7EC: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8007C7F0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8007C7F4: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
    // 0x8007C7F8: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x8007C7FC: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8007C800: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x8007C804: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8007C808: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x8007C80C: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8007C810: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x8007C814: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    // 0x8007C818: addiu       $t4, $t4, -0x65F0
    ctx->r12 = ADD32(ctx->r12, -0X65F0);
    // 0x8007C81C: b           L_8007C82C
    // 0x8007C820: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
        goto L_8007C82C;
    // 0x8007C820: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
L_8007C824:
    // 0x8007C824: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8007C828: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
L_8007C82C:
    // 0x8007C82C: jal         0x800825F0
    // 0x8007C830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    osSetIntMask_recomp(rdram, ctx);
        goto after_5;
    // 0x8007C830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8007C834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C838: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007C83C: jr          $ra
    // 0x8007C840: nop

    return;
    // 0x8007C840: nop

;}
RECOMP_FUNC void func_8006CDF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CDF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006CDF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CDFC: jal         0x8004700C
    // 0x8006CE00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8006CE00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006CE04: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8006CE08: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8006CE0C: lw          $t7, 0x68($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X68);
    // 0x8006CE10: beq         $v0, $zero, L_8006CE94
    if (ctx->r2 == 0) {
        // 0x8006CE14: sw          $t7, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r15;
            goto L_8006CE94;
    }
    // 0x8006CE14: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8006CE18: lbu         $t8, 0x18($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18);
    // 0x8006CE1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006CE20: addiu       $a1, $a3, 0xC4
    ctx->r5 = ADD32(ctx->r7, 0XC4);
    // 0x8006CE24: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x8006CE28: bnel        $at, $zero, L_8006CE44
    if (ctx->r1 != 0) {
        // 0x8006CE2C: lh          $a2, 0x13E($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X13E);
            goto L_8006CE44;
    }
    goto skip_0;
    // 0x8006CE2C: lh          $a2, 0x13E($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X13E);
    skip_0:
    // 0x8006CE30: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
    // 0x8006CE34: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8006CE38: beq         $t9, $at, L_8006CE94
    if (ctx->r25 == ctx->r1) {
        // 0x8006CE3C: nop
    
            goto L_8006CE94;
    }
    // 0x8006CE3C: nop

    // 0x8006CE40: lh          $a2, 0x13E($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X13E);
L_8006CE44:
    // 0x8006CE44: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8006CE48: jal         0x800475EC
    // 0x8006CE4C: addiu       $a2, $a2, 0xF0
    ctx->r6 = ADD32(ctx->r6, 0XF0);
    func_800475EC(rdram, ctx);
        goto after_1;
    // 0x8006CE4C: addiu       $a2, $a2, 0xF0
    ctx->r6 = ADD32(ctx->r6, 0XF0);
    after_1:
    // 0x8006CE50: beq         $v0, $zero, L_8006CE94
    if (ctx->r2 == 0) {
        // 0x8006CE54: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_8006CE94;
    }
    // 0x8006CE54: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CE58: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8006CE5C: lbu         $t0, -0x7204($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X7204);
    // 0x8006CE60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CE64: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006CE68: bne         $t0, $at, L_8006CE94
    if (ctx->r8 != ctx->r1) {
        // 0x8006CE6C: nop
    
            goto L_8006CE94;
    }
    // 0x8006CE6C: nop

    // 0x8006CE70: beq         $t1, $zero, L_8006CE94
    if (ctx->r9 == 0) {
        // 0x8006CE74: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8006CE94;
    }
    // 0x8006CE74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006CE78: jal         0x800677F8
    // 0x8006CE7C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800677F8(rdram, ctx);
        goto after_2;
    // 0x8006CE7C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8006CE80: jal         0x8002FC7C
    // 0x8006CE84: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8002FC7C(rdram, ctx);
        goto after_3;
    // 0x8006CE84: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8006CE88: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8006CE8C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CE90: sw          $zero, 0x68($t2)
    MEM_W(0X68, ctx->r10) = 0;
L_8006CE94:
    // 0x8006CE94: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x8006CE98: lbu         $t3, 0x7EA5($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7EA5);
    // 0x8006CE9C: bnel        $t3, $zero, L_8006CEF8
    if (ctx->r11 != 0) {
        // 0x8006CEA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006CEF8;
    }
    goto skip_1;
    // 0x8006CEA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8006CEA4: bne         $a3, $zero, L_8006CECC
    if (ctx->r7 != 0) {
        // 0x8006CEA8: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_8006CECC;
    }
    // 0x8006CEA8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8006CEAC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8006CEB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006CEB4: beql        $t4, $zero, L_8006CEF8
    if (ctx->r12 == 0) {
        // 0x8006CEB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006CEF8;
    }
    goto skip_2;
    // 0x8006CEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8006CEBC: jal         0x8006CC8C
    // 0x8006CEC0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_8006CC8C(rdram, ctx);
        goto after_4;
    // 0x8006CEC0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8006CEC4: b           L_8006CEF8
    // 0x8006CEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006CEF8;
    // 0x8006CEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006CECC:
    // 0x8006CECC: bne         $t5, $zero, L_8006CEE8
    if (ctx->r13 != 0) {
        // 0x8006CED0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8006CEE8;
    }
    // 0x8006CED0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006CED4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006CED8: jal         0x8006CC8C
    // 0x8006CEDC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8006CC8C(rdram, ctx);
        goto after_5;
    // 0x8006CEDC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_5:
    // 0x8006CEE0: b           L_8006CEF8
    // 0x8006CEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006CEF8;
    // 0x8006CEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006CEE8:
    // 0x8006CEE8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8006CEEC: jal         0x8006CCB4
    // 0x8006CEF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_8006CCB4(rdram, ctx);
        goto after_6;
    // 0x8006CEF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x8006CEF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006CEF8:
    // 0x8006CEF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006CEFC: jr          $ra
    // 0x8006CF00: nop

    return;
    // 0x8006CF00: nop

;}
RECOMP_FUNC void func_80558830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558830: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80558834: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x80558838: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8055883C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80558840: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80558844: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80558848: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8055884C: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80558850: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80558854: jal         0x800653D8
    // 0x80558858: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80558858: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8055885C: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x80558860: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80558864: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80558868: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8055886C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80558870: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80558874: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80558878: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8055887C: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x80558880: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80558884: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80558888: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8055888C: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80558890: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(363, 0X9530) << 16);
    // 0x80558894: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80558898: lwc1        $f18, 0x1080($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(363, 0X9530));
    // 0x8055889C: lw          $t1, 0xA68($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XA68);
    // 0x805588A0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805588A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805588A8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x805588AC: lwc1        $f16, 0x44($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X44);
    // 0x805588B0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805588B4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x805588B8: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x805588BC: lw          $t9, 0x50($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X50);
    // 0x805588C0: jalr        $t9
    // 0x805588C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805588C4: nop

    after_1:
    // 0x805588C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805588CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805588D0: jr          $ra
    // 0x805588D4: nop

    return;
    // 0x805588D4: nop

;}
RECOMP_FUNC void func_806B270C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B270C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2710: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2714: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2718: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B271C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2720: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2724: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2728: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B272C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2730: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2734: jr          $ra
    // 0x806B2738: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2738: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806D2E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2E84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D2E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D2E8C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D2E90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x806D2E94: bne         $v1, $zero, L_806D2EB0
    if (ctx->r3 != 0) {
        // 0x806D2E98: nop
    
            goto L_806D2EB0;
    }
    // 0x806D2E98: nop

    // 0x806D2E9C: jal         0x80045A34
    // 0x806D2EA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806D2EA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D2EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D2EA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806D2EAC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
L_806D2EB0:
    // 0x806D2EB0: bne         $v1, $zero, L_806D2EC8
    if (ctx->r3 != 0) {
        // 0x806D2EB4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_806D2EC8;
    }
    // 0x806D2EB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D2EB8: jal         0x800445A4
    // 0x806D2EBC: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806D2EBC: nop

    after_1:
    // 0x806D2EC0: b           L_806D2F1C
    // 0x806D2EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D2F1C;
    // 0x806D2EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D2EC8:
    // 0x806D2EC8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806D2ECC: lui         $t7, 0x806D
    ctx->r15 = S32(RELOC_HI16(613, 0X110) << 16);
    // 0x806D2ED0: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x806D2ED4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806D2ED8: addiu       $t7, $t7, 0x2F60
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(613, 0X110));
    // 0x806D2EDC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806D2EE0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D2EE4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x806D2EE8: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x806D2EEC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806D2EF0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806D2EF4: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806D2EF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806D2EFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D2F00: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806D2F04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D2F08: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x806D2F0C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x806D2F10: jal         0x806D2F28
    // 0x806D2F14: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    func_806D2F28(rdram, ctx);
        goto after_2;
    // 0x806D2F14: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    after_2:
    // 0x806D2F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D2F1C:
    // 0x806D2F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D2F20: jr          $ra
    // 0x806D2F24: nop

    return;
    // 0x806D2F24: nop

;}
RECOMP_FUNC void func_8005DCB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DCB4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005DCB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005DCBC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005DCC0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005DCC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005DCC8: lw          $s2, 0x16C($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X16C);
    // 0x8005DCCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005DCD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005DCD4: lw          $v1, 0x2C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X2C);
    // 0x8005DCD8: bnel        $v1, $at, L_8005DCEC
    if (ctx->r3 != ctx->r1) {
        // 0x8005DCDC: lbu         $t6, 0x165($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X165);
            goto L_8005DCEC;
    }
    goto skip_0;
    // 0x8005DCDC: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
    skip_0:
    // 0x8005DCE0: b           L_8005DF54
    // 0x8005DCE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005DF54;
    // 0x8005DCE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005DCE8: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
L_8005DCEC:
    // 0x8005DCEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DCF0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8005DCF4: beql        $t6, $at, L_8005DF3C
    if (ctx->r14 == ctx->r1) {
        // 0x8005DCF8: lw          $t0, 0x38($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X38);
            goto L_8005DF3C;
    }
    goto skip_1;
    // 0x8005DCF8: lw          $t0, 0x38($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X38);
    skip_1:
    // 0x8005DCFC: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x8005DD00: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005DD04: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8005DD08: lwc1        $f6, 0x38($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X38);
    // 0x8005DD0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005DD10: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x8005DD14: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005DD18: jal         0x80081C64
    // 0x8005DD1C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8005DD1C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8005DD20: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8005DD24: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8005DD28: lw          $v0, 0x3F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X3F4);
    // 0x8005DD2C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8005DD30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005DD34: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005DD38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005DD3C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005DD40: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005DD44: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8005DD48: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005DD4C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8005DD50: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8005DD54: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x8005DD58: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8005DD5C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8005DD60: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8005DD64: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005DD68: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8005DD6C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8005DD70: nop

    // 0x8005DD74: bc1fl       L_8005DF3C
    if (!c1cs) {
        // 0x8005DD78: lw          $t0, 0x38($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X38);
            goto L_8005DF3C;
    }
    goto skip_2;
    // 0x8005DD78: lw          $t0, 0x38($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X38);
    skip_2:
    // 0x8005DD7C: lw          $t8, 0xA84($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XA84);
    // 0x8005DD80: lwc1        $f2, 0x9C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8005DD84: lwc1        $f12, 0xA0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8005DD88: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x8005DD8C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8005DD90: jal         0x8004733C
    // 0x8005DD94: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_8004733C(rdram, ctx);
        goto after_1;
    // 0x8005DD94: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8005DD98: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8005DD9C: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    // 0x8005DDA0: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005DDA4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8005DDA8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005DDAC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005DDB0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005DDB4: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8005DDB8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005DDBC: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8005DDC0: beq         $t5, $zero, L_8005DDD0
    if (ctx->r13 == 0) {
        // 0x8005DDC4: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_8005DDD0;
    }
    // 0x8005DDC4: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8005DDC8: lwc1        $f2, 0x9C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8005DDCC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8005DDD0:
    // 0x8005DDD0: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x8005DDD4: bnel        $t7, $zero, L_8005DDE8
    if (ctx->r15 != 0) {
        // 0x8005DDD8: lw          $t8, 0x24($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X24);
            goto L_8005DDE8;
    }
    goto skip_3;
    // 0x8005DDD8: lw          $t8, 0x24($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X24);
    skip_3:
    // 0x8005DDDC: lwc1        $f12, 0xA0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8005DDE0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8005DDE4: lw          $t8, 0x24($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X24);
L_8005DDE8:
    // 0x8005DDE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DDEC: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8005DDF0: bnel        $t9, $at, L_8005DE0C
    if (ctx->r25 != ctx->r1) {
        // 0x8005DDF4: swc1        $f4, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
            goto L_8005DE0C;
    }
    goto skip_4;
    // 0x8005DDF4: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    skip_4:
    // 0x8005DDF8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8005DDFC: nop

    // 0x8005DE00: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8005DE04: nop

    // 0x8005DE08: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
L_8005DE0C:
    // 0x8005DE0C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005DE10: swc1        $f12, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f12.u32l;
    // 0x8005DE14: swc1        $f2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f2.u32l;
    // 0x8005DE18: swc1        $f8, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
    // 0x8005DE1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005DE20: lwc1        $f6, 0xD50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD50);
    // 0x8005DE24: lwc1        $f10, 0x98($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8005DE28: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8005DE2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005DE30: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8005DE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005DE38: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005DE3C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8005DE40: lh          $a3, 0x144($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X144);
    // 0x8005DE44: lw          $a2, 0x148($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X148);
    // 0x8005DE48: jal         0x8005DBF0
    // 0x8005DE4C: lw          $a1, 0x168($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X168);
    func_8005DBF0(rdram, ctx);
        goto after_2;
    // 0x8005DE4C: lw          $a1, 0x168($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X168);
    after_2:
    // 0x8005DE50: lw          $t0, 0x8($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X8);
    // 0x8005DE54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005DE58: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005DE5C: jal         0x8005DC34
    // 0x8005DE60: sw          $t0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r8;
    func_8005DC34(rdram, ctx);
        goto after_3;
    // 0x8005DE60: sw          $t0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r8;
    after_3:
    // 0x8005DE64: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8005DE68: lwc1        $f10, 0x60($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8005DE6C: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8005DE70: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    // 0x8005DE74: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8005DE78: nop

    // 0x8005DE7C: bc1f        L_8005DE9C
    if (!c1cs) {
        // 0x8005DE80: nop
    
            goto L_8005DE9C;
    }
    // 0x8005DE80: nop

    // 0x8005DE84: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8005DE88: lwc1        $f16, 0x64($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8005DE8C: c.eq.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl == ctx->f16.fl;
    // 0x8005DE90: nop

    // 0x8005DE94: bc1tl       L_8005DEB8
    if (c1cs) {
        // 0x8005DE98: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005DEB8;
    }
    goto skip_5;
    // 0x8005DE98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_5:
L_8005DE9C:
    // 0x8005DE9C: jal         0x80068470
    // 0x8005DEA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80068470(rdram, ctx);
        goto after_4;
    // 0x8005DEA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8005DEA4: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8005DEA8: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8005DEAC: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
    // 0x8005DEB0: swc1        $f4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f4.u32l;
    // 0x8005DEB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8005DEB8:
    // 0x8005DEB8: jal         0x8005DBCC
    // 0x8005DEBC: lbu         $a1, 0xC($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XC);
    func_8005DBCC(rdram, ctx);
        goto after_5;
    // 0x8005DEBC: lbu         $a1, 0xC($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XC);
    after_5:
    // 0x8005DEC0: addiu       $v0, $s2, 0xD
    ctx->r2 = ADD32(ctx->r18, 0XD);
    // 0x8005DEC4: beq         $v0, $zero, L_8005DF30
    if (ctx->r2 == 0) {
        // 0x8005DEC8: nop
    
            goto L_8005DF30;
    }
    // 0x8005DEC8: nop

    // 0x8005DECC: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8005DED0: sb          $t2, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r10;
    // 0x8005DED4: lbu         $t1, 0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1);
    // 0x8005DED8: sb          $t1, 0x31($s1)
    MEM_B(0X31, ctx->r17) = ctx->r9;
    // 0x8005DEDC: lbu         $t3, 0x2($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2);
    // 0x8005DEE0: sb          $t3, 0x32($s1)
    MEM_B(0X32, ctx->r17) = ctx->r11;
    // 0x8005DEE4: lbu         $t4, 0x3($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3);
    // 0x8005DEE8: sb          $t4, 0x33($s1)
    MEM_B(0X33, ctx->r17) = ctx->r12;
    // 0x8005DEEC: lbu         $t5, 0xC($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XC);
    // 0x8005DEF0: beql        $t5, $zero, L_8005DF24
    if (ctx->r13 == 0) {
        // 0x8005DEF4: sb          $zero, 0x34($s1)
        MEM_B(0X34, ctx->r17) = 0;
            goto L_8005DF24;
    }
    goto skip_6;
    // 0x8005DEF4: sb          $zero, 0x34($s1)
    MEM_B(0X34, ctx->r17) = 0;
    skip_6:
    // 0x8005DEF8: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x8005DEFC: sb          $t6, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r14;
    // 0x8005DF00: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x8005DF04: sb          $t7, 0x35($s1)
    MEM_B(0X35, ctx->r17) = ctx->r15;
    // 0x8005DF08: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x8005DF0C: sb          $t8, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r24;
    // 0x8005DF10: lbu         $t9, 0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X7);
    // 0x8005DF14: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8005DF18: b           L_8005DF54
    // 0x8005DF1C: sb          $t9, 0x37($s1)
    MEM_B(0X37, ctx->r17) = ctx->r25;
        goto L_8005DF54;
    // 0x8005DF1C: sb          $t9, 0x37($s1)
    MEM_B(0X37, ctx->r17) = ctx->r25;
    // 0x8005DF20: sb          $zero, 0x34($s1)
    MEM_B(0X34, ctx->r17) = 0;
L_8005DF24:
    // 0x8005DF24: sb          $zero, 0x35($s1)
    MEM_B(0X35, ctx->r17) = 0;
    // 0x8005DF28: sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
    // 0x8005DF2C: sb          $zero, 0x37($s1)
    MEM_B(0X37, ctx->r17) = 0;
L_8005DF30:
    // 0x8005DF30: b           L_8005DF54
    // 0x8005DF34: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8005DF54;
    // 0x8005DF34: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8005DF38: lw          $t0, 0x38($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X38);
L_8005DF3C:
    // 0x8005DF3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005DF40: beq         $t0, $zero, L_8005DF54
    if (ctx->r8 == 0) {
        // 0x8005DF44: nop
    
            goto L_8005DF54;
    }
    // 0x8005DF44: nop

    // 0x8005DF48: lbu         $t2, 0x34($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X34);
    // 0x8005DF4C: xori        $t1, $t2, 0x1
    ctx->r9 = ctx->r10 ^ 0X1;
    // 0x8005DF50: sb          $t1, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r9;
L_8005DF54:
    // 0x8005DF54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005DF58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005DF5C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005DF60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005DF64: jr          $ra
    // 0x8005DF68: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005DF68: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_805819A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805819A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805819A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805819A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805819AC: jal         0x80581854
    // 0x805819B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80581854(rdram, ctx);
        goto after_0;
    // 0x805819B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805819B4: beq         $v0, $zero, L_805819D0
    if (ctx->r2 == 0) {
        // 0x805819B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805819D0;
    }
    // 0x805819B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805819BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805819C0: jal         0x80581AA4
    // 0x805819C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80581AA4(rdram, ctx);
        goto after_1;
    // 0x805819C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x805819C8: b           L_80581A28
    // 0x805819CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80581A28;
    // 0x805819CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805819D0:
    // 0x805819D0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x805819D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805819D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805819DC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805819E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x805819E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805819E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805819EC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x805819F0: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805819F4: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x805819F8: nop

    // 0x805819FC: bc1fl       L_80581A28
    if (!c1cs) {
        // 0x80581A00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80581A28;
    }
    goto skip_0;
    // 0x80581A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80581A04: jal         0x8057EF14
    // 0x80581A08: addiu       $a1, $zero, 0x4023
    ctx->r5 = ADD32(0, 0X4023);
    func_8057EF14(rdram, ctx);
        goto after_2;
    // 0x80581A08: addiu       $a1, $zero, 0x4023
    ctx->r5 = ADD32(0, 0X4023);
    after_2:
    // 0x80581A0C: beq         $v0, $zero, L_80581A1C
    if (ctx->r2 == 0) {
        // 0x80581A10: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80581A1C;
    }
    // 0x80581A10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80581A14: jal         0x8005C9A8
    // 0x80581A18: nop

    func_8005C9A8(rdram, ctx);
        goto after_3;
    // 0x80581A18: nop

    after_3:
L_80581A1C:
    // 0x80581A1C: jal         0x800447C8
    // 0x80581A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x80581A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80581A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80581A28:
    // 0x80581A28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80581A2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80581A30: jr          $ra
    // 0x80581A34: nop

    return;
    // 0x80581A34: nop

;}
RECOMP_FUNC void func_806F89F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F89F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F89F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F89F8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F89FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806F8A00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F8A04: lwc1        $f0, 0x5F0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5F0);
    // 0x806F8A08: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806F8A0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806F8A10: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806F8A14: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x806F8A18: nop

    // 0x806F8A1C: bc1fl       L_806F8AA4
    if (!c1cs) {
        // 0x806F8A20: swc1        $f0, 0x5F0($v1)
        MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
            goto L_806F8AA4;
    }
    goto skip_0;
    // 0x806F8A20: swc1        $f0, 0x5F0($v1)
    MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
    skip_0:
    // 0x806F8A24: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806F8A28: jal         0x8004700C
    // 0x806F8A2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F8A2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F8A30: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806F8A34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F8A38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8A3C: beq         $v0, $zero, L_806F8AA0
    if (ctx->r2 == 0) {
        // 0x806F8A40: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806F8AA0;
    }
    // 0x806F8A40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F8A44: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(694, 0X12AC) << 16);
    // 0x806F8A48: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x806F8A4C: addiu       $t7, $t7, -0x7544
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(694, 0X12AC));
    // 0x806F8A50: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x806F8A54: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x806F8A58: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806F8A5C: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x806F8A60: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B38) << 16);
    // 0x806F8A64: lwc1        $f10, -0x6CB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B38));
    // 0x806F8A68: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x806F8A6C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B40) << 16);
    // 0x806F8A70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F8A74: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806F8A78: nop

    // 0x806F8A7C: bc1f        L_806F8A90
    if (!c1cs) {
        // 0x806F8A80: nop
    
            goto L_806F8A90;
    }
    // 0x806F8A80: nop

    // 0x806F8A84: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B3C) << 16);
    // 0x806F8A88: b           L_806F8A94
    // 0x806F8A8C: lwc1        $f2, -0x6CB4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B3C));
        goto L_806F8A94;
    // 0x806F8A8C: lwc1        $f2, -0x6CB4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B3C));
L_806F8A90:
    // 0x806F8A90: lwc1        $f2, -0x6CB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B40));
L_806F8A94:
    // 0x806F8A94: swc1        $f2, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f2.u32l;
    // 0x806F8A98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F8A9C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
L_806F8AA0:
    // 0x806F8AA0: swc1        $f0, 0x5F0($v1)
    MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
L_806F8AA4:
    // 0x806F8AA4: jal         0x806F85F8
    // 0x806F8AA8: addiu       $a0, $v1, 0x268
    ctx->r4 = ADD32(ctx->r3, 0X268);
    func_806F85F8(rdram, ctx);
        goto after_1;
    // 0x806F8AA8: addiu       $a0, $v1, 0x268
    ctx->r4 = ADD32(ctx->r3, 0X268);
    after_1:
    // 0x806F8AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F8AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F8AB4: jr          $ra
    // 0x806F8AB8: nop

    return;
    // 0x806F8AB8: nop

;}
RECOMP_FUNC void func_8041F130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F130: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8041F134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041F138: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041F13C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041F140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041F144: jal         0x8041DB1C
    // 0x8041F148: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041F148: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8041F14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F150: jal         0x8041E9A8
    // 0x8041F154: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041F154: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8041F158: beq         $v0, $zero, L_8041F1AC
    if (ctx->r2 == 0) {
        // 0x8041F15C: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8041F1AC;
    }
    // 0x8041F15C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8041F160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8041F164: jal         0x80048F84
    // 0x8041F168: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8041F168: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8041F16C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8041F170: jal         0x80048F84
    // 0x8041F174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8041F174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8041F178: jal         0x8041E5E8
    // 0x8041F17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_4;
    // 0x8041F17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8041F180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F184: jal         0x8041E430
    // 0x8041F188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8041E430(rdram, ctx);
        goto after_5;
    // 0x8041F188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x8041F18C: jal         0x80059278
    // 0x8041F190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80059278(rdram, ctx);
        goto after_6;
    // 0x8041F190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8041F194: bnel        $v0, $zero, L_8041F1B0
    if (ctx->r2 != 0) {
        // 0x8041F198: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F1B0;
    }
    goto skip_0;
    // 0x8041F198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8041F19C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8041F1A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F1A4: jalr        $t9
    // 0x8041F1A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8041F1A8: nop

    after_7:
L_8041F1AC:
    // 0x8041F1AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041F1B0:
    // 0x8041F1B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041F1B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8041F1B8: jr          $ra
    // 0x8041F1BC: nop

    return;
    // 0x8041F1BC: nop

;}
RECOMP_FUNC void func_80530C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80530CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80530CA4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80530CA8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80530CAC: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(339, 0X428) << 16);
    // 0x80530CB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80530CB4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80530CB8: lw          $t8, 0xD48($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(339, 0X428));
    // 0x80530CBC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80530CC0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80530CC4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80530CC8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80530CCC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80530CD0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80530CD4: beql        $v1, $zero, L_80530D08
    if (ctx->r3 == 0) {
        // 0x80530CD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80530D08;
    }
    goto skip_0;
    // 0x80530CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80530CDC: jalr        $v1
    // 0x80530CE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80530CE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80530CE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80530CE8: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80530CEC: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80530CF0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80530CF4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80530CF8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80530CFC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80530D00: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80530D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80530D08:
    // 0x80530D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80530D0C: jr          $ra
    // 0x80530D10: nop

    return;
    // 0x80530D10: nop

    // 0x80530D14: nop

    // 0x80530D18: nop

    // 0x80530D1C: nop

;}
RECOMP_FUNC void func_80582168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582168: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8058216C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80582170: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80582174: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80582178: jal         0x80580C70
    // 0x8058217C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x8058217C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80582180: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80582184: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80582188: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    // 0x8058218C: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x80582190: beq         $a2, $zero, L_805821A8
    if (ctx->r6 == 0) {
        // 0x80582194: nop
    
            goto L_805821A8;
    }
    // 0x80582194: nop

    // 0x80582198: jal         0x80582498
    // 0x8058219C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80582498(rdram, ctx);
        goto after_1;
    // 0x8058219C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805821A0: b           L_80582250
    // 0x805821A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80582250;
    // 0x805821A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805821A8:
    // 0x805821A8: jal         0x8057EF14
    // 0x805821AC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8057EF14(rdram, ctx);
        goto after_2;
    // 0x805821AC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x805821B0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805821B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805821B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805821BC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805821C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805821C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805821C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805821CC: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x805821D0: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805821D4: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x805821D8: nop

    // 0x805821DC: bc1fl       L_8058220C
    if (!c1cs) {
        // 0x805821E0: lw          $t0, 0x16C($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X16C);
            goto L_8058220C;
    }
    goto skip_0;
    // 0x805821E0: lw          $t0, 0x16C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X16C);
    skip_0:
    // 0x805821E4: lw          $t6, 0x16C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X16C);
    // 0x805821E8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x805821EC: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x805821F0: sb          $a0, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r4;
    // 0x805821F4: lw          $t7, 0x16C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X16C);
    // 0x805821F8: sb          $a0, 0xE($t7)
    MEM_B(0XE, ctx->r15) = ctx->r4;
    // 0x805821FC: lw          $t9, 0x16C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X16C);
    // 0x80582200: b           L_8058224C
    // 0x80582204: sb          $t8, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r24;
        goto L_8058224C;
    // 0x80582204: sb          $t8, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r24;
    // 0x80582208: lw          $t0, 0x16C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X16C);
L_8058220C:
    // 0x8058220C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80582210: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80582214: sb          $a0, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r4;
    // 0x80582218: lw          $t1, 0x16C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X16C);
    // 0x8058221C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80582220: sb          $a0, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r4;
    // 0x80582224: lw          $t2, 0x16C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X16C);
    // 0x80582228: sb          $a0, 0xF($t2)
    MEM_B(0XF, ctx->r10) = ctx->r4;
    // 0x8058222C: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80582230: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80582234: nop

    // 0x80582238: bc1fl       L_80582250
    if (!c1cs) {
        // 0x8058223C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80582250;
    }
    goto skip_1;
    // 0x8058223C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80582240: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80582244: nop

    // 0x80582248: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_8058224C:
    // 0x8058224C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80582250:
    // 0x80582250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80582254: jr          $ra
    // 0x80582258: nop

    return;
    // 0x80582258: nop

;}
RECOMP_FUNC void func_806DEEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DEEE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806DEEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DEEF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806DEEF4: jal         0x80047090
    // 0x806DEEF8: addiu       $a0, $zero, 0x45BA
    ctx->r4 = ADD32(0, 0X45BA);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806DEEF8: addiu       $a0, $zero, 0x45BA
    ctx->r4 = ADD32(0, 0X45BA);
    after_0:
    // 0x806DEEFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806DEF00: lui         $at, 0x45BA
    ctx->r1 = S32(0X45BA << 16);
    // 0x806DEF04: ori         $at, $at, 0x1C00
    ctx->r1 = ctx->r1 | 0X1C00;
    // 0x806DEF08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806DEF0C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806DEF10: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x806DEF14: jal         0x8004613C
    // 0x806DEF18: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806DEF18: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x806DEF1C: bne         $v0, $zero, L_806DEF2C
    if (ctx->r2 != 0) {
        // 0x806DEF20: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_806DEF2C;
    }
    // 0x806DEF20: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806DEF24: b           L_806DEF88
    // 0x806DEF28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806DEF88;
    // 0x806DEF28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806DEF2C:
    // 0x806DEF2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806DEF30: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x806DEF34: jal         0x80047F9C
    // 0x806DEF38: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806DEF38: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x806DEF3C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x806DEF40: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806DEF44: addiu       $a0, $a2, 0x6C
    ctx->r4 = ADD32(ctx->r6, 0X6C);
    // 0x806DEF48: jal         0x80065490
    // 0x806DEF4C: addiu       $a1, $a1, 0x6C
    ctx->r5 = ADD32(ctx->r5, 0X6C);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x806DEF4C: addiu       $a1, $a1, 0x6C
    ctx->r5 = ADD32(ctx->r5, 0X6C);
    after_3:
    // 0x806DEF50: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806DEF54: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806DEF58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806DEF5C: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x806DEF60: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x806DEF64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806DEF68: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806DEF6C: lwc1        $f10, 0x70($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X70);
    // 0x806DEF70: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(637, 0X180) << 16);
    // 0x806DEF74: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806DEF78: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x806DEF7C: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x806DEF80: lwc1        $f4, -0x1050($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(637, 0X180));
    // 0x806DEF84: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
L_806DEF88:
    // 0x806DEF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DEF8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806DEF90: jr          $ra
    // 0x806DEF94: nop

    return;
    // 0x806DEF94: nop

    // 0x806DEF98: nop

    // 0x806DEF9C: nop

;}
RECOMP_FUNC void func_8044A1D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A1D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A1D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044A1D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8044A1DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A1E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044A1E4: bne         $a2, $zero, L_8044A238
    if (ctx->r6 != 0) {
        // 0x8044A1E8: lw          $v0, 0x1F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X1F4);
            goto L_8044A238;
    }
    // 0x8044A1E8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A1EC: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8044A1F0: lw          $v1, 0x8C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8C);
    // 0x8044A1F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A1F8: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x8044A1FC: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8044A200: bne         $at, $zero, L_8044A228
    if (ctx->r1 != 0) {
        // 0x8044A204: sw          $t7, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r15;
            goto L_8044A228;
    }
    // 0x8044A204: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8044A208: jal         0x80446C40
    // 0x8044A20C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446C40(rdram, ctx);
        goto after_0;
    // 0x8044A20C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8044A210: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A214: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A218: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8044A21C: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8044A220: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044A224: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_8044A228:
    // 0x8044A228: jal         0x8044A060
    // 0x8044A22C: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    func_8044A060(rdram, ctx);
        goto after_1;
    // 0x8044A22C: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    after_1:
    // 0x8044A230: b           L_8044A27C
    // 0x8044A234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A27C;
    // 0x8044A234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A238:
    // 0x8044A238: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044A23C: bne         $a2, $at, L_8044A264
    if (ctx->r6 != ctx->r1) {
        // 0x8044A240: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044A264;
    }
    // 0x8044A240: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A244: jal         0x80446C40
    // 0x8044A248: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446C40(rdram, ctx);
        goto after_2;
    // 0x8044A248: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8044A24C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A250: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A254: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x8044A258: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044A25C: b           L_8044A278
    // 0x8044A260: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_8044A278;
    // 0x8044A260: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
L_8044A264:
    // 0x8044A264: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8044A268: bnel        $a2, $at, L_8044A27C
    if (ctx->r6 != ctx->r1) {
        // 0x8044A26C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044A27C;
    }
    goto skip_0;
    // 0x8044A26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044A270: jal         0x80446C80
    // 0x8044A274: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80446C80(rdram, ctx);
        goto after_3;
    // 0x8044A274: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
L_8044A278:
    // 0x8044A278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A27C:
    // 0x8044A27C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044A284: jr          $ra
    // 0x8044A288: nop

    return;
    // 0x8044A288: nop

;}
RECOMP_FUNC void func_8057ED40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057ED40: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(396, 0X10) << 16);
    // 0x8057ED44: addiu       $v0, $v0, -0x12B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(396, 0X10));
    // 0x8057ED48: jr          $ra
    // 0x8057ED4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8057ED4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800011EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011EC: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x800011F0: lui         $at, 0x300
    ctx->r1 = S32(0X300 << 16);
    // 0x800011F4: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x800011F8: andi        $t0, $a2, 0xFFFF
    ctx->r8 = ctx->r6 & 0XFFFF;
    // 0x800011FC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80001200: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80001204: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80001208: jr          $ra
    // 0x8000120C: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    return;
    // 0x8000120C: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804255A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804255A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804255A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804255AC: jal         0x80425548
    // 0x804255B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80425548(rdram, ctx);
        goto after_0;
    // 0x804255B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804255B4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804255B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804255BC: lh          $t6, 0x144($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X144);
    // 0x804255C0: bnel        $t6, $at, L_804255E4
    if (ctx->r14 != ctx->r1) {
        // 0x804255C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804255E4;
    }
    goto skip_0;
    // 0x804255C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804255C8: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x804255CC: jal         0x80067BBC
    // 0x804255D0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x804255D0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x804255D4: addiu       $a0, $zero, 0x25B
    ctx->r4 = ADD32(0, 0X25B);
    // 0x804255D8: jal         0x80067818
    // 0x804255DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x804255DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x804255E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804255E4:
    // 0x804255E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804255E8: jr          $ra
    // 0x804255EC: nop

    return;
    // 0x804255EC: nop

;}
RECOMP_FUNC void func_806F5C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5C20: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x806F5C24: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x806F5C28: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x806F5C2C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x806F5C30: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x806F5C34: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x806F5C38: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x806F5C3C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x806F5C40: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x806F5C44: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x806F5C48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806F5C4C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806F5C50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F5C54: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806F5C58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806F5C5C: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x806F5C60: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x806F5C64: addiu       $v1, $sp, 0x7A
    ctx->r3 = ADD32(ctx->r29, 0X7A);
    // 0x806F5C68: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x806F5C6C: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x806F5C70: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806F5C74: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806F5C78: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
L_806F5C7C:
    // 0x806F5C7C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x806F5C80: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x806F5C84: bne         $at, $zero, L_806F5C7C
    if (ctx->r1 != 0) {
        // 0x806F5C88: sh          $v0, -0x2($s2)
        MEM_H(-0X2, ctx->r18) = ctx->r2;
            goto L_806F5C7C;
    }
    // 0x806F5C88: sh          $v0, -0x2($s2)
    MEM_H(-0X2, ctx->r18) = ctx->r2;
    // 0x806F5C8C: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x806F5C90: sw          $a1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r5;
    // 0x806F5C94: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806F5C98: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x806F5C9C: nop

    // 0x806F5CA0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806F5CA4: jal         0x8006A99C
    // 0x806F5CA8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x806F5CA8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x806F5CAC: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x806F5CB0: sll         $s7, $v0, 16
    ctx->r23 = S32(ctx->r2 << 16);
    // 0x806F5CB4: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x806F5CB8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806F5CBC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x806F5CC0: nop

    // 0x806F5CC4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806F5CC8: jal         0x8006A99C
    // 0x806F5CCC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x806F5CCC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x806F5CD0: sll         $fp, $v0, 16
    ctx->r30 = S32(ctx->r2 << 16);
    // 0x806F5CD4: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x806F5CD8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x806F5CDC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x806F5CE0: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x806F5CE4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x806F5CE8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x806F5CEC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806F5CF0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x806F5CF4: jal         0x8006AFA0
    // 0x806F5CF8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8006AFA0(rdram, ctx);
        goto after_2;
    // 0x806F5CF8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x806F5CFC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x806F5D00: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x806F5D04: or          $s5, $fp, $zero
    ctx->r21 = ctx->r30 | 0;
    // 0x806F5D08: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_806F5D0C:
    // 0x806F5D0C: sll         $s3, $s5, 16
    ctx->r19 = S32(ctx->r21 << 16);
    // 0x806F5D10: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x806F5D14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806F5D18: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
L_806F5D1C:
    // 0x806F5D1C: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x806F5D20: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x806F5D24: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806F5D28: jal         0x8006ABF0
    // 0x806F5D2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006ABF0(rdram, ctx);
        goto after_3;
    // 0x806F5D2C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x806F5D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806F5D34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x806F5D38: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x806F5D3C: bne         $s0, $s4, L_806F5D1C
    if (ctx->r16 != ctx->r20) {
        // 0x806F5D40: sh          $v0, -0x2($s2)
        MEM_H(-0X2, ctx->r18) = ctx->r2;
            goto L_806F5D1C;
    }
    // 0x806F5D40: sh          $v0, -0x2($s2)
    MEM_H(-0X2, ctx->r18) = ctx->r2;
    // 0x806F5D44: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x806F5D48: slti        $at, $s6, 0x3
    ctx->r1 = SIGNED(ctx->r22) < 0X3 ? 1 : 0;
    // 0x806F5D4C: bne         $at, $zero, L_806F5D0C
    if (ctx->r1 != 0) {
        // 0x806F5D50: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_806F5D0C;
    }
    // 0x806F5D50: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x806F5D54: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x806F5D58: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x806F5D5C: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x806F5D60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_806F5D64:
    // 0x806F5D64: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x806F5D68: addu        $s1, $s7, $s0
    ctx->r17 = ADD32(ctx->r23, ctx->r16);
    // 0x806F5D6C: addu        $s3, $fp, $s6
    ctx->r19 = ADD32(ctx->r30, ctx->r22);
    // 0x806F5D70: beq         $s5, $v1, L_806F5DA4
    if (ctx->r21 == ctx->r3) {
        // 0x806F5D74: andi        $v0, $v1, 0xF800
        ctx->r2 = ctx->r3 & 0XF800;
            goto L_806F5DA4;
    }
    // 0x806F5D74: andi        $v0, $v1, 0xF800
    ctx->r2 = ctx->r3 & 0XF800;
    // 0x806F5D78: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x806F5D7C: bne         $v0, $zero, L_806F5D88
    if (ctx->r2 != 0) {
        // 0x806F5D80: sra         $s3, $s3, 16
        ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
            goto L_806F5D88;
    }
    // 0x806F5D80: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x806F5D84: addiu       $v0, $zero, 0x5800
    ctx->r2 = ADD32(0, 0X5800);
L_806F5D88:
    // 0x806F5D88: ori         $a2, $v0, 0x701
    ctx->r6 = ctx->r2 | 0X701;
    // 0x806F5D8C: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x806F5D90: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x806F5D94: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x806F5D98: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806F5D9C: jal         0x8006B1C8
    // 0x806F5DA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006B1C8(rdram, ctx);
        goto after_4;
    // 0x806F5DA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
L_806F5DA4:
    // 0x806F5DA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806F5DA8: bne         $s0, $s4, L_806F5D64
    if (ctx->r16 != ctx->r20) {
        // 0x806F5DAC: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_806F5D64;
    }
    // 0x806F5DAC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x806F5DB0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x806F5DB4: bnel        $s6, $s4, L_806F5D64
    if (ctx->r22 != ctx->r20) {
        // 0x806F5DB8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_806F5D64;
    }
    goto skip_0;
    // 0x806F5DB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x806F5DBC: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x806F5DC0: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(685, 0X880) << 16);
    // 0x806F5DC4: addiu       $t9, $t9, 0x5BE0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(685, 0X880));
    // 0x806F5DC8: sw          $t9, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r25;
    // 0x806F5DCC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x806F5DD0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x806F5DD4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x806F5DD8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x806F5DDC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x806F5DE0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x806F5DE4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x806F5DE8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x806F5DEC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x806F5DF0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806F5DF4: jr          $ra
    // 0x806F5DF8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x806F5DF8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_806F8448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8448: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F844C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F8450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F8454: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x806F8458: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806F845C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F8460: bnel        $t6, $at, L_806F84C8
    if (ctx->r14 != ctx->r1) {
        // 0x806F8464: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F84C8;
    }
    goto skip_0;
    // 0x806F8464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F8468: jal         0x806F8278
    // 0x806F846C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_806F8278(rdram, ctx);
        goto after_0;
    // 0x806F846C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806F8470: beq         $v0, $zero, L_806F84C4
    if (ctx->r2 == 0) {
        // 0x806F8474: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_806F84C4;
    }
    // 0x806F8474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806F8478: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x806F847C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x806F8480: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x806F8484: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x806F8488: jal         0x8002F7AC
    // 0x806F848C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8002F7AC(rdram, ctx);
        goto after_1;
    // 0x806F848C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_1:
    // 0x806F8490: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(694, 0X1448) << 16);
    // 0x806F8494: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806F8498: addiu       $t9, $t9, -0x73A8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(694, 0X1448));
    // 0x806F849C: sb          $t8, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r24;
    // 0x806F84A0: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x806F84A4: jal         0x8005FE48
    // 0x806F84A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x806F84A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F84AC: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x806F84B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F84B4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806F84B8: sb          $zero, 0x74($t1)
    MEM_B(0X74, ctx->r9) = 0;
    // 0x806F84BC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x806F84C0: swc1        $f4, 0x268($t2)
    MEM_W(0X268, ctx->r10) = ctx->f4.u32l;
L_806F84C4:
    // 0x806F84C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F84C8:
    // 0x806F84C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F84CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F84D0: jr          $ra
    // 0x806F84D4: nop

    return;
    // 0x806F84D4: nop

;}
RECOMP_FUNC void func_806AA784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AA788: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806AA78C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806AA790: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806AA794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AA798: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806AA79C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806AA7A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806AA7A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806AA7A8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806AA7AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806AA7B0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806AA7B4: lui         $t2, 0x806B
    ctx->r10 = S32(RELOC_HI16(589, 0X118C) << 16);
    // 0x806AA7B8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806AA7BC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806AA7C0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806AA7C4: lw          $t2, -0x56B4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(589, 0X118C));
    // 0x806AA7C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806AA7CC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806AA7D0: jal         0x806A97E8
    // 0x806AA7D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806A97E8(rdram, ctx);
        goto after_0;
    // 0x806AA7D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AA7D8: jal         0x806A9834
    // 0x806AA7DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806A9834(rdram, ctx);
        goto after_1;
    // 0x806AA7DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806AA7E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AA7E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AA7E8: jr          $ra
    // 0x806AA7EC: nop

    return;
    // 0x806AA7EC: nop

;}
RECOMP_FUNC void func_8043BBAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043BBAC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8043BBB0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8043BBB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8043BBB8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8043BBBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8043BBC0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043BBC4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8043BBC8: lui         $t1, 0x8044
    ctx->r9 = S32(RELOC_HI16(86, 0X1B0) << 16);
    // 0x8043BBCC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8043BBD0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8043BBD4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8043BBD8: lw          $t1, -0x4410($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(86, 0X1B0));
    // 0x8043BBDC: jr          $ra
    // 0x8043BBE0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8043BBE0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8043BBE4: nop

    // 0x8043BBE8: nop

    // 0x8043BBEC: nop

;}
RECOMP_FUNC void func_8043A198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043A19C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043A1A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043A1A4: jal         0x80045A34
    // 0x8043A1A8: addiu       $a1, $zero, 0xD58
    ctx->r5 = ADD32(0, 0XD58);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8043A1A8: addiu       $a1, $zero, 0xD58
    ctx->r5 = ADD32(0, 0XD58);
    after_0:
    // 0x8043A1AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043A1B0: beq         $v0, $zero, L_8043A1C8
    if (ctx->r2 == 0) {
        // 0x8043A1B4: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8043A1C8;
    }
    // 0x8043A1B4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8043A1B8: jal         0x80439F08
    // 0x8043A1BC: nop

    func_80439F08(rdram, ctx);
        goto after_1;
    // 0x8043A1BC: nop

    after_1:
    // 0x8043A1C0: jal         0x80439EAC
    // 0x8043A1C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80439EAC(rdram, ctx);
        goto after_2;
    // 0x8043A1C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8043A1C8:
    // 0x8043A1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043A1CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043A1D0: jr          $ra
    // 0x8043A1D4: nop

    return;
    // 0x8043A1D4: nop

;}
RECOMP_FUNC void func_80716B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716B48: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716B4C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716B50: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716B54: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716B58: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716B5C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716B60: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716B64: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716B68: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716B6C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716B70: jr          $ra
    // 0x80716B74: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716B74: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80475480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475480: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475484: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475488: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047548C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475490: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475494: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475498: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047549C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804754A0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804754A4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804754A8: jr          $ra
    // 0x804754AC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804754AC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800433D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800433D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800433D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800433D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800433DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800433E0: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x800433E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800433E8: jal         0x80042880
    // 0x800433EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042880(rdram, ctx);
        goto after_0;
    // 0x800433EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800433F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800433F4: jal         0x80042578
    // 0x800433F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042578(rdram, ctx);
        goto after_1;
    // 0x800433F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800433FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043400: jal         0x800425D4
    // 0x80043404: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800425D4(rdram, ctx);
        goto after_2;
    // 0x80043404: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80043408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004340C: jal         0x800433A4
    // 0x80043410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800433A4(rdram, ctx);
        goto after_3;
    // 0x80043410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80043414: jal         0x800426F8
    // 0x80043418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800426F8(rdram, ctx);
        goto after_4;
    // 0x80043418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004341C: jal         0x8004281C
    // 0x80043420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004281C(rdram, ctx);
        goto after_5;
    // 0x80043420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80043424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043428: jal         0x80042F50
    // 0x8004342C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042F50(rdram, ctx);
        goto after_6;
    // 0x8004342C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80043430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043434: jal         0x800431D8
    // 0x80043438: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800431D8(rdram, ctx);
        goto after_7;
    // 0x80043438: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8004343C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80043440: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80043444: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80043448: jr          $ra
    // 0x8004344C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004344C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80446348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446348: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044634C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446350: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80446354: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80446358: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044635C: sw          $t6, 0x6CAC($at)
    MEM_W(0X6CAC, ctx->r1) = ctx->r14;
    // 0x80446360: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80446364: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x80446368: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x8044636C: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x80446370: sw          $a1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r5;
    // 0x80446374: sw          $v1, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r3;
    // 0x80446378: sw          $a1, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->r5;
    // 0x8044637C: jr          $ra
    // 0x80446380: sw          $t7, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r15;
    return;
    // 0x80446380: sw          $t7, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_80065ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065ABC: add.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80065AC0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80065AC4: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80065AC8: lwc1        $f2, 0x8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80065ACC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80065AD0: nop

    // 0x80065AD4: bc1f        L_80065AE4
    if (!c1cs) {
        // 0x80065AD8: nop
    
            goto L_80065AE4;
    }
    // 0x80065AD8: nop

    // 0x80065ADC: jr          $ra
    // 0x80065AE0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    return;
    // 0x80065AE0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80065AE4:
    // 0x80065AE4: jr          $ra
    // 0x80065AE8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80065AE8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80068ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068EDC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80068EE0: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80068EE4: addiu       $a1, $zero, 0x14F0
    ctx->r5 = ADD32(0, 0X14F0);
    // 0x80068EE8: jal         0x80065728
    // 0x80068EEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80068EEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80068EF0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80068EF4: addiu       $v0, $v1, 0x7EA0
    ctx->r2 = ADD32(ctx->r3, 0X7EA0);
    // 0x80068EF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068EFC: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80068F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068F08: jr          $ra
    // 0x80068F0C: nop

    return;
    // 0x80068F0C: nop

;}
RECOMP_FUNC void func_80446BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446BBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446BC0: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446BC4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446BC8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80446BCC: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x80446BD0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446BD4: jr          $ra
    // 0x80446BD8: sw          $t7, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r15;
    return;
    // 0x80446BD8: sw          $t7, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8006EA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EA64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EA68: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8006EA6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006EA70: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8006EA74: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8006EA78: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8006EA7C: addiu       $t7, $t7, 0x7EF8
    ctx->r15 = ADD32(ctx->r15, 0X7EF8);
    // 0x8006EA80: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8006EA84: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8006EA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006EA8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006EA90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006EA94: jal         0x8006F070
    // 0x8006EA98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8006F070(rdram, ctx);
        goto after_0;
    // 0x8006EA98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8006EA9C: jal         0x8006E9D4
    // 0x8006EAA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006E9D4(rdram, ctx);
        goto after_1;
    // 0x8006EAA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006EAA4: jal         0x8005FE48
    // 0x8006EAA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8006EAA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8006EAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EAB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EAB4: jr          $ra
    // 0x8006EAB8: nop

    return;
    // 0x8006EAB8: nop

;}
RECOMP_FUNC void func_800587A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800587A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800587A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800587A8: jal         0x80047058
    // 0x800587AC: nop

    func_80047058(rdram, ctx);
        goto after_0;
    // 0x800587AC: nop

    after_0:
    // 0x800587B0: lw          $t6, 0x16C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X16C);
    // 0x800587B4: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x800587B8: addiu       $t8, $t7, 0x200
    ctx->r24 = ADD32(ctx->r15, 0X200);
    // 0x800587BC: jal         0x80047058
    // 0x800587C0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    func_80047058(rdram, ctx);
        goto after_1;
    // 0x800587C0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_1:
    // 0x800587C4: lw          $t9, 0x16C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X16C);
    // 0x800587C8: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    // 0x800587CC: jal         0x8004700C
    // 0x800587D0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x800587D0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x800587D4: beq         $v0, $zero, L_80058914
    if (ctx->r2 == 0) {
        // 0x800587D8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80058914;
    }
    // 0x800587D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800587DC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800587E0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800587E4: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x800587E8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800587EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800587F0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800587F4: lui         $t3, 0x1F
    ctx->r11 = S32(0X1F << 16);
    // 0x800587F8: ori         $t3, $t3, 0x3205
    ctx->r11 = ctx->r11 | 0X3205;
    // 0x800587FC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80058800: lui         $t2, 0xB600
    ctx->r10 = S32(0XB600 << 16);
    // 0x80058804: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80058808: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8005880C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80058810: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80058814: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x80058818: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x8005881C: ori         $t5, $t5, 0xAC00
    ctx->r13 = ctx->r13 | 0XAC00;
    // 0x80058820: ori         $t4, $t4, 0x18
    ctx->r12 = ctx->r12 | 0X18;
    // 0x80058824: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80058828: lui         $a2, 0xF0A
    ctx->r6 = S32(0XF0A << 16);
    // 0x8005882C: ori         $a2, $a2, 0x7008
    ctx->r6 = ctx->r6 | 0X7008;
    // 0x80058830: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80058834: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80058838: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005883C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80058840: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x80058844: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80058848: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8005884C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80058850: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80058854: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80058858: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x8005885C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80058860: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80058864: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80058868: lui         $t8, 0xFC12
    ctx->r24 = S32(0XFC12 << 16);
    // 0x8005886C: ori         $t8, $t8, 0x7E24
    ctx->r24 = ctx->r24 | 0X7E24;
    // 0x80058870: addiu       $t9, $zero, -0xC07
    ctx->r25 = ADD32(0, -0XC07);
    // 0x80058874: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80058878: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8005887C: addiu       $t2, $zero, 0x204
    ctx->r10 = ADD32(0, 0X204);
    // 0x80058880: lui         $t1, 0xB700
    ctx->r9 = S32(0XB700 << 16);
    // 0x80058884: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x80058888: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x8005888C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80058890: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80058894: addiu       $v0, $v0, -0x4C10
    ctx->r2 = ADD32(ctx->r2, -0X4C10);
    // 0x80058898: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8005889C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800588A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800588A4:
    // 0x800588A4: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x800588A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800588AC: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800588B0: sb          $t3, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r11;
    // 0x800588B4: lbu         $t4, -0xB($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0XB);
    // 0x800588B8: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800588BC: sb          $t4, -0x33($v1)
    MEM_B(-0X33, ctx->r3) = ctx->r12;
    // 0x800588C0: lbu         $t5, -0xA($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0XA);
    // 0x800588C4: sb          $t5, -0x32($v1)
    MEM_B(-0X32, ctx->r3) = ctx->r13;
    // 0x800588C8: lbu         $t6, -0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X9);
    // 0x800588CC: sb          $t6, -0x24($v1)
    MEM_B(-0X24, ctx->r3) = ctx->r14;
    // 0x800588D0: lbu         $t7, -0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X8);
    // 0x800588D4: sb          $t7, -0x23($v1)
    MEM_B(-0X23, ctx->r3) = ctx->r15;
    // 0x800588D8: lbu         $t8, -0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X7);
    // 0x800588DC: sb          $t8, -0x22($v1)
    MEM_B(-0X22, ctx->r3) = ctx->r24;
    // 0x800588E0: lbu         $t9, -0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X6);
    // 0x800588E4: sb          $t9, -0x14($v1)
    MEM_B(-0X14, ctx->r3) = ctx->r25;
    // 0x800588E8: lbu         $t1, -0x5($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X5);
    // 0x800588EC: sb          $t1, -0x13($v1)
    MEM_B(-0X13, ctx->r3) = ctx->r9;
    // 0x800588F0: lbu         $t2, -0x4($v0)
    ctx->r10 = MEM_BU(ctx->r2, -0X4);
    // 0x800588F4: sb          $t2, -0x12($v1)
    MEM_B(-0X12, ctx->r3) = ctx->r10;
    // 0x800588F8: lbu         $t3, -0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X3);
    // 0x800588FC: sb          $t3, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r11;
    // 0x80058900: lbu         $t4, -0x2($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X2);
    // 0x80058904: sb          $t4, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r12;
    // 0x80058908: lbu         $t5, -0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X1);
    // 0x8005890C: bne         $a0, $a1, L_800588A4
    if (ctx->r4 != ctx->r5) {
        // 0x80058910: sb          $t5, -0x2($v1)
        MEM_B(-0X2, ctx->r3) = ctx->r13;
            goto L_800588A4;
    }
    // 0x80058910: sb          $t5, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r13;
L_80058914:
    // 0x80058914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058918: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005891C: jr          $ra
    // 0x80058920: nop

    return;
    // 0x80058920: nop

;}
RECOMP_FUNC void func_800756A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800756A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800756AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800756B0: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x800756B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800756B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800756BC: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800756C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800756C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800756C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800756CC: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x800756D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800756D4:
    // 0x800756D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800756D8: jal         0x800824B0
    // 0x800756DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800756DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800756E0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800756E4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800756E8: bnel        $s1, $t7, L_800756D4
    if (ctx->r17 != ctx->r15) {
        // 0x800756EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800756D4;
    }
    goto skip_0;
    // 0x800756EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800756F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800756F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800756F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800756FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80075700: jr          $ra
    // 0x80075704: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80075704: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80075708: nop

    // 0x8007570C: nop

;}
RECOMP_FUNC void func_8067DEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067DEC0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8067DEC4: addiu       $at, $zero, 0x4573
    ctx->r1 = ADD32(0, 0X4573);
    // 0x8067DEC8: beq         $v0, $at, L_8067DEE0
    if (ctx->r2 == ctx->r1) {
        // 0x8067DECC: addiu       $at, $zero, 0x4574
        ctx->r1 = ADD32(0, 0X4574);
            goto L_8067DEE0;
    }
    // 0x8067DECC: addiu       $at, $zero, 0x4574
    ctx->r1 = ADD32(0, 0X4574);
    // 0x8067DED0: beq         $v0, $at, L_8067DEEC
    if (ctx->r2 == ctx->r1) {
        // 0x8067DED4: nop
    
            goto L_8067DEEC;
    }
    // 0x8067DED4: nop

    // 0x8067DED8: b           L_8067DEF8
    // 0x8067DEDC: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(544, 0XB54) << 16);
        goto L_8067DEF8;
    // 0x8067DEDC: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(544, 0XB54) << 16);
L_8067DEE0:
    // 0x8067DEE0: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(544, 0XB54) << 16);
    // 0x8067DEE4: jr          $ra
    // 0x8067DEE8: addiu       $v0, $v0, -0x15EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(544, 0XB54));
    return;
    // 0x8067DEE8: addiu       $v0, $v0, -0x15EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(544, 0XB54));
L_8067DEEC:
    // 0x8067DEEC: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(544, 0XBBC) << 16);
    // 0x8067DEF0: jr          $ra
    // 0x8067DEF4: addiu       $v0, $v0, -0x1584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(544, 0XBBC));
    return;
    // 0x8067DEF4: addiu       $v0, $v0, -0x1584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(544, 0XBBC));
L_8067DEF8:
    // 0x8067DEF8: addiu       $v0, $v0, -0x15EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(544, 0XB54));
    // 0x8067DEFC: jr          $ra
    // 0x8067DF00: nop

    return;
    // 0x8067DF00: nop

;}
RECOMP_FUNC void func_80029BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029BF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029BF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80029BF8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80029BFC: addiu       $a1, $a2, 0x1D0
    ctx->r5 = ADD32(ctx->r6, 0X1D0);
    // 0x80029C00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029C04: addiu       $a2, $a2, 0x1D8
    ctx->r6 = ADD32(ctx->r6, 0X1D8);
    // 0x80029C08: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80029C0C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029C10: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029C14: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80029C18: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80029C1C: jal         0x80029574
    // 0x80029C20: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80029574(rdram, ctx);
        goto after_0;
    // 0x80029C20: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x80029C24: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80029C28: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80029C2C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80029C30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80029C34: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029C38: jal         0x80029774
    // 0x80029C3C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80029774(rdram, ctx);
        goto after_1;
    // 0x80029C3C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80029C40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029C44: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80029C48: jal         0x80029220
    // 0x80029C4C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_80029220(rdram, ctx);
        goto after_2;
    // 0x80029C4C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80029C50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029C54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029C58: jr          $ra
    // 0x80029C5C: nop

    return;
    // 0x80029C5C: nop

;}
RECOMP_FUNC void func_80029220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029220: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80029224: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80029228: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002922C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80029230: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80029234: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80029238: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8002923C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029240: lwc1        $f4, 0xC4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x80029244: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80029248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002924C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80029250: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x80029254: addiu       $a1, $t6, 0x1D8
    ctx->r5 = ADD32(ctx->r14, 0X1D8);
    // 0x80029258: addiu       $a2, $t6, 0x1D0
    ctx->r6 = ADD32(ctx->r14, 0X1D0);
    // 0x8002925C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80029260: nop

    // 0x80029264: bc1fl       L_80029274
    if (!c1cs) {
        // 0x80029268: mfc1        $a3, $f0
        ctx->r7 = (int32_t)ctx->f0.u32l;
            goto L_80029274;
    }
    goto skip_0;
    // 0x80029268: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x8002926C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80029270: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
L_80029274:
    // 0x80029274: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80029278: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8002927C: jal         0x80029180
    // 0x80029280: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80029180(rdram, ctx);
        goto after_0;
    // 0x80029280: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80029284: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80029288: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8002928C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80029290: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029294: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80029298: jal         0x80029180
    // 0x8002929C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80029180(rdram, ctx);
        goto after_1;
    // 0x8002929C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x800292A0: lwc1        $f8, 0xAC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x800292A4: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800292A8: lwc1        $f18, 0xB0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800292AC: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800292B0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800292B4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800292B8: swc1        $f16, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f16.u32l;
    // 0x800292BC: swc1        $f6, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f6.u32l;
    // 0x800292C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800292C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800292C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800292CC: jr          $ra
    // 0x800292D0: nop

    return;
    // 0x800292D0: nop

;}
RECOMP_FUNC void func_8042A8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A8B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8042A8B4: lw          $v1, 0x16C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X16C);
    // 0x8042A8B8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8042A8BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8042A8C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8042A8C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8042A8C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8042A8CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8042A8D0: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8042A8D4: lui         $t1, 0x8
    ctx->r9 = S32(0X8 << 16);
    // 0x8042A8D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8042A8DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8042A8E0: ori         $t1, $t1, 0x2C80
    ctx->r9 = ctx->r9 | 0X2C80;
    // 0x8042A8E4: ori         $t9, $t9, 0x18
    ctx->r25 = ctx->r25 | 0X18;
    // 0x8042A8E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8042A8EC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8042A8F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8042A8F4: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x8042A8F8: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x8042A8FC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8042A900: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8042A904: ori         $t3, $t3, 0x3
    ctx->r11 = ctx->r11 | 0X3;
    // 0x8042A908: ori         $t0, $t0, 0x4340
    ctx->r8 = ctx->r8 | 0X4340;
    // 0x8042A90C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8042A910: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8042A914: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8042A918: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8042A91C: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x8042A920: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8042A924: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8042A928: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8042A92C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8042A930: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8042A934: lui         $t8, 0xFF2F
    ctx->r24 = S32(0XFF2F << 16);
    // 0x8042A938: lui         $t7, 0xFC41
    ctx->r15 = S32(0XFC41 << 16);
    // 0x8042A93C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8042A940: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8042A944: ori         $t7, $t7, 0x9683
    ctx->r15 = ctx->r15 | 0X9683;
    // 0x8042A948: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8042A94C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8042A950: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8042A954: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8042A958: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8042A95C: lui         $t4, 0xBB00
    ctx->r12 = S32(0XBB00 << 16);
    // 0x8042A960: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8042A964: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8042A968: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8042A96C: lbu         $t5, 0xD($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XD);
    // 0x8042A970: lbu         $t3, 0x10($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X10);
    // 0x8042A974: lbu         $t9, 0xE($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XE);
    // 0x8042A978: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x8042A97C: lbu         $t5, 0xF($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF);
    // 0x8042A980: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8042A984: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x8042A988: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x8042A98C: sll         $t3, $t5, 8
    ctx->r11 = S32(ctx->r13 << 8);
    // 0x8042A990: or          $t6, $t2, $t3
    ctx->r14 = ctx->r10 | ctx->r11;
    // 0x8042A994: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8042A998: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8042A99C: addiu       $t7, $zero, 0x204
    ctx->r15 = ADD32(0, 0X204);
    // 0x8042A9A0: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x8042A9A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8042A9A8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8042A9AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8042A9B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8042A9B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8042A9B8: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8042A9BC: ori         $t5, $t5, 0x8000
    ctx->r13 = ctx->r13 | 0X8000;
    // 0x8042A9C0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8042A9C4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8042A9C8: ori         $t4, $t4, 0x1
    ctx->r12 = ctx->r12 | 0X1;
    // 0x8042A9CC: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x8042A9D0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8042A9D4: jr          $ra
    // 0x8042A9D8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    return;
    // 0x8042A9D8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_80031F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031F6C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80031F70: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x80031F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031F7C: lhu         $t7, 0x64($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X64);
    // 0x80031F80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80031F84: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80031F88: bnel        $t8, $zero, L_80031FA0
    if (ctx->r24 != 0) {
        // 0x80031F8C: lw          $v0, 0x1E0($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X1E0);
            goto L_80031FA0;
    }
    goto skip_0;
    // 0x80031F8C: lw          $v0, 0x1E0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1E0);
    skip_0:
    // 0x80031F90: jal         0x8002CCF4
    // 0x80031F94: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8002CCF4(rdram, ctx);
        goto after_0;
    // 0x80031F94: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031F98: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80031F9C: lw          $v0, 0x1E0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1E0);
L_80031FA0:
    // 0x80031FA0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x80031FA4: beq         $v0, $zero, L_80031FB4
    if (ctx->r2 == 0) {
        // 0x80031FA8: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80031FB4;
    }
    // 0x80031FA8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80031FAC: b           L_80031FC8
    // 0x80031FB0: sw          $t9, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r25;
        goto L_80031FC8;
    // 0x80031FB0: sw          $t9, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r25;
L_80031FB4:
    // 0x80031FB4: jal         0x800677F8
    // 0x80031FB8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x80031FB8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80031FBC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80031FC0: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
    // 0x80031FC4: sw          $t0, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r8;
L_80031FC8:
    // 0x80031FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031FCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031FD0: jr          $ra
    // 0x80031FD4: nop

    return;
    // 0x80031FD4: nop

;}
RECOMP_FUNC void func_8007480C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007480C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074810: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80074814: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80074818: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007481C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80074820: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074824: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80074828: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007482C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80074830: jal         0x800744B0
    // 0x80074834: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800744B0(rdram, ctx);
        goto after_0;
    // 0x80074834: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x80074838: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x8007483C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80074840: addiu       $s2, $s2, -0x7FFC
    ctx->r18 = ADD32(ctx->r18, -0X7FFC);
    // 0x80074844: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80074848: addiu       $s1, $s4, 0x2BC
    ctx->r17 = ADD32(ctx->r20, 0X2BC);
    // 0x8007484C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80074850:
    // 0x80074850: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80074854: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80074858: jal         0x8008786C
    // 0x8007485C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x8007485C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80074860: bnel        $v0, $zero, L_80074878
    if (ctx->r2 != 0) {
        // 0x80074864: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80074878;
    }
    goto skip_0;
    // 0x80074864: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80074868: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8007486C: jal         0x800873B0
    // 0x80074870: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osMotorStop_recomp(rdram, ctx);
        goto after_2;
    // 0x80074870: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80074874: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80074878:
    // 0x80074878: bne         $s0, $s3, L_80074850
    if (ctx->r16 != ctx->r19) {
        // 0x8007487C: addiu       $s1, $s1, 0x68
        ctx->r17 = ADD32(ctx->r17, 0X68);
            goto L_80074850;
    }
    // 0x8007487C: addiu       $s1, $s1, 0x68
    ctx->r17 = ADD32(ctx->r17, 0X68);
    // 0x80074880: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80074884: jal         0x8007451C
    // 0x80074888: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_8007451C(rdram, ctx);
        goto after_3;
    // 0x80074888: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x8007488C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80074890: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074894: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074898: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007489C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800748A0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800748A4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800748A8: jr          $ra
    // 0x800748AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800748AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80056564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005656C: jal         0x80064D1C
    // 0x80056570: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x80056570: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    after_0:
    // 0x80056574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005657C: jr          $ra
    // 0x80056580: nop

    return;
    // 0x80056580: nop

;}
RECOMP_FUNC void func_8059EB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059EB34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8059EB38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059EB3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8059EB40: jal         0x80045A34
    // 0x8059EB44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8059EB44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8059EB48: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8059EB4C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8059EB50: bne         $v0, $zero, L_8059EB60
    if (ctx->r2 != 0) {
        // 0x8059EB54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8059EB60;
    }
    // 0x8059EB54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8059EB58: b           L_8059EB64
    // 0x8059EB5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8059EB64;
    // 0x8059EB5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8059EB60:
    // 0x8059EB60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8059EB64:
    // 0x8059EB64: jr          $ra
    // 0x8059EB68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8059EB68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804C37CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C37CC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x804C37D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C37D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C37D8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x804C37DC: jal         0x8004921C
    // 0x804C37E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804C37E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804C37E4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x804C37E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C37EC: jal         0x8004921C
    // 0x804C37F0: sh          $v0, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r2;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804C37F0: sh          $v0, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r2;
    after_1:
    // 0x804C37F4: lh          $t0, 0x6E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X6E);
    // 0x804C37F8: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x804C37FC: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x804C3800: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x804C3804: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C3808: lbu         $t9, 0x145($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X145);
    // 0x804C380C: lw          $s0, 0x1F4($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X1F4);
    // 0x804C3810: lw          $t7, 0x168($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X168);
    // 0x804C3814: sll         $ra, $v0, 16
    ctx->r31 = S32(ctx->r2 << 16);
    // 0x804C3818: lw          $t4, 0x300($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X300);
    // 0x804C381C: sra         $ra, $ra, 16
    ctx->r31 = S32(SIGNED(ctx->r31) >> 16);
    // 0x804C3820: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x804C3824: xori        $t4, $t4, 0x1
    ctx->r12 = ctx->r12 ^ 0X1;
    // 0x804C3828: andi        $t4, $t4, 0x1
    ctx->r12 = ctx->r12 & 0X1;
    // 0x804C382C: mflo        $t8
    ctx->r24 = lo;
    // 0x804C3830: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x804C3834: nop

    // 0x804C3838: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C383C: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x804C3840: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x804C3844: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x804C3848: sll         $t9, $t9, 7
    ctx->r25 = S32(ctx->r25 << 7);
    // 0x804C384C: addu        $t7, $s0, $t9
    ctx->r15 = ADD32(ctx->r16, ctx->r25);
    // 0x804C3850: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x804C3854: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804C3858: mflo        $t6
    ctx->r14 = lo;
    // 0x804C385C: addu        $a1, $t8, $t6
    ctx->r5 = ADD32(ctx->r24, ctx->r14);
    // 0x804C3860: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x804C3864: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x804C3868: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x804C386C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x804C3870: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x804C3874: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x804C3878: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C387C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804C3880: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x804C3884: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x804C3888: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804C388C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x804C3890: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x804C3894: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x804C3898: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x804C389C: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x804C38A0: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x804C38A4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804C38A8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x804C38AC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x804C38B0: mflo        $a0
    ctx->r4 = lo;
    // 0x804C38B4: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x804C38B8: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x804C38BC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x804C38C0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804C38C4: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x804C38C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x804C38CC: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x804C38D0: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x804C38D4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x804C38D8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x804C38DC: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x804C38E0: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x804C38E4: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x804C38E8: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804C38EC: beq         $at, $zero, L_804C38FC
    if (ctx->r1 == 0) {
        // 0x804C38F0: or          $t5, $t6, $zero
        ctx->r13 = ctx->r14 | 0;
            goto L_804C38FC;
    }
    // 0x804C38F0: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x804C38F4: b           L_804C38FC
    // 0x804C38F8: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
        goto L_804C38FC;
    // 0x804C38F8: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
L_804C38FC:
    // 0x804C38FC: bgez        $t2, L_804C390C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x804C3900: sra         $v0, $t2, 3
        ctx->r2 = S32(SIGNED(ctx->r10) >> 3);
            goto L_804C390C;
    }
    // 0x804C3900: sra         $v0, $t2, 3
    ctx->r2 = S32(SIGNED(ctx->r10) >> 3);
    // 0x804C3904: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x804C3908: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_804C390C:
    // 0x804C390C: bgtz        $v0, L_804C391C
    if (SIGNED(ctx->r2) > 0) {
        // 0x804C3910: addiu       $a0, $sp, 0x5C
        ctx->r4 = ADD32(ctx->r29, 0X5C);
            goto L_804C391C;
    }
    // 0x804C3910: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x804C3914: b           L_804C3920
    // 0x804C3918: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_804C3920;
    // 0x804C3918: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_804C391C:
    // 0x804C391C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_804C3920:
    // 0x804C3920: bgtz        $v0, L_804C3930
    if (SIGNED(ctx->r2) > 0) {
        // 0x804C3924: addiu       $t8, $t3, 0x7FF
        ctx->r24 = ADD32(ctx->r11, 0X7FF);
            goto L_804C3930;
    }
    // 0x804C3924: addiu       $t8, $t3, 0x7FF
    ctx->r24 = ADD32(ctx->r11, 0X7FF);
    // 0x804C3928: b           L_804C3934
    // 0x804C392C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_804C3934;
    // 0x804C392C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_804C3930:
    // 0x804C3930: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_804C3934:
    // 0x804C3934: div         $zero, $t8, $a3
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r7)));
    // 0x804C3938: bne         $a3, $zero, L_804C3944
    if (ctx->r7 != 0) {
        // 0x804C393C: nop
    
            goto L_804C3944;
    }
    // 0x804C393C: nop

    // 0x804C3940: break       7
    do_break(2152479040);
L_804C3944:
    // 0x804C3944: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x804C3948: bne         $a3, $at, L_804C395C
    if (ctx->r7 != ctx->r1) {
        // 0x804C394C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_804C395C;
    }
    // 0x804C394C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804C3950: bne         $t8, $at, L_804C395C
    if (ctx->r24 != ctx->r1) {
        // 0x804C3954: nop
    
            goto L_804C395C;
    }
    // 0x804C3954: nop

    // 0x804C3958: break       6
    do_break(2152479064);
L_804C395C:
    // 0x804C395C: mflo        $t6
    ctx->r14 = lo;
    // 0x804C3960: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x804C3964: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x804C3968: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x804C396C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x804C3970: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x804C3974: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x804C3978: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x804C397C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x804C3980: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x804C3984: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x804C3988: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x804C398C: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x804C3990: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x804C3994: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x804C3998: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x804C399C: addiu       $t7, $t2, 0x7
    ctx->r15 = ADD32(ctx->r10, 0X7);
    // 0x804C39A0: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x804C39A4: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x804C39A8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x804C39AC: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x804C39B0: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x804C39B4: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x804C39B8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x804C39BC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x804C39C0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x804C39C4: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x804C39C8: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x804C39CC: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x804C39D0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x804C39D4: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x804C39D8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804C39DC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x804C39E0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x804C39E4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x804C39E8: addiu       $t7, $ra, -0x1
    ctx->r15 = ADD32(ctx->r31, -0X1);
    // 0x804C39EC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x804C39F0: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x804C39F4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x804C39F8: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x804C39FC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x804C3A00: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x804C3A04: jal         0x804C365C
    // 0x804C3A08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_804C365C(rdram, ctx);
        goto after_2;
    // 0x804C3A08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x804C3A0C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x804C3A10: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x804C3A14: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x804C3A18: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x804C3A1C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x804C3A20: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x804C3A24: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x804C3A28: sw          $t4, 0x300($s0)
    MEM_W(0X300, ctx->r16) = ctx->r12;
    // 0x804C3A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C3A30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C3A34: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x804C3A38: jr          $ra
    // 0x804C3A3C: nop

    return;
    // 0x804C3A3C: nop

;}
RECOMP_FUNC void func_806FC920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FC920: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806FC924: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(703, 0X228) << 16);
    // 0x806FC928: addiu       $t6, $t6, -0x34C8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(703, 0X228));
    // 0x806FC92C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806FC930: jr          $ra
    // 0x806FC934: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806FC934: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8073EDCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EDCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073EDD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EDD4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8073EDD8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8073EDDC: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8073EDE0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8073EDE4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8073EDE8: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8073EDEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073EDF0: jal         0x8073EE08
    // 0x8073EDF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8073EE08(rdram, ctx);
        goto after_0;
    // 0x8073EDF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8073EDF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EDFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073EE00: jr          $ra
    // 0x8073EE04: nop

    return;
    // 0x8073EE04: nop

;}
RECOMP_FUNC void func_8046A310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046A314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046A318: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046A31C: jal         0x8046B08C
    // 0x8046A320: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8046B08C(rdram, ctx);
        goto after_0;
    // 0x8046A320: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046A324: jal         0x8005FDC4
    // 0x8046A328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x8046A328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046A32C: jal         0x8046A1F8
    // 0x8046A330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A1F8(rdram, ctx);
        goto after_2;
    // 0x8046A330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8046A334: jal         0x80469FF4
    // 0x8046A338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469FF4(rdram, ctx);
        goto after_3;
    // 0x8046A338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8046A33C: jal         0x80048378
    // 0x8046A340: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    func_80048378(rdram, ctx);
        goto after_4;
    // 0x8046A340: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    after_4:
    // 0x8046A344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046A34C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8046A350: jal         0x8046B2D8
    // 0x8046A354: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_5;
    // 0x8046A354: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8046A358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046A35C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046A360: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046A364: jr          $ra
    // 0x8046A368: nop

    return;
    // 0x8046A368: nop

;}
RECOMP_FUNC void func_806AF3D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF3D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x806AF3DC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x806AF3E0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x806AF3E4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x806AF3E8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x806AF3EC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x806AF3F0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806AF3F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806AF3F8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x806AF3FC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x806AF400: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x806AF404: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x806AF408: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x806AF40C: lui         $s7, 0x459B
    ctx->r23 = S32(0X459B << 16);
    // 0x806AF410: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1FAC) << 16);
    // 0x806AF414: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806AF418: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x806AF41C: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AF420: lwc1        $f22, -0x314($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1FAC));
    // 0x806AF424: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x806AF428: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806AF42C: addiu       $s6, $zero, 0x3FF
    ctx->r22 = ADD32(0, 0X3FF);
    // 0x806AF430: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
L_806AF434:
    // 0x806AF434: jal         0x80047090
    // 0x806AF438: addiu       $a0, $zero, 0x459B
    ctx->r4 = ADD32(0, 0X459B);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806AF438: addiu       $a0, $zero, 0x459B
    ctx->r4 = ADD32(0, 0X459B);
    after_0:
    // 0x806AF43C: beq         $s6, $v0, L_806AF548
    if (ctx->r22 == ctx->r2) {
        // 0x806AF440: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_806AF548;
    }
    // 0x806AF440: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x806AF444: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806AF448: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806AF44C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806AF450: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x806AF454: addu        $s1, $s4, $t6
    ctx->r17 = ADD32(ctx->r20, ctx->r14);
    // 0x806AF458: jal         0x8004613C
    // 0x806AF45C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806AF45C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x806AF460: beq         $v0, $zero, L_806AF498
    if (ctx->r2 == 0) {
        // 0x806AF464: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806AF498;
    }
    // 0x806AF464: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806AF468: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x806AF46C: andi        $t8, $s3, 0x3FF
    ctx->r24 = ctx->r19 & 0X3FF;
    // 0x806AF470: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x806AF474: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x806AF478: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x806AF47C: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x806AF480: jal         0x80047F9C
    // 0x806AF484: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806AF484: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806AF488: sb          $fp, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r30;
    // 0x806AF48C: jal         0x806AF2C8
    // 0x806AF490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AF2C8(rdram, ctx);
        goto after_3;
    // 0x806AF490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806AF494: swc1        $f22, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f22.u32l;
L_806AF498:
    // 0x806AF498: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806AF49C: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x806AF4A0: bne         $at, $zero, L_806AF434
    if (ctx->r1 != 0) {
        // 0x806AF4A4: sw          $s0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r16;
            goto L_806AF434;
    }
    // 0x806AF4A4: sw          $s0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r16;
    // 0x806AF4A8: lui         $s7, 0x459A
    ctx->r23 = S32(0X459A << 16);
    // 0x806AF4AC: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x806AF4B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_806AF4B4:
    // 0x806AF4B4: jal         0x80047090
    // 0x806AF4B8: addiu       $a0, $zero, 0x459A
    ctx->r4 = ADD32(0, 0X459A);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x806AF4B8: addiu       $a0, $zero, 0x459A
    ctx->r4 = ADD32(0, 0X459A);
    after_4:
    // 0x806AF4BC: beq         $s6, $v0, L_806AF548
    if (ctx->r22 == ctx->r2) {
        // 0x806AF4C0: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_806AF548;
    }
    // 0x806AF4C0: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x806AF4C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806AF4C8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806AF4CC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806AF4D0: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x806AF4D4: addu        $s1, $s4, $t2
    ctx->r17 = ADD32(ctx->r20, ctx->r10);
    // 0x806AF4D8: jal         0x8004613C
    // 0x806AF4DC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x806AF4DC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_5:
    // 0x806AF4E0: beq         $v0, $zero, L_806AF518
    if (ctx->r2 == 0) {
        // 0x806AF4E4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806AF518;
    }
    // 0x806AF4E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806AF4E8: lhu         $t5, 0xE($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XE);
    // 0x806AF4EC: andi        $t4, $s3, 0x3FF
    ctx->r12 = ctx->r19 & 0X3FF;
    // 0x806AF4F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x806AF4F4: andi        $t6, $t5, 0xFC00
    ctx->r14 = ctx->r13 & 0XFC00;
    // 0x806AF4F8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x806AF4FC: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x806AF500: jal         0x80047F9C
    // 0x806AF504: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x806AF504: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x806AF508: sb          $fp, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r30;
    // 0x806AF50C: jal         0x806AF314
    // 0x806AF510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AF314(rdram, ctx);
        goto after_7;
    // 0x806AF510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806AF514: swc1        $f20, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f20.u32l;
L_806AF518:
    // 0x806AF518: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806AF51C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AF520: bne         $s2, $at, L_806AF4B4
    if (ctx->r18 != ctx->r1) {
        // 0x806AF524: sw          $s0, 0x28($s1)
        MEM_W(0X28, ctx->r17) = ctx->r16;
            goto L_806AF4B4;
    }
    // 0x806AF524: sw          $s0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r16;
    // 0x806AF528: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806AF52C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806AF530: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(595, 0X7FC) << 16);
    // 0x806AF534: addiu       $t9, $t9, -0x1AC4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(595, 0X7FC));
    // 0x806AF538: sw          $zero, 0xC($s4)
    MEM_W(0XC, ctx->r20) = 0;
    // 0x806AF53C: sw          $t9, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r25;
    // 0x806AF540: sw          $zero, 0x14($s4)
    MEM_W(0X14, ctx->r20) = 0;
    // 0x806AF544: swc1        $f4, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f4.u32l;
L_806AF548:
    // 0x806AF548: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x806AF54C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806AF550: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806AF554: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x806AF558: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x806AF55C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x806AF560: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x806AF564: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x806AF568: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x806AF56C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x806AF570: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x806AF574: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x806AF578: jr          $ra
    // 0x806AF57C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x806AF57C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8001A760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A760: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001A764: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001A768: sw          $zero, 0x650($at)
    MEM_W(0X650, ctx->r1) = 0;
    // 0x8001A76C: addiu       $v1, $v1, 0x5B0
    ctx->r3 = ADD32(ctx->r3, 0X5B0);
    // 0x8001A770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A774:
    // 0x8001A774: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8001A778: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A77C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8001A780: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001A784: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8001A788: bne         $at, $zero, L_8001A774
    if (ctx->r1 != 0) {
        // 0x8001A78C: sb          $zero, 0x0($t7)
        MEM_B(0X0, ctx->r15) = 0;
            goto L_8001A774;
    }
    // 0x8001A78C: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8001A790: jr          $ra
    // 0x8001A794: nop

    return;
    // 0x8001A794: nop

    // 0x8001A798: nop

    // 0x8001A79C: nop

;}
RECOMP_FUNC void func_8003F894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F894: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003F898: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003F89C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003F8A0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003F8A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8003F8A8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003F8AC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8003F8B0: andi        $t1, $a2, 0xFF
    ctx->r9 = ctx->r6 & 0XFF;
    // 0x8003F8B4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8003F8B8: lhu         $v0, 0x12BE($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X12BE);
    // 0x8003F8BC: blez        $t1, L_8003F958
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8003F8C0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8003F958;
    }
    // 0x8003F8C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003F8C4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8003F8C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003F8CC: addiu       $t0, $zero, 0x4144
    ctx->r8 = ADD32(0, 0X4144);
    // 0x8003F8D0: addiu       $a3, $zero, 0x406C
    ctx->r7 = ADD32(0, 0X406C);
    // 0x8003F8D4: addiu       $a2, $zero, 0x4004
    ctx->r6 = ADD32(0, 0X4004);
    // 0x8003F8D8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
L_8003F8DC:
    // 0x8003F8DC: addu        $t7, $t2, $v1
    ctx->r15 = ADD32(ctx->r10, ctx->r3);
    // 0x8003F8E0: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8003F8E4: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F8E8: mflo        $t9
    ctx->r25 = lo;
    // 0x8003F8EC: addu        $t3, $s1, $t9
    ctx->r11 = ADD32(ctx->r17, ctx->r25);
    // 0x8003F8F0: lw          $a1, 0x11FC($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X11FC);
    // 0x8003F8F4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8003F8F8: beql        $v0, $a2, L_8003F914
    if (ctx->r2 == ctx->r6) {
        // 0x8003F8FC: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_8003F914;
    }
    goto skip_0;
    // 0x8003F8FC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8003F900: beql        $v0, $a3, L_8003F914
    if (ctx->r2 == ctx->r7) {
        // 0x8003F904: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_8003F914;
    }
    goto skip_1;
    // 0x8003F904: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x8003F908: bnel        $v0, $t0, L_8003F948
    if (ctx->r2 != ctx->r8) {
        // 0x8003F90C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8003F948;
    }
    goto skip_2;
    // 0x8003F90C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8003F910: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
L_8003F914:
    // 0x8003F914: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F918: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8003F91C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8003F920: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003F924: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    // 0x8003F928: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8003F92C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8003F930: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8003F934: jal         0x8003F75C
    // 0x8003F938: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8003F75C(rdram, ctx);
        goto after_0;
    // 0x8003F938: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8003F93C: b           L_8003F960
    // 0x8003F940: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003F960;
    // 0x8003F940: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F944: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8003F948:
    // 0x8003F948: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8003F94C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003F950: bne         $at, $zero, L_8003F8DC
    if (ctx->r1 != 0) {
        // 0x8003F954: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8003F8DC;
    }
    // 0x8003F954: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_8003F958:
    // 0x8003F958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003F95C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003F960:
    // 0x8003F960: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003F964: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003F968: jr          $ra
    // 0x8003F96C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003F96C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80056934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056934: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80056938: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005693C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80056940: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80056944: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80056948: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005694C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80056950: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80056954: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80056958: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8005695C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80056960: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80056964: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80056968: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005696C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80056970: sw          $t4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r12;
    // 0x80056974: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80056978: jal         0x8004921C
    // 0x8005697C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8005697C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80056980: sll         $s5, $v0, 16
    ctx->r21 = S32(ctx->r2 << 16);
    // 0x80056984: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80056988: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005698C: jal         0x8004921C
    // 0x80056990: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80056990: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80056994: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056998: lh          $t7, 0x144($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X144);
    // 0x8005699C: lw          $t9, 0x168($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X168);
    // 0x800569A0: lw          $v1, 0x16C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X16C);
    // 0x800569A4: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x800569A8: lui         $a2, 0x50
    ctx->r6 = S32(0X50 << 16);
    // 0x800569AC: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x800569B0: ori         $a2, $a2, 0x4340
    ctx->r6 = ctx->r6 | 0X4340;
    // 0x800569B4: addiu       $a1, $v1, 0xD
    ctx->r5 = ADD32(ctx->r3, 0XD);
    // 0x800569B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800569BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800569C0: nop

    // 0x800569C4: nop

    // 0x800569C8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800569CC: lw          $t6, 0x80($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X80);
    // 0x800569D0: lw          $t9, 0x1B0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1B0);
    // 0x800569D4: lw          $t7, 0x1CC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1CC);
    // 0x800569D8: mflo        $t8
    ctx->r24 = lo;
    // 0x800569DC: addu        $s4, $t8, $t6
    ctx->r20 = ADD32(ctx->r24, ctx->r14);
    // 0x800569E0: nop

    // 0x800569E4: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800569E8: lw          $t9, 0x1B8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1B8);
    // 0x800569EC: lw          $t7, 0x1BC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1BC);
    // 0x800569F0: mflo        $t8
    ctx->r24 = lo;
    // 0x800569F4: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800569F8: addu        $s2, $s1, $t6
    ctx->r18 = ADD32(ctx->r17, ctx->r14);
    // 0x800569FC: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056A00: mflo        $t8
    ctx->r24 = lo;
    // 0x80056A04: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80056A08: lw          $t7, 0x1C0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C0);
    // 0x80056A0C: lw          $t6, 0x1C4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C4);
    // 0x80056A10: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056A14: lui         $t7, 0x1F
    ctx->r15 = S32(0X1F << 16);
    // 0x80056A18: ori         $t7, $t7, 0x3205
    ctx->r15 = ctx->r15 | 0X3205;
    // 0x80056A1C: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x80056A20: mflo        $t9
    ctx->r25 = lo;
    // 0x80056A24: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x80056A28: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056A2C: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80056A30: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056A34: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80056A38: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80056A3C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056A40: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80056A44: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80056A48: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80056A4C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056A50: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80056A54: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80056A58: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056A5C: ori         $t9, $zero, 0xAC80
    ctx->r25 = 0 | 0XAC80;
    // 0x80056A60: ori         $t7, $t7, 0x18
    ctx->r15 = ctx->r15 | 0X18;
    // 0x80056A64: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80056A68: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80056A6C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80056A70: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80056A74: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056A78: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80056A7C: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x80056A80: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80056A84: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056A88: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80056A8C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80056A90: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056A94: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80056A98: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x80056A9C: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80056AA0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80056AA4: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80056AA8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80056AAC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056AB0: lui         $t7, 0xFF2F
    ctx->r15 = S32(0XFF2F << 16);
    // 0x80056AB4: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x80056AB8: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80056ABC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056AC0: ori         $t6, $t6, 0x1624
    ctx->r14 = ctx->r14 | 0X1624;
    // 0x80056AC4: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80056AC8: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80056ACC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80056AD0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056AD4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80056AD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056ADC: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80056AE0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056AE4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80056AE8: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x80056AEC: lbu         $t7, 0x3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X3);
    // 0x80056AF0: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x80056AF4: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80056AF8: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x80056AFC: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80056B00: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80056B04: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x80056B08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80056B0C: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x80056B10: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80056B14: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80056B18: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056B1C: addiu       $t6, $zero, 0x204
    ctx->r14 = ADD32(0, 0X204);
    // 0x80056B20: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x80056B24: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80056B28: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056B2C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80056B30: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80056B34: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056B38: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80056B3C: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x80056B40: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80056B44: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80056B48: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x80056B4C: ori         $t8, $t8, 0x8000
    ctx->r24 = ctx->r24 | 0X8000;
    // 0x80056B50: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80056B54: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80056B58: jal         0x8007711C
    // 0x80056B5C: sw          $t4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r12;
    func_8007711C(rdram, ctx);
        goto after_2;
    // 0x80056B5C: sw          $t4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r12;
    after_2:
    // 0x80056B60: lw          $t6, 0x1C8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C8);
    // 0x80056B64: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x80056B68: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80056B6C: blez        $t6, L_80056F10
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80056B70: lw          $v0, 0xC8($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XC8);
            goto L_80056F10;
    }
    // 0x80056B70: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x80056B74: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80056B78: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80056B7C: sll         $t7, $v0, 10
    ctx->r15 = S32(ctx->r2 << 10);
    // 0x80056B80: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80056B84: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x80056B88: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80056B8C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80056B90: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80056B94: lui         $fp, 0xFD50
    ctx->r30 = S32(0XFD50 << 16);
    // 0x80056B98: lui         $s7, 0xF200
    ctx->r23 = S32(0XF200 << 16);
    // 0x80056B9C: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
    // 0x80056BA0: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x80056BA4: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
L_80056BA8:
    // 0x80056BA8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056BAC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80056BB0: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80056BB4: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80056BB8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056BBC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80056BC0: sw          $s2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r18;
    // 0x80056BC4: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x80056BC8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80056BCC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056BD0: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x80056BD4: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80056BD8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056BDC: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
    // 0x80056BE0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80056BE4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056BE8: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80056BEC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80056BF0: sw          $fp, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r30;
    // 0x80056BF4: sw          $s4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r20;
    // 0x80056BF8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056BFC: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80056C00: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056C04: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80056C08: sw          $s6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r22;
    // 0x80056C0C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056C10: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80056C14: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80056C18: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056C1C: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
    // 0x80056C20: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80056C24: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056C28: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80056C2C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80056C30: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80056C34: lw          $t6, 0x1C4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C4);
    // 0x80056C38: lw          $v1, 0x1C0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C0);
    // 0x80056C3C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x80056C40: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80056C44: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056C48: mflo        $a0
    ctx->r4 = lo;
    // 0x80056C4C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80056C50: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80056C54: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80056C58: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x80056C5C: beq         $at, $zero, L_80056C6C
    if (ctx->r1 == 0) {
        // 0x80056C60: nop
    
            goto L_80056C6C;
    }
    // 0x80056C60: nop

    // 0x80056C64: b           L_80056C6C
    // 0x80056C68: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
        goto L_80056C6C;
    // 0x80056C68: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80056C6C:
    // 0x80056C6C: bgez        $v1, L_80056C7C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80056C70: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80056C7C;
    }
    // 0x80056C70: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80056C74: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80056C78: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80056C7C:
    // 0x80056C7C: bgtz        $v0, L_80056C8C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80056C80: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80056C8C;
    }
    // 0x80056C80: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80056C84: b           L_80056C8C
    // 0x80056C88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80056C8C;
    // 0x80056C88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80056C8C:
    // 0x80056C8C: bgtz        $v0, L_80056C9C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80056C90: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_80056C9C;
    }
    // 0x80056C90: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x80056C94: b           L_80056CA0
    // 0x80056C98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80056CA0;
    // 0x80056C98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80056C9C:
    // 0x80056C9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80056CA0:
    // 0x80056CA0: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x80056CA4: mflo        $t8
    ctx->r24 = lo;
    // 0x80056CA8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80056CAC: bne         $a1, $zero, L_80056CB8
    if (ctx->r5 != 0) {
        // 0x80056CB0: nop
    
            goto L_80056CB8;
    }
    // 0x80056CB0: nop

    // 0x80056CB4: break       7
    do_break(2147839156);
L_80056CB8:
    // 0x80056CB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056CBC: bne         $a1, $at, L_80056CD0
    if (ctx->r5 != ctx->r1) {
        // 0x80056CC0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80056CD0;
    }
    // 0x80056CC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80056CC4: bne         $t7, $at, L_80056CD0
    if (ctx->r15 != ctx->r1) {
        // 0x80056CC8: nop
    
            goto L_80056CD0;
    }
    // 0x80056CC8: nop

    // 0x80056CCC: break       6
    do_break(2147839180);
L_80056CD0:
    // 0x80056CD0: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x80056CD4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80056CD8: or          $t9, $t6, $s6
    ctx->r25 = ctx->r14 | ctx->r22;
    // 0x80056CDC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80056CE0: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80056CE4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056CE8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80056CEC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80056CF0: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80056CF4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80056CF8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80056CFC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80056D00: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056D04: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80056D08: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056D0C: lw          $t6, 0x1C0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C0);
    // 0x80056D10: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80056D14: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80056D18: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80056D1C: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x80056D20: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x80056D24: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80056D28: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80056D2C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056D30: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80056D34: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056D38: sw          $s7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r23;
    // 0x80056D3C: lw          $t8, 0x1C4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C4);
    // 0x80056D40: lw          $t9, 0x1C0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C0);
    // 0x80056D44: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80056D48: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80056D4C: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80056D50: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80056D54: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80056D58: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80056D5C: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80056D60: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80056D64: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056D68: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80056D6C: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80056D70: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056D74: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80056D78: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80056D7C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80056D80: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056D84: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80056D88: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056D8C: lh          $t6, 0xA($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XA);
    // 0x80056D90: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80056D94: srl         $t9, $t6, 7
    ctx->r25 = S32(U32(ctx->r14) >> 7);
    // 0x80056D98: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80056D9C: lh          $t9, 0x8($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X8);
    // 0x80056DA0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80056DA4: or          $t6, $t8, $s7
    ctx->r14 = ctx->r24 | ctx->r23;
    // 0x80056DA8: srl         $t7, $t9, 7
    ctx->r15 = S32(U32(ctx->r25) >> 7);
    // 0x80056DAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80056DB0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80056DB4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80056DB8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80056DBC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80056DC0: lh          $t6, 0xA($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XA);
    // 0x80056DC4: lw          $t9, 0x1C4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C4);
    // 0x80056DC8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80056DCC: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80056DD0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80056DD4: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x80056DD8: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80056DDC: lw          $t6, 0x1C0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C0);
    // 0x80056DE0: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80056DE4: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80056DE8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80056DEC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80056DF0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80056DF4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80056DF8: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80056DFC: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80056E00: lw          $v1, 0x1BC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1BC);
    // 0x80056E04: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80056E08: blezl       $v1, L_80056EE8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80056E0C: lw          $t9, 0xC8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC8);
            goto L_80056EE8;
    }
    goto skip_0;
    // 0x80056E0C: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    skip_0:
    // 0x80056E10: lw          $v0, 0x1B8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1B8);
L_80056E14:
    // 0x80056E14: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80056E18: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80056E1C: blez        $t7, L_80056ED4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80056E20: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80056ED4;
    }
    // 0x80056E20: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80056E24: sll         $a3, $a2, 1
    ctx->r7 = S32(ctx->r6 << 1);
    // 0x80056E28: addiu       $t2, $a3, 0x2
    ctx->r10 = ADD32(ctx->r7, 0X2);
    // 0x80056E2C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_80056E30:
    // 0x80056E30: andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
    // 0x80056E34: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80056E38: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80056E3C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056E40: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80056E44: lw          $t8, 0x1B8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1B8);
    // 0x80056E48: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80056E4C: addu        $t6, $t8, $a2
    ctx->r14 = ADD32(ctx->r24, ctx->r6);
    // 0x80056E50: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80056E54: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x80056E58: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80056E5C: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80056E60: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80056E64: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x80056E68: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80056E6C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80056E70: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80056E74: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x80056E78: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80056E7C: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80056E80: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80056E84: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80056E88: lw          $t7, 0x1B8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1B8);
    // 0x80056E8C: addu        $a1, $t7, $a2
    ctx->r5 = ADD32(ctx->r15, ctx->r6);
    // 0x80056E90: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80056E94: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80056E98: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80056E9C: addiu       $t7, $a1, 0x2
    ctx->r15 = ADD32(ctx->r5, 0X2);
    // 0x80056EA0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80056EA4: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80056EA8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80056EAC: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80056EB0: lw          $t8, 0x1B8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1B8);
    // 0x80056EB4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80056EB8: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80056EBC: slt         $at, $t1, $t6
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80056EC0: bnel        $at, $zero, L_80056E30
    if (ctx->r1 != 0) {
        // 0x80056EC4: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_80056E30;
    }
    goto skip_1;
    // 0x80056EC4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80056EC8: lw          $v1, 0x1BC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1BC);
    // 0x80056ECC: lw          $v0, 0x1B8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1B8);
    // 0x80056ED0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80056ED4:
    // 0x80056ED4: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x80056ED8: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80056EDC: bne         $at, $zero, L_80056E14
    if (ctx->r1 != 0) {
        // 0x80056EE0: addu        $t5, $t5, $v0
        ctx->r13 = ADD32(ctx->r13, ctx->r2);
            goto L_80056E14;
    }
    // 0x80056EE0: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80056EE4: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
L_80056EE8:
    // 0x80056EE8: lw          $t7, 0x1B8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1B8);
    // 0x80056EEC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80056EF0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x80056EF4: lw          $t7, 0x1C8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C8);
    // 0x80056EF8: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x80056EFC: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80056F00: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80056F04: addu        $s2, $s2, $t6
    ctx->r18 = ADD32(ctx->r18, ctx->r14);
    // 0x80056F08: bne         $at, $zero, L_80056BA8
    if (ctx->r1 != 0) {
        // 0x80056F0C: addu        $s4, $s4, $t9
        ctx->r20 = ADD32(ctx->r20, ctx->r25);
            goto L_80056BA8;
    }
    // 0x80056F0C: addu        $s4, $s4, $t9
    ctx->r20 = ADD32(ctx->r20, ctx->r25);
L_80056F10:
    // 0x80056F10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80056F14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80056F18: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80056F1C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80056F20: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80056F24: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80056F28: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80056F2C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80056F30: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80056F34: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80056F38: jr          $ra
    // 0x80056F3C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80056F3C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80428294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428294: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80428298: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x8042829C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804282A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804282A4: lb          $t7, 0x2($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X2);
    // 0x804282A8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804282AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804282B0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x804282B4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x804282B8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804282BC: jal         0x80065954
    // 0x804282C0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x804282C0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x804282C4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804282C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804282CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804282D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804282D4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804282D8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804282DC: bc1fl       L_80428358
    if (!c1cs) {
        // 0x804282E0: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80428358;
    }
    goto skip_0;
    // 0x804282E0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x804282E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804282E8: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x804282EC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EA8) << 16);
    // 0x804282F0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x804282F4: nop

    // 0x804282F8: bc1f        L_80428338
    if (!c1cs) {
        // 0x804282FC: nop
    
            goto L_80428338;
    }
    // 0x804282FC: nop

    // 0x80428300: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80428304: c.eq.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl == ctx->f8.fl;
    // 0x80428308: nop

    // 0x8042830C: bc1f        L_80428338
    if (!c1cs) {
        // 0x80428310: nop
    
            goto L_80428338;
    }
    // 0x80428310: nop

    // 0x80428314: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80428318: c.eq.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl == ctx->f10.fl;
    // 0x8042831C: nop

    // 0x80428320: bc1f        L_80428338
    if (!c1cs) {
        // 0x80428324: nop
    
            goto L_80428338;
    }
    // 0x80428324: nop

    // 0x80428328: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EA4) << 16);
    // 0x8042832C: lwc1        $f16, -0x681C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EA4));
    // 0x80428330: b           L_8042839C
    // 0x80428334: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_8042839C;
    // 0x80428334: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_80428338:
    // 0x80428338: lwc1        $f4, -0x6818($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EA8));
    // 0x8042833C: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80428340: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80428344: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80428348: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8042834C: b           L_8042839C
    // 0x80428350: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_8042839C;
    // 0x80428350: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80428354: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80428358:
    // 0x80428358: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8042835C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EB0) << 16);
    // 0x80428360: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80428364: nop

    // 0x80428368: bc1fl       L_80428390
    if (!c1cs) {
        // 0x8042836C: lwc1        $f18, 0x0($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80428390;
    }
    goto skip_1;
    // 0x8042836C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x80428370: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80428374: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EAC) << 16);
    // 0x80428378: lwc1        $f16, -0x6814($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EAC));
    // 0x8042837C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80428380: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80428384: b           L_8042839C
    // 0x80428388: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_8042839C;
    // 0x80428388: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8042838C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
L_80428390:
    // 0x80428390: lwc1        $f6, -0x6810($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EB0));
    // 0x80428394: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80428398: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_8042839C:
    // 0x8042839C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EB4) << 16);
    // 0x804283A0: lwc1        $f2, -0x680C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EB4));
    // 0x804283A4: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EB8) << 16);
    // 0x804283A8: lwc1        $f10, -0x6808($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EB8));
    // 0x804283AC: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804283B0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804283B4: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EBC) << 16);
    // 0x804283B8: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804283BC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804283C0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x804283C4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804283C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804283CC: nop

    // 0x804283D0: bc1f        L_804283E4
    if (!c1cs) {
        // 0x804283D4: nop
    
            goto L_804283E4;
    }
    // 0x804283D4: nop

    // 0x804283D8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x804283DC: b           L_80428400
    // 0x804283E0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
        goto L_80428400;
    // 0x804283E0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_804283E4:
    // 0x804283E4: lwc1        $f2, -0x6804($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EBC));
    // 0x804283E8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804283EC: nop

    // 0x804283F0: bc1fl       L_80428404
    if (!c1cs) {
        // 0x804283F4: lwc1        $f8, 0x50($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
            goto L_80428404;
    }
    goto skip_2;
    // 0x804283F4: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    skip_2:
    // 0x804283F8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x804283FC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_80428400:
    // 0x80428400: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
L_80428404:
    // 0x80428404: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80428408: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042840C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80428410: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x80428414: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x80428418: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8042841C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80428420: nop

    // 0x80428424: bc1fl       L_80428438
    if (!c1cs) {
        // 0x80428428: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80428438;
    }
    goto skip_3;
    // 0x80428428: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x8042842C: b           L_80428450
    // 0x80428430: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
        goto L_80428450;
    // 0x80428430: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    // 0x80428434: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80428438:
    // 0x80428438: nop

    // 0x8042843C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80428440: nop

    // 0x80428444: bc1fl       L_80428454
    if (!c1cs) {
        // 0x80428448: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80428454;
    }
    goto skip_4;
    // 0x80428448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8042844C: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_80428450:
    // 0x80428450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80428454:
    // 0x80428454: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80428458: jr          $ra
    // 0x8042845C: nop

    return;
    // 0x8042845C: nop

;}
RECOMP_FUNC void func_80741148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741148: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8074114C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X1144) << 16);
    // 0x80741150: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80741154: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x80741158: addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // 0x8074115C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80741160: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80741164: lwc1        $f4, 0x1FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X1144));
    // 0x80741168: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11DC) << 16);
    // 0x8074116C: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x80741170: swc1        $f4, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f4.u32l;
    // 0x80741174: lwc1        $f6, 0x203C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11DC));
    // 0x80741178: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8074117C: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
    // 0x80741180: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x80741184: jr          $ra
    // 0x80741188: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80741188: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80009930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009930: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80009934: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80009938: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x8000993C: addiu       $s2, $s2, 0x4D10
    ctx->r18 = ADD32(ctx->r18, 0X4D10);
    // 0x80009940: lw          $t6, 0x1DB4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1DB4);
    // 0x80009944: lh          $v1, 0x1D7C($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1D7C);
    // 0x80009948: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000994C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80009950: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x80009954: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80009958: mfhi        $a0
    ctx->r4 = hi;
    // 0x8000995C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80009960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009964: sw          $t7, 0x1DB4($s2)
    MEM_W(0X1DB4, ctx->r18) = ctx->r15;
    // 0x80009968: bne         $v1, $zero, L_80009974
    if (ctx->r3 != 0) {
        // 0x8000996C: nop
    
            goto L_80009974;
    }
    // 0x8000996C: nop

    // 0x80009970: break       7
    do_break(2147522928);
L_80009974:
    // 0x80009974: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009978: bne         $v1, $at, L_8000998C
    if (ctx->r3 != ctx->r1) {
        // 0x8000997C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000998C;
    }
    // 0x8000997C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009980: bne         $a3, $at, L_8000998C
    if (ctx->r7 != ctx->r1) {
        // 0x80009984: nop
    
            goto L_8000998C;
    }
    // 0x80009984: nop

    // 0x80009988: break       6
    do_break(2147522952);
L_8000998C:
    // 0x8000998C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80009990: beq         $a0, $zero, L_80009A08
    if (ctx->r4 == 0) {
        // 0x80009994: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80009A08;
    }
    // 0x80009994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009998: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000999C: lw          $v0, -0x5AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5AF8);
    // 0x800099A0: beql        $v0, $zero, L_800099F0
    if (ctx->r2 == 0) {
        // 0x800099A4: addiu       $t9, $a0, 0x1
        ctx->r25 = ADD32(ctx->r4, 0X1);
            goto L_800099F0;
    }
    goto skip_0;
    // 0x800099A4: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800099A8: jalr        $v0
    // 0x800099AC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800099AC: nop

    after_0:
    // 0x800099B0: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800099B4: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800099B8: lw          $t8, 0x6AC4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6AC4);
    // 0x800099BC: lh          $v1, 0x6A8C($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6A8C);
    // 0x800099C0: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x800099C4: mfhi        $a0
    ctx->r4 = hi;
    // 0x800099C8: bne         $v1, $zero, L_800099D4
    if (ctx->r3 != 0) {
        // 0x800099CC: nop
    
            goto L_800099D4;
    }
    // 0x800099CC: nop

    // 0x800099D0: break       7
    do_break(2147523024);
L_800099D4:
    // 0x800099D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800099D8: bne         $v1, $at, L_800099EC
    if (ctx->r3 != ctx->r1) {
        // 0x800099DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800099EC;
    }
    // 0x800099DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800099E0: bne         $t8, $at, L_800099EC
    if (ctx->r24 != ctx->r1) {
        // 0x800099E4: nop
    
            goto L_800099EC;
    }
    // 0x800099E4: nop

    // 0x800099E8: break       6
    do_break(2147523048);
L_800099EC:
    // 0x800099EC: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
L_800099F0:
    // 0x800099F0: bne         $v1, $t9, L_80009A00
    if (ctx->r3 != ctx->r25) {
        // 0x800099F4: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80009A00;
    }
    // 0x800099F4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800099F8: b           L_80009E94
    // 0x800099FC: lw          $v0, -0x79AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X79AC);
        goto L_80009E94;
    // 0x800099FC: lw          $v0, -0x79AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X79AC);
L_80009A00:
    // 0x80009A00: b           L_80009E94
    // 0x80009A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80009E94;
    // 0x80009A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009A08:
    // 0x80009A08: jal         0x80082210
    // 0x80009A0C: lw          $a0, 0x4F8C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4F8C);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80009A0C: lw          $a0, 0x4F8C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4F8C);
    after_1:
    // 0x80009A10: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80009A14: lw          $t3, 0x1DC0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X1DC0);
    // 0x80009A18: lw          $t1, 0x1DBC($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1DBC);
    // 0x80009A1C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80009A20: div         $zero, $t4, $v1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r3)));
    // 0x80009A24: mfhi        $t6
    ctx->r14 = hi;
    // 0x80009A28: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80009A2C: or          $t5, $t4, $zero
    ctx->r13 = ctx->r12 | 0;
    // 0x80009A30: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x80009A34: sw          $t4, 0x1DC0($s2)
    MEM_W(0X1DC0, ctx->r18) = ctx->r12;
    // 0x80009A38: mfhi        $s0
    ctx->r16 = hi;
    // 0x80009A3C: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x80009A40: sw          $t2, 0x1DBC($s2)
    MEM_W(0X1DBC, ctx->r18) = ctx->r10;
    // 0x80009A44: bne         $v1, $zero, L_80009A50
    if (ctx->r3 != 0) {
        // 0x80009A48: nop
    
            goto L_80009A50;
    }
    // 0x80009A48: nop

    // 0x80009A4C: break       7
    do_break(2147523148);
L_80009A50:
    // 0x80009A50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009A54: bne         $v1, $at, L_80009A68
    if (ctx->r3 != ctx->r1) {
        // 0x80009A58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80009A68;
    }
    // 0x80009A58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009A5C: bne         $t5, $at, L_80009A68
    if (ctx->r13 != ctx->r1) {
        // 0x80009A60: nop
    
            goto L_80009A68;
    }
    // 0x80009A60: nop

    // 0x80009A64: break       6
    do_break(2147523172);
L_80009A68:
    // 0x80009A68: sw          $t6, 0x1DC0($s2)
    MEM_W(0X1DC0, ctx->r18) = ctx->r14;
    // 0x80009A6C: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x80009A70: bne         $v1, $zero, L_80009A7C
    if (ctx->r3 != 0) {
        // 0x80009A74: nop
    
            goto L_80009A7C;
    }
    // 0x80009A74: nop

    // 0x80009A78: break       7
    do_break(2147523192);
L_80009A7C:
    // 0x80009A7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009A80: bne         $v1, $at, L_80009A94
    if (ctx->r3 != ctx->r1) {
        // 0x80009A84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80009A94;
    }
    // 0x80009A84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009A88: bne         $t8, $at, L_80009A94
    if (ctx->r24 != ctx->r1) {
        // 0x80009A8C: nop
    
            goto L_80009A94;
    }
    // 0x80009A8C: nop

    // 0x80009A90: break       6
    do_break(2147523216);
L_80009A94:
    // 0x80009A94: jal         0x8008EEE0
    // 0x80009A98: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_2;
    // 0x80009A98: nop

    after_2:
    // 0x80009A9C: lw          $t1, 0x1E9C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1E9C);
    // 0x80009AA0: srl         $t9, $v0, 2
    ctx->r25 = S32(U32(ctx->r2) >> 2);
    // 0x80009AA4: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x80009AA8: sltiu       $at, $t1, 0x10
    ctx->r1 = ctx->r9 < 0X10 ? 1 : 0;
    // 0x80009AAC: beq         $at, $zero, L_80009ADC
    if (ctx->r1 == 0) {
        // 0x80009AB0: sll         $t2, $s0, 1
        ctx->r10 = S32(ctx->r16 << 1);
            goto L_80009ADC;
    }
    // 0x80009AB0: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x80009AB4: addu        $a2, $s2, $t2
    ctx->r6 = ADD32(ctx->r18, ctx->r10);
    // 0x80009AB8: lh          $v0, 0x1E8C($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E8C);
    // 0x80009ABC: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80009AC0: addu        $v1, $s2, $t3
    ctx->r3 = ADD32(ctx->r18, ctx->r11);
    // 0x80009AC4: beq         $v0, $zero, L_80009ADC
    if (ctx->r2 == 0) {
        // 0x80009AC8: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_80009ADC;
    }
    // 0x80009AC8: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80009ACC: lw          $a0, 0x1E80($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1E80);
    // 0x80009AD0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80009AD4: jal         0x8000AD10
    // 0x80009AD8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    func_8000AD10(rdram, ctx);
        goto after_3;
    // 0x80009AD8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_3:
L_80009ADC:
    // 0x80009ADC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80009AE0: lw          $v0, -0x5AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5AF8);
    // 0x80009AE4: beql        $v0, $zero, L_80009AF8
    if (ctx->r2 == 0) {
        // 0x80009AE8: lw          $v1, 0x1DB8($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X1DB8);
            goto L_80009AF8;
    }
    goto skip_1;
    // 0x80009AE8: lw          $v1, 0x1DB8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1DB8);
    skip_1:
    // 0x80009AEC: jalr        $v0
    // 0x80009AF0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80009AF0: nop

    after_4:
    // 0x80009AF4: lw          $v1, 0x1DB8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1DB8);
L_80009AF8:
    // 0x80009AF8: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80009AFC: addiu       $s1, $s1, 0x6114
    ctx->r17 = ADD32(ctx->r17, 0X6114);
    // 0x80009B00: blez        $v1, L_80009B3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80009B04: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80009B3C;
    }
    // 0x80009B04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80009B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80009B0C:
    // 0x80009B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80009B10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009B14: jal         0x800824B0
    // 0x80009B18: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80009B18: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_5:
    // 0x80009B1C: bne         $v0, $zero, L_80009B28
    if (ctx->r2 != 0) {
        // 0x80009B20: lw          $v1, 0x5C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X5C);
            goto L_80009B28;
    }
    // 0x80009B20: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80009B24: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80009B28:
    // 0x80009B28: lw          $t4, 0x1DB8($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X1DB8);
    // 0x80009B2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80009B30: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80009B34: bnel        $at, $zero, L_80009B0C
    if (ctx->r1 != 0) {
        // 0x80009B38: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80009B0C;
    }
    goto skip_2;
    // 0x80009B38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
L_80009B3C:
    // 0x80009B3C: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80009B40: beq         $v1, $zero, L_80009B74
    if (ctx->r3 == 0) {
        // 0x80009B44: addiu       $s1, $s1, 0x6114
        ctx->r17 = ADD32(ctx->r17, 0X6114);
            goto L_80009B74;
    }
    // 0x80009B44: addiu       $s1, $s1, 0x6114
    ctx->r17 = ADD32(ctx->r17, 0X6114);
    // 0x80009B48: blez        $v1, L_80009B74
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80009B4C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80009B74;
    }
    // 0x80009B4C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80009B50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80009B54:
    // 0x80009B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80009B58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80009B5C: jal         0x800824B0
    // 0x80009B60: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80009B60: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80009B64: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80009B68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80009B6C: bnel        $s0, $v1, L_80009B54
    if (ctx->r16 != ctx->r3) {
        // 0x80009B70: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80009B54;
    }
    goto skip_3;
    // 0x80009B70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
L_80009B74:
    // 0x80009B74: lw          $v1, 0x140C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X140C);
    // 0x80009B78: beq         $v1, $zero, L_80009BAC
    if (ctx->r3 == 0) {
        // 0x80009B7C: nop
    
            goto L_80009BAC;
    }
    // 0x80009B7C: nop

    // 0x80009B80: blez        $v1, L_80009BAC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80009B84: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80009BAC;
    }
    // 0x80009B84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80009B88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80009B8C:
    // 0x80009B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80009B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009B94: jal         0x800824B0
    // 0x80009B98: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80009B98: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_7:
    // 0x80009B9C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80009BA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80009BA4: bnel        $s0, $v1, L_80009B8C
    if (ctx->r16 != ctx->r3) {
        // 0x80009BA8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80009B8C;
    }
    goto skip_4;
    // 0x80009BA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
L_80009BAC:
    // 0x80009BAC: jal         0x80005F80
    // 0x80009BB0: sw          $zero, 0x1DB8($s2)
    MEM_W(0X1DB8, ctx->r18) = 0;
    func_80005F80(rdram, ctx);
        goto after_8;
    // 0x80009BB0: sw          $zero, 0x1DB8($s2)
    MEM_W(0X1DB8, ctx->r18) = 0;
    after_8:
    // 0x80009BB4: jal         0x80007B44
    // 0x80009BB8: lbu         $a0, 0x2A22($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X2A22);
    func_80007B44(rdram, ctx);
        goto after_9;
    // 0x80009BB8: lbu         $a0, 0x2A22($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X2A22);
    after_9:
    // 0x80009BBC: lbu         $t5, 0x2A22($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X2A22);
    // 0x80009BC0: beql        $t5, $zero, L_80009C08
    if (ctx->r13 == 0) {
        // 0x80009BC4: lw          $t7, 0x1E9C($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X1E9C);
            goto L_80009C08;
    }
    goto skip_5;
    // 0x80009BC4: lw          $t7, 0x1E9C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1E9C);
    skip_5:
    // 0x80009BC8: jal         0x80004AD8
    // 0x80009BCC: nop

    func_80004AD8(rdram, ctx);
        goto after_10;
    // 0x80009BCC: nop

    after_10:
    // 0x80009BD0: bnel        $v0, $zero, L_80009C08
    if (ctx->r2 != 0) {
        // 0x80009BD4: lw          $t7, 0x1E9C($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X1E9C);
            goto L_80009C08;
    }
    goto skip_6;
    // 0x80009BD4: lw          $t7, 0x1E9C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1E9C);
    skip_6:
    // 0x80009BD8: lbu         $t6, 0x2A22($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X2A22);
    // 0x80009BDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009BE0: bne         $t6, $zero, L_80009BF4
    if (ctx->r14 != 0) {
        // 0x80009BE4: nop
    
            goto L_80009BF4;
    }
    // 0x80009BE4: nop

    // 0x80009BE8: lw          $a0, 0x4F88($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4F88);
    // 0x80009BEC: jal         0x80082210
    // 0x80009BF0: lbu         $a1, 0x2A23($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X2A23);
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80009BF0: lbu         $a1, 0x2A23($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X2A23);
    after_11:
L_80009BF4:
    // 0x80009BF4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80009BF8: sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
    // 0x80009BFC: b           L_80009E94
    // 0x80009C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80009E94;
    // 0x80009C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009C04: lw          $t7, 0x1E9C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1E9C);
L_80009C08:
    // 0x80009C08: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x80009C0C: bnel        $at, $zero, L_80009C20
    if (ctx->r1 != 0) {
        // 0x80009C10: lw          $t8, 0x1E9C($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X1E9C);
            goto L_80009C20;
    }
    goto skip_7;
    // 0x80009C10: lw          $t8, 0x1E9C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1E9C);
    skip_7:
    // 0x80009C14: b           L_80009E94
    // 0x80009C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80009E94;
    // 0x80009C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009C1C: lw          $t8, 0x1E9C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1E9C);
L_80009C20:
    // 0x80009C20: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x80009C24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80009C28: beq         $t8, $zero, L_80009C3C
    if (ctx->r24 == 0) {
        // 0x80009C2C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80009C3C;
    }
    // 0x80009C2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009C30: lw          $v0, 0x1E9C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1E9C);
    // 0x80009C34: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80009C38: sw          $t9, 0x1E9C($s2)
    MEM_W(0X1E9C, ctx->r18) = ctx->r25;
L_80009C3C:
    // 0x80009C3C: lw          $v1, 0x1DBC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1DBC);
    // 0x80009C40: lw          $s0, 0x1DC0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X1DC0);
    // 0x80009C44: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80009C48: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x80009C4C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80009C50: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x80009C54: addiu       $t3, $t2, 0x1DD8
    ctx->r11 = ADD32(ctx->r10, 0X1DD8);
    // 0x80009C58: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80009C5C: sw          $t3, 0x1DD0($s2)
    MEM_W(0X1DD0, ctx->r18) = ctx->r11;
    // 0x80009C60: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x80009C64: lw          $t6, 0x1DC4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1DC4);
    // 0x80009C68: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80009C6C: lh          $t3, 0x1D82($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X1D82);
    // 0x80009C70: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80009C74: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x80009C78: sw          $t6, 0x1DCC($s2)
    MEM_W(0X1DCC, ctx->r18) = ctx->r14;
    // 0x80009C7C: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80009C80: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80009C84: addiu       $t6, $t5, 0x80
    ctx->r14 = ADD32(ctx->r13, 0X80);
    // 0x80009C88: lw          $t1, 0x1E80($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X1E80);
    // 0x80009C8C: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x80009C90: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x80009C94: addu        $t0, $s2, $t2
    ctx->r8 = ADD32(ctx->r18, ctx->r10);
    // 0x80009C98: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80009C9C: sh          $t8, 0x1E8C($t0)
    MEM_H(0X1E8C, ctx->r8) = ctx->r24;
    // 0x80009CA0: lh          $a0, 0x1D86($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X1D86);
    // 0x80009CA4: lh          $v0, 0x1E8C($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X1E8C);
    // 0x80009CA8: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x80009CAC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80009CB0: beql        $at, $zero, L_80009CC4
    if (ctx->r1 == 0) {
        // 0x80009CB4: lh          $v1, 0x1D84($s2)
        ctx->r3 = MEM_H(ctx->r18, 0X1D84);
            goto L_80009CC4;
    }
    goto skip_8;
    // 0x80009CB4: lh          $v1, 0x1D84($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1D84);
    skip_8:
    // 0x80009CB8: sh          $a0, 0x1E8C($t0)
    MEM_H(0X1E8C, ctx->r8) = ctx->r4;
    // 0x80009CBC: lh          $v0, 0x1E8C($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X1E8C);
    // 0x80009CC0: lh          $v1, 0x1D84($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1D84);
L_80009CC4:
    // 0x80009CC4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009CC8: beql        $at, $zero, L_80009CD8
    if (ctx->r1 == 0) {
        // 0x80009CCC: lbu         $t9, 0x2A22($s2)
        ctx->r25 = MEM_BU(ctx->r18, 0X2A22);
            goto L_80009CD8;
    }
    goto skip_9;
    // 0x80009CCC: lbu         $t9, 0x2A22($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X2A22);
    skip_9:
    // 0x80009CD0: sh          $v1, 0x1E8C($t0)
    MEM_H(0X1E8C, ctx->r8) = ctx->r3;
    // 0x80009CD4: lbu         $t9, 0x2A22($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X2A22);
L_80009CD8:
    // 0x80009CD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80009CDC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80009CE0: bnel        $t9, $zero, L_80009D48
    if (ctx->r25 != 0) {
        // 0x80009CE4: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_80009D48;
    }
    goto skip_10;
    // 0x80009CE4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_10:
    // 0x80009CE8: lw          $a0, 0x4F90($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4F90);
    // 0x80009CEC: jal         0x800824B0
    // 0x80009CF0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    osRecvMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80009CF0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_12:
    // 0x80009CF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009CF8: beq         $v0, $at, L_80009D28
    if (ctx->r2 == ctx->r1) {
        // 0x80009CFC: nop
    
            goto L_80009D28;
    }
    // 0x80009CFC: nop

L_80009D00:
    // 0x80009D00: jal         0x8000A480
    // 0x80009D04: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_8000A480(rdram, ctx);
        goto after_13;
    // 0x80009D04: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_13:
    // 0x80009D08: lw          $a0, 0x4F90($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4F90);
    // 0x80009D0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80009D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009D14: jal         0x800824B0
    // 0x80009D18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80009D18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_14:
    // 0x80009D1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009D20: bne         $v0, $at, L_80009D00
    if (ctx->r2 != ctx->r1) {
        // 0x80009D24: nop
    
            goto L_80009D00;
    }
    // 0x80009D24: nop

L_80009D28:
    // 0x80009D28: bnel        $s0, $zero, L_80009D48
    if (ctx->r16 != 0) {
        // 0x80009D2C: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_80009D48;
    }
    goto skip_11;
    // 0x80009D2C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_11:
    // 0x80009D30: lbu         $t1, 0x4F7E($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X4F7E);
    // 0x80009D34: beql        $t1, $zero, L_80009D48
    if (ctx->r9 == 0) {
        // 0x80009D38: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_80009D48;
    }
    goto skip_12;
    // 0x80009D38: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_12:
    // 0x80009D3C: jal         0x8000A3E8
    // 0x80009D40: nop

    func_8000A3E8(rdram, ctx);
        goto after_15;
    // 0x80009D40: nop

    after_15:
    // 0x80009D44: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80009D48:
    // 0x80009D48: lw          $a0, 0x1DCC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1DCC);
    // 0x80009D4C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80009D50: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80009D54: jal         0x800007B0
    // 0x80009D58: lh          $a3, 0x1E8C($t0)
    ctx->r7 = MEM_H(ctx->r8, 0X1E8C);
    func_800007B0(rdram, ctx);
        goto after_16;
    // 0x80009D58: lh          $a3, 0x1E8C($t0)
    ctx->r7 = MEM_H(ctx->r8, 0X1E8C);
    after_16:
    // 0x80009D5C: jal         0x800883C0
    // 0x80009D60: sw          $v0, 0x1DCC($s2)
    MEM_W(0X1DCC, ctx->r18) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_17;
    // 0x80009D60: sw          $v0, 0x1DCC($s2)
    MEM_W(0X1DCC, ctx->r18) = ctx->r2;
    after_17:
    // 0x80009D64: lw          $a3, 0x1DB4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X1DB4);
    // 0x80009D68: lw          $t2, 0x1E94($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X1E94);
    // 0x80009D6C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80009D70: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x80009D74: addu        $t3, $t2, $a3
    ctx->r11 = ADD32(ctx->r10, ctx->r7);
    // 0x80009D78: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80009D7C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80009D80: lui         $t7, 0x8001
    ctx->r15 = S32(0X8001 << 16);
    // 0x80009D84: addiu       $t7, $t7, -0x66D0
    ctx->r15 = ADD32(ctx->r15, -0X66D0);
    // 0x80009D88: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80009D8C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80009D90: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80009D94: addiu       $a2, $a2, 0x4080
    ctx->r6 = ADD32(ctx->r6, 0X4080);
    // 0x80009D98: addiu       $t2, $t2, 0x4360
    ctx->r10 = ADD32(ctx->r10, 0X4360);
    // 0x80009D9C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80009DA0: mflo        $t4
    ctx->r12 = lo;
    // 0x80009DA4: sw          $t4, 0x1E94($s2)
    MEM_W(0X1E94, ctx->r18) = ctx->r12;
    // 0x80009DA8: lw          $t6, 0x1E80($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1E80);
    // 0x80009DAC: addiu       $a0, $a0, 0x4260
    ctx->r4 = ADD32(ctx->r4, 0X4260);
    // 0x80009DB0: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x80009DB4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80009DB8: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x80009DBC: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x80009DC0: andi        $t5, $t3, 0xFFF0
    ctx->r13 = ctx->r11 & 0XFFF0;
    // 0x80009DC4: sw          $t3, 0x1E94($s2)
    MEM_W(0X1E94, ctx->r18) = ctx->r11;
    // 0x80009DC8: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x80009DCC: sw          $t6, 0x61D0($at)
    MEM_W(0X61D0, ctx->r1) = ctx->r14;
    // 0x80009DD0: lw          $t8, 0x1DD0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1DD0);
    // 0x80009DD4: lw          $s0, 0x1DBC($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X1DBC);
    // 0x80009DD8: subu        $t3, $t2, $a2
    ctx->r11 = SUB32(ctx->r10, ctx->r6);
    // 0x80009DDC: sw          $zero, 0x40($t8)
    MEM_W(0X40, ctx->r24) = 0;
    // 0x80009DE0: lw          $t9, 0x1DD0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X1DD0);
    // 0x80009DE4: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80009DE8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80009DEC: sw          $zero, 0x44($t9)
    MEM_W(0X44, ctx->r25) = 0;
    // 0x80009DF0: lw          $v1, 0x1DD0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1DD0);
    // 0x80009DF4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80009DF8: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80009DFC: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80009E00: addu        $t8, $s2, $t6
    ctx->r24 = ADD32(ctx->r18, ctx->r14);
    // 0x80009E04: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80009E08: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80009E0C: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x80009E10: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x80009E14: sw          $t7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r15;
    // 0x80009E18: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x80009E1C: sw          $a2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r6;
    // 0x80009E20: sw          $a1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r5;
    // 0x80009E24: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x80009E28: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x80009E2C: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x80009E30: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x80009E34: lw          $t9, 0x1DC4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1DC4);
    // 0x80009E38: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80009E3C: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
    // 0x80009E40: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x80009E44: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x80009E48: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x80009E4C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80009E50: sw          $t2, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r10;
    // 0x80009E54: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80009E58: lw          $t3, -0x79B0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X79B0);
    // 0x80009E5C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80009E60: beq         $at, $zero, L_80009E6C
    if (ctx->r1 == 0) {
        // 0x80009E64: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_80009E6C;
    }
    // 0x80009E64: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80009E68: sw          $t4, -0x79B0($at)
    MEM_W(-0X79B0, ctx->r1) = ctx->r12;
L_80009E6C:
    // 0x80009E6C: lh          $t5, 0x1D7C($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X1D7C);
    // 0x80009E70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009E74: bnel        $t5, $at, L_80009E88
    if (ctx->r13 != ctx->r1) {
        // 0x80009E78: lw          $t7, 0x1DD0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X1DD0);
            goto L_80009E88;
    }
    goto skip_13;
    // 0x80009E78: lw          $t7, 0x1DD0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1DD0);
    skip_13:
    // 0x80009E7C: b           L_80009E94
    // 0x80009E80: lw          $v0, 0x1DD0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1DD0);
        goto L_80009E94;
    // 0x80009E80: lw          $v0, 0x1DD0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1DD0);
    // 0x80009E84: lw          $t7, 0x1DD0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1DD0);
L_80009E88:
    // 0x80009E88: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80009E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009E90: sw          $t7, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = ctx->r15;
L_80009E94:
    // 0x80009E94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009E98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009E9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009EA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80009EA4: jr          $ra
    // 0x80009EA8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80009EA8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_806F8E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8E98: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806F8E9C: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(694, 0XC38) << 16);
    // 0x806F8EA0: addiu       $t6, $t6, -0x7BB8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(694, 0XC38));
    // 0x806F8EA4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F8EA8: jr          $ra
    // 0x806F8EAC: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x806F8EAC: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806B15D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B15D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B15D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B15DC: jal         0x806B1524
    // 0x806B15E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806B1524(rdram, ctx);
        goto after_0;
    // 0x806B15E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806B15E4: beq         $v0, $zero, L_806B1648
    if (ctx->r2 == 0) {
        // 0x806B15E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806B1648;
    }
    // 0x806B15E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806B15EC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806B15F0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806B15F4: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(598, 0X16D0) << 16);
    // 0x806B15F8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806B15FC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806B1600: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806B1604: addiu       $t7, $t7, 0x1660
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(598, 0X16D0));
    // 0x806B1608: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806B160C: lui         $t0, 0x806B
    ctx->r8 = S32(RELOC_HI16(598, 0X103C) << 16);
    // 0x806B1610: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806B1614: addiu       $t0, $t0, 0xFCC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(598, 0X103C));
    // 0x806B1618: sb          $t9, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r25;
    // 0x806B161C: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806B1620: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x806B1624: jal         0x806B1578
    // 0x806B1628: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806B1578(rdram, ctx);
        goto after_1;
    // 0x806B1628: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x806B162C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806B1630: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x806B1634: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x806B1638: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806B163C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806B1640: sw          $t1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r9;
    // 0x806B1644: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
L_806B1648:
    // 0x806B1648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B164C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B1650: jr          $ra
    // 0x806B1654: nop

    return;
    // 0x806B1654: nop

    // 0x806B1658: nop

    // 0x806B165C: nop

;}
RECOMP_FUNC void func_80526FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526FAC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80526FB0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80526FB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80526FB8: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80526FBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80526FC0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80526FC4: nop

    // 0x80526FC8: bc1fl       L_8052701C
    if (!c1cs) {
        // 0x80526FCC: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8052701C;
    }
    goto skip_0;
    // 0x80526FCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80526FD0: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80526FD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80526FD8: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80526FDC: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80526FE0: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80526FE4: bne         $at, $zero, L_80526FFC
    if (ctx->r1 != 0) {
        // 0x80526FE8: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_80526FFC;
    }
    // 0x80526FE8: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80526FEC: jal         0x80527424
    // 0x80526FF0: nop

    func_80527424(rdram, ctx);
        goto after_0;
    // 0x80526FF0: nop

    after_0:
    // 0x80526FF4: b           L_8052702C
    // 0x80526FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8052702C;
    // 0x80526FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526FFC:
    // 0x80526FFC: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80527000: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80527004: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80527008: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8052700C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80527010: b           L_80527028
    // 0x80527014: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80527028;
    // 0x80527014: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80527018: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8052701C:
    // 0x8052701C: nop

    // 0x80527020: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80527024: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_80527028:
    // 0x80527028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052702C:
    // 0x8052702C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527030: jr          $ra
    // 0x80527034: nop

    return;
    // 0x80527034: nop

;}
RECOMP_FUNC void func_804BD6AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD6AC: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(191, 0X1E3C) << 16);
    // 0x804BD6B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804BD6B4: addiu       $t7, $t7, -0x2894
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(191, 0X1E3C));
    // 0x804BD6B8: sh          $t6, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r14;
    // 0x804BD6BC: jr          $ra
    // 0x804BD6C0: sw          $t7, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r15;
    return;
    // 0x804BD6C0: sw          $t7, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80454604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454604: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454608: addiu       $a1, $zero, 0x744
    ctx->r5 = ADD32(0, 0X744);
    // 0x8045460C: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80454610: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x80454614: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x80454618: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x8045461C: sw          $a1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r5;
    // 0x80454620: sw          $a1, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r5;
    // 0x80454624: sw          $a1, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->r5;
    // 0x80454628: jr          $ra
    // 0x8045462C: sw          $t6, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r14;
    return;
    // 0x8045462C: sw          $t6, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8000ACD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ACD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000ACD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ACD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000ACDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000ACE0: jal         0x800825F0
    // 0x8000ACE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8000ACE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8000ACE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000ACEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000ACF0: jal         0x80085FE0
    // 0x8000ACF4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x8000ACF4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8000ACF8: jal         0x800825F0
    // 0x8000ACFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x8000ACFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8000AD00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AD04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000AD08: jr          $ra
    // 0x8000AD0C: nop

    return;
    // 0x8000AD0C: nop

;}
RECOMP_FUNC void func_806FAC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FAC7C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x806FAC80: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x806FAC84: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x806FAC88: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x806FAC8C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x806FAC90: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x806FAC94: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x806FAC98: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x806FAC9C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x806FACA0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806FACA4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806FACA8: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x806FACAC: lw          $s1, 0x10($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X10);
    // 0x806FACB0: lh          $s2, 0x6($a1)
    ctx->r18 = MEM_H(ctx->r5, 0X6);
    // 0x806FACB4: lwc1        $f4, 0x3C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x806FACB8: lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X70);
    // 0x806FACBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806FACC0: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x806FACC4: lwc1        $f6, 0x40($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X40);
    // 0x806FACC8: beq         $v1, $zero, L_806FAE34
    if (ctx->r3 == 0) {
        // 0x806FACCC: swc1        $f6, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
            goto L_806FAE34;
    }
    // 0x806FACCC: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x806FACD0: beq         $s2, $zero, L_806FAE34
    if (ctx->r18 == 0) {
        // 0x806FACD4: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_806FAE34;
    }
    // 0x806FACD4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806FACD8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x806FACDC: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(700, 0X2AC8) << 16);
    // 0x806FACE0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x806FACE4: lwc1        $f24, -0x3908($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(700, 0X2AC8));
    // 0x806FACE8: addiu       $s4, $sp, 0x64
    ctx->r20 = ADD32(ctx->r29, 0X64);
    // 0x806FACEC: addiu       $s3, $sp, 0x68
    ctx->r19 = ADD32(ctx->r29, 0X68);
    // 0x806FACF0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_806FACF4:
    // 0x806FACF4: beq         $v0, $zero, L_806FAE24
    if (ctx->r2 == 0) {
        // 0x806FACF8: nop
    
            goto L_806FAE24;
    }
    // 0x806FACF8: nop

    // 0x806FACFC: beq         $a2, $v0, L_806FAE18
    if (ctx->r6 == ctx->r2) {
        // 0x806FAD00: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806FAE18;
    }
    // 0x806FAD00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806FAD04: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x806FAD08: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x806FAD0C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x806FAD10: jal         0x80047AB8
    // 0x806FAD14: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x806FAD14: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    after_0:
    // 0x806FAD18: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x806FAD1C: lwc1        $f8, 0xC8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC8);
    // 0x806FAD20: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x806FAD24: nop

    // 0x806FAD28: bc1fl       L_806FAE1C
    if (!c1cs) {
        // 0x806FAD2C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806FAE1C;
    }
    goto skip_0;
    // 0x806FAD2C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x806FAD30: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x806FAD34: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x806FAD38: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x806FAD3C: bnel        $t0, $zero, L_806FAE1C
    if (ctx->r8 != 0) {
        // 0x806FAD40: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806FAE1C;
    }
    goto skip_1;
    // 0x806FAD40: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
    // 0x806FAD44: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x806FAD48: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x806FAD4C: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x806FAD50: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x806FAD54: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806FAD58: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x806FAD5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FAD60: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x806FAD64: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x806FAD68: lw          $t2, 0x174($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X174);
    // 0x806FAD6C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806FAD70: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x806FAD74: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x806FAD78: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x806FAD7C: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x806FAD80: lw          $t3, 0x70($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X70);
    // 0x806FAD84: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x806FAD88: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x806FAD8C: lwc1        $f0, 0x4($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X4);
    // 0x806FAD90: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806FAD94: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806FAD98: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806FAD9C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x806FADA0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806FADA4: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x806FADA8: jal         0x806FAA54
    // 0x806FADAC: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    func_806FAA54(rdram, ctx);
        goto after_1;
    // 0x806FADAC: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x806FADB0: c.eq.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl == ctx->f24.fl;
    // 0x806FADB4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x806FADB8: bc1tl       L_806FAE1C
    if (c1cs) {
        // 0x806FADBC: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806FAE1C;
    }
    goto skip_2;
    // 0x806FADBC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_2:
    // 0x806FADC0: jal         0x80060ED0
    // 0x806FADC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060ED0(rdram, ctx);
        goto after_2;
    // 0x806FADC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806FADC8: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x806FADCC: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x806FADD0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x806FADD4: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x806FADD8: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x806FADDC: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x806FADE0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x806FADE4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x806FADE8: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x806FADEC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806FADF0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806FADF4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806FADF8: sub.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x806FADFC: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x806FAE00: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806FAE04: add.s       $f20, $f6, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x806FAE08: swc1        $f20, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f20.u32l;
    // 0x806FAE0C: lw          $t0, 0x3C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X3C);
    // 0x806FAE10: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x806FAE14: swc1        $f10, 0x120($t0)
    MEM_W(0X120, ctx->r8) = ctx->f10.u32l;
L_806FAE18:
    // 0x806FAE18: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_806FAE1C:
    // 0x806FAE1C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x806FAE20: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
L_806FAE24:
    // 0x806FAE24: beq         $v1, $zero, L_806FAE34
    if (ctx->r3 == 0) {
        // 0x806FAE28: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_806FAE34;
    }
    // 0x806FAE28: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806FAE2C: bnel        $s2, $zero, L_806FACF4
    if (ctx->r18 != 0) {
        // 0x806FAE30: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_806FACF4;
    }
    goto skip_3;
    // 0x806FAE30: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_3:
L_806FAE34:
    // 0x806FAE34: lh          $t1, 0x184($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X184);
    // 0x806FAE38: beql        $t1, $zero, L_806FAE54
    if (ctx->r9 == 0) {
        // 0x806FAE3C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_806FAE54;
    }
    goto skip_4;
    // 0x806FAE3C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x806FAE40: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x806FAE44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FAE48: jalr        $t9
    // 0x806FAE4C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x806FAE4C: nop

    after_3:
    // 0x806FAE50: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_806FAE54:
    // 0x806FAE54: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806FAE58: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806FAE5C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806FAE60: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x806FAE64: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x806FAE68: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x806FAE6C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x806FAE70: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x806FAE74: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x806FAE78: jr          $ra
    // 0x806FAE7C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x806FAE7C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_804A02C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A02C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A02C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A02CC: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804A02D0: lui         $t8, 0x804A
    ctx->r24 = S32(RELOC_HI16(170, 0X350) << 16);
    // 0x804A02D4: addiu       $t8, $t8, 0x3B0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(170, 0X350));
    // 0x804A02D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804A02DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804A02E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804A02E4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804A02E8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804A02EC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804A02F0: beql        $v1, $zero, L_804A0328
    if (ctx->r3 == 0) {
        // 0x804A02F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A0328;
    }
    goto skip_0;
    // 0x804A02F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A02F8: jalr        $v1
    // 0x804A02FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804A02FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A0300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A0304: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804A0308: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804A030C: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804A0310: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804A0314: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804A0318: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804A031C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804A0320: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804A0324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A0328:
    // 0x804A0328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A032C: jr          $ra
    // 0x804A0330: nop

    return;
    // 0x804A0330: nop

    // 0x804A0334: nop

    // 0x804A0338: nop

    // 0x804A033C: nop

;}
RECOMP_FUNC void func_8004F290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F290: lw          $t6, 0x1B8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004F294: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8004F298: addiu       $t7, $t7, -0x970
    ctx->r15 = ADD32(ctx->r15, -0X970);
    // 0x8004F29C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8004F2A0: sw          $t7, 0x1C0($a0)
    MEM_W(0X1C0, ctx->r4) = ctx->r15;
    // 0x8004F2A4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8004F2A8: jr          $ra
    // 0x8004F2AC: sb          $zero, -0x7D76($at)
    MEM_B(-0X7D76, ctx->r1) = 0;
    return;
    // 0x8004F2AC: sb          $zero, -0x7D76($at)
    MEM_B(-0X7D76, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8069D988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D988: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8069D98C: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(574, 0X730) << 16);
    // 0x8069D990: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8069D994: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8069D998: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8069D99C: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8069D9A0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8069D9A4: addiu       $t8, $t8, -0x2350
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(574, 0X730));
    // 0x8069D9A8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8069D9AC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8069D9B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8069D9B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8069D9B8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8069D9BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8069D9C0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8069D9C4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8069D9C8: nop

    // 0x8069D9CC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8069D9D0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8069D9D4: beql        $a2, $a0, L_8069DA60
    if (ctx->r6 == ctx->r4) {
        // 0x8069D9D8: swc1        $f18, 0x3C($t0)
        MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
            goto L_8069DA60;
    }
    goto skip_0;
    // 0x8069D9D8: swc1        $f18, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
    skip_0:
    // 0x8069D9DC: swc1        $f18, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
L_8069D9E0:
    // 0x8069D9E0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8069D9E4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8069D9E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8069D9EC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8069D9F0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8069D9F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8069D9F8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8069D9FC: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8069DA00: swc1        $f16, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f16.u32l;
    // 0x8069DA04: lwc1        $f16, -0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8069DA08: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x8069DA0C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8069DA10: swc1        $f16, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f16.u32l;
    // 0x8069DA14: lwc1        $f16, -0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8069DA18: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x8069DA1C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8069DA20: swc1        $f16, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f16.u32l;
    // 0x8069DA24: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x8069DA28: lwc1        $f16, -0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X8);
    // 0x8069DA2C: swc1        $f16, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f16.u32l;
    // 0x8069DA30: lw          $t6, -0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X4);
    // 0x8069DA34: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x8069DA38: sw          $t6, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r14;
    // 0x8069DA3C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8069DA40: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8069DA44: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8069DA48: nop

    // 0x8069DA4C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8069DA50: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8069DA54: bnel        $a2, $a0, L_8069D9E0
    if (ctx->r6 != ctx->r4) {
        // 0x8069DA58: swc1        $f18, 0x3C($t0)
        MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
            goto L_8069D9E0;
    }
    goto skip_1;
    // 0x8069DA58: swc1        $f18, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
    skip_1:
    // 0x8069DA5C: swc1        $f18, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
L_8069DA60:
    // 0x8069DA60: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8069DA64: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8069DA68: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8069DA6C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8069DA70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8069DA74: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8069DA78: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8069DA7C: swc1        $f16, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f16.u32l;
    // 0x8069DA80: lwc1        $f16, -0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8069DA84: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x8069DA88: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8069DA8C: swc1        $f16, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f16.u32l;
    // 0x8069DA90: lwc1        $f16, -0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8069DA94: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x8069DA98: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8069DA9C: swc1        $f16, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f16.u32l;
    // 0x8069DAA0: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x8069DAA4: lwc1        $f16, -0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X8);
    // 0x8069DAA8: swc1        $f16, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f16.u32l;
    // 0x8069DAAC: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x8069DAB0: lw          $t6, -0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X4);
    // 0x8069DAB4: sw          $t6, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r14;
    // 0x8069DAB8: jr          $ra
    // 0x8069DABC: nop

    return;
    // 0x8069DABC: nop

;}
RECOMP_FUNC void func_80516E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516E30: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(282, 0X84) << 16);
    // 0x80516E34: addiu       $v0, $v0, 0x6EB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(282, 0X84));
    // 0x80516E38: jr          $ra
    // 0x80516E3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80516E3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001FF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FF20: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x8001FF24: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8001FF28: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001FF2C: beq         $v1, $at, L_8001FF4C
    if (ctx->r3 == ctx->r1) {
        // 0x8001FF30: nop
    
            goto L_8001FF4C;
    }
    // 0x8001FF30: nop

    // 0x8001FF34: lbu         $t6, 0x154($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X154);
    // 0x8001FF38: bne         $t6, $zero, L_8001FF4C
    if (ctx->r14 != 0) {
        // 0x8001FF3C: nop
    
            goto L_8001FF4C;
    }
    // 0x8001FF3C: nop

    // 0x8001FF40: lbu         $t7, 0x21($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X21);
    // 0x8001FF44: beql        $t7, $zero, L_8001FF58
    if (ctx->r15 == 0) {
        // 0x8001FF48: lbu         $t8, 0xF4($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0XF4);
            goto L_8001FF58;
    }
    goto skip_0;
    // 0x8001FF48: lbu         $t8, 0xF4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF4);
    skip_0:
L_8001FF4C:
    // 0x8001FF4C: b           L_80020004
    // 0x8001FF50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80020004;
    // 0x8001FF50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FF54: lbu         $t8, 0xF4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF4);
L_8001FF58:
    // 0x8001FF58: beql        $t8, $zero, L_8001FF9C
    if (ctx->r24 == 0) {
        // 0x8001FF5C: lbu         $t4, 0x18($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X18);
            goto L_8001FF9C;
    }
    goto skip_1;
    // 0x8001FF5C: lbu         $t4, 0x18($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X18);
    skip_1:
    // 0x8001FF60: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x8001FF64: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x8001FF68: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001FF6C: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x8001FF70: bne         $t0, $zero, L_8001FF90
    if (ctx->r8 != 0) {
        // 0x8001FF74: addiu       $t2, $zero, 0xA
        ctx->r10 = ADD32(0, 0XA);
            goto L_8001FF90;
    }
    // 0x8001FF74: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8001FF78: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x8001FF7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001FF80: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x8001FF84: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001FF88: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8001FF8C: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
L_8001FF90:
    // 0x8001FF90: b           L_80020004
    // 0x8001FF94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80020004;
    // 0x8001FF94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FF98: lbu         $t4, 0x18($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X18);
L_8001FF9C:
    // 0x8001FF9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FFA0: bne         $t4, $at, L_80020000
    if (ctx->r12 != ctx->r1) {
        // 0x8001FFA4: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80020000;
    }
    // 0x8001FFA4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8001FFA8: beql        $v1, $at, L_80020004
    if (ctx->r3 == ctx->r1) {
        // 0x8001FFAC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80020004;
    }
    goto skip_2;
    // 0x8001FFAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x8001FFB0: lbu         $t5, 0x1F8($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1F8);
    // 0x8001FFB4: bnel        $t5, $zero, L_80020004
    if (ctx->r13 != 0) {
        // 0x8001FFB8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80020004;
    }
    goto skip_3;
    // 0x8001FFB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8001FFBC: lw          $t6, 0x12EC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X12EC);
    // 0x8001FFC0: bnel        $t6, $zero, L_80020004
    if (ctx->r14 != 0) {
        // 0x8001FFC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80020004;
    }
    goto skip_4;
    // 0x8001FFC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8001FFC8: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x8001FFCC: andi        $t7, $v1, 0x700
    ctx->r15 = ctx->r3 & 0X700;
    // 0x8001FFD0: beq         $t7, $zero, L_80020000
    if (ctx->r15 == 0) {
        // 0x8001FFD4: srl         $t8, $v1, 28
        ctx->r24 = S32(U32(ctx->r3) >> 28);
            goto L_80020000;
    }
    // 0x8001FFD4: srl         $t8, $v1, 28
    ctx->r24 = S32(U32(ctx->r3) >> 28);
    // 0x8001FFD8: beq         $t8, $zero, L_80020000
    if (ctx->r24 == 0) {
        // 0x8001FFDC: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_80020000;
    }
    // 0x8001FFDC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8001FFE0: lh          $t9, -0x7682($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X7682);
    // 0x8001FFE4: beql        $t9, $zero, L_80020004
    if (ctx->r25 == 0) {
        // 0x8001FFE8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80020004;
    }
    goto skip_5;
    // 0x8001FFE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x8001FFEC: lw          $t0, 0x138($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X138);
    // 0x8001FFF0: jal         0x8002ED3C
    // 0x8001FFF4: sw          $t0, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r8;
    func_8002ED3C(rdram, ctx);
        goto after_0;
    // 0x8001FFF4: sw          $t0, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r8;
    after_0:
    // 0x8001FFF8: b           L_80020004
    // 0x8001FFFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80020004;
    // 0x8001FFFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80020000:
    // 0x80020000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80020004:
    // 0x80020004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002000C: jr          $ra
    // 0x80020010: nop

    return;
    // 0x80020010: nop

;}
RECOMP_FUNC void func_8044CED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044CED4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8044CED8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8044CEDC: lui         $at, 0x3BB4
    ctx->r1 = S32(0X3BB4 << 16);
    // 0x8044CEE0: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8044CEE4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8044CEE8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8044CEEC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8044CEF0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8044CEF4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8044CEF8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8044CEFC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8044CF00: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8044CF04: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8044CF08: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8044CF0C: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8044CF10: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8044CF14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8044CF18: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8044CF1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8044CF20: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8044CF24: lw          $s4, 0x84($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X84);
    // 0x8044CF28: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x8044CF2C: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x8044CF30: addiu       $fp, $sp, 0x68
    ctx->r30 = ADD32(ctx->r29, 0X68);
L_8044CF34:
    // 0x8044CF34: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x8044CF38: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8044CF3C: bnel        $at, $zero, L_8044D010
    if (ctx->r1 != 0) {
        // 0x8044CF40: lhu         $t3, 0x2($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X2);
            goto L_8044D010;
    }
    goto skip_0;
    // 0x8044CF40: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    skip_0:
    // 0x8044CF44: bne         $s4, $zero, L_8044CF78
    if (ctx->r20 != 0) {
        // 0x8044CF48: sll         $v0, $s5, 1
        ctx->r2 = S32(ctx->r21 << 1);
            goto L_8044CF78;
    }
    // 0x8044CF48: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8044CF4C: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x8044CF50: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8044CF54: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8044CF58: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8044CF5C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8044CF60: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8044CF64: nop

    // 0x8044CF68: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044CF6C: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8044CF70: b           L_8044D030
    // 0x8044CF74: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_8044D030;
    // 0x8044CF74: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
L_8044CF78:
    // 0x8044CF78: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x8044CF7C: sll         $t0, $s6, 1
    ctx->r8 = S32(ctx->r22 << 1);
    // 0x8044CF80: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x8044CF84: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8044CF88: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x8044CF8C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8044CF90: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8044CF94: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8044CF98: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8044CF9C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8044CFA0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8044CFA4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8044CFA8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8044CFAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8044CFB0: nop

    // 0x8044CFB4: div.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8044CFB8: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x8044CFBC: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x8044CFC0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8044CFC4: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8044CFC8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8044CFCC: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8044CFD0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8044CFD4: nop

    // 0x8044CFD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8044CFDC: jal         0x8044CE3C
    // 0x8044CFE0: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    func_8044CE3C(rdram, ctx);
        goto after_0;
    // 0x8044CFE0: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8044CFE4: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8044CFE8: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8044CFEC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8044CFF0: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8044CFF4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8044CFF8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x8044CFFC: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8044D000: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8044D004: b           L_8044D030
    // 0x8044D008: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
        goto L_8044D030;
    // 0x8044D008: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x8044D00C: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
L_8044D010:
    // 0x8044D010: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8044D014: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8044D018: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8044D01C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8044D020: nop

    // 0x8044D024: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044D028: mul.s       $f18, $f6, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8044D02C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
L_8044D030:
    // 0x8044D030: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8044D034: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8044D038: bne         $s3, $s7, L_8044CF34
    if (ctx->r19 != ctx->r23) {
        // 0x8044D03C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8044CF34;
    }
    // 0x8044D03C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8044D040: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8044D044: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8044D048: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8044D04C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8044D050: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8044D054: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8044D058: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8044D05C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8044D060: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8044D064: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8044D068: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8044D06C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8044D070: jr          $ra
    // 0x8044D074: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8044D074: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800733B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800733B4: sh          $a2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r6;
    // 0x800733B8: beq         $a3, $zero, L_800733CC
    if (ctx->r7 == 0) {
        // 0x800733BC: sw          $a1, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->r5;
            goto L_800733CC;
    }
    // 0x800733BC: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    // 0x800733C0: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x800733C4: jr          $ra
    // 0x800733C8: sb          $t6, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r14;
    return;
    // 0x800733C8: sb          $t6, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r14;
L_800733CC:
    // 0x800733CC: sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
    // 0x800733D0: jr          $ra
    // 0x800733D4: nop

    return;
    // 0x800733D4: nop

;}
RECOMP_FUNC void func_80059A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059A4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80059A50: jal         0x80081C64
    // 0x80059A54: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80059A54: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80059A58: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80059A5C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80059A60: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x80059A64: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059A68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80059A6C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80059A70: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80059A74: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80059A78: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80059A7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80059A80: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80059A84: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80059A88: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80059A8C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80059A90: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80059A94: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80059A98: lw          $t0, 0x478($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X478);
    // 0x80059A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059AA0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059AA4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80059AA8: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80059AAC: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80059AB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80059AB4: lwc1        $f18, 0x34($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80059AB8: add.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059ABC: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80059AC0: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80059AC4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80059AC8: nop

    // 0x80059ACC: bc1f        L_80059AD8
    if (!c1cs) {
        // 0x80059AD0: nop
    
            goto L_80059AD8;
    }
    // 0x80059AD0: nop

    // 0x80059AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059AD8:
    // 0x80059AD8: beql        $v0, $zero, L_80059B6C
    if (ctx->r2 == 0) {
        // 0x80059ADC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80059B6C;
    }
    goto skip_0;
    // 0x80059ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80059AE0: jal         0x80081C64
    // 0x80059AE4: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80059AE4: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    after_1:
    // 0x80059AE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80059AEC: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80059AF0: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x80059AF4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059AF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80059AFC: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80059B00: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80059B04: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80059B08: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80059B0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80059B10: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x80059B14: lw          $t1, 0x478($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X478);
    // 0x80059B18: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80059B1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80059B20: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80059B24: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80059B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059B2C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80059B30: lwc1        $f16, 0x34($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X34);
    // 0x80059B34: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80059B38: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80059B3C: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059B40: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80059B44: lwc1        $f10, 0x4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80059B48: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80059B4C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80059B50: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80059B54: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x80059B58: nop

    // 0x80059B5C: bc1f        L_80059B68
    if (!c1cs) {
        // 0x80059B60: nop
    
            goto L_80059B68;
    }
    // 0x80059B60: nop

    // 0x80059B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059B68:
    // 0x80059B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80059B6C:
    // 0x80059B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059B70: jr          $ra
    // 0x80059B74: nop

    return;
    // 0x80059B74: nop

;}
RECOMP_FUNC void func_80018CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018CB0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80018CB4: lbu         $t6, -0x6D78($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6D78);
    // 0x80018CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018CBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80018CC0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80018CC4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80018CC8: beq         $t6, $zero, L_80018D08
    if (ctx->r14 == 0) {
        // 0x80018CCC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80018D08;
    }
    // 0x80018CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018CD0: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80018CD4: jal         0x80011990
    // 0x80018CD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_0;
    // 0x80018CD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80018CDC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80018CE0: jal         0x80011990
    // 0x80018CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_1;
    // 0x80018CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80018CE8: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x80018CEC: jal         0x80011990
    // 0x80018CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_2;
    // 0x80018CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80018CF4: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    // 0x80018CF8: jal         0x80011990
    // 0x80018CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_3;
    // 0x80018CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80018D00: b           L_80018E5C
    // 0x80018D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018E5C;
    // 0x80018D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018D08:
    // 0x80018D08: beq         $a0, $zero, L_80018D24
    if (ctx->r4 == 0) {
        // 0x80018D0C: slti        $at, $a1, 0xD3
        ctx->r1 = SIGNED(ctx->r5) < 0XD3 ? 1 : 0;
            goto L_80018D24;
    }
    // 0x80018D0C: slti        $at, $a1, 0xD3
    ctx->r1 = SIGNED(ctx->r5) < 0XD3 ? 1 : 0;
    // 0x80018D10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018D14: beql        $a0, $at, L_80018DC4
    if (ctx->r4 == ctx->r1) {
        // 0x80018D18: slti        $at, $a1, 0xCF
        ctx->r1 = SIGNED(ctx->r5) < 0XCF ? 1 : 0;
            goto L_80018DC4;
    }
    goto skip_0;
    // 0x80018D18: slti        $at, $a1, 0xCF
    ctx->r1 = SIGNED(ctx->r5) < 0XCF ? 1 : 0;
    skip_0:
    // 0x80018D1C: b           L_80018E5C
    // 0x80018D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018E5C;
    // 0x80018D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018D24:
    // 0x80018D24: bne         $at, $zero, L_80018D60
    if (ctx->r1 != 0) {
        // 0x80018D28: addiu       $a0, $zero, 0x70
        ctx->r4 = ADD32(0, 0X70);
            goto L_80018D60;
    }
    // 0x80018D28: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80018D2C: jal         0x80011990
    // 0x80018D30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_4;
    // 0x80018D30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80018D34: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80018D38: jal         0x80011928
    // 0x80018D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011928(rdram, ctx);
        goto after_5;
    // 0x80018D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80018D40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018D44: beq         $v0, $at, L_80018E58
    if (ctx->r2 == ctx->r1) {
        // 0x80018D48: addiu       $a0, $zero, 0x6F
        ctx->r4 = ADD32(0, 0X6F);
            goto L_80018E58;
    }
    // 0x80018D48: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80018D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018D50: jal         0x80015E74
    // 0x80018D54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80015E74(rdram, ctx);
        goto after_6;
    // 0x80018D54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80018D58: b           L_80018E5C
    // 0x80018D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018E5C;
    // 0x80018D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018D60:
    // 0x80018D60: slti        $at, $a1, 0x1E
    ctx->r1 = SIGNED(ctx->r5) < 0X1E ? 1 : 0;
    // 0x80018D64: beq         $at, $zero, L_80018D8C
    if (ctx->r1 == 0) {
        // 0x80018D68: addiu       $a0, $zero, 0x6F
        ctx->r4 = ADD32(0, 0X6F);
            goto L_80018D8C;
    }
    // 0x80018D68: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80018D6C: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80018D70: jal         0x80011990
    // 0x80018D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_7;
    // 0x80018D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80018D78: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80018D7C: jal         0x80011990
    // 0x80018D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_8;
    // 0x80018D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80018D84: b           L_80018E5C
    // 0x80018D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018E5C;
    // 0x80018D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018D8C:
    // 0x80018D8C: jal         0x80011990
    // 0x80018D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_9;
    // 0x80018D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80018D94: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80018D98: jal         0x80011928
    // 0x80018D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011928(rdram, ctx);
        goto after_10;
    // 0x80018D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80018DA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018DA4: beq         $v0, $at, L_80018E58
    if (ctx->r2 == ctx->r1) {
        // 0x80018DA8: addiu       $a0, $zero, 0x70
        ctx->r4 = ADD32(0, 0X70);
            goto L_80018E58;
    }
    // 0x80018DA8: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80018DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018DB0: jal         0x80015E74
    // 0x80018DB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80015E74(rdram, ctx);
        goto after_11;
    // 0x80018DB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80018DB8: b           L_80018E5C
    // 0x80018DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018E5C;
    // 0x80018DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018DC0: slti        $at, $a1, 0xCF
    ctx->r1 = SIGNED(ctx->r5) < 0XCF ? 1 : 0;
L_80018DC4:
    // 0x80018DC4: bne         $at, $zero, L_80018E00
    if (ctx->r1 != 0) {
        // 0x80018DC8: addiu       $a0, $zero, 0x72
        ctx->r4 = ADD32(0, 0X72);
            goto L_80018E00;
    }
    // 0x80018DC8: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    // 0x80018DCC: jal         0x80011990
    // 0x80018DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_12;
    // 0x80018DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80018DD4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x80018DD8: jal         0x80011928
    // 0x80018DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011928(rdram, ctx);
        goto after_13;
    // 0x80018DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80018DE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018DE4: beq         $v0, $at, L_80018E58
    if (ctx->r2 == ctx->r1) {
        // 0x80018DE8: addiu       $a0, $zero, 0x71
        ctx->r4 = ADD32(0, 0X71);
            goto L_80018E58;
    }
    // 0x80018DE8: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x80018DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018DF0: jal         0x80015E74
    // 0x80018DF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80015E74(rdram, ctx);
        goto after_14;
    // 0x80018DF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80018DF8: b           L_80018E5C
    // 0x80018DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018E5C;
    // 0x80018DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018E00:
    // 0x80018E00: slti        $at, $a1, 0x1E
    ctx->r1 = SIGNED(ctx->r5) < 0X1E ? 1 : 0;
    // 0x80018E04: beq         $at, $zero, L_80018E2C
    if (ctx->r1 == 0) {
        // 0x80018E08: addiu       $a0, $zero, 0x71
        ctx->r4 = ADD32(0, 0X71);
            goto L_80018E2C;
    }
    // 0x80018E08: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x80018E0C: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x80018E10: jal         0x80011990
    // 0x80018E14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_15;
    // 0x80018E14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80018E18: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    // 0x80018E1C: jal         0x80011990
    // 0x80018E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_16;
    // 0x80018E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80018E24: b           L_80018E5C
    // 0x80018E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018E5C;
    // 0x80018E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018E2C:
    // 0x80018E2C: jal         0x80011990
    // 0x80018E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011990(rdram, ctx);
        goto after_17;
    // 0x80018E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80018E34: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    // 0x80018E38: jal         0x80011928
    // 0x80018E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011928(rdram, ctx);
        goto after_18;
    // 0x80018E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80018E40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018E44: beq         $v0, $at, L_80018E58
    if (ctx->r2 == ctx->r1) {
        // 0x80018E48: addiu       $a0, $zero, 0x72
        ctx->r4 = ADD32(0, 0X72);
            goto L_80018E58;
    }
    // 0x80018E48: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    // 0x80018E4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018E50: jal         0x80015E74
    // 0x80018E54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80015E74(rdram, ctx);
        goto after_19;
    // 0x80018E54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
L_80018E58:
    // 0x80018E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018E5C:
    // 0x80018E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018E60: jr          $ra
    // 0x80018E64: nop

    return;
    // 0x80018E64: nop

;}
RECOMP_FUNC void func_80073844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073844: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80073848: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007384C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80073850: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80073854: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80073858: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007385C: lbu         $t7, 0x9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9);
    // 0x80073860: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80073864: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x80073868: beq         $t7, $at, L_800738C8
    if (ctx->r15 == ctx->r1) {
        // 0x8007386C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800738C8;
    }
    // 0x8007386C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073870: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073874: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80073878: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x8007387C: lui         $t9, 0x20
    ctx->r25 = S32(0X20 << 16);
    // 0x80073880: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80073884: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80073888: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007388C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80073890: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x80073894: ori         $t1, $t1, 0x3
    ctx->r9 = ctx->r9 | 0X3;
    // 0x80073898: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8007389C: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800738A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800738A4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800738A8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800738AC: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x800738B0: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x800738B4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800738B8: sw          $a3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r7;
    // 0x800738BC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800738C0: b           L_80073934
    // 0x800738C4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_80073934;
    // 0x800738C4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_800738C8:
    // 0x800738C8: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800738CC: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x800738D0: addiu       $t4, $zero, 0xCF0
    ctx->r12 = ADD32(0, 0XCF0);
    // 0x800738D4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800738D8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800738DC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800738E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800738E4: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x800738E8: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x800738EC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800738F0: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x800738F4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800738F8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800738FC: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80073900: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x80073904: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80073908: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
    // 0x8007390C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073910: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073914: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x80073918: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x8007391C: ori         $t8, $t8, 0xFC7E
    ctx->r24 = ctx->r24 | 0XFC7E;
    // 0x80073920: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80073924: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80073928: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007392C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073930: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80073934:
    // 0x80073934: jr          $ra
    // 0x80073938: nop

    return;
    // 0x80073938: nop

;}
RECOMP_FUNC void func_8045EF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045EF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045EF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045EF28: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8045EF2C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8045EF30: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(110, 0X12B8) << 16);
    // 0x8045EF34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8045EF38: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8045EF3C: lw          $t8, -0x1038($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(110, 0X12B8));
    // 0x8045EF40: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045EF44: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8045EF48: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045EF4C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8045EF50: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8045EF54: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8045EF58: beql        $v1, $zero, L_8045EF8C
    if (ctx->r3 == 0) {
        // 0x8045EF5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045EF8C;
    }
    goto skip_0;
    // 0x8045EF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8045EF60: jalr        $v1
    // 0x8045EF64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8045EF64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045EF68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045EF6C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8045EF70: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8045EF74: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8045EF78: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8045EF7C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8045EF80: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8045EF84: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8045EF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045EF8C:
    // 0x8045EF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045EF90: jr          $ra
    // 0x8045EF94: nop

    return;
    // 0x8045EF94: nop

    // 0x8045EF98: nop

    // 0x8045EF9C: nop

;}
RECOMP_FUNC void func_8078EDF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EDF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078EDF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078EDFC: jal         0x8078EC68
    // 0x8078EE00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8078EC68(rdram, ctx);
        goto after_0;
    // 0x8078EE00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078EE04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078EE08: beq         $v0, $zero, L_8078EE38
    if (ctx->r2 == 0) {
        // 0x8078EE0C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078EE38;
    }
    // 0x8078EE0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8078EE10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8078EE14: sb          $t6, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r14;
    // 0x8078EE18: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8078EE1C: lw          $t7, -0x6C78($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C78);
    // 0x8078EE20: beql        $t7, $zero, L_8078EE44
    if (ctx->r15 == 0) {
        // 0x8078EE24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078EE44;
    }
    goto skip_0;
    // 0x8078EE24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8078EE28: jal         0x8078ECBC
    // 0x8078EE2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8078ECBC(rdram, ctx);
        goto after_1;
    // 0x8078EE2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8078EE30: b           L_8078EE44
    // 0x8078EE34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078EE44;
    // 0x8078EE34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078EE38:
    // 0x8078EE38: jal         0x800447C8
    // 0x8078EE3C: nop

    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8078EE3C: nop

    after_2:
    // 0x8078EE40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078EE44:
    // 0x8078EE44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078EE48: jr          $ra
    // 0x8078EE4C: nop

    return;
    // 0x8078EE4C: nop

;}
RECOMP_FUNC void func_800351BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800351BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800351C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800351C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800351C8: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x800351CC: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x800351D0: beql        $v0, $zero, L_8003525C
    if (ctx->r2 == 0) {
        // 0x800351D4: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_8003525C;
    }
    goto skip_0;
    // 0x800351D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    skip_0:
    // 0x800351D8: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x800351DC: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800351E0: lwc1        $f0, 0x68($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X68);
    // 0x800351E4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800351E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800351EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800351F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800351F4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800351F8: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800351FC: nop

    // 0x80035200: bc1fl       L_80035234
    if (!c1cs) {
        // 0x80035204: lw          $t6, 0x138($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X138);
            goto L_80035234;
    }
    goto skip_1;
    // 0x80035204: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    skip_1:
    // 0x80035208: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8003520C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035210: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80035214: nop

    // 0x80035218: bc1fl       L_80035234
    if (!c1cs) {
        // 0x8003521C: lw          $t6, 0x138($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X138);
            goto L_80035234;
    }
    goto skip_2;
    // 0x8003521C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    skip_2:
    // 0x80035220: jal         0x80035008
    // 0x80035224: nop

    func_80035008(rdram, ctx);
        goto after_0;
    // 0x80035224: nop

    after_0:
    // 0x80035228: b           L_800353D8
    // 0x8003522C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800353D8;
    // 0x8003522C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80035230: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
L_80035234:
    // 0x80035234: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80035238: jal         0x80040E24
    // 0x8003523C: sb          $t6, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r14;
    func_80040E24(rdram, ctx);
        goto after_1;
    // 0x8003523C: sb          $t6, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r14;
    after_1:
    // 0x80035240: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80035244: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80035248: jal         0x8004115C
    // 0x8003524C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_8004115C(rdram, ctx);
        goto after_2;
    // 0x8003524C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80035250: b           L_800353DC
    // 0x80035254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800353DC;
    // 0x80035254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035258: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
L_8003525C:
    // 0x8003525C: jal         0x8003510C
    // 0x80035260: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_8003510C(rdram, ctx);
        goto after_3;
    // 0x80035260: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_3:
    // 0x80035264: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80035268: beq         $v0, $zero, L_800352F4
    if (ctx->r2 == 0) {
        // 0x8003526C: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_800352F4;
    }
    // 0x8003526C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80035270: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80035274: lbu         $t7, -0x7684($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7684);
    // 0x80035278: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x8003527C: beq         $t7, $t8, L_800352E4
    if (ctx->r15 == ctx->r24) {
        // 0x80035280: nop
    
            goto L_800352E4;
    }
    // 0x80035280: nop

    // 0x80035284: lw          $t9, 0x12EC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X12EC);
    // 0x80035288: bne         $t9, $zero, L_800352A0
    if (ctx->r25 != 0) {
        // 0x8003528C: nop
    
            goto L_800352A0;
    }
    // 0x8003528C: nop

    // 0x80035290: jal         0x80035008
    // 0x80035294: nop

    func_80035008(rdram, ctx);
        goto after_4;
    // 0x80035294: nop

    after_4:
    // 0x80035298: b           L_800353D8
    // 0x8003529C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800353D8;
    // 0x8003529C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800352A0:
    // 0x800352A0: jal         0x80040C9C
    // 0x800352A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80040C9C(rdram, ctx);
        goto after_5;
    // 0x800352A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_5:
    // 0x800352A8: jal         0x80040C9C
    // 0x800352AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80040C9C(rdram, ctx);
        goto after_6;
    // 0x800352AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_6:
    // 0x800352B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800352B4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800352B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800352BC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800352C0: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x800352C4: lw          $t9, -0xFFC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFFC);
    // 0x800352C8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800352CC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800352D0: lbu         $a1, -0xFC1($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFC1);
    // 0x800352D4: jalr        $t9
    // 0x800352D8: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x800352D8: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_7:
    // 0x800352DC: b           L_800353D8
    // 0x800352E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800353D8;
    // 0x800352E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800352E4:
    // 0x800352E4: jal         0x8003507C
    // 0x800352E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8003507C(rdram, ctx);
        goto after_8;
    // 0x800352E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_8:
    // 0x800352EC: b           L_800353D8
    // 0x800352F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800353D8;
    // 0x800352F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800352F4:
    // 0x800352F4: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    // 0x800352F8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800352FC: jal         0x80066E88
    // 0x80035300: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_9;
    // 0x80035300: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_9:
    // 0x80035304: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80035308: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003530C: lwc1        $f18, 0xD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XD8);
    // 0x80035310: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80035314: lwc1        $f6, 0x100($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X100);
    // 0x80035318: lwc1        $f16, 0x10C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8003531C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80035320: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80035324: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80035328: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003532C: add.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80035330: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80035334: nop

    // 0x80035338: bc1tl       L_80035360
    if (c1cs) {
        // 0x8003533C: lwc1        $f6, 0x68($a2)
        ctx->f6.u32l = MEM_W(ctx->r6, 0X68);
            goto L_80035360;
    }
    goto skip_3;
    // 0x8003533C: lwc1        $f6, 0x68($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X68);
    skip_3:
    // 0x80035340: lwc1        $f4, 0xDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XDC);
    // 0x80035344: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80035348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003534C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80035350: nop

    // 0x80035354: bc1fl       L_800353BC
    if (!c1cs) {
        // 0x80035358: lw          $t2, 0x138($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X138);
            goto L_800353BC;
    }
    goto skip_4;
    // 0x80035358: lw          $t2, 0x138($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X138);
    skip_4:
    // 0x8003535C: lwc1        $f6, 0x68($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X68);
L_80035360:
    // 0x80035360: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80035364: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80035368: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003536C: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80035370: nop

    // 0x80035374: bc1f        L_8003539C
    if (!c1cs) {
        // 0x80035378: nop
    
            goto L_8003539C;
    }
    // 0x80035378: nop

    // 0x8003537C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80035380: lw          $t9, -0x1020($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1020);
    // 0x80035384: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80035388: lbu         $a1, -0xFCA($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCA);
    // 0x8003538C: jalr        $t9
    // 0x80035390: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x80035390: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_10:
    // 0x80035394: b           L_800353D8
    // 0x80035398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800353D8;
    // 0x80035398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003539C:
    // 0x8003539C: lw          $t9, -0xFF4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFF4);
    // 0x800353A0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800353A4: lbu         $a1, -0xFBF($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFBF);
    // 0x800353A8: jalr        $t9
    // 0x800353AC: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800353AC: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_11:
    // 0x800353B0: b           L_800353D8
    // 0x800353B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800353D8;
    // 0x800353B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800353B8: lw          $t2, 0x138($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X138);
L_800353BC:
    // 0x800353BC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800353C0: jal         0x80040E24
    // 0x800353C4: sb          $t2, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r10;
    func_80040E24(rdram, ctx);
        goto after_12;
    // 0x800353C4: sb          $t2, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r10;
    after_12:
    // 0x800353C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800353CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800353D0: jal         0x8004115C
    // 0x800353D4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_8004115C(rdram, ctx);
        goto after_13;
    // 0x800353D4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_13:
L_800353D8:
    // 0x800353D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800353DC:
    // 0x800353DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800353E0: jr          $ra
    // 0x800353E4: nop

    return;
    // 0x800353E4: nop

;}
RECOMP_FUNC void func_800425D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800425D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800425D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800425DC: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x800425E0: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x800425E4: beql        $t7, $zero, L_80042610
    if (ctx->r15 == 0) {
        // 0x800425E8: lwc1        $f12, 0x58($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
            goto L_80042610;
    }
    goto skip_0;
    // 0x800425E8: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    skip_0:
    // 0x800425EC: lw          $t8, 0x38($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X38);
    // 0x800425F0: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x800425F4: bnel        $t9, $zero, L_80042610
    if (ctx->r25 != 0) {
        // 0x800425F8: lwc1        $f12, 0x58($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
            goto L_80042610;
    }
    goto skip_1;
    // 0x800425F8: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    skip_1:
    // 0x800425FC: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x80042600: lbu         $t1, 0x12($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X12);
    // 0x80042604: beql        $t1, $zero, L_80042678
    if (ctx->r9 == 0) {
        // 0x80042608: lwc1        $f2, 0x70($a1)
        ctx->f2.u32l = MEM_W(ctx->r5, 0X70);
            goto L_80042678;
    }
    goto skip_2;
    // 0x80042608: lwc1        $f2, 0x70($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X70);
    skip_2:
    // 0x8004260C: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
L_80042610:
    // 0x80042610: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80042614: jal         0x80065954
    // 0x80042618: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80042618: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x8004261C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80042620: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80042624: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80042628: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8004262C: nop

    // 0x80042630: bc1fl       L_80042648
    if (!c1cs) {
        // 0x80042634: lwc1        $f0, 0x58($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
            goto L_80042648;
    }
    goto skip_3;
    // 0x80042634: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
    skip_3:
    // 0x80042638: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004263C: b           L_800426E8
    // 0x80042640: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
        goto L_800426E8;
    // 0x80042640: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80042644: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
L_80042648:
    // 0x80042648: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004264C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80042650: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80042654: nop

    // 0x80042658: bc1fl       L_8004266C
    if (!c1cs) {
        // 0x8004265C: sub.s       $f2, $f0, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f14.fl;
            goto L_8004266C;
    }
    goto skip_4;
    // 0x8004265C: sub.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f14.fl;
    skip_4:
    // 0x80042660: b           L_8004266C
    // 0x80042664: add.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f14.fl;
        goto L_8004266C;
    // 0x80042664: add.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80042668: sub.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f14.fl;
L_8004266C:
    // 0x8004266C: b           L_800426E8
    // 0x80042670: swc1        $f2, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f2.u32l;
        goto L_800426E8;
    // 0x80042670: swc1        $f2, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f2.u32l;
    // 0x80042674: lwc1        $f2, 0x70($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X70);
L_80042678:
    // 0x80042678: lwc1        $f10, 0x58($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8004267C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80042680: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80042684: sub.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80042688: jal         0x80065954
    // 0x8004268C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8004268C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80042690: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80042694: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80042698: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004269C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800426A0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800426A4: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800426A8: bc1fl       L_800426BC
    if (!c1cs) {
        // 0x800426AC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800426BC;
    }
    goto skip_5;
    // 0x800426AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_5:
    // 0x800426B0: b           L_800426E8
    // 0x800426B4: swc1        $f2, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f2.u32l;
        goto L_800426E8;
    // 0x800426B4: swc1        $f2, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f2.u32l;
    // 0x800426B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_800426BC:
    // 0x800426BC: nop

    // 0x800426C0: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800426C4: nop

    // 0x800426C8: bc1fl       L_800426E0
    if (!c1cs) {
        // 0x800426CC: lwc1        $f4, 0x58($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
            goto L_800426E0;
    }
    goto skip_6;
    // 0x800426CC: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    skip_6:
    // 0x800426D0: lwc1        $f18, 0x58($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800426D4: b           L_800426E4
    // 0x800426D8: add.s       $f2, $f18, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f14.fl;
        goto L_800426E4;
    // 0x800426D8: add.s       $f2, $f18, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x800426DC: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
L_800426E0:
    // 0x800426E0: sub.s       $f2, $f4, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f14.fl;
L_800426E4:
    // 0x800426E4: swc1        $f2, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f2.u32l;
L_800426E8:
    // 0x800426E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800426EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800426F0: jr          $ra
    // 0x800426F4: nop

    return;
    // 0x800426F4: nop

;}
RECOMP_FUNC void func_806B267C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B267C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2680: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2684: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2688: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B268C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2690: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2694: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2698: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B269C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B26A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B26A4: jr          $ra
    // 0x806B26A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B26A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8043C818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043C818: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8043C81C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043C820: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8043C824: lw          $t4, 0x1F4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043C828: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x8043C82C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8043C830: lw          $t8, 0x318($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X318);
    // 0x8043C834: lw          $a2, 0x34($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X34);
    // 0x8043C838: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8043C83C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8043C840: bne         $at, $zero, L_8043C84C
    if (ctx->r1 != 0) {
        // 0x8043C844: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_8043C84C;
    }
    // 0x8043C844: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8043C848: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8043C84C:
    // 0x8043C84C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8043C850: lw          $t2, 0x934($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X934);
    // 0x8043C854: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8043C858: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043C85C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8043C860: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8043C864: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8043C868: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8043C86C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8043C870: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8043C874: blez        $t2, L_8043C948
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8043C878: addu        $a0, $t4, $t7
        ctx->r4 = ADD32(ctx->r12, ctx->r15);
            goto L_8043C948;
    }
    // 0x8043C878: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    // 0x8043C87C: lw          $a1, 0x930($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X930);
    // 0x8043C880: lw          $t8, 0x320($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X320);
L_8043C884:
    // 0x8043C884: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8043C888: addu        $t1, $t8, $t3
    ctx->r9 = ADD32(ctx->r24, ctx->r11);
    // 0x8043C88C: bltz        $t1, L_8043C8A4
    if (SIGNED(ctx->r9) < 0) {
        // 0x8043C890: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_8043C8A4;
    }
    // 0x8043C890: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8043C894: lw          $t9, 0x93C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X93C);
    // 0x8043C898: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8043C89C: bnel        $at, $zero, L_8043C8D4
    if (ctx->r1 != 0) {
        // 0x8043C8A0: lw          $t6, 0x938($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X938);
            goto L_8043C8D4;
    }
    goto skip_0;
    // 0x8043C8A0: lw          $t6, 0x938($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X938);
    skip_0:
L_8043C8A4:
    // 0x8043C8A4: blezl       $a1, L_8043C940
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8043C8A8: slt         $at, $t3, $t2
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8043C940;
    }
    goto skip_1;
    // 0x8043C8A8: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    skip_1:
    // 0x8043C8AC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8043C8B0:
    // 0x8043C8B0: lw          $a1, 0x930($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X930);
    // 0x8043C8B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8043C8B8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8043C8BC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8043C8C0: bnel        $at, $zero, L_8043C8B0
    if (ctx->r1 != 0) {
        // 0x8043C8C4: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_8043C8B0;
    }
    goto skip_2;
    // 0x8043C8C4: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    skip_2:
    // 0x8043C8C8: b           L_8043C93C
    // 0x8043C8CC: lw          $t2, 0x934($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X934);
        goto L_8043C93C;
    // 0x8043C8CC: lw          $t2, 0x934($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X934);
    // 0x8043C8D0: lw          $t6, 0x938($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X938);
L_8043C8D4:
    // 0x8043C8D4: lw          $t5, 0x330($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X330);
    // 0x8043C8D8: lw          $v0, 0x31C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X31C);
    // 0x8043C8DC: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8043C8E0: mflo        $t7
    ctx->r15 = lo;
    // 0x8043C8E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8043C8E8: blez        $a1, L_8043C93C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8043C8EC: addu        $a3, $t5, $t8
        ctx->r7 = ADD32(ctx->r13, ctx->r24);
            goto L_8043C93C;
    }
    // 0x8043C8EC: addu        $a3, $t5, $t8
    ctx->r7 = ADD32(ctx->r13, ctx->r24);
L_8043C8F0:
    // 0x8043C8F0: bltz        $v0, L_8043C910
    if (SIGNED(ctx->r2) < 0) {
        // 0x8043C8F4: nop
    
            goto L_8043C910;
    }
    // 0x8043C8F4: nop

    // 0x8043C8F8: lw          $t9, 0x938($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X938);
    // 0x8043C8FC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8043C900: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8043C904: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8043C908: bnel        $at, $zero, L_8043C91C
    if (ctx->r1 != 0) {
        // 0x8043C90C: lw          $t5, 0x0($t7)
        ctx->r13 = MEM_W(ctx->r15, 0X0);
            goto L_8043C91C;
    }
    goto skip_3;
    // 0x8043C90C: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    skip_3:
L_8043C910:
    // 0x8043C910: b           L_8043C920
    // 0x8043C914: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
        goto L_8043C920;
    // 0x8043C914: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8043C918: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
L_8043C91C:
    // 0x8043C91C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8043C920:
    // 0x8043C920: lw          $a1, 0x930($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X930);
    // 0x8043C924: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8043C928: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8043C92C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8043C930: bne         $at, $zero, L_8043C8F0
    if (ctx->r1 != 0) {
        // 0x8043C934: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8043C8F0;
    }
    // 0x8043C934: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8043C938: lw          $t2, 0x934($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X934);
L_8043C93C:
    // 0x8043C93C: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
L_8043C940:
    // 0x8043C940: bnel        $at, $zero, L_8043C884
    if (ctx->r1 != 0) {
        // 0x8043C944: lw          $t8, 0x320($t4)
        ctx->r24 = MEM_W(ctx->r12, 0X320);
            goto L_8043C884;
    }
    goto skip_4;
    // 0x8043C944: lw          $t8, 0x320($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X320);
    skip_4:
L_8043C948:
    // 0x8043C948: lhu         $t8, 0x334($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X334);
    // 0x8043C94C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8043C950: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8043C954: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8043C958: beql        $t9, $zero, L_8043C970
    if (ctx->r25 == 0) {
        // 0x8043C95C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8043C970;
    }
    goto skip_5;
    // 0x8043C95C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8043C960: jal         0x8043C370
    // 0x8043C964: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    func_8043C370(rdram, ctx);
        goto after_0;
    // 0x8043C964: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    after_0:
    // 0x8043C968: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8043C96C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_8043C970:
    // 0x8043C970: sw          $t6, 0x318($t4)
    MEM_W(0X318, ctx->r12) = ctx->r14;
    // 0x8043C974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043C978: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8043C97C: jr          $ra
    // 0x8043C980: nop

    return;
    // 0x8043C980: nop

;}
RECOMP_FUNC void func_805A04D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A04D4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805A04D8: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(408, 0XED8) << 16);
    // 0x805A04DC: addiu       $t6, $t6, 0x238
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(408, 0XED8));
    // 0x805A04E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805A04E4: jr          $ra
    // 0x805A04E8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805A04E8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80527EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527EA0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80527EA4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80527EA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80527EAC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80527EB0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80527EB4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80527EB8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80527EBC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80527EC0: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(327, 0X6124) << 16);
    // 0x80527EC4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80527EC8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80527ECC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80527ED0: lw          $t1, -0x3FDC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(327, 0X6124));
    // 0x80527ED4: jr          $ra
    // 0x80527ED8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80527ED8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80527EDC: nop

;}
RECOMP_FUNC void func_80678A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678A9C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80678AA0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80678AA4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80678AA8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80678AAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80678AB0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80678AB4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80678AB8: jal         0x80049018
    // 0x80678ABC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x80678ABC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80678AC0: beq         $v0, $zero, L_80678AD8
    if (ctx->r2 == 0) {
        // 0x80678AC4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80678AD8;
    }
    // 0x80678AC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80678AC8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80678ACC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80678AD0: b           L_80678AE4
    // 0x80678AD4: lw          $t6, 0x300($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X300);
        goto L_80678AE4;
    // 0x80678AD4: lw          $t6, 0x300($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X300);
L_80678AD8:
    // 0x80678AD8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80678ADC: nop

    // 0x80678AE0: lw          $t6, 0x300($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X300);
L_80678AE4:
    // 0x80678AE4: lw          $t8, 0x41C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X41C);
    // 0x80678AE8: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x80678AEC: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x80678AF0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80678AF4: beq         $t8, $zero, L_80678BC0
    if (ctx->r24 == 0) {
        // 0x80678AF8: addiu       $a0, $v0, 0x180
        ctx->r4 = ADD32(ctx->r2, 0X180);
            goto L_80678BC0;
    }
    // 0x80678AF8: addiu       $a0, $v0, 0x180
    ctx->r4 = ADD32(ctx->r2, 0X180);
    // 0x80678AFC: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80678B00: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x80678B04: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x80678B08: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80678B0C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x80678B10: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80678B14: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80678B18: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80678B1C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80678B20: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x80678B24: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80678B28: jal         0x80067114
    // 0x80678B2C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x80678B2C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80678B30: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80678B34: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80678B38: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80678B3C: lw          $t5, 0x41C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X41C);
    // 0x80678B40: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80678B44: jal         0x80066DE4
    // 0x80678B48: swc1        $f10, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80678B48: swc1        $f10, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f10.u32l;
    after_2:
    // 0x80678B4C: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x80678B50: lwc1        $f4, 0x6C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x80678B54: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80678B58: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80678B5C: lw          $t7, 0x41C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X41C);
    // 0x80678B60: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80678B64: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80678B68: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80678B6C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80678B70: swc1        $f16, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f16.u32l;
    // 0x80678B74: jal         0x80066E88
    // 0x80678B78: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x80678B78: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80678B7C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80678B80: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80678B84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80678B88: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x80678B8C: lh          $t9, 0x6($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6);
    // 0x80678B90: lwc1        $f4, 0x70($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X70);
    // 0x80678B94: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80678B98: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80678B9C: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80678BA0: lw          $t0, 0x41C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X41C);
    // 0x80678BA4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80678BA8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80678BAC: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80678BB0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80678BB4: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80678BB8: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80678BBC: swc1        $f10, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f10.u32l;
L_80678BC0:
    // 0x80678BC0: lw          $a1, 0x420($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X420);
    // 0x80678BC4: addiu       $v1, $s1, 0x7C
    ctx->r3 = ADD32(ctx->r17, 0X7C);
    // 0x80678BC8: beql        $a1, $zero, L_80678C70
    if (ctx->r5 == 0) {
        // 0x80678BCC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80678C70;
    }
    goto skip_0;
    // 0x80678BCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80678BD0: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x80678BD4: lwc1        $f18, 0x6C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x80678BD8: addiu       $v0, $a0, 0x7C
    ctx->r2 = ADD32(ctx->r4, 0X7C);
    // 0x80678BDC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80678BE0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80678BE4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80678BE8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80678BEC: nop

    // 0x80678BF0: mul.s       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80678BF4: swc1        $f16, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f16.u32l;
    // 0x80678BF8: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x80678BFC: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80678C00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80678C04: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80678C08: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80678C0C: lw          $t4, 0x420($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X420);
    // 0x80678C10: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80678C14: lwc1        $f10, 0x70($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X70);
    // 0x80678C18: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80678C1C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80678C20: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80678C24: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80678C28: swc1        $f8, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f8.u32l;
    // 0x80678C2C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80678C30: lh          $t5, -0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X4);
    // 0x80678C34: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80678C38: lh          $t8, -0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X4);
    // 0x80678C3C: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80678C40: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80678C44: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80678C48: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80678C4C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80678C50: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80678C54: jal         0x80067114
    // 0x80678C58: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80067114(rdram, ctx);
        goto after_4;
    // 0x80678C58: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_4:
    // 0x80678C5C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80678C60: lw          $t1, 0x420($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X420);
    // 0x80678C64: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80678C68: swc1        $f6, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f6.u32l;
    // 0x80678C6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80678C70:
    // 0x80678C70: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80678C74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80678C78: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80678C7C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80678C80: jr          $ra
    // 0x80678C84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80678C84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_804CD688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CD688: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x804CD68C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CD690: lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4);
    // 0x804CD694: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x804CD698: jal         0x8004700C
    // 0x804CD69C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CD69C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x804CD6A0: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x804CD6A4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x804CD6A8: beq         $v0, $zero, L_804CDB48
    if (ctx->r2 == 0) {
        // 0x804CD6AC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804CDB48;
    }
    // 0x804CD6AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804CD6B0: lwc1        $f4, 0x70($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X70);
    // 0x804CD6B4: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x804CD6B8: lw          $t0, 0x1F4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X1F4);
    // 0x804CD6BC: lwc1        $f2, 0x6C($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x804CD6C0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x804CD6C4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x804CD6C8: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x804CD6CC: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x804CD6D0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x804CD6D4: sw          $v0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r2;
    // 0x804CD6D8: sw          $v1, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r3;
    // 0x804CD6DC: beq         $v1, $zero, L_804CD984
    if (ctx->r3 == 0) {
        // 0x804CD6E0: sw          $zero, 0x10($t0)
        MEM_W(0X10, ctx->r8) = 0;
            goto L_804CD984;
    }
    // 0x804CD6E0: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x804CD6E4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x804CD6E8: lbu         $t9, 0x79($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X79);
    // 0x804CD6EC: beql        $t9, $zero, L_804CD988
    if (ctx->r25 == 0) {
        // 0x804CD6F0: lw          $t9, 0x180($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X180);
            goto L_804CD988;
    }
    goto skip_0;
    // 0x804CD6F0: lw          $t9, 0x180($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X180);
    skip_0:
    // 0x804CD6F4: lwc1        $f8, 0xC4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x804CD6F8: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x804CD6FC: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x804CD700: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804CD704: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x804CD708: swc1        $f4, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f4.u32l;
    // 0x804CD70C: lwc1        $f6, 0xC8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x804CD710: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804CD714: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804CD718: swc1        $f10, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f10.u32l;
    // 0x804CD71C: lwc1        $f6, 0xC8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x804CD720: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804CD724: nop

    // 0x804CD728: bc1fl       L_804CDB4C
    if (!c1cs) {
        // 0x804CD72C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDB4C;
    }
    goto skip_1;
    // 0x804CD72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804CD730: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x804CD734: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x804CD738: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x804CD73C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x804CD740: jal         0x80047AB8
    // 0x804CD744: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x804CD744: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x804CD748: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x804CD74C: jal         0x80047AB8
    // 0x804CD750: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x804CD750: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x804CD754: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x804CD758: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x804CD75C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x804CD760: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x804CD764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804CD768: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804CD76C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804CD770: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x804CD774: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x804CD778: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x804CD77C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x804CD780: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804CD784: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x804CD788: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x804CD78C: bc1fl       L_804CDB4C
    if (!c1cs) {
        // 0x804CD790: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDB4C;
    }
    goto skip_2;
    // 0x804CD790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804CD794: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804CD798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804CD79C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804CD7A0: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x804CD7A4: div.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804CD7A8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x804CD7AC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x804CD7B0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x804CD7B4: nop

    // 0x804CD7B8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x804CD7BC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x804CD7C0: nop

    // 0x804CD7C4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x804CD7C8: beql        $v0, $zero, L_804CD818
    if (ctx->r2 == 0) {
        // 0x804CD7CC: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_804CD818;
    }
    goto skip_3;
    // 0x804CD7CC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x804CD7D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804CD7D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804CD7D8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804CD7DC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x804CD7E0: nop

    // 0x804CD7E4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x804CD7E8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x804CD7EC: nop

    // 0x804CD7F0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x804CD7F4: bne         $v0, $zero, L_804CD80C
    if (ctx->r2 != 0) {
        // 0x804CD7F8: nop
    
            goto L_804CD80C;
    }
    // 0x804CD7F8: nop

    // 0x804CD7FC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x804CD800: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804CD804: b           L_804CD824
    // 0x804CD808: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_804CD824;
    // 0x804CD808: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_804CD80C:
    // 0x804CD80C: b           L_804CD824
    // 0x804CD810: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_804CD824;
    // 0x804CD810: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x804CD814: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_804CD818:
    // 0x804CD818: nop

    // 0x804CD81C: bltz        $v0, L_804CD80C
    if (SIGNED(ctx->r2) < 0) {
        // 0x804CD820: nop
    
            goto L_804CD80C;
    }
    // 0x804CD820: nop

L_804CD824:
    // 0x804CD824: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x804CD828: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x804CD82C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x804CD830: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x804CD834: beq         $at, $zero, L_804CDB48
    if (ctx->r1 == 0) {
        // 0x804CD838: subu        $t4, $t4, $v0
        ctx->r12 = SUB32(ctx->r12, ctx->r2);
            goto L_804CDB48;
    }
    // 0x804CD838: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x804CD83C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x804CD840: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804CD844: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804CD848: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x804CD84C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x804CD850: mul.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x804CD854: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x804CD858: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804CD85C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804CD860: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x804CD864: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x804CD868: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x804CD86C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CD870: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x804CD874: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x804CD878: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804CD87C: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x804CD880: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x804CD884: nop

    // 0x804CD888: bc1fl       L_804CDB4C
    if (!c1cs) {
        // 0x804CD88C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDB4C;
    }
    goto skip_4;
    // 0x804CD88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x804CD890: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804CD894: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804CD898: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x804CD89C: nop

    // 0x804CD8A0: bc1fl       L_804CDB4C
    if (!c1cs) {
        // 0x804CD8A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDB4C;
    }
    goto skip_5;
    // 0x804CD8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x804CD8A8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x804CD8AC: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x804CD8B0: jal         0x80060ED0
    // 0x804CD8B4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    func_80060ED0(rdram, ctx);
        goto after_3;
    // 0x804CD8B4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x804CD8B8: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x804CD8BC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804CD8C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804CD8C4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x804CD8C8: div.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
    // 0x804CD8CC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x804CD8D0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x804CD8D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804CD8D8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x804CD8DC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x804CD8E0: nop

    // 0x804CD8E4: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x804CD8E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x804CD8EC: nop

    // 0x804CD8F0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x804CD8F4: beql        $t6, $zero, L_804CD944
    if (ctx->r14 == 0) {
        // 0x804CD8F8: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_804CD944;
    }
    goto skip_6;
    // 0x804CD8F8: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x804CD8FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CD900: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804CD904: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x804CD908: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x804CD90C: nop

    // 0x804CD910: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x804CD914: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x804CD918: nop

    // 0x804CD91C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x804CD920: bne         $t6, $zero, L_804CD938
    if (ctx->r14 != 0) {
        // 0x804CD924: nop
    
            goto L_804CD938;
    }
    // 0x804CD924: nop

    // 0x804CD928: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x804CD92C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804CD930: b           L_804CD950
    // 0x804CD934: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_804CD950;
    // 0x804CD934: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_804CD938:
    // 0x804CD938: b           L_804CD950
    // 0x804CD93C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_804CD950;
    // 0x804CD93C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x804CD940: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_804CD944:
    // 0x804CD944: nop

    // 0x804CD948: bltz        $t6, L_804CD938
    if (SIGNED(ctx->r14) < 0) {
        // 0x804CD94C: nop
    
            goto L_804CD938;
    }
    // 0x804CD94C: nop

L_804CD950:
    // 0x804CD950: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804CD954: sw          $t7, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r15;
    // 0x804CD958: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x804CD95C: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804CD960: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804CD964: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804CD968: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x804CD96C: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x804CD970: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x804CD974: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x804CD978: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x804CD97C: b           L_804CDB48
    // 0x804CD980: sb          $t8, 0xDF($v1)
    MEM_B(0XDF, ctx->r3) = ctx->r24;
        goto L_804CDB48;
    // 0x804CD980: sb          $t8, 0xDF($v1)
    MEM_B(0XDF, ctx->r3) = ctx->r24;
L_804CD984:
    // 0x804CD984: lw          $t9, 0x180($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X180);
L_804CD988:
    // 0x804CD988: bnel        $a3, $t9, L_804CDB4C
    if (ctx->r7 != ctx->r25) {
        // 0x804CD98C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDB4C;
    }
    goto skip_7;
    // 0x804CD98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x804CD990: lw          $v1, 0x40($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X40);
    // 0x804CD994: beql        $v1, $zero, L_804CDB4C
    if (ctx->r3 == 0) {
        // 0x804CD998: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDB4C;
    }
    goto skip_8;
    // 0x804CD998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x804CD99C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x804CD9A0: bnel        $a3, $t1, L_804CDB4C
    if (ctx->r7 != ctx->r9) {
        // 0x804CD9A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDB4C;
    }
    goto skip_9;
    // 0x804CD9A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x804CD9A8: lwc1        $f10, 0xC8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x804CD9AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CD9B0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x804CD9B4: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x804CD9B8: nop

    // 0x804CD9BC: bc1f        L_804CDB40
    if (!c1cs) {
        // 0x804CD9C0: nop
    
            goto L_804CDB40;
    }
    // 0x804CD9C0: nop

    // 0x804CD9C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CD9C8: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804CD9CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CD9D0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x804CD9D4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x804CD9D8: add.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x804CD9DC: c.le.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl <= ctx->f14.fl;
    // 0x804CD9E0: nop

    // 0x804CD9E4: bc1f        L_804CDB30
    if (!c1cs) {
        // 0x804CD9E8: nop
    
            goto L_804CDB30;
    }
    // 0x804CD9E8: nop

    // 0x804CD9EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CD9F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x804CD9F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804CD9F8: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x804CD9FC: div.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x804CDA00: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x804CDA04: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x804CDA08: nop

    // 0x804CDA0C: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x804CDA10: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x804CDA14: nop

    // 0x804CDA18: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x804CDA1C: beql        $a0, $zero, L_804CDA6C
    if (ctx->r4 == 0) {
        // 0x804CDA20: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_804CDA6C;
    }
    goto skip_10;
    // 0x804CDA20: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_10:
    // 0x804CDA24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804CDA28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x804CDA2C: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x804CDA30: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x804CDA34: nop

    // 0x804CDA38: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x804CDA3C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x804CDA40: nop

    // 0x804CDA44: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x804CDA48: bne         $a0, $zero, L_804CDA60
    if (ctx->r4 != 0) {
        // 0x804CDA4C: nop
    
            goto L_804CDA60;
    }
    // 0x804CDA4C: nop

    // 0x804CDA50: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x804CDA54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804CDA58: b           L_804CDA78
    // 0x804CDA5C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_804CDA78;
    // 0x804CDA5C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_804CDA60:
    // 0x804CDA60: b           L_804CDA78
    // 0x804CDA64: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_804CDA78;
    // 0x804CDA64: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x804CDA68: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_804CDA6C:
    // 0x804CDA6C: nop

    // 0x804CDA70: bltz        $a0, L_804CDA60
    if (SIGNED(ctx->r4) < 0) {
        // 0x804CDA74: nop
    
            goto L_804CDA60;
    }
    // 0x804CDA74: nop

L_804CDA78:
    // 0x804CDA78: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x804CDA7C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x804CDA80: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804CDA84: sltu        $at, $a0, $t3
    ctx->r1 = ctx->r4 < ctx->r11 ? 1 : 0;
    // 0x804CDA88: beq         $at, $zero, L_804CDB20
    if (ctx->r1 == 0) {
        // 0x804CDA8C: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_804CDB20;
    }
    // 0x804CDA8C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x804CDA90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CDA94: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x804CDA98: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x804CDA9C: mul.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x804CDAA0: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x804CDAA4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x804CDAA8: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x804CDAAC: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CDAB0: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804CDAB4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804CDAB8: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x804CDABC: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x804CDAC0: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x804CDAC4: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x804CDAC8: nop

    // 0x804CDACC: bc1f        L_804CDB10
    if (!c1cs) {
        // 0x804CDAD0: nop
    
            goto L_804CDB10;
    }
    // 0x804CDAD0: nop

    // 0x804CDAD4: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x804CDAD8: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x804CDADC: bc1f        L_804CDB10
    if (!c1cs) {
        // 0x804CDAE0: nop
    
            goto L_804CDB10;
    }
    // 0x804CDAE0: nop

    // 0x804CDAE4: sw          $t6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r14;
    // 0x804CDAE8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804CDAEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804CDAF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804CDAF4: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x804CDAF8: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x804CDAFC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x804CDB00: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x804CDB04: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x804CDB08: b           L_804CDB48
    // 0x804CDB0C: sb          $t7, 0xDF($v1)
    MEM_B(0XDF, ctx->r3) = ctx->r15;
        goto L_804CDB48;
    // 0x804CDB0C: sb          $t7, 0xDF($v1)
    MEM_B(0XDF, ctx->r3) = ctx->r15;
L_804CDB10:
    // 0x804CDB10: jal         0x80060F6C
    // 0x804CDB14: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80060F6C(rdram, ctx);
        goto after_4;
    // 0x804CDB14: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x804CDB18: b           L_804CDB4C
    // 0x804CDB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CDB4C;
    // 0x804CDB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CDB20:
    // 0x804CDB20: jal         0x80060F6C
    // 0x804CDB24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80060F6C(rdram, ctx);
        goto after_5;
    // 0x804CDB24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x804CDB28: b           L_804CDB4C
    // 0x804CDB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CDB4C;
    // 0x804CDB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CDB30:
    // 0x804CDB30: jal         0x80060F6C
    // 0x804CDB34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80060F6C(rdram, ctx);
        goto after_6;
    // 0x804CDB34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x804CDB38: b           L_804CDB4C
    // 0x804CDB3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CDB4C;
    // 0x804CDB3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CDB40:
    // 0x804CDB40: jal         0x80060F6C
    // 0x804CDB44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80060F6C(rdram, ctx);
        goto after_7;
    // 0x804CDB44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
L_804CDB48:
    // 0x804CDB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CDB4C:
    // 0x804CDB4C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x804CDB50: jr          $ra
    // 0x804CDB54: nop

    return;
    // 0x804CDB54: nop

;}
RECOMP_FUNC void func_8001D224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D22C: jal         0x8001D0FC
    // 0x8001D230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001D0FC(rdram, ctx);
        goto after_0;
    // 0x8001D230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001D234: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8001D238: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8001D23C: lw          $t6, 0xF10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF10);
    // 0x8001D240: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D244: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D248: lw          $t9, 0xF14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF14);
    // 0x8001D24C: beq         $t9, $zero, L_8001D25C
    if (ctx->r25 == 0) {
        // 0x8001D250: nop
    
            goto L_8001D25C;
    }
    // 0x8001D250: nop

    // 0x8001D254: jal         0x8001D1DC
    // 0x8001D258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8001D1DC(rdram, ctx);
        goto after_1;
    // 0x8001D258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8001D25C:
    // 0x8001D25C: jal         0x8001D148
    // 0x8001D260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8001D148(rdram, ctx);
        goto after_2;
    // 0x8001D260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8001D264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D26C: jr          $ra
    // 0x8001D270: nop

    return;
    // 0x8001D270: nop

;}
RECOMP_FUNC void func_806F2318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F231C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2320: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806F2324: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806F2328: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F232C: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(679, 0X1ACC) << 16);
    // 0x806F2330: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F2334: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806F2338: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F233C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F2340: lw          $t8, 0x304C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(679, 0X1ACC));
    // 0x806F2344: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F2348: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F234C: jal         0x80048490
    // 0x806F2350: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806F2350: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806F2354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F235C: jr          $ra
    // 0x806F2360: nop

    return;
    // 0x806F2360: nop

;}
RECOMP_FUNC void func_8006758C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006758C: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80067590: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80067594: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80067598: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8006759C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800675A0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800675A4: lw          $t9, 0x6DD4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6DD4);
    // 0x800675A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800675AC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800675B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800675B4: and         $t0, $a1, $at
    ctx->r8 = ctx->r5 & ctx->r1;
    // 0x800675B8: jal         0x8007DF0C
    // 0x800675BC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    DmaMgr_RequestSync(rdram, ctx);
        goto after_0;
    // 0x800675BC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x800675C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800675C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800675C8: jr          $ra
    // 0x800675CC: nop

    return;
    // 0x800675CC: nop

;}
RECOMP_FUNC void func_80433C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433C30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80433C34: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80433C38: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80433C3C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80433C40: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80433C44: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80433C48: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80433C4C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80433C50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80433C54: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80433C58: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80433C5C: addiu       $s1, $zero, 0x77
    ctx->r17 = ADD32(0, 0X77);
    // 0x80433C60: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x80433C64: addiu       $s3, $zero, 0xF0
    ctx->r19 = ADD32(0, 0XF0);
    // 0x80433C68: addiu       $s0, $v0, 0x7AC
    ctx->r16 = ADD32(ctx->r2, 0X7AC);
L_80433C6C:
    // 0x80433C6C: jal         0x800653D8
    // 0x80433C70: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80433C70: nop

    after_0:
    // 0x80433C74: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x80433C78: mfhi        $t6
    ctx->r14 = hi;
    // 0x80433C7C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80433C80: bne         $s2, $zero, L_80433C8C
    if (ctx->r18 != 0) {
        // 0x80433C84: nop
    
            goto L_80433C8C;
    }
    // 0x80433C84: nop

    // 0x80433C88: break       7
    do_break(2151890056);
L_80433C8C:
    // 0x80433C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80433C90: bne         $s2, $at, L_80433CA4
    if (ctx->r18 != ctx->r1) {
        // 0x80433C94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80433CA4;
    }
    // 0x80433C94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80433C98: bne         $v0, $at, L_80433CA4
    if (ctx->r2 != ctx->r1) {
        // 0x80433C9C: nop
    
            goto L_80433CA4;
    }
    // 0x80433C9C: nop

    // 0x80433CA0: break       6
    do_break(2151890080);
L_80433CA4:
    // 0x80433CA4: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80433CA8: jal         0x800653D8
    // 0x80433CAC: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80433CAC: nop

    after_1:
    // 0x80433CB0: div         $zero, $v0, $s3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19)));
    // 0x80433CB4: mfhi        $t7
    ctx->r15 = hi;
    // 0x80433CB8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80433CBC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80433CC0: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x80433CC4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80433CC8: bne         $s3, $zero, L_80433CD4
    if (ctx->r19 != 0) {
        // 0x80433CCC: nop
    
            goto L_80433CD4;
    }
    // 0x80433CCC: nop

    // 0x80433CD0: break       7
    do_break(2151890128);
L_80433CD4:
    // 0x80433CD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80433CD8: bne         $s3, $at, L_80433CEC
    if (ctx->r19 != ctx->r1) {
        // 0x80433CDC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80433CEC;
    }
    // 0x80433CDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80433CE0: bne         $v0, $at, L_80433CEC
    if (ctx->r2 != ctx->r1) {
        // 0x80433CE4: nop
    
            goto L_80433CEC;
    }
    // 0x80433CE4: nop

    // 0x80433CE8: break       6
    do_break(2151890152);
L_80433CEC:
    // 0x80433CEC: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x80433CF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80433CF4: bgez        $s1, L_80433C6C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80433CF8: swc1        $f10, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
            goto L_80433C6C;
    }
    // 0x80433CF8: swc1        $f10, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80433CFC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80433D00: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80433D04: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80433D08: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80433D0C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80433D10: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80433D14: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80433D18: jr          $ra
    // 0x80433D1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80433D1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80584BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584BDC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584BE0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584BE4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584BE8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584BEC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584BF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584BF4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584BF8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584BFC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584C00: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584C04: jr          $ra
    // 0x80584C08: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584C08: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80037F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037F58: jal         0x80021958
    // 0x80037F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80037F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80037F60: bne         $v0, $zero, L_80037F70
    if (ctx->r2 != 0) {
        // 0x80037F64: nop
    
            goto L_80037F70;
    }
    // 0x80037F64: nop

    // 0x80037F68: b           L_80037FA4
    // 0x80037F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037FA4;
    // 0x80037F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037F70:
    // 0x80037F70: jal         0x800415FC
    // 0x80037F74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80037F74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80037F78: beq         $v0, $zero, L_80037F88
    if (ctx->r2 == 0) {
        // 0x80037F7C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80037F88;
    }
    // 0x80037F7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80037F80: b           L_80037FA4
    // 0x80037F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037FA4;
    // 0x80037F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037F88:
    // 0x80037F88: jal         0x800376A4
    // 0x80037F8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800376A4(rdram, ctx);
        goto after_2;
    // 0x80037F8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80037F90: bnel        $v0, $zero, L_80037FA4
    if (ctx->r2 != 0) {
        // 0x80037F94: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80037FA4;
    }
    goto skip_0;
    // 0x80037F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80037F98: b           L_80037FA4
    // 0x80037F9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037FA4;
    // 0x80037F9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80037FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037FA4:
    // 0x80037FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037FA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037FAC: jr          $ra
    // 0x80037FB0: nop

    return;
    // 0x80037FB0: nop

;}
RECOMP_FUNC void func_807A154C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A154C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807A1550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A1554: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x807A1558: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A155C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x807A1560: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x807A1564: lbu         $t8, 0x2C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2C);
    // 0x807A1568: beql        $t8, $zero, L_807A1798
    if (ctx->r24 == 0) {
        // 0x807A156C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A1798;
    }
    goto skip_0;
    // 0x807A156C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807A1570: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807A1574: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807A1578: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x807A157C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x807A1580: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x807A1584: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x807A1588: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x807A158C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x807A1590: lbu         $t1, 0x0($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X0);
    // 0x807A1594: andi        $t1, $t1, 0x10
    ctx->r9 = ctx->r9 & 0X10;
    // 0x807A1598: beql        $t1, $zero, L_807A15B4
    if (ctx->r9 == 0) {
        // 0x807A159C: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_807A15B4;
    }
    goto skip_1;
    // 0x807A159C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_1:
    // 0x807A15A0: beql        $t1, $at, L_807A1650
    if (ctx->r9 == ctx->r1) {
        // 0x807A15A4: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_807A1650;
    }
    goto skip_2;
    // 0x807A15A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    skip_2:
    // 0x807A15A8: b           L_807A16A0
    // 0x807A15AC: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
        goto L_807A16A0;
    // 0x807A15AC: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    // 0x807A15B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_807A15B4:
    // 0x807A15B4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x807A15B8: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x807A15BC: jal         0x8004700C
    // 0x807A15C0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807A15C0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_0:
    // 0x807A15C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807A15C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x807A15CC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x807A15D0: beq         $v0, $zero, L_807A1644
    if (ctx->r2 == 0) {
        // 0x807A15D4: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_807A1644;
    }
    // 0x807A15D4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x807A15D8: lw          $t4, 0x68($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X68);
    // 0x807A15DC: bnel        $t4, $zero, L_807A1618
    if (ctx->r12 != 0) {
        // 0x807A15E0: lwc1        $f10, 0x84($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
            goto L_807A1618;
    }
    goto skip_3;
    // 0x807A15E0: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
    skip_3:
    // 0x807A15E4: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807A15E8: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807A15EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A15F0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x807A15F4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x807A15F8: nop

    // 0x807A15FC: bc1f        L_807A1644
    if (!c1cs) {
        // 0x807A1600: nop
    
            goto L_807A1644;
    }
    // 0x807A1600: nop

    // 0x807A1604: jal         0x807A1AE4
    // 0x807A1608: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807A1AE4(rdram, ctx);
        goto after_1;
    // 0x807A1608: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807A160C: b           L_807A1798
    // 0x807A1610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A1798;
    // 0x807A1610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1614: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
L_807A1618:
    // 0x807A1618: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807A161C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A1620: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x807A1624: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x807A1628: nop

    // 0x807A162C: bc1f        L_807A1644
    if (!c1cs) {
        // 0x807A1630: nop
    
            goto L_807A1644;
    }
    // 0x807A1630: nop

    // 0x807A1634: jal         0x807A1AE4
    // 0x807A1638: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_807A1AE4(rdram, ctx);
        goto after_2;
    // 0x807A1638: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x807A163C: b           L_807A1798
    // 0x807A1640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A1798;
    // 0x807A1640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A1644:
    // 0x807A1644: b           L_807A16A0
    // 0x807A1648: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
        goto L_807A16A0;
    // 0x807A1648: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    // 0x807A164C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
L_807A1650:
    // 0x807A1650: lhu         $a1, 0xE($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XE);
    // 0x807A1654: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x807A1658: beq         $t6, $zero, L_807A169C
    if (ctx->r14 == 0) {
        // 0x807A165C: andi        $t7, $a1, 0xFFFE
        ctx->r15 = ctx->r5 & 0XFFFE;
            goto L_807A169C;
    }
    // 0x807A165C: andi        $t7, $a1, 0xFFFE
    ctx->r15 = ctx->r5 & 0XFFFE;
    // 0x807A1660: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x807A1664: lw          $t8, 0x68($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X68);
    // 0x807A1668: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x807A166C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A1670: bne         $t8, $zero, L_807A168C
    if (ctx->r24 != 0) {
        // 0x807A1674: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_807A168C;
    }
    // 0x807A1674: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x807A1678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A167C: jal         0x807A1AE4
    // 0x807A1680: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_807A1AE4(rdram, ctx);
        goto after_3;
    // 0x807A1680: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x807A1684: b           L_807A1798
    // 0x807A1688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A1798;
    // 0x807A1688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A168C:
    // 0x807A168C: jal         0x807A1AE4
    // 0x807A1690: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_807A1AE4(rdram, ctx);
        goto after_4;
    // 0x807A1690: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x807A1694: b           L_807A1798
    // 0x807A1698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A1798;
    // 0x807A1698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A169C:
    // 0x807A169C: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
L_807A16A0:
    // 0x807A16A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A16A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807A16A8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x807A16AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x807A16B0: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x807A16B4: jal         0x807A1AE4
    // 0x807A16B8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    func_807A1AE4(rdram, ctx);
        goto after_5;
    // 0x807A16B8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_5:
    // 0x807A16BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x807A16C0: jal         0x807A0F78
    // 0x807A16C4: addiu       $a1, $zero, 0x24D
    ctx->r5 = ADD32(0, 0X24D);
    func_807A0F78(rdram, ctx);
        goto after_6;
    // 0x807A16C4: addiu       $a1, $zero, 0x24D
    ctx->r5 = ADD32(0, 0X24D);
    after_6:
    // 0x807A16C8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x807A16CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807A16D0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x807A16D4: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x807A16D8: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x807A16DC: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x807A16E0: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x807A16E4: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x807A16E8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x807A16EC: beql        $v0, $zero, L_807A170C
    if (ctx->r2 == 0) {
        // 0x807A16F0: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_807A170C;
    }
    goto skip_4;
    // 0x807A16F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x807A16F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807A16F8: beq         $v0, $at, L_807A1714
    if (ctx->r2 == ctx->r1) {
        // 0x807A16FC: nop
    
            goto L_807A1714;
    }
    // 0x807A16FC: nop

    // 0x807A1700: b           L_807A1720
    // 0x807A1704: nop

        goto L_807A1720;
    // 0x807A1704: nop

    // 0x807A1708: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_807A170C:
    // 0x807A170C: b           L_807A1720
    // 0x807A1710: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
        goto L_807A1720;
    // 0x807A1710: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
L_807A1714:
    // 0x807A1714: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(841, 0XDA4) << 16);
    // 0x807A1718: lwc1        $f4, 0x1CE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(841, 0XDA4));
    // 0x807A171C: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
L_807A1720:
    // 0x807A1720: beq         $t1, $zero, L_807A1738
    if (ctx->r9 == 0) {
        // 0x807A1724: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_807A1738;
    }
    // 0x807A1724: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x807A1728: beql        $t1, $at, L_807A1750
    if (ctx->r9 == ctx->r1) {
        // 0x807A172C: lw          $t4, 0x68($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X68);
            goto L_807A1750;
    }
    goto skip_5;
    // 0x807A172C: lw          $t4, 0x68($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X68);
    skip_5:
    // 0x807A1730: b           L_807A177C
    // 0x807A1734: lbu         $v0, 0xC($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XC);
        goto L_807A177C;
    // 0x807A1734: lbu         $v0, 0xC($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XC);
L_807A1738:
    // 0x807A1738: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807A173C: nop

    // 0x807A1740: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x807A1744: b           L_807A177C
    // 0x807A1748: lbu         $v0, 0xC($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XC);
        goto L_807A177C;
    // 0x807A1748: lbu         $v0, 0xC($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XC);
    // 0x807A174C: lw          $t4, 0x68($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X68);
L_807A1750:
    // 0x807A1750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807A1754: bnel        $t4, $zero, L_807A1770
    if (ctx->r12 != 0) {
        // 0x807A1758: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_807A1770;
    }
    goto skip_6;
    // 0x807A1758: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_6:
    // 0x807A175C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807A1760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807A1764: b           L_807A1778
    // 0x807A1768: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
        goto L_807A1778;
    // 0x807A1768: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x807A176C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_807A1770:
    // 0x807A1770: nop

    // 0x807A1774: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_807A1778:
    // 0x807A1778: lbu         $v0, 0xC($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XC);
L_807A177C:
    // 0x807A177C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x807A1780: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x807A1784: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x807A1788: bne         $at, $zero, L_807A1794
    if (ctx->r1 != 0) {
        // 0x807A178C: sb          $t5, 0xC($t0)
        MEM_B(0XC, ctx->r8) = ctx->r13;
            goto L_807A1794;
    }
    // 0x807A178C: sb          $t5, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r13;
    // 0x807A1790: sb          $zero, 0xC($t0)
    MEM_B(0XC, ctx->r8) = 0;
L_807A1794:
    // 0x807A1794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A1798:
    // 0x807A1798: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x807A179C: jr          $ra
    // 0x807A17A0: nop

    return;
    // 0x807A17A0: nop

;}
RECOMP_FUNC void func_8006E138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006E13C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006E140: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x8006E144: sw          $a1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r5;
    // 0x8006E148: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006E14C: jr          $ra
    // 0x8006E150: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    return;
    // 0x8006E150: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80474C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474C0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80474C10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80474C14: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80474C18: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80474C1C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80474C20: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80474C24: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80474C28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80474C2C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80474C30: lw          $t6, 0x6D10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X6D10);
    // 0x80474C34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80474C38: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80474C3C: beq         $t6, $at, L_80474C88
    if (ctx->r14 == ctx->r1) {
        // 0x80474C40: addiu       $a1, $zero, 0x21C
        ctx->r5 = ADD32(0, 0X21C);
            goto L_80474C88;
    }
    // 0x80474C40: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x80474C44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474C48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80474C4C: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X29504) << 16);
    // 0x80474C50: lwc1        $f4, -0x233C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X29504));
    // 0x80474C54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80474C58: addiu       $t7, $zero, 0x1D10
    ctx->r15 = ADD32(0, 0X1D10);
    // 0x80474C5C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80474C60: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80474C64: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x80474C68: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80474C6C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80474C70: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80474C74: jal         0x804747CC
    // 0x80474C78: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_804747CC(rdram, ctx);
        goto after_0;
    // 0x80474C78: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80474C7C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80474C80: b           L_80474CD8
    // 0x80474C84: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_80474CD8;
    // 0x80474C84: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80474C88:
    // 0x80474C88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474C8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80474C90: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X29508) << 16);
    // 0x80474C94: lwc1        $f8, -0x2338($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X29508));
    // 0x80474C98: lwc1        $f0, 0x6AA0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6AA0);
    // 0x80474C9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474CA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80474CA4: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X2950C) << 16);
    // 0x80474CA8: lwc1        $f16, -0x2334($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X2950C));
    // 0x80474CAC: addiu       $t8, $zero, 0x1D10
    ctx->r24 = ADD32(0, 0X1D10);
    // 0x80474CB0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80474CB4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80474CB8: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80474CBC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80474CC0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80474CC4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80474CC8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80474CCC: jal         0x804748D0
    // 0x80474CD0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_804748D0(rdram, ctx);
        goto after_1;
    // 0x80474CD0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80474CD4: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_80474CD8:
    // 0x80474CD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474CDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80474CE0: nop

    // 0x80474CE4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80474CE8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80474CEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80474CF0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80474CF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80474CF8: jr          $ra
    // 0x80474CFC: nop

    return;
    // 0x80474CFC: nop

;}
RECOMP_FUNC void func_804BB9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB9D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB9DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB9E0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804BB9E4: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X11F8) << 16);
    // 0x804BB9E8: addiu       $t6, $t6, -0x34D8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X11F8));
    // 0x804BB9EC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804BB9F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804BB9F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x804BB9F8: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x804BB9FC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804BBA00: jal         0x8005FCA8
    // 0x804BBA04: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x804BBA04: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    after_0:
    // 0x804BBA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BBA0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BBA10: jr          $ra
    // 0x804BBA14: nop

    return;
    // 0x804BBA14: nop

;}
RECOMP_FUNC void func_80788634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80788634: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80788638: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8078863C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80788640: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80788644: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80788648: nop

    // 0x8078864C: bc1t        L_807887C0
    if (c1cs) {
        // 0x80788650: nop
    
            goto L_807887C0;
    }
    // 0x80788650: nop

    // 0x80788654: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80788658: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8078865C: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x80788660: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80788664: nop

    // 0x80788668: bc1fl       L_80788678
    if (!c1cs) {
        // 0x8078866C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80788678;
    }
    goto skip_0;
    // 0x8078866C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80788670: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80788674: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80788678:
    // 0x80788678: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078867C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80788680: nop

    // 0x80788684: bc1fl       L_80788694
    if (!c1cs) {
        // 0x80788688: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80788694;
    }
    goto skip_1;
    // 0x80788688: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_1:
    // 0x8078868C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80788690: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80788694:
    // 0x80788694: nop

    // 0x80788698: bc1fl       L_807886B8
    if (!c1cs) {
        // 0x8078869C: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_807886B8;
    }
    goto skip_2;
    // 0x8078869C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_2:
    // 0x807886A0: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x807886A4: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x807886A8: beql        $t7, $zero, L_807886B8
    if (ctx->r15 == 0) {
        // 0x807886AC: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_807886B8;
    }
    goto skip_3;
    // 0x807886AC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_3:
    // 0x807886B0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x807886B4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_807886B8:
    // 0x807886B8: nop

    // 0x807886BC: bc1fl       L_807886DC
    if (!c1cs) {
        // 0x807886C0: lwc1        $f4, 0x40($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
            goto L_807886DC;
    }
    goto skip_4;
    // 0x807886C0: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    skip_4:
    // 0x807886C4: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x807886C8: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x807886CC: beql        $t9, $zero, L_807886DC
    if (ctx->r25 == 0) {
        // 0x807886D0: lwc1        $f4, 0x40($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
            goto L_807886DC;
    }
    goto skip_5;
    // 0x807886D0: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    skip_5:
    // 0x807886D4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x807886D8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
L_807886DC:
    // 0x807886DC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x807886E0: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x807886E4: bc1f        L_8078871C
    if (!c1cs) {
        // 0x807886E8: swc1        $f6, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
            goto L_8078871C;
    }
    // 0x807886E8: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x807886EC: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x807886F0: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807886F4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F44) << 16);
    // 0x807886F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x807886FC: nop

    // 0x80788700: bc1fl       L_80788764
    if (!c1cs) {
        // 0x80788704: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_80788764;
    }
    goto skip_6;
    // 0x80788704: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_6:
    // 0x80788708: lwc1        $f8, -0x667C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F44));
    // 0x8078870C: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80788710: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80788714: b           L_80788760
    // 0x80788718: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
        goto L_80788760;
    // 0x80788718: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
L_8078871C:
    // 0x8078871C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80788720: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80788724: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F48) << 16);
    // 0x80788728: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8078872C: nop

    // 0x80788730: bc1fl       L_80788764
    if (!c1cs) {
        // 0x80788734: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_80788764;
    }
    goto skip_7;
    // 0x80788734: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_7:
    // 0x80788738: lwc1        $f18, -0x6678($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F48));
    // 0x8078873C: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80788740: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80788744: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80788748: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8078874C: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x80788750: nop

    // 0x80788754: bc1fl       L_80788764
    if (!c1cs) {
        // 0x80788758: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_80788764;
    }
    goto skip_8;
    // 0x80788758: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_8:
    // 0x8078875C: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
L_80788760:
    // 0x80788760: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_80788764:
    // 0x80788764: nop

    // 0x80788768: bc1fl       L_80788794
    if (!c1cs) {
        // 0x8078876C: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80788794;
    }
    goto skip_9;
    // 0x8078876C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_9:
    // 0x80788770: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80788774: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80788778: nop

    // 0x8078877C: bc1fl       L_80788794
    if (!c1cs) {
        // 0x80788780: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80788794;
    }
    goto skip_10;
    // 0x80788780: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_10:
    // 0x80788784: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x80788788: ori         $t1, $t0, 0x700
    ctx->r9 = ctx->r8 | 0X700;
    // 0x8078878C: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x80788790: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80788794:
    // 0x80788794: nop

    // 0x80788798: bc1f        L_807887C0
    if (!c1cs) {
        // 0x8078879C: nop
    
            goto L_807887C0;
    }
    // 0x8078879C: nop

    // 0x807887A0: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807887A4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x807887A8: nop

    // 0x807887AC: bc1f        L_807887C0
    if (!c1cs) {
        // 0x807887B0: nop
    
            goto L_807887C0;
    }
    // 0x807887B0: nop

    // 0x807887B4: lw          $t2, 0x34($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X34);
    // 0x807887B8: ori         $t3, $t2, 0x3000
    ctx->r11 = ctx->r10 | 0X3000;
    // 0x807887BC: sw          $t3, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r11;
L_807887C0:
    // 0x807887C0: jr          $ra
    // 0x807887C4: nop

    return;
    // 0x807887C4: nop

;}
RECOMP_FUNC void func_8001BCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BCF4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001BCF8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001BCFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001BD00: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001BD04: beq         $a0, $zero, L_8001BD30
    if (ctx->r4 == 0) {
        // 0x8001BD08: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8001BD30;
    }
    // 0x8001BD08: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001BD0C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8001BD10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001BD14: bgez        $a1, L_8001BD28
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8001BD18: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001BD28;
    }
    // 0x8001BD18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001BD1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001BD20: nop

    // 0x8001BD24: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001BD28:
    // 0x8001BD28: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x8001BD2C: sh          $a2, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r6;
L_8001BD30:
    // 0x8001BD30: jr          $ra
    // 0x8001BD34: nop

    return;
    // 0x8001BD34: nop

    // 0x8001BD38: nop

    // 0x8001BD3C: nop

;}
RECOMP_FUNC void func_8004C67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C67C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004C680: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004C684: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004C688: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004C68C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004C690: lh          $v0, 0x6($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X6);
    // 0x8004C694: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004C698: lh          $t0, 0x10($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X10);
    // 0x8004C69C: blez        $v0, L_8004C6DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004C6A0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8004C6DC;
    }
    // 0x8004C6A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004C6A4: lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2);
    // 0x8004C6A8: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
L_8004C6AC:
    // 0x8004C6AC: srav        $t7, $a0, $t6
    ctx->r15 = S32(SIGNED(ctx->r4) >> (ctx->r14 & 31));
    // 0x8004C6B0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8004C6B4: bnel        $t8, $zero, L_8004C6C8
    if (ctx->r24 != 0) {
        // 0x8004C6B8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004C6C8;
    }
    goto skip_0;
    // 0x8004C6B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8004C6BC: b           L_8004C820
    // 0x8004C6C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004C820;
    // 0x8004C6C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004C6C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004C6C8:
    // 0x8004C6C8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004C6CC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004C6D0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004C6D4: bnel        $at, $zero, L_8004C6AC
    if (ctx->r1 != 0) {
        // 0x8004C6D8: addu        $t6, $t0, $v1
        ctx->r14 = ADD32(ctx->r8, ctx->r3);
            goto L_8004C6AC;
    }
    goto skip_1;
    // 0x8004C6D8: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    skip_1:
L_8004C6DC:
    // 0x8004C6DC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004C6E0: slti        $at, $t9, 0x11
    ctx->r1 = SIGNED(ctx->r25) < 0X11 ? 1 : 0;
    // 0x8004C6E4: bnel        $at, $zero, L_8004C6F8
    if (ctx->r1 != 0) {
        // 0x8004C6E8: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8004C6F8;
    }
    goto skip_2;
    // 0x8004C6E8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_2:
    // 0x8004C6EC: b           L_8004C820
    // 0x8004C6F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004C820;
    // 0x8004C6F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004C6F4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_8004C6F8:
    // 0x8004C6F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C6FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004C700: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x8004C704: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004C708: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004C70C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004C710: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8004C714: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004C718: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004C71C: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004C720: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004C724: jal         0x800534C0
    // 0x8004C728: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8004C728: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x8004C72C: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004C730: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004C734: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004C738: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8004C73C: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x8004C740: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8004C744: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x8004C748: andi        $t3, $t2, 0xF8
    ctx->r11 = ctx->r10 & 0XF8;
    // 0x8004C74C: bnel        $t3, $at, L_8004C75C
    if (ctx->r11 != ctx->r1) {
        // 0x8004C750: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8004C75C;
    }
    goto skip_3;
    // 0x8004C750: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_3:
    // 0x8004C754: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x8004C758: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_8004C75C:
    // 0x8004C75C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004C760: beql        $v0, $zero, L_8004C820
    if (ctx->r2 == 0) {
        // 0x8004C764: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004C820;
    }
    goto skip_4;
    // 0x8004C764: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x8004C768: beql        $v0, $at, L_8004C820
    if (ctx->r2 == ctx->r1) {
        // 0x8004C76C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004C820;
    }
    goto skip_5;
    // 0x8004C76C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_5:
    // 0x8004C770: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004C774: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004C778: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004C77C: beq         $v0, $at, L_8004C81C
    if (ctx->r2 == ctx->r1) {
        // 0x8004C780: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004C81C;
    }
    // 0x8004C780: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004C784: beq         $v0, $at, L_8004C81C
    if (ctx->r2 == ctx->r1) {
        // 0x8004C788: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_8004C81C;
    }
    // 0x8004C788: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8004C78C: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8004C790: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8004C794: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x8004C798: srl         $t7, $v0, 6
    ctx->r15 = S32(U32(ctx->r2) >> 6);
    // 0x8004C79C: andi        $t9, $v0, 0x3F
    ctx->r25 = ctx->r2 & 0X3F;
    // 0x8004C7A0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8004C7A4: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8004C7A8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8004C7AC: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x8004C7B0: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x8004C7B4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8004C7B8: lw          $t3, 0xA24($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XA24);
    // 0x8004C7BC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8004C7C0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8004C7C4: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x8004C7C8: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x8004C7CC: beq         $t8, $zero, L_8004C81C
    if (ctx->r24 == 0) {
        // 0x8004C7D0: sh          $t9, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r25;
            goto L_8004C81C;
    }
    // 0x8004C7D0: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x8004C7D4: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8004C7D8: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8004C7DC: lhu         $t1, 0x0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X0);
    // 0x8004C7E0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8004C7E4: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8004C7E8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8004C7EC: lw          $t3, 0x40($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X40);
    // 0x8004C7F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004C7F4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8004C7F8: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x8004C7FC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8004C800: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004C804: jal         0x8004C67C
    // 0x8004C808: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_8004C67C(rdram, ctx);
        goto after_1;
    // 0x8004C808: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x8004C80C: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004C810: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C814: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004C818: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8004C81C:
    // 0x8004C81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004C820:
    // 0x8004C820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004C824: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004C828: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004C82C: jr          $ra
    // 0x8004C830: nop

    return;
    // 0x8004C830: nop

;}
RECOMP_FUNC void func_805AA338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA338: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805AA33C: lui         $t6, 0x805B
    ctx->r14 = S32(RELOC_HI16(432, 0X330) << 16);
    // 0x805AA340: addiu       $t6, $t6, -0x59E0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(432, 0X330));
    // 0x805AA344: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805AA348: jr          $ra
    // 0x805AA34C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805AA34C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8078A06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A06C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078A070: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8078A074: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8078A078: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8078A07C: jr          $ra
    // 0x8078A080: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8078A080: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80079160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079160: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80079164: lw          $v1, -0x7AF0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7AF0);
    // 0x80079168: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007916C: lhu         $t0, 0x1C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1C);
    // 0x80079170: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80079174: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80079178: beql        $at, $zero, L_800792CC
    if (ctx->r1 == 0) {
        // 0x8007917C: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800792CC;
    }
    goto skip_0;
    // 0x8007917C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_0:
    // 0x80079180: lhu         $t1, 0x1E($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X1E);
    // 0x80079184: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80079188: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8007918C: beql        $at, $zero, L_800792CC
    if (ctx->r1 == 0) {
        // 0x80079190: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800792CC;
    }
    goto skip_1;
    // 0x80079190: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_1:
    // 0x80079194: lhu         $t2, 0x18($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X18);
    // 0x80079198: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007919C: slt         $at, $a3, $t2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800791A0: bnel        $at, $zero, L_800792CC
    if (ctx->r1 != 0) {
        // 0x800791A4: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800792CC;
    }
    goto skip_2;
    // 0x800791A4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_2:
    // 0x800791A8: lhu         $t4, 0x1A($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X1A);
    // 0x800791AC: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x800791B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800791B4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800791B8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800791BC: bne         $at, $zero, L_800792C8
    if (ctx->r1 != 0) {
        // 0x800791C0: slt         $at, $a1, $t2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800792C8;
    }
    // 0x800791C0: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800791C4: beq         $at, $zero, L_800791F0
    if (ctx->r1 == 0) {
        // 0x800791C8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800791F0;
    }
    // 0x800791C8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800791CC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800791D0: subu        $t6, $a1, $t2
    ctx->r14 = SUB32(ctx->r5, ctx->r10);
    // 0x800791D4: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800791D8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800791DC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800791E0: mflo        $t8
    ctx->r24 = lo;
    // 0x800791E4: sra         $t9, $t8, 7
    ctx->r25 = S32(SIGNED(ctx->r24) >> 7);
    // 0x800791E8: subu        $t6, $t5, $t9
    ctx->r14 = SUB32(ctx->r13, ctx->r25);
    // 0x800791EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
L_800791F0:
    // 0x800791F0: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800791F4: beq         $at, $zero, L_8007921C
    if (ctx->r1 == 0) {
        // 0x800791F8: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_8007921C;
    }
    // 0x800791F8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800791FC: subu        $t7, $a2, $t4
    ctx->r15 = SUB32(ctx->r6, ctx->r12);
    // 0x80079200: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079204: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80079208: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8007920C: mflo        $t5
    ctx->r13 = lo;
    // 0x80079210: sra         $t9, $t5, 7
    ctx->r25 = S32(SIGNED(ctx->r13) >> 7);
    // 0x80079214: subu        $t7, $t6, $t9
    ctx->r15 = SUB32(ctx->r14, ctx->r25);
    // 0x80079218: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8007921C:
    // 0x8007921C: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80079220: beql        $at, $zero, L_80079230
    if (ctx->r1 == 0) {
        // 0x80079224: slt         $at, $t1, $t3
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80079230;
    }
    goto skip_3;
    // 0x80079224: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    skip_3:
    // 0x80079228: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8007922C: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
L_80079230:
    // 0x80079230: beq         $at, $zero, L_8007923C
    if (ctx->r1 == 0) {
        // 0x80079234: andi        $t8, $a3, 0xFFF
        ctx->r24 = ctx->r7 & 0XFFF;
            goto L_8007923C;
    }
    // 0x80079234: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x80079238: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8007923C:
    // 0x8007923C: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x80079240: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80079244: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80079248: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8007924C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80079250: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80079254: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80079258: andi        $t9, $a1, 0xFFF
    ctx->r25 = ctx->r5 & 0XFFF;
    // 0x8007925C: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80079260: andi        $t5, $t8, 0x7
    ctx->r13 = ctx->r24 & 0X7;
    // 0x80079264: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80079268: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8007926C: andi        $t5, $a2, 0xFFF
    ctx->r13 = ctx->r6 & 0XFFF;
    // 0x80079270: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x80079274: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80079278: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8007927C: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x80079280: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80079284: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80079288: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8007928C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80079290: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80079294: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x80079298: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8007929C: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800792A0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800792A4: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x800792A8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800792AC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800792B0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800792B4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800792B8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800792BC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800792C0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800792C4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
L_800792C8:
    // 0x800792C8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800792CC:
    // 0x800792CC: jr          $ra
    // 0x800792D0: nop

    return;
    // 0x800792D0: nop

;}
RECOMP_FUNC void func_8000C36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C36C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000C378: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000C37C: jal         0x8000BC14
    // 0x8000C380: lw          $a0, 0x44($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X44);
    func_8000BC14(rdram, ctx);
        goto after_0;
    // 0x8000C380: lw          $a0, 0x44($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X44);
    after_0:
    // 0x8000C384: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C388: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000C38C: sw          $t7, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->r15;
    // 0x8000C390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C398: jr          $ra
    // 0x8000C39C: nop

    return;
    // 0x8000C39C: nop

;}
RECOMP_FUNC void func_80038990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038990: jr          $ra
    // 0x80038994: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80038994: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80044214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004421C: jal         0x800440E4
    // 0x80044220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800440E4(rdram, ctx);
        goto after_0;
    // 0x80044220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80044224: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80044228: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x8004422C: addiu       $a3, $a3, -0x7698
    ctx->r7 = ADD32(ctx->r7, -0X7698);
    // 0x80044230: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x80044234: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80044238: jal         0x80057F74
    // 0x8004423C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80057F74(rdram, ctx);
        goto after_1;
    // 0x8004423C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80044240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044248: jr          $ra
    // 0x8004424C: nop

    return;
    // 0x8004424C: nop

;}
