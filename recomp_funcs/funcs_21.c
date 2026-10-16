#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80787FAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80787FAC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80787FB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80787FB4: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80787FB8: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x80787FBC: lw          $v0, 0xED0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XED0);
    // 0x80787FC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80787FC4: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80787FC8: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x80787FCC: beql        $v1, $zero, L_807880B8
    if (ctx->r3 == 0) {
        // 0x80787FD0: lhu         $t4, 0x52F0($a3)
        ctx->r12 = MEM_HU(ctx->r7, 0X52F0);
            goto L_807880B8;
    }
    goto skip_0;
    // 0x80787FD0: lhu         $t4, 0x52F0($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X52F0);
    skip_0:
    // 0x80787FD4: lh          $a0, 0x52C6($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X52C6);
    // 0x80787FD8: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x80787FDC: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    // 0x80787FE0: bnel        $t6, $a0, L_807880B8
    if (ctx->r14 != ctx->r4) {
        // 0x80787FE4: lhu         $t4, 0x52F0($a3)
        ctx->r12 = MEM_HU(ctx->r7, 0X52F0);
            goto L_807880B8;
    }
    goto skip_1;
    // 0x80787FE4: lhu         $t4, 0x52F0($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X52F0);
    skip_1:
    // 0x80787FE8: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    // 0x80787FEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80787FF0: jal         0x807880F0
    // 0x80787FF4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_807880F0(rdram, ctx);
        goto after_0;
    // 0x80787FF4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80787FF8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80787FFC: lw          $t7, 0xED0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XED0);
    // 0x80788000: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80788004: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    // 0x80788008: lh          $a0, 0x52C6($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X52C6);
    // 0x8078800C: jal         0x807881AC
    // 0x80788010: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    func_807881AC(rdram, ctx);
        goto after_1;
    // 0x80788010: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    after_1:
    // 0x80788014: lw          $t8, 0xED0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XED0);
    // 0x80788018: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8078801C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80788020: lwc1        $f4, 0x28($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X28);
    // 0x80788024: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80788028: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8078802C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80788030: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x80788034: lw          $t9, 0xED0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XED0);
    // 0x80788038: lwc1        $f10, 0x2C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x8078803C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80788040: swc1        $f16, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f16.u32l;
    // 0x80788044: lw          $t0, 0xED0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XED0);
    // 0x80788048: lwc1        $f2, 0x2C($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x8078804C: sub.s       $f12, $f2, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80788050: jal         0x80065954
    // 0x80788054: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80788054: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80788058: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078805C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80788060: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80788064: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80788068: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8078806C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80788070: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80788074: bc1fl       L_80788090
    if (!c1cs) {
        // 0x80788078: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80788090;
    }
    goto skip_2;
    // 0x80788078: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_2:
    // 0x8078807C: lw          $t1, 0xED0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XED0);
    // 0x80788080: swc1        $f14, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->f14.u32l;
    // 0x80788084: b           L_807880B4
    // 0x80788088: lw          $v0, 0xED0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XED0);
        goto L_807880B4;
    // 0x80788088: lw          $v0, 0xED0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XED0);
    // 0x8078808C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80788090:
    // 0x80788090: nop

    // 0x80788094: bc1fl       L_807880A8
    if (!c1cs) {
        // 0x80788098: add.s       $f2, $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
            goto L_807880A8;
    }
    goto skip_3;
    // 0x80788098: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    skip_3:
    // 0x8078809C: b           L_807880A8
    // 0x807880A0: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
        goto L_807880A8;
    // 0x807880A0: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x807880A4: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
L_807880A8:
    // 0x807880A8: lw          $t2, 0xED0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XED0);
    // 0x807880AC: swc1        $f2, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->f2.u32l;
    // 0x807880B0: lw          $v0, 0xED0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XED0);
L_807880B4:
    // 0x807880B4: lhu         $t4, 0x52F0($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X52F0);
L_807880B8:
    // 0x807880B8: lh          $a0, 0x52C6($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X52C6);
    // 0x807880BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807880C0: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x807880C4: beq         $t5, $zero, L_807880D8
    if (ctx->r13 == 0) {
        // 0x807880C8: addu        $t8, $v0, $a0
        ctx->r24 = ADD32(ctx->r2, ctx->r4);
            goto L_807880D8;
    }
    // 0x807880C8: addu        $t8, $v0, $a0
    ctx->r24 = ADD32(ctx->r2, ctx->r4);
    // 0x807880CC: addu        $t7, $v0, $a0
    ctx->r15 = ADD32(ctx->r2, ctx->r4);
    // 0x807880D0: b           L_807880DC
    // 0x807880D4: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
        goto L_807880DC;
    // 0x807880D4: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
L_807880D8:
    // 0x807880D8: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
L_807880DC:
    // 0x807880DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807880E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807880E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807880E8: jr          $ra
    // 0x807880EC: nop

    return;
    // 0x807880EC: nop

;}
RECOMP_FUNC void func_80536144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536144: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536148: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053614C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536150: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536154: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536158: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053615C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536160: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536164: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536168: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053616C: jr          $ra
    // 0x80536170: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536170: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805D3650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3650: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805D3654: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D3658: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D365C: jal         0x805D32D4
    // 0x805D3660: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_805D32D4(rdram, ctx);
        goto after_0;
    // 0x805D3660: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805D3664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D3668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D366C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x805D3670: jal         0x805D3B18
    // 0x805D3674: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D3674: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D3678: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805D367C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805D3680: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X255C) << 16);
    // 0x805D3684: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805D3688: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805D368C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x805D3690: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x805D3694: lwc1        $f4, 0x3F8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X255C));
    // 0x805D3698: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805D369C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x805D36A0: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x805D36A4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x805D36A8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x805D36AC: lw          $t9, 0x88($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X88);
    // 0x805D36B0: jalr        $t9
    // 0x805D36B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x805D36B4: nop

    after_2:
    // 0x805D36B8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805D36BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D36C0: beq         $v0, $zero, L_805D3714
    if (ctx->r2 == 0) {
        // 0x805D36C4: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_805D3714;
    }
    // 0x805D36C4: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x805D36C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805D36CC: jal         0x80047F9C
    // 0x805D36D0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x805D36D0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x805D36D4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805D36D8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x805D36DC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x805D36E0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x805D36E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805D36E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x805D36EC: sb          $t8, 0x17C($t0)
    MEM_B(0X17C, ctx->r8) = ctx->r24;
    // 0x805D36F0: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x805D36F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D36F8: swc1        $f6, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f6.u32l;
    // 0x805D36FC: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x805D3700: swc1        $f8, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f8.u32l;
    // 0x805D3704: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x805D3708: lw          $t4, 0x174($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X174);
    // 0x805D370C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x805D3710: sw          $zero, 0x44($t5)
    MEM_W(0X44, ctx->r13) = 0;
L_805D3714:
    // 0x805D3714: lw          $t6, 0x168($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X168);
    // 0x805D3718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D371C: lw          $v0, 0x88($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X88);
    // 0x805D3720: jal         0x8004590C
    // 0x805D3724: addiu       $a1, $v0, 0xA00
    ctx->r5 = ADD32(ctx->r2, 0XA00);
    func_8004590C(rdram, ctx);
        goto after_4;
    // 0x805D3724: addiu       $a1, $v0, 0xA00
    ctx->r5 = ADD32(ctx->r2, 0XA00);
    after_4:
    // 0x805D3728: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x805D372C: addiu       $t8, $zero, 0x55
    ctx->r24 = ADD32(0, 0X55);
    // 0x805D3730: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x805D3734: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x805D3738: sh          $zero, 0x18($t9)
    MEM_H(0X18, ctx->r25) = 0;
    // 0x805D373C: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x805D3740: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x805D3744: sh          $t8, 0x1A($t1)
    MEM_H(0X1A, ctx->r9) = ctx->r24;
    // 0x805D3748: sw          $t2, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r10;
    // 0x805D374C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805D3750: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D3754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805D3758: jr          $ra
    // 0x805D375C: nop

    return;
    // 0x805D375C: nop

;}
RECOMP_FUNC void func_8040ED0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040ED0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040ED10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040ED14: jal         0x8004700C
    // 0x8040ED18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8040ED18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040ED1C: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x8040ED20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040ED24: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8040ED28: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8040ED2C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8040ED30: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8040ED34: lh          $t8, 0x52($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X52);
    // 0x8040ED38: lw          $t7, 0x70($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X70);
    // 0x8040ED3C: lh          $t9, 0xC($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XC);
    // 0x8040ED40: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8040ED44: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8040ED48: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040ED4C: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8040ED50: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8040ED54: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8040ED58: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8040ED5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8040ED60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040ED64: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8040ED68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8040ED6C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8040ED70: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8040ED74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8040ED78: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040ED7C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8040ED80: add.s       $f14, $f8, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8040ED84: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8040ED88: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8040ED8C: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8040ED90: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8040ED94: nop

    // 0x8040ED98: bc1f        L_8040EDA8
    if (!c1cs) {
        // 0x8040ED9C: nop
    
            goto L_8040EDA8;
    }
    // 0x8040ED9C: nop

    // 0x8040EDA0: b           L_8040EDA8
    // 0x8040EDA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8040EDA8;
    // 0x8040EDA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8040EDA8:
    // 0x8040EDA8: jr          $ra
    // 0x8040EDAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8040EDAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8046C850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046C854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046C858: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8046C85C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8046C860: beql        $t6, $zero, L_8046C8BC
    if (ctx->r14 == 0) {
        // 0x8046C864: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046C8BC;
    }
    goto skip_0;
    // 0x8046C864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046C868: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8046C86C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8046C870: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8046C874: jalr        $t9
    // 0x8046C878: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8046C878: nop

    after_0:
    // 0x8046C87C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8046C880: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8046C884: bne         $v0, $at, L_8046C890
    if (ctx->r2 != ctx->r1) {
        // 0x8046C888: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8046C890;
    }
    // 0x8046C888: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8046C88C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8046C890:
    // 0x8046C890: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8046C894: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8046C898: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8046C89C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8046C8A0: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8046C8A4: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8046C8A8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x8046C8AC: jal         0x8046C78C
    // 0x8046C8B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8046C78C(rdram, ctx);
        goto after_1;
    // 0x8046C8B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8046C8B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8046C8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046C8BC:
    // 0x8046C8BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046C8C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8046C8C4: jr          $ra
    // 0x8046C8C8: nop

    return;
    // 0x8046C8C8: nop

;}
RECOMP_FUNC void func_804F59B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F59B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F59B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804F59BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804F59C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F59C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F59C8: lui         $v1, 0x8051
    ctx->r3 = S32(RELOC_HI16(273, 0X205FC) << 16);
    // 0x804F59CC: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x804F59D0: addiu       $v1, $v1, 0x488C
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(273, 0X205FC));
    // 0x804F59D4: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x804F59D8: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804F59DC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x804F59E0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x804F59E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F59E8: jal         0x804F5CE8
    // 0x804F59EC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_804F5CE8(rdram, ctx);
        goto after_0;
    // 0x804F59EC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x804F59F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F59F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F59F8: jr          $ra
    // 0x804F59FC: nop

    return;
    // 0x804F59FC: nop

;}
RECOMP_FUNC void func_8052FB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052FB04: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8052FB08: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(333, 0X1BC0) << 16);
    // 0x8052FB0C: addiu       $t6, $t6, -0x680
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(333, 0X1BC0));
    // 0x8052FB10: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8052FB14: jr          $ra
    // 0x8052FB18: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8052FB18: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8045FD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FD80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045FD84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045FD88: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8045FD8C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8045FD90: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8045FD94: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(116, 0X378) << 16);
    // 0x8045FD98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8045FD9C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8045FDA0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8045FDA4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8045FDA8: lw          $t8, 0x48($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(116, 0X378));
    // 0x8045FDAC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8045FDB0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8045FDB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045FDB8: jal         0x80048490
    // 0x8045FDBC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8045FDBC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8045FDC0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8045FDC4: jal         0x80048378
    // 0x8045FDC8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8045FDC8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8045FDCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045FDD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045FDD4: jr          $ra
    // 0x8045FDD8: nop

    return;
    // 0x8045FDD8: nop

;}
RECOMP_FUNC void func_8070D158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070D158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8070D15C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070D160: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070D164: jal         0x8070D100
    // 0x8070D168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8070D100(rdram, ctx);
        goto after_0;
    // 0x8070D168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8070D16C: beq         $v0, $zero, L_8070D1F4
    if (ctx->r2 == 0) {
        // 0x8070D170: lui         $at, 0x8071
        ctx->r1 = S32(RELOC_HI16(721, 0XD84) << 16);
            goto L_8070D1F4;
    }
    // 0x8070D170: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD84) << 16);
    // 0x8070D174: lwc1        $f0, -0x2BEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD84));
    // 0x8070D178: lui         $at, 0xC228
    ctx->r1 = S32(0XC228 << 16);
    // 0x8070D17C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8070D180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070D184: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8070D188: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8070D18C: jal         0x8070C934
    // 0x8070D190: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    func_8070C934(rdram, ctx);
        goto after_1;
    // 0x8070D190: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8070D194: jal         0x8005FD1C
    // 0x8070D198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x8070D198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8070D19C: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8070D1A0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8070D1A4: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8070D1A8: lui         $t7, 0x8071
    ctx->r15 = S32(RELOC_HI16(721, 0XCB4) << 16);
    // 0x8070D1AC: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8070D1B0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8070D1B4: addiu       $t7, $t7, -0x2CBC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(721, 0XCB4));
    // 0x8070D1B8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8070D1BC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8070D1C0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8070D1C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070D1C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070D1CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8070D1D0: jal         0x8070D208
    // 0x8070D1D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8070D208(rdram, ctx);
        goto after_3;
    // 0x8070D1D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8070D1D8: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8070D1DC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8070D1E0: jal         0x80067BBC
    // 0x8070D1E4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x8070D1E4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8070D1E8: addiu       $a0, $zero, 0x22E
    ctx->r4 = ADD32(0, 0X22E);
    // 0x8070D1EC: jal         0x80067818
    // 0x8070D1F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8070D1F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
L_8070D1F4:
    // 0x8070D1F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8070D1F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8070D1FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8070D200: jr          $ra
    // 0x8070D204: nop

    return;
    // 0x8070D204: nop

;}
RECOMP_FUNC void func_8042F63C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F63C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F644: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042F648: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8042F64C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X37F0) << 16);
    // 0x8042F650: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042F654: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042F658: lw          $t8, 0x18D0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X37F0));
    // 0x8042F65C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042F660: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8042F664: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8042F668: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8042F66C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042F670: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8042F674: beql        $v1, $zero, L_8042F6A8
    if (ctx->r3 == 0) {
        // 0x8042F678: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042F6A8;
    }
    goto skip_0;
    // 0x8042F678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042F67C: jalr        $v1
    // 0x8042F680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042F680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042F684: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042F688: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8042F68C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042F690: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8042F694: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8042F698: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8042F69C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042F6A0: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8042F6A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042F6A8:
    // 0x8042F6A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F6AC: jr          $ra
    // 0x8042F6B0: nop

    return;
    // 0x8042F6B0: nop

;}
RECOMP_FUNC void func_807AC414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AC418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AC41C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807AC420: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807AC424: lui         $t7, 0x807B
    ctx->r15 = S32(RELOC_HI16(856, 0XAB0) << 16);
    // 0x807AC428: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807AC42C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807AC430: addiu       $t7, $t7, -0x3B00
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(856, 0XAB0));
    // 0x807AC434: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807AC438: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807AC43C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AC440: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807AC444: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807AC448: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807AC44C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x807AC450: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x807AC454: jal         0x80048378
    // 0x807AC458: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x807AC458: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x807AC45C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AC460: jal         0x80045A34
    // 0x807AC464: addiu       $a1, $zero, 0x798
    ctx->r5 = ADD32(0, 0X798);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x807AC464: addiu       $a1, $zero, 0x798
    ctx->r5 = ADD32(0, 0X798);
    after_1:
    // 0x807AC468: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AC46C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807AC470: jal         0x807AC1A8
    // 0x807AC474: sh          $zero, 0x794($v0)
    MEM_H(0X794, ctx->r2) = 0;
    func_807AC1A8(rdram, ctx);
        goto after_2;
    // 0x807AC474: sh          $zero, 0x794($v0)
    MEM_H(0X794, ctx->r2) = 0;
    after_2:
    // 0x807AC478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AC47C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AC480: jr          $ra
    // 0x807AC484: nop

    return;
    // 0x807AC484: nop

;}
RECOMP_FUNC void func_80457020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80457020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80457024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80457028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045702C: jal         0x80456D98
    // 0x80457030: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80456D98(rdram, ctx);
        goto after_0;
    // 0x80457030: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80457034: jal         0x80455948
    // 0x80457038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455948(rdram, ctx);
        goto after_1;
    // 0x80457038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8045703C: jal         0x80455770
    // 0x80457040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455770(rdram, ctx);
        goto after_2;
    // 0x80457040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80457044: jal         0x80455864
    // 0x80457048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455864(rdram, ctx);
        goto after_3;
    // 0x80457048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8045704C: jal         0x8044FD5C
    // 0x80457050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_4;
    // 0x80457050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80457054: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80457058: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045705C: jal         0x80450490
    // 0x80457060: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_5;
    // 0x80457060: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_5:
    // 0x80457064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80457068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045706C: jal         0x80457164
    // 0x80457070: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80457164(rdram, ctx);
        goto after_6;
    // 0x80457070: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_6:
    // 0x80457074: jal         0x804503B4
    // 0x80457078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804503B4(rdram, ctx);
        goto after_7;
    // 0x80457078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8045707C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80457080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80457084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80457088: jr          $ra
    // 0x8045708C: nop

    return;
    // 0x8045708C: nop

;}
RECOMP_FUNC void func_8057C1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C1AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8057C1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C1B4: lw          $a1, 0x1E0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1E0);
    // 0x8057C1B8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8057C1BC: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(387, 0XF70) << 16);
    // 0x8057C1C0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8057C1C4: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    // 0x8057C1C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8057C1CC: lwc1        $f4, -0x3580($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(387, 0XF70));
    // 0x8057C1D0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(387, 0XE98) << 16);
    // 0x8057C1D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057C1D8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8057C1DC: lwc1        $f6, -0x3658($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(387, 0XE98));
    // 0x8057C1E0: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8057C1E4: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(387, 0XF80) << 16);
    // 0x8057C1E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8057C1EC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8057C1F0: lwc1        $f6, -0x3570($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(387, 0XF80));
    // 0x8057C1F4: lwc1        $f4, 0x70($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8057C1F8: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8057C1FC: lwc1        $f14, 0x40($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8057C200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8057C204: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8057C208: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8057C20C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8057C210: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8057C214: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8057C218: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x8057C21C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8057C220: sub.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8057C224: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8057C228: jal         0x80065954
    // 0x8057C22C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8057C22C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8057C230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8057C234: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8057C238: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8057C23C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8057C240: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8057C244: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8057C248: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057C24C: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8057C250: bc1f        L_8057C284
    if (!c1cs) {
        // 0x8057C254: lwc1        $f16, 0x34($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8057C284;
    }
    // 0x8057C254: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8057C258: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8057C25C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8057C260: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8057C264: nop

    // 0x8057C268: bc1fl       L_8057C27C
    if (!c1cs) {
        // 0x8057C26C: sub.s       $f2, $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
            goto L_8057C27C;
    }
    goto skip_0;
    // 0x8057C26C: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    skip_0:
    // 0x8057C270: b           L_8057C288
    // 0x8057C274: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
        goto L_8057C288;
    // 0x8057C274: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8057C278: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
L_8057C27C:
    // 0x8057C27C: b           L_8057C288
    // 0x8057C280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8057C288;
    // 0x8057C280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8057C284:
    // 0x8057C284: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8057C288:
    // 0x8057C288: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    // 0x8057C28C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8057C290: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x8057C294: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8057C298: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8057C29C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8057C2A0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8057C2A4: jal         0x80065954
    // 0x8057C2A8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8057C2A8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8057C2AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8057C2B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8057C2B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8057C2B8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8057C2BC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8057C2C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8057C2C4: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8057C2C8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057C2CC: bc1f        L_8057C2F4
    if (!c1cs) {
        // 0x8057C2D0: lwc1        $f14, 0x38($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8057C2F4;
    }
    // 0x8057C2D0: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8057C2D4: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8057C2D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8057C2DC: bc1f        L_8057C2EC
    if (!c1cs) {
        // 0x8057C2E0: nop
    
            goto L_8057C2EC;
    }
    // 0x8057C2E0: nop

    // 0x8057C2E4: b           L_8057C2F8
    // 0x8057C2E8: add.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f18.fl;
        goto L_8057C2F8;
    // 0x8057C2E8: add.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f18.fl;
L_8057C2EC:
    // 0x8057C2EC: b           L_8057C2F8
    // 0x8057C2F0: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
        goto L_8057C2F8;
    // 0x8057C2F0: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
L_8057C2F4:
    // 0x8057C2F4: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
L_8057C2F8:
    // 0x8057C2F8: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8057C2FC: swc1        $f14, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f14.u32l;
    // 0x8057C300: bc1fl       L_8057C31C
    if (!c1cs) {
        // 0x8057C304: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8057C31C;
    }
    goto skip_1;
    // 0x8057C304: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_1:
    // 0x8057C308: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x8057C30C: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x8057C310: b           L_8057C334
    // 0x8057C314: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
        goto L_8057C334;
    // 0x8057C314: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8057C318: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_8057C31C:
    // 0x8057C31C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8057C320: bc1fl       L_8057C338
    if (!c1cs) {
        // 0x8057C324: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057C338;
    }
    goto skip_2;
    // 0x8057C324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8057C328: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
    // 0x8057C32C: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x8057C330: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
L_8057C334:
    // 0x8057C334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057C338:
    // 0x8057C338: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8057C33C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8057C340: jr          $ra
    // 0x8057C344: nop

    return;
    // 0x8057C344: nop

;}
RECOMP_FUNC void func_8001DDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DDF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DDF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DDF8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001DDFC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001DE00: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001DE04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001DE08: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001DE0C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8001DE10: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001DE14: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001DE18: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8001DE1C: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001DE20: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8001DE24: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8001DE28: jal         0x8002F6E4
    // 0x8001DE2C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x8001DE2C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001DE30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DE34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DE38: jr          $ra
    // 0x8001DE3C: nop

    return;
    // 0x8001DE3C: nop

;}
RECOMP_FUNC void func_806D3A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3A5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D3A60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D3A64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D3A68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806D3A6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3A70: lw          $s0, 0x20($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X20);
    // 0x806D3A74: jal         0x80048060
    // 0x806D3A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_0;
    // 0x806D3A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x806D3A7C: jal         0x800440E4
    // 0x806D3A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800440E4(rdram, ctx);
        goto after_1;
    // 0x806D3A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D3A84: jal         0x8005FE48
    // 0x806D3A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x806D3A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806D3A8C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806D3A90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D3A94: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x806D3A98: sb          $t7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r15;
    // 0x806D3A9C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806D3AA0: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x806D3AA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D3AA8: jal         0x806D357C
    // 0x806D3AAC: addiu       $a1, $zero, 0x256
    ctx->r5 = ADD32(0, 0X256);
    func_806D357C(rdram, ctx);
        goto after_3;
    // 0x806D3AAC: addiu       $a1, $zero, 0x256
    ctx->r5 = ADD32(0, 0X256);
    after_3:
    // 0x806D3AB0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x806D3AB4: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x806D3AB8: addiu       $t8, $t8, -0x7218
    ctx->r24 = ADD32(ctx->r24, -0X7218);
    // 0x806D3ABC: sw          $t8, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r24;
    // 0x806D3AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D3AC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D3AC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D3ACC: jr          $ra
    // 0x806D3AD0: nop

    return;
    // 0x806D3AD0: nop

