#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Fault_PrintCharImpl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F69C: lui         $t9, 0xFFFA
    ctx->r25 = S32(0XFFFA << 16);
    // 0x8006F6A0: or          $t3, $sp, $zero
    ctx->r11 = ctx->r29 | 0;
    // 0x8006F6A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F6A8: ori         $t9, $t9, 0x5A5A
    ctx->r25 = ctx->r25 | 0X5A5A;
L_8006F6AC:
    // 0x8006F6AC: addiu       $t3, $t3, -0x8
    ctx->r11 = ADD32(ctx->r11, -0X8);
    // 0x8006F6B0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8006F6B4: bne         $t3, $sp, L_8006F6AC
    if (ctx->r11 != ctx->r29) {
        // 0x8006F6B8: sw          $t9, 0x4($t3)
        MEM_W(0X4, ctx->r11) = ctx->r25;
            goto L_8006F6AC;
    }
    // 0x8006F6B8: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8006F6BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006F6C0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8006F6C4: addiu       $v1, $v1, -0x7968
    ctx->r3 = ADD32(ctx->r3, -0X7968);
    // 0x8006F6C8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8006F6CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F6D0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8006F6D4: bgez        $v0, L_8006F6E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006F6D8: sra         $t6, $v0, 3
        ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8006F6E4;
    }
    // 0x8006F6D8: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8006F6DC: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8006F6E0: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8006F6E4:
    // 0x8006F6E4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8006F6E8: lhu         $t6, 0x5D0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X5D0);
    // 0x8006F6EC: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8006F6F0: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8006F6F4: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F6F8: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8006F6FC: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x8006F700: addiu       $t5, $t5, -0x7FF4
    ctx->r13 = ADD32(ctx->r13, -0X7FF4);
    // 0x8006F704: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8006F708: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x8006F70C: lw          $t9, 0x5CC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X5CC);
    // 0x8006F710: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8006F714: lui         $t6, 0x1000
    ctx->r14 = S32(0X1000 << 16);
    // 0x8006F718: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006F71C: mflo        $t8
    ctx->r24 = lo;
    // 0x8006F720: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8006F724: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8006F728: addu        $a3, $t3, $t4
    ctx->r7 = ADD32(ctx->r11, ctx->r12);
    // 0x8006F72C: addiu       $a2, $a2, -0x7B94
    ctx->r6 = ADD32(ctx->r6, -0X7B94);
    // 0x8006F730: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8006F734: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8006F738: bgez        $v0, L_8006F74C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006F73C: andi        $t5, $v0, 0x3
        ctx->r13 = ctx->r2 & 0X3;
            goto L_8006F74C;
    }
    // 0x8006F73C: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x8006F740: beq         $t5, $zero, L_8006F74C
    if (ctx->r13 == 0) {
        // 0x8006F744: nop
    
            goto L_8006F74C;
    }
    // 0x8006F744: nop

    // 0x8006F748: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
L_8006F74C:
    // 0x8006F74C: sllv        $t2, $t6, $t5
    ctx->r10 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8006F750: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8006F754:
    // 0x8006F754: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006F758: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006F75C:
    // 0x8006F75C: and         $t8, $v0, $a0
    ctx->r24 = ctx->r2 & ctx->r4;
    // 0x8006F760: beq         $t8, $zero, L_8006F770
    if (ctx->r24 == 0) {
        // 0x8006F764: srl         $v0, $v0, 4
        ctx->r2 = S32(U32(ctx->r2) >> 4);
            goto L_8006F770;
    }
    // 0x8006F764: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8006F768: lhu         $t7, 0x0($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X0);
    // 0x8006F76C: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_8006F770:
    // 0x8006F770: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006F774: bne         $v1, $a1, L_8006F75C
    if (ctx->r3 != ctx->r5) {
        // 0x8006F778: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_8006F75C;
    }
    // 0x8006F778: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8006F77C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8006F780: lhu         $v0, -0x7398($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7398);
    // 0x8006F784: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8006F788: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8006F78C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006F790: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8006F794: addiu       $a3, $a3, -0x10
    ctx->r7 = ADD32(ctx->r7, -0X10);
    // 0x8006F798: bnel        $t1, $a1, L_8006F754
    if (ctx->r9 != ctx->r5) {
        // 0x8006F79C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8006F754;
    }
    goto skip_0;
    // 0x8006F79C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    skip_0:
    // 0x8006F7A0: jal         0x80090710
    // 0x8006F7A4: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x8006F7A4: nop

    after_0:
    // 0x8006F7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F7AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F7B0: jr          $ra
    // 0x8006F7B4: nop

    return;
    // 0x8006F7B4: nop

;}
RECOMP_FUNC void func_806EF2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF2D0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EF2D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EF2D8: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x806EF2DC: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x806EF2E0: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x806EF2E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806EF2E8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806EF2EC: jr          $ra
    // 0x806EF2F0: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x806EF2F0: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void _bcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B800: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x8008B804: bne         $at, $zero, L_8008B8E4
    if (ctx->r1 != 0) {
        // 0x8008B808: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_8008B8E4;
    }
    // 0x8008B808: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x8008B80C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8008B810: bne         $v0, $zero, L_8008B878
    if (ctx->r2 != 0) {
        // 0x8008B814: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_8008B878;
    }
    // 0x8008B814: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x8008B818: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x8008B81C: beq         $t8, $zero, L_8008B83C
    if (ctx->r24 == 0) {
        // 0x8008B820: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_8008B83C;
    }
    // 0x8008B820: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x8008B824: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008B828: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x8008B82C: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x8008B830: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8008B834: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8008B838: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B83C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_8008B914;
    }
L_8008B83C:
    // 0x8008B83C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008B840: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8008B844: beq         $a3, $zero, L_8008B8E4
    if (ctx->r7 == 0) {
        // 0x8008B848: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8008B8E4;
    }
    // 0x8008B848: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8008B84C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B850: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8008B854:
    // 0x8008B854: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008B858: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008B85C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008B860: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B864: nop
    
            goto L_8008B914;
    }
    // 0x8008B864: nop

    // 0x8008B868: bnel        $a0, $a3, L_8008B854
    if (ctx->r4 != ctx->r7) {
        // 0x8008B86C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8008B854;
    }
    goto skip_0;
    // 0x8008B86C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8008B870: b           L_8008B8E4
    // 0x8008B874: nop

        goto L_8008B8E4;
    // 0x8008B874: nop

L_8008B878:
    // 0x8008B878: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x8008B87C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x8008B880: beq         $a3, $zero, L_8008B8AC
    if (ctx->r7 == 0) {
        // 0x8008B884: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8008B8AC;
    }
    // 0x8008B884: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8008B888: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B88C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_8008B890:
    // 0x8008B890: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8008B894: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008B898: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008B89C: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B8A0: nop
    
            goto L_8008B914;
    }
    // 0x8008B8A0: nop

    // 0x8008B8A4: bnel        $a0, $a3, L_8008B890
    if (ctx->r4 != ctx->r7) {
        // 0x8008B8A8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_8008B890;
    }
    goto skip_1;
    // 0x8008B8A8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8008B8AC:
    // 0x8008B8AC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008B8B0: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8008B8B4: beq         $a3, $zero, L_8008B8E4
    if (ctx->r7 == 0) {
        // 0x8008B8B8: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8008B8E4;
    }
    // 0x8008B8B8: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8008B8BC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B8C0: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_8008B8C4:
    // 0x8008B8C4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008B8C8: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x8008B8CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008B8D0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008B8D4: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B8D8: nop
    
            goto L_8008B914;
    }
    // 0x8008B8D8: nop

    // 0x8008B8DC: bnel        $a0, $a3, L_8008B8C4
    if (ctx->r4 != ctx->r7) {
        // 0x8008B8E0: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_8008B8C4;
    }
    goto skip_2;
    // 0x8008B8E0: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_8008B8E4:
    // 0x8008B8E4: blez        $a2, L_8008B90C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008B8E8: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_8008B90C;
    }
    // 0x8008B8E8: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x8008B8EC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_8008B8F0:
    // 0x8008B8F0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8008B8F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008B8F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008B8FC: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B900: nop
    
            goto L_8008B914;
    }
    // 0x8008B900: nop

    // 0x8008B904: bnel        $a0, $a3, L_8008B8F0
    if (ctx->r4 != ctx->r7) {
        // 0x8008B908: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_8008B8F0;
    }
    goto skip_3;
    // 0x8008B908: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_8008B90C:
    // 0x8008B90C: jr          $ra
    // 0x8008B910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008B910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008B914:
    // 0x8008B914: jr          $ra
    // 0x8008B918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8008B918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8040A13C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040A13C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8040A140: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8040A144: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8040A148: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x8040A14C: lw          $a1, 0x1F4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1F4);
    // 0x8040A150: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8040A154: lw          $a2, 0x1F4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1F4);
    // 0x8040A158: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x8040A15C: bne         $t6, $zero, L_8040A198
    if (ctx->r14 != 0) {
        // 0x8040A160: nop
    
            goto L_8040A198;
    }
    // 0x8040A160: nop

    // 0x8040A164: lw          $t7, 0x24($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X24);
    // 0x8040A168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8040A16C: bne         $t7, $zero, L_8040A198
    if (ctx->r15 != 0) {
        // 0x8040A170: nop
    
            goto L_8040A198;
    }
    // 0x8040A170: nop

    // 0x8040A174: swc1        $f12, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f12.u32l;
    // 0x8040A178: swc1        $f12, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f12.u32l;
    // 0x8040A17C: swc1        $f12, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f12.u32l;
    // 0x8040A180: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x8040A184: swc1        $f12, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f12.u32l;
    // 0x8040A188: swc1        $f14, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f14.u32l;
    // 0x8040A18C: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x8040A190: sw          $a0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r4;
    // 0x8040A194: sw          $a0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r4;
L_8040A198:
    // 0x8040A198: jr          $ra
    // 0x8040A19C: nop

    return;
    // 0x8040A19C: nop

;}
RECOMP_FUNC void func_805A0388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A0388: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A038C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A0390: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A0394: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x805A0398: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A039C: addiu       $a0, $zero, 0x405A
    ctx->r4 = ADD32(0, 0X405A);
    // 0x805A03A0: jal         0x80047090
    // 0x805A03A4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805A03A4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x805A03A8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805A03AC: bne         $v0, $at, L_805A03BC
    if (ctx->r2 != ctx->r1) {
        // 0x805A03B0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805A03BC;
    }
    // 0x805A03B0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805A03B4: b           L_805A04C0
    // 0x805A03B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A04C0;
    // 0x805A03B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A03BC:
    // 0x805A03BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A03C0: lui         $a0, 0x405A
    ctx->r4 = S32(0X405A << 16);
    // 0x805A03C4: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    // 0x805A03C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A03CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805A03D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805A03D4: jal         0x8004613C
    // 0x805A03D8: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805A03D8: nop

    after_1:
    // 0x805A03DC: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x805A03E0: bne         $v0, $zero, L_805A03F0
    if (ctx->r2 != 0) {
        // 0x805A03E4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805A03F0;
    }
    // 0x805A03E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805A03E8: b           L_805A04C0
    // 0x805A03EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A04C0;
    // 0x805A03EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A03F0:
    // 0x805A03F0: lhu         $t0, 0xE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XE);
    // 0x805A03F4: andi        $t9, $v1, 0x3FF
    ctx->r25 = ctx->r3 & 0X3FF;
    // 0x805A03F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805A03FC: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x805A0400: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x805A0404: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    // 0x805A0408: jal         0x80047F9C
    // 0x805A040C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x805A040C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x805A0410: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x805A0414: jal         0x805A058C
    // 0x805A0418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A058C(rdram, ctx);
        goto after_3;
    // 0x805A0418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A041C: lw          $t3, 0x1E0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E0);
    // 0x805A0420: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805A0424: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x805A0428: bne         $t3, $at, L_805A0438
    if (ctx->r11 != ctx->r1) {
        // 0x805A042C: addiu       $a0, $zero, 0x44FD
        ctx->r4 = ADD32(0, 0X44FD);
            goto L_805A0438;
    }
    // 0x805A042C: addiu       $a0, $zero, 0x44FD
    ctx->r4 = ADD32(0, 0X44FD);
    // 0x805A0430: b           L_805A04C0
    // 0x805A0434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A04C0;
    // 0x805A0434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A0438:
    // 0x805A0438: jal         0x80047090
    // 0x805A043C: sw          $s0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r16;
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x805A043C: sw          $s0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r16;
    after_4:
    // 0x805A0440: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805A0444: bne         $v0, $at, L_805A0454
    if (ctx->r2 != ctx->r1) {
        // 0x805A0448: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805A0454;
    }
    // 0x805A0448: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805A044C: b           L_805A04C0
    // 0x805A0450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A04C0;
    // 0x805A0450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A0454:
    // 0x805A0454: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A0458: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x805A045C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x805A0460: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A0464: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805A0468: lui         $a0, 0x44FD
    ctx->r4 = S32(0X44FD << 16);
    // 0x805A046C: jal         0x8004613C
    // 0x805A0470: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x805A0470: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_5:
    // 0x805A0474: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x805A0478: bne         $v0, $zero, L_805A0488
    if (ctx->r2 != 0) {
        // 0x805A047C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805A0488;
    }
    // 0x805A047C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805A0480: b           L_805A04C0
    // 0x805A0484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A04C0;
    // 0x805A0484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A0488:
    // 0x805A0488: lhu         $t7, 0xE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XE);
    // 0x805A048C: andi        $t6, $v1, 0x3FF
    ctx->r14 = ctx->r3 & 0X3FF;
    // 0x805A0490: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805A0494: andi        $t8, $t7, 0xFC00
    ctx->r24 = ctx->r15 & 0XFC00;
    // 0x805A0498: or          $t0, $t6, $t8
    ctx->r8 = ctx->r14 | ctx->r24;
    // 0x805A049C: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x805A04A0: jal         0x80047F9C
    // 0x805A04A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x805A04A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x805A04A8: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x805A04AC: jal         0x805A0658
    // 0x805A04B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A0658(rdram, ctx);
        goto after_7;
    // 0x805A04B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805A04B4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x805A04B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805A04BC: sw          $s0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r16;
L_805A04C0:
    // 0x805A04C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A04C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A04C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A04CC: jr          $ra
    // 0x805A04D0: nop

    return;
    // 0x805A04D0: nop

;}
RECOMP_FUNC void func_80020888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020888: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002088C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020890: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80020894: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80020898: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002089C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800208A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800208A4: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x800208A8: lw          $v1, 0x40($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X40);
    // 0x800208AC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800208B0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800208B4: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x800208B8: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x800208BC: beql        $v0, $zero, L_80020978
    if (ctx->r2 == 0) {
        // 0x800208C0: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_80020978;
    }
    goto skip_0;
    // 0x800208C0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800208C4: beql        $v0, $at, L_80020978
    if (ctx->r2 == ctx->r1) {
        // 0x800208C8: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_80020978;
    }
    goto skip_1;
    // 0x800208C8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x800208CC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800208D0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x800208D4: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x800208D8: beq         $v0, $at, L_80020974
    if (ctx->r2 == ctx->r1) {
        // 0x800208DC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80020974;
    }
    // 0x800208DC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800208E0: beq         $v0, $at, L_80020974
    if (ctx->r2 == ctx->r1) {
        // 0x800208E4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80020974;
    }
    // 0x800208E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800208E8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x800208EC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800208F0: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x800208F4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800208F8: jal         0x8004D1F0
    // 0x800208FC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x800208FC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80020900: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80020904: jal         0x8004D414
    // 0x80020908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004D414(rdram, ctx);
        goto after_1;
    // 0x80020908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8002090C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80020910: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80020914: lwc1        $f4, -0x404($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X404);
    // 0x80020918: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002091C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80020920: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80020924: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80020928: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8002092C: bc1tl       L_8002094C
    if (c1cs) {
        // 0x80020930: lw          $t8, 0x2C($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X2C);
            goto L_8002094C;
    }
    goto skip_2;
    // 0x80020930: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    skip_2:
    // 0x80020934: lwc1        $f6, -0x400($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X400);
    // 0x80020938: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8002093C: nop

    // 0x80020940: bc1fl       L_80020978
    if (!c1cs) {
        // 0x80020944: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_80020978;
    }
    goto skip_3;
    // 0x80020944: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80020948: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
L_8002094C:
    // 0x8002094C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80020950: ori         $t9, $t8, 0x2000
    ctx->r25 = ctx->r24 | 0X2000;
    // 0x80020954: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    // 0x80020958: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002095C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80020960: nop

    // 0x80020964: bc1fl       L_80020978
    if (!c1cs) {
        // 0x80020968: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_80020978;
    }
    goto skip_4;
    // 0x80020968: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x8002096C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80020970: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80020974:
    // 0x80020974: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
L_80020978:
    // 0x80020978: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002097C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80020980: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80020984: lw          $v1, 0x40($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X40);
    // 0x80020988: lhu         $v0, 0x30($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X30);
    // 0x8002098C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x80020990: beql        $v0, $zero, L_80020A4C
    if (ctx->r2 == 0) {
        // 0x80020994: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80020A4C;
    }
    goto skip_5;
    // 0x80020994: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_5:
    // 0x80020998: beql        $v0, $at, L_80020A4C
    if (ctx->r2 == ctx->r1) {
        // 0x8002099C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80020A4C;
    }
    goto skip_6;
    // 0x8002099C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_6:
    // 0x800209A0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800209A4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x800209A8: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x800209AC: beq         $v0, $at, L_80020A48
    if (ctx->r2 == ctx->r1) {
        // 0x800209B0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80020A48;
    }
    // 0x800209B0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800209B4: beq         $v0, $at, L_80020A48
    if (ctx->r2 == ctx->r1) {
        // 0x800209B8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80020A48;
    }
    // 0x800209B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800209BC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x800209C0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800209C4: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x800209C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800209CC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800209D0: jal         0x8004D1F0
    // 0x800209D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x800209D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800209D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800209DC: jal         0x8004D414
    // 0x800209E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004D414(rdram, ctx);
        goto after_3;
    // 0x800209E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x800209E4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800209E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800209EC: lwc1        $f10, -0x3FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3FC);
    // 0x800209F0: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800209F4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800209F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800209FC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80020A00: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80020A04: bc1tl       L_80020A24
    if (c1cs) {
        // 0x80020A08: lw          $t4, 0x2C($t3)
        ctx->r12 = MEM_W(ctx->r11, 0X2C);
            goto L_80020A24;
    }
    goto skip_7;
    // 0x80020A08: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    skip_7:
    // 0x80020A0C: lwc1        $f16, -0x3F8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3F8);
    // 0x80020A10: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80020A14: nop

    // 0x80020A18: bc1fl       L_80020A4C
    if (!c1cs) {
        // 0x80020A1C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80020A4C;
    }
    goto skip_8;
    // 0x80020A1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_8:
    // 0x80020A20: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
L_80020A24:
    // 0x80020A24: ori         $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 | 0X1000;
    // 0x80020A28: sw          $t5, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->r13;
    // 0x80020A2C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80020A30: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80020A34: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80020A38: nop

    // 0x80020A3C: bc1fl       L_80020A4C
    if (!c1cs) {
        // 0x80020A40: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80020A4C;
    }
    goto skip_9;
    // 0x80020A40: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_9:
    // 0x80020A44: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_80020A48:
    // 0x80020A48: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80020A4C:
    // 0x80020A4C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80020A50: beq         $t0, $at, L_80020ACC
    if (ctx->r8 == ctx->r1) {
        // 0x80020A54: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80020ACC;
    }
    // 0x80020A54: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80020A58: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80020A5C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80020A60: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80020A64: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x80020A68: bne         $t9, $zero, L_80020A88
    if (ctx->r25 != 0) {
        // 0x80020A6C: lw          $a0, 0x40($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X40);
            goto L_80020A88;
    }
    // 0x80020A6C: lw          $a0, 0x40($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X40);
    // 0x80020A70: lw          $t1, 0x30($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X30);
    // 0x80020A74: andi        $t2, $t1, 0x700
    ctx->r10 = ctx->r9 & 0X700;
    // 0x80020A78: beql        $t2, $zero, L_80020A8C
    if (ctx->r10 == 0) {
        // 0x80020A7C: lw          $t4, 0x34($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X34);
            goto L_80020A8C;
    }
    goto skip_10;
    // 0x80020A7C: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
    skip_10:
    // 0x80020A80: b           L_80020AA4
    // 0x80020A84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80020AA4;
    // 0x80020A84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80020A88:
    // 0x80020A88: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
L_80020A8C:
    // 0x80020A8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80020A90: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80020A94: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x80020A98: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80020A9C: lwc1        $f8, 0x1C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80020AA0: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
L_80020AA4:
    // 0x80020AA4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80020AA8: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x80020AAC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80020AB0: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x80020AB4: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80020AB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80020ABC: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80020AC0: lwc1        $f10, 0x40($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X40);
    // 0x80020AC4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80020AC8: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
L_80020ACC:
    // 0x80020ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020AD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80020AD4: jr          $ra
    // 0x80020AD8: nop

    return;
    // 0x80020AD8: nop

;}
RECOMP_FUNC void func_807C5DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C5DF0: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(913, 0X7E8) << 16);
    // 0x807C5DF4: addiu       $v0, $v0, 0x65D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(913, 0X7E8));
    // 0x807C5DF8: jr          $ra
    // 0x807C5DFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807C5DFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80672C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672C80: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80672C84: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80672C88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80672C8C: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(526, 0X21F8) << 16);
    // 0x80672C90: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80672C94: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80672C98: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80672C9C: lw          $t8, 0x2D28($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(526, 0X21F8));
    // 0x80672CA0: jr          $ra
    // 0x80672CA4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80672CA4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80672CA8: nop

    // 0x80672CAC: nop

;}
RECOMP_FUNC void func_80445F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445F98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445F9C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80445FA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80445FA4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80445FA8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80445FAC: sw          $t6, 0x6CA0($at)
    MEM_W(0X6CA0, ctx->r1) = ctx->r14;
    // 0x80445FB0: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80445FB4: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x80445FB8: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x80445FBC: sw          $v1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r3;
    // 0x80445FC0: sw          $a1, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r5;
    // 0x80445FC4: sw          $v1, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r3;
    // 0x80445FC8: sw          $a1, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->r5;
    // 0x80445FCC: jr          $ra
    // 0x80445FD0: sw          $t7, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->r15;
    return;
    // 0x80445FD0: sw          $t7, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_800778A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800778A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800778A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800778A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800778AC: lwc1        $f4, 0x27E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X27E0);
    // 0x800778B0: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800778B4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800778B8: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800778BC: jal         0x800828F0
    // 0x800778C0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    sins(rdram, ctx);
        goto after_0;
    // 0x800778C0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x800778C4: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800778C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800778CC: lwc1        $f18, 0x27E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X27E4);
    // 0x800778D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800778D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800778D8: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800778DC: nop

    // 0x800778E0: jr          $ra
    // 0x800778E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800778E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002ABD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ABD0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8002ABD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002ABD8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002ABDC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002ABE0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002ABE4: lw          $s0, 0xE8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0XE8);
    // 0x8002ABE8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002ABEC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002ABF0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8002ABF4: lw          $s2, 0x1F4($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X1F4);
    // 0x8002ABF8: jal         0x80028620
    // 0x8002ABFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80028620(rdram, ctx);
        goto after_0;
    // 0x8002ABFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8002AC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002AC04: jal         0x80028774
    // 0x8002AC08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80028774(rdram, ctx);
        goto after_1;
    // 0x8002AC08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8002AC0C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8002AC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002AC14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002AC18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002AC1C: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x8002AC20: jal         0x800288E8
    // 0x8002AC24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800288E8(rdram, ctx);
        goto after_2;
    // 0x8002AC24: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8002AC28: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8002AC2C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8002AC30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002AC34: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002AC38: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8002AC3C: lw          $t9, -0x2130($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2130);
    // 0x8002AC40: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8002AC44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002AC48: jalr        $t9
    // 0x8002AC4C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8002AC4C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x8002AC50: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x8002AC54: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8002AC58: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8002AC5C: bne         $t6, $at, L_8002AC70
    if (ctx->r14 != ctx->r1) {
        // 0x8002AC60: lui         $t9, 0x800A
        ctx->r25 = S32(0X800A << 16);
            goto L_8002AC70;
    }
    // 0x8002AC60: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8002AC64: lbu         $t7, 0x30($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X30);
    // 0x8002AC68: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8002AC6C: beq         $t7, $at, L_8002AC88
    if (ctx->r15 == ctx->r1) {
        // 0x8002AC70: addu        $t9, $t9, $v0
        ctx->r25 = ADD32(ctx->r25, ctx->r2);
            goto L_8002AC88;
    }
L_8002AC70:
    // 0x8002AC70: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8002AC74: lw          $t9, -0x2118($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2118);
    // 0x8002AC78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002AC7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002AC80: jalr        $t9
    // 0x8002AC84: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8002AC84: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
L_8002AC88:
    // 0x8002AC88: jal         0x8002A148
    // 0x8002AC8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002A148(rdram, ctx);
        goto after_5;
    // 0x8002AC8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8002AC90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002AC94: jal         0x8002AAF0
    // 0x8002AC98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002AAF0(rdram, ctx);
        goto after_6;
    // 0x8002AC98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8002AC9C: jal         0x80029C60
    // 0x8002ACA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80029C60(rdram, ctx);
        goto after_7;
    // 0x8002ACA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8002ACA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002ACA8: jal         0x80029FA4
    // 0x8002ACAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80029FA4(rdram, ctx);
        goto after_8;
    // 0x8002ACAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8002ACB0: jal         0x8002848C
    // 0x8002ACB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002848C(rdram, ctx);
        goto after_9;
    // 0x8002ACB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8002ACB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002ACBC: lwc1        $f4, 0xAC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8002ACC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002ACC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002ACC8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8002ACCC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002ACD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002ACD4: bc1t        L_8002ACE0
    if (c1cs) {
        // 0x8002ACD8: nop
    
            goto L_8002ACE0;
    }
    // 0x8002ACD8: nop

    // 0x8002ACDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002ACE0:
    // 0x8002ACE0: bnel        $v1, $zero, L_8002AD08
    if (ctx->r3 != 0) {
        // 0x8002ACE4: lw          $s1, 0x24($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X24);
            goto L_8002AD08;
    }
    goto skip_0;
    // 0x8002ACE4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8002ACE8: lwc1        $f6, 0xB0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XB0);
    // 0x8002ACEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002ACF0: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8002ACF4: nop

    // 0x8002ACF8: bc1tl       L_8002AD08
    if (c1cs) {
        // 0x8002ACFC: lw          $s1, 0x24($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X24);
            goto L_8002AD08;
    }
    goto skip_1;
    // 0x8002ACFC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8002AD00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002AD04: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
L_8002AD08:
    // 0x8002AD08: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8002AD0C: jr          $ra
    // 0x8002AD10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002AD10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8003D33C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D33C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003D340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D344: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003D348: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x8003D34C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003D350: lwc1        $f10, 0x7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003D354: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003D358: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8003D35C: lwc1        $f8, 0x70($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X70);
    // 0x8003D360: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003D364: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D368: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003D36C: lwc1        $f8, 0x208($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X208);
    // 0x8003D370: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D374: div.s       $f2, $f4, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8003D378: sub.s       $f12, $f2, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8003D37C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8003D380: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8003D384: bc1tl       L_8003D3A4
    if (c1cs) {
        // 0x8003D388: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8003D3A4;
    }
    goto skip_0;
    // 0x8003D388: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    skip_0:
    // 0x8003D38C: lwc1        $f10, 0x20C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X20C);
    // 0x8003D390: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8003D394: nop

    // 0x8003D398: bc1fl       L_8003D428
    if (!c1cs) {
        // 0x8003D39C: div.s       $f10, $f18, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
            goto L_8003D428;
    }
    goto skip_1;
    // 0x8003D39C: div.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    skip_1:
    // 0x8003D3A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
L_8003D3A4:
    // 0x8003D3A4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8003D3A8: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x8003D3AC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8003D3B0: jal         0x80065954
    // 0x8003D3B4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8003D3B4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8003D3B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D3BC: lwc1        $f4, 0x210($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X210);
    // 0x8003D3C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003D3C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003D3C8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8003D3CC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003D3D0: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8003D3D4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003D3D8: bc1f        L_8003D3EC
    if (!c1cs) {
        // 0x8003D3DC: lwc1        $f18, 0x20($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
            goto L_8003D3EC;
    }
    // 0x8003D3DC: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8003D3E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003D3E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003D3E8: nop

L_8003D3EC:
    // 0x8003D3EC: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x8003D3F0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003D3F4: bc1fl       L_8003D418
    if (!c1cs) {
        // 0x8003D3F8: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8003D418;
    }
    goto skip_2;
    // 0x8003D3F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_2:
    // 0x8003D3FC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003D400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003D404: nop

    // 0x8003D408: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8003D40C: b           L_8003D424
    // 0x8003D410: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_8003D424;
    // 0x8003D410: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8003D414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8003D418:
    // 0x8003D418: nop

    // 0x8003D41C: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8003D420: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_8003D424:
    // 0x8003D424: div.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
L_8003D428:
    // 0x8003D428: mul.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003D42C: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x8003D430: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8003D434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D438: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003D43C: jr          $ra
    // 0x8003D440: nop

    return;
    // 0x8003D440: nop

;}
RECOMP_FUNC void func_805D32C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D32C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805D32CC: jr          $ra
    // 0x805D32D0: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x805D32D0: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_806A2984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A2984: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806A2988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A298C: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x806A2990: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806A2994: jal         0x80049D74
    // 0x806A2998: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x806A2998: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806A299C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806A29A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806A29A4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x806A29A8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x806A29AC: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x806A29B0: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x806A29B4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x806A29B8: sltu        $v0, $zero, $t9
    ctx->r2 = 0 < ctx->r25 ? 1 : 0;
    // 0x806A29BC: sh          $t8, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r24;
    // 0x806A29C0: beq         $v0, $zero, L_806A29FC
    if (ctx->r2 == 0) {
        // 0x806A29C4: lbu         $t0, 0x1A($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X1A);
            goto L_806A29FC;
    }
    // 0x806A29C4: lbu         $t0, 0x1A($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1A);
    // 0x806A29C8: xor         $v1, $t9, $at
    ctx->r3 = ctx->r25 ^ ctx->r1;
    // 0x806A29CC: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x806A29D0: beq         $v0, $zero, L_806A29FC
    if (ctx->r2 == 0) {
        // 0x806A29D4: lbu         $v1, 0x1A($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X1A);
            goto L_806A29FC;
    }
    // 0x806A29D4: lbu         $v1, 0x1A($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1A);
    // 0x806A29D8: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x806A29DC: xori        $v0, $v1, 0x38
    ctx->r2 = ctx->r3 ^ 0X38;
    // 0x806A29E0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x806A29E4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x806A29E8: beql        $v0, $zero, L_806A2A00
    if (ctx->r2 == 0) {
        // 0x806A29EC: andi        $t1, $t0, 0xF8
        ctx->r9 = ctx->r8 & 0XF8;
            goto L_806A2A00;
    }
    goto skip_0;
    // 0x806A29EC: andi        $t1, $t0, 0xF8
    ctx->r9 = ctx->r8 & 0XF8;
    skip_0:
    // 0x806A29F0: xori        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 ^ 0X40;
    // 0x806A29F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x806A29F8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_806A29FC:
    // 0x806A29FC: andi        $t1, $t0, 0xF8
    ctx->r9 = ctx->r8 & 0XF8;
