#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806FBF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FBF18: lw          $v0, 0x14CC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14CC);
    // 0x806FBF1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806FBF20: beq         $v0, $zero, L_806FBF34
    if (ctx->r2 == 0) {
        // 0x806FBF24: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806FBF34;
    }
    // 0x806FBF24: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806FBF28: sw          $t6, 0x14CC($a0)
    MEM_W(0X14CC, ctx->r4) = ctx->r14;
    // 0x806FBF2C: jr          $ra
    // 0x806FBF30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x806FBF30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806FBF34:
    // 0x806FBF34: lw          $v0, 0x14C4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C4);
    // 0x806FBF38: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(700, 0X28D0) << 16);
    // 0x806FBF3C: addiu       $t9, $t9, -0x3B00
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(700, 0X28D0));
    // 0x806FBF40: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x806FBF44: beq         $at, $zero, L_806FBF80
    if (ctx->r1 == 0) {
        // 0x806FBF48: addiu       $a1, $v0, 0x1
        ctx->r5 = ADD32(ctx->r2, 0X1);
            goto L_806FBF80;
    }
    // 0x806FBF48: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x806FBF4C: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x806FBF50: sw          $a1, 0x14C4($a0)
    MEM_W(0X14C4, ctx->r4) = ctx->r5;
    // 0x806FBF54: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x806FBF58: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x806FBF5C: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x806FBF60: lui         $t2, 0x8070
    ctx->r10 = S32(RELOC_HI16(700, 0X2754) << 16);
    // 0x806FBF64: sll         $t1, $a2, 3
    ctx->r9 = S32(ctx->r6 << 3);
    // 0x806FBF68: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806FBF6C: sw          $t0, 0x14CC($a0)
    MEM_W(0X14CC, ctx->r4) = ctx->r8;
    // 0x806FBF70: lw          $t2, -0x3C7C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(700, 0X2754));
    // 0x806FBF74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x806FBF78: jr          $ra
    // 0x806FBF7C: sw          $t2, 0x14C8($a0)
    MEM_W(0X14C8, ctx->r4) = ctx->r10;
    return;
    // 0x806FBF7C: sw          $t2, 0x14C8($a0)
    MEM_W(0X14C8, ctx->r4) = ctx->r10;
L_806FBF80:
    // 0x806FBF80: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806FBF84: jr          $ra
    // 0x806FBF88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x806FBF88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_804BD0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD0C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD0CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD0D0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804BD0D4: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X4074) << 16);
    // 0x804BD0D8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x804BD0DC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804BD0E0: addiu       $t6, $t6, -0x65C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X4074));
    // 0x804BD0E4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804BD0E8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804BD0EC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804BD0F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BD0F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BD0F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804BD0FC: jal         0x804BD3E8
    // 0x804BD100: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804BD3E8(rdram, ctx);
        goto after_0;
    // 0x804BD100: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804BD104: jal         0x804BD098
    // 0x804BD108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804BD098(rdram, ctx);
        goto after_1;
    // 0x804BD108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804BD10C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BD110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BD114: jr          $ra
    // 0x804BD118: nop

    return;
    // 0x804BD118: nop

;}
RECOMP_FUNC void func_80565910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80565910: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80565914: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80565918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8056591C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80565920: addiu       $a3, $v0, 0x174
    ctx->r7 = ADD32(ctx->r2, 0X174);
L_80565924:
    // 0x80565924: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80565928: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8056592C: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
L_80565930:
    // 0x80565930: sh          $zero, 0x2($t0)
    MEM_H(0X2, ctx->r8) = 0;
    // 0x80565934: lh          $v1, 0x2($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X2);
    // 0x80565938: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8056593C: slti        $at, $a0, 0x3E
    ctx->r1 = SIGNED(ctx->r4) < 0X3E ? 1 : 0;
    // 0x80565940: sh          $v1, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r3;
    // 0x80565944: sh          $v1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r3;
    // 0x80565948: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8056594C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80565950: bne         $at, $zero, L_80565930
    if (ctx->r1 != 0) {
        // 0x80565954: sh          $v1, -0x4($t1)
        MEM_H(-0X4, ctx->r9) = ctx->r3;
            goto L_80565930;
    }
    // 0x80565954: sh          $v1, -0x4($t1)
    MEM_H(-0X4, ctx->r9) = ctx->r3;
    // 0x80565958: addiu       $a1, $a1, 0x7C
    ctx->r5 = ADD32(ctx->r5, 0X7C);
    // 0x8056595C: slti        $at, $a1, 0x174
    ctx->r1 = SIGNED(ctx->r5) < 0X174 ? 1 : 0;
    // 0x80565960: addiu       $a2, $a2, 0x7C
    ctx->r6 = ADD32(ctx->r6, 0X7C);
    // 0x80565964: bne         $at, $zero, L_80565924
    if (ctx->r1 != 0) {
        // 0x80565968: addiu       $a3, $a3, 0x7C
        ctx->r7 = ADD32(ctx->r7, 0X7C);
            goto L_80565924;
    }
    // 0x80565968: addiu       $a3, $a3, 0x7C
    ctx->r7 = ADD32(ctx->r7, 0X7C);
    // 0x8056596C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80565970: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x80565974: sb          $zero, 0x4E0($v0)
    MEM_B(0X4E0, ctx->r2) = 0;
    // 0x80565978: swc1        $f0, 0x2F4($v0)
    MEM_W(0X2F4, ctx->r2) = ctx->f0.u32l;
    // 0x8056597C: swc1        $f0, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f0.u32l;
    // 0x80565980: swc1        $f0, 0x3E8($v0)
    MEM_W(0X3E8, ctx->r2) = ctx->f0.u32l;
    // 0x80565984: swc1        $f0, 0x464($v0)
    MEM_W(0X464, ctx->r2) = ctx->f0.u32l;
    // 0x80565988: sb          $zero, 0x4E0($t6)
    MEM_B(0X4E0, ctx->r14) = 0;
    // 0x8056598C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80565990: addu        $a3, $v0, $t7
    ctx->r7 = ADD32(ctx->r2, ctx->r15);
    // 0x80565994: swc1        $f0, 0x2F8($v0)
    MEM_W(0X2F8, ctx->r2) = ctx->f0.u32l;
    // 0x80565998: swc1        $f0, 0x2FC($v0)
    MEM_W(0X2FC, ctx->r2) = ctx->f0.u32l;
    // 0x8056599C: swc1        $f0, 0x464($a3)
    MEM_W(0X464, ctx->r7) = ctx->f0.u32l;
    // 0x805659A0: swc1        $f0, 0x3E8($a3)
    MEM_W(0X3E8, ctx->r7) = ctx->f0.u32l;
    // 0x805659A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x805659A8: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x805659AC: sb          $zero, 0x4E0($t8)
    MEM_B(0X4E0, ctx->r24) = 0;
    // 0x805659B0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x805659B4: addu        $a3, $v0, $t9
    ctx->r7 = ADD32(ctx->r2, ctx->r25);
    // 0x805659B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x805659BC: swc1        $f0, 0x300($v0)
    MEM_W(0X300, ctx->r2) = ctx->f0.u32l;
    // 0x805659C0: swc1        $f0, 0x304($v0)
    MEM_W(0X304, ctx->r2) = ctx->f0.u32l;
    // 0x805659C4: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x805659C8: swc1        $f0, 0x464($a3)
    MEM_W(0X464, ctx->r7) = ctx->f0.u32l;
    // 0x805659CC: swc1        $f0, 0x3E8($a3)
    MEM_W(0X3E8, ctx->r7) = ctx->f0.u32l;
    // 0x805659D0: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x805659D4: addiu       $v1, $zero, 0x3E
    ctx->r3 = ADD32(0, 0X3E);
    // 0x805659D8: addu        $a3, $v0, $t2
    ctx->r7 = ADD32(ctx->r2, ctx->r10);
    // 0x805659DC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x805659E0: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
L_805659E4:
    // 0x805659E4: sb          $zero, 0x4E0($a1)
    MEM_B(0X4E0, ctx->r5) = 0;
    // 0x805659E8: swc1        $f0, 0x2F0($a2)
    MEM_W(0X2F0, ctx->r6) = ctx->f0.u32l;
    // 0x805659EC: swc1        $f0, 0x2F4($a2)
    MEM_W(0X2F4, ctx->r6) = ctx->f0.u32l;
    // 0x805659F0: swc1        $f0, 0x464($a3)
    MEM_W(0X464, ctx->r7) = ctx->f0.u32l;
    // 0x805659F4: swc1        $f0, 0x3E8($a3)
    MEM_W(0X3E8, ctx->r7) = ctx->f0.u32l;
    // 0x805659F8: sb          $zero, 0x4E1($a1)
    MEM_B(0X4E1, ctx->r5) = 0;
    // 0x805659FC: swc1        $f0, 0x2F8($a2)
    MEM_W(0X2F8, ctx->r6) = ctx->f0.u32l;
    // 0x80565A00: swc1        $f0, 0x2FC($a2)
    MEM_W(0X2FC, ctx->r6) = ctx->f0.u32l;
    // 0x80565A04: swc1        $f0, 0x468($a3)
    MEM_W(0X468, ctx->r7) = ctx->f0.u32l;
    // 0x80565A08: swc1        $f0, 0x3EC($a3)
    MEM_W(0X3EC, ctx->r7) = ctx->f0.u32l;
    // 0x80565A0C: sb          $zero, 0x4E2($a1)
    MEM_B(0X4E2, ctx->r5) = 0;
    // 0x80565A10: swc1        $f0, 0x300($a2)
    MEM_W(0X300, ctx->r6) = ctx->f0.u32l;
    // 0x80565A14: swc1        $f0, 0x304($a2)
    MEM_W(0X304, ctx->r6) = ctx->f0.u32l;
    // 0x80565A18: swc1        $f0, 0x46C($a3)
    MEM_W(0X46C, ctx->r7) = ctx->f0.u32l;
    // 0x80565A1C: swc1        $f0, 0x3F0($a3)
    MEM_W(0X3F0, ctx->r7) = ctx->f0.u32l;
    // 0x80565A20: sb          $zero, 0x4E3($a1)
    MEM_B(0X4E3, ctx->r5) = 0;
    // 0x80565A24: swc1        $f0, 0x308($a2)
    MEM_W(0X308, ctx->r6) = ctx->f0.u32l;
    // 0x80565A28: swc1        $f0, 0x30C($a2)
    MEM_W(0X30C, ctx->r6) = ctx->f0.u32l;
    // 0x80565A2C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80565A30: swc1        $f0, 0x470($a3)
    MEM_W(0X470, ctx->r7) = ctx->f0.u32l;
    // 0x80565A34: swc1        $f0, 0x3F4($a3)
    MEM_W(0X3F4, ctx->r7) = ctx->f0.u32l;
    // 0x80565A38: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80565A3C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80565A40: bne         $a0, $v1, L_805659E4
    if (ctx->r4 != ctx->r3) {
        // 0x80565A44: addiu       $a2, $a2, 0x20
        ctx->r6 = ADD32(ctx->r6, 0X20);
            goto L_805659E4;
    }
    // 0x80565A44: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80565A48: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x80565A4C: sh          $t3, 0x502($v0)
    MEM_H(0X502, ctx->r2) = ctx->r11;
    // 0x80565A50: lh          $t4, 0x502($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X502);
    // 0x80565A54: sw          $zero, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = 0;
    // 0x80565A58: sw          $zero, 0x2E8($v0)
    MEM_W(0X2E8, ctx->r2) = 0;
    // 0x80565A5C: sh          $zero, 0x52C($v0)
    MEM_H(0X52C, ctx->r2) = 0;
    // 0x80565A60: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X25BC) << 16);
    // 0x80565A64: sh          $t4, 0x500($v0)
    MEM_H(0X500, ctx->r2) = ctx->r12;
    // 0x80565A68: lwc1        $f4, 0x5E1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X25BC));
    // 0x80565A6C: jr          $ra
    // 0x80565A70: swc1        $f4, 0x504($v0)
    MEM_W(0X504, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80565A70: swc1        $f4, 0x504($v0)
    MEM_W(0X504, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8064CA70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CA70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064CA74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064CA78: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8064CA7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064CA80: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064CA84: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064CA88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064CA8C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064CA90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064CA94: bc1fl       L_8064CAB8
    if (!c1cs) {
        // 0x8064CA98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064CAB8;
    }
    goto skip_0;
    // 0x8064CA98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064CA9C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064CAA0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064CAA4: jal         0x8064CD50
    // 0x8064CAA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064CAA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064CAAC: jal         0x8064A40C
    // 0x8064CAB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8064A40C(rdram, ctx);
        goto after_1;
    // 0x8064CAB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8064CAB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064CAB8:
    // 0x8064CAB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064CABC: jr          $ra
    // 0x8064CAC0: nop

    return;
    // 0x8064CAC0: nop

;}
RECOMP_FUNC void func_8071568C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071568C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80715690: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80715694: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80715698: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8071569C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807156A0: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x807156A4: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x807156A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x807156AC: sh          $t6, 0x5E2($s2)
    MEM_H(0X5E2, ctx->r18) = ctx->r14;
    // 0x807156B0: sh          $zero, 0x5E0($s2)
    MEM_H(0X5E0, ctx->r18) = 0;
    // 0x807156B4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x807156B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807156BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807156C0: swc1        $f4, 0x5E4($s2)
    MEM_W(0X5E4, ctx->r18) = ctx->f4.u32l;
    // 0x807156C4: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807156C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807156CC: addiu       $a0, $zero, 0x4637
    ctx->r4 = ADD32(0, 0X4637);
    // 0x807156D0: sw          $zero, 0x5EC($s2)
    MEM_W(0X5EC, ctx->r18) = 0;
    // 0x807156D4: swc1        $f0, 0x5F0($s2)
    MEM_W(0X5F0, ctx->r18) = ctx->f0.u32l;
    // 0x807156D8: swc1        $f8, 0x5F4($s2)
    MEM_W(0X5F4, ctx->r18) = ctx->f8.u32l;
    // 0x807156DC: jal         0x80047090
    // 0x807156E0: swc1        $f6, 0x5E8($s2)
    MEM_W(0X5E8, ctx->r18) = ctx->f6.u32l;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807156E0: swc1        $f6, 0x5E8($s2)
    MEM_W(0X5E8, ctx->r18) = ctx->f6.u32l;
    after_0:
    // 0x807156E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807156E8: lui         $at, 0x4637
    ctx->r1 = S32(0X4637 << 16);
    // 0x807156EC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807156F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807156F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807156F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807156FC: jal         0x8004613C
    // 0x80715700: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80715700: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80715704: bne         $v0, $zero, L_8071571C
    if (ctx->r2 != 0) {
        // 0x80715708: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8071571C;
    }
    // 0x80715708: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8071570C: jal         0x800445A4
    // 0x80715710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80715710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80715714: b           L_80715828
    // 0x80715718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80715828;
    // 0x80715718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8071571C:
    // 0x8071571C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80715720: jal         0x80047F9C
    // 0x80715724: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80715724: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80715728: sb          $zero, 0x17C($s1)
    MEM_B(0X17C, ctx->r17) = 0;
    // 0x8071572C: jal         0x80715B98
    // 0x80715730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80715B98(rdram, ctx);
        goto after_4;
    // 0x80715730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80715734: sw          $s1, 0x5A0($s2)
    MEM_W(0X5A0, ctx->r18) = ctx->r17;
    // 0x80715738: jal         0x8005FDC4
    // 0x8071573C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_5;
    // 0x8071573C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80715740: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80715744: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80715748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8071574C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80715750: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x80715754: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80715758: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    // 0x8071575C: swc1        $f0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f0.u32l;
    // 0x80715760: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80715764: beq         $a0, $a1, L_807157D0
    if (ctx->r4 == ctx->r5) {
        // 0x80715768: lwc1        $f18, 0x3C($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_807157D0;
    }
    // 0x80715768: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8071576C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_80715770:
    // 0x80715770: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80715774: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80715778: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8071577C: swc1        $f16, 0x270($v0)
    MEM_W(0X270, ctx->r2) = ctx->f16.u32l;
    // 0x80715780: sb          $zero, 0x500($v1)
    MEM_B(0X500, ctx->r3) = 0;
    // 0x80715784: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80715788: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8071578C: swc1        $f16, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80715790: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80715794: swc1        $f16, 0x274($v0)
    MEM_W(0X274, ctx->r2) = ctx->f16.u32l;
    // 0x80715798: sb          $zero, 0x4FD($v1)
    MEM_B(0X4FD, ctx->r3) = 0;
    // 0x8071579C: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807157A0: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x807157A4: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807157A8: swc1        $f16, 0x278($v0)
    MEM_W(0X278, ctx->r2) = ctx->f16.u32l;
    // 0x807157AC: sb          $zero, 0x4FE($v1)
    MEM_B(0X4FE, ctx->r3) = 0;
    // 0x807157B0: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807157B4: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x807157B8: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807157BC: swc1        $f16, 0x27C($v0)
    MEM_W(0X27C, ctx->r2) = ctx->f16.u32l;
    // 0x807157C0: sb          $zero, 0x4FF($v1)
    MEM_B(0X4FF, ctx->r3) = 0;
    // 0x807157C4: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807157C8: bnel        $a0, $a1, L_80715770
    if (ctx->r4 != ctx->r5) {
        // 0x807157CC: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_80715770;
    }
    goto skip_0;
    // 0x807157CC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    skip_0:
L_807157D0:
    // 0x807157D0: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x807157D4: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807157D8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x807157DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807157E0: swc1        $f16, 0x270($v0)
    MEM_W(0X270, ctx->r2) = ctx->f16.u32l;
    // 0x807157E4: sb          $zero, 0x4FC($v1)
    MEM_B(0X4FC, ctx->r3) = 0;
    // 0x807157E8: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807157EC: swc1        $f16, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f16.u32l;
    // 0x807157F0: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807157F4: swc1        $f16, 0x274($v0)
    MEM_W(0X274, ctx->r2) = ctx->f16.u32l;
    // 0x807157F8: sb          $zero, 0x4FD($v1)
    MEM_B(0X4FD, ctx->r3) = 0;
    // 0x807157FC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80715800: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x80715804: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80715808: swc1        $f16, 0x278($v0)
    MEM_W(0X278, ctx->r2) = ctx->f16.u32l;
    // 0x8071580C: sb          $zero, 0x4FE($v1)
    MEM_B(0X4FE, ctx->r3) = 0;
    // 0x80715810: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80715814: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80715818: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8071581C: swc1        $f16, 0x27C($v0)
    MEM_W(0X27C, ctx->r2) = ctx->f16.u32l;
    // 0x80715820: sb          $zero, 0x4FF($v1)
    MEM_B(0X4FF, ctx->r3) = 0;
    // 0x80715824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80715828:
    // 0x80715828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8071582C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80715830: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80715834: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80715838: jr          $ra
    // 0x8071583C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8071583C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_807B2D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B2D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B2D08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807B2D0C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x807B2D10: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x807B2D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B2D18: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x807B2D1C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807B2D20: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x807B2D24: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x807B2D28: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x807B2D2C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x807B2D30: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x807B2D34: lui         $t2, 0x807B
    ctx->r10 = S32(RELOC_HI16(871, 0X390C) << 16);
    // 0x807B2D38: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807B2D3C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x807B2D40: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x807B2D44: lw          $t2, 0x345C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(871, 0X390C));
    // 0x807B2D48: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x807B2D4C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x807B2D50: jal         0x807B0264
    // 0x807B2D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807B0264(rdram, ctx);
        goto after_0;
    // 0x807B2D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B2D58: jal         0x807B02C0
    // 0x807B2D5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807B02C0(rdram, ctx);
        goto after_1;
    // 0x807B2D5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807B2D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B2D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B2D68: jr          $ra
    // 0x807B2D6C: nop

    return;
    // 0x807B2D6C: nop

;}
RECOMP_FUNC void func_800231AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800231AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800231B0: lwc1        $f4, -0x30C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30C);
    // 0x800231B4: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800231B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800231BC: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x800231C0: jr          $ra
    // 0x800231C4: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x800231C4: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_804C9A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9A54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C9A58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C9A5C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804C9A60: jal         0x804C995C
    // 0x804C9A64: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_804C995C(rdram, ctx);
        goto after_0;
    // 0x804C9A64: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x804C9A68: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804C9A6C: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(228, 0X8F0) << 16);
    // 0x804C9A70: lui         $a1, 0x4038
    ctx->r5 = S32(0X4038 << 16);
    // 0x804C9A74: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x804C9A78: addiu       $a0, $a0, -0x63D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(228, 0X8F0));
    // 0x804C9A7C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x804C9A80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x804C9A84: jal         0x80046804
    // 0x804C9A88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x804C9A88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x804C9A8C: beq         $v0, $zero, L_804C9AA4
    if (ctx->r2 == 0) {
        // 0x804C9A90: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804C9AA4;
    }
    // 0x804C9A90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804C9A94: jal         0x80052BA4
    // 0x804C9A98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80052BA4(rdram, ctx);
        goto after_2;
    // 0x804C9A98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x804C9A9C: jal         0x80044194
    // 0x804C9AA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x804C9AA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_804C9AA4:
    // 0x804C9AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C9AA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804C9AAC: jr          $ra
    // 0x804C9AB0: nop

    return;
    // 0x804C9AB0: nop

    // 0x804C9AB4: nop

    // 0x804C9AB8: nop

    // 0x804C9ABC: nop

;}
RECOMP_FUNC void func_80445760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445768: jal         0x80046E88
    // 0x8044576C: addiu       $a0, $zero, 0x40EE
    ctx->r4 = ADD32(0, 0X40EE);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x8044576C: addiu       $a0, $zero, 0x40EE
    ctx->r4 = ADD32(0, 0X40EE);
    after_0:
    // 0x80445770: beq         $v0, $zero, L_80445780
    if (ctx->r2 == 0) {
        // 0x80445774: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80445780;
    }
    // 0x80445774: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80445778: jal         0x800447C8
    // 0x8044577C: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8044577C: nop

    after_1:
L_80445780:
    // 0x80445780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445788: jr          $ra
    // 0x8044578C: nop

    return;
    // 0x8044578C: nop

;}
RECOMP_FUNC void func_804C3D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3D88: jal         0x804C3D3C
    // 0x804C3D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C3D3C(rdram, ctx);
        goto after_0;
    // 0x804C3D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C3D90: bne         $v0, $zero, L_804C3DA8
    if (ctx->r2 != 0) {
        // 0x804C3D94: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C3DA8;
    }
    // 0x804C3D94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C3D98: jal         0x800447C8
    // 0x804C3D9C: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804C3D9C: nop

    after_1:
    // 0x804C3DA0: b           L_804C3E00
    // 0x804C3DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C3E00;
    // 0x804C3DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C3DA8:
    // 0x804C3DA8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804C3DAC: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(206, 0XFC0) << 16);
    // 0x804C3DB0: addiu       $t6, $t6, 0x3A40
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(206, 0XFC0));
    // 0x804C3DB4: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x804C3DB8: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x804C3DBC: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x804C3DC0: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x804C3DC4: lui         $t9, 0x804C
    ctx->r25 = S32(RELOC_HI16(206, 0X143C) << 16);
    // 0x804C3DC8: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x804C3DCC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C3DD0: addiu       $t9, $t9, 0x3EBC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(206, 0X143C));
    // 0x804C3DD4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x804C3DD8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804C3DDC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804C3DE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C3DE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C3DE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C3DEC: jal         0x804C3E0C
    // 0x804C3DF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804C3E0C(rdram, ctx);
        goto after_2;
    // 0x804C3DF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804C3DF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C3DF8: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x804C3DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C3E00:
    // 0x804C3E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C3E04: jr          $ra
    // 0x804C3E08: nop

    return;
    // 0x804C3E08: nop

;}
RECOMP_FUNC void func_806CE138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CE138: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x806CE13C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x806CE140: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x806CE144: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x806CE148: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x806CE14C: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x806CE150: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x806CE154: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x806CE158: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x806CE15C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x806CE160: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x806CE164: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x806CE168: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x806CE16C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x806CE170: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x806CE174: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x806CE178: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x806CE17C: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x806CE180: sw          $a3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r7;
    // 0x806CE184: jal         0x80049018
    // 0x806CE188: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x806CE188: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x806CE18C: beq         $v0, $zero, L_806CE1B8
    if (ctx->r2 == 0) {
        // 0x806CE190: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806CE1B8;
    }
    // 0x806CE190: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CE194: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806CE198: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806CE19C: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x806CE1A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CE1A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806CE1A8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806CE1AC: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x806CE1B0: b           L_806CE1C4
    // 0x806CE1B4: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
        goto L_806CE1C4;
    // 0x806CE1B4: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
L_806CE1B8:
    // 0x806CE1B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806CE1BC: nop

    // 0x806CE1C0: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