;}
RECOMP_FUNC void func_80517218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051721C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80517224: jal         0x80045A34
    // 0x80517228: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80517228: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8051722C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80517230: lui         $t6, 0x8051
    ctx->r14 = S32(RELOC_HI16(285, 0X2D0) << 16);
    // 0x80517234: bne         $v0, $zero, L_8051724C
    if (ctx->r2 != 0) {
        // 0x80517238: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8051724C;
    }
    // 0x80517238: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8051723C: jal         0x800445A4
    // 0x80517240: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80517240: nop

    after_1:
    // 0x80517244: b           L_805172B4
    // 0x80517248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805172B4;
    // 0x80517248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051724C:
    // 0x8051724C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80517250: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80517254: addiu       $t6, $t6, 0x73E0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(285, 0X2D0));
    // 0x80517258: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8051725C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80517260: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    // 0x80517264: jal         0x80517388
    // 0x80517268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80517388(rdram, ctx);
        goto after_2;
    // 0x80517268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8051726C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80517270: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(285, 0X3D4) << 16);
    // 0x80517274: lwc1        $f4, 0x74E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(285, 0X3D4));
    // 0x80517278: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8051727C: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(285, 0X3D8) << 16);
    // 0x80517280: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x80517284: lwc1        $f6, 0x74E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(285, 0X3D8));
    // 0x80517288: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8051728C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80517290: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    // 0x80517294: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80517298: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8051729C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805172A0: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805172A4: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x805172A8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805172AC: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x805172B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805172B4:
    // 0x805172B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805172B8: jr          $ra
    // 0x805172BC: nop

    return;
    // 0x805172BC: nop

;}
RECOMP_FUNC void func_806F906C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F906C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9074: jal         0x806F8DF0
    // 0x806F9078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F8DF0(rdram, ctx);
        goto after_0;
    // 0x806F9078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F907C: beq         $v0, $zero, L_806F9100
    if (ctx->r2 == 0) {
        // 0x806F9080: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806F9100;
    }
    // 0x806F9080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F9084: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806F9088: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806F908C: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(694, 0X1900) << 16);
    // 0x806F9090: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806F9094: addiu       $t7, $t7, -0x6EF0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(694, 0X1900));
    // 0x806F9098: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806F909C: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x806F90A0: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(694, 0X848) << 16);
    // 0x806F90A4: addiu       $t9, $t9, -0x7FA8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(694, 0X848));
    // 0x806F90A8: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x806F90AC: lui         $t2, 0x8070
    ctx->r10 = S32(RELOC_HI16(694, 0X1358) << 16);
    // 0x806F90B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806F90B4: addiu       $t2, $t2, -0x7498
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(694, 0X1358));
    // 0x806F90B8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F90BC: sb          $t1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r9;
    // 0x806F90C0: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806F90C4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806F90C8: jal         0x806F8E98
    // 0x806F90CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F8E98(rdram, ctx);
        goto after_1;
    // 0x806F90CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x806F90D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F90D4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806F90D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F90DC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806F90E0: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806F90E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F90E8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x806F90EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806F90F0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806F90F4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x806F90F8: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x806F90FC: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
L_806F9100:
    // 0x806F9100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9108: jr          $ra
    // 0x806F910C: nop

    return;
    // 0x806F910C: nop

;}
RECOMP_FUNC void func_807889C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807889C4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x807889C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807889CC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807889D0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x807889D4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x807889D8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x807889DC: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x807889E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807889E4: bc1fl       L_80788A34
    if (!c1cs) {
        // 0x807889E8: lwc1        $f0, 0x4C64($t8)
        ctx->f0.u32l = MEM_W(ctx->r24, 0X4C64);
            goto L_80788A34;
    }
    goto skip_0;
    // 0x807889E8: lwc1        $f0, 0x4C64($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4C64);
    skip_0:
    // 0x807889EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807889F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807889F4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F54) << 16);
    // 0x807889F8: lwc1        $f10, -0x666C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F54));
    // 0x807889FC: mul.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80788A00: lwc1        $f8, 0x4C64($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C64);
    // 0x80788A04: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F58) << 16);
    // 0x80788A08: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80788A0C: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80788A10: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x80788A14: lwc1        $f6, -0x6668($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F58));
    // 0x80788A18: lwc1        $f4, 0x4C64($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C64);
    // 0x80788A1C: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80788A20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80788A24: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80788A28: b           L_80788AA0
    // 0x80788A2C: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
        goto L_80788AA0;
    // 0x80788A2C: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
    // 0x80788A30: lwc1        $f0, 0x4C64($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4C64);
L_80788A34:
    // 0x80788A34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80788A38: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F64) << 16);
    // 0x80788A3C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80788A40: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80788A44: nop

    // 0x80788A48: bc1fl       L_80788A88
    if (!c1cs) {
        // 0x80788A4C: sub.s       $f4, $f0, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_80788A88;
    }
    goto skip_1;
    // 0x80788A4C: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    skip_1:
    // 0x80788A50: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F5C) << 16);
    // 0x80788A54: lwc1        $f4, -0x6664($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F5C));
    // 0x80788A58: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F60) << 16);
    // 0x80788A5C: lwc1        $f8, -0x6660($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F60));
    // 0x80788A60: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80788A64: nop

    // 0x80788A68: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80788A6C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80788A70: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x80788A74: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80788A78: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80788A7C: b           L_80788AA0
    // 0x80788A80: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
        goto L_80788AA0;
    // 0x80788A80: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80788A84: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
L_80788A88:
    // 0x80788A88: lwc1        $f8, -0x665C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F64));
    // 0x80788A8C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80788A90: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x80788A94: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80788A98: add.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80788A9C: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
L_80788AA0:
    // 0x80788AA0: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80788AA4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80788AA8: jr          $ra
    // 0x80788AAC: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
    return;
    // 0x80788AAC: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_805A3F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3F88: jr          $ra
    // 0x805A3F8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805A3F8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800582E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800582E4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800582E8: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x800582EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800582F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800582F4: addiu       $t7, $t6, 0x58
    ctx->r15 = ADD32(ctx->r14, 0X58);
    // 0x800582F8: jal         0x8004700C
    // 0x800582FC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x800582FC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80058300: beq         $v0, $zero, L_80058790
    if (ctx->r2 == 0) {
        // 0x80058304: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80058790;
    }
    // 0x80058304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80058308: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005830C: addiu       $v0, $v0, -0x4C10
    ctx->r2 = ADD32(ctx->r2, -0X4C10);
    // 0x80058310: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80058314: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x80058318: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x8005831C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80058320: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80058324: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80058328: sb          $t8, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r24;
    // 0x8005832C: sb          $t9, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r25;
    // 0x80058330: sb          $t0, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r8;
    // 0x80058334: lw          $a2, -0x6DA8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6DA8);
    // 0x80058338: addiu       $a1, $a1, -0x4BC8
    ctx->r5 = ADD32(ctx->r5, -0X4BC8);
    // 0x8005833C: addiu       $v1, $v1, -0x4C10
    ctx->r3 = ADD32(ctx->r3, -0X4C10);
L_80058340:
    // 0x80058340: lbu         $v0, 0x5D($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5D);
    // 0x80058344: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x80058348: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8005834C: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x80058350: sb          $v0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r2;
    // 0x80058354: bne         $at, $zero, L_80058340
    if (ctx->r1 != 0) {
        // 0x80058358: sb          $v0, -0x3($v1)
        MEM_B(-0X3, ctx->r3) = ctx->r2;
            goto L_80058340;
    }
    // 0x80058358: sb          $v0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r2;
    // 0x8005835C: jal         0x80047058
    // 0x80058360: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80047058(rdram, ctx);
        goto after_1;
    // 0x80058360: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80058364: lw          $t1, 0x16C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X16C);
    // 0x80058368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005836C: lw          $a2, 0x38($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X38);
    // 0x80058370: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, 0X200);
    // 0x80058374: jal         0x80049018
    // 0x80058378: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x80058378: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8005837C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80058380: beq         $v0, $zero, L_80058580
    if (ctx->r2 == 0) {
        // 0x80058384: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80058580;
    }
    // 0x80058384: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80058388: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8005838C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80058390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80058394: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80058398: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x8005839C: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800583A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800583A4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800583A8: nop

    // 0x800583AC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800583B0: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800583B4: beql        $a1, $a2, L_800584B0
    if (ctx->r5 == ctx->r6) {
        // 0x800583B8: swc1        $f18, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
            goto L_800584B0;
    }
    goto skip_0;
    // 0x800583B8: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    skip_0:
    // 0x800583BC: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_800583C0:
    // 0x800583C0: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800583C4: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800583C8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800583CC: mtc1        $t3, $f14
    ctx->f14.u32l = ctx->r11;
    // 0x800583D0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800583D4: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800583D8: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800583DC: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800583E0: swc1        $f14, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f14.u32l;
    // 0x800583E4: lh          $t4, -0x30($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X30);
    // 0x800583E8: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800583EC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800583F0: nop

    // 0x800583F4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800583F8: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800583FC: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80058400: lh          $t5, -0x2E($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X2E);
    // 0x80058404: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058408: mtc1        $t5, $f14
    ctx->f14.u32l = ctx->r13;
    // 0x8005840C: nop

    // 0x80058410: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058414: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058418: swc1        $f14, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f14.u32l;
    // 0x8005841C: lh          $t6, -0x20($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X20);
    // 0x80058420: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80058424: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80058428: nop

    // 0x8005842C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80058430: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80058434: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80058438: lh          $t7, -0x1E($v1)
    ctx->r15 = MEM_H(ctx->r3, -0X1E);
    // 0x8005843C: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058440: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x80058444: nop

    // 0x80058448: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8005844C: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058450: swc1        $f14, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f14.u32l;
    // 0x80058454: lh          $t8, -0x10($v1)
    ctx->r24 = MEM_H(ctx->r3, -0X10);
    // 0x80058458: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8005845C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80058460: nop

    // 0x80058464: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80058468: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8005846C: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80058470: lh          $t9, -0xE($v1)
    ctx->r25 = MEM_H(ctx->r3, -0XE);
    // 0x80058474: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058478: mtc1        $t9, $f14
    ctx->f14.u32l = ctx->r25;
    // 0x8005847C: nop

    // 0x80058480: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058484: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058488: swc1        $f14, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f14.u32l;
    // 0x8005848C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x80058490: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80058494: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80058498: nop

    // 0x8005849C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800584A0: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800584A4: bnel        $a1, $a2, L_800583C0
    if (ctx->r5 != ctx->r6) {
        // 0x800584A8: swc1        $f18, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
            goto L_800583C0;
    }
    goto skip_1;
    // 0x800584A8: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    skip_1:
    // 0x800584AC: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_800584B0:
    // 0x800584B0: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800584B4: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800584B8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800584BC: mtc1        $t3, $f14
    ctx->f14.u32l = ctx->r11;
    // 0x800584C0: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800584C4: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800584C8: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800584CC: swc1        $f14, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f14.u32l;
    // 0x800584D0: lh          $t4, -0x30($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X30);
    // 0x800584D4: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800584D8: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800584DC: nop

    // 0x800584E0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800584E4: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800584E8: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800584EC: lh          $t5, -0x2E($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X2E);
    // 0x800584F0: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800584F4: mtc1        $t5, $f14
    ctx->f14.u32l = ctx->r13;
    // 0x800584F8: nop

    // 0x800584FC: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058500: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058504: swc1        $f14, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f14.u32l;
    // 0x80058508: lh          $t6, -0x20($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X20);
    // 0x8005850C: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80058510: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80058514: nop

    // 0x80058518: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005851C: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80058520: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80058524: lh          $t7, -0x1E($v1)
    ctx->r15 = MEM_H(ctx->r3, -0X1E);
    // 0x80058528: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8005852C: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x80058530: nop

    // 0x80058534: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058538: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8005853C: swc1        $f14, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f14.u32l;
    // 0x80058540: lh          $t8, -0x10($v1)
    ctx->r24 = MEM_H(ctx->r3, -0X10);
    // 0x80058544: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80058548: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8005854C: nop

    // 0x80058550: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80058554: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80058558: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8005855C: lh          $t9, -0xE($v1)
    ctx->r25 = MEM_H(ctx->r3, -0XE);
    // 0x80058560: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058564: mtc1        $t9, $f14
    ctx->f14.u32l = ctx->r25;
    // 0x80058568: nop

    // 0x8005856C: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058570: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058574: swc1        $f14, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f14.u32l;
    // 0x80058578: b           L_80058794
    // 0x8005857C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80058794;
    // 0x8005857C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058580:
    // 0x80058580: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80058584: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80058588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005858C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80058590: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80058594: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80058598: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8005859C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800585A0: nop

    // 0x800585A4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800585A8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800585AC: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800585B0: beql        $a1, $a2, L_800586BC
    if (ctx->r5 == ctx->r6) {
        // 0x800585B4: swc1        $f18, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
            goto L_800586BC;
    }
    goto skip_2;
    // 0x800585B4: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    skip_2:
    // 0x800585B8: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_800585BC:
    // 0x800585BC: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x800585C0: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800585C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800585C8: mtc1        $t1, $f14
    ctx->f14.u32l = ctx->r9;
    // 0x800585CC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800585D0: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800585D4: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800585D8: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800585DC: swc1        $f14, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f14.u32l;
    // 0x800585E0: lh          $t2, -0x30($v1)
    ctx->r10 = MEM_H(ctx->r3, -0X30);
    // 0x800585E4: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800585E8: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800585EC: nop

    // 0x800585F0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800585F4: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800585F8: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800585FC: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80058600: lh          $t3, -0x2E($v1)
    ctx->r11 = MEM_H(ctx->r3, -0X2E);
    // 0x80058604: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058608: mtc1        $t3, $f14
    ctx->f14.u32l = ctx->r11;
    // 0x8005860C: nop

    // 0x80058610: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058614: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058618: swc1        $f14, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f14.u32l;
    // 0x8005861C: lh          $t4, -0x20($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X20);
    // 0x80058620: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80058624: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80058628: nop

    // 0x8005862C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80058630: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80058634: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80058638: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8005863C: lh          $t5, -0x1E($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X1E);
    // 0x80058640: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058644: mtc1        $t5, $f14
    ctx->f14.u32l = ctx->r13;
    // 0x80058648: nop

    // 0x8005864C: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058650: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058654: swc1        $f14, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f14.u32l;
    // 0x80058658: lh          $t6, -0x10($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X10);
    // 0x8005865C: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80058660: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80058664: nop

    // 0x80058668: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005866C: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80058670: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80058674: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80058678: lh          $t7, -0xE($v1)
    ctx->r15 = MEM_H(ctx->r3, -0XE);
    // 0x8005867C: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058680: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x80058684: nop

    // 0x80058688: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8005868C: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058690: swc1        $f14, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f14.u32l;
    // 0x80058694: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80058698: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8005869C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800586A0: nop

    // 0x800586A4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800586A8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800586AC: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800586B0: bnel        $a1, $a2, L_800585BC
    if (ctx->r5 != ctx->r6) {
        // 0x800586B4: swc1        $f18, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
            goto L_800585BC;
    }
    goto skip_3;
    // 0x800586B4: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    skip_3:
    // 0x800586B8: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_800586BC:
    // 0x800586BC: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x800586C0: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800586C4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800586C8: mtc1        $t1, $f14
    ctx->f14.u32l = ctx->r9;
    // 0x800586CC: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x800586D0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800586D4: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800586D8: swc1        $f14, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f14.u32l;
    // 0x800586DC: lh          $t2, -0x30($v1)
    ctx->r10 = MEM_H(ctx->r3, -0X30);
    // 0x800586E0: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800586E4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800586E8: nop

    // 0x800586EC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800586F0: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800586F4: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800586F8: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800586FC: lh          $t3, -0x2E($v1)
    ctx->r11 = MEM_H(ctx->r3, -0X2E);
    // 0x80058700: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058704: mtc1        $t3, $f14
    ctx->f14.u32l = ctx->r11;
    // 0x80058708: nop

    // 0x8005870C: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058710: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058714: swc1        $f14, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f14.u32l;
    // 0x80058718: lh          $t4, -0x20($v1)
    ctx->r12 = MEM_H(ctx->r3, -0X20);
    // 0x8005871C: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80058720: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80058724: nop

    // 0x80058728: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005872C: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80058730: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80058734: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80058738: lh          $t5, -0x1E($v1)
    ctx->r13 = MEM_H(ctx->r3, -0X1E);
    // 0x8005873C: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80058740: mtc1        $t5, $f14
    ctx->f14.u32l = ctx->r13;
    // 0x80058744: nop

    // 0x80058748: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8005874C: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80058750: swc1        $f14, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f14.u32l;
    // 0x80058754: lh          $t6, -0x10($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X10);
    // 0x80058758: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8005875C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80058760: nop

    // 0x80058764: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80058768: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8005876C: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80058770: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80058774: lh          $t7, -0xE($v1)
    ctx->r15 = MEM_H(ctx->r3, -0XE);
    // 0x80058778: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8005877C: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x80058780: nop

    // 0x80058784: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80058788: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8005878C: swc1        $f14, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f14.u32l;
L_80058790:
    // 0x80058790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058794:
    // 0x80058794: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80058798: jr          $ra
    // 0x8005879C: nop

    return;
    // 0x8005879C: nop

;}
RECOMP_FUNC void func_80024840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024848: lbu         $v0, 0x158($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X158);
    // 0x8002484C: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80024850: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024854: bne         $v0, $at, L_80024888
    if (ctx->r2 != ctx->r1) {
        // 0x80024858: sw          $t6, 0x150($a0)
        MEM_W(0X150, ctx->r4) = ctx->r14;
            goto L_80024888;
    }
    // 0x80024858: sw          $t6, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r14;
    // 0x8002485C: jal         0x80048690
    // 0x80024860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048690(rdram, ctx);
        goto after_0;
    // 0x80024860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80024864: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024868: bne         $v0, $at, L_800248C4
    if (ctx->r2 != ctx->r1) {
        // 0x8002486C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800248C4;
    }
    // 0x8002486C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80024870: lw          $t8, 0x150($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X150);
    // 0x80024874: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80024878: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    // 0x8002487C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80024880: b           L_800248C4
    // 0x80024884: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
        goto L_800248C4;
    // 0x80024884: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
L_80024888:
    // 0x80024888: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002488C: bnel        $v0, $at, L_800248C8
    if (ctx->r2 != ctx->r1) {
        // 0x80024890: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800248C8;
    }
    goto skip_0;
    // 0x80024890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80024894: jal         0x80048720
    // 0x80024898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048720(rdram, ctx);
        goto after_1;
    // 0x80024898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8002489C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800248A0: bne         $v0, $at, L_800248C4
    if (ctx->r2 != ctx->r1) {
        // 0x800248A4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800248C4;
    }
    // 0x800248A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800248A8: lw          $t1, 0x150($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X150);
    // 0x800248AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800248B0: sb          $t0, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r8;
    // 0x800248B4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800248B8: sw          $t2, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r10;
    // 0x800248BC: b           L_800248C8
    // 0x800248C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800248C8;
    // 0x800248C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800248C4:
    // 0x800248C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800248C8:
    // 0x800248C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800248CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800248D0: jr          $ra
    // 0x800248D4: nop

    return;
    // 0x800248D4: nop

;}
RECOMP_FUNC void func_806E630C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E630C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806E6310: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(655, 0X594) << 16);
    // 0x806E6314: addiu       $t6, $t6, 0x6254
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(655, 0X594));
    // 0x806E6318: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806E631C: jr          $ra
    // 0x806E6320: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806E6320: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804369D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804369D0: jr          $ra
    // 0x804369D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804369D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8045043C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045043C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80450440: lw          $v0, 0x7EA8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7EA8);
    // 0x80450444: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x80450448: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8045044C: beq         $at, $zero, L_80450488
    if (ctx->r1 == 0) {
        // 0x80450450: slti        $at, $v1, -0x5
        ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
            goto L_80450488;
    }
    // 0x80450450: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
    // 0x80450454: bne         $at, $zero, L_80450488
    if (ctx->r1 != 0) {
        // 0x80450458: nop
    
            goto L_80450488;
    }
    // 0x80450458: nop

    // 0x8045045C: lb          $v1, 0x3($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3);
    // 0x80450460: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80450464: beq         $at, $zero, L_80450488
    if (ctx->r1 == 0) {
        // 0x80450468: slti        $at, $v1, -0x5
        ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
            goto L_80450488;
    }
    // 0x80450468: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
    // 0x8045046C: bne         $at, $zero, L_80450488
    if (ctx->r1 != 0) {
        // 0x80450470: nop
    
            goto L_80450488;
    }
    // 0x80450470: nop

    // 0x80450474: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450478: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045047C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80450480: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80450484: sb          $t6, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = ctx->r14;
L_80450488:
    // 0x80450488: jr          $ra
    // 0x8045048C: nop

    return;
    // 0x8045048C: nop

;}
RECOMP_FUNC void func_80407F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407F74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80407F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80407F7C: jal         0x8004700C
    // 0x80407F80: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80407F80: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80407F84: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80407F88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80407F8C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80407F90: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x80407F94: beq         $v0, $zero, L_80407FDC
    if (ctx->r2 == 0) {
        // 0x80407F98: lw          $v1, 0x4($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X4);
            goto L_80407FDC;
    }
    // 0x80407F98: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80407F9C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80407FA0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80407FA4: jal         0x80407D10
    // 0x80407FA8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_80407D10(rdram, ctx);
        goto after_1;
    // 0x80407FA8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_1:
    // 0x80407FAC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80407FB0: beq         $v0, $zero, L_80407FDC
    if (ctx->r2 == 0) {
        // 0x80407FB4: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80407FDC;
    }
    // 0x80407FB4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80407FB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80407FBC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80407FC0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80407FC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80407FC8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80407FCC: jal         0x8002F6E4
    // 0x80407FD0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_8002F6E4(rdram, ctx);
        goto after_2;
    // 0x80407FD0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_2:
    // 0x80407FD4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80407FD8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_80407FDC:
    // 0x80407FDC: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E00) << 16);
    // 0x80407FE0: lwc1        $f6, -0x5830($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E00));
    // 0x80407FE4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80407FE8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80407FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80407FF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80407FF4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80407FF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80407FFC: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x80408000: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80408004: lwc1        $f0, 0x14($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80408008: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8040800C: nop

    // 0x80408010: bc1fl       L_80408024
    if (!c1cs) {
        // 0x80408014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80408024;
    }
    goto skip_0;
    // 0x80408014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80408018: jal         0x8040818C
    // 0x8040801C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    func_8040818C(rdram, ctx);
        goto after_3;
    // 0x8040801C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    after_3:
    // 0x80408020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80408024:
    // 0x80408024: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80408028: jr          $ra
    // 0x8040802C: nop

    return;
    // 0x8040802C: nop

;}
RECOMP_FUNC void func_8078B330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B330: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8078B334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078B338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078B33C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8078B340: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8078B344: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x8078B348: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8078B34C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8078B350: beql        $t6, $at, L_8078B380
    if (ctx->r14 == ctx->r1) {
        // 0x8078B354: lhu         $t8, 0xC($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0XC);
            goto L_8078B380;
    }
    goto skip_0;
    // 0x8078B354: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
    skip_0:
    // 0x8078B358: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x8078B35C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8078B360: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8078B364: bne         $t7, $at, L_8078B3D4
    if (ctx->r15 != ctx->r1) {
        // 0x8078B368: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_8078B3D4;
    }
    // 0x8078B368: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8078B36C: jal         0x8002F6E4
    // 0x8078B370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x8078B370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8078B374: b           L_8078B3D8
    // 0x8078B378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078B3D8;
    // 0x8078B378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078B37C: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
L_8078B380:
    // 0x8078B380: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8078B384: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8078B388: beql        $t8, $at, L_8078B3D8
    if (ctx->r24 == ctx->r1) {
        // 0x8078B38C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078B3D8;
    }
    goto skip_1;
    // 0x8078B38C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8078B390: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8078B394: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B40) << 16);
    // 0x8078B398: lwc1        $f8, -0x3330($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B40));
    // 0x8078B39C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8078B3A0: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8078B3A4: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8078B3A8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8078B3AC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8078B3B0: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8078B3B4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8078B3B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8078B3BC: lw          $t9, 0x18($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X18);
    // 0x8078B3C0: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8078B3C4: jalr        $t9
    // 0x8078B3C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8078B3C8: nop

    after_1:
    // 0x8078B3CC: jal         0x800447C8
    // 0x8078B3D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8078B3D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8078B3D4:
    // 0x8078B3D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078B3D8:
    // 0x8078B3D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078B3DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8078B3E0: jr          $ra
    // 0x8078B3E4: nop

    return;
    // 0x8078B3E4: nop

