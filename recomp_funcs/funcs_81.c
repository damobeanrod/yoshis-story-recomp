#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8041FE5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FE5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8041FE60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041FE64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8041FE68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8041FE6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8041FE70: jal         0x80047090
    // 0x8041FE74: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8041FE74: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x8041FE78: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8041FE7C: beq         $v0, $at, L_8041FEC0
    if (ctx->r2 == ctx->r1) {
        // 0x8041FE80: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8041FEC0;
    }
    // 0x8041FE80: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8041FE84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041FE88: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8041FE8C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8041FE90: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8041FE94: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8041FE98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8041FE9C: jal         0x8004613C
    // 0x8041FEA0: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8041FEA0: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    after_1:
    // 0x8041FEA4: beq         $v0, $zero, L_8041FEC0
    if (ctx->r2 == 0) {
        // 0x8041FEA8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8041FEC0;
    }
    // 0x8041FEA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8041FEAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8041FEB0: jal         0x80047F9C
    // 0x8041FEB4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8041FEB4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8041FEB8: b           L_8041FEC4
    // 0x8041FEBC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8041FEC4;
    // 0x8041FEBC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8041FEC0:
    // 0x8041FEC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8041FEC4:
    // 0x8041FEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041FEC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8041FECC: jr          $ra
    // 0x8041FED0: nop

    return;
    // 0x8041FED0: nop

;}
RECOMP_FUNC void func_8043AEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AEC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043AEC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043AECC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8043AED0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8043AED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043AED8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043AEDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043AEE0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8043AEE4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043AEE8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8043AEEC: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(83, 0X1184) << 16);
    // 0x8043AEF0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8043AEF4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8043AEF8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8043AEFC: lw          $t2, -0x481C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(83, 0X1184));
    // 0x8043AF00: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8043AF04: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8043AF08: jal         0x8043A7D4
    // 0x8043AF0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043A7D4(rdram, ctx);
        goto after_0;
    // 0x8043AF0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043AF10: jal         0x8043A830
    // 0x8043AF14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043A830(rdram, ctx);
        goto after_1;
    // 0x8043AF14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043AF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043AF1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043AF20: jr          $ra
    // 0x8043AF24: nop

    return;
    // 0x8043AF24: nop

;}
RECOMP_FUNC void func_805A7414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A7418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A741C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x805A7420: beql        $a1, $zero, L_805A7434
    if (ctx->r5 == 0) {
        // 0x805A7424: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A7434;
    }
    goto skip_0;
    // 0x805A7424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A7428: jal         0x800568E0
    // 0x805A742C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x805A742C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x805A7430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A7434:
    // 0x805A7434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A7438: jr          $ra
    // 0x805A743C: nop

    return;
    // 0x805A743C: nop

;}
RECOMP_FUNC void func_8006DC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006DC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DC40: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x8006DC44: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006DC48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006DC4C: bne         $a2, $at, L_8006DC6C
    if (ctx->r6 != ctx->r1) {
        // 0x8006DC50: addiu       $v0, $a3, 0x4
        ctx->r2 = ADD32(ctx->r7, 0X4);
            goto L_8006DC6C;
    }
    // 0x8006DC50: addiu       $v0, $a3, 0x4
    ctx->r2 = ADD32(ctx->r7, 0X4);
    // 0x8006DC54: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006DC58: addiu       $v0, $a0, 0x11C
    ctx->r2 = ADD32(ctx->r4, 0X11C);
    // 0x8006DC5C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8006DC60: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8006DC64: b           L_8006DD24
    // 0x8006DC68: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
        goto L_8006DD24;
    // 0x8006DC68: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_8006DC6C:
    // 0x8006DC6C: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x8006DC70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8006DC74: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8006DC78: jal         0x8006DAF4
    // 0x8006DC7C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8006DAF4(rdram, ctx);
        goto after_0;
    // 0x8006DC7C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006DC80: bne         $v0, $zero, L_8006DCA0
    if (ctx->r2 != 0) {
        // 0x8006DC84: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006DCA0;
    }
    // 0x8006DC84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8006DC88: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006DC8C: addiu       $a0, $a0, 0x10F4
    ctx->r4 = ADD32(ctx->r4, 0X10F4);
    // 0x8006DC90: addiu       $a1, $zero, 0x23E
    ctx->r5 = ADD32(0, 0X23E);
    // 0x8006DC94: jal         0x80071380
    // 0x8006DC98: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006DC98: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8006DC9C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8006DCA0:
    // 0x8006DCA0: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8006DCA4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006DCA8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8006DCAC: nop

    // 0x8006DCB0: bgez        $v1, L_8006DCBC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006DCB4: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_8006DCBC;
    }
    // 0x8006DCB4: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x8006DCB8: addiu       $at, $v1, 0xFF
    ctx->r1 = ADD32(ctx->r3, 0XFF);
L_8006DCBC:
    // 0x8006DCBC: sra         $v1, $at, 8
    ctx->r3 = S32(SIGNED(ctx->r1) >> 8);
    // 0x8006DCC0: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8006DCC4: beql        $v1, $zero, L_8006DCD4
    if (ctx->r3 == 0) {
        // 0x8006DCC8: mtc1        $v1, $f16
        ctx->f16.u32l = ctx->r3;
            goto L_8006DCD4;
    }
    goto skip_0;
    // 0x8006DCC8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    skip_0:
    // 0x8006DCCC: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x8006DCD0: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
L_8006DCD4:
    // 0x8006DCD4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8006DCD8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006DCDC: addiu       $v0, $v0, 0x11C
    ctx->r2 = ADD32(ctx->r2, 0X11C);
    // 0x8006DCE0: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8006DCE4: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8006DCE8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006DCEC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8006DCF0: nop

    // 0x8006DCF4: bgez        $a0, L_8006DD00
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006DCF8: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_8006DD00;
    }
    // 0x8006DCF8: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x8006DCFC: addiu       $at, $a0, 0xFF
    ctx->r1 = ADD32(ctx->r4, 0XFF);
L_8006DD00:
    // 0x8006DD00: sra         $a0, $at, 8
    ctx->r4 = S32(SIGNED(ctx->r1) >> 8);
    // 0x8006DD04: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x8006DD08: beql        $a0, $zero, L_8006DD18
    if (ctx->r4 == 0) {
        // 0x8006DD0C: mtc1        $a0, $f8
        ctx->f8.u32l = ctx->r4;
            goto L_8006DD18;
    }
    goto skip_1;
    // 0x8006DD0C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    skip_1:
    // 0x8006DD10: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006DD14: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
L_8006DD18:
    // 0x8006DD18: nop

    // 0x8006DD1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006DD20: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
L_8006DD24:
    // 0x8006DD24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DD28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006DD2C: jr          $ra
    // 0x8006DD30: nop

    return;
    // 0x8006DD30: nop

;}
RECOMP_FUNC void func_80431028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80431028: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x8043102C: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X3A6C) << 16);
    // 0x80431030: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80431034: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80431038: addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    // 0x8043103C: addiu       $t6, $t6, 0x1B4C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X3A6C));
    // 0x80431040: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80431044: addiu       $s7, $sp, 0x50
    ctx->r23 = ADD32(ctx->r29, 0X50);
    // 0x80431048: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8043104C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80431050: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80431054: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80431058: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8043105C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80431060: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80431064: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80431068: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x8043106C: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80431070:
    // 0x80431070: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80431074: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80431078: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8043107C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80431080: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80431084: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80431088: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8043108C: bne         $t6, $t0, L_80431070
    if (ctx->r14 != ctx->r8) {
        // 0x80431090: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80431070;
    }
    // 0x80431090: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80431094: lui         $t1, 0x8043
    ctx->r9 = S32(RELOC_HI16(56, 0X3A9C) << 16);
    // 0x80431098: addiu       $t1, $t1, 0x1B7C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(56, 0X3A9C));
    // 0x8043109C: addiu       $t5, $t1, 0x90
    ctx->r13 = ADD32(ctx->r9, 0X90);
    // 0x804310A0: or          $t4, $s7, $zero
    ctx->r12 = ctx->r23 | 0;
L_804310A4:
    // 0x804310A4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x804310A8: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x804310AC: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x804310B0: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x804310B4: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x804310B8: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x804310BC: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x804310C0: bne         $t1, $t5, L_804310A4
    if (ctx->r9 != ctx->r13) {
        // 0x804310C4: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_804310A4;
    }
    // 0x804310C4: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x804310C8: lw          $t7, 0x16C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X16C);
    // 0x804310CC: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x804310D0: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x804310D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804310D8: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(56, 0X3150) << 16);
    // 0x804310DC: sw          $t0, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r8;
    // 0x804310E0: sb          $t6, 0x165($s4)
    MEM_B(0X165, ctx->r20) = ctx->r14;
    // 0x804310E4: addiu       $t9, $t9, 0x1230
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(56, 0X3150));
    // 0x804310E8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x804310EC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x804310F0: sw          $zero, 0x1E0($s4)
    MEM_W(0X1E0, ctx->r20) = 0;
    // 0x804310F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x804310F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804310FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80431100: jal         0x804311BC
    // 0x80431104: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804311BC(rdram, ctx);
        goto after_0;
    // 0x80431104: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80431108: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8043110C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80431110: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80431114: lui         $s6, 0x408E
    ctx->r22 = S32(0X408E << 16);
    // 0x80431118: addiu       $s5, $zero, 0x3FF
    ctx->r21 = ADD32(0, 0X3FF);
    // 0x8043111C: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_80431120:
    // 0x80431120: jal         0x80047090
    // 0x80431124: addiu       $a0, $zero, 0x408E
    ctx->r4 = ADD32(0, 0X408E);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x80431124: addiu       $a0, $zero, 0x408E
    ctx->r4 = ADD32(0, 0X408E);
    after_1:
    // 0x80431128: beq         $s5, $v0, L_80431180
    if (ctx->r21 == ctx->r2) {
        // 0x8043112C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80431180;
    }
    // 0x8043112C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80431130: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80431134: or          $a0, $v1, $s6
    ctx->r4 = ctx->r3 | ctx->r22;
    // 0x80431138: mflo        $t8
    ctx->r24 = lo;
    // 0x8043113C: addu        $v0, $s7, $t8
    ctx->r2 = ADD32(ctx->r23, ctx->r24);
    // 0x80431140: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80431144: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80431148: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8043114C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80431150: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80431154: jal         0x8004613C
    // 0x80431158: nop

    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x80431158: nop

    after_2:
    // 0x8043115C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80431160: jal         0x80430F44
    // 0x80431164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80430F44(rdram, ctx);
        goto after_3;
    // 0x80431164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80431168: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8043116C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80431170: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80431174: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80431178: jal         0x80047F9C
    // 0x8043117C: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x8043117C: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    after_4:
L_80431180:
    // 0x80431180: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80431184: bne         $s1, $s3, L_80431120
    if (ctx->r17 != ctx->r19) {
        // 0x80431188: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80431120;
    }
    // 0x80431188: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8043118C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80431190: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80431194: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80431198: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8043119C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x804311A0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x804311A4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x804311A8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x804311AC: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x804311B0: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x804311B4: jr          $ra
    // 0x804311B8: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x804311B8: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_8000BD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD90: sw          $a0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r4;
    // 0x8000BD94: sw          $a0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r4;
    // 0x8000BD98: jr          $ra
    // 0x8000BD9C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    return;
    // 0x8000BD9C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800653CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800653D0: jr          $ra
    // 0x800653D4: sw          $a0, 0x65C8($at)
    MEM_W(0X65C8, ctx->r1) = ctx->r4;
    return;
    // 0x800653D4: sw          $a0, 0x65C8($at)
    MEM_W(0X65C8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80026C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026C4C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80026C50: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80026C54: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80026C58: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80026C5C: lw          $t6, 0x9C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C);
    // 0x80026C60: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x80026C64: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80026C68: sw          $v1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r3;
    // 0x80026C6C: lw          $t7, 0xA0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XA0);
    // 0x80026C70: addiu       $t9, $t9, 0x6BF8
    ctx->r25 = ADD32(ctx->r25, 0X6BF8);
    // 0x80026C74: sw          $v1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r3;
    // 0x80026C78: sb          $t8, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r24;
    // 0x80026C7C: jr          $ra
    // 0x80026C80: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    return;
    // 0x80026C80: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80463260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80463264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80463268: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8046326C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80463270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80463274: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80463278: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8046327C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80463280: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80463284: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80463288: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(122, 0X394C) << 16);
    // 0x8046328C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80463290: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80463294: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80463298: lw          $t2, 0x3EDC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(122, 0X394C));
    // 0x8046329C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804632A0: jal         0x8046292C
    // 0x804632A4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8046292C(rdram, ctx);
        goto after_0;
    // 0x804632A4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804632A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804632AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804632B0: jr          $ra
    // 0x804632B4: nop

    return;
    // 0x804632B4: nop

;}
RECOMP_FUNC void func_804B68C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B68C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B68C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B68C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B68CC: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804B68D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B68D4: jal         0x800692D4
    // 0x804B68D8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x804B68D8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x804B68DC: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x804B68E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804B68E4: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    // 0x804B68E8: bne         $t7, $at, L_804B6910
    if (ctx->r15 != ctx->r1) {
        // 0x804B68EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804B6910;
    }
    // 0x804B68EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B68F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B68F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x804B68F8: jal         0x804B6FF0
    // 0x804B68FC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B68FC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x804B6900: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804B6904: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x804B6908: jal         0x8004A73C
    // 0x804B690C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8004A73C(rdram, ctx);
        goto after_2;
    // 0x804B690C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
L_804B6910:
    // 0x804B6910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804B6914: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B6918: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B691C: jr          $ra
    // 0x804B6920: nop

    return;
    // 0x804B6920: nop

;}
RECOMP_FUNC void func_80787414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80787414: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80787418: lw          $v1, 0x43E4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X43E4);
    // 0x8078741C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80787420: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80787424: sw          $t6, 0x43E4($v0)
    MEM_W(0X43E4, ctx->r2) = ctx->r14;
    // 0x80787428: bne         $at, $zero, L_80787434
    if (ctx->r1 != 0) {
        // 0x8078742C: sw          $v1, 0x43E0($v0)
        MEM_W(0X43E0, ctx->r2) = ctx->r3;
            goto L_80787434;
    }
    // 0x8078742C: sw          $v1, 0x43E0($v0)
    MEM_W(0X43E0, ctx->r2) = ctx->r3;
    // 0x80787430: sw          $zero, 0x43E4($v0)
    MEM_W(0X43E4, ctx->r2) = 0;
L_80787434:
    // 0x80787434: jr          $ra
    // 0x80787438: nop

    return;
    // 0x80787438: nop

;}
RECOMP_FUNC void func_807870C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807870C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807870C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807870C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807870CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807870D0: lw          $v1, 0x52E0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X52E0);
    // 0x807870D4: lw          $t8, 0x52EC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X52EC);
    // 0x807870D8: lw          $t6, 0x52E8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X52E8);
    // 0x807870DC: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x807870E0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x807870E4: lbu         $t3, 0x0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X0);
    // 0x807870E8: lbu         $t5, 0x1($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1);
    // 0x807870EC: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x807870F0: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x807870F4: lw          $a2, 0x52E4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X52E4);
    // 0x807870F8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x807870FC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80787100: addu        $a3, $t4, $a2
    ctx->r7 = ADD32(ctx->r12, ctx->r6);
    // 0x80787104: beq         $t2, $zero, L_8078712C
    if (ctx->r10 == 0) {
        // 0x80787108: addu        $t0, $t6, $a2
        ctx->r8 = ADD32(ctx->r14, ctx->r6);
            goto L_8078712C;
    }
    // 0x80787108: addu        $t0, $t6, $a2
    ctx->r8 = ADD32(ctx->r14, ctx->r6);
    // 0x8078710C: beq         $t2, $at, L_807871E8
    if (ctx->r10 == ctx->r1) {
        // 0x80787110: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_807871E8;
    }
    // 0x80787110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80787114: beq         $t2, $at, L_807872A4
    if (ctx->r10 == ctx->r1) {
        // 0x80787118: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_807872A4;
    }
    // 0x80787118: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8078711C: beql        $t2, $at, L_8078735C
    if (ctx->r10 == ctx->r1) {
        // 0x80787120: lhu         $t4, 0x52F0($v0)
        ctx->r12 = MEM_HU(ctx->r2, 0X52F0);
            goto L_8078735C;
    }
    goto skip_0;
    // 0x80787120: lhu         $t4, 0x52F0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X52F0);
    skip_0:
    // 0x80787124: b           L_80787408
    // 0x80787128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80787408;
    // 0x80787128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078712C:
    // 0x8078712C: lhu         $t7, 0x52F0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X52F0);
    // 0x80787130: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F04) << 16);
    // 0x80787134: lwc1        $f0, -0x66BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F04));
    // 0x80787138: andi        $t8, $t7, 0xFFFD
    ctx->r24 = ctx->r15 & 0XFFFD;
    // 0x8078713C: sh          $t8, 0x52F0($v0)
    MEM_H(0X52F0, ctx->r2) = ctx->r24;
    // 0x80787140: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80787144: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F08) << 16);
    // 0x80787148: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x8078714C: lhu         $t9, 0x52F0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X52F0);
    // 0x80787150: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80787154: andi        $t3, $t9, 0xFFFE
    ctx->r11 = ctx->r25 & 0XFFFE;
    // 0x80787158: sh          $t3, 0x52F0($v1)
    MEM_H(0X52F0, ctx->r3) = ctx->r11;
    // 0x8078715C: lwc1        $f4, -0x66B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F08));
    // 0x80787160: sw          $t4, 0x52D4($v0)
    MEM_W(0X52D4, ctx->r2) = ctx->r12;
    // 0x80787164: swc1        $f4, 0x52D0($v0)
    MEM_W(0X52D0, ctx->r2) = ctx->f4.u32l;
    // 0x80787168: lh          $t5, 0x2($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X2);
    // 0x8078716C: lh          $t6, 0x2($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X2);
    // 0x80787170: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80787174: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80787178: nop

    // 0x8078717C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80787180: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80787184: swc1        $f10, 0x52C8($v0)
    MEM_W(0X52C8, ctx->r2) = ctx->f10.u32l;
    // 0x80787188: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x8078718C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80787190: nop

    // 0x80787194: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80787198: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8078719C: swc1        $f4, 0x52D8($v0)
    MEM_W(0X52D8, ctx->r2) = ctx->f4.u32l;
    // 0x807871A0: lh          $t3, 0x0($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X0);
    // 0x807871A4: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x807871A8: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x807871AC: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x807871B0: nop

    // 0x807871B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807871B8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807871BC: swc1        $f10, 0x52DC($v0)
    MEM_W(0X52DC, ctx->r2) = ctx->f10.u32l;
    // 0x807871C0: lh          $t5, 0x2($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X2);
    // 0x807871C4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x807871C8: nop

    // 0x807871CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807871D0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x807871D4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x807871D8: jal         0x807892D4
    // 0x807871DC: nop

    func_807892D4(rdram, ctx);
        goto after_0;
    // 0x807871DC: nop

    after_0:
    // 0x807871E0: b           L_80787408
    // 0x807871E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80787408;
    // 0x807871E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807871E8:
    // 0x807871E8: lhu         $t6, 0x52F0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X52F0);
    // 0x807871EC: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F0C) << 16);
    // 0x807871F0: lwc1        $f0, -0x66B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F0C));
    // 0x807871F4: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x807871F8: sh          $t7, 0x52F0($v0)
    MEM_H(0X52F0, ctx->r2) = ctx->r15;
    // 0x807871FC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80787200: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F10) << 16);
    // 0x80787204: addiu       $t3, $zero, -0x2
    ctx->r11 = ADD32(0, -0X2);
    // 0x80787208: lhu         $t8, 0x52F0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X52F0);
    // 0x8078720C: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x80787210: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80787214: sh          $t9, 0x52F0($v1)
    MEM_H(0X52F0, ctx->r3) = ctx->r25;
    // 0x80787218: lwc1        $f6, -0x66B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F10));
    // 0x8078721C: sw          $t3, 0x52D4($v0)
    MEM_W(0X52D4, ctx->r2) = ctx->r11;
    // 0x80787220: swc1        $f6, 0x52D0($v0)
    MEM_W(0X52D0, ctx->r2) = ctx->f6.u32l;
    // 0x80787224: lh          $t5, 0x2($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X2);
    // 0x80787228: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x8078722C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80787230: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80787234: nop

    // 0x80787238: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8078723C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80787240: swc1        $f16, 0x52C8($v0)
    MEM_W(0X52C8, ctx->r2) = ctx->f16.u32l;
    // 0x80787244: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x80787248: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8078724C: nop

    // 0x80787250: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80787254: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80787258: swc1        $f6, 0x52D8($v0)
    MEM_W(0X52D8, ctx->r2) = ctx->f6.u32l;
    // 0x8078725C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80787260: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x80787264: subu        $t3, $t8, $t9
    ctx->r11 = SUB32(ctx->r24, ctx->r25);
    // 0x80787268: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8078726C: nop

    // 0x80787270: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80787274: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80787278: swc1        $f16, 0x52DC($v0)
    MEM_W(0X52DC, ctx->r2) = ctx->f16.u32l;
    // 0x8078727C: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x80787280: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80787284: nop

    // 0x80787288: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8078728C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80787290: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80787294: jal         0x807892D4
    // 0x80787298: nop

    func_807892D4(rdram, ctx);
        goto after_1;
    // 0x80787298: nop

    after_1:
    // 0x8078729C: b           L_80787408
    // 0x807872A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80787408;
    // 0x807872A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807872A4:
    // 0x807872A4: lhu         $t5, 0x52F0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X52F0);
    // 0x807872A8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F14) << 16);
    // 0x807872AC: lwc1        $f0, -0x66AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F14));
    // 0x807872B0: andi        $t6, $t5, 0xFFFD
    ctx->r14 = ctx->r13 & 0XFFFD;
    // 0x807872B4: sh          $t6, 0x52F0($v0)
    MEM_H(0X52F0, ctx->r2) = ctx->r14;
    // 0x807872B8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807872BC: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F18) << 16);
    // 0x807872C0: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x807872C4: lhu         $t7, 0x52F0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X52F0);
    // 0x807872C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x807872CC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x807872D0: sh          $t8, 0x52F0($v1)
    MEM_H(0X52F0, ctx->r3) = ctx->r24;
    // 0x807872D4: lwc1        $f8, -0x66A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F18));
    // 0x807872D8: sw          $t9, 0x52D4($v0)
    MEM_W(0X52D4, ctx->r2) = ctx->r25;
    // 0x807872DC: swc1        $f8, 0x52D0($v0)
    MEM_W(0X52D0, ctx->r2) = ctx->f8.u32l;
    // 0x807872E0: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x807872E4: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x807872E8: nop

    // 0x807872EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807872F0: swc1        $f16, 0x52D8($v0)
    MEM_W(0X52D8, ctx->r2) = ctx->f16.u32l;
    // 0x807872F4: lh          $t5, 0x2($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X2);
    // 0x807872F8: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x807872FC: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80787300: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80787304: nop

    // 0x80787308: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8078730C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80787310: swc1        $f6, 0x52DC($v0)
    MEM_W(0X52DC, ctx->r2) = ctx->f6.u32l;
    // 0x80787314: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x80787318: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8078731C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80787320: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80787324: nop

    // 0x80787328: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8078732C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80787330: swc1        $f16, 0x52C8($v0)
    MEM_W(0X52C8, ctx->r2) = ctx->f16.u32l;
    // 0x80787334: lh          $t3, 0x0($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X0);
    // 0x80787338: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8078733C: nop

    // 0x80787340: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80787344: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80787348: jal         0x80789190
    // 0x8078734C: nop

    func_80789190(rdram, ctx);
        goto after_2;
    // 0x8078734C: nop

    after_2:
    // 0x80787350: b           L_80787408
    // 0x80787354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80787408;
    // 0x80787354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80787358: lhu         $t4, 0x52F0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X52F0);