L_806A2A00:
    // 0x806A2A00: xori        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 ^ 0X10;
    // 0x806A2A04: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x806A2A08: and         $v1, $v0, $t2
    ctx->r3 = ctx->r2 & ctx->r10;
    // 0x806A2A0C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x806A2A10: bne         $v1, $zero, L_806A2A28
    if (ctx->r3 != 0) {
        // 0x806A2A14: sb          $v1, 0x12($a1)
        MEM_B(0X12, ctx->r5) = ctx->r3;
            goto L_806A2A28;
    }
    // 0x806A2A14: sb          $v1, 0x12($a1)
    MEM_B(0X12, ctx->r5) = ctx->r3;
    // 0x806A2A18: jal         0x800447C8
    // 0x806A2A1C: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806A2A1C: nop

    after_1:
    // 0x806A2A20: b           L_806A2A2C
    // 0x806A2A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806A2A2C;
    // 0x806A2A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806A2A28:
    // 0x806A2A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806A2A2C:
    // 0x806A2A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A2A30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806A2A34: jr          $ra
    // 0x806A2A38: nop

    return;
    // 0x806A2A38: nop

;}
RECOMP_FUNC void func_80582DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582DE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80582DEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80582DF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80582DF4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80582DF8: lui         $t6, 0x8058
    ctx->r14 = S32(RELOC_HI16(399, 0X4728) << 16);
    // 0x80582DFC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80582E00: addiu       $t6, $t6, 0x3538
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(399, 0X4728));
    // 0x80582E04: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80582E08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80582E0C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80582E10: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80582E14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80582E18: jal         0x80582498
    // 0x80582E1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80582498(rdram, ctx);
        goto after_0;
    // 0x80582E1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80582E20: jal         0x8058245C
    // 0x80582E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8058245C(rdram, ctx);
        goto after_1;
    // 0x80582E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80582E28: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80582E2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80582E30: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80582E34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80582E38: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80582E3C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X480C) << 16);
    // 0x80582E40: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80582E44: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80582E48: lwc1        $f10, 0x361C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X480C));
    // 0x80582E4C: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80582E50: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X4810) << 16);
    // 0x80582E54: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80582E58: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80582E5C: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80582E60: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80582E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582E68: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    // 0x80582E6C: lwc1        $f4, 0x3620($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X4810));
    // 0x80582E70: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80582E74: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x80582E78: sb          $zero, 0x10($t8)
    MEM_B(0X10, ctx->r24) = 0;
    // 0x80582E7C: jal         0x80582A5C
    // 0x80582E80: sb          $t9, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r25;
    func_80582A5C(rdram, ctx);
        goto after_2;
    // 0x80582E80: sb          $t9, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r25;
    after_2:
    // 0x80582E84: jal         0x80582CB4
    // 0x80582E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80582CB4(rdram, ctx);
        goto after_3;
    // 0x80582E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80582E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80582E90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80582E94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80582E98: jr          $ra
    // 0x80582E9C: nop

    return;
    // 0x80582E9C: nop

;}
RECOMP_FUNC void func_8004404C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004404C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80044050: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80044054: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80044058: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004405C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80044060: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80044064: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80044068: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004406C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80044070: jal         0x80044014
    // 0x80044074: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_80044014(rdram, ctx);
        goto after_0;
    // 0x80044074: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_0:
    // 0x80044078: addiu       $a0, $s4, 0x48
    ctx->r4 = ADD32(ctx->r20, 0X48);
    // 0x8004407C: jal         0x80044014
    // 0x80044080: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80044014(rdram, ctx);
        goto after_1;
    // 0x80044080: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x80044084: lw          $a0, 0x18($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X18);
    // 0x80044088: jal         0x80044014
    // 0x8004408C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80044014(rdram, ctx);
        goto after_2;
    // 0x8004408C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80044090: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80044094: addiu       $s1, $s4, 0x5C
    ctx->r17 = ADD32(ctx->r20, 0X5C);
    // 0x80044098: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8004409C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800440A0:
    // 0x800440A0: jal         0x80044014
    // 0x800440A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80044014(rdram, ctx);
        goto after_3;
    // 0x800440A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x800440A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800440AC: bnel        $s0, $s2, L_800440A0
    if (ctx->r16 != ctx->r18) {
        // 0x800440B0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800440A0;
    }
    goto skip_0;
    // 0x800440B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x800440B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800440B8: sw          $zero, -0x72B4($at)
    MEM_W(-0X72B4, ctx->r1) = 0;
    // 0x800440BC: jal         0x8004389C
    // 0x800440C0: addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    func_8004389C(rdram, ctx);
        goto after_4;
    // 0x800440C0: addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    after_4:
    // 0x800440C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800440C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800440CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800440D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800440D4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800440D8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800440DC: jr          $ra
    // 0x800440E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800440E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8078B958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B958: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8078B95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078B960: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8078B964: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078B968: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    // 0x8078B96C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8078B970: addiu       $v1, $a3, 0x80
    ctx->r3 = ADD32(ctx->r7, 0X80);
    // 0x8078B974: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8078B978: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8078B97C: jal         0x80065728
    // 0x8078B980: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8078B980: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8078B984: jal         0x800653D8
    // 0x8078B988: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8078B988: nop

    after_1:
    // 0x8078B98C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8078B990: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8078B994: bgez        $v0, L_8078B9A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8078B998: andi        $a1, $v0, 0x3
        ctx->r5 = ctx->r2 & 0X3;
            goto L_8078B9A8;
    }
    // 0x8078B998: andi        $a1, $v0, 0x3
    ctx->r5 = ctx->r2 & 0X3;
    // 0x8078B99C: beq         $a1, $zero, L_8078B9A8
    if (ctx->r5 == 0) {
        // 0x8078B9A0: nop
    
            goto L_8078B9A8;
    }
    // 0x8078B9A0: nop

    // 0x8078B9A4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
L_8078B9A8:
    // 0x8078B9A8: jal         0x800653D8
    // 0x8078B9AC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x8078B9AC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x8078B9B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8078B9B4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8078B9B8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8078B9BC: bgez        $v0, L_8078B9D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8078B9C0: andi        $a0, $v0, 0x3
        ctx->r4 = ctx->r2 & 0X3;
            goto L_8078B9D0;
    }
    // 0x8078B9C0: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x8078B9C4: beq         $a0, $zero, L_8078B9D0
    if (ctx->r4 == 0) {
        // 0x8078B9C8: nop
    
            goto L_8078B9D0;
    }
    // 0x8078B9C8: nop

    // 0x8078B9CC: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_8078B9D0:
    // 0x8078B9D0: bne         $a1, $a0, L_8078B9F0
    if (ctx->r5 != ctx->r4) {
        // 0x8078B9D4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8078B9F0;
    }
    // 0x8078B9D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8078B9D8: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x8078B9DC: bgez        $a2, L_8078B9F0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8078B9E0: andi        $a2, $a2, 0x3
        ctx->r6 = ctx->r6 & 0X3;
            goto L_8078B9F0;
    }
    // 0x8078B9E0: andi        $a2, $a2, 0x3
    ctx->r6 = ctx->r6 & 0X3;
    // 0x8078B9E4: beq         $a2, $zero, L_8078B9F0
    if (ctx->r6 == 0) {
        // 0x8078B9E8: nop
    
            goto L_8078B9F0;
    }
    // 0x8078B9E8: nop

    // 0x8078B9EC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
L_8078B9F0:
    // 0x8078B9F0: lui         $t0, 0x8079
    ctx->r8 = S32(RELOC_HI16(796, 0X1AB8) << 16);
    // 0x8078B9F4: addiu       $t0, $t0, -0x33B8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(796, 0X1AB8));
    // 0x8078B9F8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8078B9FC: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8078BA00: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8078BA04: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8078BA08: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8078BA0C: sw          $v0, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r2;
    // 0x8078BA10: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8078BA14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8078BA18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8078BA1C: sw          $t3, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->r11;
L_8078BA20:
    // 0x8078BA20: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8078BA24: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8078BA28: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8078BA2C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8078BA30: lwc1        $f6, -0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8078BA34: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8078BA38: swc1        $f6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f6.u32l;
    // 0x8078BA3C: lwc1        $f8, -0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8078BA40: swc1        $f8, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f8.u32l;
    // 0x8078BA44: lwc1        $f10, -0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8078BA48: bne         $a0, $a1, L_8078BA20
    if (ctx->r4 != ctx->r5) {
        // 0x8078BA4C: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_8078BA20;
    }
    // 0x8078BA4C: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8078BA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078BA54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8078BA58: jr          $ra
    // 0x8078BA5C: nop

    return;
    // 0x8078BA5C: nop

;}
RECOMP_FUNC void func_8064F2B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F2B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F2BC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F2C0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F2C4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F2C8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F2CC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F2D0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F2D4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F2D8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F2DC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F2E0: jr          $ra
    // 0x8064F2E4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F2E4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8004921C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004921C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049224: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80049228: lw          $a0, 0x168($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X168);
    // 0x8004922C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80049230: lbu         $a1, 0x164($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X164);
    // 0x80049234: jal         0x8005B238
    // 0x80049238: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_8005B238(rdram, ctx);
        goto after_0;
    // 0x80049238: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x8004923C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049244: jr          $ra
    // 0x80049248: nop

    return;
    // 0x80049248: nop

;}
RECOMP_FUNC void func_806DEE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DEE30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DEE34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DEE38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DEE3C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806DEE40: lui         $a2, 0x806E
    ctx->r6 = S32(RELOC_HI16(637, 0XB8) << 16);
    // 0x806DEE44: addiu       $a2, $a2, -0x1118
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(637, 0XB8));
    // 0x806DEE48: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806DEE4C: jal         0x80057B28
    // 0x806DEE50: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_80057B28(rdram, ctx);
        goto after_0;
    // 0x806DEE50: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_0:
    // 0x806DEE54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DEE58: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(637, 0X74) << 16);
    // 0x806DEE5C: addiu       $v0, $v0, -0x115C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(637, 0X74));
    // 0x806DEE60: jr          $ra
    // 0x806DEE64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806DEE64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8043F33C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F33C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F340: lw          $t6, 0x1C90($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C90);
    // 0x8043F344: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8043F348: slti        $at, $t7, 0x7
    ctx->r1 = SIGNED(ctx->r15) < 0X7 ? 1 : 0;
    // 0x8043F34C: bne         $at, $zero, L_8043F358
    if (ctx->r1 != 0) {
        // 0x8043F350: sw          $t7, 0x1C90($v0)
        MEM_W(0X1C90, ctx->r2) = ctx->r15;
            goto L_8043F358;
    }
    // 0x8043F350: sw          $t7, 0x1C90($v0)
    MEM_W(0X1C90, ctx->r2) = ctx->r15;
    // 0x8043F354: sw          $zero, 0x1C90($v0)
    MEM_W(0X1C90, ctx->r2) = 0;
L_8043F358:
    // 0x8043F358: jr          $ra
    // 0x8043F35C: nop

    return;
    // 0x8043F35C: nop

;}
RECOMP_FUNC void func_8076CB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076CB18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076CB1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076CB20: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8076CB24: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076CB28: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8076CB2C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x8076CB30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8076CB34: jal         0x80065728
    // 0x8076CB38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8076CB38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8076CB3C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8076CB40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8076CB44: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8076CB48: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8076CB4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8076CB50: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8076CB54: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x8076CB58: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8076CB5C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8076CB60: lwc1        $f2, 0x38($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8076CB64: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8076CB68: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8076CB6C: sub.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8076CB70: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8076CB74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076CB78: add.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8076CB7C: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X34C8) << 16);
    // 0x8076CB80: addiu       $v0, $v0, -0x348
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X34C8));
    // 0x8076CB84: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8076CB88: swc1        $f16, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f16.u32l;
    // 0x8076CB8C: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x8076CB90: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8076CB94: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x8076CB98: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x8076CB9C: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
    // 0x8076CBA0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8076CBA4: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x8076CBA8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8076CBAC: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x8076CBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076CBB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076CBB8: jr          $ra
    // 0x8076CBBC: nop

    return;
    // 0x8076CBBC: nop

;}
RECOMP_FUNC void func_80678EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678EC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80678EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80678EC8: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x80678ECC: beql        $a1, $zero, L_80678F18
    if (ctx->r5 == 0) {
        // 0x80678ED0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80678F18;
    }
    goto skip_0;
    // 0x80678ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80678ED4: lw          $t6, 0x138($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X138);
    // 0x80678ED8: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x80678EDC: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80678EE0: lhu         $v1, 0x424($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X424);
    // 0x80678EE4: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x80678EE8: beql        $t8, $zero, L_80678F10
    if (ctx->r24 == 0) {
        // 0x80678EEC: ori         $t9, $v1, 0x1
        ctx->r25 = ctx->r3 | 0X1;
            goto L_80678F10;
    }
    goto skip_1;
    // 0x80678EEC: ori         $t9, $v1, 0x1
    ctx->r25 = ctx->r3 | 0X1;
    skip_1:
    // 0x80678EF0: jal         0x8005FE48
    // 0x80678EF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x80678EF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80678EF8: jal         0x80678A9C
    // 0x80678EFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80678A9C(rdram, ctx);
        goto after_1;
    // 0x80678EFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80678F00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80678F04: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80678F08: lhu         $v1, 0x424($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X424);
    // 0x80678F0C: ori         $t9, $v1, 0x1
    ctx->r25 = ctx->r3 | 0X1;
L_80678F10:
    // 0x80678F10: sh          $t9, 0x424($v0)
    MEM_H(0X424, ctx->r2) = ctx->r25;
    // 0x80678F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80678F18:
    // 0x80678F18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80678F1C: jr          $ra
    // 0x80678F20: nop

    return;
    // 0x80678F20: nop

;}
RECOMP_FUNC void func_80022E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022E14: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80022E18: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80022E1C: addiu       $a1, $a1, -0x7684
    ctx->r5 = ADD32(ctx->r5, -0X7684);
    // 0x80022E20: addiu       $a0, $a0, -0x7664
    ctx->r4 = ADD32(ctx->r4, -0X7664);
    // 0x80022E24: jal         0x800655F4
    // 0x80022E28: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_800655F4(rdram, ctx);
        goto after_0;
    // 0x80022E28: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x80022E2C: jal         0x80022B20
    // 0x80022E30: nop

    func_80022B20(rdram, ctx);
        goto after_1;
    // 0x80022E30: nop

    after_1:
    // 0x80022E34: jal         0x80022D6C
    // 0x80022E38: nop

    func_80022D6C(rdram, ctx);
        goto after_2;
    // 0x80022E38: nop

    after_2:
    // 0x80022E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022E44: jr          $ra
    // 0x80022E48: nop

    return;
    // 0x80022E48: nop

;}
RECOMP_FUNC void func_804C4D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C4D58: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804C4D5C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804C4D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C4D64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C4D68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C4D6C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C4D70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C4D74: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C4D78: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(209, 0XE34) << 16);
    // 0x804C4D7C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804C4D80: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C4D84: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804C4D88: lw          $t1, 0x4E24($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(209, 0XE34));
    // 0x804C4D8C: jal         0x804C4DA4
    // 0x804C4D90: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804C4DA4(rdram, ctx);
        goto after_0;
    // 0x804C4D90: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804C4D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C4D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C4D9C: jr          $ra
    // 0x804C4DA0: nop

    return;
    // 0x804C4DA0: nop

;}
RECOMP_FUNC void func_804C319C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C319C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C31A0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804C31A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C31A8: lwc1        $f4, 0x6CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x804C31AC: lwc1        $f0, 0x6D0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x804C31B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x804C31B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C31B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804C31BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C31C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C31C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804C31C8: swc1        $f8, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f8.u32l;
    // 0x804C31CC: lwc1        $f10, 0x6CC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x804C31D0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804C31D4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x804C31D8: swc1        $f8, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f8.u32l;
    // 0x804C31DC: lwc1        $f10, 0x6D0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x804C31E0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x804C31E4: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804C31E8: bc1f        L_804C31F4
    if (!c1cs) {
        // 0x804C31EC: swc1        $f4, 0x6C8($v0)
        MEM_W(0X6C8, ctx->r2) = ctx->f4.u32l;
            goto L_804C31F4;
    }
    // 0x804C31EC: swc1        $f4, 0x6C8($v0)
    MEM_W(0X6C8, ctx->r2) = ctx->f4.u32l;
    // 0x804C31F0: swc1        $f2, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f2.u32l;
L_804C31F4:
    // 0x804C31F4: jr          $ra
    // 0x804C31F8: nop

    return;
    // 0x804C31F8: nop

;}
RECOMP_FUNC void func_804541F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804541F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804541FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454200: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80454204: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80454208: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045420C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80454210: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80454214: lw          $v0, 0xA5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA5C);
    // 0x80454218: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x8045421C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80454220: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80454224: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80454228: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8045422C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80454230: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454234: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454238: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8045423C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454240: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80454244: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454248: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8045424C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80454250: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x80454254: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80454258: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8045425C: jal         0x8044EEF8
    // 0x80454260: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8044EEF8(rdram, ctx);
        goto after_0;
    // 0x80454260: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80454264: jal         0x80446D70
    // 0x80454268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x80454268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8045426C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80454270: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80454274: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80454278: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045427C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80454280: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80454284: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454288: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045428C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454290: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x80454294: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x80454298: jal         0x8044ED68
    // 0x8045429C: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_2;
    // 0x8045429C: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_2:
    // 0x804542A0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x804542A4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804542A8: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x804542AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804542B0: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    // 0x804542B4: lwc1        $f4, 0x6C84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x804542B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804542BC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804542C0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804542C4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804542C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804542CC: swc1        $f8, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f8.u32l;
    // 0x804542D0: lwc1        $f12, 0x6C84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x804542D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804542D8: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x804542DC: nop

    // 0x804542E0: bc1f        L_804542FC
    if (!c1cs) {
        // 0x804542E4: nop
    
            goto L_804542FC;
    }
    // 0x804542E4: nop

    // 0x804542E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804542EC: jal         0x80450490
    // 0x804542F0: nop

    func_80450490(rdram, ctx);
        goto after_3;
    // 0x804542F0: nop

    after_3:
    // 0x804542F4: b           L_80454308
    // 0x804542F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80454308;
    // 0x804542F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804542FC:
    // 0x804542FC: jal         0x80453C3C
    // 0x80454300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80453C3C(rdram, ctx);
        goto after_4;
    // 0x80454300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80454304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80454308:
    // 0x80454308: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8045430C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80454310: jr          $ra
    // 0x80454314: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80454314: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805A46CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A46CC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x805A46D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805A46D4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x805A46D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x805A46DC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x805A46E0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x805A46E4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x805A46E8: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x805A46EC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x805A46F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x805A46F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x805A46F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x805A46FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805A4700: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A4704: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x805A4708: jal         0x80064D1C
    // 0x805A470C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x805A470C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x805A4710: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x805A4714: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x805A4718: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x805A471C: multu       $fp, $s0
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805A4720: sll         $t7, $s0, 6
    ctx->r15 = S32(ctx->r16 << 6);
    // 0x805A4724: mflo        $t6
    ctx->r14 = lo;
    // 0x805A4728: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x805A472C: nop

    // 0x805A4730: multu       $t7, $fp
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805A4734: mflo        $a0
    ctx->r4 = lo;
    // 0x805A4738: jal         0x80064D1C
    // 0x805A473C: nop

    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x805A473C: nop

    after_1:
    // 0x805A4740: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x805A4744: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x805A4748: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x805A474C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x805A4750: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x805A4754: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x805A4758: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x805A475C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x805A4760: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x805A4764: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x805A4768: mflo        $t8
    ctx->r24 = lo;
    // 0x805A476C: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x805A4770: lbu         $t9, 0x5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5);
    // 0x805A4774: bne         $a0, $zero, L_805A4780
    if (ctx->r4 != 0) {
        // 0x805A4778: nop
    
            goto L_805A4780;
    }
    // 0x805A4778: nop

    // 0x805A477C: break       7
    do_break(2153400188);
L_805A4780:
    // 0x805A4780: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805A4784: bne         $a0, $at, L_805A4798
    if (ctx->r4 != ctx->r1) {
        // 0x805A4788: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805A4798;
    }
    // 0x805A4788: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805A478C: bne         $t7, $at, L_805A4798
    if (ctx->r15 != ctx->r1) {
        // 0x805A4790: nop
    
            goto L_805A4798;
    }
    // 0x805A4790: nop

    // 0x805A4794: break       6
    do_break(2153400212);
L_805A4798:
    // 0x805A4798: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x805A479C: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x805A47A0: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x805A47A4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x805A47A8: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x805A47AC: mflo        $t9
    ctx->r25 = lo;
    // 0x805A47B0: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x805A47B4: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    // 0x805A47B8: bne         $a0, $zero, L_805A47C4
    if (ctx->r4 != 0) {
        // 0x805A47BC: nop
    
            goto L_805A47C4;
    }
    // 0x805A47BC: nop

    // 0x805A47C0: break       7
    do_break(2153400256);
L_805A47C4:
    // 0x805A47C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805A47C8: bne         $a0, $at, L_805A47DC
    if (ctx->r4 != ctx->r1) {
        // 0x805A47CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805A47DC;
    }
    // 0x805A47CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805A47D0: bne         $t8, $at, L_805A47DC
    if (ctx->r24 != ctx->r1) {
        // 0x805A47D4: nop
    
            goto L_805A47DC;
    }
    // 0x805A47D4: nop

    // 0x805A47D8: break       6
    do_break(2153400280);
L_805A47DC:
    // 0x805A47DC: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x805A47E0: lbu         $t8, 0x6($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X6);
    // 0x805A47E4: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x805A47E8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x805A47EC: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x805A47F0: mflo        $t6
    ctx->r14 = lo;
    // 0x805A47F4: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x805A47F8: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x805A47FC: bne         $a0, $zero, L_805A4808
    if (ctx->r4 != 0) {
        // 0x805A4800: nop
    
            goto L_805A4808;
    }
    // 0x805A4800: nop

    // 0x805A4804: break       7
    do_break(2153400324);
L_805A4808:
    // 0x805A4808: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805A480C: bne         $a0, $at, L_805A4820
    if (ctx->r4 != ctx->r1) {
        // 0x805A4810: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805A4820;
    }
    // 0x805A4810: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805A4814: bne         $t9, $at, L_805A4820
    if (ctx->r25 != ctx->r1) {
        // 0x805A4818: nop
    
            goto L_805A4820;
    }
    // 0x805A4818: nop

    // 0x805A481C: break       6
    do_break(2153400348);
L_805A4820:
    // 0x805A4820: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
    // 0x805A4824: lbu         $t9, 0x7($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X7);
    // 0x805A4828: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    // 0x805A482C: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x805A4830: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x805A4834: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x805A4838: div         $zero, $t6, $a0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r4)));
    // 0x805A483C: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x805A4840: mflo        $t7
    ctx->r15 = lo;
    // 0x805A4844: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x805A4848: bne         $a0, $zero, L_805A4854
    if (ctx->r4 != 0) {
        // 0x805A484C: nop
    
            goto L_805A4854;
    }
    // 0x805A484C: nop

    // 0x805A4850: break       7
    do_break(2153400400);
L_805A4854:
    // 0x805A4854: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805A4858: bne         $a0, $at, L_805A486C
    if (ctx->r4 != ctx->r1) {
        // 0x805A485C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805A486C;
    }
    // 0x805A485C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805A4860: bne         $t6, $at, L_805A486C
    if (ctx->r14 != ctx->r1) {
        // 0x805A4864: nop
    
            goto L_805A486C;
    }
    // 0x805A4864: nop

    // 0x805A4868: break       6
    do_break(2153400424);
L_805A486C:
    // 0x805A486C: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x805A4870: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x805A4874: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805A4878: negu        $t7, $s4
    ctx->r15 = SUB32(0, ctx->r20);
    // 0x805A487C: mflo        $s2
    ctx->r18 = lo;
    // 0x805A4880: blezl       $s0, L_805A4ACC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x805A4884: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_805A4ACC;
    }
    goto skip_0;
    // 0x805A4884: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x805A4888: multu       $t7, $fp
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805A488C: lw          $s7, 0x70($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X70);
    // 0x805A4890: lw          $s6, 0x6C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X6C);
    // 0x805A4894: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x805A4898: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x805A489C: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x805A48A0: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x805A48A4: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x805A48A8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x805A48AC: mflo        $t8
    ctx->r24 = lo;
    // 0x805A48B0: bgez        $t8, L_805A48C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x805A48B4: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_805A48C0;
    }
    // 0x805A48B4: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x805A48B8: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x805A48BC: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_805A48C0:
    // 0x805A48C0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_805A48C4:
    // 0x805A48C4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x805A48C8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x805A48CC: blez        $fp, L_805A4A80
    if (SIGNED(ctx->r30) <= 0) {
        // 0x805A48D0: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_805A4A80;
    }
    // 0x805A48D0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x805A48D4: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x805A48D8: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x805A48DC: sll         $t8, $s3, 4
    ctx->r24 = S32(ctx->r19 << 4);
    // 0x805A48E0: addu        $v1, $t8, $v0
    ctx->r3 = ADD32(ctx->r24, ctx->r2);
    // 0x805A48E4: addu        $s1, $t7, $t6
    ctx->r17 = ADD32(ctx->r15, ctx->r14);
    // 0x805A48E8: sll         $s1, $s1, 6
    ctx->r17 = S32(ctx->r17 << 6);
    // 0x805A48EC: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    // 0x805A48F0: addiu       $t2, $v1, 0x30
    ctx->r10 = ADD32(ctx->r3, 0X30);
    // 0x805A48F4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x805A48F8: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    // 0x805A48FC: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x805A4900: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x805A4904: subu        $ra, $s2, $t6
    ctx->r31 = SUB32(ctx->r18, ctx->r14);
    // 0x805A4908: sll         $s0, $t7, 6
    ctx->r16 = S32(ctx->r15 << 6);
L_805A490C:
    // 0x805A490C: sll         $t3, $t0, 6
    ctx->r11 = S32(ctx->r8 << 6);
    // 0x805A4910: sh          $t3, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r11;
    // 0x805A4914: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x805A4918: sh          $ra, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r31;
    // 0x805A491C: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x805A4920: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x805A4924: sh          $s0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r16;
    // 0x805A4928: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x805A492C: addu        $t4, $t0, $s4
    ctx->r12 = ADD32(ctx->r8, ctx->r20);
    // 0x805A4930: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x805A4934: sb          $t9, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r25;
    // 0x805A4938: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x805A493C: sll         $t5, $t5, 6
    ctx->r13 = S32(ctx->r13 << 6);
    // 0x805A4940: addu        $a3, $a2, $s4
    ctx->r7 = ADD32(ctx->r6, ctx->r20);
    // 0x805A4944: sb          $t7, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r15;
    // 0x805A4948: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x805A494C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x805A4950: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x805A4954: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
    // 0x805A4958: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x805A495C: sh          $s0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r16;
    // 0x805A4960: sh          $t5, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r13;
    // 0x805A4964: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x805A4968: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x805A496C: sh          $ra, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r31;
    // 0x805A4970: sh          $a3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r7;
    // 0x805A4974: sb          $t8, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r24;
    // 0x805A4978: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x805A497C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x805A4980: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x805A4984: sb          $t9, -0x24($v1)
    MEM_B(-0X24, ctx->r3) = ctx->r25;
    // 0x805A4988: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x805A498C: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
    // 0x805A4990: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x805A4994: sb          $t7, -0x23($v1)
    MEM_B(-0X23, ctx->r3) = ctx->r15;
    // 0x805A4998: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x805A499C: sb          $t6, -0x22($v1)
    MEM_B(-0X22, ctx->r3) = ctx->r14;
    // 0x805A49A0: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x805A49A4: sh          $s2, -0x1E($v1)
    MEM_H(-0X1E, ctx->r3) = ctx->r18;
    // 0x805A49A8: sh          $a2, -0x20($v1)
    MEM_H(-0X20, ctx->r3) = ctx->r6;
    // 0x805A49AC: sb          $t8, -0x21($v1)
    MEM_B(-0X21, ctx->r3) = ctx->r24;
    // 0x805A49B0: sh          $s1, -0x36($a0)
    MEM_H(-0X36, ctx->r4) = ctx->r17;
    // 0x805A49B4: sh          $t3, -0x38($a0)
    MEM_H(-0X38, ctx->r4) = ctx->r11;
    // 0x805A49B8: sh          $zero, -0x3A($a0)
    MEM_H(-0X3A, ctx->r4) = 0;
    // 0x805A49BC: sh          $zero, -0x3C($a0)
    MEM_H(-0X3C, ctx->r4) = 0;
    // 0x805A49C0: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x805A49C4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x805A49C8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x805A49CC: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x805A49D0: sb          $t6, -0x34($a0)
    MEM_B(-0X34, ctx->r4) = ctx->r14;
    // 0x805A49D4: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x805A49D8: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x805A49DC: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x805A49E0: sb          $t7, -0x33($a0)
    MEM_B(-0X33, ctx->r4) = ctx->r15;
    // 0x805A49E4: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x805A49E8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x805A49EC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x805A49F0: sb          $t9, -0x32($a0)
    MEM_B(-0X32, ctx->r4) = ctx->r25;
    // 0x805A49F4: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x805A49F8: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x805A49FC: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x805A4A00: sb          $t8, -0x31($a0)
    MEM_B(-0X31, ctx->r4) = ctx->r24;
    // 0x805A4A04: sh          $s1, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r17;
    // 0x805A4A08: sh          $t5, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r13;
    // 0x805A4A0C: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x805A4A10: sh          $zero, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = 0;
    // 0x805A4A14: sh          $s2, -0xE($v1)
    MEM_H(-0XE, ctx->r3) = ctx->r18;
    // 0x805A4A18: sh          $a3, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r7;
    // 0x805A4A1C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x805A4A20: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x805A4A24: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x805A4A28: sb          $t6, -0x34($t2)
    MEM_B(-0X34, ctx->r10) = ctx->r14;
    // 0x805A4A2C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x805A4A30: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x805A4A34: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x805A4A38: sb          $t7, -0x33($t2)
    MEM_B(-0X33, ctx->r10) = ctx->r15;
    // 0x805A4A3C: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x805A4A40: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x805A4A44: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x805A4A48: sb          $t9, -0x32($t2)
    MEM_B(-0X32, ctx->r10) = ctx->r25;
    // 0x805A4A4C: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x805A4A50: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x805A4A54: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x805A4A58: bne         $t1, $fp, L_805A490C
    if (ctx->r9 != ctx->r30) {
        // 0x805A4A5C: sb          $t8, -0x31($t2)
        MEM_B(-0X31, ctx->r10) = ctx->r24;
            goto L_805A490C;
    }
    // 0x805A4A5C: sb          $t8, -0x31($t2)
    MEM_B(-0X31, ctx->r10) = ctx->r24;
    // 0x805A4A60: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x805A4A64: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x805A4A68: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x805A4A6C: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x805A4A70: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x805A4A74: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x805A4A78: lw          $s6, 0x6C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X6C);
    // 0x805A4A7C: lw          $s7, 0x70($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X70);
