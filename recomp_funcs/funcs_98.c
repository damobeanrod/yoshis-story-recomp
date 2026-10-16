#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800456F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800456F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800456F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800456F8: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x800456FC: jal         0x80045520
    // 0x80045700: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80045520(rdram, ctx);
        goto after_0;
    // 0x80045700: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80045704: bne         $v0, $zero, L_80045714
    if (ctx->r2 != 0) {
        // 0x80045708: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_80045714;
    }
    // 0x80045708: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8004570C: b           L_80045720
    // 0x80045710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80045720;
    // 0x80045710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80045714:
    // 0x80045714: addiu       $t7, $zero, 0x88
    ctx->r15 = ADD32(0, 0X88);
    // 0x80045718: sb          $t7, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r15;
    // 0x8004571C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80045720:
    // 0x80045720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80045724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80045728: jr          $ra
    // 0x8004572C: nop

    return;
    // 0x8004572C: nop

;}
RECOMP_FUNC void func_8006D774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D774: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D778: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006D77C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006D780: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006D784: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006D788: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8006D78C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006D790: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D794: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8006D798: addiu       $s3, $zero, 0x2C
    ctx->r19 = ADD32(0, 0X2C);
L_8006D79C:
    // 0x8006D79C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006D7A0: lw          $t6, -0x7BB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BB0);
    // 0x8006D7A4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8006D7A8: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8006D7AC: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x8006D7B0: beql        $s2, $a0, L_8006D7C4
    if (ctx->r18 == ctx->r4) {
        // 0x8006D7B4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006D7C4;
    }
    goto skip_0;
    // 0x8006D7B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8006D7B8: jal         0x8006D72C
    // 0x8006D7BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8006D72C(rdram, ctx);
        goto after_0;
    // 0x8006D7BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8006D7C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006D7C4:
    // 0x8006D7C4: bne         $s0, $s3, L_8006D79C
    if (ctx->r16 != ctx->r19) {
        // 0x8006D7C8: nop
    
            goto L_8006D79C;
    }
    // 0x8006D7C8: nop

    // 0x8006D7CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006D7D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006D7D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006D7D8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D7DC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006D7E0: jr          $ra
    // 0x8006D7E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D7E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805C68E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C68E8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805C68EC: lui         $t6, 0x805C
    ctx->r14 = S32(RELOC_HI16(447, 0X410) << 16);
    // 0x805C68F0: addiu       $t6, $t6, 0x6900
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(447, 0X410));
    // 0x805C68F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805C68F8: jr          $ra
    // 0x805C68FC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805C68FC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_805C9A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C9A98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805C9A9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C9AA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C9AA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C9AA8: jal         0x80045A34
    // 0x805C9AAC: addiu       $a1, $zero, 0x188
    ctx->r5 = ADD32(0, 0X188);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805C9AAC: addiu       $a1, $zero, 0x188
    ctx->r5 = ADD32(0, 0X188);
    after_0:
    // 0x805C9AB0: bne         $v0, $zero, L_805C9AC8
    if (ctx->r2 != 0) {
        // 0x805C9AB4: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_805C9AC8;
    }
    // 0x805C9AB4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805C9AB8: jal         0x800445A4
    // 0x805C9ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805C9ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805C9AC0: b           L_805C9D00
    // 0x805C9AC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C9D00;
    // 0x805C9AC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9AC8:
    // 0x805C9AC8: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x805C9ACC: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(447, 0X3B00) << 16);
    // 0x805C9AD0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805C9AD4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805C9AD8: addiu       $t6, $t6, -0x6010
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(447, 0X3B00));
    // 0x805C9ADC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805C9AE0: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x805C9AE4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805C9AE8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x805C9AEC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805C9AF0: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(447, 0X3998) << 16);
    // 0x805C9AF4: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(447, 0X39A8) << 16);
    // 0x805C9AF8: lui         $t0, 0x805D
    ctx->r8 = S32(RELOC_HI16(447, 0X39B8) << 16);
    // 0x805C9AFC: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(447, 0X39C8) << 16);
    // 0x805C9B00: lui         $t3, 0x805D
    ctx->r11 = S32(RELOC_HI16(447, 0X3AC8) << 16);
    // 0x805C9B04: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x805C9B08: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x805C9B0C: addiu       $t3, $t3, -0x6048
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(447, 0X3AC8));
    // 0x805C9B10: addiu       $v0, $v0, -0x6148
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(447, 0X39C8));
    // 0x805C9B14: addiu       $t0, $t0, -0x6158
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(447, 0X39B8));
    // 0x805C9B18: addiu       $a2, $a2, -0x6168
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(447, 0X39A8));
    // 0x805C9B1C: addiu       $a0, $a0, -0x6178
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(447, 0X3998));
    // 0x805C9B20: addiu       $v1, $t2, 0x68
    ctx->r3 = ADD32(ctx->r10, 0X68);
    // 0x805C9B24: addiu       $a1, $t2, 0x78
    ctx->r5 = ADD32(ctx->r10, 0X78);
    // 0x805C9B28: addiu       $a3, $t2, 0x88
    ctx->r7 = ADD32(ctx->r10, 0X88);
    // 0x805C9B2C: addiu       $t1, $t2, 0x98
    ctx->r9 = ADD32(ctx->r10, 0X98);
L_805C9B30:
    // 0x805C9B30: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x805C9B34: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x805C9B38: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x805C9B3C: sw          $t6, -0x40($v1)
    MEM_W(-0X40, ctx->r3) = ctx->r14;
    // 0x805C9B40: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x805C9B44: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x805C9B48: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x805C9B4C: sw          $t5, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->r13;
    // 0x805C9B50: lw          $t6, -0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, -0X38);
    // 0x805C9B54: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x805C9B58: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x805C9B5C: sw          $t6, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = ctx->r14;
    // 0x805C9B60: lw          $t5, -0x34($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X34);
    // 0x805C9B64: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x805C9B68: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x805C9B6C: sw          $t5, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r13;
    // 0x805C9B70: lw          $t8, -0x40($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X40);
    // 0x805C9B74: sw          $t8, -0x40($a1)
    MEM_W(-0X40, ctx->r5) = ctx->r24;
    // 0x805C9B78: lw          $t7, -0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X3C);
    // 0x805C9B7C: sw          $t7, -0x3C($a1)
    MEM_W(-0X3C, ctx->r5) = ctx->r15;
    // 0x805C9B80: lw          $t8, -0x38($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X38);
    // 0x805C9B84: sw          $t8, -0x38($a1)
    MEM_W(-0X38, ctx->r5) = ctx->r24;
    // 0x805C9B88: lw          $t7, -0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X34);
    // 0x805C9B8C: sw          $t7, -0x34($a1)
    MEM_W(-0X34, ctx->r5) = ctx->r15;
    // 0x805C9B90: lw          $t5, -0x40($t0)
    ctx->r13 = MEM_W(ctx->r8, -0X40);
    // 0x805C9B94: sw          $t5, -0x40($a3)
    MEM_W(-0X40, ctx->r7) = ctx->r13;
    // 0x805C9B98: lw          $t9, -0x3C($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X3C);
    // 0x805C9B9C: sw          $t9, -0x3C($a3)
    MEM_W(-0X3C, ctx->r7) = ctx->r25;
    // 0x805C9BA0: lw          $t5, -0x38($t0)
    ctx->r13 = MEM_W(ctx->r8, -0X38);
    // 0x805C9BA4: sw          $t5, -0x38($a3)
    MEM_W(-0X38, ctx->r7) = ctx->r13;
    // 0x805C9BA8: lw          $t9, -0x34($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X34);
    // 0x805C9BAC: sw          $t9, -0x34($a3)
    MEM_W(-0X34, ctx->r7) = ctx->r25;
    // 0x805C9BB0: lw          $t7, -0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X40);
    // 0x805C9BB4: sw          $t7, -0x40($t1)
    MEM_W(-0X40, ctx->r9) = ctx->r15;
    // 0x805C9BB8: lw          $t6, -0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X3C);
    // 0x805C9BBC: sw          $t6, -0x3C($t1)
    MEM_W(-0X3C, ctx->r9) = ctx->r14;
    // 0x805C9BC0: lw          $t7, -0x38($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X38);
    // 0x805C9BC4: sw          $t7, -0x38($t1)
    MEM_W(-0X38, ctx->r9) = ctx->r15;
    // 0x805C9BC8: lw          $t6, -0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X34);
    // 0x805C9BCC: bne         $v0, $t3, L_805C9B30
    if (ctx->r2 != ctx->r11) {
        // 0x805C9BD0: sw          $t6, -0x34($t1)
        MEM_W(-0X34, ctx->r9) = ctx->r14;
            goto L_805C9B30;
    }
    // 0x805C9BD0: sw          $t6, -0x34($t1)
    MEM_W(-0X34, ctx->r9) = ctx->r14;
    // 0x805C9BD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805C9BD8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x805C9BDC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x805C9BE0: sw          $zero, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = 0;
    // 0x805C9BE4: sw          $zero, 0x58($t2)
    MEM_W(0X58, ctx->r10) = 0;
    // 0x805C9BE8: sw          $zero, 0x54($t2)
    MEM_W(0X54, ctx->r10) = 0;
    // 0x805C9BEC: sw          $zero, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = 0;
    // 0x805C9BF0: sw          $zero, 0x48($t2)
    MEM_W(0X48, ctx->r10) = 0;
    // 0x805C9BF4: sw          $zero, 0x44($t2)
    MEM_W(0X44, ctx->r10) = 0;
    // 0x805C9BF8: sw          $zero, 0x40($t2)
    MEM_W(0X40, ctx->r10) = 0;
    // 0x805C9BFC: sw          $zero, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = 0;
    // 0x805C9C00: sw          $zero, 0x38($t2)
    MEM_W(0X38, ctx->r10) = 0;
    // 0x805C9C04: sw          $zero, 0x34($t2)
    MEM_W(0X34, ctx->r10) = 0;
    // 0x805C9C08: sw          $zero, 0x30($t2)
    MEM_W(0X30, ctx->r10) = 0;
    // 0x805C9C0C: sw          $zero, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = 0;
    // 0x805C9C10: sw          $zero, 0x28($t2)
    MEM_W(0X28, ctx->r10) = 0;
    // 0x805C9C14: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
    // 0x805C9C18: sw          $zero, 0x20($t2)
    MEM_W(0X20, ctx->r10) = 0;
    // 0x805C9C1C: sw          $zero, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = 0;
    // 0x805C9C20: sw          $zero, 0x18($t2)
    MEM_W(0X18, ctx->r10) = 0;
    // 0x805C9C24: sw          $zero, 0x60($t2)
    MEM_W(0X60, ctx->r10) = 0;
    // 0x805C9C28: sw          $zero, 0x64($t2)
    MEM_W(0X64, ctx->r10) = 0;
    // 0x805C9C2C: sh          $zero, 0x168($t2)
    MEM_H(0X168, ctx->r10) = 0;
    // 0x805C9C30: sh          $v0, 0x16A($t2)
    MEM_H(0X16A, ctx->r10) = ctx->r2;
    // 0x805C9C34: sh          $t8, 0x16C($t2)
    MEM_H(0X16C, ctx->r10) = ctx->r24;
    // 0x805C9C38: sh          $t9, 0x16E($t2)
    MEM_H(0X16E, ctx->r10) = ctx->r25;
    // 0x805C9C3C: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C9C40: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805C9C44: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x805C9C48: sw          $t5, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->r13;
    // 0x805C9C4C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x805C9C50: swc1        $f0, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f0.u32l;
    // 0x805C9C54: swc1        $f0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f0.u32l;
    // 0x805C9C58: swc1        $f2, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f2.u32l;
    // 0x805C9C5C: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C9C60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C9C64: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x805C9C68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C9C6C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x805C9C70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805C9C74: swc1        $f2, 0x17C($t2)
    MEM_W(0X17C, ctx->r10) = ctx->f2.u32l;
    // 0x805C9C78: swc1        $f2, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f2.u32l;
    // 0x805C9C7C: swc1        $f2, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f2.u32l;
    // 0x805C9C80: swc1        $f4, 0x180($t2)
    MEM_W(0X180, ctx->r10) = ctx->f4.u32l;
    // 0x805C9C84: swc1        $f6, 0x170($t2)
    MEM_W(0X170, ctx->r10) = ctx->f6.u32l;
    // 0x805C9C88: swc1        $f8, 0x174($t2)
    MEM_W(0X174, ctx->r10) = ctx->f8.u32l;
    // 0x805C9C8C: swc1        $f10, 0x178($t2)
    MEM_W(0X178, ctx->r10) = ctx->f10.u32l;
    // 0x805C9C90: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x805C9C94: addiu       $at, $zero, 0x4631
    ctx->r1 = ADD32(0, 0X4631);
    // 0x805C9C98: lui         $t8, 0x805C
    ctx->r24 = S32(RELOC_HI16(447, 0X10) << 16);
    // 0x805C9C9C: bne         $t6, $at, L_805C9CB0
    if (ctx->r14 != ctx->r1) {
        // 0x805C9CA0: addiu       $t8, $t8, 0x6500
        ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(447, 0X10));
            goto L_805C9CB0;
    }
    // 0x805C9CA0: addiu       $t8, $t8, 0x6500
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(447, 0X10));
    // 0x805C9CA4: sw          $v0, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->r2;
    // 0x805C9CA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805C9CAC: sw          $t7, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r15;
L_805C9CB0:
    // 0x805C9CB0: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x805C9CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9CB8: jal         0x805C68E8
    // 0x805C9CBC: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    func_805C68E8(rdram, ctx);
        goto after_2;
    // 0x805C9CBC: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    after_2:
    // 0x805C9CC0: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3C04) << 16);
    // 0x805C9CC4: lwc1        $f0, -0x5F0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3C04));
    // 0x805C9CC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805C9CCC: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
    // 0x805C9CD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C9CD4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805C9CD8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x805C9CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9CE0: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x805C9CE4: jal         0x805C74C8
    // 0x805C9CE8: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    func_805C74C8(rdram, ctx);
        goto after_3;
    // 0x805C9CE8: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x805C9CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9CF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C9CF4: jal         0x805C9D10
    // 0x805C9CF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805C9D10(rdram, ctx);
        goto after_4;
    // 0x805C9CF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x805C9CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9D00:
    // 0x805C9D00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C9D04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805C9D08: jr          $ra
    // 0x805C9D0C: nop

    return;
    // 0x805C9D0C: nop

;}
RECOMP_FUNC void func_807C3A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C3A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3A9C: jal         0x80059278
    // 0x807C3AA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x807C3AA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807C3AA4: bne         $v0, $zero, L_807C3AC8
    if (ctx->r2 != 0) {
        // 0x807C3AA8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807C3AC8;
    }
    // 0x807C3AA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807C3AAC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807C3AB0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807C3AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C3AB8: jal         0x807C3EC0
    // 0x807C3ABC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_807C3EC0(rdram, ctx);
        goto after_1;
    // 0x807C3ABC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x807C3AC0: b           L_807C3ACC
    // 0x807C3AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807C3ACC;
    // 0x807C3AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807C3AC8:
    // 0x807C3AC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807C3ACC:
    // 0x807C3ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C3AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C3AD4: jr          $ra
    // 0x807C3AD8: nop

    return;
    // 0x807C3AD8: nop

;}
RECOMP_FUNC void aprintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082174: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008217C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80082180: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80082184: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80082188: jal         0x80082140
    // 0x8008218C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    vaprintf(rdram, ctx);
        goto after_0;
    // 0x8008218C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80082190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082198: jr          $ra
    // 0x8008219C: nop

    return;
    // 0x8008219C: nop

;}
RECOMP_FUNC void func_804CB6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB6D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CB6D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CB6DC: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804CB6E0: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x804CB6E4: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x804CB6E8: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    // 0x804CB6EC: jal         0x80065490
    // 0x804CB6F0: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x804CB6F0: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x804CB6F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CB6F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CB6FC: jr          $ra
    // 0x804CB700: nop

    return;
    // 0x804CB700: nop

;}
RECOMP_FUNC void func_800273E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800273E0: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x800273E4: addiu       $t6, $t6, 0x73A0
    ctx->r14 = ADD32(ctx->r14, 0X73A0);
    // 0x800273E8: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800273EC: jr          $ra
    // 0x800273F0: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x800273F0: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800735A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800735A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800735A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800735AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800735B0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800735B4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800735B8: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800735BC: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    // 0x800735C0: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800735C4: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x800735C8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800735CC: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    // 0x800735D0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800735D4: jal         0x800734F0
    // 0x800735D8: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    func_800734F0(rdram, ctx);
        goto after_0;
    // 0x800735D8: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    after_0:
    // 0x800735DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800735E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800735E4: jr          $ra
    // 0x800735E8: nop

    return;
    // 0x800735E8: nop

;}
RECOMP_FUNC void func_80436B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436B84: jal         0x8004700C
    // 0x80436B88: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80436B88: nop

    after_0:
    // 0x80436B8C: beq         $v0, $zero, L_80436BB0
    if (ctx->r2 == 0) {
        // 0x80436B90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80436BB0;
    }
    // 0x80436B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80436B94: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x80436B98: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80436B9C: andi        $t7, $t6, 0xF0
    ctx->r15 = ctx->r14 & 0XF0;
    // 0x80436BA0: beql        $t7, $zero, L_80436BB4
    if (ctx->r15 == 0) {
        // 0x80436BA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80436BB4;
    }
    goto skip_0;
    // 0x80436BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80436BA8: b           L_80436BB4
    // 0x80436BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80436BB4;
    // 0x80436BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80436BB0:
    // 0x80436BB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80436BB4:
    // 0x80436BB4: jr          $ra
    // 0x80436BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80436BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80068B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068B14: jal         0x8006899C
    // 0x80068B18: nop

    func_8006899C(rdram, ctx);
        goto after_0;
    // 0x80068B18: nop

    after_0:
    // 0x80068B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068B24: jr          $ra
    // 0x80068B28: nop

    return;
    // 0x80068B28: nop

;}
RECOMP_FUNC void func_805A973C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A973C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A9740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A9744: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A9748: jal         0x805A9314
    // 0x805A974C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A9314(rdram, ctx);
        goto after_0;
    // 0x805A974C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A9750: jal         0x805A925C
    // 0x805A9754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805A925C(rdram, ctx);
        goto after_1;
    // 0x805A9754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A9758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A975C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A9760: jr          $ra
    // 0x805A9764: nop

    return;
    // 0x805A9764: nop

;}
RECOMP_FUNC void func_807A9BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9BC0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807A9BC4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807A9BC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807A9BCC: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(850, 0XB8) << 16);
    // 0x807A9BD0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807A9BD4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807A9BD8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807A9BDC: lw          $t8, -0x6408($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(850, 0XB8));
    // 0x807A9BE0: jr          $ra
    // 0x807A9BE4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x807A9BE4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x807A9BE8: nop

    // 0x807A9BEC: nop

;}
RECOMP_FUNC void func_8040C9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C9AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040C9B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040C9B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040C9B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8040C9BC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8040C9C0: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8040C9C4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8040C9C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8040C9CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8040C9D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8040C9D4: jal         0x80062AEC
    // 0x8040C9D8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x8040C9D8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x8040C9DC: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x8040C9E0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8040C9E4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8040C9E8: bne         $t7, $at, L_8040CBD4
    if (ctx->r15 != ctx->r1) {
        // 0x8040C9EC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8040CBD4;
    }
    // 0x8040C9EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040C9F0: beq         $v0, $at, L_8040CA18
    if (ctx->r2 == ctx->r1) {
        // 0x8040C9F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8040CA18;
    }
    // 0x8040C9F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040C9F8: beq         $v0, $at, L_8040CAC0
    if (ctx->r2 == ctx->r1) {
        // 0x8040C9FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8040CAC0;
    }
    // 0x8040C9FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8040CA00: beq         $v0, $at, L_8040CBD4
    if (ctx->r2 == ctx->r1) {
        // 0x8040CA04: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8040CBD4;
    }
    // 0x8040CA04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8040CA08: beq         $v0, $at, L_8040CB68
    if (ctx->r2 == ctx->r1) {
        // 0x8040CA0C: nop
    
            goto L_8040CB68;
    }
    // 0x8040CA0C: nop

    // 0x8040CA10: b           L_8040CBD8
    // 0x8040CA14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8040CBD8;
    // 0x8040CA14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040CA18:
    // 0x8040CA18: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1EF8) << 16);
    // 0x8040CA1C: lwc1        $f4, -0x1B08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1EF8));
    // 0x8040CA20: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8040CA24: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8040CA28: nop

    // 0x8040CA2C: bc1fl       L_8040CBD8
    if (!c1cs) {
        // 0x8040CA30: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040CBD8;
    }
    goto skip_0;
    // 0x8040CA30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8040CA34: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x8040CA38: beql        $t8, $zero, L_8040CA84
    if (ctx->r24 == 0) {
        // 0x8040CA3C: lw          $t4, 0x174($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X174);
            goto L_8040CA84;
    }
    goto skip_1;
    // 0x8040CA3C: lw          $t4, 0x174($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X174);
    skip_1:
    // 0x8040CA40: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x8040CA44: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8040CA48: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8040CA4C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8040CA50: bne         $t1, $zero, L_8040CBD4
    if (ctx->r9 != 0) {
        // 0x8040CA54: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8040CBD4;
    }
    // 0x8040CA54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8040CA58: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8040CA5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040CA60: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040CA64: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8040CA68: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8040CA6C: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x8040CA70: lw          $t2, 0x34($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X34);
    // 0x8040CA74: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8040CA78: b           L_8040CBD4
    // 0x8040CA7C: sw          $t3, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r11;
        goto L_8040CBD4;
    // 0x8040CA7C: sw          $t3, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r11;
    // 0x8040CA80: lw          $t4, 0x174($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X174);