L_806CE1C4:
    // 0x806CE1C4: lwc1        $f0, 0x860($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X860);
    // 0x806CE1C8: lwc1        $f8, 0x854($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X854);
    // 0x806CE1CC: lwc1        $f16, 0x858($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X858);
    // 0x806CE1D0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x806CE1D4: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x806CE1D8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806CE1DC: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x806CE1E0: mul.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x806CE1E4: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x806CE1E8: mfc1        $s7, $f6
    ctx->r23 = (int32_t)ctx->f6.u32l;
    // 0x806CE1EC: nop

    // 0x806CE1F0: bltz        $s7, L_806CE718
    if (SIGNED(ctx->r23) < 0) {
        // 0x806CE1F4: sw          $s7, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r23;
            goto L_806CE718;
    }
    // 0x806CE1F4: sw          $s7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r23;
    // 0x806CE1F8: slti        $at, $s7, 0x3B
    ctx->r1 = SIGNED(ctx->r23) < 0X3B ? 1 : 0;
    // 0x806CE1FC: beq         $at, $zero, L_806CE718
    if (ctx->r1 == 0) {
        // 0x806CE200: lwc1        $f8, 0xD8($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
            goto L_806CE718;
    }
    // 0x806CE200: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x806CE204: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x806CE208: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806CE20C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806CE210: sll         $t0, $s7, 2
    ctx->r8 = S32(ctx->r23 << 2);
    // 0x806CE214: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x806CE218: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x806CE21C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806CE220: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806CE224: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x806CE228: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x806CE22C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x806CE230: div.s       $f30, $f4, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806CE234: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x806CE238: nop

    // 0x806CE23C: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x806CE240: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x806CE244: lwc1        $f8, 0x590($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X590);
    // 0x806CE248: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x806CE24C: lwc1        $f6, 0x85C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE250: subu        $t2, $s7, $t8
    ctx->r10 = SUB32(ctx->r23, ctx->r24);
    // 0x806CE254: subu        $t5, $s7, $t4
    ctx->r13 = SUB32(ctx->r23, ctx->r12);
    // 0x806CE258: slt         $at, $t5, $s7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x806CE25C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806CE260: div.s       $f22, $f14, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
    // 0x806CE264: bc1fl       L_806CE4C4
    if (!c1cs) {
        // 0x806CE268: mtc1        $zero, $f24
        ctx->f24.u32l = 0;
            goto L_806CE4C4;
    }
    goto skip_0;
    // 0x806CE268: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    skip_0:
    // 0x806CE26C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x806CE270: slt         $at, $t2, $s7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x806CE274: beq         $at, $zero, L_806CE380
    if (ctx->r1 == 0) {
        // 0x806CE278: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_806CE380;
    }
    // 0x806CE278: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x806CE27C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806CE280: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x806CE284: subu        $s5, $s7, $t8
    ctx->r21 = SUB32(ctx->r23, ctx->r24);
    // 0x806CE288: lwc1        $f26, 0xD4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x806CE28C: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
L_806CE290:
    // 0x806CE290: slti        $at, $s2, 0x3B
    ctx->r1 = SIGNED(ctx->r18) < 0X3B ? 1 : 0;
    // 0x806CE294: beql        $at, $zero, L_806CE370
    if (ctx->r1 == 0) {
        // 0x806CE298: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806CE370;
    }
    goto skip_1;
    // 0x806CE298: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
    // 0x806CE29C: bltz        $s2, L_806CE36C
    if (SIGNED(ctx->r18) < 0) {
        // 0x806CE2A0: sll         $t4, $s2, 2
        ctx->r12 = S32(ctx->r18 << 2);
            goto L_806CE36C;
    }
    // 0x806CE2A0: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x806CE2A4: sll         $t6, $s2, 3
    ctx->r14 = S32(ctx->r18 << 3);
    // 0x806CE2A8: addu        $s0, $s3, $t6
    ctx->r16 = ADD32(ctx->r19, ctx->r14);
    // 0x806CE2AC: addu        $s1, $s3, $t4
    ctx->r17 = ADD32(ctx->r19, ctx->r12);
    // 0x806CE2B0: lwc1        $f16, 0x590($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X590);
    // 0x806CE2B4: lwc1        $f18, 0x67C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X67C);
    // 0x806CE2B8: mtc1        $s4, $f8
    ctx->f8.u32l = ctx->r20;
    // 0x806CE2BC: lwc1        $f6, 0x85C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE2C0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806CE2C4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806CE2C8: mul.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x806CE2CC: nop

    // 0x806CE2D0: mul.s       $f12, $f10, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x806CE2D4: jal         0x80066E88
    // 0x806CE2D8: nop

    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806CE2D8: nop

    after_1:
    // 0x806CE2DC: lwc1        $f2, 0x85C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE2E0: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x806CE2E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806CE2E8: mul.s       $f16, $f28, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x806CE2EC: sub.s       $f18, $f26, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x806CE2F0: add.s       $f6, $f20, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x806CE2F4: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x806CE2F8: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x806CE2FC: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x806CE300: nop

    // 0x806CE304: bc1fl       L_806CE370
    if (!c1cs) {
        // 0x806CE308: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806CE370;
    }
    goto skip_2;
    // 0x806CE308: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_2:
    // 0x806CE30C: lwc1        $f16, 0x67C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X67C);
    // 0x806CE310: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x806CE314: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x806CE318: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x806CE31C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x806CE320: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x806CE324: jal         0x806CE084
    // 0x806CE328: nop

    func_806CE084(rdram, ctx);
        goto after_2;
    // 0x806CE328: nop

    after_2:
    // 0x806CE32C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x806CE330: lwc1        $f6, 0x67C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X67C);
    // 0x806CE334: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x806CE338: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806CE33C: swc1        $f10, 0x67C($s0)
    MEM_W(0X67C, ctx->r16) = ctx->f10.u32l;
    // 0x806CE340: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x806CE344: lwc1        $f16, 0x590($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X590);
    // 0x806CE348: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x806CE34C: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x806CE350: swc1        $f6, 0x590($s1)
    MEM_W(0X590, ctx->r17) = ctx->f6.u32l;
    // 0x806CE354: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x806CE358: c.lt.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl < ctx->f8.fl;
    // 0x806CE35C: nop

    // 0x806CE360: bc1fl       L_806CE370
    if (!c1cs) {
        // 0x806CE364: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806CE370;
    }
    goto skip_3;
    // 0x806CE364: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_3:
    // 0x806CE368: mov.s       $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = ctx->f8.fl;
L_806CE36C:
    // 0x806CE36C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_806CE370:
    // 0x806CE370: slt         $at, $s5, $s2
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x806CE374: bne         $at, $zero, L_806CE290
    if (ctx->r1 != 0) {
        // 0x806CE378: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_806CE290;
    }
    // 0x806CE378: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x806CE37C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_806CE380:
    // 0x806CE380: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x806CE384: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806CE388: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x806CE38C: addiu       $s2, $s7, 0x1
    ctx->r18 = ADD32(ctx->r23, 0X1);
    // 0x806CE390: addu        $t8, $s7, $t7
    ctx->r24 = ADD32(ctx->r23, ctx->r15);
    // 0x806CE394: slt         $at, $t8, $s2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x806CE398: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x806CE39C: bne         $at, $zero, L_806CE49C
    if (ctx->r1 != 0) {
        // 0x806CE3A0: lwc1        $f26, 0xD4($sp)
        ctx->f26.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_806CE49C;
    }
    // 0x806CE3A0: lwc1        $f26, 0xD4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x806CE3A4: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x806CE3A8: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x806CE3AC: addu        $s5, $t0, $t1
    ctx->r21 = ADD32(ctx->r8, ctx->r9);
L_806CE3B0:
    // 0x806CE3B0: slti        $at, $s2, 0x3B
    ctx->r1 = SIGNED(ctx->r18) < 0X3B ? 1 : 0;
    // 0x806CE3B4: beql        $at, $zero, L_806CE490
    if (ctx->r1 == 0) {
        // 0x806CE3B8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806CE490;
    }
    goto skip_4;
    // 0x806CE3B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x806CE3BC: bltz        $s2, L_806CE48C
    if (SIGNED(ctx->r18) < 0) {
        // 0x806CE3C0: sll         $t2, $s2, 2
        ctx->r10 = S32(ctx->r18 << 2);
            goto L_806CE48C;
    }
    // 0x806CE3C0: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x806CE3C4: sll         $t9, $s2, 3
    ctx->r25 = S32(ctx->r18 << 3);
    // 0x806CE3C8: addu        $s0, $s3, $t9
    ctx->r16 = ADD32(ctx->r19, ctx->r25);
    // 0x806CE3CC: addu        $s1, $s3, $t2
    ctx->r17 = ADD32(ctx->r19, ctx->r10);
    // 0x806CE3D0: lwc1        $f10, 0x590($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X590);
    // 0x806CE3D4: lwc1        $f18, 0x67C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X67C);
    // 0x806CE3D8: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x806CE3DC: lwc1        $f4, 0x85C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE3E0: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x806CE3E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806CE3E8: mul.s       $f20, $f4, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x806CE3EC: nop

    // 0x806CE3F0: mul.s       $f12, $f8, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x806CE3F4: jal         0x80066E88
    // 0x806CE3F8: nop

    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x806CE3F8: nop

    after_3:
    // 0x806CE3FC: lwc1        $f2, 0x85C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE400: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x806CE404: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806CE408: mul.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x806CE40C: sub.s       $f18, $f26, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x806CE410: add.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x806CE414: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x806CE418: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806CE41C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x806CE420: nop

    // 0x806CE424: bc1fl       L_806CE490
    if (!c1cs) {
        // 0x806CE428: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806CE490;
    }
    goto skip_5;
    // 0x806CE428: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_5:
    // 0x806CE42C: lwc1        $f10, 0x67C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X67C);
    // 0x806CE430: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x806CE434: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x806CE438: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x806CE43C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x806CE440: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x806CE444: jal         0x806CE084
    // 0x806CE448: nop

    func_806CE084(rdram, ctx);
        goto after_4;
    // 0x806CE448: nop

    after_4:
    // 0x806CE44C: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x806CE450: lwc1        $f4, 0x67C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X67C);
    // 0x806CE454: mul.s       $f6, $f16, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x806CE458: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806CE45C: swc1        $f8, 0x67C($s0)
    MEM_W(0X67C, ctx->r16) = ctx->f8.u32l;
    // 0x806CE460: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x806CE464: lwc1        $f10, 0x590($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X590);
    // 0x806CE468: mul.s       $f16, $f18, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x806CE46C: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806CE470: swc1        $f4, 0x590($s1)
    MEM_W(0X590, ctx->r17) = ctx->f4.u32l;
    // 0x806CE474: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x806CE478: c.lt.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl < ctx->f6.fl;
    // 0x806CE47C: nop

    // 0x806CE480: bc1fl       L_806CE490
    if (!c1cs) {
        // 0x806CE484: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806CE490;
    }
    goto skip_6;
    // 0x806CE484: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x806CE488: mov.s       $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = ctx->f6.fl;
L_806CE48C:
    // 0x806CE48C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_806CE490:
    // 0x806CE490: slt         $at, $s5, $s2
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x806CE494: beq         $at, $zero, L_806CE3B0
    if (ctx->r1 == 0) {
        // 0x806CE498: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_806CE3B0;
    }
    // 0x806CE498: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_806CE49C:
    // 0x806CE49C: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x806CE4A0: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x806CE4A4: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x806CE4A8: mul.s       $f18, $f24, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x806CE4AC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x806CE4B0: jalr        $t9
    // 0x806CE4B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x806CE4B4: nop

    after_5:
    // 0x806CE4B8: b           L_806CE71C
    // 0x806CE4BC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_806CE71C;
    // 0x806CE4BC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x806CE4C0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
L_806CE4C4:
    // 0x806CE4C4: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x806CE4C8: beq         $at, $zero, L_806CE5DC
    if (ctx->r1 == 0) {
        // 0x806CE4CC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_806CE5DC;
    }
    // 0x806CE4CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x806CE4D0: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x806CE4D4: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x806CE4D8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806CE4DC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x806CE4E0: lwc1        $f26, 0xD4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x806CE4E4: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x806CE4E8: subu        $s5, $t6, $t7
    ctx->r21 = SUB32(ctx->r14, ctx->r15);
L_806CE4EC:
    // 0x806CE4EC: slti        $at, $s2, 0x3B
    ctx->r1 = SIGNED(ctx->r18) < 0X3B ? 1 : 0;
    // 0x806CE4F0: beql        $at, $zero, L_806CE5CC
    if (ctx->r1 == 0) {
        // 0x806CE4F4: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806CE5CC;
    }
    goto skip_7;
    // 0x806CE4F4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_7:
    // 0x806CE4F8: bltz        $s2, L_806CE5C8
    if (SIGNED(ctx->r18) < 0) {
        // 0x806CE4FC: sll         $t8, $s2, 2
        ctx->r24 = S32(ctx->r18 << 2);
            goto L_806CE5C8;
    }
    // 0x806CE4FC: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x806CE500: sll         $t1, $s2, 3
    ctx->r9 = S32(ctx->r18 << 3);
    // 0x806CE504: addu        $s0, $s3, $t1
    ctx->r16 = ADD32(ctx->r19, ctx->r9);
    // 0x806CE508: addu        $s1, $s3, $t8
    ctx->r17 = ADD32(ctx->r19, ctx->r24);
    // 0x806CE50C: lwc1        $f10, 0x590($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X590);
    // 0x806CE510: lwc1        $f16, 0x680($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X680);
    // 0x806CE514: mtc1        $s4, $f8
    ctx->f8.u32l = ctx->r20;
    // 0x806CE518: lwc1        $f6, 0x85C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE51C: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806CE520: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806CE524: mul.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x806CE528: nop

    // 0x806CE52C: mul.s       $f12, $f18, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x806CE530: jal         0x80066E88
    // 0x806CE534: nop

    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x806CE534: nop

    after_6:
    // 0x806CE538: lwc1        $f2, 0x85C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE53C: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x806CE540: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806CE544: mul.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x806CE548: sub.s       $f16, $f26, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x806CE54C: sub.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x806CE550: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x806CE554: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x806CE558: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x806CE55C: nop

    // 0x806CE560: bc1fl       L_806CE5CC
    if (!c1cs) {
        // 0x806CE564: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806CE5CC;
    }
    goto skip_8;
    // 0x806CE564: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_8:
    // 0x806CE568: lwc1        $f10, 0x680($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X680);
    // 0x806CE56C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x806CE570: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x806CE574: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x806CE578: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x806CE57C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x806CE580: jal         0x806CE084
    // 0x806CE584: nop

    func_806CE084(rdram, ctx);
        goto after_7;
    // 0x806CE584: nop

    after_7:
    // 0x806CE588: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x806CE58C: lwc1        $f6, 0x680($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X680);
    // 0x806CE590: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x806CE594: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806CE598: swc1        $f18, 0x680($s0)
    MEM_W(0X680, ctx->r16) = ctx->f18.u32l;
    // 0x806CE59C: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x806CE5A0: lwc1        $f10, 0x590($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X590);
    // 0x806CE5A4: mul.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x806CE5A8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x806CE5AC: swc1        $f6, 0x590($s1)
    MEM_W(0X590, ctx->r17) = ctx->f6.u32l;
    // 0x806CE5B0: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x806CE5B4: c.lt.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl < ctx->f8.fl;
    // 0x806CE5B8: nop

    // 0x806CE5BC: bc1fl       L_806CE5CC
    if (!c1cs) {
        // 0x806CE5C0: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806CE5CC;
    }
    goto skip_9;
    // 0x806CE5C0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_9:
    // 0x806CE5C4: mov.s       $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = ctx->f8.fl;
L_806CE5C8:
    // 0x806CE5C8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_806CE5CC:
    // 0x806CE5CC: slt         $at, $s5, $s2
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x806CE5D0: bne         $at, $zero, L_806CE4EC
    if (ctx->r1 != 0) {
        // 0x806CE5D4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_806CE4EC;
    }
    // 0x806CE5D4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x806CE5D8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_806CE5DC:
    // 0x806CE5DC: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x806CE5E0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806CE5E4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x806CE5E8: addiu       $s2, $s7, 0x1
    ctx->r18 = ADD32(ctx->r23, 0X1);
    // 0x806CE5EC: addu        $t3, $s7, $t2
    ctx->r11 = ADD32(ctx->r23, ctx->r10);
    // 0x806CE5F0: slt         $at, $t3, $s2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x806CE5F4: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x806CE5F8: bne         $at, $zero, L_806CE6F8
    if (ctx->r1 != 0) {
        // 0x806CE5FC: lwc1        $f26, 0xD4($sp)
        ctx->f26.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_806CE6F8;
    }
    // 0x806CE5FC: lwc1        $f26, 0xD4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x806CE600: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x806CE604: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x806CE608: addu        $s5, $t9, $t4
    ctx->r21 = ADD32(ctx->r25, ctx->r12);
L_806CE60C:
    // 0x806CE60C: slti        $at, $s2, 0x3B
    ctx->r1 = SIGNED(ctx->r18) < 0X3B ? 1 : 0;
    // 0x806CE610: beql        $at, $zero, L_806CE6EC
    if (ctx->r1 == 0) {
        // 0x806CE614: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806CE6EC;
    }
    goto skip_10;
    // 0x806CE614: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_10:
    // 0x806CE618: bltz        $s2, L_806CE6E8
    if (SIGNED(ctx->r18) < 0) {
        // 0x806CE61C: sll         $t5, $s2, 2
        ctx->r13 = S32(ctx->r18 << 2);
            goto L_806CE6E8;
    }
    // 0x806CE61C: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x806CE620: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x806CE624: addu        $s0, $s3, $t7
    ctx->r16 = ADD32(ctx->r19, ctx->r15);
    // 0x806CE628: addu        $s1, $s3, $t5
    ctx->r17 = ADD32(ctx->r19, ctx->r13);
    // 0x806CE62C: lwc1        $f18, 0x590($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X590);
    // 0x806CE630: lwc1        $f16, 0x680($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X680);
    // 0x806CE634: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x806CE638: lwc1        $f4, 0x85C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE63C: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x806CE640: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806CE644: mul.s       $f20, $f4, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x806CE648: nop

    // 0x806CE64C: mul.s       $f12, $f8, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x806CE650: jal         0x80066E88
    // 0x806CE654: nop

    func_80066E88(rdram, ctx);
        goto after_8;
    // 0x806CE654: nop

    after_8:
    // 0x806CE658: lwc1        $f2, 0x85C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X85C);
    // 0x806CE65C: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x806CE660: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806CE664: mul.s       $f18, $f28, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x806CE668: sub.s       $f16, $f26, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f26.fl - ctx->f18.fl;
    // 0x806CE66C: sub.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x806CE670: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x806CE674: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806CE678: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x806CE67C: nop

    // 0x806CE680: bc1fl       L_806CE6EC
    if (!c1cs) {
        // 0x806CE684: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806CE6EC;
    }
    goto skip_11;
    // 0x806CE684: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_11:
    // 0x806CE688: lwc1        $f18, 0x680($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X680);
    // 0x806CE68C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x806CE690: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x806CE694: mul.s       $f16, $f2, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x806CE698: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x806CE69C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x806CE6A0: jal         0x806CE084
    // 0x806CE6A4: nop

    func_806CE084(rdram, ctx);
        goto after_9;
    // 0x806CE6A4: nop

    after_9:
    // 0x806CE6A8: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x806CE6AC: lwc1        $f4, 0x680($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X680);
    // 0x806CE6B0: mul.s       $f6, $f10, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x806CE6B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806CE6B8: swc1        $f8, 0x680($s0)
    MEM_W(0X680, ctx->r16) = ctx->f8.u32l;
    // 0x806CE6BC: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x806CE6C0: lwc1        $f18, 0x590($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X590);
    // 0x806CE6C4: mul.s       $f10, $f16, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x806CE6C8: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x806CE6CC: swc1        $f4, 0x590($s1)
    MEM_W(0X590, ctx->r17) = ctx->f4.u32l;
    // 0x806CE6D0: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x806CE6D4: c.lt.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl < ctx->f6.fl;
    // 0x806CE6D8: nop

    // 0x806CE6DC: bc1fl       L_806CE6EC
    if (!c1cs) {
        // 0x806CE6E0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806CE6EC;
    }
    goto skip_12;
    // 0x806CE6E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_12:
    // 0x806CE6E4: mov.s       $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = ctx->f6.fl;
L_806CE6E8:
    // 0x806CE6E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_806CE6EC:
    // 0x806CE6EC: slt         $at, $s5, $s2
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x806CE6F0: beq         $at, $zero, L_806CE60C
    if (ctx->r1 == 0) {
        // 0x806CE6F4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_806CE60C;
    }
    // 0x806CE6F4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_806CE6F8:
    // 0x806CE6F8: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x806CE6FC: neg.s       $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = -ctx->f24.fl;
    // 0x806CE700: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x806CE704: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x806CE708: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x806CE70C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x806CE710: jalr        $t9
    // 0x806CE714: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x806CE714: nop

    after_10:
L_806CE718:
    // 0x806CE718: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_806CE71C:
    // 0x806CE71C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x806CE720: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x806CE724: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x806CE728: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x806CE72C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x806CE730: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x806CE734: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x806CE738: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x806CE73C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x806CE740: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x806CE744: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x806CE748: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x806CE74C: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x806CE750: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x806CE754: jr          $ra
    // 0x806CE758: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x806CE758: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8079145C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079145C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80791460: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80791464: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80791468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079146C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80791470: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80791474: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x80791478: jal         0x80047AB8
    // 0x8079147C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8079147C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x80791480: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80791484: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80791488: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8079148C: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80791490: addiu       $v1, $a1, 0xC4
    ctx->r3 = ADD32(ctx->r5, 0XC4);
    // 0x80791494: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80791498: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8079149C: lwc1        $f6, 0x70($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X70);
    // 0x807914A0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x807914A4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807914A8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x807914AC: lw          $t6, 0x68($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X68);
    // 0x807914B0: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807914B4: beql        $t6, $zero, L_807914DC
    if (ctx->r14 == 0) {
        // 0x807914B8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_807914DC;
    }
    goto skip_0;
    // 0x807914B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x807914BC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807914C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807914C4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x807914C8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807914CC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x807914D0: b           L_807914EC
    // 0x807914D4: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
        goto L_807914EC;
    // 0x807914D4: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x807914D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_807914DC:
    // 0x807914DC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x807914E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807914E4: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x807914E8: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
L_807914EC:
    // 0x807914EC: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x807914F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807914F4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x807914F8: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x807914FC: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80791500: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80791504: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80791508: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8079150C: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x80791510: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80791514: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80791518: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8079151C: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80791520: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80791524: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x80791528: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8079152C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80791530: jalr        $t9
    // 0x80791534: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80791534: nop

    after_1:
    // 0x80791538: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8079153C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80791540: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80791544: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AC8) << 16);
    // 0x80791548: lwc1        $f18, 0x7E18($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AC8));
    // 0x8079154C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80791550: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80791554: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80791558: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8079155C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80791560: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80791564: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80791568: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8079156C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80791570: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80791574: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80791578: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8079157C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80791580: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    // 0x80791584: jal         0x80790A58
    // 0x80791588: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80790A58(rdram, ctx);
        goto after_2;
    // 0x80791588: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8079158C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80791590: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80791594: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x80791598: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8079159C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x807915A0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x807915A4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x807915A8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x807915AC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x807915B0: jalr        $t9
    // 0x807915B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x807915B4: nop

    after_3:
    // 0x807915B8: beq         $v0, $zero, L_807915C8
    if (ctx->r2 == 0) {
        // 0x807915BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_807915C8;
    }
    // 0x807915BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807915C0: jal         0x80790774
    // 0x807915C4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80790774(rdram, ctx);
        goto after_4;
    // 0x807915C4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_4:
L_807915C8:
    // 0x807915C8: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x807915CC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807915D0: sb          $t2, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r10;
    // 0x807915D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807915D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807915DC: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x807915E0: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x807915E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807915E8: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x807915EC: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
    // 0x807915F0: jr          $ra
    // 0x807915F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x807915F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8049F7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F7D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8049F7DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049F7E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8049F7E4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8049F7E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8049F7EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8049F7F0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8049F7F4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8049F7F8: jal         0x80056934
    // 0x8049F7FC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_80056934(rdram, ctx);
        goto after_0;
    // 0x8049F7FC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x8049F800: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F804: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8049F808: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8049F80C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8049F810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8049F814: jr          $ra
    // 0x8049F818: nop

    return;
    // 0x8049F818: nop

;}
RECOMP_FUNC void func_8064C130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C138: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C13C: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C140: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x8064C144: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064C14C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C150: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064C154: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8064C158: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064C15C: nop

    // 0x8064C160: bc1fl       L_8064C174
    if (!c1cs) {
        // 0x8064C164: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C174;
    }
    goto skip_0;
    // 0x8064C164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C168: jal         0x8064C5D8
    // 0x8064C16C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064C5D8(rdram, ctx);
        goto after_0;
    // 0x8064C16C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064C170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C174:
    // 0x8064C174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C178: jr          $ra
    // 0x8064C17C: nop

    return;
    // 0x8064C17C: nop

