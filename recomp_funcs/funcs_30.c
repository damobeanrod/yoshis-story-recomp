#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80716FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716FD8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716FDC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716FE0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716FE4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716FE8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716FEC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716FF0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716FF4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716FF8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716FFC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80717000: jr          $ra
    // 0x80717004: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80717004: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80717008: nop

    // 0x8071700C: nop

;}
RECOMP_FUNC void func_80040860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040860: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80040864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040868: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004086C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040870: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80040874: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80040878: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004087C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80040880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80040884: jal         0x8003BB20
    // 0x80040888: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_8003BB20(rdram, ctx);
        goto after_0;
    // 0x80040888: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_0:
    // 0x8004088C: beq         $v0, $zero, L_8004092C
    if (ctx->r2 == 0) {
        // 0x80040890: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8004092C;
    }
    // 0x80040890: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80040894: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80040898: jal         0x80047F9C
    // 0x8004089C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x8004089C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800408A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800408A4: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x800408A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800408AC: jal         0x80065490
    // 0x800408B0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x800408B0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    after_2:
    // 0x800408B4: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x800408B8: jal         0x80065490
    // 0x800408BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x800408BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x800408C0: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x800408C4: jal         0x80065490
    // 0x800408C8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x800408C8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x800408CC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800408D0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800408D4: addiu       $a2, $a2, -0x5A14
    ctx->r6 = ADD32(ctx->r6, -0X5A14);
    // 0x800408D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800408DC: jal         0x8003F14C
    // 0x800408E0: lw          $a1, 0x1F4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X1F4);
    func_8003F14C(rdram, ctx);
        goto after_5;
    // 0x800408E0: lw          $a1, 0x1F4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X1F4);
    after_5:
    // 0x800408E4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800408E8: addiu       $t8, $t8, -0x4D50
    ctx->r24 = ADD32(ctx->r24, -0X4D50);
    // 0x800408EC: jal         0x8001D770
    // 0x800408F0: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    func_8001D770(rdram, ctx);
        goto after_6;
    // 0x800408F0: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    after_6:
    // 0x800408F4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800408F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800408FC: jal         0x80067E98
    // 0x80040900: lw          $a1, 0x34($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X34);
    func_80067E98(rdram, ctx);
        goto after_7;
    // 0x80040900: lw          $a1, 0x34($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X34);
    after_7:
    // 0x80040904: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80040908: jal         0x80067818
    // 0x8004090C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x8004090C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80040910: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80040914: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80040918: addiu       $a3, $a3, -0x1A14
    ctx->r7 = ADD32(ctx->r7, -0X1A14);
    // 0x8004091C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80040920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80040924: jal         0x8003E658
    // 0x80040928: lw          $a0, 0x1F4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1F4);
    func_8003E658(rdram, ctx);
        goto after_9;
    // 0x80040928: lw          $a0, 0x1F4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1F4);
    after_9:
L_8004092C:
    // 0x8004092C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80040930: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80040934: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040938: jr          $ra
    // 0x8004093C: nop

    return;
    // 0x8004093C: nop

;}
RECOMP_FUNC void func_8051F6D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F6D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8051F6D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8051F6D8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8051F6DC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8051F6E0: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8051F6E4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8051F6E8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8051F6EC: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(303, 0X95C) << 16);
    // 0x8051F6F0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8051F6F4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8051F6F8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8051F6FC: lw          $t9, -0x624($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(303, 0X95C));
    // 0x8051F700: jr          $ra
    // 0x8051F704: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    return;
    // 0x8051F704: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80028504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028504: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80028508: lwc1        $f6, 0xDC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XDC);
    // 0x8002850C: lwc1        $f8, 0x88($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X88);
    // 0x80028510: lwc1        $f10, 0xE0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XE0);
    // 0x80028514: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80028518: addiu       $at, $zero, 0x4038
    ctx->r1 = ADD32(0, 0X4038);
    // 0x8002851C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80028520: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80028524: lhu         $v0, 0xC($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0XC);
    // 0x80028528: beq         $v0, $at, L_80028538
    if (ctx->r2 == ctx->r1) {
        // 0x8002852C: addiu       $at, $zero, 0x4640
        ctx->r1 = ADD32(0, 0X4640);
            goto L_80028538;
    }
    // 0x8002852C: addiu       $at, $zero, 0x4640
    ctx->r1 = ADD32(0, 0X4640);
    // 0x80028530: bnel        $v0, $at, L_80028548
    if (ctx->r2 != ctx->r1) {
        // 0x80028534: lhu         $t6, 0xE($a3)
        ctx->r14 = MEM_HU(ctx->r7, 0XE);
            goto L_80028548;
    }
    goto skip_0;
    // 0x80028534: lhu         $t6, 0xE($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0XE);
    skip_0:
L_80028538:
    // 0x80028538: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002853C: jr          $ra
    // 0x80028540: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x80028540: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80028544: lhu         $t6, 0xE($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0XE);
L_80028548:
    // 0x80028548: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002854C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80028550: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80028554: bnel        $t8, $at, L_8002856C
    if (ctx->r24 != ctx->r1) {
        // 0x80028558: swc1        $f2, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
            goto L_8002856C;
    }
    goto skip_1;
    // 0x80028558: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x8002855C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80028560: jr          $ra
    // 0x80028564: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80028564: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80028568: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
L_8002856C:
    // 0x8002856C: jr          $ra
    // 0x80028570: nop

    return;
    // 0x80028570: nop

;}
RECOMP_FUNC void func_80450B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80450B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450B20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80450B24: jal         0x80444408
    // 0x80450B28: addiu       $a1, $zero, 0x40F0
    ctx->r5 = ADD32(0, 0X40F0);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x80450B28: addiu       $a1, $zero, 0x40F0
    ctx->r5 = ADD32(0, 0X40F0);
    after_0:
    // 0x80450B2C: beq         $v0, $zero, L_80450B38
    if (ctx->r2 == 0) {
        // 0x80450B30: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_80450B38;
    }
    // 0x80450B30: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80450B34: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
L_80450B38:
    // 0x80450B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80450B3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80450B40: jr          $ra
    // 0x80450B44: nop

    return;
    // 0x80450B44: nop

;}
RECOMP_FUNC void func_80049D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049D74: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80049D78: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80049D7C: lw          $t7, -0x77F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X77F0);
    // 0x80049D80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80049D84: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80049D88: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80049D8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80049D90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80049D94: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80049D98: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80049D9C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80049DA0: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    // 0x80049DA4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80049DA8: addiu       $s3, $sp, 0x2C
    ctx->r19 = ADD32(ctx->r29, 0X2C);
    // 0x80049DAC: bne         $v0, $zero, L_80049DD8
    if (ctx->r2 != 0) {
        // 0x80049DB0: lw          $s0, 0x2C($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X2C);
            goto L_80049DD8;
    }
    // 0x80049DB0: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x80049DB4: beq         $s0, $zero, L_80049E60
    if (ctx->r16 == 0) {
        // 0x80049DB8: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049E60;
    }
    // 0x80049DB8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80049DBC:
    // 0x80049DBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80049DC0: jal         0x80049D38
    // 0x80049DC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80049D38(rdram, ctx);
        goto after_0;
    // 0x80049DC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80049DC8: bnel        $s0, $zero, L_80049DBC
    if (ctx->r16 != 0) {
        // 0x80049DCC: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049DBC;
    }
    goto skip_0;
    // 0x80049DCC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_0:
    // 0x80049DD0: b           L_80049E64
    // 0x80049DD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80049E64;
    // 0x80049DD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80049DD8:
    // 0x80049DD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80049DDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80049DE0: jal         0x80047AB8
    // 0x80049DE4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80049DE4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x80049DE8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80049DEC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80049DF0: lwc1        $f6, 0x8C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80049DF4: jal         0x80065954
    // 0x80049DF8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80049DF8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x80049DFC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80049E00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049E04: nop

    // 0x80049E08: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80049E0C: nop

    // 0x80049E10: bc1f        L_80049E44
    if (!c1cs) {
        // 0x80049E14: nop
    
            goto L_80049E44;
    }
    // 0x80049E14: nop

    // 0x80049E18: beq         $s0, $zero, L_80049E60
    if (ctx->r16 == 0) {
        // 0x80049E1C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049E60;
    }
    // 0x80049E1C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80049E20:
    // 0x80049E20: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80049E24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80049E28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80049E2C: jal         0x80049C70
    // 0x80049E30: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80049C70(rdram, ctx);
        goto after_3;
    // 0x80049E30: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
    // 0x80049E34: bnel        $s0, $zero, L_80049E20
    if (ctx->r16 != 0) {
        // 0x80049E38: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049E20;
    }
    goto skip_1;
    // 0x80049E38: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
    // 0x80049E3C: b           L_80049E64
    // 0x80049E40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80049E64;
    // 0x80049E40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80049E44:
    // 0x80049E44: beq         $s0, $zero, L_80049E60
    if (ctx->r16 == 0) {
        // 0x80049E48: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049E60;
    }
    // 0x80049E48: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80049E4C:
    // 0x80049E4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80049E50: jal         0x80049D38
    // 0x80049E54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80049D38(rdram, ctx);
        goto after_4;
    // 0x80049E54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80049E58: bnel        $s0, $zero, L_80049E4C
    if (ctx->r16 != 0) {
        // 0x80049E5C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80049E4C;
    }
    goto skip_2;
    // 0x80049E5C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_2:
L_80049E60:
    // 0x80049E60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80049E64:
    // 0x80049E64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80049E68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80049E6C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80049E70: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80049E74: jr          $ra
    // 0x80049E78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80049E78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8003E120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E120: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003E124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003E128: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003E12C: jal         0x8004700C
    // 0x8003E130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003E130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8003E134: beql        $v0, $zero, L_8003E1B0
    if (ctx->r2 == 0) {
        // 0x8003E138: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003E1B0;
    }
    goto skip_0;
    // 0x8003E138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003E13C: lw          $v0, 0x1F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003E140: lwc1        $f12, 0x174($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X174);
    // 0x8003E144: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8003E148: jal         0x80066E88
    // 0x8003E14C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8003E14C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8003E150: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003E154: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003E158: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8003E15C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003E160: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003E164: lwc1        $f8, 0x68($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X68);
    // 0x8003E168: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003E16C: jal         0x80066DE4
    // 0x8003E170: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8003E170: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8003E174: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8003E178: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003E17C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003E180: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003E184: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8003E188: swc1        $f12, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f12.u32l;
    // 0x8003E18C: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8003E190: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    // 0x8003E194: lwc1        $f4, 0x238($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X238);
    // 0x8003E198: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8003E19C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003E1A0: swc1        $f12, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f12.u32l;
    // 0x8003E1A4: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x8003E1A8: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x8003E1AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003E1B0:
    // 0x8003E1B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003E1B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003E1B8: jr          $ra
    // 0x8003E1BC: nop

    return;
    // 0x8003E1BC: nop

;}
RECOMP_FUNC void func_8006E5DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E5DC: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E5E0: addiu       $v0, $v0, -0x1A14
    ctx->r2 = ADD32(ctx->r2, -0X1A14);
    // 0x8006E5E4: jr          $ra
    // 0x8006E5E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006E5E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806B08E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B08E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B08EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B08F0: lwc1        $f0, 0xC8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x806B08F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806B08F8: nop

    // 0x806B08FC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806B0900: nop

    // 0x806B0904: bc1t        L_806B091C
    if (c1cs) {
        // 0x806B0908: nop
    
            goto L_806B091C;
    }
    // 0x806B0908: nop

    // 0x806B090C: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x806B0910: andi        $t7, $t6, 0x3000
    ctx->r15 = ctx->r14 & 0X3000;
    // 0x806B0914: bnel        $t7, $zero, L_806B0928
    if (ctx->r15 != 0) {
        // 0x806B0918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B0928;
    }
    goto skip_0;
    // 0x806B0918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_806B091C:
    // 0x806B091C: jal         0x806B079C
    // 0x806B0920: nop

    func_806B079C(rdram, ctx);
        goto after_0;
    // 0x806B0920: nop

    after_0:
    // 0x806B0924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B0928:
    // 0x806B0928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B092C: jr          $ra
    // 0x806B0930: nop

    return;
    // 0x806B0930: nop

;}
RECOMP_FUNC void func_806D9818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D981C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9820: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806D9824: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806D9828: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806D982C: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(631, 0X3E4) << 16);
    // 0x806D9830: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D9834: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806D9838: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806D983C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806D9840: lw          $t8, -0x650C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(631, 0X3E4));
    // 0x806D9844: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806D9848: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806D984C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D9850: jal         0x80048490
    // 0x806D9854: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806D9854: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806D9858: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806D985C: jal         0x80048378
    // 0x806D9860: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x806D9860: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x806D9864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D9868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D986C: jr          $ra
    // 0x806D9870: nop

    return;
    // 0x806D9870: nop

;}
RECOMP_FUNC void func_80018EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018EF4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80018EF8: lw          $v0, -0x6D18($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D18);
    // 0x80018EFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80018F00: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x80018F04: bne         $t6, $zero, L_80018F10
    if (ctx->r14 != 0) {
        // 0x80018F08: andi        $t7, $v0, 0x80
        ctx->r15 = ctx->r2 & 0X80;
            goto L_80018F10;
    }
    // 0x80018F08: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x80018F0C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80018F10:
    // 0x80018F10: bne         $t7, $zero, L_80018F20
    if (ctx->r15 != 0) {
        // 0x80018F14: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_80018F20;
    }
    // 0x80018F14: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80018F18: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x80018F1C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_80018F20:
    // 0x80018F20: bne         $t8, $zero, L_80018F30
    if (ctx->r24 != 0) {
        // 0x80018F24: andi        $t9, $v0, 0x8
        ctx->r25 = ctx->r2 & 0X8;
            goto L_80018F30;
    }
    // 0x80018F24: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x80018F28: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x80018F2C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_80018F30:
    // 0x80018F30: bne         $t9, $zero, L_80018F40
    if (ctx->r25 != 0) {
        // 0x80018F34: andi        $t0, $v0, 0x4
        ctx->r8 = ctx->r2 & 0X4;
            goto L_80018F40;
    }
    // 0x80018F34: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x80018F38: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x80018F3C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_80018F40:
    // 0x80018F40: bne         $t0, $zero, L_80018F50
    if (ctx->r8 != 0) {
        // 0x80018F44: andi        $t1, $v0, 0x10
        ctx->r9 = ctx->r2 & 0X10;
            goto L_80018F50;
    }
    // 0x80018F44: andi        $t1, $v0, 0x10
    ctx->r9 = ctx->r2 & 0X10;
    // 0x80018F48: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x80018F4C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_80018F50:
    // 0x80018F50: bne         $t1, $zero, L_80018F60
    if (ctx->r9 != 0) {
        // 0x80018F54: andi        $t2, $v0, 0x40
        ctx->r10 = ctx->r2 & 0X40;
            goto L_80018F60;
    }
    // 0x80018F54: andi        $t2, $v0, 0x40
    ctx->r10 = ctx->r2 & 0X40;
    // 0x80018F58: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x80018F5C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_80018F60:
    // 0x80018F60: bne         $t2, $zero, L_80018F70
    if (ctx->r10 != 0) {
        // 0x80018F64: andi        $t3, $v0, 0x20
        ctx->r11 = ctx->r2 & 0X20;
            goto L_80018F70;
    }
    // 0x80018F64: andi        $t3, $v0, 0x20
    ctx->r11 = ctx->r2 & 0X20;
    // 0x80018F68: ori         $v1, $v1, 0x40
    ctx->r3 = ctx->r3 | 0X40;
    // 0x80018F6C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_80018F70:
    // 0x80018F70: bne         $t3, $zero, L_80018F80
    if (ctx->r11 != 0) {
        // 0x80018F74: nop
    
            goto L_80018F80;
    }
    // 0x80018F74: nop

    // 0x80018F78: ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // 0x80018F7C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_80018F80:
    // 0x80018F80: jr          $ra
    // 0x80018F84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80018F84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80018F88: nop

    // 0x80018F8C: nop

;}
RECOMP_FUNC void func_807AE2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE2C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807AE2C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AE2C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AE2CC: jal         0x8004700C
    // 0x807AE2D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807AE2D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807AE2D4: jal         0x807AC734
    // 0x807AE2D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_807AC734(rdram, ctx);
        goto after_1;
    // 0x807AE2D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x807AE2DC: beql        $v0, $zero, L_807AE2F8
    if (ctx->r2 == 0) {
        // 0x807AE2E0: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_807AE2F8;
    }
    goto skip_0;
    // 0x807AE2E0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x807AE2E4: jal         0x807AE0E0
    // 0x807AE2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AE0E0(rdram, ctx);
        goto after_2;
    // 0x807AE2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807AE2EC: b           L_807AE384
    // 0x807AE2F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807AE384;
    // 0x807AE2F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AE2F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_807AE2F8:
    // 0x807AE2F8: jal         0x8006CA74
    // 0x807AE2FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8006CA74(rdram, ctx);
        goto after_3;
    // 0x807AE2FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x807AE300: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807AE304: lui         $a2, 0x807B
    ctx->r6 = S32(RELOC_HI16(859, 0X14E0) << 16);
    // 0x807AE308: addiu       $a2, $a2, -0x24C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(859, 0X14E0));
    // 0x807AE30C: lw          $a0, -0x7CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE8);
    // 0x807AE310: jal         0x8005A994
    // 0x807AE314: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005A994(rdram, ctx);
        goto after_4;
    // 0x807AE314: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x807AE318: jal         0x807ADC10
    // 0x807AE31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807ADC10(rdram, ctx);
        goto after_5;
    // 0x807AE31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807AE320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807AE324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807AE328: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x807AE32C: beql        $a0, $zero, L_807AE340
    if (ctx->r4 == 0) {
        // 0x807AE330: lw          $t6, 0x1F4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1F4);
            goto L_807AE340;
    }
    goto skip_1;
    // 0x807AE330: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x807AE334: jal         0x8002F7AC
    // 0x807AE338: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    func_8002F7AC(rdram, ctx);
        goto after_6;
    // 0x807AE338: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    after_6:
    // 0x807AE33C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
L_807AE340:
    // 0x807AE340: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807AE344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE348: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x807AE34C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE350: bne         $t7, $zero, L_807AE370
    if (ctx->r15 != 0) {
        // 0x807AE354: nop
    
            goto L_807AE370;
    }
    // 0x807AE354: nop

    // 0x807AE358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE35C: jal         0x807AEA24
    // 0x807AE360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807AEA24(rdram, ctx);
        goto after_7;
    // 0x807AE360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x807AE364: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x807AE368: b           L_807AE380
    // 0x807AE36C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
        goto L_807AE380;
    // 0x807AE36C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_807AE370:
    // 0x807AE370: jal         0x807AEA24
    // 0x807AE374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807AEA24(rdram, ctx);
        goto after_8;
    // 0x807AE374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x807AE378: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x807AE37C: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
L_807AE380:
    // 0x807AE380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE384:
    // 0x807AE384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AE388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807AE38C: jr          $ra
    // 0x807AE390: nop

    return;
    // 0x807AE390: nop

;}
RECOMP_FUNC void func_806B04B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B04B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806B04BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B04C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x806B04C4: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806B04C8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x806B04CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806B04D0: add.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x806B04D4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x806B04D8: lh          $t7, -0x7682($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7682);
    // 0x806B04DC: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806B04E0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806B04E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806B04E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806B04EC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x806B04F0: bc1f        L_806B0500
    if (!c1cs) {
        // 0x806B04F4: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_806B0500;
    }
    // 0x806B04F4: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806B04F8: b           L_806B0520
    // 0x806B04FC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
        goto L_806B0520;
    // 0x806B04FC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_806B0500:
    // 0x806B0500: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x806B0504: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806B0508: nop

    // 0x806B050C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x806B0510: nop

    // 0x806B0514: bc1fl       L_806B0524
    if (!c1cs) {
        // 0x806B0518: c.eq.s      $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
            goto L_806B0524;
    }
    goto skip_0;
    // 0x806B0518: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    skip_0:
    // 0x806B051C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_806B0520:
    // 0x806B0520: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
L_806B0524:
    // 0x806B0524: nop

    // 0x806B0528: bc1tl       L_806B05E8
    if (c1cs) {
        // 0x806B052C: lw          $t8, 0xC($a1)
        ctx->r24 = MEM_W(ctx->r5, 0XC);
            goto L_806B05E8;
    }
    goto skip_1;
    // 0x806B052C: lw          $t8, 0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC);
    skip_1:
    // 0x806B0530: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x806B0534: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806B0538: nop

    // 0x806B053C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x806B0540: nop

    // 0x806B0544: bc1fl       L_806B0574
    if (!c1cs) {
        // 0x806B0548: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_806B0574;
    }
    goto skip_2;
    // 0x806B0548: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_2:
    // 0x806B054C: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x806B0550: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1718) << 16);
    // 0x806B0554: bc1f        L_806B0568
    if (!c1cs) {
        // 0x806B0558: nop
    
            goto L_806B0568;
    }
    // 0x806B0558: nop

    // 0x806B055C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1714) << 16);
    // 0x806B0560: b           L_806B0590
    // 0x806B0564: lwc1        $f0, 0x16A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1714));
        goto L_806B0590;
    // 0x806B0564: lwc1        $f0, 0x16A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1714));
L_806B0568:
    // 0x806B0568: b           L_806B0590
    // 0x806B056C: lwc1        $f0, 0x16A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1718));
        goto L_806B0590;
    // 0x806B056C: lwc1        $f0, 0x16A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1718));
    // 0x806B0570: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_806B0574:
    // 0x806B0574: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1720) << 16);
    // 0x806B0578: bc1f        L_806B058C
    if (!c1cs) {
        // 0x806B057C: nop
    
            goto L_806B058C;
    }
    // 0x806B057C: nop

    // 0x806B0580: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X171C) << 16);
    // 0x806B0584: b           L_806B0590
    // 0x806B0588: lwc1        $f0, 0x16AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X171C));
        goto L_806B0590;
    // 0x806B0588: lwc1        $f0, 0x16AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X171C));