L_8040CA84:
    // 0x8040CA84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8040CA88: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8040CA8C: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x8040CA90: bnel        $t6, $zero, L_8040CBD8
    if (ctx->r14 != 0) {
        // 0x8040CA94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040CBD8;
    }
    goto skip_2;
    // 0x8040CA94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8040CA98: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8040CA9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040CAA0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040CAA4: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8040CAA8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8040CAAC: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x8040CAB0: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x8040CAB4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8040CAB8: b           L_8040CBD4
    // 0x8040CABC: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
        goto L_8040CBD4;
    // 0x8040CABC: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
L_8040CAC0:
    // 0x8040CAC0: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1EFC) << 16);
    // 0x8040CAC4: lwc1        $f10, -0x1B04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1EFC));
    // 0x8040CAC8: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8040CACC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8040CAD0: nop

    // 0x8040CAD4: bc1fl       L_8040CBD8
    if (!c1cs) {
        // 0x8040CAD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040CBD8;
    }
    goto skip_3;
    // 0x8040CAD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8040CADC: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x8040CAE0: beql        $t9, $zero, L_8040CB2C
    if (ctx->r25 == 0) {
        // 0x8040CAE4: lw          $t5, 0x174($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X174);
            goto L_8040CB2C;
    }
    goto skip_4;
    // 0x8040CAE4: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    skip_4:
    // 0x8040CAE8: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x8040CAEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8040CAF0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8040CAF4: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x8040CAF8: bnel        $t2, $zero, L_8040CBD8
    if (ctx->r10 != 0) {
        // 0x8040CAFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040CBD8;
    }
    goto skip_5;
    // 0x8040CAFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8040CB00: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8040CB04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8040CB08: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040CB0C: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8040CB10: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8040CB14: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8040CB18: lw          $t3, 0x34($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X34);
    // 0x8040CB1C: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8040CB20: b           L_8040CBD4
    // 0x8040CB24: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
        goto L_8040CBD4;
    // 0x8040CB24: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
    // 0x8040CB28: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
L_8040CB2C:
    // 0x8040CB2C: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8040CB30: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8040CB34: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8040CB38: bne         $t7, $zero, L_8040CBD4
    if (ctx->r15 != 0) {
        // 0x8040CB3C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8040CBD4;
    }
    // 0x8040CB3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8040CB40: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8040CB44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8040CB48: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040CB4C: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8040CB50: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8040CB54: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x8040CB58: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x8040CB5C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8040CB60: b           L_8040CBD4
    // 0x8040CB64: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_8040CBD4;
    // 0x8040CB64: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_8040CB68:
    // 0x8040CB68: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F00) << 16);
    // 0x8040CB6C: lwc1        $f18, -0x1B00($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F00));
    // 0x8040CB70: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8040CB74: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8040CB78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8040CB7C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8040CB80: nop

    // 0x8040CB84: bc1fl       L_8040CBA8
    if (!c1cs) {
        // 0x8040CB88: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_8040CBA8;
    }
    goto skip_6;
    // 0x8040CB88: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_6:
    // 0x8040CB8C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8040CB90: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8040CB94: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8040CB98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8040CB9C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8040CBA0: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x8040CBA4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8040CBA8:
    // 0x8040CBA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8040CBAC: lw          $t1, 0x34($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X34);
    // 0x8040CBB0: ori         $t2, $t1, 0x3000
    ctx->r10 = ctx->r9 | 0X3000;
    // 0x8040CBB4: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x8040CBB8: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8040CBBC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8040CBC0: nop

    // 0x8040CBC4: bc1fl       L_8040CBD8
    if (!c1cs) {
        // 0x8040CBC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040CBD8;
    }
    goto skip_7;
    // 0x8040CBC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8040CBCC: jal         0x8040C908
    // 0x8040CBD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8040C908(rdram, ctx);
        goto after_1;
    // 0x8040CBD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
L_8040CBD4:
    // 0x8040CBD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040CBD8:
    // 0x8040CBD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040CBDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040CBE0: jr          $ra
    // 0x8040CBE4: nop

    return;
    // 0x8040CBE4: nop

;}
RECOMP_FUNC void func_8064BFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BFD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BFD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BFDC: jal         0x8004700C
    // 0x8064BFE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8064BFE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064BFE4: beq         $v0, $zero, L_8064C044
    if (ctx->r2 == 0) {
        // 0x8064BFE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8064C044;
    }
    // 0x8064BFE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064BFEC: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064BFF0: blez        $v1, L_8064C000
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8064BFF4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8064C000;
    }
    // 0x8064BFF4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8064BFF8: b           L_8064C044
    // 0x8064BFFC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064C044;
    // 0x8064BFFC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064C000:
    // 0x8064C000: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8064C004: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064C008: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8064C00C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064C010: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8064C014: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8064C018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C01C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8064C020: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8064C024: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8064C028: nop

    // 0x8064C02C: bc1fl       L_8064C048
    if (!c1cs) {
        // 0x8064C030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C048;
    }
    goto skip_0;
    // 0x8064C030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C034: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064C038: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8064C03C: jal         0x8064C5D8
    // 0x8064C040: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    func_8064C5D8(rdram, ctx);
        goto after_1;
    // 0x8064C040: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    after_1:
L_8064C044:
    // 0x8064C044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C048:
    // 0x8064C048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C04C: jr          $ra
    // 0x8064C050: nop

    return;
    // 0x8064C050: nop

;}
RECOMP_FUNC void func_807603C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807603C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807603CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807603D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807603D4: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC338) << 16);
    // 0x807603D8: lwc1        $f2, -0x3C38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC338));
    // 0x807603DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807603E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807603E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807603E8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807603EC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807603F0: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x807603F4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x807603F8: addiu       $t8, $zero, 0xAC8
    ctx->r24 = ADD32(0, 0XAC8);
    // 0x807603FC: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80760400: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x80760404: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80760408: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8076040C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80760410: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80760414: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80760418: jal         0x8076009C
    // 0x8076041C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x8076041C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80760420: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80760424: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x80760428: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8076042C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80760430: jr          $ra
    // 0x80760434: nop

    return;
    // 0x80760434: nop

;}
RECOMP_FUNC void func_8040E180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E188: jal         0x8040DCF0
    // 0x8040E18C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040DCF0(rdram, ctx);
        goto after_0;
    // 0x8040E18C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040E190: bne         $v0, $zero, L_8040E1A8
    if (ctx->r2 != 0) {
        // 0x8040E194: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040E1A8;
    }
    // 0x8040E194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040E198: jal         0x800445A4
    // 0x8040E19C: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8040E19C: nop

    after_1:
    // 0x8040E1A0: b           L_8040E1D4
    // 0x8040E1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040E1D4;
    // 0x8040E1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E1A8:
    // 0x8040E1A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040E1AC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8040E1B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8040E1B4: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x8040E1B8: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8040E1BC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8040E1C0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8040E1C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040E1C8: jal         0x8040E254
    // 0x8040E1CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040E1CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8040E1D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E1D4:
    // 0x8040E1D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E1D8: jr          $ra
    // 0x8040E1DC: nop

    return;
    // 0x8040E1DC: nop

;}
RECOMP_FUNC void func_80423118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423118: jr          $ra
    // 0x8042311C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8042311C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807B10B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B10B8: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(871, 0X3220) << 16);
    // 0x807B10BC: addiu       $v0, $v0, 0x2D70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(871, 0X3220));
    // 0x807B10C0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807B10C4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807B10C8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807B10CC: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x807B10D0: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x807B10D4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X393C) << 16);
    // 0x807B10D8: lwc1        $f16, 0x348C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X393C));
    // 0x807B10DC: sub.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x807B10E0: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x807B10E4: nop

    // 0x807B10E8: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x807B10EC: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x807B10F0: add.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x807B10F4: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x807B10F8: jr          $ra
    // 0x807B10FC: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x807B10FC: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8044B67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B67C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044B680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B684: jal         0x80444408
    // 0x8044B688: addiu       $a1, $zero, 0x4505
    ctx->r5 = ADD32(0, 0X4505);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x8044B688: addiu       $a1, $zero, 0x4505
    ctx->r5 = ADD32(0, 0X4505);
    after_0:
    // 0x8044B68C: beql        $v0, $zero, L_8044B6A8
    if (ctx->r2 == 0) {
        // 0x8044B690: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044B6A8;
    }
    goto skip_0;
    // 0x8044B690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044B694: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8044B698: beql        $v1, $zero, L_8044B6A8
    if (ctx->r3 == 0) {
        // 0x8044B69C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044B6A8;
    }
    goto skip_1;
    // 0x8044B69C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8044B6A0: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
    // 0x8044B6A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B6A8:
    // 0x8044B6A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044B6AC: jr          $ra
    // 0x8044B6B0: nop

    return;
    // 0x8044B6B0: nop

;}
RECOMP_FUNC void func_8047139C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8047139C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804713A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804713A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804713A8: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(155, 0X3C0) << 16);
    // 0x804713AC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804713B0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804713B4: lw          $t8, 0x1400($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(155, 0X3C0));
    // 0x804713B8: jr          $ra
    // 0x804713BC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x804713BC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8067E718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E718: jr          $ra
    // 0x8067E71C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8067E71C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80673D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673D78: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80673D7C: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(529, 0XC6C) << 16);
    // 0x80673D80: addiu       $t6, $t6, 0x3C4C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(529, 0XC6C));
    // 0x80673D84: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80673D88: jr          $ra
    // 0x80673D8C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80673D8C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_805842B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805842B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805842BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805842C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x805842C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x805842C8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x805842CC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x805842D0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x805842D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805842D8: addiu       $t6, $zero, 0x1D88
    ctx->r14 = ADD32(0, 0X1D88);
    // 0x805842DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805842E0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805842E4: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805842E8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x805842EC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x805842F0: jal         0x80583CCC
    // 0x805842F4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80583CCC(rdram, ctx);
        goto after_0;
    // 0x805842F4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x805842F8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x805842FC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A390) << 16);
    // 0x80584300: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80584304: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x80584308: lwc1        $f4, -0x1FB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A390));
    // 0x8058430C: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A394) << 16);
    // 0x80584310: lwc1        $f6, -0x1FAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A394));
    // 0x80584314: addiu       $t8, $zero, 0x1BA8
    ctx->r24 = ADD32(0, 0X1BA8);
    // 0x80584318: addiu       $t9, $zero, 0x1C20
    ctx->r25 = ADD32(0, 0X1C20);
    // 0x8058431C: addiu       $t0, $zero, 0x1D88
    ctx->r8 = ADD32(0, 0X1D88);
    // 0x80584320: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80584324: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80584328: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8058432C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80584330: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80584334: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80584338: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8058433C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80584340: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80584344: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80584348: jal         0x80583E84
    // 0x8058434C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_80583E84(rdram, ctx);
        goto after_1;
    // 0x8058434C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80584350: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80584354: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80584358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8058435C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80584360: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80584364: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80584368: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8058436C: jr          $ra
    // 0x80584370: nop

    return;
    // 0x80584370: nop

;}
RECOMP_FUNC void func_80584C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584C9C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584CA0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584CA4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584CA8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584CAC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584CB0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584CB4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584CB8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584CBC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584CC0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584CC4: jr          $ra
    // 0x80584CC8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584CC8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806670A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806670A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806670AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806670B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806670B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806670B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806670BC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x806670C0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x806670C4: jal         0x80047090
    // 0x806670C8: addiu       $a0, $zero, 0x454F
    ctx->r4 = ADD32(0, 0X454F);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806670C8: addiu       $a0, $zero, 0x454F
    ctx->r4 = ADD32(0, 0X454F);
    after_0:
    // 0x806670CC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806670D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x806670D4: beq         $v0, $at, L_806671B8
    if (ctx->r2 == ctx->r1) {
        // 0x806670D8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806671B8;
    }
    // 0x806670D8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806670DC: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x806670E0: beq         $a0, $zero, L_80667108
    if (ctx->r4 == 0) {
        // 0x806670E4: xor         $t0, $t6, $a0
        ctx->r8 = ctx->r14 ^ ctx->r4;
            goto L_80667108;
    }
    // 0x806670E4: xor         $t0, $t6, $a0
    ctx->r8 = ctx->r14 ^ ctx->r4;
    // 0x806670E8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x806670EC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806670F0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x806670F4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806670F8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806670FC: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80667100: b           L_80667128
    // 0x80667104: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
        goto L_80667128;
    // 0x80667104: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_80667108:
    // 0x80667108: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8066710C: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80667110: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80667114: nop

    // 0x80667118: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8066711C: mul.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80667120: nop

    // 0x80667124: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_80667128:
    // 0x80667128: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8066712C: lui         $at, 0x454F
    ctx->r1 = S32(0X454F << 16);
    // 0x80667130: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80667134: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x80667138: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8066713C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80667140: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80667144: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80667148: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8066714C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80667150: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80667154: jal         0x8004613C
    // 0x80667158: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80667158: nop

    after_1:
    // 0x8066715C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80667160: beq         $v0, $zero, L_806671B8
    if (ctx->r2 == 0) {
        // 0x80667164: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_806671B8;
    }
    // 0x80667164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80667168: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8066716C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80667170: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80667174: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80667178: mul.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8066717C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80667180: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80667184: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80667188: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x8066718C: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x80667190: swc1        $f2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f2.u32l;
    // 0x80667194: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80667198: sw          $t0, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r8;
    // 0x8066719C: swc1        $f10, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
    // 0x806671A0: jal         0x80666438
    // 0x806671A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80666438(rdram, ctx);
        goto after_2;
    // 0x806671A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x806671A8: beq         $v0, $zero, L_806671B8
    if (ctx->r2 == 0) {
        // 0x806671AC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806671B8;
    }
    // 0x806671AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806671B0: b           L_806671BC
    // 0x806671B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_806671BC;
    // 0x806671B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_806671B8:
    // 0x806671B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806671BC:
    // 0x806671BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806671C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806671C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806671C8: jr          $ra
    // 0x806671CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806671CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8003632C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003632C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036334: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036338: jal         0x80028288
    // 0x8003633C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80028288(rdram, ctx);
        goto after_0;
    // 0x8003633C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80036340: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80036344: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80036348: sw          $t7, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->r15;
    // 0x8003634C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036354: jr          $ra
    // 0x80036358: nop

    return;
    // 0x80036358: nop

;}
RECOMP_FUNC void func_8046B2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B2D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046B2DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8046B2E0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8046B2E4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8046B2E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046B2EC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8046B2F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8046B2F4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8046B2F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8046B2FC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8046B300: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8046B304: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8046B308: lui         $t2, 0x8047
    ctx->r10 = S32(RELOC_HI16(138, 0X2828) << 16);
    // 0x8046B30C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8046B310: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8046B314: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8046B318: lw          $t2, -0x4098($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(138, 0X2828));
    // 0x8046B31C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8046B320: jal         0x80469780
    // 0x8046B324: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80469780(rdram, ctx);
        goto after_0;
    // 0x8046B324: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8046B328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046B32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046B330: jr          $ra
    // 0x8046B334: nop

    return;
    // 0x8046B334: nop

;}
RECOMP_FUNC void func_806EF230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EF234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EF238: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x806EF23C: lw          $t8, 0x134($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X134);
    // 0x806EF240: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(676, 0X4A54) << 16);
    // 0x806EF244: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x806EF248: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806EF24C: lw          $t7, 0x9A4($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(676, 0X4A54));
    // 0x806EF250: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806EF254: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x806EF258: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806EF25C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EF260: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x806EF264: bne         $v0, $at, L_806EF28C
    if (ctx->r2 != ctx->r1) {
        // 0x806EF268: sw          $v1, 0x15C($a0)
        MEM_W(0X15C, ctx->r4) = ctx->r3;
            goto L_806EF28C;
    }
    // 0x806EF268: sw          $v1, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r3;
    // 0x806EF26C: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EF270: lui         $t3, 0x806F
    ctx->r11 = S32(RELOC_HI16(676, 0X4A14) << 16);
    // 0x806EF274: lh          $t1, 0x10($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10);
    // 0x806EF278: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x806EF27C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x806EF280: lh          $t3, 0x964($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(676, 0X4A14));
    // 0x806EF284: b           L_806EF2C0
    // 0x806EF288: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806EF2C0;
    // 0x806EF288: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806EF28C:
    // 0x806EF28C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x806EF290: beql        $v0, $zero, L_806EF2C4
    if (ctx->r2 == 0) {
        // 0x806EF294: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806EF2C4;
    }
    goto skip_0;
    // 0x806EF294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806EF298: jalr        $v0
    // 0x806EF29C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x806EF29C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EF2A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EF2A4: lw          $t4, 0x15C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X15C);
    // 0x806EF2A8: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x806EF2AC: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x806EF2B0: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x806EF2B4: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x806EF2B8: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x806EF2BC: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
L_806EF2C0:
    // 0x806EF2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EF2C4:
    // 0x806EF2C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EF2C8: jr          $ra
    // 0x806EF2CC: nop

    return;
    // 0x806EF2CC: nop

;}
RECOMP_FUNC void func_8004A124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A124: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8004A128: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x8004A12C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004A130: lw          $t1, 0x70($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X70);
    // 0x8004A134: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8004A138: lw          $a3, 0x34($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X34);
    // 0x8004A13C: lw          $t0, 0x38($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X38);
    // 0x8004A140: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8004A144: lwc1        $f2, 0x4($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8004A148: beq         $a2, $zero, L_8004A490
    if (ctx->r6 == 0) {
        // 0x8004A14C: lwc1        $f12, 0x8($t1)
        ctx->f12.u32l = MEM_W(ctx->r9, 0X8);
            goto L_8004A490;
    }
    // 0x8004A14C: lwc1        $f12, 0x8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8004A150: beq         $a0, $zero, L_8004A220
    if (ctx->r4 == 0) {
        // 0x8004A154: addu        $v1, $a0, $a2
        ctx->r3 = ADD32(ctx->r4, ctx->r6);
            goto L_8004A220;
    }
    // 0x8004A154: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
    // 0x8004A158: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8004A15C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8004A160: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8004A164: nop

    // 0x8004A168: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A16C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A170: beql        $v1, $a2, L_8004A1DC
    if (ctx->r3 == ctx->r6) {
        // 0x8004A174: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_8004A1DC;
    }
    goto skip_0;
    // 0x8004A174: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    skip_0:
    // 0x8004A178: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8004A17C:
    // 0x8004A17C: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x8004A180: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8004A184: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004A188: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8004A18C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8004A190: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8004A194: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A198: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x8004A19C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A1A0: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8004A1A4: lh          $t8, -0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, -0X2);
    // 0x8004A1A8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8004A1AC: nop

    // 0x8004A1B0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A1B4: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A1B8: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8004A1BC: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8004A1C0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8004A1C4: nop

    // 0x8004A1C8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A1CC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A1D0: bnel        $v1, $a2, L_8004A17C
    if (ctx->r3 != ctx->r6) {
        // 0x8004A1D4: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_8004A17C;
    }
    goto skip_1;
    // 0x8004A1D4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    skip_1:
    // 0x8004A1D8: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8004A1DC:
    // 0x8004A1DC: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x8004A1E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004A1E4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8004A1E8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8004A1EC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8004A1F0: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x8004A1F4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A1F8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A1FC: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8004A200: lh          $t8, -0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, -0X2);
    // 0x8004A204: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8004A208: nop

    // 0x8004A20C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A210: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A214: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8004A218: beq         $a2, $zero, L_8004A490
    if (ctx->r6 == 0) {
        // 0x8004A21C: nop
    
            goto L_8004A490;
    }
    // 0x8004A21C: nop