;}
RECOMP_FUNC void func_80007674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007674: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80007678: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000767C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80007680: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80007684: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80007688: addiu       $s0, $a2, 0xF
    ctx->r16 = ADD32(ctx->r6, 0XF);
    // 0x8000768C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80007690: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80007694: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80007698: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000769C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    // 0x800076A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800076A4: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x800076A8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800076AC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800076B0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800076B4: jal         0x8000AC90
    // 0x800076B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000AC90(rdram, ctx);
        goto after_0;
    // 0x800076B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800076BC: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x800076C0: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x800076C4: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800076C8: addiu       $s3, $s3, 0x682C
    ctx->r19 = ADD32(ctx->r19, 0X682C);
    // 0x800076CC: addiu       $s4, $s4, 0x7FE4
    ctx->r20 = ADD32(ctx->r20, 0X7FE4);
    // 0x800076D0: addiu       $s6, $s6, 0x6848
    ctx->r22 = ADD32(ctx->r22, 0X6848);
    // 0x800076D4: sltiu       $at, $s0, 0x400
    ctx->r1 = ctx->r16 < 0X400 ? 1 : 0;
    // 0x800076D8: bne         $at, $zero, L_8000772C
    if (ctx->r1 != 0) {
        // 0x800076DC: addiu       $t6, $zero, 0x400
        ctx->r14 = ADD32(0, 0X400);
            goto L_8000772C;
    }
L_800076DC:
    // 0x800076DC: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800076E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800076E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800076E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800076EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800076F0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800076F4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800076F8: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x800076FC: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80007700: jal         0x800077AC
    // 0x80007704: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    func_800077AC(rdram, ctx);
        goto after_1;
    // 0x80007704: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    after_1:
    // 0x80007708: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000770C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007710: jal         0x800824B0
    // 0x80007714: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80007714: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80007718: addiu       $s0, $s0, -0x400
    ctx->r16 = ADD32(ctx->r16, -0X400);
    // 0x8000771C: sltiu       $at, $s0, 0x400
    ctx->r1 = ctx->r16 < 0X400 ? 1 : 0;
    // 0x80007720: addiu       $s2, $s2, 0x400
    ctx->r18 = ADD32(ctx->r18, 0X400);
    // 0x80007724: beq         $at, $zero, L_800076DC
    if (ctx->r1 == 0) {
        // 0x80007728: addiu       $s1, $s1, 0x400
        ctx->r17 = ADD32(ctx->r17, 0X400);
            goto L_800076DC;
    }
    // 0x80007728: addiu       $s1, $s1, 0x400
    ctx->r17 = ADD32(ctx->r17, 0X400);
L_8000772C:
    // 0x8000772C: beq         $s0, $zero, L_80007770
    if (ctx->r16 == 0) {
        // 0x80007730: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80007770;
    }
    // 0x80007730: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80007734: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80007738: addiu       $t7, $t7, 0x7FF0
    ctx->r15 = ADD32(ctx->r15, 0X7FF0);
    // 0x8000773C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80007740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80007744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80007748: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8000774C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80007750: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80007754: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x80007758: jal         0x800077AC
    // 0x8000775C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800077AC(rdram, ctx);
        goto after_3;
    // 0x8000775C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_3:
    // 0x80007760: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80007764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007768: jal         0x800824B0
    // 0x8000776C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8000776C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_80007770:
    // 0x80007770: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80007774: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80007778: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000777C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80007780: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80007784: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80007788: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8000778C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80007790: jr          $ra
    // 0x80007794: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80007794: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_805AB0C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB0C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805AB0C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805AB0C8: lwc1        $f0, 0x278($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X278);
    // 0x805AB0CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x805AB0D0: lwc1        $f2, 0x274($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X274);
    // 0x805AB0D4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x805AB0D8: lwc1        $f12, 0x270($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X270);
    // 0x805AB0DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x805AB0E0: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB00) << 16);
    // 0x805AB0E4: bc1f        L_805AB0F4
    if (!c1cs) {
        // 0x805AB0E8: nop
    
            goto L_805AB0F4;
    }
    // 0x805AB0E8: nop

    // 0x805AB0EC: b           L_805AB100
    // 0x805AB0F0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_805AB100;
    // 0x805AB0F0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_805AB0F4:
    // 0x805AB0F4: lwc1        $f4, -0x45C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB00));
    // 0x805AB0F8: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x805AB0FC: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_805AB100:
    // 0x805AB100: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x805AB104: nop

    // 0x805AB108: bc1fl       L_805AB130
    if (!c1cs) {
        // 0x805AB10C: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_805AB130;
    }
    goto skip_0;
    // 0x805AB10C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x805AB110: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x805AB114: nop

    // 0x805AB118: bc1fl       L_805AB148
    if (!c1cs) {
        // 0x805AB11C: div.s       $f2, $f14, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
            goto L_805AB148;
    }
    goto skip_1;
    // 0x805AB11C: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    skip_1:
    // 0x805AB120: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x805AB124: b           L_805AB144
    // 0x805AB128: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805AB144;
    // 0x805AB128: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805AB12C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_805AB130:
    // 0x805AB130: nop

    // 0x805AB134: bc1fl       L_805AB148
    if (!c1cs) {
        // 0x805AB138: div.s       $f2, $f14, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
            goto L_805AB148;
    }
    goto skip_2;
    // 0x805AB138: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    skip_2:
    // 0x805AB13C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x805AB140: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805AB144:
    // 0x805AB144: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
L_805AB148:
    // 0x805AB148: swc1        $f0, 0x278($a1)
    MEM_W(0X278, ctx->r5) = ctx->f0.u32l;
    // 0x805AB14C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805AB150: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805AB154: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x805AB158: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x805AB15C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x805AB160: sub.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x805AB164: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x805AB168: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x805AB16C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805AB170: jr          $ra
    // 0x805AB174: swc1        $f18, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x805AB174: swc1        $f18, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80534144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80534148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8053414C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80534150: jal         0x80045A34
    // 0x80534154: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80534154: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_0:
    // 0x80534158: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8053415C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80534160: bne         $v0, $zero, L_80534178
    if (ctx->r2 != 0) {
        // 0x80534164: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_80534178;
    }
    // 0x80534164: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x80534168: jal         0x800445A4
    // 0x8053416C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8053416C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80534170: b           L_805341CC
    // 0x80534174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805341CC;
    // 0x80534174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80534178:
    // 0x80534178: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x8053417C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80534180: jal         0x800657CC
    // 0x80534184: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800657CC(rdram, ctx);
        goto after_2;
    // 0x80534184: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x80534188: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8053418C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80534190: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80534194: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80534198: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8053419C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x805341A0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x805341A4: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x805341A8: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x805341AC: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x805341B0: addiu       $v1, $a0, 0xC
    ctx->r3 = ADD32(ctx->r4, 0XC);
    // 0x805341B4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x805341B8: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x805341BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805341C0: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x805341C4: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x805341C8: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
L_805341CC:
    // 0x805341CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805341D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805341D4: jr          $ra
    // 0x805341D8: nop

    return;
    // 0x805341D8: nop

;}
RECOMP_FUNC void func_804723C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804723C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804723C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804723CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804723D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804723D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804723D8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x804723DC: jal         0x8006593C
    // 0x804723E0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x804723E0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x804723E4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x804723E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x804723EC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x804723F0: subu        $v1, $v0, $t6
    ctx->r3 = SUB32(ctx->r2, ctx->r14);
    // 0x804723F4: bgez        $v1, L_80472404
    if (SIGNED(ctx->r3) >= 0) {
        // 0x804723F8: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80472404;
    }
    // 0x804723F8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x804723FC: b           L_80472414
    // 0x80472400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80472414;
    // 0x80472400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80472404:
    // 0x80472404: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80472408: beql        $at, $zero, L_80472418
    if (ctx->r1 == 0) {
        // 0x8047240C: lw          $t7, 0x0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X0);
            goto L_80472418;
    }
    goto skip_0;
    // 0x8047240C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x80472410: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80472414:
    // 0x80472414: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
L_80472418:
    // 0x80472418: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x8047241C: bgezl       $t7, L_80472430
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80472420: sw          $a0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r4;
            goto L_80472430;
    }
    goto skip_1;
    // 0x80472420: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    skip_1:
    // 0x80472424: b           L_80472430
    // 0x80472428: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_80472430;
    // 0x80472428: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8047242C: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
L_80472430:
    // 0x80472430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80472434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80472438: jr          $ra
    // 0x8047243C: nop

    return;
    // 0x8047243C: nop

;}
RECOMP_FUNC void func_8007348C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007348C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073494: lh          $t6, 0xC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC);
    // 0x80073498: bnel        $a1, $t6, L_800734B0
    if (ctx->r5 != ctx->r14) {
        // 0x8007349C: lw          $t8, 0x18($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X18);
            goto L_800734B0;
    }
    goto skip_0;
    // 0x8007349C: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    skip_0:
    // 0x800734A0: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800734A4: beql        $a2, $t7, L_800734DC
    if (ctx->r6 == ctx->r15) {
        // 0x800734A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800734DC;
    }
    goto skip_1;
    // 0x800734A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800734AC: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
L_800734B0:
    // 0x800734B0: sh          $a1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r5;
    // 0x800734B4: sh          $a2, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r6;
    // 0x800734B8: beql        $t8, $zero, L_800734DC
    if (ctx->r24 == 0) {
        // 0x800734BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800734DC;
    }
    goto skip_2;
    // 0x800734BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800734C0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800734C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800734C8: beql        $t9, $at, L_800734DC
    if (ctx->r25 == ctx->r1) {
        // 0x800734CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800734DC;
    }
    goto skip_3;
    // 0x800734CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800734D0: jal         0x80073070
    // 0x800734D4: nop

    func_80073070(rdram, ctx);
        goto after_0;
    // 0x800734D4: nop

    after_0:
    // 0x800734D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800734DC:
    // 0x800734DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800734E0: jr          $ra
    // 0x800734E4: nop

    return;
    // 0x800734E4: nop

    // 0x800734E8: nop

    // 0x800734EC: nop

;}
RECOMP_FUNC void func_805E4378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4378: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805E437C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x805E4380: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805E4384: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805E4388: nop

    // 0x805E438C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x805E4390: nop

    // 0x805E4394: bc1fl       L_805E43C4
    if (!c1cs) {
        // 0x805E4398: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_805E43C4;
    }
    goto skip_0;
    // 0x805E4398: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x805E439C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805E43A0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805E43A4: nop

    // 0x805E43A8: bc1f        L_805E43E0
    if (!c1cs) {
        // 0x805E43AC: nop
    
            goto L_805E43E0;
    }
    // 0x805E43AC: nop

    // 0x805E43B0: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x805E43B4: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x805E43B8: jr          $ra
    // 0x805E43BC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x805E43BC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x805E43C0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_805E43C4:
    // 0x805E43C4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x805E43C8: nop

    // 0x805E43CC: bc1f        L_805E43E0
    if (!c1cs) {
        // 0x805E43D0: nop
    
            goto L_805E43E0;
    }
    // 0x805E43D0: nop

    // 0x805E43D4: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x805E43D8: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x805E43DC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_805E43E0:
    // 0x805E43E0: jr          $ra
    // 0x805E43E4: nop

    return;
    // 0x805E43E4: nop

;}
RECOMP_FUNC void func_80445B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445B14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445B1C: jal         0x800679B0
    // 0x80445B20: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800679B0(rdram, ctx);
        goto after_0;
    // 0x80445B20: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_0:
    // 0x80445B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445B2C: jr          $ra
    // 0x80445B30: nop

    return;
    // 0x80445B30: nop

;}
RECOMP_FUNC void func_80682EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682EC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682EC8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682ECC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682ED0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682ED4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682ED8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682EDC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682EE0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682EE4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682EE8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682EEC: jr          $ra
    // 0x80682EF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682EF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8043F9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F9A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043F9A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F9A8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8043F9AC: beql        $v0, $zero, L_8043F9F4
    if (ctx->r2 == 0) {
        // 0x8043F9B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043F9F4;
    }
    goto skip_0;
    // 0x8043F9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043F9B4: lbu         $t6, 0x30($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X30);
    // 0x8043F9B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8043F9BC: bnel        $t6, $at, L_8043F9F4
    if (ctx->r14 != ctx->r1) {
        // 0x8043F9C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043F9F4;
    }
    goto skip_1;
    // 0x8043F9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8043F9C4: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F9C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F9CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8043F9D0: sw          $zero, 0x2630($t7)
    MEM_W(0X2630, ctx->r15) = 0;
    // 0x8043F9D4: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F9D8: sw          $zero, 0x2628($t8)
    MEM_W(0X2628, ctx->r24) = 0;
    // 0x8043F9DC: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8043F9E0: jal         0x80442188
    // 0x8043F9E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F9E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043F9E8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F9EC: sb          $zero, 0x30($v0)
    MEM_B(0X30, ctx->r2) = 0;
    // 0x8043F9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043F9F4:
    // 0x8043F9F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043F9F8: jr          $ra
    // 0x8043F9FC: nop

    return;
    // 0x8043F9FC: nop

;}
RECOMP_FUNC void func_8003BB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BB58: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003BB5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BB60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BB64: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8003BB68: addiu       $t6, $zero, 0x4005
    ctx->r14 = ADD32(0, 0X4005);
    // 0x8003BB6C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8003BB70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003BB74: lw          $a3, 0x4270($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4270);
    // 0x8003BB78: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x8003BB7C: jal         0x8003BA90
    // 0x8003BB80: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_8003BA90(rdram, ctx);
        goto after_0;
    // 0x8003BB80: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_0:
    // 0x8003BB84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BB88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003BB8C: jr          $ra
    // 0x8003BB90: nop

    return;
    // 0x8003BB90: nop

;}
RECOMP_FUNC void func_804462C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804462C0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804462C4: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x804462C8: jr          $ra
    // 0x804462CC: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    return;
    // 0x804462CC: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80461B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80461B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461B38: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80461B3C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80461B40: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80461B44: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X37A0) << 16);
    // 0x80461B48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80461B4C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80461B50: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80461B54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80461B58: lw          $t8, 0x3D30($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X37A0));
    // 0x80461B5C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80461B60: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80461B64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80461B68: jal         0x80048490
    // 0x80461B6C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80461B6C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80461B70: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80461B74: jal         0x80048378
    // 0x80461B78: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80461B78: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80461B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80461B84: jr          $ra
    // 0x80461B88: nop

    return;
    // 0x80461B88: nop

;}
RECOMP_FUNC void func_804096C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804096C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804096C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804096C8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x804096CC: jal         0x8004700C
    // 0x804096D0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804096D0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x804096D4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x804096D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804096DC: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
    // 0x804096E0: beql        $t6, $zero, L_8040978C
    if (ctx->r14 == 0) {
        // 0x804096E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040978C;
    }
    goto skip_0;
    // 0x804096E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804096E8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804096EC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x804096F0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x804096F4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x804096F8: lwc1        $f6, 0x40($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X40);
    // 0x804096FC: beq         $v0, $zero, L_80409788
    if (ctx->r2 == 0) {
        // 0x80409700: swc1        $f6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
            goto L_80409788;
    }
    // 0x80409700: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80409704: jal         0x80047AB8
    // 0x80409708: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80409708: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8040970C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80409710: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x80409714: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80409718: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x8040971C: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x80409720: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x80409724: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80409728: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8040972C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80409730: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80409734: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80409738: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8040973C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80409740: mul.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80409744: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80409748: mul.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8040974C: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80409750: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80409754: nop

    // 0x80409758: bc1fl       L_8040978C
    if (!c1cs) {
        // 0x8040975C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040978C;
    }
    goto skip_1;
    // 0x8040975C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80409760: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80409764: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80409768: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8040976C: nop

    // 0x80409770: bc1fl       L_8040978C
    if (!c1cs) {
        // 0x80409774: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040978C;
    }
    goto skip_2;
    // 0x80409774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80409778: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8040977C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80409780: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80409784: nop

L_80409788:
    // 0x80409788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040978C:
    // 0x8040978C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80409790: jr          $ra
    // 0x80409794: nop

    return;
    // 0x80409794: nop

;}
RECOMP_FUNC void func_80680E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80680E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680E10: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680E14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80680E18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80680E1C: lwc1        $f0, 0x88($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80680E20: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2254) << 16);
    // 0x80680E24: lwc1        $f8, 0x2664($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2254));
    // 0x80680E28: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80680E2C: lwc1        $f10, 0x8C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80680E30: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2258) << 16);
    // 0x80680E34: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80680E38: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80680E3C: swc1        $f16, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->f16.u32l;
    // 0x80680E40: lwc1        $f18, 0x2668($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2258));
    // 0x80680E44: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80680E48: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80680E4C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80680E50: jal         0x80680D5C
    // 0x80680E54: swc1        $f8, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f8.u32l;
    func_80680D5C(rdram, ctx);
        goto after_0;
    // 0x80680E54: swc1        $f8, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f8.u32l;
    after_0:
    // 0x80680E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80680E60: jr          $ra
    // 0x80680E64: nop

    return;
    // 0x80680E64: nop

;}
RECOMP_FUNC void func_8001F560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F560: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001F564: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F568: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F56C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8001F570: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8001F574: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8001F578: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001F57C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001F580: bne         $t6, $at, L_8001F5A0
    if (ctx->r14 != ctx->r1) {
        // 0x8001F584: lw          $v1, 0x4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X4);
            goto L_8001F5A0;
    }
    // 0x8001F584: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x8001F588: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x8001F58C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8001F590: beq         $v0, $at, L_8001F794
    if (ctx->r2 == ctx->r1) {
        // 0x8001F594: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8001F794;
    }
    // 0x8001F594: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8001F598: beql        $v0, $at, L_8001F798
    if (ctx->r2 == ctx->r1) {
        // 0x8001F59C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001F798;
    }
    goto skip_0;
    // 0x8001F59C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8001F5A0:
    // 0x8001F5A0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8001F5A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001F5A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001F5AC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8001F5B0: lhu         $a2, 0x0($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X0);
    // 0x8001F5B4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8001F5B8: jal         0x8004AB60
    // 0x8001F5BC: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    func_8004AB60(rdram, ctx);
        goto after_0;
    // 0x8001F5BC: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001F5C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8001F5C4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8001F5C8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001F5CC: lbu         $v0, 0x12($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X12);
    // 0x8001F5D0: bne         $v0, $zero, L_8001F648
    if (ctx->r2 != 0) {
        // 0x8001F5D4: nop
    
            goto L_8001F648;
    }
    // 0x8001F5D4: nop

    // 0x8001F5D8: lbu         $a0, 0x13($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X13);
    // 0x8001F5DC: beq         $a0, $zero, L_8001F648
    if (ctx->r4 == 0) {
        // 0x8001F5E0: nop
    
            goto L_8001F648;
    }
    // 0x8001F5E0: nop

    // 0x8001F5E4: lw          $t9, 0x2C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X2C);
    // 0x8001F5E8: andi        $t1, $t9, 0x700
    ctx->r9 = ctx->r25 & 0X700;
    // 0x8001F5EC: bnel        $t1, $zero, L_8001F798
    if (ctx->r9 != 0) {
        // 0x8001F5F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001F798;
    }
    goto skip_1;
    // 0x8001F5F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8001F5F4: bnel        $v1, $zero, L_8001F798
    if (ctx->r3 != 0) {
        // 0x8001F5F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001F798;
    }
    goto skip_2;
    // 0x8001F5F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8001F5FC: lw          $t2, 0x11C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X11C);
    // 0x8001F600: bnel        $t2, $zero, L_8001F798
    if (ctx->r10 != 0) {
        // 0x8001F604: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001F798;
    }
    goto skip_3;
    // 0x8001F604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8001F608: lwc1        $f0, 0xAC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8001F60C: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8001F610: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8001F614: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001F618: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001F61C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001F620: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001F624: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8001F628: swc1        $f0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f0.u32l;
    // 0x8001F62C: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8001F630: bc1f        L_8001F640
    if (!c1cs) {
        // 0x8001F634: swc1        $f8, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
            goto L_8001F640;
    }
    // 0x8001F634: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x8001F638: lwc1        $f18, -0x418($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X418);
    // 0x8001F63C: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
L_8001F640:
    // 0x8001F640: b           L_8001F794
    // 0x8001F644: sb          $a0, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r4;
        goto L_8001F794;
    // 0x8001F644: sb          $a0, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r4;
L_8001F648:
    // 0x8001F648: beql        $v0, $zero, L_8001F798
    if (ctx->r2 == 0) {
        // 0x8001F64C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001F798;
    }
    goto skip_4;
    // 0x8001F64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8001F650: lbu         $t3, 0x13($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X13);
    // 0x8001F654: bnel        $t3, $zero, L_8001F798
    if (ctx->r11 != 0) {
        // 0x8001F658: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001F798;
    }
    goto skip_5;
    // 0x8001F658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8001F65C: beq         $v1, $zero, L_8001F674
    if (ctx->r3 == 0) {
        // 0x8001F660: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_8001F674;
    }
    // 0x8001F660: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001F664: lhu         $t4, 0xC($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0XC);
    // 0x8001F668: addiu       $at, $zero, 0x45BE
    ctx->r1 = ADD32(0, 0X45BE);
    // 0x8001F66C: beql        $t4, $at, L_8001F798
    if (ctx->r12 == ctx->r1) {
        // 0x8001F670: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001F798;
    }
    goto skip_6;
    // 0x8001F670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
L_8001F674:
    // 0x8001F674: lw          $v0, -0x76F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X76F8);
    // 0x8001F678: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x8001F67C: lw          $t6, 0x9C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X9C);
    // 0x8001F680: beql        $t6, $zero, L_8001F734
    if (ctx->r14 == 0) {
        // 0x8001F684: lw          $t1, 0x24($t0)
        ctx->r9 = MEM_W(ctx->r8, 0X24);
            goto L_8001F734;
    }
    goto skip_7;
    // 0x8001F684: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    skip_7:
    // 0x8001F688: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8001F68C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001F690: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001F694: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8001F698: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8001F69C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8001F6A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001F6A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001F6A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8001F6AC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8001F6B0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8001F6B4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8001F6B8: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8001F6BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001F6C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8001F6C4: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8001F6C8: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8001F6CC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001F6D0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8001F6D4: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8001F6D8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001F6DC: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8001F6E0: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8001F6E4: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8001F6E8: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x8001F6EC: lw          $t9, 0x9C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X9C);
    // 0x8001F6F0: jalr        $t9
    // 0x8001F6F4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8001F6F4: nop

    after_1:
    // 0x8001F6F8: beq         $v0, $zero, L_8001F730
    if (ctx->r2 == 0) {
        // 0x8001F6FC: lw          $t0, 0x60($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X60);
            goto L_8001F730;
    }
    // 0x8001F6FC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001F700: lh          $t8, 0x13E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X13E);
    // 0x8001F704: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001F708: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001F70C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001F710: lwc1        $f16, 0x70($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8001F714: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F718: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8001F71C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001F720: nop

    // 0x8001F724: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8001F728: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8001F72C: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
L_8001F730:
    // 0x8001F730: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
L_8001F734:
    // 0x8001F734: andi        $t2, $t1, 0x700
    ctx->r10 = ctx->r9 & 0X700;
    // 0x8001F738: beq         $t2, $zero, L_8001F770
    if (ctx->r10 == 0) {
        // 0x8001F73C: nop
    
            goto L_8001F770;
    }
    // 0x8001F73C: nop

    // 0x8001F740: jal         0x8001D770
    // 0x8001F744: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8001F744: nop

    after_2:
    // 0x8001F748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F74C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001F750: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8001F754: jal         0x80067C68
    // 0x8001F758: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067C68(rdram, ctx);
        goto after_3;
    // 0x8001F758: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8001F75C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001F760: jal         0x80067818
    // 0x8001F764: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8001F764: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8001F768: b           L_8001F798
    // 0x8001F76C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001F798;
    // 0x8001F76C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001F770:
    // 0x8001F770: jal         0x8001D770
    // 0x8001F774: nop

    func_8001D770(rdram, ctx);
        goto after_5;
    // 0x8001F774: nop

    after_5:
    // 0x8001F778: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F77C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8001F780: jal         0x80067BF8
    // 0x8001F784: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_6;
    // 0x8001F784: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8001F788: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x8001F78C: jal         0x80067818
    // 0x8001F790: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8001F790: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
L_8001F794:
    // 0x8001F794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001F798:
    // 0x8001F798: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F79C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001F7A0: jr          $ra
    // 0x8001F7A4: nop

    return;
    // 0x8001F7A4: nop

;}
RECOMP_FUNC void func_804322F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804322F0: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x804322F4: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x804322F8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(59, 0X450) << 16);
    // 0x804322FC: lwc1        $f0, 0x2730($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(59, 0X450));
    // 0x80432300: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80432304: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80432308: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8043230C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80432310: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80432314: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80432318: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8043231C: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x80432320: lwc1        $f18, 0x88($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80432324: lwc1        $f16, 0x88($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X88);
    // 0x80432328: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8043232C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80432330: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80432334: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80432338: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8043233C: bc1f        L_80432348
    if (!c1cs) {
        // 0x80432340: swc1        $f6, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
            goto L_80432348;
    }
    // 0x80432340: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
    // 0x80432344: swc1        $f2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f2.u32l;