;}
RECOMP_FUNC void func_8079A038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079A03C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079A040: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8079A044: slti        $at, $v0, 0x471D
    ctx->r1 = SIGNED(ctx->r2) < 0X471D ? 1 : 0;
    // 0x8079A048: bne         $at, $zero, L_8079A068
    if (ctx->r1 != 0) {
        // 0x8079A04C: addiu       $at, $zero, 0x471D
        ctx->r1 = ADD32(0, 0X471D);
            goto L_8079A068;
    }
    // 0x8079A04C: addiu       $at, $zero, 0x471D
    ctx->r1 = ADD32(0, 0X471D);
    // 0x8079A050: beq         $v0, $at, L_8079A114
    if (ctx->r2 == ctx->r1) {
        // 0x8079A054: addiu       $at, $zero, 0x471E
        ctx->r1 = ADD32(0, 0X471E);
            goto L_8079A114;
    }
    // 0x8079A054: addiu       $at, $zero, 0x471E
    ctx->r1 = ADD32(0, 0X471E);
    // 0x8079A058: beq         $v0, $at, L_8079A124
    if (ctx->r2 == ctx->r1) {
        // 0x8079A05C: nop
    
            goto L_8079A124;
    }
    // 0x8079A05C: nop

    // 0x8079A060: b           L_8079A150
    // 0x8079A064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A068:
    // 0x8079A068: slti        $at, $v0, 0x46E2
    ctx->r1 = SIGNED(ctx->r2) < 0X46E2 ? 1 : 0;
    // 0x8079A06C: bne         $at, $zero, L_8079A084
    if (ctx->r1 != 0) {
        // 0x8079A070: addiu       $at, $zero, 0x471C
        ctx->r1 = ADD32(0, 0X471C);
            goto L_8079A084;
    }
    // 0x8079A070: addiu       $at, $zero, 0x471C
    ctx->r1 = ADD32(0, 0X471C);
    // 0x8079A074: beq         $v0, $at, L_8079A104
    if (ctx->r2 == ctx->r1) {
        // 0x8079A078: nop
    
            goto L_8079A104;
    }
    // 0x8079A078: nop

    // 0x8079A07C: b           L_8079A150
    // 0x8079A080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A084:
    // 0x8079A084: slti        $at, $v0, 0x46B9
    ctx->r1 = SIGNED(ctx->r2) < 0X46B9 ? 1 : 0;
    // 0x8079A088: bne         $at, $zero, L_8079A0A4
    if (ctx->r1 != 0) {
        // 0x8079A08C: addiu       $t6, $v0, -0x46B4
        ctx->r14 = ADD32(ctx->r2, -0X46B4);
            goto L_8079A0A4;
    }
    // 0x8079A08C: addiu       $t6, $v0, -0x46B4
    ctx->r14 = ADD32(ctx->r2, -0X46B4);
    // 0x8079A090: addiu       $at, $zero, 0x46E1
    ctx->r1 = ADD32(0, 0X46E1);
    // 0x8079A094: beq         $v0, $at, L_8079A144
    if (ctx->r2 == ctx->r1) {
        // 0x8079A098: nop
    
            goto L_8079A144;
    }
    // 0x8079A098: nop

    // 0x8079A09C: b           L_8079A150
    // 0x8079A0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A0A4:
    // 0x8079A0A4: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8079A0A8: beq         $at, $zero, L_8079A14C
    if (ctx->r1 == 0) {
        // 0x8079A0AC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8079A14C;
    }
    // 0x8079A0AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8079A0B0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2680) << 16);
    // 0x8079A0B4: addu        $at, $at, $t6
    gpr jr_addend_8079A0BC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8079A0B8: lw          $t6, -0x4E60($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(826, 0X2680));
    // 0x8079A0BC: jr          $t6
    // 0x8079A0C0: nop

    switch (jr_addend_8079A0BC >> 2) {
        case 0: goto L_8079A0C4; break;
        case 1: goto L_8079A0E4; break;
        case 2: goto L_8079A0D4; break;
        case 3: goto L_8079A0F4; break;
        case 4: goto L_8079A134; break;
        default: switch_error(__func__, 0x8079A0BC, 0x8079B1A0);
    }
    // 0x8079A0C0: nop

L_8079A0C4:
    // 0x8079A0C4: jal         0x80799DF0
    // 0x8079A0C8: addiu       $a1, $zero, 0x4034
    ctx->r5 = ADD32(0, 0X4034);
    func_80799DF0(rdram, ctx);
        goto after_0;
    // 0x8079A0C8: addiu       $a1, $zero, 0x4034
    ctx->r5 = ADD32(0, 0X4034);
    after_0:
    // 0x8079A0CC: b           L_8079A150
    // 0x8079A0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A0D4:
    // 0x8079A0D4: jal         0x80799DF0
    // 0x8079A0D8: addiu       $a1, $zero, 0x4035
    ctx->r5 = ADD32(0, 0X4035);
    func_80799DF0(rdram, ctx);
        goto after_1;
    // 0x8079A0D8: addiu       $a1, $zero, 0x4035
    ctx->r5 = ADD32(0, 0X4035);
    after_1:
    // 0x8079A0DC: b           L_8079A150
    // 0x8079A0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A0E4:
    // 0x8079A0E4: jal         0x80799F74
    // 0x8079A0E8: nop

    func_80799F74(rdram, ctx);
        goto after_2;
    // 0x8079A0E8: nop

    after_2:
    // 0x8079A0EC: b           L_8079A150
    // 0x8079A0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A0F4:
    // 0x8079A0F4: jal         0x80799EBC
    // 0x8079A0F8: addiu       $a1, $zero, 0x4507
    ctx->r5 = ADD32(0, 0X4507);
    func_80799EBC(rdram, ctx);
        goto after_3;
    // 0x8079A0F8: addiu       $a1, $zero, 0x4507
    ctx->r5 = ADD32(0, 0X4507);
    after_3:
    // 0x8079A0FC: b           L_8079A150
    // 0x8079A100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A104:
    // 0x8079A104: jal         0x80799EBC
    // 0x8079A108: addiu       $a1, $zero, 0x4508
    ctx->r5 = ADD32(0, 0X4508);
    func_80799EBC(rdram, ctx);
        goto after_4;
    // 0x8079A108: addiu       $a1, $zero, 0x4508
    ctx->r5 = ADD32(0, 0X4508);
    after_4:
    // 0x8079A10C: b           L_8079A150
    // 0x8079A110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A114:
    // 0x8079A114: jal         0x80799EBC
    // 0x8079A118: addiu       $a1, $zero, 0x4509
    ctx->r5 = ADD32(0, 0X4509);
    func_80799EBC(rdram, ctx);
        goto after_5;
    // 0x8079A118: addiu       $a1, $zero, 0x4509
    ctx->r5 = ADD32(0, 0X4509);
    after_5:
    // 0x8079A11C: b           L_8079A150
    // 0x8079A120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A124:
    // 0x8079A124: jal         0x80799EBC
    // 0x8079A128: addiu       $a1, $zero, 0x450A
    ctx->r5 = ADD32(0, 0X450A);
    func_80799EBC(rdram, ctx);
        goto after_6;
    // 0x8079A128: addiu       $a1, $zero, 0x450A
    ctx->r5 = ADD32(0, 0X450A);
    after_6:
    // 0x8079A12C: b           L_8079A150
    // 0x8079A130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A134:
    // 0x8079A134: jal         0x80799F20
    // 0x8079A138: nop

    func_80799F20(rdram, ctx);
        goto after_7;
    // 0x8079A138: nop

    after_7:
    // 0x8079A13C: b           L_8079A150
    // 0x8079A140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A150;
    // 0x8079A140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A144:
    // 0x8079A144: jal         0x80799FB0
    // 0x8079A148: nop

    func_80799FB0(rdram, ctx);
        goto after_8;
    // 0x8079A148: nop

    after_8:
L_8079A14C:
    // 0x8079A14C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A150:
    // 0x8079A150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079A154: jr          $ra
    // 0x8079A158: nop

    return;
    // 0x8079A158: nop

;}
RECOMP_FUNC void func_8043C370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043C370: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8043C374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043C378: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x8043C37C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8043C380: lw          $t4, 0x1F4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043C384: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8043C388: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x8043C38C: lw          $a2, -0x7CE8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CE8);
    // 0x8043C390: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x8043C394: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043C398: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x8043C39C: sw          $t4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r12;
    // 0x8043C3A0: jal         0x80066DE4
    // 0x8043C3A4: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8043C3A4: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8043C3A8: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x8043C3AC: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x8043C3B0: jal         0x80066E88
    // 0x8043C3B4: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8043C3B4: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    after_1:
    // 0x8043C3B8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8043C3BC: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x8043C3C0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8043C3C4: lwc1        $f4, 0x30($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X30);
    // 0x8043C3C8: lwc1        $f6, 0x328($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X328);
    // 0x8043C3CC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8043C3D0: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x8043C3D4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043C3D8: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x8043C3DC: lwc1        $f6, 0x32C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X32C);
    // 0x8043C3E0: addiu       $v1, $sp, 0x48
    ctx->r3 = ADD32(ctx->r29, 0X48);
    // 0x8043C3E4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8043C3E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043C3EC: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8043C3F0: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x8043C3F4: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8043C3F8: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8043C3FC: lwc1        $f10, 0x944($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X944);
    // 0x8043C400: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8043C404: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x8043C408: lwc1        $f10, 0x30($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X30);
    // 0x8043C40C: lwc1        $f8, 0x328($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X328);
    // 0x8043C410: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8043C414: lwc1        $f8, 0x34($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X34);
    // 0x8043C418: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8043C41C: lwc1        $f6, 0x32C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X32C);
    // 0x8043C420: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8043C424: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8043C428: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8043C42C: lwc1        $f10, 0x948($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X948);
    // 0x8043C430: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8043C434: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8043C438: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043C43C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8043C440: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8043C444: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8043C448: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    // 0x8043C44C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043C450: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8043C454: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8043C458: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8043C45C: sub.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8043C460: add.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8043C464: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8043C468: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8043C46C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x8043C470: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8043C474: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8043C478: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8043C47C: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x8043C480: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043C484: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8043C488: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8043C48C: mul.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8043C490: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8043C494: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x8043C498: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(89, 0X133C) << 16);
    // 0x8043C49C: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8043C4A0: lwc1        $f2, -0x3084($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(89, 0X133C));
    // 0x8043C4A4: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(89, 0X1340) << 16);
    // 0x8043C4A8: lwc1        $f0, -0x3080($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(89, 0X1340));
    // 0x8043C4AC: add.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8043C4B0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8043C4B4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8043C4B8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8043C4BC: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8043C4C0: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8043C4C4: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x8043C4C8: sub.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8043C4CC: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8043C4D0: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8043C4D4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8043C4D8: add.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8043C4DC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x8043C4E0: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8043C4E4: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043C4E8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8043C4EC: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8043C4F0: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8043C4F4: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8043C4F8: beq         $at, $zero, L_8043C548
    if (ctx->r1 == 0) {
        // 0x8043C4FC: trunc.w.s   $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
            goto L_8043C548;
    }
    // 0x8043C4FC: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
L_8043C500:
    // 0x8043C500: mul.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8043C504: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8043C508: lw          $t6, 0x31C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X31C);
    // 0x8043C50C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043C510: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8043C514: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8043C518: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8043C51C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8043C520: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8043C524: lw          $t6, 0x320($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X320);
    // 0x8043C528: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8043C52C: mfc1        $t9, $f14
    ctx->r25 = (int32_t)ctx->f14.u32l;
    // 0x8043C530: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8043C534: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8043C538: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8043C53C: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8043C540: bne         $at, $zero, L_8043C500
    if (ctx->r1 != 0) {
        // 0x8043C544: sw          $t7, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r15;
            goto L_8043C500;
    }
    // 0x8043C544: sw          $t7, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r15;
L_8043C548:
    // 0x8043C548: mul.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8043C54C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8043C550: lw          $t6, 0x31C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X31C);
    // 0x8043C554: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8043C558: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8043C55C: sw          $t7, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r15;
    // 0x8043C560: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8043C564: lw          $t6, 0x320($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X320);
    // 0x8043C568: mfc1        $t9, $f14
    ctx->r25 = (int32_t)ctx->f14.u32l;
    // 0x8043C56C: nop

    // 0x8043C570: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8043C574: sw          $t7, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r15;
    // 0x8043C578: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8043C57C: addiu       $v1, $sp, 0x50
    ctx->r3 = ADD32(ctx->r29, 0X50);
    // 0x8043C580: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x8043C584: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8043C588: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8043C58C:
    // 0x8043C58C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8043C590: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8043C594: beql        $at, $zero, L_8043C5A4
    if (ctx->r1 == 0) {
        // 0x8043C598: slt         $at, $v0, $t1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8043C5A4;
    }
    goto skip_0;
    // 0x8043C598: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    skip_0:
    // 0x8043C59C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8043C5A0: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
L_8043C5A4:
    // 0x8043C5A4: beql        $at, $zero, L_8043C5B4
    if (ctx->r1 == 0) {
        // 0x8043C5A8: sltu        $at, $v1, $a0
        ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
            goto L_8043C5B4;
    }
    goto skip_1;
    // 0x8043C5A8: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    skip_1:
    // 0x8043C5AC: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8043C5B0: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
L_8043C5B4:
    // 0x8043C5B4: bnel        $at, $zero, L_8043C58C
    if (ctx->r1 != 0) {
        // 0x8043C5B8: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_8043C58C;
    }
    goto skip_2;
    // 0x8043C5B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x8043C5BC: blez        $t1, L_8043C62C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8043C5C0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8043C62C;
    }
    // 0x8043C5C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8043C5C4: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8043C5C8: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8043C5CC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8043C5D0: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8043C5D4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8043C5D8: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8043C5DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8043C5E0: addu        $a2, $t4, $t8
    ctx->r6 = ADD32(ctx->r12, ctx->r24);
    // 0x8043C5E4: addiu       $t0, $a2, 0x2C
    ctx->r8 = ADD32(ctx->r6, 0X2C);
    // 0x8043C5E8: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8043C5EC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8043C5F0: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
L_8043C5F4:
    // 0x8043C5F4: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x8043C5F8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8043C5FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8043C600:
    // 0x8043C600: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8043C604: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    // 0x8043C608: sw          $a0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r4;
    // 0x8043C60C: sw          $a0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r4;
    // 0x8043C610: addiu       $v0, $v0, 0xB0
    ctx->r2 = ADD32(ctx->r2, 0XB0);
    // 0x8043C614: bne         $v1, $a1, L_8043C600
    if (ctx->r3 != ctx->r5) {
        // 0x8043C618: sw          $a0, -0xB0($v0)
        MEM_W(-0XB0, ctx->r2) = ctx->r4;
            goto L_8043C600;
    }
    // 0x8043C618: sw          $a0, -0xB0($v0)
    MEM_W(-0XB0, ctx->r2) = ctx->r4;
    // 0x8043C61C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8043C620: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8043C624: bne         $a3, $t3, L_8043C5F4
    if (ctx->r7 != ctx->r11) {
        // 0x8043C628: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8043C5F4;
    }
    // 0x8043C628: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8043C62C:
    // 0x8043C62C: addiu       $v0, $t2, 0x1
    ctx->r2 = ADD32(ctx->r10, 0X1);
    // 0x8043C630: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8043C634: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x8043C638: beq         $at, $zero, L_8043C6A8
    if (ctx->r1 == 0) {
        // 0x8043C63C: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_8043C6A8;
    }
    // 0x8043C63C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8043C640: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8043C644: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x8043C648: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8043C64C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8043C650: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043C654: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x8043C658: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043C65C: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8043C660: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x8043C664: addu        $a2, $t6, $a3
    ctx->r6 = ADD32(ctx->r14, ctx->r7);
    // 0x8043C668: addiu       $t0, $a2, 0x2C
    ctx->r8 = ADD32(ctx->r6, 0X2C);
    // 0x8043C66C: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
L_8043C670:
    // 0x8043C670: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x8043C674: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8043C678: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8043C67C:
    // 0x8043C67C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8043C680: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    // 0x8043C684: sw          $a0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r4;
    // 0x8043C688: sw          $a0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r4;
    // 0x8043C68C: addiu       $v0, $v0, 0xB0
    ctx->r2 = ADD32(ctx->r2, 0XB0);
    // 0x8043C690: bne         $v1, $a1, L_8043C67C
    if (ctx->r3 != ctx->r5) {
        // 0x8043C694: sw          $a0, -0xB0($v0)
        MEM_W(-0XB0, ctx->r2) = ctx->r4;
            goto L_8043C67C;
    }
    // 0x8043C694: sw          $a0, -0xB0($v0)
    MEM_W(-0XB0, ctx->r2) = ctx->r4;
    // 0x8043C698: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8043C69C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8043C6A0: bne         $a3, $t1, L_8043C670
    if (ctx->r7 != ctx->r9) {
        // 0x8043C6A4: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8043C670;
    }
    // 0x8043C6A4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8043C6A8:
    // 0x8043C6A8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8043C6AC: addiu       $v1, $sp, 0x50
    ctx->r3 = ADD32(ctx->r29, 0X50);
    // 0x8043C6B0: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8043C6B4: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8043C6B8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_8043C6BC:
    // 0x8043C6BC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8043C6C0: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8043C6C4: beql        $at, $zero, L_8043C6D4
    if (ctx->r1 == 0) {
        // 0x8043C6C8: slt         $at, $v0, $t1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8043C6D4;
    }
    goto skip_3;
    // 0x8043C6C8: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    skip_3:
    // 0x8043C6CC: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8043C6D0: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
L_8043C6D4:
    // 0x8043C6D4: beql        $at, $zero, L_8043C6E4
    if (ctx->r1 == 0) {
        // 0x8043C6D8: sltu        $at, $v1, $a1
        ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
            goto L_8043C6E4;
    }
    goto skip_4;
    // 0x8043C6D8: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    skip_4:
    // 0x8043C6DC: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8043C6E0: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
L_8043C6E4:
    // 0x8043C6E4: bnel        $at, $zero, L_8043C6BC
    if (ctx->r1 != 0) {
        // 0x8043C6E8: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_8043C6BC;
    }
    goto skip_5;
    // 0x8043C6E8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_5:
    // 0x8043C6EC: blez        $t1, L_8043C774
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8043C6F0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8043C774;
    }
    // 0x8043C6F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8043C6F4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8043C6F8: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8043C6FC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8043C700: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8043C704: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8043C708: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8043C70C: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8043C710: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8043C714: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8043C718: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8043C71C: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8043C720: addu        $a2, $t4, $t7
    ctx->r6 = ADD32(ctx->r12, ctx->r15);
    // 0x8043C724: addiu       $t0, $a2, 0x4
    ctx->r8 = ADD32(ctx->r6, 0X4);
    // 0x8043C728: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8043C72C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
L_8043C730:
    // 0x8043C730: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x8043C734: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8043C738: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8043C73C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8043C740: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8043C744: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8043C748:
    // 0x8043C748: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8043C74C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8043C750: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8043C754: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8043C758: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8043C75C: bne         $v1, $a1, L_8043C748
    if (ctx->r3 != ctx->r5) {
        // 0x8043C760: sw          $a0, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r4;
            goto L_8043C748;
    }
    // 0x8043C760: sw          $a0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r4;
    // 0x8043C764: addiu       $a3, $a3, 0x2C
    ctx->r7 = ADD32(ctx->r7, 0X2C);
    // 0x8043C768: addiu       $a2, $a2, 0x2C
    ctx->r6 = ADD32(ctx->r6, 0X2C);
    // 0x8043C76C: bne         $a3, $t3, L_8043C730
    if (ctx->r7 != ctx->r11) {
        // 0x8043C770: addiu       $t0, $t0, 0x2C
        ctx->r8 = ADD32(ctx->r8, 0X2C);
            goto L_8043C730;
    }
    // 0x8043C770: addiu       $t0, $t0, 0x2C
    ctx->r8 = ADD32(ctx->r8, 0X2C);
L_8043C774:
    // 0x8043C774: addiu       $v0, $t2, 0x1
    ctx->r2 = ADD32(ctx->r10, 0X1);
    // 0x8043C778: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8043C77C: beq         $at, $zero, L_8043C808
    if (ctx->r1 == 0) {
        // 0x8043C780: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_8043C808;
    }
    // 0x8043C780: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8043C784: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8043C788: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8043C78C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8043C790: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8043C794: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x8043C798: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x8043C79C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8043C7A0: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8043C7A4: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8043C7A8: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x8043C7AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8043C7B0: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8043C7B4: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8043C7B8: addu        $a2, $t9, $a3
    ctx->r6 = ADD32(ctx->r25, ctx->r7);
    // 0x8043C7BC: addiu       $t0, $a2, 0x4
    ctx->r8 = ADD32(ctx->r6, 0X4);
    // 0x8043C7C0: addiu       $t1, $zero, 0x18C
    ctx->r9 = ADD32(0, 0X18C);
L_8043C7C4:
    // 0x8043C7C4: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x8043C7C8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8043C7CC: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8043C7D0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8043C7D4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8043C7D8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8043C7DC:
    // 0x8043C7DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8043C7E0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8043C7E4: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8043C7E8: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8043C7EC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8043C7F0: bne         $v1, $a1, L_8043C7DC
    if (ctx->r3 != ctx->r5) {
        // 0x8043C7F4: sw          $a0, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r4;
            goto L_8043C7DC;
    }
    // 0x8043C7F4: sw          $a0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r4;
    // 0x8043C7F8: addiu       $a3, $a3, 0x2C
    ctx->r7 = ADD32(ctx->r7, 0X2C);
    // 0x8043C7FC: addiu       $a2, $a2, 0x2C
    ctx->r6 = ADD32(ctx->r6, 0X2C);
    // 0x8043C800: bne         $a3, $t1, L_8043C7C4
    if (ctx->r7 != ctx->r9) {
        // 0x8043C804: addiu       $t0, $t0, 0x2C
        ctx->r8 = ADD32(ctx->r8, 0X2C);
            goto L_8043C7C4;
    }
    // 0x8043C804: addiu       $t0, $t0, 0x2C
    ctx->r8 = ADD32(ctx->r8, 0X2C);
L_8043C808:
    // 0x8043C808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043C80C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x8043C810: jr          $ra
    // 0x8043C814: nop

    return;
    // 0x8043C814: nop

;}
RECOMP_FUNC void func_80425324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80425328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042532C: jal         0x804251D4
    // 0x80425330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804251D4(rdram, ctx);
        goto after_0;
    // 0x80425330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80425334: bne         $v0, $zero, L_8042534C
    if (ctx->r2 != 0) {
        // 0x80425338: lui         $a1, 0x8042
        ctx->r5 = S32(RELOC_HI16(35, 0X3578) << 16);
            goto L_8042534C;
    }
    // 0x80425338: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(35, 0X3578) << 16);
    // 0x8042533C: jal         0x800445A4
    // 0x80425340: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80425340: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80425344: b           L_804253FC
    // 0x80425348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804253FC;
    // 0x80425348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042534C:
    // 0x8042534C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80425350: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(35, 0X35BC) << 16);
    // 0x80425354: addiu       $v0, $a1, 0x5F78
    ctx->r2 = ADD32(ctx->r5, (int16_t)RELOC_LO16(35, 0X3578));
    // 0x80425358: lw          $t0, 0x1F4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X1F4);
    // 0x8042535C: addiu       $t7, $t7, 0x5FBC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(35, 0X35BC));
    // 0x80425360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80425364: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x80425368: sw          $t7, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->r15;
    // 0x8042536C: sw          $v0, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r2;
    // 0x80425370: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x80425374: beq         $a2, $zero, L_804253D8
    if (ctx->r6 == 0) {
        // 0x80425378: addiu       $v1, $t0, 0xA0
        ctx->r3 = ADD32(ctx->r8, 0XA0);
            goto L_804253D8;
    }
    // 0x80425378: addiu       $v1, $t0, 0xA0
    ctx->r3 = ADD32(ctx->r8, 0XA0);
    // 0x8042537C: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x80425380: beq         $a3, $zero, L_804253A8
    if (ctx->r7 == 0) {
        // 0x80425384: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_804253A8;
    }
    // 0x80425384: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80425388:
    // 0x80425388: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042538C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80425390: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80425394: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80425398: bne         $a1, $a0, L_80425388
    if (ctx->r5 != ctx->r4) {
        // 0x8042539C: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_80425388;
    }
    // 0x8042539C: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x804253A0: beql        $a0, $a2, L_804253DC
    if (ctx->r4 == ctx->r6) {
        // 0x804253A4: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_804253DC;
    }
    goto skip_0;
    // 0x804253A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_0:
L_804253A8:
    // 0x804253A8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804253AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804253B0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x804253B4: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x804253B8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804253BC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x804253C0: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x804253C4: lwc1        $f10, -0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X8);
    // 0x804253C8: swc1        $f10, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f10.u32l;
    // 0x804253CC: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x804253D0: bne         $a0, $a2, L_804253A8
    if (ctx->r4 != ctx->r6) {
        // 0x804253D4: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_804253A8;
    }
    // 0x804253D4: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