L_8004A220:
    // 0x8004A220: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8004A224: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8004A228: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8004A22C: nop

    // 0x8004A230: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A234: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A238: beql        $a2, $zero, L_8004A37C
    if (ctx->r6 == 0) {
        // 0x8004A23C: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_8004A37C;
    }
    goto skip_2;
    // 0x8004A23C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    skip_2:
    // 0x8004A240: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8004A244:
    // 0x8004A244: lh          $t2, 0x2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2);
    // 0x8004A248: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8004A24C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004A250: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8004A254: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8004A258: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8004A25C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A260: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8004A264: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A268: swc1        $f16, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8004A26C: lh          $t3, -0x14($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X14);
    // 0x8004A270: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8004A274: nop

    // 0x8004A278: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A27C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A280: swc1        $f16, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f16.u32l;
    // 0x8004A284: lh          $t4, -0x12($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X12);
    // 0x8004A288: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8004A28C: nop

    // 0x8004A290: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A294: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A298: swc1        $f16, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8004A29C: lh          $t5, -0x10($a1)
    ctx->r13 = MEM_H(ctx->r5, -0X10);
    // 0x8004A2A0: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8004A2A4: nop

    // 0x8004A2A8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A2AC: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A2B0: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x8004A2B4: lh          $t6, -0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, -0XE);
    // 0x8004A2B8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8004A2BC: nop

    // 0x8004A2C0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A2C4: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A2C8: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8004A2CC: lh          $t7, -0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, -0XC);
    // 0x8004A2D0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8004A2D4: nop

    // 0x8004A2D8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A2DC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A2E0: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8004A2E4: lh          $t8, -0xA($a1)
    ctx->r24 = MEM_H(ctx->r5, -0XA);
    // 0x8004A2E8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8004A2EC: nop

    // 0x8004A2F0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A2F4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A2F8: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8004A2FC: lh          $t9, -0x8($a1)
    ctx->r25 = MEM_H(ctx->r5, -0X8);
    // 0x8004A300: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8004A304: nop

    // 0x8004A308: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A30C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A310: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x8004A314: lh          $t2, -0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X6);
    // 0x8004A318: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8004A31C: nop

    // 0x8004A320: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A324: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A328: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8004A32C: lh          $t3, -0x4($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X4);
    // 0x8004A330: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8004A334: nop

    // 0x8004A338: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A33C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A340: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8004A344: lh          $t4, -0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X2);
    // 0x8004A348: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8004A34C: nop

    // 0x8004A350: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A354: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A358: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8004A35C: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8004A360: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8004A364: nop

    // 0x8004A368: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A36C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A370: bnel        $a2, $zero, L_8004A244
    if (ctx->r6 != 0) {
        // 0x8004A374: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_8004A244;
    }
    goto skip_3;
    // 0x8004A374: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    skip_3:
    // 0x8004A378: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8004A37C:
    // 0x8004A37C: lh          $t2, 0x2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2);
    // 0x8004A380: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8004A384: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8004A388: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8004A38C: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8004A390: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8004A394: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A398: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A39C: swc1        $f16, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8004A3A0: lh          $t3, -0x14($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X14);
    // 0x8004A3A4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8004A3A8: nop

    // 0x8004A3AC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A3B0: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A3B4: swc1        $f16, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f16.u32l;
    // 0x8004A3B8: lh          $t4, -0x12($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X12);
    // 0x8004A3BC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8004A3C0: nop

    // 0x8004A3C4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A3C8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A3CC: swc1        $f16, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8004A3D0: lh          $t5, -0x10($a1)
    ctx->r13 = MEM_H(ctx->r5, -0X10);
    // 0x8004A3D4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8004A3D8: nop

    // 0x8004A3DC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A3E0: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A3E4: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x8004A3E8: lh          $t6, -0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, -0XE);
    // 0x8004A3EC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8004A3F0: nop

    // 0x8004A3F4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A3F8: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A3FC: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8004A400: lh          $t7, -0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, -0XC);
    // 0x8004A404: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8004A408: nop

    // 0x8004A40C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A410: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A414: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8004A418: lh          $t8, -0xA($a1)
    ctx->r24 = MEM_H(ctx->r5, -0XA);
    // 0x8004A41C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8004A420: nop

    // 0x8004A424: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A428: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A42C: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8004A430: lh          $t9, -0x8($a1)
    ctx->r25 = MEM_H(ctx->r5, -0X8);
    // 0x8004A434: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8004A438: nop

    // 0x8004A43C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A440: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A444: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x8004A448: lh          $t2, -0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X6);
    // 0x8004A44C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8004A450: nop

    // 0x8004A454: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A458: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A45C: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8004A460: lh          $t3, -0x4($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X4);
    // 0x8004A464: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8004A468: nop

    // 0x8004A46C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A470: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A474: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8004A478: lh          $t4, -0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X2);
    // 0x8004A47C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8004A480: nop

    // 0x8004A484: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004A488: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A48C: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
L_8004A490:
    // 0x8004A490: jr          $ra
    // 0x8004A494: nop

    return;
    // 0x8004A494: nop

;}
RECOMP_FUNC void func_80448C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80448C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448C80: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80448C84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80448C88: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80448C8C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14044) << 16);
    // 0x80448C90: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80448C94: nop

    // 0x80448C98: bc1f        L_80448CC0
    if (!c1cs) {
        // 0x80448C9C: nop
    
            goto L_80448CC0;
    }
    // 0x80448C9C: nop

    // 0x80448CA0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80448CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448CA8: beql        $v0, $t6, L_80448E0C
    if (ctx->r2 == ctx->r14) {
        // 0x80448CAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448E0C;
    }
    goto skip_0;
    // 0x80448CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80448CB0: jal         0x80445930
    // 0x80448CB4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_80445930(rdram, ctx);
        goto after_0;
    // 0x80448CB4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_0:
    // 0x80448CB8: b           L_80448E0C
    // 0x80448CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448E0C;
    // 0x80448CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448CC0:
    // 0x80448CC0: lwc1        $f6, -0x7BDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14044));
    // 0x80448CC4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14048) << 16);
    // 0x80448CC8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80448CCC: nop

    // 0x80448CD0: bc1f        L_80448CF8
    if (!c1cs) {
        // 0x80448CD4: nop
    
            goto L_80448CF8;
    }
    // 0x80448CD4: nop

    // 0x80448CD8: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x80448CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448CE0: beql        $v0, $t7, L_80448E0C
    if (ctx->r2 == ctx->r15) {
        // 0x80448CE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448E0C;
    }
    goto skip_1;
    // 0x80448CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80448CE8: jal         0x80445954
    // 0x80448CEC: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_1;
    // 0x80448CEC: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    after_1:
    // 0x80448CF0: b           L_80448E0C
    // 0x80448CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448E0C;
    // 0x80448CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448CF8:
    // 0x80448CF8: lwc1        $f8, -0x7BD8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14048));
    // 0x80448CFC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1404C) << 16);
    // 0x80448D00: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80448D04: nop

    // 0x80448D08: bc1f        L_80448D30
    if (!c1cs) {
        // 0x80448D0C: nop
    
            goto L_80448D30;
    }
    // 0x80448D0C: nop

    // 0x80448D10: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x80448D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448D18: beql        $v0, $t8, L_80448E0C
    if (ctx->r2 == ctx->r24) {
        // 0x80448D1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448E0C;
    }
    goto skip_2;
    // 0x80448D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80448D20: jal         0x80445954
    // 0x80448D24: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_2;
    // 0x80448D24: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    after_2:
    // 0x80448D28: b           L_80448E0C
    // 0x80448D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448E0C;
    // 0x80448D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448D30:
    // 0x80448D30: lwc1        $f10, -0x7BD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1404C));
    // 0x80448D34: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14050) << 16);
    // 0x80448D38: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80448D3C: nop

    // 0x80448D40: bc1f        L_80448D68
    if (!c1cs) {
        // 0x80448D44: nop
    
            goto L_80448D68;
    }
    // 0x80448D44: nop

    // 0x80448D48: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x80448D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448D50: beql        $v0, $t9, L_80448E0C
    if (ctx->r2 == ctx->r25) {
        // 0x80448D54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448E0C;
    }
    goto skip_3;
    // 0x80448D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80448D58: jal         0x80445954
    // 0x80448D5C: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_3;
    // 0x80448D5C: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    after_3:
    // 0x80448D60: b           L_80448E0C
    // 0x80448D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448E0C;
    // 0x80448D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448D68:
    // 0x80448D68: lwc1        $f16, -0x7BD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14050));
    // 0x80448D6C: lui         $at, 0x43FF
    ctx->r1 = S32(0X43FF << 16);
    // 0x80448D70: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80448D74: nop

    // 0x80448D78: bc1fl       L_80448DA4
    if (!c1cs) {
        // 0x80448D7C: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80448DA4;
    }
    goto skip_4;
    // 0x80448D7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x80448D80: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x80448D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448D88: beql        $v0, $t0, L_80448E0C
    if (ctx->r2 == ctx->r8) {
        // 0x80448D8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448E0C;
    }
    goto skip_5;
    // 0x80448D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80448D90: jal         0x80445954
    // 0x80448D94: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_4;
    // 0x80448D94: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    after_4:
    // 0x80448D98: b           L_80448E0C
    // 0x80448D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448E0C;
    // 0x80448D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80448DA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80448DA4:
    // 0x80448DA4: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x80448DA8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80448DAC: nop

    // 0x80448DB0: bc1fl       L_80448DDC
    if (!c1cs) {
        // 0x80448DB4: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80448DDC;
    }
    goto skip_6;
    // 0x80448DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_6:
    // 0x80448DB8: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x80448DBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448DC0: beql        $v0, $t1, L_80448E0C
    if (ctx->r2 == ctx->r9) {
        // 0x80448DC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448E0C;
    }
    goto skip_7;
    // 0x80448DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80448DC8: jal         0x80445954
    // 0x80448DCC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_5;
    // 0x80448DCC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    after_5:
    // 0x80448DD0: b           L_80448E0C
    // 0x80448DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448E0C;
    // 0x80448DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80448DD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80448DDC:
    // 0x80448DDC: nop

    // 0x80448DE0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80448DE4: nop

    // 0x80448DE8: bc1fl       L_80448E0C
    if (!c1cs) {
        // 0x80448DEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448E0C;
    }
    goto skip_8;
    // 0x80448DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80448DF0: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x80448DF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448DF8: beql        $v0, $t2, L_80448E0C
    if (ctx->r2 == ctx->r10) {
        // 0x80448DFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448E0C;
    }
    goto skip_9;
    // 0x80448DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80448E00: jal         0x80445954
    // 0x80448E04: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_6;
    // 0x80448E04: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    after_6:
    // 0x80448E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448E0C:
    // 0x80448E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80448E10: jr          $ra
    // 0x80448E14: nop

    return;
    // 0x80448E14: nop

;}
RECOMP_FUNC void func_80075388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007538C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80075390: addiu       $a1, $a1, -0x7B10
    ctx->r5 = ADD32(ctx->r5, -0X7B10);
    // 0x80075394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075398: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007539C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800753A0: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800753A4: bne         $t6, $zero, L_80075438
    if (ctx->r14 != 0) {
        // 0x800753A8: nop
    
            goto L_80075438;
    }
    // 0x800753A8: nop

    // 0x800753AC: bne         $t7, $zero, L_80075438
    if (ctx->r15 != 0) {
        // 0x800753B0: lui         $t8, 0x800B
        ctx->r24 = S32(0X800B << 16);
            goto L_80075438;
    }
    // 0x800753B0: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800753B4: lw          $t8, -0x7AF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AF8);
    // 0x800753B8: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x800753BC: lw          $t9, -0x7AF4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AF4);
    // 0x800753C0: bne         $t8, $zero, L_800753E8
    if (ctx->r24 != 0) {
        // 0x800753C4: nop
    
            goto L_800753E8;
    }
    // 0x800753C4: nop

    // 0x800753C8: bne         $t9, $zero, L_800753E8
    if (ctx->r25 != 0) {
        // 0x800753CC: nop
    
            goto L_800753E8;
    }
    // 0x800753CC: nop

    // 0x800753D0: jal         0x8008B920
    // 0x800753D4: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800753D4: nop

    after_0:
    // 0x800753D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800753DC: sw          $v0, -0x7AF8($at)
    MEM_W(-0X7AF8, ctx->r1) = ctx->r2;
    // 0x800753E0: b           L_80075438
    // 0x800753E4: sw          $v1, -0x7AF4($at)
    MEM_W(-0X7AF4, ctx->r1) = ctx->r3;
        goto L_80075438;
    // 0x800753E4: sw          $v1, -0x7AF4($at)
    MEM_W(-0X7AF4, ctx->r1) = ctx->r3;
L_800753E8:
    // 0x800753E8: jal         0x8008B920
    // 0x800753EC: nop

    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x800753EC: nop

    after_1:
    // 0x800753F0: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x800753F4: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800753F8: lw          $t1, -0x7AF4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AF4);
    // 0x800753FC: lw          $t0, -0x7AF8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AF8);
    // 0x80075400: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80075404: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x80075408: subu        $t2, $v0, $t0
    ctx->r10 = SUB32(ctx->r2, ctx->r8);
    // 0x8007540C: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x80075410: addiu       $a1, $a1, -0x7B10
    ctx->r5 = ADD32(ctx->r5, -0X7B10);
    // 0x80075414: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80075418: subu        $t3, $v1, $t1
    ctx->r11 = SUB32(ctx->r3, ctx->r9);
    // 0x8007541C: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x80075420: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80075424: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x80075428: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8007542C: addiu       $t6, $t6, -0x7B00
    ctx->r14 = ADD32(ctx->r14, -0X7B00);
    // 0x80075430: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80075434: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_80075438:
    // 0x80075438: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8007543C: addiu       $v0, $v0, -0x7B08
    ctx->r2 = ADD32(ctx->r2, -0X7B08);
    // 0x80075440: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80075444: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80075448: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007544C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80075450: jal         0x800751FC
    // 0x80075454: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800751FC(rdram, ctx);
        goto after_2;
    // 0x80075454: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80075458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007545C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075460: jr          $ra
    // 0x80075464: nop

    return;
    // 0x80075464: nop

;}
RECOMP_FUNC void func_8003BD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BD60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BD68: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8003BD6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003BD70: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003BD74: beq         $t6, $at, L_8003BE34
    if (ctx->r14 == ctx->r1) {
        // 0x8003BD78: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003BE34;
    }
    // 0x8003BD78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003BD7C: lw          $a1, 0x1F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1F0);
    // 0x8003BD80: bnel        $a1, $zero, L_8003BD9C
    if (ctx->r5 != 0) {
        // 0x8003BD84: lhu         $t7, 0xC($a1)
        ctx->r15 = MEM_HU(ctx->r5, 0XC);
            goto L_8003BD9C;
    }
    goto skip_0;
    // 0x8003BD84: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    skip_0:
    // 0x8003BD88: jal         0x8002EFF8
    // 0x8003BD8C: nop

    func_8002EFF8(rdram, ctx);
        goto after_0;
    // 0x8003BD8C: nop

    after_0:
    // 0x8003BD90: b           L_8003BE34
    // 0x8003BD94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003BE34;
    // 0x8003BD94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003BD98: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
L_8003BD9C:
    // 0x8003BD9C: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003BDA0: bnel        $t7, $at, L_8003BDCC
    if (ctx->r15 != ctx->r1) {
        // 0x8003BDA4: lw          $t9, 0x1E0($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X1E0);
            goto L_8003BDCC;
    }
    goto skip_1;
    // 0x8003BDA4: lw          $t9, 0x1E0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1E0);
    skip_1:
    // 0x8003BDA8: lw          $t8, 0x1E0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1E0);
    // 0x8003BDAC: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x8003BDB0: beql        $at, $zero, L_8003BDCC
    if (ctx->r1 == 0) {
        // 0x8003BDB4: lw          $t9, 0x1E0($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X1E0);
            goto L_8003BDCC;
    }
    goto skip_2;
    // 0x8003BDB4: lw          $t9, 0x1E0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1E0);
    skip_2:
    // 0x8003BDB8: jal         0x8003BCDC
    // 0x8003BDBC: nop

    func_8003BCDC(rdram, ctx);
        goto after_1;
    // 0x8003BDBC: nop

    after_1:
    // 0x8003BDC0: b           L_8003BE38
    // 0x8003BDC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003BE38;
    // 0x8003BDC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BDC8: lw          $t9, 0x1E0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1E0);
L_8003BDCC:
    // 0x8003BDCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003BDD0: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8003BDD4: bne         $t9, $at, L_8003BE00
    if (ctx->r25 != ctx->r1) {
        // 0x8003BDD8: lui         $t3, 0x800F
        ctx->r11 = S32(0X800F << 16);
            goto L_8003BE00;
    }
    // 0x8003BDD8: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x8003BDDC: lw          $t0, 0x7EA8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7EA8);
    // 0x8003BDE0: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x8003BDE4: andi        $t2, $t1, 0x200F
    ctx->r10 = ctx->r9 & 0X200F;
    // 0x8003BDE8: beq         $t2, $zero, L_8003BE24
    if (ctx->r10 == 0) {
        // 0x8003BDEC: nop
    
            goto L_8003BE24;
    }
    // 0x8003BDEC: nop

    // 0x8003BDF0: jal         0x8003BCDC
    // 0x8003BDF4: nop

    func_8003BCDC(rdram, ctx);
        goto after_2;
    // 0x8003BDF4: nop

    after_2:
    // 0x8003BDF8: b           L_8003BE38
    // 0x8003BDFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003BE38;
    // 0x8003BDFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003BE00:
    // 0x8003BE00: lw          $t3, 0x7EA8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7EA8);
    // 0x8003BE04: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8003BE08: andi        $t5, $t4, 0x200F
    ctx->r13 = ctx->r12 & 0X200F;
    // 0x8003BE0C: bne         $t5, $zero, L_8003BE24
    if (ctx->r13 != 0) {
        // 0x8003BE10: nop
    
            goto L_8003BE24;
    }
    // 0x8003BE10: nop

    // 0x8003BE14: jal         0x8003BCDC
    // 0x8003BE18: nop

    func_8003BCDC(rdram, ctx);
        goto after_3;
    // 0x8003BE18: nop

    after_3:
    // 0x8003BE1C: b           L_8003BE38
    // 0x8003BE20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003BE38;
    // 0x8003BE20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003BE24:
    // 0x8003BE24: jal         0x8003BD18
    // 0x8003BE28: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8003BD18(rdram, ctx);
        goto after_4;
    // 0x8003BE28: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x8003BE2C: b           L_8003BE38
    // 0x8003BE30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003BE38;
    // 0x8003BE30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003BE34:
    // 0x8003BE34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003BE38:
    // 0x8003BE38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BE3C: jr          $ra
    // 0x8003BE40: nop

    return;
    // 0x8003BE40: nop

;}
RECOMP_FUNC void func_805818C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805818C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805818C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805818CC: jal         0x80580C70
    // 0x805818D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x805818D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805818D4: jal         0x80581880
    // 0x805818D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80581880(rdram, ctx);
        goto after_1;
    // 0x805818D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805818DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805818E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805818E4: jr          $ra
    // 0x805818E8: nop

    return;
    // 0x805818E8: nop

;}
RECOMP_FUNC void func_8002D3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D3FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002D400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D408: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D40C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D410: jal         0x8002D198
    // 0x8002D414: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8002D198(rdram, ctx);
        goto after_0;
    // 0x8002D414: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002D418: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D41C: jal         0x8002BB90
    // 0x8002D420: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002BB90(rdram, ctx);
        goto after_1;
    // 0x8002D420: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8002D424: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002D428: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002D42C: addiu       $a1, $a1, -0x2CFC
    ctx->r5 = ADD32(ctx->r5, -0X2CFC);
    // 0x8002D430: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002D434: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8002D438: addiu       $t8, $t8, 0x85C
    ctx->r24 = ADD32(ctx->r24, 0X85C);
    // 0x8002D43C: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
    // 0x8002D440: sb          $t7, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r15;
    // 0x8002D444: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8002D448: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002D44C: jal         0x80028118
    // 0x8002D450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028118(rdram, ctx);
        goto after_2;
    // 0x8002D450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002D454: jal         0x8002AEE4
    // 0x8002D458: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    func_8002AEE4(rdram, ctx);
        goto after_3;
    // 0x8002D458: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    after_3:
    // 0x8002D45C: jal         0x8001D770
    // 0x8002D460: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x8002D460: nop

    after_4:
    // 0x8002D464: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002D468: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002D46C: jal         0x80067BF8
    // 0x8002D470: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_5;
    // 0x8002D470: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8002D474: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x8002D478: jal         0x80067818
    // 0x8002D47C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8002D47C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8002D480: jal         0x800677F8
    // 0x8002D484: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800677F8(rdram, ctx);
        goto after_7;
    // 0x8002D484: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_7:
    // 0x8002D488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D48C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D490: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002D494: jr          $ra
    // 0x8002D498: nop

    return;
    // 0x8002D498: nop