L_80432348:
    // 0x80432348: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8043234C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80432350: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80432354: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80432358: nop

    // 0x8043235C: bc1fl       L_8043236C
    if (!c1cs) {
        // 0x80432360: lwc1        $f0, 0x8($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X8);
            goto L_8043236C;
    }
    goto skip_0;
    // 0x80432360: lwc1        $f0, 0x8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8);
    skip_0:
    // 0x80432364: swc1        $f0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f0.u32l;
    // 0x80432368: lwc1        $f0, 0x8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8);
L_8043236C:
    // 0x8043236C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80432370: nop

    // 0x80432374: bc1fl       L_80432384
    if (!c1cs) {
        // 0x80432378: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80432384;
    }
    goto skip_1;
    // 0x80432378: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x8043237C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80432380: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80432384:
    // 0x80432384: swc1        $f0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f0.u32l;
    // 0x80432388: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8043238C: nop

    // 0x80432390: bc1fl       L_804323A0
    if (!c1cs) {
        // 0x80432394: lwc1        $f16, 0x4($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
            goto L_804323A0;
    }
    goto skip_2;
    // 0x80432394: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    skip_2:
    // 0x80432398: swc1        $f2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f2.u32l;
    // 0x8043239C: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
L_804323A0:
    // 0x804323A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804323A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804323A8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x804323AC: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x804323B0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x804323B4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804323B8: jr          $ra
    // 0x804323BC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x804323BC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8079AEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079AEDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079AEE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8079AEE4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8079AEE8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8079AEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079AEF0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8079AEF4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8079AEF8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8079AEFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8079AF00: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8079AF04: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8079AF08: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8079AF0C: lui         $t2, 0x807A
    ctx->r10 = S32(RELOC_HI16(826, 0X2534) << 16);
    // 0x8079AF10: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8079AF14: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8079AF18: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8079AF1C: lw          $t2, -0x4FAC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(826, 0X2534));
    // 0x8079AF20: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8079AF24: jal         0x80799DA4
    // 0x8079AF28: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80799DA4(rdram, ctx);
        goto after_0;
    // 0x8079AF28: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8079AF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079AF30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079AF34: jr          $ra
    // 0x8079AF38: nop

    return;
    // 0x8079AF38: nop

    // 0x8079AF3C: nop

;}
RECOMP_FUNC void func_80715A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715A88: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80715A8C: jal         0x80715840
    // 0x80715A90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80715840(rdram, ctx);
        goto after_0;
    // 0x80715A90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80715A94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80715A98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80715A9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80715AA0: lui         $t7, 0x8071
    ctx->r15 = S32(RELOC_HI16(730, 0XCB8) << 16);
    // 0x80715AA4: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x80715AA8: addiu       $t7, $t7, 0x54D8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(730, 0XCB8));
    // 0x80715AAC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x80715AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80715AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715AB8: jr          $ra
    // 0x80715ABC: nop

    return;
    // 0x80715ABC: nop

;}
RECOMP_FUNC void func_805D79EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D79EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805D79F0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x805D79F4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x805D79F8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x805D79FC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x805D7A00: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x805D7A04: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x805D7A08: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x805D7A0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805D7A10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805D7A14: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x805D7A18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805D7A1C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805D7A20: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x805D7A24: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805D7A28: jal         0x805D7F84
    // 0x805D7A2C: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    func_805D7F84(rdram, ctx);
        goto after_0;
    // 0x805D7A2C: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x805D7A30: beq         $v0, $zero, L_805D7B48
    if (ctx->r2 == 0) {
        // 0x805D7A34: nop
    
            goto L_805D7B48;
    }
    // 0x805D7A34: nop

    // 0x805D7A38: jal         0x805D7FBC
    // 0x805D7A3C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_805D7FBC(rdram, ctx);
        goto after_1;
    // 0x805D7A3C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x805D7A40: lw          $t9, 0x16C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X16C);
    // 0x805D7A44: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x805D7A48: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x805D7A4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805D7A50: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(474, 0X2478) << 16);
    // 0x805D7A54: sw          $t6, 0x130($s5)
    MEM_W(0X130, ctx->r21) = ctx->r14;
    // 0x805D7A58: sb          $t7, 0x165($s5)
    MEM_B(0X165, ctx->r21) = ctx->r15;
    // 0x805D7A5C: addiu       $t8, $t8, -0x6288
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(474, 0X2478));
    // 0x805D7A60: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x805D7A64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805D7A68: sw          $zero, 0x1E0($s5)
    MEM_W(0X1E0, ctx->r21) = 0;
    // 0x805D7A6C: sw          $zero, 0x138($s5)
    MEM_W(0X138, ctx->r21) = 0;
    // 0x805D7A70: sh          $t0, 0x144($s5)
    MEM_H(0X144, ctx->r21) = ctx->r8;
    // 0x805D7A74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x805D7A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D7A7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805D7A80: jal         0x805D8AB4
    // 0x805D7A84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805D8AB4(rdram, ctx);
        goto after_2;
    // 0x805D7A84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x805D7A88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805D7A8C: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(474, 0X2570) << 16);
    // 0x805D7A90: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x805D7A94: swc1        $f0, 0xE8($s5)
    MEM_W(0XE8, ctx->r21) = ctx->f0.u32l;
    // 0x805D7A98: swc1        $f0, 0xDC($s5)
    MEM_W(0XDC, ctx->r21) = ctx->f0.u32l;
    // 0x805D7A9C: swc1        $f0, 0xC4($s5)
    MEM_W(0XC4, ctx->r21) = ctx->f0.u32l;
    // 0x805D7AA0: swc1        $f0, 0xE0($s5)
    MEM_W(0XE0, ctx->r21) = ctx->f0.u32l;
    // 0x805D7AA4: swc1        $f0, 0xC8($s5)
    MEM_W(0XC8, ctx->r21) = ctx->f0.u32l;
    // 0x805D7AA8: lwc1        $f10, -0x6190($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(474, 0X2570));
    // 0x805D7AAC: jal         0x805D79A8
    // 0x805D7AB0: swc1        $f10, 0xEC($s5)
    MEM_W(0XEC, ctx->r21) = ctx->f10.u32l;
    func_805D79A8(rdram, ctx);
        goto after_3;
    // 0x805D7AB0: swc1        $f10, 0xEC($s5)
    MEM_W(0XEC, ctx->r21) = ctx->f10.u32l;
    after_3:
    // 0x805D7AB4: lw          $s1, 0x1F4($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X1F4);
    // 0x805D7AB8: lui         $s2, 0x805E
    ctx->r18 = S32(RELOC_HI16(474, 0X2488) << 16);
    // 0x805D7ABC: lui         $s4, 0x805E
    ctx->r20 = S32(RELOC_HI16(474, 0X24A8) << 16);
    // 0x805D7AC0: lui         $s7, 0x805E
    ctx->r23 = S32(RELOC_HI16(474, 0X24A8) << 16);
    // 0x805D7AC4: lui         $s6, 0x805E
    ctx->r22 = S32(RELOC_HI16(474, 0X2494) << 16);
    // 0x805D7AC8: addiu       $s6, $s6, -0x626C
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(474, 0X2494));
    // 0x805D7ACC: addiu       $s7, $s7, -0x6258
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(474, 0X24A8));
    // 0x805D7AD0: addiu       $s4, $s4, -0x6258
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(474, 0X24A8));
    // 0x805D7AD4: addiu       $s2, $s2, -0x6278
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(474, 0X2488));
    // 0x805D7AD8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x805D7ADC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
L_805D7AE0:
    // 0x805D7AE0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x805D7AE4: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x805D7AE8: jal         0x805D8AF8
    // 0x805D7AEC: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    func_805D8AF8(rdram, ctx);
        goto after_4;
    // 0x805D7AEC: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    after_4:
    // 0x805D7AF0: bne         $v0, $zero, L_805D7B08
    if (ctx->r2 != 0) {
        // 0x805D7AF4: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_805D7B08;
    }
    // 0x805D7AF4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x805D7AF8: jal         0x800445A4
    // 0x805D7AFC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x805D7AFC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x805D7B00: b           L_805D7B54
    // 0x805D7B04: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_805D7B54;
    // 0x805D7B04: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_805D7B08:
    // 0x805D7B08: addu        $s0, $s6, $s3
    ctx->r16 = ADD32(ctx->r22, ctx->r19);
    // 0x805D7B0C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x805D7B10: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x805D7B14: jalr        $t9
    // 0x805D7B18: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x805D7B18: nop

    after_6:
    // 0x805D7B1C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x805D7B20: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x805D7B24: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x805D7B28: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x805D7B2C: bne         $s0, $s7, L_805D7AE0
    if (ctx->r16 != ctx->r23) {
        // 0x805D7B30: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_805D7AE0;
    }
    // 0x805D7B30: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x805D7B34: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x805D7B38: jal         0x805D84A4
    // 0x805D7B3C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_805D84A4(rdram, ctx);
        goto after_7;
    // 0x805D7B3C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x805D7B40: b           L_805D7B54
    // 0x805D7B44: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_805D7B54;
    // 0x805D7B44: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_805D7B48:
    // 0x805D7B48: jal         0x800445A4
    // 0x805D7B4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x805D7B4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x805D7B50: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_805D7B54:
    // 0x805D7B54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805D7B58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805D7B5C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x805D7B60: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x805D7B64: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x805D7B68: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x805D7B6C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x805D7B70: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x805D7B74: jr          $ra
    // 0x805D7B78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805D7B78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_805ADF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADF04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADF08: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADF0C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADF10: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADF14: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADF18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADF1C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADF20: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADF24: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADF28: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADF2C: jr          $ra
    // 0x805ADF30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADF30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806EFAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EFAB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EFABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EFAC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EFAC4: jal         0x8004700C
    // 0x806EFAC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EFAC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EFACC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EFAD0: jal         0x806EC16C
    // 0x806EFAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC16C(rdram, ctx);
        goto after_1;
    // 0x806EFAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EFAD8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EFADC: jal         0x800577D8
    // 0x806EFAE0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_2;
    // 0x806EFAE0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x806EFAE4: jal         0x806EF504
    // 0x806EFAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF504(rdram, ctx);
        goto after_3;
    // 0x806EFAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EFAEC: jal         0x806EF584
    // 0x806EFAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF584(rdram, ctx);
        goto after_4;
    // 0x806EFAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EFAF4: jal         0x806EF5CC
    // 0x806EFAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF5CC(rdram, ctx);
        goto after_5;
    // 0x806EFAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EFAFC: jal         0x806EF638
    // 0x806EFB00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF638(rdram, ctx);
        goto after_6;
    // 0x806EFB00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806EFB04: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806EFB08: beql        $t7, $zero, L_806EFBC8
    if (ctx->r15 == 0) {
        // 0x806EFB0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EFBC8;
    }
    goto skip_0;
    // 0x806EFB0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EFB10: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806EFB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EFB18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFB1C: blez        $v0, L_806EFBBC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806EFB20: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_806EFBBC;
    }
    // 0x806EFB20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EFB24: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x806EFB28: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x806EFB2C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806EFB30: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x806EFB34: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806EFB38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EFB3C: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x806EFB40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EFB44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFB48: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806EFB4C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806EFB50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806EFB54: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806EFB58: nop

    // 0x806EFB5C: bc1f        L_806EFB88
    if (!c1cs) {
        // 0x806EFB60: nop
    
            goto L_806EFB88;
    }
    // 0x806EFB60: nop

    // 0x806EFB64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EFB68: jal         0x806F0348
    // 0x806EFB6C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_7;
    // 0x806EFB6C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806EFB70: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D7C) << 16);
    // 0x806EFB74: lwc1        $f14, 0xCCC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D7C));
    // 0x806EFB78: jal         0x806EC03C
    // 0x806EFB7C: lwc1        $f12, 0xEC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
    func_806EC03C(rdram, ctx);
        goto after_8;
    // 0x806EFB7C: lwc1        $f12, 0xEC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
    after_8:
    // 0x806EFB80: b           L_806EFBC4
    // 0x806EFB84: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
        goto L_806EFBC4;
    // 0x806EFB84: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
L_806EFB88:
    // 0x806EFB88: jal         0x806EBFB8
    // 0x806EFB8C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_806EBFB8(rdram, ctx);
        goto after_9;
    // 0x806EFB8C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_9:
    // 0x806EFB90: bnel        $v0, $zero, L_806EFBC8
    if (ctx->r2 != 0) {
        // 0x806EFB94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EFBC8;
    }
    goto skip_1;
    // 0x806EFB94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806EFB98: jal         0x806EF560
    // 0x806EFB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF560(rdram, ctx);
        goto after_10;
    // 0x806EFB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x806EFBA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EFBA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFBA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EFBAC: jal         0x806F0348
    // 0x806EFBB0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_11;
    // 0x806EFBB0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_11:
    // 0x806EFBB4: b           L_806EFBC8
    // 0x806EFBB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EFBC8;
    // 0x806EFBB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EFBBC:
    // 0x806EFBBC: jal         0x806F0348
    // 0x806EFBC0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_12;
    // 0x806EFBC0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_12:
L_806EFBC4:
    // 0x806EFBC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EFBC8:
    // 0x806EFBC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EFBCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EFBD0: jr          $ra
    // 0x806EFBD4: nop

    return;
    // 0x806EFBD4: nop

;}
RECOMP_FUNC void func_8044B604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B604: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044B608: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13554) << 16);
    // 0x8044B60C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B610: addiu       $t6, $t6, 0x7934
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13554));
    // 0x8044B614: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044B618: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044B61C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044B620: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044B624: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044B628: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B62C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044B630: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044B634: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044B638: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044B63C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044B640: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044B644: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B648: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044B64C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044B650: jal         0x80050A50
    // 0x8044B654: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044B654: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044B658: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044B65C: jalr        $v0
    // 0x8044B660: sw          $v0, 0x6A90($v1)
    MEM_W(0X6A90, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044B660: sw          $v0, 0x6A90($v1)
    MEM_W(0X6A90, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044B664: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B668: sw          $v0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r2;
    // 0x8044B66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B670: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044B674: jr          $ra
    // 0x8044B678: nop

    return;
    // 0x8044B678: nop

;}
RECOMP_FUNC void func_80521C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521C58: jal         0x80047090
    // 0x80521C5C: addiu       $a0, $zero, 0x41DB
    ctx->r4 = ADD32(0, 0X41DB);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80521C5C: addiu       $a0, $zero, 0x41DB
    ctx->r4 = ADD32(0, 0X41DB);
    after_0:
    // 0x80521C60: lui         $at, 0x41DB
    ctx->r1 = S32(0X41DB << 16);
    // 0x80521C64: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x80521C68: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80521C6C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80521C70: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80521C74: jal         0x8004613C
    // 0x80521C78: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80521C78: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_1:
    // 0x80521C7C: bne         $v0, $zero, L_80521C8C
    if (ctx->r2 != 0) {
        // 0x80521C80: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80521C8C;
    }
    // 0x80521C80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80521C84: b           L_80521C90
    // 0x80521C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80521C90;
    // 0x80521C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80521C8C:
    // 0x80521C8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80521C90:
    // 0x80521C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80521C98: jr          $ra
    // 0x80521C9C: nop

    return;
    // 0x80521C9C: nop

;}
RECOMP_FUNC void func_804234C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804234C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804234C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804234C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804234CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804234D0: jal         0x80045A34
    // 0x804234D4: addiu       $a1, $zero, 0x828
    ctx->r5 = ADD32(0, 0X828);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804234D4: addiu       $a1, $zero, 0x828
    ctx->r5 = ADD32(0, 0X828);
    after_0:
    // 0x804234D8: bne         $v0, $zero, L_804234E8
    if (ctx->r2 != 0) {
        // 0x804234DC: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_804234E8;
    }
    // 0x804234DC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804234E0: b           L_80423594
    // 0x804234E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80423594;
    // 0x804234E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804234E8:
    // 0x804234E8: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(35, 0X718) << 16);
    // 0x804234EC: addiu       $t6, $t6, 0x3118
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(35, 0X718));
    // 0x804234F0: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x804234F4: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x804234F8: addiu       $a1, $zero, 0x828
    ctx->r5 = ADD32(0, 0X828);
    // 0x804234FC: jal         0x80065728
    // 0x80423500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x80423500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80423504: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    // 0x80423508: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8042350C: jal         0x80422FA8
    // 0x80423510: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80422FA8(rdram, ctx);
        goto after_2;
    // 0x80423510: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x80423514: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80423518: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042351C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80423520: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80423524: swc1        $f0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f0.u32l;
    // 0x80423528: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042352C: swc1        $f0, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f0.u32l;
    // 0x80423530: addiu       $v1, $v1, 0xA4
    ctx->r3 = ADD32(ctx->r3, 0XA4);
L_80423534:
    // 0x80423534: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80423538: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8042353C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80423540: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80423544: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80423548: bne         $v0, $a0, L_80423534
    if (ctx->r2 != ctx->r4) {
        // 0x8042354C: swc1        $f0, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->f0.u32l;
            goto L_80423534;
    }
    // 0x8042354C: swc1        $f0, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f0.u32l;
    // 0x80423550: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x80423554: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80423558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042355C: sh          $t8, 0xE8($t9)
    MEM_H(0XE8, ctx->r25) = ctx->r24;
    // 0x80423560: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x80423564: swc1        $f0, 0x98($t0)
    MEM_W(0X98, ctx->r8) = ctx->f0.u32l;
    // 0x80423568: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042356C: lwc1        $f2, 0x98($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X98);
    // 0x80423570: swc1        $f2, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f2.u32l;
    // 0x80423574: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x80423578: jal         0x804233F4
    // 0x8042357C: swc1        $f2, 0x90($t1)
    MEM_W(0X90, ctx->r9) = ctx->f2.u32l;
    func_804233F4(rdram, ctx);
        goto after_3;
    // 0x8042357C: swc1        $f2, 0x90($t1)
    MEM_W(0X90, ctx->r9) = ctx->f2.u32l;
    after_3:
    // 0x80423580: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x80423584: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X944) << 16);
    // 0x80423588: addiu       $t2, $t2, 0x3344
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(35, 0X944));
    // 0x8042358C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80423590: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
L_80423594:
    // 0x80423594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80423598: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042359C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804235A0: jr          $ra
    // 0x804235A4: nop

    return;
    // 0x804235A4: nop

;}
RECOMP_FUNC void func_8000D6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D6BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000D6C0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8000D6C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D6C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000D6CC: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x8000D6D0: lw          $a3, 0x50($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X50);
    // 0x8000D6D4: bne         $a3, $zero, L_8000D704
    if (ctx->r7 != 0) {
        // 0x8000D6D8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8000D704;
    }
    // 0x8000D6D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000D6DC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000D6E0: addiu       $a0, $a0, -0x63C4
    ctx->r4 = ADD32(ctx->r4, -0X63C4);
    // 0x8000D6E4: jal         0x8000DBD4
    // 0x8000D6E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8000DBD4(rdram, ctx);
        goto after_0;
    // 0x8000D6E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000D6EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D6F0: bne         $v0, $zero, L_8000D710
    if (ctx->r2 != 0) {
        // 0x8000D6F4: sw          $v0, 0x50($a2)
        MEM_W(0X50, ctx->r6) = ctx->r2;
            goto L_8000D710;
    }
    // 0x8000D6F4: sw          $v0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r2;
    // 0x8000D6F8: sw          $zero, 0x50($a2)
    MEM_W(0X50, ctx->r6) = 0;
    // 0x8000D6FC: b           L_8000D7D0
    // 0x8000D700: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D7D0;
    // 0x8000D700: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D704:
    // 0x8000D704: jal         0x8000BBF4
    // 0x8000D708: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8000BBF4(rdram, ctx);
        goto after_1;
    // 0x8000D708: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8000D70C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_8000D710:
    // 0x8000D710: lw          $v1, 0x50($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X50);
    // 0x8000D714: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000D718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D71C: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8000D720: sw          $t8, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r24;
    // 0x8000D724: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000D728: ori         $t5, $t3, 0x80
    ctx->r13 = ctx->r11 | 0X80;
    // 0x8000D72C: andi        $t7, $t5, 0xBF
    ctx->r15 = ctx->r13 & 0XBF;
    // 0x8000D730: lw          $t1, 0x84($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X84);
    // 0x8000D734: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000D738: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000D73C: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x8000D740: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x8000D744: andi        $t9, $t7, 0xDF
    ctx->r25 = ctx->r15 & 0XDF;
    // 0x8000D748: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8000D74C: andi        $t1, $t9, 0xEF
    ctx->r9 = ctx->r25 & 0XEF;
    // 0x8000D750: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x8000D754: andi        $t3, $t1, 0xF7
    ctx->r11 = ctx->r9 & 0XF7;
    // 0x8000D758: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x8000D75C: andi        $t5, $t3, 0xFB
    ctx->r13 = ctx->r11 & 0XFB;
    // 0x8000D760: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8000D764: andi        $t7, $t5, 0xFD
    ctx->r15 = ctx->r13 & 0XFD;
    // 0x8000D768: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x8000D76C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8000D770: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8000D774: sw          $t0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r8;
    // 0x8000D778: andi        $t8, $t7, 0xFE
    ctx->r24 = ctx->r15 & 0XFE;
    // 0x8000D77C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8000D780: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8000D784: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x8000D788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D78C: sb          $zero, 0x18($v1)
    MEM_B(0X18, ctx->r3) = 0;
    // 0x8000D790: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8000D794: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x8000D798: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
    // 0x8000D79C: sb          $zero, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = 0;
    // 0x8000D7A0: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    // 0x8000D7A4: sb          $a0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r4;
    // 0x8000D7A8: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x8000D7AC: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x8000D7B0: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8000D7B4: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x8000D7B8: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x8000D7BC: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    // 0x8000D7C0: sb          $t0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r8;
    // 0x8000D7C4: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x8000D7C8: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8000D7CC: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
L_8000D7D0:
    // 0x8000D7D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D7D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000D7D8: jr          $ra
    // 0x8000D7DC: nop

    return;
    // 0x8000D7DC: nop

;}
RECOMP_FUNC void func_8003A5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A5BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003A5C0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8003A5C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003A5C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003A5CC: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x8003A5D0: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8003A5D4: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x8003A5D8: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x8003A5DC: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x8003A5E0: lwc1        $f6, 0x1E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1E0);
    // 0x8003A5E4: jr          $ra
    // 0x8003A5E8: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8003A5E8: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80789DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789DA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80789DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80789DA8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80789DAC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80789DB0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80789DB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80789DB8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80789DBC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80789DC0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(790, 0X504) << 16);
    // 0x80789DC4: lwc1        $f10, -0x5E4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(790, 0X504));
    // 0x80789DC8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80789DCC: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80789DD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80789DD4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80789DD8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80789DDC: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80789DE0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80789DE4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80789DE8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80789DEC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80789DF0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80789DF4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80789DF8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80789DFC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80789E00: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80789E04: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80789E08: jalr        $t9
    // 0x80789E0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80789E0C: nop

    after_0:
    // 0x80789E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80789E14: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80789E18: jr          $ra
    // 0x80789E1C: nop

    return;
    // 0x80789E1C: nop