L_8078735C:
    // 0x8078735C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F1C) << 16);
    // 0x80787360: lwc1        $f0, -0x66A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F1C));
    // 0x80787364: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80787368: sh          $t5, 0x52F0($v0)
    MEM_H(0X52F0, ctx->r2) = ctx->r13;
    // 0x8078736C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80787370: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F20) << 16);
    // 0x80787374: addiu       $t8, $zero, -0x2
    ctx->r24 = ADD32(0, -0X2);
    // 0x80787378: lhu         $t6, 0x52F0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X52F0);
    // 0x8078737C: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x80787380: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80787384: sh          $t7, 0x52F0($v1)
    MEM_H(0X52F0, ctx->r3) = ctx->r15;
    // 0x80787388: lwc1        $f4, -0x66A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F20));
    // 0x8078738C: sw          $t8, 0x52D4($v0)
    MEM_W(0X52D4, ctx->r2) = ctx->r24;
    // 0x80787390: swc1        $f4, 0x52D0($v0)
    MEM_W(0X52D0, ctx->r2) = ctx->f4.u32l;
    // 0x80787394: lh          $t9, 0x2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2);
    // 0x80787398: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8078739C: nop

    // 0x807873A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807873A4: swc1        $f8, 0x52D8($v0)
    MEM_W(0X52D8, ctx->r2) = ctx->f8.u32l;
    // 0x807873A8: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x807873AC: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x807873B0: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x807873B4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x807873B8: nop

    // 0x807873BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807873C0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807873C4: swc1        $f18, 0x52DC($v0)
    MEM_W(0X52DC, ctx->r2) = ctx->f18.u32l;
    // 0x807873C8: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x807873CC: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x807873D0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x807873D4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x807873D8: nop

    // 0x807873DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807873E0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x807873E4: swc1        $f8, 0x52C8($v0)
    MEM_W(0X52C8, ctx->r2) = ctx->f8.u32l;
    // 0x807873E8: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x807873EC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x807873F0: nop

    // 0x807873F4: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807873F8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x807873FC: jal         0x80789190
    // 0x80787400: nop

    func_80789190(rdram, ctx);
        goto after_3;
    // 0x80787400: nop

    after_3:
    // 0x80787404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80787408:
    // 0x80787408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078740C: jr          $ra
    // 0x80787410: nop

    return;
    // 0x80787410: nop

;}
RECOMP_FUNC void func_80558AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558AE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80558AE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558AE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558AEC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558AF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80558AF4: jal         0x8004700C
    // 0x80558AF8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80558AF8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80558AFC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80558B00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80558B04: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80558B08: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80558B0C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80558B10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558B14: jal         0x80048F84
    // 0x80558B18: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80558B18: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    after_1:
    // 0x80558B1C: jal         0x805580E8
    // 0x80558B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_2;
    // 0x80558B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80558B24: jal         0x805582E0
    // 0x80558B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_3;
    // 0x80558B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80558B2C: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x80558B30: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80558B34: slti        $at, $t9, 0x42
    ctx->r1 = SIGNED(ctx->r25) < 0X42 ? 1 : 0;
    // 0x80558B38: bne         $at, $zero, L_80558B74
    if (ctx->r1 != 0) {
        // 0x80558B3C: sw          $t9, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r25;
            goto L_80558B74;
    }
    // 0x80558B3C: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x80558B40: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    // 0x80558B44: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80558B48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80558B4C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80558B50: sw          $t2, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r10;
    // 0x80558B54: sb          $t3, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = ctx->r11;
    // 0x80558B58: jal         0x8002FE38
    // 0x80558B5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002FE38(rdram, ctx);
        goto after_4;
    // 0x80558B5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80558B60: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x80558B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558B6C: jal         0x80559928
    // 0x80558B70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80559928(rdram, ctx);
        goto after_5;
    // 0x80558B70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_80558B74:
    // 0x80558B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80558B78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558B7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80558B80: jr          $ra
    // 0x80558B84: nop

    return;
    // 0x80558B84: nop

;}
RECOMP_FUNC void func_804EF078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF07C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF080: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804EF084: jal         0x80065954
    // 0x804EF088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x804EF088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EF08C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x804EF090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804EF094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EF098: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(267, 0X1188) << 16);
    // 0x804EF09C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804EF0A0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804EF0A4: bc1fl       L_804EF0C8
    if (!c1cs) {
        // 0x804EF0A8: lwc1        $f16, 0x28($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
            goto L_804EF0C8;
    }
    goto skip_0;
    // 0x804EF0A8: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    skip_0:
    // 0x804EF0AC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804EF0B0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804EF0B4: lwc1        $f8, 0x28($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X28);
    // 0x804EF0B8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804EF0BC: b           L_804EF0DC
    // 0x804EF0C0: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_804EF0DC;
    // 0x804EF0C0: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x804EF0C4: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
L_804EF0C8:
    // 0x804EF0C8: lwc1        $f18, -0xE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(267, 0X1188));
    // 0x804EF0CC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804EF0D0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804EF0D4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x804EF0D8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
L_804EF0DC:
    // 0x804EF0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF0E4: jr          $ra
    // 0x804EF0E8: nop

    return;
    // 0x804EF0E8: nop

;}
RECOMP_FUNC void func_80428080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80428084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80428088: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042808C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80428090: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80428094: jal         0x80066DE4
    // 0x80428098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80428098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8042809C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804280A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804280A4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804280A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804280AC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804280B0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804280B4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804280B8: add.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804280BC: sub.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x804280C0: swc1        $f12, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f12.u32l;
    // 0x804280C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804280C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804280CC: jr          $ra
    // 0x804280D0: nop

    return;
    // 0x804280D0: nop

;}
RECOMP_FUNC void func_806F00D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F00D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F00DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F00E0: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x806F00E4: lw          $t8, 0x134($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X134);
    // 0x806F00E8: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(676, 0X4C44) << 16);
    // 0x806F00EC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x806F00F0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806F00F4: lw          $t7, 0xB94($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(676, 0X4C44));
    // 0x806F00F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806F00FC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x806F0100: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F0104: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F0108: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x806F010C: bne         $v0, $at, L_806F0134
    if (ctx->r2 != ctx->r1) {
        // 0x806F0110: sw          $v1, 0x15C($a0)
        MEM_W(0X15C, ctx->r4) = ctx->r3;
            goto L_806F0134;
    }
    // 0x806F0110: sw          $v1, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r3;
    // 0x806F0114: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F0118: lui         $t3, 0x806F
    ctx->r11 = S32(RELOC_HI16(676, 0X4C04) << 16);
    // 0x806F011C: lh          $t1, 0x10($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10);
    // 0x806F0120: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x806F0124: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x806F0128: lh          $t3, 0xB54($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(676, 0X4C04));
    // 0x806F012C: b           L_806F0168
    // 0x806F0130: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806F0168;
    // 0x806F0130: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806F0134:
    // 0x806F0134: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x806F0138: beql        $v0, $zero, L_806F016C
    if (ctx->r2 == 0) {
        // 0x806F013C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F016C;
    }
    goto skip_0;
    // 0x806F013C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F0140: jalr        $v0
    // 0x806F0144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x806F0144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F0148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F014C: lw          $t4, 0x15C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X15C);
    // 0x806F0150: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x806F0154: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x806F0158: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x806F015C: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x806F0160: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x806F0164: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
L_806F0168:
    // 0x806F0168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F016C:
    // 0x806F016C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F0170: jr          $ra
    // 0x806F0174: nop

    return;
    // 0x806F0174: nop

;}
RECOMP_FUNC void func_8007C974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C974: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007C978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C97C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007C980: addiu       $a1, $a1, -0x1C28
    ctx->r5 = ADD32(ctx->r5, -0X1C28);
    // 0x8007C984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007C988: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x8007C98C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8007C990:
    // 0x8007C990: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8007C994: addiu       $a2, $a1, 0x38
    ctx->r6 = ADD32(ctx->r5, 0X38);
    // 0x8007C998: beql        $t6, $zero, L_8007C9D0
    if (ctx->r14 == 0) {
        // 0x8007C99C: lw          $t2, 0x38($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X38);
            goto L_8007C9D0;
    }
    goto skip_0;
    // 0x8007C99C: lw          $t2, 0x38($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X38);
    skip_0:
    // 0x8007C9A0: lhu         $t7, 0x4($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X4);
    // 0x8007C9A4: bnel        $a3, $t7, L_8007C9D0
    if (ctx->r7 != ctx->r15) {
        // 0x8007C9A8: lw          $t2, 0x38($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X38);
            goto L_8007C9D0;
    }
    goto skip_1;
    // 0x8007C9A8: lw          $t2, 0x38($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X38);
    skip_1:
    // 0x8007C9AC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8007C9B0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8007C9B4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8007C9B8: beql        $at, $zero, L_8007C9D0
    if (ctx->r1 == 0) {
        // 0x8007C9BC: lw          $t2, 0x38($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X38);
            goto L_8007C9D0;
    }
    goto skip_2;
    // 0x8007C9BC: lw          $t2, 0x38($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X38);
    skip_2:
    // 0x8007C9C0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8007C9C4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007C9C8: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    // 0x8007C9CC: lw          $t2, 0x38($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X38);
L_8007C9D0:
    // 0x8007C9D0: beql        $t2, $zero, L_8007CA08
    if (ctx->r10 == 0) {
        // 0x8007C9D4: lw          $t7, 0x70($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X70);
            goto L_8007CA08;
    }
    goto skip_3;
    // 0x8007C9D4: lw          $t7, 0x70($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X70);
    skip_3:
    // 0x8007C9D8: lhu         $t3, 0x4($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X4);
    // 0x8007C9DC: bnel        $a3, $t3, L_8007CA08
    if (ctx->r7 != ctx->r11) {
        // 0x8007C9E0: lw          $t7, 0x70($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X70);
            goto L_8007CA08;
    }
    goto skip_4;
    // 0x8007C9E0: lw          $t7, 0x70($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X70);
    skip_4:
    // 0x8007C9E4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8007C9E8: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8007C9EC: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007C9F0: beql        $at, $zero, L_8007CA08
    if (ctx->r1 == 0) {
        // 0x8007C9F4: lw          $t7, 0x70($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X70);
            goto L_8007CA08;
    }
    goto skip_5;
    // 0x8007C9F4: lw          $t7, 0x70($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X70);
    skip_5:
    // 0x8007C9F8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8007C9FC: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8007CA00: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x8007CA04: lw          $t7, 0x70($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X70);
L_8007CA08:
    // 0x8007CA08: addiu       $a2, $a1, 0x70
    ctx->r6 = ADD32(ctx->r5, 0X70);
    // 0x8007CA0C: beql        $t7, $zero, L_8007CA44
    if (ctx->r15 == 0) {
        // 0x8007CA10: lw          $t3, 0xA8($a1)
        ctx->r11 = MEM_W(ctx->r5, 0XA8);
            goto L_8007CA44;
    }
    goto skip_6;
    // 0x8007CA10: lw          $t3, 0xA8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XA8);
    skip_6:
    // 0x8007CA14: lhu         $t8, 0x4($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X4);
    // 0x8007CA18: bnel        $a3, $t8, L_8007CA44
    if (ctx->r7 != ctx->r24) {
        // 0x8007CA1C: lw          $t3, 0xA8($a1)
        ctx->r11 = MEM_W(ctx->r5, 0XA8);
            goto L_8007CA44;
    }
    goto skip_7;
    // 0x8007CA1C: lw          $t3, 0xA8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XA8);
    skip_7:
    // 0x8007CA20: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8007CA24: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8007CA28: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8007CA2C: beql        $at, $zero, L_8007CA44
    if (ctx->r1 == 0) {
        // 0x8007CA30: lw          $t3, 0xA8($a1)
        ctx->r11 = MEM_W(ctx->r5, 0XA8);
            goto L_8007CA44;
    }
    goto skip_8;
    // 0x8007CA30: lw          $t3, 0xA8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XA8);
    skip_8:
    // 0x8007CA34: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8007CA38: addiu       $v1, $a0, 0x2
    ctx->r3 = ADD32(ctx->r4, 0X2);
    // 0x8007CA3C: lw          $v0, 0x4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X4);
    // 0x8007CA40: lw          $t3, 0xA8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XA8);
L_8007CA44:
    // 0x8007CA44: addiu       $a2, $a1, 0xA8
    ctx->r6 = ADD32(ctx->r5, 0XA8);
    // 0x8007CA48: beql        $t3, $zero, L_8007CA80
    if (ctx->r11 == 0) {
        // 0x8007CA4C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8007CA80;
    }
    goto skip_9;
    // 0x8007CA4C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_9:
    // 0x8007CA50: lhu         $t4, 0x4($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X4);
    // 0x8007CA54: bnel        $a3, $t4, L_8007CA80
    if (ctx->r7 != ctx->r12) {
        // 0x8007CA58: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8007CA80;
    }
    goto skip_10;
    // 0x8007CA58: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_10:
    // 0x8007CA5C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8007CA60: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8007CA64: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CA68: beql        $at, $zero, L_8007CA80
    if (ctx->r1 == 0) {
        // 0x8007CA6C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8007CA80;
    }
    goto skip_11;
    // 0x8007CA6C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_11:
    // 0x8007CA70: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8007CA74: addiu       $v1, $a0, 0x3
    ctx->r3 = ADD32(ctx->r4, 0X3);
    // 0x8007CA78: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8007CA7C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8007CA80:
    // 0x8007CA80: bne         $a0, $t0, L_8007C990
    if (ctx->r4 != ctx->r8) {
        // 0x8007CA84: addiu       $a1, $a1, 0xE0
        ctx->r5 = ADD32(ctx->r5, 0XE0);
            goto L_8007C990;
    }
    // 0x8007CA84: addiu       $a1, $a1, 0xE0
    ctx->r5 = ADD32(ctx->r5, 0XE0);
    // 0x8007CA88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007CA8C: jr          $ra
    // 0x8007CA90: nop

    return;
    // 0x8007CA90: nop

;}
RECOMP_FUNC void func_80467EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467EB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80467EB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80467EB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80467EBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467EC0: lh          $t7, 0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X1A);
    // 0x80467EC4: lh          $t8, 0x18($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X18);
    // 0x80467EC8: lw          $t0, 0x1FA0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1FA0);
    // 0x80467ECC: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80467ED0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467ED4: addiu       $t2, $v0, 0x2C70
    ctx->r10 = ADD32(ctx->r2, 0X2C70);
    // 0x80467ED8: addiu       $t3, $v0, 0x2CF0
    ctx->r11 = ADD32(ctx->r2, 0X2CF0);
    // 0x80467EDC: addiu       $t4, $v0, 0x18
    ctx->r12 = ADD32(ctx->r2, 0X18);
    // 0x80467EE0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80467EE4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80467EE8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80467EEC: lh          $t5, 0x14($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X14);
    // 0x80467EF0: addiu       $a2, $v0, 0x238E
    ctx->r6 = ADD32(ctx->r2, 0X238E);
    // 0x80467EF4: addiu       $a3, $v0, 0x238C
    ctx->r7 = ADD32(ctx->r2, 0X238C);
    // 0x80467EF8: mflo        $t9
    ctx->r25 = lo;
    // 0x80467EFC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80467F00: nop

    // 0x80467F04: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467F08: mflo        $t1
    ctx->r9 = lo;
    // 0x80467F0C: addu        $a1, $t1, $v0
    ctx->r5 = ADD32(ctx->r9, ctx->r2);
    // 0x80467F10: jal         0x80055E10
    // 0x80467F14: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_80055E10(rdram, ctx);
        goto after_0;
    // 0x80467F14: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x80467F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80467F1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80467F20: jr          $ra
    // 0x80467F24: nop

    return;
    // 0x80467F24: nop

;}
RECOMP_FUNC void func_80422294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80422298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042229C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804222A0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x804222A4: jal         0x80067878
    // 0x804222A8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x804222A8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_0:
    // 0x804222AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804222B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804222B4: jr          $ra
    // 0x804222B8: nop

    return;
    // 0x804222B8: nop

;}
RECOMP_FUNC void func_8002848C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002848C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80028490: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80028494: lw          $t6, 0x3EC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3EC);
    // 0x80028498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002849C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800284A0: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800284A4: lbu         $v0, 0x598($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X598);
    // 0x800284A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800284AC: beq         $v0, $at, L_800284CC
    if (ctx->r2 == ctx->r1) {
        // 0x800284B0: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_800284CC;
    }
    // 0x800284B0: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x800284B4: beq         $v0, $at, L_800284DC
    if (ctx->r2 == ctx->r1) {
        // 0x800284B8: addiu       $at, $zero, 0x9E
        ctx->r1 = ADD32(0, 0X9E);
            goto L_800284DC;
    }
    // 0x800284B8: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x800284BC: beq         $v0, $at, L_800284EC
    if (ctx->r2 == ctx->r1) {
        // 0x800284C0: nop
    
            goto L_800284EC;
    }
    // 0x800284C0: nop

    // 0x800284C4: b           L_800284F8
    // 0x800284C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800284F8;
    // 0x800284C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800284CC:
    // 0x800284CC: jal         0x8002835C
    // 0x800284D0: nop

    func_8002835C(rdram, ctx);
        goto after_0;
    // 0x800284D0: nop

    after_0:
    // 0x800284D4: b           L_800284F8
    // 0x800284D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800284F8;
    // 0x800284D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800284DC:
    // 0x800284DC: jal         0x800283C4
    // 0x800284E0: lui         $a1, 0x44F1
    ctx->r5 = S32(0X44F1 << 16);
    func_800283C4(rdram, ctx);
        goto after_1;
    // 0x800284E0: lui         $a1, 0x44F1
    ctx->r5 = S32(0X44F1 << 16);
    after_1:
    // 0x800284E4: b           L_800284F8
    // 0x800284E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800284F8;
    // 0x800284E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800284EC:
    // 0x800284EC: jal         0x800283C4
    // 0x800284F0: lui         $a1, 0x44D3
    ctx->r5 = S32(0X44D3 << 16);
    func_800283C4(rdram, ctx);
        goto after_2;
    // 0x800284F0: lui         $a1, 0x44D3
    ctx->r5 = S32(0X44D3 << 16);
    after_2:
    // 0x800284F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800284F8:
    // 0x800284F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800284FC: jr          $ra
    // 0x80028500: nop

    return;
    // 0x80028500: nop

;}
RECOMP_FUNC void func_8067379C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067379C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806737A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806737A4: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x806737A8: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(529, 0X1A8C) << 16);
    // 0x806737AC: addiu       $t8, $t8, 0x4A6C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(529, 0X1A8C));
    // 0x806737B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806737B4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806737B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806737BC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x806737C0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806737C4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806737C8: beql        $v1, $zero, L_806737FC
    if (ctx->r3 == 0) {
        // 0x806737CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806737FC;
    }
    goto skip_0;
    // 0x806737CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806737D0: jalr        $v1
    // 0x806737D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806737D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806737D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806737DC: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x806737E0: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x806737E4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x806737E8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x806737EC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x806737F0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x806737F4: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x806737F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806737FC:
    // 0x806737FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80673800: jr          $ra
    // 0x80673804: nop

    return;
    // 0x80673804: nop

;}
RECOMP_FUNC void func_80557A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80557A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80557A18: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80557A1C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80557A20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80557A24: lbu         $v0, 0x30($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X30);
    // 0x80557A28: beq         $v0, $at, L_80557A38
    if (ctx->r2 == ctx->r1) {
        // 0x80557A2C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80557A38;
    }
    // 0x80557A2C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80557A30: bnel        $v0, $at, L_80557A4C
    if (ctx->r2 != ctx->r1) {
        // 0x80557A34: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80557A4C;
    }
    goto skip_0;
    // 0x80557A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
L_80557A38:
    // 0x80557A38: jal         0x80557AA0
    // 0x80557A3C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    func_80557AA0(rdram, ctx);
        goto after_0;
    // 0x80557A3C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    after_0:
    // 0x80557A40: b           L_80557A94
    // 0x80557A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80557A94;
    // 0x80557A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80557A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80557A4C:
    // 0x80557A4C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80557A50: jalr        $t9
    // 0x80557A54: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80557A54: nop

    after_1:
    // 0x80557A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80557A5C: bne         $v0, $at, L_80557A74
    if (ctx->r2 != ctx->r1) {
        // 0x80557A60: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80557A74;
    }
    // 0x80557A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80557A64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80557A68: jal         0x80557AA0
    // 0x80557A6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80557AA0(rdram, ctx);
        goto after_2;
    // 0x80557A6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80557A70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80557A74:
    // 0x80557A74: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80557A78: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80557A7C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80557A80: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80557A84: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80557A88: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80557A8C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x80557A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80557A94:
    // 0x80557A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80557A98: jr          $ra
    // 0x80557A9C: nop

    return;
    // 0x80557A9C: nop

;}
RECOMP_FUNC void func_8006D46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D46C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D470: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006D474: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006D478: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006D47C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006D480: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006D484: lbu         $t7, 0x59($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X59);
    // 0x8006D488: lbu         $t6, 0x58($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X58);
    // 0x8006D48C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x8006D490: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8006D494: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D498: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006D49C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006D4A0: mflo        $s2
    ctx->r18 = lo;
    // 0x8006D4A4: blez        $s2, L_8006D4D4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8006D4A8: nop
    
            goto L_8006D4D4;
    }
    // 0x8006D4A8: nop

    // 0x8006D4AC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_8006D4B0:
    // 0x8006D4B0: jal         0x80064E84
    // 0x8006D4B4: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8006D4B4: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_0:
    // 0x8006D4B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006D4BC: jal         0x80064E84
    // 0x8006D4C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8006D4C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8006D4C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006D4C8: bnel        $s1, $s2, L_8006D4B0
    if (ctx->r17 != ctx->r18) {
        // 0x8006D4CC: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_8006D4B0;
    }
    goto skip_0;
    // 0x8006D4CC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8006D4D0: lw          $a1, 0x5C($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X5C);
L_8006D4D4:
    // 0x8006D4D4: jal         0x80064E84
    // 0x8006D4D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x8006D4D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8006D4DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8006D4E0: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x8006D4E4: jal         0x80065728
    // 0x8006D4E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_3;
    // 0x8006D4E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8006D4EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006D4F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006D4F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006D4F8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D4FC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006D500: jr          $ra
    // 0x8006D504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8079F020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079F020: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8079F024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079F028: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079F02C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8079F030: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8079F034: lw          $t6, 0x88($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X88);
    // 0x8079F038: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x8079F03C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8079F040: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8079F044: lbu         $t0, 0x10($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X10);
    // 0x8079F048: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8079F04C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8079F050: addiu       $t0, $t0, 0x5
    ctx->r8 = ADD32(ctx->r8, 0X5);
    // 0x8079F054: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
    // 0x8079F058: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8079F05C: bne         $at, $zero, L_8079F1A8
    if (ctx->r1 != 0) {
        // 0x8079F060: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_8079F1A8;
    }
    // 0x8079F060: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8079F064: sb          $zero, 0x5($a3)
    MEM_B(0X5, ctx->r7) = 0;
    // 0x8079F068: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
    // 0x8079F06C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8079F070: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079F074: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8079F078: sb          $t4, 0xF5C($a3)
    MEM_B(0XF5C, ctx->r7) = ctx->r12;
    // 0x8079F07C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8079F080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8079F084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079F088: sb          $t5, 0xF5D($a3)
    MEM_B(0XF5D, ctx->r7) = ctx->r13;
    // 0x8079F08C: sw          $zero, -0x7474($at)
    MEM_W(-0X7474, ctx->r1) = 0;
    // 0x8079F090: sw          $zero, 0xCF0($a3)
    MEM_W(0XCF0, ctx->r7) = 0;
    // 0x8079F094: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8079F098: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8079F09C: beq         $t6, $zero, L_8079F184
    if (ctx->r14 == 0) {
        // 0x8079F0A0: nop
    
            goto L_8079F184;
    }
    // 0x8079F0A0: nop

    // 0x8079F0A4: sb          $zero, 0x4($a3)
    MEM_B(0X4, ctx->r7) = 0;
    // 0x8079F0A8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8079F0AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079F0B0: beq         $v1, $at, L_8079F0D0
    if (ctx->r3 == ctx->r1) {
        // 0x8079F0B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8079F0D0;
    }
    // 0x8079F0B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8079F0B8: beq         $v1, $at, L_8079F13C
    if (ctx->r3 == ctx->r1) {
        // 0x8079F0BC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8079F13C;
    }
    // 0x8079F0BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8079F0C0: beq         $v1, $at, L_8079F158
    if (ctx->r3 == ctx->r1) {
        // 0x8079F0C4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8079F158;
    }
    // 0x8079F0C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8079F0C8: b           L_8079F1AC
    // 0x8079F0CC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
        goto L_8079F1AC;
    // 0x8079F0CC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_8079F0D0:
    // 0x8079F0D0: lw          $t7, 0xFB4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XFB4);
    // 0x8079F0D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8079F0D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079F0DC: beq         $t7, $zero, L_8079F108
    if (ctx->r15 == 0) {
        // 0x8079F0E0: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8079F108;
    }
    // 0x8079F0E0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8079F0E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8079F0E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079F0EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8079F0F0: jal         0x8006E0FC
    // 0x8079F0F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x8079F0F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x8079F0F8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8079F0FC: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8079F100: b           L_8079F11C
    // 0x8079F104: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_8079F11C;
    // 0x8079F104: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_8079F108:
    // 0x8079F108: jal         0x8006E0FC
    // 0x8079F10C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x8079F10C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x8079F110: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8079F114: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8079F118: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_8079F11C:
    // 0x8079F11C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8079F120: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(835, 0X191C) << 16);
    // 0x8079F124: addiu       $t1, $zero, 0x3F
    ctx->r9 = ADD32(0, 0X3F);
    // 0x8079F128: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8079F12C: lbu         $t9, -0xBF4($t9)
    ctx->r25 = MEM_BU(ctx->r25, (int16_t)RELOC_LO16(835, 0X191C));
    // 0x8079F130: sw          $t1, 0xF54($a3)
    MEM_W(0XF54, ctx->r7) = ctx->r9;
    // 0x8079F134: b           L_8079F1A8
    // 0x8079F138: sb          $t9, 0x585($a3)
    MEM_B(0X585, ctx->r7) = ctx->r25;
        goto L_8079F1A8;
    // 0x8079F138: sb          $t9, 0x585($a3)
    MEM_B(0X585, ctx->r7) = ctx->r25;