L_806B058C:
    // 0x806B058C: lwc1        $f0, 0x16B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1720));
L_806B0590:
    // 0x806B0590: add.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x806B0594: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806B0598: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806B059C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806B05A0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x806B05A4: nop

    // 0x806B05A8: bc1fl       L_806B05BC
    if (!c1cs) {
        // 0x806B05AC: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806B05BC;
    }
    goto skip_3;
    // 0x806B05AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_3:
    // 0x806B05B0: b           L_806B06EC
    // 0x806B05B4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
        goto L_806B06EC;
    // 0x806B05B4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x806B05B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806B05BC:
    // 0x806B05BC: nop

    // 0x806B05C0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806B05C4: nop

    // 0x806B05C8: bc1fl       L_806B05DC
    if (!c1cs) {
        // 0x806B05CC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_806B05DC;
    }
    goto skip_4;
    // 0x806B05CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_4:
    // 0x806B05D0: b           L_806B06EC
    // 0x806B05D4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
        goto L_806B06EC;
    // 0x806B05D4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x806B05D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_806B05DC:
    // 0x806B05DC: b           L_806B06EC
    // 0x806B05E0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_806B06EC;
    // 0x806B05E0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x806B05E4: lw          $t8, 0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC);
L_806B05E8:
    // 0x806B05E8: beql        $t8, $zero, L_806B066C
    if (ctx->r24 == 0) {
        // 0x806B05EC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_806B066C;
    }
    goto skip_5;
    // 0x806B05EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_5:
    // 0x806B05F0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806B05F4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x806B05F8: jal         0x80066DE4
    // 0x806B05FC: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806B05FC: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x806B0600: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806B0604: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806B0608: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1724) << 16);
    // 0x806B060C: lwc1        $f10, 0x16B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1724));
    // 0x806B0610: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x806B0614: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x806B0618: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806B061C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806B0620: add.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x806B0624: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x806B0628: nop

    // 0x806B062C: bc1fl       L_806B0640
    if (!c1cs) {
        // 0x806B0630: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806B0640;
    }
    goto skip_6;
    // 0x806B0630: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_6:
    // 0x806B0634: b           L_806B06EC
    // 0x806B0638: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
        goto L_806B06EC;
    // 0x806B0638: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x806B063C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806B0640:
    // 0x806B0640: nop

    // 0x806B0644: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806B0648: nop

    // 0x806B064C: bc1fl       L_806B0660
    if (!c1cs) {
        // 0x806B0650: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_806B0660;
    }
    goto skip_7;
    // 0x806B0650: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_7:
    // 0x806B0654: b           L_806B06EC
    // 0x806B0658: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
        goto L_806B06EC;
    // 0x806B0658: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x806B065C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_806B0660:
    // 0x806B0660: b           L_806B06EC
    // 0x806B0664: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_806B06EC;
    // 0x806B0664: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x806B0668: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_806B066C:
    // 0x806B066C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806B0670: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806B0674: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x806B0678: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X16D8) << 16);
    // 0x806B067C: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x806B0680: bc1fl       L_806B0690
    if (!c1cs) {
        // 0x806B0684: sll         $t0, $t9, 2
        ctx->r8 = S32(ctx->r25 << 2);
            goto L_806B0690;
    }
    goto skip_8;
    // 0x806B0684: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    skip_8:
    // 0x806B0688: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806B068C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
L_806B0690:
    // 0x806B0690: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x806B0694: lwc1        $f6, 0x1668($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X16D8));
    // 0x806B0698: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1728) << 16);
    // 0x806B069C: lwc1        $f8, 0x16B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1728));
    // 0x806B06A0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806B06A4: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806B06A8: add.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x806B06AC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x806B06B0: nop

    // 0x806B06B4: bc1fl       L_806B06C8
    if (!c1cs) {
        // 0x806B06B8: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806B06C8;
    }
    goto skip_9;
    // 0x806B06B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_9:
    // 0x806B06BC: b           L_806B06EC
    // 0x806B06C0: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
        goto L_806B06EC;
    // 0x806B06C0: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    // 0x806B06C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806B06C8:
    // 0x806B06C8: nop

    // 0x806B06CC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806B06D0: nop

    // 0x806B06D4: bc1fl       L_806B06E8
    if (!c1cs) {
        // 0x806B06D8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_806B06E8;
    }
    goto skip_10;
    // 0x806B06D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_10:
    // 0x806B06DC: b           L_806B06E8
    // 0x806B06E0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_806B06E8;
    // 0x806B06E0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x806B06E4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_806B06E8:
    // 0x806B06E8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_806B06EC:
    // 0x806B06EC: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    // 0x806B06F0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x806B06F4: lw          $t2, 0x1F4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1F4);
    // 0x806B06F8: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x806B06FC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x806B0700: lwc1        $f12, 0x50($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X50);
    // 0x806B0704: jal         0x80066E88
    // 0x806B0708: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806B0708: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x806B070C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806B0710: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x806B0714: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806B0718: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806B071C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806B0720: jal         0x80066DE4
    // 0x806B0724: swc1        $f8, 0xC4($t3)
    MEM_W(0XC4, ctx->r11) = ctx->f8.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x806B0724: swc1        $f8, 0xC4($t3)
    MEM_W(0XC4, ctx->r11) = ctx->f8.u32l;
    after_2:
    // 0x806B0728: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806B072C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806B0730: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806B0734: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806B0738: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X172C) << 16);
    // 0x806B073C: lwc1        $f10, 0x16BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X172C));
    // 0x806B0740: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x806B0744: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806B0748: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806B074C: swc1        $f4, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->f4.u32l;
    // 0x806B0750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B0754: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806B0758: jr          $ra
    // 0x806B075C: nop

    return;
    // 0x806B075C: nop

;}
RECOMP_FUNC void func_804E9CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9CC0: addiu       $v0, $a0, 0xD
    ctx->r2 = ADD32(ctx->r4, 0XD);
    // 0x804E9CC4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x804E9CC8: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x804E9CCC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x804E9CD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804E9CD4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x804E9CD8: beq         $a3, $a0, L_804E9DB0
    if (ctx->r7 == ctx->r4) {
        // 0x804E9CDC: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_804E9DB0;
    }
    // 0x804E9CDC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_804E9CE0:
    // 0x804E9CE0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x804E9CE4: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x804E9CE8: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x804E9CEC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804E9CF0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x804E9CF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804E9CF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804E9CFC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x804E9D00: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804E9D04: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804E9D08: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x804E9D0C: nop

    // 0x804E9D10: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804E9D14: sb          $t0, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r8;
    // 0x804E9D18: lw          $t1, -0xC($a2)
    ctx->r9 = MEM_W(ctx->r6, -0XC);
    // 0x804E9D1C: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x804E9D20: lbu         $t2, -0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, -0X3);
    // 0x804E9D24: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x804E9D28: nop

    // 0x804E9D2C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804E9D30: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804E9D34: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804E9D38: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x804E9D3C: nop

    // 0x804E9D40: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804E9D44: sb          $t5, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r13;
    // 0x804E9D48: lw          $t6, -0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, -0X8);
    // 0x804E9D4C: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x804E9D50: lbu         $t8, -0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X2);
    // 0x804E9D54: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x804E9D58: nop

    // 0x804E9D5C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804E9D60: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804E9D64: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804E9D68: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x804E9D6C: nop

    // 0x804E9D70: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804E9D74: sb          $t0, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r8;
    // 0x804E9D78: lw          $t1, -0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, -0X4);
    // 0x804E9D7C: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x804E9D80: lbu         $t3, -0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, -0X1);
    // 0x804E9D84: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x804E9D88: nop

    // 0x804E9D8C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804E9D90: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804E9D94: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804E9D98: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x804E9D9C: nop

    // 0x804E9DA0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x804E9DA4: sb          $t5, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r13;
    // 0x804E9DA8: bne         $a3, $a0, L_804E9CE0
    if (ctx->r7 != ctx->r4) {
        // 0x804E9DAC: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_804E9CE0;
    }
    // 0x804E9DAC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_804E9DB0:
    // 0x804E9DB0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x804E9DB4: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x804E9DB8: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x804E9DBC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804E9DC0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804E9DC4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804E9DC8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x804E9DCC: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804E9DD0: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804E9DD4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x804E9DD8: nop

    // 0x804E9DDC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804E9DE0: sb          $t0, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r8;
    // 0x804E9DE4: lw          $t1, -0xC($a2)
    ctx->r9 = MEM_W(ctx->r6, -0XC);
    // 0x804E9DE8: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x804E9DEC: lbu         $t2, -0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, -0X3);
    // 0x804E9DF0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x804E9DF4: nop

    // 0x804E9DF8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804E9DFC: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804E9E00: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804E9E04: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x804E9E08: nop

    // 0x804E9E0C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804E9E10: sb          $t5, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r13;
    // 0x804E9E14: lw          $t6, -0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, -0X8);
    // 0x804E9E18: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x804E9E1C: lbu         $t8, -0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X2);
    // 0x804E9E20: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x804E9E24: nop

    // 0x804E9E28: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804E9E2C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804E9E30: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804E9E34: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x804E9E38: nop

    // 0x804E9E3C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804E9E40: sb          $t0, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r8;
    // 0x804E9E44: lw          $t1, -0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, -0X4);
    // 0x804E9E48: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x804E9E4C: lbu         $t3, -0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, -0X1);
    // 0x804E9E50: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x804E9E54: nop

    // 0x804E9E58: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804E9E5C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x804E9E60: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804E9E64: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x804E9E68: nop

    // 0x804E9E6C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x804E9E70: sb          $t5, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r13;
    // 0x804E9E74: jr          $ra
    // 0x804E9E78: nop

    return;
    // 0x804E9E78: nop

;}
RECOMP_FUNC void func_80715B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715BA0: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80715BA4: lui         $t8, 0x8071
    ctx->r24 = S32(RELOC_HI16(730, 0X1548) << 16);
    // 0x80715BA8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80715BAC: bne         $t6, $zero, L_80715BC4
    if (ctx->r14 != 0) {
        // 0x80715BB0: addiu       $t8, $t8, 0x5D68
        ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(730, 0X1548));
            goto L_80715BC4;
    }
    // 0x80715BB0: addiu       $t8, $t8, 0x5D68
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(730, 0X1548));
    // 0x80715BB4: jal         0x800447C8
    // 0x80715BB8: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80715BB8: nop

    after_0:
    // 0x80715BBC: b           L_80715C18
    // 0x80715BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80715C18;
    // 0x80715BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715BC4:
    // 0x80715BC4: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x80715BC8: sh          $t7, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r15;
    // 0x80715BCC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80715BD0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80715BD4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x80715BD8: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x80715BDC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80715BE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80715BE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80715BE8: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x80715BEC: lui         $t1, 0x8071
    ctx->r9 = S32(RELOC_HI16(730, 0XBF0) << 16);
    // 0x80715BF0: addiu       $t1, $t1, 0x5410
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(730, 0XBF0));
    // 0x80715BF4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80715BF8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80715BFC: jal         0x8071584C
    // 0x80715C00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8071584C(rdram, ctx);
        goto after_1;
    // 0x80715C00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80715C04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80715C08: lui         $t2, 0x8071
    ctx->r10 = S32(RELOC_HI16(730, 0X1350) << 16);
    // 0x80715C0C: addiu       $t2, $t2, 0x5B70
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(730, 0X1350));
    // 0x80715C10: sw          $t2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r10;
    // 0x80715C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715C18:
    // 0x80715C18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715C1C: jr          $ra
    // 0x80715C20: nop

    return;
    // 0x80715C20: nop

;}
RECOMP_FUNC void func_80022FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022FA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022FA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022FAC: lwc1        $f4, -0x340($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X340);
    // 0x80022FB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022FB4: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80022FB8: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x80022FBC: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80022FC0: lwc1        $f6, -0x33C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X33C);
    // 0x80022FC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022FC8: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
    // 0x80022FCC: lwc1        $f8, -0x338($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X338);
    // 0x80022FD0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80022FD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022FD8: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x80022FDC: jr          $ra
    // 0x80022FE0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80022FE0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_805A1848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1848: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x805A184C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x805A1850: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x805A1854: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x805A1858: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x805A185C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x805A1860: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x805A1864: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x805A1868: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x805A186C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x805A1870: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x805A1874: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805A1878: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805A187C: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A1880: lw          $s5, 0x174($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X174);
    // 0x805A1884: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A1888: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x805A188C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x805A1890: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x805A1894: beq         $v0, $zero, L_805A18B4
    if (ctx->r2 == 0) {
        // 0x805A1898: lw          $s1, 0x2C($t6)
        ctx->r17 = MEM_W(ctx->r14, 0X2C);
            goto L_805A18B4;
    }
    // 0x805A1898: lw          $s1, 0x2C($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X2C);
    // 0x805A189C: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x805A18A0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x805A18A4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x805A18A8: beq         $t7, $at, L_805A18B4
    if (ctx->r15 == ctx->r1) {
        // 0x805A18AC: nop
    
            goto L_805A18B4;
    }
    // 0x805A18AC: nop

    // 0x805A18B0: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
L_805A18B4:
    // 0x805A18B4: jal         0x80049D74
    // 0x805A18B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x805A18B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x805A18BC: beq         $s1, $zero, L_805A19F0
    if (ctx->r17 == 0) {
        // 0x805A18C0: sw          $zero, 0x8($s5)
        MEM_W(0X8, ctx->r21) = 0;
            goto L_805A19F0;
    }
    // 0x805A18C0: sw          $zero, 0x8($s5)
    MEM_W(0X8, ctx->r21) = 0;
    // 0x805A18C4: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x805A18C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805A18CC: subu        $s2, $s2, $s1
    ctx->r18 = SUB32(ctx->r18, ctx->r17);
    // 0x805A18D0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x805A18D4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x805A18D8: sll         $s2, $s2, 3
    ctx->r18 = S32(ctx->r18 << 3);
    // 0x805A18DC: addiu       $fp, $zero, 0x40
    ctx->r30 = ADD32(0, 0X40);
    // 0x805A18E0: addiu       $s7, $zero, 0x38
    ctx->r23 = ADD32(0, 0X38);
    // 0x805A18E4: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x805A18E8: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x805A18EC: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
L_805A18F0:
    // 0x805A18F0: addiu       $s2, $s2, -0x18
    ctx->r18 = ADD32(ctx->r18, -0X18);
    // 0x805A18F4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x805A18F8: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x805A18FC: addu        $v0, $t0, $s2
    ctx->r2 = ADD32(ctx->r8, ctx->r18);
    // 0x805A1900: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x805A1904: beq         $v1, $zero, L_805A1958
    if (ctx->r3 == 0) {
        // 0x805A1908: nop
    
            goto L_805A1958;
    }
    // 0x805A1908: nop

    // 0x805A190C: beq         $s6, $v1, L_805A1958
    if (ctx->r22 == ctx->r3) {
        // 0x805A1910: nop
    
            goto L_805A1958;
    }
    // 0x805A1910: nop

    // 0x805A1914: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x805A1918: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x805A191C: beq         $s7, $v1, L_805A1958
    if (ctx->r23 == ctx->r3) {
        // 0x805A1920: nop
    
            goto L_805A1958;
    }
    // 0x805A1920: nop

    // 0x805A1924: beq         $fp, $v1, L_805A1958
    if (ctx->r30 == ctx->r3) {
        // 0x805A1928: nop
    
            goto L_805A1958;
    }
    // 0x805A1928: nop

    // 0x805A192C: beq         $s1, $s4, L_805A19E8
    if (ctx->r17 == ctx->r20) {
        // 0x805A1930: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_805A19E8;
    }
    // 0x805A1930: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x805A1934: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(411, 0X1D28) << 16);
    // 0x805A1938: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x805A193C: lw          $t9, 0x3098($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(411, 0X1D28));
    // 0x805A1940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A1944: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x805A1948: jalr        $t9
    // 0x805A194C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805A194C: nop

    after_1:
    // 0x805A1950: b           L_805A19E8
    // 0x805A1954: nop

        goto L_805A19E8;
    // 0x805A1954: nop

L_805A1958:
    // 0x805A1958: bne         $s1, $s4, L_805A19E8
    if (ctx->r17 != ctx->r20) {
        // 0x805A195C: nop
    
            goto L_805A19E8;
    }
    // 0x805A195C: nop

    // 0x805A1960: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x805A1964: bne         $t2, $zero, L_805A19E8
    if (ctx->r10 != 0) {
        // 0x805A1968: nop
    
            goto L_805A19E8;
    }
    // 0x805A1968: nop

    // 0x805A196C: lw          $t3, 0xC($s3)
    ctx->r11 = MEM_W(ctx->r19, 0XC);
    // 0x805A1970: beq         $t3, $zero, L_805A19E8
    if (ctx->r11 == 0) {
        // 0x805A1974: nop
    
            goto L_805A19E8;
    }
    // 0x805A1974: nop

    // 0x805A1978: lbu         $t4, 0x30($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X30);
    // 0x805A197C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A1980: bne         $t4, $at, L_805A19E8
    if (ctx->r12 != ctx->r1) {
        // 0x805A1984: nop
    
            goto L_805A19E8;
    }
    // 0x805A1984: nop

    // 0x805A1988: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x805A198C: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x805A1990: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805A1994: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x805A1998: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x805A199C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805A19A0: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805A19A4: swc1        $f22, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f22.u32l;
    // 0x805A19A8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x805A19AC: swc1        $f22, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f22.u32l;
    // 0x805A19B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805A19B4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x805A19B8: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x805A19BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A19C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A19C4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x805A19C8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A19CC: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
    // 0x805A19D0: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x805A19D4: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x805A19D8: sw          $t7, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r15;
    // 0x805A19DC: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x805A19E0: jal         0x805A2B28
    // 0x805A19E4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_2;
    // 0x805A19E4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
L_805A19E8:
    // 0x805A19E8: bnel        $s1, $zero, L_805A18F0
    if (ctx->r17 != 0) {
        // 0x805A19EC: lw          $t9, 0x0($s5)
        ctx->r25 = MEM_W(ctx->r21, 0X0);
            goto L_805A18F0;
    }
    goto skip_0;
    // 0x805A19EC: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    skip_0:
L_805A19F0:
    // 0x805A19F0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x805A19F4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805A19F8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805A19FC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x805A1A00: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x805A1A04: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x805A1A08: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x805A1A0C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x805A1A10: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x805A1A14: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x805A1A18: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x805A1A1C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x805A1A20: jr          $ra
    // 0x805A1A24: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x805A1A24: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8042D33C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042D33C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8042D340: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8042D344: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8042D348: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8042D34C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8042D350: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8042D354: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(50, 0X2F04) << 16);
    // 0x8042D358: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8042D35C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8042D360: addiu       $t7, $t7, -0x285C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(50, 0X2F04));
    // 0x8042D364: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8042D368: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8042D36C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042D370: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8042D374: sw          $t9, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r25;
    // 0x8042D378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042D37C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8042D380: jal         0x8042D50C
    // 0x8042D384: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8042D50C(rdram, ctx);
        goto after_0;
    // 0x8042D384: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8042D388: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8042D38C: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8042D390: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x8042D394: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8042D398: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8042D39C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x8042D3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042D3A4: jal         0x800457A0
    // 0x8042D3A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_1;
    // 0x8042D3A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8042D3AC: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x8042D3B0: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(50, 0XFCC) << 16);
    // 0x8042D3B4: addiu       $t2, $t2, -0x4794
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(50, 0XFCC));
    // 0x8042D3B8: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
    // 0x8042D3BC: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8042D3C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8042D3C4: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x8042D3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042D3CC: jal         0x80045A34
    // 0x8042D3D0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8042D3D0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
    // 0x8042D3D4: lui         $t4, 0x8043
    ctx->r12 = S32(RELOC_HI16(50, 0X25BC) << 16);
    // 0x8042D3D8: addiu       $t4, $t4, -0x31A4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(50, 0X25BC));
    // 0x8042D3DC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8042D3E0: sw          $t4, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r12;
    // 0x8042D3E4: lui         $t5, 0x8043
    ctx->r13 = S32(RELOC_HI16(50, 0X2DA0) << 16);
    // 0x8042D3E8: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(50, 0X2DA8) << 16);
    // 0x8042D3EC: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(50, 0X2DB0) << 16);
    // 0x8042D3F0: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(50, 0X2DBC) << 16);
    // 0x8042D3F4: addiu       $t9, $t9, -0x29A4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(50, 0X2DBC));
    // 0x8042D3F8: addiu       $t7, $t7, -0x29B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(50, 0X2DB0));
    // 0x8042D3FC: addiu       $t6, $t6, -0x29B8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(50, 0X2DA8));
    // 0x8042D400: addiu       $t5, $t5, -0x29C0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(50, 0X2DA0));
    // 0x8042D404: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8042D408: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8042D40C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8042D410: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8042D414: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8042D418: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8042D41C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8042D420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042D424: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8042D428: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8042D42C: jal         0x8042B18C
    // 0x8042D430: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8042B18C(rdram, ctx);
        goto after_3;
    // 0x8042D430: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x8042D434: jal         0x800653D8
    // 0x8042D438: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x8042D438: nop

    after_4:
    // 0x8042D43C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8042D440: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042D444: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8042D448: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042D44C: andi        $t0, $v0, 0x3F
    ctx->r8 = ctx->r2 & 0X3F;
    // 0x8042D450: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8042D454: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
    // 0x8042D458: sw          $t1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r9;
    // 0x8042D45C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8042D460: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x8042D464: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8042D468: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8042D46C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042D470: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    // 0x8042D474: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042D478: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8042D47C: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8042D480: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8042D484: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8042D488: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x8042D48C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8042D490: jal         0x8042CF94
    // 0x8042D494: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    func_8042CF94(rdram, ctx);
        goto after_5;
    // 0x8042D494: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    after_5:
    // 0x8042D498: jal         0x8042CF18
    // 0x8042D49C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_8042CF18(rdram, ctx);
        goto after_6;
    // 0x8042D49C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x8042D4A0: jal         0x8042D324
    // 0x8042D4A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042D324(rdram, ctx);
        goto after_7;
    // 0x8042D4A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8042D4A8: jal         0x8042D2A4
    // 0x8042D4AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042D2A4(rdram, ctx);
        goto after_8;
    // 0x8042D4AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8042D4B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8042D4B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042D4B8: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // 0x8042D4BC: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x8042D4C0: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x8042D4C4: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x8042D4C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042D4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042D4D0: jal         0x8006CB0C
    // 0x8042D4D4: swc1        $f10, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f10.u32l;
    func_8006CB0C(rdram, ctx);
        goto after_9;
    // 0x8042D4D4: swc1        $f10, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f10.u32l;
    after_9:
    // 0x8042D4D8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8042D4DC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042D4E0: jal         0x8006CB1C
    // 0x8042D4E4: nop

    func_8006CB1C(rdram, ctx);
        goto after_10;
    // 0x8042D4E4: nop

    after_10:
    // 0x8042D4E8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8042D4EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042D4F0: jal         0x8006CB2C
    // 0x8042D4F4: nop

    func_8006CB2C(rdram, ctx);
        goto after_11;
    // 0x8042D4F4: nop

    after_11:
    // 0x8042D4F8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8042D4FC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8042D500: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8042D504: jr          $ra
    // 0x8042D508: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8042D508: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_804536C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804536C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804536C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804536CC: jal         0x80453644
    // 0x804536D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80453644(rdram, ctx);
        goto after_0;
    // 0x804536D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x804536D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804536D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804536DC: jr          $ra
    // 0x804536E0: nop

    return;
    // 0x804536E0: nop