L_805A4A80:
    // 0x805A4A80: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x805A4A84: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x805A4A88: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x805A4A8C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x805A4A90: addu        $t7, $t9, $a0
    ctx->r15 = ADD32(ctx->r25, ctx->r4);
    // 0x805A4A94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x805A4A98: sw          $v1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r3;
    // 0x805A4A9C: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x805A4AA0: addu        $a3, $a3, $s5
    ctx->r7 = ADD32(ctx->r7, ctx->r21);
    // 0x805A4AA4: addu        $t3, $t3, $s6
    ctx->r11 = ADD32(ctx->r11, ctx->r22);
    // 0x805A4AA8: addu        $t4, $t4, $s7
    ctx->r12 = ADD32(ctx->r12, ctx->r23);
    // 0x805A4AAC: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x805A4AB0: bne         $v1, $t6, L_805A48C4
    if (ctx->r3 != ctx->r14) {
        // 0x805A4AB4: addu        $s2, $s2, $a0
        ctx->r18 = ADD32(ctx->r18, ctx->r4);
            goto L_805A48C4;
    }
    // 0x805A4AB4: addu        $s2, $s2, $a0
    ctx->r18 = ADD32(ctx->r18, ctx->r4);
    // 0x805A4AB8: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x805A4ABC: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x805A4AC0: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    // 0x805A4AC4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x805A4AC8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_805A4ACC:
    // 0x805A4ACC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A4AD0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805A4AD4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805A4AD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x805A4ADC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x805A4AE0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x805A4AE4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x805A4AE8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x805A4AEC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x805A4AF0: jr          $ra
    // 0x805A4AF4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x805A4AF4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80671060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80671064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80671068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8067106C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80671070: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80671074: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x80671078: lbu         $t0, 0xF5C($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0XF5C);
    // 0x8067107C: lbu         $t1, 0xF5D($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0XF5D);
    // 0x80671080: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x80671084: lw          $v0, 0xCB4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XCB4);
    // 0x80671088: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8067108C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80671090: slti        $at, $v0, 0x2711
    ctx->r1 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80671094: bne         $at, $zero, L_806710A0
    if (ctx->r1 != 0) {
        // 0x80671098: addiu       $a1, $zero, 0x3E8
        ctx->r5 = ADD32(0, 0X3E8);
            goto L_806710A0;
    }
    // 0x80671098: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x8067109C: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
L_806710A0:
    // 0x806710A0: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x806710A4: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x806710A8: mflo        $t9
    ctx->r25 = lo;
    // 0x806710AC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x806710B0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x806710B4: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x806710B8: bne         $a1, $zero, L_806710C4
    if (ctx->r5 != 0) {
        // 0x806710BC: nop
    
            goto L_806710C4;
    }
    // 0x806710BC: nop

    // 0x806710C0: break       7
    do_break(2154238144);
L_806710C4:
    // 0x806710C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806710C8: bne         $a1, $at, L_806710DC
    if (ctx->r5 != ctx->r1) {
        // 0x806710CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806710DC;
    }
    // 0x806710CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806710D0: bne         $v0, $at, L_806710DC
    if (ctx->r2 != ctx->r1) {
        // 0x806710D4: nop
    
            goto L_806710DC;
    }
    // 0x806710D4: nop

    // 0x806710D8: break       6
    do_break(2154238168);
L_806710DC:
    // 0x806710DC: mfhi        $v0
    ctx->r2 = hi;
    // 0x806710E0: sw          $t9, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r25;
    // 0x806710E4: nop

    // 0x806710E8: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x806710EC: bne         $a0, $zero, L_806710F8
    if (ctx->r4 != 0) {
        // 0x806710F0: nop
    
            goto L_806710F8;
    }
    // 0x806710F0: nop

    // 0x806710F4: break       7
    do_break(2154238196);
L_806710F8:
    // 0x806710F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806710FC: bne         $a0, $at, L_80671110
    if (ctx->r4 != ctx->r1) {
        // 0x80671100: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671110;
    }
    // 0x80671100: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671104: bne         $v0, $at, L_80671110
    if (ctx->r2 != ctx->r1) {
        // 0x80671108: nop
    
            goto L_80671110;
    }
    // 0x80671108: nop

    // 0x8067110C: break       6
    do_break(2154238220);
L_80671110:
    // 0x80671110: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671114: mflo        $t2
    ctx->r10 = lo;
    // 0x80671118: sw          $t2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r10;
    // 0x8067111C: nop

    // 0x80671120: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x80671124: bne         $a2, $zero, L_80671130
    if (ctx->r6 != 0) {
        // 0x80671128: nop
    
            goto L_80671130;
    }
    // 0x80671128: nop

    // 0x8067112C: break       7
    do_break(2154238252);
L_80671130:
    // 0x80671130: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671134: bne         $a2, $at, L_80671148
    if (ctx->r6 != ctx->r1) {
        // 0x80671138: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671148;
    }
    // 0x80671138: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067113C: bne         $v0, $at, L_80671148
    if (ctx->r2 != ctx->r1) {
        // 0x80671140: nop
    
            goto L_80671148;
    }
    // 0x80671140: nop

    // 0x80671144: break       6
    do_break(2154238276);
L_80671148:
    // 0x80671148: mfhi        $v0
    ctx->r2 = hi;
    // 0x8067114C: mflo        $t3
    ctx->r11 = lo;
    // 0x80671150: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x80671154: sw          $t3, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r11;
    // 0x80671158: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8067115C: lw          $v0, -0x74A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74A8);
    // 0x80671160: slti        $at, $v0, 0x2711
    ctx->r1 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80671164: bne         $at, $zero, L_80671170
    if (ctx->r1 != 0) {
        // 0x80671168: nop
    
            goto L_80671170;
    }
    // 0x80671168: nop

    // 0x8067116C: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
L_80671170:
    // 0x80671170: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x80671174: lw          $t4, 0x28($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X28);
    // 0x80671178: mflo        $t6
    ctx->r14 = lo;
    // 0x8067117C: sw          $t6, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r14;
    // 0x80671180: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80671184: sw          $t5, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r13;
    // 0x80671188: bne         $a1, $zero, L_80671194
    if (ctx->r5 != 0) {
        // 0x8067118C: nop
    
            goto L_80671194;
    }
    // 0x8067118C: nop

    // 0x80671190: break       7
    do_break(2154238352);
L_80671194:
    // 0x80671194: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671198: bne         $a1, $at, L_806711AC
    if (ctx->r5 != ctx->r1) {
        // 0x8067119C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806711AC;
    }
    // 0x8067119C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806711A0: bne         $v0, $at, L_806711AC
    if (ctx->r2 != ctx->r1) {
        // 0x806711A4: nop
    
            goto L_806711AC;
    }
    // 0x806711A4: nop

    // 0x806711A8: break       6
    do_break(2154238376);
L_806711AC:
    // 0x806711AC: mfhi        $v0
    ctx->r2 = hi;
    // 0x806711B0: nop

    // 0x806711B4: nop

    // 0x806711B8: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x806711BC: bne         $a0, $zero, L_806711C8
    if (ctx->r4 != 0) {
        // 0x806711C0: nop
    
            goto L_806711C8;
    }
    // 0x806711C0: nop

    // 0x806711C4: break       7
    do_break(2154238404);
L_806711C8:
    // 0x806711C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806711CC: bne         $a0, $at, L_806711E0
    if (ctx->r4 != ctx->r1) {
        // 0x806711D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806711E0;
    }
    // 0x806711D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806711D4: bne         $v0, $at, L_806711E0
    if (ctx->r2 != ctx->r1) {
        // 0x806711D8: nop
    
            goto L_806711E0;
    }
    // 0x806711D8: nop

    // 0x806711DC: break       6
    do_break(2154238428);
L_806711E0:
    // 0x806711E0: mfhi        $v0
    ctx->r2 = hi;
    // 0x806711E4: mflo        $t7
    ctx->r15 = lo;
    // 0x806711E8: sw          $t7, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r15;
    // 0x806711EC: nop

    // 0x806711F0: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x806711F4: bne         $a2, $zero, L_80671200
    if (ctx->r6 != 0) {
        // 0x806711F8: nop
    
            goto L_80671200;
    }
    // 0x806711F8: nop

    // 0x806711FC: break       7
    do_break(2154238460);
L_80671200:
    // 0x80671200: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671204: bne         $a2, $at, L_80671218
    if (ctx->r6 != ctx->r1) {
        // 0x80671208: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671218;
    }
    // 0x80671208: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067120C: bne         $v0, $at, L_80671218
    if (ctx->r2 != ctx->r1) {
        // 0x80671210: nop
    
            goto L_80671218;
    }
    // 0x80671210: nop

    // 0x80671214: break       6
    do_break(2154238484);
L_80671218:
    // 0x80671218: mfhi        $v0
    ctx->r2 = hi;
    // 0x8067121C: mflo        $t8
    ctx->r24 = lo;
    // 0x80671220: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x80671224: sw          $t8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r24;
    // 0x80671228: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8067122C: lw          $v0, -0x74A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74A4);
    // 0x80671230: slti        $at, $v0, 0x2711
    ctx->r1 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80671234: bne         $at, $zero, L_80671240
    if (ctx->r1 != 0) {
        // 0x80671238: nop
    
            goto L_80671240;
    }
    // 0x80671238: nop

    // 0x8067123C: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
L_80671240:
    // 0x80671240: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x80671244: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x80671248: mflo        $t3
    ctx->r11 = lo;
    // 0x8067124C: sw          $t3, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r11;
    // 0x80671250: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x80671254: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x80671258: bne         $a1, $zero, L_80671264
    if (ctx->r5 != 0) {
        // 0x8067125C: nop
    
            goto L_80671264;
    }
    // 0x8067125C: nop

    // 0x80671260: break       7
    do_break(2154238560);
L_80671264:
    // 0x80671264: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671268: bne         $a1, $at, L_8067127C
    if (ctx->r5 != ctx->r1) {
        // 0x8067126C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8067127C;
    }
    // 0x8067126C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671270: bne         $v0, $at, L_8067127C
    if (ctx->r2 != ctx->r1) {
        // 0x80671274: nop
    
            goto L_8067127C;
    }
    // 0x80671274: nop

    // 0x80671278: break       6
    do_break(2154238584);
L_8067127C:
    // 0x8067127C: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671280: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80671284: nop

    // 0x80671288: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x8067128C: bne         $a0, $zero, L_80671298
    if (ctx->r4 != 0) {
        // 0x80671290: nop
    
            goto L_80671298;
    }
    // 0x80671290: nop

    // 0x80671294: break       7
    do_break(2154238612);
L_80671298:
    // 0x80671298: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8067129C: bne         $a0, $at, L_806712B0
    if (ctx->r4 != ctx->r1) {
        // 0x806712A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806712B0;
    }
    // 0x806712A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806712A4: bne         $v0, $at, L_806712B0
    if (ctx->r2 != ctx->r1) {
        // 0x806712A8: nop
    
            goto L_806712B0;
    }
    // 0x806712A8: nop

    // 0x806712AC: break       6
    do_break(2154238636);
L_806712B0:
    // 0x806712B0: mfhi        $v0
    ctx->r2 = hi;
    // 0x806712B4: mflo        $t4
    ctx->r12 = lo;
    // 0x806712B8: sw          $t4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r12;
    // 0x806712BC: nop

    // 0x806712C0: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x806712C4: bne         $a2, $zero, L_806712D0
    if (ctx->r6 != 0) {
        // 0x806712C8: nop
    
            goto L_806712D0;
    }
    // 0x806712C8: nop

    // 0x806712CC: break       7
    do_break(2154238668);
L_806712D0:
    // 0x806712D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806712D4: bne         $a2, $at, L_806712E8
    if (ctx->r6 != ctx->r1) {
        // 0x806712D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806712E8;
    }
    // 0x806712D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806712DC: bne         $v0, $at, L_806712E8
    if (ctx->r2 != ctx->r1) {
        // 0x806712E0: nop
    
            goto L_806712E8;
    }
    // 0x806712E0: nop

    // 0x806712E4: break       6
    do_break(2154238692);
L_806712E8:
    // 0x806712E8: mflo        $t5
    ctx->r13 = lo;
    // 0x806712EC: mfhi        $v0
    ctx->r2 = hi;
    // 0x806712F0: sw          $t5, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r13;
    // 0x806712F4: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x806712F8: lw          $t6, -0x74A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X74A0);
    // 0x806712FC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80671300: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80671304: sb          $t6, -0x71F4($at)
    MEM_B(-0X71F4, ctx->r1) = ctx->r14;
    // 0x80671308: mflo        $v0
    ctx->r2 = lo;
    // 0x8067130C: slti        $at, $v0, 0x2711
    ctx->r1 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80671310: bne         $at, $zero, L_8067131C
    if (ctx->r1 != 0) {
        // 0x80671314: nop
    
            goto L_8067131C;
    }
    // 0x80671314: nop

    // 0x80671318: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
L_8067131C:
    // 0x8067131C: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x80671320: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x80671324: mflo        $t9
    ctx->r25 = lo;
    // 0x80671328: sw          $t9, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r25;
    // 0x8067132C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80671330: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x80671334: bne         $a1, $zero, L_80671340
    if (ctx->r5 != 0) {
        // 0x80671338: nop
    
            goto L_80671340;
    }
    // 0x80671338: nop

    // 0x8067133C: break       7
    do_break(2154238780);
L_80671340:
    // 0x80671340: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671344: bne         $a1, $at, L_80671358
    if (ctx->r5 != ctx->r1) {
        // 0x80671348: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671358;
    }
    // 0x80671348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067134C: bne         $v0, $at, L_80671358
    if (ctx->r2 != ctx->r1) {
        // 0x80671350: nop
    
            goto L_80671358;
    }
    // 0x80671350: nop

    // 0x80671354: break       6
    do_break(2154238804);
L_80671358:
    // 0x80671358: mfhi        $v0
    ctx->r2 = hi;
    // 0x8067135C: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80671360: nop

    // 0x80671364: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80671368: bne         $a0, $zero, L_80671374
    if (ctx->r4 != 0) {
        // 0x8067136C: nop
    
            goto L_80671374;
    }
    // 0x8067136C: nop

    // 0x80671370: break       7
    do_break(2154238832);
L_80671374:
    // 0x80671374: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671378: bne         $a0, $at, L_8067138C
    if (ctx->r4 != ctx->r1) {
        // 0x8067137C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8067138C;
    }
    // 0x8067137C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671380: bne         $v0, $at, L_8067138C
    if (ctx->r2 != ctx->r1) {
        // 0x80671384: nop
    
            goto L_8067138C;
    }
    // 0x80671384: nop

    // 0x80671388: break       6
    do_break(2154238856);
L_8067138C:
    // 0x8067138C: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671390: mflo        $t2
    ctx->r10 = lo;
    // 0x80671394: sw          $t2, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r10;
    // 0x80671398: nop

    // 0x8067139C: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x806713A0: bne         $a2, $zero, L_806713AC
    if (ctx->r6 != 0) {
        // 0x806713A4: nop
    
            goto L_806713AC;
    }
    // 0x806713A4: nop

    // 0x806713A8: break       7
    do_break(2154238888);
L_806713AC:
    // 0x806713AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806713B0: bne         $a2, $at, L_806713C4
    if (ctx->r6 != ctx->r1) {
        // 0x806713B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806713C4;
    }
    // 0x806713B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806713B8: bne         $v0, $at, L_806713C4
    if (ctx->r2 != ctx->r1) {
        // 0x806713BC: nop
    
            goto L_806713C4;
    }
    // 0x806713BC: nop

    // 0x806713C0: break       6
    do_break(2154238912);
L_806713C4:
    // 0x806713C4: mflo        $t3
    ctx->r11 = lo;
    // 0x806713C8: mfhi        $v0
    ctx->r2 = hi;
    // 0x806713CC: sw          $t3, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r11;
    // 0x806713D0: sw          $v0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r2;
    // 0x806713D4: lw          $t4, -0x749C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X749C);
    // 0x806713D8: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806713DC: mflo        $v0
    ctx->r2 = lo;
    // 0x806713E0: slti        $at, $v0, 0x2711
    ctx->r1 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x806713E4: bne         $at, $zero, L_806713F0
    if (ctx->r1 != 0) {
        // 0x806713E8: nop
    
            goto L_806713F0;
    }
    // 0x806713E8: nop

    // 0x806713EC: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
L_806713F0:
    // 0x806713F0: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x806713F4: lw          $t5, 0x28($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X28);
    // 0x806713F8: mflo        $t7
    ctx->r15 = lo;
    // 0x806713FC: sw          $t7, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->r15;
    // 0x80671400: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80671404: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x80671408: bne         $a1, $zero, L_80671414
    if (ctx->r5 != 0) {
        // 0x8067140C: nop
    
            goto L_80671414;
    }
    // 0x8067140C: nop

    // 0x80671410: break       7
    do_break(2154238992);
L_80671414:
    // 0x80671414: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671418: bne         $a1, $at, L_8067142C
    if (ctx->r5 != ctx->r1) {
        // 0x8067141C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8067142C;
    }
    // 0x8067141C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671420: bne         $v0, $at, L_8067142C
    if (ctx->r2 != ctx->r1) {
        // 0x80671424: nop
    
            goto L_8067142C;
    }
    // 0x80671424: nop

    // 0x80671428: break       6
    do_break(2154239016);
L_8067142C:
    // 0x8067142C: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671430: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80671434: nop

    // 0x80671438: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x8067143C: bne         $a0, $zero, L_80671448
    if (ctx->r4 != 0) {
        // 0x80671440: nop
    
            goto L_80671448;
    }
    // 0x80671440: nop

    // 0x80671444: break       7
    do_break(2154239044);
L_80671448:
    // 0x80671448: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8067144C: bne         $a0, $at, L_80671460
    if (ctx->r4 != ctx->r1) {
        // 0x80671450: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671460;
    }
    // 0x80671450: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671454: bne         $v0, $at, L_80671460
    if (ctx->r2 != ctx->r1) {
        // 0x80671458: nop
    
            goto L_80671460;
    }
    // 0x80671458: nop

    // 0x8067145C: break       6
    do_break(2154239068);
L_80671460:
    // 0x80671460: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671464: mflo        $t8
    ctx->r24 = lo;
    // 0x80671468: sw          $t8, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r24;
    // 0x8067146C: nop

    // 0x80671470: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x80671474: bne         $a2, $zero, L_80671480
    if (ctx->r6 != 0) {
        // 0x80671478: nop
    
            goto L_80671480;
    }
    // 0x80671478: nop

    // 0x8067147C: break       7
    do_break(2154239100);
L_80671480:
    // 0x80671480: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671484: bne         $a2, $at, L_80671498
    if (ctx->r6 != ctx->r1) {
        // 0x80671488: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671498;
    }
    // 0x80671488: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067148C: bne         $v0, $at, L_80671498
    if (ctx->r2 != ctx->r1) {
        // 0x80671490: nop
    
            goto L_80671498;
    }
    // 0x80671490: nop

    // 0x80671494: break       6
    do_break(2154239124);
L_80671498:
    // 0x80671498: mflo        $t9
    ctx->r25 = lo;
    // 0x8067149C: mfhi        $v0
    ctx->r2 = hi;
    // 0x806714A0: sw          $t9, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r25;
    // 0x806714A4: sw          $v0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->r2;
    // 0x806714A8: lw          $t2, -0x7498($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7498);
    // 0x806714AC: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806714B0: mflo        $v0
    ctx->r2 = lo;
    // 0x806714B4: slti        $at, $v0, 0x2711
    ctx->r1 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x806714B8: bne         $at, $zero, L_806714C4
    if (ctx->r1 != 0) {
        // 0x806714BC: nop
    
            goto L_806714C4;
    }
    // 0x806714BC: nop

    // 0x806714C0: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
L_806714C4:
    // 0x806714C4: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x806714C8: lw          $t3, 0x28($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X28);
    // 0x806714CC: mflo        $t5
    ctx->r13 = lo;
    // 0x806714D0: sw          $t5, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->r13;
    // 0x806714D4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x806714D8: sw          $t4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r12;
    // 0x806714DC: bne         $a1, $zero, L_806714E8
    if (ctx->r5 != 0) {
        // 0x806714E0: nop
    
            goto L_806714E8;
    }
    // 0x806714E0: nop

    // 0x806714E4: break       7
    do_break(2154239204);
L_806714E8:
    // 0x806714E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806714EC: bne         $a1, $at, L_80671500
    if (ctx->r5 != ctx->r1) {
        // 0x806714F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671500;
    }
    // 0x806714F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806714F4: bne         $v0, $at, L_80671500
    if (ctx->r2 != ctx->r1) {
        // 0x806714F8: nop
    
            goto L_80671500;
    }
    // 0x806714F8: nop

    // 0x806714FC: break       6
    do_break(2154239228);
L_80671500:
    // 0x80671500: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671504: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80671508: nop

    // 0x8067150C: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80671510: bne         $a0, $zero, L_8067151C
    if (ctx->r4 != 0) {
        // 0x80671514: nop
    
            goto L_8067151C;
    }
    // 0x80671514: nop

    // 0x80671518: break       7
    do_break(2154239256);
L_8067151C:
    // 0x8067151C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671520: bne         $a0, $at, L_80671534
    if (ctx->r4 != ctx->r1) {
        // 0x80671524: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671534;
    }
    // 0x80671524: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671528: bne         $v0, $at, L_80671534
    if (ctx->r2 != ctx->r1) {
        // 0x8067152C: nop
    
            goto L_80671534;
    }
    // 0x8067152C: nop

    // 0x80671530: break       6
    do_break(2154239280);
L_80671534:
    // 0x80671534: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671538: mflo        $t6
    ctx->r14 = lo;
    // 0x8067153C: sw          $t6, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r14;
    // 0x80671540: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x80671544: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x80671548: bne         $a2, $zero, L_80671554
    if (ctx->r6 != 0) {
        // 0x8067154C: nop
    
            goto L_80671554;
    }
    // 0x8067154C: nop

    // 0x80671550: break       7
    do_break(2154239312);
L_80671554:
    // 0x80671554: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80671558: bne         $a2, $at, L_8067156C
    if (ctx->r6 != ctx->r1) {
        // 0x8067155C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8067156C;
    }
    // 0x8067155C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671560: bne         $v0, $at, L_8067156C
    if (ctx->r2 != ctx->r1) {
        // 0x80671564: nop
    
            goto L_8067156C;
    }
    // 0x80671564: nop

    // 0x80671568: break       6
    do_break(2154239336);
L_8067156C:
    // 0x8067156C: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671570: sw          $v0, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r2;
    // 0x80671574: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x80671578: mflo        $t7
    ctx->r15 = lo;
    // 0x8067157C: sw          $t7, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r15;
    // 0x80671580: slti        $at, $v0, 0x2711
    ctx->r1 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80671584: bne         $at, $zero, L_80671598
    if (ctx->r1 != 0) {
        // 0x80671588: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_80671598;
    }
    // 0x80671588: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8067158C: addiu       $t8, $zero, 0x270F
    ctx->r24 = ADD32(0, 0X270F);
    // 0x80671590: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
    // 0x80671594: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
L_80671598:
    // 0x80671598: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x8067159C: bne         $a1, $zero, L_806715A8
    if (ctx->r5 != 0) {
        // 0x806715A0: nop
    
            goto L_806715A8;
    }
    // 0x806715A0: nop

    // 0x806715A4: break       7
    do_break(2154239396);
L_806715A8:
    // 0x806715A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806715AC: bne         $a1, $at, L_806715C0
    if (ctx->r5 != ctx->r1) {
        // 0x806715B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806715C0;
    }
    // 0x806715B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806715B4: bne         $v0, $at, L_806715C0
    if (ctx->r2 != ctx->r1) {
        // 0x806715B8: nop
    
            goto L_806715C0;
    }
    // 0x806715B8: nop

    // 0x806715BC: break       6
    do_break(2154239420);
L_806715C0:
    // 0x806715C0: mfhi        $v0
    ctx->r2 = hi;
    // 0x806715C4: mflo        $t9
    ctx->r25 = lo;
    // 0x806715C8: sw          $t9, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->r25;
    // 0x806715CC: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x806715D0: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x806715D4: bne         $a0, $zero, L_806715E0
    if (ctx->r4 != 0) {
        // 0x806715D8: nop
    
            goto L_806715E0;
    }
    // 0x806715D8: nop

    // 0x806715DC: break       7
    do_break(2154239452);
L_806715E0:
    // 0x806715E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806715E4: bne         $a0, $at, L_806715F8
    if (ctx->r4 != ctx->r1) {
        // 0x806715E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806715F8;
    }
    // 0x806715E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806715EC: bne         $v0, $at, L_806715F8
    if (ctx->r2 != ctx->r1) {
        // 0x806715F0: nop
    
            goto L_806715F8;
    }
    // 0x806715F0: nop

    // 0x806715F4: break       6
    do_break(2154239476);
L_806715F8:
    // 0x806715F8: mfhi        $v0
    ctx->r2 = hi;
    // 0x806715FC: mflo        $t2
    ctx->r10 = lo;
    // 0x80671600: sw          $t2, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r10;
    // 0x80671604: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80671608: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x8067160C: bne         $a2, $zero, L_80671618
    if (ctx->r6 != 0) {
        // 0x80671610: nop
    
            goto L_80671618;
    }
    // 0x80671610: nop

    // 0x80671614: break       7
    do_break(2154239508);
L_80671618:
    // 0x80671618: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8067161C: bne         $a2, $at, L_80671630
    if (ctx->r6 != ctx->r1) {
        // 0x80671620: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80671630;
    }
    // 0x80671620: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671624: bne         $v0, $at, L_80671630
    if (ctx->r2 != ctx->r1) {
        // 0x80671628: nop
    
            goto L_80671630;
    }
    // 0x80671628: nop

    // 0x8067162C: break       6
    do_break(2154239532);
L_80671630:
    // 0x80671630: mflo        $t3
    ctx->r11 = lo;
    // 0x80671634: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671638: sw          $t3, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->r11;
    // 0x8067163C: sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // 0x80671640: lw          $t4, -0x7478($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7478);
    // 0x80671644: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80671648: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8067164C: beql        $t4, $zero, L_80671720
    if (ctx->r12 == 0) {
        // 0x80671650: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80671720;
    }
    goto skip_0;
    // 0x80671650: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80671654: lhu         $t9, 0xFE8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XFE8);
    // 0x80671658: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8067165C: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80671660: sw          $t9, -0x7494($at)
    MEM_W(-0X7494, ctx->r1) = ctx->r25;
    // 0x80671664: lw          $t2, -0x7494($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7494);
    // 0x80671668: div         $zero, $t2, $a1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r5)));
    // 0x8067166C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80671670: mflo        $t3
    ctx->r11 = lo;
    // 0x80671674: sw          $t3, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->r11;
    // 0x80671678: sw          $t2, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r10;
    // 0x8067167C: bne         $a1, $zero, L_80671688
    if (ctx->r5 != 0) {
        // 0x80671680: nop
    
            goto L_80671688;
    }
    // 0x80671680: nop

    // 0x80671684: break       7
    do_break(2154239620);
L_80671688:
    // 0x80671688: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8067168C: bne         $a1, $at, L_806716A0
    if (ctx->r5 != ctx->r1) {
        // 0x80671690: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806716A0;
    }
    // 0x80671690: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671694: bne         $v0, $at, L_806716A0
    if (ctx->r2 != ctx->r1) {
        // 0x80671698: nop
    
            goto L_806716A0;
    }
    // 0x80671698: nop

    // 0x8067169C: break       6
    do_break(2154239644);
L_806716A0:
    // 0x806716A0: mfhi        $v0
    ctx->r2 = hi;
    // 0x806716A4: nop

    // 0x806716A8: nop

    // 0x806716AC: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x806716B0: bne         $a0, $zero, L_806716BC
    if (ctx->r4 != 0) {
        // 0x806716B4: nop
    
            goto L_806716BC;
    }
    // 0x806716B4: nop

    // 0x806716B8: break       7
    do_break(2154239672);
L_806716BC:
    // 0x806716BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806716C0: bne         $a0, $at, L_806716D4
    if (ctx->r4 != ctx->r1) {
        // 0x806716C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806716D4;
    }
    // 0x806716C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806716C8: bne         $v0, $at, L_806716D4
    if (ctx->r2 != ctx->r1) {
        // 0x806716CC: nop
    
            goto L_806716D4;
    }
    // 0x806716CC: nop

    // 0x806716D0: break       6
    do_break(2154239696);
L_806716D4:
    // 0x806716D4: mfhi        $v0
    ctx->r2 = hi;
    // 0x806716D8: mflo        $t4
    ctx->r12 = lo;
    // 0x806716DC: sw          $t4, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r12;
    // 0x806716E0: nop

    // 0x806716E4: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x806716E8: bne         $a2, $zero, L_806716F4
    if (ctx->r6 != 0) {
        // 0x806716EC: nop
    
            goto L_806716F4;
    }
    // 0x806716EC: nop

    // 0x806716F0: break       7
    do_break(2154239728);
L_806716F4:
    // 0x806716F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806716F8: bne         $a2, $at, L_8067170C
    if (ctx->r6 != ctx->r1) {
        // 0x806716FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8067170C;
    }
    // 0x806716FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80671700: bne         $v0, $at, L_8067170C
    if (ctx->r2 != ctx->r1) {
        // 0x80671704: nop
    
            goto L_8067170C;
    }
    // 0x80671704: nop

    // 0x80671708: break       6
    do_break(2154239752);
L_8067170C:
    // 0x8067170C: mflo        $t5
    ctx->r13 = lo;
    // 0x80671710: mfhi        $v0
    ctx->r2 = hi;
    // 0x80671714: sw          $t5, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r13;
    // 0x80671718: sw          $v0, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->r2;
    // 0x8067171C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80671720:
    // 0x80671720: jal         0x80672C80
    // 0x80671724: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80672C80(rdram, ctx);
        goto after_0;
    // 0x80671724: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80671728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067172C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80671730: jr          $ra
    // 0x80671734: nop

    return;
    // 0x80671734: nop

;}
RECOMP_FUNC void func_800724CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800724D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800724D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800724D8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800724DC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800724E0: sw          $t6, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r14;
    // 0x800724E4: addiu       $a0, $a0, -0x5928
    ctx->r4 = ADD32(ctx->r4, -0X5928);
    // 0x800724E8: jal         0x80082210
    // 0x800724EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800724EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800724F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800724F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800724F8: jr          $ra
    // 0x800724FC: nop

    return;
    // 0x800724FC: nop

;}
RECOMP_FUNC void func_804C1D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1D7C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C1D80: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804C1D84: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x804C1D88: jr          $ra
    // 0x804C1D8C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x804C1D8C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80044E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044E08: jal         0x80044DC0
    // 0x80044E0C: nop

    func_80044DC0(rdram, ctx);
        goto after_0;
    // 0x80044E0C: nop

    after_0:
    // 0x80044E10: beql        $v0, $zero, L_80044E2C
    if (ctx->r2 == 0) {
        // 0x80044E14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044E2C;
    }
    goto skip_0;
    // 0x80044E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80044E18:
    // 0x80044E18: jal         0x80044DC0
    // 0x80044E1C: nop

    func_80044DC0(rdram, ctx);
        goto after_1;
    // 0x80044E1C: nop

    after_1:
    // 0x80044E20: bne         $v0, $zero, L_80044E18
    if (ctx->r2 != 0) {
        // 0x80044E24: nop
    
            goto L_80044E18;
    }
    // 0x80044E24: nop

    // 0x80044E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044E2C:
    // 0x80044E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044E30: jr          $ra
    // 0x80044E34: nop

    return;
    // 0x80044E34: nop