L_804253D8:
    // 0x804253D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_804253DC:
    // 0x804253DC: sw          $zero, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = 0;
    // 0x804253E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804253E4: swc1        $f18, 0xE4($t0)
    MEM_W(0XE4, ctx->r8) = ctx->f18.u32l;
    // 0x804253E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804253EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804253F0: jal         0x80425408
    // 0x804253F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80425408(rdram, ctx);
        goto after_2;
    // 0x804253F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804253F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804253FC:
    // 0x804253FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80425400: jr          $ra
    // 0x80425404: nop

    return;
    // 0x80425404: nop

;}
RECOMP_FUNC void func_8044DF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044DF2C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8044DF30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044DF34: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8044DF38: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x8044DF3C: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x8044DF40: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044DF44: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044DF48: addu        $v0, $a2, $at
    ctx->r2 = ADD32(ctx->r6, ctx->r1);
    // 0x8044DF4C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8044DF50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044DF54: lwc1        $f6, 0x6F18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6F18);
    // 0x8044DF58: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044DF5C: ori         $at, $at, 0x6F18
    ctx->r1 = ctx->r1 | 0X6F18;
    // 0x8044DF60: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8044DF64: nop

    // 0x8044DF68: bc1fl       L_8044E2C0
    if (!c1cs) {
        // 0x8044DF6C: addu        $v0, $a2, $at
        ctx->r2 = ADD32(ctx->r6, ctx->r1);
            goto L_8044E2C0;
    }
    goto skip_0;
    // 0x8044DF6C: addu        $v0, $a2, $at
    ctx->r2 = ADD32(ctx->r6, ctx->r1);
    skip_0:
    // 0x8044DF70: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1407C) << 16);
    // 0x8044DF74: lwc1        $f10, -0x7BA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1407C));
    // 0x8044DF78: lwc1        $f8, 0x6F1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6F1C);
    // 0x8044DF7C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8044DF80: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8044DF84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8044DF88: swc1        $f4, 0x6F1C($v0)
    MEM_W(0X6F1C, ctx->r2) = ctx->f4.u32l;
    // 0x8044DF8C: lwc1        $f6, 0x6F1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6F1C);
    // 0x8044DF90: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8044DF94: nop

    // 0x8044DF98: bc1fl       L_8044DFB4
    if (!c1cs) {
        // 0x8044DF9C: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8044DFB4;
    }
    goto skip_1;
    // 0x8044DF9C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_1:
    // 0x8044DFA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8044DFA4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044DFA8: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8044DFAC: swc1        $f10, 0x6F1C($at)
    MEM_W(0X6F1C, ctx->r1) = ctx->f10.u32l;
    // 0x8044DFB0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_8044DFB4:
    // 0x8044DFB4: ori         $at, $at, 0x6F1C
    ctx->r1 = ctx->r1 | 0X6F1C;
    // 0x8044DFB8: addu        $v0, $a2, $at
    ctx->r2 = ADD32(ctx->r6, ctx->r1);
    // 0x8044DFBC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8044DFC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044DFC4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8044DFC8: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x8044DFCC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8044DFD0: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8044DFD4: jal         0x80066E88
    // 0x8044DFD8: nop

    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8044DFD8: nop

    after_0:
    // 0x8044DFDC: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
    // 0x8044DFE0: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13BE8) << 16);
    // 0x8044DFE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8044DFE8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8044DFEC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044DFF0: lwc1        $f8, 0x7FC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13BE8));
    // 0x8044DFF4: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13BB8) << 16);
    // 0x8044DFF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044DFFC: lwc1        $f10, 0x7F98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13BB8));
    // 0x8044E000: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8044E004: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8044E008: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8044E00C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8044E010: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x8044E014: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8044E018: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8044E01C: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8044E020: jal         0x80066DE4
    // 0x8044E024: nop

    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8044E024: nop

    after_1:
    // 0x8044E028: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8044E02C: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13C00) << 16);
    // 0x8044E030: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8044E034: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E038: lwc1        $f4, 0x7FE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13C00));
    // 0x8044E03C: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13BD0) << 16);
    // 0x8044E040: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E044: lwc1        $f6, 0x7FB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13BD0));
    // 0x8044E048: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8044E04C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8044E050: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8044E054: jal         0x80066E88
    // 0x8044E058: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8044E058: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x8044E05C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8044E060: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14080) << 16);
    // 0x8044E064: lwc1        $f18, -0x7BA0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14080));
    // 0x8044E068: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13C18) << 16);
    // 0x8044E06C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E070: lwc1        $f6, 0x7FF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13C18));
    // 0x8044E074: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13C30) << 16);
    // 0x8044E078: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E07C: lwc1        $f4, -0x7FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13C30));
    // 0x8044E080: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8044E084: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8044E088: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8044E08C: add.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8044E090: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8044E094: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8044E098: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8044E09C: mul.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8044E0A0: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8044E0A4: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8044E0A8: sub.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8044E0AC: mul.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8044E0B0: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    // 0x8044E0B4: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8044E0B8: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8044E0BC: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x8044E0C0: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8044E0C4: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x8044E0C8: jal         0x80065954
    // 0x8044E0CC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8044E0CC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8044E0D0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14084) << 16);
    // 0x8044E0D4: lwc1        $f2, -0x7B9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14084));
    // 0x8044E0D8: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x8044E0DC: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8044E0E0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8044E0E4: nop

    // 0x8044E0E8: bc1fl       L_8044E11C
    if (!c1cs) {
        // 0x8044E0EC: lwc1        $f12, 0x20($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
            goto L_8044E11C;
    }
    goto skip_2;
    // 0x8044E0EC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x8044E0F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8044E0F4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14088) << 16);
    // 0x8044E0F8: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8044E0FC: nop

    // 0x8044E100: bc1f        L_8044E110
    if (!c1cs) {
        // 0x8044E104: nop
    
            goto L_8044E110;
    }
    // 0x8044E104: nop

    // 0x8044E108: b           L_8044E118
    // 0x8044E10C: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
        goto L_8044E118;
    // 0x8044E10C: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
L_8044E110:
    // 0x8044E110: lwc1        $f4, -0x7B98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14088));
    // 0x8044E114: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
L_8044E118:
    // 0x8044E118: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
L_8044E11C:
    // 0x8044E11C: jal         0x80065954
    // 0x8044E120: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x8044E120: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_4:
    // 0x8044E124: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1408C) << 16);
    // 0x8044E128: lwc1        $f2, -0x7B94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1408C));
    // 0x8044E12C: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x8044E130: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8044E134: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8044E138: nop

    // 0x8044E13C: bc1fl       L_8044E170
    if (!c1cs) {
        // 0x8044E140: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8044E170;
    }
    goto skip_3;
    // 0x8044E140: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8044E144: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8044E148: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14090) << 16);
    // 0x8044E14C: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x8044E150: nop

    // 0x8044E154: bc1f        L_8044E164
    if (!c1cs) {
        // 0x8044E158: nop
    
            goto L_8044E164;
    }
    // 0x8044E158: nop

    // 0x8044E15C: b           L_8044E16C
    // 0x8044E160: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
        goto L_8044E16C;
    // 0x8044E160: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
L_8044E164:
    // 0x8044E164: lwc1        $f8, -0x7B90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14090));
    // 0x8044E168: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
L_8044E16C:
    // 0x8044E16C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
L_8044E170:
    // 0x8044E170: jal         0x80065954
    // 0x8044E174: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x8044E174: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_5:
    // 0x8044E178: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14094) << 16);
    // 0x8044E17C: lwc1        $f2, -0x7B8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14094));
    // 0x8044E180: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x8044E184: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8044E188: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8044E18C: nop

    // 0x8044E190: bc1fl       L_8044E1C4
    if (!c1cs) {
        // 0x8044E194: lwc1        $f8, 0x54($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
            goto L_8044E1C4;
    }
    goto skip_4;
    // 0x8044E194: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    skip_4:
    // 0x8044E198: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8044E19C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14098) << 16);
    // 0x8044E1A0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8044E1A4: nop

    // 0x8044E1A8: bc1f        L_8044E1B8
    if (!c1cs) {
        // 0x8044E1AC: nop
    
            goto L_8044E1B8;
    }
    // 0x8044E1AC: nop

    // 0x8044E1B0: b           L_8044E1C0
    // 0x8044E1B4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
        goto L_8044E1C0;
    // 0x8044E1B4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
L_8044E1B8:
    // 0x8044E1B8: lwc1        $f10, -0x7B88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14098));
    // 0x8044E1BC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_8044E1C0:
    // 0x8044E1C0: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
L_8044E1C4:
    // 0x8044E1C4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044E1C8: ori         $at, $at, 0x6F20
    ctx->r1 = ctx->r1 | 0X6F20;
    // 0x8044E1CC: addu        $v0, $a2, $at
    ctx->r2 = ADD32(ctx->r6, ctx->r1);
    // 0x8044E1D0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8044E1D4: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8044E1D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044E1DC: ori         $at, $at, 0x6F24
    ctx->r1 = ctx->r1 | 0X6F24;
    // 0x8044E1E0: addu        $v1, $a2, $at
    ctx->r3 = ADD32(ctx->r6, ctx->r1);
    // 0x8044E1E4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8044E1E8: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8044E1EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044E1F0: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8044E1F4: swc1        $f6, 0x6F28($at)
    MEM_W(0X6F28, ctx->r1) = ctx->f6.u32l;
    // 0x8044E1F8: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8044E1FC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8044E200: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8044E204: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8044E208: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8044E20C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8044E210: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8044E214: jal         0x80066DE4
    // 0x8044E218: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8044E218: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x8044E21C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8044E220: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8044E224: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8044E228: add.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8044E22C: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8044E230: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8044E234: jal         0x80066E88
    // 0x8044E238: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x8044E238: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8044E23C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8044E240: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8044E244: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8044E248: jal         0x80066DE4
    // 0x8044E24C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x8044E24C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x8044E250: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8044E254: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8044E258: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8044E25C: jal         0x80066E88
    // 0x8044E260: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    func_80066E88(rdram, ctx);
        goto after_9;
    // 0x8044E260: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8044E264: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8044E268: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8044E26C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8044E270: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8044E274: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8044E278: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8044E27C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8044E280: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x8044E284: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044E288: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8044E28C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8044E290: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8044E294: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8044E298: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8044E29C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8044E2A0: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8044E2A4: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8044E2A8: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8044E2AC: jal         0x8006C56C
    // 0x8044E2B0: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    func_8006C56C(rdram, ctx);
        goto after_10;
    // 0x8044E2B0: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x8044E2B4: b           L_8044E2D8
    // 0x8044E2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044E2D8;
    // 0x8044E2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044E2BC: addu        $v0, $a2, $at
    ctx->r2 = ADD32(ctx->r6, ctx->r1);
L_8044E2C0:
    // 0x8044E2C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044E2C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044E2C8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8044E2CC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8044E2D0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8044E2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044E2D8:
    // 0x8044E2D8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8044E2DC: jr          $ra
    // 0x8044E2E0: nop

    return;
    // 0x8044E2E0: nop

;}
RECOMP_FUNC void func_8001C608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C608: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8001C60C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001C610: sltiu       $at, $t7, 0x4
    ctx->r1 = ctx->r15 < 0X4 ? 1 : 0;
    // 0x8001C614: bne         $at, $zero, L_8001C63C
    if (ctx->r1 != 0) {
        // 0x8001C618: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_8001C63C;
    }
    // 0x8001C618: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x8001C61C: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x8001C620: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001C624: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8001C628: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8001C62C: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x8001C630: mfhi        $t1
    ctx->r9 = hi;
    // 0x8001C634: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
    // 0x8001C638: nop

L_8001C63C:
    // 0x8001C63C: lw          $t2, 0x14C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X14C);
    // 0x8001C640: jr          $ra
    // 0x8001C644: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    return;
    // 0x8001C644: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_807A0FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A0FFC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807A1000: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x807A1004: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807A1008: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807A100C: nop

    // 0x807A1010: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x807A1014: nop

    // 0x807A1018: bc1fl       L_807A1048
    if (!c1cs) {
        // 0x807A101C: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_807A1048;
    }
    goto skip_0;
    // 0x807A101C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x807A1020: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A1024: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x807A1028: nop

    // 0x807A102C: bc1f        L_807A1064
    if (!c1cs) {
        // 0x807A1030: nop
    
            goto L_807A1064;
    }
    // 0x807A1030: nop

    // 0x807A1034: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807A1038: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x807A103C: jr          $ra
    // 0x807A1040: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x807A1040: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x807A1044: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_807A1048:
    // 0x807A1048: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807A104C: nop

    // 0x807A1050: bc1f        L_807A1064
    if (!c1cs) {
        // 0x807A1054: nop
    
            goto L_807A1064;
    }
    // 0x807A1054: nop

    // 0x807A1058: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807A105C: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x807A1060: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_807A1064:
    // 0x807A1064: jr          $ra
    // 0x807A1068: nop

    return;
    // 0x807A1068: nop

;}
RECOMP_FUNC void func_8057EAEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057EAEC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8057EAF0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8057EAF4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8057EAF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8057EAFC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8057EB00: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8057EB04: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8057EB08: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8057EB0C: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(393, 0X10B0) << 16);
    // 0x8057EB10: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8057EB14: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8057EB18: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8057EB1C: lw          $t1, -0x1410($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(393, 0X10B0));
    // 0x8057EB20: jr          $ra
    // 0x8057EB24: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8057EB24: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8057EB28: nop

    // 0x8057EB2C: nop

;}
RECOMP_FUNC void func_804D9108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D9108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D910C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804D9110: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804D9114: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804D9118: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804D911C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D9120: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804D9124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804D9128: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804D912C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804D9130: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804D9134: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804D9138: lui         $t1, 0x804E
    ctx->r9 = S32(RELOC_HI16(258, 0XE660) << 16);
    // 0x804D913C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804D9140: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804D9144: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804D9148: lw          $t1, 0x7330($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(258, 0XE660));
    // 0x804D914C: jal         0x804D8EA8
    // 0x804D9150: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804D8EA8(rdram, ctx);
        goto after_0;
    // 0x804D9150: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804D9154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D9158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D915C: jr          $ra
    // 0x804D9160: nop

    return;
    // 0x804D9160: nop

    // 0x804D9164: nop

    // 0x804D9168: nop

    // 0x804D916C: nop

;}
RECOMP_FUNC void func_807BC6DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC6DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC6E4: jal         0x807BC6B4
    // 0x807BC6E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807BC6B4(rdram, ctx);
        goto after_0;
    // 0x807BC6E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BC6EC: jal         0x80045BD8
    // 0x807BC6F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x807BC6F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807BC6F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BC6F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC6FC: jr          $ra
    // 0x807BC700: nop

    return;
    // 0x807BC700: nop

;}
RECOMP_FUNC void func_80032258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003225C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032260: jal         0x800321DC
    // 0x80032264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800321DC(rdram, ctx);
        goto after_0;
    // 0x80032264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80032268: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8003226C: jal         0x8002EED8
    // 0x80032270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002EED8(rdram, ctx);
        goto after_1;
    // 0x80032270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80032274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003227C: jr          $ra
    // 0x80032280: nop

    return;
    // 0x80032280: nop

;}
RECOMP_FUNC void func_80008504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008504: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80008508: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000850C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80008510: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80008514: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80008518: jal         0x8000AC90
    // 0x8000851C: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    func_8000AC90(rdram, ctx);
        goto after_0;
    // 0x8000851C: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80008520: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x80008524: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x80008528: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x8000852C: jal         0x8008AE20
    // 0x80008530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80008530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80008534: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80008538: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8000853C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80008540: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80008544: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80008548: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8000854C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80008550: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80008554: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80008558: addiu       $t0, $t0, -0x7DA4
    ctx->r8 = ADD32(ctx->r8, -0X7DA4);
    // 0x8000855C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80008560: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80008564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008568: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000856C: jal         0x800077AC
    // 0x80008570: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_800077AC(rdram, ctx);
        goto after_2;
    // 0x80008570: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_2:
    // 0x80008574: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80008578: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000857C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80008580: jr          $ra
    // 0x80008584: nop

    return;
    // 0x80008584: nop

;}
RECOMP_FUNC void func_80674304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80674308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067430C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80674310: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80674314: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80674318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8067431C: jal         0x800659EC
    // 0x80674320: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x80674320: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80674324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80674328: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8067432C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80674330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80674334: jr          $ra
    // 0x80674338: nop

    return;
    // 0x80674338: nop

;}
RECOMP_FUNC void func_8002B124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B124: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8002B128: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002B12C: lw          $t7, 0xE94($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE94);
    // 0x8002B130: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002B134: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x8002B138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B13C: addiu       $t6, $zero, 0x4035
    ctx->r14 = ADD32(0, 0X4035);
    // 0x8002B140: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8002B144: lw          $t8, 0xE94($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE94);
    // 0x8002B148: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002B14C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002B150: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002B154: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x8002B158: lw          $t9, 0xE94($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE94);
    // 0x8002B15C: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x8002B160: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002B164: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x8002B168: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8002B16C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B170: lwc1        $f4, -0x17C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X17C);
    // 0x8002B174: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8002B178: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002B17C: lw          $t0, 0xE94($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE94);
    // 0x8002B180: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8002B184: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8002B188: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002B18C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002B190: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8002B194: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x8002B198: jalr        $t9
    // 0x8002B19C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002B19C: nop

    after_0:
    // 0x8002B1A0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8002B1A4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002B1A8: lw          $t1, 0x59C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X59C);
    // 0x8002B1AC: lw          $t5, 0xA68($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XA68);
    // 0x8002B1B0: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002B1B4: lw          $t2, 0x10C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10C);
    // 0x8002B1B8: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x8002B1BC: addiu       $a0, $zero, 0x400F
    ctx->r4 = ADD32(0, 0X400F);
    // 0x8002B1C0: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x8002B1C4: lw          $t9, 0x14($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X14);
    // 0x8002B1C8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8002B1CC: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8002B1D0: lw          $a2, -0x20E8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X20E8);
    // 0x8002B1D4: jalr        $t9
    // 0x8002B1D8: addiu       $a1, $v0, 0x84
    ctx->r5 = ADD32(ctx->r2, 0X84);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002B1D8: addiu       $a1, $v0, 0x84
    ctx->r5 = ADD32(ctx->r2, 0X84);
    after_1:
    // 0x8002B1DC: jal         0x80067E68
    // 0x8002B1E0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80067E68(rdram, ctx);
        goto after_2;
    // 0x8002B1E0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x8002B1E4: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8002B1E8: jal         0x80067818
    // 0x8002B1EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8002B1EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8002B1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B1F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002B1F8: jr          $ra
    // 0x8002B1FC: nop

    return;
    // 0x8002B1FC: nop

;}
RECOMP_FUNC void func_805A7DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7DA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A7DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A7DA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A7DAC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A7DB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7DB4: jal         0x805A7440
    // 0x805A7DB8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_805A7440(rdram, ctx);
        goto after_0;
    // 0x805A7DB8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x805A7DBC: jal         0x800692D4
    // 0x805A7DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800692D4(rdram, ctx);
        goto after_1;
    // 0x805A7DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A7DC4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805A7DC8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A7DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A7DD0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x805A7DD4: beq         $v1, $zero, L_805A7DE4
    if (ctx->r3 == 0) {
        // 0x805A7DD8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_805A7DE4;
    }
    // 0x805A7DD8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x805A7DDC: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x805A7DE0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_805A7DE4:
    // 0x805A7DE4: bne         $v1, $zero, L_805A7E24
    if (ctx->r3 != 0) {
        // 0x805A7DE8: nop
    
            goto L_805A7E24;
    }
    // 0x805A7DE8: nop

    // 0x805A7DEC: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x805A7DF0: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(426, 0X16D8) << 16);
    // 0x805A7DF4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x805A7DF8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x805A7DFC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805A7E00: lh          $t9, -0x75D8($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(426, 0X16D8));
    // 0x805A7E04: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
    // 0x805A7E08: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x805A7E0C: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x805A7E10: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x805A7E14: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x805A7E18: bne         $at, $zero, L_805A7E24
    if (ctx->r1 != 0) {
        // 0x805A7E1C: sw          $t1, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r9;
            goto L_805A7E24;
    }
    // 0x805A7E1C: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x805A7E20: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_805A7E24:
    // 0x805A7E24: jal         0x80048F84
    // 0x805A7E28: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805A7E28: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x805A7E2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A7E30: jal         0x80048F84
    // 0x805A7E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805A7E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805A7E38: jal         0x805A7460
    // 0x805A7E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A7460(rdram, ctx);
        goto after_4;
    // 0x805A7E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A7E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A7E44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A7E48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A7E4C: jr          $ra
    // 0x805A7E50: nop

    return;
    // 0x805A7E50: nop

;}
RECOMP_FUNC void func_80027B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027B90: lw          $v1, 0x15C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X15C);
    // 0x80027B94: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80027B98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80027B9C: beql        $v0, $zero, L_80027BAC
    if (ctx->r2 == 0) {
        // 0x80027BA0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80027BAC;
    }
    goto skip_0;
    // 0x80027BA0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    skip_0:
    // 0x80027BA4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027BA8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80027BAC:
    // 0x80027BAC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80027BB0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80027BB4: lw          $t7, -0x3A38($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3A38);
    // 0x80027BB8: lw          $t8, 0x15C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X15C);
    // 0x80027BBC: jr          $ra
    // 0x80027BC0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x80027BC0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void func_80064AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064AD4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80064AD8: lw          $t6, -0x79E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X79E0);
    // 0x80064ADC: lui         $at, 0x260
    ctx->r1 = S32(0X260 << 16);
    // 0x80064AE0: ori         $at, $at, 0xBCD5
    ctx->r1 = ctx->r1 | 0XBCD5;
    // 0x80064AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064AE8: xor         $t7, $t6, $at
    ctx->r15 = ctx->r14 ^ ctx->r1;
    // 0x80064AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064AF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80064AF4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80064AF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80064AFC: sw          $t7, 0x6590($at)
    MEM_W(0X6590, ctx->r1) = ctx->r15;
    // 0x80064B00: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80064B04: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80064B08: jal         0x80065728
    // 0x80064B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80064B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80064B10: jal         0x8007C540
    // 0x80064B14: nop

    func_8007C540(rdram, ctx);
        goto after_1;
    // 0x80064B14: nop

    after_1:
    // 0x80064B18: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80064B1C: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80064B20: addiu       $t8, $t8, 0x4920
    ctx->r24 = ADD32(ctx->r24, 0X4920);
    // 0x80064B24: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x80064B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064B30: jr          $ra
    // 0x80064B34: nop

    return;
    // 0x80064B34: nop

;}
RECOMP_FUNC void func_8005A484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A48C: jal         0x8005A400
    // 0x8005A490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005A400(rdram, ctx);
        goto after_0;
    // 0x8005A490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005A494: jal         0x8005A3D4
    // 0x8005A498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005A3D4(rdram, ctx);
        goto after_1;
    // 0x8005A498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8005A49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A4A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A4A4: jr          $ra
    // 0x8005A4A8: nop

    return;
    // 0x8005A4A8: nop

;}
RECOMP_FUNC void func_8001B8FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B8FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B900: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001B908: beq         $a0, $zero, L_8001B94C
    if (ctx->r4 == 0) {
        // 0x8001B90C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8001B94C;
    }
    // 0x8001B90C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B910: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x8001B914: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001B918: bnel        $t6, $at, L_8001B950
    if (ctx->r14 != ctx->r1) {
        // 0x8001B91C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B950;
    }
    goto skip_0;
    // 0x8001B91C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001B920: jal         0x8001BA50
    // 0x8001B924: nop

    func_8001BA50(rdram, ctx);
        goto after_0;
    // 0x8001B924: nop

    after_0:
    // 0x8001B928: beq         $v0, $zero, L_8001B940
    if (ctx->r2 == 0) {
        // 0x8001B92C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8001B940;
    }
    // 0x8001B92C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B930: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8001B934: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001B938: jal         0x80019E98
    // 0x8001B93C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019E98(rdram, ctx);
        goto after_1;
    // 0x8001B93C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8001B940:
    // 0x8001B940: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x8001B944: jal         0x80019C4C
    // 0x8001B948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80019C4C(rdram, ctx);
        goto after_2;
    // 0x8001B948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8001B94C:
    // 0x8001B94C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B950:
    // 0x8001B950: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B954: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B958: jr          $ra
    // 0x8001B95C: nop

    return;
    // 0x8001B95C: nop