;}
RECOMP_FUNC void eepmgr_HandleWrite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D1EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007D1F0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007D1F4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8007D1F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D1FC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007D200: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007D204: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007D208: lbu         $t6, 0x21C($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X21C);
    // 0x8007D20C: bnel        $t6, $zero, L_8007D220
    if (ctx->r14 != 0) {
        // 0x8007D210: lbu         $t7, 0x224($s3)
        ctx->r15 = MEM_BU(ctx->r19, 0X224);
            goto L_8007D220;
    }
    goto skip_0;
    // 0x8007D210: lbu         $t7, 0x224($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X224);
    skip_0:
    // 0x8007D214: b           L_8007D2A8
    // 0x8007D218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007D2A8;
    // 0x8007D218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007D21C: lbu         $t7, 0x224($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X224);
L_8007D220:
    // 0x8007D220: bnel        $t7, $zero, L_8007D234
    if (ctx->r15 != 0) {
        // 0x8007D224: lhu         $v0, 0x21E($s3)
        ctx->r2 = MEM_HU(ctx->r19, 0X21E);
            goto L_8007D234;
    }
    goto skip_1;
    // 0x8007D224: lhu         $v0, 0x21E($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X21E);
    skip_1:
    // 0x8007D228: b           L_8007D2A8
    // 0x8007D22C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007D2A8;
    // 0x8007D22C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007D230: lhu         $v0, 0x21E($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X21E);
L_8007D234:
    // 0x8007D234: lw          $s1, 0x220($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X220);
    // 0x8007D238: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8007D23C: blez        $v0, L_8007D2A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007D240: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8007D2A4;
    }
    // 0x8007D240: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8007D244:
    // 0x8007D244: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8007D248: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8007D24C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8007D250: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x8007D254: bne         $t8, $t0, L_8007D260
    if (ctx->r24 != ctx->r8) {
        // 0x8007D258: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8007D260;
    }
    // 0x8007D258: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8007D25C: beq         $t9, $t1, L_8007D290
    if (ctx->r25 == ctx->r9) {
        // 0x8007D260: andi        $a1, $s2, 0xFF
        ctx->r5 = ctx->r18 & 0XFF;
            goto L_8007D290;
    }
L_8007D260:
    // 0x8007D260: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    // 0x8007D264: jal         0x8007D0B0
    // 0x8007D268: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    eepmgr_Write(rdram, ctx);
        goto after_0;
    // 0x8007D268: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x8007D26C: beql        $v0, $zero, L_8007D280
    if (ctx->r2 == 0) {
        // 0x8007D270: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_8007D280;
    }
    goto skip_2;
    // 0x8007D270: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8007D274: b           L_8007D2A8
    // 0x8007D278: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007D2A8;
    // 0x8007D278: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007D27C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_8007D280:
    // 0x8007D280: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8007D284: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8007D288: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x8007D28C: lhu         $v0, 0x21E($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X21E);
L_8007D290:
    // 0x8007D290: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007D294: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D298: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8007D29C: bne         $at, $zero, L_8007D244
    if (ctx->r1 != 0) {
        // 0x8007D2A0: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8007D244;
    }
    // 0x8007D2A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8007D2A4:
    // 0x8007D2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007D2A8:
    // 0x8007D2A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007D2AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007D2B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007D2B4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D2B8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007D2BC: jr          $ra
    // 0x8007D2C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007D2C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80475600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475600: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475604: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475608: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047560C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475610: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475614: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475618: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047561C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475620: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475624: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475628: jr          $ra
    // 0x8047562C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047562C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807B9014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9014: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807B9018: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807B901C: lbu         $t6, 0xFB8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XFB8);
    // 0x807B9020: andi        $t7, $t6, 0xFFF3
    ctx->r15 = ctx->r14 & 0XFFF3;
    // 0x807B9024: sb          $t7, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r15;
    // 0x807B9028: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B902C: jr          $ra
    // 0x807B9030: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    return;
    // 0x807B9030: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
;}
RECOMP_FUNC void func_8057FBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057FBD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057FBDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057FBE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057FBE4: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47DC) << 16);
    // 0x8057FBE8: lwc1        $f0, 0x35EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47DC));
    // 0x8057FBEC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8057FBF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057FBF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057FBF8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8057FBFC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8057FC00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8057FC04: bc1f        L_8057FC20
    if (!c1cs) {
        // 0x8057FC08: nop
    
            goto L_8057FC20;
    }
    // 0x8057FC08: nop

    // 0x8057FC0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8057FC10: jal         0x8057F8C4
    // 0x8057FC14: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_8057F8C4(rdram, ctx);
        goto after_0;
    // 0x8057FC14: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_0:
    // 0x8057FC18: b           L_8057FC5C
    // 0x8057FC1C: nop

        goto L_8057FC5C;
    // 0x8057FC1C: nop

L_8057FC20:
    // 0x8057FC20: jal         0x805802D8
    // 0x8057FC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805802D8(rdram, ctx);
        goto after_1;
    // 0x8057FC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8057FC28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8057FC2C: jal         0x8057F74C
    // 0x8057FC30: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    func_8057F74C(rdram, ctx);
        goto after_2;
    // 0x8057FC30: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    after_2:
    // 0x8057FC34: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8057FC38: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8057FC3C: lui         $a1, 0x8058
    ctx->r5 = S32(RELOC_HI16(399, 0X41A8) << 16);
    // 0x8057FC40: addiu       $a1, $a1, 0x2FB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(399, 0X41A8));
    // 0x8057FC44: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8057FC48: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x8057FC4C: addiu       $a2, $zero, 0x40EC
    ctx->r6 = ADD32(0, 0X40EC);
    // 0x8057FC50: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8057FC54: jalr        $t9
    // 0x8057FC58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8057FC58: nop

    after_3:
L_8057FC5C:
    // 0x8057FC5C: jal         0x8057F810
    // 0x8057FC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F810(rdram, ctx);
        goto after_4;
    // 0x8057FC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8057FC64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057FC68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057FC6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057FC70: jr          $ra
    // 0x8057FC74: nop

    return;
    // 0x8057FC74: nop

;}
RECOMP_FUNC void func_805312B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805312B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805312B4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x805312B8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x805312BC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x805312C0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x805312C4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x805312C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x805312CC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x805312D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805312D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805312D8: lw          $t6, 0x134($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X134);
    // 0x805312DC: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(342, 0X192C) << 16);
    // 0x805312E0: addiu       $t8, $t8, 0x271C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(342, 0X192C));
    // 0x805312E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805312E8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805312EC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x805312F0: lui         $s5, 0x8053
    ctx->r21 = S32(RELOC_HI16(342, 0X1920) << 16);
    // 0x805312F4: lui         $s7, 0x8053
    ctx->r23 = S32(RELOC_HI16(342, 0X192C) << 16);
    // 0x805312F8: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x805312FC: addiu       $s7, $s7, 0x271C
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(342, 0X192C));
    // 0x80531300: addiu       $s5, $s5, 0x2710
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(342, 0X1920));
    // 0x80531304: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x80531308: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
L_8053130C:
    // 0x8053130C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80531310: addiu       $s1, $s6, 0x278
    ctx->r17 = ADD32(ctx->r22, 0X278);
L_80531314:
    // 0x80531314: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80531318: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x8053131C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80531320: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80531324: jal         0x80065528
    // 0x80531328: addu        $a1, $t9, $s0
    ctx->r5 = ADD32(ctx->r25, ctx->r16);
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x80531328: addu        $a1, $t9, $s0
    ctx->r5 = ADD32(ctx->r25, ctx->r16);
    after_0:
    // 0x8053132C: lh          $t0, 0x0($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X0);
    // 0x80531330: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80531334: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80531338: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8053133C: bne         $s0, $s4, L_80531314
    if (ctx->r16 != ctx->r20) {
        // 0x80531340: sh          $t0, 0x2($s3)
        MEM_H(0X2, ctx->r19) = ctx->r8;
            goto L_80531314;
    }
    // 0x80531340: sh          $t0, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r8;
    // 0x80531344: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80531348: bne         $s5, $s7, L_8053130C
    if (ctx->r21 != ctx->r23) {
        // 0x8053134C: addiu       $s6, $s6, 0x40
        ctx->r22 = ADD32(ctx->r22, 0X40);
            goto L_8053130C;
    }
    // 0x8053134C: addiu       $s6, $s6, 0x40
    ctx->r22 = ADD32(ctx->r22, 0X40);
    // 0x80531350: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80531354: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80531358: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8053135C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80531360: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80531364: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80531368: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8053136C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80531370: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80531374: jr          $ra
    // 0x80531378: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80531378: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807A61F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A61F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807A61F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807A61F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807A61FC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x807A6200: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x807A6204: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A6208: slti        $at, $t6, 0x13
    ctx->r1 = SIGNED(ctx->r14) < 0X13 ? 1 : 0;
    // 0x807A620C: beql        $at, $zero, L_807A6294
    if (ctx->r1 == 0) {
        // 0x807A6210: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_807A6294;
    }
    goto skip_0;
    // 0x807A6210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x807A6214: jal         0x80047090
    // 0x807A6218: addiu       $a0, $zero, 0x46E8
    ctx->r4 = ADD32(0, 0X46E8);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807A6218: addiu       $a0, $zero, 0x46E8
    ctx->r4 = ADD32(0, 0X46E8);
    after_0:
    // 0x807A621C: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x807A6220: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x807A6224: lui         $at, 0x46E8
    ctx->r1 = S32(0X46E8 << 16);
    // 0x807A6228: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807A622C: lw          $a3, 0x88($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X88);
    // 0x807A6230: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    // 0x807A6234: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(847, 0X18B0) << 16);
    // 0x807A6238: addiu       $a0, $a0, 0x75B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(847, 0X18B0));
    // 0x807A623C: or          $a1, $v0, $at
    ctx->r5 = ctx->r2 | ctx->r1;
    // 0x807A6240: jal         0x80046804
    // 0x807A6244: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x807A6244: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x807A6248: beq         $v0, $zero, L_807A6290
    if (ctx->r2 == 0) {
        // 0x807A624C: lhu         $t8, 0x2A($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X2A);
            goto L_807A6290;
    }
    // 0x807A624C: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x807A6250: lhu         $t0, 0xE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XE);
    // 0x807A6254: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x807A6258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A625C: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x807A6260: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x807A6264: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x807A6268: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x807A626C: jal         0x80047F9C
    // 0x807A6270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807A6270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x807A6274: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x807A6278: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807A627C: jal         0x807A6020
    // 0x807A6280: sb          $t3, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r11;
    func_807A6020(rdram, ctx);
        goto after_3;
    // 0x807A6280: sb          $t3, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r11;
    after_3:
    // 0x807A6284: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x807A6288: jal         0x807A60A8
    // 0x807A628C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_807A60A8(rdram, ctx);
        goto after_4;
    // 0x807A628C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
L_807A6290:
    // 0x807A6290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807A6294:
    // 0x807A6294: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807A6298: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807A629C: jr          $ra
    // 0x807A62A0: nop

    return;
    // 0x807A62A0: nop

;}
RECOMP_FUNC void func_8005A3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A3D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A3D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A3DC: lw          $a0, 0xD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD8);
    // 0x8005A3E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A3E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005A3E8: jal         0x8005A36C
    // 0x8005A3EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8005A36C(rdram, ctx);
        goto after_0;
    // 0x8005A3EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8005A3F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A3F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A3F8: jr          $ra
    // 0x8005A3FC: nop

    return;
    // 0x8005A3FC: nop

;}
RECOMP_FUNC void func_807AE4A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE4A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AE4A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AE4A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AE4AC: jal         0x807AC734
    // 0x807AE4B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807AC734(rdram, ctx);
        goto after_0;
    // 0x807AE4B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807AE4B4: beq         $v0, $zero, L_807AE4CC
    if (ctx->r2 == 0) {
        // 0x807AE4B8: nop
    
            goto L_807AE4CC;
    }
    // 0x807AE4B8: nop

    // 0x807AE4BC: jal         0x807AE0E0
    // 0x807AE4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AE0E0(rdram, ctx);
        goto after_1;
    // 0x807AE4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807AE4C4: b           L_807AE57C
    // 0x807AE4C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807AE57C;
    // 0x807AE4C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE4CC:
    // 0x807AE4CC: jal         0x807ADD60
    // 0x807AE4D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807ADD60(rdram, ctx);
        goto after_2;
    // 0x807AE4D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807AE4D4: beql        $v0, $zero, L_807AE4F4
    if (ctx->r2 == 0) {
        // 0x807AE4D8: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_807AE4F4;
    }
    goto skip_0;
    // 0x807AE4D8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x807AE4DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE4E0: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE4E4: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x807AE4E8: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE4EC: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x807AE4F0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_807AE4F4:
    // 0x807AE4F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE4F8: blez        $v0, L_807AE508
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807AE4FC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_807AE508;
    }
    // 0x807AE4FC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x807AE500: b           L_807AE578
    // 0x807AE504: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
        goto L_807AE578;
    // 0x807AE504: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_807AE508:
    // 0x807AE508: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE514: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x807AE518: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE51C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807AE520: jal         0x807AEA24
    // 0x807AE524: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    func_807AEA24(rdram, ctx);
        goto after_3;
    // 0x807AE524: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    after_3:
    // 0x807AE528: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x807AE52C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE530: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x807AE534: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE538: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x807AE53C: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x807AE540: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE544: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x807AE548: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807AE54C: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x807AE550: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x807AE554: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807AE558: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
    // 0x807AE55C: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x807AE560: lbu         $t5, 0xF0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XF0);
    // 0x807AE564: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x807AE568: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x807AE56C: sb          $t7, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r15;
    // 0x807AE570: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x807AE574: sb          $zero, 0xF2($t8)
    MEM_B(0XF2, ctx->r24) = 0;
L_807AE578:
    // 0x807AE578: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE57C:
    // 0x807AE57C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AE580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AE584: jr          $ra
    // 0x807AE588: nop

    return;
    // 0x807AE588: nop

;}
RECOMP_FUNC void func_805829E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805829E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805829E4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x805829E8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x805829EC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x805829F0: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x805829F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x805829F8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x805829FC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80582A00: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80582A04: blez        $a1, L_80582A38
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80582A08: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80582A38;
    }
    // 0x80582A08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80582A0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80582A10: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80582A14: sll         $s3, $a1, 3
    ctx->r19 = S32(ctx->r5 << 3);
L_80582A18:
    // 0x80582A18: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80582A1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582A20: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80582A24: jal         0x8005C27C
    // 0x80582A28: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x80582A28: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x80582A2C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80582A30: bne         $s0, $s3, L_80582A18
    if (ctx->r16 != ctx->r19) {
        // 0x80582A34: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80582A18;
    }
    // 0x80582A34: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_80582A38:
    // 0x80582A38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80582A3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80582A40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80582A44: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80582A48: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80582A4C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80582A50: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80582A54: jr          $ra
    // 0x80582A58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80582A58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8043B000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B000: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043B004: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043B008: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8043B00C: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8043B010: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8043B014: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043B018: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8043B01C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043B020: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8043B024: nop

    // 0x8043B028: bc1fl       L_8043B040
    if (!c1cs) {
        // 0x8043B02C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8043B040;
    }
    goto skip_0;
    // 0x8043B02C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x8043B030: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8043B034: jr          $ra
    // 0x8043B038: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8043B038: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x8043B03C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8043B040:
    // 0x8043B040: nop

    // 0x8043B044: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8043B048: nop

    // 0x8043B04C: bc1f        L_8043B05C
    if (!c1cs) {
        // 0x8043B050: nop
    
            goto L_8043B05C;
    }
    // 0x8043B050: nop

    // 0x8043B054: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8043B058: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
L_8043B05C:
    // 0x8043B05C: jr          $ra
    // 0x8043B060: nop

    return;
    // 0x8043B060: nop

;}
RECOMP_FUNC void func_806748E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806748E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806748E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806748EC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806748F0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806748F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806748F8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806748FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80674900: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80674904: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80674908: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8067490C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80674910: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80674914: lui         $t2, 0x8067
    ctx->r10 = S32(RELOC_HI16(529, 0X1B88) << 16);
    // 0x80674918: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8067491C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80674920: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80674924: lw          $t2, 0x4B68($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(529, 0X1B88));
    // 0x80674928: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8067492C: jal         0x80674730
    // 0x80674930: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80674730(rdram, ctx);
        goto after_0;
    // 0x80674930: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x80674934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80674938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067493C: jr          $ra
    // 0x80674940: nop

    return;
    // 0x80674940: nop

    // 0x80674944: nop

    // 0x80674948: nop

    // 0x8067494C: nop

;}
RECOMP_FUNC void func_80677594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677594: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80677598: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(535, 0X1B84) << 16);
    // 0x8067759C: addiu       $t6, $t6, 0x7244
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(535, 0X1B84));
    // 0x806775A0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806775A4: jr          $ra
    // 0x806775A8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806775A8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8004BA14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BA14: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8004BA18: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8004BA1C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004BA20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004BA24: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8004BA28: lw          $a0, 0x174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X174);
    // 0x8004BA2C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8004BA30: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004BA34: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004BA38: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004BA3C: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8004BA40: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004BA44: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004BA48: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8004BA4C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004BA50: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8004BA54: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8004BA58: jal         0x80049864
    // 0x8004BA5C: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004BA5C: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004BA60: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8004BA64: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8004BA68: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8004BA6C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8004BA70: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004BA74: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8004BA78: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8004BA7C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004BA80: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BA84: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004BA88: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8004BA8C: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8004BA90: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8004BA94: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004BA98: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x8004BA9C: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8004BAA0: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8004BAA4: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004BAA8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004BAAC: sh          $t6, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r14;
    // 0x8004BAB0: srav        $t6, $t5, $t4
    ctx->r14 = S32(SIGNED(ctx->r13) >> (ctx->r12 & 31));
    // 0x8004BAB4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004BAB8: addiu       $t2, $v1, 0xC
    ctx->r10 = ADD32(ctx->r3, 0XC);
    // 0x8004BABC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8004BAC0: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8004BAC4: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004BAC8: andi        $t8, $t0, 0xF
    ctx->r24 = ctx->r8 & 0XF;
    // 0x8004BACC: sh          $t8, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r24;
    // 0x8004BAD0: lh          $t9, 0x50($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X50);
    // 0x8004BAD4: sh          $t6, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r14;
    // 0x8004BAD8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8004BADC: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8004BAE0: sh          $t1, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r9;
    // 0x8004BAE4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8004BAE8: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8004BAEC: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x8004BAF0: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8004BAF4: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8004BAF8: srl         $t3, $v0, 6
    ctx->r11 = S32(U32(ctx->r2) >> 6);
    // 0x8004BAFC: andi        $t4, $v0, 0x3F
    ctx->r12 = ctx->r2 & 0X3F;
    // 0x8004BB00: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8004BB04: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x8004BB08: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8004BB0C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8004BB10: lw          $t1, 0xA24($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XA24);
    // 0x8004BB14: andi        $t5, $t6, 0xFFFF
    ctx->r13 = ctx->r14 & 0XFFFF;
    // 0x8004BB18: lhu         $t8, 0x40($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X40);
    // 0x8004BB1C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8004BB20: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8004BB24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004BB28: and         $t7, $t4, $t5
    ctx->r15 = ctx->r12 & ctx->r13;
    // 0x8004BB2C: beql        $t7, $zero, L_8004BBC0
    if (ctx->r15 == 0) {
        // 0x8004BB30: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004BBC0;
    }
    goto skip_0;
    // 0x8004BB30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8004BB34: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
    // 0x8004BB38: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8004BB3C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8004BB40: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8004BB44: jal         0x8004B79C
    // 0x8004BB48: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_8004B79C(rdram, ctx);
        goto after_1;
    // 0x8004BB48: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8004BB4C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x8004BB50: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8004BB54: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004BB58: slti        $at, $a0, -0x8
    ctx->r1 = SIGNED(ctx->r4) < -0X8 ? 1 : 0;
    // 0x8004BB5C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BB60: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8004BB64: beq         $at, $zero, L_8004BB98
    if (ctx->r1 == 0) {
        // 0x8004BB68: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8004BB98;
    }
    // 0x8004BB68: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004BB6C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8004BB70: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8004BB74: lhu         $t2, 0x2A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2A);
    // 0x8004BB78: lwc1        $f16, 0x4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8004BB7C: lwc1        $f18, 0x88($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X88);
    // 0x8004BB80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004BB84: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8004BB88: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004BB8C: lwc1        $f4, 0x8BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8BC);
    // 0x8004BB90: b           L_8004BBC4
    // 0x8004BB94: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
        goto L_8004BBC4;
    // 0x8004BB94: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
