#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80450350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80450354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045035C: jal         0x80444408
    // 0x80450360: addiu       $a1, $zero, 0x40F8
    ctx->r5 = ADD32(0, 0X40F8);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x80450360: addiu       $a1, $zero, 0x40F8
    ctx->r5 = ADD32(0, 0X40F8);
    after_0:
    // 0x80450364: bnel        $v0, $zero, L_80450378
    if (ctx->r2 != 0) {
        // 0x80450368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80450378;
    }
    goto skip_0;
    // 0x80450368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8045036C: jal         0x804452AC
    // 0x80450370: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804452AC(rdram, ctx);
        goto after_1;
    // 0x80450370: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80450374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80450378:
    // 0x80450378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045037C: jr          $ra
    // 0x80450380: nop

    return;
    // 0x80450380: nop

;}
RECOMP_FUNC void func_80049864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004986C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80049870: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80049874: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80049878: jal         0x80049018
    // 0x8004987C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8004987C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80049880: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80049884: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80049888: beq         $v0, $zero, L_800498AC
    if (ctx->r2 == 0) {
        // 0x8004988C: lwc1        $f2, 0x24($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
            goto L_800498AC;
    }
    // 0x8004988C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80049890: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80049894: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80049898: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8004989C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800498A0: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800498A4: b           L_800498C4
    // 0x800498A8: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
        goto L_800498C4;
    // 0x800498A8: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
L_800498AC:
    // 0x800498AC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800498B0: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800498B4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x800498B8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800498BC: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800498C0: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_800498C4:
    // 0x800498C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800498C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800498CC: jr          $ra
    // 0x800498D0: nop

    return;
    // 0x800498D0: nop

;}
RECOMP_FUNC void func_806EC288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC288: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EC28C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EC290: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806EC294: jal         0x80047090
    // 0x806EC298: addiu       $a0, $zero, 0x45E3
    ctx->r4 = ADD32(0, 0X45E3);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806EC298: addiu       $a0, $zero, 0x45E3
    ctx->r4 = ADD32(0, 0X45E3);
    after_0:
    // 0x806EC29C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806EC2A0: bne         $v0, $at, L_806EC2B0
    if (ctx->r2 != ctx->r1) {
        // 0x806EC2A4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806EC2B0;
    }
    // 0x806EC2A4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806EC2A8: b           L_806EC314
    // 0x806EC2AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EC314;
    // 0x806EC2AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EC2B0:
    // 0x806EC2B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EC2B4: lui         $at, 0x45E3
    ctx->r1 = S32(0X45E3 << 16);
    // 0x806EC2B8: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x806EC2BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806EC2C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806EC2C4: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x806EC2C8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x806EC2CC: jal         0x8004613C
    // 0x806EC2D0: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806EC2D0: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x806EC2D4: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x806EC2D8: bne         $v0, $zero, L_806EC2E8
    if (ctx->r2 != 0) {
        // 0x806EC2DC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806EC2E8;
    }
    // 0x806EC2DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806EC2E0: b           L_806EC314
    // 0x806EC2E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EC314;
    // 0x806EC2E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EC2E8:
    // 0x806EC2E8: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x806EC2EC: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x806EC2F0: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806EC2F4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x806EC2F8: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x806EC2FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806EC300: jal         0x80047F9C
    // 0x806EC304: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806EC304: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806EC308: jal         0x8005FDC4
    // 0x806EC30C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x806EC30C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x806EC310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EC314:
    // 0x806EC314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EC318: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EC31C: jr          $ra
    // 0x806EC320: nop

    return;
    // 0x806EC320: nop

;}
RECOMP_FUNC void func_8051AAEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051AAEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8051AAF0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8051AAF4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8051AAF8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8051AAFC: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8051AB00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051AB04: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8051AB08: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8051AB0C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8051AB10: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8051AB14: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8051AB18: lw          $t9, 0x38($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X38);
    // 0x8051AB1C: jalr        $t9
    // 0x8051AB20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8051AB20: nop

    after_0:
    // 0x8051AB24: bne         $v0, $zero, L_8051AB34
    if (ctx->r2 != 0) {
        // 0x8051AB28: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8051AB34;
    }
    // 0x8051AB28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8051AB2C: b           L_8051AB38
    // 0x8051AB30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8051AB38;
    // 0x8051AB30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8051AB34:
    // 0x8051AB34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8051AB38:
    // 0x8051AB38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051AB3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8051AB40: jr          $ra
    // 0x8051AB44: nop

    return;
    // 0x8051AB44: nop

;}
RECOMP_FUNC void func_80453D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453D64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453D6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453D70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80453D74: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453D78: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80453D7C: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    // 0x80453D80: jal         0x804449C0
    // 0x80453D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804449C0(rdram, ctx);
        goto after_0;
    // 0x80453D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80453D88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80453D8C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80453D90: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80453D94: jal         0x80450490
    // 0x80453D98: nop

    func_80450490(rdram, ctx);
        goto after_1;
    // 0x80453D98: nop

    after_1:
    // 0x80453D9C: jal         0x80445760
    // 0x80453DA0: nop

    func_80445760(rdram, ctx);
        goto after_2;
    // 0x80453DA0: nop

    after_2:
    // 0x80453DA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80453DA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80453DAC: jal         0x80457164
    // 0x80453DB0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_80457164(rdram, ctx);
        goto after_3;
    // 0x80453DB0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
    // 0x80453DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453DBC: jr          $ra
    // 0x80453DC0: nop

    return;
    // 0x80453DC0: nop

;}
RECOMP_FUNC void pad_logical_stick_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FBBC: jr          $ra
    // 0x8007FBC0: lb          $v0, 0x15($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X15);
    return;
    // 0x8007FBC0: lb          $v0, 0x15($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X15);
;}
RECOMP_FUNC void func_8078A148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A148: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8078A14C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078A150: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8078A154: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8078A158: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078A15C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078A160: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078A164: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8078A168: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8078A16C: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(790, 0X4E0) << 16);
    // 0x8078A170: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8078A174: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078A178: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078A17C: lw          $t1, -0x5E70($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(790, 0X4E0));
    // 0x8078A180: jr          $ra
    // 0x8078A184: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8078A184: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8078A188: nop

    // 0x8078A18C: nop

;}
RECOMP_FUNC void func_805DA4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA4E0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805DA4E4: lw          $t6, -0x71F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71F0);
    // 0x805DA4E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DA4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA4F0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x805DA4F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805DA4F8: bne         $t7, $zero, L_805DA510
    if (ctx->r15 != 0) {
        // 0x805DA4FC: nop
    
            goto L_805DA510;
    }
    // 0x805DA4FC: nop

    // 0x805DA500: jal         0x800447C8
    // 0x805DA504: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x805DA504: nop

    after_0:
    // 0x805DA508: b           L_805DA510
    // 0x805DA50C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805DA510;
    // 0x805DA50C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805DA510:
    // 0x805DA510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DA518: jr          $ra
    // 0x805DA51C: nop

    return;
    // 0x805DA51C: nop

;}
RECOMP_FUNC void func_807094B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807094B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807094B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807094BC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807094C0: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(718, 0X14F8) << 16);
    // 0x807094C4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807094C8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807094CC: addiu       $t6, $t6, -0x5928
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(718, 0X14F8));
    // 0x807094D0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807094D4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807094D8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807094DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807094E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807094E4: jal         0x80709504
    // 0x807094E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80709504(rdram, ctx);
        goto after_0;
    // 0x807094E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x807094EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807094F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807094F4: jr          $ra
    // 0x807094F8: nop

    return;
    // 0x807094F8: nop

;}
RECOMP_FUNC void func_807B8878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8878: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B887C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B8880: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807B8884: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807B8888: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B888C: jal         0x807B8298
    // 0x807B8890: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_807B8298(rdram, ctx);
        goto after_0;
    // 0x807B8890: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x807B8894: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x807B8898: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x807B889C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B88A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B88A4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807B88A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B88AC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x807B88B0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807B88B4: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B88B8: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x807B88BC: lui         $a2, 0x4188
    ctx->r6 = S32(0X4188 << 16);
    // 0x807B88C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B88C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807B88C8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807B88CC: ori         $a2, $a2, 0x51EB
    ctx->r6 = ctx->r6 | 0X51EB;
    // 0x807B88D0: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B88D4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x807B88D8: jal         0x8005CEBC
    // 0x807B88DC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_1;
    // 0x807B88DC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x807B88E0: lw          $t2, 0x3C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X3C);
    // 0x807B88E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B88E8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B88EC: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x807B88F0: jal         0x807B8314
    // 0x807B88F4: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_2;
    // 0x807B88F4: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    after_2:
    // 0x807B88F8: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x807B88FC: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8900: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807B8904: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x807B8908: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x807B890C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807B8910: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x807B8914: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x807B8918: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B891C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x807B8920: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807B8924: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x807B8928: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B892C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x807B8930: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x807B8934: lui         $a3, 0xC220
    ctx->r7 = S32(0XC220 << 16);
    // 0x807B8938: jal         0x8005CEBC
    // 0x807B893C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_3;
    // 0x807B893C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x807B8940: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B8948: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x807B894C: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x807B8950: jal         0x807B8314
    // 0x807B8954: sw          $v0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_4;
    // 0x807B8954: sw          $v0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r2;
    after_4:
    // 0x807B8958: jal         0x807B8340
    // 0x807B895C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807B8340(rdram, ctx);
        goto after_5;
    // 0x807B895C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x807B8960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B8964: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807B8968: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807B896C: jr          $ra
    // 0x807B8970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B8970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80672420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672420: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80672424: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80672428: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8067242C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80672430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80672434: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80672438: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8067243C: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x80672440: jal         0x80671D4C
    // 0x80672444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80672444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80672448: lw          $t6, 0x1E0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1E0);
    // 0x8067244C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x80672450: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80672454: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80672458: blez        $t7, L_80672488
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8067245C: sw          $t7, 0x1E0($s2)
        MEM_W(0X1E0, ctx->r18) = ctx->r15;
            goto L_80672488;
    }
    // 0x8067245C: sw          $t7, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = ctx->r15;
    // 0x80672460: sw          $zero, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = 0;
    // 0x80672464: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672468: jal         0x80671954
    // 0x8067246C: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    func_80671954(rdram, ctx);
        goto after_1;
    // 0x8067246C: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_1:
    // 0x80672470: beq         $v0, $zero, L_8067247C
    if (ctx->r2 == 0) {
        // 0x80672474: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8067247C;
    }
    // 0x80672474: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80672478: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8067247C:
    // 0x8067247C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80672480: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80672484: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
L_80672488:
    // 0x80672488: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8067248C: beq         $at, $zero, L_806724A0
    if (ctx->r1 == 0) {
        // 0x80672490: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_806724A0;
    }
    // 0x80672490: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80672494: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672498: jal         0x80671C98
    // 0x8067249C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    func_80671C98(rdram, ctx);
        goto after_2;
    // 0x8067249C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_2:
L_806724A0:
    // 0x806724A0: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x806724A4: bne         $at, $zero, L_806724C0
    if (ctx->r1 != 0) {
        // 0x806724A8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_806724C0;
    }
    // 0x806724A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x806724AC: jal         0x80672C80
    // 0x806724B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80672C80(rdram, ctx);
        goto after_3;
    // 0x806724B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x806724B4: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x806724B8: jal         0x80067818
    // 0x806724BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x806724BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_806724C0:
    // 0x806724C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806724C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806724C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806724CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806724D0: jr          $ra
    // 0x806724D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806724D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8076DD8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DD8C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8076DD90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8076DD94: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8076DD98: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8076DD9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8076DDA0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8076DDA4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8076DDA8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8076DDAC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8076DDB0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8076DDB4: lui         $t1, 0x8077
    ctx->r9 = S32(RELOC_HI16(766, 0X3A3C) << 16);
    // 0x8076DDB8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8076DDBC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8076DDC0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8076DDC4: lw          $t1, 0x22C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(766, 0X3A3C));
    // 0x8076DDC8: jr          $ra
    // 0x8076DDCC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8076DDCC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80471368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8047136C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471370: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80471374: sw          $zero, -0x71AC($at)
    MEM_W(-0X71AC, ctx->r1) = 0;
    // 0x80471378: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8047137C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80471380: jal         0x8006E0FC
    // 0x80471384: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x80471384: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80471388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8047138C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80471390: sw          $zero, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = 0;
    // 0x80471394: jr          $ra
    // 0x80471398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80471398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006DA0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DA10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DA14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006DA18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006DA1C: jal         0x8006D6F8
    // 0x8006DA20: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    func_8006D6F8(rdram, ctx);
        goto after_0;
    // 0x8006DA20: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    after_0:
    // 0x8006DA24: bne         $v0, $zero, L_8006DAD8
    if (ctx->r2 != 0) {
        // 0x8006DA28: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006DAD8;
    }
    // 0x8006DA28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8006DA2C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8006DA30: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x8006DA34: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8006DA38: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8006DA3C: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8006DA40: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8006DA44: jal         0x8006D59C
    // 0x8006DA48: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8006D59C(rdram, ctx);
        goto after_1;
    // 0x8006DA48: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8006DA4C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8006DA50: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8006DA54: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x8006DA58: jal         0x8006D85C
    // 0x8006DA5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8006D85C(rdram, ctx);
        goto after_2;
    // 0x8006DA5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8006DA60: bne         $v0, $zero, L_8006DA70
    if (ctx->r2 != 0) {
        // 0x8006DA64: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_8006DA70;
    }
    // 0x8006DA64: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DA68: b           L_8006DAE4
    // 0x8006DA6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006DAE4;
    // 0x8006DA6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006DA70:
    // 0x8006DA70: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8006DA74: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8006DA78: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x8006DA7C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006DA80: beq         $v0, $at, L_8006DA98
    if (ctx->r2 == ctx->r1) {
        // 0x8006DA84: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8006DA98;
    }
    // 0x8006DA84: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006DA88: beq         $v0, $at, L_8006DA98
    if (ctx->r2 == ctx->r1) {
        // 0x8006DA8C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006DA98;
    }
    // 0x8006DA8C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006DA90: bnel        $v0, $at, L_8006DAD4
    if (ctx->r2 != ctx->r1) {
        // 0x8006DA94: lbu         $t3, 0x27($sp)
        ctx->r11 = MEM_BU(ctx->r29, 0X27);
            goto L_8006DAD4;
    }
    goto skip_0;
    // 0x8006DA94: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    skip_0:
L_8006DA98:
    // 0x8006DA98: lw          $t0, 0x8D0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8D0);
    // 0x8006DA9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006DAA0: lh          $t1, 0x7C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X7C);
    // 0x8006DAA4: beql        $t1, $at, L_8006DAD4
    if (ctx->r9 == ctx->r1) {
        // 0x8006DAA8: lbu         $t3, 0x27($sp)
        ctx->r11 = MEM_BU(ctx->r29, 0X27);
            goto L_8006DAD4;
    }
    goto skip_1;
    // 0x8006DAA8: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    skip_1:
    // 0x8006DAAC: lw          $t2, 0x62C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X62C);
    // 0x8006DAB0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006DAB4: addiu       $a0, $a0, 0x10E4
    ctx->r4 = ADD32(ctx->r4, 0X10E4);
    // 0x8006DAB8: beql        $t2, $zero, L_8006DAD4
    if (ctx->r10 == 0) {
        // 0x8006DABC: lbu         $t3, 0x27($sp)
        ctx->r11 = MEM_BU(ctx->r29, 0X27);
            goto L_8006DAD4;
    }
    goto skip_2;
    // 0x8006DABC: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
    skip_2:
    // 0x8006DAC0: jal         0x80071380
    // 0x8006DAC4: addiu       $a1, $zero, 0x1D8
    ctx->r5 = ADD32(0, 0X1D8);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x8006DAC4: addiu       $a1, $zero, 0x1D8
    ctx->r5 = ADD32(0, 0X1D8);
    after_3:
    // 0x8006DAC8: b           L_8006DAE4
    // 0x8006DACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006DAE4;
    // 0x8006DACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006DAD0: lbu         $t3, 0x27($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X27);
L_8006DAD4:
    // 0x8006DAD4: sb          $t3, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r11;
L_8006DAD8:
    // 0x8006DAD8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006DADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006DAE0: sw          $a2, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r6;
L_8006DAE4:
    // 0x8006DAE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DAE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006DAEC: jr          $ra
    // 0x8006DAF0: nop

    return;
    // 0x8006DAF0: nop

;}
RECOMP_FUNC void func_80525510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525510: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80525514: addiu       $at, $zero, 0x41E7
    ctx->r1 = ADD32(0, 0X41E7);
    // 0x80525518: beq         $v0, $at, L_80525548
    if (ctx->r2 == ctx->r1) {
        // 0x8052551C: addiu       $at, $zero, 0x41E8
        ctx->r1 = ADD32(0, 0X41E8);
            goto L_80525548;
    }
    // 0x8052551C: addiu       $at, $zero, 0x41E8
    ctx->r1 = ADD32(0, 0X41E8);
    // 0x80525520: beq         $v0, $at, L_80525548
    if (ctx->r2 == ctx->r1) {
        // 0x80525524: addiu       $at, $zero, 0x41E9
        ctx->r1 = ADD32(0, 0X41E9);
            goto L_80525548;
    }
    // 0x80525524: addiu       $at, $zero, 0x41E9
    ctx->r1 = ADD32(0, 0X41E9);
    // 0x80525528: beq         $v0, $at, L_80525548
    if (ctx->r2 == ctx->r1) {
        // 0x8052552C: addiu       $at, $zero, 0x41EA
        ctx->r1 = ADD32(0, 0X41EA);
            goto L_80525548;
    }
    // 0x8052552C: addiu       $at, $zero, 0x41EA
    ctx->r1 = ADD32(0, 0X41EA);
    // 0x80525530: beq         $v0, $at, L_80525548
    if (ctx->r2 == ctx->r1) {
        // 0x80525534: addiu       $at, $zero, 0x45D7
        ctx->r1 = ADD32(0, 0X45D7);
            goto L_80525548;
    }
    // 0x80525534: addiu       $at, $zero, 0x45D7
    ctx->r1 = ADD32(0, 0X45D7);
    // 0x80525538: beq         $v0, $at, L_80525554
    if (ctx->r2 == ctx->r1) {
        // 0x8052553C: lui         $t6, 0x8052
        ctx->r14 = S32(RELOC_HI16(324, 0X7DC) << 16);
            goto L_80525554;
    }
    // 0x8052553C: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(324, 0X7DC) << 16);
    // 0x80525540: b           L_8052556C
    // 0x80525544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8052556C;
    // 0x80525544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80525548:
    // 0x80525548: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(324, 0X4EC) << 16);
    // 0x8052554C: jr          $ra
    // 0x80525550: addiu       $v0, $v0, 0x59FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(324, 0X4EC));
    return;
    // 0x80525550: addiu       $v0, $v0, 0x59FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(324, 0X4EC));
L_80525554:
    // 0x80525554: addiu       $t6, $t6, 0x5CEC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(324, 0X7DC));
    // 0x80525558: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8052555C: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(324, 0X788) << 16);
    // 0x80525560: sw          $t6, -0x72EC($at)
    MEM_W(-0X72EC, ctx->r1) = ctx->r14;
    // 0x80525564: jr          $ra
    // 0x80525568: addiu       $v0, $v0, 0x5C98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(324, 0X788));
    return;
    // 0x80525568: addiu       $v0, $v0, 0x5C98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(324, 0X788));
L_8052556C:
    // 0x8052556C: jr          $ra
    // 0x80525570: nop

    return;
    // 0x80525570: nop