L_8079F13C:
    // 0x8079F13C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8079F140: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8079F144: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8079F148: jal         0x8006E0FC
    // 0x8079F14C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_8006E0FC(rdram, ctx);
        goto after_2;
    // 0x8079F14C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_2:
    // 0x8079F150: b           L_8079F1A8
    // 0x8079F154: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_8079F1A8;
    // 0x8079F154: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_8079F158:
    // 0x8079F158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079F15C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8079F160: jal         0x8006E0FC
    // 0x8079F164: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_8006E0FC(rdram, ctx);
        goto after_3;
    // 0x8079F164: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_3:
    // 0x8079F168: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8079F16C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079F170: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8079F174: sw          $zero, -0x7478($at)
    MEM_W(-0X7478, ctx->r1) = 0;
    // 0x8079F178: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8079F17C: b           L_8079F1A8
    // 0x8079F180: sw          $zero, 0xF60($a3)
    MEM_W(0XF60, ctx->r7) = 0;
        goto L_8079F1A8;
    // 0x8079F180: sw          $zero, 0xF60($a3)
    MEM_W(0XF60, ctx->r7) = 0;
L_8079F184:
    // 0x8079F184: jal         0x8006E0FC
    // 0x8079F188: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_8006E0FC(rdram, ctx);
        goto after_4;
    // 0x8079F188: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_4:
    // 0x8079F18C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8079F190: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079F194: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8079F198: sw          $zero, -0x7478($at)
    MEM_W(-0X7478, ctx->r1) = 0;
    // 0x8079F19C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8079F1A0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8079F1A4: sw          $t2, 0xF60($a3)
    MEM_W(0XF60, ctx->r7) = ctx->r10;
L_8079F1A8:
    // 0x8079F1A8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_8079F1AC:
    // 0x8079F1AC: sb          $t0, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r8;
    // 0x8079F1B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079F1B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8079F1B8: jr          $ra
    // 0x8079F1BC: nop

    return;
    // 0x8079F1BC: nop

;}
RECOMP_FUNC void func_8005B96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B96C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B974: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x8005B978: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005B97C: beq         $a2, $zero, L_8005B990
    if (ctx->r6 == 0) {
        // 0x8005B980: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8005B990;
    }
    // 0x8005B980: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8005B984: jal         0x80064E84
    // 0x8005B988: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8005B988: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005B98C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_8005B990:
    // 0x8005B990: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x8005B994: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8005B998: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8005B99C: beql        $a0, $zero, L_8005B9B4
    if (ctx->r4 == 0) {
        // 0x8005B9A0: lw          $a0, 0x14($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X14);
            goto L_8005B9B4;
    }
    goto skip_0;
    // 0x8005B9A0: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    skip_0:
    // 0x8005B9A4: jal         0x80064E84
    // 0x8005B9A8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8005B9A8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8005B9AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005B9B0: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
L_8005B9B4:
    // 0x8005B9B4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x8005B9B8: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x8005B9BC: beql        $a0, $zero, L_8005B9D4
    if (ctx->r4 == 0) {
        // 0x8005B9C0: sw          $zero, 0x10($a1)
        MEM_W(0X10, ctx->r5) = 0;
            goto L_8005B9D4;
    }
    goto skip_1;
    // 0x8005B9C0: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    skip_1:
    // 0x8005B9C4: jal         0x80064E84
    // 0x8005B9C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x8005B9C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x8005B9CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005B9D0: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
L_8005B9D4:
    // 0x8005B9D4: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    // 0x8005B9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B9E0: jr          $ra
    // 0x8005B9E4: nop

    return;
    // 0x8005B9E4: nop

;}
RECOMP_FUNC void func_80670B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670B30: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(526, 0X4AC) << 16);
    // 0x80670B34: addiu       $v0, $v0, 0xFDC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(526, 0X4AC));
    // 0x80670B38: jr          $ra
    // 0x80670B3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80670B3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8045350C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045350C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453514: jal         0x8045341C
    // 0x80453518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8045341C(rdram, ctx);
        goto after_0;
    // 0x80453518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8045351C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453524: jr          $ra
    // 0x80453528: nop

    return;
    // 0x80453528: nop

;}
RECOMP_FUNC void func_80675B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675B3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80675B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675B44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80675B48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80675B4C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80675B50: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80675B54: jal         0x80675770
    // 0x80675B58: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80675770(rdram, ctx);
        goto after_0;
    // 0x80675B58: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80675B5C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80675B60: jal         0x8067586C
    // 0x80675B64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8067586C(rdram, ctx);
        goto after_1;
    // 0x80675B64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80675B68: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80675B6C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80675B70: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80675B74: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80675B78: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80675B7C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x80675B80: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80675B84: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80675B88: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80675B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80675B90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80675B94: jr          $ra
    // 0x80675B98: nop

    return;
    // 0x80675B98: nop

;}
RECOMP_FUNC void func_804535D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804535D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804535D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804535DC: jal         0x8045341C
    // 0x804535E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8045341C(rdram, ctx);
        goto after_0;
    // 0x804535E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x804535E4: jal         0x80445CBC
    // 0x804535E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80445CBC(rdram, ctx);
        goto after_1;
    // 0x804535E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x804535EC: jal         0x80445D08
    // 0x804535F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445D08(rdram, ctx);
        goto after_2;
    // 0x804535F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x804535F4: jal         0x804444FC
    // 0x804535F8: nop

    static_98_804444FC(rdram, ctx);
        goto after_3;
    // 0x804535F8: nop

    after_3:
    // 0x804535FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453604: jr          $ra
    // 0x80453608: nop

    return;
    // 0x80453608: nop

;}
RECOMP_FUNC void func_80047128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047128: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004712C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047130: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80047134: lwc1        $f12, 0x8C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80047138: jal         0x80081C64
    // 0x8004713C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8004713C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80047140: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80047144: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80047148: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004714C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047150: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80047154: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80047158: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8004715C: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80047160: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80047164: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80047168: div.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8004716C: swc1        $f18, 0xB4($t7)
    MEM_W(0XB4, ctx->r15) = ctx->f18.u32l;
    // 0x80047170: jal         0x80058D94
    // 0x80047174: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    func_80058D94(rdram, ctx);
        goto after_1;
    // 0x80047174: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80047178: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8004717C: swc1        $f0, 0xB8($t8)
    MEM_W(0XB8, ctx->r24) = ctx->f0.u32l;
    // 0x80047180: jal         0x80058E08
    // 0x80047184: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    func_80058E08(rdram, ctx);
        goto after_2;
    // 0x80047184: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80047188: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004718C: swc1        $f0, 0xBC($t9)
    MEM_W(0XBC, ctx->r25) = ctx->f0.u32l;
    // 0x80047190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80047198: jr          $ra
    // 0x8004719C: nop

    return;
    // 0x8004719C: nop

;}
RECOMP_FUNC void func_804CEBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CEBC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CEBC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CEBCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804CEBD0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804CEBD4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x804CEBD8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804CEBDC: bnel        $t6, $at, L_804CEC14
    if (ctx->r14 != ctx->r1) {
        // 0x804CEBE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CEC14;
    }
    goto skip_0;
    // 0x804CEBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804CEBE4: lw          $t7, 0x180($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X180);
    // 0x804CEBE8: bnel        $t7, $zero, L_804CEC14
    if (ctx->r15 != 0) {
        // 0x804CEBEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CEC14;
    }
    goto skip_1;
    // 0x804CEBEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804CEBF0: jal         0x804CEA08
    // 0x804CEBF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_804CEA08(rdram, ctx);
        goto after_0;
    // 0x804CEBF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804CEBF8: beq         $v0, $zero, L_804CEC10
    if (ctx->r2 == 0) {
        // 0x804CEBFC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_804CEC10;
    }
    // 0x804CEBFC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804CEC00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CEC04: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804CEC08: jal         0x804CEA84
    // 0x804CEC0C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_804CEA84(rdram, ctx);
        goto after_1;
    // 0x804CEC0C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
L_804CEC10:
    // 0x804CEC10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CEC14:
    // 0x804CEC14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CEC18: jr          $ra
    // 0x804CEC1C: nop

    return;
    // 0x804CEC1C: nop

;}
RECOMP_FUNC void func_80036760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036768: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8003676C: jal         0x80065954
    // 0x80036770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80036770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80036774: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80036778: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003677C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80036780: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80036784: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80036788: jal         0x80041214
    // 0x8003678C: nop

    func_80041214(rdram, ctx);
        goto after_1;
    // 0x8003678C: nop

    after_1:
    // 0x80036790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80036794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036798: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x8003679C: bnel        $v0, $t6, L_800367C0
    if (ctx->r2 != ctx->r14) {
        // 0x800367A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800367C0;
    }
    goto skip_0;
    // 0x800367A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800367A4: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    // 0x800367A8: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x800367AC: bnel        $v0, $t7, L_800367C0
    if (ctx->r2 != ctx->r15) {
        // 0x800367B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800367C0;
    }
    goto skip_1;
    // 0x800367B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800367B4: jal         0x8002288C
    // 0x800367B8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_8002288C(rdram, ctx);
        goto after_2;
    // 0x800367B8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_2:
    // 0x800367BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800367C0:
    // 0x800367C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800367C4: jr          $ra
    // 0x800367C8: nop

    return;
    // 0x800367C8: nop

;}
RECOMP_FUNC void func_8005A6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A6E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A6E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8005A6EC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8005A6F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A6F4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8005A6F8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8005A6FC: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8005A700: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005A704: jal         0x8005A52C
    // 0x8005A708: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    func_8005A52C(rdram, ctx);
        goto after_0;
    // 0x8005A708: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x8005A70C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A714: jr          $ra
    // 0x8005A718: nop

    return;
    // 0x8005A718: nop

;}
RECOMP_FUNC void func_8005D83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D83C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D844: jal         0x8005D7F4
    // 0x8005D848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005D7F4(rdram, ctx);
        goto after_0;
    // 0x8005D848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005D84C: beql        $v0, $zero, L_8005D870
    if (ctx->r2 == 0) {
        // 0x8005D850: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005D870;
    }
    goto skip_0;
    // 0x8005D850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005D854: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8005D858: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8005D85C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8005D860: bnel        $t6, $at, L_8005D870
    if (ctx->r14 != ctx->r1) {
        // 0x8005D864: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005D870;
    }
    goto skip_1;
    // 0x8005D864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8005D868: sw          $v0, 0x264($t7)
    MEM_W(0X264, ctx->r15) = ctx->r2;
    // 0x8005D86C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D870:
    // 0x8005D870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D874: jr          $ra
    // 0x8005D878: nop

    return;
    // 0x8005D878: nop

;}
RECOMP_FUNC void func_80475120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475120: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475124: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475128: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047512C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475130: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475134: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475138: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047513C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475140: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475144: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475148: jr          $ra
    // 0x8047514C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047514C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80428C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428C04: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80428C08: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80428C0C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80428C10: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80428C14: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80428C18: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80428C1C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80428C20: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80428C24: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80428C28: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80428C2C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80428C30: lwc1        $f24, 0x50($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80428C34: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80428C38: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80428C3C: addiu       $s1, $zero, 0x24
    ctx->r17 = ADD32(0, 0X24);
    // 0x80428C40: addiu       $s2, $v0, 0x24
    ctx->r18 = ADD32(ctx->r2, 0X24);
    // 0x80428C44: addiu       $s3, $v0, 0x4C
    ctx->r19 = ADD32(ctx->r2, 0X4C);
    // 0x80428C48: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
L_80428C4C:
    // 0x80428C4C: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80428C50: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80428C54: sub.s       $f20, $f24, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x80428C58: jal         0x80066E88
    // 0x80428C5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80428C5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80428C60: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80428C64: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80428C68: addiu       $s4, $s0, 0xC4
    ctx->r20 = ADD32(ctx->r16, 0XC4);
    // 0x80428C6C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80428C70: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80428C74: jal         0x80066DE4
    // 0x80428C78: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80428C78: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    after_1:
    // 0x80428C7C: mul.s       $f16, $f22, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80428C80: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80428C84: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x80428C88: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x80428C8C: addiu       $s3, $s3, -0x4
    ctx->r19 = ADD32(ctx->r19, -0X4);
    // 0x80428C90: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80428C94: bgez        $s1, L_80428C4C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80428C98: swc1        $f4, 0x4($s4)
        MEM_W(0X4, ctx->r20) = ctx->f4.u32l;
            goto L_80428C4C;
    }
    // 0x80428C98: swc1        $f4, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f4.u32l;
    // 0x80428C9C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80428CA0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80428CA4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80428CA8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80428CAC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80428CB0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80428CB4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80428CB8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80428CBC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80428CC0: jr          $ra
    // 0x80428CC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80428CC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8000A468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A468: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000A46C: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x8000A470: lbu         $t6, 0x4F7C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4F7C);
    // 0x8000A474: sb          $zero, 0x4F7E($v0)
    MEM_B(0X4F7E, ctx->r2) = 0;
    // 0x8000A478: jr          $ra
    // 0x8000A47C: sb          $t6, 0x4F7D($v0)
    MEM_B(0X4F7D, ctx->r2) = ctx->r14;
    return;
    // 0x8000A47C: sb          $t6, 0x4F7D($v0)
    MEM_B(0X4F7D, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80026934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026934: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80026938: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002693C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80026940: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80026944: lwc1        $f4, -0x7678($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x80026948: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002694C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026950: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026954: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026958: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002695C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80026960: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80026964: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80026968: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8002696C: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80026970: beq         $a1, $zero, L_800269BC
    if (ctx->r5 == 0) {
        // 0x80026974: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_800269BC;
    }
    // 0x80026974: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80026978: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002697C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80026980: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80026984: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80026988: nop

    // 0x8002698C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80026990: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80026994: nop

    // 0x80026998: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8002699C: bne         $a1, $zero, L_800269B4
    if (ctx->r5 != 0) {
        // 0x800269A0: nop
    
            goto L_800269B4;
    }
    // 0x800269A0: nop

    // 0x800269A4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800269A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800269AC: b           L_800269CC
    // 0x800269B0: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_800269CC;
    // 0x800269B0: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_800269B4:
    // 0x800269B4: b           L_800269CC
    // 0x800269B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_800269CC;
    // 0x800269B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_800269BC:
    // 0x800269BC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800269C0: nop

    // 0x800269C4: bltz        $a1, L_800269B4
    if (SIGNED(ctx->r5) < 0) {
        // 0x800269C8: nop
    
            goto L_800269B4;
    }
    // 0x800269C8: nop

L_800269CC:
    // 0x800269CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800269D0: sltiu       $at, $a1, 0xA
    ctx->r1 = ctx->r5 < 0XA ? 1 : 0;
    // 0x800269D4: beq         $at, $zero, L_800269E0
    if (ctx->r1 == 0) {
        // 0x800269D8: nop
    
            goto L_800269E0;
    }
    // 0x800269D8: nop

    // 0x800269DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_800269E0:
    // 0x800269E0: jal         0x80024D30
    // 0x800269E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80024D30(rdram, ctx);
        goto after_0;
    // 0x800269E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x800269E8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800269EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800269F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800269F4: lw          $v0, 0x14C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X14C);
    // 0x800269F8: beq         $v0, $at, L_80026A08
    if (ctx->r2 == ctx->r1) {
        // 0x800269FC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80026A08;
    }
    // 0x800269FC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80026A00: bnel        $v0, $at, L_80026A14
    if (ctx->r2 != ctx->r1) {
        // 0x80026A04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80026A14;
    }
    goto skip_0;
    // 0x80026A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80026A08:
    // 0x80026A08: b           L_80026A14
    // 0x80026A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80026A14;
    // 0x80026A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026A10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80026A14:
    // 0x80026A14: jr          $ra
    // 0x80026A18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026A18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806EC9CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC9CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EC9D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EC9D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EC9D8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EC9DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EC9E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EC9E4: jal         0x800577D8
    // 0x806EC9E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EC9E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x806EC9EC: jal         0x806EC444
    // 0x806EC9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC444(rdram, ctx);
        goto after_1;
    // 0x806EC9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EC9F4: jal         0x806EC4B0
    // 0x806EC9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC4B0(rdram, ctx);
        goto after_2;
    // 0x806EC9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EC9FC: jal         0x806EC584
    // 0x806ECA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC584(rdram, ctx);
        goto after_3;
    // 0x806ECA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806ECA04: bne         $v0, $zero, L_806ECA24
    if (ctx->r2 != 0) {
        // 0x806ECA08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806ECA24;
    }
    // 0x806ECA08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECA0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECA10: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806ECA14: jal         0x806ED360
    // 0x806ECA18: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_4;
    // 0x806ECA18: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806ECA1C: b           L_806ECA88
    // 0x806ECA20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806ECA88;
    // 0x806ECA20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECA24:
    // 0x806ECA24: jal         0x806EC5D4
    // 0x806ECA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC5D4(rdram, ctx);
        goto after_5;
    // 0x806ECA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806ECA2C: beq         $v0, $zero, L_806ECA4C
    if (ctx->r2 == 0) {
        // 0x806ECA30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806ECA4C;
    }
    // 0x806ECA30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECA34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECA38: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806ECA3C: jal         0x806ED360
    // 0x806ECA40: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_6;
    // 0x806ECA40: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806ECA44: b           L_806ECA88
    // 0x806ECA48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806ECA88;
    // 0x806ECA48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECA4C:
    // 0x806ECA4C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806ECA50: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806ECA54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECA58: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806ECA5C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806ECA60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECA64: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806ECA68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806ECA6C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806ECA70: nop

    // 0x806ECA74: bc1fl       L_806ECA88
    if (!c1cs) {
        // 0x806ECA78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806ECA88;
    }
    goto skip_0;
    // 0x806ECA78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806ECA7C: jal         0x806ED360
    // 0x806ECA80: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_7;
    // 0x806ECA80: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806ECA84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECA88:
    // 0x806ECA88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ECA8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806ECA90: jr          $ra
    // 0x806ECA94: nop

    return;
    // 0x806ECA94: nop

;}
RECOMP_FUNC void func_804528A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804528A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804528A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804528A8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x804528AC: jal         0x804527B0
    // 0x804528B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_804527B0(rdram, ctx);
        goto after_0;
    // 0x804528B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x804528B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804528B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804528BC: jr          $ra
    // 0x804528C0: nop

    return;
    // 0x804528C0: nop

;}
RECOMP_FUNC void func_804BE828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE828: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804BE82C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x804BE830: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x804BE834: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x804BE838: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x804BE83C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x804BE840: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x804BE844: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x804BE848: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x804BE84C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x804BE850: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804BE854: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804BE858: lw          $s6, 0x1F4($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BE85C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804BE860: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x804BE864: lwc1        $f0, 0xE8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0XE8);
    // 0x804BE868: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BE86C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x804BE870: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x804BE874: lui         $s7, 0x804C
    ctx->r23 = S32(RELOC_HI16(191, 0X2714) << 16);
    // 0x804BE878: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x804BE87C: bc1tl       L_804BE898
    if (c1cs) {
        // 0x804BE880: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_804BE898;
    }
    goto skip_0;
    // 0x804BE880: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x804BE884: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x804BE888: nop

    // 0x804BE88C: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x804BE890: swc1        $f4, 0xE8($s6)
    MEM_W(0XE8, ctx->r22) = ctx->f4.u32l;
    // 0x804BE894: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_804BE898:
    // 0x804BE898: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x804BE89C: addiu       $s7, $s7, -0x1FBC
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(191, 0X2714));
L_804BE8A0:
    // 0x804BE8A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x804BE8A4: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(191, 0X3D18) << 16);
    // 0x804BE8A8: addiu       $t1, $t1, -0x9B8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(191, 0X3D18));
    // 0x804BE8AC: beql        $a0, $zero, L_804BE98C
    if (ctx->r4 == 0) {
        // 0x804BE8B0: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_804BE98C;
    }
    goto skip_1;
    // 0x804BE8B0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_1:
    // 0x804BE8B4: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x804BE8B8: beq         $v0, $zero, L_804BE8C8
    if (ctx->r2 == 0) {
        // 0x804BE8BC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_804BE8C8;
    }
    // 0x804BE8BC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x804BE8C0: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    // 0x804BE8C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_804BE8C8:
    // 0x804BE8C8: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BE8CC: sra         $v1, $v0, 2
    ctx->r3 = S32(SIGNED(ctx->r2) >> 2);
    // 0x804BE8D0: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x804BE8D4: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x804BE8D8: lw          $t8, 0x168($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X168);
    // 0x804BE8DC: lw          $s1, 0x370($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X370);
    // 0x804BE8E0: addu        $s2, $t0, $t1
    ctx->r18 = ADD32(ctx->r8, ctx->r9);
    // 0x804BE8E4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x804BE8E8: lw          $a2, 0x88($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X88);
    // 0x804BE8EC: lw          $t9, 0x168($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X168);
    // 0x804BE8F0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x804BE8F4: addu        $a1, $t3, $a2
    ctx->r5 = ADD32(ctx->r11, ctx->r6);
    // 0x804BE8F8: jal         0x8004590C
    // 0x804BE8FC: lw          $s3, 0x88($t9)
    ctx->r19 = MEM_W(ctx->r25, 0X88);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x804BE8FC: lw          $s3, 0x88($t9)
    ctx->r19 = MEM_W(ctx->r25, 0X88);
    after_0:
    // 0x804BE900: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x804BE904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804BE908: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x804BE90C: jal         0x8004590C
    // 0x804BE910: addu        $a1, $t5, $s3
    ctx->r5 = ADD32(ctx->r13, ctx->r19);
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x804BE910: addu        $a1, $t5, $s3
    ctx->r5 = ADD32(ctx->r13, ctx->r19);
    after_1:
    // 0x804BE914: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x804BE918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BE91C: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x804BE920: nop

    // 0x804BE924: bc1tl       L_804BE938
    if (c1cs) {
        // 0x804BE928: lwc1        $f0, 0x24($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
            goto L_804BE938;
    }
    goto skip_2;
    // 0x804BE928: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x804BE92C: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x804BE930: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x804BE934: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