;}
RECOMP_FUNC void func_8045B444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B444: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8045B448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045B44C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045B450: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8045B454: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8045B458: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(104, 0XCB0) << 16);
    // 0x8045B45C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8045B460: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8045B464: addiu       $t7, $t7, -0x4940
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(104, 0XCB0));
    // 0x8045B468: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8045B46C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045B470: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8045B474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045B478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8045B47C: jal         0x8045B594
    // 0x8045B480: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8045B594(rdram, ctx);
        goto after_0;
    // 0x8045B480: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8045B484: jal         0x8045B418
    // 0x8045B488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045B418(rdram, ctx);
        goto after_1;
    // 0x8045B488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8045B48C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(104, 0X9E8) << 16);
    // 0x8045B490: addiu       $t9, $t9, -0x4C08
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(104, 0X9E8));
    // 0x8045B494: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x8045B498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045B49C: jal         0x80045A34
    // 0x8045B4A0: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8045B4A0: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_2:
    // 0x8045B4A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8045B4A8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8045B4AC: sw          $s0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r16;
    // 0x8045B4B0: sh          $zero, 0x40($v0)
    MEM_H(0X40, ctx->r2) = 0;
    // 0x8045B4B4: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8045B4B8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8045B4BC: jal         0x80052CA8
    // 0x8045B4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052CA8(rdram, ctx);
        goto after_3;
    // 0x8045B4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8045B4C4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8045B4C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8045B4CC: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // 0x8045B4D0: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8045B4D4: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x8045B4D8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8045B4DC: sh          $t0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r8;
    // 0x8045B4E0: sh          $zero, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = 0;
    // 0x8045B4E4: swc1        $f0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
    // 0x8045B4E8: swc1        $f0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f0.u32l;
    // 0x8045B4EC: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8045B4F0: sw          $t1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r9;
    // 0x8045B4F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8045B4F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8045B4FC: jal         0x80048378
    // 0x8045B500: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    func_80048378(rdram, ctx);
        goto after_4;
    // 0x8045B500: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    after_4:
    // 0x8045B504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045B508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045B50C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8045B510: jr          $ra
    // 0x8045B514: nop

    return;
    // 0x8045B514: nop

;}
RECOMP_FUNC void func_800497D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800497D4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800497D8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x800497DC: lbu         $t6, 0xF6F($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF6F);
    // 0x800497E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800497E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800497E8: bnel        $t6, $zero, L_80049820
    if (ctx->r14 != 0) {
        // 0x800497EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049820;
    }
    goto skip_0;
    // 0x800497EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800497F0: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x800497F4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800497F8: bnel        $t7, $at, L_80049820
    if (ctx->r15 != ctx->r1) {
        // 0x800497FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049820;
    }
    goto skip_1;
    // 0x800497FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80049800: jal         0x800492C0
    // 0x80049804: addiu       $a0, $zero, -0xAC
    ctx->r4 = ADD32(0, -0XAC);
    func_800492C0(rdram, ctx);
        goto after_0;
    // 0x80049804: addiu       $a0, $zero, -0xAC
    ctx->r4 = ADD32(0, -0XAC);
    after_0:
    // 0x80049808: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8004980C: beq         $v0, $zero, L_8004981C
    if (ctx->r2 == 0) {
        // 0x80049810: addiu       $v1, $v1, 0x7EA0
        ctx->r3 = ADD32(ctx->r3, 0X7EA0);
            goto L_8004981C;
    }
    // 0x80049810: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80049814: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80049818: sb          $t8, 0xF6F($v1)
    MEM_B(0XF6F, ctx->r3) = ctx->r24;
L_8004981C:
    // 0x8004981C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049820:
    // 0x80049820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049824: jr          $ra
    // 0x80049828: nop

    return;
    // 0x80049828: nop

    // 0x8004982C: nop

;}
RECOMP_FUNC void func_80462374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462374: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80462378: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046237C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80462380: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80462384: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80462388: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(122, 0X37A8) << 16);
    // 0x8046238C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80462390: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80462394: addiu       $t7, $t7, 0x3D38
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(122, 0X37A8));
    // 0x80462398: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8046239C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804623A0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804623A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804623A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804623AC: jal         0x804623F0
    // 0x804623B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804623F0(rdram, ctx);
        goto after_0;
    // 0x804623B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804623B4: jal         0x804622C4
    // 0x804623B8: nop

    func_804622C4(rdram, ctx);
        goto after_1;
    // 0x804623B8: nop

    after_1:
    // 0x804623BC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804623C0: jal         0x804622E4
    // 0x804623C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804622E4(rdram, ctx);
        goto after_2;
    // 0x804623C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804623C8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804623CC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804623D0: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x804623D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804623D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804623DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804623E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804623E4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804623E8: jr          $ra
    // 0x804623EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804623EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80474D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474D00: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474D04: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474D08: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474D0C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474D10: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474D14: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474D18: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474D1C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474D20: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474D24: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474D28: jr          $ra
    // 0x80474D2C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474D2C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8067C174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067C174: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067C178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067C17C: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8067C180: lui         $a3, 0x8067
    ctx->r7 = S32(0X8067 << 16);
    // 0x8067C184: lui         $a1, 0x8068
    ctx->r5 = S32(RELOC_HI16(541, 0X201C) << 16);
    // 0x8067C188: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8067C18C: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x8067C190: addiu       $t8, $zero, 0x3B8
    ctx->r24 = ADD32(0, 0X3B8);
    // 0x8067C194: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8067C198: lw          $a3, -0x41B0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X41B0);
    // 0x8067C19C: addiu       $a1, $a1, -0x4334
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(541, 0X201C));
    // 0x8067C1A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067C1A4: jal         0x8067BF84
    // 0x8067C1A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8067BF84(rdram, ctx);
        goto after_0;
    // 0x8067C1A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8067C1AC: beq         $v0, $zero, L_8067C1C4
    if (ctx->r2 == 0) {
        // 0x8067C1B0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8067C1C4;
    }
    // 0x8067C1B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067C1B4: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x8067C1B8: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X1CF0) << 16);
    // 0x8067C1BC: addiu       $t9, $t9, -0x4660
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(541, 0X1CF0));
    // 0x8067C1C0: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
L_8067C1C4:
    // 0x8067C1C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067C1C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067C1CC: jr          $ra
    // 0x8067C1D0: nop

    return;
    // 0x8067C1D0: nop

;}
RECOMP_FUNC void func_80408684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80408688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040868C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80408690: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80408694: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(11, 0X2DE0) << 16);
    // 0x80408698: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040869C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804086A0: lw          $t8, -0x5850($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(11, 0X2DE0));
    // 0x804086A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804086A8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804086AC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804086B0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804086B4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804086B8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804086BC: beql        $v1, $zero, L_804086F0
    if (ctx->r3 == 0) {
        // 0x804086C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804086F0;
    }
    goto skip_0;
    // 0x804086C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804086C4: jalr        $v1
    // 0x804086C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804086C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804086CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804086D0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804086D4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804086D8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804086DC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804086E0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804086E4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804086E8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804086EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804086F0:
    // 0x804086F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804086F4: jr          $ra
    // 0x804086F8: nop

    return;
    // 0x804086F8: nop

;}
RECOMP_FUNC void func_80032F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032F9C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80032FA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80032FA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032FA8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80032FAC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032FB0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80032FB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80032FB8: lwc1        $f4, 0x184($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X184);
    // 0x80032FBC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80032FC0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80032FC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80032FC8: bne         $a1, $zero, L_80033148
    if (ctx->r5 != 0) {
        // 0x80032FCC: add.s       $f12, $f4, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
            goto L_80033148;
    }
    // 0x80032FCC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80032FD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80032FD4: nop

    // 0x80032FD8: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80032FDC: nop

    // 0x80032FE0: bc1fl       L_8003314C
    if (!c1cs) {
        // 0x80032FE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003314C;
    }
    goto skip_0;
    // 0x80032FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80032FE8: lw          $t6, 0x190($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X190);
    // 0x80032FEC: beql        $t6, $zero, L_8003314C
    if (ctx->r14 == 0) {
        // 0x80032FF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003314C;
    }
    goto skip_1;
    // 0x80032FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80032FF4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80032FF8: jal         0x80066DE4
    // 0x80032FFC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80032FFC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80033000: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80033004: jal         0x80066E88
    // 0x80033008: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80033008: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8003300C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80033010: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80033014: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80033018: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003301C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80033020: lwc1        $f10, 0x194($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X194);
    // 0x80033024: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80033028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003302C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80033030: lwc1        $f8, 0x64($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80033034: div.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80033038: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8003303C: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
    // 0x80033040: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80033044: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x80033048: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003304C: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80033050: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80033054: nop

    // 0x80033058: bc1fl       L_8003306C
    if (!c1cs) {
        // 0x8003305C: swc1        $f12, 0xC8($s0)
        MEM_W(0XC8, ctx->r16) = ctx->f12.u32l;
            goto L_8003306C;
    }
    goto skip_2;
    // 0x8003305C: swc1        $f12, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f12.u32l;
    skip_2:
    // 0x80033060: b           L_8003306C
    // 0x80033064: swc1        $f14, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f14.u32l;
        goto L_8003306C;
    // 0x80033064: swc1        $f14, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f14.u32l;
    // 0x80033068: swc1        $f12, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f12.u32l;
L_8003306C:
    // 0x8003306C: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x80033070: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80033074: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80033078: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x8003307C: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80033080: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80033084: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x80033088: jal         0x80066DE4
    // 0x8003308C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8003308C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80033090: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80033094: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80033098: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8003309C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800330A0: lwc1        $f10, 0x68($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X68);
    // 0x800330A4: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800330A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800330AC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800330B0: jal         0x80066E88
    // 0x800330B4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x800330B4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x800330B8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800330BC: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800330C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800330C4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800330C8: lwc1        $f4, 0x54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54);
    // 0x800330CC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800330D0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800330D4: lw          $t0, 0x59C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X59C);
    // 0x800330D8: lw          $t4, 0xA68($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XA68);
    // 0x800330DC: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800330E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800330E4: addiu       $a0, $zero, 0x400F
    ctx->r4 = ADD32(0, 0X400F);
    // 0x800330E8: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x800330EC: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x800330F0: lwc1        $f18, 0x8C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800330F4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800330F8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x800330FC: lw          $t1, 0x10C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10C);
    // 0x80033100: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80033104: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x80033108: lw          $t9, 0x14($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X14);
    // 0x8003310C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80033110: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80033114: jalr        $t9
    // 0x80033118: lw          $a2, -0x20E8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X20E8);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80033118: lw          $a2, -0x20E8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X20E8);
    after_4:
    // 0x8003311C: jal         0x8001D770
    // 0x80033120: nop

    func_8001D770(rdram, ctx);
        goto after_5;
    // 0x80033120: nop

    after_5:
    // 0x80033124: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80033128: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8003312C: jal         0x80067BF8
    // 0x80033130: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_6;
    // 0x80033130: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x80033134: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x80033138: jal         0x80067818
    // 0x8003313C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8003313C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80033140: b           L_8003314C
    // 0x80033144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003314C;
    // 0x80033144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80033148:
    // 0x80033148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003314C:
    // 0x8003314C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80033150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80033154: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80033158: jr          $ra
    // 0x8003315C: nop

    return;
    // 0x8003315C: nop

;}
RECOMP_FUNC void func_807C5464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C5464: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807C5468: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807C546C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807C5470: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807C5474: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807C5478: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807C547C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807C5480: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807C5484: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807C5488: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(910, 0X131C) << 16);
    // 0x807C548C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C5490: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807C5494: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807C5498: lw          $t1, 0x5CDC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(910, 0X131C));
    // 0x807C549C: jr          $ra
    // 0x807C54A0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807C54A0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x807C54A4: nop

    // 0x807C54A8: nop

    // 0x807C54AC: nop

;}
RECOMP_FUNC void func_80438074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438074: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80438078: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8043807C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80438080: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80438084: nop

    // 0x80438088: bc1fl       L_8043809C
    if (!c1cs) {
        // 0x8043808C: neg.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
            goto L_8043809C;
    }
    goto skip_0;
    // 0x8043808C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    skip_0:
    // 0x80438090: b           L_804380B0
    // 0x80438094: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_804380B0;
    // 0x80438094: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80438098: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_8043809C:
    // 0x8043809C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x804380A0: nop

    // 0x804380A4: bc1f        L_804380B0
    if (!c1cs) {
        // 0x804380A8: nop
    
            goto L_804380B0;
    }
    // 0x804380A8: nop

    // 0x804380AC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_804380B0:
    // 0x804380B0: jr          $ra
    // 0x804380B4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    return;
    // 0x804380B4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_8004D06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D06C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004D070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D074: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004D078: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D07C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004D080: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004D084: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D088: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004D08C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8004D090: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D094: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D098: jal         0x8004C13C
    // 0x8004D09C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004C13C(rdram, ctx);
        goto after_0;
    // 0x8004D09C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004D0A0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004D0A4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004D0A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004D0AC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004D0B0: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x8004D0B4: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8004D0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D0BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004D0C0: jr          $ra
    // 0x8004D0C4: nop

    return;
    // 0x8004D0C4: nop

;}
RECOMP_FUNC void func_807115CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807115CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807115D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807115D4: jal         0x80711510
    // 0x807115D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80711510(rdram, ctx);
        goto after_0;
    // 0x807115D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807115DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807115E0: beq         $v0, $at, L_807115FC
    if (ctx->r2 == ctx->r1) {
        // 0x807115E4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807115FC;
    }
    // 0x807115E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807115E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807115EC: beq         $v0, $at, L_8071160C
    if (ctx->r2 == ctx->r1) {
        // 0x807115F0: nop
    
            goto L_8071160C;
    }
    // 0x807115F0: nop

    // 0x807115F4: b           L_8071161C
    // 0x807115F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8071161C;
    // 0x807115F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807115FC:
    // 0x807115FC: jal         0x807111A4
    // 0x80711600: nop

    func_807111A4(rdram, ctx);
        goto after_1;
    // 0x80711600: nop

    after_1:
    // 0x80711604: b           L_8071161C
    // 0x80711608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8071161C;
    // 0x80711608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8071160C:
    // 0x8071160C: jal         0x807111A4
    // 0x80711610: nop

    func_807111A4(rdram, ctx);
        goto after_2;
    // 0x80711610: nop

    after_2:
    // 0x80711614: b           L_8071161C
    // 0x80711618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8071161C;
    // 0x80711618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8071161C:
    // 0x8071161C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80711620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80711624: jr          $ra
    // 0x80711628: nop

    return;
    // 0x80711628: nop

;}
RECOMP_FUNC void func_80580984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8058098C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80580990: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80580994: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(399, 0X4588) << 16);
    // 0x80580998: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8058099C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805809A0: addiu       $t7, $t7, 0x3398
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(399, 0X4588));
    // 0x805809A4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805809A8: lhu         $t9, 0xC($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XC);
    // 0x805809AC: addiu       $at, $zero, 0x4710
    ctx->r1 = ADD32(0, 0X4710);
    // 0x805809B0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805809B4: beq         $t9, $at, L_805809CC
    if (ctx->r25 == ctx->r1) {
        // 0x805809B8: nop
    
            goto L_805809CC;
    }
    // 0x805809B8: nop

    // 0x805809BC: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x805809C0: lui         $t0, 0x8058
    ctx->r8 = S32(RELOC_HI16(399, 0X4190) << 16);
    // 0x805809C4: addiu       $t0, $t0, 0x2FA0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(399, 0X4190));
    // 0x805809C8: sw          $t0, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r8;
L_805809CC:
    // 0x805809CC: jal         0x805808E4
    // 0x805809D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805808E4(rdram, ctx);
        goto after_0;
    // 0x805809D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805809D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805809D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805809DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805809E0: jal         0x80580920
    // 0x805809E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80580920(rdram, ctx);
        goto after_1;
    // 0x805809E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x805809E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805809EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805809F0: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x805809F4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805809F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805809FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80580A00: nop

    // 0x80580A04: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x80580A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580A10: jr          $ra
    // 0x80580A14: nop

    return;
    // 0x80580A14: nop

;}
RECOMP_FUNC void func_807B26B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B26B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807B26BC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x807B26C0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x807B26C4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x807B26C8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x807B26CC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x807B26D0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x807B26D4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x807B26D8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x807B26DC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x807B26E0: lw          $s4, 0x174($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X174);
    // 0x807B26E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B26E8: jal         0x80049D74
    // 0x807B26EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x807B26EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x807B26F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B26F4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x807B26F8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X39B8) << 16);
    // 0x807B26FC: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x807B2700: addiu       $s2, $s2, -0x3108
    ctx->r18 = ADD32(ctx->r18, -0X3108);
    // 0x807B2704: lwc1        $f20, 0x3508($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X39B8));
    // 0x807B2708: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B270C: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x807B2710: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
L_807B2714:
    // 0x807B2714: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B2718: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B271C: jal         0x8004D150
    // 0x807B2720: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x807B2720: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x807B2724: lwc1        $f4, 0xC8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x807B2728: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x807B272C: nop

    // 0x807B2730: bc1fl       L_807B2790
    if (!c1cs) {
        // 0x807B2734: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807B2790;
    }
    goto skip_0;
    // 0x807B2734: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x807B2738: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B273C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x807B2740: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x807B2744: mflo        $t8
    ctx->r24 = lo;
    // 0x807B2748: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x807B274C: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x807B2750: beq         $t0, $zero, L_807B278C
    if (ctx->r8 == 0) {
        // 0x807B2754: lui         $a2, 0x8006
        ctx->r6 = S32(0X8006 << 16);
            goto L_807B278C;
    }
    // 0x807B2754: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x807B2758: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x807B275C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B2760: jal         0x8004D618
    // 0x807B2764: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004D618(rdram, ctx);
        goto after_2;
    // 0x807B2764: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x807B2768: addiu       $a0, $s1, 0x84
    ctx->r4 = ADD32(ctx->r17, 0X84);
    // 0x807B276C: jal         0x80047AB8
    // 0x807B2770: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047AB8(rdram, ctx);
        goto after_3;
    // 0x807B2770: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x807B2774: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807B2778: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B277C: lwc1        $f6, 0xC8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x807B2780: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807B2784: b           L_807B279C
    // 0x807B2788: swc1        $f10, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f10.u32l;
        goto L_807B279C;
    // 0x807B2788: swc1        $f10, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f10.u32l;
L_807B278C:
    // 0x807B278C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_807B2790:
    // 0x807B2790: sltiu       $at, $s0, 0x4
    ctx->r1 = ctx->r16 < 0X4 ? 1 : 0;
    // 0x807B2794: bnel        $at, $zero, L_807B2714
    if (ctx->r1 != 0) {
        // 0x807B2798: mfc1        $a3, $f22
        ctx->r7 = (int32_t)ctx->f22.u32l;
            goto L_807B2714;
    }
    goto skip_1;
    // 0x807B2798: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    skip_1:
L_807B279C:
    // 0x807B279C: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x807B27A0: addiu       $s2, $s2, -0x2F94
    ctx->r18 = ADD32(ctx->r18, -0X2F94);
    // 0x807B27A4: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x807B27A8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
L_807B27AC:
    // 0x807B27AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B27B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B27B4: jal         0x8004D150
    // 0x807B27B8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8004D150(rdram, ctx);
        goto after_4;
    // 0x807B27B8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x807B27BC: lwc1        $f16, 0xC4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x807B27C0: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x807B27C4: nop

    // 0x807B27C8: bc1fl       L_807B282C
    if (!c1cs) {
        // 0x807B27CC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807B282C;
    }
    goto skip_2;
    // 0x807B27CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x807B27D0: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B27D4: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x807B27D8: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x807B27DC: mflo        $t3
    ctx->r11 = lo;
    // 0x807B27E0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x807B27E4: lbu         $t5, 0x14($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X14);
    // 0x807B27E8: beq         $t5, $zero, L_807B2828
    if (ctx->r13 == 0) {
        // 0x807B27EC: lui         $a2, 0x8005
        ctx->r6 = S32(0X8005 << 16);
            goto L_807B2828;
    }
    // 0x807B27EC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x807B27F0: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    // 0x807B27F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B27F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B27FC: jal         0x8004D618
    // 0x807B2800: addiu       $s2, $s1, 0x84
    ctx->r18 = ADD32(ctx->r17, 0X84);
    func_8004D618(rdram, ctx);
        goto after_5;
    // 0x807B2800: addiu       $s2, $s1, 0x84
    ctx->r18 = ADD32(ctx->r17, 0X84);
    after_5:
    // 0x807B2804: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B2808: jal         0x80047AB8
    // 0x807B280C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047AB8(rdram, ctx);
        goto after_6;
    // 0x807B280C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x807B2810: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807B2814: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B2818: lwc1        $f18, 0xC4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x807B281C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x807B2820: b           L_807B2838
    // 0x807B2824: swc1        $f6, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f6.u32l;
        goto L_807B2838;
    // 0x807B2824: swc1        $f6, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f6.u32l;
L_807B2828:
    // 0x807B2828: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_807B282C:
    // 0x807B282C: sltiu       $at, $s0, 0x8
    ctx->r1 = ctx->r16 < 0X8 ? 1 : 0;
    // 0x807B2830: bnel        $at, $zero, L_807B27AC
    if (ctx->r1 != 0) {
        // 0x807B2834: mfc1        $a3, $f22
        ctx->r7 = (int32_t)ctx->f22.u32l;
            goto L_807B27AC;
    }
    goto skip_3;
    // 0x807B2834: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    skip_3:
L_807B2838:
    // 0x807B2838: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x807B283C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X39BC) << 16);
    // 0x807B2840: lwc1        $f20, 0x350C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X39BC));
    // 0x807B2844: addiu       $s2, $s2, -0x3078
    ctx->r18 = ADD32(ctx->r18, -0X3078);
    // 0x807B2848: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x807B284C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