;}
RECOMP_FUNC void func_807098C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807098C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807098C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807098C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807098CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807098D0: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x807098D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807098D8: jal         0x807095E4
    // 0x807098DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_807095E4(rdram, ctx);
        goto after_0;
    // 0x807098DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x807098E0: bne         $v0, $zero, L_807099C4
    if (ctx->r2 != 0) {
        // 0x807098E4: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_807099C4;
    }
    // 0x807098E4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x807098E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807098EC: jal         0x80048F84
    // 0x807098F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x807098F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x807098F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807098F8: jal         0x80048F84
    // 0x807098FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x807098FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80709900: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80709904: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80709908: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8070990C: nop

    // 0x80709910: bc1fl       L_807099B4
    if (!c1cs) {
        // 0x80709914: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807099B4;
    }
    goto skip_0;
    // 0x80709914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80709918: jal         0x80709860
    // 0x8070991C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80709860(rdram, ctx);
        goto after_3;
    // 0x8070991C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80709920: beql        $v0, $zero, L_807099B4
    if (ctx->r2 == 0) {
        // 0x80709924: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807099B4;
    }
    goto skip_1;
    // 0x80709924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80709928: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8070992C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80709930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80709934: bne         $v0, $at, L_80709984
    if (ctx->r2 != ctx->r1) {
        // 0x80709938: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80709984;
    }
    // 0x80709938: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070993C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80709940: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80709944: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80709948: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8070994C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80709950: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80709954: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80709958: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8070995C: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x80709960: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
    // 0x80709964: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x80709968: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x8070996C: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
    // 0x80709970: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x80709974: jal         0x80709CB8
    // 0x80709978: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80709CB8(rdram, ctx);
        goto after_4;
    // 0x80709978: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x8070997C: b           L_807099B4
    // 0x80709980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_807099B4;
    // 0x80709980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80709984:
    // 0x80709984: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80709988: bne         $v0, $at, L_807099B0
    if (ctx->r2 != ctx->r1) {
        // 0x8070998C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807099B0;
    }
    // 0x8070998C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80709990: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80709994: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80709998: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x8070999C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807099A0: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x807099A4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x807099A8: jal         0x80709CB8
    // 0x807099AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80709CB8(rdram, ctx);
        goto after_5;
    // 0x807099AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
L_807099B0:
    // 0x807099B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_807099B4:
    // 0x807099B4: jal         0x80709744
    // 0x807099B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80709744(rdram, ctx);
        goto after_6;
    // 0x807099B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x807099BC: jal         0x80709620
    // 0x807099C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80709620(rdram, ctx);
        goto after_7;
    // 0x807099C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_807099C4:
    // 0x807099C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807099C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807099CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807099D0: jr          $ra
    // 0x807099D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807099D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_807C6548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C654C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C6550: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(913, 0X96C) << 16);
    // 0x807C6554: lwc1        $f4, 0x675C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(913, 0X96C));
    // 0x807C6558: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807C655C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807C6560: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(913, 0X970) << 16);
    // 0x807C6564: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x807C6568: nop

    // 0x807C656C: bc1fl       L_807C6594
    if (!c1cs) {
        // 0x807C6570: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_807C6594;
    }
    goto skip_0;
    // 0x807C6570: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x807C6574: lwc1        $f2, 0x6760($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(913, 0X970));
    // 0x807C6578: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807C657C: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x807C6580: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x807C6584: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x807C6588: b           L_807C65C8
    // 0x807C658C: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
        goto L_807C65C8;
    // 0x807C658C: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x807C6590: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_807C6594:
    // 0x807C6594: jal         0x800447C8
    // 0x807C6598: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x807C6598: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x807C659C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807C65A0: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x807C65A4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807C65A8: lui         $a1, 0x807C
    ctx->r5 = S32(RELOC_HI16(913, 0X928) << 16);
    // 0x807C65AC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x807C65B0: addiu       $a1, $a1, 0x6718
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(913, 0X928));
    // 0x807C65B4: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x807C65B8: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x807C65BC: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x807C65C0: jalr        $t9
    // 0x807C65C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x807C65C4: nop

    after_1:
L_807C65C8:
    // 0x807C65C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C65CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C65D0: jr          $ra
    // 0x807C65D4: nop

    return;
    // 0x807C65D4: nop

;}
RECOMP_FUNC void func_8040DCD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040DCD8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8040DCDC: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(20, 0X3AC) << 16);
    // 0x8040DCE0: addiu       $t6, $t6, -0x3654
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(20, 0X3AC));
    // 0x8040DCE4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8040DCE8: jr          $ra
    // 0x8040DCEC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8040DCEC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80447000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447004: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447008: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044700C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447010: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447014: bne         $a2, $zero, L_80447050
    if (ctx->r6 != 0) {
        // 0x80447018: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80447050;
    }
    // 0x80447018: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044701C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80447020: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x80447024: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80447028: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8044702C: bne         $at, $zero, L_8044708C
    if (ctx->r1 != 0) {
        // 0x80447030: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_8044708C;
    }
    // 0x80447030: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80447034: jal         0x80445EC8
    // 0x80447038: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445EC8(rdram, ctx);
        goto after_0;
    // 0x80447038: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8044703C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447040: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447044: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447048: b           L_8044708C
    // 0x8044704C: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_8044708C;
    // 0x8044704C: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
L_80447050:
    // 0x80447050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447054: bnel        $a2, $at, L_8044707C
    if (ctx->r6 != ctx->r1) {
        // 0x80447058: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8044707C;
    }
    goto skip_0;
    // 0x80447058: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8044705C: jal         0x80445EC8
    // 0x80447060: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445EC8(rdram, ctx);
        goto after_1;
    // 0x80447060: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80447064: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447068: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044706C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447070: b           L_8044708C
    // 0x80447074: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_8044708C;
    // 0x80447074: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
    // 0x80447078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8044707C:
    // 0x8044707C: bnel        $a2, $at, L_80447090
    if (ctx->r6 != ctx->r1) {
        // 0x80447080: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447090;
    }
    goto skip_1;
    // 0x80447080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447084: jal         0x80445F04
    // 0x80447088: nop

    func_80445F04(rdram, ctx);
        goto after_2;
    // 0x80447088: nop

    after_2:
L_8044708C:
    // 0x8044708C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447090:
    // 0x80447090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447098: jr          $ra
    // 0x8044709C: nop

    return;
    // 0x8044709C: nop

;}
RECOMP_FUNC void func_80792F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80792F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80792F88: jal         0x80790714
    // 0x80792F8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80790714(rdram, ctx);
        goto after_0;
    // 0x80792F8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80792F90: beq         $v0, $zero, L_80792FA8
    if (ctx->r2 == 0) {
        // 0x80792F94: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80792FA8;
    }
    // 0x80792F94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80792F98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792F9C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80792FA0: jal         0x8079393C
    // 0x80792FA4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_1;
    // 0x80792FA4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
L_80792FA8:
    // 0x80792FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80792FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80792FB0: jr          $ra
    // 0x80792FB4: nop

    return;
    // 0x80792FB4: nop

;}
RECOMP_FUNC void func_80436EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436EAC: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80436EB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80436EB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436EBC: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80436EC0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80436EC4: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x80436EC8: bc1t        L_80436EE8
    if (c1cs) {
        // 0x80436ECC: nop
    
            goto L_80436EE8;
    }
    // 0x80436ECC: nop

    // 0x80436ED0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80436ED4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80436ED8: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80436EDC: nop

    // 0x80436EE0: bc1fl       L_80436EFC
    if (!c1cs) {
        // 0x80436EE4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80436EFC;
    }
    goto skip_0;
    // 0x80436EE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
L_80436EE8:
    // 0x80436EE8: jal         0x80066E88
    // 0x80436EEC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80436EEC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_0:
    // 0x80436EF0: b           L_80436F30
    // 0x80436EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80436F30;
    // 0x80436EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80436EF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80436EFC:
    // 0x80436EFC: nop

    // 0x80436F00: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x80436F04: nop

    // 0x80436F08: bc1f        L_80436F20
    if (!c1cs) {
        // 0x80436F0C: nop
    
            goto L_80436F20;
    }
    // 0x80436F0C: nop

    // 0x80436F10: jal         0x80436E3C
    // 0x80436F14: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    func_80436E3C(rdram, ctx);
        goto after_1;
    // 0x80436F14: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    after_1:
    // 0x80436F18: b           L_80436F30
    // 0x80436F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80436F30;
    // 0x80436F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80436F20:
    // 0x80436F20: jal         0x80436E3C
    // 0x80436F24: sub.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f0.fl;
    func_80436E3C(rdram, ctx);
        goto after_2;
    // 0x80436F24: sub.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f0.fl;
    after_2:
    // 0x80436F28: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80436F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80436F30:
    // 0x80436F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436F34: jr          $ra
    // 0x80436F38: nop

    return;
    // 0x80436F38: nop

;}
RECOMP_FUNC void func_8044AD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AD74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044AD78: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X134D4) << 16);
    // 0x8044AD7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AD80: addiu       $t6, $t6, 0x78B4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X134D4));
    // 0x8044AD84: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044AD88: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044AD8C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044AD90: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044AD94: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044AD98: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044AD9C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044ADA0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044ADA4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044ADA8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044ADAC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044ADB0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044ADB4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044ADB8: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044ADBC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044ADC0: jal         0x80050A50
    // 0x8044ADC4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044ADC4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044ADC8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044ADCC: jalr        $v0
    // 0x8044ADD0: sw          $v0, 0x6A60($v1)
    MEM_W(0X6A60, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044ADD0: sw          $v0, 0x6A60($v1)
    MEM_W(0X6A60, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044ADD4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044ADD8: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x8044ADDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044ADE0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044ADE4: jr          $ra
    // 0x8044ADE8: nop

    return;
    // 0x8044ADE8: nop

;}
RECOMP_FUNC void func_80034E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034E20: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034E24: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80034E28: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80034E2C: beql        $t8, $zero, L_80034E80
    if (ctx->r24 == 0) {
        // 0x80034E30: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80034E80;
    }
    goto skip_0;
    // 0x80034E30: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x80034E34: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80034E38: jal         0x80065954
    // 0x80034E3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80034E3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034E40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034E44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034E48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80034E4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034E50: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80034E54: nop

    // 0x80034E58: bc1f        L_80034E70
    if (!c1cs) {
        // 0x80034E5C: nop
    
            goto L_80034E70;
    }
    // 0x80034E5C: nop

    // 0x80034E60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034E64: lwc1        $f6, 0xC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XC8);
    // 0x80034E68: b           L_80034E88
    // 0x80034E6C: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
        goto L_80034E88;
    // 0x80034E6C: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
L_80034E70:
    // 0x80034E70: lwc1        $f8, 0xCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XCC);
    // 0x80034E74: b           L_80034E88
    // 0x80034E78: swc1        $f8, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f8.u32l;
        goto L_80034E88;
    // 0x80034E78: swc1        $f8, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f8.u32l;
    // 0x80034E7C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80034E80:
    // 0x80034E80: nop

    // 0x80034E84: swc1        $f10, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f10.u32l;
L_80034E88:
    // 0x80034E88: jal         0x80023EA0
    // 0x80034E8C: nop

    func_80023EA0(rdram, ctx);
        goto after_1;
    // 0x80034E8C: nop

    after_1:
    // 0x80034E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034E98: jr          $ra
    // 0x80034E9C: nop

    return;
    // 0x80034E9C: nop

;}
RECOMP_FUNC void func_80051AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051AC4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80051AC8: andi        $s2, $a2, 0xFF
    ctx->r18 = ctx->r6 & 0XFF;
    // 0x80051ACC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80051AD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80051AD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80051AD8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80051ADC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80051AE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80051AE4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80051AE8: beq         $s2, $zero, L_80051B28
    if (ctx->r18 == 0) {
        // 0x80051AEC: andi        $s1, $s2, 0xFF
        ctx->r17 = ctx->r18 & 0XFF;
            goto L_80051B28;
    }
    // 0x80051AEC: andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
L_80051AF0:
    // 0x80051AF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80051AF4: beq         $v0, $zero, L_80051B20
    if (ctx->r2 == 0) {
        // 0x80051AF8: nop
    
            goto L_80051B20;
    }
    // 0x80051AF8: nop

    // 0x80051AFC: lbu         $t6, 0x94($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X94);
    // 0x80051B00: bnel        $t6, $zero, L_80051B1C
    if (ctx->r14 != 0) {
        // 0x80051B04: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80051B1C;
    }
    goto skip_0;
    // 0x80051B04: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x80051B08: jalr        $s3
    // 0x80051B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_0;
    // 0x80051B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80051B10: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80051B14: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80051B18: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80051B1C:
    // 0x80051B1C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
L_80051B20:
    // 0x80051B20: bne         $s1, $zero, L_80051AF0
    if (ctx->r17 != 0) {
        // 0x80051B24: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80051AF0;
    }
    // 0x80051B24: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80051B28:
    // 0x80051B28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80051B2C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80051B30: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80051B34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80051B38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80051B3C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80051B40: jr          $ra
    // 0x80051B44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80051B44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804369D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804369D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804369DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804369E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804369E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804369E8: jal         0x80047090
    // 0x804369EC: addiu       $a0, $zero, 0x407A
    ctx->r4 = ADD32(0, 0X407A);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804369EC: addiu       $a0, $zero, 0x407A
    ctx->r4 = ADD32(0, 0X407A);
    after_0:
    // 0x804369F0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804369F4: bne         $v0, $at, L_80436A04
    if (ctx->r2 != ctx->r1) {
        // 0x804369F8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80436A04;
    }
    // 0x804369F8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804369FC: b           L_80436AC0
    // 0x80436A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80436AC0;
    // 0x80436A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80436A04:
    // 0x80436A04: lui         $at, 0x407A
    ctx->r1 = S32(0X407A << 16);
    // 0x80436A08: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80436A0C: lui         $a2, 0xBF66
    ctx->r6 = S32(0XBF66 << 16);
    // 0x80436A10: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x80436A14: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80436A18: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80436A1C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80436A20: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80436A24: jal         0x8004613C
    // 0x80436A28: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80436A28: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_1:
    // 0x80436A2C: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x80436A30: bne         $v0, $zero, L_80436A40
    if (ctx->r2 != 0) {
        // 0x80436A34: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80436A40;
    }
    // 0x80436A34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80436A38: b           L_80436AC0
    // 0x80436A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80436AC0;
    // 0x80436A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80436A40:
    // 0x80436A40: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x80436A44: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x80436A48: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x80436A4C: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80436A50: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80436A54: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80436A58: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(77, 0X1EC0) << 16);
    // 0x80436A5C: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x80436A60: sw          $t1, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r9;
    // 0x80436A64: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80436A68: addiu       $t2, $t2, -0x78A0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(77, 0X1EC0));
    // 0x80436A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80436A70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80436A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80436A78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80436A7C: jal         0x80436AD4
    // 0x80436A80: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    func_80436AD4(rdram, ctx);
        goto after_2;
    // 0x80436A80: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    after_2:
    // 0x80436A84: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80436A88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80436A8C: jal         0x80047F9C
    // 0x80436A90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80436A90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80436A94: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80436A98: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80436A9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80436AA0: lwc1        $f4, 0x6C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x80436AA4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80436AA8: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x80436AAC: lwc1        $f6, 0x70($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X70);
    // 0x80436AB0: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x80436AB4: lwc1        $f8, 0x74($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80436AB8: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
    // 0x80436ABC: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
L_80436AC0:
    // 0x80436AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80436AC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80436AC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80436ACC: jr          $ra
    // 0x80436AD0: nop

    return;
    // 0x80436AD0: nop

;}
RECOMP_FUNC void func_806A7D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A7D34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806A7D38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806A7D3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806A7D40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806A7D44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806A7D48: jal         0x80047090
    // 0x806A7D4C: addiu       $a0, $zero, 0x4582
    ctx->r4 = ADD32(0, 0X4582);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806A7D4C: addiu       $a0, $zero, 0x4582
    ctx->r4 = ADD32(0, 0X4582);
    after_0:
    // 0x806A7D50: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806A7D54: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x806A7D58: beq         $v0, $at, L_806A7DDC
    if (ctx->r2 == ctx->r1) {
        // 0x806A7D5C: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_806A7DDC;
    }
    // 0x806A7D5C: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x806A7D60: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x806A7D64: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(586, 0X4F0) << 16);
    // 0x806A7D68: lui         $at, 0x4582
    ctx->r1 = S32(0X4582 << 16);
    // 0x806A7D6C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x806A7D70: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x806A7D74: or          $a1, $t0, $at
    ctx->r5 = ctx->r8 | ctx->r1;
    // 0x806A7D78: addiu       $a0, $a0, 0x7EB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(586, 0X4F0));
    // 0x806A7D7C: jal         0x80046804
    // 0x806A7D80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x806A7D80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x806A7D84: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806A7D88: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x806A7D8C: beq         $v0, $zero, L_806A7DDC
    if (ctx->r2 == 0) {
        // 0x806A7D90: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_806A7DDC;
    }
    // 0x806A7D90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806A7D94: beq         $v1, $zero, L_806A7DB4
    if (ctx->r3 == 0) {
        // 0x806A7D98: nop
    
            goto L_806A7DB4;
    }
    // 0x806A7D98: nop

    // 0x806A7D9C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806A7DA0: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x806A7DA4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806A7DA8: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x806A7DAC: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x806A7DB0: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_806A7DB4:
    // 0x806A7DB4: beq         $t2, $zero, L_806A7DCC
    if (ctx->r10 == 0) {
        // 0x806A7DB8: nop
    
            goto L_806A7DCC;
    }
    // 0x806A7DB8: nop

    // 0x806A7DBC: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x806A7DC0: swc1        $f16, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f16.u32l;
    // 0x806A7DC4: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x806A7DC8: swc1        $f18, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f18.u32l;
L_806A7DCC:
    // 0x806A7DCC: jal         0x80044194
    // 0x806A7DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806A7DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x806A7DD4: b           L_806A7DE0
    // 0x806A7DD8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_806A7DE0;
    // 0x806A7DD8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_806A7DDC:
    // 0x806A7DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806A7DE0:
    // 0x806A7DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806A7DE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806A7DE8: jr          $ra
    // 0x806A7DEC: nop

    return;
    // 0x806A7DEC: nop

;}
RECOMP_FUNC void func_805DA040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DA044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA048: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x805DA04C: addiu       $at, $zero, 0x4538
    ctx->r1 = ADD32(0, 0X4538);
    // 0x805DA050: beq         $v0, $at, L_805DA068
    if (ctx->r2 == ctx->r1) {
        // 0x805DA054: addiu       $at, $zero, 0x46ED
        ctx->r1 = ADD32(0, 0X46ED);
            goto L_805DA068;
    }
    // 0x805DA054: addiu       $at, $zero, 0x46ED
    ctx->r1 = ADD32(0, 0X46ED);
    // 0x805DA058: beq         $v0, $at, L_805DA07C
    if (ctx->r2 == ctx->r1) {
        // 0x805DA05C: addiu       $at, $zero, 0x471B
        ctx->r1 = ADD32(0, 0X471B);
            goto L_805DA07C;
    }
    // 0x805DA05C: addiu       $at, $zero, 0x471B
    ctx->r1 = ADD32(0, 0X471B);
    // 0x805DA060: bnel        $v0, $at, L_805DA08C
    if (ctx->r2 != ctx->r1) {
        // 0x805DA064: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805DA08C;
    }
    goto skip_0;
    // 0x805DA064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_805DA068:
    // 0x805DA068: jal         0x805DA09C
    // 0x805DA06C: nop

    func_805DA09C(rdram, ctx);
        goto after_0;
    // 0x805DA06C: nop

    after_0:
    // 0x805DA070: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(477, 0X94C) << 16);
    // 0x805DA074: b           L_805DA08C
    // 0x805DA078: addiu       $v0, $v0, -0x5674
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(477, 0X94C));
        goto L_805DA08C;
    // 0x805DA078: addiu       $v0, $v0, -0x5674
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(477, 0X94C));
L_805DA07C:
    // 0x805DA07C: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(477, 0X94C) << 16);
    // 0x805DA080: b           L_805DA08C
    // 0x805DA084: addiu       $v0, $v0, -0x5674
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(477, 0X94C));
        goto L_805DA08C;
    // 0x805DA084: addiu       $v0, $v0, -0x5674
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(477, 0X94C));
    // 0x805DA088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805DA08C:
    // 0x805DA08C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DA094: jr          $ra
    // 0x805DA098: nop

    return;
    // 0x805DA098: nop

;}
RECOMP_FUNC void func_80780DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780DC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80780DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80780DCC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80780DD0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80780DD4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80780DD8: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80780DDC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80780DE0: lbu         $t9, 0x10($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X10);
    // 0x80780DE4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80780DE8: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80780DEC: addiu       $t3, $t9, 0x5
    ctx->r11 = ADD32(ctx->r25, 0X5);
    // 0x80780DF0: slti        $at, $t3, 0xFF
    ctx->r1 = SIGNED(ctx->r11) < 0XFF ? 1 : 0;
    // 0x80780DF4: lw          $t1, 0x180($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X180);
    // 0x80780DF8: lw          $t2, 0x1F4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1F4);
    // 0x80780DFC: lw          $v1, 0x48($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X48);
    // 0x80780E00: bne         $at, $zero, L_80781038
    if (ctx->r1 != 0) {
        // 0x80780E04: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_80781038;
    }
    // 0x80780E04: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80780E08: lw          $t5, 0xF54($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XF54);
    // 0x80780E0C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80780E10: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80780E14: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80780E18: beq         $t6, $zero, L_80780F6C
    if (ctx->r14 == 0) {
        // 0x80780E1C: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_80780F6C;
    }
    // 0x80780E1C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80780E20: beq         $v1, $zero, L_80780E48
    if (ctx->r3 == 0) {
        // 0x80780E24: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80780E48;
    }
    // 0x80780E24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80780E28: beq         $v1, $at, L_80780E48
    if (ctx->r3 == ctx->r1) {
        // 0x80780E2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80780E48;
    }
    // 0x80780E2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80780E30: beq         $v1, $at, L_80780EC8
    if (ctx->r3 == ctx->r1) {
        // 0x80780E34: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80780EC8;
    }
    // 0x80780E34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80780E38: beq         $v1, $at, L_80780F4C
    if (ctx->r3 == ctx->r1) {
        // 0x80780E3C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80780F4C;
    }
    // 0x80780E3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80780E40: b           L_8078103C
    // 0x80780E44: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
        goto L_8078103C;
    // 0x80780E44: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_80780E48:
    // 0x80780E48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80780E4C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80780E50: jal         0x8006E0FC
    // 0x80780E54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x80780E54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80780E58: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80780E5C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80780E60: lw          $t7, 0xAC4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XAC4);
    // 0x80780E64: lw          $t8, 0xAC8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XAC8);
    // 0x80780E68: lw          $t0, 0xACC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XACC);
    // 0x80780E6C: lw          $t1, 0xAD0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XAD0);
    // 0x80780E70: lw          $t2, 0xAD4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XAD4);
    // 0x80780E74: lw          $t9, 0xBAC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBAC);
    // 0x80780E78: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80780E7C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80780E80: addiu       $a1, $a1, -0x75B0
    ctx->r5 = ADD32(ctx->r5, -0X75B0);
    // 0x80780E84: addiu       $a0, $a0, -0x762C
    ctx->r4 = ADD32(ctx->r4, -0X762C);
    // 0x80780E88: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x80780E8C: sw          $t7, 0xAB0($v0)
    MEM_W(0XAB0, ctx->r2) = ctx->r15;
    // 0x80780E90: sw          $t8, 0xAB4($v0)
    MEM_W(0XAB4, ctx->r2) = ctx->r24;
    // 0x80780E94: sw          $t0, 0xAB8($v0)
    MEM_W(0XAB8, ctx->r2) = ctx->r8;
    // 0x80780E98: sw          $t1, 0xABC($v0)
    MEM_W(0XABC, ctx->r2) = ctx->r9;
    // 0x80780E9C: sw          $t2, 0xAC0($v0)
    MEM_W(0XAC0, ctx->r2) = ctx->r10;
    // 0x80780EA0: jal         0x80065528
    // 0x80780EA4: sw          $t9, 0xB30($v0)
    MEM_W(0XB30, ctx->r2) = ctx->r25;
    func_80065528(rdram, ctx);
        goto after_1;
    // 0x80780EA4: sw          $t9, 0xB30($v0)
    MEM_W(0XB30, ctx->r2) = ctx->r25;
    after_1:
    // 0x80780EA8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80780EAC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80780EB0: addiu       $a1, $a1, -0x722C
    ctx->r5 = ADD32(ctx->r5, -0X722C);
    // 0x80780EB4: addiu       $a0, $a0, -0x724C
    ctx->r4 = ADD32(ctx->r4, -0X724C);
    // 0x80780EB8: jal         0x80065528
    // 0x80780EBC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80065528(rdram, ctx);
        goto after_2;
    // 0x80780EBC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_2:
    // 0x80780EC0: b           L_8078103C
    // 0x80780EC4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
        goto L_8078103C;
    // 0x80780EC4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_80780EC8:
    // 0x80780EC8: jal         0x80068D24
    // 0x80780ECC: nop

    func_80068D24(rdram, ctx);
        goto after_3;
    // 0x80780ECC: nop

    after_3:
    // 0x80780ED0: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80780ED4: lw          $t3, -0x7478($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7478);
    // 0x80780ED8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80780EDC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80780EE0: beq         $t3, $zero, L_80780F2C
    if (ctx->r11 == 0) {
        // 0x80780EE4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80780F2C;
    }
    // 0x80780EE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80780EE8: lw          $t4, 0xFB8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XFB8);
    // 0x80780EEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80780EF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80780EF4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80780EF8: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x80780EFC: bne         $t6, $at, L_80780F1C
    if (ctx->r14 != ctx->r1) {
        // 0x80780F00: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80780F1C;
    }
    // 0x80780F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80780F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80780F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80780F0C: jal         0x8006E0FC
    // 0x80780F10: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8006E0FC(rdram, ctx);
        goto after_4;
    // 0x80780F10: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_4:
    // 0x80780F14: b           L_8078103C
    // 0x80780F18: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
        goto L_8078103C;
    // 0x80780F18: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_80780F1C:
    // 0x80780F1C: jal         0x8006E0FC
    // 0x80780F20: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    func_8006E0FC(rdram, ctx);
        goto after_5;
    // 0x80780F20: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    after_5:
    // 0x80780F24: b           L_8078103C
    // 0x80780F28: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
        goto L_8078103C;
    // 0x80780F28: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_80780F2C:
    // 0x80780F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80780F30: jal         0x8006E0FC
    // 0x80780F34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_6;
    // 0x80780F34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80780F38: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80780F3C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80780F40: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80780F44: b           L_80781038
    // 0x80780F48: sw          $t7, 0xF60($v0)
    MEM_W(0XF60, ctx->r2) = ctx->r15;
        goto L_80781038;
    // 0x80780F48: sw          $t7, 0xF60($v0)
    MEM_W(0XF60, ctx->r2) = ctx->r15;