;}
RECOMP_FUNC void func_804D8330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8330: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804D8334: addiu       $at, $zero, 0x404A
    ctx->r1 = ADD32(0, 0X404A);
    // 0x804D8338: beq         $v0, $at, L_804D8350
    if (ctx->r2 == ctx->r1) {
        // 0x804D833C: addiu       $at, $zero, 0x404B
        ctx->r1 = ADD32(0, 0X404B);
            goto L_804D8350;
    }
    // 0x804D833C: addiu       $at, $zero, 0x404B
    ctx->r1 = ADD32(0, 0X404B);
    // 0x804D8340: beq         $v0, $at, L_804D835C
    if (ctx->r2 == ctx->r1) {
        // 0x804D8344: nop
    
            goto L_804D835C;
    }
    // 0x804D8344: nop

    // 0x804D8348: b           L_804D8368
    // 0x804D834C: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(255, 0X4A4) << 16);
        goto L_804D8368;
    // 0x804D834C: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(255, 0X4A4) << 16);
L_804D8350:
    // 0x804D8350: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(255, 0X4A4) << 16);
    // 0x804D8354: jr          $ra
    // 0x804D8358: addiu       $v0, $v0, -0x782C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(255, 0X4A4));
    return;
    // 0x804D8358: addiu       $v0, $v0, -0x782C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(255, 0X4A4));
L_804D835C:
    // 0x804D835C: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(255, 0X69C) << 16);
    // 0x804D8360: jr          $ra
    // 0x804D8364: addiu       $v0, $v0, -0x7634
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(255, 0X69C));
    return;
    // 0x804D8364: addiu       $v0, $v0, -0x7634
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(255, 0X69C));
L_804D8368:
    // 0x804D8368: addiu       $v0, $v0, -0x782C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(255, 0X4A4));
    // 0x804D836C: jr          $ra
    // 0x804D8370: nop

    return;
    // 0x804D8370: nop

;}
RECOMP_FUNC void func_804F3360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3360: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x804F3364: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x804F3368: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804F336C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x804F3370: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x804F3374: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x804F3378: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x804F337C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x804F3380: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x804F3384: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x804F3388: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x804F338C: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
L_804F3390:
    // 0x804F3390: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804F3394: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x804F3398: sh          $a0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r4;
    // 0x804F339C: sh          $a0, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r4;
    // 0x804F33A0: sh          $a0, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r4;
    // 0x804F33A4: bne         $at, $zero, L_804F3390
    if (ctx->r1 != 0) {
        // 0x804F33A8: sh          $a0, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r4;
            goto L_804F3390;
    }
    // 0x804F33A8: sh          $a0, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r4;
    // 0x804F33AC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x804F33B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804F33B4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804F33B8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804F33BC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x804F33C0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x804F33C4: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x804F33C8: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804F33CC: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x804F33D0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804F33D4: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x804F33D8: nop

    // 0x804F33DC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x804F33E0: jal         0x8006A99C
    // 0x804F33E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x804F33E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x804F33E8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804F33EC: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x804F33F0: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804F33F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804F33F8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x804F33FC: nop

    // 0x804F3400: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x804F3404: jal         0x8006A99C
    // 0x804F3408: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x804F3408: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x804F340C: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x804F3410: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x804F3414: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x804F3418: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x804F341C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x804F3420: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x804F3424: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x804F3428: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x804F342C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x804F3430: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x804F3434: jal         0x8006AFA0
    // 0x804F3438: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_8006AFA0(rdram, ctx);
        goto after_2;
    // 0x804F3438: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_2:
    // 0x804F343C: lui         $s0, 0x804F
    ctx->r16 = S32(RELOC_HI16(270, 0XD10) << 16);
    // 0x804F3440: lui         $s5, 0x804F
    ctx->r21 = S32(RELOC_HI16(270, 0XD48) << 16);
    // 0x804F3444: addiu       $s5, $s5, 0x4078
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(270, 0XD48));
    // 0x804F3448: addiu       $s0, $s0, 0x4040
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(270, 0XD10));
    // 0x804F344C: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x804F3450: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_804F3454:
    // 0x804F3454: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x804F3458: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x804F345C: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x804F3460: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x804F3464: andi        $a3, $v0, 0xF000
    ctx->r7 = ctx->r2 & 0XF000;
    // 0x804F3468: sra         $a3, $a3, 12
    ctx->r7 = S32(SIGNED(ctx->r7) >> 12);
    // 0x804F346C: beq         $s4, $a0, L_804F34BC
    if (ctx->r20 == ctx->r4) {
        // 0x804F3470: andi        $v1, $a0, 0xF800
        ctx->r3 = ctx->r4 & 0XF800;
            goto L_804F34BC;
    }
    // 0x804F3470: andi        $v1, $a0, 0xF800
    ctx->r3 = ctx->r4 & 0XF800;
    // 0x804F3474: bne         $v1, $zero, L_804F3480
    if (ctx->r3 != 0) {
        // 0x804F3478: sll         $a3, $a3, 16
        ctx->r7 = S32(ctx->r7 << 16);
            goto L_804F3480;
    }
    // 0x804F3478: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x804F347C: addiu       $v1, $zero, 0x5800
    ctx->r3 = ADD32(0, 0X5800);
L_804F3480:
    // 0x804F3480: andi        $t0, $v0, 0xF00
    ctx->r8 = ctx->r2 & 0XF00;
    // 0x804F3484: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    // 0x804F3488: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    // 0x804F348C: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x804F3490: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x804F3494: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x804F3498: addu        $a1, $s2, $t0
    ctx->r5 = ADD32(ctx->r18, ctx->r8);
    // 0x804F349C: addu        $a0, $s1, $a3
    ctx->r4 = ADD32(ctx->r17, ctx->r7);
    // 0x804F34A0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x804F34A4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x804F34A8: or          $a2, $t3, $v1
    ctx->r6 = ctx->r11 | ctx->r3;
    // 0x804F34AC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x804F34B0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x804F34B4: jal         0x8006B1C8
    // 0x804F34B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006B1C8(rdram, ctx);
        goto after_3;
    // 0x804F34B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
L_804F34BC:
    // 0x804F34BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x804F34C0: bnel        $s0, $s5, L_804F3454
    if (ctx->r16 != ctx->r21) {
        // 0x804F34C4: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_804F3454;
    }
    goto skip_0;
    // 0x804F34C4: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_0:
    // 0x804F34C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x804F34CC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x804F34D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x804F34D4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x804F34D8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x804F34DC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x804F34E0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x804F34E4: jr          $ra
    // 0x804F34E8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x804F34E8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_80550B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80550B5C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80550B60: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(354, 0X2CB4) << 16);
    // 0x80550B64: addiu       $t6, $t6, 0x37D4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(354, 0X2CB4));
    // 0x80550B68: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80550B6C: jr          $ra
    // 0x80550B70: sw          $t6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r14;
    return;
    // 0x80550B70: sw          $t6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8004613C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004613C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80046140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80046144: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80046148: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004614C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80046150: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80046154: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80046158: jal         0x80046118
    // 0x8004615C: lhu         $a0, 0x20($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X20);
    func_80046118(rdram, ctx);
        goto after_0;
    // 0x8004615C: lhu         $a0, 0x20($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X20);
    after_0:
    // 0x80046160: bne         $v0, $zero, L_80046170
    if (ctx->r2 != 0) {
        // 0x80046164: nop
    
            goto L_80046170;
    }
    // 0x80046164: nop

    // 0x80046168: b           L_800461E4
    // 0x8004616C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800461E4;
    // 0x8004616C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046170:
    // 0x80046170: jal         0x80045B2C
    // 0x80046174: nop

    func_80045B2C(rdram, ctx);
        goto after_1;
    // 0x80046174: nop

    after_1:
    // 0x80046178: bne         $v0, $zero, L_80046188
    if (ctx->r2 != 0) {
        // 0x8004617C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80046188;
    }
    // 0x8004617C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80046180: b           L_800461E4
    // 0x80046184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800461E4;
    // 0x80046184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046188:
    // 0x80046188: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004618C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80046190: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80046194: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80046198: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8004619C: jal         0x80046014
    // 0x800461A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046014(rdram, ctx);
        goto after_2;
    // 0x800461A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800461A4: bne         $v0, $zero, L_800461BC
    if (ctx->r2 != 0) {
        // 0x800461A8: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800461BC;
    }
    // 0x800461A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800461AC: jal         0x80045BD8
    // 0x800461B0: nop

    func_80045BD8(rdram, ctx);
        goto after_3;
    // 0x800461B0: nop

    after_3:
    // 0x800461B4: b           L_800461E4
    // 0x800461B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800461E4;
    // 0x800461B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800461BC:
    // 0x800461BC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800461C0: addiu       $t7, $t7, 0x5BD8
    ctx->r15 = ADD32(ctx->r15, 0X5BD8);
    // 0x800461C4: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x800461C8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800461CC: lw          $t8, 0x6EB8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6EB8);
    // 0x800461D0: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x800461D4: addiu       $t9, $t9, 0x5284
    ctx->r25 = ADD32(ctx->r25, 0X5284);
    // 0x800461D8: bne         $t8, $zero, L_800461E4
    if (ctx->r24 != 0) {
        // 0x800461DC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800461E4;
    }
    // 0x800461DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800461E0: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
L_800461E4:
    // 0x800461E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800461E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800461EC: jr          $ra
    // 0x800461F0: nop

    return;
    // 0x800461F0: nop

;}
RECOMP_FUNC void func_805CA59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA59C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CA5A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CA5A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805CA5A8: jal         0x80045A34
    // 0x805CA5AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805CA5AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x805CA5B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805CA5B4: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x805CA5B8: bne         $v0, $zero, L_805CA5C8
    if (ctx->r2 != 0) {
        // 0x805CA5BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805CA5C8;
    }
    // 0x805CA5BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CA5C0: b           L_805CA5CC
    // 0x805CA5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805CA5CC;
    // 0x805CA5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805CA5C8:
    // 0x805CA5C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805CA5CC:
    // 0x805CA5CC: jr          $ra
    // 0x805CA5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805CA5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80039970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039978: jal         0x8004700C
    // 0x8003997C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003997C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80039980: lbu         $a0, 0x18($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X18);
    // 0x80039984: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80039988: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8003998C: xori        $v1, $a0, 0x8
    ctx->r3 = ctx->r4 ^ 0X8;
    // 0x80039990: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80039994: beql        $v1, $zero, L_800399A8
    if (ctx->r3 == 0) {
        // 0x80039998: sb          $zero, 0x165($a3)
        MEM_B(0X165, ctx->r7) = 0;
            goto L_800399A8;
    }
    goto skip_0;
    // 0x80039998: sb          $zero, 0x165($a3)
    MEM_B(0X165, ctx->r7) = 0;
    skip_0:
    // 0x8003999C: xori        $v1, $a0, 0x68
    ctx->r3 = ctx->r4 ^ 0X68;
    // 0x800399A0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800399A4: sb          $zero, 0x165($a3)
    MEM_B(0X165, ctx->r7) = 0;
L_800399A8:
    // 0x800399A8: sw          $zero, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = 0;
    // 0x800399AC: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x800399B0: lbu         $a1, -0x1404($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1404);
    // 0x800399B4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800399B8: jal         0x8003994C
    // 0x800399BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8003994C(rdram, ctx);
        goto after_1;
    // 0x800399BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x800399C0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800399C4: lw          $v0, 0x180($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X180);
    // 0x800399C8: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x800399CC: lw          $a1, 0x34($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X34);
    // 0x800399D0: jal         0x80067D5C
    // 0x800399D4: lw          $a2, 0x38($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x800399D4: lw          $a2, 0x38($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X38);
    after_2:
    // 0x800399D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800399DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800399E0: jal         0x80067838
    // 0x800399E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x800399E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x800399E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800399EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800399F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800399F4: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x800399F8: jr          $ra
    // 0x800399FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800399FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80027488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027488: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002748C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80027490: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80027494: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80027498: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002749C: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x800274A0: addiu       $a2, $zero, 0x89
    ctx->r6 = ADD32(0, 0X89);
    // 0x800274A4: jal         0x80024680
    // 0x800274A8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x800274A8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_0:
    // 0x800274AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800274B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800274B4: jr          $ra
    // 0x800274B8: nop

    return;
    // 0x800274B8: nop

;}
RECOMP_FUNC void func_80079118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079118: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007911C: jr          $ra
    // 0x80079120: nop

    return;
    // 0x80079120: nop

;}
RECOMP_FUNC void func_80453F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453F10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80453F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453F18: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453F1C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80453F20: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80453F24: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80453F28: lw          $t6, 0x6D10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D10);
    // 0x80453F2C: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x80453F30: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80453F34: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80453F38: lhu         $v1, 0xC($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0XC);
    // 0x80453F3C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80453F40: andi        $t8, $v1, 0x1000
    ctx->r24 = ctx->r3 & 0X1000;
    // 0x80453F44: beq         $t8, $at, L_80453F58
    if (ctx->r24 == ctx->r1) {
        // 0x80453F48: andi        $t9, $v1, 0x8000
        ctx->r25 = ctx->r3 & 0X8000;
            goto L_80453F58;
    }
    // 0x80453F48: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x80453F4C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80453F50: bnel        $t9, $at, L_80453FE4
    if (ctx->r25 != ctx->r1) {
        // 0x80453F54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80453FE4;
    }
    goto skip_0;
    // 0x80453F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80453F58:
    // 0x80453F58: bne         $t0, $zero, L_80453F78
    if (ctx->r8 != 0) {
        // 0x80453F5C: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_80453F78;
    }
    // 0x80453F5C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80453F60: jal         0x8044459C
    // 0x80453F64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8044459C(rdram, ctx);
        goto after_0;
    // 0x80453F64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80453F68: jal         0x80453CFC
    // 0x80453F6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80453CFC(rdram, ctx);
        goto after_1;
    // 0x80453F6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80453F70: b           L_80453FCC
    // 0x80453F74: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80453FCC;
    // 0x80453F74: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80453F78:
    // 0x80453F78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80453F7C: bne         $t1, $at, L_80453F9C
    if (ctx->r9 != ctx->r1) {
        // 0x80453F80: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_80453F9C;
    }
    // 0x80453F80: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80453F84: jal         0x80444840
    // 0x80453F88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80444840(rdram, ctx);
        goto after_2;
    // 0x80453F88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80453F8C: jal         0x80453BDC
    // 0x80453F90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80453BDC(rdram, ctx);
        goto after_3;
    // 0x80453F90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80453F94: b           L_80453FCC
    // 0x80453F98: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80453FCC;
    // 0x80453F98: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80453F9C:
    // 0x80453F9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80453FA0: bne         $t2, $at, L_80453FC0
    if (ctx->r10 != ctx->r1) {
        // 0x80453FA4: nop
    
            goto L_80453FC0;
    }
    // 0x80453FA4: nop

    // 0x80453FA8: jal         0x80444890
    // 0x80453FAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80444890(rdram, ctx);
        goto after_4;
    // 0x80453FAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_4:
    // 0x80453FB0: jal         0x80453EB0
    // 0x80453FB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80453EB0(rdram, ctx);
        goto after_5;
    // 0x80453FB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80453FB8: b           L_80453FCC
    // 0x80453FBC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80453FCC;
    // 0x80453FBC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80453FC0:
    // 0x80453FC0: jal         0x80453D64
    // 0x80453FC4: nop

    func_80453D64(rdram, ctx);
        goto after_6;
    // 0x80453FC4: nop

    after_6:
    // 0x80453FC8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80453FCC:
    // 0x80453FCC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80453FD0: jal         0x804459A4
    // 0x80453FD4: sb          $t3, -0x71F5($at)
    MEM_B(-0X71F5, ctx->r1) = ctx->r11;
    func_804459A4(rdram, ctx);
        goto after_7;
    // 0x80453FD4: sb          $t3, -0x71F5($at)
    MEM_B(-0X71F5, ctx->r1) = ctx->r11;
    after_7:
    // 0x80453FD8: jal         0x80445C04
    // 0x80453FDC: nop

    func_80445C04(rdram, ctx);
        goto after_8;
    // 0x80453FDC: nop

    after_8:
    // 0x80453FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453FE4:
    // 0x80453FE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80453FE8: jr          $ra
    // 0x80453FEC: nop

    return;
    // 0x80453FEC: nop

;}
RECOMP_FUNC void func_8001B004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B004: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B008: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001B00C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001B010: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001B014: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001B018: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001B01C: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8001B020: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001B024: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001B028: addiu       $s3, $s3, 0x660
    ctx->r19 = ADD32(ctx->r19, 0X660);
    // 0x8001B02C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001B030: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001B034: addiu       $s4, $zero, 0x48
    ctx->r20 = ADD32(0, 0X48);
    // 0x8001B038: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_8001B03C:
    // 0x8001B03C: multu       $s1, $s4
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B040: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B044: addu        $s0, $s3, $t6
    ctx->r16 = ADD32(ctx->r19, ctx->r14);
    // 0x8001B048: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x8001B04C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8001B050: beq         $at, $zero, L_8001B0F0
    if (ctx->r1 == 0) {
        // 0x8001B054: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8001B0F0;
    }
    // 0x8001B054: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001B058: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B05C: addu        $at, $at, $t7
    gpr jr_addend_8001B064 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001B060: lw          $t7, -0x5F4($at)
    ctx->r15 = ADD32(ctx->r1, -0X5F4);
    // 0x8001B064: jr          $t7
    // 0x8001B068: nop

    switch (jr_addend_8001B064 >> 2) {
        case 0: goto L_8001B0F0; break;
        case 1: goto L_8001B06C; break;
        case 2: goto L_8001B094; break;
        case 3: goto L_8001B0C0; break;
        case 4: goto L_8001B0D8; break;
        default: switch_error(__func__, 0x8001B064, 0x800AFA0C);
    }
    // 0x8001B068: nop

L_8001B06C:
    // 0x8001B06C: jal         0x8001B3AC
    // 0x8001B070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001B3AC(rdram, ctx);
        goto after_0;
    // 0x8001B070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001B074: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8001B078: bltz        $v0, L_8001B0F0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001B07C: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8001B0F0;
    }
    // 0x8001B07C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001B080: sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    // 0x8001B084: jal         0x8001B200
    // 0x8001B088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001B200(rdram, ctx);
        goto after_1;
    // 0x8001B088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001B08C: b           L_8001B0F0
    // 0x8001B090: nop

        goto L_8001B0F0;
    // 0x8001B090: nop

L_8001B094:
    // 0x8001B094: jal         0x8001B618
    // 0x8001B098: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_8001B618(rdram, ctx);
        goto after_2;
    // 0x8001B098: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
    // 0x8001B09C: bne         $v0, $zero, L_8001B0F0
    if (ctx->r2 != 0) {
        // 0x8001B0A0: nop
    
            goto L_8001B0F0;
    }
    // 0x8001B0A0: nop

    // 0x8001B0A4: lbu         $t8, 0x3C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3C);
    // 0x8001B0A8: beq         $s2, $t8, L_8001B0F0
    if (ctx->r18 == ctx->r24) {
        // 0x8001B0AC: nop
    
            goto L_8001B0F0;
    }
    // 0x8001B0AC: nop

    // 0x8001B0B0: jal         0x8001B23C
    // 0x8001B0B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001B23C(rdram, ctx);
        goto after_3;
    // 0x8001B0B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8001B0B8: b           L_8001B0F0
    // 0x8001B0BC: nop

        goto L_8001B0F0;
    // 0x8001B0BC: nop

L_8001B0C0:
    // 0x8001B0C0: jal         0x8001B618
    // 0x8001B0C4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_8001B618(rdram, ctx);
        goto after_4;
    // 0x8001B0C4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_4:
    // 0x8001B0C8: bne         $s2, $v0, L_8001B0F0
    if (ctx->r18 != ctx->r2) {
        // 0x8001B0CC: nop
    
            goto L_8001B0F0;
    }
    // 0x8001B0CC: nop

    // 0x8001B0D0: b           L_8001B0F0
    // 0x8001B0D4: sw          $s5, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r21;
        goto L_8001B0F0;
    // 0x8001B0D4: sw          $s5, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r21;
L_8001B0D8:
    // 0x8001B0D8: jal         0x8001B618
    // 0x8001B0DC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_8001B618(rdram, ctx);
        goto after_5;
    // 0x8001B0DC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_5:
    // 0x8001B0E0: bne         $v0, $zero, L_8001B0F0
    if (ctx->r2 != 0) {
        // 0x8001B0E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001B0F0;
    }
    // 0x8001B0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001B0E8: jal         0x80019C4C
    // 0x8001B0EC: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    func_80019C4C(rdram, ctx);
        goto after_6;
    // 0x8001B0EC: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    after_6:
L_8001B0F0:
    // 0x8001B0F0: jal         0x8001BB04
    // 0x8001B0F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001BB04(rdram, ctx);
        goto after_7;
    // 0x8001B0F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8001B0F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001B0FC: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8001B100: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8001B104: slti        $at, $s1, 0x32
    ctx->r1 = SIGNED(ctx->r17) < 0X32 ? 1 : 0;
    // 0x8001B108: bne         $at, $zero, L_8001B03C
    if (ctx->r1 != 0) {
        // 0x8001B10C: nop
    
            goto L_8001B03C;
    }
    // 0x8001B10C: nop

    // 0x8001B110: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001B114: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001B118: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001B11C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B120: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001B124: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001B128: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001B12C: jr          $ra
    // 0x8001B130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001B130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001B134: nop

    // 0x8001B138: nop

    // 0x8001B13C: nop

;}
RECOMP_FUNC void func_806E83E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E83E0: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(667, 0X1644) << 16);
    // 0x806E83E4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x806E83E8: lbu         $t6, -0x670C($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(667, 0X1644));
    // 0x806E83EC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16B0) << 16);
    // 0x806E83F0: lwc1        $f8, -0x66A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16B0));
    // 0x806E83F4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806E83F8: nop

    // 0x806E83FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806E8400: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806E8404: jr          $ra
    // 0x806E8408: nop

    return;
    // 0x806E8408: nop

;}
RECOMP_FUNC void func_80452C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452C70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452C74: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452C78: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80452C7C: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80452C80: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452C84: ori         $at, $at, 0x6D64
    ctx->r1 = ctx->r1 | 0X6D64;
    // 0x80452C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80452C8C: jal         0x80452A64
    // 0x80452C90: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_80452A64(rdram, ctx);
        goto after_0;
    // 0x80452C90: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_0:
    // 0x80452C94: bne         $v0, $zero, L_80452CAC
    if (ctx->r2 != 0) {
        // 0x80452C98: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80452CAC;
    }
    // 0x80452C98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80452C9C: jal         0x80452A14
    // 0x80452CA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80452A14(rdram, ctx);
        goto after_1;
    // 0x80452CA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80452CA4: b           L_80452CB8
    // 0x80452CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452CB8;
    // 0x80452CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452CAC:
    // 0x80452CAC: jal         0x804526D8
    // 0x80452CB0: nop

    func_804526D8(rdram, ctx);
        goto after_2;
    // 0x80452CB0: nop

    after_2:
    // 0x80452CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452CB8:
    // 0x80452CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452CBC: jr          $ra
    // 0x80452CC0: nop

    return;
    // 0x80452CC0: nop

;}
RECOMP_FUNC void func_8003E070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E070: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003E074: lwc1        $f14, 0x234($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X234);
    // 0x8003E078: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8003E07C: lwc1        $f12, 0x78($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003E080: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8003E084: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8003E088: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8003E08C: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8003E090: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8003E094: nop

    // 0x8003E098: bc1fl       L_8003E0AC
    if (!c1cs) {
        // 0x8003E09C: lwc1        $f12, 0x7C($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
            goto L_8003E0AC;
    }
    goto skip_0;
    // 0x8003E09C: lwc1        $f12, 0x7C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
    skip_0:
    // 0x8003E0A0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8003E0A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003E0A8: lwc1        $f12, 0x7C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
L_8003E0AC:
    // 0x8003E0AC: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8003E0B0: nop

    // 0x8003E0B4: bc1fl       L_8003E0C8
    if (!c1cs) {
        // 0x8003E0B8: swc1        $f0, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
            goto L_8003E0C8;
    }
    goto skip_1;
    // 0x8003E0B8: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x8003E0BC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8003E0C0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003E0C4: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
L_8003E0C8:
    // 0x8003E0C8: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x8003E0CC: jr          $ra
    // 0x8003E0D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8003E0D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8057FB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057FB28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057FB2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057FB30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057FB34: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x8057FB38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057FB3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8057FB40: bne         $v0, $zero, L_8057FB6C
    if (ctx->r2 != 0) {
        // 0x8057FB44: nop
    
            goto L_8057FB6C;
    }
    // 0x8057FB44: nop

    // 0x8057FB48: jal         0x8057F6F4
    // 0x8057FB4C: nop

    func_8057F6F4(rdram, ctx);
        goto after_0;
    // 0x8057FB4C: nop

    after_0:
    // 0x8057FB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FB54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057FB58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8057FB5C: jal         0x805802D8
    // 0x8057FB60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805802D8(rdram, ctx);
        goto after_1;
    // 0x8057FB60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8057FB64: b           L_8057FB98
    // 0x8057FB68: nop

        goto L_8057FB98;
    // 0x8057FB68: nop

L_8057FB6C:
    // 0x8057FB6C: bne         $v0, $at, L_8057FB98
    if (ctx->r2 != ctx->r1) {
        // 0x8057FB70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8057FB98;
    }
    // 0x8057FB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FB74: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8057FB78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057FB7C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8057FB80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057FB84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8057FB88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8057FB8C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8057FB90: jal         0x805802D8
    // 0x8057FB94: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    func_805802D8(rdram, ctx);
        goto after_2;
    // 0x8057FB94: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    after_2:
L_8057FB98:
    // 0x8057FB98: jal         0x8057FA74
    // 0x8057FB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057FA74(rdram, ctx);
        goto after_3;
    // 0x8057FB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8057FBA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8057FBA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057FBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FBAC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8057FBB0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8057FBB4: jal         0x8057F7CC
    // 0x8057FBB8: nop

    func_8057F7CC(rdram, ctx);
        goto after_4;
    // 0x8057FBB8: nop

    after_4:
    // 0x8057FBBC: jal         0x8057F810
    // 0x8057FBC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F810(rdram, ctx);
        goto after_5;
    // 0x8057FBC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8057FBC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057FBC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057FBCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057FBD0: jr          $ra
    // 0x8057FBD4: nop

    return;
    // 0x8057FBD4: nop

;}
RECOMP_FUNC void func_80425130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425130: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80425134: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80425138: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8042513C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80425140: jal         0x80424F94
    // 0x80425144: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80424F94(rdram, ctx);
        goto after_0;
    // 0x80425144: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80425148: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8042514C: lw          $a1, 0xF4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XF4);
    // 0x80425150: lw          $a2, 0xF8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XF8);
    // 0x80425154: lw          $a3, 0xE4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE4);
    // 0x80425158: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x8042515C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80425160: jal         0x80424824
    // 0x80425164: addiu       $a0, $s0, 0xA0
    ctx->r4 = ADD32(ctx->r16, 0XA0);
    func_80424824(rdram, ctx);
        goto after_1;
    // 0x80425164: addiu       $a0, $s0, 0xA0
    ctx->r4 = ADD32(ctx->r16, 0XA0);
    after_1:
    // 0x80425168: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36E8) << 16);
    // 0x8042516C: lwc1        $f6, 0x60E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36E8));
    // 0x80425170: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80425174: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80425178: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8042517C: swc1        $f8, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f8.u32l;
    // 0x80425180: lwc1        $f10, 0xE4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80425184: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80425188: nop

    // 0x8042518C: bc1fl       L_804251C4
    if (!c1cs) {
        // 0x80425190: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804251C4;
    }
    goto skip_0;
    // 0x80425190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80425194: jal         0x800653D8
    // 0x80425198: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x80425198: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x8042519C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x804251A0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x804251A4: mfhi        $t8
    ctx->r24 = hi;
    // 0x804251A8: sw          $t8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->r24;
    // 0x804251AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804251B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804251B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804251B8: jal         0x80425408
    // 0x804251BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80425408(rdram, ctx);
        goto after_3;
    // 0x804251BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x804251C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804251C4:
    // 0x804251C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804251C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804251CC: jr          $ra
    // 0x804251D0: nop

    return;
    // 0x804251D0: nop

;}
RECOMP_FUNC void func_804EF400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF408: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804EF40C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804EF410: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804EF414: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x804EF418: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804EF41C: sltiu       $at, $v1, 0x96
    ctx->r1 = ctx->r3 < 0X96 ? 1 : 0;
    // 0x804EF420: bne         $at, $zero, L_804EF458
    if (ctx->r1 != 0) {
        // 0x804EF424: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_804EF458;
    }
    // 0x804EF424: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x804EF428: jal         0x804EF5A0
    // 0x804EF42C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EF5A0(rdram, ctx);
        goto after_0;
    // 0x804EF42C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EF430: jal         0x804EEF8C
    // 0x804EF434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804EEF8C(rdram, ctx);
        goto after_1;
    // 0x804EF434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804EF438: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804EF43C: jal         0x80067E78
    // 0x804EF440: lw          $a0, 0x34($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X34);
    func_80067E78(rdram, ctx);
        goto after_2;
    // 0x804EF440: lw          $a0, 0x34($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X34);
    after_2:
    // 0x804EF444: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x804EF448: jal         0x80067818
    // 0x804EF44C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x804EF44C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x804EF450: b           L_804EF460
    // 0x804EF454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804EF460;
    // 0x804EF454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EF458:
    // 0x804EF458: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804EF45C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EF460:
    // 0x804EF460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF464: jr          $ra
    // 0x804EF468: nop

    return;
    // 0x804EF468: nop

;}
RECOMP_FUNC void func_8069E3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069E3E0: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8069E3E4: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(577, 0X910) << 16);
    // 0x8069E3E8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8069E3EC: lh          $t7, -0x1320($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(577, 0X910));
    // 0x8069E3F0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8069E3F4: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(577, 0X91C) << 16);
    // 0x8069E3F8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8069E3FC: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
    // 0x8069E400: lw          $v0, -0x1314($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(577, 0X91C));
    // 0x8069E404: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x8069E408: jr          $ra
    // 0x8069E40C: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
    return;
    // 0x8069E40C: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80465FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80465FA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80465FAC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80465FB0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80465FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465FB8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80465FBC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80465FC0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80465FC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80465FC8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80465FCC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80465FD0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80465FD4: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(125, 0X1DE0) << 16);
    // 0x80465FD8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80465FDC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80465FE0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80465FE4: lw          $t2, 0x63B0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(125, 0X1DE0));
    // 0x80465FE8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80465FEC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80465FF0: jal         0x8046549C
    // 0x80465FF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046549C(rdram, ctx);
        goto after_0;
    // 0x80465FF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80465FF8: jal         0x80465424
    // 0x80465FFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80465424(rdram, ctx);
        goto after_1;
    // 0x80465FFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80466000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80466004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80466008: jr          $ra
    // 0x8046600C: nop

    return;
    // 0x8046600C: nop

;}
RECOMP_FUNC void func_80735C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80735C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80735C3C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80735C40: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(736, 0X3920) << 16);
    // 0x80735C44: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80735C48: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80735C4C: addiu       $t6, $t6, -0x6C80
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(736, 0X3920));
    // 0x80735C50: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80735C54: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80735C58: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80735C5C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80735C60: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x80735C64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80735C68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80735C6C: jal         0x80735C84
    // 0x80735C70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80735C84(rdram, ctx);
        goto after_0;
    // 0x80735C70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80735C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80735C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80735C7C: jr          $ra
    // 0x80735C80: nop

    return;
    // 0x80735C80: nop

;}
RECOMP_FUNC void func_805338E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805338E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805338E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805338EC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805338F0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805338F4: lui         $t7, 0x8053
    ctx->r15 = S32(RELOC_HI16(345, 0X1850) << 16);
    // 0x805338F8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805338FC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80533900: addiu       $t7, $t7, 0x4320
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(345, 0X1850));
    // 0x80533904: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80533908: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8053390C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80533910: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80533914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80533918: jal         0x80533878
    // 0x8053391C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80533878(rdram, ctx);
        goto after_0;
    // 0x8053391C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80533920: jal         0x80533840
    // 0x80533924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80533840(rdram, ctx);
        goto after_1;
    // 0x80533924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80533928: bne         $v0, $zero, L_80533940
    if (ctx->r2 != 0) {
        // 0x8053392C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80533940;
    }
    // 0x8053392C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80533930: jal         0x800445A4
    // 0x80533934: nop

    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80533934: nop

    after_2:
    // 0x80533938: b           L_80533974
    // 0x8053393C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80533974;
    // 0x8053393C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80533940:
    // 0x80533940: lw          $t9, 0x180($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X180);
    // 0x80533944: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80533948: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8053394C: beq         $t9, $zero, L_80533958
    if (ctx->r25 == 0) {
        // 0x80533950: lui         $t1, 0x8053
        ctx->r9 = S32(RELOC_HI16(345, 0X12C) << 16);
            goto L_80533958;
    }
    // 0x80533950: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(345, 0X12C) << 16);
    // 0x80533954: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
L_80533958:
    // 0x80533958: addiu       $t1, $t1, 0x2BFC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(345, 0X12C));
    // 0x8053395C: sh          $t0, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r8;
    // 0x80533960: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80533964: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80533968: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8053396C: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x80533970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80533974:
    // 0x80533974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80533978: jr          $ra
    // 0x8053397C: nop

    return;
    // 0x8053397C: nop

;}
RECOMP_FUNC void func_80445B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445B9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445BA4: jal         0x800677F8
    // 0x80445BA8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80445BA8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_0:
    // 0x80445BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445BB4: jr          $ra
    // 0x80445BB8: nop

    return;
    // 0x80445BB8: nop

;}
RECOMP_FUNC void func_80579CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80579CD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80579CDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80579CE0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80579CE4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80579CE8: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80579CEC: lui         $t0, 0x8058
    ctx->r8 = S32(RELOC_HI16(384, 0X270) << 16);
    // 0x80579CF0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80579CF4: lbu         $t6, 0x34($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X34);
    // 0x80579CF8: addiu       $t0, $t0, -0x6350
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(384, 0X270));
    // 0x80579CFC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80579D00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80579D04: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80579D08: lw          $a3, 0x38($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X38);
    // 0x80579D0C: lui         $t2, 0x8058
    ctx->r10 = S32(RELOC_HI16(384, 0X1AC0) << 16);
    // 0x80579D10: sh          $t9, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r25;
    // 0x80579D14: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x80579D18: sb          $t1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r9;
    // 0x80579D1C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80579D20: addiu       $t2, $t2, -0x4B00
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(384, 0X1AC0));
    // 0x80579D24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80579D28: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80579D2C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80579D30: jal         0x80579A90
    // 0x80579D34: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80579A90(rdram, ctx);
        goto after_0;
    // 0x80579D34: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80579D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80579D3C: jal         0x80045A34
    // 0x80579D40: addiu       $a1, $zero, 0x490
    ctx->r5 = ADD32(0, 0X490);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80579D40: addiu       $a1, $zero, 0x490
    ctx->r5 = ADD32(0, 0X490);
    after_1:
    // 0x80579D44: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80579D48: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80579D4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80579D50: addiu       $a1, $zero, 0x490
    ctx->r5 = ADD32(0, 0X490);
    // 0x80579D54: jal         0x80065728
    // 0x80579D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80579D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80579D5C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80579D60: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80579D64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80579D68: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80579D6C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80579D70: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1AF4) << 16);
    // 0x80579D74: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x80579D78: lwc1        $f0, -0x4ACC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1AF4));
    // 0x80579D7C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80579D80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80579D84: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80579D88: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80579D8C: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x80579D90: lh          $t3, 0x18($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X18);
    // 0x80579D94: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80579D98: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x80579D9C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80579DA0: nop

    // 0x80579DA4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80579DA8: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x80579DAC: lh          $t5, 0x20($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X20);
    // 0x80579DB0: beq         $a0, $a1, L_80579E1C
    if (ctx->r4 == ctx->r5) {
        // 0x80579DB4: sra         $t6, $t5, 2
        ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
            goto L_80579E1C;
    }
    // 0x80579DB4: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
L_80579DB8:
    // 0x80579DB8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80579DBC: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80579DC0: swc1        $f2, 0x228($v0)
    MEM_W(0X228, ctx->r2) = ctx->f2.u32l;
    // 0x80579DC4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80579DC8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80579DCC: swc1        $f12, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->f12.u32l;
    // 0x80579DD0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80579DD4: addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // 0x80579DD8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80579DDC: swc1        $f18, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f18.u32l;
    // 0x80579DE0: lwc1        $f18, 0xC0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x80579DE4: swc1        $f16, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f16.u32l;
    // 0x80579DE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80579DEC: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80579DF0: swc1        $f18, 0x1AC($v0)
    MEM_W(0X1AC, ctx->r2) = ctx->f18.u32l;
    // 0x80579DF4: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x80579DF8: lh          $t3, 0x18($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X18);
    // 0x80579DFC: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x80579E00: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80579E04: nop

    // 0x80579E08: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80579E0C: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x80579E10: lh          $t5, 0x20($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X20);
    // 0x80579E14: bne         $a0, $a1, L_80579DB8
    if (ctx->r4 != ctx->r5) {
        // 0x80579E18: sra         $t6, $t5, 2
        ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
            goto L_80579DB8;
    }
    // 0x80579E18: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
L_80579E1C:
    // 0x80579E1C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80579E20: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80579E24: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80579E28: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80579E2C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80579E30: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80579E34: swc1        $f2, 0x224($v0)
    MEM_W(0X224, ctx->r2) = ctx->f2.u32l;
    // 0x80579E38: swc1        $f12, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->f12.u32l;
    // 0x80579E3C: addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // 0x80579E40: swc1        $f18, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f18.u32l;
    // 0x80579E44: lwc1        $f18, 0xBC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x80579E48: swc1        $f16, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->f16.u32l;
    // 0x80579E4C: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80579E50: swc1        $f18, 0x1AC($v0)
    MEM_W(0X1AC, ctx->r2) = ctx->f18.u32l;
    // 0x80579E54: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80579E58: lw          $a2, -0x7638($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7638);
    // 0x80579E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80579E60: jal         0x80579F18
    // 0x80579E64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80579F18(rdram, ctx);
        goto after_3;
    // 0x80579E64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80579E68: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80579E6C: sw          $t7, 0x48C($s1)
    MEM_W(0X48C, ctx->r17) = ctx->r15;
    // 0x80579E70: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80579E74: lw          $t8, -0x7640($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7640);
    // 0x80579E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80579E7C: beq         $t8, $zero, L_80579E9C
    if (ctx->r24 == 0) {
        // 0x80579E80: nop
    
            goto L_80579E9C;
    }
    // 0x80579E80: nop

    // 0x80579E84: jal         0x8057B444
    // 0x80579E88: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8057B444(rdram, ctx);
        goto after_4;
    // 0x80579E88: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80579E8C: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80579E90: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80579E94: b           L_80579EB8
    // 0x80579E98: sw          $zero, 0xB20($s1)
    MEM_W(0XB20, ctx->r17) = 0;
        goto L_80579EB8;
    // 0x80579E98: sw          $zero, 0xB20($s1)
    MEM_W(0XB20, ctx->r17) = 0;