;}
RECOMP_FUNC void func_805A925C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A925C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A9260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A9264: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A9268: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805A926C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x805A9270: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x805A9274: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x805A9278: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805A927C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x805A9280: nop

    // 0x805A9284: bc1fl       L_805A92F4
    if (!c1cs) {
        // 0x805A9288: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805A92F4;
    }
    goto skip_0;
    // 0x805A9288: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x805A928C: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x805A9290: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805A9294: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x805A9298: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x805A929C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x805A92A0: bne         $at, $zero, L_805A92D0
    if (ctx->r1 != 0) {
        // 0x805A92A4: swc1        $f6, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->f6.u32l;
            goto L_805A92D0;
    }
    // 0x805A92A4: swc1        $f6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f6.u32l;
    // 0x805A92A8: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x805A92AC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805A92B0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805A92B4: jal         0x80067BBC
    // 0x805A92B8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805A92B8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A92BC: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    // 0x805A92C0: jal         0x80067818
    // 0x805A92C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805A92C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805A92C8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x805A92CC: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_805A92D0:
    // 0x805A92D0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x805A92D4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x805A92D8: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x805A92DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805A92E0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x805A92E4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x805A92E8: b           L_805A9300
    // 0x805A92EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_805A9300;
    // 0x805A92EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805A92F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805A92F4:
    // 0x805A92F4: nop

    // 0x805A92F8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x805A92FC: swc1        $f10, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f10.u32l;
L_805A9300:
    // 0x805A9300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A9304: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A9308: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x805A930C: jr          $ra
    // 0x805A9310: nop

    return;
    // 0x805A9310: nop

;}
RECOMP_FUNC void func_8001EF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EF3C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001EF40: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001EF44: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8001EF48: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001EF4C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8001EF50: nop

    // 0x8001EF54: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8001EF58: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8001EF5C: bne         $at, $zero, L_8001EFA0
    if (ctx->r1 != 0) {
        // 0x8001EF60: subu        $t9, $t8, $v0
        ctx->r25 = SUB32(ctx->r24, ctx->r2);
            goto L_8001EFA0;
    }
    // 0x8001EF60: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x8001EF64: addiu       $t7, $v0, -0x8
    ctx->r15 = ADD32(ctx->r2, -0X8);
    // 0x8001EF68: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8001EF6C: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x8001EF70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001EF74: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EF78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EF7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001EF80: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001EF84: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001EF88: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8001EF8C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001EF90: nop

    // 0x8001EF94: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8001EF98: jr          $ra
    // 0x8001EF9C: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    return;
    // 0x8001EF9C: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
L_8001EFA0:
    // 0x8001EFA0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8001EFA4: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x8001EFA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001EFAC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001EFB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EFB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001EFB8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001EFBC: mul.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8001EFC0: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8001EFC4: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001EFC8: nop

    // 0x8001EFCC: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8001EFD0: add.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8001EFD4: jr          $ra
    // 0x8001EFD8: nop

    return;
    // 0x8001EFD8: nop

;}
RECOMP_FUNC void func_8071496C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071496C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80714970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80714974: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80714978: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8071497C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80714980: jal         0x80067BBC
    // 0x80714984: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80714984: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80714988: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8071498C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80714990: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80714994: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x80714998: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x8071499C: bne         $a1, $at, L_807149C0
    if (ctx->r5 != ctx->r1) {
        // 0x807149A0: nop
    
            goto L_807149C0;
    }
    // 0x807149A0: nop

    // 0x807149A4: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x807149A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807149AC: jal         0x80067F78
    // 0x807149B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x807149B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x807149B4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x807149B8: b           L_807149C8
    // 0x807149BC: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
        goto L_807149C8;
    // 0x807149BC: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
L_807149C0:
    // 0x807149C0: jal         0x800678F0
    // 0x807149C4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800678F0(rdram, ctx);
        goto after_2;
    // 0x807149C4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_2:
L_807149C8:
    // 0x807149C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807149CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807149D0: jr          $ra
    // 0x807149D4: nop

    return;
    // 0x807149D4: nop

;}
RECOMP_FUNC void func_8059F3CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F3CC: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8059F3D0: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(408, 0X1C0C) << 16);
    // 0x8059F3D4: addiu       $t9, $t9, 0xF6C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(408, 0X1C0C));
    // 0x8059F3D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8059F3DC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8059F3E0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8059F3E4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8059F3E8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8059F3EC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8059F3F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059F3F4: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x8059F3F8: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8059F3FC: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8059F400: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8059F404: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8059F408: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8059F40C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8059F410: addiu       $a3, $sp, 0xC
    ctx->r7 = ADD32(ctx->r29, 0XC);
    // 0x8059F414: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8059F418: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x8059F41C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8059F420: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8059F424: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8059F428: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8059F42C: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x8059F430: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8059F434: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x8059F438: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8059F43C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8059F440: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(408, 0X14A0) << 16);
    // 0x8059F444: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8059F448: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8059F44C: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8059F450: addiu       $t6, $t6, 0x800
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(408, 0X14A0));
    // 0x8059F454: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8059F458: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8059F45C: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8059F460: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8059F464: mflo        $t9
    ctx->r25 = lo;
    // 0x8059F468: addu        $t0, $t9, $t6
    ctx->r8 = ADD32(ctx->r25, ctx->r14);
    // 0x8059F46C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8059F470: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8059F474: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8059F478: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8059F47C: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x8059F480: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8059F484: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x8059F488: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
    // 0x8059F48C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8059F490: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x8059F494: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8059F498: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x8059F49C: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8059F4A0: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8059F4A4: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x8059F4A8: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x8059F4AC: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x8059F4B0: sw          $t2, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r10;
    // 0x8059F4B4: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x8059F4B8: sw          $t4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r12;
    // 0x8059F4BC: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
    // 0x8059F4C0: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8059F4C4: lui         $t3, 0x805A
    ctx->r11 = S32(RELOC_HI16(408, 0X1740) << 16);
    // 0x8059F4C8: addiu       $t3, $t3, 0xAA0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(408, 0X1740));
    // 0x8059F4CC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8059F4D0: nop

    // 0x8059F4D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8059F4D8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8059F4DC: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x8059F4E0: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x8059F4E4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8059F4E8: nop

    // 0x8059F4EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8059F4F0: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8059F4F4: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x8059F4F8: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8059F4FC: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8059F500: nop

    // 0x8059F504: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8059F508: swc1        $f8, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f8.u32l;
    // 0x8059F50C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8059F510: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8059F514: nop

    // 0x8059F518: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8059F51C: swc1        $f18, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f18.u32l;
    // 0x8059F520: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8059F524: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
    // 0x8059F528: lh          $t8, 0x38($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X38);
    // 0x8059F52C: sh          $t8, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r24;
    // 0x8059F530: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8059F534: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8059F538: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8059F53C: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x8059F540: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8059F544: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8059F548: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8059F54C: mflo        $t4
    ctx->r12 = lo;
    // 0x8059F550: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x8059F554: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8059F558: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8059F55C: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8059F560: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8059F564: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8059F568: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x8059F56C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8059F570: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x8059F574: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x8059F578: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x8059F57C: lw          $t8, 0x10($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X10);
    // 0x8059F580: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x8059F584: lw          $t7, 0x14($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X14);
    // 0x8059F588: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8059F58C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8059F590: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8059F594: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x8059F598: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
    // 0x8059F59C: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x8059F5A0: sw          $t6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r14;
    // 0x8059F5A4: sw          $t9, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r25;
    // 0x8059F5A8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8059F5AC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8059F5B0: nop

    // 0x8059F5B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8059F5B8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8059F5BC: swc1        $f10, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f10.u32l;
    // 0x8059F5C0: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x8059F5C4: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8059F5C8: nop

    // 0x8059F5CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8059F5D0: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8059F5D4: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x8059F5D8: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8059F5DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8059F5E0: swc1        $f8, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f8.u32l;
    // 0x8059F5E4: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8059F5E8: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8059F5EC: swc1        $f16, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f16.u32l;
    // 0x8059F5F0: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8059F5F4: swc1        $f18, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f18.u32l;
    // 0x8059F5F8: lh          $t2, 0x38($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X38);
    // 0x8059F5FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8059F600: jr          $ra
    // 0x8059F604: sh          $t2, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r10;
    return;
    // 0x8059F604: sh          $t2, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void func_80027384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027384: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80027388: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002738C: addiu       $t7, $t7, 0x7304
    ctx->r15 = ADD32(ctx->r15, 0X7304);
    // 0x80027390: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x80027394: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027398: jr          $ra
    // 0x8002739C: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    return;
    // 0x8002739C: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_806CD60C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD60C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CD610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CD614: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CD618: jal         0x806CCF00
    // 0x806CD61C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD61C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD620: jal         0x806CD470
    // 0x806CD624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD470(rdram, ctx);
        goto after_1;
    // 0x806CD624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD628: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806CD62C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD630: blez        $v0, L_806CD648
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806CD634: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806CD648;
    }
    // 0x806CD634: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806CD638: jal         0x806CD5CC
    // 0x806CD63C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    func_806CD5CC(rdram, ctx);
        goto after_2;
    // 0x806CD63C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    after_2:
    // 0x806CD640: b           L_806CD6A4
    // 0x806CD644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806CD6A4;
    // 0x806CD644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CD648:
    // 0x806CD648: jal         0x800653D8
    // 0x806CD64C: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x806CD64C: nop

    after_3:
    // 0x806CD650: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x806CD654: beq         $t7, $zero, L_806CD67C
    if (ctx->r15 == 0) {
        // 0x806CD658: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_806CD67C;
    }
    // 0x806CD658: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x806CD65C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x806CD660: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806CD664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD66C: jal         0x806CED40
    // 0x806CD670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806CED40(rdram, ctx);
        goto after_4;
    // 0x806CD670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x806CD674: b           L_806CD6A4
    // 0x806CD678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806CD6A4;
    // 0x806CD678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CD67C:
    // 0x806CD67C: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x806CD680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD688: jal         0x806CED40
    // 0x806CD68C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_806CED40(rdram, ctx);
        goto after_5;
    // 0x806CD68C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_5:
    // 0x806CD690: jal         0x806CCCE4
    // 0x806CD694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_6;
    // 0x806CD694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806CD698: jal         0x806CC008
    // 0x806CD69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CC008(rdram, ctx);
        goto after_7;
    // 0x806CD69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806CD6A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CD6A4:
    // 0x806CD6A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CD6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CD6AC: jr          $ra
    // 0x806CD6B0: nop

    return;
    // 0x806CD6B0: nop

;}
RECOMP_FUNC void func_80030E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030E14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80030E18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80030E1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80030E20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80030E24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80030E28: lw          $t7, 0x78($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X78);
    // 0x80030E2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030E30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80030E34: beq         $t7, $zero, L_80030ED4
    if (ctx->r15 == 0) {
        // 0x80030E38: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80030ED4;
    }
    // 0x80030E38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030E3C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80030E40: addiu       $t9, $t9, 0x3450
    ctx->r25 = ADD32(ctx->r25, 0X3450);
    // 0x80030E44: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
    // 0x80030E48: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80030E4C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80030E50: lw          $s1, 0x174($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X174);
    // 0x80030E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80030E58: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x80030E5C: andi        $t2, $t1, 0x700
    ctx->r10 = ctx->r9 & 0X700;
    // 0x80030E60: beq         $t2, $zero, L_80030E78
    if (ctx->r10 == 0) {
        // 0x80030E64: nop
    
            goto L_80030E78;
    }
    // 0x80030E64: nop

    // 0x80030E68: jal         0x8002DBE4
    // 0x80030E6C: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_0;
    // 0x80030E6C: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x80030E70: b           L_80030E84
    // 0x80030E74: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
        goto L_80030E84;
    // 0x80030E74: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_80030E78:
    // 0x80030E78: jal         0x8002DB78
    // 0x80030E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002DB78(rdram, ctx);
        goto after_1;
    // 0x80030E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80030E80: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
L_80030E84:
    // 0x80030E84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80030E8C: sh          $v0, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r2;
    // 0x80030E90: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80030E94: sh          $v0, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r2;
    // 0x80030E98: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80030E9C: jal         0x8005FDC4
    // 0x80030EA0: sh          $v0, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r2;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x80030EA0: sh          $v0, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r2;
    after_2:
    // 0x80030EA4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80030EA8: jal         0x8002ADE4
    // 0x80030EAC: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    func_8002ADE4(rdram, ctx);
        goto after_3;
    // 0x80030EAC: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    after_3:
    // 0x80030EB0: jal         0x8001DBEC
    // 0x80030EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001DBEC(rdram, ctx);
        goto after_4;
    // 0x80030EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80030EB8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80030EBC: jal         0x8002AFA0
    // 0x80030EC0: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    func_8002AFA0(rdram, ctx);
        goto after_5;
    // 0x80030EC0: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    after_5:
    // 0x80030EC4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80030EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030ECC: b           L_80030ED4
    // 0x80030ED0: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
        goto L_80030ED4;
    // 0x80030ED0: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
L_80030ED4:
    // 0x80030ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80030ED8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80030EDC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80030EE0: jr          $ra
    // 0x80030EE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80030EE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002DF30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DF30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DF34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002DF38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002DF3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002DF40: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DF44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002DF48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002DF4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002DF50: jal         0x8002AFDC
    // 0x8002DF54: swc1        $f4, 0x10C($s1)
    MEM_W(0X10C, ctx->r17) = ctx->f4.u32l;
    func_8002AFDC(rdram, ctx);
        goto after_0;
    // 0x8002DF54: swc1        $f4, 0x10C($s1)
    MEM_W(0X10C, ctx->r17) = ctx->f4.u32l;
    after_0:
    // 0x8002DF58: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8002DF5C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8002DF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002DF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DF68: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8002DF6C: lw          $t9, 0x78($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X78);
    // 0x8002DF70: jalr        $t9
    // 0x8002DF74: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002DF74: nop

    after_1:
    // 0x8002DF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002DF7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DF80: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8002DF84: jal         0x8002B9E4
    // 0x8002DF88: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_2;
    // 0x8002DF88: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8002DF8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002DF90: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002DF94: sb          $zero, 0x21($s1)
    MEM_B(0X21, ctx->r17) = 0;
    // 0x8002DF98: sh          $t8, 0x102($s1)
    MEM_H(0X102, ctx->r17) = ctx->r24;
    // 0x8002DF9C: jal         0x8001D770
    // 0x8002DFA0: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    func_8001D770(rdram, ctx);
        goto after_3;
    // 0x8002DFA0: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    after_3:
    // 0x8002DFA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002DFA8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002DFAC: jal         0x80067BF8
    // 0x8002DFB0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_4;
    // 0x8002DFB0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8002DFB4: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x8002DFB8: jal         0x80067818
    // 0x8002DFBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8002DFBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8002DFC0: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x8002DFC4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002DFC8: sb          $t0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r8;
    // 0x8002DFCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DFD0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002DFD4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8002DFD8: sb          $t1, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r9;
    // 0x8002DFDC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002DFE0: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x8002DFE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002DFE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002DFEC: sb          $t2, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r10;
    // 0x8002DFF0: jr          $ra
    // 0x8002DFF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002DFF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026214: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026218: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x8002621C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80026220: addiu       $t7, $t7, 0x61E0
    ctx->r15 = ADD32(ctx->r15, 0X61E0);
    // 0x80026224: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x80026228: sw          $zero, 0x80($v0)
    MEM_W(0X80, ctx->r2) = 0;
    // 0x8002622C: sb          $t6, 0x8C($v0)
    MEM_B(0X8C, ctx->r2) = ctx->r14;
    // 0x80026230: jr          $ra
    // 0x80026234: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
    return;
    // 0x80026234: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_8040C610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040C614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C618: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8040C61C: addiu       $at, $zero, 0x4085
    ctx->r1 = ADD32(0, 0X4085);
    // 0x8040C620: beq         $v0, $at, L_8040C660
    if (ctx->r2 == ctx->r1) {
        // 0x8040C624: addiu       $at, $zero, 0x4086
        ctx->r1 = ADD32(0, 0X4086);
            goto L_8040C660;
    }
    // 0x8040C624: addiu       $at, $zero, 0x4086
    ctx->r1 = ADD32(0, 0X4086);
    // 0x8040C628: beq         $v0, $at, L_8040C670
    if (ctx->r2 == ctx->r1) {
        // 0x8040C62C: addiu       $at, $zero, 0x4087
        ctx->r1 = ADD32(0, 0X4087);
            goto L_8040C670;
    }
    // 0x8040C62C: addiu       $at, $zero, 0x4087
    ctx->r1 = ADD32(0, 0X4087);
    // 0x8040C630: beq         $v0, $at, L_8040C680
    if (ctx->r2 == ctx->r1) {
        // 0x8040C634: addiu       $at, $zero, 0x4524
        ctx->r1 = ADD32(0, 0X4524);
            goto L_8040C680;
    }
    // 0x8040C634: addiu       $at, $zero, 0x4524
    ctx->r1 = ADD32(0, 0X4524);
    // 0x8040C638: beq         $v0, $at, L_8040C690
    if (ctx->r2 == ctx->r1) {
        // 0x8040C63C: addiu       $at, $zero, 0x4684
        ctx->r1 = ADD32(0, 0X4684);
            goto L_8040C690;
    }
    // 0x8040C63C: addiu       $at, $zero, 0x4684
    ctx->r1 = ADD32(0, 0X4684);
    // 0x8040C640: beq         $v0, $at, L_8040C6A0
    if (ctx->r2 == ctx->r1) {
        // 0x8040C644: addiu       $at, $zero, 0x4699
        ctx->r1 = ADD32(0, 0X4699);
            goto L_8040C6A0;
    }
    // 0x8040C644: addiu       $at, $zero, 0x4699
    ctx->r1 = ADD32(0, 0X4699);
    // 0x8040C648: beq         $v0, $at, L_8040C6B0
    if (ctx->r2 == ctx->r1) {
        // 0x8040C64C: addiu       $at, $zero, 0x469A
        ctx->r1 = ADD32(0, 0X469A);
            goto L_8040C6B0;
    }
    // 0x8040C64C: addiu       $at, $zero, 0x469A
    ctx->r1 = ADD32(0, 0X469A);
    // 0x8040C650: beq         $v0, $at, L_8040C6C0
    if (ctx->r2 == ctx->r1) {
        // 0x8040C654: nop
    
            goto L_8040C6C0;
    }
    // 0x8040C654: nop

    // 0x8040C658: b           L_8040C6CC
    // 0x8040C65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C6CC;
    // 0x8040C65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C660:
    // 0x8040C660: jal         0x8040DDCC
    // 0x8040C664: nop

    func_8040DDCC(rdram, ctx);
        goto after_0;
    // 0x8040C664: nop

    after_0:
    // 0x8040C668: b           L_8040C6CC
    // 0x8040C66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C6CC;
    // 0x8040C66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C670:
    // 0x8040C670: jal         0x8040DEAC
    // 0x8040C674: nop

    func_8040DEAC(rdram, ctx);
        goto after_1;
    // 0x8040C674: nop

    after_1:
    // 0x8040C678: b           L_8040C6CC
    // 0x8040C67C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C6CC;
    // 0x8040C67C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C680:
    // 0x8040C680: jal         0x8040DFD8
    // 0x8040C684: nop

    func_8040DFD8(rdram, ctx);
        goto after_2;
    // 0x8040C684: nop

    after_2:
    // 0x8040C688: b           L_8040C6CC
    // 0x8040C68C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C6CC;
    // 0x8040C68C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C690:
    // 0x8040C690: jal         0x8040E034
    // 0x8040C694: nop

    func_8040E034(rdram, ctx);
        goto after_3;
    // 0x8040C694: nop

    after_3:
    // 0x8040C698: b           L_8040C6CC
    // 0x8040C69C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C6CC;
    // 0x8040C69C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C6A0:
    // 0x8040C6A0: jal         0x8040E120
    // 0x8040C6A4: nop

    func_8040E120(rdram, ctx);
        goto after_4;
    // 0x8040C6A4: nop

    after_4:
    // 0x8040C6A8: b           L_8040C6CC
    // 0x8040C6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C6CC;
    // 0x8040C6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C6B0:
    // 0x8040C6B0: jal         0x8040E180
    // 0x8040C6B4: nop

    func_8040E180(rdram, ctx);
        goto after_5;
    // 0x8040C6B4: nop

    after_5:
    // 0x8040C6B8: b           L_8040C6CC
    // 0x8040C6BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C6CC;
    // 0x8040C6BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C6C0:
    // 0x8040C6C0: jal         0x8040E1E0
    // 0x8040C6C4: nop

    func_8040E1E0(rdram, ctx);
        goto after_6;
    // 0x8040C6C4: nop

    after_6:
    // 0x8040C6C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C6CC:
    // 0x8040C6CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040C6D0: jr          $ra
    // 0x8040C6D4: nop

    return;
    // 0x8040C6D4: nop

;}
RECOMP_FUNC void func_804C5694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5694: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C5698: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C569C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C56A0: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804C56A4: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804C56A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C56AC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x804C56B0: jal         0x804C50B4
    // 0x804C56B4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_804C50B4(rdram, ctx);
        goto after_0;
    // 0x804C56B4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x804C56B8: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(212, 0X99C) << 16);
    // 0x804C56BC: lwc1        $f12, 0x58DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(212, 0X99C));
    // 0x804C56C0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804C56C4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(212, 0X9A0) << 16);
    // 0x804C56C8: lwc1        $f4, 0x58E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(212, 0X9A0));
    // 0x804C56CC: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x804C56D0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804C56D4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804C56D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C56DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x804C56E0: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x804C56E4: bc1fl       L_804C5704
    if (!c1cs) {
        // 0x804C56E8: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_804C5704;
    }
    goto skip_0;
    // 0x804C56E8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x804C56EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C56F0: jal         0x804C57AC
    // 0x804C56F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_804C57AC(rdram, ctx);
        goto after_1;
    // 0x804C56F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x804C56F8: b           L_804C5748
    // 0x804C56FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804C5748;
    // 0x804C56FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C5700: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_804C5704:
    // 0x804C5704: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
    // 0x804C5708: jal         0x80048F84
    // 0x804C570C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x804C570C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x804C5710: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804C5714: jal         0x80048F84
    // 0x804C5718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x804C5718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x804C571C: jal         0x804C53C4
    // 0x804C5720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C53C4(rdram, ctx);
        goto after_4;
    // 0x804C5720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804C5724: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C5728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C572C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804C5730: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x804C5734: beql        $t6, $zero, L_804C5748
    if (ctx->r14 == 0) {
        // 0x804C5738: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C5748;
    }
    goto skip_1;
    // 0x804C5738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x804C573C: jal         0x804C57AC
    // 0x804C5740: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_804C57AC(rdram, ctx);
        goto after_5;
    // 0x804C5740: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_5:
    // 0x804C5744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C5748:
    // 0x804C5748: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C574C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804C5750: jr          $ra
    // 0x804C5754: nop

    return;
    // 0x804C5754: nop

;}
RECOMP_FUNC void func_8055799C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055799C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805579A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805579A4: jal         0x80557AA0
    // 0x805579A8: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    func_80557AA0(rdram, ctx);
        goto after_0;
    // 0x805579A8: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    after_0:
    // 0x805579AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805579B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805579B4: jr          $ra
    // 0x805579B8: nop

    return;
    // 0x805579B8: nop

;}
RECOMP_FUNC void func_8064F198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F198: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F19C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F1A0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F1A4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F1A8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F1AC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F1B0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F1B4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F1B8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F1BC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F1C0: jr          $ra
    // 0x8064F1C4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F1C4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8004488C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004488C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044894: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80044898: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8004489C: addiu       $a1, $a1, 0x4800
    ctx->r5 = ADD32(ctx->r5, 0X4800);
    // 0x800448A0: lw          $a2, 0x6C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X6C);
    // 0x800448A4: jal         0x80058000
    // 0x800448A8: addiu       $a0, $a0, 0x5C
    ctx->r4 = ADD32(ctx->r4, 0X5C);
    func_80058000(rdram, ctx);
        goto after_0;
    // 0x800448A8: addiu       $a0, $a0, 0x5C
    ctx->r4 = ADD32(ctx->r4, 0X5C);
    after_0:
    // 0x800448AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800448B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800448B4: jr          $ra
    // 0x800448B8: nop

    return;
    // 0x800448B8: nop

;}
RECOMP_FUNC void func_8058466C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058466C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584670: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584674: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584678: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058467C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584680: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584684: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584688: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058468C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584690: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584694: jr          $ra
    // 0x80584698: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584698: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800386B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800386B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800386B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800386BC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800386C0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800386C4: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x800386C8: lw          $t6, 0x78($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X78);
    // 0x800386CC: beql        $t6, $zero, L_8003871C
    if (ctx->r14 == 0) {
        // 0x800386D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003871C;
    }
    goto skip_0;
    // 0x800386D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800386D4: lh          $v0, 0xADE($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XADE);
    // 0x800386D8: lh          $a1, 0xAE0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0XAE0);
    // 0x800386DC: or          $t7, $v0, $a1
    ctx->r15 = ctx->r2 | ctx->r5;
    // 0x800386E0: beq         $t7, $zero, L_80038708
    if (ctx->r15 == 0) {
        // 0x800386E4: nop
    
            goto L_80038708;
    }
    // 0x800386E4: nop

    // 0x800386E8: lw          $v0, 0x60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X60);
    // 0x800386EC: slt         $t8, $zero, $a1
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800386F0: beql        $v0, $t8, L_8003871C
    if (ctx->r2 == ctx->r24) {
        // 0x800386F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003871C;
    }
    goto skip_1;
    // 0x800386F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x800386F8: jal         0x8002F574
    // 0x800386FC: nop

    func_8002F574(rdram, ctx);
        goto after_0;
    // 0x800386FC: nop

    after_0:
    // 0x80038700: b           L_8003871C
    // 0x80038704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003871C;
    // 0x80038704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038708:
    // 0x80038708: jal         0x8002F5B4
    // 0x8003870C: nop

    func_8002F5B4(rdram, ctx);
        goto after_1;
    // 0x8003870C: nop

    after_1:
    // 0x80038710: b           L_8003871C
    // 0x80038714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003871C;
    // 0x80038714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003871C:
    // 0x8003871C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038724: jr          $ra
    // 0x80038728: nop

    return;
    // 0x80038728: nop

;}
RECOMP_FUNC void func_80678048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067804C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80678050: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80678054: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80678058: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8067805C: jal         0x80067BBC
    // 0x80678060: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80678060: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80678064: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80678068: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8067806C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80678070: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x80678074: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80678078: bne         $a1, $at, L_8067809C
    if (ctx->r5 != ctx->r1) {
        // 0x8067807C: nop
    
            goto L_8067809C;
    }
    // 0x8067807C: nop

    // 0x80678080: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80678084: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80678088: jal         0x80067F78
    // 0x8067808C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8067808C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80678090: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80678094: b           L_806780A4
    // 0x80678098: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
        goto L_806780A4;
    // 0x80678098: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
L_8067809C:
    // 0x8067809C: jal         0x800678F0
    // 0x806780A0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800678F0(rdram, ctx);
        goto after_2;
    // 0x806780A0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_2:
L_806780A4:
    // 0x806780A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806780A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806780AC: jr          $ra
    // 0x806780B0: nop

    return;
    // 0x806780B0: nop

;}
RECOMP_FUNC void func_8004445C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004445C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80044464: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80044468: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004446C: lh          $t6, 0x4E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4E);
    // 0x80044470: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x80044474: addiu       $s1, $a0, 0x48
    ctx->r17 = ADD32(ctx->r4, 0X48);
    // 0x80044478: beq         $t6, $zero, L_800444BC
    if (ctx->r14 == 0) {
        // 0x8004447C: addiu       $s0, $s0, -0x77C0
        ctx->r16 = ADD32(ctx->r16, -0X77C0);
            goto L_800444BC;
    }
    // 0x8004447C: addiu       $s0, $s0, -0x77C0
    ctx->r16 = ADD32(ctx->r16, -0X77C0);
L_80044480:
    // 0x80044480: jal         0x80043DD4
    // 0x80044484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80043DD4(rdram, ctx);
        goto after_0;
    // 0x80044484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80044488: bne         $v0, $zero, L_800444A8
    if (ctx->r2 != 0) {
        // 0x8004448C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800444A8;
    }
    // 0x8004448C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80044490: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044494: addiu       $a0, $a0, 0x470
    ctx->r4 = ADD32(ctx->r4, 0X470);
    // 0x80044498: jal         0x80071380
    // 0x8004449C: addiu       $a1, $zero, 0x47F
    ctx->r5 = ADD32(0, 0X47F);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8004449C: addiu       $a1, $zero, 0x47F
    ctx->r5 = ADD32(0, 0X47F);
    after_1:
    // 0x800444A0: b           L_800444C0
    // 0x800444A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800444C0;
    // 0x800444A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800444A8:
    // 0x800444A8: jal         0x800440E4
    // 0x800444AC: nop

    func_800440E4(rdram, ctx);
        goto after_2;
    // 0x800444AC: nop

    after_2:
    // 0x800444B0: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x800444B4: bne         $t7, $zero, L_80044480
    if (ctx->r15 != 0) {
        // 0x800444B8: nop
    
            goto L_80044480;
    }
    // 0x800444B8: nop

L_800444BC:
    // 0x800444BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800444C0:
    // 0x800444C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800444C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800444C8: jr          $ra
    // 0x800444CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800444CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80792934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792934: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80792938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079293C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80792940: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80792944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80792948: jal         0x80790CB4
    // 0x8079294C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x8079294C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x80792950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792954: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80792958: jal         0x807925B0
    // 0x8079295C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807925B0(rdram, ctx);
        goto after_1;
    // 0x8079295C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80792960: bne         $v0, $zero, L_80792974
    if (ctx->r2 != 0) {
        // 0x80792964: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80792974;
    }
    // 0x80792964: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80792968: jal         0x807926B4
    // 0x8079296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807926B4(rdram, ctx);
        goto after_2;
    // 0x8079296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80792970: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80792974:
    // 0x80792974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792978: jal         0x80790714
    // 0x8079297C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80790714(rdram, ctx);
        goto after_3;
    // 0x8079297C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80792980: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80792984: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x80792988: beq         $t7, $zero, L_807929D0
    if (ctx->r15 == 0) {
        // 0x8079298C: nop
    
            goto L_807929D0;
    }
    // 0x8079298C: nop

    // 0x80792990: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x80792994: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80792998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079299C: bne         $a3, $zero, L_807929B8
    if (ctx->r7 != 0) {
        // 0x807929A0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_807929B8;
    }
    // 0x807929A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807929A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807929A8: jal         0x8079393C
    // 0x807929AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8079393C(rdram, ctx);
        goto after_4;
    // 0x807929AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x807929B0: b           L_807929C4
    // 0x807929B4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
        goto L_807929C4;
    // 0x807929B4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_807929B8:
    // 0x807929B8: jal         0x8079393C
    // 0x807929BC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8079393C(rdram, ctx);
        goto after_5;
    // 0x807929BC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_5:
    // 0x807929C0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_807929C4:
    // 0x807929C4: addiu       $t8, $zero, 0x1A
    ctx->r24 = ADD32(0, 0X1A);
    // 0x807929C8: b           L_807929E8
    // 0x807929CC: sb          $t8, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r24;
        goto L_807929E8;
    // 0x807929CC: sb          $t8, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r24;