L_80780F4C:
    // 0x80780F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80780F50: jal         0x8006E0FC
    // 0x80780F54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_7;
    // 0x80780F54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80780F58: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80780F5C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80780F60: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80780F64: b           L_80781038
    // 0x80780F68: sw          $t8, 0xF60($v0)
    MEM_W(0XF60, ctx->r2) = ctx->r24;
        goto L_80781038;
    // 0x80780F68: sw          $t8, 0xF60($v0)
    MEM_W(0XF60, ctx->r2) = ctx->r24;
L_80780F6C:
    // 0x80780F6C: lw          $t0, -0x7478($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7478);
    // 0x80780F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80780F74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80780F78: beq         $t0, $zero, L_80780FC4
    if (ctx->r8 == 0) {
        // 0x80780F7C: nop
    
            goto L_80780FC4;
    }
    // 0x80780F7C: nop

    // 0x80780F80: lw          $t1, 0xFB8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XFB8);
    // 0x80780F84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80780F88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80780F8C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80780F90: srl         $t9, $t2, 30
    ctx->r25 = S32(U32(ctx->r10) >> 30);
    // 0x80780F94: bne         $t9, $at, L_80780FB4
    if (ctx->r25 != ctx->r1) {
        // 0x80780F98: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80780FB4;
    }
    // 0x80780F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80780F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80780FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80780FA4: jal         0x8006E0FC
    // 0x80780FA8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8006E0FC(rdram, ctx);
        goto after_8;
    // 0x80780FA8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_8:
    // 0x80780FAC: b           L_8078103C
    // 0x80780FB0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
        goto L_8078103C;
    // 0x80780FB0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_80780FB4:
    // 0x80780FB4: jal         0x8006E0FC
    // 0x80780FB8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    func_8006E0FC(rdram, ctx);
        goto after_9;
    // 0x80780FB8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    after_9:
    // 0x80780FBC: b           L_8078103C
    // 0x80780FC0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
        goto L_8078103C;
    // 0x80780FC0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_80780FC4:
    // 0x80780FC4: jal         0x8006E0FC
    // 0x80780FC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_10;
    // 0x80780FC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x80780FCC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80780FD0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80780FD4: lbu         $t4, 0xF6B($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XF6B);
    // 0x80780FD8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80780FDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80780FE0: beq         $t4, $at, L_80781034
    if (ctx->r12 == ctx->r1) {
        // 0x80780FE4: sw          $t3, 0xF60($v0)
        MEM_W(0XF60, ctx->r2) = ctx->r11;
            goto L_80781034;
    }
    // 0x80780FE4: sw          $t3, 0xF60($v0)
    MEM_W(0XF60, ctx->r2) = ctx->r11;
    // 0x80780FE8: lw          $t5, 0xF54($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XF54);
    // 0x80780FEC: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80780FF0: lbu         $t2, 0xFB8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XFB8);
    // 0x80780FF4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80780FF8: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80780FFC: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80781000: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80781004: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x80781008: sw          $t6, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r14;
    // 0x8078100C: ori         $at, $at, 0x3FFF
    ctx->r1 = ctx->r1 | 0X3FFF;
    // 0x80781010: sw          $t8, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r24;
    // 0x80781014: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x80781018: sb          $t3, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r11;
    // 0x8078101C: andi        $t4, $t3, 0xEF
    ctx->r12 = ctx->r11 & 0XEF;
    // 0x80781020: sw          $t1, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r9;
    // 0x80781024: jal         0x80780CEC
    // 0x80781028: sb          $t4, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r12;
    func_80780CEC(rdram, ctx);
        goto after_11;
    // 0x80781028: sb          $t4, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r12;
    after_11:
    // 0x8078102C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80781030: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
L_80781034:
    // 0x80781034: sw          $zero, 0xFB4($v0)
    MEM_W(0XFB4, ctx->r2) = 0;
L_80781038:
    // 0x80781038: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_8078103C:
    // 0x8078103C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80781040: sb          $t5, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r13;
    // 0x80781044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80781048: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078104C: jr          $ra
    // 0x80781050: nop

    return;
    // 0x80781050: nop

;}
RECOMP_FUNC void func_80536444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536444: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536448: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053644C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536450: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536454: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536458: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053645C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536460: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536464: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536468: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053646C: jr          $ra
    // 0x80536470: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536470: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805322EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805322EC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805322F0: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(342, 0X7B4) << 16);
    // 0x805322F4: addiu       $t6, $t6, 0x15A4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(342, 0X7B4));
    // 0x805322F8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805322FC: jr          $ra
    // 0x80532300: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x80532300: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8044A060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A060: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8044A064: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8044A068: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8044A06C: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X133D0) << 16);
    // 0x8044A070: lui         $a2, 0x8045
    ctx->r6 = S32(RELOC_HI16(98, 0X133F0) << 16);
    // 0x8044A074: lui         $a3, 0x8045
    ctx->r7 = S32(RELOC_HI16(98, 0X13410) << 16);
    // 0x8044A078: lui         $t3, 0x8045
    ctx->r11 = S32(RELOC_HI16(98, 0X13430) << 16);
    // 0x8044A07C: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8044A080: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8044A084: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8044A088: ori         $t1, $t1, 0x6ECC
    ctx->r9 = ctx->r9 | 0X6ECC;
    // 0x8044A08C: addiu       $t3, $t3, 0x7810
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(98, 0X13430));
    // 0x8044A090: addiu       $a3, $a3, 0x77F0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(98, 0X13410));
    // 0x8044A094: addiu       $a2, $a2, 0x77D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(98, 0X133F0));
    // 0x8044A098: addiu       $v1, $v1, 0x77B0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(98, 0X133D0));
    // 0x8044A09C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8044A0A0:
    // 0x8044A0A0: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8044A0A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8044A0A8: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8044A0AC: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8044A0B0: bne         $at, $zero, L_8044A0D8
    if (ctx->r1 != 0) {
        // 0x8044A0B4: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_8044A0D8;
    }
    // 0x8044A0B4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8044A0B8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8044A0BC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8044A0C0: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8044A0C4: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8044A0C8: bne         $at, $zero, L_8044A0D8
    if (ctx->r1 != 0) {
        // 0x8044A0CC: addu        $t9, $t8, $t1
        ctx->r25 = ADD32(ctx->r24, ctx->r9);
            goto L_8044A0D8;
    }
    // 0x8044A0CC: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8044A0D0: b           L_8044A0E4
    // 0x8044A0D4: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
        goto L_8044A0E4;
    // 0x8044A0D4: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
L_8044A0D8:
    // 0x8044A0D8: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8044A0DC: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x8044A0E0: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_8044A0E4:
    // 0x8044A0E4: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x8044A0E8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8044A0EC: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x8044A0F0: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8044A0F4: bne         $at, $zero, L_8044A118
    if (ctx->r1 != 0) {
        // 0x8044A0F8: lw          $t0, 0x1F4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1F4);
            goto L_8044A118;
    }
    // 0x8044A0F8: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8044A0FC: slt         $at, $a1, $s1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8044A100: bne         $at, $zero, L_8044A118
    if (ctx->r1 != 0) {
        // 0x8044A104: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8044A118;
    }
    // 0x8044A104: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8044A108: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8044A10C: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8044A110: b           L_8044A128
    // 0x8044A114: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
        goto L_8044A128;
    // 0x8044A114: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
L_8044A118:
    // 0x8044A118: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8044A11C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8044A120: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x8044A124: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_8044A128:
    // 0x8044A128: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8044A12C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8044A130: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x8044A134: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8044A138: bne         $at, $zero, L_8044A15C
    if (ctx->r1 != 0) {
        // 0x8044A13C: lw          $t0, 0x1F4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1F4);
            goto L_8044A15C;
    }
    // 0x8044A13C: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8044A140: slt         $at, $a1, $s1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8044A144: bne         $at, $zero, L_8044A15C
    if (ctx->r1 != 0) {
        // 0x8044A148: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8044A15C;
    }
    // 0x8044A148: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8044A14C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8044A150: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8044A154: b           L_8044A16C
    // 0x8044A158: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
        goto L_8044A16C;
    // 0x8044A158: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
L_8044A15C:
    // 0x8044A15C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8044A160: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8044A164: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x8044A168: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_8044A16C:
    // 0x8044A16C: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    // 0x8044A170: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8044A174: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x8044A178: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8044A17C: bne         $at, $zero, L_8044A1A0
    if (ctx->r1 != 0) {
        // 0x8044A180: lw          $t0, 0x1F4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1F4);
            goto L_8044A1A0;
    }
    // 0x8044A180: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8044A184: slt         $at, $a1, $s1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8044A188: bne         $at, $zero, L_8044A1A0
    if (ctx->r1 != 0) {
        // 0x8044A18C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8044A1A0;
    }
    // 0x8044A18C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8044A190: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8044A194: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8044A198: b           L_8044A1B0
    // 0x8044A19C: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
        goto L_8044A1B0;
    // 0x8044A19C: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
L_8044A1A0:
    // 0x8044A1A0: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8044A1A4: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8044A1A8: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x8044A1AC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_8044A1B0:
    // 0x8044A1B0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8044A1B4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8044A1B8: bne         $a3, $t3, L_8044A0A0
    if (ctx->r7 != ctx->r11) {
        // 0x8044A1BC: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8044A0A0;
    }
    // 0x8044A1BC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8044A1C0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8044A1C4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8044A1C8: jr          $ra
    // 0x8044A1CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8044A1CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_806EAEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAEC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EAEC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EAECC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EAED0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806EAED4: jal         0x806EA9C0
    // 0x806EAED8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_806EA9C0(rdram, ctx);
        goto after_0;
    // 0x806EAED8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x806EAEDC: jal         0x806EA92C
    // 0x806EAEE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806EA92C(rdram, ctx);
        goto after_1;
    // 0x806EAEE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806EAEE4: beq         $v0, $zero, L_806EAF04
    if (ctx->r2 == 0) {
        // 0x806EAEE8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806EAF04;
    }
    // 0x806EAEE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806EAEEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EAEF0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806EAEF4: jal         0x806EB43C
    // 0x806EAEF8: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806EB43C(rdram, ctx);
        goto after_2;
    // 0x806EAEF8: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x806EAEFC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x806EAF00: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_806EAF04:
    // 0x806EAF04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EAF08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EAF0C: jr          $ra
    // 0x806EAF10: nop

    return;
    // 0x806EAF10: nop

;}
RECOMP_FUNC void func_8002C7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C7D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C7DC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C7E0: addiu       $a1, $a1, -0x250C
    ctx->r5 = ADD32(ctx->r5, -0X250C);
    // 0x8002C7E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C7E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002C7EC: jal         0x80028118
    // 0x8002C7F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C7F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C7F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002C7F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002C7FC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002C800: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8002C804: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8002C808: sw          $zero, 0x44($t7)
    MEM_W(0X44, ctx->r15) = 0;
    // 0x8002C80C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8002C810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C814: sw          $t8, -0x7258($at)
    MEM_W(-0X7258, ctx->r1) = ctx->r24;
    // 0x8002C818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C81C: jr          $ra
    // 0x8002C820: nop

    return;
    // 0x8002C820: nop

;}
RECOMP_FUNC void func_806F0178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F0178: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F017C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F0180: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x806F0184: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x806F0188: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x806F018C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806F0190: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806F0194: jr          $ra
    // 0x806F0198: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x806F0198: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_805D2854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2854: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D2858: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D285C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D2860: jal         0x8004700C
    // 0x805D2864: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D2864: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805D2868: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x805D286C: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(471, 0XD94) << 16);
    // 0x805D2870: addiu       $t7, $t7, 0x27C4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(471, 0XD94));
    // 0x805D2874: beq         $t6, $zero, L_805D2884
    if (ctx->r14 == 0) {
        // 0x805D2878: nop
    
            goto L_805D2884;
    }
    // 0x805D2878: nop

    // 0x805D287C: b           L_805D2910
    // 0x805D2880: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
        goto L_805D2910;
    // 0x805D2880: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
L_805D2884:
    // 0x805D2884: beql        $v0, $zero, L_805D2914
    if (ctx->r2 == 0) {
        // 0x805D2888: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2914;
    }
    goto skip_0;
    // 0x805D2888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805D288C: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805D2890: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805D2894: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x805D2898: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x805D289C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805D28A0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805D28A4: nop

    // 0x805D28A8: bc1fl       L_805D28E8
    if (!c1cs) {
        // 0x805D28AC: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_805D28E8;
    }
    goto skip_1;
    // 0x805D28AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_1:
    // 0x805D28B0: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x805D28B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805D28B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D28BC: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x805D28C0: nop

    // 0x805D28C4: bc1fl       L_805D2914
    if (!c1cs) {
        // 0x805D28C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2914;
    }
    goto skip_2;
    // 0x805D28C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805D28CC: jal         0x805D1CC0
    // 0x805D28D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805D1CC0(rdram, ctx);
        goto after_1;
    // 0x805D28D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805D28D4: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(471, 0XD94) << 16);
    // 0x805D28D8: addiu       $t8, $t8, 0x27C4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(471, 0XD94));
    // 0x805D28DC: b           L_805D2910
    // 0x805D28E0: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
        goto L_805D2910;
    // 0x805D28E0: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x805D28E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_805D28E8:
    // 0x805D28E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D28EC: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x805D28F0: nop

    // 0x805D28F4: bc1fl       L_805D2914
    if (!c1cs) {
        // 0x805D28F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2914;
    }
    goto skip_3;
    // 0x805D28F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805D28FC: jal         0x805D1CC0
    // 0x805D2900: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805D1CC0(rdram, ctx);
        goto after_2;
    // 0x805D2900: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x805D2904: lui         $t9, 0x805D
    ctx->r25 = S32(RELOC_HI16(471, 0XD94) << 16);
    // 0x805D2908: addiu       $t9, $t9, 0x27C4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(471, 0XD94));
    // 0x805D290C: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
L_805D2910:
    // 0x805D2910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D2914:
    // 0x805D2914: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D2918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D291C: jr          $ra
    // 0x805D2920: nop

    return;
    // 0x805D2920: nop

;}
RECOMP_FUNC void func_80704670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80704670: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80704674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80704678: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070467C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80704680: jal         0x8004700C
    // 0x80704684: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80704684: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x80704688: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8070468C: beq         $v0, $zero, L_807048C0
    if (ctx->r2 == 0) {
        // 0x80704690: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_807048C0;
    }
    // 0x80704690: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80704694: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80704698: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8070469C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807046A0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x807046A4: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x807046A8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x807046AC: nop

    // 0x807046B0: bc1fl       L_807046D8
    if (!c1cs) {
        // 0x807046B4: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_807046D8;
    }
    goto skip_0;
    // 0x807046B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x807046B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807046BC: nop

    // 0x807046C0: swc1        $f0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f0.u32l;
    // 0x807046C4: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807046C8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x807046CC: b           L_807046E0
    // 0x807046D0: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
        goto L_807046E0;
    // 0x807046D0: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x807046D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_807046D8:
    // 0x807046D8: nop

    // 0x807046DC: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
L_807046E0:
    // 0x807046E0: lw          $v1, 0x30($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X30);
    // 0x807046E4: beq         $v1, $zero, L_807046F0
    if (ctx->r3 == 0) {
        // 0x807046E8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_807046F0;
    }
    // 0x807046E8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x807046EC: sw          $t6, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r14;
L_807046F0:
    // 0x807046F0: lhu         $t7, 0xC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC);
    // 0x807046F4: addiu       $at, $zero, 0x4607
    ctx->r1 = ADD32(0, 0X4607);
    // 0x807046F8: beql        $t7, $at, L_80704718
    if (ctx->r15 == ctx->r1) {
        // 0x807046FC: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_80704718;
    }
    goto skip_1;
    // 0x807046FC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    skip_1:
    // 0x80704700: lwc1        $f18, 0x3C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80704704: swc1        $f18, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f18.u32l;
    // 0x80704708: lwc1        $f12, 0x84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8070470C: b           L_80704740
    // 0x80704710: lwc1        $f2, 0x84($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X84);
        goto L_80704740;
    // 0x80704710: lwc1        $f2, 0x84($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80704714: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_80704718:
    // 0x80704718: lwc1        $f12, 0x84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8070471C: lwc1        $f2, 0x84($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80704720: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80704724: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80704728: nop

    // 0x8070472C: bc1fl       L_80704744
    if (!c1cs) {
        // 0x80704730: sub.s       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_80704744;
    }
    goto skip_2;
    // 0x80704730: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    skip_2:
    // 0x80704734: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
    // 0x80704738: lwc1        $f12, 0x84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8070473C: lwc1        $f2, 0x84($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X84);
L_80704740:
    // 0x80704740: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
L_80704744:
    // 0x80704744: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80704748: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8070474C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80704750: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80704754: nop

    // 0x80704758: bc1fl       L_80704770
    if (!c1cs) {
        // 0x8070475C: lw          $v0, 0x2C($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X2C);
            goto L_80704770;
    }
    goto skip_3;
    // 0x8070475C: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    skip_3:
    // 0x80704760: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x80704764: beql        $v0, $zero, L_80704784
    if (ctx->r2 == 0) {
        // 0x80704768: lui         $at, 0x4380
        ctx->r1 = S32(0X4380 << 16);
            goto L_80704784;
    }
    goto skip_4;
    // 0x80704768: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    skip_4:
    // 0x8070476C: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
L_80704770:
    // 0x80704770: beql        $v0, $zero, L_80704860
    if (ctx->r2 == 0) {
        // 0x80704774: lw          $v0, 0x20($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X20);
            goto L_80704860;
    }
    goto skip_5;
    // 0x80704774: lw          $v0, 0x20($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X20);
    skip_5:
    // 0x80704778: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x8070477C: bne         $t9, $zero, L_8070485C
    if (ctx->r25 != 0) {
        // 0x80704780: lui         $at, 0x4380
        ctx->r1 = S32(0X4380 << 16);
            goto L_8070485C;
    }
    // 0x80704780: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
L_80704784:
    // 0x80704784: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80704788: lwc1        $f2, 0x4($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8070478C: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80704790: sub.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80704794: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80704798: nop

    // 0x8070479C: bc1fl       L_807047B4
    if (!c1cs) {
        // 0x807047A0: add.s       $f12, $f2, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f16.fl;
            goto L_807047B4;
    }
    goto skip_6;
    // 0x807047A0: add.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f16.fl;
    skip_6:
    // 0x807047A4: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x807047A8: bne         $t1, $zero, L_807047F0
    if (ctx->r9 != 0) {
        // 0x807047AC: nop
    
            goto L_807047F0;
    }
    // 0x807047AC: nop

    // 0x807047B0: add.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f16.fl;
L_807047B4:
    // 0x807047B4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x807047B8: nop

    // 0x807047BC: bc1fl       L_807047D4
    if (!c1cs) {
        // 0x807047C0: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_807047D4;
    }
    goto skip_7;
    // 0x807047C0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_7:
    // 0x807047C4: lw          $t2, 0x138($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X138);
    // 0x807047C8: beq         $t2, $zero, L_807047F0
    if (ctx->r10 == 0) {
        // 0x807047CC: nop
    
            goto L_807047F0;
    }
    // 0x807047CC: nop

    // 0x807047D0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_807047D4:
    // 0x807047D4: nop

    // 0x807047D8: bc1fl       L_80704860
    if (!c1cs) {
        // 0x807047DC: lw          $v0, 0x20($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X20);
            goto L_80704860;
    }
    goto skip_8;
    // 0x807047DC: lw          $v0, 0x20($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X20);
    skip_8:
    // 0x807047E0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x807047E4: nop

    // 0x807047E8: bc1fl       L_80704860
    if (!c1cs) {
        // 0x807047EC: lw          $v0, 0x20($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X20);
            goto L_80704860;
    }
    goto skip_9;
    // 0x807047EC: lw          $v0, 0x20($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X20);
    skip_9:
L_807047F0:
    // 0x807047F0: bne         $v0, $zero, L_80704844
    if (ctx->r2 != 0) {
        // 0x807047F4: lui         $t3, 0x8010
        ctx->r11 = S32(0X8010 << 16);
            goto L_80704844;
    }
    // 0x807047F4: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x807047F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807047FC: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x80704800: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80704804: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80704808: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8070480C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80704810: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80704814: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80704818: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    // 0x8070481C: lw          $t9, 0x40($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X40);
    // 0x80704820: lui         $a3, 0xC1D0
    ctx->r7 = S32(0XC1D0 << 16);
    // 0x80704824: jalr        $t9
    // 0x80704828: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80704828: nop

    after_1:
    // 0x8070482C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80704830: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80704834: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80704838: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8070483C: sw          $t5, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r13;
    // 0x80704840: sw          $t6, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r14;
L_80704844:
    // 0x80704844: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
    // 0x80704848: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070484C: jal         0x80705A5C
    // 0x80704850: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80705A5C(rdram, ctx);
        goto after_2;
    // 0x80704850: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80704854: b           L_807048C4
    // 0x80704858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807048C4;
    // 0x80704858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8070485C:
    // 0x8070485C: lw          $v0, 0x20($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X20);
L_80704860:
    // 0x80704860: beq         $v0, $zero, L_80704870
    if (ctx->r2 == 0) {
        // 0x80704864: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80704870;
    }
    // 0x80704864: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80704868: sw          $t7, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r15;
    // 0x8070486C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80704870:
    // 0x80704870: bne         $v0, $zero, L_807048B0
    if (ctx->r2 != 0) {
        // 0x80704874: nop
    
            goto L_807048B0;
    }
    // 0x80704874: nop

    // 0x80704878: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x8070487C: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(709, 0X3598) << 16);
    // 0x80704880: lui         $t1, 0x8070
    ctx->r9 = S32(RELOC_HI16(709, 0X35A8) << 16);
    // 0x80704884: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80704888: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8070488C: lw          $t8, 0x6A08($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(709, 0X3598));
    // 0x80704890: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x80704894: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80704898: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x8070489C: lw          $t1, 0x6A18($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(709, 0X35A8));
    // 0x807048A0: sw          $t2, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r10;
    // 0x807048A4: andi        $t4, $t2, 0x3
    ctx->r12 = ctx->r10 & 0X3;
    // 0x807048A8: sw          $t4, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r12;
    // 0x807048AC: sw          $t1, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r9;
L_807048B0:
    // 0x807048B0: jal         0x8070384C
    // 0x807048B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8070384C(rdram, ctx);
        goto after_3;
    // 0x807048B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
    // 0x807048B8: jal         0x80703F10
    // 0x807048BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80703F10(rdram, ctx);
        goto after_4;
    // 0x807048BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_807048C0:
    // 0x807048C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807048C4:
    // 0x807048C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807048C8: jr          $ra
    // 0x807048CC: nop

    return;
    // 0x807048CC: nop