L_8004BB98:
    // 0x8004BB98: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8004BB9C: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x8004BBA0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004BBA4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004BBA8: sb          $t3, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r11;
    // 0x8004BBAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004BBB0: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8004BBB4: b           L_8004BBC4
    // 0x8004BBB8: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
        goto L_8004BBC4;
    // 0x8004BBB8: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8004BBBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8004BBC0:
    // 0x8004BBC0: nop

L_8004BBC4:
    // 0x8004BBC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004BBC8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8004BBCC: jr          $ra
    // 0x8004BBD0: nop

    return;
    // 0x8004BBD0: nop

;}
RECOMP_FUNC void func_80054B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054B28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80054B2C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80054B30: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80054B34: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80054B38: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80054B3C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80054B40: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80054B44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80054B48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80054B4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80054B50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80054B54: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80054B58: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80054B5C: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80054B60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054B64: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80054B68: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80054B6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054B70: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80054B74: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80054B78: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80054B7C: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80054B80: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80054B84: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80054B88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80054B8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80054B90: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80054B94: ori         $t9, $zero, 0xAC80
    ctx->r25 = 0 | 0XAC80;
    // 0x80054B98: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x80054B9C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80054BA0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80054BA4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80054BA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80054BAC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80054BB0: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80054BB4: lui         $a2, 0xF0A
    ctx->r6 = S32(0XF0A << 16);
    // 0x80054BB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054BBC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80054BC0: ori         $a2, $a2, 0x7008
    ctx->r6 = ctx->r6 | 0X7008;
    // 0x80054BC4: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x80054BC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054BCC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80054BD0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80054BD4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80054BD8: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80054BDC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054BE0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80054BE4: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x80054BE8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054BEC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80054BF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054BF4: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x80054BF8: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x80054BFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054C00: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054C04: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80054C08: ori         $t8, $t8, 0xF279
    ctx->r24 = ctx->r24 | 0XF279;
    // 0x80054C0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80054C10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054C14: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054C18: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80054C1C: lui         $t6, 0xBB00
    ctx->r14 = S32(0XBB00 << 16);
    // 0x80054C20: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80054C24: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80054C28: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x80054C2C: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x80054C30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80054C34: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80054C38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80054C3C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80054C40: lw          $t8, 0x10($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X10);
    // 0x80054C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80054C48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80054C4C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054C50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80054C54: mflo        $t6
    ctx->r14 = lo;
    // 0x80054C58: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80054C5C: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80054C60: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80054C64: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80054C68: jal         0x8007711C
    // 0x80054C6C: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x80054C6C: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    after_0:
    // 0x80054C70: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80054C74: lw          $s3, 0x20($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X20);
    // 0x80054C78: lui         $s7, 0xE600
    ctx->r23 = S32(0XE600 << 16);
    // 0x80054C7C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80054C80: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80054C84: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80054C88: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80054C8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054C90: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x80054C94: lui         $fp, 0x700
    ctx->r30 = S32(0X700 << 16);
    // 0x80054C98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054C9C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054CA0: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x80054CA4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054CA8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054CAC: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80054CB0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80054CB4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054CB8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80054CBC: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x80054CC0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054CC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054CC8: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80054CCC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80054CD0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054CD4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054CD8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80054CDC: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80054CE0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80054CE4: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    // 0x80054CE8: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80054CEC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80054CF0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80054CF4: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80054CF8: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80054CFC: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054D00: srl         $v0, $a1, 3
    ctx->r2 = S32(U32(ctx->r5) >> 3);
    // 0x80054D04: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80054D08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80054D0C: mflo        $a0
    ctx->r4 = lo;
    // 0x80054D10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80054D14: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x80054D18: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80054D1C: sltiu       $at, $a0, 0x7FF
    ctx->r1 = ctx->r4 < 0X7FF ? 1 : 0;
    // 0x80054D20: beq         $at, $zero, L_80054D30
    if (ctx->r1 == 0) {
        // 0x80054D24: nop
    
            goto L_80054D30;
    }
    // 0x80054D24: nop

    // 0x80054D28: b           L_80054D30
    // 0x80054D2C: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
        goto L_80054D30;
    // 0x80054D2C: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_80054D30:
    // 0x80054D30: bne         $v0, $zero, L_80054D40
    if (ctx->r2 != 0) {
        // 0x80054D34: sll         $ra, $s5, 2
        ctx->r31 = S32(ctx->r21 << 2);
            goto L_80054D40;
    }
    // 0x80054D34: sll         $ra, $s5, 2
    ctx->r31 = S32(ctx->r21 << 2);
    // 0x80054D38: b           L_80054D40
    // 0x80054D3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80054D40;
    // 0x80054D3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80054D40:
    // 0x80054D40: bne         $v0, $zero, L_80054D50
    if (ctx->r2 != 0) {
        // 0x80054D44: addiu       $t6, $t0, 0x7FF
        ctx->r14 = ADD32(ctx->r8, 0X7FF);
            goto L_80054D50;
    }
    // 0x80054D44: addiu       $t6, $t0, 0x7FF
    ctx->r14 = ADD32(ctx->r8, 0X7FF);
    // 0x80054D48: b           L_80054D50
    // 0x80054D4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80054D50;
    // 0x80054D4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80054D50:
    // 0x80054D50: divu        $zero, $t6, $a2
    lo = S32(U32(ctx->r14) / U32(ctx->r6)); hi = S32(U32(ctx->r14) % U32(ctx->r6));
    // 0x80054D54: mflo        $t7
    ctx->r15 = lo;
    // 0x80054D58: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80054D5C: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x80054D60: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80054D64: or          $t9, $t8, $fp
    ctx->r25 = ctx->r24 | ctx->r30;
    // 0x80054D68: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80054D6C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80054D70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054D74: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80054D78: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80054D7C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054D80: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054D84: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80054D88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054D8C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80054D90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054D94: bne         $a2, $zero, L_80054DA0
    if (ctx->r6 != 0) {
        // 0x80054D98: nop
    
            goto L_80054DA0;
    }
    // 0x80054D98: nop

    // 0x80054D9C: break       7
    do_break(2147831196);
L_80054DA0:
    // 0x80054DA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80054DA4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80054DA8: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80054DAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80054DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80054DB4: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x80054DB8: srl         $t9, $t6, 3
    ctx->r25 = S32(U32(ctx->r14) >> 3);
    // 0x80054DBC: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x80054DC0: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80054DC4: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80054DC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80054DCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054DD0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80054DD4: addiu       $s6, $zero, 0x46
    ctx->r22 = ADD32(0, 0X46);
    // 0x80054DD8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80054DDC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80054DE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054DE4: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80054DE8: lui         $s4, 0xBF00
    ctx->r20 = S32(0XBF00 << 16);
    // 0x80054DEC: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80054DF0: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80054DF4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80054DF8: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80054DFC: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80054E00: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80054E04: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80054E08: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80054E0C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80054E10: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80054E14: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80054E18: sltiu       $at, $a1, 0x20
    ctx->r1 = ctx->r5 < 0X20 ? 1 : 0;
    // 0x80054E1C: bnel        $at, $zero, L_800550A8
    if (ctx->r1 != 0) {
        // 0x80054E20: sltiu       $at, $a1, 0x4
        ctx->r1 = ctx->r5 < 0X4 ? 1 : 0;
            goto L_800550A8;
    }
    goto skip_0;
    // 0x80054E20: sltiu       $at, $a1, 0x4
    ctx->r1 = ctx->r5 < 0X4 ? 1 : 0;
    skip_0:
L_80054E24:
    // 0x80054E24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054E28: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80054E2C: ori         $t7, $t7, 0x81FF
    ctx->r15 = ctx->r15 | 0X81FF;
    // 0x80054E30: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054E34: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80054E38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054E3C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80054E40: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80054E44: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80054E48: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80054E4C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80054E50: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80054E54:
    // 0x80054E54: lw          $t9, 0x18($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X18);
    // 0x80054E58: addu        $t8, $t9, $ra
    ctx->r24 = ADD32(ctx->r25, ctx->r31);
    // 0x80054E5C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80054E60: sltu        $at, $s2, $t7
    ctx->r1 = ctx->r18 < ctx->r15 ? 1 : 0;
    // 0x80054E64: bnel        $at, $zero, L_8005501C
    if (ctx->r1 != 0) {
        // 0x80054E68: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8005501C;
    }
    goto skip_1;
    // 0x80054E68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80054E6C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80054E70: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80054E74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054E78: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80054E7C: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054E80: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80054E84: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80054E88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80054E8C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80054E90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054E94: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x80054E98: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x80054E9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054EA0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054EA4: mflo        $t8
    ctx->r24 = lo;
    // 0x80054EA8: addu        $s3, $s3, $t8
    ctx->r19 = ADD32(ctx->r19, ctx->r24);
    // 0x80054EAC: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x80054EB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054EB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054EB8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80054EBC: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80054EC0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054EC4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80054EC8: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x80054ECC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054ED0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80054ED4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80054ED8: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    // 0x80054EDC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80054EE0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054EE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80054EE8: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80054EEC: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80054EF0: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x80054EF4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80054EF8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80054EFC: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x80054F00: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80054F04: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054F08: srl         $v0, $a1, 3
    ctx->r2 = S32(U32(ctx->r5) >> 3);
    // 0x80054F0C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80054F10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80054F14: mflo        $a0
    ctx->r4 = lo;
    // 0x80054F18: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80054F1C: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x80054F20: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80054F24: sltiu       $at, $a0, 0x7FF
    ctx->r1 = ctx->r4 < 0X7FF ? 1 : 0;
    // 0x80054F28: beq         $at, $zero, L_80054F38
    if (ctx->r1 == 0) {
        // 0x80054F2C: nop
    
            goto L_80054F38;
    }
    // 0x80054F2C: nop

    // 0x80054F30: b           L_80054F38
    // 0x80054F34: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
        goto L_80054F38;
    // 0x80054F34: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_80054F38:
    // 0x80054F38: bne         $v0, $zero, L_80054F48
    if (ctx->r2 != 0) {
        // 0x80054F3C: nop
    
            goto L_80054F48;
    }
    // 0x80054F3C: nop

    // 0x80054F40: b           L_80054F48
    // 0x80054F44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80054F48;
    // 0x80054F44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80054F48:
    // 0x80054F48: bne         $v0, $zero, L_80054F58
    if (ctx->r2 != 0) {
        // 0x80054F4C: addiu       $t6, $t0, 0x7FF
        ctx->r14 = ADD32(ctx->r8, 0X7FF);
            goto L_80054F58;
    }
    // 0x80054F4C: addiu       $t6, $t0, 0x7FF
    ctx->r14 = ADD32(ctx->r8, 0X7FF);
    // 0x80054F50: b           L_80054F58
    // 0x80054F54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80054F58;
    // 0x80054F54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80054F58:
    // 0x80054F58: divu        $zero, $t6, $a2
    lo = S32(U32(ctx->r14) / U32(ctx->r6)); hi = S32(U32(ctx->r14) % U32(ctx->r6));
    // 0x80054F5C: mflo        $t9
    ctx->r25 = lo;
    // 0x80054F60: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80054F64: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x80054F68: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80054F6C: or          $t7, $t8, $fp
    ctx->r15 = ctx->r24 | ctx->r30;
    // 0x80054F70: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80054F74: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80054F78: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054F7C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80054F80: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80054F84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054F88: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054F8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80054F90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80054F94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80054F98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054F9C: bne         $a2, $zero, L_80054FA8
    if (ctx->r6 != 0) {
        // 0x80054FA0: nop
    
            goto L_80054FA8;
    }
    // 0x80054FA0: nop

    // 0x80054FA4: break       7
    do_break(2147831716);
L_80054FA8:
    // 0x80054FA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80054FAC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80054FB0: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80054FB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80054FB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80054FBC: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x80054FC0: srl         $t7, $t6, 3
    ctx->r15 = S32(U32(ctx->r14) >> 3);
    // 0x80054FC4: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80054FC8: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x80054FCC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80054FD0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80054FD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054FD8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80054FDC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80054FE0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80054FE4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80054FE8: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80054FEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80054FF0: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80054FF4: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80054FF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80054FFC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80055000: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80055004: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80055008: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8005500C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80055010: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80055014: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80055018: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8005501C:
    // 0x8005501C: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x80055020: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80055024: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80055028: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005502C: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x80055030: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80055034: or          $a1, $t6, $t8
    ctx->r5 = ctx->r14 | ctx->r24;
    // 0x80055038: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x8005503C: or          $t7, $a1, $t9
    ctx->r15 = ctx->r5 | ctx->r25;
    // 0x80055040: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80055044: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80055048: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005504C: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x80055050: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80055054: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80055058: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005505C: or          $t9, $a1, $t8
    ctx->r25 = ctx->r5 | ctx->r24;
    // 0x80055060: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x80055064: addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // 0x80055068: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x8005506C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80055070: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80055074: bne         $t1, $s6, L_80054E54
    if (ctx->r9 != ctx->r22) {
        // 0x80055078: sw          $s4, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r20;
            goto L_80054E54;
    }
    // 0x80055078: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8005507C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80055080: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80055084: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80055088: sltiu       $at, $v0, 0x20
    ctx->r1 = ctx->r2 < 0X20 ? 1 : 0;
    // 0x8005508C: addiu       $t6, $t7, 0x200
    ctx->r14 = ADD32(ctx->r15, 0X200);
    // 0x80055090: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80055094: beq         $at, $zero, L_80054E24
    if (ctx->r1 == 0) {
        // 0x80055098: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_80054E24;
    }
    // 0x80055098: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8005509C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800550A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800550A4: sltiu       $at, $a1, 0x4
    ctx->r1 = ctx->r5 < 0X4 ? 1 : 0;
L_800550A8:
    // 0x800550A8: bne         $at, $zero, L_80055328
    if (ctx->r1 != 0) {
        // 0x800550AC: lui         $s4, 0xBF00
        ctx->r20 = S32(0XBF00 << 16);
            goto L_80055328;
    }
    // 0x800550AC: lui         $s4, 0xBF00
    ctx->r20 = S32(0XBF00 << 16);
    // 0x800550B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800550B4: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x800550B8: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800550BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800550C0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800550C4: sll         $t9, $a1, 10
    ctx->r25 = S32(ctx->r5 << 10);
    // 0x800550C8: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800550CC: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800550D0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800550D4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800550D8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800550DC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800550E0: sll         $ra, $s5, 2
    ctx->r31 = S32(ctx->r21 << 2);
    // 0x800550E4: beq         $a1, $zero, L_80055328
    if (ctx->r5 == 0) {
        // 0x800550E8: sw          $t6, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r14;
            goto L_80055328;
    }
    // 0x800550E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800550EC: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800550F0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800550F4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800550F8: sll         $s6, $s6, 1
    ctx->r22 = S32(ctx->r22 << 1);
    // 0x800550FC: addiu       $s6, $s6, 0x6
    ctx->r22 = ADD32(ctx->r22, 0X6);
    // 0x80055100: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80055104: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
L_80055108:
    // 0x80055108: lw          $t8, 0x18($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X18);
    // 0x8005510C: addu        $t7, $t8, $ra
    ctx->r15 = ADD32(ctx->r24, ctx->r31);
    // 0x80055110: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80055114: sltu        $at, $s2, $t9
    ctx->r1 = ctx->r18 < ctx->r25 ? 1 : 0;
    // 0x80055118: bne         $at, $zero, L_800552C4
    if (ctx->r1 != 0) {
        // 0x8005511C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800552C4;
    }
    // 0x8005511C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80055120: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80055124: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80055128: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005512C: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80055130: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055134: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80055138: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005513C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80055140: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80055144: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055148: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8005514C: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80055150: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80055154: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80055158: mflo        $t7
    ctx->r15 = lo;
    // 0x8005515C: addu        $s3, $s3, $t7
    ctx->r19 = ADD32(ctx->r19, ctx->r15);
    // 0x80055160: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x80055164: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80055168: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005516C: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    // 0x80055170: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80055174: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80055178: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x8005517C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80055180: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80055184: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80055188: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005518C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80055190: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80055194: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80055198: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8005519C: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800551A0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800551A4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800551A8: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800551AC: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x800551B0: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800551B4: srl         $v0, $a1, 3
    ctx->r2 = S32(U32(ctx->r5) >> 3);
    // 0x800551B8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800551BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800551C0: mflo        $a0
    ctx->r4 = lo;
    // 0x800551C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800551C8: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x800551CC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800551D0: sltiu       $at, $a0, 0x7FF
    ctx->r1 = ctx->r4 < 0X7FF ? 1 : 0;
    // 0x800551D4: beq         $at, $zero, L_800551E4
    if (ctx->r1 == 0) {
        // 0x800551D8: nop
    
            goto L_800551E4;
    }
    // 0x800551D8: nop

    // 0x800551DC: b           L_800551E4
    // 0x800551E0: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
        goto L_800551E4;
    // 0x800551E0: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_800551E4:
    // 0x800551E4: bne         $v0, $zero, L_800551F4
    if (ctx->r2 != 0) {
        // 0x800551E8: nop
    
            goto L_800551F4;
    }
    // 0x800551E8: nop

    // 0x800551EC: b           L_800551F4
    // 0x800551F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_800551F4;
    // 0x800551F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800551F4:
    // 0x800551F4: bne         $v0, $zero, L_80055204
    if (ctx->r2 != 0) {
        // 0x800551F8: addiu       $t6, $t0, 0x7FF
        ctx->r14 = ADD32(ctx->r8, 0X7FF);
            goto L_80055204;
    }
    // 0x800551F8: addiu       $t6, $t0, 0x7FF
    ctx->r14 = ADD32(ctx->r8, 0X7FF);
    // 0x800551FC: b           L_80055204
    // 0x80055200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80055204;
    // 0x80055200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80055204:
    // 0x80055204: divu        $zero, $t6, $a2
    lo = S32(U32(ctx->r14) / U32(ctx->r6)); hi = S32(U32(ctx->r14) % U32(ctx->r6));
    // 0x80055208: mflo        $t8
    ctx->r24 = lo;
    // 0x8005520C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80055210: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x80055214: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80055218: or          $t9, $t7, $fp
    ctx->r25 = ctx->r15 | ctx->r30;
    // 0x8005521C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80055220: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80055224: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055228: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005522C: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80055230: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80055234: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80055238: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005523C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80055240: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80055244: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055248: bne         $a2, $zero, L_80055254
    if (ctx->r6 != 0) {
        // 0x8005524C: nop
    
            goto L_80055254;
    }
    // 0x8005524C: nop

    // 0x80055250: break       7
    do_break(2147832400);
L_80055254:
    // 0x80055254: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80055258: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005525C: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80055260: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80055264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80055268: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8005526C: srl         $t9, $t6, 3
    ctx->r25 = S32(U32(ctx->r14) >> 3);
    // 0x80055270: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x80055274: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x80055278: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8005527C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80055280: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055284: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80055288: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005528C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80055290: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80055294: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x80055298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005529C: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800552A0: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800552A4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800552A8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800552AC: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800552B0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800552B4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800552B8: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800552BC: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800552C0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800552C4:
    // 0x800552C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800552C8: andi        $t8, $t3, 0xFF
    ctx->r24 = ctx->r11 & 0XFF;
    // 0x800552CC: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800552D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800552D4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800552D8: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800552DC: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800552E0: or          $a1, $t6, $t7
    ctx->r5 = ctx->r14 | ctx->r15;
    // 0x800552E4: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x800552E8: or          $t9, $a1, $t8
    ctx->r25 = ctx->r5 | ctx->r24;
    // 0x800552EC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800552F0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x800552F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800552F8: andi        $t7, $t1, 0xFF
    ctx->r15 = ctx->r9 & 0XFF;
    // 0x800552FC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80055300: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80055304: sltu        $at, $t1, $s6
    ctx->r1 = ctx->r9 < ctx->r22 ? 1 : 0;
    // 0x80055308: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005530C: or          $t8, $a1, $t7
    ctx->r24 = ctx->r5 | ctx->r15;
    // 0x80055310: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x80055314: addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // 0x80055318: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x8005531C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80055320: bne         $at, $zero, L_80055108
    if (ctx->r1 != 0) {
        // 0x80055324: sw          $s4, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r20;
            goto L_80055108;
    }
    // 0x80055324: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
L_80055328:
    // 0x80055328: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005532C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80055330: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80055334: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80055338: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005533C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80055340: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80055344: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80055348: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8005534C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80055350: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80055354: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80055358: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005535C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80055360: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80055364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80055368: jr          $ra
    // 0x8005536C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8005536C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800491B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800491B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800491BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800491C0: lbu         $v1, 0x164($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X164);
    // 0x800491C4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800491C8: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800491CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800491D0: beq         $v1, $at, L_800491FC
    if (ctx->r3 == ctx->r1) {
        // 0x800491D4: lw          $v0, 0x16C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X16C);
            goto L_800491FC;
    }
    // 0x800491D4: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x800491D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800491DC: beql        $v1, $at, L_80049200
    if (ctx->r3 == ctx->r1) {
        // 0x800491E0: swc1        $f12, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
            goto L_80049200;
    }
    goto skip_0;
    // 0x800491E0: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
    skip_0:
    // 0x800491E4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800491E8: addiu       $a0, $a0, 0x870
    ctx->r4 = ADD32(ctx->r4, 0X870);
    // 0x800491EC: jal         0x80071380
    // 0x800491F0: addiu       $a1, $zero, 0xE2E
    ctx->r5 = ADD32(0, 0XE2E);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x800491F0: addiu       $a1, $zero, 0xE2E
    ctx->r5 = ADD32(0, 0XE2E);
    after_0:
    // 0x800491F4: b           L_80049210
    // 0x800491F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80049210;
    // 0x800491F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800491FC:
    // 0x800491FC: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