L_807B2850:
    // 0x807B2850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B2854: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B2858: jal         0x8004D150
    // 0x807B285C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8004D150(rdram, ctx);
        goto after_7;
    // 0x807B285C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
    // 0x807B2860: lwc1        $f8, 0xC4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x807B2864: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x807B2868: nop

    // 0x807B286C: bc1fl       L_807B28D0
    if (!c1cs) {
        // 0x807B2870: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807B28D0;
    }
    goto skip_4;
    // 0x807B2870: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x807B2874: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B2878: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x807B287C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x807B2880: mflo        $t8
    ctx->r24 = lo;
    // 0x807B2884: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x807B2888: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x807B288C: beq         $t0, $zero, L_807B28CC
    if (ctx->r8 == 0) {
        // 0x807B2890: lui         $a2, 0x8005
        ctx->r6 = S32(0X8005 << 16);
            goto L_807B28CC;
    }
    // 0x807B2890: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x807B2894: addiu       $a2, $a2, -0x2B40
    ctx->r6 = ADD32(ctx->r6, -0X2B40);
    // 0x807B2898: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B289C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B28A0: jal         0x8004D618
    // 0x807B28A4: addiu       $s2, $s1, 0x84
    ctx->r18 = ADD32(ctx->r17, 0X84);
    func_8004D618(rdram, ctx);
        goto after_8;
    // 0x807B28A4: addiu       $s2, $s1, 0x84
    ctx->r18 = ADD32(ctx->r17, 0X84);
    after_8:
    // 0x807B28A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B28AC: jal         0x80047AB8
    // 0x807B28B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047AB8(rdram, ctx);
        goto after_9;
    // 0x807B28B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x807B28B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807B28B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807B28BC: lwc1        $f10, 0xC4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x807B28C0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807B28C4: b           L_807B28DC
    // 0x807B28C8: swc1        $f18, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f18.u32l;
        goto L_807B28DC;
    // 0x807B28C8: swc1        $f18, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f18.u32l;
L_807B28CC:
    // 0x807B28CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_807B28D0:
    // 0x807B28D0: sltiu       $at, $s0, 0xC
    ctx->r1 = ctx->r16 < 0XC ? 1 : 0;
    // 0x807B28D4: bnel        $at, $zero, L_807B2850
    if (ctx->r1 != 0) {
        // 0x807B28D8: mfc1        $a3, $f22
        ctx->r7 = (int32_t)ctx->f22.u32l;
            goto L_807B2850;
    }
    goto skip_5;
    // 0x807B28D8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    skip_5:
L_807B28DC:
    // 0x807B28DC: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x807B28E0: addiu       $s2, $s2, -0x3198
    ctx->r18 = ADD32(ctx->r18, -0X3198);
    // 0x807B28E4: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x807B28E8: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x807B28EC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
L_807B28F0:
    // 0x807B28F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B28F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B28F8: jal         0x8004D150
    // 0x807B28FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8004D150(rdram, ctx);
        goto after_10;
    // 0x807B28FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_10:
    // 0x807B2900: lwc1        $f4, 0xC8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x807B2904: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x807B2908: nop

    // 0x807B290C: bc1fl       L_807B2970
    if (!c1cs) {
        // 0x807B2910: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807B2970;
    }
    goto skip_6;
    // 0x807B2910: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_6:
    // 0x807B2914: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B2918: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x807B291C: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x807B2920: mflo        $t3
    ctx->r11 = lo;
    // 0x807B2924: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x807B2928: lbu         $t5, 0x14($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X14);
    // 0x807B292C: beq         $t5, $zero, L_807B296C
    if (ctx->r13 == 0) {
        // 0x807B2930: lui         $a2, 0x8005
        ctx->r6 = S32(0X8005 << 16);
            goto L_807B296C;
    }
    // 0x807B2930: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x807B2934: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    // 0x807B2938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B293C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B2940: jal         0x8004D618
    // 0x807B2944: addiu       $s2, $s1, 0x84
    ctx->r18 = ADD32(ctx->r17, 0X84);
    func_8004D618(rdram, ctx);
        goto after_11;
    // 0x807B2944: addiu       $s2, $s1, 0x84
    ctx->r18 = ADD32(ctx->r17, 0X84);
    after_11:
    // 0x807B2948: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B294C: jal         0x80047AB8
    // 0x807B2950: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047AB8(rdram, ctx);
        goto after_12;
    // 0x807B2950: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x807B2954: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807B2958: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B295C: lwc1        $f6, 0xC8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x807B2960: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807B2964: b           L_807B2978
    // 0x807B2968: swc1        $f10, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f10.u32l;
        goto L_807B2978;
    // 0x807B2968: swc1        $f10, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f10.u32l;
L_807B296C:
    // 0x807B296C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_807B2970:
    // 0x807B2970: bnel        $s0, $s3, L_807B28F0
    if (ctx->r16 != ctx->r19) {
        // 0x807B2974: mfc1        $a3, $f22
        ctx->r7 = (int32_t)ctx->f22.u32l;
            goto L_807B28F0;
    }
    goto skip_7;
    // 0x807B2974: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    skip_7:
L_807B2978:
    // 0x807B2978: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x807B297C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x807B2980: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x807B2984: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x807B2988: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x807B298C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x807B2990: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x807B2994: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x807B2998: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x807B299C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x807B29A0: jr          $ra
    // 0x807B29A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x807B29A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_807B3C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3C08: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807B3C0C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807B3C10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B3C14: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(877, 0X2A8) << 16);
    // 0x807B3C18: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807B3C1C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807B3C20: lw          $t8, 0x3D38($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(877, 0X2A8));
    // 0x807B3C24: jr          $ra
    // 0x807B3C28: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x807B3C28: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80535FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535FEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80535FF0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80535FF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80535FF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80535FFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80536000: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80536004: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80536008: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8053600C: addiu       $t6, $zero, 0x1D4C
    ctx->r14 = ADD32(0, 0X1D4C);
    // 0x80536010: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80536014: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80536018: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8053601C: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x80536020: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80536024: jal         0x8053589C
    // 0x80536028: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8053589C(rdram, ctx);
        goto after_0;
    // 0x80536028: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8053602C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80536030: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80536034: addiu       $t8, $zero, 0x1D4C
    ctx->r24 = ADD32(0, 0X1D4C);
    // 0x80536038: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8053603C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80536040: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80536044: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x80536048: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8053604C: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80536050: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80536054: jal         0x8053589C
    // 0x80536058: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8053589C(rdram, ctx);
        goto after_1;
    // 0x80536058: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8053605C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80536060: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80536064: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80536068: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8053606C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80536070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80536074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80536078: jr          $ra
    // 0x8053607C: nop

    return;
    // 0x8053607C: nop

;}
RECOMP_FUNC void func_800493B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800493B8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800493BC: lh          $a1, 0x5A4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X5A4);
    // 0x800493C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800493C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800493C8: beq         $a1, $at, L_800493E4
    if (ctx->r5 == ctx->r1) {
        // 0x800493CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800493E4;
    }
    // 0x800493CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800493D0: jal         0x80067878
    // 0x800493D4: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x800493D4: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_0:
    // 0x800493D8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800493DC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800493E0: sh          $t6, 0x5A4($at)
    MEM_H(0X5A4, ctx->r1) = ctx->r14;
L_800493E4:
    // 0x800493E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800493E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800493EC: jr          $ra
    // 0x800493F0: nop

    return;
    // 0x800493F0: nop

;}
RECOMP_FUNC void func_800070EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800070EC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800070F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800070F4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800070F8: jal         0x800073BC
    // 0x800070FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x800070FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80007100: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80007104: lw          $t6, 0x6A88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A88);
    // 0x80007108: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8000710C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80007110: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80007114: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80007118: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8000711C: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x80007120: lbu         $a2, 0x3($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3);
    // 0x80007124: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80007128: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000712C: beq         $a0, $at, L_8000714C
    if (ctx->r4 == ctx->r1) {
        // 0x80007130: sw          $a2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r6;
            goto L_8000714C;
    }
    // 0x80007130: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80007134: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80007138: jal         0x80007014
    // 0x8000713C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    func_80007014(rdram, ctx);
        goto after_1;
    // 0x8000713C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80007140: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80007144: b           L_80007150
    // 0x80007148: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80007150;
    // 0x80007148: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_8000714C:
    // 0x8000714C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80007150:
    // 0x80007150: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80007154: beq         $a2, $at, L_8000716C
    if (ctx->r6 == ctx->r1) {
        // 0x80007158: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8000716C;
    }
    // 0x80007158: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000715C: jal         0x80007014
    // 0x80007160: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80007014(rdram, ctx);
        goto after_2;
    // 0x80007160: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80007164: b           L_80007170
    // 0x80007168: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80007170;
    // 0x80007168: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8000716C:
    // 0x8000716C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80007170:
    // 0x80007170: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80007174: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80007178: jal         0x800071C8
    // 0x8000717C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800071C8(rdram, ctx);
        goto after_3;
    // 0x8000717C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x80007180: bne         $v0, $zero, L_80007190
    if (ctx->r2 != 0) {
        // 0x80007184: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80007190;
    }
    // 0x80007184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80007188: b           L_800071B8
    // 0x8000718C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800071B8;
    // 0x8000718C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007190:
    // 0x80007190: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80007194: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007198: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000719C: bne         $t8, $at, L_800071B4
    if (ctx->r24 != ctx->r1) {
        // 0x800071A0: addiu       $a2, $sp, 0x20
        ctx->r6 = ADD32(ctx->r29, 0X20);
            goto L_800071B4;
    }
    // 0x800071A0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800071A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800071A8: jal         0x80008C3C
    // 0x800071AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80008C3C(rdram, ctx);
        goto after_4;
    // 0x800071AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_4:
    // 0x800071B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_800071B4:
    // 0x800071B4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800071B8:
    // 0x800071B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800071BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800071C0: jr          $ra
    // 0x800071C4: nop

    return;
    // 0x800071C4: nop

;}
RECOMP_FUNC void func_80777668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077766C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80777670: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80777674: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80777678: lui         $t7, 0x8077
    ctx->r15 = S32(RELOC_HI16(775, 0X4B4) << 16);
    // 0x8077767C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80777680: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80777684: addiu       $t7, $t7, 0x78C4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(775, 0X4B4));
    // 0x80777688: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8077768C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80777690: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80777694: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80777698: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8077769C: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x807776A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807776A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807776A8: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x807776AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x807776B0: jal         0x80048378
    // 0x807776B4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x807776B4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x807776B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x807776BC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x807776C0: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x807776C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807776C8: bnel        $v1, $zero, L_807776E8
    if (ctx->r3 != 0) {
        // 0x807776CC: sh          $zero, 0x8($v1)
        MEM_H(0X8, ctx->r3) = 0;
            goto L_807776E8;
    }
    goto skip_0;
    // 0x807776CC: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    skip_0:
    // 0x807776D0: jal         0x80045A34
    // 0x807776D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x807776D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x807776D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x807776DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807776E0: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x807776E4: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
L_807776E8:
    // 0x807776E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807776EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807776F0: jr          $ra
    // 0x807776F4: nop

    return;
    // 0x807776F4: nop

;}
RECOMP_FUNC void func_8057DB40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DB40: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(393, 0XE8) << 16);
    // 0x8057DB44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8057DB48: jr          $ra
    // 0x8057DB4C: addiu       $v0, $v0, -0x23D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(393, 0XE8));
    return;
    // 0x8057DB4C: addiu       $v0, $v0, -0x23D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(393, 0XE8));
;}
RECOMP_FUNC void func_80029574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029574: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80029578: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8002957C: lw          $v0, 0x34($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X34);
    // 0x80029580: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80029584: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80029588: lw          $t6, -0x2234($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2234);
    // 0x8002958C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80029590: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80029594: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80029598: bne         $at, $zero, L_80029600
    if (ctx->r1 != 0) {
        // 0x8002959C: addu        $t8, $t8, $v1
        ctx->r24 = ADD32(ctx->r24, ctx->r3);
            goto L_80029600;
    }
    // 0x8002959C: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800295A0: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800295A4: lw          $t7, -0x221C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X221C);
    // 0x800295A8: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800295AC: beq         $at, $zero, L_800295E8
    if (ctx->r1 == 0) {
        // 0x800295B0: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_800295E8;
    }
    // 0x800295B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800295B4: lwc1        $f4, -0x1DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1DC);
    // 0x800295B8: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x800295BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800295C0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800295C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800295C8: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800295CC: lwc1        $f8, 0xC0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC0);
    // 0x800295D0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800295D4: nop

    // 0x800295D8: bc1f        L_80029670
    if (!c1cs) {
        // 0x800295DC: nop
    
            goto L_80029670;
    }
    // 0x800295DC: nop

    // 0x800295E0: jr          $ra
    // 0x800295E4: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800295E4: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
L_800295E8:
    // 0x800295E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800295EC: nop

    // 0x800295F0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800295F4: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x800295F8: jr          $ra
    // 0x800295FC: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800295FC: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
L_80029600:
    // 0x80029600: lw          $t8, -0x227C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X227C);
    // 0x80029604: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80029608: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8002960C: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80029610: bne         $at, $zero, L_80029670
    if (ctx->r1 != 0) {
        // 0x80029614: nop
    
            goto L_80029670;
    }
    // 0x80029614: nop

    // 0x80029618: lw          $t9, -0x2264($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2264);
    // 0x8002961C: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80029620: beq         $at, $zero, L_8002965C
    if (ctx->r1 == 0) {
        // 0x80029624: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_8002965C;
    }
    // 0x80029624: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029628: lwc1        $f10, -0x1D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1D8);
    // 0x8002962C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80029630: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80029634: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x80029638: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002963C: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x80029640: lwc1        $f18, 0xC0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC0);
    // 0x80029644: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80029648: nop

    // 0x8002964C: bc1f        L_80029670
    if (!c1cs) {
        // 0x80029650: nop
    
            goto L_80029670;
    }
    // 0x80029650: nop

    // 0x80029654: jr          $ra
    // 0x80029658: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80029658: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
L_8002965C:
    // 0x8002965C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029660: nop

    // 0x80029664: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80029668: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8002966C: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
L_80029670:
    // 0x80029670: jr          $ra
    // 0x80029674: nop

    return;
    // 0x80029674: nop

;}
RECOMP_FUNC void func_80044AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044AEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80044AF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80044AF4: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80044AF8: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x80044AFC: lw          $v0, 0xB24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB24);
    // 0x80044B00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80044B04: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80044B08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80044B0C: beq         $v0, $zero, L_80044B1C
    if (ctx->r2 == 0) {
        // 0x80044B10: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80044B1C;
    }
    // 0x80044B10: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80044B14: jalr        $v0
    // 0x80044B18: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80044B18: nop

    after_0:
L_80044B1C:
    // 0x80044B1C: lw          $v0, 0xED4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XED4);
    // 0x80044B20: beql        $v0, $zero, L_80044B34
    if (ctx->r2 == 0) {
        // 0x80044B24: lh          $t6, 0x3A($s2)
        ctx->r14 = MEM_H(ctx->r18, 0X3A);
            goto L_80044B34;
    }
    goto skip_0;
    // 0x80044B24: lh          $t6, 0x3A($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X3A);
    skip_0:
    // 0x80044B28: jalr        $v0
    // 0x80044B2C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80044B2C: nop

    after_1:
    // 0x80044B30: lh          $t6, 0x3A($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X3A);
L_80044B34:
    // 0x80044B34: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80044B38: addiu       $s1, $s1, 0x42F0
    ctx->r17 = ADD32(ctx->r17, 0X42F0);
    // 0x80044B3C: beq         $t6, $zero, L_80044B5C
    if (ctx->r14 == 0) {
        // 0x80044B40: addiu       $s0, $s2, 0x34
        ctx->r16 = ADD32(ctx->r18, 0X34);
            goto L_80044B5C;
    }
    // 0x80044B40: addiu       $s0, $s2, 0x34
    ctx->r16 = ADD32(ctx->r18, 0X34);
    // 0x80044B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80044B48:
    // 0x80044B48: jal         0x80057EB0
    // 0x80044B4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80057EB0(rdram, ctx);
        goto after_2;
    // 0x80044B4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80044B50: lh          $t7, 0x3A($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X3A);
    // 0x80044B54: bnel        $t7, $zero, L_80044B48
    if (ctx->r15 != 0) {
        // 0x80044B58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80044B48;
    }
    goto skip_1;
    // 0x80044B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80044B5C:
    // 0x80044B5C: jal         0x8004445C
    // 0x80044B60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8004445C(rdram, ctx);
        goto after_3;
    // 0x80044B60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80044B64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80044B68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044B6C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80044B70: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80044B74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80044B78: jr          $ra
    // 0x80044B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80044B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800319E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800319E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800319E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800319EC: jal         0x800421B4
    // 0x800319F0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    func_800421B4(rdram, ctx);
        goto after_0;
    // 0x800319F0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x800319F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800319F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800319FC: jr          $ra
    // 0x80031A00: nop

    return;
    // 0x80031A00: nop

;}
RECOMP_FUNC void func_8040E7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E7A0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8040E7A4: addiu       $at, $zero, 0x4075
    ctx->r1 = ADD32(0, 0X4075);
    // 0x8040E7A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8040E7AC: bne         $t6, $at, L_8040E7C0
    if (ctx->r14 != ctx->r1) {
        // 0x8040E7B0: nop
    
            goto L_8040E7C0;
    }
    // 0x8040E7B0: nop

    // 0x8040E7B4: lui         $v0, 0x8041
    ctx->r2 = S32(RELOC_HI16(23, 0X858) << 16);
    // 0x8040E7B8: jr          $ra
    // 0x8040E7BC: addiu       $v0, $v0, -0x1008
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(23, 0X858));
    return;
    // 0x8040E7BC: addiu       $v0, $v0, -0x1008
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(23, 0X858));
L_8040E7C0:
    // 0x8040E7C0: jr          $ra
    // 0x8040E7C4: nop

    return;
    // 0x8040E7C4: nop

;}
RECOMP_FUNC void func_805A1400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A1404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A1408: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x805A140C: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(411, 0X1C60) << 16);
    // 0x805A1410: addiu       $t8, $t8, 0x2FD0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(411, 0X1C60));
    // 0x805A1414: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805A1418: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805A141C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805A1420: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x805A1424: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805A1428: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805A142C: beql        $v1, $zero, L_805A1460
    if (ctx->r3 == 0) {
        // 0x805A1430: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A1460;
    }
    goto skip_0;
    // 0x805A1430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A1434: jalr        $v1
    // 0x805A1438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805A1438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A143C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A1440: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x805A1444: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x805A1448: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x805A144C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x805A1450: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x805A1454: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x805A1458: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x805A145C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A1460:
    // 0x805A1460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A1464: jr          $ra
    // 0x805A1468: nop

    return;
    // 0x805A1468: nop

;}
RECOMP_FUNC void func_8003163C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003163C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031640: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80031644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80031648: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003164C: jal         0x800310A0
    // 0x80031650: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031650: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    after_0:
    // 0x80031654: jal         0x80030FA4
    // 0x80031658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80030FA4(rdram, ctx);
        goto after_1;
    // 0x80031658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003165C: beql        $v0, $zero, L_800316AC
    if (ctx->r2 == 0) {
        // 0x80031660: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800316AC;
    }
    goto skip_0;
    // 0x80031660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80031664: jal         0x80028220
    // 0x80031668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_2;
    // 0x80031668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003166C: jal         0x80065954
    // 0x80031670: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80031670: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_3:
    // 0x80031674: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80031678: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003167C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031680: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80031684: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80031688: jal         0x80041214
    // 0x8003168C: nop

    func_80041214(rdram, ctx);
        goto after_4;
    // 0x8003168C: nop

    after_4:
    // 0x80031690: lui         $a1, 0x3A83
    ctx->r5 = S32(0X3A83 << 16);
    // 0x80031694: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x80031698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003169C: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x800316A0: jal         0x80031170
    // 0x800316A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80031170(rdram, ctx);
        goto after_5;
    // 0x800316A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x800316A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800316AC:
    // 0x800316AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800316B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800316B4: jr          $ra
    // 0x800316B8: nop

    return;
    // 0x800316B8: nop

;}
RECOMP_FUNC void func_80067B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B3C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80067B40: lw          $v0, 0x6E94($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E94);
    // 0x80067B44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80067B48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80067B4C: sw          $v0, 0x6E94($at)
    MEM_W(0X6E94, ctx->r1) = ctx->r2;
    // 0x80067B50: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80067B54: bne         $at, $zero, L_80067B64
    if (ctx->r1 != 0) {
        // 0x80067B58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80067B64;
    }
    // 0x80067B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80067B5C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80067B60: sw          $v0, 0x6E94($at)
    MEM_W(0X6E94, ctx->r1) = ctx->r2;
L_80067B64:
    // 0x80067B64: jr          $ra
    // 0x80067B68: nop

    return;
    // 0x80067B68: nop

    // 0x80067B6C: jr          $ra
    // 0x80067B70: nop

    return;
    // 0x80067B70: nop