;}
RECOMP_FUNC void func_8006E620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E620: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E624: addiu       $v0, $v0, -0x19D0
    ctx->r2 = ADD32(ctx->r2, -0X19D0);
    // 0x8006E628: jr          $ra
    // 0x8006E62C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006E62C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807B64DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B64DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807B64E0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x807B64E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B64E8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x807B64EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807B64F0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B64F4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B64F8: lui         $a0, 0x402C
    ctx->r4 = S32(0X402C << 16);
    // 0x807B64FC: lui         $a3, 0xBB03
    ctx->r7 = S32(0XBB03 << 16);
    // 0x807B6500: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807B6504: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x807B6508: lui         $a1, 0x42D0
    ctx->r5 = S32(0X42D0 << 16);
    // 0x807B650C: jal         0x8004613C
    // 0x807B6510: lui         $a2, 0xC23C
    ctx->r6 = S32(0XC23C << 16);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x807B6510: lui         $a2, 0xC23C
    ctx->r6 = S32(0XC23C << 16);
    after_0:
    // 0x807B6514: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x807B6518: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x807B651C: sb          $s2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r18;
    // 0x807B6520: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x807B6524: jal         0x80047F9C
    // 0x807B6528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x807B6528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x807B652C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EC8) << 16);
    // 0x807B6530: lwc1        $f0, 0x76C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EC8));
    // 0x807B6534: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x807B6538: lui         $a0, 0x4025
    ctx->r4 = S32(0X4025 << 16);
    // 0x807B653C: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x807B6540: swc1        $f0, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f0.u32l;
    // 0x807B6544: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x807B6548: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807B654C: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x807B6550: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x807B6554: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x807B6558: jal         0x8004613C
    // 0x807B655C: swc1        $f0, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f0.u32l;
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x807B655C: swc1        $f0, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f0.u32l;
    after_2:
    // 0x807B6560: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x807B6564: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B6568: jal         0x80047F9C
    // 0x807B656C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x807B656C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x807B6570: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x807B6574: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2ECC) << 16);
    // 0x807B6578: addiu       $a0, $zero, 0x4021
    ctx->r4 = ADD32(0, 0X4021);
    // 0x807B657C: sb          $s2, 0x31($t8)
    MEM_B(0X31, ctx->r24) = ctx->r18;
    // 0x807B6580: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x807B6584: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x807B6588: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x807B658C: lw          $t0, 0x16C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X16C);
    // 0x807B6590: lui         $a3, 0xC288
    ctx->r7 = S32(0XC288 << 16);
    // 0x807B6594: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
    // 0x807B6598: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x807B659C: sb          $s2, 0x165($t1)
    MEM_B(0X165, ctx->r9) = ctx->r18;
    // 0x807B65A0: lwc1        $f4, 0x76CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2ECC));
    // 0x807B65A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x807B65A8: jal         0x8005CEBC
    // 0x807B65AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_4;
    // 0x807B65AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x807B65B0: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x807B65B4: sb          $s2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r18;
    // 0x807B65B8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x807B65BC: jal         0x80047F9C
    // 0x807B65C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x807B65C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x807B65C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B65C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B65CC: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x807B65D0: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x807B65D4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x807B65D8: swc1        $f0, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f0.u32l;
    // 0x807B65DC: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x807B65E0: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2ED0) << 16);
    // 0x807B65E4: addiu       $a0, $zero, 0x4022
    ctx->r4 = ADD32(0, 0X4022);
    // 0x807B65E8: swc1        $f0, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f0.u32l;
    // 0x807B65EC: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x807B65F0: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x807B65F4: lui         $a2, 0x4268
    ctx->r6 = S32(0X4268 << 16);
    // 0x807B65F8: lw          $v0, 0x16C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X16C);
    // 0x807B65FC: lui         $a3, 0xC1B8
    ctx->r7 = S32(0XC1B8 << 16);
    // 0x807B6600: sb          $t5, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r13;
    // 0x807B6604: sb          $v1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r3;
    // 0x807B6608: sb          $v1, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r3;
    // 0x807B660C: lwc1        $f6, 0x76D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2ED0));
    // 0x807B6610: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x807B6614: jal         0x8005CEBC
    // 0x807B6618: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_6;
    // 0x807B6618: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x807B661C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x807B6620: sb          $s2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r18;
    // 0x807B6624: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x807B6628: jal         0x80047F9C
    // 0x807B662C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x807B662C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x807B6630: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B6634: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B6638: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x807B663C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2ED4) << 16);
    // 0x807B6640: addiu       $a0, $zero, 0x4023
    ctx->r4 = ADD32(0, 0X4023);
    // 0x807B6644: swc1        $f0, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f0.u32l;
    // 0x807B6648: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x807B664C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x807B6650: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x807B6654: swc1        $f0, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f0.u32l;
    // 0x807B6658: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x807B665C: lui         $a3, 0x4240
    ctx->r7 = S32(0X4240 << 16);
    // 0x807B6660: lw          $v0, 0x16C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X16C);
    // 0x807B6664: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x807B6668: lwc1        $f8, 0x76D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2ED4));
    // 0x807B666C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x807B6670: jal         0x8005CEBC
    // 0x807B6674: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_8;
    // 0x807B6674: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x807B6678: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x807B667C: sb          $s2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r18;
    // 0x807B6680: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x807B6684: jal         0x80047F9C
    // 0x807B6688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x807B6688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x807B668C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2ED8) << 16);
    // 0x807B6690: lwc1        $f0, 0x76D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2ED8));
    // 0x807B6694: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x807B6698: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x807B669C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B66A0: swc1        $f0, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f0.u32l;
    // 0x807B66A4: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x807B66A8: addiu       $a0, $zero, 0x40F2
    ctx->r4 = ADD32(0, 0X40F2);
    // 0x807B66AC: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x807B66B0: swc1        $f0, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->f0.u32l;
    // 0x807B66B4: lw          $t1, -0x7478($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7478);
    // 0x807B66B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x807B66BC: lui         $a3, 0x4240
    ctx->r7 = S32(0X4240 << 16);
    // 0x807B66C0: bne         $t1, $at, L_807B6728
    if (ctx->r9 != ctx->r1) {
        // 0x807B66C4: lui         $at, 0x807B
        ctx->r1 = S32(RELOC_HI16(880, 0X2EDC) << 16);
            goto L_807B6728;
    }
    // 0x807B66C4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EDC) << 16);
    // 0x807B66C8: lwc1        $f10, 0x76DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EDC));
    // 0x807B66CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x807B66D0: jal         0x8005CEBC
    // 0x807B66D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_10;
    // 0x807B66D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x807B66D8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x807B66DC: sb          $s2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r18;
    // 0x807B66E0: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x807B66E4: jal         0x80047F9C
    // 0x807B66E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_11;
    // 0x807B66E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x807B66EC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EE4) << 16);
    // 0x807B66F0: lwc1        $f0, 0x76E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EE4));
    // 0x807B66F4: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x807B66F8: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x807B66FC: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x807B6700: swc1        $f0, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f0.u32l;
    // 0x807B6704: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x807B6708: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x807B670C: swc1        $f0, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f0.u32l;
    // 0x807B6710: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x807B6714: lw          $v0, 0x16C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X16C);
    // 0x807B6718: sb          $t5, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r13;
    // 0x807B671C: sb          $t6, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r14;
    // 0x807B6720: b           L_807B672C
    // 0x807B6724: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
        goto L_807B672C;
    // 0x807B6724: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
L_807B6728:
    // 0x807B6728: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
L_807B672C:
    // 0x807B672C: jal         0x807B634C
    // 0x807B6730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807B634C(rdram, ctx);
        goto after_12;
    // 0x807B6730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x807B6734: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x807B6738: lw          $t8, -0x7478($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7478);
    // 0x807B673C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B6740: bne         $t8, $at, L_807B6758
    if (ctx->r24 != ctx->r1) {
        // 0x807B6744: nop
    
            goto L_807B6758;
    }
    // 0x807B6744: nop

    // 0x807B6748: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x807B674C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x807B6750: b           L_807B6760
    // 0x807B6754: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
        goto L_807B6760;
    // 0x807B6754: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_807B6758:
    // 0x807B6758: jal         0x807B63C4
    // 0x807B675C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807B63C4(rdram, ctx);
        goto after_13;
    // 0x807B675C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
L_807B6760:
    // 0x807B6760: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B6764: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807B6768: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x807B676C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x807B6770: jr          $ra
    // 0x807B6774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807B6774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80582CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582CB4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80582CB8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80582CBC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80582CC0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80582CC4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80582CC8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80582CCC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80582CD0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80582CD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80582CD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80582CDC: jal         0x8057EF14
    // 0x80582CE0: addiu       $a1, $zero, 0x40F1
    ctx->r5 = ADD32(0, 0X40F1);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x80582CE0: addiu       $a1, $zero, 0x40F1
    ctx->r5 = ADD32(0, 0X40F1);
    after_0:
    // 0x80582CE4: beq         $v0, $zero, L_80582DBC
    if (ctx->r2 == 0) {
        // 0x80582CE8: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_80582DBC;
    }
    // 0x80582CE8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80582CEC: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80582CF0: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80582CF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80582CF8: addiu       $s2, $zero, 0x70
    ctx->r18 = ADD32(0, 0X70);
    // 0x80582CFC: addiu       $s3, $zero, 0x80
    ctx->r19 = ADD32(0, 0X80);
    // 0x80582D00: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    // 0x80582D04: addiu       $s5, $sp, 0x58
    ctx->r21 = ADD32(ctx->r29, 0X58);
    // 0x80582D08: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
L_80582D0C:
    // 0x80582D0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80582D10: jal         0x805824D8
    // 0x80582D14: lhu         $a1, 0xFC0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XFC0);
    func_805824D8(rdram, ctx);
        goto after_1;
    // 0x80582D14: lhu         $a1, 0xFC0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XFC0);
    after_1:
    // 0x80582D18: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80582D1C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80582D20: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80582D24: jal         0x805826F4
    // 0x80582D28: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_805826F4(rdram, ctx);
        goto after_2;
    // 0x80582D28: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_2:
    // 0x80582D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582D30: jal         0x80069644
    // 0x80582D34: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80069644(rdram, ctx);
        goto after_3;
    // 0x80582D34: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x80582D38: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80582D3C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80582D40: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80582D44: jal         0x80582804
    // 0x80582D48: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80582804(rdram, ctx);
        goto after_4;
    // 0x80582D48: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_4:
    // 0x80582D4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80582D50: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80582D54: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // 0x80582D58: bne         $s0, $s7, L_80582D0C
    if (ctx->r16 != ctx->r23) {
        // 0x80582D5C: addiu       $s3, $s3, 0x30
        ctx->r19 = ADD32(ctx->r19, 0X30);
            goto L_80582D0C;
    }
    // 0x80582D5C: addiu       $s3, $s3, 0x30
    ctx->r19 = ADD32(ctx->r19, 0X30);
    // 0x80582D60: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80582D64: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x80582D68: lw          $v0, 0xCF0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XCF0);
    // 0x80582D6C: addiu       $s1, $zero, 0x30
    ctx->r17 = ADD32(0, 0X30);
    // 0x80582D70: beql        $v0, $zero, L_80582DC0
    if (ctx->r2 == 0) {
        // 0x80582D74: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80582DC0;
    }
    goto skip_0;
    // 0x80582D74: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80582D78: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582D7C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80582D80: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80582D84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80582D88: mflo        $a3
    ctx->r7 = lo;
    // 0x80582D8C: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x80582D90: jal         0x805829E0
    // 0x80582D94: nop

    func_805829E0(rdram, ctx);
        goto after_5;
    // 0x80582D94: nop

    after_5:
    // 0x80582D98: lw          $t6, 0xCF0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XCF0);
    // 0x80582D9C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80582DA0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80582DA4: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80582DA8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80582DAC: mflo        $a3
    ctx->r7 = lo;
    // 0x80582DB0: addiu       $a3, $a3, 0x50
    ctx->r7 = ADD32(ctx->r7, 0X50);
    // 0x80582DB4: jal         0x805829E0
    // 0x80582DB8: nop

    func_805829E0(rdram, ctx);
        goto after_6;
    // 0x80582DB8: nop

    after_6:
L_80582DBC:
    // 0x80582DBC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80582DC0:
    // 0x80582DC0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80582DC4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80582DC8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80582DCC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80582DD0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80582DD4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80582DD8: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80582DDC: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80582DE0: jr          $ra
    // 0x80582DE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80582DE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80028620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028624: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80028628: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002862C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80028630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028634: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x80028638: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002863C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80028640: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80028644: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80028648: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8002864C: beql        $a3, $zero, L_80028668
    if (ctx->r7 == 0) {
        // 0x80028650: lbu         $t7, 0x1F8($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X1F8);
            goto L_80028668;
    }
    goto skip_0;
    // 0x80028650: lbu         $t7, 0x1F8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1F8);
    skip_0:
    // 0x80028654: jal         0x80028504
    // 0x80028658: nop

    func_80028504(rdram, ctx);
        goto after_0;
    // 0x80028658: nop

    after_0:
    // 0x8002865C: b           L_800286C8
    // 0x80028660: nop

        goto L_800286C8;
    // 0x80028660: nop

    // 0x80028664: lbu         $t7, 0x1F8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1F8);
L_80028668:
    // 0x80028668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002866C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80028670: beq         $t7, $zero, L_800286C0
    if (ctx->r15 == 0) {
        // 0x80028674: nop
    
            goto L_800286C0;
    }
    // 0x80028674: nop

    // 0x80028678: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x8002867C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80028680: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80028684: beq         $a2, $zero, L_800286C0
    if (ctx->r6 == 0) {
        // 0x80028688: nop
    
            goto L_800286C0;
    }
    // 0x80028688: nop

    // 0x8002868C: lw          $t8, 0x3EC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X3EC);
    // 0x80028690: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80028694: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80028698: lbu         $v0, 0x598($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X598);
    // 0x8002869C: beq         $v0, $at, L_800286C0
    if (ctx->r2 == ctx->r1) {
        // 0x800286A0: addiu       $at, $zero, 0xA3
        ctx->r1 = ADD32(0, 0XA3);
            goto L_800286C0;
    }
    // 0x800286A0: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x800286A4: beq         $v0, $at, L_800286C0
    if (ctx->r2 == ctx->r1) {
        // 0x800286A8: or          $a3, $s2, $zero
        ctx->r7 = ctx->r18 | 0;
            goto L_800286C0;
    }
    // 0x800286A8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800286AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800286B0: jal         0x80028574
    // 0x800286B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80028574(rdram, ctx);
        goto after_1;
    // 0x800286B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800286B8: b           L_800286C8
    // 0x800286BC: nop

        goto L_800286C8;
    // 0x800286BC: nop

L_800286C0:
    // 0x800286C0: jal         0x800285B8
    // 0x800286C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800285B8(rdram, ctx);
        goto after_2;
    // 0x800286C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
L_800286C8:
    // 0x800286C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800286CC: lwc1        $f2, -0x258($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X258);
    // 0x800286D0: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800286D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800286D8: addiu       $a0, $s2, 0xDC
    ctx->r4 = ADD32(ctx->r18, 0XDC);
    // 0x800286DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800286E0: nop

    // 0x800286E4: bc1tl       L_80028710
    if (c1cs) {
        // 0x800286E8: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80028710;
    }
    goto skip_1;
    // 0x800286E8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x800286EC: lwc1        $f4, -0x254($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X254);
    // 0x800286F0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800286F4: nop

    // 0x800286F8: bc1tl       L_80028710
    if (c1cs) {
        // 0x800286FC: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80028710;
    }
    goto skip_2;
    // 0x800286FC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x80028700: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80028704: nop

    // 0x80028708: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x8002870C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_80028710:
    // 0x80028710: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028714: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80028718: nop

    // 0x8002871C: bc1t        L_80028744
    if (c1cs) {
        // 0x80028720: nop
    
            goto L_80028744;
    }
    // 0x80028720: nop

    // 0x80028724: lwc1        $f8, -0x250($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X250);
    // 0x80028728: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8002872C: nop

    // 0x80028730: bc1t        L_80028744
    if (c1cs) {
        // 0x80028734: nop
    
            goto L_80028744;
    }
    // 0x80028734: nop

    // 0x80028738: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002873C: nop

    // 0x80028740: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
L_80028744:
    // 0x80028744: jal         0x80065490
    // 0x80028748: addiu       $a1, $s1, 0x84
    ctx->r5 = ADD32(ctx->r17, 0X84);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x80028748: addiu       $a1, $s1, 0x84
    ctx->r5 = ADD32(ctx->r17, 0X84);
    after_3:
    // 0x8002874C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80028750: swc1        $f16, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->f16.u32l;
    // 0x80028754: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80028758: swc1        $f18, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->f18.u32l;
    // 0x8002875C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80028760: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80028764: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80028768: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002876C: jr          $ra
    // 0x80028770: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80028770: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8042F710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042F714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042F718: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8042F71C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8042F720: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8042F724: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8042F728: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8042F72C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042F730: bne         $v0, $at, L_8042F784
    if (ctx->r2 != ctx->r1) {
        // 0x8042F734: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8042F784;
    }
    // 0x8042F734: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8042F738: jal         0x8005FE48
    // 0x8042F73C: nop

    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8042F73C: nop

    after_0:
    // 0x8042F740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042F748: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8042F74C: jal         0x804303F0
    // 0x8042F750: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804303F0(rdram, ctx);
        goto after_1;
    // 0x8042F750: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_1:
    // 0x8042F754: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8042F758: lwc1        $f4, 0xC4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8042F75C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B90) << 16);
    // 0x8042F760: lwc1        $f8, 0x1C70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B90));
    // 0x8042F764: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8042F768: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8042F76C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8042F770: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8042F774: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8042F778: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8042F77C: b           L_8042F810
    // 0x8042F780: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
        goto L_8042F810;
    // 0x8042F780: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
L_8042F784:
    // 0x8042F784: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8042F788: bne         $v0, $at, L_8042F810
    if (ctx->r2 != ctx->r1) {
        // 0x8042F78C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8042F810;
    }
    // 0x8042F78C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8042F790: jal         0x80062AEC
    // 0x8042F794: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80062AEC(rdram, ctx);
        goto after_2;
    // 0x8042F794: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x8042F798: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8042F79C: beq         $v0, $at, L_8042F7C0
    if (ctx->r2 == ctx->r1) {
        // 0x8042F7A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8042F7C0;
    }
    // 0x8042F7A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8042F7A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8042F7A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8042F7AC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8042F7B0: jal         0x8002F6E4
    // 0x8042F7B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_3;
    // 0x8042F7B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8042F7B8: b           L_8042F814
    // 0x8042F7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042F814;
    // 0x8042F7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042F7C0:
    // 0x8042F7C0: jal         0x8002FABC
    // 0x8042F7C4: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    func_8002FABC(rdram, ctx);
        goto after_4;
    // 0x8042F7C4: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    after_4:
    // 0x8042F7C8: jal         0x8005FE48
    // 0x8042F7CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_5;
    // 0x8042F7CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8042F7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F7D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042F7D8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8042F7DC: jal         0x804303F0
    // 0x8042F7E0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804303F0(rdram, ctx);
        goto after_6;
    // 0x8042F7E0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_6:
    // 0x8042F7E4: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8042F7E8: lwc1        $f18, 0xC4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8042F7EC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B94) << 16);
    // 0x8042F7F0: lwc1        $f6, 0x1C74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B94));
    // 0x8042F7F4: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8042F7F8: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8042F7FC: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8042F800: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x8042F804: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8042F808: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8042F80C: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
L_8042F810:
    // 0x8042F810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042F814:
    // 0x8042F814: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8042F818: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8042F81C: jr          $ra
    // 0x8042F820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8042F820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806E6F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6F54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E6F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E6F5C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806E6F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806E6F64: jal         0x80048F84
    // 0x806E6F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x806E6F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x806E6F6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E6F70: jal         0x80048F84
    // 0x806E6F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806E6F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806E6F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E6F7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E6F80: jr          $ra
    // 0x806E6F84: nop

    return;
    // 0x806E6F84: nop

;}
RECOMP_FUNC void func_80053C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053C4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80053C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053C54: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80053C58: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80053C5C: jal         0x80047090
    // 0x80053C60: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80053C60: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    after_0:
    // 0x80053C64: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80053C68: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80053C6C: jal         0x80047AB8
    // 0x80053C70: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80053C70: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80053C74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80053C78: lwc1        $f6, 0xB4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB4C);
    // 0x80053C7C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80053C80: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    // 0x80053C84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80053C88: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80053C8C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80053C90: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80053C94: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80053C98: jal         0x8004613C
    // 0x80053C9C: nop

    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x80053C9C: nop

    after_2:
    // 0x80053CA0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80053CA4: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x80053CA8: lhu         $t7, 0x2E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2E);
    // 0x80053CAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80053CB0: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80053CB4: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80053CB8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80053CBC: jal         0x80044194
    // 0x80053CC0: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x80053CC0: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    after_3:
    // 0x80053CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053CC8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80053CCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80053CD0: jr          $ra
    // 0x80053CD4: nop

    return;
    // 0x80053CD4: nop

;}
RECOMP_FUNC void func_80435044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435044: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80435048: lui         $t2, 0xF700
    ctx->r10 = S32(0XF700 << 16);
    // 0x8043504C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80435050: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80435054: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80435058: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8043505C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80435060: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x80435064: lui         $t4, 0xB800
    ctx->r12 = S32(0XB800 << 16);
    // 0x80435068: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x8043506C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80435070: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x80435074: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80435078: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8043507C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80435080: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80435084: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80435088: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8043508C: jr          $ra
    // 0x80435090: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    return;
    // 0x80435090: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
;}
RECOMP_FUNC void func_8059FDD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059FDD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8059FDD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8059FDD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8059FDDC: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8059FDE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8059FDE4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8059FDE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059FDEC: jal         0x80048F84
    // 0x8059FDF0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8059FDF0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8059FDF4: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x8059FDF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059FDFC: lhu         $t9, 0x8($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X8);
    // 0x8059FE00: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8059FE04: beq         $t0, $zero, L_8059FE64
    if (ctx->r8 == 0) {
        // 0x8059FE08: nop
    
            goto L_8059FE64;
    }
    // 0x8059FE08: nop

    // 0x8059FE0C: jal         0x8059F608
    // 0x8059FE10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059F608(rdram, ctx);
        goto after_1;
    // 0x8059FE10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8059FE14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8059FE18: beq         $v0, $at, L_8059FE30
    if (ctx->r2 == ctx->r1) {
        // 0x8059FE1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8059FE30;
    }
    // 0x8059FE1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8059FE20: beq         $v0, $at, L_8059FE40
    if (ctx->r2 == ctx->r1) {
        // 0x8059FE24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8059FE40;
    }
    // 0x8059FE24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059FE28: b           L_8059FEF0
    // 0x8059FE2C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059FEF0;
    // 0x8059FE2C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059FE30:
    // 0x8059FE30: jal         0x8059F3CC
    // 0x8059FE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059F3CC(rdram, ctx);
        goto after_2;
    // 0x8059FE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8059FE38: b           L_8059FEF0
    // 0x8059FE3C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059FEF0;
    // 0x8059FE3C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059FE40:
    // 0x8059FE40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059FE44: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8059FE48: jal         0x805A0790
    // 0x8059FE4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_3;
    // 0x8059FE4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8059FE50: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8059FE54: lhu         $t1, 0x8($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FE58: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x8059FE5C: b           L_8059FEEC
    // 0x8059FE60: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
        goto L_8059FEEC;
    // 0x8059FE60: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
L_8059FE64:
    // 0x8059FE64: jal         0x80049D74
    // 0x8059FE68: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80049D74(rdram, ctx);
        goto after_4;
    // 0x8059FE68: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8059FE6C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8059FE70: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8059FE74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8059FE78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059FE7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059FE80: jal         0x8004D150
    // 0x8059FE84: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D150(rdram, ctx);
        goto after_5;
    // 0x8059FE84: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x8059FE88: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8059FE8C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8059FE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059FE94: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8059FE98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8059FE9C: lw          $t5, 0x40($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X40);
    // 0x8059FEA0: lbu         $t6, 0x2C($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2C);
    // 0x8059FEA4: beq         $t6, $zero, L_8059FEBC
    if (ctx->r14 == 0) {
        // 0x8059FEA8: nop
    
            goto L_8059FEBC;
    }
    // 0x8059FEA8: nop

    // 0x8059FEAC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8059FEB0: lhu         $t7, 0x8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FEB4: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8059FEB8: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