L_80579E9C:
    // 0x80579E9C: jal         0x80579AF4
    // 0x80579EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80579AF4(rdram, ctx);
        goto after_5;
    // 0x80579EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80579EA4: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80579EA8: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80579EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80579EB0: jal         0x8057B444
    // 0x80579EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8057B444(rdram, ctx);
        goto after_6;
    // 0x80579EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_80579EB8:
    // 0x80579EB8: lbu         $t9, 0x2($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X2);
    // 0x80579EBC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80579EC0: lui         $a0, 0x4739
    ctx->r4 = S32(0X4739 << 16);
    // 0x80579EC4: bne         $t9, $at, L_80579EEC
    if (ctx->r25 != ctx->r1) {
        // 0x80579EC8: ori         $a0, $a0, 0x2200
        ctx->r4 = ctx->r4 | 0X2200;
            goto L_80579EEC;
    }
    // 0x80579EC8: ori         $a0, $a0, 0x2200
    ctx->r4 = ctx->r4 | 0X2200;
    // 0x80579ECC: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x80579ED0: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80579ED4: jal         0x8004613C
    // 0x80579ED8: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x80579ED8: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    after_7:
    // 0x80579EDC: jal         0x80044194
    // 0x80579EE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80044194(rdram, ctx);
        goto after_8;
    // 0x80579EE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80579EE4: b           L_80579F08
    // 0x80579EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80579F08;
    // 0x80579EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80579EEC:
    // 0x80579EEC: lw          $t0, 0xA68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XA68);
    // 0x80579EF0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80579EF4: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80579EF8: lw          $t9, 0xB0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XB0);
    // 0x80579EFC: jalr        $t9
    // 0x80579F00: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80579F00: nop

    after_9:
    // 0x80579F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80579F08:
    // 0x80579F08: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80579F0C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80579F10: jr          $ra
    // 0x80579F14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80579F14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805A5FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5FF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A5FF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A5FFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A6000: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A6004: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A6008: jal         0x805A5DF0
    // 0x805A600C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_805A5DF0(rdram, ctx);
        goto after_0;
    // 0x805A600C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x805A6010: beq         $v0, $zero, L_805A6084
    if (ctx->r2 == 0) {
        // 0x805A6014: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_805A6084;
    }
    // 0x805A6014: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x805A6018: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x805A601C: lbu         $t6, 0x7EA5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7EA5);
    // 0x805A6020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A6024: bnel        $t6, $zero, L_805A603C
    if (ctx->r14 != 0) {
        // 0x805A6028: lw          $t7, 0x264($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X264);
            goto L_805A603C;
    }
    goto skip_0;
    // 0x805A6028: lw          $t7, 0x264($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X264);
    skip_0:
    // 0x805A602C: jal         0x805A5508
    // 0x805A6030: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_805A5508(rdram, ctx);
        goto after_1;
    // 0x805A6030: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x805A6034: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x805A6038: lw          $t7, 0x264($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X264);
L_805A603C:
    // 0x805A603C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x805A6040: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805A6044: beq         $t7, $zero, L_805A607C
    if (ctx->r15 == 0) {
        // 0x805A6048: nop
    
            goto L_805A607C;
    }
    // 0x805A6048: nop

    // 0x805A604C: jal         0x805A5C3C
    // 0x805A6050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A5C3C(rdram, ctx);
        goto after_2;
    // 0x805A6050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A6054: beq         $v0, $zero, L_805A6084
    if (ctx->r2 == 0) {
        // 0x805A6058: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A6084;
    }
    // 0x805A6058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A605C: jal         0x805A6730
    // 0x805A6060: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_805A6730(rdram, ctx);
        goto after_3;
    // 0x805A6060: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x805A6064: jal         0x8005FC5C
    // 0x805A6068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FC5C(rdram, ctx);
        goto after_4;
    // 0x805A6068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A606C: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x805A6070: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805A6074: b           L_805A6084
    // 0x805A6078: sb          $zero, 0x75($t9)
    MEM_B(0X75, ctx->r25) = 0;
        goto L_805A6084;
    // 0x805A6078: sb          $zero, 0x75($t9)
    MEM_B(0X75, ctx->r25) = 0;
L_805A607C:
    // 0x805A607C: jal         0x8005D87C
    // 0x805A6080: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005D87C(rdram, ctx);
        goto after_5;
    // 0x805A6080: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_805A6084:
    // 0x805A6084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A6088: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A608C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A6090: jr          $ra
    // 0x805A6094: nop

    return;
    // 0x805A6094: nop

;}
RECOMP_FUNC void func_8057A6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057A6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057A6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057A6FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057A700: sw          $zero, 0x488($v0)
    MEM_W(0X488, ctx->r2) = 0;
    // 0x8057A704: sw          $zero, 0x484($v0)
    MEM_W(0X484, ctx->r2) = 0;
    // 0x8057A708: jal         0x8057A6CC
    // 0x8057A70C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057A6CC(rdram, ctx);
        goto after_0;
    // 0x8057A70C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057A710: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8057A714: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057A718: lbu         $t6, -0x7634($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7634);
    // 0x8057A71C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8057A720: jal         0x8057B444
    // 0x8057A724: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_8057B444(rdram, ctx);
        goto after_1;
    // 0x8057A724: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_1:
    // 0x8057A728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057A72C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057A730: jr          $ra
    // 0x8057A734: nop

    return;
    // 0x8057A734: nop

;}
RECOMP_FUNC void func_80031368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031368: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003136C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031370: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80031374: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031378: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003137C: jal         0x800310A0
    // 0x80031380: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031380: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031388: jal         0x80030E14
    // 0x8003138C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80030E14(rdram, ctx);
        goto after_1;
    // 0x8003138C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80031390: beql        $v0, $zero, L_800313D0
    if (ctx->r2 == 0) {
        // 0x80031394: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800313D0;
    }
    goto skip_0;
    // 0x80031394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80031398: jal         0x80028220
    // 0x8003139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_2;
    // 0x8003139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800313A0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800313A4: sw          $v0, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->r2;
    // 0x800313A8: jal         0x80065954
    // 0x800313AC: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x800313AC: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_3:
    // 0x800313B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800313B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800313B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800313BC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800313C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800313C4: jal         0x80041214
    // 0x800313C8: nop

    func_80041214(rdram, ctx);
        goto after_4;
    // 0x800313C8: nop

    after_4:
    // 0x800313CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800313D0:
    // 0x800313D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800313D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800313D8: jr          $ra
    // 0x800313DC: nop

    return;
    // 0x800313DC: nop

;}
RECOMP_FUNC void func_8078F7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F7C0: addiu       $t6, $zero, 0x190
    ctx->r14 = ADD32(0, 0X190);
    // 0x8078F7C4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8078F7C8: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8078F7CC: jr          $ra
    // 0x8078F7D0: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    return;
    // 0x8078F7D0: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_807A9D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9D84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807A9D88: addiu       $v0, $a0, 0x84
    ctx->r2 = ADD32(ctx->r4, 0X84);
    // 0x807A9D8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807A9D90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_807A9D94:
    // 0x807A9D94: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807A9D98: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x807A9D9C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807A9DA0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x807A9DA4: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x807A9DA8: swc1        $f0, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
    // 0x807A9DAC: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x807A9DB0: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x807A9DB4: swc1        $f0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f0.u32l;
    // 0x807A9DB8: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x807A9DBC: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x807A9DC0: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807A9DC4: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x807A9DC8: bne         $v1, $a1, L_807A9D94
    if (ctx->r3 != ctx->r5) {
        // 0x807A9DCC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_807A9D94;
    }
    // 0x807A9DCC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x807A9DD0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x807A9DD4: beq         $at, $zero, L_807A9DF8
    if (ctx->r1 == 0) {
        // 0x807A9DD8: add.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_807A9DF8;
    }
    // 0x807A9DD8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_807A9DDC:
    // 0x807A9DDC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807A9DE0: lwc1        $f10, 0xC4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x807A9DE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x807A9DE8: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x807A9DEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x807A9DF0: bne         $at, $zero, L_807A9DDC
    if (ctx->r1 != 0) {
        // 0x807A9DF4: add.s       $f0, $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
            goto L_807A9DDC;
    }
    // 0x807A9DF4: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_807A9DF8:
    // 0x807A9DF8: jr          $ra
    // 0x807A9DFC: nop

    return;
    // 0x807A9DFC: nop

;}
RECOMP_FUNC void func_8006EB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006EB94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EB98: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8006EB9C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8006EBA0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006EBA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006EBA8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8006EBAC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8006EBB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006EBB4: lwc1        $f10, 0x1184($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1184);
    // 0x8006EBB8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8006EBBC: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8006EBC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006EBC4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006EBC8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006EBCC: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8006EBD0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8006EBD4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8006EBD8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8006EBDC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8006EBE0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8006EBE4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8006EBE8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8006EBEC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006EBF0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006EBF4: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8006EBF8: jalr        $t9
    // 0x8006EBFC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8006EBFC: nop

    after_0:
    // 0x8006EC00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EC04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8006EC08: jr          $ra
    // 0x8006EC0C: nop

    return;
    // 0x8006EC0C: nop

;}
RECOMP_FUNC void func_8041E430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E430: lh          $t8, 0xC($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XC);
    // 0x8041E434: lh          $t2, 0x144($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X144);
    // 0x8041E438: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8041E43C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8041E440: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(29, 0X3010) << 16);
    // 0x8041E444: lui         $t1, 0x8042
    ctx->r9 = S32(RELOC_HI16(29, 0X3290) << 16);
    // 0x8041E448: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8041E44C: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x8041E450: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8041E454: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8041E458: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8041E45C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8041E460: addiu       $t7, $t7, 0x670
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(29, 0X3010));
    // 0x8041E464: addiu       $t1, $t1, 0x8F0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(29, 0X3290));
    // 0x8041E468: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8041E46C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8041E470: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8041E474: addu        $a3, $t9, $t1
    ctx->r7 = ADD32(ctx->r25, ctx->r9);
    // 0x8041E478: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8041E47C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8041E480: sh          $t2, 0x144($t3)
    MEM_H(0X144, ctx->r11) = ctx->r10;
L_8041E484:
    // 0x8041E484: lw          $t4, 0x138($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X138);
    // 0x8041E488: beql        $t4, $zero, L_8041E4C0
    if (ctx->r12 == 0) {
        // 0x8041E48C: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_8041E4C0;
    }
    goto skip_0;
    // 0x8041E48C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8041E490: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8041E494: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8041E498: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8041E49C: nop

    // 0x8041E4A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8041E4A4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8041E4A8: swc1        $f8, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f8.u32l;
    // 0x8041E4AC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8041E4B0: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8041E4B4: b           L_8041E4F0
    // 0x8041E4B8: swc1        $f10, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f10.u32l;
        goto L_8041E4F0;
    // 0x8041E4B8: swc1        $f10, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f10.u32l;
    // 0x8041E4BC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_8041E4C0:
    // 0x8041E4C0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8041E4C4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8041E4C8: nop

    // 0x8041E4CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8041E4D0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8041E4D4: nop

    // 0x8041E4D8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8041E4DC: swc1        $f6, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f6.u32l;
    // 0x8041E4E0: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8041E4E4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8041E4E8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8041E4EC: swc1        $f10, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f10.u32l;
L_8041E4F0:
    // 0x8041E4F0: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8041E4F4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8041E4F8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8041E4FC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8041E500: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8041E504: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8041E508: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8041E50C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8041E510: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8041E514: swc1        $f4, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f4.u32l;
    // 0x8041E518: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x8041E51C: lwc1        $f6, -0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X4);
    // 0x8041E520: swc1        $f6, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f6.u32l;
    // 0x8041E524: lwc1        $f8, -0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8041E528: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x8041E52C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8041E530: swc1        $f10, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f10.u32l;
    // 0x8041E534: lwc1        $f16, -0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8041E538: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x8041E53C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8041E540: swc1        $f18, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f18.u32l;
    // 0x8041E544: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x8041E548: lw          $t7, -0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X4);
    // 0x8041E54C: lw          $t1, -0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, -0X4);
    // 0x8041E550: xor         $t9, $t7, $t8
    ctx->r25 = ctx->r15 ^ ctx->r24;
    // 0x8041E554: bne         $t0, $a1, L_8041E484
    if (ctx->r8 != ctx->r5) {
        // 0x8041E558: sw          $t9, 0x138($t1)
        MEM_W(0X138, ctx->r9) = ctx->r25;
            goto L_8041E484;
    }
    // 0x8041E558: sw          $t9, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->r25;
    // 0x8041E55C: jr          $ra
    // 0x8041E560: nop

    return;
    // 0x8041E560: nop

;}
RECOMP_FUNC void func_8073EB74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EB74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073EB78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EB7C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8073EB80: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(748, 0X236C) << 16);
    // 0x8073EB84: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8073EB88: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8073EB8C: addiu       $t6, $t6, 0xB5C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(748, 0X236C));
    // 0x8073EB90: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073EB94: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8073EB98: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8073EB9C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8073EBA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073EBA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073EBA8: jal         0x8073EBC0
    // 0x8073EBAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8073EBC0(rdram, ctx);
        goto after_0;
    // 0x8073EBAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8073EBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073EBB8: jr          $ra
    // 0x8073EBBC: nop

    return;
    // 0x8073EBBC: nop

;}
RECOMP_FUNC void func_804E9B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E9B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E9B84: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804E9B88: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804E9B8C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804E9B90: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(264, 0X7E4) << 16);
    // 0x804E9B94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804E9B98: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804E9B9C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804E9BA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804E9BA4: lw          $t8, -0x5EAC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(264, 0X7E4));
    // 0x804E9BA8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804E9BAC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804E9BB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804E9BB4: jal         0x80048490
    // 0x804E9BB8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804E9BB8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804E9BBC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804E9BC0: jal         0x80048378
    // 0x804E9BC4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804E9BC4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804E9BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E9BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E9BD0: jr          $ra
    // 0x804E9BD4: nop

    return;
    // 0x804E9BD4: nop

;}
RECOMP_FUNC void func_8000A9CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A9CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8000A9D0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000A9D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000A9D8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000A9DC: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8000A9E0: addiu       $t7, $t7, 0x4D10
    ctx->r15 = ADD32(ctx->r15, 0X4D10);
    // 0x8000A9E4: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8000A9E8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8000A9EC: lw          $t8, 0x2A30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2A30);
    // 0x8000A9F0: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8000A9F4: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8000A9F8: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x8000A9FC: beql        $t9, $zero, L_8000AA18
    if (ctx->r25 == 0) {
        // 0x8000AA00: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000AA18;
    }
    goto skip_0;
    // 0x8000AA00: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x8000AA04: lw          $a0, 0x2A64($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X2A64);
    // 0x8000AA08: addu        $t2, $a0, $a2
    ctx->r10 = ADD32(ctx->r4, ctx->r6);
    // 0x8000AA0C: jr          $ra
    // 0x8000AA10: lb          $v0, 0xCC($t2)
    ctx->r2 = MEM_B(ctx->r10, 0XCC);
    return;
    // 0x8000AA10: lb          $v0, 0xCC($t2)
    ctx->r2 = MEM_B(ctx->r10, 0XCC);
    // 0x8000AA14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000AA18:
    // 0x8000AA18: jr          $ra
    // 0x8000AA1C: nop

    return;
    // 0x8000AA1C: nop

;}
RECOMP_FUNC void func_800662B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800662BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800662C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800662C4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800662C8: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x800662CC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800662D0: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x800662D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800662D8: bc1t        L_800663E4
    if (c1cs) {
        // 0x800662DC: addu        $a0, $a0, $t7
        ctx->r4 = ADD32(ctx->r4, ctx->r15);
            goto L_800663E4;
    }
    // 0x800662DC: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800662E0: sll         $t8, $a3, 4
    ctx->r24 = S32(ctx->r7 << 4);
    // 0x800662E4: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x800662E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800662EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800662F0: jal         0x80066DE4
    // 0x800662F4: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x800662F4: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800662F8: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800662FC: jal         0x80066E88
    // 0x80066300: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80066300: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80066304: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80066308: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8006630C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80066310: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80066314: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80066318: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8006631C: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80066320: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80066324: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80066328: nop

    // 0x8006632C: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80066330: nop

    // 0x80066334: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80066338: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006633C: swc1        $f10, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80066340: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80066344: lwc1        $f12, -0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, -0X8);
    // 0x80066348: swc1        $f4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f4.u32l;
    // 0x8006634C: lwc1        $f2, -0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X8);
    // 0x80066350: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80066354: nop

    // 0x80066358: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8006635C: nop

    // 0x80066360: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80066364: nop

    // 0x80066368: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8006636C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80066370: swc1        $f10, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80066374: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80066378: lwc1        $f12, -0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, -0X4);
    // 0x8006637C: swc1        $f4, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f4.u32l;
    // 0x80066380: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80066384: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80066388: nop

    // 0x8006638C: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80066390: nop

    // 0x80066394: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80066398: nop

    // 0x8006639C: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800663A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800663A4: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800663A8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800663AC: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800663B0: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800663B4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800663B8: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800663BC: nop

    // 0x800663C0: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800663C4: nop

    // 0x800663C8: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800663CC: nop

    // 0x800663D0: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800663D4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800663D8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800663DC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800663E0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_800663E4:
    // 0x800663E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800663E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800663EC: jr          $ra
    // 0x800663F0: nop

    return;
    // 0x800663F0: nop

;}
RECOMP_FUNC void cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void func_80742468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742468: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8074246C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742470: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80742474: lui         $at, 0x8076
    ctx->r1 = S32(RELOC_HI16(754, 0X1C374) << 16);
    // 0x80742478: lwc1        $f2, -0x1A4C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(754, 0X1C374));
    // 0x8074247C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80742480: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80742484: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80742488: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8074248C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80742490: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80742494: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80742498: addiu       $t8, $zero, 0xAC8
    ctx->r24 = ADD32(0, 0XAC8);
    // 0x8074249C: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x807424A0: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x807424A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x807424A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807424AC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x807424B0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x807424B4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x807424B8: jal         0x8074224C
    // 0x807424BC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8074224C(rdram, ctx);
        goto after_0;
    // 0x807424BC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x807424C0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x807424C4: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x807424C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807424CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807424D0: jr          $ra
    // 0x807424D4: nop

    return;
    // 0x807424D4: nop

;}
RECOMP_FUNC void func_8001C100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C100: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8001C104: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8001C108: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C10C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C110: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8001C114: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8001C118: jal         0x8006E444
    // 0x8001C11C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8006E444(rdram, ctx);
        goto after_0;
    // 0x8001C11C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001C120: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C124: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001C128: lbu         $t8, 0x165($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X165);
    // 0x8001C12C: bnel        $t8, $zero, L_8001C13C
    if (ctx->r24 != 0) {
        // 0x8001C130: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001C13C;
    }
    goto skip_0;
    // 0x8001C130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001C134: sb          $t9, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r25;
    // 0x8001C138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001C13C:
    // 0x8001C13C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001C140: jr          $ra
    // 0x8001C144: nop

    return;
    // 0x8001C144: nop

;}
RECOMP_FUNC void func_800309C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800309C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800309C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800309CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800309D0: lw          $v1, 0x1C4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C4);
    // 0x800309D4: bne         $v1, $zero, L_80030A50
    if (ctx->r3 != 0) {
        // 0x800309D8: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_80030A50;
    }
    // 0x800309D8: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x800309DC: lbu         $t6, 0x12C8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12C8);
    // 0x800309E0: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800309E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800309E8: subu        $v1, $t7, $t6
    ctx->r3 = SUB32(ctx->r15, ctx->r14);
    // 0x800309EC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800309F0: beq         $v1, $zero, L_80030A40
    if (ctx->r3 == 0) {
        // 0x800309F4: nop
    
            goto L_80030A40;
    }
    // 0x800309F4: nop

    // 0x800309F8: lwc1        $f0, -0x18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X18);
    // 0x800309FC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80030A00: addiu       $a1, $a0, 0x84
    ctx->r5 = ADD32(ctx->r4, 0X84);
    // 0x80030A04: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80030A08: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80030A0C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80030A10: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80030A14: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80030A18: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80030A1C: lwc1        $f16, 0x74($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80030A20: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80030A24: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80030A28: jal         0x80040860
    // 0x80030A2C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_80040860(rdram, ctx);
        goto after_0;
    // 0x80030A2C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80030A30: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80030A34: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80030A38: b           L_80030A54
    // 0x80030A3C: sw          $t8, 0x1C4($v0)
    MEM_W(0X1C4, ctx->r2) = ctx->r24;
        goto L_80030A54;
    // 0x80030A3C: sw          $t8, 0x1C4($v0)
    MEM_W(0X1C4, ctx->r2) = ctx->r24;