;}
RECOMP_FUNC void func_8064ACEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064ACEC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8064ACF0: lwc1        $f16, 0xE0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x8064ACF4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064ACF8: lwc1        $f6, 0xEC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8064ACFC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8064AD00: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8064AD04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8064AD08: bc1f        L_8064AD34
    if (!c1cs) {
        // 0x8064AD0C: swc1        $f8, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
            goto L_8064AD34;
    }
    // 0x8064AD0C: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x8064AD10: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8064AD14: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8064AD18: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064AD1C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8064AD20: nop

    // 0x8064AD24: bc1fl       L_8064AD54
    if (!c1cs) {
        // 0x8064AD28: lwc1        $f6, 0x40($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
            goto L_8064AD54;
    }
    goto skip_0;
    // 0x8064AD28: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    skip_0:
    // 0x8064AD2C: b           L_8064AD50
    // 0x8064AD30: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
        goto L_8064AD50;
    // 0x8064AD30: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8064AD34:
    // 0x8064AD34: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8064AD38: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064AD3C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8064AD40: nop

    // 0x8064AD44: bc1fl       L_8064AD54
    if (!c1cs) {
        // 0x8064AD48: lwc1        $f6, 0x40($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
            goto L_8064AD54;
    }
    goto skip_1;
    // 0x8064AD48: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    skip_1:
    // 0x8064AD4C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8064AD50:
    // 0x8064AD50: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
L_8064AD54:
    // 0x8064AD54: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064AD58: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8064AD5C: jr          $ra
    // 0x8064AD60: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8064AD60: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80741288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741288: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11E0) << 16);
    // 0x8074128C: lwc1        $f0, 0x2040($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11E0));
    // 0x80741290: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80741294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80741298: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8074129C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807412A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807412A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807412A8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807412AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807412B0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11E4) << 16);
    // 0x807412B4: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x807412B8: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x807412BC: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
    // 0x807412C0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
    // 0x807412C4: lwc1        $f16, 0x2044($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11E4));
    // 0x807412C8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11E8) << 16);
    // 0x807412CC: swc1        $f16, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f16.u32l;
    // 0x807412D0: lwc1        $f18, 0x2048($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11E8));
    // 0x807412D4: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x807412D8: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x807412DC: jr          $ra
    // 0x807412E0: swc1        $f18, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x807412E0: swc1        $f18, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8057BDD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BDD8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8057BDDC: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8057BDE0: lwc1        $f0, 0xC4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x8057BDE4: lwc1        $f2, 0xDC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XDC);
    // 0x8057BDE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8057BDEC: nop

    // 0x8057BDF0: bc1fl       L_8057BE2C
    if (!c1cs) {
        // 0x8057BDF4: sub.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8057BE2C;
    }
    goto skip_0;
    // 0x8057BDF4: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x8057BDF8: lwc1        $f12, 0xE8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x8057BDFC: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8057BE00: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x8057BE04: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8057BE08: nop

    // 0x8057BE0C: bc1fl       L_8057BE20
    if (!c1cs) {
        // 0x8057BE10: add.s       $f14, $f12, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8057BE20;
    }
    goto skip_1;
    // 0x8057BE10: add.s       $f14, $f12, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f0.fl;
    skip_1:
    // 0x8057BE14: b           L_8057BE20
    // 0x8057BE18: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
        goto L_8057BE20;
    // 0x8057BE18: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8057BE1C: add.s       $f14, $f12, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f0.fl;
L_8057BE20:
    // 0x8057BE20: jr          $ra
    // 0x8057BE24: swc1        $f14, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f14.u32l;
    return;
    // 0x8057BE24: swc1        $f14, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f14.u32l;
    // 0x8057BE28: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
L_8057BE2C:
    // 0x8057BE2C: lwc1        $f12, 0xE8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x8057BE30: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8057BE34: nop

    // 0x8057BE38: bc1fl       L_8057BE4C
    if (!c1cs) {
        // 0x8057BE3C: sub.s       $f14, $f0, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_8057BE4C;
    }
    goto skip_2;
    // 0x8057BE3C: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    skip_2:
    // 0x8057BE40: b           L_8057BE4C
    // 0x8057BE44: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
        goto L_8057BE4C;
    // 0x8057BE44: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8057BE48: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
L_8057BE4C:
    // 0x8057BE4C: swc1        $f14, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f14.u32l;
    // 0x8057BE50: jr          $ra
    // 0x8057BE54: nop

    return;
    // 0x8057BE54: nop

;}
RECOMP_FUNC void func_80433AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433AB0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80433AB4: addiu       $at, $zero, 0x4093
    ctx->r1 = ADD32(0, 0X4093);
    // 0x80433AB8: beq         $v0, $at, L_80433AD8
    if (ctx->r2 == ctx->r1) {
        // 0x80433ABC: addiu       $at, $zero, 0x4094
        ctx->r1 = ADD32(0, 0X4094);
            goto L_80433AD8;
    }
    // 0x80433ABC: addiu       $at, $zero, 0x4094
    ctx->r1 = ADD32(0, 0X4094);
    // 0x80433AC0: beq         $v0, $at, L_80433AE4
    if (ctx->r2 == ctx->r1) {
        // 0x80433AC4: addiu       $at, $zero, 0x4095
        ctx->r1 = ADD32(0, 0X4095);
            goto L_80433AE4;
    }
    // 0x80433AC4: addiu       $at, $zero, 0x4095
    ctx->r1 = ADD32(0, 0X4095);
    // 0x80433AC8: beq         $v0, $at, L_80433AF0
    if (ctx->r2 == ctx->r1) {
        // 0x80433ACC: nop
    
            goto L_80433AF0;
    }
    // 0x80433ACC: nop

    // 0x80433AD0: b           L_80433AFC
    // 0x80433AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80433AFC;
    // 0x80433AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80433AD8:
    // 0x80433AD8: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(71, 0XAF8) << 16);
    // 0x80433ADC: jr          $ra
    // 0x80433AE0: addiu       $v0, $v0, 0x45A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(71, 0XAF8));
    return;
    // 0x80433AE0: addiu       $v0, $v0, 0x45A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(71, 0XAF8));
L_80433AE4:
    // 0x80433AE4: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(71, 0X16AC) << 16);
    // 0x80433AE8: jr          $ra
    // 0x80433AEC: addiu       $v0, $v0, 0x515C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(71, 0X16AC));
    return;
    // 0x80433AEC: addiu       $v0, $v0, 0x515C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(71, 0X16AC));
L_80433AF0:
    // 0x80433AF0: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(71, 0X26D8) << 16);
    // 0x80433AF4: jr          $ra
    // 0x80433AF8: addiu       $v0, $v0, 0x6188
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(71, 0X26D8));
    return;
    // 0x80433AF8: addiu       $v0, $v0, 0x6188
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(71, 0X26D8));
L_80433AFC:
    // 0x80433AFC: jr          $ra
    // 0x80433B00: nop

    return;
    // 0x80433B00: nop

;}
RECOMP_FUNC void func_8058493C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058493C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584940: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584944: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584948: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058494C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584950: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584954: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584958: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058495C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584960: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584964: jr          $ra
    // 0x80584968: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584968: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807988A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807988A0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807988A4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807988A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807988AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807988B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807988B4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807988B8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807988BC: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(820, 0X2F0) << 16);
    // 0x807988C0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807988C4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807988C8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807988CC: lw          $t1, -0x7720($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(820, 0X2F0));
    // 0x807988D0: jr          $ra
    // 0x807988D4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807988D4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x807988D8: nop

    // 0x807988DC: nop

;}
RECOMP_FUNC void func_806D351C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D351C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D3520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D3524: jal         0x806D3460
    // 0x806D3528: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D3460(rdram, ctx);
        goto after_0;
    // 0x806D3528: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D352C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D3530: beq         $v0, $at, L_806D354C
    if (ctx->r2 == ctx->r1) {
        // 0x806D3534: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806D354C;
    }
    // 0x806D3534: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D3538: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806D353C: beq         $v0, $at, L_806D355C
    if (ctx->r2 == ctx->r1) {
        // 0x806D3540: nop
    
            goto L_806D355C;
    }
    // 0x806D3540: nop

    // 0x806D3544: b           L_806D356C
    // 0x806D3548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D356C;
    // 0x806D3548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D354C:
    // 0x806D354C: jal         0x806D3134
    // 0x806D3550: nop

    func_806D3134(rdram, ctx);
        goto after_1;
    // 0x806D3550: nop

    after_1:
    // 0x806D3554: b           L_806D356C
    // 0x806D3558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D356C;
    // 0x806D3558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D355C:
    // 0x806D355C: jal         0x806D3134
    // 0x806D3560: nop

    func_806D3134(rdram, ctx);
        goto after_2;
    // 0x806D3560: nop

    after_2:
    // 0x806D3564: b           L_806D356C
    // 0x806D3568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806D356C;
    // 0x806D3568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806D356C:
    // 0x806D356C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D3570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D3574: jr          $ra
    // 0x806D3578: nop

    return;
    // 0x806D3578: nop

;}
RECOMP_FUNC void func_80445C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445C54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445C5C: jal         0x80445C4C
    // 0x80445C60: nop

    func_80445C4C(rdram, ctx);
        goto after_0;
    // 0x80445C60: nop

    after_0:
    // 0x80445C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445C68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445C6C: jr          $ra
    // 0x80445C70: nop

    return;
    // 0x80445C70: nop

;}
RECOMP_FUNC void func_805260DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805260DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805260E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805260E4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805260E8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805260EC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805260F0: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x805260F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805260F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805260FC: jal         0x80526218
    // 0x80526100: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80526218(rdram, ctx);
        goto after_0;
    // 0x80526100: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80526104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80526108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052610C: jr          $ra
    // 0x80526110: nop

    return;
    // 0x80526110: nop

;}
RECOMP_FUNC void func_8079FF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FF78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079FF7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079FF80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079FF84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8079FF88: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079FF8C: lw          $s0, 0x14($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X14);
    // 0x8079FF90: jal         0x80048060
    // 0x8079FF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_0;
    // 0x8079FF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8079FF98: jal         0x800440E4
    // 0x8079FF9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800440E4(rdram, ctx);
        goto after_1;
    // 0x8079FF9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8079FFA0: jal         0x8005FE48
    // 0x8079FFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8079FFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8079FFA8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8079FFAC: sb          $t7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r15;
    // 0x8079FFB0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8079FFB4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8079FFB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079FFBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8079FFC0: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8079FFC4: addiu       $t8, $t8, -0x7218
    ctx->r24 = ADD32(ctx->r24, -0X7218);
    // 0x8079FFC8: sw          $t8, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r24;
    // 0x8079FFCC: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8079FFD0: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8079FFD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079FFD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079FFDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079FFE0: jr          $ra
    // 0x8079FFE4: nop

    return;
    // 0x8079FFE4: nop

;}
RECOMP_FUNC void func_804CC8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CC8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CC8B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CC8BC: jal         0x80064E84
    // 0x804CC8C0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x804CC8C0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x804CC8C4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x804CC8C8: jal         0x80064E84
    // 0x804CC8CC: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x804CC8CC: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_1:
    // 0x804CC8D0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x804CC8D4: jal         0x80064E84
    // 0x804CC8D8: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x804CC8D8: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_2:
    // 0x804CC8DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CC8E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CC8E4: jr          $ra
    // 0x804CC8E8: nop

    return;
    // 0x804CC8E8: nop

;}
RECOMP_FUNC void func_80437EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437EA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80437EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437EAC: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80437EB0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80437EB8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80437EBC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80437EC0: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80437EC4: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x80437EC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80437ECC: jal         0x8004A97C
    // 0x80437ED0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8004A97C(rdram, ctx);
        goto after_0;
    // 0x80437ED0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80437ED4: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80437ED8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80437EDC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80437EE0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80437EE4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80437EE8: nop

    // 0x80437EEC: bc1fl       L_80437F34
    if (!c1cs) {
        // 0x80437EF0: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_80437F34;
    }
    goto skip_0;
    // 0x80437EF0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_0:
    // 0x80437EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80437EF8: jal         0x80066E88
    // 0x80437EFC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80437EFC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80437F00: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80437F04: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80437F08: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80437F0C: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80437F10: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80437F14: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80437F18: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80437F1C: nop

    // 0x80437F20: bc1fl       L_80437F7C
    if (!c1cs) {
        // 0x80437F24: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80437F7C;
    }
    goto skip_1;
    // 0x80437F24: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_1:
    // 0x80437F28: b           L_80437F78
    // 0x80437F2C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_80437F78;
    // 0x80437F2C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80437F30: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_80437F34:
    // 0x80437F34: nop

    // 0x80437F38: bc1fl       L_80437F7C
    if (!c1cs) {
        // 0x80437F3C: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80437F7C;
    }
    goto skip_2;
    // 0x80437F3C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_2:
    // 0x80437F40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80437F44: jal         0x80066E88
    // 0x80437F48: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80437F48: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80437F4C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80437F50: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80437F54: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80437F58: lwc1        $f8, 0x28($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80437F5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80437F60: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80437F64: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80437F68: nop

    // 0x80437F6C: bc1fl       L_80437F7C
    if (!c1cs) {
        // 0x80437F70: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80437F7C;
    }
    goto skip_3;
    // 0x80437F70: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_3:
    // 0x80437F74: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80437F78:
    // 0x80437F78: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_80437F7C:
    // 0x80437F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80437F80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80437F84: jr          $ra
    // 0x80437F88: nop

    return;
    // 0x80437F88: nop

;}
RECOMP_FUNC void func_806B2A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2A9C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2AA0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2AA4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2AA8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2AAC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2AB0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2AB4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2AB8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2ABC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2AC0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2AC4: jr          $ra
    // 0x806B2AC8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2AC8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80050928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005092C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050934: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80050938: beql        $a1, $zero, L_80050964
    if (ctx->r5 == 0) {
        // 0x8005093C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80050964;
    }
    goto skip_0;
    // 0x8005093C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80050940: jal         0x80050894
    // 0x80050944: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80050894(rdram, ctx);
        goto after_0;
    // 0x80050944: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80050948: beq         $v0, $zero, L_80050958
    if (ctx->r2 == 0) {
        // 0x8005094C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80050958;
    }
    // 0x8005094C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80050950: jal         0x80064E84
    // 0x80050954: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80050954: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
L_80050958:
    // 0x80050958: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005095C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80050960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80050964:
    // 0x80050964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050968: jr          $ra
    // 0x8005096C: nop

    return;
    // 0x8005096C: nop

;}
RECOMP_FUNC void func_807BC600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC600: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BC604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BC608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807BC60C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x807BC610: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807BC614: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807BC618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807BC61C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807BC620: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x807BC624: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x807BC628: nop

    // 0x807BC62C: slti        $at, $a3, 0x80
    ctx->r1 = SIGNED(ctx->r7) < 0X80 ? 1 : 0;
    // 0x807BC630: bne         $at, $zero, L_807BC640
    if (ctx->r1 != 0) {
        // 0x807BC634: nop
    
            goto L_807BC640;
    }
    // 0x807BC634: nop

    // 0x807BC638: b           L_807BC64C
    // 0x807BC63C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
        goto L_807BC64C;
    // 0x807BC63C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
L_807BC640:
    // 0x807BC640: bgezl       $a3, L_807BC650
    if (SIGNED(ctx->r7) >= 0) {
        // 0x807BC644: lh          $t7, 0x1F0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X1F0);
            goto L_807BC650;
    }
    goto skip_0;
    // 0x807BC644: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
    skip_0:
    // 0x807BC648: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_807BC64C:
    // 0x807BC64C: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
L_807BC650:
    // 0x807BC650: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x807BC654: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807BC658: bnel        $t7, $at, L_807BC688
    if (ctx->r15 != ctx->r1) {
        // 0x807BC65C: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_807BC688;
    }
    goto skip_1;
    // 0x807BC65C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x807BC660: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807BC664: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x807BC668: jal         0x80067D5C
    // 0x807BC66C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x807BC66C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x807BC670: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x807BC674: jal         0x80067F78
    // 0x807BC678: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x807BC678: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807BC67C: b           L_807BC6A0
    // 0x807BC680: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_807BC6A0;
    // 0x807BC680: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x807BC684: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_807BC688:
    // 0x807BC688: jal         0x80067D5C
    // 0x807BC68C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x807BC68C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x807BC690: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x807BC694: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x807BC698: jal         0x800678F0
    // 0x807BC69C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x807BC69C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_807BC6A0:
    // 0x807BC6A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807BC6A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807BC6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BC6AC: jr          $ra
    // 0x807BC6B0: nop

    return;
    // 0x807BC6B0: nop

;}
RECOMP_FUNC void func_805AC344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC344: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805AC348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AC34C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805AC350: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805AC354: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AC358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805AC35C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x805AC360: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x805AC364: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805AC368: bnel        $t8, $zero, L_805AC40C
    if (ctx->r24 != 0) {
        // 0x805AC36C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805AC40C;
    }
    goto skip_0;
    // 0x805AC36C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805AC370: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x805AC374: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC378: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x805AC37C: beq         $t9, $zero, L_805AC3C0
    if (ctx->r25 == 0) {
        // 0x805AC380: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_805AC3C0;
    }
    // 0x805AC380: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x805AC384: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC388: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x805AC38C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x805AC390: jal         0x8004D1F0
    // 0x805AC394: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x805AC394: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x805AC398: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC39C: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x805AC3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC3A4: jal         0x8004D698
    // 0x805AC3A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x805AC3A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x805AC3AC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805AC3B0: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x805AC3B4: ori         $t1, $t0, 0xF
    ctx->r9 = ctx->r8 | 0XF;
    // 0x805AC3B8: b           L_805AC3F4
    // 0x805AC3BC: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
        goto L_805AC3F4;
    // 0x805AC3BC: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
L_805AC3C0:
    // 0x805AC3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC3C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x805AC3C8: jal         0x8004D1F0
    // 0x805AC3CC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x805AC3CC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x805AC3D0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC3D4: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x805AC3D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC3DC: jal         0x8004D698
    // 0x805AC3E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x805AC3E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x805AC3E4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805AC3E8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x805AC3EC: ori         $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 | 0XF0;
    // 0x805AC3F0: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_805AC3F4:
    // 0x805AC3F4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x805AC3F8: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x805AC3FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AC400: jal         0x805AC200
    // 0x805AC404: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
    func_805AC200(rdram, ctx);
        goto after_4;
    // 0x805AC404: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
    after_4:
    // 0x805AC408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AC40C:
    // 0x805AC40C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805AC410: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805AC414: jr          $ra
    // 0x805AC418: nop

    return;
    // 0x805AC418: nop

;}
RECOMP_FUNC void func_800048A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800048A0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800048A4: addiu       $a1, $a1, 0x4D10
    ctx->r5 = ADD32(ctx->r5, 0X4D10);
    // 0x800048A8: lh          $t6, 0x1D7C($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X1D7C);
    // 0x800048AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800048B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800048B4: bne         $t6, $at, L_800048C4
    if (ctx->r14 != ctx->r1) {
        // 0x800048B8: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_800048C4;
    }
    // 0x800048B8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800048BC: b           L_800048C4
    // 0x800048C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800048C4;
    // 0x800048C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800048C4:
    // 0x800048C4: lb          $a0, 0x1($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X1);
    // 0x800048C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800048CC: blez        $a0, L_80004A64
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800048D0: nop
    
            goto L_80004A64;
    }
    // 0x800048D0: nop

L_800048D4:
    // 0x800048D4: blez        $v0, L_80004A54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800048D8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80004A54;
    }
    // 0x800048D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800048DC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800048E0: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800048E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800048E8: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800048EC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800048F0: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800048F4: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800048F8: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x800048FC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004900: andi        $a2, $v0, 0x3
    ctx->r6 = ctx->r2 & 0X3;
    // 0x80004904: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80004908: beq         $a2, $zero, L_80004960
    if (ctx->r6 == 0) {
        // 0x8000490C: addu        $a0, $t7, $t8
        ctx->r4 = ADD32(ctx->r15, ctx->r24);
            goto L_80004960;
    }
    // 0x8000490C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80004910: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80004914: lhu         $a2, 0x24($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X24);
L_80004918:
    // 0x80004918: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000491C: div         $zero, $a2, $t0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r8)));
    // 0x80004920: mflo        $t9
    ctx->r25 = lo;
    // 0x80004924: subu        $t1, $a2, $t9
    ctx->r9 = SUB32(ctx->r6, ctx->r25);
    // 0x80004928: bne         $t0, $zero, L_80004934
    if (ctx->r8 != 0) {
        // 0x8000492C: nop
    
            goto L_80004934;
    }
    // 0x8000492C: nop

    // 0x80004930: break       7
    do_break(2147502384);
L_80004934:
    // 0x80004934: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004938: bne         $t0, $at, L_8000494C
    if (ctx->r8 != ctx->r1) {
        // 0x8000493C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000494C;
    }
    // 0x8000493C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004940: bne         $a2, $at, L_8000494C
    if (ctx->r6 != ctx->r1) {
        // 0x80004944: nop
    
            goto L_8000494C;
    }
    // 0x80004944: nop

    // 0x80004948: break       6
    do_break(2147502408);
L_8000494C:
    // 0x8000494C: sh          $t1, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r9;
    // 0x80004950: bnel        $a3, $a1, L_80004918
    if (ctx->r7 != ctx->r5) {
        // 0x80004954: lhu         $a2, 0x24($a0)
        ctx->r6 = MEM_HU(ctx->r4, 0X24);
            goto L_80004918;
    }
    goto skip_0;
    // 0x80004954: lhu         $a2, 0x24($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X24);
    skip_0:
    // 0x80004958: beq         $a1, $v0, L_80004A4C
    if (ctx->r5 == ctx->r2) {
        // 0x8000495C: nop
    
            goto L_80004A4C;
    }
    // 0x8000495C: nop

L_80004960:
    // 0x80004960: lhu         $a2, 0x24($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X24);
L_80004964:
    // 0x80004964: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80004968: div         $zero, $a2, $t0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r8)));
    // 0x8000496C: mflo        $t2
    ctx->r10 = lo;
    // 0x80004970: subu        $t3, $a2, $t2
    ctx->r11 = SUB32(ctx->r6, ctx->r10);
    // 0x80004974: bne         $t0, $zero, L_80004980
    if (ctx->r8 != 0) {
        // 0x80004978: nop
    
            goto L_80004980;
    }
    // 0x80004978: nop

    // 0x8000497C: break       7
    do_break(2147502460);
L_80004980:
    // 0x80004980: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004984: bne         $t0, $at, L_80004998
    if (ctx->r8 != ctx->r1) {
        // 0x80004988: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80004998;
    }
    // 0x80004988: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000498C: bne         $a2, $at, L_80004998
    if (ctx->r6 != ctx->r1) {
        // 0x80004990: nop
    
            goto L_80004998;
    }
    // 0x80004990: nop

    // 0x80004994: break       6
    do_break(2147502484);
L_80004998:
    // 0x80004998: andi        $a2, $t3, 0xFFFF
    ctx->r6 = ctx->r11 & 0XFFFF;
    // 0x8000499C: div         $zero, $a2, $t0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r8)));
    // 0x800049A0: mflo        $t4
    ctx->r12 = lo;
    // 0x800049A4: subu        $t5, $a2, $t4
    ctx->r13 = SUB32(ctx->r6, ctx->r12);
    // 0x800049A8: sh          $t3, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r11;
    // 0x800049AC: bne         $t0, $zero, L_800049B8
    if (ctx->r8 != 0) {
        // 0x800049B0: nop
    
            goto L_800049B8;
    }
    // 0x800049B0: nop

    // 0x800049B4: break       7
    do_break(2147502516);
L_800049B8:
    // 0x800049B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800049BC: bne         $t0, $at, L_800049D0
    if (ctx->r8 != ctx->r1) {
        // 0x800049C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800049D0;
    }
    // 0x800049C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800049C4: bne         $a2, $at, L_800049D0
    if (ctx->r6 != ctx->r1) {
        // 0x800049C8: nop
    
            goto L_800049D0;
    }
    // 0x800049C8: nop

    // 0x800049CC: break       6
    do_break(2147502540);
L_800049D0:
    // 0x800049D0: andi        $a2, $t5, 0xFFFF
    ctx->r6 = ctx->r13 & 0XFFFF;
    // 0x800049D4: div         $zero, $a2, $t0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r8)));
    // 0x800049D8: mflo        $t6
    ctx->r14 = lo;
    // 0x800049DC: subu        $t7, $a2, $t6
    ctx->r15 = SUB32(ctx->r6, ctx->r14);
    // 0x800049E0: sh          $t5, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r13;
    // 0x800049E4: bne         $t0, $zero, L_800049F0
    if (ctx->r8 != 0) {
        // 0x800049E8: nop
    
            goto L_800049F0;
    }
    // 0x800049E8: nop

    // 0x800049EC: break       7
    do_break(2147502572);
L_800049F0:
    // 0x800049F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800049F4: bne         $t0, $at, L_80004A08
    if (ctx->r8 != ctx->r1) {
        // 0x800049F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80004A08;
    }
    // 0x800049F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800049FC: bne         $a2, $at, L_80004A08
    if (ctx->r6 != ctx->r1) {
        // 0x80004A00: nop
    
            goto L_80004A08;
    }
    // 0x80004A00: nop

    // 0x80004A04: break       6
    do_break(2147502596);