L_804BE938:
    // 0x804BE938: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x804BE93C: nop

    // 0x804BE940: bc1t        L_804BE950
    if (c1cs) {
        // 0x804BE944: nop
    
            goto L_804BE950;
    }
    // 0x804BE944: nop

    // 0x804BE948: sub.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x804BE94C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_804BE950:
    // 0x804BE950: jal         0x804BE788
    // 0x804BE954: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_804BE788(rdram, ctx);
        goto after_2;
    // 0x804BE954: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x804BE958: bnel        $v0, $zero, L_804BE970
    if (ctx->r2 != 0) {
        // 0x804BE95C: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_804BE970;
    }
    goto skip_3;
    // 0x804BE95C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x804BE960: lh          $t6, 0x36($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X36);
    // 0x804BE964: beql        $t6, $zero, L_804BE98C
    if (ctx->r14 == 0) {
        // 0x804BE968: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_804BE98C;
    }
    goto skip_4;
    // 0x804BE968: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_4:
    // 0x804BE96C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_804BE970:
    // 0x804BE970: sw          $s7, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r23;
    // 0x804BE974: lw          $v0, 0x1F4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1F4);
    // 0x804BE978: lwc1        $f10, 0x360($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X360);
    // 0x804BE97C: lwc1        $f16, 0x364($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X364);
    // 0x804BE980: swc1        $f10, 0x368($v0)
    MEM_W(0X368, ctx->r2) = ctx->f10.u32l;
    // 0x804BE984: swc1        $f16, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f16.u32l;
    // 0x804BE988: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_804BE98C:
    // 0x804BE98C: slti        $at, $s4, 0x3
    ctx->r1 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x804BE990: bne         $at, $zero, L_804BE8A0
    if (ctx->r1 != 0) {
        // 0x804BE994: addiu       $s0, $s0, 0x4C
        ctx->r16 = ADD32(ctx->r16, 0X4C);
            goto L_804BE8A0;
    }
    // 0x804BE994: addiu       $s0, $s0, 0x4C
    ctx->r16 = ADD32(ctx->r16, 0X4C);
    // 0x804BE998: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x804BE99C: jal         0x804BEF4C
    // 0x804BE9A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_804BEF4C(rdram, ctx);
        goto after_3;
    // 0x804BE9A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x804BE9A4: lh          $t8, 0xE4($s6)
    ctx->r24 = MEM_H(ctx->r22, 0XE4);
    // 0x804BE9A8: bnel        $t8, $zero, L_804BEA80
    if (ctx->r24 != 0) {
        // 0x804BE9AC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_804BEA80;
    }
    goto skip_5;
    // 0x804BE9AC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_5:
    // 0x804BE9B0: jal         0x800653D8
    // 0x804BE9B4: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x804BE9B4: nop

    after_4:
    // 0x804BE9B8: andi        $t9, $v0, 0x3F
    ctx->r25 = ctx->r2 & 0X3F;
    // 0x804BE9BC: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x804BE9C0: bnel        $t9, $at, L_804BEA80
    if (ctx->r25 != ctx->r1) {
        // 0x804BE9C4: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_804BEA80;
    }
    goto skip_6;
    // 0x804BE9C4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_6:
    // 0x804BE9C8: jal         0x800653D8
    // 0x804BE9CC: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x804BE9CC: nop

    after_5:
    // 0x804BE9D0: srl         $t0, $v0, 1
    ctx->r8 = S32(U32(ctx->r2) >> 1);
    // 0x804BE9D4: srl         $t2, $v0, 2
    ctx->r10 = S32(U32(ctx->r2) >> 2);
    // 0x804BE9D8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x804BE9DC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x804BE9E0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804BE9E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x804BE9E8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x804BE9EC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x804BE9F0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x804BE9F4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x804BE9F8: addu        $v1, $t5, $s6
    ctx->r3 = ADD32(ctx->r13, ctx->r22);
    // 0x804BE9FC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x804BEA00: beql        $a0, $zero, L_804BEA80
    if (ctx->r4 == 0) {
        // 0x804BEA04: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_804BEA80;
    }
    goto skip_7;
    // 0x804BEA04: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_7:
    // 0x804BEA08: lwc1        $f18, 0x50($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804BEA0C: c.eq.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl == ctx->f18.fl;
    // 0x804BEA10: nop

    // 0x804BEA14: bc1fl       L_804BEA80
    if (!c1cs) {
        // 0x804BEA18: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_804BEA80;
    }
    goto skip_8;
    // 0x804BEA18: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_8:
    // 0x804BEA1C: lh          $t6, 0x2A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2A);
    // 0x804BEA20: bnel        $t6, $zero, L_804BEA80
    if (ctx->r14 != 0) {
        // 0x804BEA24: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_804BEA80;
    }
    goto skip_9;
    // 0x804BEA24: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_9:
    // 0x804BEA28: lh          $t7, 0x36($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X36);
    // 0x804BEA2C: bnel        $t7, $zero, L_804BEA80
    if (ctx->r15 != 0) {
        // 0x804BEA30: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_804BEA80;
    }
    goto skip_10;
    // 0x804BEA30: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_10:
    // 0x804BEA34: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x804BEA38: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X2B78) << 16);
    // 0x804BEA3C: addiu       $t8, $t8, -0x1B58
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(191, 0X2B78));
    // 0x804BEA40: beql        $s7, $v0, L_804BEA80
    if (ctx->r23 == ctx->r2) {
        // 0x804BEA44: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_804BEA80;
    }
    goto skip_11;
    // 0x804BEA44: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_11:
    // 0x804BEA48: beq         $t8, $v0, L_804BEA7C
    if (ctx->r24 == ctx->r2) {
        // 0x804BEA4C: lui         $t9, 0x804C
        ctx->r25 = S32(RELOC_HI16(191, 0X21CC) << 16);
            goto L_804BEA7C;
    }
    // 0x804BEA4C: lui         $t9, 0x804C
    ctx->r25 = S32(RELOC_HI16(191, 0X21CC) << 16);
    // 0x804BEA50: addiu       $t9, $t9, -0x2504
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(191, 0X21CC));
    // 0x804BEA54: sw          $t9, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r25;
    // 0x804BEA58: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BEA5C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804BEA60: lwc1        $f4, 0x360($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X360);
    // 0x804BEA64: lwc1        $f6, 0x364($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X364);
    // 0x804BEA68: swc1        $f4, 0x368($v0)
    MEM_W(0X368, ctx->r2) = ctx->f4.u32l;
    // 0x804BEA6C: swc1        $f6, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f6.u32l;
    // 0x804BEA70: sh          $t0, 0xE4($s6)
    MEM_H(0XE4, ctx->r22) = ctx->r8;
    // 0x804BEA74: lh          $t2, 0xE4($s6)
    ctx->r10 = MEM_H(ctx->r22, 0XE4);
    // 0x804BEA78: sh          $t2, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r10;
L_804BEA7C:
    // 0x804BEA7C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_804BEA80:
    // 0x804BEA80: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x804BEA84: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_804BEA88:
    // 0x804BEA88: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x804BEA8C: beql        $t1, $zero, L_804BEAB4
    if (ctx->r9 == 0) {
        // 0x804BEA90: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_804BEAB4;
    }
    goto skip_12;
    // 0x804BEA90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_12:
    // 0x804BEA94: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x804BEA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BEA9C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x804BEAA0: jalr        $t9
    // 0x804BEAA4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x804BEAA4: nop

    after_6:
    // 0x804BEAA8: b           L_804BEAB8
    // 0x804BEAAC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_804BEAB8;
    // 0x804BEAAC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x804BEAB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_804BEAB4:
    // 0x804BEAB4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_804BEAB8:
    // 0x804BEAB8: bne         $s4, $s2, L_804BEA88
    if (ctx->r20 != ctx->r18) {
        // 0x804BEABC: addiu       $s0, $s0, 0x4C
        ctx->r16 = ADD32(ctx->r16, 0X4C);
            goto L_804BEA88;
    }
    // 0x804BEABC: addiu       $s0, $s0, 0x4C
    ctx->r16 = ADD32(ctx->r16, 0X4C);
    // 0x804BEAC0: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x804BEAC4: bne         $at, $zero, L_804BEAE4
    if (ctx->r1 != 0) {
        // 0x804BEAC8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_804BEAE4;
    }
    // 0x804BEAC8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x804BEACC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804BEAD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BEAD4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804BEAD8: swc1        $f8, 0xE8($s6)
    MEM_W(0XE8, ctx->r22) = ctx->f8.u32l;
    // 0x804BEADC: jal         0x804BED04
    // 0x804BEAE0: lw          $a3, 0x138($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X138);
    func_804BED04(rdram, ctx);
        goto after_7;
    // 0x804BEAE0: lw          $a3, 0x138($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X138);
    after_7:
L_804BEAE4:
    // 0x804BEAE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x804BEAE8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804BEAEC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804BEAF0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x804BEAF4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x804BEAF8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x804BEAFC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x804BEB00: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x804BEB04: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x804BEB08: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x804BEB0C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x804BEB10: jr          $ra
    // 0x804BEB14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x804BEB14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80067970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067978: jal         0x80010640
    // 0x8006797C: nop

    func_80010640(rdram, ctx);
        goto after_0;
    // 0x8006797C: nop

    after_0:
    // 0x80067980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067988: jr          $ra
    // 0x8006798C: nop

    return;
    // 0x8006798C: nop

;}
RECOMP_FUNC void func_8003E3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E3D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E3D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E3DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003E3E0: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8003E3E4: addiu       $t6, $zero, 0x6B
    ctx->r14 = ADD32(0, 0X6B);
    // 0x8003E3E8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003E3EC: beq         $v0, $zero, L_8003E400
    if (ctx->r2 == 0) {
        // 0x8003E3F0: addiu       $a1, $zero, 0x6B
        ctx->r5 = ADD32(0, 0X6B);
            goto L_8003E400;
    }
    // 0x8003E3F0: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    // 0x8003E3F4: jalr        $v0
    // 0x8003E3F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8003E3F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003E3FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8003E400:
    // 0x8003E400: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003E404: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003E408: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8003E40C: addiu       $t7, $t7, -0x1E40
    ctx->r15 = ADD32(ctx->r15, -0X1E40);
    // 0x8003E410: addiu       $t8, $t8, -0x7218
    ctx->r24 = ADD32(ctx->r24, -0X7218);
    // 0x8003E414: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8003E418: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x8003E41C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003E420: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8003E424: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8003E428: lwc1        $f4, 0x244($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X244);
    // 0x8003E42C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8003E430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003E434: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8003E438: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8003E43C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8003E440: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8003E444: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x8003E448: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x8003E44C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8003E450: sw          $zero, 0x44($t1)
    MEM_W(0X44, ctx->r9) = 0;
    // 0x8003E454: jal         0x8005FE48
    // 0x8003E458: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x8003E458: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003E45C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E460: jal         0x8003DA30
    // 0x8003E464: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8003DA30(rdram, ctx);
        goto after_2;
    // 0x8003E464: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8003E468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E46C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E470: jr          $ra
    // 0x8003E474: nop

    return;
    // 0x8003E474: nop

;}
RECOMP_FUNC void func_806FBA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FBA08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806FBA0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FBA10: lw          $v1, 0x14B0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14B0);
    // 0x806FBA14: lwc1        $f12, 0x14A4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X14A4);
    // 0x806FBA18: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x806FBA1C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x806FBA20: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x806FBA24: jal         0x80066DE4
    // 0x806FBA28: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806FBA28: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x806FBA2C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806FBA30: jal         0x80066E88
    // 0x806FBA34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806FBA34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x806FBA38: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x806FBA3C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x806FBA40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806FBA44: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806FBA48: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x806FBA4C: lui         $a2, 0x8070
    ctx->r6 = S32(RELOC_HI16(700, 0X2600) << 16);
    // 0x806FBA50: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806FBA54: addiu       $a2, $a2, -0x3DD0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(700, 0X2600));
    // 0x806FBA58: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806FBA5C: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x806FBA60: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x806FBA64: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806FBA68: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x806FBA6C: mul.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x806FBA70: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x806FBA74: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x806FBA78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806FBA7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806FBA80: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x806FBA84: nop

    // 0x806FBA88: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x806FBA8C: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x806FBA90: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x806FBA94: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806FBA98: lw          $v0, 0x138($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X138);
    // 0x806FBA9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806FBAA0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806FBAA4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x806FBAA8: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x806FBAAC: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x806FBAB0: sw          $v0, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r2;
    // 0x806FBAB4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806FBAB8: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806FBABC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806FBAC0: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
    // 0x806FBAC4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x806FBAC8: nop

    // 0x806FBACC: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x806FBAD0: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x806FBAD4: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x806FBAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FBADC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806FBAE0: jr          $ra
    // 0x806FBAE4: nop

    return;
    // 0x806FBAE4: nop

;}
RECOMP_FUNC void func_8044A498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044A49C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8044A4A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8044A4A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A4A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8044A4AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8044A4B0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A4B4: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8044A4B8: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8044A4BC: lw          $a0, 0x8C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8C);
    // 0x8044A4C0: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x8044A4C4: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8044A4C8: beq         $at, $zero, L_8044A4D8
    if (ctx->r1 == 0) {
        // 0x8044A4CC: sw          $t7, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r15;
            goto L_8044A4D8;
    }
    // 0x8044A4CC: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8044A4D0: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8044A4D4: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
L_8044A4D8:
    // 0x8044A4D8: jal         0x8044A060
    // 0x8044A4DC: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    func_8044A060(rdram, ctx);
        goto after_0;
    // 0x8044A4DC: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    after_0:
    // 0x8044A4E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A4E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044A4E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044A4EC: jr          $ra
    // 0x8044A4F0: nop

    return;
    // 0x8044A4F0: nop

;}
RECOMP_FUNC void func_807B56F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B56F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B56F4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B56F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B56FC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x807B5700: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B5704: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B5708: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B570C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B5710: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_807B5714:
    // 0x807B5714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5718: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x807B571C: jal         0x8005C27C
    // 0x807B5720: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x807B5720: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_0:
    // 0x807B5724: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B5728: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x807B572C: bnel        $at, $zero, L_807B5714
    if (ctx->r1 != 0) {
        // 0x807B5730: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_807B5714;
    }
    goto skip_0;
    // 0x807B5730: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x807B5734: lui         $s1, 0x807B
    ctx->r17 = S32(RELOC_HI16(880, 0X2DD8) << 16);
    // 0x807B5738: addiu       $s1, $s1, 0x75D8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(880, 0X2DD8));
    // 0x807B573C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5740: addiu       $s3, $zero, 0x1000
    ctx->r19 = ADD32(0, 0X1000);
    // 0x807B5744: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
L_807B5748:
    // 0x807B5748: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x807B574C: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x807B5750: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B5754: sll         $a2, $s0, 3
    ctx->r6 = S32(ctx->r16 << 3);
    // 0x807B5758: bne         $s3, $a1, L_807B5768
    if (ctx->r19 != ctx->r5) {
        // 0x807B575C: nop
    
            goto L_807B5768;
    }
    // 0x807B575C: nop

    // 0x807B5760: b           L_807B5770
    // 0x807B5764: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
        goto L_807B5770;
    // 0x807B5764: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
L_807B5768:
    // 0x807B5768: jal         0x8005C27C
    // 0x807B576C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x807B576C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_1:
L_807B5770:
    // 0x807B5770: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807B5774: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x807B5778: bnel        $at, $zero, L_807B5748
    if (ctx->r1 != 0) {
        // 0x807B577C: sll         $t6, $s0, 1
        ctx->r14 = S32(ctx->r16 << 1);
            goto L_807B5748;
    }
    goto skip_1;
    // 0x807B577C: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    skip_1:
    // 0x807B5780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B5784: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B5788: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B578C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B5790: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B5794: jr          $ra
    // 0x807B5798: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B5798: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806E6974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6974: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(655, 0X1098) << 16);
    // 0x806E6978: lwc1        $f4, 0x6D58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(655, 0X1098));
    // 0x806E697C: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806E6980: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(655, 0X109C) << 16);
    // 0x806E6984: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806E6988: nop

    // 0x806E698C: bc1f        L_806E69A0
    if (!c1cs) {
        // 0x806E6990: nop
    
            goto L_806E69A0;
    }
    // 0x806E6990: nop

    // 0x806E6994: lwc1        $f6, 0x6D5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(655, 0X109C));
    // 0x806E6998: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x806E699C: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
L_806E69A0:
    // 0x806E69A0: jr          $ra
    // 0x806E69A4: nop

    return;
    // 0x806E69A4: nop

;}
RECOMP_FUNC void func_80051194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051198: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005119C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800511A0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800511A4: bne         $a0, $at, L_800511C4
    if (ctx->r4 != ctx->r1) {
        // 0x800511A8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800511C4;
    }
    // 0x800511A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800511AC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800511B0: addiu       $a0, $a0, 0xA30
    ctx->r4 = ADD32(ctx->r4, 0XA30);
    // 0x800511B4: jal         0x80071380
    // 0x800511B8: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x800511B8: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    after_0:
    // 0x800511BC: b           L_800511F0
    // 0x800511C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800511F0;
    // 0x800511C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800511C4:
    // 0x800511C4: jal         0x80051100
    // 0x800511C8: nop

    func_80051100(rdram, ctx);
        goto after_1;
    // 0x800511C8: nop

    after_1:
    // 0x800511CC: bne         $v0, $zero, L_800511EC
    if (ctx->r2 != 0) {
        // 0x800511D0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800511EC;
    }
    // 0x800511D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800511D4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800511D8: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    // 0x800511DC: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x800511E0: jal         0x80071380
    // 0x800511E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x800511E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x800511E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800511EC:
    // 0x800511EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_800511F0:
    // 0x800511F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800511F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800511F8: jr          $ra
    // 0x800511FC: nop

    return;
    // 0x800511FC: nop

;}
RECOMP_FUNC void func_804EFABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EFABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804EFAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EFAC4: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x804EFAC8: lui         $t7, 0x804F
    ctx->r15 = S32(RELOC_HI16(267, 0X1170) << 16);
    // 0x804EFACC: lw          $a1, 0x16C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X16C);
    // 0x804EFAD0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804EFAD4: lbu         $t7, -0x100($t7)
    ctx->r15 = MEM_BU(ctx->r15, (int16_t)RELOC_LO16(267, 0X1170));
    // 0x804EFAD8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804EFADC: lui         $t0, 0x804F
    ctx->r8 = S32(RELOC_HI16(267, 0X1150) << 16);
    // 0x804EFAE0: sb          $t7, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r15;
    // 0x804EFAE4: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x804EFAE8: addiu       $t0, $t0, -0x120
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(267, 0X1150));
    // 0x804EFAEC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804EFAF0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804EFAF4: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x804EFAF8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804EFAFC: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804EFB00: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x804EFB04: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804EFB08: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x804EFB0C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804EFB10: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804EFB14: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x804EFB18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804EFB1C: jal         0x804EFA60
    // 0x804EFB20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_804EFA60(rdram, ctx);
        goto after_0;
    // 0x804EFB20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804EFB24: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804EFB28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804EFB2C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x804EFB30: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x804EFB34: sltiu       $at, $t2, 0x28
    ctx->r1 = ctx->r10 < 0X28 ? 1 : 0;
    // 0x804EFB38: bne         $at, $zero, L_804EFB48
    if (ctx->r1 != 0) {
        // 0x804EFB3C: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_804EFB48;
    }
    // 0x804EFB3C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x804EFB40: jal         0x800447C8
    // 0x804EFB44: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804EFB44: nop

    after_1:
L_804EFB48:
    // 0x804EFB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EFB4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804EFB50: jr          $ra
    // 0x804EFB54: nop

    return;
    // 0x804EFB54: nop

;}
RECOMP_FUNC void func_804EF98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF98C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF994: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804EF998: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804EF99C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804EF9A0: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(267, 0X111C) << 16);
    // 0x804EF9A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804EF9A8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804EF9AC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804EF9B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804EF9B4: lw          $t8, -0x154($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(267, 0X111C));
    // 0x804EF9B8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804EF9BC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804EF9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804EF9C4: jal         0x80048490
    // 0x804EF9C8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804EF9C8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804EF9CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804EF9D0: jal         0x80048378
    // 0x804EF9D4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804EF9D4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804EF9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF9E0: jr          $ra
    // 0x804EF9E4: nop

    return;
    // 0x804EF9E4: nop

;}
RECOMP_FUNC void func_804510D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804510D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804510D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804510DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804510E0: jal         0x80450F20
    // 0x804510E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80450F20(rdram, ctx);
        goto after_0;
    // 0x804510E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804510E8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804510EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804510F0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x804510F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804510F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804510FC: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x80451100: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451104: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80451108: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    // 0x8045110C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80451110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80451114: jr          $ra
    // 0x80451118: nop

    return;
    // 0x80451118: nop

;}
RECOMP_FUNC void func_80533FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533FC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80533FC4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80533FC8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80533FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80533FD0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80533FD4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80533FD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80533FDC: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    // 0x80533FE0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80533FE4: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80533FE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80533FEC: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80533FF0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80533FF4: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x80533FF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80533FFC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80534000: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80534004: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80534008: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8053400C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80534010: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80534014: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x80534018: jalr        $t9
    // 0x8053401C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8053401C: nop

    after_0:
    // 0x80534020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80534024: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80534028: jr          $ra
    // 0x8053402C: nop

    return;
    // 0x8053402C: nop

;}
RECOMP_FUNC void func_80742974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742974: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742978: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8074297C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742980: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742984: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742988: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8074298C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742990: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742994: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742998: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8074299C: jr          $ra
    // 0x807429A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807429A0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805DA98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA98C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DA990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA994: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x805DA998: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DA99C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805DA9A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805DA9A4: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x805DA9A8: jal         0x805DA948
    // 0x805DA9AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805DA948(rdram, ctx);
        goto after_0;
    // 0x805DA9AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805DA9B0: bne         $v0, $zero, L_805DA9C8
    if (ctx->r2 != 0) {
        // 0x805DA9B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805DA9C8;
    }
    // 0x805DA9B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805DA9B8: jal         0x800445A4
    // 0x805DA9BC: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805DA9BC: nop

    after_1:
    // 0x805DA9C0: b           L_805DAA14
    // 0x805DA9C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805DAA14;
    // 0x805DA9C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DA9C8:
    // 0x805DA9C8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805DA9CC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x805DA9D0: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x805DA9D4: lui         $t7, 0x805E
    ctx->r15 = S32(RELOC_HI16(477, 0XB68) << 16);
    // 0x805DA9D8: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x805DA9DC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805DA9E0: addiu       $t7, $t7, -0x5458
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(477, 0XB68));
    // 0x805DA9E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805DA9E8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805DA9EC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x805DA9F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805DA9F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DA9F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805DA9FC: jal         0x805DAA20
    // 0x805DAA00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805DAA20(rdram, ctx);
        goto after_2;
    // 0x805DAA00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x805DAA04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805DAA08: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x805DAA0C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x805DAA10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DAA14:
    // 0x805DAA14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DAA18: jr          $ra
    // 0x805DAA1C: nop

    return;
    // 0x805DAA1C: nop