L_80030A40:
    // 0x80030A40: jal         0x8002E6FC
    // 0x80030A44: nop

    func_8002E6FC(rdram, ctx);
        goto after_1;
    // 0x80030A44: nop

    after_1:
    // 0x80030A48: b           L_80030A58
    // 0x80030A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80030A58;
    // 0x80030A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80030A50:
    // 0x80030A50: sw          $t9, 0x1C4($v0)
    MEM_W(0X1C4, ctx->r2) = ctx->r25;
L_80030A54:
    // 0x80030A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80030A58:
    // 0x80030A58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80030A5C: jr          $ra
    // 0x80030A60: nop

    return;
    // 0x80030A60: nop

;}
RECOMP_FUNC void func_807B4E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4E00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B4E04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B4E08: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x807B4E0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B4E10: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x807B4E14: jal         0x807B49A0
    // 0x807B4E18: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_807B49A0(rdram, ctx);
        goto after_0;
    // 0x807B4E18: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B4E1C: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2CFC) << 16);
    // 0x807B4E20: addiu       $t6, $zero, 0x120
    ctx->r14 = ADD32(0, 0X120);
    // 0x807B4E24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807B4E28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807B4E2C: addiu       $a1, $a1, 0x74FC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2CFC));
    // 0x807B4E30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B4E34: jal         0x807B4850
    // 0x807B4E38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4850(rdram, ctx);
        goto after_1;
    // 0x807B4E38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807B4E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B4E40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B4E44: jr          $ra
    // 0x807B4E48: nop

    return;
    // 0x807B4E48: nop

;}
RECOMP_FUNC void func_8040C600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C600: lui         $v0, 0x8041
    ctx->r2 = S32(RELOC_HI16(20, 0X10) << 16);
    // 0x8040C604: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8040C608: jr          $ra
    // 0x8040C60C: addiu       $v0, $v0, -0x39F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(20, 0X10));
    return;
    // 0x8040C60C: addiu       $v0, $v0, -0x39F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(20, 0X10));
;}
RECOMP_FUNC void func_805ABCAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABCAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805ABCB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805ABCB4: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x805ABCB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ABCBC: lw          $t6, 0x264($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X264);
    // 0x805ABCC0: beq         $t6, $zero, L_805ABCF4
    if (ctx->r14 == 0) {
        // 0x805ABCC4: nop
    
            goto L_805ABCF4;
    }
    // 0x805ABCC4: nop

    // 0x805ABCC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ABCCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805ABCD0: jal         0x805AC088
    // 0x805ABCD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AC088(rdram, ctx);
        goto after_0;
    // 0x805ABCD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805ABCD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805ABCDC: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(438, 0X58C) << 16);
    // 0x805ABCE0: lwc1        $f0, -0x3EE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X58C));
    // 0x805ABCE4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805ABCE8: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805ABCEC: b           L_805ABCFC
    // 0x805ABCF0: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
        goto L_805ABCFC;
    // 0x805ABCF0: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
L_805ABCF4:
    // 0x805ABCF4: jal         0x8005D87C
    // 0x805ABCF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8005D87C(rdram, ctx);
        goto after_1;
    // 0x805ABCF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_805ABCFC:
    // 0x805ABCFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805ABD00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805ABD04: jr          $ra
    // 0x805ABD08: nop

    return;
    // 0x805ABD08: nop

;}
RECOMP_FUNC void func_80408118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408118: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040811C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80408120: jal         0x8004700C
    // 0x80408124: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80408124: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80408128: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8040812C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80408130: beq         $v0, $zero, L_8040814C
    if (ctx->r2 == 0) {
        // 0x80408134: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_8040814C;
    }
    // 0x80408134: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80408138: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8040813C: jal         0x80407D10
    // 0x80408140: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80407D10(rdram, ctx);
        goto after_1;
    // 0x80408140: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80408144: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80408148: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_8040814C:
    // 0x8040814C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80408150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80408154: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80408158: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x8040815C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80408160: bne         $t7, $zero, L_80408174
    if (ctx->r15 != 0) {
        // 0x80408164: nop
    
            goto L_80408174;
    }
    // 0x80408164: nop

    // 0x80408168: jal         0x8040818C
    // 0x8040816C: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    func_8040818C(rdram, ctx);
        goto after_2;
    // 0x8040816C: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    after_2:
    // 0x80408170: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80408174:
    // 0x80408174: jal         0x8040A470
    // 0x80408178: nop

    func_8040A470(rdram, ctx);
        goto after_3;
    // 0x80408178: nop

    after_3:
    // 0x8040817C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80408180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80408184: jr          $ra
    // 0x80408188: nop

    return;
    // 0x80408188: nop

;}
RECOMP_FUNC void func_8006B1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B1C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006B1CC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006B1D0: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8006B1D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006B1D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006B1DC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8006B1E0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8006B1E4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006B1E8: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x8006B1EC: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x8006B1F0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8006B1F4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B1F8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8006B1FC: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8006B200: addiu       $a1, $sp, 0x26
    ctx->r5 = ADD32(ctx->r29, 0X26);
    // 0x8006B204: lw          $v1, 0x1B0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X1B0);
    // 0x8006B208: lw          $a0, 0x20($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X20);
    // 0x8006B20C: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x8006B210: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x8006B214: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8006B218: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8006B21C: jal         0x8006AB7C
    // 0x8006B220: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8006AB7C(rdram, ctx);
        goto after_0;
    // 0x8006B220: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006B224: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006B228: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8006B22C: beq         $v0, $at, L_8006B270
    if (ctx->r2 == ctx->r1) {
        // 0x8006B230: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8006B270;
    }
    // 0x8006B230: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006B234: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x8006B238: lh          $t8, 0x24($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X24);
    // 0x8006B23C: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8006B240: lh          $t7, 0x16($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X16);
    // 0x8006B244: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x8006B248: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8006B24C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B250: lhu         $t1, 0x3A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X3A);
    // 0x8006B254: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8006B258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B25C: mflo        $t9
    ctx->r25 = lo;
    // 0x8006B260: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8006B264: addu        $t3, $t5, $t0
    ctx->r11 = ADD32(ctx->r13, ctx->r8);
    // 0x8006B268: b           L_8006B274
    // 0x8006B26C: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
        goto L_8006B274;
    // 0x8006B26C: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
L_8006B270:
    // 0x8006B270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006B274:
    // 0x8006B274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B278: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006B27C: jr          $ra
    // 0x8006B280: nop

    return;
    // 0x8006B280: nop

;}
RECOMP_FUNC void func_804757B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804757B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804757B4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804757B8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804757BC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804757C0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804757C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804757C8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804757CC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804757D0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804757D4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804757D8: jr          $ra
    // 0x804757DC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804757DC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800318C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800318C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800318C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800318C8: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x800318CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800318D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800318D4: bne         $v0, $zero, L_800318F4
    if (ctx->r2 != 0) {
        // 0x800318D8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800318F4;
    }
    // 0x800318D8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800318DC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800318E0: sw          $t6, -0x7644($at)
    MEM_W(-0X7644, ctx->r1) = ctx->r14;
    // 0x800318E4: jal         0x80030B7C
    // 0x800318E8: addiu       $a1, $a1, -0x17A8
    ctx->r5 = ADD32(ctx->r5, -0X17A8);
    func_80030B7C(rdram, ctx);
        goto after_0;
    // 0x800318E8: addiu       $a1, $a1, -0x17A8
    ctx->r5 = ADD32(ctx->r5, -0X17A8);
    after_0:
    // 0x800318EC: b           L_800318FC
    // 0x800318F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800318FC;
    // 0x800318F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800318F4:
    // 0x800318F4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x800318F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800318FC:
    // 0x800318FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031900: jr          $ra
    // 0x80031904: nop

    return;
    // 0x80031904: nop

;}
RECOMP_FUNC void func_807A9C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9C80: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807A9C84: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(853, 0X760) << 16);
    // 0x807A9C88: addiu       $t6, $t6, -0x5C60
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(853, 0X760));
    // 0x807A9C8C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807A9C90: jr          $ra
    // 0x807A9C94: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x807A9C94: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804611DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804611DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804611E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804611E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804611E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x804611EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x804611F0: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804611F4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x804611F8: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x804611FC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A00) << 16);
    // 0x80461200: lwc1        $f6, 0x3F90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A00));
    // 0x80461204: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80461208: lb          $t7, 0x2($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X2);
    // 0x8046120C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A04) << 16);
    // 0x80461210: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80461214: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80461218: bc1f        L_80461244
    if (!c1cs) {
        // 0x8046121C: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80461244;
    }
    // 0x8046121C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80461220: lwc1        $f8, 0x3F94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A04));
    // 0x80461224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80461228: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8046122C: nop

    // 0x80461230: bc1fl       L_80461248
    if (!c1cs) {
        // 0x80461234: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80461248;
    }
    goto skip_0;
    // 0x80461234: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_0:
    // 0x80461238: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8046123C: b           L_80461250
    // 0x80461240: nop

        goto L_80461250;
    // 0x80461240: nop

L_80461244:
    // 0x80461244: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_80461248:
    // 0x80461248: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8046124C: nop

L_80461250:
    // 0x80461250: mul.s       $f18, $f12, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80461254: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80461258: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8046125C: sub.s       $f0, $f14, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80461260: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80461264: nop

    // 0x80461268: bc1fl       L_80461320
    if (!c1cs) {
        // 0x8046126C: lwc1        $f0, 0xC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80461320;
    }
    goto skip_1;
    // 0x8046126C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x80461270: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80461274: jal         0x804610D4
    // 0x80461278: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    func_804610D4(rdram, ctx);
        goto after_0;
    // 0x80461278: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8046127C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80461280: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80461284: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80461288: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8046128C: nop

    // 0x80461290: bc1fl       L_804612D8
    if (!c1cs) {
        // 0x80461294: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_804612D8;
    }
    goto skip_2;
    // 0x80461294: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_2:
    // 0x80461298: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8046129C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x804612A0: jal         0x8008D250
    // 0x804612A4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x804612A4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x804612A8: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804612AC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804612B0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x804612B4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x804612B8: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804612BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804612C0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x804612C4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804612C8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804612CC: b           L_8046131C
    // 0x804612D0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8046131C;
    // 0x804612D0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x804612D4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_804612D8:
    // 0x804612D8: nop

    // 0x804612DC: bc1fl       L_80461320
    if (!c1cs) {
        // 0x804612E0: lwc1        $f0, 0xC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80461320;
    }
    goto skip_3;
    // 0x804612E0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    skip_3:
    // 0x804612E4: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x804612E8: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x804612EC: jal         0x8008D250
    // 0x804612F0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    fcos(rdram, ctx);
        goto after_2;
    // 0x804612F0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x804612F4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804612F8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x804612FC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80461300: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80461304: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80461308: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8046130C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80461310: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80461314: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80461318: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8046131C:
    // 0x8046131C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
L_80461320:
    // 0x80461320: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A08) << 16);
    // 0x80461324: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80461328: nop

    // 0x8046132C: bc1f        L_8046133C
    if (!c1cs) {
        // 0x80461330: nop
    
            goto L_8046133C;
    }
    // 0x80461330: nop

    // 0x80461334: b           L_80461354
    // 0x80461338: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
        goto L_80461354;
    // 0x80461338: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
L_8046133C:
    // 0x8046133C: lwc1        $f2, 0x3F98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A08));
    // 0x80461340: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80461344: nop

    // 0x80461348: bc1fl       L_80461358
    if (!c1cs) {
        // 0x8046134C: swc1        $f14, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f14.u32l;
            goto L_80461358;
    }
    goto skip_4;
    // 0x8046134C: swc1        $f14, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f14.u32l;
    skip_4:
    // 0x80461350: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
L_80461354:
    // 0x80461354: swc1        $f14, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f14.u32l;
L_80461358:
    // 0x80461358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046135C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80461360: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80461364: jr          $ra
    // 0x80461368: nop

    return;
    // 0x80461368: nop

;}
RECOMP_FUNC void func_804F4374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F4378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F437C: jal         0x8004700C
    // 0x804F4380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804F4380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804F4384: beq         $v0, $zero, L_804F43AC
    if (ctx->r2 == 0) {
        // 0x804F4388: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804F43AC;
    }
    // 0x804F4388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F438C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804F4390: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x804F4394: lwc1        $f4, 0x84($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X84);
    // 0x804F4398: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804F439C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804F43A0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x804F43A4: b           L_804F43B0
    // 0x804F43A8: nop

        goto L_804F43B0;
    // 0x804F43A8: nop

L_804F43AC:
    // 0x804F43AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804F43B0:
    // 0x804F43B0: jr          $ra
    // 0x804F43B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804F43B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002DB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DB14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DB1C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DB20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DB24: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8002DB28: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002DB2C: lbu         $t8, 0x154($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X154);
    // 0x8002DB30: bne         $t8, $zero, L_8002DB50
    if (ctx->r24 != 0) {
        // 0x8002DB34: nop
    
            goto L_8002DB50;
    }
    // 0x8002DB34: nop

    // 0x8002DB38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DB3C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8002DB40: jal         0x8002B9E4
    // 0x8002DB44: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002DB44: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8002DB48: b           L_8002DB60
    // 0x8002DB4C: nop

        goto L_8002DB60;
    // 0x8002DB4C: nop

L_8002DB50:
    // 0x8002DB50: jal         0x8002B9E4
    // 0x8002DB54: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_1;
    // 0x8002DB54: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002DB58: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DB5C: sb          $zero, 0x1AD($t9)
    MEM_B(0X1AD, ctx->r25) = 0;
L_8002DB60:
    // 0x8002DB60: jal         0x8002DAF0
    // 0x8002DB64: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8002DAF0(rdram, ctx);
        goto after_2;
    // 0x8002DB64: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8002DB68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DB6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DB70: jr          $ra
    // 0x8002DB74: nop

    return;
    // 0x8002DB74: nop

;}
RECOMP_FUNC void func_8077FDF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FDF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077FDF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077FDFC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8077FE00: lw          $t6, 0x264($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X264);
    // 0x8077FE04: beq         $t6, $zero, L_8077FE34
    if (ctx->r14 == 0) {
        // 0x8077FE08: nop
    
            goto L_8077FE34;
    }
    // 0x8077FE08: nop

    // 0x8077FE0C: jal         0x8077FB48
    // 0x8077FE10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8077FB48(rdram, ctx);
        goto after_0;
    // 0x8077FE10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8077FE14: beq         $v0, $zero, L_8077FE3C
    if (ctx->r2 == 0) {
        // 0x8077FE18: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8077FE3C;
    }
    // 0x8077FE18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8077FE1C: jal         0x80044658
    // 0x8077FE20: nop

    func_80044658(rdram, ctx);
        goto after_1;
    // 0x8077FE20: nop

    after_1:
    // 0x8077FE24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8077FE28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8077FE2C: b           L_8077FE3C
    // 0x8077FE30: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
        goto L_8077FE3C;
    // 0x8077FE30: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
L_8077FE34:
    // 0x8077FE34: jal         0x8005D83C
    // 0x8077FE38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8005D83C(rdram, ctx);
        goto after_2;
    // 0x8077FE38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_8077FE3C:
    // 0x8077FE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077FE40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8077FE44: jr          $ra
    // 0x8077FE48: nop

    return;
    // 0x8077FE48: nop

;}
RECOMP_FUNC void func_805236D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805236D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805236D8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805236DC: lw          $t6, -0x72D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72D8);
    // 0x805236E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805236E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805236E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805236EC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x805236F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805236F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805236F8: bne         $t7, $at, L_80523710
    if (ctx->r15 != ctx->r1) {
        // 0x805236FC: addiu       $a1, $zero, 0x24
        ctx->r5 = ADD32(0, 0X24);
            goto L_80523710;
    }
    // 0x805236FC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80523700: jal         0x800447C8
    // 0x80523704: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80523704: nop

    after_0:
    // 0x80523708: b           L_80523820
    // 0x8052370C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80523820;
    // 0x8052370C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80523710:
    // 0x80523710: jal         0x80045A34
    // 0x80523714: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80523714: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80523718: bne         $v0, $zero, L_80523730
    if (ctx->r2 != 0) {
        // 0x8052371C: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_80523730;
    }
    // 0x8052371C: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x80523720: jal         0x800445A4
    // 0x80523724: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80523724: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80523728: b           L_80523820
    // 0x8052372C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80523820;
    // 0x8052372C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80523730:
    // 0x80523730: lw          $t0, 0x16C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X16C);
    // 0x80523734: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80523738: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(321, 0X1E3C) << 16);
    // 0x8052373C: sb          $t8, 0x165($s1)
    MEM_B(0X165, ctx->r17) = ctx->r24;
    // 0x80523740: addiu       $t9, $t9, 0x40EC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(321, 0X1E3C));
    // 0x80523744: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80523748: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x8052374C: jal         0x80522ABC
    // 0x80523750: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80522ABC(rdram, ctx);
        goto after_3;
    // 0x80523750: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80523754: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x80523758: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8052375C: sw          $t1, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->r9;
    // 0x80523760: sw          $zero, 0x130($s1)
    MEM_W(0X130, ctx->r17) = 0;
    // 0x80523764: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80523768: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8052376C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80523770: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80523774: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80523778: addiu       $a0, $zero, 0x4146
    ctx->r4 = ADD32(0, 0X4146);
    // 0x8052377C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80523780: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80523784: jal         0x80047090
    // 0x80523788: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x80523788: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x8052378C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80523790: lui         $at, 0x4146
    ctx->r1 = S32(0X4146 << 16);
    // 0x80523794: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80523798: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x8052379C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805237A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805237A4: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x805237A8: jal         0x8004613C
    // 0x805237AC: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x805237AC: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_5:
    // 0x805237B0: bne         $v0, $zero, L_805237C8
    if (ctx->r2 != 0) {
        // 0x805237B4: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_805237C8;
    }
    // 0x805237B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x805237B8: jal         0x800445A4
    // 0x805237BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x805237BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x805237C0: b           L_80523820
    // 0x805237C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80523820;
    // 0x805237C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805237C8:
    // 0x805237C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805237CC: jal         0x80047F9C
    // 0x805237D0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x805237D0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x805237D4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x805237D8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x805237DC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x805237E0: sb          $t2, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = ctx->r10;
    // 0x805237E4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x805237E8: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X1EB0) << 16);
    // 0x805237EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805237F0: sb          $t4, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r12;
    // 0x805237F4: lwc1        $f8, 0x4160($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(321, 0X1EB0));
    // 0x805237F8: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X1EB4) << 16);
    // 0x805237FC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80523800: swc1        $f8, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f8.u32l;
    // 0x80523804: lwc1        $f10, 0x4164($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(321, 0X1EB4));
    // 0x80523808: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8052380C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80523810: swc1        $f10, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f10.u32l;
    // 0x80523814: jal         0x80523830
    // 0x80523818: swc1        $f16, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f16.u32l;
    func_80523830(rdram, ctx);
        goto after_8;
    // 0x80523818: swc1        $f16, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f16.u32l;
    after_8:
    // 0x8052381C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80523820:
    // 0x80523820: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80523824: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80523828: jr          $ra
    // 0x8052382C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8052382C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805D8018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D8018: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805D801C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D8020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D8024: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x805D8028: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805D802C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805D8030: lbu         $t6, 0x10($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X10);
    // 0x805D8034: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D8038: bnel        $t6, $at, L_805D8070
    if (ctx->r14 != ctx->r1) {
        // 0x805D803C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805D8070;
    }
    goto skip_0;
    // 0x805D803C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x805D8040: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x805D8044: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805D8048: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805D804C: nop

    // 0x805D8050: bc1fl       L_805D80D0
    if (!c1cs) {
        // 0x805D8054: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D80D0;
    }
    goto skip_1;
    // 0x805D8054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805D8058: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805D805C: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x805D8060: swc1        $f2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f2.u32l;
    // 0x805D8064: b           L_805D80CC
    // 0x805D8068: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
        goto L_805D80CC;
    // 0x805D8068: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
    // 0x805D806C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805D8070:
    // 0x805D8070: jal         0x80049D74
    // 0x805D8074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x805D8074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x805D8078: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805D807C: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x805D8080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D8084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D8088: jal         0x8004D150
    // 0x805D808C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x805D808C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_1:
    // 0x805D8090: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x805D8094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D8098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D809C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805D80A0: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x805D80A4: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x805D80A8: lbu         $t0, 0x2C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2C);
    // 0x805D80AC: beql        $t0, $zero, L_805D80D0
    if (ctx->r8 == 0) {
        // 0x805D80B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D80D0;
    }
    goto skip_2;
    // 0x805D80B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805D80B4: jal         0x8004D618
    // 0x805D80B8: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_2;
    // 0x805D80B8: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_2:
    // 0x805D80BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805D80C0: nop

    // 0x805D80C4: swc1        $f2, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f2.u32l;
    // 0x805D80C8: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