L_80004A08:
    // 0x80004A08: andi        $a2, $t7, 0xFFFF
    ctx->r6 = ctx->r15 & 0XFFFF;
    // 0x80004A0C: div         $zero, $a2, $t0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r8)));
    // 0x80004A10: mflo        $t8
    ctx->r24 = lo;
    // 0x80004A14: subu        $t9, $a2, $t8
    ctx->r25 = SUB32(ctx->r6, ctx->r24);
    // 0x80004A18: sh          $t7, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r15;
    // 0x80004A1C: bne         $t0, $zero, L_80004A28
    if (ctx->r8 != 0) {
        // 0x80004A20: nop
    
            goto L_80004A28;
    }
    // 0x80004A20: nop

    // 0x80004A24: break       7
    do_break(2147502628);
L_80004A28:
    // 0x80004A28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004A2C: bne         $t0, $at, L_80004A40
    if (ctx->r8 != ctx->r1) {
        // 0x80004A30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80004A40;
    }
    // 0x80004A30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004A34: bne         $a2, $at, L_80004A40
    if (ctx->r6 != ctx->r1) {
        // 0x80004A38: nop
    
            goto L_80004A40;
    }
    // 0x80004A38: nop

    // 0x80004A3C: break       6
    do_break(2147502652);
L_80004A40:
    // 0x80004A40: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80004A44: bnel        $a1, $v0, L_80004964
    if (ctx->r5 != ctx->r2) {
        // 0x80004A48: lhu         $a2, 0x24($a0)
        ctx->r6 = MEM_HU(ctx->r4, 0X24);
            goto L_80004964;
    }
    goto skip_1;
    // 0x80004A48: lhu         $a2, 0x24($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X24);
    skip_1:
L_80004A4C:
    // 0x80004A4C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80004A50: lb          $a0, 0x4D11($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X4D11);
L_80004A54:
    // 0x80004A54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004A58: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80004A5C: bne         $at, $zero, L_800048D4
    if (ctx->r1 != 0) {
        // 0x80004A60: nop
    
            goto L_800048D4;
    }
    // 0x80004A60: nop

L_80004A64:
    // 0x80004A64: jr          $ra
    // 0x80004A68: nop

    return;
    // 0x80004A68: nop

;}
RECOMP_FUNC void func_80071C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071C68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80071C6C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80071C70: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071C74: sw          $t6, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r14;
    // 0x80071C78: addiu       $a0, $a0, -0x59C0
    ctx->r4 = ADD32(ctx->r4, -0X59C0);
    // 0x80071C7C: jal         0x80082210
    // 0x80071C80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071C80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80071C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071C8C: jr          $ra
    // 0x80071C90: nop

    return;
    // 0x80071C90: nop

;}
RECOMP_FUNC void func_80446B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446B9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446BA0: addiu       $t6, $zero, 0x618
    ctx->r14 = ADD32(0, 0X618);
    // 0x80446BA4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446BA8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446BAC: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x80446BB0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446BB4: jr          $ra
    // 0x80446BB8: sw          $t7, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r15;
    return;
    // 0x80446BB8: sw          $t7, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80022280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022284: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80022288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002228C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80022290: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    // 0x80022294: jal         0x8006593C
    // 0x80022298: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80022298: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8002229C: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800222A0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800222A4: slti        $at, $t7, 0x2D
    ctx->r1 = SIGNED(ctx->r15) < 0X2D ? 1 : 0;
    // 0x800222A8: bne         $at, $zero, L_80022350
    if (ctx->r1 != 0) {
        // 0x800222AC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80022350;
    }
    // 0x800222AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800222B0: lw          $t8, 0x174($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X174);
    // 0x800222B4: lbu         $t9, 0x12($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X12);
    // 0x800222B8: bnel        $t9, $zero, L_80022354
    if (ctx->r25 != 0) {
        // 0x800222BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022354;
    }
    goto skip_0;
    // 0x800222BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800222C0: lw          $t0, 0x14C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14C);
    // 0x800222C4: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x800222C8: bnel        $t1, $zero, L_80022354
    if (ctx->r9 != 0) {
        // 0x800222CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022354;
    }
    goto skip_1;
    // 0x800222CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800222D0: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x800222D4: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x800222D8: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x800222DC: beql        $t3, $zero, L_800222F0
    if (ctx->r11 == 0) {
        // 0x800222E0: lwc1        $f4, 0xC4($a2)
        ctx->f4.u32l = MEM_W(ctx->r6, 0XC4);
            goto L_800222F0;
    }
    goto skip_2;
    // 0x800222E0: lwc1        $f4, 0xC4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC4);
    skip_2:
    // 0x800222E4: b           L_80022344
    // 0x800222E8: lwc1        $f0, 0x64($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X64);
        goto L_80022344;
    // 0x800222E8: lwc1        $f0, 0x64($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X64);
    // 0x800222EC: lwc1        $f4, 0xC4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC4);
L_800222F0:
    // 0x800222F0: lwc1        $f6, 0x64($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X64);
    // 0x800222F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800222F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800222FC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80022300: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80022304: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80022308: nop

    // 0x8002230C: bc1fl       L_80022320
    if (!c1cs) {
        // 0x80022310: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80022320;
    }
    goto skip_3;
    // 0x80022310: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_3:
    // 0x80022314: b           L_80022344
    // 0x80022318: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80022344;
    // 0x80022318: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8002231C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80022320:
    // 0x80022320: nop

    // 0x80022324: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80022328: nop

    // 0x8002232C: bc1fl       L_80022340
    if (!c1cs) {
        // 0x80022330: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80022340;
    }
    goto skip_4;
    // 0x80022330: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_4:
    // 0x80022334: b           L_80022340
    // 0x80022338: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_80022340;
    // 0x80022338: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8002233C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80022340:
    // 0x80022340: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80022344:
    // 0x80022344: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80022348: jal         0x80021C88
    // 0x8002234C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80021C88(rdram, ctx);
        goto after_1;
    // 0x8002234C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_80022350:
    // 0x80022350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80022354:
    // 0x80022354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022358: jr          $ra
    // 0x8002235C: nop

    return;
    // 0x8002235C: nop

;}
RECOMP_FUNC void func_804556D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804556D8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804556DC: lui         $v1, 0xB800
    ctx->r3 = S32(0XB800 << 16);
    // 0x804556E0: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X112A8) << 16);
    // 0x804556E4: sw          $v1, 0xAE0($v0)
    MEM_W(0XAE0, ctx->r2) = ctx->r3;
    // 0x804556E8: sw          $zero, 0xAE4($v0)
    MEM_W(0XAE4, ctx->r2) = 0;
    // 0x804556EC: sw          $v1, 0x3D30($v0)
    MEM_W(0X3D30, ctx->r2) = ctx->r3;
    // 0x804556F0: sw          $zero, 0x3D34($v0)
    MEM_W(0X3D34, ctx->r2) = 0;
    // 0x804556F4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804556F8: addiu       $t6, $t6, 0x5688
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X112A8));
    // 0x804556FC: jr          $ra
    // 0x80455700: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    return;
    // 0x80455700: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_8006F3BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F3BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F3C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F3C4: jal         0x8006E7F0
    // 0x8006F3C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006E7F0(rdram, ctx);
        goto after_0;
    // 0x8006F3C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006F3CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006F3D0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8006F3D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006F3D8: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8006F3DC: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8006F3E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006F3E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8006F3E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006F3EC: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8006F3F0: jal         0x8006F49C
    // 0x8006F3F4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    func_8006F49C(rdram, ctx);
        goto after_1;
    // 0x8006F3F4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x8006F3F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F3FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F400: jr          $ra
    // 0x8006F404: nop

    return;
    // 0x8006F404: nop

;}
RECOMP_FUNC void func_807AB3E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AB3E4: jr          $ra
    // 0x807AB3E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807AB3E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8079A15C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A15C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079A160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079A164: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8079A168: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8079A16C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8079A170: jal         0x80065ABC
    // 0x8079A174: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x8079A174: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079A178: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079A17C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2694) << 16);
    // 0x8079A180: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8079A184: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8079A188: lwc1        $f4, -0x4E4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2694));
    // 0x8079A18C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079A190: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X269C) << 16);
    // 0x8079A194: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8079A198: nop

    // 0x8079A19C: bc1f        L_8079A1B8
    if (!c1cs) {
        // 0x8079A1A0: nop
    
            goto L_8079A1B8;
    }
    // 0x8079A1A0: nop

    // 0x8079A1A4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2698) << 16);
    // 0x8079A1A8: lwc1        $f0, -0x4E48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2698));
    // 0x8079A1AC: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8079A1B0: b           L_8079A1E4
    // 0x8079A1B4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_8079A1E4;
    // 0x8079A1B4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_8079A1B8:
    // 0x8079A1B8: lwc1        $f0, -0x4E44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X269C));
    // 0x8079A1BC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8079A1C0: nop

    // 0x8079A1C4: bc1fl       L_8079A1DC
    if (!c1cs) {
        // 0x8079A1C8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8079A1DC;
    }
    goto skip_0;
    // 0x8079A1C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x8079A1CC: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8079A1D0: b           L_8079A1E4
    // 0x8079A1D4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_8079A1E4;
    // 0x8079A1D4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8079A1D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8079A1DC:
    // 0x8079A1DC: nop

    // 0x8079A1E0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_8079A1E4:
    // 0x8079A1E4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079A1E8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8079A1EC: beq         $t7, $zero, L_8079A240
    if (ctx->r15 == 0) {
        // 0x8079A1F0: nop
    
            goto L_8079A240;
    }
    // 0x8079A1F0: nop

    // 0x8079A1F4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079A1F8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X26A0) << 16);
    // 0x8079A1FC: lwc1        $f16, -0x4E40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X26A0));
    // 0x8079A200: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8079A204: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8079A208: nop

    // 0x8079A20C: bc1f        L_8079A240
    if (!c1cs) {
        // 0x8079A210: nop
    
            goto L_8079A240;
    }
    // 0x8079A210: nop

    // 0x8079A214: jal         0x80799AC8
    // 0x8079A218: nop

    func_80799AC8(rdram, ctx);
        goto after_1;
    // 0x8079A218: nop

    after_1:
    // 0x8079A21C: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x8079A220: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079A224: sb          $v0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r2;
    // 0x8079A228: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079A22C: sb          $v0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r2;
    // 0x8079A230: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079A234: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8079A238: b           L_8079A248
    // 0x8079A23C: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
        goto L_8079A248;
    // 0x8079A23C: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
L_8079A240:
    // 0x8079A240: jal         0x80799A80
    // 0x8079A244: nop

    func_80799A80(rdram, ctx);
        goto after_2;
    // 0x8079A244: nop

    after_2:
L_8079A248:
    // 0x8079A248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079A24C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079A250: jr          $ra
    // 0x8079A254: nop

    return;
    // 0x8079A254: nop

;}
RECOMP_FUNC void func_80742FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742FD4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742FD8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742FDC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742FE0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742FE4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742FE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742FEC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742FF0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742FF4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742FF8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742FFC: jr          $ra
    // 0x80743000: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80743000: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80058A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058A14: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80058A18: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x80058A1C: lw          $t6, 0xCE8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XCE8);
    // 0x80058A20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80058A24: bnel        $t6, $at, L_80058A38
    if (ctx->r14 != ctx->r1) {
        // 0x80058A28: lbu         $t7, 0x2($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X2);
            goto L_80058A38;
    }
    goto skip_0;
    // 0x80058A28: lbu         $t7, 0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X2);
    skip_0:
    // 0x80058A2C: jr          $ra
    // 0x80058A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80058A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058A34: lbu         $t7, 0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X2);
L_80058A38:
    // 0x80058A38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80058A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058A40: bnel        $t7, $at, L_80058A54
    if (ctx->r15 != ctx->r1) {
        // 0x80058A44: lw          $a0, 0xF54($a2)
        ctx->r4 = MEM_W(ctx->r6, 0XF54);
            goto L_80058A54;
    }
    goto skip_1;
    // 0x80058A44: lw          $a0, 0xF54($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XF54);
    skip_1:
    // 0x80058A48: jr          $ra
    // 0x80058A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80058A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80058A50: lw          $a0, 0xF54($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XF54);
L_80058A54:
    // 0x80058A54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80058A58: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80058A5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80058A60:
    // 0x80058A60: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x80058A64: beq         $t8, $zero, L_80058A70
    if (ctx->r24 == 0) {
        // 0x80058A68: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_80058A70;
    }
    // 0x80058A68: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80058A6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80058A70:
    // 0x80058A70: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x80058A74: beq         $t9, $zero, L_80058A80
    if (ctx->r25 == 0) {
        // 0x80058A78: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_80058A80;
    }
    // 0x80058A78: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80058A7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80058A80:
    // 0x80058A80: andi        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 & 0X1;
    // 0x80058A84: beq         $t0, $zero, L_80058A90
    if (ctx->r8 == 0) {
        // 0x80058A88: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_80058A90;
    }
    // 0x80058A88: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80058A8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80058A90:
    // 0x80058A90: andi        $t1, $v1, 0x1
    ctx->r9 = ctx->r3 & 0X1;
    // 0x80058A94: beq         $t1, $zero, L_80058AA0
    if (ctx->r9 == 0) {
        // 0x80058A98: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80058AA0;
    }
    // 0x80058A98: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80058A9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80058AA0:
    // 0x80058AA0: bne         $a1, $a3, L_80058A60
    if (ctx->r5 != ctx->r7) {
        // 0x80058AA4: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_80058A60;
    }
    // 0x80058AA4: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x80058AA8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80058AAC: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80058AB0: and         $t2, $a0, $at
    ctx->r10 = ctx->r4 & ctx->r1;
    // 0x80058AB4: srl         $t3, $t2, 14
    ctx->r11 = S32(U32(ctx->r10) >> 14);
    // 0x80058AB8: andi        $t4, $a0, 0x80
    ctx->r12 = ctx->r4 & 0X80;
    // 0x80058ABC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80058AC0: bne         $t4, $zero, L_80058AD8
    if (ctx->r12 != 0) {
        // 0x80058AC4: addiu       $v1, $zero, 0x6
        ctx->r3 = ADD32(0, 0X6);
            goto L_80058AD8;
    }
    // 0x80058AC4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80058AC8: lw          $t5, 0xFB8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XFB8);
    // 0x80058ACC: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x80058AD0: bgezl       $t7, L_80058AE0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80058AD4: andi        $t8, $a0, 0x40
        ctx->r24 = ctx->r4 & 0X40;
            goto L_80058AE0;
    }
    goto skip_2;
    // 0x80058AD4: andi        $t8, $a0, 0x40
    ctx->r24 = ctx->r4 & 0X40;
    skip_2:
L_80058AD8:
    // 0x80058AD8: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80058ADC: andi        $t8, $a0, 0x40
    ctx->r24 = ctx->r4 & 0X40;
L_80058AE0:
    // 0x80058AE0: bnel        $t8, $zero, L_80058AFC
    if (ctx->r24 != 0) {
        // 0x80058AE4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80058AFC;
    }
    goto skip_3;
    // 0x80058AE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x80058AE8: lw          $t9, 0xFB8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XFB8);
    // 0x80058AEC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80058AF0: bgezl       $t1, L_80058B00
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80058AF4: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80058B00;
    }
    goto skip_4;
    // 0x80058AF4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_4:
    // 0x80058AF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80058AFC:
    // 0x80058AFC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80058B00:
    // 0x80058B00: beq         $at, $zero, L_80058B10
    if (ctx->r1 == 0) {
        // 0x80058B04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80058B10;
    }
    // 0x80058B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058B08: jr          $ra
    // 0x80058B0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80058B0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80058B10:
    // 0x80058B10: jr          $ra
    // 0x80058B14: nop

    return;
    // 0x80058B14: nop

;}
RECOMP_FUNC void func_80465EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465EF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80465EFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80465F00: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80465F04: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x80465F08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80465F0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80465F10: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x80465F14: jal         0x80051194
    // 0x80465F18: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80465F18: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80465F1C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80465F20: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80465F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80465F28: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80465F2C: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80465F30: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80465F34: jal         0x80465EB8
    // 0x80465F38: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    func_80465EB8(rdram, ctx);
        goto after_1;
    // 0x80465F38: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80465F3C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80465F40: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(125, 0X1DB4) << 16);
    // 0x80465F44: addiu       $t7, $t7, 0x6384
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(125, 0X1DB4));
    // 0x80465F48: bne         $t6, $zero, L_80465F60
    if (ctx->r14 != 0) {
        // 0x80465F4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80465F60;
    }
    // 0x80465F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80465F50: jal         0x800445A4
    // 0x80465F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80465F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80465F58: b           L_80465F94
    // 0x80465F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80465F94;
    // 0x80465F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80465F60:
    // 0x80465F60: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80465F64: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80465F68: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80465F6C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80465F70: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80465F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80465F78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80465F7C: jal         0x80465FA4
    // 0x80465F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80465FA4(rdram, ctx);
        goto after_3;
    // 0x80465F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80465F84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80465F88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80465F8C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80465F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80465F94:
    // 0x80465F94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80465F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80465F9C: jr          $ra
    // 0x80465FA0: nop

    return;
    // 0x80465FA0: nop

;}
RECOMP_FUNC void func_80451AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80451AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80451AB0: jal         0x80450F94
    // 0x80451AB4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80450F94(rdram, ctx);
        goto after_0;
    // 0x80451AB4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80451AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80451ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80451AC0: jr          $ra
    // 0x80451AC4: nop

    return;
    // 0x80451AC4: nop

;}
RECOMP_FUNC void func_805AC8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC8F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AC8F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC8F8: jal         0x805AC884
    // 0x805AC8FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AC884(rdram, ctx);
        goto after_0;
    // 0x805AC8FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AC900: jal         0x805AC528
    // 0x805AC904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805AC528(rdram, ctx);
        goto after_1;
    // 0x805AC904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805AC908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AC90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AC910: jr          $ra
    // 0x805AC914: nop

    return;
    // 0x805AC914: nop

;}
RECOMP_FUNC void func_80711690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80711690: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80711694: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80711698: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8071169C: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x807116A0: lui         $t7, 0x8071
    ctx->r15 = S32(RELOC_HI16(727, 0X1904) << 16);
    // 0x807116A4: addiu       $t7, $t7, 0x2874
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(727, 0X1904));
    // 0x807116A8: addiu       $t6, $v0, 0xD
    ctx->r14 = ADD32(ctx->r2, 0XD);
    // 0x807116AC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x807116B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807116B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807116B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807116BC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807116C0: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    // 0x807116C4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807116C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807116CC: jal         0x80711A8C
    // 0x807116D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80711A8C(rdram, ctx);
        goto after_0;
    // 0x807116D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807116D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807116D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807116DC: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x807116E0: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x807116E4: beql        $a0, $zero, L_807116FC
    if (ctx->r4 == 0) {
        // 0x807116E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807116FC;
    }
    goto skip_0;
    // 0x807116E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x807116EC: jal         0x80711664
    // 0x807116F0: nop

    func_80711664(rdram, ctx);
        goto after_1;
    // 0x807116F0: nop

    after_1:
    // 0x807116F4: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
    // 0x807116F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_807116FC:
    // 0x807116FC: jal         0x80045A34
    // 0x80711700: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x80711700: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80711704: lui         $t0, 0x8071
    ctx->r8 = S32(RELOC_HI16(727, 0X6F4) << 16);
    // 0x80711708: addiu       $t0, $t0, 0x1664
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(727, 0X6F4));
    // 0x8071170C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80711710: sw          $t0, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r8;
    // 0x80711714: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80711718: lui         $t2, 0x8071
    ctx->r10 = S32(RELOC_HI16(727, 0X190C) << 16);
    // 0x8071171C: addiu       $t2, $t2, 0x287C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(727, 0X190C));
    // 0x80711720: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80711724: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80711728: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8071172C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80711730: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80711734: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80711738: jal         0x80054530
    // 0x8071173C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_80054530(rdram, ctx);
        goto after_3;
    // 0x8071173C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_3:
    // 0x80711740: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80711744: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80711748: bne         $v0, $zero, L_80711758
    if (ctx->r2 != 0) {
        // 0x8071174C: sw          $v0, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r2;
            goto L_80711758;
    }
    // 0x8071174C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80711750: b           L_80711768
    // 0x80711754: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
        goto L_80711768;
    // 0x80711754: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
L_80711758:
    // 0x80711758: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x8071175C: lui         $t5, 0x8071
    ctx->r13 = S32(RELOC_HI16(727, 0X17C) << 16);
    // 0x80711760: addiu       $t5, $t5, 0x10EC
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(727, 0X17C));
    // 0x80711764: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
L_80711768:
    // 0x80711768: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8071176C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80711770: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80711774: jr          $ra
    // 0x80711778: nop

    return;
    // 0x80711778: nop

;}
RECOMP_FUNC void func_8002387C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002387C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023884: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80023888: jal         0x800232E0
    // 0x8002388C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800232E0(rdram, ctx);
        goto after_0;
    // 0x8002388C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80023890: jal         0x800233B4
    // 0x80023894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800233B4(rdram, ctx);
        goto after_1;
    // 0x80023894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80023898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002389C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800238A0: jr          $ra
    // 0x800238A4: nop

    return;
    // 0x800238A4: nop

;}
RECOMP_FUNC void func_8001AA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AA08: bnel        $a0, $zero, L_8001AA1C
    if (ctx->r4 != 0) {
        // 0x8001AA0C: lw          $v0, 0x84($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X84);
            goto L_8001AA1C;
    }
    goto skip_0;
    // 0x8001AA0C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    skip_0:
    // 0x8001AA10: jr          $ra
    // 0x8001AA14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001AA14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AA18: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
L_8001AA1C:
    // 0x8001AA1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001AA20: beq         $v0, $zero, L_8001AA38
    if (ctx->r2 == 0) {
        // 0x8001AA24: nop
    
            goto L_8001AA38;
    }
    // 0x8001AA24: nop

    // 0x8001AA28: beq         $v0, $at, L_8001AA38
    if (ctx->r2 == ctx->r1) {
        // 0x8001AA2C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8001AA38;
    }
    // 0x8001AA2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001AA30: bnel        $v0, $at, L_8001AA44
    if (ctx->r2 != ctx->r1) {
        // 0x8001AA34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001AA44;
    }
    goto skip_1;
    // 0x8001AA34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_8001AA38:
    // 0x8001AA38: jr          $ra
    // 0x8001AA3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001AA3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001AA40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001AA44:
    // 0x8001AA44: jr          $ra
    // 0x8001AA48: nop

    return;
    // 0x8001AA48: nop

;}
RECOMP_FUNC void func_804697D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804697D8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804697DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804697E0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804697E4: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804697E8: nop

    // 0x804697EC: bc1fl       L_8046980C
    if (!c1cs) {
        // 0x804697F0: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_8046980C;
    }
    goto skip_0;
    // 0x804697F0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x804697F4: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_804697F8:
    // 0x804697F8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804697FC: nop

    // 0x80469800: bc1tl       L_804697F8
    if (c1cs) {
        // 0x80469804: sub.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_804697F8;
    }
    goto skip_1;
    // 0x80469804: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    skip_1:
    // 0x80469808: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_8046980C:
    // 0x8046980C: nop

    // 0x80469810: bc1f        L_8046982C
    if (!c1cs) {
        // 0x80469814: nop
    
            goto L_8046982C;
    }
    // 0x80469814: nop

    // 0x80469818: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_8046981C:
    // 0x8046981C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80469820: nop

    // 0x80469824: bc1tl       L_8046981C
    if (c1cs) {
        // 0x80469828: add.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8046981C;
    }
    goto skip_2;
    // 0x80469828: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    skip_2:
L_8046982C:
    // 0x8046982C: jr          $ra
    // 0x80469830: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80469830: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_8047387C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8047387C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80473880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80473884: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80473888: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(161, 0X131C) << 16);
    // 0x8047388C: addiu       $t8, $t8, 0x44AC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(161, 0X131C));
    // 0x80473890: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80473894: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80473898: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8047389C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804738A0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804738A4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804738A8: beql        $v1, $zero, L_804738F8
    if (ctx->r3 == 0) {
        // 0x804738AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804738F8;
    }
    goto skip_0;
    // 0x804738AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804738B0: jalr        $v1
    // 0x804738B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804738B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804738B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804738BC: lui         $t7, 0x8047
    ctx->r15 = S32(RELOC_HI16(161, 0X1380) << 16);
    // 0x804738C0: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x804738C4: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x804738C8: lw          $t5, 0x134($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X134);
    // 0x804738CC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x804738D0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x804738D4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x804738D8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x804738DC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x804738E0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804738E4: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x804738E8: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x804738EC: lw          $t7, 0x4510($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(161, 0X1380));
    // 0x804738F0: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x804738F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804738F8:
    // 0x804738F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804738FC: jr          $ra
    // 0x80473900: nop

    return;
    // 0x80473900: nop