L_807929D0:
    // 0x807929D0: beq         $v1, $zero, L_807929E8
    if (ctx->r3 == 0) {
        // 0x807929D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807929E8;
    }
    // 0x807929D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807929D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807929DC: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x807929E0: jal         0x8079393C
    // 0x807929E4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_6;
    // 0x807929E4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
L_807929E8:
    // 0x807929E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807929EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807929F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807929F4: jr          $ra
    // 0x807929F8: nop

    return;
    // 0x807929F8: nop

;}
RECOMP_FUNC void func_8006E2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E2B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E2B4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006E2B8: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8006E2BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E2C0: lw          $a0, 0x16C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C);
    // 0x8006E2C4: lw          $a2, 0xB0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XB0);
    // 0x8006E2C8: jal         0x800504D0
    // 0x8006E2CC: lw          $a1, 0xAC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XAC);
    func_800504D0(rdram, ctx);
        goto after_0;
    // 0x8006E2CC: lw          $a1, 0xAC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XAC);
    after_0:
    // 0x8006E2D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E2D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E2D8: jr          $ra
    // 0x8006E2DC: nop

    return;
    // 0x8006E2DC: nop

;}
RECOMP_FUNC void func_8046C460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C460: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8046C464: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(143, 0XBC) << 16);
    // 0x8046C468: addiu       $t6, $t6, -0x3AF4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(143, 0XBC));
    // 0x8046C46C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8046C470: jr          $ra
    // 0x8046C474: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8046C474: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8070FFC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FFC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8070FFC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070FFC8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8070FFCC: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x8070FFD0: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x8070FFD4: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8070FFD8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8070FFDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8070FFE0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8070FFE4: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x8070FFE8: addu        $a2, $t7, $v0
    ctx->r6 = ADD32(ctx->r15, ctx->r2);
    // 0x8070FFEC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8070FFF0: jal         0x8005B270
    // 0x8070FFF4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005B270(rdram, ctx);
        goto after_0;
    // 0x8070FFF4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8070FFF8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8070FFFC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80710000: sh          $v0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r2;
    // 0x80710004: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80710008: sh          $v0, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r2;
    // 0x8071000C: sh          $v0, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r2;
    // 0x80710010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80710014: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80710018: jr          $ra
    // 0x8071001C: nop

    return;
    // 0x8071001C: nop

;}
RECOMP_FUNC void func_8041FB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FB14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8041FB18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041FB1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041FB20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041FB24: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041FB28: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8041FB2C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8041FB30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8041FB34: jal         0x8041E9A8
    // 0x8041FB38: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8041E9A8(rdram, ctx);
        goto after_0;
    // 0x8041FB38: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8041FB3C: beq         $v0, $zero, L_8041FBCC
    if (ctx->r2 == 0) {
        // 0x8041FB40: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8041FBCC;
    }
    // 0x8041FB40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8041FB44: beq         $a0, $zero, L_8041FB98
    if (ctx->r4 == 0) {
        // 0x8041FB48: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8041FB98;
    }
    // 0x8041FB48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041FB4C: lh          $v0, 0x32($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X32);
    // 0x8041FB50: blez        $v0, L_8041FB60
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8041FB54: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8041FB60;
    }
    // 0x8041FB54: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8041FB58: b           L_8041FBB0
    // 0x8041FB5C: sh          $t7, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r15;
        goto L_8041FBB0;
    // 0x8041FB5C: sh          $t7, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r15;
L_8041FB60:
    // 0x8041FB60: jal         0x8004816C
    // 0x8041FB64: nop

    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8041FB64: nop

    after_1:
    // 0x8041FB68: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8041FB6C: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    // 0x8041FB70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8041FB74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041FB78: jal         0x8041FE10
    // 0x8041FB7C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_8041FE10(rdram, ctx);
        goto after_2;
    // 0x8041FB7C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_2:
    // 0x8041FB80: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8041FB84: sh          $t8, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r24;
    // 0x8041FB88: jal         0x8005FDC4
    // 0x8041FB8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x8041FB8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8041FB90: b           L_8041FBB0
    // 0x8041FB94: nop

        goto L_8041FBB0;
    // 0x8041FB94: nop

L_8041FB98:
    // 0x8041FB98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8041FB9C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8041FBA0: jal         0x8041FE10
    // 0x8041FBA4: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_4;
    // 0x8041FBA4: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_4:
    // 0x8041FBA8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8041FBAC: sh          $t9, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r25;
L_8041FBB0:
    // 0x8041FBB0: jal         0x8041F594
    // 0x8041FBB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8041F594(rdram, ctx);
        goto after_5;
    // 0x8041FBB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8041FBB8: jal         0x8041E5E8
    // 0x8041FBBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_6;
    // 0x8041FBBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8041FBC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8041FBC4: jal         0x8041E430
    // 0x8041FBC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8041E430(rdram, ctx);
        goto after_7;
    // 0x8041FBC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
L_8041FBCC:
    // 0x8041FBCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041FBD0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041FBD4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041FBD8: jr          $ra
    // 0x8041FBDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8041FBDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80069D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069D8C: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80069D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80069D94: beql        $v0, $zero, L_80069DAC
    if (ctx->r2 == 0) {
        // 0x80069D98: lw          $v0, 0x24($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X24);
            goto L_80069DAC;
    }
    goto skip_0;
    // 0x80069D98: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    skip_0:
    // 0x80069D9C: addiu       $a1, $v0, 0x7
    ctx->r5 = ADD32(ctx->r2, 0X7);
    // 0x80069DA0: srl         $a1, $a1, 3
    ctx->r5 = S32(U32(ctx->r5) >> 3);
    // 0x80069DA4: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x80069DA8: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_80069DAC:
    // 0x80069DAC: beq         $v0, $zero, L_80069DC0
    if (ctx->r2 == 0) {
        // 0x80069DB0: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_80069DC0;
    }
    // 0x80069DB0: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x80069DB4: srl         $t7, $t6, 3
    ctx->r15 = S32(U32(ctx->r14) >> 3);
    // 0x80069DB8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80069DBC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
L_80069DC0:
    // 0x80069DC0: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x80069DC4: beq         $v0, $zero, L_80069DD8
    if (ctx->r2 == 0) {
        // 0x80069DC8: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_80069DD8;
    }
    // 0x80069DC8: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x80069DCC: srl         $t0, $t9, 3
    ctx->r8 = S32(U32(ctx->r25) >> 3);
    // 0x80069DD0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80069DD4: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
L_80069DD8:
    // 0x80069DD8: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x80069DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80069DE0: beq         $t2, $zero, L_80069DF0
    if (ctx->r10 == 0) {
        // 0x80069DE4: nop
    
            goto L_80069DF0;
    }
    // 0x80069DE4: nop

    // 0x80069DE8: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x80069DEC: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
L_80069DF0:
    // 0x80069DF0: beq         $a1, $zero, L_80069E08
    if (ctx->r5 == 0) {
        // 0x80069DF4: nop
    
            goto L_80069E08;
    }
    // 0x80069DF4: nop

    // 0x80069DF8: jal         0x80064DD0
    // 0x80069DFC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x80069DFC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80069E00: b           L_80069E0C
    // 0x80069E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069E0C;
    // 0x80069E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069E08:
    // 0x80069E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069E0C:
    // 0x80069E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069E10: jr          $ra
    // 0x80069E14: nop

    return;
    // 0x80069E14: nop

;}
RECOMP_FUNC void func_8043AC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AC8C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043AC90: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11C8) << 16);
    // 0x8043AC94: lwc1        $f6, -0x47D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11C8));
    // 0x8043AC98: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043AC9C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11CC) << 16);
    // 0x8043ACA0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8043ACA4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8043ACA8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043ACAC: lwc1        $f10, -0x47D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11CC));
    // 0x8043ACB0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11D0) << 16);
    // 0x8043ACB4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043ACB8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8043ACBC: nop

    // 0x8043ACC0: bc1f        L_8043ACE8
    if (!c1cs) {
        // 0x8043ACC4: nop
    
            goto L_8043ACE8;
    }
    // 0x8043ACC4: nop

    // 0x8043ACC8: lwc1        $f16, -0x47D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11D0));
    // 0x8043ACCC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8043ACD0: nop

    // 0x8043ACD4: bc1f        L_8043ACE8
    if (!c1cs) {
        // 0x8043ACD8: nop
    
            goto L_8043ACE8;
    }
    // 0x8043ACD8: nop

    // 0x8043ACDC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8043ACE0: nop

    // 0x8043ACE4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8043ACE8:
    // 0x8043ACE8: jr          $ra
    // 0x8043ACEC: nop

    return;
    // 0x8043ACEC: nop

;}
RECOMP_FUNC void func_80429AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429AE8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80429AEC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80429AF0: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80429AF4: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(44, 0X238) << 16);
    // 0x80429AF8: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x80429AFC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80429B00: addiu       $t7, $t7, -0x62F8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(44, 0X238));
    // 0x80429B04: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80429B08: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80429B0C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x80429B10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80429B14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80429B18: jal         0x80429C44
    // 0x80429B1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80429C44(rdram, ctx);
        goto after_0;
    // 0x80429B1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80429B20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80429B24: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80429B28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80429B2C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80429B30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80429B34: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80429B38: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80429B3C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(44, 0X280) << 16);
    // 0x80429B40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80429B44: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80429B48: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80429B4C: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x80429B50: lwc1        $f4, -0x62B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(44, 0X280));
    // 0x80429B54: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x80429B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80429B5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429B60: jr          $ra
    // 0x80429B64: nop

    return;
    // 0x80429B64: nop

;}
RECOMP_FUNC void func_80666604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80666604: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80666608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066660C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x80666610: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x80666614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80666618: jal         0x80065728
    // 0x8066661C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8066661C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80666620: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80666624: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80666628: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8066662C: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x80666630: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80666634: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
    // 0x80666638: swc1        $f0, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f0.u32l;
    // 0x8066663C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80666640: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80666644: jr          $ra
    // 0x80666648: nop

    return;
    // 0x80666648: nop

;}
RECOMP_FUNC void func_80580CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580CE8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80580CEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80580CF0: nop

    // 0x80580CF4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80580CF8: div.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80580CFC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80580D00: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80580D04: jr          $ra
    // 0x80580D08: nop

    return;
    // 0x80580D08: nop

;}
RECOMP_FUNC void func_8003F4DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F4DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F4E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F4E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003F4E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F4EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003F4F0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003F4F4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003F4F8: jal         0x8003EBD4
    // 0x8003F4FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EBD4(rdram, ctx);
        goto after_0;
    // 0x8003F4FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003F500: jal         0x8003E520
    // 0x8003F504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E520(rdram, ctx);
        goto after_1;
    // 0x8003F504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003F508: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8003F50C: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003F510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F514: jalr        $t9
    // 0x8003F518: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8003F518: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_2:
    // 0x8003F51C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003F520: addiu       $t6, $t6, -0x1A14
    ctx->r14 = ADD32(ctx->r14, -0X1A14);
    // 0x8003F524: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F528: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F52C: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003F530: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003F534: jal         0x8003E6C4
    // 0x8003F538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8003E6C4(rdram, ctx);
        goto after_3;
    // 0x8003F538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8003F53C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8003F540: addiu       $a2, $a2, -0x7C48
    ctx->r6 = ADD32(ctx->r6, -0X7C48);
    // 0x8003F544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F548: jal         0x8003F14C
    // 0x8003F54C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8003F14C(rdram, ctx);
        goto after_4;
    // 0x8003F54C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x8003F550: jal         0x800447C8
    // 0x8003F554: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x8003F554: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x8003F558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F55C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F560: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003F564: jr          $ra
    // 0x8003F568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8003F568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_806F5360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5360: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806F5364: slti        $at, $v0, 0x464D
    ctx->r1 = SIGNED(ctx->r2) < 0X464D ? 1 : 0;
    // 0x806F5368: bne         $at, $zero, L_806F53A0
    if (ctx->r1 != 0) {
        // 0x806F536C: addiu       $at, $zero, 0x464D
        ctx->r1 = ADD32(0, 0X464D);
            goto L_806F53A0;
    }
    // 0x806F536C: addiu       $at, $zero, 0x464D
    ctx->r1 = ADD32(0, 0X464D);
    // 0x806F5370: beq         $v0, $at, L_806F53D4
    if (ctx->r2 == ctx->r1) {
        // 0x806F5374: addiu       $at, $zero, 0x464F
        ctx->r1 = ADD32(0, 0X464F);
            goto L_806F53D4;
    }
    // 0x806F5374: addiu       $at, $zero, 0x464F
    ctx->r1 = ADD32(0, 0X464F);
    // 0x806F5378: beq         $v0, $at, L_806F53E0
    if (ctx->r2 == ctx->r1) {
        // 0x806F537C: addiu       $at, $zero, 0x4676
        ctx->r1 = ADD32(0, 0X4676);
            goto L_806F53E0;
    }
    // 0x806F537C: addiu       $at, $zero, 0x4676
    ctx->r1 = ADD32(0, 0X4676);
    // 0x806F5380: beq         $v0, $at, L_806F53C8
    if (ctx->r2 == ctx->r1) {
        // 0x806F5384: addiu       $at, $zero, 0x467B
        ctx->r1 = ADD32(0, 0X467B);
            goto L_806F53C8;
    }
    // 0x806F5384: addiu       $at, $zero, 0x467B
    ctx->r1 = ADD32(0, 0X467B);
    // 0x806F5388: beq         $v0, $at, L_806F53C8
    if (ctx->r2 == ctx->r1) {
        // 0x806F538C: addiu       $at, $zero, 0x46BA
        ctx->r1 = ADD32(0, 0X46BA);
            goto L_806F53C8;
    }
    // 0x806F538C: addiu       $at, $zero, 0x46BA
    ctx->r1 = ADD32(0, 0X46BA);
    // 0x806F5390: beq         $v0, $at, L_806F53F8
    if (ctx->r2 == ctx->r1) {
        // 0x806F5394: lui         $t6, 0x806F
        ctx->r14 = S32(RELOC_HI16(685, 0X218) << 16);
            goto L_806F53F8;
    }
    // 0x806F5394: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(685, 0X218) << 16);
    // 0x806F5398: b           L_806F5410
    // 0x806F539C: nop

        goto L_806F5410;
    // 0x806F539C: nop

L_806F53A0:
    // 0x806F53A0: addiu       $at, $zero, 0x45EE
    ctx->r1 = ADD32(0, 0X45EE);
    // 0x806F53A4: beq         $v0, $at, L_806F53C8
    if (ctx->r2 == ctx->r1) {
        // 0x806F53A8: addiu       $at, $zero, 0x45EF
        ctx->r1 = ADD32(0, 0X45EF);
            goto L_806F53C8;
    }
    // 0x806F53A8: addiu       $at, $zero, 0x45EF
    ctx->r1 = ADD32(0, 0X45EF);
    // 0x806F53AC: beq         $v0, $at, L_806F53EC
    if (ctx->r2 == ctx->r1) {
        // 0x806F53B0: addiu       $at, $zero, 0x4603
        ctx->r1 = ADD32(0, 0X4603);
            goto L_806F53EC;
    }
    // 0x806F53B0: addiu       $at, $zero, 0x4603
    ctx->r1 = ADD32(0, 0X4603);
    // 0x806F53B4: beq         $v0, $at, L_806F53C8
    if (ctx->r2 == ctx->r1) {
        // 0x806F53B8: addiu       $at, $zero, 0x4604
        ctx->r1 = ADD32(0, 0X4604);
            goto L_806F53C8;
    }
    // 0x806F53B8: addiu       $at, $zero, 0x4604
    ctx->r1 = ADD32(0, 0X4604);
    // 0x806F53BC: beq         $v0, $at, L_806F53C8
    if (ctx->r2 == ctx->r1) {
        // 0x806F53C0: addiu       $at, $zero, 0x464C
        ctx->r1 = ADD32(0, 0X464C);
            goto L_806F53C8;
    }
    // 0x806F53C0: addiu       $at, $zero, 0x464C
    ctx->r1 = ADD32(0, 0X464C);
    // 0x806F53C4: bne         $v0, $at, L_806F5410
    if (ctx->r2 != ctx->r1) {
        // 0x806F53C8: lui         $v0, 0x806F
        ctx->r2 = S32(RELOC_HI16(685, 0XCF8) << 16);
            goto L_806F5410;
    }
L_806F53C8:
    // 0x806F53C8: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(685, 0XCF8) << 16);
    // 0x806F53CC: jr          $ra
    // 0x806F53D0: addiu       $v0, $v0, 0x6058
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XCF8));
    return;
    // 0x806F53D0: addiu       $v0, $v0, 0x6058
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XCF8));
L_806F53D4:
    // 0x806F53D4: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(685, 0XE0C) << 16);
    // 0x806F53D8: jr          $ra
    // 0x806F53DC: addiu       $v0, $v0, 0x616C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XE0C));
    return;
    // 0x806F53DC: addiu       $v0, $v0, 0x616C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XE0C));
L_806F53E0:
    // 0x806F53E0: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(685, 0XE60) << 16);
    // 0x806F53E4: jr          $ra
    // 0x806F53E8: addiu       $v0, $v0, 0x61C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XE60));
    return;
    // 0x806F53E8: addiu       $v0, $v0, 0x61C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XE60));
L_806F53EC:
    // 0x806F53EC: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(685, 0XF6C) << 16);
    // 0x806F53F0: jr          $ra
    // 0x806F53F4: addiu       $v0, $v0, 0x62CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XF6C));
    return;
    // 0x806F53F4: addiu       $v0, $v0, 0x62CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XF6C));
L_806F53F8:
    // 0x806F53F8: addiu       $t6, $t6, 0x5578
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(685, 0X218));
    // 0x806F53FC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F5400: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(685, 0X10FC) << 16);
    // 0x806F5404: sw          $t6, -0x72A4($at)
    MEM_W(-0X72A4, ctx->r1) = ctx->r14;
    // 0x806F5408: jr          $ra
    // 0x806F540C: addiu       $v0, $v0, 0x645C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0X10FC));
    return;
    // 0x806F540C: addiu       $v0, $v0, 0x645C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0X10FC));
L_806F5410:
    // 0x806F5410: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(685, 0XCF8) << 16);
    // 0x806F5414: addiu       $v0, $v0, 0x6058
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(685, 0XCF8));
    // 0x806F5418: jr          $ra
    // 0x806F541C: nop

    return;
    // 0x806F541C: nop

;}
RECOMP_FUNC void func_8073AD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073AD70: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8073AD74: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8073AD78: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x8073AD7C: addiu       $s4, $s4, 0x7EA0
    ctx->r20 = ADD32(ctx->r20, 0X7EA0);
    // 0x8073AD80: lw          $v1, 0xF54($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XF54);
    // 0x8073AD84: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8073AD88: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8073AD8C: andi        $t6, $v1, 0x40
    ctx->r14 = ctx->r3 & 0X40;
    // 0x8073AD90: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8073AD94: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8073AD98: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8073AD9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8073ADA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8073ADA4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8073ADA8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8073ADAC: lbu         $a3, 0xF5C($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0XF5C);
    // 0x8073ADB0: lbu         $t0, 0xF5D($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0XF5D);
    // 0x8073ADB4: beq         $t6, $zero, L_8073ADC0
    if (ctx->r14 == 0) {
        // 0x8073ADB8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8073ADC0;
    }
    // 0x8073ADB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8073ADBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8073ADC0:
    // 0x8073ADC0: lbu         $t1, 0xFB8($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0XFB8);
    // 0x8073ADC4: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x8073ADC8: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8073ADCC: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8073ADD0: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x8073ADD4: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x8073ADD8: andi        $t4, $v1, 0x80
    ctx->r12 = ctx->r3 & 0X80;
    // 0x8073ADDC: sb          $t3, 0xFB8($s4)
    MEM_B(0XFB8, ctx->r20) = ctx->r11;
    // 0x8073ADE0: beq         $t4, $zero, L_8073ADEC
    if (ctx->r12 == 0) {
        // 0x8073ADE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8073ADEC;
    }
    // 0x8073ADE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8073ADE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8073ADEC:
    // 0x8073ADEC: lbu         $t8, 0xFB8($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0XFB8);
    // 0x8073ADF0: lw          $t2, 0xFBC($s4)
    ctx->r10 = MEM_W(ctx->r20, 0XFBC);
    // 0x8073ADF4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8073ADF8: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8073ADFC: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8073AE00: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x8073AE04: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8073AE08: andi        $t1, $t8, 0xFFEF
    ctx->r9 = ctx->r24 & 0XFFEF;
    // 0x8073AE0C: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x8073AE10: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x8073AE14: or          $t8, $t2, $t6
    ctx->r24 = ctx->r10 | ctx->r14;
    // 0x8073AE18: sb          $t9, 0xFB8($s4)
    MEM_B(0XFB8, ctx->r20) = ctx->r25;
    // 0x8073AE1C: beq         $s5, $zero, L_8073AE90
    if (ctx->r21 == 0) {
        // 0x8073AE20: sw          $t8, 0xFBC($s4)
        MEM_W(0XFBC, ctx->r20) = ctx->r24;
            goto L_8073AE90;
    }
    // 0x8073AE20: sw          $t8, 0xFBC($s4)
    MEM_W(0XFBC, ctx->r20) = ctx->r24;
    // 0x8073AE24: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x8073AE28: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8073AE2C: beq         $at, $zero, L_8073AE70
    if (ctx->r1 == 0) {
        // 0x8073AE30: addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
            goto L_8073AE70;
    }
    // 0x8073AE30: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8073AE34: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x8073AE38: addiu       $s1, $s1, 0x7EB8
    ctx->r17 = ADD32(ctx->r17, 0X7EB8);
    // 0x8073AE3C: addiu       $s3, $s5, -0x1
    ctx->r19 = ADD32(ctx->r21, -0X1);
    // 0x8073AE40: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
L_8073AE44:
    // 0x8073AE44: lhu         $v0, 0xFC0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XFC0);
    // 0x8073AE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073AE4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8073AE50: jal         0x80069644
    // 0x8073AE54: sh          $v0, 0xFC8($s1)
    MEM_H(0XFC8, ctx->r17) = ctx->r2;
    func_80069644(rdram, ctx);
        goto after_0;
    // 0x8073AE54: sh          $v0, 0xFC8($s1)
    MEM_H(0XFC8, ctx->r17) = ctx->r2;
    after_0:
    // 0x8073AE58: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x8073AE5C: jal         0x80069610
    // 0x8073AE60: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80069610(rdram, ctx);
        goto after_1;
    // 0x8073AE60: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8073AE64: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8073AE68: bne         $s0, $s3, L_8073AE44
    if (ctx->r16 != ctx->r19) {
        // 0x8073AE6C: addiu       $s1, $s1, -0x8
        ctx->r17 = ADD32(ctx->r17, -0X8);
            goto L_8073AE44;
    }
    // 0x8073AE6C: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
L_8073AE70:
    // 0x8073AE70: lhu         $t7, 0x62($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X62);
    // 0x8073AE74: sll         $t1, $s5, 3
    ctx->r9 = S32(ctx->r21 << 3);
    // 0x8073AE78: addu        $t9, $s4, $t1
    ctx->r25 = ADD32(ctx->r20, ctx->r9);
    // 0x8073AE7C: sh          $t7, 0xFC0($t9)
    MEM_H(0XFC0, ctx->r25) = ctx->r15;
    // 0x8073AE80: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8073AE84: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8073AE88: jal         0x80069610
    // 0x8073AE8C: addiu       $a1, $a1, 0x1A
    ctx->r5 = ADD32(ctx->r5, 0X1A);
    func_80069610(rdram, ctx);
        goto after_2;
    // 0x8073AE8C: addiu       $a1, $a1, 0x1A
    ctx->r5 = ADD32(ctx->r5, 0X1A);
    after_2:
L_8073AE90:
    // 0x8073AE90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8073AE94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8073AE98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8073AE9C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8073AEA0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8073AEA4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8073AEA8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8073AEAC: jr          $ra
    // 0x8073AEB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8073AEB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_807999F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807999F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807999FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799A00: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80799A04: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80799A08: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80799A0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80799A10: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80799A14: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80799A18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80799A1C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80799A20: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80799A24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80799A28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80799A2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80799A30: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80799A34: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80799A38: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80799A3C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80799A40: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80799A44: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80799A48: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80799A4C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80799A50: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80799A54: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80799A58: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80799A5C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80799A60: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80799A64: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80799A68: jalr        $t9
    // 0x80799A6C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80799A6C: nop

    after_0:
    // 0x80799A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799A74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80799A78: jr          $ra
    // 0x80799A7C: nop

    return;
    // 0x80799A7C: nop