L_805D80CC:
    // 0x805D80CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D80D0:
    // 0x805D80D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D80D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805D80D8: jr          $ra
    // 0x805D80DC: nop

    return;
    // 0x805D80DC: nop

;}
RECOMP_FUNC void func_804E7860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7868: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804E786C: addiu       $at, $zero, 0x400E
    ctx->r1 = ADD32(0, 0X400E);
    // 0x804E7870: lui         $a0, 0x804F
    ctx->r4 = S32(RELOC_HI16(261, 0X800) << 16);
    // 0x804E7874: beq         $v0, $at, L_804E78D0
    if (ctx->r2 == ctx->r1) {
        // 0x804E7878: addiu       $a0, $a0, -0x7FA0
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(261, 0X800));
            goto L_804E78D0;
    }
    // 0x804E7878: addiu       $a0, $a0, -0x7FA0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(261, 0X800));
    // 0x804E787C: addiu       $at, $zero, 0x40EC
    ctx->r1 = ADD32(0, 0X40EC);
    // 0x804E7880: bne         $v0, $at, L_804E78D0
    if (ctx->r2 != ctx->r1) {
        // 0x804E7884: lui         $a1, 0x804F
        ctx->r5 = S32(RELOC_HI16(261, 0X810) << 16);
            goto L_804E78D0;
    }
    // 0x804E7884: lui         $a1, 0x804F
    ctx->r5 = S32(RELOC_HI16(261, 0X810) << 16);
    // 0x804E7888: lui         $a0, 0x804F
    ctx->r4 = S32(RELOC_HI16(261, 0X800) << 16);
    // 0x804E788C: addiu       $a0, $a0, -0x7FA0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(261, 0X800));
    // 0x804E7890: addiu       $a1, $a1, -0x7F90
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(261, 0X810));
    // 0x804E7894: jal         0x8004667C
    // 0x804E7898: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804E7898: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x804E789C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804E78A0: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804E78A4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x804E78A8: lui         $a2, 0x804E
    ctx->r6 = S32(RELOC_HI16(261, 0X560) << 16);
    // 0x804E78AC: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x804E78B0: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x804E78B4: bne         $t7, $zero, L_804E78C4
    if (ctx->r15 != 0) {
        // 0x804E78B8: nop
    
            goto L_804E78C4;
    }
    // 0x804E78B8: nop

    // 0x804E78BC: jal         0x80057B28
    // 0x804E78C0: addiu       $a2, $a2, 0x7DC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(261, 0X560));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804E78C0: addiu       $a2, $a2, 0x7DC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(261, 0X560));
    after_1:
L_804E78C4:
    // 0x804E78C4: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(261, 0X1C8) << 16);
    // 0x804E78C8: b           L_804E7910
    // 0x804E78CC: addiu       $v0, $v0, 0x7A28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(261, 0X1C8));
        goto L_804E7910;
    // 0x804E78CC: addiu       $v0, $v0, 0x7A28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(261, 0X1C8));
L_804E78D0:
    // 0x804E78D0: lui         $a1, 0x804F
    ctx->r5 = S32(RELOC_HI16(261, 0X810) << 16);
    // 0x804E78D4: addiu       $a1, $a1, -0x7F90
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(261, 0X810));
    // 0x804E78D8: jal         0x8004667C
    // 0x804E78DC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004667C(rdram, ctx);
        goto after_2;
    // 0x804E78DC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_2:
    // 0x804E78E0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804E78E4: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804E78E8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x804E78EC: lui         $a2, 0x804E
    ctx->r6 = S32(RELOC_HI16(261, 0X560) << 16);
    // 0x804E78F0: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x804E78F4: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x804E78F8: bne         $t9, $zero, L_804E7908
    if (ctx->r25 != 0) {
        // 0x804E78FC: nop
    
            goto L_804E7908;
    }
    // 0x804E78FC: nop

    // 0x804E7900: jal         0x80057B28
    // 0x804E7904: addiu       $a2, $a2, 0x7DC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(261, 0X560));
    func_80057B28(rdram, ctx);
        goto after_3;
    // 0x804E7904: addiu       $a2, $a2, 0x7DC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(261, 0X560));
    after_3:
L_804E7908:
    // 0x804E7908: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(261, 0X17C) << 16);
    // 0x804E790C: addiu       $v0, $v0, 0x79DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(261, 0X17C));
L_804E7910:
    // 0x804E7910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7918: jr          $ra
    // 0x804E791C: nop

    return;
    // 0x804E791C: nop

;}
RECOMP_FUNC void func_80567E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567E60: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80567E64: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80567E68: lw          $t6, 0xF10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XF10);
    // 0x80567E6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80567E70: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80567E74: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80567E78: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80567E7C: lw          $t9, 0xF14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF14);
    // 0x80567E80: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x80567E84: bne         $at, $zero, L_80567E9C
    if (ctx->r1 != 0) {
        // 0x80567E88: lui         $at, 0x8057
        ctx->r1 = S32(RELOC_HI16(378, 0X2198) << 16);
            goto L_80567E9C;
    }
    // 0x80567E88: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2198) << 16);
    // 0x80567E8C: lwc1        $f4, -0x68B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2198));
    // 0x80567E90: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80567E94: b           L_80567EBC
    // 0x80567E98: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
        goto L_80567EBC;
    // 0x80567E98: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80567E9C:
    // 0x80567E9C: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80567EA0: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X219C) << 16);
    // 0x80567EA4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80567EA8: nop

    // 0x80567EAC: bc1fl       L_80567EC0
    if (!c1cs) {
        // 0x80567EB0: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_80567EC0;
    }
    goto skip_0;
    // 0x80567EB0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_0:
    // 0x80567EB4: lwc1        $f6, -0x68B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X219C));
    // 0x80567EB8: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
L_80567EBC:
    // 0x80567EBC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_80567EC0:
    // 0x80567EC0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80567EC4: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80567EC8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80567ECC: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x80567ED0: nop

    // 0x80567ED4: bc1fl       L_80567F00
    if (!c1cs) {
        // 0x80567ED8: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80567F00;
    }
    goto skip_1;
    // 0x80567ED8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_1:
    // 0x80567EDC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80567EE0: nop

    // 0x80567EE4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80567EE8: nop

    // 0x80567EEC: bc1fl       L_80567F14
    if (!c1cs) {
        // 0x80567EF0: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80567F14;
    }
    goto skip_2;
    // 0x80567EF0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x80567EF4: b           L_80567F10
    // 0x80567EF8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80567F10;
    // 0x80567EF8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80567EFC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_80567F00:
    // 0x80567F00: nop

    // 0x80567F04: bc1fl       L_80567F14
    if (!c1cs) {
        // 0x80567F08: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80567F14;
    }
    goto skip_3;
    // 0x80567F08: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_3:
    // 0x80567F0C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80567F10:
    // 0x80567F10: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80567F14:
    // 0x80567F14: nop

    // 0x80567F18: bc1f        L_80567F24
    if (!c1cs) {
        // 0x80567F1C: nop
    
            goto L_80567F24;
    }
    // 0x80567F1C: nop

    // 0x80567F20: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80567F24:
    // 0x80567F24: jr          $ra
    // 0x80567F28: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80567F28: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8066A2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A2F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A300: jal         0x80669E80
    // 0x8066A304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80669E80(rdram, ctx);
        goto after_0;
    // 0x8066A304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A308: jal         0x80669FA4
    // 0x8066A30C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80669FA4(rdram, ctx);
        goto after_1;
    // 0x8066A30C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8066A310: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A314: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8066A318: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8066A31C: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8066A320: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8066A324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A328: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066A32C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8066A330: bc1fl       L_8066A348
    if (!c1cs) {
        // 0x8066A334: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A348;
    }
    goto skip_0;
    // 0x8066A334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A338: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8066A33C: jal         0x8066A790
    // 0x8066A340: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8066A790(rdram, ctx);
        goto after_2;
    // 0x8066A340: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x8066A344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A348:
    // 0x8066A348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A34C: jr          $ra
    // 0x8066A350: nop

    return;
    // 0x8066A350: nop

;}
RECOMP_FUNC void func_80448498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448498: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044849C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x804484A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804484A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804484A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804484AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x804484B0: bne         $a2, $zero, L_80448520
    if (ctx->r6 != 0) {
        // 0x804484B4: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_80448520;
    }
    // 0x804484B4: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x804484B8: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X13248) << 16);
    // 0x804484BC: lw          $v0, 0x7628($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(98, 0X13248));
    // 0x804484C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x804484C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x804484C8: beq         $v0, $zero, L_804484E8
    if (ctx->r2 == 0) {
        // 0x804484CC: nop
    
            goto L_804484E8;
    }
    // 0x804484CC: nop

    // 0x804484D0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x804484D4: jalr        $v0
    // 0x804484D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x804484D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804484DC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804484E0: b           L_804484E8
    // 0x804484E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_804484E8;
    // 0x804484E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_804484E8:
    // 0x804484E8: bne         $a0, $zero, L_804484F8
    if (ctx->r4 != 0) {
        // 0x804484EC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_804484F8;
    }
    // 0x804484EC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x804484F0: b           L_80448564
    // 0x804484F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80448564;
    // 0x804484F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804484F8:
    // 0x804484F8: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x804484FC: lw          $v0, 0x104($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X104);
    // 0x80448500: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80448504: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80448508: bne         $at, $zero, L_80448560
    if (ctx->r1 != 0) {
        // 0x8044850C: sw          $t9, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r25;
            goto L_80448560;
    }
    // 0x8044850C: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    // 0x80448510: jal         0x80446518
    // 0x80448514: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80446518(rdram, ctx);
        goto after_1;
    // 0x80448514: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80448518: b           L_80448564
    // 0x8044851C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80448564;
    // 0x8044851C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80448520:
    // 0x80448520: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448524: bne         $a2, $at, L_8044854C
    if (ctx->r6 != ctx->r1) {
        // 0x80448528: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8044854C;
    }
    // 0x80448528: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044852C: jal         0x804464B4
    // 0x80448530: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_804464B4(rdram, ctx);
        goto after_2;
    // 0x80448530: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80448534: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80448538: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044853C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80448540: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80448544: b           L_80448560
    // 0x80448548: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
        goto L_80448560;
    // 0x80448548: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
L_8044854C:
    // 0x8044854C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80448550: bnel        $a2, $at, L_80448564
    if (ctx->r6 != ctx->r1) {
        // 0x80448554: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80448564;
    }
    goto skip_0;
    // 0x80448554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80448558: jal         0x80446518
    // 0x8044855C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80446518(rdram, ctx);
        goto after_3;
    // 0x8044855C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
L_80448560:
    // 0x80448560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80448564:
    // 0x80448564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80448568: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044856C: jr          $ra
    // 0x80448570: nop

    return;
    // 0x80448570: nop

;}
RECOMP_FUNC void func_8007740C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007740C: addiu       $sp, $sp, -0x1C8
    ctx->r29 = ADD32(ctx->r29, -0X1C8);
    // 0x80077410: sw          $a0, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r4;
    // 0x80077414: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80077418: lw          $t6, 0x1C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C8);
    // 0x8007741C: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80077420: addiu       $t8, $t8, -0x6B48
    ctx->r24 = ADD32(ctx->r24, -0X6B48);
    // 0x80077424: addiu       $at, $t8, 0x138
    ctx->r1 = ADD32(ctx->r24, 0X138);
    // 0x80077428: addiu       $t7, $sp, 0x80
    ctx->r15 = ADD32(ctx->r29, 0X80);
    // 0x8007742C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
L_80077430:
    // 0x80077430: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80077434: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80077438: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8007743C: sw          $t6, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r14;
    // 0x80077440: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x80077444: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x80077448: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x8007744C: bne         $t8, $at, L_80077430
    if (ctx->r24 != ctx->r1) {
        // 0x80077450: sw          $t6, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r14;
            goto L_80077430;
    }
    // 0x80077450: sw          $t6, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r14;
    // 0x80077454: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80077458: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8007745C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80077460: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80077464: blez        $a1, L_80077480
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80077468: sw          $t9, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r25;
            goto L_80077480;
    }
    // 0x80077468: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8007746C: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80077470: beql        $at, $zero, L_80077484
    if (ctx->r1 == 0) {
        // 0x80077474: sw          $zero, 0x20($sp)
        MEM_W(0X20, ctx->r29) = 0;
            goto L_80077484;
    }
    goto skip_0;
    // 0x80077474: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    skip_0:
    // 0x80077478: b           L_80077484
    // 0x8007747C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
        goto L_80077484;
    // 0x8007747C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
L_80077480:
    // 0x80077480: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_80077484:
    // 0x80077484: lui         $a1, 0xE700
    ctx->r5 = S32(0XE700 << 16);
    // 0x80077488: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007748C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80077490: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077494: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80077498: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8007749C: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x800774A0: lui         $t7, 0x30
    ctx->r15 = S32(0X30 << 16);
    // 0x800774A4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800774A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800774AC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800774B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800774B4: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x800774B8: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x800774BC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800774C0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800774C4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800774C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800774CC: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x800774D0: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x800774D4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800774D8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800774DC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800774E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800774E4: bne         $a3, $at, L_80077788
    if (ctx->r7 != ctx->r1) {
        // 0x800774E8: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_80077788;
    }
    // 0x800774E8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800774EC: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800774F0: addiu       $a3, $a3, -0x7AF0
    ctx->r7 = ADD32(ctx->r7, -0X7AF0);
    // 0x800774F4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800774F8: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x800774FC: addiu       $t9, $sp, 0x80
    ctx->r25 = ADD32(ctx->r29, 0X80);
    // 0x80077500: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80077504: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80077508: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8007750C: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x80077510: lhu         $t7, 0x8($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X8);
    // 0x80077514: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x80077518: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x8007751C: subu        $t3, $t6, $t8
    ctx->r11 = SUB32(ctx->r14, ctx->r24);
    // 0x80077520: subu        $t4, $t7, $t9
    ctx->r12 = SUB32(ctx->r15, ctx->r25);
    // 0x80077524: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80077528: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    // 0x8007752C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80077530: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077534: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80077538: lui         $t8, 0xD00
    ctx->r24 = S32(0XD00 << 16);
    // 0x8007753C: addiu       $t8, $t8, 0x198
    ctx->r24 = ADD32(ctx->r24, 0X198);
    // 0x80077540: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80077544: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80077548: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8007754C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077550: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x80077554: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80077558: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x8007755C: lui         $t7, 0xF700
    ctx->r15 = S32(0XF700 << 16);
    // 0x80077560: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80077564: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80077568: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007756C: blez        $a2, L_800775AC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80077570: lui         $t5, 0xF600
        ctx->r13 = S32(0XF600 << 16);
            goto L_800775AC;
    }
    // 0x80077570: lui         $t5, 0xF600
    ctx->r13 = S32(0XF600 << 16);
    // 0x80077574: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80077578: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007757C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077580: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80077584: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077588: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8007758C: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x80077590: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80077594: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x80077598: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x8007759C: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x800775A0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800775A4: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800775A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800775AC:
    // 0x800775AC: blez        $t2, L_800775EC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800775B0: lui         $t5, 0xF600
        ctx->r13 = S32(0XF600 << 16);
            goto L_800775EC;
    }
    // 0x800775B0: lui         $t5, 0xF600
    ctx->r13 = S32(0XF600 << 16);
    // 0x800775B4: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x800775B8: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x800775BC: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x800775C0: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x800775C4: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x800775C8: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x800775CC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800775D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800775D4: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800775D8: andi        $t8, $a2, 0x3FF
    ctx->r24 = ctx->r6 & 0X3FF;
    // 0x800775DC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800775E0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800775E4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800775E8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800775EC:
    // 0x800775EC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800775F0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800775F4: lhu         $a1, 0x6($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X6);
    // 0x800775F8: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800775FC: beq         $at, $zero, L_80077648
    if (ctx->r1 == 0) {
        // 0x80077600: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80077648;
    }
    // 0x80077600: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80077604: andi        $t9, $t6, 0x3FF
    ctx->r25 = ctx->r14 & 0X3FF;
    // 0x80077608: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8007760C: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80077610: andi        $t9, $t6, 0x3FF
    ctx->r25 = ctx->r14 & 0X3FF;
    // 0x80077614: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x80077618: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007761C: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80077620: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80077624: andi        $t8, $a2, 0x3FF
    ctx->r24 = ctx->r6 & 0X3FF;
    // 0x80077628: andi        $t9, $t3, 0x3FF
    ctx->r25 = ctx->r11 & 0X3FF;
    // 0x8007762C: sll         $t7, $t9, 14
    ctx->r15 = S32(ctx->r25 << 14);
    // 0x80077630: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80077634: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80077638: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007763C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077640: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80077644: lhu         $a1, 0x6($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X6);
L_80077648:
    // 0x80077648: lhu         $t1, 0x8($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X8);
    // 0x8007764C: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x80077650: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x80077654: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80077658: beq         $at, $zero, L_80077698
    if (ctx->r1 == 0) {
        // 0x8007765C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80077698;
    }
    // 0x8007765C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80077660: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x80077664: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x80077668: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x8007766C: or          $t9, $t6, $t5
    ctx->r25 = ctx->r14 | ctx->r13;
    // 0x80077670: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80077674: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80077678: andi        $t7, $t4, 0x3FF
    ctx->r15 = ctx->r12 & 0X3FF;
    // 0x8007767C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80077680: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80077684: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077688: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007768C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80077690: lhu         $a1, 0x6($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X6);
    // 0x80077694: lhu         $t1, 0x8($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X8);
L_80077698:
    // 0x80077698: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8007769C: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x800776A0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800776A4: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x800776A8: subu        $t3, $a1, $t7
    ctx->r11 = SUB32(ctx->r5, ctx->r15);
    // 0x800776AC: subu        $t4, $t1, $t9
    ctx->r12 = SUB32(ctx->r9, ctx->r25);
    // 0x800776B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800776B4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800776B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800776BC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800776C0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800776C4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800776C8: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x800776CC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800776D0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800776D4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800776D8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800776DC: andi        $t9, $t3, 0x3FF
    ctx->r25 = ctx->r11 & 0X3FF;
    // 0x800776E0: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x800776E4: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800776E8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800776EC: andi        $t5, $a2, 0x3FF
    ctx->r13 = ctx->r6 & 0X3FF;
    // 0x800776F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800776F4: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800776F8: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x800776FC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80077700: andi        $t9, $t2, 0x3FF
    ctx->r25 = ctx->r10 & 0X3FF;
    // 0x80077704: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80077708: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007770C: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80077710: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x80077714: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80077718: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8007771C: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80077720: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80077724: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077728: andi        $v1, $t4, 0x3FF
    ctx->r3 = ctx->r12 & 0X3FF;
    // 0x8007772C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077730: or          $t7, $t0, $at
    ctx->r15 = ctx->r8 | ctx->r1;
    // 0x80077734: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80077738: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x8007773C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80077740: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80077744: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80077748: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007774C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80077750: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80077754: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80077758: or          $a2, $t8, $v1
    ctx->r6 = ctx->r24 | ctx->r3;
    // 0x8007775C: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x80077760: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80077764: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077768: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8007776C: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x80077770: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80077774: or          $t6, $t0, $v1
    ctx->r14 = ctx->r8 | ctx->r3;
    // 0x80077778: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8007777C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077780: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80077784: lui         $a1, 0xE700
    ctx->r5 = S32(0XE700 << 16);