;}
RECOMP_FUNC void func_80667E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80667E08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80667E0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80667E10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80667E14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80667E18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80667E1C: jal         0x80047090
    // 0x80667E20: addiu       $a0, $zero, 0x4550
    ctx->r4 = ADD32(0, 0X4550);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80667E20: addiu       $a0, $zero, 0x4550
    ctx->r4 = ADD32(0, 0X4550);
    after_0:
    // 0x80667E24: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80667E28: beq         $v0, $at, L_80667E9C
    if (ctx->r2 == ctx->r1) {
        // 0x80667E2C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80667E9C;
    }
    // 0x80667E2C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80667E30: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80667E34: lui         $at, 0x4550
    ctx->r1 = S32(0X4550 << 16);
    // 0x80667E38: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x80667E3C: lui         $a0, 0x8066
    ctx->r4 = S32(RELOC_HI16(507, 0X280) << 16);
    // 0x80667E40: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80667E44: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80667E48: addiu       $a0, $a0, 0x7F50
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(507, 0X280));
    // 0x80667E4C: or          $a1, $v1, $at
    ctx->r5 = ctx->r3 | ctx->r1;
    // 0x80667E50: jal         0x80046804
    // 0x80667E54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x80667E54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80667E58: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80667E5C: beq         $v0, $zero, L_80667E9C
    if (ctx->r2 == 0) {
        // 0x80667E60: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80667E9C;
    }
    // 0x80667E60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80667E64: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80667E68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80667E6C: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x80667E70: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80667E74: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x80667E78: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80667E7C: jal         0x80052BA4
    // 0x80667E80: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
    func_80052BA4(rdram, ctx);
        goto after_2;
    // 0x80667E80: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
    after_2:
    // 0x80667E84: jal         0x8005FDC4
    // 0x80667E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x80667E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80667E8C: jal         0x80667D6C
    // 0x80667E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80667D6C(rdram, ctx);
        goto after_4;
    // 0x80667E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80667E94: b           L_80667EA0
    // 0x80667E98: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80667EA0;
    // 0x80667E98: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80667E9C:
    // 0x80667E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80667EA0:
    // 0x80667EA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80667EA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80667EA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80667EAC: jr          $ra
    // 0x80667EB0: nop

    return;
    // 0x80667EB0: nop

    // 0x80667EB4: nop

    // 0x80667EB8: nop

    // 0x80667EBC: nop

;}
RECOMP_FUNC void func_804F571C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F571C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804F5720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F5724: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F5728: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804F572C: jal         0x804F4F50
    // 0x804F5730: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_804F4F50(rdram, ctx);
        goto after_0;
    // 0x804F5730: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804F5734: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804F5738: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804F573C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F5740: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x804F5744: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804F5748: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x804F574C: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x804F5750: bne         $at, $zero, L_804F5760
    if (ctx->r1 != 0) {
        // 0x804F5754: sw          $v1, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r3;
            goto L_804F5760;
    }
    // 0x804F5754: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x804F5758: b           L_804F5778
    // 0x804F575C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
        goto L_804F5778;
    // 0x804F575C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_804F5760:
    // 0x804F5760: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x804F5764: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x804F5768: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x804F576C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804F5770: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804F5774: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_804F5778:
    // 0x804F5778: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804F577C: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804F5780: addiu       $at, $zero, 0x41EC
    ctx->r1 = ADD32(0, 0X41EC);
    // 0x804F5784: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804F5788: nop

    // 0x804F578C: bc1fl       L_804F57D4
    if (!c1cs) {
        // 0x804F5790: swc1        $f2, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
            goto L_804F57D4;
    }
    goto skip_0;
    // 0x804F5790: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    skip_0:
    // 0x804F5794: lhu         $t1, 0xC($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0XC);
    // 0x804F5798: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804F579C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x804F57A0: bne         $t1, $at, L_804F57B4
    if (ctx->r9 != ctx->r1) {
        // 0x804F57A4: swc1        $f4, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
            goto L_804F57B4;
    }
    // 0x804F57A4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x804F57A8: addiu       $t2, $zero, 0x12C
    ctx->r10 = ADD32(0, 0X12C);
    // 0x804F57AC: b           L_804F57B8
    // 0x804F57B0: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
        goto L_804F57B8;
    // 0x804F57B0: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
L_804F57B4:
    // 0x804F57B4: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
L_804F57B8:
    // 0x804F57B8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x804F57BC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x804F57C0: jal         0x804F5CE8
    // 0x804F57C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_804F5CE8(rdram, ctx);
        goto after_1;
    // 0x804F57C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x804F57C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804F57CC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804F57D0: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
L_804F57D4:
    // 0x804F57D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F57D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804F57DC: jr          $ra
    // 0x804F57E0: nop

    return;
    // 0x804F57E0: nop

;}
RECOMP_FUNC void func_80780098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780098: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078009C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x807800A0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807800A4: lui         $t7, 0x8078
    ctx->r15 = S32(RELOC_HI16(781, 0X7E0) << 16);
    // 0x807800A8: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x807800AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x807800B0: lw          $t7, 0xF0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(781, 0X7E0));
    // 0x807800B4: jr          $ra
    // 0x807800B8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x807800B8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8003F56C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F56C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F570: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F574: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003F578: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F57C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003F580: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003F584: jal         0x8003EBD4
    // 0x8003F588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EBD4(rdram, ctx);
        goto after_0;
    // 0x8003F588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003F58C: jal         0x8003E520
    // 0x8003F590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E520(rdram, ctx);
        goto after_1;
    // 0x8003F590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003F594: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8003F598: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003F59C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F5A0: jalr        $t9
    // 0x8003F5A4: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8003F5A4: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_2:
    // 0x8003F5A8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003F5AC: addiu       $t6, $t6, -0x19E8
    ctx->r14 = ADD32(ctx->r14, -0X19E8);
    // 0x8003F5B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F5B4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F5B8: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003F5BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003F5C0: jal         0x8003E6C4
    // 0x8003F5C4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_8003E6C4(rdram, ctx);
        goto after_3;
    // 0x8003F5C4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x8003F5C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F5CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F5D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003F5D4: jr          $ra
    // 0x8003F5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8003F5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80581880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581888: jal         0x80581854
    // 0x8058188C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80581854(rdram, ctx);
        goto after_0;
    // 0x8058188C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581890: bne         $v0, $zero, L_805818B4
    if (ctx->r2 != 0) {
        // 0x80581894: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805818B4;
    }
    // 0x80581894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581898: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8058189C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805818A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805818A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805818A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805818AC: jal         0x80581AA4
    // 0x805818B0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    func_80581AA4(rdram, ctx);
        goto after_1;
    // 0x805818B0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    after_1:
L_805818B4:
    // 0x805818B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805818B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805818BC: jr          $ra
    // 0x805818C0: nop

    return;
    // 0x805818C0: nop

;}
RECOMP_FUNC void func_8040D04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D04C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040D050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D054: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D058: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8040D05C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8040D060: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8040D064: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8040D068: sw          $t6, -0x72E0($at)
    MEM_W(-0X72E0, ctx->r1) = ctx->r14;
    // 0x8040D06C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8040D070: jal         0x80067BBC
    // 0x8040D074: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8040D074: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8040D078: jal         0x80067E68
    // 0x8040D07C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x8040D07C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x8040D080: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8040D084: jal         0x80067818
    // 0x8040D088: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8040D088: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8040D08C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040D090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040D094: jr          $ra
    // 0x8040D098: nop

    return;
    // 0x8040D098: nop

;}
RECOMP_FUNC void func_8052FA28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052FA28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8052FA2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052FA30: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8052FA34: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8052FA38: beq         $v0, $at, L_8052FA58
    if (ctx->r2 == ctx->r1) {
        // 0x8052FA3C: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_8052FA58;
    }
    // 0x8052FA3C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8052FA40: beq         $v0, $at, L_8052FA68
    if (ctx->r2 == ctx->r1) {
        // 0x8052FA44: addiu       $at, $zero, 0x400C
        ctx->r1 = ADD32(0, 0X400C);
            goto L_8052FA68;
    }
    // 0x8052FA44: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x8052FA48: beql        $v0, $at, L_8052FA90
    if (ctx->r2 == ctx->r1) {
        // 0x8052FA4C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8052FA90;
    }
    goto skip_0;
    // 0x8052FA4C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_0:
    // 0x8052FA50: b           L_8052FAA0
    // 0x8052FA54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052FAA0;
    // 0x8052FA54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052FA58:
    // 0x8052FA58: jal         0x8052F650
    // 0x8052FA5C: nop

    func_8052F650(rdram, ctx);
        goto after_0;
    // 0x8052FA5C: nop

    after_0:
    // 0x8052FA60: b           L_8052FAA0
    // 0x8052FA64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052FAA0;
    // 0x8052FA64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052FA68:
    // 0x8052FA68: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x8052FA6C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8052FA70: bne         $t6, $at, L_8052FA9C
    if (ctx->r14 != ctx->r1) {
        // 0x8052FA74: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8052FA9C;
    }
    // 0x8052FA74: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8052FA78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052FA7C: jal         0x8052E698
    // 0x8052FA80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8052E698(rdram, ctx);
        goto after_1;
    // 0x8052FA80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8052FA84: b           L_8052FAA0
    // 0x8052FA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052FAA0;
    // 0x8052FA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8052FA8C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_8052FA90:
    // 0x8052FA90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052FA94: jal         0x8052E9E8
    // 0x8052FA98: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8052E9E8(rdram, ctx);
        goto after_2;
    // 0x8052FA98: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
L_8052FA9C:
    // 0x8052FA9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052FAA0:
    // 0x8052FAA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8052FAA4: jr          $ra
    // 0x8052FAA8: nop

    return;
    // 0x8052FAA8: nop

;}
RECOMP_FUNC void func_805D3188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D318C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D3190: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805D3194: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D3198: jal         0x8004700C
    // 0x805D319C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D319C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805D31A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805D31A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805D31A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x805D31AC: lhu         $t7, 0x4($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X4);
    // 0x805D31B0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x805D31B4: bne         $t7, $zero, L_805D31C4
    if (ctx->r15 != 0) {
        // 0x805D31B8: nop
    
            goto L_805D31C4;
    }
    // 0x805D31B8: nop

    // 0x805D31BC: b           L_805D31C4
    // 0x805D31C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D31C4;
    // 0x805D31C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D31C4:
    // 0x805D31C4: beq         $v0, $zero, L_805D32B8
    if (ctx->r2 == 0) {
        // 0x805D31C8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_805D32B8;
    }
    // 0x805D31C8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x805D31CC: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x805D31D0: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x805D31D4: lwc1        $f6, 0x84($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X84);
    // 0x805D31D8: lwc1        $f4, 0x84($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X84);
    // 0x805D31DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805D31E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D31E4: jal         0x80065954
    // 0x805D31E8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x805D31E8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x805D31EC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x805D31F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D31F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D31F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805D31FC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805D3200: nop

    // 0x805D3204: bc1fl       L_805D32BC
    if (!c1cs) {
        // 0x805D3208: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D32BC;
    }
    goto skip_0;
    // 0x805D3208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805D320C: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x805D3210: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x805D3214: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x805D3218: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x805D321C: addu        $a3, $t1, $v0
    ctx->r7 = ADD32(ctx->r9, ctx->r2);
    // 0x805D3220: lwc1        $f16, 0x84($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X84);
    // 0x805D3224: lwc1        $f10, 0x84($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X84);
    // 0x805D3228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805D322C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805D3230: nop

    // 0x805D3234: bc1f        L_805D3244
    if (!c1cs) {
        // 0x805D3238: nop
    
            goto L_805D3244;
    }
    // 0x805D3238: nop

    // 0x805D323C: b           L_805D3244
    // 0x805D3240: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_805D3244;
    // 0x805D3240: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_805D3244:
    // 0x805D3244: lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X2);
    // 0x805D3248: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x805D324C: beq         $t3, $zero, L_805D3258
    if (ctx->r11 == 0) {
        // 0x805D3250: andi        $t5, $v1, 0xFFFD
        ctx->r13 = ctx->r3 & 0XFFFD;
            goto L_805D3258;
    }
    // 0x805D3250: andi        $t5, $v1, 0xFFFD
    ctx->r13 = ctx->r3 & 0XFFFD;
    // 0x805D3254: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_805D3258:
    // 0x805D3258: bgez        $v0, L_805D32A0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805D325C: ori         $t4, $v1, 0x2
        ctx->r12 = ctx->r3 | 0X2;
            goto L_805D32A0;
    }
    // 0x805D325C: ori         $t4, $v1, 0x2
    ctx->r12 = ctx->r3 | 0X2;
    // 0x805D3260: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x805D3264: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
    // 0x805D3268: lwc1        $f18, 0x84($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X84);
    // 0x805D326C: jal         0x80065954
    // 0x805D3270: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x805D3270: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_2:
    // 0x805D3274: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x805D3278: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805D327C: nop

    // 0x805D3280: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x805D3284: nop

    // 0x805D3288: bc1fl       L_805D32A8
    if (!c1cs) {
        // 0x805D328C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805D32A8;
    }
    goto skip_1;
    // 0x805D328C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x805D3290: jal         0x805D2F88
    // 0x805D3294: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805D2F88(rdram, ctx);
        goto after_3;
    // 0x805D3294: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x805D3298: b           L_805D32A8
    // 0x805D329C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_805D32A8;
    // 0x805D329C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_805D32A0:
    // 0x805D32A0: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x805D32A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_805D32A8:
    // 0x805D32A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D32AC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x805D32B0: jal         0x805D3B18
    // 0x805D32B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_4;
    // 0x805D32B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
L_805D32B8:
    // 0x805D32B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D32BC:
    // 0x805D32BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D32C0: jr          $ra
    // 0x805D32C4: nop

    return;
    // 0x805D32C4: nop

;}
RECOMP_FUNC void func_805CFFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CFFD0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805CFFD4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x805CFFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CFFDC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805CFFE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CFFE4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x805CFFE8: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(462, 0X2E0) << 16);
    // 0x805CFFEC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805CFFF0: addiu       $t7, $t7, 0x250
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(462, 0X2E0));
    // 0x805CFFF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805CFFF8: jal         0x80048490
    // 0x805CFFFC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805CFFFC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x805D0000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D0004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D0008: jr          $ra
    // 0x805D000C: nop

    return;
    // 0x805D000C: nop

;}
RECOMP_FUNC void func_8005AC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AC14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005AC18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005AC1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005AC20: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x8005AC24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005AC28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005AC2C: beq         $t6, $at, L_8005AC6C
    if (ctx->r14 == ctx->r1) {
        // 0x8005AC30: nop
    
            goto L_8005AC6C;
    }
    // 0x8005AC30: nop

    // 0x8005AC34: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x8005AC38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005AC3C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8005AC40: jal         0x800506B4
    // 0x8005AC44: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800506B4(rdram, ctx);
        goto after_0;
    // 0x8005AC44: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x8005AC48: beq         $v0, $zero, L_8005AC60
    if (ctx->r2 == 0) {
        // 0x8005AC4C: nop
    
            goto L_8005AC60;
    }
    // 0x8005AC4C: nop

    // 0x8005AC50: jal         0x80050928
    // 0x8005AC54: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80050928(rdram, ctx);
        goto after_1;
    // 0x8005AC54: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8005AC58: b           L_8005AC6C
    // 0x8005AC5C: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
        goto L_8005AC6C;
    // 0x8005AC5C: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
L_8005AC60:
    // 0x8005AC60: jal         0x80064E84
    // 0x8005AC64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x8005AC64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8005AC68: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
L_8005AC6C:
    // 0x8005AC6C: jal         0x8005AB10
    // 0x8005AC70: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8005AB10(rdram, ctx);
        goto after_3;
    // 0x8005AC70: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x8005AC74: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8005AC78: jal         0x8006A64C
    // 0x8005AC7C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_8006A64C(rdram, ctx);
        goto after_4;
    // 0x8005AC7C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x8005AC80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005AC84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005AC88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005AC8C: jr          $ra
    // 0x8005AC90: nop

    return;
    // 0x8005AC90: nop

;}
RECOMP_FUNC void func_80471C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471C10: beq         $a0, $zero, L_80471C24
    if (ctx->r4 == 0) {
        // 0x80471C14: lui         $at, 0xC180
        ctx->r1 = S32(0XC180 << 16);
            goto L_80471C24;
    }
    // 0x80471C14: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80471C18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80471C1C: nop

    // 0x80471C20: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
L_80471C24:
    // 0x80471C24: jr          $ra
    // 0x80471C28: nop

    return;
    // 0x80471C28: nop

;}
RECOMP_FUNC void func_80584A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584A5C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584A60: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584A64: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584A68: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584A6C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584A70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584A74: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584A78: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584A7C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584A80: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584A84: jr          $ra
    // 0x80584A88: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584A88: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806E840C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E840C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806E8410: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x806E8414: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x806E8418: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x806E841C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806E8420: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x806E8424: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x806E8428: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x806E842C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806E8430: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x806E8434: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x806E8438: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x806E843C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806E8440: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806E8444: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x806E8448: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806E844C: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x806E8450: addiu       $t3, $zero, 0x2C80
    ctx->r11 = ADD32(0, 0X2C80);
    // 0x806E8454: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x806E8458: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x806E845C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x806E8460: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x806E8464: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806E8468: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x806E846C: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x806E8470: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x806E8474: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x806E8478: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x806E847C: ori         $a3, $a3, 0x41C8
    ctx->r7 = ctx->r7 | 0X41C8;
    // 0x806E8480: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x806E8484: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x806E8488: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806E848C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x806E8490: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x806E8494: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x806E8498: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806E849C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x806E84A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x806E84A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806E84A8: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x806E84AC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x806E84B0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x806E84B4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806E84B8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x806E84BC: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x806E84C0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x806E84C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x806E84C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806E84CC: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x806E84D0: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x806E84D4: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x806E84D8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x806E84DC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x806E84E0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x806E84E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806E84E8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x806E84EC: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x806E84F0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x806E84F4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x806E84F8: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x806E84FC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x806E8500: jr          $ra
    // 0x806E8504: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x806E8504: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80793144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80793144: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80793148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079314C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80793150: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80793154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80793158: jal         0x80790714
    // 0x8079315C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80790714(rdram, ctx);
        goto after_0;
    // 0x8079315C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x80793160: beq         $v0, $zero, L_80793268
    if (ctx->r2 == 0) {
        // 0x80793164: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80793268;
    }
    // 0x80793164: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80793168: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8079316C: lw          $t6, -0x7290($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7290);
    // 0x80793170: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x80793174: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    // 0x80793178: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8079317C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80793180: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80793184: jalr        $t9
    // 0x80793188: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80793188: nop

    after_1:
    // 0x8079318C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80793190: lw          $t7, -0x7290($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7290);
    // 0x80793194: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80793198: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8079319C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x807931A0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x807931A4: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x807931A8: jalr        $t9
    // 0x807931AC: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x807931AC: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    after_2:
    // 0x807931B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x807931B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807931B8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x807931BC: lw          $t8, -0x7290($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7290);
    // 0x807931C0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x807931C4: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x807931C8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x807931CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807931D0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x807931D4: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x807931D8: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x807931DC: lw          $t1, 0x68($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X68);
    // 0x807931E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807931E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x807931E8: bne         $t1, $zero, L_80793210
    if (ctx->r9 != 0) {
        // 0x807931EC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80793210;
    }
    // 0x807931EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x807931F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807931F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807931F8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x807931FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80793200: jal         0x8079393C
    // 0x80793204: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8079393C(rdram, ctx);
        goto after_3;
    // 0x80793204: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x80793208: b           L_8079321C
    // 0x8079320C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_8079321C;
    // 0x8079320C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80793210:
    // 0x80793210: jal         0x8079393C
    // 0x80793214: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8079393C(rdram, ctx);
        goto after_4;
    // 0x80793214: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_4:
    // 0x80793218: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8079321C:
    // 0x8079321C: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80793220: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80793224: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7B0C) << 16);
    // 0x80793228: lwc1        $f0, 0x7E5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7B0C));
    // 0x8079322C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80793230: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80793234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80793238: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8079323C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80793240: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80793244: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80793248: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x8079324C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80793250: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80793254: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80793258: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8079325C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80793260: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80793264: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_80793268:
    // 0x80793268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079326C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80793270: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80793274: jr          $ra
    // 0x80793278: nop

    return;
    // 0x80793278: nop

;}
RECOMP_FUNC void func_80047AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047AB8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80047ABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80047AC0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80047AC4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80047AC8: lw          $a2, 0x180($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X180);
    // 0x80047ACC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80047AD0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80047AD4: beq         $a2, $zero, L_80047AEC
    if (ctx->r6 == 0) {
        // 0x80047AD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80047AEC;
    }
    // 0x80047AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80047ADC: lbu         $v0, 0x17C($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X17C);
    // 0x80047AE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80047AE4: bne         $v0, $at, L_80047AFC
    if (ctx->r2 != ctx->r1) {
        // 0x80047AE8: nop
    
            goto L_80047AFC;
    }
    // 0x80047AE8: nop