;}
RECOMP_FUNC void func_8003E618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E618: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003E61C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8003E620: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8003E624: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8003E628: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003E62C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8003E630: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003E634: sb          $t7, 0x1202($v0)
    MEM_B(0X1202, ctx->r2) = ctx->r15;
    // 0x8003E638: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8003E63C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003E640: swc1        $f4, 0x1204($v0)
    MEM_W(0X1204, ctx->r2) = ctx->f4.u32l;
    // 0x8003E644: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8003E648: sw          $a2, 0x11FC($v0)
    MEM_W(0X11FC, ctx->r2) = ctx->r6;
    // 0x8003E64C: swc1        $f8, 0x120C($v0)
    MEM_W(0X120C, ctx->r2) = ctx->f8.u32l;
    // 0x8003E650: jr          $ra
    // 0x8003E654: swc1        $f6, 0x1208($v0)
    MEM_W(0X1208, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8003E654: swc1        $f6, 0x1208($v0)
    MEM_W(0X1208, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8005EC98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005EC9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005ECA0: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x8005ECA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8005ECA8: lw          $t6, 0x1B0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X1B0);
    // 0x8005ECAC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8005ECB0: bnel        $t7, $zero, L_8005ECC4
    if (ctx->r15 != 0) {
        // 0x8005ECB4: lw          $v0, 0x2C($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X2C);
            goto L_8005ECC4;
    }
    goto skip_0;
    // 0x8005ECB4: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    skip_0:
    // 0x8005ECB8: b           L_8005EFD0
    // 0x8005ECBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005EFD0;
    // 0x8005ECBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005ECC0: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
L_8005ECC4:
    // 0x8005ECC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005ECC8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8005ECCC: bne         $v0, $at, L_8005ECDC
    if (ctx->r2 != ctx->r1) {
        // 0x8005ECD0: sll         $t9, $v0, 3
        ctx->r25 = S32(ctx->r2 << 3);
            goto L_8005ECDC;
    }
    // 0x8005ECD0: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x8005ECD4: b           L_8005EFD0
    // 0x8005ECD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005EFD0;
    // 0x8005ECD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005ECDC:
    // 0x8005ECDC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8005ECE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005ECE4: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8005ECE8: lw          $t8, -0x76C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76C8);
    // 0x8005ECEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005ECF0: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8005ECF4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005ECF8: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8005ECFC: bnel        $a3, $zero, L_8005ED10
    if (ctx->r7 != 0) {
        // 0x8005ED00: lbu         $t2, 0x165($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X165);
            goto L_8005ED10;
    }
    goto skip_1;
    // 0x8005ED00: lbu         $t2, 0x165($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X165);
    skip_1:
    // 0x8005ED04: b           L_8005EFD0
    // 0x8005ED08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005EFD0;
    // 0x8005ED08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005ED0C: lbu         $t2, 0x165($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X165);
L_8005ED10:
    // 0x8005ED10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005ED14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005ED18: beq         $t2, $at, L_8005EFD0
    if (ctx->r10 == ctx->r1) {
        // 0x8005ED1C: nop
    
            goto L_8005EFD0;
    }
    // 0x8005ED1C: nop

    // 0x8005ED20: lw          $t1, 0x1B8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1B8);
    // 0x8005ED24: lwc1        $f14, 0x6C($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x8005ED28: lwc1        $f16, 0x70($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X70);
    // 0x8005ED2C: lh          $t3, 0x4E($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X4E);
    // 0x8005ED30: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8005ED34: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8005ED38: sh          $t3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r11;
    // 0x8005ED3C: lh          $t4, 0x50($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X50);
    // 0x8005ED40: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8005ED44: sh          $t4, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r12;
    // 0x8005ED48: sw          $zero, 0x1AC($a3)
    MEM_W(0X1AC, ctx->r7) = 0;
    // 0x8005ED4C: sw          $zero, 0x1A8($a3)
    MEM_W(0X1A8, ctx->r7) = 0;
    // 0x8005ED50: sh          $t6, 0x1B0($a3)
    MEM_H(0X1B0, ctx->r7) = ctx->r14;
    // 0x8005ED54: sb          $t5, 0x1A0($a3)
    MEM_B(0X1A0, ctx->r7) = ctx->r13;
    // 0x8005ED58: lw          $t7, 0x1C0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C0);
    // 0x8005ED5C: sw          $a3, 0x1AC($a3)
    MEM_W(0X1AC, ctx->r7) = ctx->r7;
    // 0x8005ED60: sw          $t7, 0x1A8($a3)
    MEM_W(0X1A8, ctx->r7) = ctx->r15;
    // 0x8005ED64: lh          $t8, 0x52($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X52);
    // 0x8005ED68: sh          $t8, 0x28($a3)
    MEM_H(0X28, ctx->r7) = ctx->r24;
    // 0x8005ED6C: lh          $t9, 0x54($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X54);
    // 0x8005ED70: sh          $t9, 0x2A($a3)
    MEM_H(0X2A, ctx->r7) = ctx->r25;
    // 0x8005ED74: lbu         $t2, 0x28($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X28);
    // 0x8005ED78: sb          $t2, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r10;
    // 0x8005ED7C: lh          $t3, 0x2($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X2);
    // 0x8005ED80: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8005ED84: addiu       $t2, $t2, 0x6498
    ctx->r10 = ADD32(ctx->r10, 0X6498);
    // 0x8005ED88: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x8005ED8C: lh          $t4, 0x4($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X4);
    // 0x8005ED90: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x8005ED94: lwc1        $f4, 0x20($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X20);
    // 0x8005ED98: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
    // 0x8005ED9C: lwc1        $f6, 0x24($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X24);
    // 0x8005EDA0: swc1        $f6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f6.u32l;
    // 0x8005EDA4: lwc1        $f8, 0x84($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8005EDA8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005EDAC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8005EDB0: nop

    // 0x8005EDB4: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x8005EDB8: lwc1        $f18, 0x88($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8005EDBC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8005EDC0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8005EDC4: nop

    // 0x8005EDC8: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
    // 0x8005EDCC: lw          $t9, 0x1BC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X1BC);
    // 0x8005EDD0: sw          $t2, 0x19C($a3)
    MEM_W(0X19C, ctx->r7) = ctx->r10;
    // 0x8005EDD4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8005EDD8: lbu         $a1, 0xC($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0XC);
    // 0x8005EDDC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8005EDE0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8005EDE4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8005EDE8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005EDEC: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8005EDF0: jal         0x8005EC60
    // 0x8005EDF4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_8005EC60(rdram, ctx);
        goto after_0;
    // 0x8005EDF4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8005EDF8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005EDFC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EE00: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8005EE04: addiu       $v0, $t0, 0xD
    ctx->r2 = ADD32(ctx->r8, 0XD);
    // 0x8005EE08: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8005EE0C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x8005EE10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005EE14: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005EE18: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005EE1C: sb          $t3, 0x3C($t4)
    MEM_B(0X3C, ctx->r12) = ctx->r11;
    // 0x8005EE20: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x8005EE24: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8005EE28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EE2C: sb          $t5, 0x3D($t6)
    MEM_B(0X3D, ctx->r14) = ctx->r13;
    // 0x8005EE30: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8005EE34: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8005EE38: sb          $t7, 0x3E($t8)
    MEM_B(0X3E, ctx->r24) = ctx->r15;
    // 0x8005EE3C: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8005EE40: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8005EE44: sb          $t9, 0x3F($t2)
    MEM_B(0X3F, ctx->r10) = ctx->r25;
    // 0x8005EE48: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
    // 0x8005EE4C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x8005EE50: sb          $t3, 0x40($t4)
    MEM_B(0X40, ctx->r12) = ctx->r11;
    // 0x8005EE54: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x8005EE58: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8005EE5C: sb          $t5, 0x41($t6)
    MEM_B(0X41, ctx->r14) = ctx->r13;
    // 0x8005EE60: lbu         $t7, 0x6($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X6);
    // 0x8005EE64: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8005EE68: sb          $t7, 0x42($t8)
    MEM_B(0X42, ctx->r24) = ctx->r15;
    // 0x8005EE6C: lbu         $t9, 0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X7);
    // 0x8005EE70: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8005EE74: sb          $t9, 0x43($t2)
    MEM_B(0X43, ctx->r10) = ctx->r25;
    // 0x8005EE78: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x8005EE7C: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x8005EE80: bnel        $t4, $at, L_8005EEF4
    if (ctx->r12 != ctx->r1) {
        // 0x8005EE84: swc1        $f14, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f14.u32l;
            goto L_8005EEF4;
    }
    goto skip_2;
    // 0x8005EE84: swc1        $f14, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f14.u32l;
    skip_2:
    // 0x8005EE88: lwc1        $f12, 0x8C($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X8C);
    // 0x8005EE8C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8005EE90: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8005EE94: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005EE98: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8005EE9C: jal         0x80081C64
    // 0x8005EEA0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x8005EEA0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8005EEA4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8005EEA8: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8005EEAC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005EEB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005EEB4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005EEB8: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005EEBC: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005EEC0: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005EEC4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005EEC8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EECC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005EED0: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8005EED4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005EED8: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8005EEDC: div.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8005EEE0: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8005EEE4: nop

    // 0x8005EEE8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8005EEEC: nop

    // 0x8005EEF0: swc1        $f14, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f14.u32l;
L_8005EEF4:
    // 0x8005EEF4: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x8005EEF8: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x8005EEFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EF00: sh          $t5, 0x2C($a3)
    MEM_H(0X2C, ctx->r7) = ctx->r13;
    // 0x8005EF04: lh          $t6, 0x1C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1C);
    // 0x8005EF08: sh          $t6, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r14;
    // 0x8005EF0C: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x8005EF10: bne         $t7, $at, L_8005EFC8
    if (ctx->r15 != ctx->r1) {
        // 0x8005EF14: nop
    
            goto L_8005EFC8;
    }
    // 0x8005EF14: nop

    // 0x8005EF18: lw          $t8, 0x1B0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X1B0);
    // 0x8005EF1C: addiu       $a0, $a3, 0x54
    ctx->r4 = ADD32(ctx->r7, 0X54);
    // 0x8005EF20: addiu       $a1, $t0, 0x68
    ctx->r5 = ADD32(ctx->r8, 0X68);
    // 0x8005EF24: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x8005EF28: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    // 0x8005EF2C: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x8005EF30: sh          $t2, 0x30($a3)
    MEM_H(0X30, ctx->r7) = ctx->r10;
    // 0x8005EF34: lw          $t3, 0x1B0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X1B0);
    // 0x8005EF38: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8005EF3C: sw          $t4, 0x198($a3)
    MEM_W(0X198, ctx->r7) = ctx->r12;
    // 0x8005EF40: lbu         $t5, 0x69($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X69);
    // 0x8005EF44: beql        $t5, $zero, L_8005EF70
    if (ctx->r13 == 0) {
        // 0x8005EF48: addiu       $v0, $t0, 0x38
        ctx->r2 = ADD32(ctx->r8, 0X38);
            goto L_8005EF70;
    }
    goto skip_3;
    // 0x8005EF48: addiu       $v0, $t0, 0x38
    ctx->r2 = ADD32(ctx->r8, 0X38);
    skip_3:
    // 0x8005EF4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8005EF50: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8005EF54: jal         0x80065528
    // 0x8005EF58: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    func_80065528(rdram, ctx);
        goto after_2;
    // 0x8005EF58: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_2:
    // 0x8005EF5C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005EF60: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EF64: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005EF68: sb          $zero, 0x69($t0)
    MEM_B(0X69, ctx->r8) = 0;
    // 0x8005EF6C: addiu       $v0, $t0, 0x38
    ctx->r2 = ADD32(ctx->r8, 0X38);
L_8005EF70:
    // 0x8005EF70: addiu       $v1, $a3, 0x34
    ctx->r3 = ADD32(ctx->r7, 0X34);
    // 0x8005EF74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005EF78: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_8005EF7C:
    // 0x8005EF7C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8005EF80: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005EF84: beq         $a0, $zero, L_8005EFB4
    if (ctx->r4 == 0) {
        // 0x8005EF88: sb          $a0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r4;
            goto L_8005EFB4;
    }
    // 0x8005EF88: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8005EF8C: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8005EF90: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x8005EF94: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x8005EF98: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
    // 0x8005EF9C: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x8005EFA0: sh          $t8, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r24;
    // 0x8005EFA4: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x8005EFA8: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x8005EFAC: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x8005EFB0: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
L_8005EFB4:
    // 0x8005EFB4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8005EFB8: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x8005EFBC: bne         $a1, $a2, L_8005EF7C
    if (ctx->r5 != ctx->r6) {
        // 0x8005EFC0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8005EF7C;
    }
    // 0x8005EFC0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8005EFC4: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
L_8005EFC8:
    // 0x8005EFC8: b           L_8005EFD0
    // 0x8005EFCC: addiu       $v0, $a3, 0x1A0
    ctx->r2 = ADD32(ctx->r7, 0X1A0);
        goto L_8005EFD0;
    // 0x8005EFCC: addiu       $v0, $a3, 0x1A0
    ctx->r2 = ADD32(ctx->r7, 0X1A0);
L_8005EFD0:
    // 0x8005EFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005EFD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8005EFD8: jr          $ra
    // 0x8005EFDC: nop

    return;
    // 0x8005EFDC: nop

;}
RECOMP_FUNC void func_8003C7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C7C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003C7C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C7CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003C7D0: lw          $s0, 0x174($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X174);
    // 0x8003C7D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003C7D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8003C7DC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8003C7E0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8003C7E4: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x8003C7E8: jal         0x80047AB8
    // 0x8003C7EC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8003C7EC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8003C7F0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8003C7F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003C7F8: jal         0x80049E7C
    // 0x8003C7FC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_80049E7C(rdram, ctx);
        goto after_1;
    // 0x8003C7FC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x8003C800: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8003C804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003C80C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8003C810: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003C814: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8003C818: jal         0x80049864
    // 0x8003C81C: sh          $t9, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r25;
    func_80049864(rdram, ctx);
        goto after_2;
    // 0x8003C81C: sh          $t9, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r25;
    after_2:
    // 0x8003C820: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8003C824: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8003C828: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8003C82C: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8003C830: lhu         $t4, 0x42($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X42);
    // 0x8003C834: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003C838: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8003C83C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003C840: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003C844: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8003C848: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8003C84C: beql        $t4, $zero, L_8003C8E0
    if (ctx->r12 == 0) {
        // 0x8003C850: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003C8E0;
    }
    goto skip_0;
    // 0x8003C850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003C854: beq         $t4, $at, L_8003C8DC
    if (ctx->r12 == ctx->r1) {
        // 0x8003C858: lbu         $v0, 0x42($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X42);
            goto L_8003C8DC;
    }
    // 0x8003C858: lbu         $v0, 0x42($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X42);
    // 0x8003C85C: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8003C860: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8003C864: beq         $v0, $at, L_8003C8DC
    if (ctx->r2 == ctx->r1) {
        // 0x8003C868: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8003C8DC;
    }
    // 0x8003C868: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8003C86C: beq         $v0, $at, L_8003C8DC
    if (ctx->r2 == ctx->r1) {
        // 0x8003C870: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_8003C8DC;
    }
    // 0x8003C870: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8003C874: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003C878: jal         0x8003C710
    // 0x8003C87C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8003C710(rdram, ctx);
        goto after_3;
    // 0x8003C87C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x8003C880: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C884: bne         $v0, $zero, L_8003C89C
    if (ctx->r2 != 0) {
        // 0x8003C888: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_8003C89C;
    }
    // 0x8003C888: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8003C88C: jal         0x8003C764
    // 0x8003C890: lhu         $a0, 0x42($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X42);
    func_8003C764(rdram, ctx);
        goto after_4;
    // 0x8003C890: lhu         $a0, 0x42($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X42);
    after_4:
    // 0x8003C894: beql        $v0, $zero, L_8003C8E0
    if (ctx->r2 == 0) {
        // 0x8003C898: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003C8E0;
    }
    goto skip_1;
    // 0x8003C898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8003C89C:
    // 0x8003C89C: jal         0x8004700C
    // 0x8003C8A0: nop

    func_8004700C(rdram, ctx);
        goto after_5;
    // 0x8003C8A0: nop

    after_5:
    // 0x8003C8A4: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003C8A8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003C8AC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8003C8B0: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8003C8B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003C8B8: sb          $t5, 0x159($v1)
    MEM_B(0X159, ctx->r3) = ctx->r13;
    // 0x8003C8BC: sb          $t6, 0x15A($v1)
    MEM_B(0X15A, ctx->r3) = ctx->r14;
    // 0x8003C8C0: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x8003C8C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003C8C8: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8003C8CC: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x8003C8D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003C8D4: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8003C8D8: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
L_8003C8DC:
    // 0x8003C8DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003C8E0:
    // 0x8003C8E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003C8E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8003C8E8: jr          $ra
    // 0x8003C8EC: nop

    return;
    // 0x8003C8EC: nop

;}
RECOMP_FUNC void func_8006CB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB1C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006CB20: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x8006CB24: jr          $ra
    // 0x8006CB28: swc1        $f12, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8006CB28: swc1        $f12, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_8045E490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045E490: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8045E494: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045E498: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045E49C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8045E4A0: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x8045E4A4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8045E4A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045E4AC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8045E4B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8045E4B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8045E4B8: lw          $v0, 0x70($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X70);
    // 0x8045E4BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045E4C0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8045E4C4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8045E4C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8045E4CC: andi        $t7, $zero, 0xFFF7
    ctx->r15 = 0 & 0XFFF7;
    // 0x8045E4D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045E4D4: nop

    // 0x8045E4D8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8045E4DC: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8045E4E0: lwc1        $f18, 0xC8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x8045E4E4: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x8045E4E8: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8045E4EC: nop

    // 0x8045E4F0: bc1f        L_8045E504
    if (!c1cs) {
        // 0x8045E4F4: nop
    
            goto L_8045E504;
    }
    // 0x8045E4F4: nop

    // 0x8045E4F8: lhu         $t8, 0x28($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X28);
    // 0x8045E4FC: andi        $t9, $t8, 0xFF11
    ctx->r25 = ctx->r24 & 0XFF11;
    // 0x8045E500: sh          $t9, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r25;
L_8045E504:
    // 0x8045E504: lhu         $v1, 0x28($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X28);
    // 0x8045E508: andi        $t1, $v1, 0x10
    ctx->r9 = ctx->r3 & 0X10;
    // 0x8045E50C: sra         $t2, $t1, 4
    ctx->r10 = S32(SIGNED(ctx->r9) >> 4);
    // 0x8045E510: beq         $t2, $zero, L_8045E934
    if (ctx->r10 == 0) {
        // 0x8045E514: andi        $t3, $v1, 0x2
        ctx->r11 = ctx->r3 & 0X2;
            goto L_8045E934;
    }
    // 0x8045E514: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    // 0x8045E518: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8045E51C: beq         $t4, $zero, L_8045E834
    if (ctx->r12 == 0) {
        // 0x8045E520: addiu       $t5, $a3, 0xC4
        ctx->r13 = ADD32(ctx->r7, 0XC4);
            goto L_8045E834;
    }
    // 0x8045E520: addiu       $t5, $a3, 0xC4
    ctx->r13 = ADD32(ctx->r7, 0XC4);
    // 0x8045E524: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8045E528: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8045E52C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8045E530: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8045E534: nop

    // 0x8045E538: bc1fl       L_8045E838
    if (!c1cs) {
        // 0x8045E53C: andi        $t7, $v1, 0x1
        ctx->r15 = ctx->r3 & 0X1;
            goto L_8045E838;
    }
    goto skip_0;
    // 0x8045E53C: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    skip_0:
    // 0x8045E540: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x8045E544: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045E548: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x8045E54C: lw          $v0, 0x1F4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X1F4);
    // 0x8045E550: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8045E554: lhu         $t9, 0x4($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4);
    // 0x8045E558: ori         $t1, $t9, 0x2
    ctx->r9 = ctx->r25 | 0X2;
    // 0x8045E55C: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x8045E560: lhu         $v1, 0x28($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X28);
    // 0x8045E564: andi        $t2, $v1, 0x4
    ctx->r10 = ctx->r3 & 0X4;
    // 0x8045E568: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x8045E56C: bne         $t3, $zero, L_8045E714
    if (ctx->r11 != 0) {
        // 0x8045E570: andi        $t7, $v1, 0xFFF7
        ctx->r15 = ctx->r3 & 0XFFF7;
            goto L_8045E714;
    }
    // 0x8045E570: andi        $t7, $v1, 0xFFF7
    ctx->r15 = ctx->r3 & 0XFFF7;
    // 0x8045E574: lw          $t4, 0x7EA8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7EA8);
    // 0x8045E578: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8045E57C: lb          $v0, 0x2($t4)
    ctx->r2 = MEM_B(ctx->r12, 0X2);
    // 0x8045E580: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8045E584: beq         $at, $zero, L_8045E590
    if (ctx->r1 == 0) {
        // 0x8045E588: slti        $at, $v0, -0x9
        ctx->r1 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
            goto L_8045E590;
    }
    // 0x8045E588: slti        $at, $v0, -0x9
    ctx->r1 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x8045E58C: beq         $at, $zero, L_8045E5C4
    if (ctx->r1 == 0) {
        // 0x8045E590: lui         $at, 0x8046
        ctx->r1 = S32(RELOC_HI16(110, 0X12D0) << 16);
            goto L_8045E5C4;
    }
L_8045E590:
    // 0x8045E590: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12D0) << 16);
    // 0x8045E594: lwc1        $f6, -0x1020($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12D0));
    // 0x8045E598: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8045E59C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045E5A0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12D4) << 16);
    // 0x8045E5A4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8045E5A8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8045E5AC: bc1fl       L_8045E6E8
    if (!c1cs) {
        // 0x8045E5B0: lw          $a1, 0x8($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X8);
            goto L_8045E6E8;
    }
    goto skip_1;
    // 0x8045E5B0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x8045E5B4: lwc1        $f8, -0x101C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12D4));
    // 0x8045E5B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8045E5BC: nop

    // 0x8045E5C0: bc1f        L_8045E6E4
    if (!c1cs) {
        // 0x8045E5C4: andi        $t6, $v1, 0x8
        ctx->r14 = ctx->r3 & 0X8;
            goto L_8045E6E4;
    }
L_8045E5C4:
    // 0x8045E5C4: andi        $t6, $v1, 0x8
    ctx->r14 = ctx->r3 & 0X8;
    // 0x8045E5C8: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8045E5CC: bne         $t7, $zero, L_8045E610
    if (ctx->r15 != 0) {
        // 0x8045E5D0: addiu       $a0, $s0, 0x1C
        ctx->r4 = ADD32(ctx->r16, 0X1C);
            goto L_8045E610;
    }
    // 0x8045E5D0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045E5D4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8045E5D8: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8045E5DC: ori         $t8, $v1, 0x8
    ctx->r24 = ctx->r3 | 0X8;
    // 0x8045E5E0: sh          $t8, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r24;
    // 0x8045E5E4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045E5E8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8045E5EC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8045E5F0: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8045E5F4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8045E5F8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8045E5FC: jal         0x8045DD20
    // 0x8045E600: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8045DD20(rdram, ctx);
        goto after_0;
    // 0x8045E600: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x8045E604: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8045E608: b           L_8045E730
    // 0x8045E60C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
        goto L_8045E730;
    // 0x8045E60C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8045E610:
    // 0x8045E610: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8045E614: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8045E618: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8045E61C: jal         0x8045DD20
    // 0x8045E620: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    func_8045DD20(rdram, ctx);
        goto after_1;
    // 0x8045E620: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    after_1:
    // 0x8045E624: lhu         $t9, 0x28($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X28);
    // 0x8045E628: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8045E62C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8045E630: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x8045E634: sra         $t2, $t1, 5
    ctx->r10 = S32(SIGNED(ctx->r9) >> 5);
    // 0x8045E638: beq         $t2, $zero, L_8045E694
    if (ctx->r10 == 0) {
        // 0x8045E63C: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_8045E694;
    }
    // 0x8045E63C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8045E640: lwc1        $f12, 0x5C($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X5C);
    // 0x8045E644: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8045E648: jal         0x80066E88
    // 0x8045E64C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8045E64C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8045E650: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8045E654: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8045E658: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8045E65C: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8045E660: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x8045E664: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8045E668: jal         0x80066DE4
    // 0x8045E66C: lwc1        $f12, 0x5C($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X5C);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8045E66C: lwc1        $f12, 0x5C($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X5C);
    after_3:
    // 0x8045E670: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8045E674: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8045E678: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8045E67C: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8045E680: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8045E684: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8045E688: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8045E68C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8045E690: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
L_8045E694:
    // 0x8045E694: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8045E698: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8045E69C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8045E6A0: jal         0x80047AB8
    // 0x8045E6A4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_80047AB8(rdram, ctx);
        goto after_4;
    // 0x8045E6A4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_4:
    // 0x8045E6A8: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8045E6AC: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8045E6B0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8045E6B4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8045E6B8: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8045E6BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8045E6C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8045E6C4: swc1        $f10, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f10.u32l;
    // 0x8045E6C8: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8045E6CC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8045E6D0: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8045E6D4: swc1        $f6, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f6.u32l;
    // 0x8045E6D8: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x8045E6DC: b           L_8045E730
    // 0x8045E6E0: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
        goto L_8045E730;
    // 0x8045E6E0: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
L_8045E6E4:
    // 0x8045E6E4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
L_8045E6E8:
    // 0x8045E6E8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8045E6EC: jal         0x8045DD20
    // 0x8045E6F0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_8045DD20(rdram, ctx);
        goto after_5;
    // 0x8045E6F0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_5:
    // 0x8045E6F4: lhu         $t5, 0x28($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X28);
    // 0x8045E6F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8045E6FC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8045E700: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8045E704: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x8045E708: sh          $t6, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r14;
    // 0x8045E70C: b           L_8045E730
    // 0x8045E710: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
        goto L_8045E730;
    // 0x8045E710: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
L_8045E714:
    // 0x8045E714: sh          $t7, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r15;
    // 0x8045E718: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8045E71C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8045E720: jal         0x8045DD20
    // 0x8045E724: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_8045DD20(rdram, ctx);
        goto after_6;
    // 0x8045E724: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_6:
    // 0x8045E728: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8045E72C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_8045E730:
    // 0x8045E730: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8045E734: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045E738: lwc1        $f0, 0x50($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X50);
    // 0x8045E73C: lw          $t8, 0x16C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X16C);
    // 0x8045E740: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8045E744: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8045E748: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8045E74C: bc1fl       L_8045E77C
    if (!c1cs) {
        // 0x8045E750: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8045E77C;
    }
    goto skip_2;
    // 0x8045E750: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_2:
    // 0x8045E754: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045E758: nop

    // 0x8045E75C: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
L_8045E760:
    // 0x8045E760: swc1        $f4, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f4.u32l;
    // 0x8045E764: lwc1        $f0, 0x50($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X50);
    // 0x8045E768: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8045E76C: nop

    // 0x8045E770: bc1tl       L_8045E760
    if (c1cs) {
        // 0x8045E774: sub.s       $f4, $f0, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8045E760;
    }
    goto skip_3;
    // 0x8045E774: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x8045E778: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8045E77C:
    // 0x8045E77C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045E780: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8045E784: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045E788: nop

    // 0x8045E78C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8045E790: nop

    // 0x8045E794: bc1fl       L_8045E7BC
    if (!c1cs) {
        // 0x8045E798: lw          $t9, 0x138($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X138);
            goto L_8045E7BC;
    }
    goto skip_4;
    // 0x8045E798: lw          $t9, 0x138($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X138);
    skip_4:
    // 0x8045E79C: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
L_8045E7A0:
    // 0x8045E7A0: swc1        $f18, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f18.u32l;
    // 0x8045E7A4: lwc1        $f0, 0x50($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X50);
    // 0x8045E7A8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8045E7AC: nop

    // 0x8045E7B0: bc1tl       L_8045E7A0
    if (c1cs) {
        // 0x8045E7B4: add.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_8045E7A0;
    }
    goto skip_5;
    // 0x8045E7B4: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    skip_5:
    // 0x8045E7B8: lw          $t9, 0x138($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X138);
L_8045E7BC:
    // 0x8045E7BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8045E7C0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8045E7C4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8045E7C8: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8045E7CC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8045E7D0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8045E7D4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8045E7D8: beq         $t4, $at, L_8045E808
    if (ctx->r12 == ctx->r1) {
        // 0x8045E7DC: lui         $at, 0x8046
        ctx->r1 = S32(RELOC_HI16(110, 0X12D8) << 16);
            goto L_8045E808;
    }
    // 0x8045E7DC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12D8) << 16);
    // 0x8045E7E0: lwc1        $f8, -0x1018($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12D8));
    // 0x8045E7E4: lwc1        $f6, 0x5C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X5C);
    // 0x8045E7E8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12DC) << 16);
    // 0x8045E7EC: lwc1        $f10, -0x1014($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12DC));
    // 0x8045E7F0: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8045E7F4: nop

    // 0x8045E7F8: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8045E7FC: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8045E800: b           L_8045E874
    // 0x8045E804: swc1        $f18, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f18.u32l;
        goto L_8045E874;
    // 0x8045E804: swc1        $f18, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f18.u32l;
L_8045E808:
    // 0x8045E808: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12E0) << 16);
    // 0x8045E80C: lwc1        $f8, -0x1010($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12E0));
    // 0x8045E810: lwc1        $f6, 0x5C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x8045E814: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(110, 0X12E4) << 16);
    // 0x8045E818: lwc1        $f4, -0x100C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(110, 0X12E4));
    // 0x8045E81C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8045E820: nop

    // 0x8045E824: mul.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8045E828: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8045E82C: b           L_8045E874
    // 0x8045E830: swc1        $f18, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f18.u32l;
        goto L_8045E874;
    // 0x8045E830: swc1        $f18, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f18.u32l;
L_8045E834:
    // 0x8045E834: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
L_8045E838:
    // 0x8045E838: beq         $t7, $zero, L_8045E84C
    if (ctx->r15 == 0) {
        // 0x8045E83C: addiu       $a0, $s0, 0x1C
        ctx->r4 = ADD32(ctx->r16, 0X1C);
            goto L_8045E84C;
    }
    // 0x8045E83C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8045E840: lw          $t8, 0x34($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X34);
    // 0x8045E844: ori         $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 | 0X3000;
    // 0x8045E848: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
L_8045E84C:
    // 0x8045E84C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8045E850: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8045E854: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8045E858: jal         0x8045DD20
    // 0x8045E85C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8045DD20(rdram, ctx);
        goto after_7;
    // 0x8045E85C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_7:
    // 0x8045E860: lhu         $t1, 0x28($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X28);
    // 0x8045E864: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8045E868: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8045E86C: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8045E870: sh          $t2, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r10;
L_8045E874:
    // 0x8045E874: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045E878: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8045E87C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8045E880: nop

    // 0x8045E884: bc1fl       L_8045E8C4
    if (!c1cs) {
        // 0x8045E888: lw          $t7, 0x2C($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X2C);
            goto L_8045E8C4;
    }
    goto skip_6;
    // 0x8045E888: lw          $t7, 0x2C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X2C);
    skip_6:
    // 0x8045E88C: lw          $t3, 0x2C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X2C);
    // 0x8045E890: lui         $v0, 0xF
    ctx->r2 = S32(0XF << 16);
    // 0x8045E894: and         $t4, $t3, $v0
    ctx->r12 = ctx->r11 & ctx->r2;
    // 0x8045E898: bnel        $t4, $zero, L_8045E8F4
    if (ctx->r12 != 0) {
        // 0x8045E89C: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_8045E8F4;
    }
    goto skip_7;
    // 0x8045E89C: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_7:
    // 0x8045E8A0: lw          $t5, 0x28($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X28);
    // 0x8045E8A4: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x8045E8A8: bnel        $t6, $zero, L_8045E8F4
    if (ctx->r14 != 0) {
        // 0x8045E8AC: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_8045E8F4;
    }
    goto skip_8;
    // 0x8045E8AC: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_8:
    // 0x8045E8B0: lwc1        $f6, 0x3C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8045E8B4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8045E8B8: b           L_8045E8F0
    // 0x8045E8BC: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
        goto L_8045E8F0;
    // 0x8045E8BC: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x8045E8C0: lw          $t7, 0x2C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X2C);
L_8045E8C4:
    // 0x8045E8C4: lui         $v0, 0xF0
    ctx->r2 = S32(0XF0 << 16);
    // 0x8045E8C8: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x8045E8CC: bnel        $t8, $zero, L_8045E8F4
    if (ctx->r24 != 0) {
        // 0x8045E8D0: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_8045E8F4;
    }
    goto skip_9;
    // 0x8045E8D0: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_9:
    // 0x8045E8D4: lw          $t9, 0x28($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X28);
    // 0x8045E8D8: and         $t1, $t9, $v0
    ctx->r9 = ctx->r25 & ctx->r2;
    // 0x8045E8DC: bnel        $t1, $zero, L_8045E8F4
    if (ctx->r9 != 0) {
        // 0x8045E8E0: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_8045E8F4;
    }
    goto skip_10;
    // 0x8045E8E0: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_10:
    // 0x8045E8E4: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8045E8E8: add.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8045E8EC: swc1        $f10, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f10.u32l;
L_8045E8F0:
    // 0x8045E8F0: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
L_8045E8F4:
    // 0x8045E8F4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8045E8F8: nop

    // 0x8045E8FC: bc1tl       L_8045E928
    if (c1cs) {
        // 0x8045E900: lwc1        $f16, 0x40($a3)
        ctx->f16.u32l = MEM_W(ctx->r7, 0X40);
            goto L_8045E928;
    }
    goto skip_11;
    // 0x8045E900: lwc1        $f16, 0x40($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X40);
    skip_11:
    // 0x8045E904: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x8045E908: andi        $t3, $t2, 0x700
    ctx->r11 = ctx->r10 & 0X700;
    // 0x8045E90C: bnel        $t3, $zero, L_8045E940
    if (ctx->r11 != 0) {
        // 0x8045E910: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8045E940;
    }
    goto skip_12;
    // 0x8045E910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x8045E914: lw          $t4, 0x28($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X28);
    // 0x8045E918: andi        $t5, $t4, 0x700
    ctx->r13 = ctx->r12 & 0X700;
    // 0x8045E91C: bnel        $t5, $zero, L_8045E940
    if (ctx->r13 != 0) {
        // 0x8045E920: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8045E940;
    }
    goto skip_13;
    // 0x8045E920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x8045E924: lwc1        $f16, 0x40($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X40);
L_8045E928:
    // 0x8045E928: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8045E92C: b           L_8045E93C
    // 0x8045E930: swc1        $f18, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f18.u32l;
        goto L_8045E93C;
    // 0x8045E930: swc1        $f18, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f18.u32l;
L_8045E934:
    // 0x8045E934: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // 0x8045E938: sh          $t7, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r15;
L_8045E93C:
    // 0x8045E93C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045E940:
    // 0x8045E940: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045E944: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8045E948: jr          $ra
    // 0x8045E94C: nop

    return;
    // 0x8045E94C: nop

;}
RECOMP_FUNC void func_80737490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737490: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80737494: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80737498: lw          $t6, 0xA68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA68);
    // 0x8073749C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807374A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807374A4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x807374A8: lw          $v1, 0x70($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X70);
    // 0x807374AC: beql        $v1, $zero, L_80737510
    if (ctx->r3 == 0) {
        // 0x807374B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80737510;
    }
    goto skip_0;
    // 0x807374B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807374B4: lw          $t8, 0xD8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD8);
    // 0x807374B8: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x807374BC: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x807374C0: mfhi        $t9
    ctx->r25 = hi;
    // 0x807374C4: bnel        $t9, $zero, L_80737510
    if (ctx->r25 != 0) {
        // 0x807374C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80737510;
    }
    goto skip_1;
    // 0x807374C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x807374CC: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x807374D0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B50) << 16);
    // 0x807374D4: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x807374D8: beql        $v0, $zero, L_80737510
    if (ctx->r2 == 0) {
        // 0x807374DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80737510;
    }
    goto skip_2;
    // 0x807374DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x807374E0: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x807374E4: lwc1        $f6, -0x6A50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B50));
    // 0x807374E8: lwc1        $f12, 0x84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807374EC: lwc1        $f14, 0x88($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X88);
    // 0x807374F0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807374F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807374F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x807374FC: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x80737500: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80737504: jalr        $v1
    // 0x80737508: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80737508: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x8073750C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80737510:
    // 0x80737510: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80737514: jr          $ra
    // 0x80737518: nop

    return;
    // 0x80737518: nop

;}
RECOMP_FUNC void func_807C2F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C2F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C2F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C2F18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807C2F1C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807C2F20: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x807C2F24: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807C2F28: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807C2F2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C2F30: jal         0x807C32C0
    // 0x807C2F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807C32C0(rdram, ctx);
        goto after_0;
    // 0x807C2F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807C2F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C2F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C2F40: jr          $ra
    // 0x807C2F44: nop

    return;
    // 0x807C2F44: nop

;}
RECOMP_FUNC void func_806E7574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E7578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E757C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806E7580: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806E7584: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806E7588: jal         0x80062AEC
    // 0x806E758C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x806E758C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x806E7590: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806E7594: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806E7598: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E759C: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x806E75A0: beq         $v0, $at, L_806E75C0
    if (ctx->r2 == ctx->r1) {
        // 0x806E75A4: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_806E75C0;
    }
    // 0x806E75A4: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806E75A8: bnel        $v0, $at, L_806E75CC
    if (ctx->r2 != ctx->r1) {
        // 0x806E75AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E75CC;
    }
    goto skip_0;
    // 0x806E75AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E75B0: lbu         $t6, 0x18($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X18);
    // 0x806E75B4: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806E75B8: bnel        $t6, $at, L_806E75CC
    if (ctx->r14 != ctx->r1) {
        // 0x806E75BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E75CC;
    }
    goto skip_1;
    // 0x806E75BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_806E75C0:
    // 0x806E75C0: jal         0x806E7E4C
    // 0x806E75C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_806E7E4C(rdram, ctx);
        goto after_1;
    // 0x806E75C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x806E75C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E75CC:
    // 0x806E75CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E75D0: jr          $ra
    // 0x806E75D4: nop

    return;
    // 0x806E75D4: nop