L_80077788:
    // 0x80077788: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8007778C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80077790: lw          $v1, -0x7AF0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7AF0);
    // 0x80077794: addiu       $t9, $sp, 0x80
    ctx->r25 = ADD32(ctx->r29, 0X80);
    // 0x80077798: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x8007779C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x800777A0: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800777A4: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x800777A8: lhu         $t6, 0x6($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X6);
    // 0x800777AC: lhu         $t7, 0x8($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X8);
    // 0x800777B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800777B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800777B8: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800777BC: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x800777C0: subu        $t3, $t6, $t8
    ctx->r11 = SUB32(ctx->r14, ctx->r24);
    // 0x800777C4: subu        $t4, $t7, $t9
    ctx->r12 = SUB32(ctx->r15, ctx->r25);
    // 0x800777C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800777CC: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x800777D0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800777D4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800777D8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800777DC: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800777E0: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800777E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800777E8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800777EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800777F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800777F4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800777F8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800777FC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80077800: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80077804: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80077808: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007780C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80077810: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80077814: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80077818: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8007781C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80077820: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80077824: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80077828: nop

    // 0x8007782C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80077830: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80077834: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80077838: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8007783C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80077840: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80077844: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80077848: nop

    // 0x8007784C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80077850: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80077854: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80077858: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8007785C: nop

    // 0x80077860: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80077864: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80077868: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007786C: lw          $t6, 0x1C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C8);
    // 0x80077870: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80077874: jr          $ra
    // 0x80077878: addiu       $sp, $sp, 0x1C8
    ctx->r29 = ADD32(ctx->r29, 0X1C8);
    return;
    // 0x80077878: addiu       $sp, $sp, 0x1C8
    ctx->r29 = ADD32(ctx->r29, 0X1C8);
    // 0x8007787C: nop

;}
RECOMP_FUNC void func_8064A7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A7C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8064A7C4: lwc1        $f16, 0xE0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x8064A7C8: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064A7CC: lwc1        $f6, 0xEC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8064A7D0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8064A7D4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8064A7D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8064A7DC: bc1f        L_8064A808
    if (!c1cs) {
        // 0x8064A7E0: swc1        $f8, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
            goto L_8064A808;
    }
    // 0x8064A7E0: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x8064A7E4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8064A7E8: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8064A7EC: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064A7F0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8064A7F4: nop

    // 0x8064A7F8: bc1fl       L_8064A828
    if (!c1cs) {
        // 0x8064A7FC: lwc1        $f6, 0x40($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
            goto L_8064A828;
    }
    goto skip_0;
    // 0x8064A7FC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    skip_0:
    // 0x8064A800: b           L_8064A824
    // 0x8064A804: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
        goto L_8064A824;
    // 0x8064A804: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8064A808:
    // 0x8064A808: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8064A80C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064A810: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8064A814: nop

    // 0x8064A818: bc1fl       L_8064A828
    if (!c1cs) {
        // 0x8064A81C: lwc1        $f6, 0x40($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
            goto L_8064A828;
    }
    goto skip_1;
    // 0x8064A81C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    skip_1:
    // 0x8064A820: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8064A824:
    // 0x8064A824: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
L_8064A828:
    // 0x8064A828: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064A82C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8064A830: jr          $ra
    // 0x8064A834: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8064A834: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80078444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078444: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80078448: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007844C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80078450: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80078454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80078458: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x8007845C: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x80078460: addu        $t6, $a0, $s0
    ctx->r14 = ADD32(ctx->r4, ctx->r16);
    // 0x80078464: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80078468: subu        $s2, $t6, $a1
    ctx->r18 = SUB32(ctx->r14, ctx->r5);
    // 0x8007846C: srl         $s1, $s1, 24
    ctx->r17 = S32(U32(ctx->r17) >> 24);
    // 0x80078470: blez        $s1, L_80078494
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80078474: sw          $s2, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r18;
            goto L_80078494;
    }
    // 0x80078474: sw          $s2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r18;
L_80078478:
    // 0x80078478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007847C: jal         0x8007816C
    // 0x80078480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8007816C(rdram, ctx);
        goto after_0;
    // 0x80078480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80078484: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80078488: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8007848C: bgtz        $s1, L_80078478
    if (SIGNED(ctx->r17) > 0) {
        // 0x80078490: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_80078478;
    }
    // 0x80078490: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80078494:
    // 0x80078494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007849C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800784A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800784A4: jr          $ra
    // 0x800784A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800784A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80025E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025E1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025E24: jal         0x80067A10
    // 0x80025E28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80067A10(rdram, ctx);
        goto after_0;
    // 0x80025E28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80025E2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80025E30: bne         $v0, $at, L_80025E50
    if (ctx->r2 != ctx->r1) {
        // 0x80025E34: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80025E50;
    }
    // 0x80025E34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80025E38: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80025E3C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80025E40: addiu       $t7, $t7, 0x5D7C
    ctx->r15 = ADD32(ctx->r15, 0X5D7C);
    // 0x80025E44: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x80025E48: sb          $zero, 0x158($a0)
    MEM_B(0X158, ctx->r4) = 0;
    // 0x80025E4C: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
L_80025E50:
    // 0x80025E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025E58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80025E5C: jr          $ra
    // 0x80025E60: nop

    return;
    // 0x80025E60: nop

;}
RECOMP_FUNC void func_80040CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040CE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040CE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80040CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040CEC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80040CF0: jal         0x8006593C
    // 0x80040CF4: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80040CF4: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    after_0:
    // 0x80040CF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80040CFC: slti        $at, $v0, 0x35
    ctx->r1 = SIGNED(ctx->r2) < 0X35 ? 1 : 0;
    // 0x80040D00: bne         $at, $zero, L_80040D10
    if (ctx->r1 != 0) {
        // 0x80040D04: lbu         $v1, 0x30($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X30);
            goto L_80040D10;
    }
    // 0x80040D04: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x80040D08: b           L_80040D68
    // 0x80040D0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80040D68;
    // 0x80040D0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80040D10:
    // 0x80040D10: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80040D14: bnel        $at, $zero, L_80040D28
    if (ctx->r1 != 0) {
        // 0x80040D18: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80040D28;
    }
    goto skip_0;
    // 0x80040D18: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x80040D1C: b           L_80040D68
    // 0x80040D20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80040D68;
    // 0x80040D20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80040D24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80040D28:
    // 0x80040D28: beq         $v1, $at, L_80040D60
    if (ctx->r3 == ctx->r1) {
        // 0x80040D2C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80040D60;
    }
    // 0x80040D2C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80040D30: beq         $v1, $at, L_80040D60
    if (ctx->r3 == ctx->r1) {
        // 0x80040D34: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80040D60;
    }
    // 0x80040D34: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80040D38: beq         $v1, $at, L_80040D60
    if (ctx->r3 == ctx->r1) {
        // 0x80040D3C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80040D60;
    }
    // 0x80040D3C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80040D40: beq         $v1, $at, L_80040D60
    if (ctx->r3 == ctx->r1) {
        // 0x80040D44: nop
    
            goto L_80040D60;
    }
    // 0x80040D44: nop

    // 0x80040D48: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80040D4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80040D50: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80040D54: lbu         $t7, 0x22($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X22);
    // 0x80040D58: bne         $t7, $at, L_80040D68
    if (ctx->r15 != ctx->r1) {
        // 0x80040D5C: nop
    
            goto L_80040D68;
    }
    // 0x80040D5C: nop

L_80040D60:
    // 0x80040D60: b           L_80040D68
    // 0x80040D64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80040D68;
    // 0x80040D64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80040D68:
    // 0x80040D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040D70: jr          $ra
    // 0x80040D74: nop

    return;
    // 0x80040D74: nop

;}
RECOMP_FUNC void func_8055484C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055484C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80554850: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80554854: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80554858: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8055485C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80554860: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80554864: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80554868: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8055486C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80554870: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80554874: lui         $t1, 0x8055
    ctx->r9 = S32(RELOC_HI16(354, 0X412C) << 16);
    // 0x80554878: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8055487C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80554880: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80554884: lw          $t1, 0x4C4C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(354, 0X412C));
    // 0x80554888: jr          $ra
    // 0x8055488C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8055488C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80675724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675724: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675728: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8067572C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80675730: jr          $ra
    // 0x80675734: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x80675734: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8043AE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AE24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043AE28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043AE2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043AE30: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8043AE34: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8043AE38: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(83, 0X1160) << 16);
    // 0x8043AE3C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8043AE40: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8043AE44: addiu       $t7, $t7, -0x4840
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(83, 0X1160));
    // 0x8043AE48: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8043AE4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043AE50: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8043AE54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043AE58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8043AE5C: jal         0x8043AEC4
    // 0x8043AE60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8043AEC4(rdram, ctx);
        goto after_0;
    // 0x8043AE60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8043AE64: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8043AE68: jal         0x8043AD9C
    // 0x8043AE6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043AD9C(rdram, ctx);
        goto after_1;
    // 0x8043AE6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043AE70: bne         $v0, $zero, L_8043AE88
    if (ctx->r2 != 0) {
        // 0x8043AE74: nop
    
            goto L_8043AE88;
    }
    // 0x8043AE74: nop

    // 0x8043AE78: jal         0x800445A4
    // 0x8043AE7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8043AE7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043AE80: b           L_8043AEB4
    // 0x8043AE84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043AEB4;
    // 0x8043AE84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043AE88:
    // 0x8043AE88: jal         0x8043ADE4
    // 0x8043AE8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043ADE4(rdram, ctx);
        goto after_3;
    // 0x8043AE8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043AE90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8043AE94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043AE98: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x8043AE9C: lui         $t1, 0x8044
    ctx->r9 = S32(RELOC_HI16(83, 0X79C) << 16);
    // 0x8043AEA0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8043AEA4: addiu       $t1, $t1, -0x5204
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(83, 0X79C));
    // 0x8043AEA8: sh          $t0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r8;
    // 0x8043AEAC: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x8043AEB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043AEB4:
    // 0x8043AEB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043AEB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043AEBC: jr          $ra
    // 0x8043AEC0: nop

    return;
    // 0x8043AEC0: nop

;}
RECOMP_FUNC void func_80429E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429E5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80429E60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80429E64: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80429E68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80429E6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80429E70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80429E74: jal         0x80064E84
    // 0x80429E78: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80429E78: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80429E7C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80429E80: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80429E84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80429E88:
    // 0x80429E88: jal         0x80064E84
    // 0x80429E8C: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80429E8C: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    after_1:
    // 0x80429E90: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80429E94: bne         $s0, $s2, L_80429E88
    if (ctx->r16 != ctx->r18) {
        // 0x80429E98: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80429E88;
    }
    // 0x80429E98: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80429E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80429EA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80429EA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80429EA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80429EAC: jr          $ra
    // 0x80429EB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80429EB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80735CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80735CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80735CD0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80735CD4: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(736, 0X3930) << 16);
    // 0x80735CD8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80735CDC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80735CE0: addiu       $t6, $t6, -0x6C70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(736, 0X3930));
    // 0x80735CE4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80735CE8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80735CEC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80735CF0: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80735CF4: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x80735CF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80735CFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80735D00: jal         0x80735D18
    // 0x80735D04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80735D18(rdram, ctx);
        goto after_0;
    // 0x80735D04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80735D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80735D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80735D10: jr          $ra
    // 0x80735D14: nop

    return;
    // 0x80735D14: nop

;}
RECOMP_FUNC void func_804308DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804308DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x804308E0: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x804308E4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x804308E8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x804308EC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x804308F0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x804308F4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x804308F8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x804308FC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80430900: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80430904: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80430908: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8043090C: lwc1        $f28, 0x44($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80430910: lwc1        $f22, 0x40($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80430914: bne         $a1, $zero, L_8043092C
    if (ctx->r5 != 0) {
        // 0x80430918: lwc1        $f20, 0x3C($a0)
        ctx->f20.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_8043092C;
    }
    // 0x80430918: lwc1        $f20, 0x3C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8043091C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80430920: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80430924: b           L_80430940
    // 0x80430928: mov.s       $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
        goto L_80430940;
    // 0x80430928: mov.s       $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
L_8043092C:
    // 0x8043092C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80430930: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80430934: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80430938: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8043093C: nop

L_80430940:
    // 0x80430940: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80430944: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80430948:
    // 0x80430948: andi        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 & 0X1;
    // 0x8043094C: bne         $t6, $zero, L_8043095C
    if (ctx->r14 != 0) {
        // 0x80430950: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8043095C;
    }
    // 0x80430950: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80430954: b           L_80430960
    // 0x80430958: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80430960;
    // 0x80430958: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8043095C:
    // 0x8043095C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80430960:
    // 0x80430960: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80430964: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80430968: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8043096C: jal         0x80430838
    // 0x80430970: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80430838(rdram, ctx);
        goto after_0;
    // 0x80430970: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80430974: bne         $s0, $zero, L_80430988
    if (ctx->r16 != 0) {
        // 0x80430978: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80430988;
    }
    // 0x80430978: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8043097C: add.s       $f4, $f26, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f24.fl;
    // 0x80430980: b           L_80430990
    // 0x80430984: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
        goto L_80430990;
    // 0x80430984: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
L_80430988:
    // 0x80430988: sub.s       $f6, $f26, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f24.fl;
    // 0x8043098C: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_80430990:
    // 0x80430990: bne         $s1, $s2, L_80430948
    if (ctx->r17 != ctx->r18) {
        // 0x80430994: sub.s       $f22, $f22, $f24
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f24.fl;
            goto L_80430948;
    }
    // 0x80430994: sub.s       $f22, $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x80430998: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8043099C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804309A0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804309A4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804309A8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804309AC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x804309B0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x804309B4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x804309B8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x804309BC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x804309C0: jr          $ra
    // 0x804309C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x804309C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8076C848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076C848: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8076C84C: lui         $t6, 0x8077
    ctx->r14 = S32(RELOC_HI16(766, 0X440) << 16);
    // 0x8076C850: addiu       $t6, $t6, -0x33D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(766, 0X440));
    // 0x8076C854: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8076C858: jr          $ra
    // 0x8076C85C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8076C85C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806ED844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ED848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ED84C: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806ED850: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ED854: bnel        $t6, $zero, L_806ED894
    if (ctx->r14 != 0) {
        // 0x806ED858: lw          $t7, 0x12C($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X12C);
            goto L_806ED894;
    }
    goto skip_0;
    // 0x806ED858: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
    skip_0:
    // 0x806ED85C: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806ED860: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806ED864: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x806ED868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806ED86C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806ED870: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806ED874: nop

    // 0x806ED878: bc1fl       L_806ED894
    if (!c1cs) {
        // 0x806ED87C: lw          $t7, 0x12C($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X12C);
            goto L_806ED894;
    }
    goto skip_1;
    // 0x806ED87C: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
    skip_1:
    // 0x806ED880: jal         0x806EE338
    // 0x806ED884: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806EE338(rdram, ctx);
        goto after_0;
    // 0x806ED884: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x806ED888: b           L_806ED8D0
    // 0x806ED88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806ED8D0;
    // 0x806ED88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ED890: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
L_806ED894:
    // 0x806ED894: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806ED898: bnel        $t7, $at, L_806ED8D0
    if (ctx->r15 != ctx->r1) {
        // 0x806ED89C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806ED8D0;
    }
    goto skip_2;
    // 0x806ED89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x806ED8A0: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806ED8A4: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806ED8A8: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x806ED8AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806ED8B0: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806ED8B4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806ED8B8: nop

    // 0x806ED8BC: bc1fl       L_806ED8D0
    if (!c1cs) {
        // 0x806ED8C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806ED8D0;
    }
    goto skip_3;
    // 0x806ED8C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x806ED8C4: jal         0x806EE338
    // 0x806ED8C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806EE338(rdram, ctx);
        goto after_1;
    // 0x806ED8C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x806ED8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806ED8D0:
    // 0x806ED8D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ED8D4: jr          $ra
    // 0x806ED8D8: nop

    return;
    // 0x806ED8D8: nop

;}
RECOMP_FUNC void func_805E4CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4CD8: jal         0x805E4BB8
    // 0x805E4CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805E4BB8(rdram, ctx);
        goto after_0;
    // 0x805E4CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4CE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E4CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4CE8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x805E4CEC: jal         0x805E4D78
    // 0x805E4CF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805E4D78(rdram, ctx);
        goto after_1;
    // 0x805E4CF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x805E4CF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E4CF8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805E4CFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805E4D00: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4D04: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805E4D08: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x805E4D0C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x805E4D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4D14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4D18: jr          $ra
    // 0x805E4D1C: nop

    return;
    // 0x805E4D1C: nop

;}
RECOMP_FUNC void func_80532F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532F90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80532F94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80532F98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80532F9C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80532FA0: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80532FA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80532FA8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80532FAC: beq         $v0, $at, L_8053304C
    if (ctx->r2 == ctx->r1) {
        // 0x80532FB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8053304C;
    }
    // 0x80532FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80532FB4: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80532FB8: beq         $v0, $at, L_80532FC8
    if (ctx->r2 == ctx->r1) {
        // 0x80532FBC: addiu       $at, $zero, 0x4018
        ctx->r1 = ADD32(0, 0X4018);
            goto L_80532FC8;
    }
    // 0x80532FBC: addiu       $at, $zero, 0x4018
    ctx->r1 = ADD32(0, 0X4018);
    // 0x80532FC0: bnel        $v0, $at, L_805330F8
    if (ctx->r2 != ctx->r1) {
        // 0x80532FC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805330F8;
    }
    goto skip_0;
    // 0x80532FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80532FC8:
    // 0x80532FC8: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x80532FCC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80532FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80532FD4: bnel        $t6, $at, L_805330F8
    if (ctx->r14 != ctx->r1) {
        // 0x80532FD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805330F8;
    }
    goto skip_1;
    // 0x80532FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80532FDC: lw          $t7, 0x174($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X174);
    // 0x80532FE0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80532FE4: jal         0x80532D94
    // 0x80532FE8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_80532D94(rdram, ctx);
        goto after_0;
    // 0x80532FE8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80532FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80532FF0: jal         0x80532F54
    // 0x80532FF4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80532F54(rdram, ctx);
        goto after_1;
    // 0x80532FF4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80532FF8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80532FFC: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x80533000: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(345, 0X18C4) << 16);
    // 0x80533004: addiu       $a1, $a1, 0x4394
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(345, 0X18C4));
    // 0x80533008: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8053300C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80533010: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80533014: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x80533018: jalr        $t9
    // 0x8053301C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8053301C: nop

    after_2:
    // 0x80533020: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80533024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533028: lbu         $t0, 0x1C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1C);
    // 0x8053302C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80533030: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    // 0x80533034: jal         0x80532BC0
    // 0x80533038: sb          $t1, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r9;
    func_80532BC0(rdram, ctx);
        goto after_3;
    // 0x80533038: sb          $t1, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r9;
    after_3:
    // 0x8053303C: jal         0x800447C8
    // 0x80533040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x80533040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80533044: b           L_805330F8
    // 0x80533048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805330F8;
    // 0x80533048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8053304C:
    // 0x8053304C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80533050: jal         0x80532D58
    // 0x80533054: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80532D58(rdram, ctx);
        goto after_5;
    // 0x80533054: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_5:
    // 0x80533058: beq         $v0, $zero, L_805330E4
    if (ctx->r2 == 0) {
        // 0x8053305C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_805330E4;
    }
    // 0x8053305C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80533060: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x80533064: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x80533068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053306C: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x80533070: beq         $t3, $zero, L_8053308C
    if (ctx->r11 == 0) {
        // 0x80533074: nop
    
            goto L_8053308C;
    }
    // 0x80533074: nop

    // 0x80533078: jal         0x80532D94
    // 0x8053307C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80532D94(rdram, ctx);
        goto after_6;
    // 0x8053307C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_6:
    // 0x80533080: jal         0x80532F18
    // 0x80533084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532F18(rdram, ctx);
        goto after_7;
    // 0x80533084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80533088: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_8053308C:
    // 0x8053308C: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80533090: lw          $t4, -0x76F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76F8);
    // 0x80533094: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80533098: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(345, 0X18C4) << 16);
    // 0x8053309C: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x805330A0: addiu       $a1, $a1, 0x4394
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(345, 0X18C4));
    // 0x805330A4: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x805330A8: lw          $t9, 0x18($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X18);
    // 0x805330AC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x805330B0: jalr        $t9
    // 0x805330B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x805330B4: nop

    after_8:
    // 0x805330B8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805330BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805330C0: lbu         $t6, 0x1C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1C);
    // 0x805330C4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805330C8: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    // 0x805330CC: jal         0x80532BC0
    // 0x805330D0: sb          $t7, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r15;
    func_80532BC0(rdram, ctx);
        goto after_9;
    // 0x805330D0: sb          $t7, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r15;
    after_9:
    // 0x805330D4: jal         0x800447C8
    // 0x805330D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_10;
    // 0x805330D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x805330DC: b           L_805330F8
    // 0x805330E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805330F8;
    // 0x805330E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805330E4:
    // 0x805330E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805330E8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805330EC: jal         0x8002F6E4
    // 0x805330F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_11;
    // 0x805330F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x805330F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805330F8:
    // 0x805330F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805330FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80533100: jr          $ra
    // 0x80533104: nop

    return;
    // 0x80533104: nop