;}
RECOMP_FUNC void func_806D3944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3944: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D3948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D394C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D3950: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806D3954: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D3958: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x806D395C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3960: jal         0x806D373C
    // 0x806D3964: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_806D373C(rdram, ctx);
        goto after_0;
    // 0x806D3964: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x806D3968: bne         $v0, $zero, L_806D3A48
    if (ctx->r2 != 0) {
        // 0x806D396C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_806D3A48;
    }
    // 0x806D396C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806D3970: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x806D3974: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    // 0x806D3978: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806D397C: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806D3980: lbu         $t0, 0x2C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2C);
    // 0x806D3984: beql        $t0, $zero, L_806D3A40
    if (ctx->r8 == 0) {
        // 0x806D3988: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806D3A40;
    }
    goto skip_0;
    // 0x806D3988: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x806D398C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D3990: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806D3994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D3998: addiu       $a1, $zero, 0x232
    ctx->r5 = ADD32(0, 0X232);
    // 0x806D399C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D39A0: nop

    // 0x806D39A4: bc1fl       L_806D3A40
    if (!c1cs) {
        // 0x806D39A8: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806D3A40;
    }
    goto skip_1;
    // 0x806D39A8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x806D39AC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x806D39B0: jal         0x806D357C
    // 0x806D39B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_806D357C(rdram, ctx);
        goto after_1;
    // 0x806D39B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x806D39B8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806D39BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806D39C0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x806D39C4: lh          $t1, 0x24($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X24);
    // 0x806D39C8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x806D39CC: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    // 0x806D39D0: lh          $v0, 0x24($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X24);
    // 0x806D39D4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x806D39D8: bne         $at, $zero, L_806D3A28
    if (ctx->r1 != 0) {
        // 0x806D39DC: subu        $t4, $t3, $v0
        ctx->r12 = SUB32(ctx->r11, ctx->r2);
            goto L_806D3A28;
    }
    // 0x806D39DC: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x806D39E0: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x806D39E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D39E8: beql        $v0, $zero, L_806D3A40
    if (ctx->r2 == 0) {
        // 0x806D39EC: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806D3A40;
    }
    goto skip_2;
    // 0x806D39EC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_2:
    // 0x806D39F0: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x806D39F4: lw          $a1, 0x68($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X68);
    // 0x806D39F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806D39FC: jal         0x806D301C
    // 0x806D3A00: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_806D301C(rdram, ctx);
        goto after_2;
    // 0x806D3A00: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x806D3A04: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806D3A08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D3A0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806D3A10: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x806D3A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D3A18: jal         0x806D30C4
    // 0x806D3A1C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    func_806D30C4(rdram, ctx);
        goto after_3;
    // 0x806D3A1C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    after_3:
    // 0x806D3A20: b           L_806D3A40
    // 0x806D3A24: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
        goto L_806D3A40;
    // 0x806D3A24: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D3A28:
    // 0x806D3A28: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x806D3A2C: nop

    // 0x806D3A30: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806D3A34: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x806D3A38: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
    // 0x806D3A3C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D3A40:
    // 0x806D3A40: jal         0x806D30C4
    // 0x806D3A44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806D30C4(rdram, ctx);
        goto after_4;
    // 0x806D3A44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_806D3A48:
    // 0x806D3A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D3A4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D3A50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806D3A54: jr          $ra
    // 0x806D3A58: nop

    return;
    // 0x806D3A58: nop

;}
RECOMP_FUNC void func_80742CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742CF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80742CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742CFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80742D00: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80742D04: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80742D08: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80742D0C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80742D10: lw          $v1, 0x6E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E64);
    // 0x80742D14: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80742D18: beql        $v1, $zero, L_80742D34
    if (ctx->r3 == 0) {
        // 0x80742D1C: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80742D34;
    }
    goto skip_0;
    // 0x80742D1C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80742D20: jal         0x80742A04
    // 0x80742D24: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    func_80742A04(rdram, ctx);
        goto after_0;
    // 0x80742D24: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    after_0:
    // 0x80742D28: b           L_80742D58
    // 0x80742D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742D58;
    // 0x80742D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80742D30: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80742D34:
    // 0x80742D34: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80742D38: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80742D3C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80742D40: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80742D44: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80742D48: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80742D4C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80742D50: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80742D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742D58:
    // 0x80742D58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80742D5C: jr          $ra
    // 0x80742D60: nop

    return;
    // 0x80742D60: nop

;}
RECOMP_FUNC void func_80055A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055A68: addiu       $sp, $sp, -0x1018
    ctx->r29 = ADD32(ctx->r29, -0X1018);
    // 0x80055A6C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80055A70: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80055A74: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80055A78: andi        $s7, $a3, 0xFF
    ctx->r23 = ctx->r7 & 0XFF;
    // 0x80055A7C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80055A80: sw          $a0, 0x1018($sp)
    MEM_W(0X1018, ctx->r29) = ctx->r4;
    // 0x80055A84: sw          $a1, 0x101C($sp)
    MEM_W(0X101C, ctx->r29) = ctx->r5;
    // 0x80055A88: sw          $a3, 0x1024($sp)
    MEM_W(0X1024, ctx->r29) = ctx->r7;
    // 0x80055A8C: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x80055A90: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80055A94: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80055A98: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80055A9C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80055AA0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80055AA4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80055AA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80055AAC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80055AB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80055AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80055AB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80055ABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80055AC0: jal         0x80055A38
    // 0x80055AC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80055A38(rdram, ctx);
        goto after_0;
    // 0x80055AC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80055AC8: lw          $v1, 0x1018($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1018);
    // 0x80055ACC: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80055AD0: addiu       $fp, $sp, 0x8C
    ctx->r30 = ADD32(ctx->r29, 0X8C);
    // 0x80055AD4: lw          $s4, 0x1028($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X1028);
    // 0x80055AD8: lw          $v0, -0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, -0X4);
L_80055ADC:
    // 0x80055ADC: addiu       $t0, $t0, -0x14
    ctx->r8 = ADD32(ctx->r8, -0X14);
    // 0x80055AE0: addiu       $fp, $fp, -0x14
    ctx->r30 = ADD32(ctx->r30, -0X14);
    // 0x80055AE4: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x80055AE8: lw          $s5, 0x4($fp)
    ctx->r21 = MEM_W(ctx->r30, 0X4);
    // 0x80055AEC: lw          $s3, 0x8($fp)
    ctx->r19 = MEM_W(ctx->r30, 0X8);
    // 0x80055AF0: beq         $v0, $zero, L_80055B14
    if (ctx->r2 == 0) {
        // 0x80055AF4: lw          $s0, 0xC($fp)
        ctx->r16 = MEM_W(ctx->r30, 0XC);
            goto L_80055B14;
    }
    // 0x80055AF4: lw          $s0, 0xC($fp)
    ctx->r16 = MEM_W(ctx->r30, 0XC);
    // 0x80055AF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80055AFC: beq         $v0, $at, L_80055BB0
    if (ctx->r2 == ctx->r1) {
        // 0x80055B00: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80055BB0;
    }
    // 0x80055B00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055B04: beql        $v0, $at, L_80055C6C
    if (ctx->r2 == ctx->r1) {
        // 0x80055B08: lw          $t3, 0x101C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X101C);
            goto L_80055C6C;
    }
    goto skip_0;
    // 0x80055B08: lw          $t3, 0x101C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X101C);
    skip_0:
    // 0x80055B0C: b           L_80055D24
    // 0x80055B10: addiu       $t9, $sp, 0x102C
    ctx->r25 = ADD32(ctx->r29, 0X102C);
        goto L_80055D24;
    // 0x80055B10: addiu       $t9, $sp, 0x102C
    ctx->r25 = ADD32(ctx->r29, 0X102C);
L_80055B14:
    // 0x80055B14: bltz        $s1, L_80055B5C
    if (SIGNED(ctx->r17) < 0) {
        // 0x80055B18: or          $s3, $s1, $zero
        ctx->r19 = ctx->r17 | 0;
            goto L_80055B5C;
    }
    // 0x80055B18: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x80055B1C: addu        $t7, $s1, $s5
    ctx->r15 = ADD32(ctx->r17, ctx->r21);
    // 0x80055B20: addu        $t8, $t7, $s6
    ctx->r24 = ADD32(ctx->r15, ctx->r22);
    // 0x80055B24: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80055B28: addu        $t1, $s6, $s3
    ctx->r9 = ADD32(ctx->r22, ctx->r19);
    // 0x80055B2C: addu        $v0, $t1, $s5
    ctx->r2 = ADD32(ctx->r9, ctx->r21);
    // 0x80055B30: bnel        $s4, $t9, L_80055B60
    if (ctx->r20 != ctx->r25) {
        // 0x80055B34: addiu       $v0, $s1, 0x1
        ctx->r2 = ADD32(ctx->r17, 0X1);
            goto L_80055B60;
    }
    goto skip_1;
    // 0x80055B34: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80055B38: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80055B3C:
    // 0x80055B3C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80055B40: bltz        $s3, L_80055B5C
    if (SIGNED(ctx->r19) < 0) {
        // 0x80055B44: sb          $s7, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r23;
            goto L_80055B5C;
    }
    // 0x80055B44: sb          $s7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r23;
    // 0x80055B48: addu        $t2, $s3, $s5
    ctx->r10 = ADD32(ctx->r19, ctx->r21);
    // 0x80055B4C: addu        $t3, $t2, $s6
    ctx->r11 = ADD32(ctx->r10, ctx->r22);
    // 0x80055B50: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80055B54: beql        $s4, $t4, L_80055B3C
    if (ctx->r20 == ctx->r12) {
        // 0x80055B58: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80055B3C;
    }
    goto skip_2;
    // 0x80055B58: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_2:
L_80055B5C:
    // 0x80055B5C: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
L_80055B60:
    // 0x80055B60: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80055B64: beq         $at, $zero, L_80055BB0
    if (ctx->r1 == 0) {
        // 0x80055B68: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80055BB0;
    }
    // 0x80055B68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80055B6C: addu        $t5, $v0, $s5
    ctx->r13 = ADD32(ctx->r2, ctx->r21);
    // 0x80055B70: addu        $t6, $t5, $s6
    ctx->r14 = ADD32(ctx->r13, ctx->r22);
    // 0x80055B74: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80055B78: addu        $t8, $s6, $v0
    ctx->r24 = ADD32(ctx->r22, ctx->r2);
    // 0x80055B7C: addu        $v0, $t8, $s5
    ctx->r2 = ADD32(ctx->r24, ctx->r21);
    // 0x80055B80: bnel        $s4, $t7, L_80055BB4
    if (ctx->r20 != ctx->r15) {
        // 0x80055B84: subu        $t3, $s5, $v1
        ctx->r11 = SUB32(ctx->r21, ctx->r3);
            goto L_80055BB4;
    }
    goto skip_3;
    // 0x80055B84: subu        $t3, $s5, $v1
    ctx->r11 = SUB32(ctx->r21, ctx->r3);
    skip_3:
    // 0x80055B88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80055B8C:
    // 0x80055B8C: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80055B90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80055B94: beq         $at, $zero, L_80055BB0
    if (ctx->r1 == 0) {
        // 0x80055B98: sb          $s7, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r23;
            goto L_80055BB0;
    }
    // 0x80055B98: sb          $s7, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r23;
    // 0x80055B9C: addu        $t9, $s0, $s5
    ctx->r25 = ADD32(ctx->r16, ctx->r21);
    // 0x80055BA0: addu        $t1, $t9, $s6
    ctx->r9 = ADD32(ctx->r25, ctx->r22);
    // 0x80055BA4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80055BA8: beql        $s4, $t2, L_80055B8C
    if (ctx->r20 == ctx->r10) {
        // 0x80055BAC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80055B8C;
    }
    goto skip_4;
    // 0x80055BAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
L_80055BB0:
    // 0x80055BB0: subu        $t3, $s5, $v1
    ctx->r11 = SUB32(ctx->r21, ctx->r3);
L_80055BB4:
    // 0x80055BB4: bltz        $t3, L_80055C58
    if (SIGNED(ctx->r11) < 0) {
        // 0x80055BB8: sw          $t3, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r11;
            goto L_80055C58;
    }
    // 0x80055BB8: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x80055BBC: addiu       $v0, $s3, 0x1
    ctx->r2 = ADD32(ctx->r19, 0X1);
    // 0x80055BC0: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80055BC4: beq         $at, $zero, L_80055C58
    if (ctx->r1 == 0) {
        // 0x80055BC8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80055C58;
    }
    // 0x80055BC8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80055BCC: addu        $t5, $v0, $t3
    ctx->r13 = ADD32(ctx->r2, ctx->r11);
    // 0x80055BD0: addu        $v0, $t5, $s6
    ctx->r2 = ADD32(ctx->r13, ctx->r22);
L_80055BD4:
    // 0x80055BD4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80055BD8: bne         $s4, $t6, L_80055C4C
    if (ctx->r20 != ctx->r14) {
        // 0x80055BDC: addiu       $t8, $sp, 0x78
        ctx->r24 = ADD32(ctx->r29, 0X78);
            goto L_80055C4C;
    }
    // 0x80055BDC: addiu       $t8, $sp, 0x78
    ctx->r24 = ADD32(ctx->r29, 0X78);
    // 0x80055BE0: addu        $s2, $t0, $t8
    ctx->r18 = ADD32(ctx->r8, ctx->r24);
    // 0x80055BE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80055BE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80055BEC: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80055BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80055BF4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80055BF8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80055BFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80055C00: jal         0x80055A38
    // 0x80055C04: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    func_80055A38(rdram, ctx);
        goto after_1;
    // 0x80055C04: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    after_1:
    // 0x80055C08: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80055C0C: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80055C10: addiu       $fp, $fp, 0x14
    ctx->r30 = ADD32(ctx->r30, 0X14);
    // 0x80055C14: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // 0x80055C18: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80055C1C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80055C20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80055C24: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80055C28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80055C2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80055C30: jal         0x80055A38
    // 0x80055C34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80055A38(rdram, ctx);
        goto after_2;
    // 0x80055C34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80055C38: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80055C3C: lw          $v1, 0x1018($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1018);
    // 0x80055C40: addiu       $fp, $fp, 0x14
    ctx->r30 = ADD32(ctx->r30, 0X14);
    // 0x80055C44: b           L_80055C58
    // 0x80055C48: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
        goto L_80055C58;
    // 0x80055C48: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
L_80055C4C:
    // 0x80055C4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80055C50: bne         $s1, $s0, L_80055BD4
    if (ctx->r17 != ctx->r16) {
        // 0x80055C54: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80055BD4;
    }
    // 0x80055C54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80055C58:
    // 0x80055C58: beq         $s1, $s0, L_80055C68
    if (ctx->r17 == ctx->r16) {
        // 0x80055C5C: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_80055C68;
    }
    // 0x80055C5C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80055C60: bgezl       $t9, L_80055D24
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80055C64: addiu       $t9, $sp, 0x102C
        ctx->r25 = ADD32(ctx->r29, 0X102C);
            goto L_80055D24;
    }
    goto skip_5;
    // 0x80055C64: addiu       $t9, $sp, 0x102C
    ctx->r25 = ADD32(ctx->r29, 0X102C);
    skip_5:
L_80055C68:
    // 0x80055C68: lw          $t3, 0x101C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X101C);
L_80055C6C:
    // 0x80055C6C: addu        $t1, $s5, $v1
    ctx->r9 = ADD32(ctx->r21, ctx->r3);
    // 0x80055C70: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80055C74: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055C78: addiu       $v0, $s3, 0x1
    ctx->r2 = ADD32(ctx->r19, 0X1);
    // 0x80055C7C: mflo        $t4
    ctx->r12 = lo;
    // 0x80055C80: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80055C84: beq         $at, $zero, L_80055D20
    if (ctx->r1 == 0) {
        // 0x80055C88: slt         $at, $v0, $s0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_80055D20;
    }
    // 0x80055C88: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80055C8C: beq         $at, $zero, L_80055D20
    if (ctx->r1 == 0) {
        // 0x80055C90: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80055D20;
    }
    // 0x80055C90: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80055C94: addu        $t5, $v0, $t1
    ctx->r13 = ADD32(ctx->r2, ctx->r9);
    // 0x80055C98: addu        $v0, $t5, $s6
    ctx->r2 = ADD32(ctx->r13, ctx->r22);
L_80055C9C:
    // 0x80055C9C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80055CA0: bne         $s4, $t6, L_80055D14
    if (ctx->r20 != ctx->r14) {
        // 0x80055CA4: addiu       $t8, $sp, 0x78
        ctx->r24 = ADD32(ctx->r29, 0X78);
            goto L_80055D14;
    }
    // 0x80055CA4: addiu       $t8, $sp, 0x78
    ctx->r24 = ADD32(ctx->r29, 0X78);
    // 0x80055CA8: addu        $s2, $t0, $t8
    ctx->r18 = ADD32(ctx->r8, ctx->r24);
    // 0x80055CAC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80055CB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80055CB4: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80055CB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80055CBC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80055CC0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80055CC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80055CC8: jal         0x80055A38
    // 0x80055CCC: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    func_80055A38(rdram, ctx);
        goto after_3;
    // 0x80055CCC: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    after_3:
    // 0x80055CD0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80055CD4: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80055CD8: addiu       $fp, $fp, 0x14
    ctx->r30 = ADD32(ctx->r30, 0X14);
    // 0x80055CDC: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // 0x80055CE0: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80055CE4: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80055CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80055CEC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80055CF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80055CF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80055CF8: jal         0x80055A38
    // 0x80055CFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80055A38(rdram, ctx);
        goto after_4;
    // 0x80055CFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80055D00: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80055D04: lw          $v1, 0x1018($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1018);
    // 0x80055D08: addiu       $fp, $fp, 0x14
    ctx->r30 = ADD32(ctx->r30, 0X14);
    // 0x80055D0C: b           L_80055D20
    // 0x80055D10: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
        goto L_80055D20;
    // 0x80055D10: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
L_80055D14:
    // 0x80055D14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80055D18: bne         $s1, $s0, L_80055C9C
    if (ctx->r17 != ctx->r16) {
        // 0x80055D1C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80055C9C;
    }
    // 0x80055D1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80055D20:
    // 0x80055D20: addiu       $t9, $sp, 0x102C
    ctx->r25 = ADD32(ctx->r29, 0X102C);
L_80055D24:
    // 0x80055D24: sltu        $at, $fp, $t9
    ctx->r1 = ctx->r30 < ctx->r25 ? 1 : 0;
    // 0x80055D28: beq         $at, $zero, L_80055D3C
    if (ctx->r1 == 0) {
        // 0x80055D2C: addiu       $t1, $sp, 0x8C
        ctx->r9 = ADD32(ctx->r29, 0X8C);
            goto L_80055D3C;
    }
    // 0x80055D2C: addiu       $t1, $sp, 0x8C
    ctx->r9 = ADD32(ctx->r29, 0X8C);
    // 0x80055D30: sltu        $at, $fp, $t1
    ctx->r1 = ctx->r30 < ctx->r9 ? 1 : 0;
    // 0x80055D34: beql        $at, $zero, L_80055ADC
    if (ctx->r1 == 0) {
        // 0x80055D38: lw          $v0, -0x4($fp)
        ctx->r2 = MEM_W(ctx->r30, -0X4);
            goto L_80055ADC;
    }
    goto skip_6;
    // 0x80055D38: lw          $v0, -0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, -0X4);
    skip_6:
L_80055D3C:
    // 0x80055D3C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80055D40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80055D44: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80055D48: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80055D4C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80055D50: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80055D54: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80055D58: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80055D5C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80055D60: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80055D64: jr          $ra
    // 0x80055D68: addiu       $sp, $sp, 0x1018
    ctx->r29 = ADD32(ctx->r29, 0X1018);
    return;
    // 0x80055D68: addiu       $sp, $sp, 0x1018
    ctx->r29 = ADD32(ctx->r29, 0X1018);
;}
RECOMP_FUNC void func_804A4304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4304: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804A4308: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x804A430C: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x804A4310: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x804A4314: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x804A4318: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x804A431C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804A4320: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804A4324: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804A4328: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804A432C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804A4330: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A4334: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804A4338: lwc1        $f26, 0x3C($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A433C: addiu       $s0, $v0, 0x188
    ctx->r16 = ADD32(ctx->r2, 0X188);
    // 0x804A4340: lwc1        $f28, 0x40($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A4344: bne         $s0, $zero, L_804A4354
    if (ctx->r16 != 0) {
        // 0x804A4348: lh          $s1, 0x184($v0)
        ctx->r17 = MEM_H(ctx->r2, 0X184);
            goto L_804A4354;
    }
    // 0x804A4348: lh          $s1, 0x184($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X184);
    // 0x804A434C: b           L_804A4400
    // 0x804A4350: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_804A4400;
    // 0x804A4350: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_804A4354:
    // 0x804A4354: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A4358: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804A435C: beq         $s1, $zero, L_804A43DC
    if (ctx->r17 == 0) {
        // 0x804A4360: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_804A43DC;
    }
    // 0x804A4360: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_804A4364:
    // 0x804A4364: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804A4368: beq         $v0, $zero, L_804A43D4
    if (ctx->r2 == 0) {
        // 0x804A436C: nop
    
            goto L_804A43D4;
    }
    // 0x804A436C: nop

    // 0x804A4370: lwc1        $f14, 0x3C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A4374: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x804A4378: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x804A437C: c.lt.s      $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f26.fl < ctx->f14.fl;
    // 0x804A4380: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804A4384: lwc1        $f20, 0x40($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A4388: bc1t        L_804A43A0
    if (c1cs) {
        // 0x804A438C: nop
    
            goto L_804A43A0;
    }
    // 0x804A438C: nop

    // 0x804A4390: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x804A4394: nop

    // 0x804A4398: bc1f        L_804A43D4
    if (!c1cs) {
        // 0x804A439C: nop
    
            goto L_804A43D4;
    }
    // 0x804A439C: nop

L_804A43A0:
    // 0x804A43A0: jal         0x804A3C08
    // 0x804A43A4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_804A3C08(rdram, ctx);
        goto after_0;
    // 0x804A43A4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_0:
    // 0x804A43A8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804A43AC: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x804A43B0: jal         0x804A3C08
    // 0x804A43B4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_804A3C08(rdram, ctx);
        goto after_1;
    // 0x804A43B4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x804A43B8: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804A43BC: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x804A43C0: nop

    // 0x804A43C4: bc1f        L_804A43D4
    if (!c1cs) {
        // 0x804A43C8: nop
    
            goto L_804A43D4;
    }
    // 0x804A43C8: nop

    // 0x804A43CC: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804A43D0: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_804A43D4:
    // 0x804A43D4: bne         $s1, $zero, L_804A4364
    if (ctx->r17 != 0) {
        // 0x804A43D8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804A4364;
    }
    // 0x804A43D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804A43DC:
    // 0x804A43DC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A43E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A43E4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x804A43E8: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x804A43EC: nop

    // 0x804A43F0: bc1f        L_804A4400
    if (!c1cs) {
        // 0x804A43F4: nop
    
            goto L_804A4400;
    }
    // 0x804A43F4: nop

    // 0x804A43F8: b           L_804A4400
    // 0x804A43FC: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_804A4400;
    // 0x804A43FC: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_804A4400:
    // 0x804A4400: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x804A4404: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804A4408: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804A440C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804A4410: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804A4414: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804A4418: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x804A441C: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x804A4420: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x804A4424: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x804A4428: jr          $ra
    // 0x804A442C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804A442C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8002C7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C7B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C7B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C7B8: jal         0x8002C74C
    // 0x8002C7BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002C74C(rdram, ctx);
        goto after_0;
    // 0x8002C7BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C7C0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8002C7C4: sw          $zero, 0x138($t6)
    MEM_W(0X138, ctx->r14) = 0;
    // 0x8002C7C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C7CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C7D0: jr          $ra
    // 0x8002C7D4: nop

    return;
    // 0x8002C7D4: nop

;}
RECOMP_FUNC void func_804F3D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804F3D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F3D28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804F3D2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804F3D30: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804F3D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804F3D38: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804F3D3C: lui         $t7, 0x804F
    ctx->r15 = S32(RELOC_HI16(270, 0XD80) << 16);
    // 0x804F3D40: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804F3D44: sb          $v0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r2;
    // 0x804F3D48: addiu       $t7, $t7, 0x40B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(270, 0XD80));
    // 0x804F3D4C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804F3D50: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804F3D54: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x804F3D58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804F3D5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804F3D60: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x804F3D64: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x804F3D68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804F3D6C: jal         0x804F3EF0
    // 0x804F3D70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804F3EF0(rdram, ctx);
        goto after_0;
    // 0x804F3D70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804F3D74: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x804F3D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F3D7C: jal         0x80045A34
    // 0x804F3D80: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804F3D80: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_1:
    // 0x804F3D84: lui         $t9, 0x804F
    ctx->r25 = S32(RELOC_HI16(270, 0X790) << 16);
    // 0x804F3D88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804F3D8C: addiu       $t9, $t9, 0x3AC0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(270, 0X790));
    // 0x804F3D90: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804F3D94: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x804F3D98: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x804F3D9C: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x804F3DA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804F3DA4: jal         0x80047AB8
    // 0x804F3DA8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x804F3DA8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x804F3DAC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x804F3DB0: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x804F3DB4: addiu       $at, $zero, 0x4050
    ctx->r1 = ADD32(0, 0X4050);
    // 0x804F3DB8: beq         $v0, $at, L_804F3DD0
    if (ctx->r2 == ctx->r1) {
        // 0x804F3DBC: addiu       $at, $zero, 0x4051
        ctx->r1 = ADD32(0, 0X4051);
            goto L_804F3DD0;
    }
    // 0x804F3DBC: addiu       $at, $zero, 0x4051
    ctx->r1 = ADD32(0, 0X4051);
    // 0x804F3DC0: beq         $v0, $at, L_804F3E60
    if (ctx->r2 == ctx->r1) {
        // 0x804F3DC4: nop
    
            goto L_804F3E60;
    }
    // 0x804F3DC4: nop

    // 0x804F3DC8: b           L_804F3EE0
    // 0x804F3DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804F3EE0;
    // 0x804F3DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F3DD0:
    // 0x804F3DD0: jal         0x800576CC
    // 0x804F3DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800576CC(rdram, ctx);
        goto after_3;
    // 0x804F3DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804F3DD8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x804F3DDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804F3DE0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x804F3DE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804F3DE8: jal         0x80066E88
    // 0x804F3DEC: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x804F3DEC: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x804F3DF0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804F3DF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804F3DF8: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x804F3DFC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x804F3E00: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x804F3E04: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804F3E08: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x804F3E0C: jal         0x80066DE4
    // 0x804F3E10: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x804F3E10: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    after_5:
    // 0x804F3E14: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804F3E18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804F3E1C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x804F3E20: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x804F3E24: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804F3E28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804F3E2C: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x804F3E30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804F3E34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804F3E38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804F3E3C: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(270, 0XE48) << 16);
    // 0x804F3E40: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x804F3E44: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x804F3E48: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x804F3E4C: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    // 0x804F3E50: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x804F3E54: lwc1        $f4, 0x4178($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(270, 0XE48));
    // 0x804F3E58: b           L_804F3EDC
    // 0x804F3E5C: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
        goto L_804F3EDC;
    // 0x804F3E5C: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