;}
RECOMP_FUNC void func_806F6E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6E98: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806F6E9C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x806F6EA0: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(691, 0X8DC) << 16);
    // 0x806F6EA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F6EA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F6EAC: lw          $t8, 0x766C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(691, 0X8DC));
    // 0x806F6EB0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806F6EB4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806F6EB8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806F6EBC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x806F6EC0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806F6EC4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806F6EC8: beql        $v1, $zero, L_806F6EFC
    if (ctx->r3 == 0) {
        // 0x806F6ECC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F6EFC;
    }
    goto skip_0;
    // 0x806F6ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F6ED0: jalr        $v1
    // 0x806F6ED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806F6ED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F6ED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F6EDC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x806F6EE0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x806F6EE4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x806F6EE8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x806F6EEC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x806F6EF0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x806F6EF4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x806F6EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F6EFC:
    // 0x806F6EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6F00: jr          $ra
    // 0x806F6F04: nop

    return;
    // 0x806F6F04: nop

;}
RECOMP_FUNC void func_800696D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800696D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800696D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800696DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800696E0: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x800696E4: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800696E8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800696EC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800696F0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800696F4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800696F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800696FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80069700: addiu       $t1, $t0, 0xFEA
    ctx->r9 = ADD32(ctx->r8, 0XFEA);
    // 0x80069704: addiu       $t2, $t2, 0x7EA0
    ctx->r10 = ADD32(ctx->r10, 0X7EA0);
    // 0x80069708: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8006970C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80069710: jal         0x8006958C
    // 0x80069714: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    func_8006958C(rdram, ctx);
        goto after_0;
    // 0x80069714: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_0:
    // 0x80069718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006971C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069720: jr          $ra
    // 0x80069724: nop

    return;
    // 0x80069724: nop

;}
RECOMP_FUNC void func_8040CCAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040CCAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040CCB0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8040CCB4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8040CCB8: lw          $t6, 0xF74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF74);
    // 0x8040CCBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040CCC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8040CCC4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8040CCC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040CCCC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040CCD0: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8040CCD4: lw          $t7, 0xA68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XA68);
    // 0x8040CCD8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8040CCDC: lui         $a1, 0x8041
    ctx->r5 = S32(RELOC_HI16(20, 0X1E2C) << 16);
    // 0x8040CCE0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8040CCE4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8040CCE8: addiu       $a1, $a1, -0x1BD4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(20, 0X1E2C));
    // 0x8040CCEC: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8040CCF0: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8040CCF4: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8040CCF8: jalr        $t9
    // 0x8040CCFC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040CCFC: nop

    after_0:
    // 0x8040CD00: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x8040CD04: beq         $t0, $zero, L_8040CD28
    if (ctx->r8 == 0) {
        // 0x8040CD08: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8040CD28;
    }
L_8040CD08:
    // 0x8040CD08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8040CD0C: jal         0x8040E2A0
    // 0x8040CD10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8040E2A0(rdram, ctx);
        goto after_1;
    // 0x8040CD10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8040CD14: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x8040CD18: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8040CD1C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8040CD20: bne         $t2, $zero, L_8040CD08
    if (ctx->r10 != 0) {
        // 0x8040CD24: sw          $t2, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r10;
            goto L_8040CD08;
    }
    // 0x8040CD24: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
L_8040CD28:
    // 0x8040CD28: lw          $a0, 0x34($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X34);
    // 0x8040CD2C: jal         0x80067BBC
    // 0x8040CD30: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8040CD30: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    after_2:
    // 0x8040CD34: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    // 0x8040CD38: jal         0x80067818
    // 0x8040CD3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8040CD3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8040CD40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8040CD44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040CD48: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8040CD4C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8040CD50: jr          $ra
    // 0x8040CD54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8040CD54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80050128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050128: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050130: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80050134: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80050138: lh          $t8, 0x44($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X44);
    // 0x8005013C: lh          $t7, 0x42($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X42);
    // 0x80050140: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x80050144: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80050148: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005014C: sh          $a1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r5;
    // 0x80050150: mflo        $a3
    ctx->r7 = lo;
    // 0x80050154: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80050158: jal         0x8004FC60
    // 0x8005015C: nop

    func_8004FC60(rdram, ctx);
        goto after_0;
    // 0x8005015C: nop

    after_0:
    // 0x80050160: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80050164: jal         0x8004FCB0
    // 0x80050168: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004FCB0(rdram, ctx);
        goto after_1;
    // 0x80050168: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8005016C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80050170: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80050174: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x80050178: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005017C: blez        $a3, L_80050200
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80050180: sw          $v0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r2;
            goto L_80050200;
    }
    // 0x80050180: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80050184: andi        $a1, $a3, 0x3
    ctx->r5 = ctx->r7 & 0X3;
    // 0x80050188: beq         $a1, $zero, L_800501B4
    if (ctx->r5 == 0) {
        // 0x8005018C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800501B4;
    }
    // 0x8005018C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80050190:
    // 0x80050190: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80050194: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050198: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
    // 0x8005019C: lw          $t0, 0x14($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14);
    // 0x800501A0: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x800501A4: bne         $v0, $v1, L_80050190
    if (ctx->r2 != ctx->r3) {
        // 0x800501A8: sw          $t1, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r9;
            goto L_80050190;
    }
    // 0x800501A8: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x800501AC: beql        $v1, $a3, L_80050204
    if (ctx->r3 == ctx->r7) {
        // 0x800501B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80050204;
    }
    goto skip_0;
    // 0x800501B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800501B4:
    // 0x800501B4: lw          $t2, 0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X14);
    // 0x800501B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800501BC: sh          $a2, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r6;
    // 0x800501C0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800501C4: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800501C8: sw          $t4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r12;
    // 0x800501CC: sh          $a2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r6;
    // 0x800501D0: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x800501D4: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800501D8: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
    // 0x800501DC: sh          $a2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r6;
    // 0x800501E0: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800501E4: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x800501E8: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x800501EC: sh          $a2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r6;
    // 0x800501F0: lw          $t2, 0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X14);
    // 0x800501F4: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x800501F8: bne         $v1, $a3, L_800501B4
    if (ctx->r3 != ctx->r7) {
        // 0x800501FC: sw          $t3, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r11;
            goto L_800501B4;
    }
    // 0x800501FC: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
L_80050200:
    // 0x80050200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80050204:
    // 0x80050204: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80050208: jr          $ra
    // 0x8005020C: nop

    return;
    // 0x8005020C: nop

;}
RECOMP_FUNC void func_80034AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034AA8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034AAC: lw          $t6, 0x78($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X78);
    // 0x80034AB0: beql        $t6, $zero, L_80034B1C
    if (ctx->r14 == 0) {
        // 0x80034AB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80034B1C;
    }
    goto skip_0;
    // 0x80034AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80034AB8: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80034ABC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034AC0: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80034AC4: bnel        $t8, $zero, L_80034B1C
    if (ctx->r24 != 0) {
        // 0x80034AC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80034B1C;
    }
    goto skip_1;
    // 0x80034AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80034ACC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034AD0: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80034AD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034AD8: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80034ADC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034AE0: lwc1        $f10, 0xC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XC0);
    // 0x80034AE4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80034AE8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80034AEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034AF0: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80034AF4: addiu       $a1, $a1, -0x6E80
    ctx->r5 = ADD32(ctx->r5, -0X6E80);
    // 0x80034AF8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80034AFC: add.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80034B00: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80034B04: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80034B08: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80034B0C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80034B10: jal         0x800491B8
    // 0x80034B14: nop

    func_800491B8(rdram, ctx);
        goto after_0;
    // 0x80034B14: nop

    after_0:
    // 0x80034B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80034B1C:
    // 0x80034B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034B20: jr          $ra
    // 0x80034B24: nop

    return;
    // 0x80034B24: nop

;}
RECOMP_FUNC void func_80474F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474F70: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474F74: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474F78: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474F7C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474F80: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474F84: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474F88: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474F8C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474F90: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474F94: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474F98: jr          $ra
    // 0x80474F9C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474F9C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807B579C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B579C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B57A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B57A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B57A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B57AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B57B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B57B4: lw          $s2, 0x18($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X18);
    // 0x807B57B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B57BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_807B57C0:
    // 0x807B57C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B57C4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x807B57C8: jal         0x8005C27C
    // 0x807B57CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x807B57CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x807B57D0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B57D4: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x807B57D8: bnel        $at, $zero, L_807B57C0
    if (ctx->r1 != 0) {
        // 0x807B57DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_807B57C0;
    }
    goto skip_0;
    // 0x807B57DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x807B57E0: lui         $s1, 0x807B
    ctx->r17 = S32(RELOC_HI16(880, 0X2DF4) << 16);
    // 0x807B57E4: addiu       $s1, $s1, 0x75F4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(880, 0X2DF4));
    // 0x807B57E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B57EC: addiu       $s3, $zero, 0x1000
    ctx->r19 = ADD32(0, 0X1000);
    // 0x807B57F0: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
L_807B57F4:
    // 0x807B57F4: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x807B57F8: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x807B57FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B5800: sll         $a2, $s0, 3
    ctx->r6 = S32(ctx->r16 << 3);
    // 0x807B5804: bne         $s3, $a1, L_807B5814
    if (ctx->r19 != ctx->r5) {
        // 0x807B5808: nop
    
            goto L_807B5814;
    }
    // 0x807B5808: nop

    // 0x807B580C: b           L_807B581C
    // 0x807B5810: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
        goto L_807B581C;
    // 0x807B5810: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
L_807B5814:
    // 0x807B5814: jal         0x8005C27C
    // 0x807B5818: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x807B5818: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_807B581C:
    // 0x807B581C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807B5820: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x807B5824: bnel        $at, $zero, L_807B57F4
    if (ctx->r1 != 0) {
        // 0x807B5828: sll         $t6, $s0, 1
        ctx->r14 = S32(ctx->r16 << 1);
            goto L_807B57F4;
    }
    goto skip_1;
    // 0x807B5828: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    skip_1:
    // 0x807B582C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B5830: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B5834: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B5838: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B583C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B5840: jr          $ra
    // 0x807B5844: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B5844: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80079060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079060: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80079064: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80079068: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x8007906C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80079070: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80079074: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80079078: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8007907C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079080: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80079084: jal         0x8007FA00
    // 0x80079088: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    gfxprint_init(rdram, ctx);
        goto after_0;
    // 0x80079088: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007908C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079090: jal         0x8007FA48
    // 0x80079094: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    gfxprint_open(rdram, ctx);
        goto after_1;
    // 0x80079094: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_1:
    // 0x80079098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007909C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800790A0: jal         0x8007F464
    // 0x800790A4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    gfxprint_locate8x8(rdram, ctx);
        goto after_2;
    // 0x800790A4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_2:
    // 0x800790A8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800790AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800790B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800790B4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800790B8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800790BC: jal         0x8007F3F4
    // 0x800790C0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    gfxprint_color(rdram, ctx);
        goto after_3;
    // 0x800790C0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x800790C4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800790C8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800790CC: addiu       $a1, $a1, 0x2890
    ctx->r5 = ADD32(ctx->r5, 0X2890);
    // 0x800790D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800790D4: jal         0x8007FAAC
    // 0x800790D8: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    gfxprint_printf(rdram, ctx);
        goto after_4;
    // 0x800790D8: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    after_4:
    // 0x800790DC: jal         0x8007FA7C
    // 0x800790E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gfxprint_close(rdram, ctx);
        goto after_5;
    // 0x800790E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800790E4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800790E8: jal         0x8007FA40
    // 0x800790EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gfxprint_cleanup(rdram, ctx);
        goto after_6;
    // 0x800790EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800790F0: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800790F4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800790F8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800790FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80079100: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80079104: jr          $ra
    // 0x80079108: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80079108: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80441F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441F08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80441F0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80441F10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80441F14: jal         0x8004700C
    // 0x80441F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80441F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80441F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441F20: jal         0x80441EB8
    // 0x80441F24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80441EB8(rdram, ctx);
        goto after_1;
    // 0x80441F24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80441F28: beq         $v0, $zero, L_80441F40
    if (ctx->r2 == 0) {
        // 0x80441F2C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80441F40;
    }
    // 0x80441F2C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80441F30: jal         0x800445A4
    // 0x80441F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80441F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80441F38: b           L_80441FE4
    // 0x80441F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80441FE4;
    // 0x80441F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441F40:
    // 0x80441F40: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x80441F44: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(95, 0X3D7C) << 16);
    // 0x80441F48: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80441F4C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80441F50: addiu       $t6, $t6, 0x2C7C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(95, 0X3D7C));
    // 0x80441F54: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80441F58: beq         $v1, $zero, L_80441FAC
    if (ctx->r3 == 0) {
        // 0x80441F5C: sw          $zero, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = 0;
            goto L_80441FAC;
    }
    // 0x80441F5C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80441F60: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80441F64: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80441F68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80441F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441F70: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80441F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80441F78: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80441F7C: bc1f        L_80441F9C
    if (!c1cs) {
        // 0x80441F80: nop
    
            goto L_80441F9C;
    }
    // 0x80441F80: nop

    // 0x80441F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80441F8C: jal         0x80442188
    // 0x80441F90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80442188(rdram, ctx);
        goto after_3;
    // 0x80441F90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x80441F94: b           L_80441FC0
    // 0x80441F98: nop

        goto L_80441FC0;
    // 0x80441F98: nop

L_80441F9C:
    // 0x80441F9C: jal         0x80442188
    // 0x80441FA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80442188(rdram, ctx);
        goto after_4;
    // 0x80441FA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80441FA4: b           L_80441FC0
    // 0x80441FA8: nop

        goto L_80441FC0;
    // 0x80441FA8: nop

L_80441FAC:
    // 0x80441FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80441FB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80441FB8: jal         0x80442188
    // 0x80441FBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80442188(rdram, ctx);
        goto after_5;
    // 0x80441FBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
L_80441FC0:
    // 0x80441FC0: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(95, 0X154) << 16);
    // 0x80441FC4: addiu       $t8, $t8, -0xFAC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(95, 0X154));
    // 0x80441FC8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80441FCC: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x80441FD0: sh          $t9, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r25;
    // 0x80441FD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80441FD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80441FDC: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x80441FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441FE4:
    // 0x80441FE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80441FE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80441FEC: jr          $ra
    // 0x80441FF0: nop

    return;
    // 0x80441FF0: nop

;}
RECOMP_FUNC void guOrthoF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CB80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CB84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CB88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008CB8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008CB90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8008CB94: jal         0x80086EA0
    // 0x8008CB98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x8008CB98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008CB9C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008CBA0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008CBA4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008CBA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008CBAC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8008CBB0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8008CBB4: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8008CBB8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008CBBC: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8008CBC0: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8008CBC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008CBC8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8008CBCC: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8008CBD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008CBD4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8008CBD8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8008CBDC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8008CBE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008CBE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008CBE8: sub.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8008CBEC: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8008CBF0: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8008CBF4: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x8008CBF8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x8008CBFC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008CC00: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008CC04: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008CC08: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8008CC0C: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8008CC10: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x8008CC14: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8008CC18: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8008CC1C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8008CC20: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8008CC24: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8008CC28: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8008CC2C: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8008CC30: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x8008CC34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008CC38: nop

    // 0x8008CC3C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x8008CC40: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x8008CC44: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8008CC48: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8008CC4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008CC50: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8008CC54: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8008CC58: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8008CC5C: beq         $v1, $a0, L_8008CCA0
    if (ctx->r3 == ctx->r4) {
        // 0x8008CC60: lwc1        $f16, 0xC($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
            goto L_8008CCA0;
    }
    // 0x8008CC60: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
L_8008CC64:
    // 0x8008CC64: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8008CC68: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8008CC6C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8008CC70: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8008CC74: lwc1        $f14, 0x18($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8008CC78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008CC7C: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8008CC80: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8008CC84: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x8008CC88: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8008CC8C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8008CC90: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8008CC94: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008CC98: bne         $v1, $a0, L_8008CC64
    if (ctx->r3 != ctx->r4) {
        // 0x8008CC9C: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_8008CC64;
    }
    // 0x8008CC9C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
L_8008CCA0:
    // 0x8008CCA0: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8008CCA4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008CCA8: swc1        $f12, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f12.u32l;
    // 0x8008CCAC: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8008CCB0: nop

    // 0x8008CCB4: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8008CCB8: swc1        $f10, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8008CCBC: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8008CCC0: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8008CCC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CCC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CCCC: jr          $ra
    // 0x8008CCD0: nop

    return;
    // 0x8008CCD0: nop

;}
RECOMP_FUNC void func_80519170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519170: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80519174: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80519178: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8051917C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80519180: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80519184: jal         0x800653D8
    // 0x80519188: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80519188: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x8051918C: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x80519190: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80519194: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X2568) << 16);
    // 0x80519198: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8051919C: srl         $t8, $v0, 3
    ctx->r24 = S32(U32(ctx->r2) >> 3);
    // 0x805191A0: lwc1        $f12, -0x5E28($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X2568));
    // 0x805191A4: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x805191A8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805191AC: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X2588) << 16);
    // 0x805191B0: lw          $a0, 0x1E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1E0);
    // 0x805191B4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x805191B8: srl         $t1, $v0, 5
    ctx->r9 = S32(U32(ctx->r2) >> 5);
    // 0x805191BC: lwc1        $f20, -0x5E08($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X2588));
    // 0x805191C0: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x805191C4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x805191C8: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X25A8) << 16);
    // 0x805191CC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x805191D0: andi        $t4, $a0, 0x1
    ctx->r12 = ctx->r4 & 0X1;
    // 0x805191D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805191D8: beq         $t4, $zero, L_80519264
    if (ctx->r12 == 0) {
        // 0x805191DC: lwc1        $f22, -0x5DE8($at)
        ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X25A8));
            goto L_80519264;
    }
    // 0x805191DC: lwc1        $f22, -0x5DE8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X25A8));
    // 0x805191E0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x805191E4: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x805191E8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x805191EC: jal         0x80066E88
    // 0x805191F0: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x805191F0: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x805191F4: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x805191F8: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805191FC: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80519200: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80519204: jal         0x80066DE4
    // 0x80519208: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80519208: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8051920C: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80519210: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80519214: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80519218: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8051921C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80519220: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80519224: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80519228: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x8051922C: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80519230: swc1        $f22, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f22.u32l;
    // 0x80519234: swc1        $f22, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f22.u32l;
    // 0x80519238: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x8051923C: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x80519240: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x80519244: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80519248: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x8051924C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80519250: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80519254: jalr        $t9
    // 0x80519258: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80519258: nop

    after_3:
    // 0x8051925C: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80519260: lw          $a0, 0x1E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1E0);
L_80519264:
    // 0x80519264: andi        $t8, $a0, 0x3
    ctx->r24 = ctx->r4 & 0X3;
    // 0x80519268: beq         $t8, $zero, L_80519328
    if (ctx->r24 == 0) {
        // 0x8051926C: srl         $v1, $v1, 8
        ctx->r3 = S32(U32(ctx->r3) >> 8);
            goto L_80519328;
    }
    // 0x8051926C: srl         $v1, $v1, 8
    ctx->r3 = S32(U32(ctx->r3) >> 8);
    // 0x80519270: andi        $t0, $v1, 0x7
    ctx->r8 = ctx->r3 & 0X7;
    // 0x80519274: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80519278: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X2568) << 16);
    // 0x8051927C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80519280: srl         $t2, $v1, 3
    ctx->r10 = S32(U32(ctx->r3) >> 3);
    // 0x80519284: lwc1        $f12, -0x5E28($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X2568));
    // 0x80519288: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8051928C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80519290: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X2588) << 16);
    // 0x80519294: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80519298: srl         $t5, $v1, 5
    ctx->r13 = S32(U32(ctx->r3) >> 5);
    // 0x8051929C: lwc1        $f20, -0x5E08($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X2588));
    // 0x805192A0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x805192A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805192A8: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X25B0) << 16);
    // 0x805192AC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805192B0: lwc1        $f22, -0x5DE0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X25B0));
    // 0x805192B4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x805192B8: jal         0x80066E88
    // 0x805192BC: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x805192BC: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x805192C0: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x805192C4: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805192C8: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x805192CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805192D0: jal         0x80066DE4
    // 0x805192D4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x805192D4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x805192D8: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x805192DC: lwc1        $f18, 0x88($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805192E0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805192E4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x805192E8: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x805192EC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x805192F0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x805192F4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x805192F8: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x805192FC: swc1        $f22, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f22.u32l;
    // 0x80519300: swc1        $f22, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f22.u32l;
    // 0x80519304: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x80519308: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x8051930C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x80519310: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80519314: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80519318: lw          $t8, 0x10($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X10);
    // 0x8051931C: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80519320: jalr        $t9
    // 0x80519324: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80519324: nop

    after_6:
L_80519328:
    // 0x80519328: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8051932C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80519330: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80519334: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80519338: jr          $ra
    // 0x8051933C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8051933C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80073BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073BA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80073BAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80073BB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80073BB4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80073BB8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80073BBC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80073BC0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80073BC4: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80073BC8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80073BCC: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x80073BD0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073BD4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80073BD8: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80073BDC: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80073BE0: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80073BE4: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80073BE8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80073BEC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80073BF0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80073BF4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80073BF8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073BFC: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80073C00: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80073C04: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80073C08: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80073C0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073C10: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073C14: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x80073C18: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073C1C: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80073C20: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x80073C24: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80073C28: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x80073C2C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073C30: mflo        $t2
    ctx->r10 = lo;
    // 0x80073C34: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80073C38: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80073C3C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80073C40: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x80073C44: beq         $at, $zero, L_80073C54
    if (ctx->r1 == 0) {
        // 0x80073C48: nop
    
            goto L_80073C54;
    }
    // 0x80073C48: nop

    // 0x80073C4C: b           L_80073C54
    // 0x80073C50: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
        goto L_80073C54;
    // 0x80073C50: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
L_80073C54:
    // 0x80073C54: bgez        $a0, L_80073C64
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80073C58: sra         $t1, $a0, 3
        ctx->r9 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80073C64;
    }
    // 0x80073C58: sra         $t1, $a0, 3
    ctx->r9 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80073C5C: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x80073C60: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_80073C64:
    // 0x80073C64: bgtz        $t1, L_80073C74
    if (SIGNED(ctx->r9) > 0) {
        // 0x80073C68: or          $t2, $t1, $zero
        ctx->r10 = ctx->r9 | 0;
            goto L_80073C74;
    }
    // 0x80073C68: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x80073C6C: b           L_80073C74
    // 0x80073C70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80073C74;
    // 0x80073C70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80073C74:
    // 0x80073C74: bgtz        $t1, L_80073C84
    if (SIGNED(ctx->r9) > 0) {
        // 0x80073C78: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_80073C84;
    }
    // 0x80073C78: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x80073C7C: b           L_80073C88
    // 0x80073C80: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80073C88;
    // 0x80073C80: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80073C84:
    // 0x80073C84: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_80073C88:
    // 0x80073C88: div         $zero, $t7, $t3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r11)));
    // 0x80073C8C: mflo        $t8
    ctx->r24 = lo;
    // 0x80073C90: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80073C94: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80073C98: bne         $t3, $zero, L_80073CA4
    if (ctx->r11 != 0) {
        // 0x80073C9C: nop
    
            goto L_80073CA4;
    }
    // 0x80073C9C: nop

    // 0x80073CA0: break       7
    do_break(2147957920);
L_80073CA4:
    // 0x80073CA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80073CA8: bne         $t3, $at, L_80073CBC
    if (ctx->r11 != ctx->r1) {
        // 0x80073CAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80073CBC;
    }
    // 0x80073CAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80073CB0: bne         $t7, $at, L_80073CBC
    if (ctx->r15 != ctx->r1) {
        // 0x80073CB4: nop
    
            goto L_80073CBC;
    }
    // 0x80073CB4: nop

    // 0x80073CB8: break       6
    do_break(2147957944);
L_80073CBC:
    // 0x80073CBC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80073CC0: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x80073CC4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80073CC8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80073CCC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80073CD0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80073CD4: addu        $t7, $a3, $a0
    ctx->r15 = ADD32(ctx->r7, ctx->r4);
    // 0x80073CD8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80073CDC: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80073CE0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80073CE4: addu        $t6, $t1, $a2
    ctx->r14 = ADD32(ctx->r9, ctx->r6);
    // 0x80073CE8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80073CEC: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80073CF0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80073CF4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80073CF8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80073CFC: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x80073D00: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80073D04: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80073D08: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80073D0C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80073D10: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80073D14: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80073D18: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80073D1C: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x80073D20: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80073D24: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80073D28: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x80073D2C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80073D30: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80073D34: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80073D38: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80073D3C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80073D40: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80073D44: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073D48: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80073D4C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80073D50: jr          $ra
    // 0x80073D54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80073D54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80028DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028DB4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80028DB8: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x80028DBC: lw          $t1, 0xD0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XD0);
    // 0x80028DC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028DC4: lw          $t8, 0xFC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XFC);
    // 0x80028DC8: lwc1        $f4, -0x214($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X214);
    // 0x80028DCC: lwc1        $f0, 0xB0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XB0);
    // 0x80028DD0: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x80028DD4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80028DD8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80028DDC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80028DE0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80028DE4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80028DE8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80028DEC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80028DF0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80028DF4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80028DF8: lw          $t4, -0x218C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X218C);
    // 0x80028DFC: lw          $t6, 0x38($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X38);
    // 0x80028E00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028E04: bc1t        L_80028E20
    if (c1cs) {
        // 0x80028E08: subu        $v0, $t6, $t4
        ctx->r2 = SUB32(ctx->r14, ctx->r12);
            goto L_80028E20;
    }
    // 0x80028E08: subu        $v0, $t6, $t4
    ctx->r2 = SUB32(ctx->r14, ctx->r12);
    // 0x80028E0C: lwc1        $f6, -0x210($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X210);
    // 0x80028E10: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80028E14: nop

    // 0x80028E18: bc1fl       L_80028E70
    if (!c1cs) {
        // 0x80028E1C: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80028E70;
    }
    goto skip_0;
    // 0x80028E1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
L_80028E20:
    // 0x80028E20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80028E24: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x80028E28: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80028E2C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80028E30: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80028E34: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80028E38: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80028E3C: bc1f        L_80028E5C
    if (!c1cs) {
        // 0x80028E40: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_80028E5C;
    }
    // 0x80028E40: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80028E44: lw          $t7, -0x21BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X21BC);
    // 0x80028E48: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80028E4C: bnel        $at, $zero, L_80028E70
    if (ctx->r1 != 0) {
        // 0x80028E50: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80028E70;
    }
    goto skip_1;
    // 0x80028E50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x80028E54: jr          $ra
    // 0x80028E58: nop

    return;
    // 0x80028E58: nop

L_80028E5C:
    // 0x80028E5C: lw          $t9, -0x21EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X21EC);
    // 0x80028E60: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80028E64: beq         $at, $zero, L_80028E78
    if (ctx->r1 == 0) {
        // 0x80028E68: nop
    
            goto L_80028E78;
    }
    // 0x80028E68: nop

    // 0x80028E6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80028E70:
    // 0x80028E70: nop

    // 0x80028E74: swc1        $f10, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f10.u32l;
L_80028E78:
    // 0x80028E78: jr          $ra
    // 0x80028E7C: nop

    return;
    // 0x80028E7C: nop

;}
RECOMP_FUNC void func_8057DD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DD6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8057DD70: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_8057DD74:
    // 0x8057DD74: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8057DD78: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8057DD7C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8057DD80: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8057DD84: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8057DD88: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8057DD8C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8057DD90: addiu       $t7, $v0, 0x2
    ctx->r15 = ADD32(ctx->r2, 0X2);
    // 0x8057DD94: addiu       $t8, $v0, 0x3
    ctx->r24 = ADD32(ctx->r2, 0X3);
    // 0x8057DD98: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8057DD9C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8057DDA0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8057DDA4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8057DDA8: swc1        $f16, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x8057DDAC: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8057DDB0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8057DDB4: swc1        $f18, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = ctx->f18.u32l;
    // 0x8057DDB8: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8057DDBC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8057DDC0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8057DDC4: swc1        $f10, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8057DDC8: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8057DDCC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8057DDD0: swc1        $f16, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f16.u32l;
    // 0x8057DDD4: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8057DDD8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8057DDDC: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8057DDE0: swc1        $f6, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f6.u32l;
    // 0x8057DDE4: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8057DDE8: swc1        $f10, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f10.u32l;
    // 0x8057DDEC: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8057DDF0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8057DDF4: bne         $v0, $v1, L_8057DD74
    if (ctx->r2 != ctx->r3) {
        // 0x8057DDF8: swc1        $f4, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
            goto L_8057DD74;
    }
    // 0x8057DDF8: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8057DDFC: jr          $ra
    // 0x8057DE00: nop

    return;
    // 0x8057DE00: nop

;}
RECOMP_FUNC void func_804CCAB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CCAB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CCAB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CCABC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804CCAC0: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804CCAC4: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(237, 0X1BD8) << 16);
    // 0x804CCAC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CCACC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804CCAD0: lw          $t8, -0x1FB8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(237, 0X1BD8));
    // 0x804CCAD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804CCAD8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804CCADC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804CCAE0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804CCAE4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804CCAE8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804CCAEC: beql        $v1, $zero, L_804CCB20
    if (ctx->r3 == 0) {
        // 0x804CCAF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CCB20;
    }
    goto skip_0;
    // 0x804CCAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804CCAF4: jalr        $v1
    // 0x804CCAF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804CCAF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CCAFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CCB00: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804CCB04: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804CCB08: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804CCB0C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804CCB10: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804CCB14: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804CCB18: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804CCB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CCB20:
    // 0x804CCB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CCB24: jr          $ra
    // 0x804CCB28: nop

    return;
    // 0x804CCB28: nop

;}
RECOMP_FUNC void func_80517EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517EBC: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x80517EC0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80517EC4: lui         $a1, 0x8052
    ctx->r5 = S32(RELOC_HI16(291, 0X24A8) << 16);
    // 0x80517EC8: beq         $v0, $zero, L_805181B0
    if (ctx->r2 == 0) {
        // 0x80517ECC: nop
    
            goto L_805181B0;
    }
    // 0x80517ECC: nop

    // 0x80517ED0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80517ED4: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80517ED8: lw          $a1, -0x5EE8($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(291, 0X24A8));
    // 0x80517EDC: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x80517EE0: lw          $a3, 0x30($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X30);
    // 0x80517EE4: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80517EE8: lw          $t1, 0x38($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X38);
    // 0x80517EEC: beq         $v1, $zero, L_805181B0
    if (ctx->r3 == 0) {
        // 0x80517EF0: sw          $a1, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->r5;
            goto L_805181B0;
    }
    // 0x80517EF0: sw          $a1, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r5;
    // 0x80517EF4: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x80517EF8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80517EFC: beq         $a0, $zero, L_80517FA8
    if (ctx->r4 == 0) {
        // 0x80517F00: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_80517FA8;
    }
    // 0x80517F00: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x80517F04: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80517F08: beq         $v0, $v1, L_80517F60
    if (ctx->r2 == ctx->r3) {
        // 0x80517F0C: lh          $t7, 0x0($a1)
        ctx->r15 = MEM_H(ctx->r5, 0X0);
            goto L_80517F60;
    }
    // 0x80517F0C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