;}
RECOMP_FUNC void func_8004EE68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EE68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004EE6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004EE70: jal         0x80064DD0
    // 0x8004EE74: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8004EE74: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_0:
    // 0x8004EE78: bne         $v0, $zero, L_8004EE98
    if (ctx->r2 != 0) {
        // 0x8004EE7C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8004EE98;
    }
    // 0x8004EE7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004EE80: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004EE84: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    // 0x8004EE88: jal         0x80071380
    // 0x8004EE8C: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8004EE8C: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    after_1:
    // 0x8004EE90: b           L_8004EEA8
    // 0x8004EE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004EEA8;
    // 0x8004EE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EE98:
    // 0x8004EE98: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // 0x8004EE9C: jal         0x8004EE30
    // 0x8004EEA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004EE30(rdram, ctx);
        goto after_2;
    // 0x8004EEA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8004EEA4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_8004EEA8:
    // 0x8004EEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004EEAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004EEB0: jr          $ra
    // 0x8004EEB4: nop

    return;
    // 0x8004EEB4: nop

;}
RECOMP_FUNC void func_8076069C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076069C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807606A0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807606A4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807606A8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807606AC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807606B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807606B4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807606B8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807606BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807606C0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807606C4: jr          $ra
    // 0x807606C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807606C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8040B2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B2F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8040B2F4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8040B2F8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8040B2FC: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(14, 0X11B8) << 16);
    // 0x8040B300: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8040B304: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8040B308: lw          $t7, -0x42E8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(14, 0X11B8));
    // 0x8040B30C: jr          $ra
    // 0x8040B310: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x8040B310: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80025370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025370: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80025374: addiu       $t6, $t6, 0x4E04
    ctx->r14 = ADD32(ctx->r14, 0X4E04);
    // 0x80025378: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x8002537C: jr          $ra
    // 0x80025380: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80025380: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8040828C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040828C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80408290: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80408294: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E08) << 16);
    // 0x80408298: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8040829C: lwc1        $f6, -0x5828($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E08));
    // 0x804082A0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804082A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804082A8: jr          $ra
    // 0x804082AC: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x804082AC: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8003FC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FC48: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8003FC4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003FC50: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003FC54: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8003FC58: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8003FC5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003FC60: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8003FC64: lbu         $t7, 0x12C8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X12C8);
    // 0x8003FC68: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8003FC6C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8003FC70: jal         0x80065490
    // 0x8003FC74: sb          $t7, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r15;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x8003FC74: sb          $t7, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r15;
    after_0:
    // 0x8003FC78: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8003FC7C: jal         0x80065490
    // 0x8003FC80: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8003FC80: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    after_1:
    // 0x8003FC84: jal         0x8001D770
    // 0x8003FC88: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8003FC88: nop

    after_2:
    // 0x8003FC8C: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8003FC90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003FC94: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x8003FC98: jal         0x80067BF8
    // 0x8003FC9C: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x8003FC9C: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_3:
    // 0x8003FCA0: addiu       $a0, $zero, 0x21D
    ctx->r4 = ADD32(0, 0X21D);
    // 0x8003FCA4: jal         0x80067818
    // 0x8003FCA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8003FCA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8003FCAC: lw          $t8, 0x180($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X180);
    // 0x8003FCB0: beql        $t8, $zero, L_8003FCC4
    if (ctx->r24 == 0) {
        // 0x8003FCB4: lbu         $a2, 0x57($sp)
        ctx->r6 = MEM_BU(ctx->r29, 0X57);
            goto L_8003FCC4;
    }
    goto skip_0;
    // 0x8003FCB4: lbu         $a2, 0x57($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X57);
    skip_0:
    // 0x8003FCB8: jal         0x80048060
    // 0x8003FCBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_5;
    // 0x8003FCBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8003FCC0: lbu         $a2, 0x57($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X57);
L_8003FCC4:
    // 0x8003FCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FCC8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8003FCCC: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x8003FCD0: bne         $at, $zero, L_8003FD04
    if (ctx->r1 != 0) {
        // 0x8003FCD4: addiu       $a3, $sp, 0x48
        ctx->r7 = ADD32(ctx->r29, 0X48);
            goto L_8003FD04;
    }
    // 0x8003FCD4: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8003FCD8: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8003FCDC: addiu       $t9, $sp, 0x3C
    ctx->r25 = ADD32(ctx->r29, 0X3C);
    // 0x8003FCE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003FCE4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003FCE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003FCEC: jal         0x8003F894
    // 0x8003FCF0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_8003F894(rdram, ctx);
        goto after_6;
    // 0x8003FCF0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003FCF4: bnel        $v0, $zero, L_8003FDB4
    if (ctx->r2 != 0) {
        // 0x8003FCF8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003FDB4;
    }
    goto skip_1;
    // 0x8003FCF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8003FCFC: b           L_8003FDB4
    // 0x8003FD00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003FDB4;
    // 0x8003FD00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FD04:
    // 0x8003FD04: lw          $t2, 0x1EC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1EC);
    // 0x8003FD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FD0C: jal         0x800447C8
    // 0x8003FD10: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x8003FD10: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    after_7:
    // 0x8003FD14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003FD18: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003FD1C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8003FD20: jal         0x8003BB20
    // 0x8003FD24: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_8003BB20(rdram, ctx);
        goto after_8;
    // 0x8003FD24: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_8:
    // 0x8003FD28: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8003FD2C: addiu       $t3, $t3, -0x4D50
    ctx->r11 = ADD32(ctx->r11, -0X4D50);
    // 0x8003FD30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003FD34: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    // 0x8003FD38: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
    // 0x8003FD3C: jal         0x80065490
    // 0x8003FD40: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80065490(rdram, ctx);
        goto after_9;
    // 0x8003FD40: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_9:
    // 0x8003FD44: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8003FD48: jal         0x80065490
    // 0x8003FD4C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_10;
    // 0x8003FD4C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_10:
    // 0x8003FD50: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8003FD54: jal         0x80065490
    // 0x8003FD58: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_11;
    // 0x8003FD58: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x8003FD5C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8003FD60: jal         0x80047F9C
    // 0x8003FD64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_12;
    // 0x8003FD64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x8003FD68: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003FD6C: sb          $t4, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r12;
    // 0x8003FD70: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8003FD74: addiu       $a3, $a3, -0x1A14
    ctx->r7 = ADD32(ctx->r7, -0X1A14);
    // 0x8003FD78: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8003FD7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003FD80: jal         0x8003E658
    // 0x8003FD84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8003E658(rdram, ctx);
        goto after_13;
    // 0x8003FD84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x8003FD88: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8003FD8C: addiu       $a2, $a2, -0x5A14
    ctx->r6 = ADD32(ctx->r6, -0X5A14);
    // 0x8003FD90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FD94: jal         0x8003F14C
    // 0x8003FD98: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_8003F14C(rdram, ctx);
        goto after_14;
    // 0x8003FD98: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_14:
    // 0x8003FD9C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8003FDA0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003FDA4: addiu       $t6, $t6, -0x7630
    ctx->r14 = ADD32(ctx->r14, -0X7630);
    // 0x8003FDA8: sb          $t5, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r13;
    // 0x8003FDAC: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8003FDB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FDB4:
    // 0x8003FDB4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003FDB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8003FDBC: jr          $ra
    // 0x8003FDC0: nop

    return;
    // 0x8003FDC0: nop

;}
RECOMP_FUNC void func_80452C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452C14: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452C18: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452C1C: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80452C20: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80452C24: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452C28: ori         $at, $at, 0x6D3C
    ctx->r1 = ctx->r1 | 0X6D3C;
    // 0x80452C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80452C30: jal         0x80452A64
    // 0x80452C34: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_80452A64(rdram, ctx);
        goto after_0;
    // 0x80452C34: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_0:
    // 0x80452C38: bne         $v0, $zero, L_80452C50
    if (ctx->r2 != 0) {
        // 0x80452C3C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80452C50;
    }
    // 0x80452C3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80452C40: jal         0x80452A14
    // 0x80452C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80452A14(rdram, ctx);
        goto after_1;
    // 0x80452C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80452C48: b           L_80452C5C
    // 0x80452C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452C5C;
    // 0x80452C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452C50:
    // 0x80452C50: jal         0x804526B4
    // 0x80452C54: nop

    func_804526B4(rdram, ctx);
        goto after_2;
    // 0x80452C54: nop

    after_2:
    // 0x80452C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452C5C:
    // 0x80452C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452C60: jr          $ra
    // 0x80452C64: nop

    return;
    // 0x80452C64: nop

;}
RECOMP_FUNC void func_80433830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433830: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(68, 0X30) << 16);
    // 0x80433834: addiu       $v0, $v0, 0x3860
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(68, 0X30));
    // 0x80433838: jr          $ra
    // 0x8043383C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8043383C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001D6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D6FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D704: jal         0x80047090
    // 0x8001D708: addiu       $a0, $zero, 0x4010
    ctx->r4 = ADD32(0, 0X4010);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8001D708: addiu       $a0, $zero, 0x4010
    ctx->r4 = ADD32(0, 0X4010);
    after_0:
    // 0x8001D70C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001D710: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8001D714: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8001D718: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8001D71C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001D720: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001D724: jal         0x8004613C
    // 0x8001D728: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8001D728: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8001D72C: beq         $v0, $zero, L_8001D74C
    if (ctx->r2 == 0) {
        // 0x8001D730: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001D74C;
    }
    // 0x8001D730: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001D734: jal         0x80044194
    // 0x8001D738: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8001D738: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8001D73C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001D740: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D744: lwc1        $f4, -0x454($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X454);
    // 0x8001D748: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
L_8001D74C:
    // 0x8001D74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D754: jr          $ra
    // 0x8001D758: nop

    return;
    // 0x8001D758: nop

    // 0x8001D75C: nop

;}
RECOMP_FUNC void func_8046D308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046D308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046D30C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046D310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8046D314: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8046D318: jal         0x800447C8
    // 0x8046D31C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8046D31C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046D320: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8046D324: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8046D328: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8046D32C: lui         $a1, 0x8047
    ctx->r5 = S32(RELOC_HI16(143, 0X13A4) << 16);
    // 0x8046D330: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8046D334: addiu       $a1, $a1, -0x280C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(143, 0X13A4));
    // 0x8046D338: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8046D33C: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8046D340: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8046D344: jalr        $t9
    // 0x8046D348: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8046D348: nop

    after_1:
    // 0x8046D34C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046D350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046D354: jr          $ra
    // 0x8046D358: nop

    return;
    // 0x8046D358: nop

;}
RECOMP_FUNC void func_80681894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681894: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80681898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8068189C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806818A0: jal         0x80047090
    // 0x806818A4: addiu       $a0, $zero, 0x4596
    ctx->r4 = ADD32(0, 0X4596);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806818A4: addiu       $a0, $zero, 0x4596
    ctx->r4 = ADD32(0, 0X4596);
    after_0:
    // 0x806818A8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806818AC: bne         $v0, $at, L_806818BC
    if (ctx->r2 != ctx->r1) {
        // 0x806818B0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806818BC;
    }
    // 0x806818B0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806818B4: b           L_80681934
    // 0x806818B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80681934;
    // 0x806818B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806818BC:
    // 0x806818BC: lui         $at, 0x4596
    ctx->r1 = S32(0X4596 << 16);
    // 0x806818C0: lui         $a3, 0x3E24
    ctx->r7 = S32(0X3E24 << 16);
    // 0x806818C4: ori         $a3, $a3, 0xD800
    ctx->r7 = ctx->r7 | 0XD800;
    // 0x806818C8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x806818CC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x806818D0: lui         $a2, 0xC198
    ctx->r6 = S32(0XC198 << 16);
    // 0x806818D4: jal         0x8004613C
    // 0x806818D8: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806818D8: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x806818DC: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x806818E0: bne         $v0, $zero, L_806818F0
    if (ctx->r2 != 0) {
        // 0x806818E4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806818F0;
    }
    // 0x806818E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806818E8: b           L_80681934
    // 0x806818EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80681934;
    // 0x806818EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806818F0:
    // 0x806818F0: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x806818F4: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x806818F8: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806818FC: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80681900: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x80681904: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80681908: jal         0x80047F9C
    // 0x8068190C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8068190C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80681910: jal         0x80682070
    // 0x80681914: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80682070(rdram, ctx);
        goto after_3;
    // 0x80681914: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80681918: bne         $v0, $zero, L_80681928
    if (ctx->r2 != 0) {
        // 0x8068191C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80681928;
    }
    // 0x8068191C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80681920: b           L_80681934
    // 0x80681924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80681934;
    // 0x80681924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80681928:
    // 0x80681928: jal         0x8005FDC4
    // 0x8068192C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x8068192C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80681930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80681934:
    // 0x80681934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80681938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8068193C: jr          $ra
    // 0x80681940: nop

    return;
    // 0x80681940: nop

;}
RECOMP_FUNC void func_80516E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80516E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80516E9C: jal         0x80516E40
    // 0x80516EA0: nop

    func_80516E40(rdram, ctx);
        goto after_0;
    // 0x80516EA0: nop

    after_0:
    // 0x80516EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80516EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80516EAC: jr          $ra
    // 0x80516EB0: nop

    return;
    // 0x80516EB0: nop

;}
RECOMP_FUNC void func_8007C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C2F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C2F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C2F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007C2FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007C300: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8007C304: addiu       $t6, $t6, -0x7B10
    ctx->r14 = ADD32(ctx->r14, -0X7B10);
    // 0x8007C308: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8007C30C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8007C310: addiu       $v1, $v1, -0x25F0
    ctx->r3 = ADD32(ctx->r3, -0X25F0);
    // 0x8007C314: bne         $t8, $zero, L_8007C324
    if (ctx->r24 != 0) {
        // 0x8007C318: lw          $t9, 0x4($t6)
        ctx->r25 = MEM_W(ctx->r14, 0X4);
            goto L_8007C324;
    }
    // 0x8007C318: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8007C31C: beql        $t9, $zero, L_8007C530
    if (ctx->r25 == 0) {
        // 0x8007C320: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007C530;
    }
    goto skip_0;
    // 0x8007C320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8007C324:
    // 0x8007C324: lw          $t7, 0x58($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X58);
    // 0x8007C328: beql        $t7, $zero, L_8007C530
    if (ctx->r15 == 0) {
        // 0x8007C32C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007C530;
    }
    goto skip_1;
    // 0x8007C32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8007C330: jal         0x8007C030
    // 0x8007C334: nop

    func_8007C030(rdram, ctx);
        goto after_0;
    // 0x8007C334: nop

    after_0:
    // 0x8007C338: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8007C33C: addiu       $v1, $v1, -0x25F0
    ctx->r3 = ADD32(ctx->r3, -0X25F0);
    // 0x8007C340: lw          $t2, 0x58($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X58);
    // 0x8007C344: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C348: lw          $t3, 0x58($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X58);
    // 0x8007C34C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8007C350: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x8007C354: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x8007C358: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007C35C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007C360: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C364: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C368: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007C36C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x8007C370: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x8007C374: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x8007C378: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C37C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007C380: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C384: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007C388: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8007C38C: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x8007C390: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007C394: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007C398: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C39C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007C3A0: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8007C3A4: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8007C3A8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007C3AC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007C3B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C3B4: lui         $t1, 0xF700
    ctx->r9 = S32(0XF700 << 16);
    // 0x8007C3B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007C3BC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007C3C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C3C4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C3C8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007C3CC: lui         $t7, 0x3F
    ctx->r15 = S32(0X3F << 16);
    // 0x8007C3D0: ori         $t7, $t7, 0x3F
    ctx->r15 = ctx->r15 | 0X3F;
    // 0x8007C3D4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007C3D8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8007C3DC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C3E0: andi        $a2, $t3, 0x3FF
    ctx->r6 = ctx->r11 & 0X3FF;
    // 0x8007C3E4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8007C3E8: lui         $at, 0xF618
    ctx->r1 = S32(0XF618 << 16);
    // 0x8007C3EC: or          $t5, $a2, $at
    ctx->r13 = ctx->r6 | ctx->r1;
    // 0x8007C3F0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007C3F4: andi        $a3, $t2, 0x3FF
    ctx->r7 = ctx->r10 & 0X3FF;
    // 0x8007C3F8: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8007C3FC: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8007C400: or          $t6, $a3, $at
    ctx->r14 = ctx->r7 | ctx->r1;
    // 0x8007C404: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007C408: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007C40C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C410: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007C414: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007C418: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C41C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C420: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007C424: lui         $t8, 0x7C1
    ctx->r24 = S32(0X7C1 << 16);
    // 0x8007C428: ori         $t8, $t8, 0x7C1
    ctx->r24 = ctx->r24 | 0X7C1;
    // 0x8007C42C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007C430: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8007C434: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C438: lui         $at, 0xF628
    ctx->r1 = S32(0XF628 << 16);
    // 0x8007C43C: or          $t9, $a2, $at
    ctx->r25 = ctx->r6 | ctx->r1;
    // 0x8007C440: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007C444: lui         $at, 0x18
    ctx->r1 = S32(0X18 << 16);
    // 0x8007C448: or          $t7, $a3, $at
    ctx->r15 = ctx->r7 | ctx->r1;
    // 0x8007C44C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007C450: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007C454: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C458: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007C45C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007C460: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C464: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C468: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007C46C: lui         $t5, 0xF801
    ctx->r13 = S32(0XF801 << 16);
    // 0x8007C470: ori         $t5, $t5, 0xF801
    ctx->r13 = ctx->r13 | 0XF801;
    // 0x8007C474: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8007C478: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8007C47C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C480: lui         $at, 0xF638
    ctx->r1 = S32(0XF638 << 16);
    // 0x8007C484: or          $t6, $a2, $at
    ctx->r14 = ctx->r6 | ctx->r1;
    // 0x8007C488: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007C48C: lui         $at, 0x28
    ctx->r1 = S32(0X28 << 16);
    // 0x8007C490: or          $t8, $a3, $at
    ctx->r24 = ctx->r7 | ctx->r1;
    // 0x8007C494: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007C498: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007C49C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C4A0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007C4A4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007C4A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C4AC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C4B0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007C4B4: lui         $t9, 0xF83F
    ctx->r25 = S32(0XF83F << 16);
    // 0x8007C4B8: ori         $t9, $t9, 0xF83F
    ctx->r25 = ctx->r25 | 0XF83F;
    // 0x8007C4BC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007C4C0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8007C4C4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C4C8: lui         $at, 0xF648
    ctx->r1 = S32(0XF648 << 16);
    // 0x8007C4CC: or          $t7, $a2, $at
    ctx->r15 = ctx->r6 | ctx->r1;
    // 0x8007C4D0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007C4D4: lui         $at, 0x38
    ctx->r1 = S32(0X38 << 16);
    // 0x8007C4D8: or          $t5, $a3, $at
    ctx->r13 = ctx->r7 | ctx->r1;
    // 0x8007C4DC: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8007C4E0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007C4E4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C4E8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8007C4EC: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8007C4F0: addiu       $v1, $v1, -0x2570
    ctx->r3 = ADD32(ctx->r3, -0X2570);
    // 0x8007C4F4: addiu       $t6, $t6, -0x69C0
    ctx->r14 = ADD32(ctx->r14, -0X69C0);
    // 0x8007C4F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007C4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C500: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
L_8007C504:
    // 0x8007C504: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8007C508: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007C50C: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x8007C510: bne         $v0, $a1, L_8007C504
    if (ctx->r2 != ctx->r5) {
        // 0x8007C514: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_8007C504;
    }
    // 0x8007C514: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007C518: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007C51C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007C520: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C524: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8007C528: sw          $a0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r4;
    // 0x8007C52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007C530:
    // 0x8007C530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C534: jr          $ra
    // 0x8007C538: nop

    return;
    // 0x8007C538: nop

    // 0x8007C53C: nop

;}
RECOMP_FUNC void func_8079B994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079B994: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079B998: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8079B99C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8079B9A0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8079B9A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8079B9A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8079B9AC: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x8079B9B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8079B9B4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8079B9B8: beq         $v1, $zero, L_8079B9F0
    if (ctx->r3 == 0) {
        // 0x8079B9BC: addiu       $s3, $zero, 0x20
        ctx->r19 = ADD32(0, 0X20);
            goto L_8079B9F0;
    }
    // 0x8079B9BC: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x8079B9C0: lw          $s0, 0x1F4($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X1F4);
L_8079B9C4:
    // 0x8079B9C4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8079B9C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8079B9CC: bnel        $s1, $t6, L_8079B9E8
    if (ctx->r17 != ctx->r14) {
        // 0x8079B9D0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8079B9E8;
    }
    goto skip_0;
    // 0x8079B9D0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
    // 0x8079B9D4: jal         0x80048060
    // 0x8079B9D8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    func_80048060(rdram, ctx);
        goto after_0;
    // 0x8079B9D8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_0:
    // 0x8079B9DC: jal         0x800440E4
    // 0x8079B9E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800440E4(rdram, ctx);
        goto after_1;
    // 0x8079B9E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8079B9E4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8079B9E8:
    // 0x8079B9E8: bne         $s2, $s3, L_8079B9C4
    if (ctx->r18 != ctx->r19) {
        // 0x8079B9EC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8079B9C4;
    }
    // 0x8079B9EC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8079B9F0:
    // 0x8079B9F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8079B9F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8079B9F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8079B9FC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8079BA00: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8079BA04: jr          $ra
    // 0x8079BA08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8079BA08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805CC2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CC2D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CC2DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CC2E0: jal         0x805CC370
    // 0x805CC2E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805CC370(rdram, ctx);
        goto after_0;
    // 0x805CC2E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805CC2E8: beq         $v0, $zero, L_805CC358
    if (ctx->r2 == 0) {
        // 0x805CC2EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805CC358;
    }
    // 0x805CC2EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805CC2F0: jal         0x805CC3B8
    // 0x805CC2F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805CC3B8(rdram, ctx);
        goto after_1;
    // 0x805CC2F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x805CC2F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805CC2FC: addiu       $at, $zero, 0x4529
    ctx->r1 = ADD32(0, 0X4529);
    // 0x805CC300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805CC304: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805CC308: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805CC30C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805CC310: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805CC314: beq         $v0, $at, L_805CC330
    if (ctx->r2 == ctx->r1) {
        // 0x805CC318: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_805CC330;
    }
    // 0x805CC318: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x805CC31C: addiu       $at, $zero, 0x45E9
    ctx->r1 = ADD32(0, 0X45E9);
    // 0x805CC320: beq         $v0, $at, L_805CC344
    if (ctx->r2 == ctx->r1) {
        // 0x805CC324: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_805CC344;
    }
    // 0x805CC324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805CC328: b           L_805CC364
    // 0x805CC32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805CC364;
    // 0x805CC32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CC330:
    // 0x805CC330: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805CC334: jal         0x805CC554
    // 0x805CC338: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_805CC554(rdram, ctx);
        goto after_2;
    // 0x805CC338: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_2:
    // 0x805CC33C: b           L_805CC364
    // 0x805CC340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805CC364;
    // 0x805CC340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CC344:
    // 0x805CC344: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805CC348: jal         0x805CC554
    // 0x805CC34C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_805CC554(rdram, ctx);
        goto after_3;
    // 0x805CC34C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_3:
    // 0x805CC350: b           L_805CC364
    // 0x805CC354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805CC364;
    // 0x805CC354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CC358:
    // 0x805CC358: jal         0x800445A4
    // 0x805CC35C: nop

    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x805CC35C: nop

    after_4:
    // 0x805CC360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CC364:
    // 0x805CC364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CC368: jr          $ra
    // 0x805CC36C: nop

    return;
    // 0x805CC36C: nop

;}
RECOMP_FUNC void func_8049EEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049EEA4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8049EEA8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8049EEAC: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8049EEB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8049EEB4: nop

    // 0x8049EEB8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8049EEBC: nop

    // 0x8049EEC0: bc1fl       L_8049EEF4
    if (!c1cs) {
        // 0x8049EEC4: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8049EEF4;
    }
    goto skip_0;
    // 0x8049EEC4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8049EEC8: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8049EECC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8049EED0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8049EED4: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8049EED8: nop

    // 0x8049EEDC: bc1f        L_8049EF10
    if (!c1cs) {
        // 0x8049EEE0: nop
    
            goto L_8049EF10;
    }
    // 0x8049EEE0: nop

    // 0x8049EEE4: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8049EEE8: jr          $ra
    // 0x8049EEEC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x8049EEEC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8049EEF0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_8049EEF4:
    // 0x8049EEF4: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8049EEF8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8049EEFC: nop

    // 0x8049EF00: bc1f        L_8049EF10
    if (!c1cs) {
        // 0x8049EF04: nop
    
            goto L_8049EF10;
    }
    // 0x8049EF04: nop

    // 0x8049EF08: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8049EF0C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8049EF10:
    // 0x8049EF10: jr          $ra
    // 0x8049EF14: nop

    return;
    // 0x8049EF14: nop

;}
RECOMP_FUNC void func_8043B728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043B72C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043B730: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8043B734: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8043B738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043B73C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043B740: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043B744: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8043B748: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043B74C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8043B750: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(83, 0X1194) << 16);
    // 0x8043B754: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8043B758: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8043B75C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8043B760: lw          $t2, -0x480C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(83, 0X1194));
    // 0x8043B764: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8043B768: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8043B76C: jal         0x8043A7D4
    // 0x8043B770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043A7D4(rdram, ctx);
        goto after_0;
    // 0x8043B770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043B774: jal         0x8043A830
    // 0x8043B778: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043A830(rdram, ctx);
        goto after_1;
    // 0x8043B778: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043B77C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043B780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043B784: jr          $ra
    // 0x8043B788: nop

    return;
    // 0x8043B788: nop

    // 0x8043B78C: nop