L_80049200:
    // 0x80049200: swc1        $f14, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f14.u32l;
    // 0x80049204: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x80049208: sw          $a1, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r5;
    // 0x8004920C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049210:
    // 0x80049210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049214: jr          $ra
    // 0x80049218: nop

    return;
    // 0x80049218: nop

;}
RECOMP_FUNC void func_80432E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80432E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432E30: jal         0x80432E08
    // 0x80432E34: nop

    func_80432E08(rdram, ctx);
        goto after_0;
    // 0x80432E34: nop

    after_0:
    // 0x80432E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80432E3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432E40: jr          $ra
    // 0x80432E44: nop

    return;
    // 0x80432E44: nop

;}
RECOMP_FUNC void func_80000EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000EF4: addiu       $t0, $zero, 0x158
    ctx->r8 = ADD32(0, 0X158);
    // 0x80000EF8: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000EFC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80000F00: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80000F04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000F08: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80000F0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000F14: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    // 0x80000F18: mflo        $t6
    ctx->r14 = lo;
    // 0x80000F1C: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80000F20: lb          $a3, 0x1D($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X1D);
    // 0x80000F24: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000F28: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x80000F2C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80000F30: mflo        $t7
    ctx->r15 = lo;
    // 0x80000F34: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80000F38: lbu         $t9, 0x1C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1C);
    // 0x80000F3C: bnel        $t9, $at, L_80000F88
    if (ctx->r25 != ctx->r1) {
        // 0x80000F40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80000F88;
    }
    goto skip_0;
    // 0x80000F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80000F44: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80000F48: jal         0x80000A20
    // 0x80000F4C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80000A20(rdram, ctx);
        goto after_0;
    // 0x80000F4C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80000F50: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80000F54: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80000F58: lui         $at, 0xC34
    ctx->r1 = S32(0XC34 << 16);
    // 0x80000F5C: lhu         $t2, 0x20($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X20);
    // 0x80000F60: lui         $t4, 0xC80
    ctx->r12 = S32(0XC80 << 16);
    // 0x80000F64: ori         $t4, $t4, 0x3E0
    ctx->r12 = ctx->r12 | 0X3E0;
    // 0x80000F68: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80000F6C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80000F70: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80000F74: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x80000F78: jal         0x80000AF0
    // 0x80000F7C: lb          $a1, 0x1D($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X1D);
    func_80000AF0(rdram, ctx);
        goto after_1;
    // 0x80000F7C: lb          $a1, 0x1D($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X1D);
    after_1:
    // 0x80000F80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80000F88:
    // 0x80000F88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80000F8C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80000F90: jr          $ra
    // 0x80000F94: nop

    return;
    // 0x80000F94: nop

    // 0x80000F98: jr          $ra
    // 0x80000F9C: nop

    return;
    // 0x80000F9C: nop

;}
RECOMP_FUNC void func_80789580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789580: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80789584: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(787, 0X2544) << 16);
    // 0x80789588: addiu       $t6, $t6, -0x707C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(787, 0X2544));
    // 0x8078958C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80789590: jr          $ra
    // 0x80789594: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80789594: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8078B840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B840: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8078B844: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8078B848: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078B84C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078B850: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8078B854: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078B858: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8078B85C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8078B860: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(796, 0X1B14) << 16);
    // 0x8078B864: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8078B868: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078B86C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078B870: lw          $t1, -0x335C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(796, 0X1B14));
    // 0x8078B874: jr          $ra
    // 0x8078B878: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8078B878: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80475300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475300: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475304: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475308: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047530C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475310: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475314: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475318: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047531C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475320: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475324: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475328: jr          $ra
    // 0x8047532C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047532C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807A9E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9E00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807A9E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A9E08: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807A9E0C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A9E10: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x807A9E14: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    // 0x807A9E18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807A9E1C: jal         0x80065728
    // 0x807A9E20: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x807A9E20: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A9E24: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807A9E28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807A9E2C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x807A9E30: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x807A9E34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807A9E38: swc1        $f0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->f0.u32l;
    // 0x807A9E3C: swc1        $f0, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->f0.u32l;
    // 0x807A9E40: jal         0x807A9D84
    // 0x807A9E44: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    func_807A9D84(rdram, ctx);
        goto after_1;
    // 0x807A9E44: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x807A9E48: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x807A9E4C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807A9E50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807A9E54: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x807A9E58: lwc1        $f8, 0x40($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X40);
    // 0x807A9E5C: swc1        $f6, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f6.u32l;
    // 0x807A9E60: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x807A9E64: swc1        $f8, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f8.u32l;
    // 0x807A9E68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807A9E6C: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x807A9E70: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807A9E74: swc1        $f18, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f18.u32l;
    // 0x807A9E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A9E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807A9E80: jr          $ra
    // 0x807A9E84: nop

    return;
    // 0x807A9E84: nop

;}
RECOMP_FUNC void func_80042558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042558: lw          $v0, 0x1400($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1400);
    // 0x8004255C: beq         $v0, $zero, L_8004256C
    if (ctx->r2 == 0) {
        // 0x80042560: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8004256C;
    }
    // 0x80042560: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80042564: jr          $ra
    // 0x80042568: sw          $t6, 0x1400($a0)
    MEM_W(0X1400, ctx->r4) = ctx->r14;
    return;
    // 0x80042568: sw          $t6, 0x1400($a0)
    MEM_W(0X1400, ctx->r4) = ctx->r14;
L_8004256C:
    // 0x8004256C: sw          $zero, 0x178($a0)
    MEM_W(0X178, ctx->r4) = 0;
    // 0x80042570: jr          $ra
    // 0x80042574: nop

    return;
    // 0x80042574: nop

;}
RECOMP_FUNC void func_8066A614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A61C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8066A620: jal         0x80045A34
    // 0x8066A624: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8066A624: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8066A628: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A62C: bne         $v0, $zero, L_8066A63C
    if (ctx->r2 != 0) {
        // 0x8066A630: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8066A63C;
    }
    // 0x8066A630: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8066A634: b           L_8066A648
    // 0x8066A638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8066A648;
    // 0x8066A638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8066A63C:
    // 0x8066A63C: jal         0x8066A5F4
    // 0x8066A640: nop

    func_8066A5F4(rdram, ctx);
        goto after_1;
    // 0x8066A640: nop

    after_1:
    // 0x8066A644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8066A648:
    // 0x8066A648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066A64C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A650: jr          $ra
    // 0x8066A654: nop

    return;
    // 0x8066A654: nop

;}
RECOMP_FUNC void func_80716ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80716EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80716EE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80716EE4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80716EE8: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80716EEC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80716EF0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80716EF4: lw          $v1, 0x6E38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E38);
    // 0x80716EF8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80716EFC: beql        $v1, $zero, L_80716F18
    if (ctx->r3 == 0) {
        // 0x80716F00: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80716F18;
    }
    goto skip_0;
    // 0x80716F00: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80716F04: jal         0x80716A58
    // 0x80716F08: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    func_80716A58(rdram, ctx);
        goto after_0;
    // 0x80716F08: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x80716F0C: b           L_80716F3C
    // 0x80716F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80716F3C;
    // 0x80716F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80716F14: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80716F18:
    // 0x80716F18: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80716F1C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80716F20: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80716F24: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80716F28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80716F2C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80716F30: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80716F34: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80716F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80716F3C:
    // 0x80716F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80716F40: jr          $ra
    // 0x80716F44: nop

    return;
    // 0x80716F44: nop

;}
RECOMP_FUNC void func_80665288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066528C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80665290: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x80665294: bnel        $t6, $zero, L_806652DC
    if (ctx->r14 != 0) {
        // 0x80665298: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806652DC;
    }
    goto skip_0;
    // 0x80665298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066529C: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x806652A0: lui         $t0, 0x8066
    ctx->r8 = S32(RELOC_HI16(504, 0X2B10) << 16);
    // 0x806652A4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x806652A8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x806652AC: slti        $at, $t8, 0xD
    ctx->r1 = SIGNED(ctx->r24) < 0XD ? 1 : 0;
    // 0x806652B0: beq         $at, $zero, L_806652D0
    if (ctx->r1 == 0) {
        // 0x806652B4: sw          $t8, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->r24;
            goto L_806652D0;
    }
    // 0x806652B4: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x806652B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806652BC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806652C0: lw          $t0, 0x77E0($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(504, 0X2B10));
    // 0x806652C4: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x806652C8: b           L_806652D8
    // 0x806652CC: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
        goto L_806652D8;
    // 0x806652CC: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
L_806652D0:
    // 0x806652D0: jal         0x806652E8
    // 0x806652D4: nop

    func_806652E8(rdram, ctx);
        goto after_0;
    // 0x806652D4: nop

    after_0:
L_806652D8:
    // 0x806652D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806652DC:
    // 0x806652DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806652E0: jr          $ra
    // 0x806652E4: nop

    return;
    // 0x806652E4: nop

;}
RECOMP_FUNC void func_8057DC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DC00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057DC04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057DC08: jal         0x8057DBC0
    // 0x8057DC0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057DBC0(rdram, ctx);
        goto after_0;
    // 0x8057DC0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057DC10: jal         0x80045BD8
    // 0x8057DC14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8057DC14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8057DC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057DC1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057DC20: jr          $ra
    // 0x8057DC24: nop

    return;
    // 0x8057DC24: nop

;}
RECOMP_FUNC void func_804A4E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4E94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4E98: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4E9C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4EA0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4EA4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4EA8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4EAC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4EB0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4EB4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4EB8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4EBC: jr          $ra
    // 0x804A4EC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4EC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805D7F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7F48: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805D7F4C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805D7F50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805D7F54: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805D7F58: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805D7F5C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805D7F60: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805D7F64: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805D7F68: lui         $t1, 0x805E
    ctx->r9 = S32(RELOC_HI16(474, 0X252C) << 16);
    // 0x805D7F6C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805D7F70: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D7F74: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D7F78: lw          $t1, -0x61D4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(474, 0X252C));
    // 0x805D7F7C: jr          $ra
    // 0x805D7F80: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805D7F80: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80030D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030D80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030D84: lwc1        $f12, -0x8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X8);
    // 0x80030D88: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80030D8C: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80030D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030D94: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80030D98: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80030D9C: nop

    // 0x80030DA0: bc1t        L_80030DCC
    if (c1cs) {
        // 0x80030DA4: nop
    
            goto L_80030DCC;
    }
    // 0x80030DA4: nop

    // 0x80030DA8: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80030DAC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80030DB0: nop

    // 0x80030DB4: bc1t        L_80030DCC
    if (c1cs) {
        // 0x80030DB8: nop
    
            goto L_80030DCC;
    }
    // 0x80030DB8: nop

    // 0x80030DBC: jal         0x8002CE9C
    // 0x80030DC0: nop

    func_8002CE9C(rdram, ctx);
        goto after_0;
    // 0x80030DC0: nop

    after_0:
    // 0x80030DC4: b           L_80030DCC
    // 0x80030DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030DCC;
    // 0x80030DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80030DCC:
    // 0x80030DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030DD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030DD4: jr          $ra
    // 0x80030DD8: nop

    return;
    // 0x80030DD8: nop

;}
RECOMP_FUNC void func_80023D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023D3C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80023D40: lh          $v0, -0x7680($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7680);
    // 0x80023D44: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80023D48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023D4C: blez        $v0, L_80023D9C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80023D50: nop
    
            goto L_80023D9C;
    }
    // 0x80023D50: nop

    // 0x80023D54: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80023D58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023D5C: lwc1        $f12, -0x2A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2A8);
    // 0x80023D60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80023D64: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80023D68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023D6C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80023D70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80023D74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023D78: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80023D7C: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023D80: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80023D84: nop

    // 0x80023D88: bc1f        L_80023D94
    if (!c1cs) {
        // 0x80023D8C: nop
    
            goto L_80023D94;
    }
    // 0x80023D8C: nop

    // 0x80023D90: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80023D94:
    // 0x80023D94: b           L_80023DA8
    // 0x80023D98: lwc1        $f2, -0x2A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A4);
        goto L_80023DA8;
    // 0x80023D98: lwc1        $f2, -0x2A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A4);
L_80023D9C:
    // 0x80023D9C: lwc1        $f0, -0x2A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A0);
    // 0x80023DA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023DA4: lwc1        $f2, -0x29C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X29C);
L_80023DA8:
    // 0x80023DA8: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80023DAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023DB0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80023DB4: nop

    // 0x80023DB8: bc1fl       L_80023DC8
    if (!c1cs) {
        // 0x80023DBC: swc1        $f0, 0xE0($a0)
        MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
            goto L_80023DC8;
    }
    goto skip_0;
    // 0x80023DBC: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x80023DC0: lwc1        $f2, -0x298($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X298);
    // 0x80023DC4: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
L_80023DC8:
    // 0x80023DC8: jr          $ra
    // 0x80023DCC: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x80023DCC: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_804727AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804727AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804727B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804727B4: jal         0x8004700C
    // 0x804727B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804727B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804727BC: beq         $v0, $zero, L_8047280C
    if (ctx->r2 == 0) {
        // 0x804727C0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8047280C;
    }
    // 0x804727C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x804727C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804727C8: lw          $t8, 0x180($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X180);
    // 0x804727CC: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x804727D0: bnel        $t7, $t8, L_80472810
    if (ctx->r15 != ctx->r24) {
        // 0x804727D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80472810;
    }
    goto skip_0;
    // 0x804727D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x804727D8: lw          $t9, 0x138($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X138);
    // 0x804727DC: beql        $t9, $zero, L_804727FC
    if (ctx->r25 == 0) {
        // 0x804727E0: lw          $t1, 0x174($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X174);
            goto L_804727FC;
    }
    goto skip_1;
    // 0x804727E0: lw          $t1, 0x174($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X174);
    skip_1:
    // 0x804727E4: lw          $t0, 0x174($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X174);
    // 0x804727E8: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x804727EC: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x804727F0: b           L_80472810
    // 0x804727F4: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
        goto L_80472810;
    // 0x804727F4: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x804727F8: lw          $t1, 0x174($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X174);
L_804727FC:
    // 0x804727FC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x80472800: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x80472804: b           L_80472810
    // 0x80472808: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
        goto L_80472810;
    // 0x80472808: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
L_8047280C:
    // 0x8047280C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80472810:
    // 0x80472810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80472814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80472818: jr          $ra
    // 0x8047281C: nop

    return;
    // 0x8047281C: nop

;}
RECOMP_FUNC void guS2DInitBg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DAB0: lbu         $t6, 0x16($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X16);
    // 0x8008DAB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008DAB8: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8008DABC: bne         $t6, $at, L_8008DACC
    if (ctx->r14 != ctx->r1) {
        // 0x8008DAC0: addiu       $t8, $zero, 0x6
        ctx->r24 = ADD32(0, 0X6);
            goto L_8008DACC;
    }
    // 0x8008DAC0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8008DAC4: b           L_8008DACC
    // 0x8008DAC8: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
        goto L_8008DACC;
    // 0x8008DAC8: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_8008DACC:
    // 0x8008DACC: lbu         $t7, 0x17($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X17);
    // 0x8008DAD0: lhu         $t0, 0x14($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X14);
    // 0x8008DAD4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8008DAD8: subu        $v1, $t8, $t7
    ctx->r3 = SUB32(ctx->r24, ctx->r15);
    // 0x8008DADC: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x8008DAE0: bne         $t0, $at, L_8008DB98
    if (ctx->r8 != ctx->r1) {
        // 0x8008DAE4: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_8008DB98;
    }
    // 0x8008DAE4: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8008DAE8: lhu         $t1, 0x2($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X2);
    // 0x8008DAEC: srav        $t2, $t1, $v1
    ctx->r10 = S32(SIGNED(ctx->r9) >> (ctx->r3 & 31));
    // 0x8008DAF0: andi        $a2, $t2, 0xFFFF
    ctx->r6 = ctx->r10 & 0XFFFF;
    // 0x8008DAF4: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x8008DAF8: mflo        $t3
    ctx->r11 = lo;
    // 0x8008DAFC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8008DB00: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x8008DB04: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x8008DB08: andi        $t6, $t4, 0xFFFF
    ctx->r14 = ctx->r12 & 0XFFFF;
    // 0x8008DB0C: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DB10: sh          $t2, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r10;
    // 0x8008DB14: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    // 0x8008DB18: bne         $a2, $zero, L_8008DB24
    if (ctx->r6 != 0) {
        // 0x8008DB1C: nop
    
            goto L_8008DB24;
    }
    // 0x8008DB1C: nop

    // 0x8008DB20: break       7
    do_break(2148064032);
L_8008DB24:
    // 0x8008DB24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008DB28: bne         $a2, $at, L_8008DB3C
    if (ctx->r6 != ctx->r1) {
        // 0x8008DB2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008DB3C;
    }
    // 0x8008DB2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DB30: bne         $v0, $at, L_8008DB3C
    if (ctx->r2 != ctx->r1) {
        // 0x8008DB34: nop
    
            goto L_8008DB3C;
    }
    // 0x8008DB34: nop

    // 0x8008DB38: break       6
    do_break(2148064056);
L_8008DB3C:
    // 0x8008DB3C: mflo        $t7
    ctx->r15 = lo;
    // 0x8008DB40: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8008DB44: sh          $t4, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r12;
    // 0x8008DB48: div         $zero, $t2, $a2
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r6)));
    // 0x8008DB4C: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8008DB50: mflo        $t3
    ctx->r11 = lo;
    // 0x8008DB54: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8008DB58: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008DB5C: sh          $t5, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r13;
    // 0x8008DB60: sh          $t7, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r15;
    // 0x8008DB64: sh          $t1, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r9;
    // 0x8008DB68: bne         $a2, $zero, L_8008DB74
    if (ctx->r6 != 0) {
        // 0x8008DB6C: nop
    
            goto L_8008DB74;
    }
    // 0x8008DB6C: nop

    // 0x8008DB70: break       7
    do_break(2148064112);
L_8008DB74:
    // 0x8008DB74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008DB78: bne         $a2, $at, L_8008DB8C
    if (ctx->r6 != ctx->r1) {
        // 0x8008DB7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008DB8C;
    }
    // 0x8008DB7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DB80: bne         $t2, $at, L_8008DB8C
    if (ctx->r10 != ctx->r1) {
        // 0x8008DB84: nop
    
            goto L_8008DB8C;
    }
    // 0x8008DB84: nop

    // 0x8008DB88: break       6
    do_break(2148064136);
L_8008DB8C:
    // 0x8008DB8C: sh          $t4, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r12;
    // 0x8008DB90: jr          $ra
    // 0x8008DB94: nop

    return;
    // 0x8008DB94: nop

L_8008DB98:
    // 0x8008DB98: lhu         $t5, 0x6($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X6);
    // 0x8008DB9C: lhu         $t0, 0x2($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X2);
    // 0x8008DBA0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008DBA4: srav        $t6, $t5, $v1
    ctx->r14 = S32(SIGNED(ctx->r13) >> (ctx->r3 & 31));
    // 0x8008DBA8: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8008DBAC: andi        $a2, $t8, 0xFFFF
    ctx->r6 = ctx->r24 & 0XFFFF;
    // 0x8008DBB0: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x8008DBB4: mflo        $t7
    ctx->r15 = lo;
    // 0x8008DBB8: srav        $t1, $t0, $a1
    ctx->r9 = S32(SIGNED(ctx->r8) >> (ctx->r5 & 31));
    // 0x8008DBBC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8008DBC0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8008DBC4: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8008DBC8: andi        $a3, $t9, 0xFFFF
    ctx->r7 = ctx->r25 & 0XFFFF;
    // 0x8008DBCC: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DBD0: sh          $t8, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r24;
    // 0x8008DBD4: sll         $t5, $a2, 4
    ctx->r13 = S32(ctx->r6 << 4);
    // 0x8008DBD8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8008DBDC: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8008DBE0: bne         $a2, $zero, L_8008DBEC
    if (ctx->r6 != 0) {
        // 0x8008DBE4: nop
    
            goto L_8008DBEC;
    }
    // 0x8008DBE4: nop

    // 0x8008DBE8: break       7
    do_break(2148064232);
L_8008DBEC:
    // 0x8008DBEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008DBF0: bne         $a2, $at, L_8008DC04
    if (ctx->r6 != ctx->r1) {
        // 0x8008DBF4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008DC04;
    }
    // 0x8008DBF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DBF8: bne         $v0, $at, L_8008DC04
    if (ctx->r2 != ctx->r1) {
        // 0x8008DBFC: nop
    
            goto L_8008DC04;
    }
    // 0x8008DBFC: nop

    // 0x8008DC00: break       6
    do_break(2148064256);
L_8008DC04:
    // 0x8008DC04: mflo        $t4
    ctx->r12 = lo;
    // 0x8008DC08: sh          $t9, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r25;
    // 0x8008DC0C: sh          $t2, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r10;
    // 0x8008DC10: sh          $t4, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r12;
    // 0x8008DC14: sh          $t6, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r14;
    // 0x8008DC18: sh          $t8, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r24;
    // 0x8008DC1C: jr          $ra
    // 0x8008DC20: nop

    return;
    // 0x8008DC20: nop