L_80517F10:
    // 0x80517F10: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80517F14: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80517F18: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80517F1C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517F20: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80517F24: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80517F28: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x80517F2C: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80517F30: lh          $t8, -0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, -0X4);
    // 0x80517F34: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80517F38: nop

    // 0x80517F3C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517F40: swc1        $f18, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f18.u32l;
    // 0x80517F44: lh          $t9, -0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, -0X2);
    // 0x80517F48: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80517F4C: nop

    // 0x80517F50: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517F54: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x80517F58: bne         $v0, $v1, L_80517F10
    if (ctx->r2 != ctx->r3) {
        // 0x80517F5C: lh          $t7, 0x0($a1)
        ctx->r15 = MEM_H(ctx->r5, 0X0);
            goto L_80517F10;
    }
    // 0x80517F5C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
L_80517F60:
    // 0x80517F60: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80517F64: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80517F68: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80517F6C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517F70: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80517F74: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x80517F78: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80517F7C: lh          $t8, -0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, -0X4);
    // 0x80517F80: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80517F84: nop

    // 0x80517F88: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517F8C: swc1        $f18, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f18.u32l;
    // 0x80517F90: lh          $t9, -0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, -0X2);
    // 0x80517F94: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80517F98: nop

    // 0x80517F9C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517FA0: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x80517FA4: beq         $v1, $zero, L_805181B0
    if (ctx->r3 == 0) {
        // 0x80517FA8: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_805181B0;
    }
L_80517FA8:
    // 0x80517FA8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80517FAC: beq         $v1, $zero, L_805180B8
    if (ctx->r3 == 0) {
        // 0x80517FB0: lh          $t2, 0x0($a1)
        ctx->r10 = MEM_H(ctx->r5, 0X0);
            goto L_805180B8;
    }
    // 0x80517FB0: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
L_80517FB4:
    // 0x80517FB4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80517FB8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80517FBC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80517FC0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517FC4: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80517FC8: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80517FCC: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80517FD0: swc1        $f18, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f18.u32l;
    // 0x80517FD4: lh          $t3, -0x16($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X16);
    // 0x80517FD8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80517FDC: nop

    // 0x80517FE0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517FE4: swc1        $f18, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f18.u32l;
    // 0x80517FE8: lh          $t4, -0x14($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X14);
    // 0x80517FEC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80517FF0: nop

    // 0x80517FF4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80517FF8: swc1        $f18, -0x10($t1)
    MEM_W(-0X10, ctx->r9) = ctx->f18.u32l;
    // 0x80517FFC: lh          $t5, -0x12($a1)
    ctx->r13 = MEM_H(ctx->r5, -0X12);
    // 0x80518000: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80518004: nop

    // 0x80518008: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8051800C: swc1        $f18, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f18.u32l;
    // 0x80518010: lh          $t6, -0x10($a1)
    ctx->r14 = MEM_H(ctx->r5, -0X10);
    // 0x80518014: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80518018: nop

    // 0x8051801C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518020: swc1        $f18, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f18.u32l;
    // 0x80518024: lh          $t7, -0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, -0XE);
    // 0x80518028: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8051802C: nop

    // 0x80518030: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518034: swc1        $f18, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80518038: lh          $t8, -0xC($a1)
    ctx->r24 = MEM_H(ctx->r5, -0XC);
    // 0x8051803C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80518040: nop

    // 0x80518044: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518048: swc1        $f18, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8051804C: lh          $t9, -0xA($a1)
    ctx->r25 = MEM_H(ctx->r5, -0XA);
    // 0x80518050: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80518054: nop

    // 0x80518058: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8051805C: swc1        $f18, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f18.u32l;
    // 0x80518060: lh          $t2, -0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X8);
    // 0x80518064: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80518068: nop

    // 0x8051806C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518070: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x80518074: lh          $t3, -0x6($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X6);
    // 0x80518078: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8051807C: nop

    // 0x80518080: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518084: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80518088: lh          $t4, -0x4($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X4);
    // 0x8051808C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80518090: nop

    // 0x80518094: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518098: swc1        $f18, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f18.u32l;
    // 0x8051809C: lh          $t5, -0x2($a1)
    ctx->r13 = MEM_H(ctx->r5, -0X2);
    // 0x805180A0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x805180A4: nop

    // 0x805180A8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805180AC: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x805180B0: bne         $v1, $zero, L_80517FB4
    if (ctx->r3 != 0) {
        // 0x805180B4: lh          $t2, 0x0($a1)
        ctx->r10 = MEM_H(ctx->r5, 0X0);
            goto L_80517FB4;
    }
    // 0x805180B4: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
L_805180B8:
    // 0x805180B8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x805180BC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x805180C0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x805180C4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805180C8: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x805180CC: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x805180D0: swc1        $f18, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f18.u32l;
    // 0x805180D4: lh          $t3, -0x16($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X16);
    // 0x805180D8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x805180DC: nop

    // 0x805180E0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805180E4: swc1        $f18, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f18.u32l;
    // 0x805180E8: lh          $t4, -0x14($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X14);
    // 0x805180EC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x805180F0: nop

    // 0x805180F4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805180F8: swc1        $f18, -0x10($t1)
    MEM_W(-0X10, ctx->r9) = ctx->f18.u32l;
    // 0x805180FC: lh          $t5, -0x12($a1)
    ctx->r13 = MEM_H(ctx->r5, -0X12);
    // 0x80518100: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80518104: nop

    // 0x80518108: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8051810C: swc1        $f18, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f18.u32l;
    // 0x80518110: lh          $t6, -0x10($a1)
    ctx->r14 = MEM_H(ctx->r5, -0X10);
    // 0x80518114: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80518118: nop

    // 0x8051811C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518120: swc1        $f18, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f18.u32l;
    // 0x80518124: lh          $t7, -0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, -0XE);
    // 0x80518128: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8051812C: nop

    // 0x80518130: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518134: swc1        $f18, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->f18.u32l;
    // 0x80518138: lh          $t8, -0xC($a1)
    ctx->r24 = MEM_H(ctx->r5, -0XC);
    // 0x8051813C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80518140: nop

    // 0x80518144: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518148: swc1        $f18, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8051814C: lh          $t9, -0xA($a1)
    ctx->r25 = MEM_H(ctx->r5, -0XA);
    // 0x80518150: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80518154: nop

    // 0x80518158: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8051815C: swc1        $f18, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f18.u32l;
    // 0x80518160: lh          $t2, -0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X8);
    // 0x80518164: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80518168: nop

    // 0x8051816C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518170: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x80518174: lh          $t3, -0x6($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X6);
    // 0x80518178: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8051817C: nop

    // 0x80518180: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518184: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80518188: lh          $t4, -0x4($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X4);
    // 0x8051818C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80518190: nop

    // 0x80518194: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518198: swc1        $f18, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f18.u32l;
    // 0x8051819C: lh          $t5, -0x2($a1)
    ctx->r13 = MEM_H(ctx->r5, -0X2);
    // 0x805181A0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x805181A4: nop

    // 0x805181A8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805181AC: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
L_805181B0:
    // 0x805181B0: jr          $ra
    // 0x805181B4: nop

    return;
    // 0x805181B4: nop

;}
RECOMP_FUNC void func_807AC734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AC738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AC73C: jal         0x8004700C
    // 0x807AC740: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807AC740: nop

    after_0:
    // 0x807AC744: beq         $v0, $zero, L_807AC784
    if (ctx->r2 == 0) {
        // 0x807AC748: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807AC784;
    }
    // 0x807AC748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AC74C: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x807AC750: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x807AC754: bnel        $a0, $t6, L_807AC788
    if (ctx->r4 != ctx->r14) {
        // 0x807AC758: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807AC788;
    }
    goto skip_0;
    // 0x807AC758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x807AC75C: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x807AC760: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x807AC764: beq         $v1, $a0, L_807AC77C
    if (ctx->r3 == ctx->r4) {
        // 0x807AC768: nop
    
            goto L_807AC77C;
    }
    // 0x807AC768: nop

    // 0x807AC76C: beq         $v1, $at, L_807AC77C
    if (ctx->r3 == ctx->r1) {
        // 0x807AC770: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_807AC77C;
    }
    // 0x807AC770: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x807AC774: bnel        $v1, $at, L_807AC788
    if (ctx->r3 != ctx->r1) {
        // 0x807AC778: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807AC788;
    }
    goto skip_1;
    // 0x807AC778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_807AC77C:
    // 0x807AC77C: b           L_807AC788
    // 0x807AC780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807AC788;
    // 0x807AC780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807AC784:
    // 0x807AC784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AC788:
    // 0x807AC788: jr          $ra
    // 0x807AC78C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807AC78C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805229DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805229DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805229E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805229E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805229E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805229EC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x805229F0: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x805229F4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805229F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805229FC: bne         $t6, $at, L_80522A64
    if (ctx->r14 != ctx->r1) {
        // 0x80522A00: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_80522A64;
    }
    // 0x80522A00: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80522A04: lbu         $t7, 0x165($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X165);
    // 0x80522A08: bnel        $t7, $zero, L_80522A68
    if (ctx->r15 != 0) {
        // 0x80522A0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80522A68;
    }
    goto skip_0;
    // 0x80522A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80522A10: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x80522A14: bnel        $t8, $zero, L_80522A68
    if (ctx->r24 != 0) {
        // 0x80522A18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80522A68;
    }
    goto skip_1;
    // 0x80522A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80522A1C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80522A20: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80522A24: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80522A28: jal         0x80067BBC
    // 0x80522A2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80522A2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80522A30: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    // 0x80522A34: jal         0x80067818
    // 0x80522A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80522A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80522A3C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80522A40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80522A44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80522A48: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80522A4C: addiu       $t1, $zero, 0x13
    ctx->r9 = ADD32(0, 0X13);
    // 0x80522A50: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80522A54: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x80522A58: sw          $t0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r8;
    // 0x80522A5C: jal         0x80523830
    // 0x80522A60: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    func_80523830(rdram, ctx);
        goto after_2;
    // 0x80522A60: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    after_2:
L_80522A64:
    // 0x80522A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80522A68:
    // 0x80522A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80522A6C: jr          $ra
    // 0x80522A70: nop

    return;
    // 0x80522A70: nop

;}
RECOMP_FUNC void func_80518D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80518D68: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80518D6C: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80518D70: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80518D74: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80518D78: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80518D7C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80518D80: sltu        $at, $a2, $t7
    ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
    // 0x80518D84: beq         $at, $zero, L_80518DD0
    if (ctx->r1 == 0) {
        // 0x80518D88: sltu        $at, $t7, $a2
        ctx->r1 = ctx->r15 < ctx->r6 ? 1 : 0;
            goto L_80518DD0;
    }
    // 0x80518D88: sltu        $at, $t7, $a2
    ctx->r1 = ctx->r15 < ctx->r6 ? 1 : 0;
    // 0x80518D8C: bne         $at, $zero, L_80518DAC
    if (ctx->r1 != 0) {
        // 0x80518D90: subu        $t8, $v1, $a2
        ctx->r24 = SUB32(ctx->r3, ctx->r6);
            goto L_80518DAC;
    }
    // 0x80518D90: subu        $t8, $v1, $a2
    ctx->r24 = SUB32(ctx->r3, ctx->r6);
L_80518D94:
    // 0x80518D94: sw          $t8, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r24;
    // 0x80518D98: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80518D9C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80518DA0: sltu        $at, $t8, $a2
    ctx->r1 = ctx->r24 < ctx->r6 ? 1 : 0;
    // 0x80518DA4: beql        $at, $zero, L_80518D94
    if (ctx->r1 == 0) {
        // 0x80518DA8: subu        $t8, $v1, $a2
        ctx->r24 = SUB32(ctx->r3, ctx->r6);
            goto L_80518D94;
    }
    goto skip_0;
    // 0x80518DA8: subu        $t8, $v1, $a2
    ctx->r24 = SUB32(ctx->r3, ctx->r6);
    skip_0:
L_80518DAC:
    // 0x80518DAC: lw          $v1, 0x14C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14C);
    // 0x80518DB0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80518DB4: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x80518DB8: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x80518DBC: beql        $at, $zero, L_80518DD0
    if (ctx->r1 == 0) {
        // 0x80518DC0: sw          $zero, 0x14C($a0)
        MEM_W(0X14C, ctx->r4) = 0;
            goto L_80518DD0;
    }
    goto skip_1;
    // 0x80518DC0: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    skip_1:
    // 0x80518DC4: jr          $ra
    // 0x80518DC8: sw          $t0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r8;
    return;
    // 0x80518DC8: sw          $t0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r8;
    // 0x80518DCC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
L_80518DD0:
    // 0x80518DD0: jr          $ra
    // 0x80518DD4: nop

    return;
    // 0x80518DD4: nop

;}
RECOMP_FUNC void func_80780048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80780050: jal         0x8077FE4C
    // 0x80780054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8077FE4C(rdram, ctx);
        goto after_0;
    // 0x80780054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80780058: beq         $v0, $zero, L_80780088
    if (ctx->r2 == 0) {
        // 0x8078005C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80780088;
    }
    // 0x8078005C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80780060: lui         $t7, 0x8078
    ctx->r15 = S32(RELOC_HI16(781, 0X4E4) << 16);
    // 0x80780064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80780068: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8078006C: addiu       $t7, $t7, -0x20C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(781, 0X4E4));
    // 0x80780070: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80780074: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x80780078: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8078007C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x80780080: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80780084: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
L_80780088:
    // 0x80780088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80780090: jr          $ra
    // 0x80780094: nop

    return;
    // 0x80780094: nop

;}
RECOMP_FUNC void func_806EA844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EA844: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x806EA848: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x806EA84C: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806EA850: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806EA854: nop

    // 0x806EA858: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806EA85C: nop

    // 0x806EA860: bc1fl       L_806EA890
    if (!c1cs) {
        // 0x806EA864: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_806EA890;
    }
    goto skip_0;
    // 0x806EA864: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x806EA868: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806EA86C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806EA870: nop

    // 0x806EA874: bc1f        L_806EA8AC
    if (!c1cs) {
        // 0x806EA878: nop
    
            goto L_806EA8AC;
    }
    // 0x806EA878: nop

    // 0x806EA87C: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806EA880: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x806EA884: jr          $ra
    // 0x806EA888: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x806EA888: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x806EA88C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_806EA890:
    // 0x806EA890: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806EA894: nop

    // 0x806EA898: bc1f        L_806EA8AC
    if (!c1cs) {
        // 0x806EA89C: nop
    
            goto L_806EA8AC;
    }
    // 0x806EA89C: nop

    // 0x806EA8A0: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806EA8A4: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x806EA8A8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_806EA8AC:
    // 0x806EA8AC: jr          $ra
    // 0x806EA8B0: nop

    return;
    // 0x806EA8B0: nop

;}
RECOMP_FUNC void func_8041DD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DD44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8041DD48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8041DD4C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8041DD50: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8041DD54: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8041DD58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8041DD5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8041DD60: jal         0x8041E20C
    // 0x8041DD64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8041E20C(rdram, ctx);
        goto after_0;
    // 0x8041DD64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8041DD68: beq         $v0, $zero, L_8041DE84
    if (ctx->r2 == 0) {
        // 0x8041DD6C: nop
    
            goto L_8041DE84;
    }
    // 0x8041DD6C: nop

    // 0x8041DD70: jal         0x8041E2A0
    // 0x8041DD74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8041E2A0(rdram, ctx);
        goto after_1;
    // 0x8041DD74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8041DD78: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8041DD7C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8041DD80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8041DD84: sw          $t6, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->r14;
    // 0x8041DD88: sb          $t7, 0x165($s3)
    MEM_B(0X165, ctx->r19) = ctx->r15;
    // 0x8041DD8C: sw          $zero, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = 0;
    // 0x8041DD90: sw          $zero, 0x138($s3)
    MEM_W(0X138, ctx->r19) = 0;
    // 0x8041DD94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041DD98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041DD9C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8041DDA0: jal         0x8041FE10
    // 0x8041DDA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8041FE10(rdram, ctx);
        goto after_2;
    // 0x8041DDA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8041DDA8: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(29, 0X554) << 16);
    // 0x8041DDAC: addiu       $t8, $t8, -0x244C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(29, 0X554));
    // 0x8041DDB0: sw          $t8, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r24;
    // 0x8041DDB4: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34DC) << 16);
    // 0x8041DDB8: lwc1        $f4, 0xB3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34DC));
    // 0x8041DDBC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34E0) << 16);
    // 0x8041DDC0: lwc1        $f16, 0x6C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x8041DDC4: swc1        $f4, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f4.u32l;
    // 0x8041DDC8: lwc1        $f6, 0xB40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34E0));
    // 0x8041DDCC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8041DDD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8041DDD4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8041DDD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041DDDC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8041DDE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041DDE4: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8041DDE8: swc1        $f8, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f8.u32l;
    // 0x8041DDEC: swc1        $f10, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f10.u32l;
    // 0x8041DDF0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8041DDF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041DDF8: lwc1        $f8, 0x70($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X70);
    // 0x8041DDFC: swc1        $f6, 0xEC($s3)
    MEM_W(0XEC, ctx->r19) = ctx->f6.u32l;
    // 0x8041DE00: lui         $s2, 0x8042
    ctx->r18 = S32(RELOC_HI16(29, 0X32E4) << 16);
    // 0x8041DE04: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8041DE08: lui         $s1, 0x8042
    ctx->r17 = S32(RELOC_HI16(29, 0X3290) << 16);
    // 0x8041DE0C: lui         $s4, 0x8042
    ctx->r20 = S32(RELOC_HI16(29, 0X3298) << 16);
    // 0x8041DE10: lw          $s0, 0x1F4($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X1F4);
    // 0x8041DE14: addiu       $s4, $s4, 0x8F8
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(29, 0X3298));
    // 0x8041DE18: addiu       $s1, $s1, 0x8F0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(29, 0X3290));
    // 0x8041DE1C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8041DE20: addiu       $s2, $s2, 0x944
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(29, 0X32E4));
    // 0x8041DE24: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8041DE28: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8041DE2C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8041DE30: sh          $t0, 0x13C($s3)
    MEM_H(0X13C, ctx->r19) = ctx->r8;
    // 0x8041DE34: sh          $t2, 0x13E($s3)
    MEM_H(0X13E, ctx->r19) = ctx->r10;
L_8041DE38:
    // 0x8041DE38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041DE3C: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x8041DE40: jal         0x8041FE5C
    // 0x8041DE44: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    func_8041FE5C(rdram, ctx);
        goto after_3;
    // 0x8041DE44: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x8041DE48: bne         $s0, $zero, L_8041DE60
    if (ctx->r16 != 0) {
        // 0x8041DE4C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8041DE60;
    }
    // 0x8041DE4C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8041DE50: jal         0x800445A4
    // 0x8041DE54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8041DE54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8041DE58: b           L_8041DE90
    // 0x8041DE5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8041DE90;
    // 0x8041DE5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8041DE60:
    // 0x8041DE60: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8041DE64: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8041DE68: bne         $s1, $s4, L_8041DE38
    if (ctx->r17 != ctx->r20) {
        // 0x8041DE6C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8041DE38;
    }
    // 0x8041DE6C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8041DE70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041DE74: jal         0x8041E430
    // 0x8041DE78: lw          $a1, 0x1F4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1F4);
    func_8041E430(rdram, ctx);
        goto after_5;
    // 0x8041DE78: lw          $a1, 0x1F4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1F4);
    after_5:
    // 0x8041DE7C: b           L_8041DE90
    // 0x8041DE80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8041DE90;
    // 0x8041DE80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8041DE84:
    // 0x8041DE84: jal         0x800445A4
    // 0x8041DE88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x8041DE88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x8041DE8C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8041DE90:
    // 0x8041DE90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041DE94: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8041DE98: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8041DE9C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8041DEA0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8041DEA4: jr          $ra
    // 0x8041DEA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8041DEA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8042DE88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042DE88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042DE8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042DE90: jal         0x8042DE2C
    // 0x8042DE94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042DE2C(rdram, ctx);
        goto after_0;
    // 0x8042DE94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042DE98: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8042DE9C: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x8042DEA0: lw          $a0, 0x168($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X168);
    // 0x8042DEA4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8042DEA8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x8042DEAC: jal         0x8005B1E4
    // 0x8042DEB0: lbu         $a1, 0x1($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X1);
    func_8005B1E4(rdram, ctx);
        goto after_1;
    // 0x8042DEB0: lbu         $a1, 0x1($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X1);
    after_1:
    // 0x8042DEB4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8042DEB8: lw          $t9, 0x1F4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1F4);
    // 0x8042DEBC: lw          $v0, 0xC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XC);
    // 0x8042DEC0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8042DEC4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8042DEC8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8042DECC: bgez        $v1, L_8042DEE0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8042DED0: andi        $t0, $v1, 0x3F
        ctx->r8 = ctx->r3 & 0X3F;
            goto L_8042DEE0;
    }
    // 0x8042DED0: andi        $t0, $v1, 0x3F
    ctx->r8 = ctx->r3 & 0X3F;
    // 0x8042DED4: beq         $t0, $zero, L_8042DEE0
    if (ctx->r8 == 0) {
        // 0x8042DED8: nop
    
            goto L_8042DEE0;
    }
    // 0x8042DED8: nop

    // 0x8042DEDC: addiu       $t0, $t0, -0x40
    ctx->r8 = ADD32(ctx->r8, -0X40);
L_8042DEE0:
    // 0x8042DEE0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8042DEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042DEE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042DEEC: jr          $ra
    // 0x8042DEF0: nop

    return;
    // 0x8042DEF0: nop

;}
RECOMP_FUNC void func_80027634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002763C: jal         0x80024748
    // 0x80027640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x80027640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027644: beq         $v0, $zero, L_80027688
    if (ctx->r2 == 0) {
        // 0x80027648: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80027688;
    }
    // 0x80027648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002764C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80027650: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x80027654: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80027658: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8002765C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80027660: addiu       $t0, $t0, 0x4748
    ctx->r8 = ADD32(ctx->r8, 0X4748);
    // 0x80027664: beq         $t7, $zero, L_80027680
    if (ctx->r15 == 0) {
        // 0x80027668: nop
    
            goto L_80027680;
    }
    // 0x80027668: nop

    // 0x8002766C: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
    // 0x80027670: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027674: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
    // 0x80027678: b           L_80027688
    // 0x8002767C: sw          $t0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r8;
        goto L_80027688;
    // 0x8002767C: sw          $t0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r8;
L_80027680:
    // 0x80027680: jal         0x8002761C
    // 0x80027684: nop

    func_8002761C(rdram, ctx);
        goto after_1;
    // 0x80027684: nop

    after_1:
L_80027688:
    // 0x80027688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002768C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027694: jr          $ra
    // 0x80027698: nop

    return;
    // 0x80027698: nop

;}
RECOMP_FUNC void func_8040AB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040AB88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040AB8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040AB90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040AB94: jal         0x8040BA98
    // 0x8040AB98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8040BA98(rdram, ctx);
        goto after_0;
    // 0x8040AB98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8040AB9C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8040ABA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040ABA4: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8040ABA8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8040ABAC: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x8040ABB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040ABB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040ABB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8040ABBC: jal         0x80045A34
    // 0x8040ABC0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8040ABC0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8040ABC4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8040ABC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040ABCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040ABD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8040ABD4: jal         0x8040BA40
    // 0x8040ABD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8040BA40(rdram, ctx);
        goto after_2;
    // 0x8040ABD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8040ABDC: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8040ABE0: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8040ABE4: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x8040ABE8: jal         0x8040AB70
    // 0x8040ABEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040AB70(rdram, ctx);
        goto after_3;
    // 0x8040ABEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8040ABF0: lui         $a1, 0x8041
    ctx->r5 = S32(RELOC_HI16(14, 0XF70) << 16);
    // 0x8040ABF4: lui         $a2, 0xBC23
    ctx->r6 = S32(0XBC23 << 16);
    // 0x8040ABF8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8040ABFC: addiu       $a1, $a1, -0x4530
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(14, 0XF70));
    // 0x8040AC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040AC04: jal         0x8040B314
    // 0x8040AC08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8040B314(rdram, ctx);
        goto after_4;
    // 0x8040AC08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8040AC0C: jal         0x8040BA98
    // 0x8040AC10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8040BA98(rdram, ctx);
        goto after_5;
    // 0x8040AC10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8040AC14: lui         $a1, 0x8041
    ctx->r5 = S32(RELOC_HI16(14, 0XF70) << 16);
    // 0x8040AC18: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8040AC1C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8040AC20: addiu       $a1, $a1, -0x4530
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(14, 0XF70));
    // 0x8040AC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040AC28: jal         0x8040B314
    // 0x8040AC2C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8040B314(rdram, ctx);
        goto after_6;
    // 0x8040AC2C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_6:
    // 0x8040AC30: jal         0x8040BA98
    // 0x8040AC34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8040BA98(rdram, ctx);
        goto after_7;
    // 0x8040AC34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x8040AC38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040AC3C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8040AC40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8040AC44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040AC48: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8040AC4C: jr          $ra
    // 0x8040AC50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8040AC50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806E4E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E4E84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806E4E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E4E8C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E4E90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806E4E94: jal         0x806E3DD0
    // 0x806E4E98: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_806E3DD0(rdram, ctx);
        goto after_0;
    // 0x806E4E98: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x806E4E9C: jal         0x806E3A3C
    // 0x806E4EA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_806E3A3C(rdram, ctx);
        goto after_1;
    // 0x806E4EA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x806E4EA4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x806E4EA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806E4EAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E4EB0: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x806E4EB4: addiu       $a3, $a0, 0xC4
    ctx->r7 = ADD32(ctx->r4, 0XC4);
    // 0x806E4EB8: bnel        $t8, $zero, L_806E4F0C
    if (ctx->r24 != 0) {
        // 0x806E4EBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E4F0C;
    }
    goto skip_0;
    // 0x806E4EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E4EC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E4EC4: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806E4EC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4ECC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806E4ED0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806E4ED4: nop

    // 0x806E4ED8: bc1fl       L_806E4EF0
    if (!c1cs) {
        // 0x806E4EDC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_806E4EF0;
    }
    goto skip_1;
    // 0x806E4EDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_1:
    // 0x806E4EE0: jal         0x806E511C
    // 0x806E4EE4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_806E511C(rdram, ctx);
        goto after_2;
    // 0x806E4EE4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x806E4EE8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x806E4EEC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_806E4EF0:
    // 0x806E4EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806E4EF4: jal         0x80048F84
    // 0x806E4EF8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x806E4EF8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_3:
    // 0x806E4EFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806E4F00: jal         0x80048F84
    // 0x806E4F04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x806E4F04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x806E4F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E4F0C:
    // 0x806E4F0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806E4F10: jr          $ra
    // 0x806E4F14: nop

    return;
    // 0x806E4F14: nop

;}
RECOMP_FUNC void func_8003510C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003510C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035110: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80035114: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x80035118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003511C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80035120: jal         0x8006593C
    // 0x80035124: lh          $a0, 0xADE($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XADE);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80035124: lh          $a0, 0xADE($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XADE);
    after_0:
    // 0x80035128: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003512C: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80035130: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80035134: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80035138: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003513C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80035140: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x80035144: blez        $a0, L_8003518C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80035148: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_8003518C;
    }
    // 0x80035148: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x8003514C: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x80035150: beq         $at, $zero, L_8003518C
    if (ctx->r1 == 0) {
        // 0x80035154: nop
    
            goto L_8003518C;
    }
    // 0x80035154: nop

    // 0x80035158: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003515C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80035160: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80035164: sw          $t8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r24;
    // 0x80035168: sltiu       $at, $t0, 0x4
    ctx->r1 = ctx->r8 < 0X4 ? 1 : 0;
    // 0x8003516C: beq         $at, $zero, L_80035184
    if (ctx->r1 == 0) {
        // 0x80035170: sw          $t0, 0x40($v1)
        MEM_W(0X40, ctx->r3) = ctx->r8;
            goto L_80035184;
    }
    // 0x80035170: sw          $t0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r8;
    // 0x80035174: lbu         $t2, 0xAFC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XAFC);
    // 0x80035178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003517C: b           L_800351AC
    // 0x80035180: sb          $t2, 0xADC($a1)
    MEM_B(0XADC, ctx->r5) = ctx->r10;
        goto L_800351AC;
    // 0x80035180: sb          $t2, 0xADC($a1)
    MEM_B(0XADC, ctx->r5) = ctx->r10;
L_80035184:
    // 0x80035184: b           L_800351AC
    // 0x80035188: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800351AC;
    // 0x80035188: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8003518C:
    // 0x8003518C: bgtzl       $a0, L_800351A8
    if (SIGNED(ctx->r4) > 0) {
        // 0x80035190: sw          $zero, 0x40($v1)
        MEM_W(0X40, ctx->r3) = 0;
            goto L_800351A8;
    }
    goto skip_0;
    // 0x80035190: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    skip_0:
    // 0x80035194: lbu         $t3, 0xAFC($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XAFC);
    // 0x80035198: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003519C: b           L_800351AC
    // 0x800351A0: sb          $t3, 0xADC($a1)
    MEM_B(0XADC, ctx->r5) = ctx->r11;
        goto L_800351AC;
    // 0x800351A0: sb          $t3, 0xADC($a1)
    MEM_B(0XADC, ctx->r5) = ctx->r11;
    // 0x800351A4: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
L_800351A8:
    // 0x800351A8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800351AC:
    // 0x800351AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800351B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800351B4: jr          $ra
    // 0x800351B8: nop

    return;
    // 0x800351B8: nop

;}
RECOMP_FUNC void func_80424F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424F94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80424F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80424F9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80424FA0: jal         0x804233F4
    // 0x80424FA4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_804233F4(rdram, ctx);
        goto after_0;
    // 0x80424FA4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80424FA8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80424FAC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80424FB0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80424FB4: addiu       $t6, $v0, 0x90
    ctx->r14 = ADD32(ctx->r2, 0X90);
    // 0x80424FB8: addiu       $t7, $v0, 0x9C
    ctx->r15 = ADD32(ctx->r2, 0X9C);
    // 0x80424FBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80424FC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80424FC4: addiu       $a1, $v0, 0xA0
    ctx->r5 = ADD32(ctx->r2, 0XA0);
    // 0x80424FC8: jal         0x80424690
    // 0x80424FCC: addiu       $a3, $v0, 0x28
    ctx->r7 = ADD32(ctx->r2, 0X28);
    func_80424690(rdram, ctx);
        goto after_1;
    // 0x80424FCC: addiu       $a3, $v0, 0x28
    ctx->r7 = ADD32(ctx->r2, 0X28);
    after_1:
    // 0x80424FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80424FD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80424FD8: jr          $ra
    // 0x80424FDC: nop

    return;
    // 0x80424FDC: nop

;}