;}
RECOMP_FUNC void func_8049F848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8049F84C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049F850: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8049F854: beql        $a1, $zero, L_8049F868
    if (ctx->r5 == 0) {
        // 0x8049F858: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8049F868;
    }
    goto skip_0;
    // 0x8049F858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8049F85C: jal         0x800568E0
    // 0x8049F860: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x8049F860: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8049F864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8049F868:
    // 0x8049F868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8049F86C: jr          $ra
    // 0x8049F870: nop

    return;
    // 0x8049F870: nop

;}
RECOMP_FUNC void func_804613B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804613B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804613BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804613C0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804613C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804613C8: jal         0x8046118C
    // 0x804613CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8046118C(rdram, ctx);
        goto after_0;
    // 0x804613CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x804613D0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x804613D4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A0C) << 16);
    // 0x804613D8: lwc1        $f4, 0x3F9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A0C));
    // 0x804613DC: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x804613E0: lui         $a1, 0x3C13
    ctx->r5 = S32(0X3C13 << 16);
    // 0x804613E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804613E8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804613EC: ori         $a1, $a1, 0x74BC
    ctx->r5 = ctx->r5 | 0X74BC;
    // 0x804613F0: lui         $a2, 0x3B44
    ctx->r6 = S32(0X3B44 << 16);
    // 0x804613F4: bc1f        L_80461418
    if (!c1cs) {
        // 0x804613F8: nop
    
            goto L_80461418;
    }
    // 0x804613F8: nop

    // 0x804613FC: lui         $a1, 0x3C03
    ctx->r5 = S32(0X3C03 << 16);
    // 0x80461400: lui         $a2, 0x3BE5
    ctx->r6 = S32(0X3BE5 << 16);
    // 0x80461404: ori         $a2, $a2, 0x6042
    ctx->r6 = ctx->r6 | 0X6042;
    // 0x80461408: jal         0x804611DC
    // 0x8046140C: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    func_804611DC(rdram, ctx);
        goto after_1;
    // 0x8046140C: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    after_1:
    // 0x80461410: b           L_80461424
    // 0x80461414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80461424;
    // 0x80461414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80461418:
    // 0x80461418: jal         0x804611DC
    // 0x8046141C: ori         $a2, $a2, 0x9BA6
    ctx->r6 = ctx->r6 | 0X9BA6;
    func_804611DC(rdram, ctx);
        goto after_2;
    // 0x8046141C: ori         $a2, $a2, 0x9BA6
    ctx->r6 = ctx->r6 | 0X9BA6;
    after_2:
    // 0x80461420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80461424:
    // 0x80461424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80461428: jr          $ra
    // 0x8046142C: nop

    return;
    // 0x8046142C: nop

;}
RECOMP_FUNC void func_807BC474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC47C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807BC480: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807BC484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807BC488: beq         $v0, $zero, L_807BC49C
    if (ctx->r2 == 0) {
        // 0x807BC48C: addiu       $a2, $zero, 0x14
        ctx->r6 = ADD32(0, 0X14);
            goto L_807BC49C;
    }
    // 0x807BC48C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x807BC490: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807BC494: b           L_807BC4BC
    // 0x807BC498: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_807BC4BC;
    // 0x807BC498: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807BC49C:
    // 0x807BC49C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807BC4A0: jal         0x8006E0FC
    // 0x807BC4A4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x807BC4A4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x807BC4A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BC4AC: jal         0x800461F4
    // 0x807BC4B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800461F4(rdram, ctx);
        goto after_1;
    // 0x807BC4B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807BC4B4: jal         0x800447C8
    // 0x807BC4B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x807BC4B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_807BC4BC:
    // 0x807BC4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BC4C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC4C4: jr          $ra
    // 0x807BC4C8: nop

    return;
    // 0x807BC4C8: nop

;}
RECOMP_FUNC void func_80474DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474DC0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474DC4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474DC8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474DCC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474DD0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474DD4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474DD8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474DDC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474DE0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474DE4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474DE8: jr          $ra
    // 0x80474DEC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474DEC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8003C044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C044: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003C048: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003C04C: addiu       $t7, $t7, 0x3450
    ctx->r15 = ADD32(ctx->r15, 0X3450);
    // 0x8003C050: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8003C054: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8003C058: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003C05C: jr          $ra
    // 0x8003C060: sb          $zero, 0x1F8($v0)
    MEM_B(0X1F8, ctx->r2) = 0;
    return;
    // 0x8003C060: sb          $zero, 0x1F8($v0)
    MEM_B(0X1F8, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8040E254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E254: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8040E258: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040E25C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8040E260: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8040E264: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8040E268: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8040E26C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8040E270: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8040E274: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8040E278: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8040E27C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8040E280: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8040E284: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(20, 0X1E94) << 16);
    // 0x8040E288: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8040E28C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8040E290: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8040E294: lw          $t1, -0x1B6C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(20, 0X1E94));
    // 0x8040E298: jr          $ra
    // 0x8040E29C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8040E29C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80021958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021958: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002195C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80021960: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80021964: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80021968: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002196C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80021970: lw          $s2, 0x174($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X174);
    // 0x80021974: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80021978: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8002197C: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80021980: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80021984: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021988: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x8002198C: jal         0x80020820
    // 0x80021990: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    func_80020820(rdram, ctx);
        goto after_0;
    // 0x80021990: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    after_0:
    // 0x80021994: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021998: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002199C: jal         0x80020ADC
    // 0x800219A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80020ADC(rdram, ctx);
        goto after_1;
    // 0x800219A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800219A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800219A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800219AC: jal         0x80020DBC
    // 0x800219B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80020DBC(rdram, ctx);
        goto after_2;
    // 0x800219B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800219B4: jal         0x8002181C
    // 0x800219B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002181C(rdram, ctx);
        goto after_3;
    // 0x800219B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800219BC: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x800219C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800219C4: beql        $t8, $zero, L_800219DC
    if (ctx->r24 == 0) {
        // 0x800219C8: lw          $t1, 0x38($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X38);
            goto L_800219DC;
    }
    goto skip_0;
    // 0x800219C8: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x800219CC: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800219D0: ori         $t0, $t9, 0x700
    ctx->r8 = ctx->r25 | 0X700;
    // 0x800219D4: sw          $t0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r8;
    // 0x800219D8: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
L_800219DC:
    // 0x800219DC: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x800219E0: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x800219E4: sw          $t1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r9;
    // 0x800219E8: jal         0x8001EA24
    // 0x800219EC: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    func_8001EA24(rdram, ctx);
        goto after_4;
    // 0x800219EC: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    after_4:
    // 0x800219F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800219F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800219F8: jal         0x8001F904
    // 0x800219FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F904(rdram, ctx);
        goto after_5;
    // 0x800219FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80021A00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021A04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80021A08: jal         0x80021884
    // 0x80021A0C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80021884(rdram, ctx);
        goto after_6;
    // 0x80021A0C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
    // 0x80021A10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021A14: jal         0x80020014
    // 0x80021A18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80020014(rdram, ctx);
        goto after_7;
    // 0x80021A18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80021A1C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80021A20: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80021A24: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80021A28: sw          $t5, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r13;
    // 0x80021A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80021A30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80021A34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021A38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021A3C: jr          $ra
    // 0x80021A40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80021A40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_807915F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807915F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807915FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791600: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80791604: jal         0x80790CB4
    // 0x80791608: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x80791608: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8079160C: jal         0x80790714
    // 0x80791610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80791610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80791614: beq         $v0, $zero, L_8079163C
    if (ctx->r2 == 0) {
        // 0x80791618: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8079163C;
    }
    // 0x80791618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079161C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791620: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80791624: jal         0x8079393C
    // 0x80791628: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80791628: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x8079162C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791630: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80791634: jal         0x8079145C
    // 0x80791638: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    func_8079145C(rdram, ctx);
        goto after_3;
    // 0x80791638: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_3:
L_8079163C:
    // 0x8079163C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80791640: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80791644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80791648: jr          $ra
    // 0x8079164C: nop

    return;
    // 0x8079164C: nop

;}
RECOMP_FUNC void func_80462850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80462854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462858: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8046285C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80462860: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(122, 0X3878) << 16);
    // 0x80462864: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80462868: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8046286C: addiu       $t7, $t7, 0x3E08
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(122, 0X3878));
    // 0x80462870: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80462874: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80462878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046287C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462880: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80462884: jal         0x804628D4
    // 0x80462888: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804628D4(rdram, ctx);
        goto after_0;
    // 0x80462888: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8046288C: jal         0x804627D0
    // 0x80462890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804627D0(rdram, ctx);
        goto after_1;
    // 0x80462890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80462894: bne         $v0, $zero, L_804628A4
    if (ctx->r2 != 0) {
        // 0x80462898: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804628A4;
    }
    // 0x80462898: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046289C: b           L_804628C4
    // 0x804628A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804628C4;
    // 0x804628A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804628A4:
    // 0x804628A4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804628A8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804628AC: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x804628B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804628B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804628B8: jal         0x80462734
    // 0x804628BC: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80462734(rdram, ctx);
        goto after_2;
    // 0x804628BC: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_2:
    // 0x804628C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804628C4:
    // 0x804628C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804628C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804628CC: jr          $ra
    // 0x804628D0: nop

    return;
    // 0x804628D0: nop

;}
RECOMP_FUNC void func_806AEEB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEEB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AEEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AEEC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806AEEC4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AEEC8: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x806AEECC: jalr        $t9
    // 0x806AEED0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806AEED0: nop

    after_0:
    // 0x806AEED4: jal         0x806AE458
    // 0x806AEED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806AE458(rdram, ctx);
        goto after_1;
    // 0x806AEED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806AEEDC: beq         $v0, $zero, L_806AEEF4
    if (ctx->r2 == 0) {
        // 0x806AEEE0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AEEF4;
    }
    // 0x806AEEE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AEEE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AEEE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806AEEEC: jal         0x806AF64C
    // 0x806AEEF0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806AF64C(rdram, ctx);
        goto after_2;
    // 0x806AEEF0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
L_806AEEF4:
    // 0x806AEEF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AEEF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AEEFC: jr          $ra
    // 0x806AEF00: nop

    return;
    // 0x806AEF00: nop

;}
RECOMP_FUNC void func_804242A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804242A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804242A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804242AC: jal         0x804241A4
    // 0x804242B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804241A4(rdram, ctx);
        goto after_0;
    // 0x804242B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804242B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804242B8: lui         $at, 0xC387
    ctx->r1 = S32(0XC387 << 16);
    // 0x804242BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804242C0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804242C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804242C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804242CC: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804242D0: lwc1        $f6, 0xEC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x804242D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804242D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804242DC: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x804242E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804242E4: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804242E8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804242EC: nop

    // 0x804242F0: bc1fl       L_80424304
    if (!c1cs) {
        // 0x804242F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80424304;
    }
    goto skip_0;
    // 0x804242F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804242F8: jal         0x80424550
    // 0x804242FC: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    func_80424550(rdram, ctx);
        goto after_1;
    // 0x804242FC: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x80424300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80424304:
    // 0x80424304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80424308: jr          $ra
    // 0x8042430C: nop

    return;
    // 0x8042430C: nop

;}
RECOMP_FUNC void func_806A7A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A7A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A7A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A7A90: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x806A7A94: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x806A7A98: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x806A7A9C: bne         $t6, $zero, L_806A7AB4
    if (ctx->r14 != 0) {
        // 0x806A7AA0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806A7AB4;
    }
    // 0x806A7AA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A7AA4: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x806A7AA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806A7AAC: jal         0x806A7CF0
    // 0x806A7AB0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_806A7CF0(rdram, ctx);
        goto after_0;
    // 0x806A7AB0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
L_806A7AB4:
    // 0x806A7AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A7AB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A7ABC: jr          $ra
    // 0x806A7AC0: nop

    return;
    // 0x806A7AC0: nop

;}
RECOMP_FUNC void func_807AC488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AC48C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AC490: jal         0x807AC414
    // 0x807AC494: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807AC414(rdram, ctx);
        goto after_0;
    // 0x807AC494: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AC498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AC49C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AC4A0: jal         0x807AC4CC
    // 0x807AC4A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807AC4CC(rdram, ctx);
        goto after_1;
    // 0x807AC4A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x807AC4A8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x807AC4AC: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(856, 0X530) << 16);
    // 0x807AC4B0: addiu       $t6, $t6, -0x4080
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(856, 0X530));
    // 0x807AC4B4: lw          $t8, 0x16C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X16C);
    // 0x807AC4B8: sw          $t6, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r14;
    // 0x807AC4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AC4C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AC4C4: jr          $ra
    // 0x807AC4C8: nop

    return;
    // 0x807AC4C8: nop

;}
RECOMP_FUNC void func_806F9C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9C48: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x806F9C4C: addiu       $at, $zero, 0x45F1
    ctx->r1 = ADD32(0, 0X45F1);
    // 0x806F9C50: beq         $v0, $at, L_806F9C68
    if (ctx->r2 == ctx->r1) {
        // 0x806F9C54: addiu       $at, $zero, 0x45F2
        ctx->r1 = ADD32(0, 0X45F2);
            goto L_806F9C68;
    }
    // 0x806F9C54: addiu       $at, $zero, 0x45F2
    ctx->r1 = ADD32(0, 0X45F2);
    // 0x806F9C58: beq         $v0, $at, L_806F9C78
    if (ctx->r2 == ctx->r1) {
        // 0x806F9C5C: nop
    
            goto L_806F9C78;
    }
    // 0x806F9C5C: nop

    // 0x806F9C60: b           L_806F9C84
    // 0x806F9C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F9C84;
    // 0x806F9C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F9C68:
    // 0x806F9C68: jal         0x806F9D60
    // 0x806F9C6C: nop

    func_806F9D60(rdram, ctx);
        goto after_0;
    // 0x806F9C6C: nop

    after_0:
    // 0x806F9C70: b           L_806F9C84
    // 0x806F9C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F9C84;
    // 0x806F9C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F9C78:
    // 0x806F9C78: jal         0x806F9EA4
    // 0x806F9C7C: nop

    func_806F9EA4(rdram, ctx);
        goto after_1;
    // 0x806F9C7C: nop

    after_1:
    // 0x806F9C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F9C84:
    // 0x806F9C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9C88: jr          $ra
    // 0x806F9C8C: nop

    return;
    // 0x806F9C8C: nop

;}
RECOMP_FUNC void func_80698D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80698D80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80698D84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80698D88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80698D8C: jal         0x80698EBC
    // 0x80698D90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80698EBC(rdram, ctx);
        goto after_0;
    // 0x80698D90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80698D94: beql        $v0, $zero, L_80698E88
    if (ctx->r2 == 0) {
        // 0x80698D98: lw          $a0, 0x180($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X180);
            goto L_80698E88;
    }
    goto skip_0;
    // 0x80698D98: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x80698D9C: jal         0x80698EF4
    // 0x80698DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80698EF4(rdram, ctx);
        goto after_1;
    // 0x80698DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80698DA4: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80698DA8: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80698DAC: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80698DB0: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(556, 0X58C) << 16);
    // 0x80698DB4: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80698DB8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80698DBC: addiu       $t7, $t7, -0x6D54
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(556, 0X58C));
    // 0x80698DC0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80698DC4: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80698DC8: addiu       $at, $zero, 0x457C
    ctx->r1 = ADD32(0, 0X457C);
    // 0x80698DCC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80698DD0: beq         $v0, $at, L_80698DF8
    if (ctx->r2 == ctx->r1) {
        // 0x80698DD4: sw          $zero, 0x138($s0)
        MEM_W(0X138, ctx->r16) = 0;
            goto L_80698DF8;
    }
    // 0x80698DD4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80698DD8: addiu       $at, $zero, 0x457D
    ctx->r1 = ADD32(0, 0X457D);
    // 0x80698DDC: beq         $v0, $at, L_80698E3C
    if (ctx->r2 == ctx->r1) {
        // 0x80698DE0: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80698E3C;
    }
    // 0x80698DE0: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80698DE4: addiu       $at, $zero, 0x457F
    ctx->r1 = ADD32(0, 0X457F);
    // 0x80698DE8: beq         $v0, $at, L_80698E64
    if (ctx->r2 == ctx->r1) {
        // 0x80698DEC: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_80698E64;
    }
    // 0x80698DEC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80698DF0: b           L_80698EAC
    // 0x80698DF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80698EAC;
    // 0x80698DF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80698DF8:
    // 0x80698DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80698DFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80698E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80698E04: jal         0x80699250
    // 0x80698E08: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80699250(rdram, ctx);
        goto after_2;
    // 0x80698E08: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x80698E0C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80698E10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80698E14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80698E18: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(556, 0X5D0) << 16);
    // 0x80698E1C: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x80698E20: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x80698E24: lwc1        $f8, -0x6D10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(556, 0X5D0));
    // 0x80698E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80698E2C: jal         0x80698D30
    // 0x80698E30: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    func_80698D30(rdram, ctx);
        goto after_3;
    // 0x80698E30: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x80698E34: b           L_80698EAC
    // 0x80698E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80698EAC;
    // 0x80698E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80698E3C:
    // 0x80698E3C: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
    // 0x80698E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80698E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80698E48: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80698E4C: jal         0x80699250
    // 0x80698E50: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80699250(rdram, ctx);
        goto after_4;
    // 0x80698E50: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x80698E54: jal         0x80698D48
    // 0x80698E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80698D48(rdram, ctx);
        goto after_5;
    // 0x80698E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80698E5C: b           L_80698EAC
    // 0x80698E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80698EAC;
    // 0x80698E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80698E64:
    // 0x80698E64: sh          $t0, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r8;
    // 0x80698E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80698E6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80698E70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80698E74: jal         0x80699250
    // 0x80698E78: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80699250(rdram, ctx);
        goto after_6;
    // 0x80698E78: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_6:
    // 0x80698E7C: b           L_80698EAC
    // 0x80698E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80698EAC;
    // 0x80698E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80698E84: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
L_80698E88:
    // 0x80698E88: beq         $a0, $zero, L_80698EA0
    if (ctx->r4 == 0) {
        // 0x80698E8C: nop
    
            goto L_80698EA0;
    }
    // 0x80698E8C: nop

    // 0x80698E90: jal         0x800445A4
    // 0x80698E94: nop

    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x80698E94: nop

    after_7:
    // 0x80698E98: b           L_80698EAC
    // 0x80698E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80698EAC;
    // 0x80698E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80698EA0:
    // 0x80698EA0: jal         0x800445A4
    // 0x80698EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x80698EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80698EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80698EAC:
    // 0x80698EAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80698EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80698EB4: jr          $ra
    // 0x80698EB8: nop

    return;
    // 0x80698EB8: nop

;}