;}
RECOMP_FUNC void func_80448B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448B50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448B54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80448B58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80448B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448B60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80448B64: bne         $a2, $zero, L_80448B94
    if (ctx->r6 != 0) {
        // 0x80448B68: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80448B94;
    }
    // 0x80448B68: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448B6C: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80448B70: lw          $v1, 0x10C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10C);
    // 0x80448B74: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80448B78: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80448B7C: bne         $at, $zero, L_80448BD4
    if (ctx->r1 != 0) {
        // 0x80448B80: sw          $t7, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r15;
            goto L_80448BD4;
    }
    // 0x80448B80: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x80448B84: jal         0x804467BC
    // 0x80448B88: nop

    func_804467BC(rdram, ctx);
        goto after_0;
    // 0x80448B88: nop

    after_0:
    // 0x80448B8C: b           L_80448BD8
    // 0x80448B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448BD8;
    // 0x80448B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448B94:
    // 0x80448B94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448B98: bnel        $a2, $at, L_80448BC4
    if (ctx->r6 != ctx->r1) {
        // 0x80448B9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80448BC4;
    }
    goto skip_0;
    // 0x80448B9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448BA0: jal         0x80446758
    // 0x80448BA4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446758(rdram, ctx);
        goto after_1;
    // 0x80448BA4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448BA8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448BAC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448BB0: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80448BB4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448BB8: b           L_80448BD4
    // 0x80448BBC: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80448BD4;
    // 0x80448BBC: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80448BC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80448BC4:
    // 0x80448BC4: bnel        $a2, $at, L_80448BD8
    if (ctx->r6 != ctx->r1) {
        // 0x80448BC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448BD8;
    }
    goto skip_1;
    // 0x80448BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80448BCC: jal         0x804467BC
    // 0x80448BD0: nop

    func_804467BC(rdram, ctx);
        goto after_2;
    // 0x80448BD0: nop

    after_2:
L_80448BD4:
    // 0x80448BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448BD8:
    // 0x80448BD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80448BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448BE0: jr          $ra
    // 0x80448BE4: nop

    return;
    // 0x80448BE4: nop

;}
RECOMP_FUNC void func_8005BD08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BD08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005BD0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BD10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005BD14: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005BD18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005BD1C: jal         0x8005BA30
    // 0x8005BD20: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BD20: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8005BD24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BD28: beq         $v0, $at, L_8005BD98
    if (ctx->r2 == ctx->r1) {
        // 0x8005BD2C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8005BD98;
    }
    // 0x8005BD2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005BD30: lhu         $a2, 0x2E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2E);
    // 0x8005BD34: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x8005BD38: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8005BD3C: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x8005BD40: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8005BD44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8005BD48: jal         0x80064D1C
    // 0x8005BD4C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x8005BD4C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8005BD50: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8005BD54: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BD58: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005BD5C: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8005BD60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005BD64: jal         0x800675D0
    // 0x8005BD68: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8005BD68: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8005BD6C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005BD70: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005BD74: lhu         $t9, 0x2E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2E);
    // 0x8005BD78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005BD7C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005BD80: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005BD84: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005BD88: addiu       $t8, $t8, -0x4BB0
    ctx->r24 = ADD32(ctx->r24, -0X4BB0);
    // 0x8005BD8C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8005BD90: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x8005BD94: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
L_8005BD98:
    // 0x8005BD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BD9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005BDA0: jr          $ra
    // 0x8005BDA4: nop

    return;
    // 0x8005BDA4: nop

;}
RECOMP_FUNC void func_8046BB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BB60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046BB64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046BB68: jal         0x8046B8B4
    // 0x8046BB6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046B8B4(rdram, ctx);
        goto after_0;
    // 0x8046BB6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046BB70: jal         0x8046B40C
    // 0x8046BB74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8046B40C(rdram, ctx);
        goto after_1;
    // 0x8046BB74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046BB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046BB7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046BB80: jr          $ra
    // 0x8046BB84: nop

    return;
    // 0x8046BB84: nop

;}
RECOMP_FUNC void func_805D37FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D37FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D3800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D3804: jal         0x805D3358
    // 0x805D3808: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D3358(rdram, ctx);
        goto after_0;
    // 0x805D3808: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D380C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3810: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D3814: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805D3818: jal         0x805D3B18
    // 0x805D381C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D381C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D3820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D3824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D3828: jr          $ra
    // 0x805D382C: nop

    return;
    // 0x805D382C: nop

;}
RECOMP_FUNC void func_80530920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530920: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80530924: addiu       $at, $zero, 0x41E2
    ctx->r1 = ADD32(0, 0X41E2);
    // 0x80530928: beq         $v0, $at, L_80530948
    if (ctx->r2 == ctx->r1) {
        // 0x8053092C: addiu       $at, $zero, 0x41E3
        ctx->r1 = ADD32(0, 0X41E3);
            goto L_80530948;
    }
    // 0x8053092C: addiu       $at, $zero, 0x41E3
    ctx->r1 = ADD32(0, 0X41E3);
    // 0x80530930: beq         $v0, $at, L_80530954
    if (ctx->r2 == ctx->r1) {
        // 0x80530934: addiu       $at, $zero, 0x41E4
        ctx->r1 = ADD32(0, 0X41E4);
            goto L_80530954;
    }
    // 0x80530934: addiu       $at, $zero, 0x41E4
    ctx->r1 = ADD32(0, 0X41E4);
    // 0x80530938: beq         $v0, $at, L_80530954
    if (ctx->r2 == ctx->r1) {
        // 0x8053093C: nop
    
            goto L_80530954;
    }
    // 0x8053093C: nop

    // 0x80530940: b           L_80530960
    // 0x80530944: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(339, 0X1DC) << 16);
        goto L_80530960;
    // 0x80530944: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(339, 0X1DC) << 16);
L_80530948:
    // 0x80530948: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(339, 0X2B4) << 16);
    // 0x8053094C: jr          $ra
    // 0x80530950: addiu       $v0, $v0, 0xBD4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(339, 0X2B4));
    return;
    // 0x80530950: addiu       $v0, $v0, 0xBD4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(339, 0X2B4));
L_80530954:
    // 0x80530954: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(339, 0X1DC) << 16);
    // 0x80530958: jr          $ra
    // 0x8053095C: addiu       $v0, $v0, 0xAFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(339, 0X1DC));
    return;
    // 0x8053095C: addiu       $v0, $v0, 0xAFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(339, 0X1DC));
L_80530960:
    // 0x80530960: addiu       $v0, $v0, 0xAFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(339, 0X1DC));
    // 0x80530964: jr          $ra
    // 0x80530968: nop

    return;
    // 0x80530968: nop

;}
RECOMP_FUNC void func_800653D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653D8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800653DC: addiu       $v1, $v1, 0x65C8
    ctx->r3 = ADD32(ctx->r3, 0X65C8);
    // 0x800653E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800653E4: lui         $at, 0x41C6
    ctx->r1 = S32(0X41C6 << 16);
    // 0x800653E8: ori         $at, $at, 0x4E6D
    ctx->r1 = ctx->r1 | 0X4E6D;
    // 0x800653EC: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800653F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800653F4: addiu       $t8, $t7, 0x3039
    ctx->r24 = ADD32(ctx->r15, 0X3039);
    // 0x800653F8: srl         $v0, $t8, 16
    ctx->r2 = S32(U32(ctx->r24) >> 16);
    // 0x800653FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80065400: jr          $ra
    // 0x80065404: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    return;
    // 0x80065404: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
;}
RECOMP_FUNC void func_8002C0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C0EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C0F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002C0F4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C0F8: addiu       $a1, $a1, -0x2B14
    ctx->r5 = ADD32(ctx->r5, -0X2B14);
    // 0x8002C0FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C104: jal         0x80028118
    // 0x8002C108: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C108: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C10C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002C110: jal         0x8002C064
    // 0x8002C114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002C064(rdram, ctx);
        goto after_1;
    // 0x8002C114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002C118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C11C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C120: jr          $ra
    // 0x8002C124: nop

    return;
    // 0x8002C124: nop

;}
RECOMP_FUNC void func_805747B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805747B8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805747BC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x805747C0: lw          $t6, 0xC2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC2C);
    // 0x805747C4: lw          $t7, 0xC30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC30);
    // 0x805747C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805747CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805747D0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x805747D4: bnel        $at, $zero, L_805747E8
    if (ctx->r1 != 0) {
        // 0x805747D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805747E8;
    }
    goto skip_0;
    // 0x805747D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805747DC: jal         0x805746D0
    // 0x805747E0: nop

    func_805746D0(rdram, ctx);
        goto after_0;
    // 0x805747E0: nop

    after_0:
    // 0x805747E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805747E8:
    // 0x805747E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805747EC: jr          $ra
    // 0x805747F0: nop

    return;
    // 0x805747F0: nop

;}
RECOMP_FUNC void func_8003DF38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DF38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003DF3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003DF40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003DF44: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003DF48: jal         0x8004700C
    // 0x8003DF4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003DF4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DF50: beql        $v0, $zero, L_8003E060
    if (ctx->r2 == 0) {
        // 0x8003DF54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003E060;
    }
    goto skip_0;
    // 0x8003DF54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003DF58: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003DF5C: lw          $t6, 0x164($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X164);
    // 0x8003DF60: bnel        $t6, $zero, L_8003E060
    if (ctx->r14 != 0) {
        // 0x8003DF64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003E060;
    }
    goto skip_1;
    // 0x8003DF64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8003DF68: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x8003DF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003DF70: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003DF74: lbu         $t9, 0x75($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X75);
    // 0x8003DF78: beql        $t9, $zero, L_8003DF90
    if (ctx->r25 == 0) {
        // 0x8003DF7C: sw          $s0, 0x164($v1)
        MEM_W(0X164, ctx->r3) = ctx->r16;
            goto L_8003DF90;
    }
    goto skip_2;
    // 0x8003DF7C: sw          $s0, 0x164($v1)
    MEM_W(0X164, ctx->r3) = ctx->r16;
    skip_2:
    // 0x8003DF80: jal         0x80060FE0
    // 0x8003DF84: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80060FE0(rdram, ctx);
        goto after_1;
    // 0x8003DF84: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x8003DF88: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8003DF8C: sw          $s0, 0x164($v1)
    MEM_W(0X164, ctx->r3) = ctx->r16;
L_8003DF90:
    // 0x8003DF90: lw          $t0, 0x180($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X180);
    // 0x8003DF94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003DF98: bnel        $t0, $zero, L_8003DFB4
    if (ctx->r8 != 0) {
        // 0x8003DF9C: lw          $v0, 0x174($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X174);
            goto L_8003DFB4;
    }
    goto skip_3;
    // 0x8003DF9C: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
    skip_3:
    // 0x8003DFA0: jal         0x80048114
    // 0x8003DFA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80048114(rdram, ctx);
        goto after_2;
    // 0x8003DFA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8003DFA8: b           L_8003DFDC
    // 0x8003DFAC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
        goto L_8003DFDC;
    // 0x8003DFAC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8003DFB0: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
L_8003DFB4:
    // 0x8003DFB4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8003DFB8: beq         $t1, $zero, L_8003DFC4
    if (ctx->r9 == 0) {
        // 0x8003DFBC: nop
    
            goto L_8003DFC4;
    }
    // 0x8003DFBC: nop

    // 0x8003DFC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_8003DFC4:
    // 0x8003DFC4: jal         0x80048060
    // 0x8003DFC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_3;
    // 0x8003DFC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003DFCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003DFD0: jal         0x80047F9C
    // 0x8003DFD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x8003DFD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8003DFD8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_8003DFDC:
    // 0x8003DFDC: sb          $t2, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r10;
    // 0x8003DFE0: jal         0x8005FE48
    // 0x8003DFE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_5;
    // 0x8003DFE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8003DFE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003DFEC: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8003DFF0: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8003DFF4: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8003DFF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003DFFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003E000: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8003E004: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8003E008: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8003E00C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003E010: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8003E014: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8003E018: lwc1        $f10, 0x230($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X230);
    // 0x8003E01C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003E020: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003E024: jal         0x8005FE48
    // 0x8003E028: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    func_8005FE48(rdram, ctx);
        goto after_6;
    // 0x8003E028: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    after_6:
    // 0x8003E02C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8003E030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E034: beq         $v0, $zero, L_8003E044
    if (ctx->r2 == 0) {
        // 0x8003E038: nop
    
            goto L_8003E044;
    }
    // 0x8003E038: nop

    // 0x8003E03C: jalr        $v0
    // 0x8003E040: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_7;
    // 0x8003E040: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_7:
L_8003E044:
    // 0x8003E044: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8003E048: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8003E04C: addiu       $t4, $t4, -0x20E8
    ctx->r12 = ADD32(ctx->r12, -0X20E8);
    // 0x8003E050: sb          $t3, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r11;
    // 0x8003E054: sw          $t4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r12;
    // 0x8003E058: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8003E05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003E060:
    // 0x8003E060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003E064: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003E068: jr          $ra
    // 0x8003E06C: nop

    return;
    // 0x8003E06C: nop

;}
RECOMP_FUNC void func_80068418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068418: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006841C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80068420: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80068424: addiu       $v0, $v0, 0x6EB0
    ctx->r2 = ADD32(ctx->r2, 0X6EB0);
    // 0x80068428: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8006842C: sw          $zero, 0x158($v1)
    MEM_W(0X158, ctx->r3) = 0;
    // 0x80068430: jr          $ra
    // 0x80068434: sw          $zero, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = 0;
    return;
    // 0x80068434: sw          $zero, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = 0;
;}
RECOMP_FUNC void func_80034B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80034B80: jal         0x80065954
    // 0x80034B84: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80034B84: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x80034B88: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80034B8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80034B94: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80034B98: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80034B9C: jal         0x80041214
    // 0x80034BA0: nop

    func_80041214(rdram, ctx);
        goto after_1;
    // 0x80034BA0: nop

    after_1:
    // 0x80034BA4: jal         0x80034AA0
    // 0x80034BA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80034AA0(rdram, ctx);
        goto after_2;
    // 0x80034BA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80034BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034BB4: jr          $ra
    // 0x80034BB8: nop

    return;
    // 0x80034BB8: nop

;}
RECOMP_FUNC void func_8044610C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044610C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80446110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446114: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446118: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x8044611C: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80446120: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446124: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80446128: sw          $a1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r5;
    // 0x8044612C: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x80446130: sw          $t6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r14;
    // 0x80446134: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446138: sw          $t7, 0x6CA4($at)
    MEM_W(0X6CA4, ctx->r1) = ctx->r15;
    // 0x8044613C: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131DC) << 16);
    // 0x80446140: lw          $v1, 0x75BC($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131DC));
    // 0x80446144: beql        $v1, $zero, L_80446158
    if (ctx->r3 == 0) {
        // 0x80446148: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80446158;
    }
    goto skip_0;
    // 0x80446148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044614C: jalr        $v1
    // 0x80446150: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80446150: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80446154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80446158:
    // 0x80446158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044615C: jr          $ra
    // 0x80446160: nop

    return;
    // 0x80446160: nop

;}
RECOMP_FUNC void func_8006D59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D59C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D5A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006D5A4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8006D5A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D5AC: bne         $a0, $at, L_8006D5CC
    if (ctx->r4 != ctx->r1) {
        // 0x8006D5B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006D5CC;
    }
    // 0x8006D5B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D5B4: jal         0x8006D554
    // 0x8006D5B8: nop

    func_8006D554(rdram, ctx);
        goto after_0;
    // 0x8006D5B8: nop

    after_0:
    // 0x8006D5BC: beq         $v0, $zero, L_8006D5CC
    if (ctx->r2 == 0) {
        // 0x8006D5C0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8006D5CC;
    }
    // 0x8006D5C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D5C4: b           L_8006D5E0
    // 0x8006D5C8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
        goto L_8006D5E0;
    // 0x8006D5C8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_8006D5CC:
    // 0x8006D5CC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006D5D0: jal         0x8006D508
    // 0x8006D5D4: addiu       $a0, $a0, 0x6F0
    ctx->r4 = ADD32(ctx->r4, 0X6F0);
    func_8006D508(rdram, ctx);
        goto after_1;
    // 0x8006D5D4: addiu       $a0, $a0, 0x6F0
    ctx->r4 = ADD32(ctx->r4, 0X6F0);
    after_1:
    // 0x8006D5D8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006D5DC: addiu       $v0, $v0, 0x6F0
    ctx->r2 = ADD32(ctx->r2, 0X6F0);
L_8006D5E0:
    // 0x8006D5E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D5E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D5E8: jr          $ra
    // 0x8006D5EC: nop

    return;
    // 0x8006D5EC: nop

;}
RECOMP_FUNC void func_8002F86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F86C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F874: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002F878: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F87C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002F880: jal         0x8002F678
    // 0x8002F884: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002F884: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F888: beq         $v0, $zero, L_8002F89C
    if (ctx->r2 == 0) {
        // 0x8002F88C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002F89C;
    }
    // 0x8002F88C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F890: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002F894: addiu       $t6, $t6, -0x34E4
    ctx->r14 = ADD32(ctx->r14, -0X34E4);
    // 0x8002F898: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002F89C:
    // 0x8002F89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F8A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F8A4: jr          $ra
    // 0x8002F8A8: nop

    return;
    // 0x8002F8A8: nop

;}
RECOMP_FUNC void func_805E4D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4D7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805E4D80: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805E4D84: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805E4D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4D8C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805E4D90: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x805E4D94: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805E4D98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805E4D9C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x805E4DA0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805E4DA4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805E4DA8: lui         $t2, 0x805E
    ctx->r10 = S32(RELOC_HI16(486, 0XFB0) << 16);
    // 0x805E4DAC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805E4DB0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805E4DB4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805E4DB8: lw          $t2, 0x50F0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(486, 0XFB0));
    // 0x805E4DBC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805E4DC0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x805E4DC4: jal         0x805E432C
    // 0x805E4DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805E432C(rdram, ctx);
        goto after_0;
    // 0x805E4DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4DCC: jal         0x805E43E8
    // 0x805E4DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805E43E8(rdram, ctx);
        goto after_1;
    // 0x805E4DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805E4DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4DD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4DDC: jr          $ra
    // 0x805E4DE0: nop

    return;
    // 0x805E4DE0: nop

    // 0x805E4DE4: nop

    // 0x805E4DE8: nop

    // 0x805E4DEC: nop

;}
RECOMP_FUNC void func_806F38EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F38EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F38F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F38F4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F38F8: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x806F38FC: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(682, 0X934) << 16);
    // 0x806F3900: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806F3904: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F3908: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806F390C: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x806F3910: lbu         $t7, 0x3D84($t7)
    ctx->r15 = MEM_BU(ctx->r15, (int16_t)RELOC_LO16(682, 0X934));
    // 0x806F3914: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(682, 0X938) << 16);
    // 0x806F3918: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x806F391C: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x806F3920: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x806F3924: lw          $t8, 0x3D88($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(682, 0X938));
    // 0x806F3928: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(682, 0X940) << 16);
    // 0x806F392C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x806F3930: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x806F3934: lw          $t9, 0x3D90($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(682, 0X940));
    // 0x806F3938: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(682, 0X948) << 16);
    // 0x806F393C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806F3940: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
    // 0x806F3944: lw          $t1, 0x3D98($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(682, 0X948));
    // 0x806F3948: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X9B0) << 16);
    // 0x806F394C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F3950: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
    // 0x806F3954: lwc1        $f4, 0x3E00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X9B0));
    // 0x806F3958: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x806F395C: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x806F3960: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806F3964: sw          $t2, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r10;
    // 0x806F3968: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x806F396C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x806F3970: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x806F3974: lw          $a0, 0x174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X174);
    // 0x806F3978: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x806F397C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x806F3980: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x806F3984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F3988: jal         0x800657CC
    // 0x806F398C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800657CC(rdram, ctx);
        goto after_0;
    // 0x806F398C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x806F3990: jal         0x806F38D4
    // 0x806F3994: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_806F38D4(rdram, ctx);
        goto after_1;
    // 0x806F3994: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x806F3998: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x806F399C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x806F39A0: lw          $t3, -0x7BC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7BC4);
    // 0x806F39A4: lui         $t4, 0x806F
    ctx->r12 = S32(RELOC_HI16(682, 0X968) << 16);
    // 0x806F39A8: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x806F39AC: lw          $v1, 0x10C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X10C);
    // 0x806F39B0: lw          $t4, 0x3DB8($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(682, 0X968));
    // 0x806F39B4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x806F39B8: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x806F39BC: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x806F39C0: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x806F39C4: lw          $v0, 0x16C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X16C);
    // 0x806F39C8: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(682, 0X970) << 16);
    // 0x806F39CC: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x806F39D0: sb          $t6, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r14;
    // 0x806F39D4: lw          $t7, 0x3DC0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(682, 0X970));
    // 0x806F39D8: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(682, 0X978) << 16);
    // 0x806F39DC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806F39E0: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x806F39E4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x806F39E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806F39EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F39F0: sb          $t9, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r25;
    // 0x806F39F4: lw          $t1, 0x3DC8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(682, 0X978));
    // 0x806F39F8: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x806F39FC: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x806F3A00: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x806F3A04: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    // 0x806F3A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F3A0C: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    // 0x806F3A10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806F3A14: jr          $ra
    // 0x806F3A18: nop

    return;
    // 0x806F3A18: nop