;}
RECOMP_FUNC void func_80068C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C74: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80068C78: lw          $t9, 0x6ECC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6ECC);
    // 0x80068C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068C84: jalr        $t9
    // 0x80068C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80068C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068C8C: bne         $v0, $zero, L_80068CA8
    if (ctx->r2 != 0) {
        // 0x80068C90: lui         $t7, 0x8007
        ctx->r15 = S32(0X8007 << 16);
            goto L_80068CA8;
    }
    // 0x80068C90: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80068C94: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80068C98: addiu       $t6, $t6, -0x7400
    ctx->r14 = ADD32(ctx->r14, -0X7400);
    // 0x80068C9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80068CA0: b           L_80068CC4
    // 0x80068CA4: sw          $t6, 0x6ECC($at)
    MEM_W(0X6ECC, ctx->r1) = ctx->r14;
        goto L_80068CC4;
    // 0x80068CA4: sw          $t6, 0x6ECC($at)
    MEM_W(0X6ECC, ctx->r1) = ctx->r14;
L_80068CA8:
    // 0x80068CA8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80068CAC: addiu       $t7, $t7, -0x7440
    ctx->r15 = ADD32(ctx->r15, -0X7440);
    // 0x80068CB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80068CB4: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80068CB8: sw          $t7, 0x6ECC($at)
    MEM_W(0X6ECC, ctx->r1) = ctx->r15;
    // 0x80068CBC: addiu       $t8, $t8, -0x726C
    ctx->r24 = ADD32(ctx->r24, -0X726C);
    // 0x80068CC0: sw          $t8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r24;
L_80068CC4:
    // 0x80068CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068CC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068CCC: jr          $ra
    // 0x80068CD0: nop

    return;
    // 0x80068CD0: nop

;}
RECOMP_FUNC void func_80554890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80554894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80554898: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8055489C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805548A0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805548A4: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x805548A8: jal         0x8005FCA8
    // 0x805548AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x805548AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805548B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805548B4: lui         $t9, 0x8055
    ctx->r25 = S32(RELOC_HI16(354, 0X3E08) << 16);
    // 0x805548B8: addiu       $t9, $t9, 0x4928
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(354, 0X3E08));
    // 0x805548BC: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x805548C0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x805548C4: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    // 0x805548C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805548CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805548D0: jr          $ra
    // 0x805548D4: nop

    return;
    // 0x805548D4: nop

;}
RECOMP_FUNC void func_80737D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737D34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80737D38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80737D3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80737D40: jal         0x80737B68
    // 0x80737D44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80737B68(rdram, ctx);
        goto after_0;
    // 0x80737D44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80737D48: jal         0x8073751C
    // 0x80737D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073751C(rdram, ctx);
        goto after_1;
    // 0x80737D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80737D50: jal         0x80737120
    // 0x80737D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737120(rdram, ctx);
        goto after_2;
    // 0x80737D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80737D58: jal         0x80737208
    // 0x80737D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737208(rdram, ctx);
        goto after_3;
    // 0x80737D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80737D60: jal         0x80737C4C
    // 0x80737D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737C4C(rdram, ctx);
        goto after_4;
    // 0x80737D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80737D68: jal         0x80737490
    // 0x80737D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737490(rdram, ctx);
        goto after_5;
    // 0x80737D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80737D70: jal         0x80737B98
    // 0x80737D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737B98(rdram, ctx);
        goto after_6;
    // 0x80737D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80737D78: beq         $v0, $zero, L_80737DA4
    if (ctx->r2 == 0) {
        // 0x80737D7C: nop
    
            goto L_80737DA4;
    }
    // 0x80737D7C: nop

    // 0x80737D80: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80737D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80737D88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80737D8C: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x80737D90: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x80737D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80737D98: sw          $zero, 0x18($t7)
    MEM_W(0X18, ctx->r15) = 0;
    // 0x80737D9C: jal         0x80738050
    // 0x80737DA0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80738050(rdram, ctx);
        goto after_7;
    // 0x80737DA0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
L_80737DA4:
    // 0x80737DA4: jal         0x80735B8C
    // 0x80737DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80735B8C(rdram, ctx);
        goto after_8;
    // 0x80737DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80737DAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80737DB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80737DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80737DB8: jr          $ra
    // 0x80737DBC: nop

    return;
    // 0x80737DBC: nop

;}
RECOMP_FUNC void func_804BD5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD5A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BD5A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD5A8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BD5AC: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x804BD5B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804BD5B4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x804BD5B8: jal         0x80065728
    // 0x804BD5BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x804BD5BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BD5C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804BD5C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BD5C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804BD5CC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804BD5D0: sh          $zero, 0xE4($a0)
    MEM_H(0XE4, ctx->r4) = 0;
    // 0x804BD5D4: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x804BD5D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x804BD5DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_804BD5E0:
    // 0x804BD5E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x804BD5E4: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x804BD5E8: bne         $v1, $a0, L_804BD5E0
    if (ctx->r3 != ctx->r4) {
        // 0x804BD5EC: addiu       $v0, $v0, 0x4C
        ctx->r2 = ADD32(ctx->r2, 0X4C);
            goto L_804BD5E0;
    }
    // 0x804BD5EC: addiu       $v0, $v0, 0x4C
    ctx->r2 = ADD32(ctx->r2, 0X4C);
    // 0x804BD5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BD5F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BD5F8: jr          $ra
    // 0x804BD5FC: nop

    return;
    // 0x804BD5FC: nop

;}
RECOMP_FUNC void func_806ED57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED57C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806ED580: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806ED584: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x806ED588: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_806ED58C:
    // 0x806ED58C: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x806ED590: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x806ED594: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806ED598: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x806ED59C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806ED5A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806ED5A4: bc1f        L_806ED5C8
    if (!c1cs) {
        // 0x806ED5A8: swc1        $f8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
            goto L_806ED5C8;
    }
    // 0x806ED5A8: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x806ED5AC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806ED5B0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806ED5B4: nop

    // 0x806ED5B8: bc1f        L_806ED5E0
    if (!c1cs) {
        // 0x806ED5BC: nop
    
            goto L_806ED5E0;
    }
    // 0x806ED5BC: nop

    // 0x806ED5C0: b           L_806ED5E0
    // 0x806ED5C4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_806ED5E0;
    // 0x806ED5C4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_806ED5C8:
    // 0x806ED5C8: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806ED5CC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806ED5D0: nop

    // 0x806ED5D4: bc1f        L_806ED5E0
    if (!c1cs) {
        // 0x806ED5D8: nop
    
            goto L_806ED5E0;
    }
    // 0x806ED5D8: nop

    // 0x806ED5DC: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_806ED5E0:
    // 0x806ED5E0: bne         $v1, $v0, L_806ED58C
    if (ctx->r3 != ctx->r2) {
        // 0x806ED5E4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_806ED58C;
    }
    // 0x806ED5E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806ED5E8: jr          $ra
    // 0x806ED5EC: nop

    return;
    // 0x806ED5EC: nop

;}
RECOMP_FUNC void func_800372EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800372EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800372F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800372F4: jal         0x80023D3C
    // 0x800372F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80023D3C(rdram, ctx);
        goto after_0;
    // 0x800372F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800372FC: jal         0x800240C0
    // 0x80037300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800240C0(rdram, ctx);
        goto after_1;
    // 0x80037300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80037304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003730C: jr          $ra
    // 0x80037310: nop

    return;
    // 0x80037310: nop

;}
RECOMP_FUNC void func_80678DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678DEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80678DF0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80678DF4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80678DF8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80678DFC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80678E00: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80678E04: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80678E08: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80678E0C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80678E10: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80678E14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80678E18: jal         0x80679364
    // 0x80678E1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80679364(rdram, ctx);
        goto after_0;
    // 0x80678E1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80678E20: lwc1        $f4, 0x84($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X84);
    // 0x80678E24: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80678E28: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80678E2C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80678E30: lwc1        $f6, 0x88($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X88);
    // 0x80678E34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80678E38: addiu       $s5, $zero, 0xF
    ctx->r21 = ADD32(0, 0XF);
    // 0x80678E3C: addiu       $s4, $sp, 0x46
    ctx->r20 = ADD32(ctx->r29, 0X46);
    // 0x80678E40: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x80678E44: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x80678E48: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
L_80678E4C:
    // 0x80678E4C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80678E50: jal         0x80053924
    // 0x80678E54: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    func_80053924(rdram, ctx);
        goto after_1;
    // 0x80678E54: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80678E58: beq         $s2, $v0, L_80678E70
    if (ctx->r18 == ctx->r2) {
        // 0x80678E5C: sh          $v0, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r2;
            goto L_80678E70;
    }
    // 0x80678E5C: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x80678E60: lbu         $t6, 0x0($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X0);
    // 0x80678E64: andi        $t7, $t6, 0xF8
    ctx->r15 = ctx->r14 & 0XF8;
    // 0x80678E68: beql        $s3, $t7, L_80678E9C
    if (ctx->r19 == ctx->r15) {
        // 0x80678E6C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80678E9C;
    }
    goto skip_0;
    // 0x80678E6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
L_80678E70:
    // 0x80678E70: lwc1        $f8, 0x40($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80678E74: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80678E78: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80678E7C: swc1        $f10, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f10.u32l;
    // 0x80678E80: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80678E84: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80678E88: bne         $s0, $s5, L_80678E4C
    if (ctx->r16 != ctx->r21) {
        // 0x80678E8C: swc1        $f18, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
            goto L_80678E4C;
    }
    // 0x80678E8C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80678E90: jal         0x800447C8
    // 0x80678E94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x80678E94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80678E98: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80678E9C:
    // 0x80678E9C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80678EA0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80678EA4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80678EA8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80678EAC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80678EB0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80678EB4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80678EB8: jr          $ra
    // 0x80678EBC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80678EBC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_806CE828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CE828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CE82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CE830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806CE834: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x806CE838: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806CE83C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x806CE840: beq         $t6, $at, L_806CE850
    if (ctx->r14 == ctx->r1) {
        // 0x806CE844: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_806CE850;
    }
    // 0x806CE844: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806CE848: b           L_806CE8C0
    // 0x806CE84C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806CE8C0;
    // 0x806CE84C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806CE850:
    // 0x806CE850: sb          $t7, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r15;
    // 0x806CE854: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x806CE858: lw          $t9, 0x1C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1C);
    // 0x806CE85C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806CE860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CE864: jalr        $t9
    // 0x806CE868: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806CE868: nop

    after_0:
    // 0x806CE86C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x806CE870: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x806CE874: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CE878: lwc1        $f4, 0x84($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X84);
    // 0x806CE87C: lwc1        $f6, 0x84($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X84);
    // 0x806CE880: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806CE884: nop

    // 0x806CE888: bc1fl       L_806CE8A8
    if (!c1cs) {
        // 0x806CE88C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_806CE8A8;
    }
    goto skip_0;
    // 0x806CE88C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x806CE890: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806CE894: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CE898: addiu       $v1, $a2, 0xC4
    ctx->r3 = ADD32(ctx->r6, 0XC4);
    // 0x806CE89C: b           L_806CE8B0
    // 0x806CE8A0: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
        goto L_806CE8B0;
    // 0x806CE8A0: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x806CE8A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_806CE8A8:
    // 0x806CE8A8: addiu       $v1, $a2, 0xC4
    ctx->r3 = ADD32(ctx->r6, 0XC4);
    // 0x806CE8AC: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_806CE8B0:
    // 0x806CE8B0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806CE8B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806CE8B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806CE8BC: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
L_806CE8C0:
    // 0x806CE8C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CE8C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CE8C8: jr          $ra
    // 0x806CE8CC: nop

    return;
    // 0x806CE8CC: nop

;}
RECOMP_FUNC void func_8059FF10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059FF10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059FF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059FF18: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8059FF1C: addiu       $at, $zero, 0x405A
    ctx->r1 = ADD32(0, 0X405A);
    // 0x8059FF20: bnel        $t6, $at, L_8059FF68
    if (ctx->r14 != ctx->r1) {
        // 0x8059FF24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8059FF68;
    }
    goto skip_0;
    // 0x8059FF24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8059FF28: lw          $a0, 0x180($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X180);
    // 0x8059FF2C: beql        $a0, $zero, L_8059FF68
    if (ctx->r4 == 0) {
        // 0x8059FF30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8059FF68;
    }
    goto skip_1;
    // 0x8059FF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8059FF34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059FF38: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FF3C: andi        $t8, $v1, 0x8
    ctx->r24 = ctx->r3 & 0X8;
    // 0x8059FF40: beql        $t8, $zero, L_8059FF60
    if (ctx->r24 == 0) {
        // 0x8059FF44: ori         $t9, $v1, 0x8
        ctx->r25 = ctx->r3 | 0X8;
            goto L_8059FF60;
    }
    goto skip_2;
    // 0x8059FF44: ori         $t9, $v1, 0x8
    ctx->r25 = ctx->r3 | 0X8;
    skip_2:
    // 0x8059FF48: jal         0x8059F3CC
    // 0x8059FF4C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8059F3CC(rdram, ctx);
        goto after_0;
    // 0x8059FF4C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8059FF50: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8059FF54: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059FF58: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FF5C: ori         $t9, $v1, 0x8
    ctx->r25 = ctx->r3 | 0X8;
L_8059FF60:
    // 0x8059FF60: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x8059FF64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8059FF68:
    // 0x8059FF68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8059FF6C: jr          $ra
    // 0x8059FF70: nop

    return;
    // 0x8059FF70: nop

;}
RECOMP_FUNC void func_80430F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430F44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430F4C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80430F50: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80430F54: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80430F58: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(56, 0X3150) << 16);
    // 0x80430F5C: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x80430F60: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80430F64: addiu       $t7, $t7, 0x1230
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(56, 0X3150));
    // 0x80430F68: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80430F6C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80430F70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80430F74: jal         0x80045A34
    // 0x80430F78: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80430F78: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x80430F7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80430F80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80430F84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80430F88: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80430F8C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80430F90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80430F94: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80430F98: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430F9C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80430FA0: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80430FA4: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x80430FA8: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430FAC: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80430FB0: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80430FB4: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430FB8: swc1        $f0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f0.u32l;
    // 0x80430FBC: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430FC0: swc1        $f0, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f0.u32l;
    // 0x80430FC4: lw          $t3, 0x1F4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430FC8: swc1        $f10, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f10.u32l;
    // 0x80430FCC: lw          $t4, 0x1F4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430FD0: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x80430FD4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430FD8: jal         0x800653D8
    // 0x80430FDC: sh          $t5, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = ctx->r13;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80430FDC: sh          $t5, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = ctx->r13;
    after_1:
    // 0x80430FE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80430FE4: lui         $at, 0x3F20
    ctx->r1 = S32(0X3F20 << 16);
    // 0x80430FE8: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80430FEC: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430FF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80430FF4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80430FF8: sw          $t8, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r24;
    // 0x80430FFC: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x80431000: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x80431004: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x80431008: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043100C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80431010: jal         0x804311BC
    // 0x80431014: lw          $a3, 0x20($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X20);
    func_804311BC(rdram, ctx);
        goto after_2;
    // 0x80431014: lw          $a3, 0x20($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X20);
    after_2:
    // 0x80431018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043101C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80431020: jr          $ra
    // 0x80431024: nop

    return;
    // 0x80431024: nop

;}
RECOMP_FUNC void func_80790774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80790778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079077C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80790780: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80790784: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80790788: jal         0x80067BBC
    // 0x8079078C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8079078C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80790790: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80790794: jal         0x80067818
    // 0x80790798: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80790798: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8079079C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807907A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807907A4: jr          $ra
    // 0x807907A8: nop

    return;
    // 0x807907A8: nop

;}
RECOMP_FUNC void func_804CB9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB9B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CB9B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CB9BC: lwc1        $f0, 0xC8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804CB9C0: lwc1        $f6, 0x104($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X104);
    // 0x804CB9C4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13FC) << 16);
    // 0x804CB9C8: lwc1        $f4, -0x40C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13FC));
    // 0x804CB9CC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804CB9D0: lwc1        $f18, 0x110($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X110);
    // 0x804CB9D4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804CB9D8: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x804CB9DC: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x804CB9E0: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804CB9E4: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
    // 0x804CB9E8: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x804CB9EC: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804CB9F0: lw          $t6, -0x7BC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BC4);
    // 0x804CB9F4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804CB9F8: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804CB9FC: lwc1        $f4, 0x40($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X40);
    // 0x804CBA00: lwc1        $f18, 0xCC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x804CBA04: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x804CBA08: lwc1        $f6, 0x114($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X114);
    // 0x804CBA0C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x804CBA10: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x804CBA14: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x804CBA18: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x804CBA1C: lwc1        $f16, 0x100($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X100);
    // 0x804CBA20: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804CBA24: mul.s       $f14, $f16, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x804CBA28: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x804CBA2C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x804CBA30: add.s       $f18, $f12, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804CBA34: swc1        $f14, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f14.u32l;
    // 0x804CBA38: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    // 0x804CBA3C: swc1        $f18, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f18.u32l;
    // 0x804CBA40: jal         0x80066E88
    // 0x804CBA44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x804CBA44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CBA48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CBA4C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804CBA50: lw          $t7, -0x7BC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BC4);
    // 0x804CBA54: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x804CBA58: lwc1        $f4, 0x10C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x804CBA5C: lwc1        $f16, 0x3C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x804CBA60: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804CBA64: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804CBA68: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804CBA6C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x804CBA70: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x804CBA74: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x804CBA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CBA7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CBA80: jr          $ra
    // 0x804CBA84: nop

    return;
    // 0x804CBA84: nop

;}
RECOMP_FUNC void func_804A1928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A192C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A1930: jal         0x804A1820
    // 0x804A1934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A1820(rdram, ctx);
        goto after_0;
    // 0x804A1934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A1938: bne         $v0, $zero, L_804A1968
    if (ctx->r2 != 0) {
        // 0x804A193C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A1968;
    }
    // 0x804A193C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A1940: jal         0x804A2910
    // 0x804A1944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A2910(rdram, ctx);
        goto after_1;
    // 0x804A1944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x804A1948: beq         $v0, $zero, L_804A1968
    if (ctx->r2 == 0) {
        // 0x804A194C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A1968;
    }
    // 0x804A194C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A1950: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804A1954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A1958: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804A195C: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x804A1960: jal         0x804A27A0
    // 0x804A1964: andi        $a2, $t7, 0xFF
    ctx->r6 = ctx->r15 & 0XFF;
    func_804A27A0(rdram, ctx);
        goto after_2;
    // 0x804A1964: andi        $a2, $t7, 0xFF
    ctx->r6 = ctx->r15 & 0XFF;
    after_2:
L_804A1968:
    // 0x804A1968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A196C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A1970: jr          $ra
    // 0x804A1974: nop

    return;
    // 0x804A1974: nop

;}
RECOMP_FUNC void func_800274D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800274D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800274D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800274DC: jal         0x800274BC
    // 0x800274E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800274BC(rdram, ctx);
        goto after_0;
    // 0x800274E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800274E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800274E8: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x800274EC: addiu       $t6, $t6, 0x73F4
    ctx->r14 = ADD32(ctx->r14, 0X73F4);
    // 0x800274F0: sw          $t6, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r14;
    // 0x800274F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800274F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800274FC: jr          $ra
    // 0x80027500: nop

    return;
    // 0x80027500: nop

;}
RECOMP_FUNC void func_80021B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021B44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80021B48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80021B4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80021B50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80021B54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80021B58: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80021B5C: lw          $s2, 0x174($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X174);
    // 0x80021B60: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80021B64: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80021B68: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80021B6C: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80021B70: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021B74: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80021B78: jal         0x80020820
    // 0x80021B7C: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    func_80020820(rdram, ctx);
        goto after_0;
    // 0x80021B7C: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    after_0:
    // 0x80021B80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021B84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021B88: jal         0x80020ADC
    // 0x80021B8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80020ADC(rdram, ctx);
        goto after_1;
    // 0x80021B8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80021B90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021B94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021B98: jal         0x80020DBC
    // 0x80021B9C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80020DBC(rdram, ctx);
        goto after_2;
    // 0x80021B9C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80021BA0: jal         0x8002181C
    // 0x80021BA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002181C(rdram, ctx);
        goto after_3;
    // 0x80021BA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80021BA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021BAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80021BB0: jal         0x80021884
    // 0x80021BB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80021884(rdram, ctx);
        goto after_4;
    // 0x80021BB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x80021BB8: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x80021BBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021BC0: beql        $t8, $zero, L_80021BD8
    if (ctx->r24 == 0) {
        // 0x80021BC4: lw          $t1, 0x38($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X38);
            goto L_80021BD8;
    }
    goto skip_0;
    // 0x80021BC4: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x80021BC8: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x80021BCC: ori         $t0, $t9, 0x700
    ctx->r8 = ctx->r25 | 0X700;
    // 0x80021BD0: sw          $t0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r8;
    // 0x80021BD4: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
L_80021BD8:
    // 0x80021BD8: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x80021BDC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80021BE0: sw          $t1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r9;
    // 0x80021BE4: jal         0x8001EA24
    // 0x80021BE8: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    func_8001EA24(rdram, ctx);
        goto after_5;
    // 0x80021BE8: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    after_5:
    // 0x80021BEC: lbu         $t3, 0x30($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X30);
    // 0x80021BF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80021BF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021BF8: bne         $t3, $at, L_80021C34
    if (ctx->r11 != ctx->r1) {
        // 0x80021BFC: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80021C34;
    }
    // 0x80021BFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021C00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021C04: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021C08: jal         0x8001F99C
    // 0x80021C0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F99C(rdram, ctx);
        goto after_6;
    // 0x80021C0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x80021C10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021C14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80021C18: jal         0x80021884
    // 0x80021C1C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80021884(rdram, ctx);
        goto after_7;
    // 0x80021C1C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_7:
    // 0x80021C20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021C24: jal         0x80020508
    // 0x80021C28: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80020508(rdram, ctx);
        goto after_8;
    // 0x80021C28: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x80021C2C: b           L_80021C5C
    // 0x80021C30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80021C5C;
    // 0x80021C30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80021C34:
    // 0x80021C34: jal         0x8001F904
    // 0x80021C38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F904(rdram, ctx);
        goto after_9;
    // 0x80021C38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80021C3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021C40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80021C44: jal         0x80021884
    // 0x80021C48: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80021884(rdram, ctx);
        goto after_10;
    // 0x80021C48: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_10:
    // 0x80021C4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021C50: jal         0x800202B4
    // 0x80021C54: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800202B4(rdram, ctx);
        goto after_11;
    // 0x80021C54: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x80021C58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80021C5C:
    // 0x80021C5C: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x80021C60: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x80021C64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80021C68: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80021C6C: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x80021C70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80021C74: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80021C78: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021C7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021C80: jr          $ra
    // 0x80021C84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80021C84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80517110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517110: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(285, 0X108) << 16);
    // 0x80517114: addiu       $v0, $v0, 0x7218
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(285, 0X108));
    // 0x80517118: jr          $ra
    // 0x8051711C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8051711C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80527DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527DF4: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80527DF8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X61AC) << 16);
    // 0x80527DFC: lwc1        $f6, -0x3F54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X61AC));
    // 0x80527E00: lwc1        $f2, 0x30($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527E04: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80527E08: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X61B0) << 16);
    // 0x80527E0C: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80527E10: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80527E14: nop

    // 0x80527E18: bc1tl       L_80527E80
    if (c1cs) {
        // 0x80527E1C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80527E80;
    }
    goto skip_0;
    // 0x80527E1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80527E20: lwc1        $f8, -0x3F50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X61B0));
    // 0x80527E24: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80527E28: nop

    // 0x80527E2C: bc1tl       L_80527E80
    if (c1cs) {
        // 0x80527E30: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80527E80;
    }
    goto skip_1;
    // 0x80527E30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80527E34: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80527E38: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x80527E3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80527E40: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x80527E44: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80527E48: bgez        $v0, L_80527E60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80527E4C: swc1        $f10, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
            goto L_80527E60;
    }
    // 0x80527E4C: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
    // 0x80527E50: jal         0x805276E0
    // 0x80527E54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_805276E0(rdram, ctx);
        goto after_0;
    // 0x80527E54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80527E58: b           L_80527E94
    // 0x80527E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80527E94;
    // 0x80527E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527E60:
    // 0x80527E60: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80527E64: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80527E68: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80527E6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80527E70: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80527E74: b           L_80527E90
    // 0x80527E78: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80527E90;
    // 0x80527E78: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80527E7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80527E80:
    // 0x80527E80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80527E84: nop

    // 0x80527E88: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80527E8C: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
L_80527E90:
    // 0x80527E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527E94:
    // 0x80527E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527E98: jr          $ra
    // 0x80527E9C: nop

    return;
    // 0x80527E9C: nop

;}