L_80047AEC:
    // 0x80047AEC: jal         0x80065490
    // 0x80047AF0: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x80047AF0: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    after_0:
    // 0x80047AF4: b           L_80047C28
    // 0x80047AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80047C28;
    // 0x80047AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80047AFC:
    // 0x80047AFC: bne         $v0, $zero, L_80047B44
    if (ctx->r2 != 0) {
        // 0x80047B00: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80047B44;
    }
    // 0x80047B00: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80047B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80047B08: jal         0x80047AB8
    // 0x80047B0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80047B0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x80047B10: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80047B14: lwc1        $f6, 0x3C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80047B18: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80047B1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80047B20: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80047B24: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x80047B28: lwc1        $f16, 0x40($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80047B2C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80047B30: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80047B34: lwc1        $f6, 0x44($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80047B38: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80047B3C: b           L_80047C24
    // 0x80047B40: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_80047C24;
    // 0x80047B40: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80047B44:
    // 0x80047B44: beq         $v1, $v0, L_80047B54
    if (ctx->r3 == ctx->r2) {
        // 0x80047B48: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80047B54;
    }
    // 0x80047B48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80047B4C: bne         $v0, $at, L_80047C1C
    if (ctx->r2 != ctx->r1) {
        // 0x80047B50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80047C1C;
    }
    // 0x80047B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80047B54:
    // 0x80047B54: lwc1        $f10, 0x98($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X98);
    // 0x80047B58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047B5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80047B60: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80047B64: bne         $v1, $v0, L_80047B88
    if (ctx->r3 != ctx->r2) {
        // 0x80047B68: swc1        $f10, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
            goto L_80047B88;
    }
    // 0x80047B68: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80047B6C: jal         0x80049018
    // 0x80047B70: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x80047B70: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80047B74: beq         $v0, $zero, L_80047B88
    if (ctx->r2 == 0) {
        // 0x80047B78: lwc1        $f0, 0x24($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80047B88;
    }
    // 0x80047B78: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80047B7C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80047B80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80047B84: nop

L_80047B88:
    // 0x80047B88: lw          $a1, 0x180($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X180);
    // 0x80047B8C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80047B90: jal         0x80047648
    // 0x80047B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80047648(rdram, ctx);
        goto after_3;
    // 0x80047B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80047B98: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80047B9C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80047BA0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80047BA4: mul.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80047BA8: jal         0x80066E88
    // 0x80047BAC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x80047BAC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80047BB0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80047BB4: jal         0x80066DE4
    // 0x80047BB8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x80047BB8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80047BBC: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80047BC0: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80047BC4: lwc1        $f8, 0x40($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80047BC8: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80047BCC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80047BD0: nop

    // 0x80047BD4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80047BD8: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80047BDC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80047BE0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80047BE4: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80047BE8: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80047BEC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80047BF0: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80047BF4: nop

    // 0x80047BF8: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80047BFC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80047C00: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80047C04: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80047C08: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80047C0C: lwc1        $f6, 0x44($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80047C10: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80047C14: b           L_80047C24
    // 0x80047C18: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_80047C24;
    // 0x80047C18: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_80047C1C:
    // 0x80047C1C: jal         0x80065490
    // 0x80047C20: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    func_80065490(rdram, ctx);
        goto after_6;
    // 0x80047C20: addiu       $a1, $s1, 0x3C
    ctx->r5 = ADD32(ctx->r17, 0X3C);
    after_6:
L_80047C24:
    // 0x80047C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80047C28:
    // 0x80047C28: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80047C2C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80047C30: jr          $ra
    // 0x80047C34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80047C34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80079124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079124: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80079128: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007912C: jr          $ra
    // 0x80079130: nop

    return;
    // 0x80079130: nop

;}
RECOMP_FUNC void func_80584D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584D5C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584D60: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584D64: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584D68: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584D6C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584D70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584D74: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584D78: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584D7C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584D80: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584D84: jr          $ra
    // 0x80584D88: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584D88: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80444570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80444574: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80444578: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8044457C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80444580: sb          $zero, 0xF5C($v0)
    MEM_B(0XF5C, ctx->r2) = 0;
    // 0x80444584: jal         0x8044453C
    // 0x80444588: sb          $zero, 0xF5D($v0)
    MEM_B(0XF5D, ctx->r2) = 0;
    func_8044453C(rdram, ctx);
        goto after_0;
    // 0x80444588: sb          $zero, 0xF5D($v0)
    MEM_B(0XF5D, ctx->r2) = 0;
    after_0:
    // 0x8044458C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80444590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80444594: jr          $ra
    // 0x80444598: nop

    return;
    // 0x80444598: nop

;}
RECOMP_FUNC void func_8058106C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058106C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80581070: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80581074: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80581078: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8058107C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80581080: andi        $s4, $a1, 0xFF
    ctx->r20 = ctx->r5 & 0XFF;
    // 0x80581084: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80581088: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8058108C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80581090: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80581094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80581098: jal         0x80581040
    // 0x8058109C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80581040(rdram, ctx);
        goto after_0;
    // 0x8058109C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805810A0: lui         $s1, 0x8058
    ctx->r17 = S32(RELOC_HI16(399, 0X4638) << 16);
    // 0x805810A4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x805810A8: addiu       $s1, $s1, 0x3448
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(399, 0X4638));
    // 0x805810AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x805810B0: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x805810B4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_805810B8:
    // 0x805810B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x805810BC: jal         0x8057EF14
    // 0x805810C0: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    func_8057EF14(rdram, ctx);
        goto after_1;
    // 0x805810C0: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    after_1:
    // 0x805810C4: beql        $v0, $zero, L_805810EC
    if (ctx->r2 == 0) {
        // 0x805810C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_805810EC;
    }
    goto skip_0;
    // 0x805810C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x805810CC: beql        $s0, $s3, L_805810E0
    if (ctx->r16 == ctx->r19) {
        // 0x805810D0: sb          $zero, 0x165($v0)
        MEM_B(0X165, ctx->r2) = 0;
            goto L_805810E0;
    }
    goto skip_1;
    // 0x805810D0: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    skip_1:
    // 0x805810D4: b           L_805810E0
    // 0x805810D8: sb          $s5, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r21;
        goto L_805810E0;
    // 0x805810D8: sb          $s5, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r21;
    // 0x805810DC: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
L_805810E0:
    // 0x805810E0: lw          $t6, 0x16C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X16C);
    // 0x805810E4: sb          $s4, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r20;
    // 0x805810E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_805810EC:
    // 0x805810EC: bne         $s0, $s6, L_805810B8
    if (ctx->r16 != ctx->r22) {
        // 0x805810F0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_805810B8;
    }
    // 0x805810F0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x805810F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x805810F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805810FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80581100: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80581104: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80581108: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8058110C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80581110: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80581114: jr          $ra
    // 0x80581118: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80581118: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8052C5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C5D0: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(330, 0X10) << 16);
    // 0x8052C5D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8052C5D8: jr          $ra
    // 0x8052C5DC: addiu       $v0, $v0, -0x3A20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(330, 0X10));
    return;
    // 0x8052C5DC: addiu       $v0, $v0, -0x3A20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(330, 0X10));
;}
RECOMP_FUNC void func_80475810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475810: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475814: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475818: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047581C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475820: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475824: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475828: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047582C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475830: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475834: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475838: jr          $ra
    // 0x8047583C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047583C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80078E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078E40: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x80078E44: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x80078E48: addiu       $t8, $zero, 0xFA
    ctx->r24 = ADD32(0, 0XFA);
    // 0x80078E4C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80078E50: sb          $t9, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r25;
    // 0x80078E54: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    // 0x80078E58: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x80078E5C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80078E60: jr          $ra
    // 0x80078E64: nop

    return;
    // 0x80078E64: nop

;}
RECOMP_FUNC void func_807B3C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3C2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807B3C30: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807B3C34: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x807B3C38: lui         $at, 0x460D
    ctx->r1 = S32(0X460D << 16);
    // 0x807B3C3C: lui         $a2, 0x807B
    ctx->r6 = S32(RELOC_HI16(877, 0X258) << 16);
    // 0x807B3C40: addiu       $a1, $t6, 0x200
    ctx->r5 = ADD32(ctx->r14, 0X200);
    // 0x807B3C44: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x807B3C48: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x807B3C4C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(877, 0X278) << 16);
    // 0x807B3C50: sll         $v1, $t6, 2
    ctx->r3 = S32(ctx->r14 << 2);
    // 0x807B3C54: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x807B3C58: lwc1        $f4, 0x3D08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(877, 0X278));
    // 0x807B3C5C: lui         $a3, 0x807B
    ctx->r7 = S32(RELOC_HI16(877, 0X268) << 16);
    // 0x807B3C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B3C64: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x807B3C68: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x807B3C6C: lui         $a0, 0x807B
    ctx->r4 = S32(RELOC_HI16(877, 0X360) << 16);
    // 0x807B3C70: addiu       $a0, $a0, 0x3DF0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(877, 0X360));
    // 0x807B3C74: lw          $a2, 0x3CE8($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(877, 0X258));
    // 0x807B3C78: lw          $a3, 0x3CF8($a3)
    ctx->r7 = MEM_W(ctx->r7, (int16_t)RELOC_LO16(877, 0X268));
    // 0x807B3C7C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x807B3C80: jal         0x80046804
    // 0x807B3C84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x807B3C84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x807B3C88: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807B3C8C: bne         $v0, $zero, L_807B3C9C
    if (ctx->r2 != 0) {
        // 0x807B3C90: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807B3C9C;
    }
    // 0x807B3C90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807B3C94: b           L_807B3CCC
    // 0x807B3C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B3CCC;
    // 0x807B3C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B3C9C:
    // 0x807B3C9C: lui         $t7, 0x807B
    ctx->r15 = S32(RELOC_HI16(877, 0X288) << 16);
    // 0x807B3CA0: addiu       $t7, $t7, 0x3D18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(877, 0X288));
    // 0x807B3CA4: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x807B3CA8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807B3CAC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(877, 0X298) << 16);
    // 0x807B3CB0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x807B3CB4: swc1        $f6, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f6.u32l;
    // 0x807B3CB8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807B3CBC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x807B3CC0: swc1        $f8, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->f8.u32l;
    // 0x807B3CC4: lwc1        $f10, 0x3D28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(877, 0X298));
    // 0x807B3CC8: swc1        $f10, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f10.u32l;
L_807B3CCC:
    // 0x807B3CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B3CD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807B3CD4: jr          $ra
    // 0x807B3CD8: nop

    return;
    // 0x807B3CD8: nop

    // 0x807B3CDC: nop

;}
RECOMP_FUNC void func_8005D160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D160: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D164: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005D168: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005D16C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005D170: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D174: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D178: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x8005D17C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005D180: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
    // 0x8005D184: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8005D188:
    // 0x8005D188: lw          $t6, 0x78($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X78);
    // 0x8005D18C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8005D190: beql        $s0, $t6, L_8005D1A4
    if (ctx->r16 == ctx->r14) {
        // 0x8005D194: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_8005D1A4;
    }
    goto skip_0;
    // 0x8005D194: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    skip_0:
    // 0x8005D198: jal         0x80043F00
    // 0x8005D19C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80043F00(rdram, ctx);
        goto after_0;
    // 0x8005D19C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005D1A0: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_8005D1A4:
    // 0x8005D1A4: bne         $s1, $s3, L_8005D188
    if (ctx->r17 != ctx->r19) {
        // 0x8005D1A8: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_8005D188;
    }
    // 0x8005D1A8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8005D1AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005D1B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005D1B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005D1B8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D1BC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005D1C0: jr          $ra
    // 0x8005D1C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005D1C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001F880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F880: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001F884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F888: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8001F88C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001F890: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001F894: jal         0x8001F27C
    // 0x8001F898: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8001F27C(rdram, ctx);
        goto after_0;
    // 0x8001F898: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8001F89C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001F8A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001F8A4: swc1        $f0, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f0.u32l;
    // 0x8001F8A8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F8AC: lhu         $t9, 0xE($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XE);
    // 0x8001F8B0: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x8001F8B4: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x8001F8B8: beq         $t1, $at, L_8001F8CC
    if (ctx->r9 == ctx->r1) {
        // 0x8001F8BC: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8001F8CC;
    }
    // 0x8001F8BC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001F8C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001F8C4: nop

    // 0x8001F8C8: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
L_8001F8CC:
    // 0x8001F8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F8D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001F8D4: jr          $ra
    // 0x8001F8D8: nop

    return;
    // 0x8001F8D8: nop

;}
RECOMP_FUNC void func_806ED3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED3C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ED3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ED3C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806ED3CC: jal         0x80047090
    // 0x806ED3D0: addiu       $a0, $zero, 0x45E4
    ctx->r4 = ADD32(0, 0X45E4);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806ED3D0: addiu       $a0, $zero, 0x45E4
    ctx->r4 = ADD32(0, 0X45E4);
    after_0:
    // 0x806ED3D4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806ED3D8: bne         $v0, $at, L_806ED3E8
    if (ctx->r2 != ctx->r1) {
        // 0x806ED3DC: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806ED3E8;
    }
    // 0x806ED3DC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806ED3E0: b           L_806ED44C
    // 0x806ED3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806ED44C;
    // 0x806ED3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806ED3E8:
    // 0x806ED3E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806ED3EC: lui         $at, 0x45E4
    ctx->r1 = S32(0X45E4 << 16);
    // 0x806ED3F0: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x806ED3F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806ED3F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806ED3FC: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x806ED400: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x806ED404: jal         0x8004613C
    // 0x806ED408: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806ED408: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x806ED40C: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x806ED410: bne         $v0, $zero, L_806ED420
    if (ctx->r2 != 0) {
        // 0x806ED414: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806ED420;
    }
    // 0x806ED414: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806ED418: b           L_806ED44C
    // 0x806ED41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806ED44C;
    // 0x806ED41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806ED420:
    // 0x806ED420: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x806ED424: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x806ED428: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806ED42C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x806ED430: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x806ED434: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806ED438: jal         0x80047F9C
    // 0x806ED43C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806ED43C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806ED440: jal         0x8005FDC4
    // 0x806ED444: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x806ED444: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x806ED448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806ED44C:
    // 0x806ED44C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ED450: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806ED454: jr          $ra
    // 0x806ED458: nop

    return;
    // 0x806ED458: nop

;}
RECOMP_FUNC void func_800430E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800430E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800430E8: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800430EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800430F0: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800430F4: lw          $a3, 0x1314($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1314);
    // 0x800430F8: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800430FC: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80043100: bnel        $at, $zero, L_80043120
    if (ctx->r1 != 0) {
        // 0x80043104: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80043120;
    }
    goto skip_0;
    // 0x80043104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80043108: lw          $t9, -0x72F4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72F4);
    // 0x8004310C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80043110: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80043114: jalr        $t9
    // 0x80043118: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80043118: nop

    after_0:
    // 0x8004311C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80043120:
    // 0x80043120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80043124: jr          $ra
    // 0x80043128: nop

    return;
    // 0x80043128: nop

;}
RECOMP_FUNC void func_8079F1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079F1C0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8079F1C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8079F1C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8079F1CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8079F1D0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8079F1D4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8079F1D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8079F1DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8079F1E0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8079F1E4: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(835, 0X1934) << 16);
    // 0x8079F1E8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8079F1EC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8079F1F0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8079F1F4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8079F1F8: lw          $t1, -0xBDC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(835, 0X1934));
    // 0x8079F1FC: jr          $ra
    // 0x8079F200: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8079F200: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8079F204: nop

    // 0x8079F208: nop

    // 0x8079F20C: nop

;}
RECOMP_FUNC void func_8000C170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C170: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000C174: beq         $v0, $zero, L_8000C194
    if (ctx->r2 == 0) {
        // 0x8000C178: nop
    
            goto L_8000C194;
    }
    // 0x8000C178: nop

    // 0x8000C17C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8000C180: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000C184: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000C188: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8000C18C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000C190: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8000C194:
    // 0x8000C194: jr          $ra
    // 0x8000C198: nop

    return;
    // 0x8000C198: nop

;}
RECOMP_FUNC void func_80036F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036F40: jal         0x80021958
    // 0x80036F44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80036F44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80036F48: bne         $v0, $zero, L_80036F58
    if (ctx->r2 != 0) {
        // 0x80036F4C: nop
    
            goto L_80036F58;
    }
    // 0x80036F4C: nop

    // 0x80036F50: b           L_80036F94
    // 0x80036F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036F94;
    // 0x80036F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036F58:
    // 0x80036F58: jal         0x80041714
    // 0x80036F5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041714(rdram, ctx);
        goto after_1;
    // 0x80036F5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80036F60: beq         $v0, $zero, L_80036F70
    if (ctx->r2 == 0) {
        // 0x80036F64: nop
    
            goto L_80036F70;
    }
    // 0x80036F64: nop

    // 0x80036F68: b           L_80036F94
    // 0x80036F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036F94;
    // 0x80036F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036F70:
    // 0x80036F70: jal         0x80036BB0
    // 0x80036F74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036BB0(rdram, ctx);
        goto after_2;
    // 0x80036F74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80036F78: bne         $v0, $zero, L_80036F88
    if (ctx->r2 != 0) {
        // 0x80036F7C: nop
    
            goto L_80036F88;
    }
    // 0x80036F7C: nop

    // 0x80036F80: b           L_80036F94
    // 0x80036F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036F94;
    // 0x80036F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036F88:
    // 0x80036F88: jal         0x80036EDC
    // 0x80036F8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036EDC(rdram, ctx);
        goto after_3;
    // 0x80036F8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80036F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036F94:
    // 0x80036F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036F9C: jr          $ra
    // 0x80036FA0: nop

    return;
    // 0x80036FA0: nop

;}
RECOMP_FUNC void func_80788238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80788238: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078823C: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80788240: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x80788244: lh          $t6, 0x52C6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X52C6);
    // 0x80788248: bne         $t6, $zero, L_807882C4
    if (ctx->r14 != 0) {
        // 0x8078824C: nop
    
            goto L_807882C4;
    }
    // 0x8078824C: nop

    // 0x80788250: lw          $v0, 0xED0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XED0);
    // 0x80788254: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80788258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8078825C: lbu         $t7, 0x40($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X40);
    // 0x80788260: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80788264: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80788268: beq         $t7, $zero, L_807882C4
    if (ctx->r15 == 0) {
        // 0x8078826C: nop
    
            goto L_807882C4;
    }
    // 0x8078826C: nop

    // 0x80788270: sb          $t8, 0x42($v0)
    MEM_B(0X42, ctx->r2) = ctx->r24;
    // 0x80788274: lw          $t9, 0xED0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XED0);
L_80788278:
    // 0x80788278: addu        $t1, $t9, $a0
    ctx->r9 = ADD32(ctx->r25, ctx->r4);
    // 0x8078827C: lw          $v1, 0x38($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X38);
    // 0x80788280: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80788284: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x80788288: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
    // 0x8078828C: lbu         $a1, 0x10($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X10);
    // 0x80788290: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x80788294: slti        $at, $a1, 0xFC
    ctx->r1 = SIGNED(ctx->r5) < 0XFC ? 1 : 0;
    // 0x80788298: beq         $at, $zero, L_807882A8
    if (ctx->r1 == 0) {
        // 0x8078829C: addiu       $t2, $a1, 0x4
        ctx->r10 = ADD32(ctx->r5, 0X4);
            goto L_807882A8;
    }
    // 0x8078829C: addiu       $t2, $a1, 0x4
    ctx->r10 = ADD32(ctx->r5, 0X4);
    // 0x807882A0: b           L_807882BC
    // 0x807882A4: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
        goto L_807882BC;
    // 0x807882A4: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
L_807882A8:
    // 0x807882A8: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
    // 0x807882AC: lw          $t3, 0xED0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XED0);
    // 0x807882B0: sb          $zero, 0x42($t3)
    MEM_B(0X42, ctx->r11) = 0;
    // 0x807882B4: lw          $t4, 0xED0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XED0);
    // 0x807882B8: sb          $zero, 0x40($t4)
    MEM_B(0X40, ctx->r12) = 0;
L_807882BC:
    // 0x807882BC: bnel        $a0, $a3, L_80788278
    if (ctx->r4 != ctx->r7) {
        // 0x807882C0: lw          $t9, 0xED0($a2)
        ctx->r25 = MEM_W(ctx->r6, 0XED0);
            goto L_80788278;
    }
    goto skip_0;
    // 0x807882C0: lw          $t9, 0xED0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XED0);
    skip_0:
L_807882C4:
    // 0x807882C4: jr          $ra
    // 0x807882C8: nop

    return;
    // 0x807882C8: nop

;}
RECOMP_FUNC void func_8001B66C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B66C: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8001B670: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8001B674: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001B678: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001B67C: addiu       $a2, $a2, 0x660
    ctx->r6 = ADD32(ctx->r6, 0X660);
    // 0x8001B680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B684: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8001B688: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8001B68C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8001B690: addiu       $a3, $zero, 0x48
    ctx->r7 = ADD32(0, 0X48);