;}
RECOMP_FUNC void func_806F3498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F3498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F349C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F34A0: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x806F34A4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806F34A8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806F34AC: beql        $t6, $at, L_806F34E0
    if (ctx->r14 == ctx->r1) {
        // 0x806F34B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F34E0;
    }
    goto skip_0;
    // 0x806F34B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F34B4: lw          $v0, 0x174($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X174);
    // 0x806F34B8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x806F34BC: lhu         $v1, 0x16($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X16);
    // 0x806F34C0: andi        $t8, $v1, 0xC000
    ctx->r24 = ctx->r3 & 0XC000;
    // 0x806F34C4: beq         $t8, $zero, L_806F34DC
    if (ctx->r24 == 0) {
        // 0x806F34C8: andi        $t9, $v1, 0x4000
        ctx->r25 = ctx->r3 & 0X4000;
            goto L_806F34DC;
    }
    // 0x806F34C8: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x806F34CC: beq         $t9, $zero, L_806F34DC
    if (ctx->r25 == 0) {
        // 0x806F34D0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_806F34DC;
    }
    // 0x806F34D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806F34D4: jal         0x8003DBB4
    // 0x806F34D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8003DBB4(rdram, ctx);
        goto after_0;
    // 0x806F34D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
L_806F34DC:
    // 0x806F34DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F34E0:
    // 0x806F34E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F34E4: jr          $ra
    // 0x806F34E8: nop

    return;
    // 0x806F34E8: nop

;}
RECOMP_FUNC void func_806A2C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A2C64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806A2C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A2C6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806A2C70: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A2C74: jal         0x800653D8
    // 0x806A2C78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x806A2C78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x806A2C7C: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x806A2C80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806A2C84: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(583, 0X568) << 16);
    // 0x806A2C88: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x806A2C8C: lwc1        $f4, 0x2DC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(583, 0X568));
    // 0x806A2C90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806A2C94: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x806A2C98: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806A2C9C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x806A2CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A2CA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806A2CA8: jr          $ra
    // 0x806A2CAC: nop

    return;
    // 0x806A2CAC: nop

;}
RECOMP_FUNC void func_80699248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699248: jr          $ra
    // 0x8069924C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8069924C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800401D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800401D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800401DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800401E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800401E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800401E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800401EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800401F0: jal         0x8003B764
    // 0x800401F4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_8003B764(rdram, ctx);
        goto after_0;
    // 0x800401F4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x800401F8: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800401FC: bne         $at, $zero, L_8004020C
    if (ctx->r1 != 0) {
        // 0x80040200: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_8004020C;
    }
    // 0x80040200: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80040204: b           L_80040288
    // 0x80040208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040288;
    // 0x80040208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004020C:
    // 0x8004020C: jal         0x8003BB58
    // 0x80040210: lw          $a0, 0x1EC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X1EC);
    func_8003BB58(rdram, ctx);
        goto after_1;
    // 0x80040210: lw          $a0, 0x1EC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X1EC);
    after_1:
    // 0x80040214: bne         $v0, $zero, L_80040224
    if (ctx->r2 != 0) {
        // 0x80040218: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80040224;
    }
    // 0x80040218: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004021C: b           L_80040288
    // 0x80040220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80040288;
    // 0x80040220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040224:
    // 0x80040224: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80040228: jal         0x80047F9C
    // 0x8004022C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8004022C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80040230: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80040234: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x80040238: addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
    // 0x8004023C: jal         0x80065490
    // 0x80040240: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x80040240: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x80040244: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80040248: jal         0x80065490
    // 0x8004024C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x8004024C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    after_4:
    // 0x80040250: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80040254: addiu       $t7, $t7, -0x4D04
    ctx->r15 = ADD32(ctx->r15, -0X4D04);
    // 0x80040258: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8004025C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80040260: jal         0x800401B4
    // 0x80040264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800401B4(rdram, ctx);
        goto after_5;
    // 0x80040264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80040268: jal         0x800447C8
    // 0x8004026C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x8004026C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80040270: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80040274: jal         0x8003E7E0
    // 0x80040278: lhu         $a1, 0x36($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X36);
    func_8003E7E0(rdram, ctx);
        goto after_7;
    // 0x80040278: lhu         $a1, 0x36($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X36);
    after_7:
    // 0x8004027C: jal         0x80038E18
    // 0x80040280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80038E18(rdram, ctx);
        goto after_8;
    // 0x80040280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80040284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80040288:
    // 0x80040288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004028C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80040290: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80040294: jr          $ra
    // 0x80040298: nop

    return;
    // 0x80040298: nop

;}
RECOMP_FUNC void func_80010230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80010234: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80010238: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001023C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80010240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80010244: jal         0x8000DAE8
    // 0x80010248: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8000DAE8(rdram, ctx);
        goto after_0;
    // 0x80010248: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001024C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80010250: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010254: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80010258: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001025C: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80010260: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80010264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80010268: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001026C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80010270: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80010274: addiu       $t9, $zero, 0x1680
    ctx->r25 = ADD32(0, 0X1680);
    // 0x80010278: addiu       $t0, $t0, 0x6BD4
    ctx->r8 = ADD32(ctx->r8, 0X6BD4);
    // 0x8001027C: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80010280: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x80010284: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80010288: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
    // 0x8001028C: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x80010290: sh          $zero, 0x10($s1)
    MEM_H(0X10, ctx->r17) = 0;
    // 0x80010294: sb          $t8, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r24;
    // 0x80010298: sh          $zero, 0x12($s1)
    MEM_H(0X12, ctx->r17) = 0;
    // 0x8001029C: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
    // 0x800102A0: sh          $zero, 0xA($s1)
    MEM_H(0XA, ctx->r17) = 0;
    // 0x800102A4: sh          $t9, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r25;
    // 0x800102A8: sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // 0x800102AC: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x800102B0: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
    // 0x800102B4: sw          $t0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r8;
    // 0x800102B8: sw          $t1, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r9;
    // 0x800102BC: sw          $zero, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = 0;
    // 0x800102C0: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800102C4: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x800102C8: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
    // 0x800102CC: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    // 0x800102D0: swc1        $f4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f4.u32l;
L_800102D4:
    // 0x800102D4: jal         0x8000D574
    // 0x800102D8: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_8000D574(rdram, ctx);
        goto after_1;
    // 0x800102D8: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_1:
    // 0x800102DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800102E0: bne         $s0, $s2, L_800102D4
    if (ctx->r16 != ctx->r18) {
        // 0x800102E4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800102D4;
    }
    // 0x800102E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800102E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800102EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800102F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800102F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800102F8: jr          $ra
    // 0x800102FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800102FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80584B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584B7C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584B80: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584B84: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584B88: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584B8C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584B90: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584B94: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584B98: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584B9C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584BA0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584BA4: jr          $ra
    // 0x80584BA8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584BA8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8002F4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F4E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F4F0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F4F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002F4F8: jal         0x8002B00C
    // 0x8002F4FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8002B00C(rdram, ctx);
        goto after_0;
    // 0x8002F4FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002F500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002F504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F508: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x8002F50C: jal         0x8002B9E4
    // 0x8002F510: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_1;
    // 0x8002F510: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002F514: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F518: sw          $zero, 0x60($t6)
    MEM_W(0X60, ctx->r14) = 0;
    // 0x8002F51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F524: jr          $ra
    // 0x8002F528: nop

    return;
    // 0x8002F528: nop

;}
RECOMP_FUNC void func_8007B59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B59C: lui         $t6, 0xF00
    ctx->r14 = S32(0XF00 << 16);
    // 0x8007B5A0: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x8007B5A4: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x8007B5A8: jr          $ra
    // 0x8007B5AC: nop

    return;
    // 0x8007B5AC: nop

;}
RECOMP_FUNC void func_80436D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436D8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80436D90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80436D94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80436D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80436D9C: jal         0x80049D74
    // 0x80436DA0: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x80436DA0: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_0:
    // 0x80436DA4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80436DA8: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80436DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80436DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80436DB4: jal         0x8004D150
    // 0x80436DB8: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x80436DB8: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_1:
    // 0x80436DBC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80436DC0: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x80436DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80436DC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80436DCC: jal         0x8004D150
    // 0x80436DD0: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    func_8004D150(rdram, ctx);
        goto after_2;
    // 0x80436DD0: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    after_2:
    // 0x80436DD4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80436DD8: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x80436DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80436DE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80436DE4: jal         0x8004D150
    // 0x80436DE8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x80436DE8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80436DEC: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80436DF0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x80436DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80436DF8: jal         0x8004D618
    // 0x80436DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x80436DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80436E00: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80436E04: addiu       $a2, $a2, -0x2B40
    ctx->r6 = ADD32(ctx->r6, -0X2B40);
    // 0x80436E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80436E0C: jal         0x8004D618
    // 0x80436E10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004D618(rdram, ctx);
        goto after_5;
    // 0x80436E10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80436E14: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80436E18: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    // 0x80436E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80436E20: jal         0x8004D618
    // 0x80436E24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8004D618(rdram, ctx);
        goto after_6;
    // 0x80436E24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80436E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80436E2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80436E30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80436E34: jr          $ra
    // 0x80436E38: nop

    return;
    // 0x80436E38: nop

;}
RECOMP_FUNC void func_8064A5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A5A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064A5A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064A5A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064A5AC: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064A5B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064A5B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064A5B8: blez        $v0, L_8064A5CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064A5BC: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8064A5CC;
    }
    // 0x8064A5BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064A5C0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064A5C4: b           L_8064A5F8
    // 0x8064A5C8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064A5F8;
    // 0x8064A5C8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064A5CC:
    // 0x8064A5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064A5D0: jal         0x8064A97C
    // 0x8064A5D4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064A97C(rdram, ctx);
        goto after_0;
    // 0x8064A5D4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x8064A5D8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064A5DC: jal         0x80067BBC
    // 0x8064A5E0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8064A5E0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8064A5E4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8064A5E8: jal         0x80067818
    // 0x8064A5EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8064A5EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8064A5F0: jal         0x8064A43C
    // 0x8064A5F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A43C(rdram, ctx);
        goto after_3;
    // 0x8064A5F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8064A5F8:
    // 0x8064A5F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064A5FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064A600: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064A604: jr          $ra
    // 0x8064A608: nop

    return;
    // 0x8064A608: nop

;}
RECOMP_FUNC void func_80452CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452CCC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452CD0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452CD4: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80452CD8: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80452CDC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452CE0: ori         $at, $at, 0x6D8C
    ctx->r1 = ctx->r1 | 0X6D8C;
    // 0x80452CE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80452CE8: jal         0x80452A64
    // 0x80452CEC: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_80452A64(rdram, ctx);
        goto after_0;
    // 0x80452CEC: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_0:
    // 0x80452CF0: bne         $v0, $zero, L_80452D08
    if (ctx->r2 != 0) {
        // 0x80452CF4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80452D08;
    }
    // 0x80452CF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80452CF8: jal         0x80452A14
    // 0x80452CFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80452A14(rdram, ctx);
        goto after_1;
    // 0x80452CFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80452D00: b           L_80452D14
    // 0x80452D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452D14;
    // 0x80452D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452D08:
    // 0x80452D08: jal         0x804526FC
    // 0x80452D0C: nop

    func_804526FC(rdram, ctx);
        goto after_2;
    // 0x80452D0C: nop

    after_2:
    // 0x80452D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452D14:
    // 0x80452D14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452D18: jr          $ra
    // 0x80452D1C: nop

    return;
    // 0x80452D1C: nop

;}
RECOMP_FUNC void func_806E98B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E98B8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806E98BC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806E98C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806E98C4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806E98C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806E98CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E98D0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806E98D4: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(667, 0X16A0) << 16);
    // 0x806E98D8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806E98DC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806E98E0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E98E4: lw          $t1, -0x66B0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(667, 0X16A0));
    // 0x806E98E8: jr          $ra
    // 0x806E98EC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806E98EC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80423A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423A0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80423A10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80423A14: jal         0x804233F4
    // 0x80423A18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_804233F4(rdram, ctx);
        goto after_0;
    // 0x80423A18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80423A1C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80423A20: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(35, 0X2F0C) << 16);
    // 0x80423A24: addiu       $a1, $a1, 0x590C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(35, 0X2F0C));
    // 0x80423A28: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80423A2C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80423A30: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x80423A34: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80423A38: addiu       $t7, $v0, 0x28
    ctx->r15 = ADD32(ctx->r2, 0X28);
    // 0x80423A3C: addiu       $t8, $v0, 0x90
    ctx->r24 = ADD32(ctx->r2, 0X90);
    // 0x80423A40: addiu       $t9, $v0, 0x9C
    ctx->r25 = ADD32(ctx->r2, 0X9C);
    // 0x80423A44: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80423A48: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80423A4C: jal         0x80423630
    // 0x80423A50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80423630(rdram, ctx);
        goto after_1;
    // 0x80423A50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x80423A54: jal         0x804235A8
    // 0x80423A58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_804235A8(rdram, ctx);
        goto after_2;
    // 0x80423A58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80423A5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80423A60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80423A64: jr          $ra
    // 0x80423A68: nop

    return;
    // 0x80423A68: nop

;}
RECOMP_FUNC void func_8053096C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053096C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80530970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80530974: lwc1        $f0, 0x7C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80530978: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8053097C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80530980: jal         0x80062684
    // 0x80530984: nop

    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80530984: nop

    after_0:
    // 0x80530988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8053098C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80530990: jr          $ra
    // 0x80530994: nop

    return;
    // 0x80530994: nop

;}
RECOMP_FUNC void func_80438300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80438304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80438308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043830C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80438310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80438314: jal         0x80048214
    // 0x80438318: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80048214(rdram, ctx);
        goto after_0;
    // 0x80438318: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8043831C: sw          $v0, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->r2;
    // 0x80438320: jal         0x80436D8C
    // 0x80438324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80436D8C(rdram, ctx);
        goto after_1;
    // 0x80438324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80438328: jal         0x80437A1C
    // 0x8043832C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437A1C(rdram, ctx);
        goto after_2;
    // 0x8043832C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80438330: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80438334: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80438338: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8043833C: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x80438340: beq         $t0, $zero, L_80438388
    if (ctx->r8 == 0) {
        // 0x80438344: nop
    
            goto L_80438388;
    }
    // 0x80438344: nop

    // 0x80438348: jal         0x80437B74
    // 0x8043834C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437B74(rdram, ctx);
        goto after_3;
    // 0x8043834C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80438350: jal         0x80437CF0
    // 0x80438354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437CF0(rdram, ctx);
        goto after_4;
    // 0x80438354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80438358: jal         0x80437EA4
    // 0x8043835C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437EA4(rdram, ctx);
        goto after_5;
    // 0x8043835C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80438360: jal         0x804380B8
    // 0x80438364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804380B8(rdram, ctx);
        goto after_6;
    // 0x80438364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80438368: jal         0x80437FF4
    // 0x8043836C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437FF4(rdram, ctx);
        goto after_7;
    // 0x8043836C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80438370: jal         0x80438074
    // 0x80438374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80438074(rdram, ctx);
        goto after_8;
    // 0x80438374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80438378: jal         0x80437C04
    // 0x8043837C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437C04(rdram, ctx);
        goto after_9;
    // 0x8043837C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80438380: b           L_804383A8
    // 0x80438384: nop

        goto L_804383A8;
    // 0x80438384: nop

L_80438388:
    // 0x80438388: jal         0x80437CF0
    // 0x8043838C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437CF0(rdram, ctx);
        goto after_10;
    // 0x8043838C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80438390: jal         0x80437E1C
    // 0x80438394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437E1C(rdram, ctx);
        goto after_11;
    // 0x80438394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80438398: jal         0x80437F8C
    // 0x8043839C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437F8C(rdram, ctx);
        goto after_12;
    // 0x8043839C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x804383A0: jal         0x80437CBC
    // 0x804383A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80437CBC(rdram, ctx);
        goto after_13;
    // 0x804383A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_804383A8:
    // 0x804383A8: jal         0x8043813C
    // 0x804383AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043813C(rdram, ctx);
        goto after_14;
    // 0x804383AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x804383B0: jal         0x80438180
    // 0x804383B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80438180(rdram, ctx);
        goto after_15;
    // 0x804383B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x804383B8: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804383BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804383C0: jal         0x80438234
    // 0x804383C4: sw          $zero, 0x54($t1)
    MEM_W(0X54, ctx->r9) = 0;
    func_80438234(rdram, ctx);
        goto after_16;
    // 0x804383C4: sw          $zero, 0x54($t1)
    MEM_W(0X54, ctx->r9) = 0;
    after_16:
    // 0x804383C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804383CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804383D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804383D4: jr          $ra
    // 0x804383D8: nop

    return;
    // 0x804383D8: nop

;}
RECOMP_FUNC void func_806B261C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B261C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2620: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2624: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2628: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B262C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2630: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2634: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2638: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B263C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2640: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2644: jr          $ra
    // 0x806B2648: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2648: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8004E1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004E1F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004E1F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004E1F8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004E1FC: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004E200: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004E204: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004E208: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004E20C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004E210: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8004E214: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8004E218: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8004E21C: beq         $t2, $zero, L_8004E29C
    if (ctx->r10 == 0) {
        // 0x8004E220: sh          $t2, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r10;
            goto L_8004E29C;
    }
    // 0x8004E220: sh          $t2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r10;
    // 0x8004E224: beq         $t2, $at, L_8004E29C
    if (ctx->r10 == ctx->r1) {
        // 0x8004E228: lbu         $v0, 0x1A($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X1A);
            goto L_8004E29C;
    }
    // 0x8004E228: lbu         $v0, 0x1A($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1A);
    // 0x8004E22C: andi        $v1, $v0, 0xF8
    ctx->r3 = ctx->r2 & 0XF8;
    // 0x8004E230: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004E234: beq         $v1, $at, L_8004E29C
    if (ctx->r3 == ctx->r1) {
        // 0x8004E238: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004E29C;
    }
    // 0x8004E238: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004E23C: beql        $v1, $at, L_8004E2A0
    if (ctx->r3 == ctx->r1) {
        // 0x8004E240: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E2A0;
    }
    goto skip_0;
    // 0x8004E240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004E244: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8004E248: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E24C: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8004E250: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004E254: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8004E258: nop

    // 0x8004E25C: bc1t        L_8004E274
    if (c1cs) {
        // 0x8004E260: nop
    
            goto L_8004E274;
    }
    // 0x8004E260: nop

    // 0x8004E264: bne         $t3, $zero, L_8004E274
    if (ctx->r11 != 0) {
        // 0x8004E268: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_8004E274;
    }
    // 0x8004E268: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x8004E26C: bnel        $t4, $zero, L_8004E2A0
    if (ctx->r12 != 0) {
        // 0x8004E270: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E2A0;
    }
    goto skip_1;
    // 0x8004E270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8004E274:
    // 0x8004E274: jal         0x8004CF54
    // 0x8004E278: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8004CF54(rdram, ctx);
        goto after_0;
    // 0x8004E278: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x8004E27C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E280: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004E284: lbu         $t6, 0x14($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X14);
    // 0x8004E288: beql        $t6, $zero, L_8004E2A0
    if (ctx->r14 == 0) {
        // 0x8004E28C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E2A0;
    }
    goto skip_2;
    // 0x8004E28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8004E290: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8004E294: ori         $t9, $t7, 0xF00
    ctx->r25 = ctx->r15 | 0XF00;
    // 0x8004E298: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
L_8004E29C:
    // 0x8004E29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004E2A0:
    // 0x8004E2A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E2A4: jr          $ra
    // 0x8004E2A8: nop

    return;
    // 0x8004E2A8: nop

;}
RECOMP_FUNC void func_800041B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800041BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800041C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800041C4: beq         $a0, $zero, L_800041EC
    if (ctx->r4 == 0) {
        // 0x800041C8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800041EC;
    }
    // 0x800041C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800041CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800041D0: beq         $a0, $at, L_800041F8
    if (ctx->r4 == ctx->r1) {
        // 0x800041D4: lui         $a1, 0x800B
        ctx->r5 = S32(0X800B << 16);
            goto L_800041F8;
    }
    // 0x800041D4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800041D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800041DC: beq         $a0, $at, L_80004200
    if (ctx->r4 == ctx->r1) {
        // 0x800041E0: lui         $a1, 0x800B
        ctx->r5 = S32(0X800B << 16);
            goto L_80004200;
    }
    // 0x800041E0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800041E4: b           L_80004204
    // 0x800041E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
        goto L_80004204;
    // 0x800041E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_800041EC:
    // 0x800041EC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800041F0: b           L_80004204
    // 0x800041F4: addiu       $a1, $a1, 0x6C48
    ctx->r5 = ADD32(ctx->r5, 0X6C48);
        goto L_80004204;
    // 0x800041F4: addiu       $a1, $a1, 0x6C48
    ctx->r5 = ADD32(ctx->r5, 0X6C48);
L_800041F8:
    // 0x800041F8: b           L_80004204
    // 0x800041FC: addiu       $a1, $a1, 0x6D58
    ctx->r5 = ADD32(ctx->r5, 0X6D58);
        goto L_80004204;
    // 0x800041FC: addiu       $a1, $a1, 0x6D58
    ctx->r5 = ADD32(ctx->r5, 0X6D58);
L_80004200:
    // 0x80004200: addiu       $a1, $a1, 0x6E68
    ctx->r5 = ADD32(ctx->r5, 0X6E68);
L_80004204:
    // 0x80004204: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80004208: addiu       $v1, $a1, 0xD4
    ctx->r3 = ADD32(ctx->r5, 0XD4);
    // 0x8000420C: bnel        $t6, $zero, L_80004254
    if (ctx->r14 != 0) {
        // 0x80004210: lw          $t0, 0x0($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X0);
            goto L_80004254;
    }
    goto skip_0;
    // 0x80004210: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80004214: lh          $t7, 0x1E($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1E);
    // 0x80004218: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000421C: bnel        $a2, $t7, L_80004234
    if (ctx->r6 != ctx->r15) {
        // 0x80004220: lh          $t9, 0x2A($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X2A);
            goto L_80004234;
    }
    goto skip_1;
    // 0x80004220: lh          $t9, 0x2A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2A);
    skip_1:
    // 0x80004224: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80004228: b           L_800042B4
    // 0x8000422C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
        goto L_800042B4;
    // 0x8000422C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80004230: lh          $t9, 0x2A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2A);