L_804F3E60:
    // 0x804F3E60: jal         0x800576EC
    // 0x804F3E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800576EC(rdram, ctx);
        goto after_6;
    // 0x804F3E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804F3E68: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804F3E6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804F3E70: jal         0x80066E88
    // 0x804F3E74: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x804F3E74: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
    after_7:
    // 0x804F3E78: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804F3E7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804F3E80: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x804F3E84: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804F3E88: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804F3E8C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804F3E90: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804F3E94: jal         0x80066DE4
    // 0x804F3E98: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x804F3E98: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    after_8:
    // 0x804F3E9C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804F3EA0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804F3EA4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804F3EA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804F3EAC: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x804F3EB0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x804F3EB4: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804F3EB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804F3EBC: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(270, 0XE4C) << 16);
    // 0x804F3EC0: swc1        $f2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f2.u32l;
    // 0x804F3EC4: swc1        $f2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f2.u32l;
    // 0x804F3EC8: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x804F3ECC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804F3ED0: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x804F3ED4: lwc1        $f18, 0x417C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(270, 0XE4C));
    // 0x804F3ED8: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
L_804F3EDC:
    // 0x804F3EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F3EE0:
    // 0x804F3EE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804F3EE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804F3EE8: jr          $ra
    // 0x804F3EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804F3EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80798E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798E00: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80798E04: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80798E08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80798E0C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80798E10: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80798E14: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80798E18: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80798E1C: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(826, 0X2468) << 16);
    // 0x80798E20: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80798E24: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80798E28: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80798E2C: lw          $t1, -0x5078($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(826, 0X2468));
    // 0x80798E30: jr          $ra
    // 0x80798E34: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80798E34: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_800780F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800780F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800780F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800780F8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800780FC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80078100: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80078104: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80078108: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007810C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80078110: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80078114: jal         0x8007861C
    // 0x80078118: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8007861C(rdram, ctx);
        goto after_0;
    // 0x80078118: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007811C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80078124: jr          $ra
    // 0x80078128: nop

    return;
    // 0x80078128: nop

;}
RECOMP_FUNC void func_8079F730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079F730: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8079F734: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8079F738: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8079F73C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8079F740: nop

    // 0x8079F744: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8079F748: nop

    // 0x8079F74C: bc1fl       L_8079F77C
    if (!c1cs) {
        // 0x8079F750: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8079F77C;
    }
    goto skip_0;
    // 0x8079F750: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8079F754: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079F758: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8079F75C: nop

    // 0x8079F760: bc1f        L_8079F798
    if (!c1cs) {
        // 0x8079F764: nop
    
            goto L_8079F798;
    }
    // 0x8079F764: nop

    // 0x8079F768: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8079F76C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8079F770: jr          $ra
    // 0x8079F774: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8079F774: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8079F778: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_8079F77C:
    // 0x8079F77C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8079F780: nop

    // 0x8079F784: bc1f        L_8079F798
    if (!c1cs) {
        // 0x8079F788: nop
    
            goto L_8079F798;
    }
    // 0x8079F788: nop

    // 0x8079F78C: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8079F790: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8079F794: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8079F798:
    // 0x8079F798: jr          $ra
    // 0x8079F79C: nop

    return;
    // 0x8079F79C: nop

;}
RECOMP_FUNC void func_804CBA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CBA88: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804CBA8C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x804CBA90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804CBA94: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x804CBA98: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804CBA9C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x804CBAA0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804CBAA4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x804CBAA8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x804CBAAC: lui         $t9, 0x804D
    ctx->r25 = S32(RELOC_HI16(231, 0X1390) << 16);
    // 0x804CBAB0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804CBAB4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804CBAB8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804CBABC: lw          $t9, -0x4130($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(231, 0X1390));
    // 0x804CBAC0: jr          $ra
    // 0x804CBAC4: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    return;
    // 0x804CBAC4: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void gfxprint_puts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F97C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007F980: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007F984: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007F988: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007F98C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007F990: lbu         $s0, 0x0($a1)
    ctx->r16 = MEM_BU(ctx->r5, 0X0);
    // 0x8007F994: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007F998: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007F99C: beq         $s0, $zero, L_8007F9BC
    if (ctx->r16 == 0) {
        // 0x8007F9A0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007F9BC;
    }
    // 0x8007F9A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8007F9A4:
    // 0x8007F9A4: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8007F9A8: jal         0x8007F79C
    // 0x8007F9AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    gfxprint_putc(rdram, ctx);
        goto after_0;
    // 0x8007F9AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x8007F9B0: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x8007F9B4: bnel        $s0, $zero, L_8007F9A4
    if (ctx->r16 != 0) {
        // 0x8007F9B8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007F9A4;
    }
    goto skip_0;
    // 0x8007F9B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_8007F9BC:
    // 0x8007F9BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007F9C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007F9C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F9C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007F9CC: jr          $ra
    // 0x8007F9D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007F9D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000CE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000CE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000CE98: lbu         $t6, 0x80($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X80);
    // 0x8000CE9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000CEA0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x8000CEA4: beql        $t6, $zero, L_8000CEC0
    if (ctx->r14 == 0) {
        // 0x8000CEA8: lbu         $t7, 0xA0($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0XA0);
            goto L_8000CEC0;
    }
    goto skip_0;
    // 0x8000CEA8: lbu         $t7, 0xA0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA0);
    skip_0:
    // 0x8000CEAC: jal         0x8000CBFC
    // 0x8000CEB0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8000CBFC(rdram, ctx);
        goto after_0;
    // 0x8000CEB0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000CEB4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000CEB8: swc1        $f0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f0.u32l;
    // 0x8000CEBC: lbu         $t7, 0xA0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA0);
L_8000CEC0:
    // 0x8000CEC0: addiu       $a0, $a1, 0x8C
    ctx->r4 = ADD32(ctx->r5, 0X8C);
    // 0x8000CEC4: beql        $t7, $zero, L_8000CEE0
    if (ctx->r15 == 0) {
        // 0x8000CEC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000CEE0;
    }
    goto skip_1;
    // 0x8000CEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8000CECC: jal         0x8000CC9C
    // 0x8000CED0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8000CC9C(rdram, ctx);
        goto after_1;
    // 0x8000CED0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8000CED4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000CED8: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x8000CEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000CEE0:
    // 0x8000CEE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000CEE4: jr          $ra
    // 0x8000CEE8: nop

    return;
    // 0x8000CEE8: nop

;}
RECOMP_FUNC void func_80565074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80565074: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80565078: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8056507C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80565080: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80565084: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80565088: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8056508C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80565090: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80565094: bc1fl       L_805650C0
    if (!c1cs) {
        // 0x80565098: lwc1        $f0, 0x464($t9)
        ctx->f0.u32l = MEM_W(ctx->r25, 0X464);
            goto L_805650C0;
    }
    goto skip_0;
    // 0x80565098: lwc1        $f0, 0x464($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X464);
    skip_0:
    // 0x8056509C: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X25AC) << 16);
    // 0x805650A0: lwc1        $f6, 0x5E0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X25AC));
    // 0x805650A4: lwc1        $f4, 0x464($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X464);
    // 0x805650A8: swc1        $f2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f2.u32l;
    // 0x805650AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805650B0: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x805650B4: b           L_80565118
    // 0x805650B8: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
        goto L_80565118;
    // 0x805650B8: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x805650BC: lwc1        $f0, 0x464($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X464);
L_805650C0:
    // 0x805650C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805650C4: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X25B8) << 16);
    // 0x805650C8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x805650CC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x805650D0: nop

    // 0x805650D4: bc1fl       L_80565108
    if (!c1cs) {
        // 0x805650D8: sub.s       $f18, $f0, $f12
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_80565108;
    }
    goto skip_1;
    // 0x805650D8: sub.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f12.fl;
    skip_1:
    // 0x805650DC: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X25B0) << 16);
    // 0x805650E0: lwc1        $f4, 0x5E10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X25B0));
    // 0x805650E4: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X25B4) << 16);
    // 0x805650E8: lwc1        $f8, 0x5E14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X25B4));
    // 0x805650EC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x805650F0: swc1        $f2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f2.u32l;
    // 0x805650F4: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x805650F8: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x805650FC: b           L_80565118
    // 0x80565100: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
        goto L_80565118;
    // 0x80565100: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x80565104: sub.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f12.fl;
L_80565108:
    // 0x80565108: lwc1        $f4, 0x5E18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X25B8));
    // 0x8056510C: swc1        $f2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f2.u32l;
    // 0x80565110: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80565114: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_80565118:
    // 0x80565118: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8056511C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80565120: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80565124: jr          $ra
    // 0x80565128: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    return;
    // 0x80565128: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_80736D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80736D1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80736D20: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80736D24: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80736D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736D2C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80736D30: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80736D34: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80736D38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80736D3C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80736D40: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80736D44: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80736D48: lui         $t2, 0x8074
    ctx->r10 = S32(RELOC_HI16(736, 0X3994) << 16);
    // 0x80736D4C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80736D50: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80736D54: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80736D58: lw          $t2, -0x6C0C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(736, 0X3994));
    // 0x80736D5C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80736D60: jal         0x80736B70
    // 0x80736D64: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80736B70(rdram, ctx);
        goto after_0;
    // 0x80736D64: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x80736D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80736D70: jr          $ra
    // 0x80736D74: nop

    return;
    // 0x80736D74: nop

;}
RECOMP_FUNC void func_806ADD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ADD68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ADD6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ADD70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806ADD74: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x806ADD78: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806ADD7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806ADD80: beq         $a2, $at, L_806ADDB0
    if (ctx->r6 == ctx->r1) {
        // 0x806ADD84: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_806ADDB0;
    }
    // 0x806ADD84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806ADD88: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x806ADD8C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806ADD90: jal         0x80067930
    // 0x806ADD94: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x806ADD94: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x806ADD98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806ADD9C: bne         $v0, $at, L_806ADDB0
    if (ctx->r2 != ctx->r1) {
        // 0x806ADDA0: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_806ADDB0;
    }
    // 0x806ADDA0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806ADDA4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806ADDA8: jal         0x80067878
    // 0x806ADDAC: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x806ADDAC: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_1:
L_806ADDB0:
    // 0x806ADDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ADDB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ADDB8: jr          $ra
    // 0x806ADDBC: nop

    return;
    // 0x806ADDBC: nop

;}
RECOMP_FUNC void func_8044C948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C948: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044C94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044C950: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044C954: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8044C958: jal         0x80066E88
    // 0x8044C95C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8044C95C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8044C960: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8044C964: lwc1        $f12, 0x8($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8044C968: jal         0x80066DE4
    // 0x8044C96C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8044C96C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8044C970: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8044C974: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8044C978: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8044C97C: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x8044C980: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C984: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8044C988: swc1        $f14, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
    // 0x8044C98C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8044C990: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8044C994: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8044C998: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C99C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044C9A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044C9A4: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8044C9A8: swc1        $f14, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
    // 0x8044C9AC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8044C9B0: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8044C9B4: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x8044C9B8: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8044C9BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044C9C0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8044C9C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044C9C8: jr          $ra
    // 0x8044C9CC: nop

    return;
    // 0x8044C9CC: nop

;}
RECOMP_FUNC void func_8002FCBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FCBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FCC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FCC4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FCC8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FCCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FCD0: jal         0x8002F678
    // 0x8002FCD4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FCD4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FCD8: beq         $v0, $zero, L_8002FCEC
    if (ctx->r2 == 0) {
        // 0x8002FCDC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FCEC;
    }
    // 0x8002FCDC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FCE0: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FCE4: addiu       $t6, $t6, -0xA0C
    ctx->r14 = ADD32(ctx->r14, -0XA0C);
    // 0x8002FCE8: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FCEC:
    // 0x8002FCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FCF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FCF4: jr          $ra
    // 0x8002FCF8: nop

    return;
    // 0x8002FCF8: nop

;}
RECOMP_FUNC void func_8043A660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A660: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8043A664: addiu       $at, $zero, 0x40BE
    ctx->r1 = ADD32(0, 0X40BE);
    // 0x8043A668: beq         $v0, $at, L_8043A688
    if (ctx->r2 == ctx->r1) {
        // 0x8043A66C: addiu       $at, $zero, 0x40BF
        ctx->r1 = ADD32(0, 0X40BF);
            goto L_8043A688;
    }
    // 0x8043A66C: addiu       $at, $zero, 0x40BF
    ctx->r1 = ADD32(0, 0X40BF);
    // 0x8043A670: beq         $v0, $at, L_8043A694
    if (ctx->r2 == ctx->r1) {
        // 0x8043A674: addiu       $at, $zero, 0x40C0
        ctx->r1 = ADD32(0, 0X40C0);
            goto L_8043A694;
    }
    // 0x8043A674: addiu       $at, $zero, 0x40C0
    ctx->r1 = ADD32(0, 0X40C0);
    // 0x8043A678: beq         $v0, $at, L_8043A6A0
    if (ctx->r2 == ctx->r1) {
        // 0x8043A67C: nop
    
            goto L_8043A6A0;
    }
    // 0x8043A67C: nop

    // 0x8043A680: b           L_8043A6AC
    // 0x8043A684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043A6AC;
    // 0x8043A684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043A688:
    // 0x8043A688: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(83, 0X7C4) << 16);
    // 0x8043A68C: jr          $ra
    // 0x8043A690: addiu       $v0, $v0, -0x51DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(83, 0X7C4));
    return;
    // 0x8043A690: addiu       $v0, $v0, -0x51DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(83, 0X7C4));
L_8043A694:
    // 0x8043A694: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(83, 0XCBC) << 16);
    // 0x8043A698: jr          $ra
    // 0x8043A69C: addiu       $v0, $v0, -0x4CE4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(83, 0XCBC));
    return;
    // 0x8043A69C: addiu       $v0, $v0, -0x4CE4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(83, 0XCBC));
L_8043A6A0:
    // 0x8043A6A0: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(83, 0X1028) << 16);
    // 0x8043A6A4: jr          $ra
    // 0x8043A6A8: addiu       $v0, $v0, -0x4978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(83, 0X1028));
    return;
    // 0x8043A6A8: addiu       $v0, $v0, -0x4978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(83, 0X1028));
L_8043A6AC:
    // 0x8043A6AC: jr          $ra
    // 0x8043A6B0: nop

    return;
    // 0x8043A6B0: nop

;}
RECOMP_FUNC void func_807B0ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0ED4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x807B0ED8: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x807B0EDC: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x807B0EE0: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x807B0EE4: bgtz        $t8, L_807B0F0C
    if (SIGNED(ctx->r24) > 0) {
        // 0x807B0EE8: nop
    
            goto L_807B0F0C;
    }
    // 0x807B0EE8: nop

    // 0x807B0EEC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x807B0EF0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x807B0EF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x807B0EF8: bne         $v0, $at, L_807B0F08
    if (ctx->r2 != ctx->r1) {
        // 0x807B0EFC: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_807B0F08;
    }
    // 0x807B0EFC: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x807B0F00: jr          $ra
    // 0x807B0F04: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    return;
    // 0x807B0F04: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_807B0F08:
    // 0x807B0F08: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
L_807B0F0C:
    // 0x807B0F0C: jr          $ra
    // 0x807B0F10: nop

    return;
    // 0x807B0F10: nop

;}
RECOMP_FUNC void func_806D97BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D97BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D97C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D97C4: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806D97C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806D97CC: beq         $t6, $zero, L_806D9808
    if (ctx->r14 == 0) {
        // 0x806D97D0: nop
    
            goto L_806D9808;
    }
    // 0x806D97D0: nop

    // 0x806D97D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D97D8: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806D97DC: jalr        $t9
    // 0x806D97E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806D97E0: nop

    after_0:
    // 0x806D97E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D97E8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806D97EC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806D97F0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806D97F4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806D97F8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806D97FC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806D9800: b           L_806D9808
    // 0x806D9804: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806D9808;
    // 0x806D9804: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806D9808:
    // 0x806D9808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D980C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D9810: jr          $ra
    // 0x806D9814: nop

    return;
    // 0x806D9814: nop

;}
RECOMP_FUNC void func_805317EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805317EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805317F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805317F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805317F8: lwc1        $f6, 0x84($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X84);
    // 0x805317FC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80531800: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80531804: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80531808: jal         0x80065954
    // 0x8053180C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8053180C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80531810: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X19FC) << 16);
    // 0x80531814: lwc1        $f2, 0x27EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X19FC));
    // 0x80531818: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8053181C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80531820: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80531824: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80531828: bc1fl       L_80531840
    if (!c1cs) {
        // 0x8053182C: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80531840;
    }
    goto skip_0;
    // 0x8053182C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x80531830: lwc1        $f8, 0x84($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X84);
    // 0x80531834: b           L_80531870
    // 0x80531838: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
        goto L_80531870;
    // 0x80531838: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8053183C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80531840:
    // 0x80531840: nop

    // 0x80531844: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80531848: nop

    // 0x8053184C: bc1fl       L_80531868
    if (!c1cs) {
        // 0x80531850: lwc1        $f4, 0x3C($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_80531868;
    }
    goto skip_1;
    // 0x80531850: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    skip_1:
    // 0x80531854: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80531858: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8053185C: b           L_80531870
    // 0x80531860: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
        goto L_80531870;
    // 0x80531860: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80531864: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
L_80531868:
    // 0x80531868: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8053186C: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
L_80531870:
    // 0x80531870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80531874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80531878: jr          $ra
    // 0x8053187C: nop

    return;
    // 0x8053187C: nop

;}
RECOMP_FUNC void func_80708DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80708DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80708E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80708E04: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80708E08: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80708E0C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80708E10: sw          $zero, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = 0;
    // 0x80708E14: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x80708E18: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80708E1C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80708E20: jal         0x80048378
    // 0x80708E24: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80708E24: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x80708E28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80708E2C: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(715, 0X1C0) << 16);
    // 0x80708E30: addiu       $t6, $t6, -0x7120
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(715, 0X1C0));
    // 0x80708E34: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80708E38: jal         0x80708D70
    // 0x80708E3C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    func_80708D70(rdram, ctx);
        goto after_1;
    // 0x80708E3C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_1:
    // 0x80708E40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80708E44: jal         0x80708E6C
    // 0x80708E48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80708E6C(rdram, ctx);
        goto after_2;
    // 0x80708E48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80708E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80708E50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80708E54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80708E58: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x80708E5C: jr          $ra
    // 0x80708E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80708E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80427F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427F60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427F64: jal         0x800610A0
    // 0x80427F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800610A0(rdram, ctx);
        goto after_0;
    // 0x80427F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80427F6C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80427F70: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80427F74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80427F78: lui         $a1, 0x8043
    ctx->r5 = S32(RELOC_HI16(41, 0X1DAC) << 16);
    // 0x80427F7C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80427F80: addiu       $a1, $a1, -0x6914
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(41, 0X1DAC));
    // 0x80427F84: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80427F88: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80427F8C: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x80427F90: jalr        $t9
    // 0x80427F94: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80427F94: nop

    after_1:
    // 0x80427F98: jal         0x80427994
    // 0x80427F9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80427994(rdram, ctx);
        goto after_2;
    // 0x80427F9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80427FA0: jal         0x80048D4C
    // 0x80427FA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80048D4C(rdram, ctx);
        goto after_3;
    // 0x80427FA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80427FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427FB0: jr          $ra
    // 0x80427FB4: nop

    return;
    // 0x80427FB4: nop

;}
RECOMP_FUNC void func_80581AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581AEC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80581AF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80581AF4: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(399, 0X4674) << 16);
    // 0x80581AF8: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80581AFC: addiu       $t7, $t7, 0x3484
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(399, 0X4674));
    // 0x80581B00: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80581B04: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80581B08: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80581B0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80581B10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581B14: jal         0x80581AA4
    // 0x80581B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80581AA4(rdram, ctx);
        goto after_0;
    // 0x80581B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80581B1C: jal         0x80581A68
    // 0x80581B20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80581A68(rdram, ctx);
        goto after_1;
    // 0x80581B20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80581B24: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80581B28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80581B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581B30: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x80581B34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80581B38: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80581B3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80581B40: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80581B44: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80581B48: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x80581B4C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80581B50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80581B54: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80581B58: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x80581B5C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80581B60: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80581B64: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80581B68: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x80581B6C: sb          $t9, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r25;
    // 0x80581B70: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x80581B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581B7C: jr          $ra
    // 0x80581B80: nop

    return;
    // 0x80581B80: nop

;}
RECOMP_FUNC void func_805D886C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D886C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D8870: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D8874: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D8878: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D887C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805D8880: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x805D8884: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x805D8888: beq         $v0, $zero, L_805D8894
    if (ctx->r2 == 0) {
        // 0x805D888C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_805D8894;
    }
    // 0x805D888C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x805D8890: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
L_805D8894:
    // 0x805D8894: jal         0x805D81A8
    // 0x805D8898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D81A8(rdram, ctx);
        goto after_0;
    // 0x805D8898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x805D889C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805D88A0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805D88A4: jal         0x80048F84
    // 0x805D88A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x805D88A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x805D88AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805D88B0: jal         0x80048F84
    // 0x805D88B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805D88B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805D88B8: jal         0x805D87D0
    // 0x805D88BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D87D0(rdram, ctx);
        goto after_3;
    // 0x805D88BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805D88C0: jal         0x805D8804
    // 0x805D88C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D8804(rdram, ctx);
        goto after_4;
    // 0x805D88C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805D88C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x805D88CC: jal         0x805D86B0
    // 0x805D88D0: lw          $a1, 0xE0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XE0);
    func_805D86B0(rdram, ctx);
        goto after_5;
    // 0x805D88D0: lw          $a1, 0xE0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XE0);
    after_5:
    // 0x805D88D4: jal         0x805D8370
    // 0x805D88D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D8370(rdram, ctx);
        goto after_6;
    // 0x805D88D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805D88DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D88E0: jal         0x805D84A4
    // 0x805D88E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_805D84A4(rdram, ctx);
        goto after_7;
    // 0x805D88E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x805D88E8: jal         0x805D83E8
    // 0x805D88EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D83E8(rdram, ctx);
        goto after_8;
    // 0x805D88EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x805D88F0: beql        $v0, $zero, L_805D8934
    if (ctx->r2 == 0) {
        // 0x805D88F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D8934;
    }
    goto skip_0;
    // 0x805D88F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805D88F8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805D88FC: jal         0x80067BBC
    // 0x805D8900: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_9;
    // 0x805D8900: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_9:
    // 0x805D8904: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x805D8908: jal         0x80011D1C
    // 0x805D890C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80011D1C(rdram, ctx);
        goto after_10;
    // 0x805D890C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x805D8910: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x805D8914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D8918: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D891C: sw          $zero, 0x18($t8)
    MEM_W(0X18, ctx->r24) = 0;
    // 0x805D8920: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x805D8924: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x805D8928: jal         0x805D8AB4
    // 0x805D892C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_805D8AB4(rdram, ctx);
        goto after_11;
    // 0x805D892C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x805D8930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D8934:
    // 0x805D8934: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D8938: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D893C: jr          $ra
    // 0x805D8940: nop

    return;
    // 0x805D8940: nop