L_8059FEBC:
    // 0x8059FEBC: jal         0x8004D150
    // 0x8059FEC0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D150(rdram, ctx);
        goto after_6;
    // 0x8059FEC0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_6:
    // 0x8059FEC4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8059FEC8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8059FECC: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x8059FED0: lbu         $t2, 0x44($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X44);
    // 0x8059FED4: beql        $t2, $zero, L_8059FEF0
    if (ctx->r10 == 0) {
        // 0x8059FED8: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_8059FEF0;
    }
    goto skip_0;
    // 0x8059FED8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x8059FEDC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8059FEE0: lhu         $t3, 0x8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FEE4: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x8059FEE8: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
L_8059FEEC:
    // 0x8059FEEC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059FEF0:
    // 0x8059FEF0: lhu         $t5, 0x8($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FEF4: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x8059FEF8: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x8059FEFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8059FF00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8059FF04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8059FF08: jr          $ra
    // 0x8059FF0C: nop

    return;
    // 0x8059FF0C: nop

;}
RECOMP_FUNC void func_804A5354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A5354: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A5358: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A535C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A5360: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A5364: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A5368: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A536C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A5370: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A5374: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A5378: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A537C: jr          $ra
    // 0x804A5380: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A5380: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x804A5384: nop

    // 0x804A5388: nop

    // 0x804A538C: nop

;}
RECOMP_FUNC void func_80409EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409EA4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80409EA8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80409EAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80409EB0: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0X16E8) << 16);
    // 0x80409EB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80409EB8: addiu       $t6, $t6, -0x6F48
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0X16E8));
    // 0x80409EBC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80409EC0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80409EC4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80409EC8: jal         0x80409CD0
    // 0x80409ECC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80409CD0(rdram, ctx);
        goto after_0;
    // 0x80409ECC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80409ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80409ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80409ED8: jr          $ra
    // 0x80409EDC: nop

    return;
    // 0x80409EDC: nop

;}
RECOMP_FUNC void func_8041D708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041D708: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8041D70C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041D710: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041D714: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8041D718: addiu       $at, $zero, 0x40AF
    ctx->r1 = ADD32(0, 0X40AF);
    // 0x8041D71C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041D720: beq         $v0, $at, L_8041D788
    if (ctx->r2 == ctx->r1) {
        // 0x8041D724: addiu       $at, $zero, 0x40B0
        ctx->r1 = ADD32(0, 0X40B0);
            goto L_8041D788;
    }
    // 0x8041D724: addiu       $at, $zero, 0x40B0
    ctx->r1 = ADD32(0, 0X40B0);
    // 0x8041D728: beq         $v0, $at, L_8041D788
    if (ctx->r2 == ctx->r1) {
        // 0x8041D72C: addiu       $at, $zero, 0x40B1
        ctx->r1 = ADD32(0, 0X40B1);
            goto L_8041D788;
    }
    // 0x8041D72C: addiu       $at, $zero, 0x40B1
    ctx->r1 = ADD32(0, 0X40B1);
    // 0x8041D730: beq         $v0, $at, L_8041D7A8
    if (ctx->r2 == ctx->r1) {
        // 0x8041D734: addiu       $at, $zero, 0x45A0
        ctx->r1 = ADD32(0, 0X45A0);
            goto L_8041D7A8;
    }
    // 0x8041D734: addiu       $at, $zero, 0x45A0
    ctx->r1 = ADD32(0, 0X45A0);
    // 0x8041D738: beq         $v0, $at, L_8041D788
    if (ctx->r2 == ctx->r1) {
        // 0x8041D73C: addiu       $at, $zero, 0x45A5
        ctx->r1 = ADD32(0, 0X45A5);
            goto L_8041D788;
    }
    // 0x8041D73C: addiu       $at, $zero, 0x45A5
    ctx->r1 = ADD32(0, 0X45A5);
    // 0x8041D740: beq         $v0, $at, L_8041D768
    if (ctx->r2 == ctx->r1) {
        // 0x8041D744: addiu       $at, $zero, 0x45CB
        ctx->r1 = ADD32(0, 0X45CB);
            goto L_8041D768;
    }
    // 0x8041D744: addiu       $at, $zero, 0x45CB
    ctx->r1 = ADD32(0, 0X45CB);
    // 0x8041D748: beq         $v0, $at, L_8041D778
    if (ctx->r2 == ctx->r1) {
        // 0x8041D74C: addiu       $at, $zero, 0x45F0
        ctx->r1 = ADD32(0, 0X45F0);
            goto L_8041D778;
    }
    // 0x8041D74C: addiu       $at, $zero, 0x45F0
    ctx->r1 = ADD32(0, 0X45F0);
    // 0x8041D750: beq         $v0, $at, L_8041D798
    if (ctx->r2 == ctx->r1) {
        // 0x8041D754: addiu       $at, $zero, 0x4638
        ctx->r1 = ADD32(0, 0X4638);
            goto L_8041D798;
    }
    // 0x8041D754: addiu       $at, $zero, 0x4638
    ctx->r1 = ADD32(0, 0X4638);
    // 0x8041D758: beq         $v0, $at, L_8041D798
    if (ctx->r2 == ctx->r1) {
        // 0x8041D75C: nop
    
            goto L_8041D798;
    }
    // 0x8041D75C: nop

    // 0x8041D760: b           L_8041D7B0
    // 0x8041D764: nop

        goto L_8041D7B0;
    // 0x8041D764: nop

L_8041D768:
    // 0x8041D768: jal         0x8041D864
    // 0x8041D76C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041D864(rdram, ctx);
        goto after_0;
    // 0x8041D76C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8041D770: b           L_8041D7B0
    // 0x8041D774: nop

        goto L_8041D7B0;
    // 0x8041D774: nop

L_8041D778:
    // 0x8041D778: jal         0x8041DD44
    // 0x8041D77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041DD44(rdram, ctx);
        goto after_1;
    // 0x8041D77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8041D780: b           L_8041D7B0
    // 0x8041D784: nop

        goto L_8041D7B0;
    // 0x8041D784: nop

L_8041D788:
    // 0x8041D788: jal         0x8041DBDC
    // 0x8041D78C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041DBDC(rdram, ctx);
        goto after_2;
    // 0x8041D78C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8041D790: b           L_8041D7B0
    // 0x8041D794: nop

        goto L_8041D7B0;
    // 0x8041D794: nop

L_8041D798:
    // 0x8041D798: jal         0x8041E090
    // 0x8041D79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E090(rdram, ctx);
        goto after_3;
    // 0x8041D79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8041D7A0: b           L_8041D7B0
    // 0x8041D7A4: nop

        goto L_8041D7B0;
    // 0x8041D7A4: nop

L_8041D7A8:
    // 0x8041D7A8: jal         0x80420520
    // 0x8041D7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80420520(rdram, ctx);
        goto after_4;
    // 0x8041D7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8041D7B0:
    // 0x8041D7B0: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(29, 0X74) << 16);
    // 0x8041D7B4: addiu       $t6, $t6, -0x292C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(29, 0X74));
    // 0x8041D7B8: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x8041D7BC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8041D7C0: jal         0x80067BBC
    // 0x8041D7C4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8041D7C4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8041D7C8: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8041D7CC: jal         0x80067F78
    // 0x8041D7D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_6;
    // 0x8041D7D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8041D7D4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8041D7D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041D7DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041D7E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8041D7E4: jr          $ra
    // 0x8041D7E8: nop

    return;
    // 0x8041D7E8: nop

;}
RECOMP_FUNC void func_80446704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80446708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044670C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446710: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446714: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80446718: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8044671C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446720: sw          $t6, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = ctx->r14;
    // 0x80446724: addiu       $v1, $zero, 0x744
    ctx->r3 = ADD32(0, 0X744);
    // 0x80446728: addiu       $t7, $zero, 0x3C0
    ctx->r15 = ADD32(0, 0X3C0);
    // 0x8044672C: addiu       $t8, $zero, 0xAC8
    ctx->r24 = ADD32(0, 0XAC8);
    // 0x80446730: sw          $t7, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r15;
    // 0x80446734: sw          $v1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r3;
    // 0x80446738: sw          $v1, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r3;
    // 0x8044673C: sw          $v1, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->r3;
    // 0x80446740: jal         0x80446690
    // 0x80446744: sw          $t8, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r24;
    func_80446690(rdram, ctx);
        goto after_0;
    // 0x80446744: sw          $t8, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r24;
    after_0:
    // 0x80446748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044674C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80446750: jr          $ra
    // 0x80446754: nop

    return;
    // 0x80446754: nop

;}
RECOMP_FUNC void func_8045111C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045111C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80451120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80451124: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80451128: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8045112C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80451130: lw          $v0, 0xA5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA5C);
    // 0x80451134: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80451138: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8045113C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80451140: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80451144: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80451148: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8045114C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80451150: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80451154: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80451158: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8045115C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80451160: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80451164: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80451168: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x8045116C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80451170: jal         0x80446D70
    // 0x80451174: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x80451174: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x80451178: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x8045117C: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80451180: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80451184: jal         0x8044EEF8
    // 0x80451188: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8044EEF8(rdram, ctx);
        goto after_1;
    // 0x80451188: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8045118C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80451190: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80451194: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80451198: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045119C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804511A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804511A4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804511A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804511AC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804511B0: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x804511B4: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x804511B8: jal         0x8044ED68
    // 0x804511BC: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_2;
    // 0x804511BC: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_2:
    // 0x804511C0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x804511C4: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    // 0x804511C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804511CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804511D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804511D4: jr          $ra
    // 0x804511D8: nop

    return;
    // 0x804511D8: nop

;}
RECOMP_FUNC void func_807A6B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6B0C: lui         $v1, 0x807A
    ctx->r3 = S32(RELOC_HI16(847, 0X1484) << 16);
    // 0x807A6B10: addiu       $v1, $v1, 0x7184
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(847, 0X1484));
    // 0x807A6B14: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x807A6B18: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x807A6B1C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807A6B20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807A6B24: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x807A6B28: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x807A6B2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807A6B30: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x807A6B34: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807A6B38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807A6B3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807A6B40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807A6B44: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807A6B48: mul.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807A6B4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A6B50: beq         $a1, $zero, L_807A6B70
    if (ctx->r5 == 0) {
        // 0x807A6B54: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_807A6B70;
    }
    // 0x807A6B54: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6B58: sub.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x807A6B5C: jal         0x807A5DC8
    // 0x807A6B60: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_807A5DC8(rdram, ctx);
        goto after_0;
    // 0x807A6B60: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807A6B64: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x807A6B68: b           L_807A6B84
    // 0x807A6B6C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_807A6B84;
    // 0x807A6B6C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_807A6B70:
    // 0x807A6B70: add.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x807A6B74: jal         0x807A5DC8
    // 0x807A6B78: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_807A5DC8(rdram, ctx);
        goto after_1;
    // 0x807A6B78: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x807A6B7C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x807A6B80: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_807A6B84:
    // 0x807A6B84: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x807A6B88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807A6B8C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A6B90: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x807A6B94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807A6B98: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807A6B9C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x807A6BA0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x807A6BA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807A6BA8: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x807A6BAC: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x807A6BB0: jal         0x807A5DC8
    // 0x807A6BB4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_807A5DC8(rdram, ctx);
        goto after_2;
    // 0x807A6BB4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x807A6BB8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x807A6BBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807A6BC0: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x807A6BC4: jal         0x807A5DC8
    // 0x807A6BC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_807A5DC8(rdram, ctx);
        goto after_3;
    // 0x807A6BC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x807A6BCC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x807A6BD0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807A6BD4: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x807A6BD8: jal         0x807A5DC8
    // 0x807A6BDC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_807A5DC8(rdram, ctx);
        goto after_4;
    // 0x807A6BDC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_4:
    // 0x807A6BE0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X15B4) << 16);
    // 0x807A6BE4: lwc1        $f2, 0x72B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X15B4));
    // 0x807A6BE8: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x807A6BEC: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x807A6BF0: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x807A6BF4: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x807A6BF8: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x807A6BFC: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x807A6C00: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X15B8) << 16);
    // 0x807A6C04: lwc1        $f10, 0x72B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X15B8));
    // 0x807A6C08: swc1        $f20, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x807A6C0C: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x807A6C10: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X15BC) << 16);
    // 0x807A6C14: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x807A6C18: lwc1        $f18, 0x72BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X15BC));
    // 0x807A6C1C: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x807A6C20: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x807A6C24: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    // 0x807A6C28: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
    // 0x807A6C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807A6C30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807A6C34: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807A6C38: jr          $ra
    // 0x807A6C3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807A6C3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806D35B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D35B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D35B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D35BC: jal         0x8004700C
    // 0x806D35C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D35C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D35C4: beq         $v0, $zero, L_806D3618
    if (ctx->r2 == 0) {
        // 0x806D35C8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806D3618;
    }
    // 0x806D35C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D35CC: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806D35D0: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806D35D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D35D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D35DC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D35E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806D35E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806D35E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D35EC: bc1f        L_806D3610
    if (!c1cs) {
        // 0x806D35F0: nop
    
            goto L_806D3610;
    }
    // 0x806D35F0: nop

    // 0x806D35F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D35F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806D35FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x806D3600: jal         0x806D414C
    // 0x806D3604: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_806D414C(rdram, ctx);
        goto after_1;
    // 0x806D3604: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x806D3608: b           L_806D361C
    // 0x806D360C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D361C;
    // 0x806D360C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D3610:
    // 0x806D3610: jal         0x806D414C
    // 0x806D3614: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_806D414C(rdram, ctx);
        goto after_2;
    // 0x806D3614: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
L_806D3618:
    // 0x806D3618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D361C:
    // 0x806D361C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D3620: jr          $ra
    // 0x806D3624: nop

    return;
    // 0x806D3624: nop

;}
RECOMP_FUNC void func_8005DC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DC70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005DC78: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005DC7C: lwc1        $f4, 0x54($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X54);
    // 0x8005DC80: lwc1        $f8, 0x58($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X58);
    // 0x8005DC84: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x8005DC88: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005DC8C: lw          $a0, 0x30($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X30);
    // 0x8005DC90: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005DC94: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005DC98: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8005DC9C: jal         0x8007348C
    // 0x8005DCA0: nop

    func_8007348C(rdram, ctx);
        goto after_0;
    // 0x8005DCA0: nop

    after_0:
    // 0x8005DCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005DCA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DCAC: jr          $ra
    // 0x8005DCB0: nop

    return;
    // 0x8005DCB0: nop

;}
RECOMP_FUNC void func_80006960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006968: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000696C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80006970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80006978: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000697C: bnel        $t7, $at, L_80006A34
    if (ctx->r15 != ctx->r1) {
        // 0x80006980: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80006A34;
    }
    goto skip_0;
    // 0x80006980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80006984: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80006988: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000698C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80006990: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80006994: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x80006998: beq         $v1, $zero, L_80006A30
    if (ctx->r3 == 0) {
        // 0x8000699C: and         $a0, $v0, $at
        ctx->r4 = ctx->r2 & ctx->r1;
            goto L_80006A30;
    }
    // 0x8000699C: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x800069A0: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x800069A4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800069A8: jal         0x8000576C
    // 0x800069AC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000576C(rdram, ctx);
        goto after_0;
    // 0x800069AC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x800069B0: bne         $v0, $zero, L_800069C0
    if (ctx->r2 != 0) {
        // 0x800069B4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800069C0;
    }
    // 0x800069B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800069B8: b           L_80006A30
    // 0x800069BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80006A30;
    // 0x800069BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800069C0:
    // 0x800069C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800069C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800069C8: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800069CC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800069D0: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x800069D4: bne         $v1, $at, L_80006A04
    if (ctx->r3 != ctx->r1) {
        // 0x800069D8: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80006A04;
    }
    // 0x800069D8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800069DC: lw          $t8, 0x6A7C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A7C);
    // 0x800069E0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800069E4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800069E8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800069EC: lh          $a3, 0x2($t8)
    ctx->r7 = MEM_H(ctx->r24, 0X2);
    // 0x800069F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800069F4: jal         0x80007798
    // 0x800069F8: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    func_80007798(rdram, ctx);
        goto after_1;
    // 0x800069F8: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    after_1:
    // 0x800069FC: b           L_80006A20
    // 0x80006A00: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
        goto L_80006A20;
    // 0x80006A00: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
L_80006A04:
    // 0x80006A04: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80006A08: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80006A0C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80006A10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80006A14: jal         0x80007674
    // 0x80006A18: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    func_80007674(rdram, ctx);
        goto after_2;
    // 0x80006A18: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    after_2:
    // 0x80006A1C: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
L_80006A20:
    // 0x80006A20: andi        $t0, $t9, 0xFFF3
    ctx->r8 = ctx->r25 & 0XFFF3;
    // 0x80006A24: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x80006A28: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80006A2C: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
L_80006A30:
    // 0x80006A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80006A34:
    // 0x80006A34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006A38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80006A3C: jr          $ra
    // 0x80006A40: nop

    return;
    // 0x80006A40: nop

;}
RECOMP_FUNC void func_8078D2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D2D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078D2D8: lui         $t8, 0x8079
    ctx->r24 = S32(RELOC_HI16(802, 0X970) << 16);
    // 0x8078D2DC: addiu       $t8, $t8, -0x2580
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(802, 0X970));
    // 0x8078D2E0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8078D2E4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8078D2E8: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8078D2EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078D2F0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8078D2F4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8078D2F8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8078D2FC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8078D300: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8078D304: nop

    // 0x8078D308: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8078D30C: swc1        $f6, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f6.u32l;
    // 0x8078D310: lw          $t0, -0x72B0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X72B0);
    // 0x8078D314: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8078D318: beq         $t1, $zero, L_8078D338
    if (ctx->r9 == 0) {
        // 0x8078D31C: nop
    
            goto L_8078D338;
    }
    // 0x8078D31C: nop

    // 0x8078D320: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8078D324: lui         $t4, 0x8079
    ctx->r12 = S32(RELOC_HI16(802, 0XB20) << 16);
    // 0x8078D328: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8078D32C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8078D330: lw          $t4, -0x23D0($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(802, 0XB20));
    // 0x8078D334: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
L_8078D338:
    // 0x8078D338: jr          $ra
    // 0x8078D33C: nop

    return;
    // 0x8078D33C: nop

;}
RECOMP_FUNC void func_80430B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430B14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430B1C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80430B20: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80430B24: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80430B28: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X39E0) << 16);
    // 0x80430B2C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80430B30: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80430B34: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80430B38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80430B3C: lw          $t8, 0x1AC0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X39E0));
    // 0x80430B40: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80430B44: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80430B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80430B4C: jal         0x80048490
    // 0x80430B50: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80430B50: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80430B54: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80430B58: jal         0x80048378
    // 0x80430B5C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80430B5C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80430B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430B64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430B68: jr          $ra
    // 0x80430B6C: nop

    return;
    // 0x80430B6C: nop

;}
RECOMP_FUNC void func_80704470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80704470: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80704474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80704478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070447C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80704480: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80704484: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80704488: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x8070448C: beql        $t6, $zero, L_807044FC
    if (ctx->r14 == 0) {
        // 0x80704490: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_807044FC;
    }
    goto skip_0;
    // 0x80704490: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x80704494: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x80704498: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8070449C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807044A0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x807044A4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x807044A8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807044AC: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x807044B0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x807044B4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x807044B8: jal         0x80067BBC
    // 0x807044BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x807044BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x807044C0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x807044C4: jal         0x80067818
    // 0x807044C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807044C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807044CC: jal         0x807041F8
    // 0x807044D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807041F8(rdram, ctx);
        goto after_2;
    // 0x807044D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807044D4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807044D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807044DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807044E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807044E4: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x807044E8: jal         0x80705A5C
    // 0x807044EC: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    func_80705A5C(rdram, ctx);
        goto after_3;
    // 0x807044EC: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    after_3:
    // 0x807044F0: b           L_80704540
    // 0x807044F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80704540;
    // 0x807044F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807044F8: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_807044FC:
    // 0x807044FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80704500: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80704504: beq         $t8, $zero, L_80704524
    if (ctx->r24 == 0) {
        // 0x80704508: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_80704524;
    }
    // 0x80704508: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8070450C: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x80704510: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x80704514: jal         0x80705A5C
    // 0x80704518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80705A5C(rdram, ctx);
        goto after_4;
    // 0x80704518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8070451C: b           L_80704540
    // 0x80704520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80704540;
    // 0x80704520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80704524:
    // 0x80704524: jal         0x80048F84
    // 0x80704528: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x80704528: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8070452C: jal         0x8070384C
    // 0x80704530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070384C(rdram, ctx);
        goto after_6;
    // 0x80704530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80704534: jal         0x80703F10
    // 0x80704538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80703F10(rdram, ctx);
        goto after_7;
    // 0x80704538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8070453C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80704540:
    // 0x80704540: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80704544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80704548: jr          $ra
    // 0x8070454C: nop

    return;
    // 0x8070454C: nop

;}
RECOMP_FUNC void func_8064B63C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B63C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B644: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064B648: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B64C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064B650: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B658: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8064B65C: nop

    // 0x8064B660: bc1fl       L_8064B690
    if (!c1cs) {
        // 0x8064B664: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064B690;
    }
    goto skip_0;
    // 0x8064B664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064B668: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064B66C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B670: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064B674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064B678: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8064B67C: jal         0x8064B918
    // 0x8064B680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8064B918(rdram, ctx);
        goto after_0;
    // 0x8064B680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064B684: jal         0x8064A40C
    // 0x8064B688: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8064A40C(rdram, ctx);
        goto after_1;
    // 0x8064B688: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8064B68C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064B690:
    // 0x8064B690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B694: jr          $ra
    // 0x8064B698: nop

    return;
    // 0x8064B698: nop

;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DE0: jr          $ra
    // 0x80089DE4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x80089DE4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void func_8003150C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003150C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80031510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031514: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80031518: lw          $v0, 0x1C0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C0);
    // 0x8003151C: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80031520: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80031524: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80031528: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8003152C: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80031530: jal         0x80065954
    // 0x80031534: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80031534: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80031538: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003153C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80031540: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80031544: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80031548: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8003154C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80031550: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80031554: bc1fl       L_80031568
    if (!c1cs) {
        // 0x80031558: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80031568;
    }
    goto skip_0;
    // 0x80031558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8003155C: b           L_80031588
    // 0x80031560: lwc1        $f2, 0x3C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3C);
        goto L_80031588;
    // 0x80031560: lwc1        $f2, 0x3C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80031564: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80031568:
    // 0x80031568: nop

    // 0x8003156C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80031570: nop

    // 0x80031574: bc1fl       L_80031588
    if (!c1cs) {
        // 0x80031578: add.s       $f2, $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_80031588;
    }
    goto skip_1;
    // 0x80031578: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    skip_1:
    // 0x8003157C: b           L_80031588
    // 0x80031580: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
        goto L_80031588;
    // 0x80031580: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80031584: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
L_80031588:
    // 0x80031588: swc1        $f2, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f2.u32l;
    // 0x8003158C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031590: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031594: jr          $ra
    // 0x80031598: nop

    return;
    // 0x80031598: nop

;}
RECOMP_FUNC void func_8002BDCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BDCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BDD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BDD4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002BDD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002BDDC: jal         0x8002BC1C
    // 0x8002BDE0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002BC1C(rdram, ctx);
        goto after_0;
    // 0x8002BDE0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002BDE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002BDE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002BDEC: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002BDF0: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8002BDF4: addiu       $t8, $t8, 0x1B38
    ctx->r24 = ADD32(ctx->r24, 0X1B38);
    // 0x8002BDF8: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8002BDFC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8002BE00: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8002BE04: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BE08: swc1        $f0, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->f0.u32l;
    // 0x8002BE0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BE10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002BE14: jr          $ra
    // 0x8002BE18: nop

    return;
    // 0x8002BE18: nop

;}
RECOMP_FUNC void func_80670290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670290: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80670294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80670298: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8067029C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806702A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806702A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806702A8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x806702AC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806702B0: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(520, 0X730) << 16);
    // 0x806702B4: lwc1        $f10, 0x9B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(520, 0X730));
    // 0x806702B8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x806702BC: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806702C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806702C4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806702C8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806702CC: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806702D0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x806702D4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x806702D8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x806702DC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806702E0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806702E4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806702E8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806702EC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806702F0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806702F4: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x806702F8: jalr        $t9
    // 0x806702FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806702FC: nop

    after_0:
    // 0x80670300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80670304: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80670308: jr          $ra
    // 0x8067030C: nop

    return;
    // 0x8067030C: nop

;}