L_80004234:
    // 0x80004234: bne         $a2, $t9, L_80004248
    if (ctx->r6 != ctx->r25) {
        // 0x80004238: nop
    
            goto L_80004248;
    }
    // 0x80004238: nop

    // 0x8000423C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80004240: b           L_800042B4
    // 0x80004244: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
        goto L_800042B4;
    // 0x80004244: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
L_80004248:
    // 0x80004248: b           L_800042B4
    // 0x8000424C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800042B4;
    // 0x8000424C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004250: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
L_80004254:
    // 0x80004254: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80004258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000425C: beq         $t0, $zero, L_80004290
    if (ctx->r8 == 0) {
        // 0x80004260: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80004290;
    }
    // 0x80004260: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80004264: lh          $t1, 0x1E($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1E);
L_80004268:
    // 0x80004268: bnel        $a2, $t1, L_8000427C
    if (ctx->r6 != ctx->r9) {
        // 0x8000426C: lw          $t2, 0x0($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X0);
            goto L_8000427C;
    }
    goto skip_2;
    // 0x8000426C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x80004270: b           L_800042B4
    // 0x80004274: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
        goto L_800042B4;
    // 0x80004274: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80004278: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
L_8000427C:
    // 0x8000427C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80004280: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80004284: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x80004288: bnel        $at, $zero, L_80004268
    if (ctx->r1 != 0) {
        // 0x8000428C: lh          $t1, 0x1E($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X1E);
            goto L_80004268;
    }
    goto skip_3;
    // 0x8000428C: lh          $t1, 0x1E($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1E);
    skip_3:
L_80004290:
    // 0x80004290: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80004294: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80004298: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000429C: bne         $t3, $at, L_800042B4
    if (ctx->r11 != ctx->r1) {
        // 0x800042A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800042B4;
    }
    // 0x800042A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800042A4: jal         0x80004160
    // 0x800042A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80004160(rdram, ctx);
        goto after_0;
    // 0x800042A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800042AC: b           L_800042B8
    // 0x800042B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800042B8;
    // 0x800042B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800042B4:
    // 0x800042B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800042B8:
    // 0x800042B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800042BC: jr          $ra
    // 0x800042C0: nop

    return;
    // 0x800042C0: nop

;}
RECOMP_FUNC void func_8003F85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F85C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003F860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003F864: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003F868: sw          $zero, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = 0;
    // 0x8003F86C: sb          $zero, 0x1F8($a0)
    MEM_B(0X1F8, ctx->r4) = 0;
    // 0x8003F870: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003F874: jal         0x800447C8
    // 0x8003F878: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8003F878: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003F87C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003F880: sw          $zero, 0x1F4($a1)
    MEM_W(0X1F4, ctx->r5) = 0;
    // 0x8003F884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003F888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003F88C: jr          $ra
    // 0x8003F890: nop

    return;
    // 0x8003F890: nop

;}
RECOMP_FUNC void func_80471040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471040: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(155, 0X48) << 16);
    // 0x80471044: addiu       $v0, $v0, 0x1088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(155, 0X48));
    // 0x80471048: jr          $ra
    // 0x8047104C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8047104C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8003D0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D0B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003D0B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D0B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D0BC: jal         0x8004700C
    // 0x8003D0C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003D0C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8003D0C4: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003D0C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D0CC: lbu         $t6, 0x159($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X159);
    // 0x8003D0D0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8003D0D4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8003D0D8: jal         0x8003D090
    // 0x8003D0DC: sb          $t6, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r14;
    func_8003D090(rdram, ctx);
        goto after_1;
    // 0x8003D0DC: sb          $t6, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r14;
    after_1:
    // 0x8003D0E0: lbu         $v1, 0x3F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003D0E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003D0E8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8003D0EC: beq         $v1, $at, L_8003D1C8
    if (ctx->r3 == ctx->r1) {
        // 0x8003D0F0: lw          $a3, 0x44($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X44);
            goto L_8003D1C8;
    }
    // 0x8003D0F0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8003D0F4: lwc1        $f2, 0xC4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8003D0F8: lwc1        $f4, 0xDC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x8003D0FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D100: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8003D104: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8003D108: bne         $v1, $at, L_8003D134
    if (ctx->r3 != ctx->r1) {
        // 0x8003D10C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003D134;
    }
    // 0x8003D10C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003D110: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003D114: nop

    // 0x8003D118: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8003D11C: nop

    // 0x8003D120: bc1fl       L_8003D154
    if (!c1cs) {
        // 0x8003D124: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_8003D154;
    }
    goto skip_0;
    // 0x8003D124: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_0:
    // 0x8003D128: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8003D12C: b           L_8003D150
    // 0x8003D130: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
        goto L_8003D150;
    // 0x8003D130: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
L_8003D134:
    // 0x8003D134: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003D138: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003D13C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8003D140: nop

    // 0x8003D144: bc1fl       L_8003D154
    if (!c1cs) {
        // 0x8003D148: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_8003D154;
    }
    goto skip_1;
    // 0x8003D148: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_1:
    // 0x8003D14C: sb          $t7, 0x159($a2)
    MEM_B(0X159, ctx->r6) = ctx->r15;
L_8003D150:
    // 0x8003D150: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_8003D154:
    // 0x8003D154: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8003D158: jal         0x80048F84
    // 0x8003D15C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8003D15C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_2:
    // 0x8003D160: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003D164: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D168: lwc1        $f16, 0xC4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8003D16C: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8003D170: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8003D174: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003D178: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003D17C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8003D180: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8003D184: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003D188: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8003D18C: nop

    // 0x8003D190: bc1fl       L_8003D1A4
    if (!c1cs) {
        // 0x8003D194: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_8003D1A4;
    }
    goto skip_2;
    // 0x8003D194: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    skip_2:
    // 0x8003D198: sb          $zero, 0x159($a2)
    MEM_B(0X159, ctx->r6) = 0;
    // 0x8003D19C: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8003D1A0: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_8003D1A4:
    // 0x8003D1A4: lwc1        $f10, 0x70($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X70);
    // 0x8003D1A8: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8003D1AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D1B0: lwc1        $f18, 0x1FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1FC);
    // 0x8003D1B4: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003D1B8: nop

    // 0x8003D1BC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8003D1C0: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8003D1C4: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
L_8003D1C8:
    // 0x8003D1C8: lw          $t8, 0x180($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X180);
    // 0x8003D1CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D1D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8003D1D4: bne         $a3, $t8, L_8003D1F4
    if (ctx->r7 != ctx->r24) {
        // 0x8003D1D8: nop
    
            goto L_8003D1F4;
    }
    // 0x8003D1D8: nop

    // 0x8003D1DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D1E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8003D1E4: jal         0x8003CE84
    // 0x8003D1E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8003CE84(rdram, ctx);
        goto after_3;
    // 0x8003D1E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x8003D1EC: b           L_8003D200
    // 0x8003D1F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8003D200;
    // 0x8003D1F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8003D1F4:
    // 0x8003D1F4: jal         0x8003CF70
    // 0x8003D1F8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8003CF70(rdram, ctx);
        goto after_4;
    // 0x8003D1F8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x8003D1FC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8003D200:
    // 0x8003D200: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D204: bnel        $v1, $at, L_8003D244
    if (ctx->r3 != ctx->r1) {
        // 0x8003D208: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003D244;
    }
    goto skip_3;
    // 0x8003D208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8003D20C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003D210: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003D214: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8003D218: bnel        $t9, $zero, L_8003D244
    if (ctx->r25 != 0) {
        // 0x8003D21C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003D244;
    }
    goto skip_4;
    // 0x8003D21C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8003D220: jal         0x8001D770
    // 0x8003D224: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    func_8001D770(rdram, ctx);
        goto after_5;
    // 0x8003D224: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_5:
    // 0x8003D228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003D22C: jal         0x80067E98
    // 0x8003D230: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_80067E98(rdram, ctx);
        goto after_6;
    // 0x8003D230: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_6:
    // 0x8003D234: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8003D238: jal         0x80067818
    // 0x8003D23C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8003D23C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8003D240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D244:
    // 0x8003D244: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D248: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8003D24C: jr          $ra
    // 0x8003D250: nop

    return;
    // 0x8003D250: nop

;}
RECOMP_FUNC void func_804374E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804374E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804374EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804374F0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804374F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804374F8: jal         0x8005FBC0
    // 0x804374FC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8005FBC0(rdram, ctx);
        goto after_0;
    // 0x804374FC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80437500: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80437504: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80437508: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    // 0x8043750C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80437510: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80437514: jr          $ra
    // 0x80437518: nop

    return;
    // 0x80437518: nop

;}
RECOMP_FUNC void func_804674FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804674FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80467500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80467504: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80467508: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8046750C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80467510: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80467514: lh          $t8, 0x1A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1A);
    // 0x80467518: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x8046751C: lw          $t2, 0x1F9C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1F9C);
    // 0x80467520: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467524: mflo        $t1
    ctx->r9 = lo;
    // 0x80467528: nop

    // 0x8046752C: nop

    // 0x80467530: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467534: mflo        $t3
    ctx->r11 = lo;
    // 0x80467538: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x8046753C: addiu       $t4, $v1, 0x1C
    ctx->r12 = ADD32(ctx->r3, 0X1C);
    // 0x80467540: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80467544: lw          $t0, 0x2CF8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2CF8);
    // 0x80467548: addiu       $a2, $v1, 0xFDC
    ctx->r6 = ADD32(ctx->r3, 0XFDC);
    // 0x8046754C: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x80467550: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80467554: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x80467558: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8046755C: bne         $at, $zero, L_80467568
    if (ctx->r1 != 0) {
        // 0x80467560: nop
    
            goto L_80467568;
    }
    // 0x80467560: nop

    // 0x80467564: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_80467568:
    // 0x80467568: bgezl       $t0, L_80467578
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8046756C: lw          $t5, 0x10($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X10);
            goto L_80467578;
    }
    goto skip_0;
    // 0x8046756C: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x80467570: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80467574: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
L_80467578:
    // 0x80467578: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8046757C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80467580: lw          $t6, 0x168($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X168);
    // 0x80467584: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80467588: lw          $a3, 0x88($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X88);
    // 0x8046758C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80467590: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80467594: jal         0x80056F40
    // 0x80467598: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80056F40(rdram, ctx);
        goto after_0;
    // 0x80467598: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8046759C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x804675A0: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x804675A4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x804675A8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x804675AC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x804675B0: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x804675B4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x804675B8: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x804675BC: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x804675C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x804675C4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x804675C8: lw          $t3, 0x168($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X168);
    // 0x804675CC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x804675D0: lw          $a3, 0x88($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X88);
    // 0x804675D4: jal         0x80056F40
    // 0x804675D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80056F40(rdram, ctx);
        goto after_1;
    // 0x804675D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x804675DC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x804675E0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x804675E4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x804675E8: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x804675EC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x804675F0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x804675F4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x804675F8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x804675FC: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80467600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80467604: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80467608: jr          $ra
    // 0x8046760C: nop

    return;
    // 0x8046760C: nop

;}
RECOMP_FUNC void func_8003DBB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DBB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DBB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DBBC: jal         0x8003D9E4
    // 0x8003DBC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003D9E4(rdram, ctx);
        goto after_0;
    // 0x8003DBC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DBC4: jal         0x8003DB3C
    // 0x8003DBC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003DB3C(rdram, ctx);
        goto after_1;
    // 0x8003DBC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003DBCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DBD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DBD4: jr          $ra
    // 0x8003DBD8: nop

    return;
    // 0x8003DBD8: nop

;}
RECOMP_FUNC void func_804C3574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3574: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804C3578: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(206, 0X93C) << 16);
    // 0x804C357C: addiu       $t6, $t6, 0x33BC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(206, 0X93C));
    // 0x804C3580: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804C3584: jr          $ra
    // 0x804C3588: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804C3588: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void fcos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D250: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8008D254: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8008D258: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8008D25C: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8008D260: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8008D264: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8008D268: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x8008D26C: beql        $at, $zero, L_8008D394
    if (ctx->r1 == 0) {
        // 0x8008D270: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_8008D394;
    }
    goto skip_0;
    // 0x8008D270: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x8008D274: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008D278: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8008D27C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008D280: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008D284: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8008D288: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D28C: bc1fl       L_8008D2A0
    if (!c1cs) {
        // 0x8008D290: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_8008D2A0;
    }
    goto skip_1;
    // 0x8008D290: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x8008D294: b           L_8008D2A0
    // 0x8008D298: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_8008D2A0;
    // 0x8008D298: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x8008D29C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8008D2A0:
    // 0x8008D2A0: ldc1        $f8, 0x3418($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X3418);
    // 0x8008D2A4: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x8008D2A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008D2AC: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x8008D2B0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8008D2B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008D2B8: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x8008D2BC: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x8008D2C0: nop

    // 0x8008D2C4: bc1fl       L_8008D2E4
    if (!c1cs) {
        // 0x8008D2C8: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_8008D2E4;
    }
    goto skip_2;
    // 0x8008D2C8: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x8008D2CC: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x8008D2D0: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8008D2D4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8008D2D8: b           L_8008D2F4
    // 0x8008D2DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_8008D2F4;
    // 0x8008D2DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8008D2E0: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_8008D2E4:
    // 0x8008D2E4: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8008D2E8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8008D2EC: nop

    // 0x8008D2F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_8008D2F4:
    // 0x8008D2F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D2F8: ldc1        $f10, 0x3420($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3420);
    // 0x8008D2FC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8008D300: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D304: ldc1        $f6, 0x3428($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3428);
    // 0x8008D308: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8008D30C: addiu       $v1, $v1, 0x33F0
    ctx->r3 = ADD32(ctx->r3, 0X33F0);
    // 0x8008D310: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x8008D314: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8008D318: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8008D31C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x8008D320: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8008D324: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x8008D328: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x8008D32C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x8008D330: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8008D334: nop

    // 0x8008D338: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x8008D33C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8008D340: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x8008D344: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8008D348: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8008D34C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x8008D350: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8008D354: bne         $t0, $zero, L_8008D374
    if (ctx->r8 != 0) {
        // 0x8008D358: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_8008D374;
    }
    // 0x8008D358: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8008D35C: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8008D360: nop

    // 0x8008D364: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8008D368: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8008D36C: jr          $ra
    // 0x8008D370: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x8008D370: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8008D374:
    // 0x8008D374: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8008D378: nop

    // 0x8008D37C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8008D380: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x8008D384: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x8008D388: jr          $ra
    // 0x8008D38C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8008D38C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8008D390: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_8008D394:
    // 0x8008D394: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D398: bc1t        L_8008D3AC
    if (c1cs) {
        // 0x8008D39C: nop
    
            goto L_8008D3AC;
    }
    // 0x8008D39C: nop

    // 0x8008D3A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8008D3A4: jr          $ra
    // 0x8008D3A8: lwc1        $f0, 0x3440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3440);
    return;
    // 0x8008D3A8: lwc1        $f0, 0x3440($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3440);
L_8008D3AC:
    // 0x8008D3AC: lwc1        $f0, 0x3430($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3430);
    // 0x8008D3B0: jr          $ra
    // 0x8008D3B4: nop

    return;
    // 0x8008D3B4: nop

    // 0x8008D3B8: nop

    // 0x8008D3BC: nop

;}
RECOMP_FUNC void func_8057F8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F8C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8057F8C8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8057F8CC: addiu       $v0, $a0, 0x6C
    ctx->r2 = ADD32(ctx->r4, 0X6C);
    // 0x8057F8D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8057F8D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8057F8D8: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
L_8057F8DC:
    // 0x8057F8DC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057F8E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8057F8E4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8057F8E8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8057F8EC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057F8F0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8057F8F4: nop

    // 0x8057F8F8: bc1f        L_8057F904
    if (!c1cs) {
        // 0x8057F8FC: nop
    
            goto L_8057F904;
    }
    // 0x8057F8FC: nop

    // 0x8057F900: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_8057F904:
    // 0x8057F904: bne         $v1, $a0, L_8057F8DC
    if (ctx->r3 != ctx->r4) {
        // 0x8057F908: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8057F8DC;
    }
    // 0x8057F908: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8057F90C: jr          $ra
    // 0x8057F910: nop

    return;
    // 0x8057F910: nop

;}
RECOMP_FUNC void func_80007B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007B74: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80007B78: jr          $ra
    // 0x80007B7C: sw          $a0, 0x7E70($at)
    MEM_W(0X7E70, ctx->r1) = ctx->r4;
    return;
    // 0x80007B7C: sw          $a0, 0x7E70($at)
    MEM_W(0X7E70, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8042F9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F9B0: lw          $a2, 0xC8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC8);
    // 0x8042F9B4: lw          $a1, 0xC4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC4);
    // 0x8042F9B8: jal         0x8042F868
    // 0x8042F9BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042F868(rdram, ctx);
        goto after_0;
    // 0x8042F9BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042F9C0: jal         0x8042F894
    // 0x8042F9C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042F894(rdram, ctx);
        goto after_1;
    // 0x8042F9C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042F9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F9CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F9D0: jr          $ra
    // 0x8042F9D4: nop

    return;
    // 0x8042F9D4: nop

;}
RECOMP_FUNC void func_806FD534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FD538: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806FD53C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x806FD540: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806FD544: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806FD548: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x806FD54C: lui         $a0, 0x8070
    ctx->r4 = S32(RELOC_HI16(706, 0X1500) << 16);
    // 0x806FD550: lui         $a1, 0x4600
    ctx->r5 = S32(0X4600 << 16);
    // 0x806FD554: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x806FD558: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x806FD55C: ori         $a1, $a1, 0x2800
    ctx->r5 = ctx->r5 | 0X2800;
    // 0x806FD560: addiu       $a0, $a0, -0x16A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(706, 0X1500));
    // 0x806FD564: jal         0x80046804
    // 0x806FD568: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x806FD568: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x806FD56C: bne         $v0, $zero, L_806FD57C
    if (ctx->r2 != 0) {
        // 0x806FD570: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806FD57C;
    }
    // 0x806FD570: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806FD574: b           L_806FD5AC
    // 0x806FD578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806FD5AC;
    // 0x806FD578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806FD57C:
    // 0x806FD57C: jal         0x80047090
    // 0x806FD580: addiu       $a0, $zero, 0x4600
    ctx->r4 = ADD32(0, 0X4600);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x806FD580: addiu       $a0, $zero, 0x4600
    ctx->r4 = ADD32(0, 0X4600);
    after_1:
    // 0x806FD584: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x806FD588: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x806FD58C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FD590: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x806FD594: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x806FD598: jal         0x80044194
    // 0x806FD59C: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806FD59C: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    after_2:
    // 0x806FD5A0: jal         0x80052BA4
    // 0x806FD5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_3;
    // 0x806FD5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806FD5A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_806FD5AC:
    // 0x806FD5AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806FD5B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806FD5B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FD5B8: jr          $ra
    // 0x806FD5BC: nop

    return;
    // 0x806FD5BC: nop

;}
RECOMP_FUNC void func_8064EE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EE50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064EE54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8064EE58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8064EE5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8064EE60: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064EE64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8064EE68: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8064EE6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064EE70: addiu       $t6, $zero, 0x1EB4
    ctx->r14 = ADD32(0, 0X1EB4);
    // 0x8064EE74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8064EE78: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064EE7C: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064EE80: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8064EE84: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8064EE88: jal         0x8064EA0C
    // 0x8064EE8C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_0;
    // 0x8064EE8C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8064EE90: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8064EE94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EE98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064EE9C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8064EEA0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8064EEA4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8064EEA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8064EEAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064EEB0: jr          $ra
    // 0x8064EEB4: nop

    return;
    // 0x8064EEB4: nop

;}
RECOMP_FUNC void func_80736FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736FA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80736FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736FA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80736FAC: jal         0x80047090
    // 0x80736FB0: addiu       $a0, $zero, 0x462C
    ctx->r4 = ADD32(0, 0X462C);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80736FB0: addiu       $a0, $zero, 0x462C
    ctx->r4 = ADD32(0, 0X462C);
    after_0:
    // 0x80736FB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80736FB8: lui         $at, 0x462C
    ctx->r1 = S32(0X462C << 16);
    // 0x80736FBC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80736FC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80736FC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80736FC8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80736FCC: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80736FD0: jal         0x8004613C
    // 0x80736FD4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80736FD4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80736FD8: bne         $v0, $zero, L_80736FE8
    if (ctx->r2 != 0) {
        // 0x80736FDC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80736FE8;
    }
    // 0x80736FDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80736FE0: b           L_80737010
    // 0x80736FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80737010;
    // 0x80736FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80736FE8:
    // 0x80736FE8: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x80736FEC: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x80736FF0: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80736FF4: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80736FF8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80736FFC: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x80737000: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80737004: jal         0x80047F9C
    // 0x80737008: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80737008: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8073700C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80737010:
    // 0x80737010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80737014: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80737018: jr          $ra
    // 0x8073701C: nop

    return;
    // 0x8073701C: nop

;}
RECOMP_FUNC void func_806EF4A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF4A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EF4A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806EF4A8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806EF4AC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806EF4B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EF4B4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806EF4B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806EF4BC: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x806EF4C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806EF4C4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806EF4C8: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(676, 0X4A8C) << 16);
    // 0x806EF4CC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806EF4D0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806EF4D4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806EF4D8: lw          $t2, 0x9DC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(676, 0X4A8C));
    // 0x806EF4DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806EF4E0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806EF4E4: jal         0x806EF1E4
    // 0x806EF4E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806EF1E4(rdram, ctx);
        goto after_0;
    // 0x806EF4E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EF4EC: jal         0x806EF230
    // 0x806EF4F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806EF230(rdram, ctx);
        goto after_1;
    // 0x806EF4F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806EF4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EF4F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EF4FC: jr          $ra
    // 0x806EF500: nop

    return;
    // 0x806EF500: nop

;}