L_8001B694:
    // 0x8001B694: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B698: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B69C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001B6A0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001B6A4: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8001B6A8: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B6AC: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x8001B6B0: lw          $a0, 0x40($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X40);
    // 0x8001B6B4: beql        $a0, $t0, L_8001B6D0
    if (ctx->r4 == ctx->r8) {
        // 0x8001B6B8: lh          $t7, 0x0($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X0);
            goto L_8001B6D0;
    }
    goto skip_0;
    // 0x8001B6B8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    skip_0:
    // 0x8001B6BC: beql        $a0, $t1, L_8001B6D0
    if (ctx->r4 == ctx->r9) {
        // 0x8001B6C0: lh          $t7, 0x0($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X0);
            goto L_8001B6D0;
    }
    goto skip_1;
    // 0x8001B6C0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    skip_1:
    // 0x8001B6C4: bne         $a0, $t2, L_8001B6E0
    if (ctx->r4 != ctx->r10) {
        // 0x8001B6C8: nop
    
            goto L_8001B6E0;
    }
    // 0x8001B6C8: nop

    // 0x8001B6CC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_8001B6D0:
    // 0x8001B6D0: bne         $a1, $t7, L_8001B6E0
    if (ctx->r5 != ctx->r15) {
        // 0x8001B6D4: nop
    
            goto L_8001B6E0;
    }
    // 0x8001B6D4: nop

    // 0x8001B6D8: jr          $ra
    // 0x8001B6DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001B6DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001B6E0:
    // 0x8001B6E0: bne         $at, $zero, L_8001B694
    if (ctx->r1 != 0) {
        // 0x8001B6E4: nop
    
            goto L_8001B694;
    }
    // 0x8001B6E4: nop

    // 0x8001B6E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B6EC: jr          $ra
    // 0x8001B6F0: nop

    return;
    // 0x8001B6F0: nop

;}
RECOMP_FUNC void func_8005D8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D8C0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005D8C4: lw          $a0, 0x6340($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6340);
    // 0x8005D8C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D8D0: slti        $at, $a0, 0x98
    ctx->r1 = SIGNED(ctx->r4) < 0X98 ? 1 : 0;
    // 0x8005D8D4: bne         $at, $zero, L_8005D8F4
    if (ctx->r1 != 0) {
        // 0x8005D8D8: sll         $t6, $a0, 6
        ctx->r14 = S32(ctx->r4 << 6);
            goto L_8005D8F4;
    }
    // 0x8005D8D8: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x8005D8DC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005D8E0: addiu       $a0, $a0, 0xD00
    ctx->r4 = ADD32(ctx->r4, 0XD00);
    // 0x8005D8E4: jal         0x80071380
    // 0x8005D8E8: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005D8E8: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_0:
    // 0x8005D8EC: b           L_8005D90C
    // 0x8005D8F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D90C;
    // 0x8005D8F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005D8F4:
    // 0x8005D8F4: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8005D8F8: addiu       $t7, $t7, 0x5858
    ctx->r15 = ADD32(ctx->r15, 0X5858);
    // 0x8005D8FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005D900: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005D904: sw          $a0, 0x6340($at)
    MEM_W(0X6340, ctx->r1) = ctx->r4;
    // 0x8005D908: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8005D90C:
    // 0x8005D90C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D914: jr          $ra
    // 0x8005D918: nop

    return;
    // 0x8005D918: nop

;}
RECOMP_FUNC void func_8067A340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067A340: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8067A344: lbu         $a1, 0x7($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X7);
    // 0x8067A348: lui         $a2, 0x8068
    ctx->r6 = S32(RELOC_HI16(541, 0X26E8) << 16);
    // 0x8067A34C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8067A350: andi        $a1, $a1, 0x3F
    ctx->r5 = ctx->r5 & 0X3F;
    // 0x8067A354: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8067A358: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x8067A35C: addu        $a2, $a2, $a3
    ctx->r6 = ADD32(ctx->r6, ctx->r7);
    // 0x8067A360: lw          $a2, -0x3C68($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(541, 0X26E8));
    // 0x8067A364: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8067A368: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8067A36C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8067A370: addu        $t1, $a0, $t6
    ctx->r9 = ADD32(ctx->r4, ctx->r14);
    // 0x8067A374: lwc1        $f0, 0x3C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X3C);
    // 0x8067A378: lui         $t0, 0x8068
    ctx->r8 = S32(RELOC_HI16(541, 0X26F8) << 16);
    // 0x8067A37C: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(541, 0X26C8) << 16);
    // 0x8067A380: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8067A384: addu        $t0, $t0, $a3
    ctx->r8 = ADD32(ctx->r8, ctx->r7);
    // 0x8067A388: addu        $t7, $t7, $a3
    ctx->r15 = ADD32(ctx->r15, ctx->r7);
    // 0x8067A38C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067A390: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8067A394: lw          $t0, -0x3C58($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(541, 0X26F8));
    // 0x8067A398: lw          $t7, -0x3C88($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(541, 0X26C8));
    // 0x8067A39C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8067A3A0: beq         $t9, $zero, L_8067A3EC
    if (ctx->r25 == 0) {
        // 0x8067A3A4: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8067A3EC;
    }
    // 0x8067A3A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067A3A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067A3AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8067A3B0: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8067A3B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8067A3B8: nop

    // 0x8067A3BC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8067A3C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8067A3C4: nop

    // 0x8067A3C8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8067A3CC: bne         $t9, $zero, L_8067A3E4
    if (ctx->r25 != 0) {
        // 0x8067A3D0: nop
    
            goto L_8067A3E4;
    }
    // 0x8067A3D0: nop

    // 0x8067A3D4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8067A3D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067A3DC: b           L_8067A3FC
    // 0x8067A3E0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8067A3FC;
    // 0x8067A3E0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8067A3E4:
    // 0x8067A3E4: b           L_8067A3FC
    // 0x8067A3E8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8067A3FC;
    // 0x8067A3E8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_8067A3EC:
    // 0x8067A3EC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8067A3F0: nop

    // 0x8067A3F4: bltz        $t9, L_8067A3E4
    if (SIGNED(ctx->r25) < 0) {
        // 0x8067A3F8: nop
    
            goto L_8067A3E4;
    }
    // 0x8067A3F8: nop

L_8067A3FC:
    // 0x8067A3FC: andi        $t2, $t9, 0xF
    ctx->r10 = ctx->r25 & 0XF;
    // 0x8067A400: addiu       $t3, $t2, -0x8
    ctx->r11 = ADD32(ctx->r10, -0X8);
    // 0x8067A404: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8067A408: lui         $v1, 0x8068
    ctx->r3 = S32(RELOC_HI16(541, 0X26D8) << 16);
    // 0x8067A40C: addiu       $v1, $v1, -0x3C78
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(541, 0X26D8));
    // 0x8067A410: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8067A414: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8067A418: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8067A41C: mflo        $t4
    ctx->r12 = lo;
    // 0x8067A420: bgezl       $t4, L_8067A454
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8067A424: swc1        $f0, 0x3C($t1)
        MEM_W(0X3C, ctx->r9) = ctx->f0.u32l;
            goto L_8067A454;
    }
    goto skip_0;
    // 0x8067A424: swc1        $f0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f0.u32l;
    skip_0:
    // 0x8067A428: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8067A42C: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8067A430: addu        $t8, $v1, $a3
    ctx->r24 = ADD32(ctx->r3, ctx->r7);
    // 0x8067A434: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8067A438: nop

    // 0x8067A43C: bc1tl       L_8067A454
    if (c1cs) {
        // 0x8067A440: swc1        $f0, 0x3C($t1)
        MEM_W(0X3C, ctx->r9) = ctx->f0.u32l;
            goto L_8067A454;
    }
    goto skip_1;
    // 0x8067A440: swc1        $f0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f0.u32l;
    skip_1:
    // 0x8067A444: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8067A448: b           L_8067A454
    // 0x8067A44C: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
        goto L_8067A454;
    // 0x8067A44C: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x8067A450: swc1        $f0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f0.u32l;
L_8067A454:
    // 0x8067A454: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8067A458: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x8067A45C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8067A460: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A464: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A468: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8067A46C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067A470: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8067A474: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A478: nop

    // 0x8067A47C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A480: beql        $t7, $zero, L_8067A4D0
    if (ctx->r15 == 0) {
        // 0x8067A484: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_8067A4D0;
    }
    goto skip_2;
    // 0x8067A484: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x8067A488: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067A48C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A490: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8067A494: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A498: nop

    // 0x8067A49C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8067A4A0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A4A4: nop

    // 0x8067A4A8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A4AC: bne         $t7, $zero, L_8067A4C4
    if (ctx->r15 != 0) {
        // 0x8067A4B0: nop
    
            goto L_8067A4C4;
    }
    // 0x8067A4B0: nop

    // 0x8067A4B4: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8067A4B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067A4BC: b           L_8067A4DC
    // 0x8067A4C0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8067A4DC;
    // 0x8067A4C0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8067A4C4:
    // 0x8067A4C4: b           L_8067A4DC
    // 0x8067A4C8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8067A4DC;
    // 0x8067A4C8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8067A4CC: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_8067A4D0:
    // 0x8067A4D0: nop

    // 0x8067A4D4: bltz        $t7, L_8067A4C4
    if (SIGNED(ctx->r15) < 0) {
        // 0x8067A4D8: nop
    
            goto L_8067A4C4;
    }
    // 0x8067A4D8: nop

L_8067A4DC:
    // 0x8067A4DC: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8067A4E0: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8067A4E4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8067A4E8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8067A4EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8067A4F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8067A4F4: bgez        $t4, L_8067A508
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8067A4F8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8067A508;
    }
    // 0x8067A4F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8067A4FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067A500: nop

    // 0x8067A504: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8067A508:
    // 0x8067A508: jr          $ra
    // 0x8067A50C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8067A50C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_805CA4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA4F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805CA4F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805CA4F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805CA4FC: jal         0x805CA59C
    // 0x805CA500: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_805CA59C(rdram, ctx);
        goto after_0;
    // 0x805CA500: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805CA504: beq         $v0, $zero, L_805CA580
    if (ctx->r2 == 0) {
        // 0x805CA508: nop
    
            goto L_805CA580;
    }
    // 0x805CA508: nop

    // 0x805CA50C: jal         0x805CA5D4
    // 0x805CA510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805CA5D4(rdram, ctx);
        goto after_1;
    // 0x805CA510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805CA514: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x805CA518: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x805CA51C: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x805CA520: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805CA524: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805CA528: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805CA52C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805CA530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805CA534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805CA538: jal         0x805CA798
    // 0x805CA53C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805CA798(rdram, ctx);
        goto after_2;
    // 0x805CA53C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x805CA540: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x805CA544: addiu       $at, $zero, 0x4514
    ctx->r1 = ADD32(0, 0X4514);
    // 0x805CA548: beq         $v0, $at, L_805CA560
    if (ctx->r2 == ctx->r1) {
        // 0x805CA54C: addiu       $at, $zero, 0x45DC
        ctx->r1 = ADD32(0, 0X45DC);
            goto L_805CA560;
    }
    // 0x805CA54C: addiu       $at, $zero, 0x45DC
    ctx->r1 = ADD32(0, 0X45DC);
    // 0x805CA550: beql        $v0, $at, L_805CA574
    if (ctx->r2 == ctx->r1) {
        // 0x805CA554: lw          $t0, 0x1F4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1F4);
            goto L_805CA574;
    }
    goto skip_0;
    // 0x805CA554: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x805CA558: b           L_805CA58C
    // 0x805CA55C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805CA58C;
    // 0x805CA55C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805CA560:
    // 0x805CA560: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x805CA564: addiu       $t7, $zero, 0x41C8
    ctx->r15 = ADD32(0, 0X41C8);
    // 0x805CA568: b           L_805CA588
    // 0x805CA56C: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
        goto L_805CA588;
    // 0x805CA56C: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x805CA570: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
L_805CA574:
    // 0x805CA574: addiu       $t9, $zero, 0x45DD
    ctx->r25 = ADD32(0, 0X45DD);
    // 0x805CA578: b           L_805CA588
    // 0x805CA57C: sh          $t9, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r25;
        goto L_805CA588;
    // 0x805CA57C: sh          $t9, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r25;
L_805CA580:
    // 0x805CA580: jal         0x800445A4
    // 0x805CA584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x805CA584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_805CA588:
    // 0x805CA588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805CA58C:
    // 0x805CA58C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805CA590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805CA594: jr          $ra
    // 0x805CA598: nop

    return;
    // 0x805CA598: nop

;}
RECOMP_FUNC void func_80461ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80461AD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80461AD4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80461AD8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80461ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461AE0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80461AE4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80461AE8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80461AEC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80461AF0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80461AF4: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(122, 0X3738) << 16);
    // 0x80461AF8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80461AFC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80461B00: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80461B04: lw          $t2, 0x3CC8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(122, 0X3738));
    // 0x80461B08: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80461B0C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80461B10: jal         0x80460E1C
    // 0x80461B14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80460E1C(rdram, ctx);
        goto after_0;
    // 0x80461B14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80461B18: jal         0x80460E78
    // 0x80461B1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80460E78(rdram, ctx);
        goto after_1;
    // 0x80461B1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80461B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80461B28: jr          $ra
    // 0x80461B2C: nop

    return;
    // 0x80461B2C: nop

;}
RECOMP_FUNC void func_8002288C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002288C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80022890: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80022894: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x80022898: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002289C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800228A0: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800228A4: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x800228A8: lw          $t7, 0x54($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X54);
    // 0x800228AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800228B0: bnel        $t7, $zero, L_80022A48
    if (ctx->r15 != 0) {
        // 0x800228B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80022A48;
    }
    goto skip_0;
    // 0x800228B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800228B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800228BC: lwc1        $f4, 0x68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68);
    // 0x800228C0: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800228C4: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    // 0x800228C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800228CC: jal         0x80066DE4
    // 0x800228D0: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x800228D0: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800228D4: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800228D8: jal         0x80066E88
    // 0x800228DC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x800228DC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800228E0: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800228E4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800228E8: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800228EC: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800228F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800228F4: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800228F8: sub.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800228FC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80022900: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022904: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80022908: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x8002290C: mul.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80022910: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80022914: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80022918: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8002291C: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80022920: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80022924: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80022928: nop

    // 0x8002292C: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80022930: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80022934: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80022938: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002293C: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80022940: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80022944: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80022948: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002294C: lwc1        $f10, -0x380($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X380);
    // 0x80022950: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022954: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80022958: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8002295C: lwc1        $f4, -0x37C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X37C);
    // 0x80022960: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022964: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80022968: lwc1        $f6, -0x378($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X378);
    // 0x8002296C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80022970: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80022974: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80022978: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8002297C: jal         0x80066E88
    // 0x80022980: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80022980: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80022984: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80022988: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002298C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022990: lwc1        $f10, -0x374($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X374);
    // 0x80022994: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80022998: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002299C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800229A0: mul.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800229A4: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800229A8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800229AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800229B0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800229B4: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x800229B8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800229BC: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800229C0: nop

    // 0x800229C4: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800229C8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800229CC: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800229D0: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800229D4: lwc1        $f10, 0x100($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X100);
    // 0x800229D8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800229DC: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800229E0: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800229E4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800229E8: lwc1        $f10, 0xE4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x800229EC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800229F0: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800229F4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800229F8: mul.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800229FC: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80022A00: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80022A04: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80022A08: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80022A0C: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80022A10: lwc1        $f4, 0xE8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x80022A14: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80022A18: lwc1        $f10, -0x370($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X370);
    // 0x80022A1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022A20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80022A24: lwc1        $f4, -0x36C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X36C);
    // 0x80022A28: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x80022A2C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80022A30: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x80022A34: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80022A38: lw          $t9, 0x10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X10);
    // 0x80022A3C: jalr        $t9
    // 0x80022A40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80022A40: nop

    after_3:
    // 0x80022A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80022A48:
    // 0x80022A48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022A4C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80022A50: jr          $ra
    // 0x80022A54: nop

    return;
    // 0x80022A54: nop

;}
RECOMP_FUNC void func_807B3AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B3AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B3AE8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807B3AEC: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(877, 0X250) << 16);
    // 0x807B3AF0: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x807B3AF4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807B3AF8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807B3AFC: sw          $zero, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = 0;
    // 0x807B3B00: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x807B3B04: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807B3B08: addiu       $t6, $t6, 0x3CE0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(877, 0X250));
    // 0x807B3B0C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807B3B10: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x807B3B14: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x807B3B18: andi        $a2, $a2, 0x3FF
    ctx->r6 = ctx->r6 & 0X3FF;
    // 0x807B3B1C: lwc1        $f6, 0x6C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x807B3B20: addiu       $a2, $a2, -0x200
    ctx->r6 = ADD32(ctx->r6, -0X200);
    // 0x807B3B24: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x807B3B28: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B3B2C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(877, 0X258) << 16);
    // 0x807B3B30: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x807B3B34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B3B38: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x807B3B3C: lwc1        $f10, 0x70($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X70);
    // 0x807B3B40: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x807B3B44: lwc1        $f18, 0x3CE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(877, 0X258));
    // 0x807B3B48: lwc1        $f16, 0x6C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x807B3B4C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(877, 0X268) << 16);
    // 0x807B3B50: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x807B3B54: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x807B3B58: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x807B3B5C: lwc1        $f8, 0x3CF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(877, 0X268));
    // 0x807B3B60: lwc1        $f6, 0x70($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X70);
    // 0x807B3B64: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807B3B68: jal         0x807B3C08
    // 0x807B3B6C: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    func_807B3C08(rdram, ctx);
        goto after_0;
    // 0x807B3B6C: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    after_0:
    // 0x807B3B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B3B74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807B3B78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807B3B7C: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x807B3B80: jr          $ra
    // 0x807B3B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807B3B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8044D51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D51C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044D520: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044D524: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8044D528: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8044D52C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8044D530: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8044D534: lw          $v1, 0x1F4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X1F4);
    // 0x8044D538: lw          $t0, 0xA54($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XA54);
    // 0x8044D53C: slti        $at, $t0, 0x99D
    ctx->r1 = SIGNED(ctx->r8) < 0X99D ? 1 : 0;
    // 0x8044D540: bne         $at, $zero, L_8044D5E4
    if (ctx->r1 != 0) {
        // 0x8044D544: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8044D5E4;
    }
    // 0x8044D544: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044D548: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x8044D54C: lw          $t7, 0x6C90($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X6C90);
    // 0x8044D550: lw          $a0, 0x6980($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6980);
    // 0x8044D554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044D558: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8044D55C: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8044D560: lw          $a3, 0x3C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X3C);
    // 0x8044D564: bne         $at, $zero, L_8044D598
    if (ctx->r1 != 0) {
        // 0x8044D568: sw          $t8, 0x6C90($v0)
        MEM_W(0X6C90, ctx->r2) = ctx->r24;
            goto L_8044D598;
    }
    // 0x8044D568: sw          $t8, 0x6C90($v0)
    MEM_W(0X6C90, ctx->r2) = ctx->r24;
    // 0x8044D56C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044D570: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8044D574: sw          $zero, 0x6C90($at)
    MEM_W(0X6C90, ctx->r1) = 0;
    // 0x8044D578: lw          $t1, 0x6C8C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X6C8C);
    // 0x8044D57C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8044D580: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8044D584: bne         $at, $zero, L_8044D598
    if (ctx->r1 != 0) {
        // 0x8044D588: sw          $t2, 0x6C8C($v0)
        MEM_W(0X6C8C, ctx->r2) = ctx->r10;
            goto L_8044D598;
    }
    // 0x8044D588: sw          $t2, 0x6C8C($v0)
    MEM_W(0X6C8C, ctx->r2) = ctx->r10;
    // 0x8044D58C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044D590: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8044D594: sw          $zero, 0x6C8C($at)
    MEM_W(0X6C8C, ctx->r1) = 0;
L_8044D598:
    // 0x8044D598: beq         $a3, $zero, L_8044D5E4
    if (ctx->r7 == 0) {
        // 0x8044D59C: addiu       $t0, $t0, -0x780
        ctx->r8 = ADD32(ctx->r8, -0X780);
            goto L_8044D5E4;
    }
    // 0x8044D59C: addiu       $t0, $t0, -0x780
    ctx->r8 = ADD32(ctx->r8, -0X780);
    // 0x8044D5A0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8044D5A4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8044D5A8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8044D5AC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8044D5B0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8044D5B4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8044D5B8: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8044D5BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044D5C0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8044D5C4: jal         0x8044D1F4
    // 0x8044D5C8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_8044D1F4(rdram, ctx);
        goto after_0;
    // 0x8044D5C8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x8044D5CC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8044D5D0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8044D5D4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8044D5D8: lh          $t1, 0x2($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X2);
    // 0x8044D5DC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8044D5E0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_8044D5E4:
    // 0x8044D5E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044D5E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044D5EC: jr          $ra
    // 0x8044D5F0: nop

    return;
    // 0x8044D5F0: nop

;}