;}
RECOMP_FUNC void func_807A14EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A14EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A14F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A14F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A14F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A14FC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x807A1500: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807A1504: jal         0x807A0FFC
    // 0x807A1508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A0FFC(rdram, ctx);
        goto after_0;
    // 0x807A1508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807A150C: lw          $t6, 0x1E4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E4);
    // 0x807A1510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A1514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A1518: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807A151C: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x807A1520: bne         $at, $zero, L_807A1538
    if (ctx->r1 != 0) {
        // 0x807A1524: sw          $t7, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r15;
            goto L_807A1538;
    }
    // 0x807A1524: sw          $t7, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r15;
    // 0x807A1528: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x807A152C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807A1530: jal         0x807A1AE4
    // 0x807A1534: lw          $a3, 0x68($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X68);
    func_807A1AE4(rdram, ctx);
        goto after_1;
    // 0x807A1534: lw          $a3, 0x68($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X68);
    after_1:
L_807A1538:
    // 0x807A1538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807A153C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A1540: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A1544: jr          $ra
    // 0x807A1548: nop

    return;
    // 0x807A1548: nop

;}
RECOMP_FUNC void func_807BBDAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BBDAC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x807BBDB0: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(898, 0X6EA4) << 16);
    // 0x807BBDB4: lwc1        $f0, 0x2B64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(898, 0X6EA4));
    // 0x807BBDB8: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x807BBDBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807BBDC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807BBDC4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807BBDC8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807BBDCC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807BBDD0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807BBDD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807BBDD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807BBDDC: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x807BBDE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807BBDE4: lui         $s2, 0x807C
    ctx->r18 = S32(RELOC_HI16(898, 0X6DC0) << 16);
    // 0x807BBDE8: lui         $s3, 0x807C
    ctx->r19 = S32(RELOC_HI16(898, 0X6DE0) << 16);
    // 0x807BBDEC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x807BBDF0: addiu       $s2, $s2, 0x2A80
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(898, 0X6DC0));
    // 0x807BBDF4: addiu       $s3, $s3, 0x2AA0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(898, 0X6DE0));
    // 0x807BBDF8: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x807BBDFC: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x807BBE00: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x807BBE04: jal         0x807BBEFC
    // 0x807BBE08: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    func_807BBEFC(rdram, ctx);
        goto after_0;
    // 0x807BBE08: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x807BBE0C: beq         $v0, $zero, L_807BBED0
    if (ctx->r2 == 0) {
        // 0x807BBE10: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_807BBED0;
    }
    // 0x807BBE10: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x807BBE14: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x807BBE18: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x807BBE1C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807BBE20: sw          $t6, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r14;
    // 0x807BBE24: sb          $t7, 0x165($s4)
    MEM_B(0X165, ctx->r20) = ctx->r15;
    // 0x807BBE28: sw          $zero, 0x1E0($s4)
    MEM_W(0X1E0, ctx->r20) = 0;
    // 0x807BBE2C: sw          $zero, 0x138($s4)
    MEM_W(0X138, ctx->r20) = 0;
    // 0x807BBE30: sh          $v0, 0x13C($s4)
    MEM_H(0X13C, ctx->r20) = ctx->r2;
    // 0x807BBE34: sh          $v0, 0x13E($s4)
    MEM_H(0X13E, ctx->r20) = ctx->r2;
    // 0x807BBE38: sw          $zero, 0x24($s4)
    MEM_W(0X24, ctx->r20) = 0;
    // 0x807BBE3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807BBE40: jal         0x800461F4
    // 0x807BBE44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800461F4(rdram, ctx);
        goto after_1;
    // 0x807BBE44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x807BBE48: jal         0x807BBF44
    // 0x807BBE4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_807BBF44(rdram, ctx);
        goto after_2;
    // 0x807BBE4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x807BBE50: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807BBE54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BBE58: jal         0x807BC4D4
    // 0x807BBE5C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807BC4D4(rdram, ctx);
        goto after_3;
    // 0x807BBE5C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x807BBE60: lw          $s0, 0x1F4($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X1F4);
    // 0x807BBE64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807BBE68: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x807BBE6C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
L_807BBE70:
    // 0x807BBE70: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807BBE74: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x807BBE78: jal         0x807BC7C4
    // 0x807BBE7C: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    func_807BC7C4(rdram, ctx);
        goto after_4;
    // 0x807BBE7C: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    after_4:
    // 0x807BBE80: bne         $v0, $zero, L_807BBE98
    if (ctx->r2 != 0) {
        // 0x807BBE84: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_807BBE98;
    }
    // 0x807BBE84: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x807BBE88: jal         0x800445A4
    // 0x807BBE8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x807BBE8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x807BBE90: b           L_807BBEDC
    // 0x807BBE94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_807BBEDC;
    // 0x807BBE94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807BBE98:
    // 0x807BBE98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x807BBE9C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x807BBEA0: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x807BBEA4: bne         $s1, $s5, L_807BBE70
    if (ctx->r17 != ctx->r21) {
        // 0x807BBEA8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_807BBE70;
    }
    // 0x807BBEA8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x807BBEAC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x807BBEB0: jal         0x807BBF84
    // 0x807BBEB4: addiu       $a1, $s4, 0x6C
    ctx->r5 = ADD32(ctx->r20, 0X6C);
    func_807BBF84(rdram, ctx);
        goto after_6;
    // 0x807BBEB4: addiu       $a1, $s4, 0x6C
    ctx->r5 = ADD32(ctx->r20, 0X6C);
    after_6:
    // 0x807BBEB8: jal         0x807BBD18
    // 0x807BBEBC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_807BBD18(rdram, ctx);
        goto after_7;
    // 0x807BBEBC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x807BBEC0: jal         0x800677F8
    // 0x807BBEC4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_800677F8(rdram, ctx);
        goto after_8;
    // 0x807BBEC4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_8:
    // 0x807BBEC8: b           L_807BBEDC
    // 0x807BBECC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_807BBEDC;
    // 0x807BBECC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807BBED0:
    // 0x807BBED0: jal         0x800445A4
    // 0x807BBED4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x807BBED4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
    // 0x807BBED8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807BBEDC:
    // 0x807BBEDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807BBEE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807BBEE4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807BBEE8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807BBEEC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807BBEF0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807BBEF4: jr          $ra
    // 0x807BBEF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x807BBEF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8002C784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C78C: jal         0x8002C74C
    // 0x8002C790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002C74C(rdram, ctx);
        goto after_0;
    // 0x8002C790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C794: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8002C798: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002C79C: sw          $t6, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r14;
    // 0x8002C7A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C7A8: jr          $ra
    // 0x8002C7AC: nop

    return;
    // 0x8002C7AC: nop

;}
RECOMP_FUNC void func_8042C428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C428: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042C42C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042C430: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8042C434: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8042C438: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042C43C: jal         0x8004700C
    // 0x8042C440: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8042C440: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8042C444: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8042C448: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042C44C: jal         0x8006CB1C
    // 0x8042C450: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8006CB1C(rdram, ctx);
        goto after_1;
    // 0x8042C450: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8042C454: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8042C458: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042C45C: jal         0x8006CB2C
    // 0x8042C460: nop

    func_8006CB2C(rdram, ctx);
        goto after_2;
    // 0x8042C460: nop

    after_2:
    // 0x8042C464: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x8042C468: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042C46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C470: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x8042C474: jal         0x8042BD04
    // 0x8042C478: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    func_8042BD04(rdram, ctx);
        goto after_3;
    // 0x8042C478: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    after_3:
    // 0x8042C47C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042C480: jal         0x8042A9DC
    // 0x8042C484: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_8042A9DC(rdram, ctx);
        goto after_4;
    // 0x8042C484: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x8042C488: jal         0x8042BB3C
    // 0x8042C48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BB3C(rdram, ctx);
        goto after_5;
    // 0x8042C48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8042C490: jal         0x8042BA84
    // 0x8042C494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BA84(rdram, ctx);
        goto after_6;
    // 0x8042C494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8042C498: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C49C: bnel        $v0, $zero, L_8042C4B4
    if (ctx->r2 != 0) {
        // 0x8042C4A0: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_8042C4B4;
    }
    goto skip_0;
    // 0x8042C4A0: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    skip_0:
    // 0x8042C4A4: jal         0x8042C1D8
    // 0x8042C4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042C1D8(rdram, ctx);
        goto after_7;
    // 0x8042C4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8042C4AC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C4B0: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
L_8042C4B4:
    // 0x8042C4B4: bnel        $v0, $at, L_8042C4D4
    if (ctx->r2 != ctx->r1) {
        // 0x8042C4B8: slti        $at, $v0, 0x12C
        ctx->r1 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
            goto L_8042C4D4;
    }
    goto skip_1;
    // 0x8042C4B8: slti        $at, $v0, 0x12C
    ctx->r1 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    skip_1:
    // 0x8042C4BC: jal         0x8042C1D8
    // 0x8042C4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042C1D8(rdram, ctx);
        goto after_8;
    // 0x8042C4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8042C4C4: jal         0x8042BF3C
    // 0x8042C4C8: nop

    func_8042BF3C(rdram, ctx);
        goto after_9;
    // 0x8042C4C8: nop

    after_9:
    // 0x8042C4CC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C4D0: slti        $at, $v0, 0x12C
    ctx->r1 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
L_8042C4D4:
    // 0x8042C4D4: bnel        $at, $zero, L_8042C5EC
    if (ctx->r1 != 0) {
        // 0x8042C4D8: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8042C5EC;
    }
    goto skip_2;
    // 0x8042C4D8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8042C4DC: jal         0x800653D8
    // 0x8042C4E0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    func_800653D8(rdram, ctx);
        goto after_10;
    // 0x8042C4E0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    after_10:
    // 0x8042C4E4: andi        $t7, $v0, 0xC
    ctx->r15 = ctx->r2 & 0XC;
    // 0x8042C4E8: beq         $t7, $zero, L_8042C580
    if (ctx->r15 == 0) {
        // 0x8042C4EC: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_8042C580;
    }
    // 0x8042C4EC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8042C4F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042C4F4: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8042C4F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8042C4FC: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x8042C500: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8042C504: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042C508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C50C: lwc1        $f10, 0x3C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x8042C510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C514: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8042C518: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8042C51C: nop

    // 0x8042C520: bc1fl       L_8042C540
    if (!c1cs) {
        // 0x8042C524: lui         $at, 0x42C0
        ctx->r1 = S32(0X42C0 << 16);
            goto L_8042C540;
    }
    goto skip_3;
    // 0x8042C524: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    skip_3:
    // 0x8042C528: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8042C52C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042C530: nop

    // 0x8042C534: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8042C538: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x8042C53C: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
L_8042C540:
    // 0x8042C540: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042C544: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x8042C548: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042C54C: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8042C550: bne         $t9, $at, L_8042C570
    if (ctx->r25 != ctx->r1) {
        // 0x8042C554: nop
    
            goto L_8042C570;
    }
    // 0x8042C554: nop

    // 0x8042C558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C55C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C560: jal         0x8042D50C
    // 0x8042C564: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_8042D50C(rdram, ctx);
        goto after_11;
    // 0x8042C564: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_11:
    // 0x8042C568: b           L_8042C578
    // 0x8042C56C: nop

        goto L_8042C578;
    // 0x8042C56C: nop

L_8042C570:
    // 0x8042C570: jal         0x8042D50C
    // 0x8042C574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_12;
    // 0x8042C574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
L_8042C578:
    // 0x8042C578: b           L_8042C5E8
    // 0x8042C57C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
        goto L_8042C5E8;
    // 0x8042C57C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8042C580:
    // 0x8042C580: jal         0x800653D8
    // 0x8042C584: nop

    func_800653D8(rdram, ctx);
        goto after_13;
    // 0x8042C584: nop

    after_13:
    // 0x8042C588: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8042C58C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8042C590: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8042C594: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042C598: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8042C59C: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x8042C5A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042C5A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042C5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C5AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C5B0: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8042C5B4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8042C5B8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8042C5BC: bne         $t1, $at, L_8042C5DC
    if (ctx->r9 != ctx->r1) {
        // 0x8042C5C0: swc1        $f18, 0x10($s1)
        MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
            goto L_8042C5DC;
    }
    // 0x8042C5C0: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8042C5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C5C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C5CC: jal         0x8042D50C
    // 0x8042C5D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8042D50C(rdram, ctx);
        goto after_14;
    // 0x8042C5D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_14:
    // 0x8042C5D4: b           L_8042C5E8
    // 0x8042C5D8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
        goto L_8042C5E8;
    // 0x8042C5D8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8042C5DC:
    // 0x8042C5DC: jal         0x8042D50C
    // 0x8042C5E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_15;
    // 0x8042C5E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x8042C5E4: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8042C5E8:
    // 0x8042C5E8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
L_8042C5EC:
    // 0x8042C5EC: sw          $t2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r10;
    // 0x8042C5F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042C5F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8042C5F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8042C5FC: jr          $ra
    // 0x8042C600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8042C600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80075830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075830: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80075834: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80075838: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8007583C: addiu       $a3, $a3, -0x7AF0
    ctx->r7 = ADD32(ctx->r7, -0X7AF0);
    // 0x80075840: addiu       $v1, $v1, -0x260C
    ctx->r3 = ADD32(ctx->r3, -0X260C);
    // 0x80075844: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80075848: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007584C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80075850: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80075854: lw          $t9, 0x68($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X68);
    // 0x80075858: sw          $t9, 0xB0($t6)
    MEM_W(0XB0, ctx->r14) = ctx->r25;
    // 0x8007585C: lw          $t8, 0x6C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X6C);
    // 0x80075860: sw          $t8, 0xB4($t6)
    MEM_W(0XB4, ctx->r14) = ctx->r24;
    // 0x80075864: lw          $t9, 0x70($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X70);
    // 0x80075868: sw          $t9, 0xB8($t6)
    MEM_W(0XB8, ctx->r14) = ctx->r25;
    // 0x8007586C: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80075870: sw          $t8, 0xBC($t6)
    MEM_W(0XBC, ctx->r14) = ctx->r24;
    // 0x80075874: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80075878: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8007587C: addiu       $at, $t7, 0x3C
    ctx->r1 = ADD32(ctx->r15, 0X3C);
L_80075880:
    // 0x80075880: lw          $t9, 0x20($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X20);
    // 0x80075884: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80075888: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8007588C: sw          $t9, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r25;
    // 0x80075890: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80075894: sw          $t8, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r24;
    // 0x80075898: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8007589C: bne         $t7, $at, L_80075880
    if (ctx->r15 != ctx->r1) {
        // 0x800758A0: sw          $t9, 0x6C($t6)
        MEM_W(0X6C, ctx->r14) = ctx->r25;
            goto L_80075880;
    }
    // 0x800758A0: sw          $t9, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->r25;
    // 0x800758A4: lw          $t9, 0x20($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X20);
    // 0x800758A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800758AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800758B0: sw          $t9, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->r25;
    // 0x800758B4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800758B8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800758BC: lui         $a2, 0xE700
    ctx->r6 = S32(0XE700 << 16);
    // 0x800758C0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800758C4: lui         $t0, 0xB800
    ctx->r8 = S32(0XB800 << 16);
    // 0x800758C8: lui         $t4, 0xED00
    ctx->r12 = S32(0XED00 << 16);
    // 0x800758CC: sw          $t9, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r25;
    // 0x800758D0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800758D4: sw          $t8, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r24;
    // 0x800758D8: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800758DC: sw          $t9, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r25;
    // 0x800758E0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x800758E4: sw          $t8, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r24;
    // 0x800758E8: lw          $t9, 0x14($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X14);
    // 0x800758EC: sw          $t9, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r25;
    // 0x800758F0: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800758F4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800758F8: lwl         $t9, 0x18($t6)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r14, 0X18);
    // 0x800758FC: lwr         $t9, 0x1B($t6)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r14, 0X1B);
    // 0x80075900: swl         $t9, 0x24($t7)
    do_swl(rdram, 0X24, ctx->r15, ctx->r25);
    // 0x80075904: swr         $t9, 0x27($t7)
    do_swr(rdram, 0X27, ctx->r15, ctx->r25);
    // 0x80075908: lwl         $t8, 0x1C($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X1C);
    // 0x8007590C: lwr         $t8, 0x1F($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X1F);
    // 0x80075910: swl         $t8, 0x28($t7)
    do_swl(rdram, 0X28, ctx->r15, ctx->r24);
    // 0x80075914: swr         $t8, 0x2B($t7)
    do_swr(rdram, 0X2B, ctx->r15, ctx->r24);
    // 0x80075918: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007591C: addiu       $v0, $v0, 0x180
    ctx->r2 = ADD32(ctx->r2, 0X180);
    // 0x80075920: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075924: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x80075928: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007592C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075930: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80075934: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80075938: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007593C: lhu         $t7, 0x24($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X24);
    // 0x80075940: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80075944: bgez        $t7, L_8007595C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80075948: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8007595C;
    }
    // 0x80075948: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007594C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80075950: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80075954: nop

    // 0x80075958: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8007595C:
    // 0x8007595C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80075960: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80075964: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80075968: nop

    // 0x8007596C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80075970: lhu         $t8, 0x26($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X26);
    // 0x80075974: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80075978: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x8007597C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80075980: bgez        $t8, L_80075998
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80075984: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80075998;
    }
    // 0x80075984: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80075988: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007598C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80075990: nop

    // 0x80075994: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80075998:
    // 0x80075998: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8007599C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800759A0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800759A4: nop

    // 0x800759A8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800759AC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800759B0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800759B4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800759B8: lhu         $t7, 0x28($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X28);
    // 0x800759BC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800759C0: bgez        $t7, L_800759D8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800759C4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800759D8;
    }
    // 0x800759C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800759C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800759CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800759D0: nop

    // 0x800759D4: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_800759D8:
    // 0x800759D8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800759DC: lhu         $t6, 0x2A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2A);
    // 0x800759E0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800759E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800759E8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800759EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800759F0: nop

    // 0x800759F4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800759F8: bgez        $t6, L_80075A10
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800759FC: sll         $t7, $t9, 12
        ctx->r15 = S32(ctx->r25 << 12);
            goto L_80075A10;
    }
    // 0x800759FC: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80075A00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80075A04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80075A08: nop

    // 0x80075A0C: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_80075A10:
    // 0x80075A10: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80075A14: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80075A18: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80075A1C: nop

    // 0x80075A20: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80075A24: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80075A28: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x80075A2C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80075A30: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80075A34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80075A38: addiu       $v0, $v0, 0x198
    ctx->r2 = ADD32(ctx->r2, 0X198);
    // 0x80075A3C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80075A40: sw          $a2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r6;
    // 0x80075A44: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80075A48: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075A4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075A50: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80075A54: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80075A58: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075A5C: lhu         $t9, 0x12($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X12);
    // 0x80075A60: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80075A64: bgez        $t9, L_80075A7C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80075A68: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80075A7C;
    }
    // 0x80075A68: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80075A6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80075A70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80075A74: nop

    // 0x80075A78: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_80075A7C:
    // 0x80075A7C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80075A80: lhu         $t7, 0x14($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X14);
    // 0x80075A84: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80075A88: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80075A8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80075A90: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80075A94: nop

    // 0x80075A98: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80075A9C: bgez        $t7, L_80075AB4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80075AA0: sll         $t9, $t8, 12
        ctx->r25 = S32(ctx->r24 << 12);
            goto L_80075AB4;
    }
    // 0x80075AA0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80075AA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80075AA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80075AAC: nop

    // 0x80075AB0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80075AB4:
    // 0x80075AB4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80075AB8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80075ABC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80075AC0: nop

    // 0x80075AC4: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80075AC8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80075ACC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80075AD0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80075AD4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80075AD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80075ADC: lui         $t8, 0xFE00
    ctx->r24 = S32(0XFE00 << 16);
    // 0x80075AE0: lui         $t9, 0xE00
    ctx->r25 = S32(0XE00 << 16);
    // 0x80075AE4: addiu       $v0, $v0, 0x168
    ctx->r2 = ADD32(ctx->r2, 0X168);
    // 0x80075AE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075AEC: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x80075AF0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80075AF4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075AF8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80075AFC: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x80075B00: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80075B04: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80075B08: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075B0C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80075B10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80075B14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80075B18: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80075B1C: addiu       $t4, $t4, -0x5028
    ctx->r12 = ADD32(ctx->r12, -0X5028);
    // 0x80075B20: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, 0X150);
    // 0x80075B24: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80075B28: sw          $a2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r6;
    // 0x80075B2C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80075B30: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075B34: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80075B38: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80075B3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80075B40: lbu         $t7, 0x10($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X10);
    // 0x80075B44: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075B48: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80075B4C: andi        $t6, $t7, 0x7
    ctx->r14 = ctx->r15 & 0X7;
    // 0x80075B50: lbu         $t7, 0x11($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X11);
    // 0x80075B54: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x80075B58: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80075B5C: andi        $t6, $t7, 0x3
    ctx->r14 = ctx->r15 & 0X3;
    // 0x80075B60: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80075B64: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    // 0x80075B68: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80075B6C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80075B70: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80075B74: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80075B78: lui         $t9, 0xF00
    ctx->r25 = S32(0XF00 << 16);
    // 0x80075B7C: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x80075B80: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80075B84: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80075B88: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80075B8C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80075B90: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80075B94: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80075B98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80075B9C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80075BA0: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x80075BA4: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x80075BA8: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80075BAC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80075BB0: sw          $t8, -0x4FEC($at)
    MEM_W(-0X4FEC, ctx->r1) = ctx->r24;
    // 0x80075BB4: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80075BB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80075BBC: lui         $a1, 0xBC00
    ctx->r5 = S32(0XBC00 << 16);
    // 0x80075BC0: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x80075BC4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80075BC8: sw          $t9, -0x4FF0($at)
    MEM_W(-0X4FF0, ctx->r1) = ctx->r25;
    // 0x80075BCC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80075BD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80075BD4: addu        $t7, $a0, $at
    ctx->r15 = ADD32(ctx->r4, ctx->r1);
    // 0x80075BD8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80075BDC: sw          $t7, -0x4FF4($at)
    MEM_W(-0X4FF4, ctx->r1) = ctx->r15;
    // 0x80075BE0: addiu       $v0, $a0, 0xC0
    ctx->r2 = ADD32(ctx->r4, 0XC0);
    // 0x80075BE4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80075BE8: sw          $a2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r6;
    // 0x80075BEC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80075BF0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075BF4: addiu       $t1, $zero, 0x4C
    ctx->r9 = ADD32(0, 0X4C);
L_80075BF8:
    // 0x80075BF8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80075BFC: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80075C00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80075C04: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80075C08: sw          $t8, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->r24;
    // 0x80075C0C: andi        $t7, $t3, 0xFFFF
    ctx->r15 = ctx->r11 & 0XFFFF;
    // 0x80075C10: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80075C14: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x80075C18: ori         $t9, $t8, 0x6
    ctx->r25 = ctx->r24 | 0X6;
    // 0x80075C1C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80075C20: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80075C24: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075C28: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80075C2C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80075C30: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x80075C34: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x80075C38: addu        $t9, $t8, $t3
    ctx->r25 = ADD32(ctx->r24, ctx->r11);
    // 0x80075C3C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80075C40: sw          $t6, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r14;
    // 0x80075C44: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x80075C48: ori         $t9, $t6, 0x6
    ctx->r25 = ctx->r14 | 0X6;
    // 0x80075C4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80075C50: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80075C54: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80075C58: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075C5C: addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // 0x80075C60: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80075C64: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80075C68: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x80075C6C: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x80075C70: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80075C74: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80075C78: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x80075C7C: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x80075C80: ori         $t9, $t8, 0x6
    ctx->r25 = ctx->r24 | 0X6;
    // 0x80075C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80075C88: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80075C8C: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x80075C90: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075C94: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80075C98: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80075C9C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80075CA0: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x80075CA4: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x80075CA8: addu        $t9, $t8, $t3
    ctx->r25 = ADD32(ctx->r24, ctx->r11);
    // 0x80075CAC: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80075CB0: sw          $t6, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r14;
    // 0x80075CB4: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x80075CB8: ori         $t9, $t6, 0x6
    ctx->r25 = ctx->r14 | 0X6;
    // 0x80075CBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80075CC0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80075CC4: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x80075CC8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80075CCC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075CD0: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x80075CD4: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, 0X10);
    // 0x80075CD8: bne         $s1, $t1, L_80075BF8
    if (ctx->r17 != ctx->r9) {
        // 0x80075CDC: sw          $t7, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r15;
            goto L_80075BF8;
    }
    // 0x80075CDC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80075CE0: lui         $t5, 0xF600
    ctx->r13 = S32(0XF600 << 16);
    // 0x80075CE4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80075CE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80075CEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80075CF0: addiu       $v0, $v0, 0x1C8
    ctx->r2 = ADD32(ctx->r2, 0X1C8);
    // 0x80075CF4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80075CF8: sw          $a2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r6;
    // 0x80075CFC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80075D00: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075D04: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80075D08: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80075D0C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075D10: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x80075D14: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x80075D18: lhu         $t8, 0x8($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X8);
    // 0x80075D1C: sll         $t9, $t6, 14
    ctx->r25 = S32(ctx->r14 << 14);
    // 0x80075D20: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80075D24: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x80075D28: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80075D2C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80075D30: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80075D34: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80075D38: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80075D3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80075D40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80075D44: addiu       $v0, $v0, 0x1B0
    ctx->r2 = ADD32(ctx->r2, 0X1B0);
    // 0x80075D48: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x80075D4C: sw          $a2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r6;
    // 0x80075D50: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80075D54: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075D58: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80075D5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80075D60: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075D64: lhu         $t6, 0x6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X6);
    // 0x80075D68: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80075D6C: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x80075D70: lhu         $t7, 0x8($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X8);
    // 0x80075D74: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x80075D78: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80075D7C: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80075D80: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x80075D84: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80075D88: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80075D8C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80075D90: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80075D94: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80075D98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80075D9C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80075DA0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80075DA4: jr          $ra
    // 0x80075DA8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80075DA8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80791330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791330: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80791334: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80791338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079133C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80791340: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80791344: jal         0x807903C4
    // 0x80791348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80791348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8079134C: jal         0x80790714
    // 0x80791350: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80791350: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80791354: beq         $v0, $zero, L_80791370
    if (ctx->r2 == 0) {
        // 0x80791358: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80791370;
    }
    // 0x80791358: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8079135C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80791360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791364: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80791368: jal         0x8079393C
    // 0x8079136C: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x8079136C: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    after_2:
L_80791370:
    // 0x80791370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80791374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80791378: jr          $ra
    // 0x8079137C: nop

    return;
    // 0x8079137C: nop

;}
RECOMP_FUNC void func_80080EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080EE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80080EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080EE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80080EEC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80080EF0: jal         0x80082730
    // 0x80080EF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fsin(rdram, ctx);
        goto after_0;
    // 0x80080EF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80080EF8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80080EFC: jal         0x8008D250
    // 0x80080F00: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80080F00: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80080F04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80080F08: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80080F0C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80080F10: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80080F14: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080F18: nop

    // 0x80080F1C: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80080F20: nop

    // 0x80080F24: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080F28: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80080F2C: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80080F30: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80080F34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080F38: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080F3C: nop

    // 0x80080F40: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80080F44: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80080F48: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080F4C: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080F50: lwc1        $f2, 0x28($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80080F54: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80080F58: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80080F5C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080F60: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080F64: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80080F68: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80080F6C: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80080F70: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080F74: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080F78: lwc1        $f2, 0x38($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80080F7C: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80080F80: lwc1        $f12, 0x30($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80080F84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080F88: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080F8C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80080F90: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80080F94: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x80080F98: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080F9C: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080FA0: nop

    // 0x80080FA4: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80080FA8: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x80080FAC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080FB0: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x80080FB4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080FB8: swc1        $f18, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f18.u32l;
    // 0x80080FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080FC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80080FC4: jr          $ra
    // 0x80080FC8: nop

    return;
    // 0x80080FC8: nop

;}
RECOMP_FUNC void func_8044641C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044641C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446420: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446424: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446428: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8044642C: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x80446430: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446434: sw          $t7, 0x6CAC($at)
    MEM_W(0X6CAC, ctx->r1) = ctx->r15;
    // 0x80446438: jr          $ra
    // 0x8044643C: sw          $zero, 0x220($v0)
    MEM_W(0X220, ctx->r2) = 0;
    return;
    // 0x8044643C: sw          $zero, 0x220($v0)
    MEM_W(0X220, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80475EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475EA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475EAC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475EB0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475EB4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475EB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475EBC: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26E38) << 16);
    // 0x80475EC0: addiu       $a2, $a2, -0x4A08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26E38));
    // 0x80475EC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80475EC8: jal         0x80475B40
    // 0x80475ECC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475ECC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475ED8: jr          $ra
    // 0x80475EDC: nop

    return;
    // 0x80475EDC: nop

;}
RECOMP_FUNC void func_807BAC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAC0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BAC10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BAC14: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x807BAC18: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x807BAC1C: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x807BAC20: slti        $at, $v1, 0xF5
    ctx->r1 = SIGNED(ctx->r3) < 0XF5 ? 1 : 0;
    // 0x807BAC24: beq         $at, $zero, L_807BAC4C
    if (ctx->r1 == 0) {
        // 0x807BAC28: addiu       $t6, $v1, 0xA
        ctx->r14 = ADD32(ctx->r3, 0XA);
            goto L_807BAC4C;
    }
    // 0x807BAC28: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x807BAC2C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x807BAC30: slti        $at, $t7, 0xF5
    ctx->r1 = SIGNED(ctx->r15) < 0XF5 ? 1 : 0;
    // 0x807BAC34: bne         $at, $zero, L_807BAC4C
    if (ctx->r1 != 0) {
        // 0x807BAC38: sb          $t6, 0x3($v0)
        MEM_B(0X3, ctx->r2) = ctx->r14;
            goto L_807BAC4C;
    }
    // 0x807BAC38: sb          $t6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r14;
    // 0x807BAC3C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x807BAC40: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
    // 0x807BAC44: jal         0x807BA9E8
    // 0x807BAC48: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    func_807BA9E8(rdram, ctx);
        goto after_0;
    // 0x807BAC48: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    after_0:
L_807BAC4C:
    // 0x807BAC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BAC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BAC54: jr          $ra
    // 0x807BAC58: nop

    return;
    // 0x807BAC58: nop

;}
RECOMP_FUNC void func_80034160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034160: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034164: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80034168: sb          $zero, 0xF5($v0)
    MEM_B(0XF5, ctx->r2) = 0;
    // 0x8003416C: jr          $ra
    // 0x80034170: sb          $t6, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = ctx->r14;
    return;
    // 0x80034170: sb          $t6, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_806FD700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD708: jal         0x80058B44
    // 0x806FD70C: addiu       $a0, $zero, 0x4602
    ctx->r4 = ADD32(0, 0X4602);
    func_80058B44(rdram, ctx);
        goto after_0;
    // 0x806FD70C: addiu       $a0, $zero, 0x4602
    ctx->r4 = ADD32(0, 0X4602);
    after_0:
    // 0x806FD710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD718: jr          $ra
    // 0x806FD71C: nop

    return;
    // 0x806FD71C: nop

;}
RECOMP_FUNC void func_80522218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522218: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8052221C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80522220: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80522224: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(318, 0XA8) << 16);
    // 0x80522228: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8052222C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80522230: lw          $t8, 0x2248($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(318, 0XA8));
    // 0x80522234: jr          $ra
    // 0x80522238: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80522238: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8052223C: nop

;}
RECOMP_FUNC void func_804B6400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6400: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x804B6404: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x804B6408: lw          $a1, 0x40($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X40);
    // 0x804B640C: lbu         $t7, 0x14($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X14);
    // 0x804B6410: beql        $t7, $zero, L_804B649C
    if (ctx->r15 == 0) {
        // 0x804B6414: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804B649C;
    }
    goto skip_0;
    // 0x804B6414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x804B6418: lbu         $t8, 0x2C($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2C);
    // 0x804B641C: beql        $t8, $zero, L_804B649C
    if (ctx->r24 == 0) {
        // 0x804B6420: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804B649C;
    }
    goto skip_1;
    // 0x804B6420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x804B6424: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x804B6428: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x804B642C: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x804B6430: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x804B6434: lbu         $v0, 0x19($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X19);
    // 0x804B6438: beq         $v0, $at, L_804B6478
    if (ctx->r2 == ctx->r1) {
        // 0x804B643C: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_804B6478;
    }
    // 0x804B643C: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x804B6440: beq         $v0, $at, L_804B6478
    if (ctx->r2 == ctx->r1) {
        // 0x804B6444: addiu       $at, $zero, 0x56
        ctx->r1 = ADD32(0, 0X56);
            goto L_804B6478;
    }
    // 0x804B6444: addiu       $at, $zero, 0x56
    ctx->r1 = ADD32(0, 0X56);
    // 0x804B6448: beq         $v0, $at, L_804B645C
    if (ctx->r2 == ctx->r1) {
        // 0x804B644C: addiu       $v1, $a0, 0xC4
        ctx->r3 = ADD32(ctx->r4, 0XC4);
            goto L_804B645C;
    }
    // 0x804B644C: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x804B6450: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x804B6454: bnel        $v0, $at, L_804B649C
    if (ctx->r2 != ctx->r1) {
        // 0x804B6458: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804B649C;
    }
    goto skip_2;
    // 0x804B6458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
L_804B645C:
    // 0x804B645C: lw          $t1, 0x68($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X68);
    // 0x804B6460: bnel        $t1, $zero, L_804B649C
    if (ctx->r9 != 0) {
        // 0x804B6464: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804B649C;
    }
    goto skip_3;
    // 0x804B6464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x804B6468: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804B646C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804B6470: jr          $ra
    // 0x804B6474: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x804B6474: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_804B6478:
    // 0x804B6478: lw          $t2, 0x68($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X68);
    // 0x804B647C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804B6480: bnel        $t2, $at, L_804B649C
    if (ctx->r10 != ctx->r1) {
        // 0x804B6484: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804B649C;
    }
    goto skip_4;
    // 0x804B6484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x804B6488: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804B648C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804B6490: jr          $ra
    // 0x804B6494: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    return;
    // 0x804B6494: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x804B6498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804B649C:
    // 0x804B649C: jr          $ra
    // 0x804B64A0: nop

    return;
    // 0x804B64A0: nop

;}
RECOMP_FUNC void func_80069CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069CA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80069CA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069CA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069CAC: lhu         $t6, 0x18($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X18);
    // 0x80069CB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80069CB4: beq         $a0, $zero, L_80069D2C
    if (ctx->r4 == 0) {
        // 0x80069CB8: sh          $t6, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r14;
            goto L_80069D2C;
    }
    // 0x80069CB8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x80069CBC: jal         0x80069E18
    // 0x80069CC0: nop

    func_80069E18(rdram, ctx);
        goto after_0;
    // 0x80069CC0: nop

    after_0:
    // 0x80069CC4: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x80069CC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069CCC: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x80069CD0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80069CD4: bne         $t9, $at, L_80069CEC
    if (ctx->r25 != ctx->r1) {
        // 0x80069CD8: sw          $t9, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r25;
            goto L_80069CEC;
    }
    // 0x80069CD8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80069CDC: jal         0x80050AFC
    // 0x80069CE0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    func_80050AFC(rdram, ctx);
        goto after_1;
    // 0x80069CE0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    after_1:
    // 0x80069CE4: b           L_80069D10
    // 0x80069CE8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_80069D10;
    // 0x80069CE8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_80069CEC:
    // 0x80069CEC: jal         0x80064E84
    // 0x80069CF0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x80069CF0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x80069CF4: jal         0x80064E84
    // 0x80069CF8: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x80069CF8: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    after_3:
    // 0x80069CFC: jal         0x80064E84
    // 0x80069D00: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    func_80064E84(rdram, ctx);
        goto after_4;
    // 0x80069D00: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_4:
    // 0x80069D04: jal         0x80064E84
    // 0x80069D08: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    func_80064E84(rdram, ctx);
        goto after_5;
    // 0x80069D08: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    after_5:
    // 0x80069D0C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_80069D10:
    // 0x80069D10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069D14: bne         $t0, $at, L_80069D24
    if (ctx->r8 != ctx->r1) {
        // 0x80069D18: nop
    
            goto L_80069D24;
    }
    // 0x80069D18: nop

    // 0x80069D1C: jal         0x8005BA40
    // 0x80069D20: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_8005BA40(rdram, ctx);
        goto after_6;
    // 0x80069D20: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_6:
L_80069D24:
    // 0x80069D24: jal         0x80064E84
    // 0x80069D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064E84(rdram, ctx);
        goto after_7;
    // 0x80069D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80069D2C:
    // 0x80069D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80069D30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069D34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80069D38: jr          $ra
    // 0x80069D3C: nop

    return;
    // 0x80069D3C: nop

;}
RECOMP_FUNC void func_80567C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567C4C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80567C50: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x80567C54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80567C58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80567C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80567C60: bne         $t6, $zero, L_80567CEC
    if (ctx->r14 != 0) {
        // 0x80567C64: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80567CEC;
    }
    // 0x80567C64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80567C68: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80567C6C: addiu       $at, $zero, 0x4668
    ctx->r1 = ADD32(0, 0X4668);
    // 0x80567C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80567C74: beq         $v0, $at, L_80567C84
    if (ctx->r2 == ctx->r1) {
        // 0x80567C78: addiu       $at, $zero, 0x4669
        ctx->r1 = ADD32(0, 0X4669);
            goto L_80567C84;
    }
    // 0x80567C78: addiu       $at, $zero, 0x4669
    ctx->r1 = ADD32(0, 0X4669);
    // 0x80567C7C: bnel        $v0, $at, L_80567CF0
    if (ctx->r2 != ctx->r1) {
        // 0x80567C80: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80567CF0;
    }
    goto skip_0;
    // 0x80567C80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80567C84:
    // 0x80567C84: jal         0x80569310
    // 0x80567C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80569310(rdram, ctx);
        goto after_0;
    // 0x80567C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80567C8C: jal         0x8004700C
    // 0x80567C90: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x80567C90: nop

    after_1:
    // 0x80567C94: beql        $v0, $zero, L_80567CB4
    if (ctx->r2 == 0) {
        // 0x80567C98: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80567CB4;
    }
    goto skip_1;
    // 0x80567C98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_1:
    // 0x80567C9C: lw          $t7, 0x180($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X180);
    // 0x80567CA0: bnel        $s0, $t7, L_80567CB4
    if (ctx->r16 != ctx->r15) {
        // 0x80567CA4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80567CB4;
    }
    goto skip_2;
    // 0x80567CA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_2:
    // 0x80567CA8: jal         0x80060FE0
    // 0x80567CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060FE0(rdram, ctx);
        goto after_2;
    // 0x80567CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80567CB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80567CB4:
    // 0x80567CB4: sb          $t8, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r24;
    // 0x80567CB8: jal         0x8005FE48
    // 0x80567CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x80567CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80567CC0: jal         0x80567AC4
    // 0x80567CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80567AC4(rdram, ctx);
        goto after_4;
    // 0x80567CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80567CC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80567CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80567CD0: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x80567CD4: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x80567CD8: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x80567CDC: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80567CE0: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x80567CE4: b           L_80567CF0
    // 0x80567CE8: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
        goto L_80567CF0;
    // 0x80567CE8: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
L_80567CEC:
    // 0x80567CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80567CF0:
    // 0x80567CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80567CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80567CF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80567CFC: jr          $ra
    // 0x80567D00: nop

    return;
    // 0x80567D00: nop

;}
RECOMP_FUNC void func_8078EE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EE50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078EE54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078EE58: jal         0x8078EC68
    // 0x8078EE5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8078EC68(rdram, ctx);
        goto after_0;
    // 0x8078EE5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078EE60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078EE64: beq         $v0, $zero, L_8078EE8C
    if (ctx->r2 == 0) {
        // 0x8078EE68: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078EE8C;
    }
    // 0x8078EE68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8078EE6C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8078EE70: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x8078EE74: bnel        $t6, $zero, L_8078EE98
    if (ctx->r14 != 0) {
        // 0x8078EE78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078EE98;
    }
    goto skip_0;
    // 0x8078EE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8078EE7C: jal         0x8078ED54
    // 0x8078EE80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8078ED54(rdram, ctx);
        goto after_1;
    // 0x8078EE80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8078EE84: b           L_8078EE98
    // 0x8078EE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078EE98;
    // 0x8078EE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078EE8C:
    // 0x8078EE8C: jal         0x800447C8
    // 0x8078EE90: nop

    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8078EE90: nop

    after_2:
    // 0x8078EE94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078EE98:
    // 0x8078EE98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078EE9C: jr          $ra
    // 0x8078EEA0: nop

    return;
    // 0x8078EEA0: nop

;}
RECOMP_FUNC void func_8042C3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C3A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042C3A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8042C3A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042C3AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042C3B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042C3B4: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x8042C3B8: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8042C3BC: jal         0x8042BFF4
    // 0x8042C3C0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    func_8042BFF4(rdram, ctx);
        goto after_0;
    // 0x8042C3C0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x8042C3C4: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C3C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8042C3CC: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8042C3D0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8042C3D4: slti        $at, $t7, 0x79
    ctx->r1 = SIGNED(ctx->r15) < 0X79 ? 1 : 0;
    // 0x8042C3D8: bne         $at, $zero, L_8042C414
    if (ctx->r1 != 0) {
        // 0x8042C3DC: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_8042C414;
    }
    // 0x8042C3DC: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x8042C3E0: jal         0x800677F8
    // 0x8042C3E4: sb          $t9, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r25;
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x8042C3E4: sb          $t9, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r25;
    after_1:
    // 0x8042C3E8: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8042C3EC: lw          $t9, -0x7288($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7288);
    // 0x8042C3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C3F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C3F8: jalr        $t9
    // 0x8042C3FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8042C3FC: nop

    after_2:
    // 0x8042C400: lui         $t0, 0x8043
    ctx->r8 = S32(RELOC_HI16(50, 0X1AB8) << 16);
    // 0x8042C404: addiu       $t0, $t0, -0x3CA8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(50, 0X1AB8));
    // 0x8042C408: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x8042C40C: jal         0x8006CAE0
    // 0x8042C410: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8006CAE0(rdram, ctx);
        goto after_3;
    // 0x8042C410: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_8042C414:
    // 0x8042C414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042C418: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042C41C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042C420: jr          $ra
    // 0x8042C424: nop

    return;
    // 0x8042C424: nop

;}
RECOMP_FUNC void func_807378E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807378E8: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x807378EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807378F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807378F4: bne         $t6, $zero, L_80737920
    if (ctx->r14 != 0) {
        // 0x807378F8: addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
            goto L_80737920;
    }
    // 0x807378F8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x807378FC: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B80) << 16);
    // 0x80737900: lwc1        $f0, -0x6A20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B80));
    // 0x80737904: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80737908: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8073790C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80737910: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80737914: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80737918: b           L_80737940
    // 0x8073791C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
        goto L_80737940;
    // 0x8073791C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
L_80737920:
    // 0x80737920: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B84) << 16);
    // 0x80737924: lwc1        $f0, -0x6A1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B84));
    // 0x80737928: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8073792C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80737930: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80737934: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80737938: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8073793C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
L_80737940:
    // 0x80737940: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B88) << 16);
    // 0x80737944: lwc1        $f18, -0x6A18($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B88));
    // 0x80737948: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B8C) << 16);
    // 0x8073794C: lwc1        $f16, -0x6A14($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B8C));
    // 0x80737950: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B90) << 16);
    // 0x80737954: lwc1        $f14, -0x6A10($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B90));
    // 0x80737958: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B94) << 16);
    // 0x8073795C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80737960: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80737964: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80737968: lwc1        $f12, -0x6A0C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B94));
    // 0x8073796C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80737970: addiu       $t0, $a0, 0xC4
    ctx->r8 = ADD32(ctx->r4, 0XC4);
L_80737974:
    // 0x80737974: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80737978: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8073797C: lwc1        $f10, 0x28($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X28);
    // 0x80737980: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80737984: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80737988: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8073798C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80737990: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80737994: swc1        $f4, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80737998: lwc1        $f0, -0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8073799C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807379A0: nop

    // 0x807379A4: bc1f        L_807379CC
    if (!c1cs) {
        // 0x807379A8: nop
    
            goto L_807379CC;
    }
    // 0x807379A8: nop

    // 0x807379AC: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x807379B0: nop

    // 0x807379B4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x807379B8: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x807379BC: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x807379C0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x807379C4: b           L_807379EC
    // 0x807379C8: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
        goto L_807379EC;
    // 0x807379C8: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
L_807379CC:
    // 0x807379CC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x807379D0: nop

    // 0x807379D4: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x807379D8: nop

    // 0x807379DC: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x807379E0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x807379E4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x807379E8: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
L_807379EC:
    // 0x807379EC: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x807379F0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x807379F4: nop

    // 0x807379F8: bc1fl       L_80737A0C
    if (!c1cs) {
        // 0x807379FC: c.lt.s      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
            goto L_80737A0C;
    }
    goto skip_0;
    // 0x807379FC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    skip_0:
    // 0x80737A00: b           L_80737A1C
    // 0x80737A04: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
        goto L_80737A1C;
    // 0x80737A04: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80737A08: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
L_80737A0C:
    // 0x80737A0C: nop

    // 0x80737A10: bc1f        L_80737A1C
    if (!c1cs) {
        // 0x80737A14: nop
    
            goto L_80737A1C;
    }
    // 0x80737A14: nop

    // 0x80737A18: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
L_80737A1C:
    // 0x80737A1C: bne         $a3, $v0, L_80737974
    if (ctx->r7 != ctx->r2) {
        // 0x80737A20: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80737974;
    }
    // 0x80737A20: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80737A24: jr          $ra
    // 0x80737A28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80737A28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804627A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804627A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804627A8: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x804627AC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804627B0: lwc1        $f6, 0x3C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x804627B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804627B8: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x804627BC: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804627C0: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x804627C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804627C8: jr          $ra
    // 0x804627CC: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x804627CC: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8078A81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A81C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078A820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078A824: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8078A828: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078A82C: lwc1        $f0, 0x268($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X268);
    // 0x8078A830: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8078A834: jal         0x8004700C
    // 0x8078A838: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078A838: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8078A83C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8078A840: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8078A844: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDE4) << 16);
    // 0x8078A848: lwc1        $f2, -0x4FDC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDE4));
    // 0x8078A84C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8078A850: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8078A854: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078A858: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8078A85C: nop

    // 0x8078A860: bc1fl       L_8078A874
    if (!c1cs) {
        // 0x8078A864: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8078A874;
    }
    goto skip_0;
    // 0x8078A864: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8078A868: b           L_8078A88C
    // 0x8078A86C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8078A88C;
    // 0x8078A86C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8078A870: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8078A874:
    // 0x8078A874: nop

    // 0x8078A878: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8078A87C: nop

    // 0x8078A880: bc1f        L_8078A88C
    if (!c1cs) {
        // 0x8078A884: nop
    
            goto L_8078A88C;
    }
    // 0x8078A884: nop

    // 0x8078A888: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8078A88C:
    // 0x8078A88C: beq         $v0, $zero, L_8078A8A0
    if (ctx->r2 == 0) {
        // 0x8078A890: swc1        $f0, 0x268($v1)
        MEM_W(0X268, ctx->r3) = ctx->f0.u32l;
            goto L_8078A8A0;
    }
    // 0x8078A890: swc1        $f0, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->f0.u32l;
    // 0x8078A894: lwc1        $f6, 0x7C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x8078A898: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8078A89C: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
L_8078A8A0:
    // 0x8078A8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078A8A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078A8A8: jr          $ra
    // 0x8078A8AC: nop

    return;
    // 0x8078A8AC: nop

;}
