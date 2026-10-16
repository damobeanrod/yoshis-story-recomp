#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804CE318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE318: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CE31C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CE320: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804CE324: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804CE328: addiu       $v1, $a2, 0x14C
    ctx->r3 = ADD32(ctx->r6, 0X14C);
    // 0x804CE32C: beq         $t6, $zero, L_804CE3B8
    if (ctx->r14 == 0) {
        // 0x804CE330: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804CE3B8;
    }
    // 0x804CE330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804CE334: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x804CE338: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804CE33C: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x804CE340: jalr        $t9
    // 0x804CE344: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804CE344: nop

    after_0:
    // 0x804CE348: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x804CE34C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804CE350: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x804CE354: lw          $t7, 0x15C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X15C);
    // 0x804CE358: lw          $t0, 0x14C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14C);
    // 0x804CE35C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804CE360: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804CE364: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804CE368: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804CE36C: sh          $t3, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r11;
    // 0x804CE370: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x804CE374: bne         $t4, $zero, L_804CE3B0
    if (ctx->r12 != 0) {
        // 0x804CE378: nop
    
            goto L_804CE3B0;
    }
    // 0x804CE378: nop

    // 0x804CE37C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x804CE380: bne         $t5, $zero, L_804CE3B0
    if (ctx->r13 != 0) {
        // 0x804CE384: nop
    
            goto L_804CE3B0;
    }
    // 0x804CE384: nop

    // 0x804CE388: lbu         $t6, 0x30($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X30);
    // 0x804CE38C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804CE390: bne         $t6, $at, L_804CE3B0
    if (ctx->r14 != ctx->r1) {
        // 0x804CE394: nop
    
            goto L_804CE3B0;
    }
    // 0x804CE394: nop

    // 0x804CE398: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x804CE39C: jal         0x80067BBC
    // 0x804CE3A0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x804CE3A0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x804CE3A4: addiu       $a0, $zero, 0x27A
    ctx->r4 = ADD32(0, 0X27A);
    // 0x804CE3A8: jal         0x80067818
    // 0x804CE3AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x804CE3AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_804CE3B0:
    // 0x804CE3B0: b           L_804CE3B8
    // 0x804CE3B4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_804CE3B8;
    // 0x804CE3B4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_804CE3B8:
    // 0x804CE3B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CE3BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CE3C0: jr          $ra
    // 0x804CE3C4: nop

    return;
    // 0x804CE3C4: nop

;}
RECOMP_FUNC void func_806EC124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EC128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EC12C: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x806EC130: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806EC134: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806EC138: beq         $a1, $at, L_806EC15C
    if (ctx->r5 == ctx->r1) {
        // 0x806EC13C: addiu       $a0, $zero, 0x2F
        ctx->r4 = ADD32(0, 0X2F);
            goto L_806EC15C;
    }
    // 0x806EC13C: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x806EC140: jal         0x80067930
    // 0x806EC144: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x806EC144: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x806EC148: beq         $v0, $zero, L_806EC15C
    if (ctx->r2 == 0) {
        // 0x806EC14C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_806EC15C;
    }
    // 0x806EC14C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806EC150: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x806EC154: jal         0x80067878
    // 0x806EC158: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x806EC158: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_806EC15C:
    // 0x806EC15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EC160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EC164: jr          $ra
    // 0x806EC168: nop

    return;
    // 0x806EC168: nop

;}
RECOMP_FUNC void func_805AD9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AD9DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805AD9E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805AD9E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805AD9E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805AD9EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805AD9F0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805AD9F4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805AD9F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805AD9FC: addiu       $t6, $zero, 0x1E78
    ctx->r14 = ADD32(0, 0X1E78);
    // 0x805ADA00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805ADA04: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805ADA08: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805ADA0C: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    // 0x805ADA10: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x805ADA14: jal         0x805AD70C
    // 0x805ADA18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_805AD70C(rdram, ctx);
        goto after_0;
    // 0x805ADA18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805ADA1C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ADA20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADA24: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805ADA28: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805ADA2C: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805ADA30: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x805ADA34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ADA38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ADA3C: jr          $ra
    // 0x805ADA40: nop

    return;
    // 0x805ADA40: nop

;}
RECOMP_FUNC void func_8073F848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073F84C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073F850: jal         0x8004700C
    // 0x8073F854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8073F854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073F858: beq         $v0, $zero, L_8073F8B4
    if (ctx->r2 == 0) {
        // 0x8073F85C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8073F8B4;
    }
    // 0x8073F85C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8073F860: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8073F864: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8073F868: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8073F86C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8073F870: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8073F874: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8073F878: nop

    // 0x8073F87C: bc1fl       L_8073F8B8
    if (!c1cs) {
        // 0x8073F880: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8073F8B8;
    }
    goto skip_0;
    // 0x8073F880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8073F884: lwc1        $f16, 0x84($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8073F888: lwc1        $f18, 0x84($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8073F88C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8073F890: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8073F894: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8073F898: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8073F89C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8073F8A0: nop

    // 0x8073F8A4: bc1fl       L_8073F8B8
    if (!c1cs) {
        // 0x8073F8A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8073F8B8;
    }
    goto skip_1;
    // 0x8073F8A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8073F8AC: b           L_8073F8B8
    // 0x8073F8B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8073F8B8;
    // 0x8073F8B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8073F8B4:
    // 0x8073F8B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073F8B8:
    // 0x8073F8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073F8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073F8C0: jr          $ra
    // 0x8073F8C4: nop

    return;
    // 0x8073F8C4: nop

;}
RECOMP_FUNC void func_80058160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058168: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005816C: addiu       $a1, $a1, -0x4CD8
    ctx->r5 = ADD32(ctx->r5, -0X4CD8);
    // 0x80058170: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80058174: jal         0x80058110
    // 0x80058178: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    func_80058110(rdram, ctx);
        goto after_0;
    // 0x80058178: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_0:
    // 0x8005817C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80058180: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80058184: lw          $t6, 0x3EC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3EC);
    // 0x80058188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005818C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058190: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80058194: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80058198: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005819C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800581A0: addiu       $t9, $t8, 0xA6C
    ctx->r25 = ADD32(ctx->r24, 0XA6C);
    // 0x800581A4: jr          $ra
    // 0x800581A8: sw          $t9, 0xA68($v0)
    MEM_W(0XA68, ctx->r2) = ctx->r25;
    return;
    // 0x800581A8: sw          $t9, 0xA68($v0)
    MEM_W(0XA68, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_80679E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679E50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80679E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80679E58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80679E5C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80679E60: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(541, 0X2658) << 16);
    // 0x80679E64: lh          $s0, 0x1F0($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X1F0);
    // 0x80679E68: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    // 0x80679E6C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80679E70: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80679E74: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80679E78: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80679E7C: lw          $t8, -0x3CF8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(541, 0X2658));
    // 0x80679E80: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80679E84: bne         $s0, $at, L_80679EF0
    if (ctx->r16 != ctx->r1) {
        // 0x80679E88: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80679EF0;
    }
    // 0x80679E88: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80679E8C: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80679E90: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x80679E94: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80679E98: jal         0x80067D5C
    // 0x80679E9C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80679E9C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x80679EA0: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80679EA4: jal         0x80067F78
    // 0x80679EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80679EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80679EAC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80679EB0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80679EB4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80679EB8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80679EBC: beq         $v0, $at, L_80679F2C
    if (ctx->r2 == ctx->r1) {
        // 0x80679EC0: sh          $v0, 0x1F0($a3)
        MEM_H(0X1F0, ctx->r7) = ctx->r2;
            goto L_80679F2C;
    }
    // 0x80679EC0: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
    // 0x80679EC4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80679EC8: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80679ECC: jal         0x80067D5C
    // 0x80679ED0: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x80679ED0: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80679ED4: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80679ED8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80679EDC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80679EE0: jal         0x80067838
    // 0x80679EE4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x80679EE4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x80679EE8: b           L_80679F30
    // 0x80679EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80679F30;
    // 0x80679EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80679EF0:
    // 0x80679EF0: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80679EF4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80679EF8: jal         0x80067930
    // 0x80679EFC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x80679EFC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_4:
    // 0x80679F00: beq         $v0, $zero, L_80679F2C
    if (ctx->r2 == 0) {
        // 0x80679F04: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_80679F2C;
    }
    // 0x80679F04: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80679F08: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80679F0C: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80679F10: jal         0x80067D5C
    // 0x80679F14: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_5;
    // 0x80679F14: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_5:
    // 0x80679F18: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80679F1C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80679F20: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80679F24: jal         0x800678F0
    // 0x80679F28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x80679F28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_80679F2C:
    // 0x80679F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80679F30:
    // 0x80679F30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80679F34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80679F38: jr          $ra
    // 0x80679F3C: nop

    return;
    // 0x80679F3C: nop

;}
RECOMP_FUNC void func_8064C780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C788: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C78C: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C790: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x8064C794: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C798: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064C79C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C7A0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064C7A4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8064C7A8: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064C7AC: nop

    // 0x8064C7B0: bc1fl       L_8064C7C4
    if (!c1cs) {
        // 0x8064C7B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C7C4;
    }
    goto skip_0;
    // 0x8064C7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C7B8: jal         0x8064CD50
    // 0x8064C7BC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064C7BC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064C7C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C7C4:
    // 0x8064C7C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C7C8: jr          $ra
    // 0x8064C7CC: nop

    return;
    // 0x8064C7CC: nop

;}
RECOMP_FUNC void func_804C0BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C0BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C0BC8: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804C0BCC: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(200, 0X45C) << 16);
    // 0x804C0BD0: addiu       $t8, $t8, 0xEBC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(200, 0X45C));
    // 0x804C0BD4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C0BD8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804C0BDC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804C0BE0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804C0BE4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C0BE8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804C0BEC: beql        $v1, $zero, L_804C0C20
    if (ctx->r3 == 0) {
        // 0x804C0BF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C0C20;
    }
    goto skip_0;
    // 0x804C0BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C0BF4: jalr        $v1
    // 0x804C0BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804C0BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C0BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C0C00: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x804C0C04: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x804C0C08: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x804C0C0C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x804C0C10: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x804C0C14: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x804C0C18: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x804C0C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C0C20:
    // 0x804C0C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C0C24: jr          $ra
    // 0x804C0C28: nop

    return;
    // 0x804C0C28: nop

;}
RECOMP_FUNC void func_8002D164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D16C: jal         0x8002CF94
    // 0x8002D170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002CF94(rdram, ctx);
        goto after_0;
    // 0x8002D170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002D174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002D178: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002D17C: addiu       $t6, $t6, 0x381C
    ctx->r14 = ADD32(ctx->r14, 0X381C);
    // 0x8002D180: jal         0x8002D0B4
    // 0x8002D184: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    func_8002D0B4(rdram, ctx);
        goto after_1;
    // 0x8002D184: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    after_1:
    // 0x8002D188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D18C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D190: jr          $ra
    // 0x8002D194: nop

    return;
    // 0x8002D194: nop

;}
RECOMP_FUNC void func_804C3374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C337C: jal         0x804C31FC
    // 0x804C3380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C31FC(rdram, ctx);
        goto after_0;
    // 0x804C3380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C3384: beq         $v0, $zero, L_804C33AC
    if (ctx->r2 == 0) {
        // 0x804C3388: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C33AC;
    }
    // 0x804C3388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C338C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804C3390: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(206, 0X678) << 16);
    // 0x804C3394: addiu       $t6, $t6, 0x30F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(206, 0X678));
    // 0x804C3398: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x804C339C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x804C33A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C33A4: jal         0x804C3618
    // 0x804C33A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804C3618(rdram, ctx);
        goto after_1;
    // 0x804C33A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_804C33AC:
    // 0x804C33AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C33B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C33B4: jr          $ra
    // 0x804C33B8: nop

    return;
    // 0x804C33B8: nop

;}
RECOMP_FUNC void func_8002B82C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B82C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002B830: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002B834: andi        $s1, $a2, 0xFF
    ctx->r17 = ctx->r6 & 0XFF;
    // 0x8002B838: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8002B83C: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x8002B840: lbu         $t0, -0x1ACC($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1ACC);
    // 0x8002B844: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8002B848: addiu       $t6, $t6, -0x1A7C
    ctx->r14 = ADD32(ctx->r14, -0X1A7C);
    // 0x8002B84C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002B850: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002B854: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002B858: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002B85C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8002B860: addu        $t2, $s1, $t6
    ctx->r10 = ADD32(ctx->r17, ctx->r14);
    // 0x8002B864: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002B868: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002B86C: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002B870: bne         $v1, $t0, L_8002B89C
    if (ctx->r3 != ctx->r8) {
        // 0x8002B874: lbu         $t1, 0x0($t2)
        ctx->r9 = MEM_BU(ctx->r10, 0X0);
            goto L_8002B89C;
    }
    // 0x8002B874: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8002B878: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x8002B87C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8002B880: beq         $v0, $at, L_8002B8A8
    if (ctx->r2 == ctx->r1) {
        // 0x8002B884: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8002B8A8;
    }
    // 0x8002B884: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8002B888: beql        $v0, $at, L_8002B8AC
    if (ctx->r2 == ctx->r1) {
        // 0x8002B88C: lbu         $v0, 0x18($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X18);
            goto L_8002B8AC;
    }
    goto skip_0;
    // 0x8002B88C: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    skip_0:
    // 0x8002B890: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x8002B894: beql        $v1, $t7, L_8002B8AC
    if (ctx->r3 == ctx->r15) {
        // 0x8002B898: lbu         $v0, 0x18($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X18);
            goto L_8002B8AC;
    }
    goto skip_1;
    // 0x8002B898: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    skip_1:
L_8002B89C:
    // 0x8002B89C: lbu         $t8, 0x1F8($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1F8);
    // 0x8002B8A0: beql        $t8, $zero, L_8002B8BC
    if (ctx->r24 == 0) {
        // 0x8002B8A4: lbu         $v0, 0x18($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X18);
            goto L_8002B8BC;
    }
    goto skip_2;
    // 0x8002B8A4: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    skip_2:
L_8002B8A8:
    // 0x8002B8A8: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
L_8002B8AC:
    // 0x8002B8AC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002B8B0: b           L_8002B8CC
    // 0x8002B8B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8002B8CC;
    // 0x8002B8B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002B8B8: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
L_8002B8BC:
    // 0x8002B8BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002B8C0: bne         $v0, $at, L_8002B8CC
    if (ctx->r2 != ctx->r1) {
        // 0x8002B8C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8002B8CC;
    }
    // 0x8002B8C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002B8C8: lbu         $t0, 0x20($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X20);
L_8002B8CC:
    // 0x8002B8CC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8002B8D0: beql        $at, $zero, L_8002B8E4
    if (ctx->r1 == 0) {
        // 0x8002B8D4: lbu         $t9, 0x30($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X30);
            goto L_8002B8E4;
    }
    goto skip_3;
    // 0x8002B8D4: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    skip_3:
    // 0x8002B8D8: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x8002B8DC: sb          $a1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r5;
    // 0x8002B8E0: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
L_8002B8E4:
    // 0x8002B8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B8E8: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x8002B8EC: sb          $t9, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r25;
    // 0x8002B8F0: sb          $s1, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r17;
    // 0x8002B8F4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8002B8F8: sb          $t1, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r9;
    // 0x8002B8FC: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    // 0x8002B900: jal         0x8002B7EC
    // 0x8002B904: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8002B7EC(rdram, ctx);
        goto after_0;
    // 0x8002B904: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8002B908: lbu         $t1, 0x2A($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2A);
    // 0x8002B90C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B910: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x8002B914: bnel        $t1, $zero, L_8002B988
    if (ctx->r9 != 0) {
        // 0x8002B918: sw          $zero, 0x78($a3)
        MEM_W(0X78, ctx->r7) = 0;
            goto L_8002B988;
    }
    goto skip_4;
    // 0x8002B918: sw          $zero, 0x78($a3)
    MEM_W(0X78, ctx->r7) = 0;
    skip_4:
    // 0x8002B91C: lbu         $t3, 0xDD($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0XDD);
    // 0x8002B920: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8002B924: beql        $t3, $t1, L_8002B988
    if (ctx->r11 == ctx->r9) {
        // 0x8002B928: sw          $zero, 0x78($a3)
        MEM_W(0X78, ctx->r7) = 0;
            goto L_8002B988;
    }
    goto skip_5;
    // 0x8002B928: sw          $zero, 0x78($a3)
    MEM_W(0X78, ctx->r7) = 0;
    skip_5:
    // 0x8002B92C: beq         $s1, $at, L_8002B948
    if (ctx->r17 == ctx->r1) {
        // 0x8002B930: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_8002B948;
    }
    // 0x8002B930: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8002B934: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8002B938: beq         $v0, $at, L_8002B948
    if (ctx->r2 == ctx->r1) {
        // 0x8002B93C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8002B948;
    }
    // 0x8002B93C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002B940: bne         $v0, $at, L_8002B970
    if (ctx->r2 != ctx->r1) {
        // 0x8002B944: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_8002B970;
    }
    // 0x8002B944: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
L_8002B948:
    // 0x8002B948: lbu         $t4, 0x1F8($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X1F8);
    // 0x8002B94C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8002B950: bnel        $t4, $zero, L_8002B988
    if (ctx->r12 != 0) {
        // 0x8002B954: sw          $zero, 0x78($a3)
        MEM_W(0X78, ctx->r7) = 0;
            goto L_8002B988;
    }
    goto skip_6;
    // 0x8002B954: sw          $zero, 0x78($a3)
    MEM_W(0X78, ctx->r7) = 0;
    skip_6:
    // 0x8002B958: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8002B95C: jal         0x800677F8
    // 0x8002B960: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x8002B960: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    after_1:
    // 0x8002B964: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B968: b           L_8002B984
    // 0x8002B96C: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
        goto L_8002B984;
    // 0x8002B96C: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
L_8002B970:
    // 0x8002B970: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8002B974: jal         0x800677F8
    // 0x8002B978: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    func_800677F8(rdram, ctx);
        goto after_2;
    // 0x8002B978: sb          $t0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r8;
    after_2:
    // 0x8002B97C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B980: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
L_8002B984:
    // 0x8002B984: sw          $zero, 0x78($a3)
    MEM_W(0X78, ctx->r7) = 0;
L_8002B988:
    // 0x8002B988: sb          $t0, 0x20($a3)
    MEM_B(0X20, ctx->r7) = ctx->r8;
    // 0x8002B98C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8002B990: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8002B994: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x8002B998: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8002B99C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8002B9A0: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8002B9A4: sb          $t6, 0xDD($a3)
    MEM_B(0XDD, ctx->r7) = ctx->r14;
    // 0x8002B9A8: lbu         $t7, -0x1A2C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1A2C);
    // 0x8002B9AC: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002B9B0: addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // 0x8002B9B4: sb          $t7, 0x157($a3)
    MEM_B(0X157, ctx->r7) = ctx->r15;
    // 0x8002B9B8: lbu         $t8, -0x19DC($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X19DC);
    // 0x8002B9BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B9C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8002B9C4: sb          $t8, 0x111($a3)
    MEM_B(0X111, ctx->r7) = ctx->r24;
    // 0x8002B9C8: jal         0x8001DD60
    // 0x8002B9CC: lbu         $a2, -0x198C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X198C);
    func_8001DD60(rdram, ctx);
        goto after_3;
    // 0x8002B9CC: lbu         $a2, -0x198C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X198C);
    after_3:
    // 0x8002B9D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B9D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002B9D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002B9DC: jr          $ra
    // 0x8002B9E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002B9E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80463180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463180: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80463184: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(122, 0X27DC) << 16);
    // 0x80463188: addiu       $t6, $t6, 0x2D6C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(122, 0X27DC));
    // 0x8046318C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80463190: jr          $ra
    // 0x80463194: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80463194: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804D8FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8FC4: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(258, 0X4328) << 16);
    // 0x804D8FC8: addiu       $v0, $v0, -0x3008
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(258, 0X4328));
    // 0x804D8FCC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x804D8FD0: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x804D8FD4: jr          $ra
    // 0x804D8FD8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x804D8FD8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80421F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421F54: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80421F58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80421F5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80421F60: lw          $a1, 0x1E0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1E0);
    // 0x80421F64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421F68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80421F6C: bne         $a1, $zero, L_804220E0
    if (ctx->r5 != 0) {
        // 0x80421F70: addiu       $v1, $v0, 0xC
        ctx->r3 = ADD32(ctx->r2, 0XC);
            goto L_804220E0;
    }
    // 0x80421F70: addiu       $v1, $v0, 0xC
    ctx->r3 = ADD32(ctx->r2, 0XC);
    // 0x80421F74: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80421F78: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x80421F7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80421F80: addiu       $a1, $zero, 0x40B6
    ctx->r5 = ADD32(0, 0X40B6);
L_80421F84:
    // 0x80421F84: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80421F88: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80421F8C: beq         $a0, $zero, L_80422008
    if (ctx->r4 == 0) {
        // 0x80421F90: nop
    
            goto L_80422008;
    }
    // 0x80421F90: nop

    // 0x80421F94: lhu         $t7, 0xC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC);
    // 0x80421F98: bne         $a1, $t7, L_80422008
    if (ctx->r5 != ctx->r15) {
        // 0x80421F9C: nop
    
            goto L_80422008;
    }
    // 0x80421F9C: nop

    // 0x80421FA0: jal         0x80048060
    // 0x80421FA4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80048060(rdram, ctx);
        goto after_0;
    // 0x80421FA4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80421FA8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80421FAC: jal         0x80044658
    // 0x80421FB0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x80421FB0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_1:
    // 0x80421FB4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80421FB8: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x80421FBC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80421FC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80421FC4: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80421FC8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80421FCC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80421FD0: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x80421FD4: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    // 0x80421FD8: jalr        $t9
    // 0x80421FDC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80421FDC: nop

    after_2:
    // 0x80421FE0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80421FE4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80421FE8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80421FEC: jal         0x80067BBC
    // 0x80421FF0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x80421FF0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x80421FF4: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    // 0x80421FF8: jal         0x80067818
    // 0x80421FFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80421FFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80422000: b           L_804220EC
    // 0x80422004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804220EC;
    // 0x80422004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80422008:
    // 0x80422008: bgez        $v0, L_80421F84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8042200C: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_80421F84;
    }
    // 0x8042200C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80422010: jal         0x80422294
    // 0x80422014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80422294(rdram, ctx);
        goto after_5;
    // 0x80422014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80422018: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8042201C: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x80422020: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x80422024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80422028: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x8042202C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80422030: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x80422034: jalr        $t9
    // 0x80422038: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80422038: nop

    after_6:
    // 0x8042203C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80422040: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80422044: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80422048: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8042204C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80422050: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80422054: lw          $t4, -0x76F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76F8);
    // 0x80422058: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8042205C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80422060: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80422064: addiu       $t3, $zero, 0x4034
    ctx->r11 = ADD32(0, 0X4034);
    // 0x80422068: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8042206C: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
    // 0x80422070: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80422074: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80422078: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x8042207C: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80422080: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80422084: lw          $t9, 0x54($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X54);
    // 0x80422088: jalr        $t9
    // 0x8042208C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8042208C: nop

    after_7:
    // 0x80422090: beq         $v0, $zero, L_804220B0
    if (ctx->r2 == 0) {
        // 0x80422094: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804220B0;
    }
    // 0x80422094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80422098: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x8042209C: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x804220A0: jal         0x80048BE8
    // 0x804220A4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_8;
    // 0x804220A4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_8:
    // 0x804220A8: b           L_804220B8
    // 0x804220AC: nop

        goto L_804220B8;
    // 0x804220AC: nop

L_804220B0:
    // 0x804220B0: jal         0x80048CC0
    // 0x804220B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048CC0(rdram, ctx);
        goto after_9;
    // 0x804220B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_804220B8:
    // 0x804220B8: jal         0x800447C8
    // 0x804220BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_10;
    // 0x804220BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x804220C0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x804220C4: jal         0x80067BBC
    // 0x804220C8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_11;
    // 0x804220C8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_11:
    // 0x804220CC: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    // 0x804220D0: jal         0x80067818
    // 0x804220D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_12;
    // 0x804220D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x804220D8: b           L_804220EC
    // 0x804220DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804220EC;
    // 0x804220DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804220E0:
    // 0x804220E0: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x804220E4: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x804220E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804220EC:
    // 0x804220EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804220F0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x804220F4: jr          $ra
    // 0x804220F8: nop

    return;
    // 0x804220F8: nop

;}
RECOMP_FUNC void func_8066E208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066E208: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066E20C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066E210: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8066E214: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8066E218: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8066E21C: jal         0x80045A34
    // 0x8066E220: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8066E220: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_0:
    // 0x8066E224: bne         $v0, $zero, L_8066E23C
    if (ctx->r2 != 0) {
        // 0x8066E228: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_8066E23C;
    }
    // 0x8066E228: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x8066E22C: jal         0x800445A4
    // 0x8066E230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8066E230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8066E234: b           L_8066E4B8
    // 0x8066E238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066E4B8;
    // 0x8066E238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E23C:
    // 0x8066E23C: lw          $t7, 0x16C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X16C);
    // 0x8066E240: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(517, 0X2B58) << 16);
    // 0x8066E244: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x8066E248: addiu       $t6, $t6, 0x118
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(517, 0X2B58));
    // 0x8066E24C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8066E250: lhu         $t0, 0xC($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0XC);
    // 0x8066E254: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8066E258: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8066E25C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8066E260: addiu       $at, $zero, 0x4557
    ctx->r1 = ADD32(0, 0X4557);
    // 0x8066E264: sw          $t8, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->r24;
    // 0x8066E268: bne         $t0, $at, L_8066E4A0
    if (ctx->r8 != ctx->r1) {
        // 0x8066E26C: sw          $t9, 0x130($s1)
        MEM_W(0X130, ctx->r17) = ctx->r25;
            goto L_8066E4A0;
    }
    // 0x8066E26C: sw          $t9, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->r25;
    // 0x8066E270: lui         $t2, 0x8067
    ctx->r10 = S32(RELOC_HI16(517, 0X584) << 16);
    // 0x8066E274: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8066E278: addiu       $t2, $t2, -0x24BC
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(517, 0X584));
    // 0x8066E27C: sb          $t1, 0x165($s1)
    MEM_B(0X165, ctx->r17) = ctx->r9;
    // 0x8066E280: sw          $t2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r10;
    // 0x8066E284: jal         0x8066DAE0
    // 0x8066E288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8066DAE0(rdram, ctx);
        goto after_2;
    // 0x8066E288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8066E28C: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x8066E290: addiu       $a0, $zero, 0x4558
    ctx->r4 = ADD32(0, 0X4558);
    // 0x8066E294: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8066E298: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8066E29C: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8066E2A0: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8066E2A4: jal         0x80047090
    // 0x8066E2A8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    func_80047090(rdram, ctx);
        goto after_3;
    // 0x8066E2A8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    after_3:
    // 0x8066E2AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8066E2B0: lui         $at, 0x4558
    ctx->r1 = S32(0X4558 << 16);
    // 0x8066E2B4: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x8066E2B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8066E2BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8066E2C0: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8066E2C4: jal         0x8004613C
    // 0x8066E2C8: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x8066E2C8: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_4:
    // 0x8066E2CC: bne         $v0, $zero, L_8066E2E4
    if (ctx->r2 != 0) {
        // 0x8066E2D0: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8066E2E4;
    }
    // 0x8066E2D0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8066E2D4: jal         0x800445A4
    // 0x8066E2D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x8066E2D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8066E2DC: b           L_8066E4B8
    // 0x8066E2E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066E4B8;
    // 0x8066E2E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E2E4:
    // 0x8066E2E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E2E8: jal         0x80047F9C
    // 0x8066E2EC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8066E2EC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x8066E2F0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8066E2F4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8066E2F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8066E2FC: sb          $t3, 0x17C($t4)
    MEM_B(0X17C, ctx->r12) = ctx->r11;
    // 0x8066E300: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8066E304: addiu       $a0, $zero, 0x4558
    ctx->r4 = ADD32(0, 0X4558);
    // 0x8066E308: jal         0x80047090
    // 0x8066E30C: sh          $t5, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r13;
    func_80047090(rdram, ctx);
        goto after_7;
    // 0x8066E30C: sh          $t5, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r13;
    after_7:
    // 0x8066E310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8066E314: lui         $at, 0x4558
    ctx->r1 = S32(0X4558 << 16);
    // 0x8066E318: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x8066E31C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8066E320: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8066E324: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8066E328: jal         0x8004613C
    // 0x8066E32C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x8066E32C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_8:
    // 0x8066E330: bne         $v0, $zero, L_8066E348
    if (ctx->r2 != 0) {
        // 0x8066E334: sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
            goto L_8066E348;
    }
    // 0x8066E334: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8066E338: jal         0x800445A4
    // 0x8066E33C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x8066E33C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8066E340: b           L_8066E4B8
    // 0x8066E344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066E4B8;
    // 0x8066E344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E348:
    // 0x8066E348: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E34C: jal         0x80047F9C
    // 0x8066E350: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x8066E350: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_10:
    // 0x8066E354: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8066E358: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8066E35C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8066E360: sb          $t7, 0x17C($t8)
    MEM_B(0X17C, ctx->r24) = ctx->r15;
    // 0x8066E364: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x8066E368: addiu       $a0, $zero, 0x4558
    ctx->r4 = ADD32(0, 0X4558);
    // 0x8066E36C: jal         0x80047090
    // 0x8066E370: sh          $t9, 0x144($t0)
    MEM_H(0X144, ctx->r8) = ctx->r25;
    func_80047090(rdram, ctx);
        goto after_11;
    // 0x8066E370: sh          $t9, 0x144($t0)
    MEM_H(0X144, ctx->r8) = ctx->r25;
    after_11:
    // 0x8066E374: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8066E378: lui         $at, 0x4558
    ctx->r1 = S32(0X4558 << 16);
    // 0x8066E37C: lui         $a3, 0x3B44
    ctx->r7 = S32(0X3B44 << 16);
    // 0x8066E380: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8066E384: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8066E388: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x8066E38C: jal         0x8004613C
    // 0x8066E390: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_12;
    // 0x8066E390: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_12:
    // 0x8066E394: bne         $v0, $zero, L_8066E3AC
    if (ctx->r2 != 0) {
        // 0x8066E398: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_8066E3AC;
    }
    // 0x8066E398: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8066E39C: jal         0x800445A4
    // 0x8066E3A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_13;
    // 0x8066E3A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8066E3A4: b           L_8066E4B8
    // 0x8066E3A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066E4B8;
    // 0x8066E3A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E3AC:
    // 0x8066E3AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E3B0: jal         0x80047F9C
    // 0x8066E3B4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_14;
    // 0x8066E3B4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_14:
    // 0x8066E3B8: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8066E3BC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8066E3C0: addiu       $a0, $zero, 0x4558
    ctx->r4 = ADD32(0, 0X4558);
    // 0x8066E3C4: sb          $t1, 0x17C($t2)
    MEM_B(0X17C, ctx->r10) = ctx->r9;
    // 0x8066E3C8: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8066E3CC: jal         0x80047090
    // 0x8066E3D0: sh          $zero, 0x144($t3)
    MEM_H(0X144, ctx->r11) = 0;
    func_80047090(rdram, ctx);
        goto after_15;
    // 0x8066E3D0: sh          $zero, 0x144($t3)
    MEM_H(0X144, ctx->r11) = 0;
    after_15:
    // 0x8066E3D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8066E3D8: lui         $at, 0x4558
    ctx->r1 = S32(0X4558 << 16);
    // 0x8066E3DC: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x8066E3E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8066E3E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8066E3E8: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8066E3EC: jal         0x8004613C
    // 0x8066E3F0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_16;
    // 0x8066E3F0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_16:
    // 0x8066E3F4: bne         $v0, $zero, L_8066E40C
    if (ctx->r2 != 0) {
        // 0x8066E3F8: sw          $v0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r2;
            goto L_8066E40C;
    }
    // 0x8066E3F8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8066E3FC: jal         0x800445A4
    // 0x8066E400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_17;
    // 0x8066E400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x8066E404: b           L_8066E4B8
    // 0x8066E408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066E4B8;
    // 0x8066E408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E40C:
    // 0x8066E40C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E410: jal         0x80047F9C
    // 0x8066E414: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    func_80047F9C(rdram, ctx);
        goto after_18;
    // 0x8066E414: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_18:
    // 0x8066E418: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8066E41C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8066E420: addiu       $a0, $zero, 0x46EB
    ctx->r4 = ADD32(0, 0X46EB);
    // 0x8066E424: sb          $t4, 0x17C($t5)
    MEM_B(0X17C, ctx->r13) = ctx->r12;
    // 0x8066E428: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8066E42C: jal         0x80047090
    // 0x8066E430: sh          $zero, 0x144($t6)
    MEM_H(0X144, ctx->r14) = 0;
    func_80047090(rdram, ctx);
        goto after_19;
    // 0x8066E430: sh          $zero, 0x144($t6)
    MEM_H(0X144, ctx->r14) = 0;
    after_19:
    // 0x8066E434: lui         $at, 0x46EB
    ctx->r1 = S32(0X46EB << 16);
    // 0x8066E438: lui         $a3, 0x3B83
    ctx->r7 = S32(0X3B83 << 16);
    // 0x8066E43C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8066E440: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8066E444: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8066E448: jal         0x8004613C
    // 0x8066E44C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8004613C(rdram, ctx);
        goto after_20;
    // 0x8066E44C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_20:
    // 0x8066E450: bne         $v0, $zero, L_8066E468
    if (ctx->r2 != 0) {
        // 0x8066E454: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_8066E468;
    }
    // 0x8066E454: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8066E458: jal         0x800445A4
    // 0x8066E45C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_21;
    // 0x8066E45C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x8066E460: b           L_8066E4B8
    // 0x8066E464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066E4B8;
    // 0x8066E464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E468:
    // 0x8066E468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E46C: jal         0x80047F9C
    // 0x8066E470: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80047F9C(rdram, ctx);
        goto after_22;
    // 0x8066E470: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_22:
    // 0x8066E474: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8066E478: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8066E47C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E480: sb          $t7, 0x17C($t8)
    MEM_B(0X17C, ctx->r24) = ctx->r15;
    // 0x8066E484: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8066E488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066E48C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8066E490: jal         0x8066E4C8
    // 0x8066E494: sh          $zero, 0x144($t9)
    MEM_H(0X144, ctx->r25) = 0;
    func_8066E4C8(rdram, ctx);
        goto after_23;
    // 0x8066E494: sh          $zero, 0x144($t9)
    MEM_H(0X144, ctx->r25) = 0;
    after_23:
    // 0x8066E498: b           L_8066E4B8
    // 0x8066E49C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066E4B8;
    // 0x8066E49C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E4A0:
    // 0x8066E4A0: sb          $zero, 0x165($s1)
    MEM_B(0X165, ctx->r17) = 0;
    // 0x8066E4A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E4A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066E4AC: jal         0x8066E4C8
    // 0x8066E4B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8066E4C8(rdram, ctx);
        goto after_24;
    // 0x8066E4B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x8066E4B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E4B8:
    // 0x8066E4B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8066E4BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8066E4C0: jr          $ra
    // 0x8066E4C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8066E4C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000DED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000DED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DED8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000DEDC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000DEE0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8000DEE4: bltzl       $t7, L_8000DF34
    if (SIGNED(ctx->r15) < 0) {
        // 0x8000DEE8: sll         $v1, $v0, 3
        ctx->r3 = S32(ctx->r2 << 3);
            goto L_8000DF34;
    }
    goto skip_0;
    // 0x8000DEE8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    skip_0:
    // 0x8000DEEC: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8000DEF0: beql        $v1, $zero, L_8000DF34
    if (ctx->r3 == 0) {
        // 0x8000DEF4: sll         $v1, $v0, 3
        ctx->r3 = S32(ctx->r2 << 3);
            goto L_8000DF34;
    }
    goto skip_1;
    // 0x8000DEF4: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    skip_1:
    // 0x8000DEF8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000DEFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000DF00: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8000DF04: srl         $t9, $a0, 28
    ctx->r25 = S32(U32(ctx->r4) >> 28);
    // 0x8000DF08: bne         $t9, $at, L_8000DF30
    if (ctx->r25 != ctx->r1) {
        // 0x8000DF0C: sll         $t0, $a0, 4
        ctx->r8 = S32(ctx->r4 << 4);
            goto L_8000DF30;
    }
    // 0x8000DF0C: sll         $t0, $a0, 4
    ctx->r8 = S32(ctx->r4 << 4);
    // 0x8000DF10: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x8000DF14: beql        $t1, $zero, L_8000DF34
    if (ctx->r9 == 0) {
        // 0x8000DF18: sll         $v1, $v0, 3
        ctx->r3 = S32(ctx->r2 << 3);
            goto L_8000DF34;
    }
    goto skip_2;
    // 0x8000DF18: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    skip_2:
    // 0x8000DF1C: lbu         $t3, 0x0($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X0);
    // 0x8000DF20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000DF24: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8000DF28: b           L_8000E01C
    // 0x8000DF2C: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
        goto L_8000E01C;
    // 0x8000DF2C: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
L_8000DF30:
    // 0x8000DF30: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
L_8000DF34:
    // 0x8000DF34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000DF38: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x8000DF3C: bne         $a0, $v1, L_8000DF58
    if (ctx->r4 != ctx->r3) {
        // 0x8000DF40: sll         $t5, $v0, 6
        ctx->r13 = S32(ctx->r2 << 6);
            goto L_8000DF58;
    }
    // 0x8000DF40: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x8000DF44: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x8000DF48: bne         $a0, $t6, L_8000DF58
    if (ctx->r4 != ctx->r14) {
        // 0x8000DF4C: nop
    
            goto L_8000DF58;
    }
    // 0x8000DF4C: nop

    // 0x8000DF50: b           L_8000E01C
    // 0x8000DF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E01C;
    // 0x8000DF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DF58:
    // 0x8000DF58: bne         $a0, $v1, L_8000DFB0
    if (ctx->r4 != ctx->r3) {
        // 0x8000DF5C: nop
    
            goto L_8000DFB0;
    }
    // 0x8000DF5C: nop

    // 0x8000DF60: lw          $a2, 0x2C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X2C);
    // 0x8000DF64: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8000DF68: beq         $a2, $zero, L_8000DFB0
    if (ctx->r6 == 0) {
        // 0x8000DF6C: nop
    
            goto L_8000DFB0;
    }
    // 0x8000DF6C: nop

    // 0x8000DF70: bgez        $t8, L_8000DFB0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000DF74: nop
    
            goto L_8000DFB0;
    }
    // 0x8000DF74: nop

    // 0x8000DF78: bne         $a1, $a0, L_8000DFB0
    if (ctx->r5 != ctx->r4) {
        // 0x8000DF7C: nop
    
            goto L_8000DFB0;
    }
    // 0x8000DF7C: nop

    // 0x8000DF80: lw          $t9, 0x44($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X44);
    // 0x8000DF84: bne         $a3, $t9, L_8000DFB0
    if (ctx->r7 != ctx->r25) {
        // 0x8000DF88: nop
    
            goto L_8000DFB0;
    }
    // 0x8000DF88: nop

    // 0x8000DF8C: lw          $t0, 0x4C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4C);
    // 0x8000DF90: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000DF94: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8000DF98: bnel        $t0, $zero, L_8000DFFC
    if (ctx->r8 != 0) {
        // 0x8000DF9C: lw          $a2, 0x2C($a3)
        ctx->r6 = MEM_W(ctx->r7, 0X2C);
            goto L_8000DFFC;
    }
    goto skip_3;
    // 0x8000DF9C: lw          $a2, 0x2C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X2C);
    skip_3:
    // 0x8000DFA0: jal         0x8000BD38
    // 0x8000DFA4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8000BD38(rdram, ctx);
        goto after_0;
    // 0x8000DFA4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000DFA8: b           L_8000DFF8
    // 0x8000DFAC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_8000DFF8;
    // 0x8000DFAC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8000DFB0:
    // 0x8000DFB0: bne         $a1, $zero, L_8000DFC4
    if (ctx->r5 != 0) {
        // 0x8000DFB4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8000DFC4;
    }
    // 0x8000DFB4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000DFB8: jal         0x8000BBF4
    // 0x8000DFBC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8000BBF4(rdram, ctx);
        goto after_1;
    // 0x8000DFBC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8000DFC0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8000DFC4:
    // 0x8000DFC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000DFC8: jal         0x8000C560
    // 0x8000DFCC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8000C560(rdram, ctx);
        goto after_2;
    // 0x8000DFCC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x8000DFD0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000DFD4: beq         $v0, $zero, L_8000DFF8
    if (ctx->r2 == 0) {
        // 0x8000DFD8: sw          $v0, 0x2C($a3)
        MEM_W(0X2C, ctx->r7) = ctx->r2;
            goto L_8000DFF8;
    }
    // 0x8000DFD8: sw          $v0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r2;
    // 0x8000DFDC: lw          $t1, 0x44($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X44);
    // 0x8000DFE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000DFE4: bnel        $a3, $t1, L_8000DFFC
    if (ctx->r7 != ctx->r9) {
        // 0x8000DFE8: lw          $a2, 0x2C($a3)
        ctx->r6 = MEM_W(ctx->r7, 0X2C);
            goto L_8000DFFC;
    }
    goto skip_4;
    // 0x8000DFE8: lw          $a2, 0x2C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X2C);
    skip_4:
    // 0x8000DFEC: jal         0x8000CEEC
    // 0x8000DFF0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8000CEEC(rdram, ctx);
        goto after_3;
    // 0x8000DFF0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x8000DFF4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8000DFF8:
    // 0x8000DFF8: lw          $a2, 0x2C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X2C);
L_8000DFFC:
    // 0x8000DFFC: beql        $a2, $zero, L_8000E01C
    if (ctx->r6 == 0) {
        // 0x8000E000: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000E01C;
    }
    goto skip_5;
    // 0x8000E000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x8000E004: lw          $t2, 0x44($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X44);
    // 0x8000E008: bnel        $a3, $t2, L_8000E01C
    if (ctx->r7 != ctx->r10) {
        // 0x8000E00C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000E01C;
    }
    goto skip_6;
    // 0x8000E00C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x8000E010: jal         0x8000CFA4
    // 0x8000E014: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8000CFA4(rdram, ctx);
        goto after_4;
    // 0x8000E014: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x8000E018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E01C:
    // 0x8000E01C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000E024: jr          $ra
    // 0x8000E028: nop

    return;
    // 0x8000E028: nop

;}
RECOMP_FUNC void func_804C21F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C21F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C21F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804C21FC: addiu       $a0, $zero, 0x4122
    ctx->r4 = ADD32(0, 0X4122);
    // 0x804C2200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C2204: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
L_804C2208:
    // 0x804C2208: lw          $v1, 0x188($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X188);
    // 0x804C220C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804C2210: beq         $v1, $zero, L_804C223C
    if (ctx->r3 == 0) {
        // 0x804C2214: nop
    
            goto L_804C223C;
    }
    // 0x804C2214: nop

    // 0x804C2218: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x804C221C: bne         $a0, $t6, L_804C223C
    if (ctx->r4 != ctx->r14) {
        // 0x804C2220: nop
    
            goto L_804C223C;
    }
    // 0x804C2220: nop

    // 0x804C2224: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x804C2228: beq         $a0, $zero, L_804C2244
    if (ctx->r4 == 0) {
        // 0x804C222C: nop
    
            goto L_804C2244;
    }
    // 0x804C222C: nop

    // 0x804C2230: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C2234: jr          $ra
    // 0x804C2238: swc1        $f4, 0x908($a0)
    MEM_W(0X908, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x804C2238: swc1        $f4, 0x908($a0)
    MEM_W(0X908, ctx->r4) = ctx->f4.u32l;
L_804C223C:
    // 0x804C223C: bne         $a1, $a3, L_804C2208
    if (ctx->r5 != ctx->r7) {
        // 0x804C2240: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_804C2208;
    }
    // 0x804C2240: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_804C2244:
    // 0x804C2244: jr          $ra
    // 0x804C2248: nop

    return;
    // 0x804C2248: nop

;}
RECOMP_FUNC void func_8004AB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004AB60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004AB64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004AB68: lhu         $t7, 0x32($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X32);
    // 0x8004AB6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004AB70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004AB74: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004AB78: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
    // 0x8004AB7C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004AB80: beq         $v0, $zero, L_8004ABC0
    if (ctx->r2 == 0) {
        // 0x8004AB84: lbu         $a2, 0x12($a0)
        ctx->r6 = MEM_BU(ctx->r4, 0X12);
            goto L_8004ABC0;
    }
    // 0x8004AB84: lbu         $a2, 0x12($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X12);
    // 0x8004AB88: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004AB8C: xor         $v1, $t7, $at
    ctx->r3 = ctx->r15 ^ ctx->r1;
    // 0x8004AB90: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x8004AB94: beq         $v0, $zero, L_8004ABC0
    if (ctx->r2 == 0) {
        // 0x8004AB98: lbu         $v1, 0x32($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X32);
            goto L_8004ABC0;
    }
    // 0x8004AB98: lbu         $v1, 0x32($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X32);
    // 0x8004AB9C: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8004ABA0: xori        $v0, $v1, 0x38
    ctx->r2 = ctx->r3 ^ 0X38;
    // 0x8004ABA4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004ABA8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004ABAC: beql        $v0, $zero, L_8004ABC4
    if (ctx->r2 == 0) {
        // 0x8004ABB0: lbu         $t8, 0x32($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X32);
            goto L_8004ABC4;
    }
    goto skip_0;
    // 0x8004ABB0: lbu         $t8, 0x32($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X32);
    skip_0:
    // 0x8004ABB4: xori        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 ^ 0X40;
    // 0x8004ABB8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004ABBC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8004ABC0:
    // 0x8004ABC0: lbu         $t8, 0x32($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X32);
L_8004ABC4:
    // 0x8004ABC4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8004ABC8: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8004ABCC: andi        $t9, $t8, 0xF8
    ctx->r25 = ctx->r24 & 0XF8;
    // 0x8004ABD0: xori        $t1, $t9, 0x10
    ctx->r9 = ctx->r25 ^ 0X10;
    // 0x8004ABD4: sb          $a2, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r6;
    // 0x8004ABD8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004ABDC: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8004ABE0: and         $v1, $v0, $t1
    ctx->r3 = ctx->r2 & ctx->r9;
    // 0x8004ABE4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8004ABE8: sb          $v1, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r3;
    // 0x8004ABEC: lw          $t4, -0x6DA8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6DA8);
    // 0x8004ABF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8004ABF4: beq         $a2, $v1, L_8004AD88
    if (ctx->r6 == ctx->r3) {
        // 0x8004ABF8: lw          $t0, 0x0($t4)
        ctx->r8 = MEM_W(ctx->r12, 0X0);
            goto L_8004AD88;
    }
    // 0x8004ABF8: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8004ABFC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8004AC00: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x8004AC04: bnel        $t8, $zero, L_8004AD8C
    if (ctx->r24 != 0) {
        // 0x8004AC08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004AD8C;
    }
    goto skip_1;
    // 0x8004AC08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8004AC0C: beql        $t0, $zero, L_8004ACA8
    if (ctx->r8 == 0) {
        // 0x8004AC10: lhu         $t1, 0xC($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0XC);
            goto L_8004ACA8;
    }
    goto skip_2;
    // 0x8004AC10: lhu         $t1, 0xC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XC);
    skip_2:
    // 0x8004AC14: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004AC18: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8004AC1C: jal         0x80065954
    // 0x8004AC20: sb          $v1, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r3;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8004AC20: sb          $v1, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004AC24: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004AC28: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004AC2C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8004AC30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004AC34: lbu         $v1, 0x26($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X26);
    // 0x8004AC38: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8004AC3C: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004AC40: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004AC44: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8004AC48: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8004AC4C: bc1fl       L_8004AC60
    if (!c1cs) {
        // 0x8004AC50: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8004AC60;
    }
    goto skip_3;
    // 0x8004AC50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x8004AC54: b           L_8004AC78
    // 0x8004AC58: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_8004AC78;
    // 0x8004AC58: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8004AC5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8004AC60:
    // 0x8004AC60: nop

    // 0x8004AC64: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8004AC68: nop

    // 0x8004AC6C: bc1fl       L_8004AC7C
    if (!c1cs) {
        // 0x8004AC70: lw          $t9, 0x0($t0)
        ctx->r25 = MEM_W(ctx->r8, 0X0);
            goto L_8004AC7C;
    }
    goto skip_4;
    // 0x8004AC70: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    skip_4:
    // 0x8004AC74: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8004AC78:
    // 0x8004AC78: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
L_8004AC7C:
    // 0x8004AC7C: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x8004AC80: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004AC84: lw          $v0, 0x1F4($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X1F4);
    // 0x8004AC88: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8004AC8C: lw          $a0, 0x115C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X115C);
    // 0x8004AC90: sb          $v1, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r3;
    // 0x8004AC94: lw          $t9, 0x1160($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1160);
    // 0x8004AC98: jalr        $t9
    // 0x8004AC9C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8004AC9C: nop

    after_1:
    // 0x8004ACA0: lbu         $v1, 0x26($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X26);
    // 0x8004ACA4: lhu         $t1, 0xC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XC);
L_8004ACA8:
    // 0x8004ACA8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8004ACAC: beql        $t1, $at, L_8004AD8C
    if (ctx->r9 == ctx->r1) {
        // 0x8004ACB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004AD8C;
    }
    goto skip_5;
    // 0x8004ACB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8004ACB4: beql        $v1, $zero, L_8004AD44
    if (ctx->r3 == 0) {
        // 0x8004ACB8: lh          $t7, 0x13C($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X13C);
            goto L_8004AD44;
    }
    goto skip_6;
    // 0x8004ACB8: lh          $t7, 0x13C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X13C);
    skip_6:
    // 0x8004ACBC: lh          $t2, 0x13C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X13C);
    // 0x8004ACC0: slti        $at, $t2, 0x30
    ctx->r1 = SIGNED(ctx->r10) < 0X30 ? 1 : 0;
    // 0x8004ACC4: beql        $at, $zero, L_8004ACF0
    if (ctx->r1 == 0) {
        // 0x8004ACC8: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8004ACF0;
    }
    goto skip_7;
    // 0x8004ACC8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_7:
    // 0x8004ACCC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8004ACD0: jal         0x80067BBC
    // 0x8004ACD4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8004ACD4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8004ACD8: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x8004ACDC: jal         0x80011D1C
    // 0x8004ACE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80011D1C(rdram, ctx);
        goto after_3;
    // 0x8004ACE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8004ACE4: b           L_8004AD08
    // 0x8004ACE8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
        goto L_8004AD08;
    // 0x8004ACE8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8004ACEC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8004ACF0:
    // 0x8004ACF0: jal         0x80067BBC
    // 0x8004ACF4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x8004ACF4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8004ACF8: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x8004ACFC: jal         0x80011D1C
    // 0x8004AD00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80011D1C(rdram, ctx);
        goto after_5;
    // 0x8004AD00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8004AD04: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_8004AD08:
    // 0x8004AD08: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8004AD0C: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8004AD10: sb          $t3, 0x1D($t4)
    MEM_B(0X1D, ctx->r12) = ctx->r11;
    // 0x8004AD14: lw          $t5, -0x76F8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76F8);
    // 0x8004AD18: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x8004AD1C: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x8004AD20: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x8004AD24: lw          $v0, 0x9C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X9C);
    // 0x8004AD28: beql        $v0, $zero, L_8004AD8C
    if (ctx->r2 == 0) {
        // 0x8004AD2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004AD8C;
    }
    goto skip_8;
    // 0x8004AD2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8004AD30: jalr        $v0
    // 0x8004AD34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x8004AD34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x8004AD38: b           L_8004AD8C
    // 0x8004AD3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004AD8C;
    // 0x8004AD3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AD40: lh          $t7, 0x13C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X13C);
L_8004AD44:
    // 0x8004AD44: slti        $at, $t7, 0x30
    ctx->r1 = SIGNED(ctx->r15) < 0X30 ? 1 : 0;
    // 0x8004AD48: beql        $at, $zero, L_8004AD74
    if (ctx->r1 == 0) {
        // 0x8004AD4C: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8004AD74;
    }
    goto skip_9;
    // 0x8004AD4C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_9:
    // 0x8004AD50: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8004AD54: jal         0x80067BBC
    // 0x8004AD58: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x8004AD58: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_7:
    // 0x8004AD5C: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x8004AD60: jal         0x80011D1C
    // 0x8004AD64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80011D1C(rdram, ctx);
        goto after_8;
    // 0x8004AD64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8004AD68: b           L_8004AD8C
    // 0x8004AD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004AD8C;
    // 0x8004AD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AD70: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8004AD74:
    // 0x8004AD74: jal         0x80067BBC
    // 0x8004AD78: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_9;
    // 0x8004AD78: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_9:
    // 0x8004AD7C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x8004AD80: jal         0x80011D1C
    // 0x8004AD84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80011D1C(rdram, ctx);
        goto after_10;
    // 0x8004AD84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
L_8004AD88:
    // 0x8004AD88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004AD8C:
    // 0x8004AD8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004AD90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004AD94: jr          $ra
    // 0x8004AD98: nop

    return;
    // 0x8004AD98: nop

;}
RECOMP_FUNC void func_8005F930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F938: jal         0x8005DAE4
    // 0x8005F93C: sb          $zero, 0xA80($a0)
    MEM_B(0XA80, ctx->r4) = 0;
    func_8005DAE4(rdram, ctx);
        goto after_0;
    // 0x8005F93C: sb          $zero, 0xA80($a0)
    MEM_B(0XA80, ctx->r4) = 0;
    after_0:
    // 0x8005F940: jal         0x8005F8A4
    // 0x8005F944: nop

    func_8005F8A4(rdram, ctx);
        goto after_1;
    // 0x8005F944: nop

    after_1:
    // 0x8005F948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F94C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005F950: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F954: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x8005F958: jr          $ra
    // 0x8005F95C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005F95C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806CEB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CEB2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CEB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CEB34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806CEB38: jal         0x806CB78C
    // 0x806CEB3C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_806CB78C(rdram, ctx);
        goto after_0;
    // 0x806CEB3C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_0:
    // 0x806CEB40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CEB44: jal         0x806CB78C
    // 0x806CEB48: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    func_806CB78C(rdram, ctx);
        goto after_1;
    // 0x806CEB48: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    after_1:
    // 0x806CEB4C: jal         0x80045BD8
    // 0x806CEB50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_2;
    // 0x806CEB50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806CEB54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CEB58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CEB5C: jr          $ra
    // 0x806CEB60: nop

    return;
    // 0x806CEB60: nop

;}
RECOMP_FUNC void func_804483F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804483F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804483F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804483FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80448400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448404: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80448408: bne         $a2, $zero, L_80448444
    if (ctx->r6 != 0) {
        // 0x8044840C: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80448444;
    }
    // 0x8044840C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448410: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x80448414: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x80448418: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8044841C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80448420: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80448424: bne         $at, $zero, L_80448484
    if (ctx->r1 != 0) {
        // 0x80448428: sw          $t7, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r15;
            goto L_80448484;
    }
    // 0x80448428: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x8044842C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448430: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448434: jal         0x804464B4
    // 0x80448438: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    func_804464B4(rdram, ctx);
        goto after_0;
    // 0x80448438: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    after_0:
    // 0x8044843C: b           L_80448488
    // 0x80448440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448488;
    // 0x80448440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448444:
    // 0x80448444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448448: bnel        $a2, $at, L_80448474
    if (ctx->r6 != ctx->r1) {
        // 0x8044844C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80448474;
    }
    goto skip_0;
    // 0x8044844C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448450: jal         0x804464B4
    // 0x80448454: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804464B4(rdram, ctx);
        goto after_1;
    // 0x80448454: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448458: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044845C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448460: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80448464: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448468: b           L_80448484
    // 0x8044846C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80448484;
    // 0x8044846C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80448470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80448474:
    // 0x80448474: bnel        $a2, $at, L_80448488
    if (ctx->r6 != ctx->r1) {
        // 0x80448478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448488;
    }
    goto skip_1;
    // 0x80448478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8044847C: jal         0x8044650C
    // 0x80448480: nop

    func_8044650C(rdram, ctx);
        goto after_2;
    // 0x80448480: nop

    after_2:
L_80448484:
    // 0x80448484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448488:
    // 0x80448488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044848C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448490: jr          $ra
    // 0x80448494: nop

    return;
    // 0x80448494: nop

;}
RECOMP_FUNC void func_80536714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536714: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536718: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053671C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536720: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536724: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536728: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053672C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536730: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536734: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536738: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053673C: jr          $ra
    // 0x80536740: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536740: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8003DD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DD70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DD74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003DD78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003DD7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003DD80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003DD84: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8003DD88: jal         0x80067BBC
    // 0x8003DD8C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8003DD8C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8003DD90: addiu       $a0, $zero, 0x22F
    ctx->r4 = ADD32(0, 0X22F);
    // 0x8003DD94: jal         0x80067818
    // 0x8003DD98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8003DD98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8003DD9C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003DDA0: addiu       $t6, $zero, 0x6C
    ctx->r14 = ADD32(0, 0X6C);
    // 0x8003DDA4: addiu       $t7, $t7, -0x22E8
    ctx->r15 = ADD32(ctx->r15, -0X22E8);
    // 0x8003DDA8: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x8003DDAC: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
    // 0x8003DDB0: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8003DDB4: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x8003DDB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003DDBC: jal         0x8003DA30
    // 0x8003DDC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003DA30(rdram, ctx);
        goto after_2;
    // 0x8003DDC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003DDC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003DDC8: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8003DDCC: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8003DDD0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003DDD4: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x8003DDD8: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x8003DDDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DDE0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003DDE4: sb          $zero, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = 0;
    // 0x8003DDE8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003DDEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003DDF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003DDF4: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x8003DDF8: jr          $ra
    // 0x8003DDFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003DDFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8044BB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB10: jr          $ra
    // 0x8044BB14: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB14: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8076E4DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076E4DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076E4E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076E4E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8076E4E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8076E4EC: jal         0x80047090
    // 0x8076E4F0: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8076E4F0: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    after_0:
    // 0x8076E4F4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8076E4F8: beq         $v0, $at, L_8076E540
    if (ctx->r2 == ctx->r1) {
        // 0x8076E4FC: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8076E540;
    }
    // 0x8076E4FC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8076E500: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8076E504: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x8076E508: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8076E50C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8076E510: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x8076E514: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8076E518: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8076E51C: jal         0x8004613C
    // 0x8076E520: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8076E520: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    after_1:
    // 0x8076E524: beq         $v0, $zero, L_8076E540
    if (ctx->r2 == 0) {
        // 0x8076E528: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8076E540;
    }
    // 0x8076E528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8076E52C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8076E530: jal         0x80047F9C
    // 0x8076E534: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8076E534: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x8076E538: b           L_8076E544
    // 0x8076E53C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_8076E544;
    // 0x8076E53C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_8076E540:
    // 0x8076E540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8076E544:
    // 0x8076E544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076E548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076E54C: jr          $ra
    // 0x8076E550: nop

    return;
    // 0x8076E550: nop

    // 0x8076E554: nop

    // 0x8076E558: nop

    // 0x8076E55C: nop

;}
RECOMP_FUNC void func_80574A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574A88: slti        $at, $a0, 0x45C0
    ctx->r1 = SIGNED(ctx->r4) < 0X45C0 ? 1 : 0;
    // 0x80574A8C: bne         $at, $zero, L_80574AAC
    if (ctx->r1 != 0) {
        // 0x80574A90: addiu       $at, $zero, 0x45F3
        ctx->r1 = ADD32(0, 0X45F3);
            goto L_80574AAC;
    }
    // 0x80574A90: addiu       $at, $zero, 0x45F3
    ctx->r1 = ADD32(0, 0X45F3);
    // 0x80574A94: beq         $a0, $at, L_80574B28
    if (ctx->r4 == ctx->r1) {
        // 0x80574A98: addiu       $at, $zero, 0x468C
        ctx->r1 = ADD32(0, 0X468C);
            goto L_80574B28;
    }
    // 0x80574A98: addiu       $at, $zero, 0x468C
    ctx->r1 = ADD32(0, 0X468C);
    // 0x80574A9C: beq         $a0, $at, L_80574B30
    if (ctx->r4 == ctx->r1) {
        // 0x80574AA0: nop
    
            goto L_80574B30;
    }
    // 0x80574AA0: nop

    // 0x80574AA4: b           L_80574B3C
    // 0x80574AA8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_80574B3C;
    // 0x80574AA8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_80574AAC:
    // 0x80574AAC: slti        $at, $a0, 0x45BD
    ctx->r1 = SIGNED(ctx->r4) < 0X45BD ? 1 : 0;
    // 0x80574AB0: bne         $at, $zero, L_80574AC8
    if (ctx->r1 != 0) {
        // 0x80574AB4: addiu       $at, $zero, 0x45BF
        ctx->r1 = ADD32(0, 0X45BF);
            goto L_80574AC8;
    }
    // 0x80574AB4: addiu       $at, $zero, 0x45BF
    ctx->r1 = ADD32(0, 0X45BF);
    // 0x80574AB8: beq         $a0, $at, L_80574B28
    if (ctx->r4 == ctx->r1) {
        // 0x80574ABC: nop
    
            goto L_80574B28;
    }
    // 0x80574ABC: nop

    // 0x80574AC0: b           L_80574B3C
    // 0x80574AC4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_80574B3C;
    // 0x80574AC4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_80574AC8:
    // 0x80574AC8: slti        $at, $a0, 0x4036
    ctx->r1 = SIGNED(ctx->r4) < 0X4036 ? 1 : 0;
    // 0x80574ACC: bne         $at, $zero, L_80574AE8
    if (ctx->r1 != 0) {
        // 0x80574AD0: addiu       $t6, $a0, -0x4030
        ctx->r14 = ADD32(ctx->r4, -0X4030);
            goto L_80574AE8;
    }
    // 0x80574AD0: addiu       $t6, $a0, -0x4030
    ctx->r14 = ADD32(ctx->r4, -0X4030);
    // 0x80574AD4: addiu       $at, $zero, 0x45BC
    ctx->r1 = ADD32(0, 0X45BC);
    // 0x80574AD8: beq         $a0, $at, L_80574B28
    if (ctx->r4 == ctx->r1) {
        // 0x80574ADC: nop
    
            goto L_80574B28;
    }
    // 0x80574ADC: nop

    // 0x80574AE0: b           L_80574B3C
    // 0x80574AE4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_80574B3C;
    // 0x80574AE4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_80574AE8:
    // 0x80574AE8: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80574AEC: beq         $at, $zero, L_80574B38
    if (ctx->r1 == 0) {
        // 0x80574AF0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80574B38;
    }
    // 0x80574AF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80574AF4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XEF8) << 16);
    // 0x80574AF8: addu        $at, $at, $t6
    gpr jr_addend_80574B00 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80574AFC: lw          $t6, 0x4D88($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(381, 0XEF8));
    // 0x80574B00: jr          $t6
    // 0x80574B04: nop

    switch (jr_addend_80574B00 >> 2) {
        case 0: goto L_80574B08; break;
        case 1: goto L_80574B10; break;
        case 2: goto L_80574B18; break;
        case 3: goto L_80574B20; break;
        case 4: goto L_80574B28; break;
        case 5: goto L_80574B30; break;
        default: switch_error(__func__, 0x80574B00, 0x80574D88);
    }
    // 0x80574B04: nop

L_80574B08:
    // 0x80574B08: jr          $ra
    // 0x80574B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80574B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80574B10:
    // 0x80574B10: jr          $ra
    // 0x80574B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80574B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80574B18:
    // 0x80574B18: jr          $ra
    // 0x80574B1C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80574B1C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80574B20:
    // 0x80574B20: jr          $ra
    // 0x80574B24: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80574B24: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80574B28:
    // 0x80574B28: jr          $ra
    // 0x80574B2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80574B2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80574B30:
    // 0x80574B30: jr          $ra
    // 0x80574B34: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80574B34: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80574B38:
    // 0x80574B38: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_80574B3C:
    // 0x80574B3C: jr          $ra
    // 0x80574B40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80574B40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_806FAE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FAE80: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x806FAE84: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x806FAE88: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x806FAE8C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x806FAE90: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x806FAE94: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x806FAE98: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x806FAE9C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x806FAEA0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x806FAEA4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x806FAEA8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806FAEAC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806FAEB0: lw          $s3, 0x4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X4);
    // 0x806FAEB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806FAEB8: addiu       $s5, $sp, 0x68
    ctx->r21 = ADD32(ctx->r29, 0X68);
    // 0x806FAEBC: lh          $s2, 0x184($s3)
    ctx->r18 = MEM_H(ctx->r19, 0X184);
    // 0x806FAEC0: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x806FAEC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806FAEC8: beq         $s2, $zero, L_806FB01C
    if (ctx->r18 == 0) {
        // 0x806FAECC: addiu       $s1, $s3, 0x188
        ctx->r17 = ADD32(ctx->r19, 0X188);
            goto L_806FB01C;
    }
    // 0x806FAECC: addiu       $s1, $s3, 0x188
    ctx->r17 = ADD32(ctx->r19, 0X188);
    // 0x806FAED0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x806FAED4: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(700, 0X2ACC) << 16);
    // 0x806FAED8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806FAEDC: lwc1        $f22, -0x3904($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(700, 0X2ACC));
    // 0x806FAEE0: addiu       $s4, $zero, 0x45F2
    ctx->r20 = ADD32(0, 0X45F2);
L_806FAEE4:
    // 0x806FAEE4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x806FAEE8: beq         $v0, $zero, L_806FB014
    if (ctx->r2 == 0) {
        // 0x806FAEEC: nop
    
            goto L_806FB014;
    }
    // 0x806FAEEC: nop

    // 0x806FAEF0: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x806FAEF4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x806FAEF8: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x806FAEFC: beql        $s4, $t7, L_806FB00C
    if (ctx->r20 == ctx->r15) {
        // 0x806FAF00: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806FB00C;
    }
    goto skip_0;
    // 0x806FAF00: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x806FAF04: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x806FAF08: beq         $v1, $zero, L_806FB008
    if (ctx->r3 == 0) {
        // 0x806FAF0C: sw          $v1, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r3;
            goto L_806FB008;
    }
    // 0x806FAF0C: sw          $v1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r3;
    // 0x806FAF10: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x806FAF14: bnel        $s3, $t9, L_806FB00C
    if (ctx->r19 != ctx->r25) {
        // 0x806FAF18: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806FB00C;
    }
    goto skip_1;
    // 0x806FAF18: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
    // 0x806FAF1C: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x806FAF20: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x806FAF24: nop

    // 0x806FAF28: bc1f        L_806FB000
    if (!c1cs) {
        // 0x806FAF2C: nop
    
            goto L_806FB000;
    }
    // 0x806FAF2C: nop

    // 0x806FAF30: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x806FAF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FAF38: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x806FAF3C: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x806FAF40: lw          $t0, 0x174($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X174);
    // 0x806FAF44: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x806FAF48: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x806FAF4C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x806FAF50: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x806FAF54: lh          $t3, 0xC($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XC);
    // 0x806FAF58: lw          $t1, 0x70($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X70);
    // 0x806FAF5C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x806FAF60: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x806FAF64: lwc1        $f0, 0x4($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X4);
    // 0x806FAF68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806FAF6C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806FAF70: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806FAF74: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x806FAF78: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806FAF7C: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x806FAF80: jal         0x806FAA54
    // 0x806FAF84: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    func_806FAA54(rdram, ctx);
        goto after_0;
    // 0x806FAF84: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    after_0:
    // 0x806FAF88: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x806FAF8C: c.eq.s      $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f18.fl == ctx->f22.fl;
    // 0x806FAF90: nop

    // 0x806FAF94: bc1t        L_806FAFF0
    if (c1cs) {
        // 0x806FAF98: nop
    
            goto L_806FAFF0;
    }
    // 0x806FAF98: nop

    // 0x806FAF9C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x806FAFA0: lw          $t4, 0x174($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X174);
    // 0x806FAFA4: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x806FAFA8: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x806FAFAC: lh          $t7, 0xC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XC);
    // 0x806FAFB0: lw          $t5, 0x70($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X70);
    // 0x806FAFB4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x806FAFB8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x806FAFBC: lwc1        $f0, 0x4($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X4);
    // 0x806FAFC0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806FAFC4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806FAFC8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806FAFCC: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x806FAFD0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806FAFD4: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x806FAFD8: add.s       $f2, $f18, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x806FAFDC: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
    // 0x806FAFE0: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x806FAFE4: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x806FAFE8: b           L_806FB008
    // 0x806FAFEC: swc1        $f16, 0x120($t8)
    MEM_W(0X120, ctx->r24) = ctx->f16.u32l;
        goto L_806FB008;
    // 0x806FAFEC: swc1        $f16, 0x120($t8)
    MEM_W(0X120, ctx->r24) = ctx->f16.u32l;
L_806FAFF0:
    // 0x806FAFF0: jal         0x80060F6C
    // 0x806FAFF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060F6C(rdram, ctx);
        goto after_1;
    // 0x806FAFF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806FAFF8: b           L_806FB00C
    // 0x806FAFFC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_806FB00C;
    // 0x806FAFFC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_806FB000:
    // 0x806FB000: jal         0x80060F6C
    // 0x806FB004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060F6C(rdram, ctx);
        goto after_2;
    // 0x806FB004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_806FB008:
    // 0x806FB008: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_806FB00C:
    // 0x806FB00C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x806FB010: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_806FB014:
    // 0x806FB014: bne         $s2, $zero, L_806FAEE4
    if (ctx->r18 != 0) {
        // 0x806FB018: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_806FAEE4;
    }
    // 0x806FB018: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_806FB01C:
    // 0x806FB01C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x806FB020: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806FB024: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806FB028: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806FB02C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x806FB030: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x806FB034: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x806FB038: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x806FB03C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x806FB040: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x806FB044: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x806FB048: jr          $ra
    // 0x806FB04C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x806FB04C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80446068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446068: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044606C: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446070: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446074: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80446078: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8044607C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446080: jr          $ra
    // 0x80446084: sw          $t7, 0x6CA0($at)
    MEM_W(0X6CA0, ctx->r1) = ctx->r15;
    return;
    // 0x80446084: sw          $t7, 0x6CA0($at)
    MEM_W(0X6CA0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8067F6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F6C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067F6C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067F6C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8067F6CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8067F6D0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8067F6D4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8067F6D8: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8067F6DC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8067F6E0: bnel        $t6, $at, L_8067F72C
    if (ctx->r14 != ctx->r1) {
        // 0x8067F6E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067F72C;
    }
    goto skip_0;
    // 0x8067F6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8067F6E8: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8067F6EC: beql        $t7, $zero, L_8067F72C
    if (ctx->r15 == 0) {
        // 0x8067F6F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067F72C;
    }
    goto skip_1;
    // 0x8067F6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8067F6F4: jal         0x80044658
    // 0x8067F6F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80044658(rdram, ctx);
        goto after_0;
    // 0x8067F6F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8067F6FC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8067F700: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x8067F704: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8067F708: lui         $a1, 0x8068
    ctx->r5 = S32(RELOC_HI16(547, 0X10B0) << 16);
    // 0x8067F70C: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8067F710: addiu       $a1, $a1, 0x2A0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(547, 0X10B0));
    // 0x8067F714: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8067F718: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x8067F71C: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8067F720: jalr        $t9
    // 0x8067F724: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8067F724: nop

    after_1:
    // 0x8067F728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8067F72C:
    // 0x8067F72C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067F730: jr          $ra
    // 0x8067F734: nop

    return;
    // 0x8067F734: nop

;}
RECOMP_FUNC void func_804F4290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4290: lui         $v0, 0x804F
    ctx->r2 = S32(RELOC_HI16(273, 0X28) << 16);
    // 0x804F4294: addiu       $v0, $v0, 0x42B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X28));
    // 0x804F4298: jr          $ra
    // 0x804F429C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804F429C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80798864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80798868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079886C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80798870: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80798874: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80798878: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8079887C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80798880: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x80798884: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80798888: jal         0x807988A0
    // 0x8079888C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807988A0(rdram, ctx);
        goto after_0;
    // 0x8079888C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80798890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80798898: jr          $ra
    // 0x8079889C: nop

    return;
    // 0x8079889C: nop

;}
RECOMP_FUNC void func_805ACC2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ACC2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805ACC30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805ACC34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805ACC38: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805ACC3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805ACC40: jal         0x805AC884
    // 0x805ACC44: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_805AC884(rdram, ctx);
        goto after_0;
    // 0x805ACC44: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x805ACC48: jal         0x805AC528
    // 0x805ACC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AC528(rdram, ctx);
        goto after_1;
    // 0x805ACC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805ACC50: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ACC54: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x805ACC58: beq         $v1, $zero, L_805ACC68
    if (ctx->r3 == 0) {
        // 0x805ACC5C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_805ACC68;
    }
    // 0x805ACC5C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x805ACC60: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x805ACC64: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_805ACC68:
    // 0x805ACC68: bnel        $v1, $zero, L_805ACCE0
    if (ctx->r3 != 0) {
        // 0x805ACC6C: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805ACCE0;
    }
    goto skip_0;
    // 0x805ACC6C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x805ACC70: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x805ACC74: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(441, 0X120C) << 16);
    // 0x805ACC78: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x805ACC7C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x805ACC80: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805ACC84: lh          $t9, -0x2C04($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(441, 0X120C));
    // 0x805ACC88: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x805ACC8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ACC90: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
    // 0x805ACC94: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    // 0x805ACC98: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
    // 0x805ACC9C: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x805ACCA0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x805ACCA4: sw          $t1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r9;
    // 0x805ACCA8: lh          $v1, 0x144($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X144);
    // 0x805ACCAC: beq         $v1, $at, L_805ACCBC
    if (ctx->r3 == ctx->r1) {
        // 0x805ACCB0: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_805ACCBC;
    }
    // 0x805ACCB0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x805ACCB4: bnel        $v1, $at, L_805ACCCC
    if (ctx->r3 != ctx->r1) {
        // 0x805ACCB8: lw          $t3, 0x1C($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X1C);
            goto L_805ACCCC;
    }
    goto skip_1;
    // 0x805ACCB8: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    skip_1:
L_805ACCBC:
    // 0x805ACCBC: jal         0x805AC744
    // 0x805ACCC0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_805AC744(rdram, ctx);
        goto after_2;
    // 0x805ACCC0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x805ACCC4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ACCC8: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
L_805ACCCC:
    // 0x805ACCCC: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x805ACCD0: bnel        $at, $zero, L_805ACCE0
    if (ctx->r1 != 0) {
        // 0x805ACCD4: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805ACCE0;
    }
    goto skip_2;
    // 0x805ACCD4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_2:
    // 0x805ACCD8: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x805ACCDC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805ACCE0:
    // 0x805ACCE0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805ACCE4: jal         0x80048F84
    // 0x805ACCE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805ACCE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x805ACCEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805ACCF0: jal         0x80048F84
    // 0x805ACCF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805ACCF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x805ACCF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805ACCFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805ACD00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805ACD04: jr          $ra
    // 0x805ACD08: nop

    return;
    // 0x805ACD08: nop

;}
RECOMP_FUNC void func_80409304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409304: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80409308: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040930C: lwc1        $f0, 0xB48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XB48);
    // 0x80409310: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E10) << 16);
    // 0x80409314: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80409318: nop

    // 0x8040931C: bc1f        L_80409350
    if (!c1cs) {
        // 0x80409320: nop
    
            goto L_80409350;
    }
    // 0x80409320: nop

    // 0x80409324: lwc1        $f4, -0x5820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E10));
    // 0x80409328: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8040932C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80409330: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80409334: nop

    // 0x80409338: bc1fl       L_80409350
    if (!c1cs) {
        // 0x8040933C: swc1        $f0, 0xB48($a0)
        MEM_W(0XB48, ctx->r4) = ctx->f0.u32l;
            goto L_80409350;
    }
    goto skip_0;
    // 0x8040933C: swc1        $f0, 0xB48($a0)
    MEM_W(0XB48, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x80409340: swc1        $f2, 0xB48($a0)
    MEM_W(0XB48, ctx->r4) = ctx->f2.u32l;
    // 0x80409344: jr          $ra
    // 0x80409348: sw          $t6, 0xB4C($a0)
    MEM_W(0XB4C, ctx->r4) = ctx->r14;
    return;
    // 0x80409348: sw          $t6, 0xB4C($a0)
    MEM_W(0XB4C, ctx->r4) = ctx->r14;
    // 0x8040934C: swc1        $f0, 0xB48($a0)
    MEM_W(0XB48, ctx->r4) = ctx->f0.u32l;
L_80409350:
    // 0x80409350: jr          $ra
    // 0x80409354: nop

    return;
    // 0x80409354: nop

;}
RECOMP_FUNC void func_804B6660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6660: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804B6664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B6668: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804B666C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804B6670: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804B6674: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804B6678: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x804B667C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6684: jal         0x804B6580
    // 0x804B6688: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_804B6580(rdram, ctx);
        goto after_0;
    // 0x804B6688: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x804B668C: lw          $t7, 0x1E0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1E0);
    // 0x804B6690: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x804B6694: slti        $at, $t8, 0x15
    ctx->r1 = SIGNED(ctx->r24) < 0X15 ? 1 : 0;
    // 0x804B6698: bne         $at, $zero, L_804B66E4
    if (ctx->r1 != 0) {
        // 0x804B669C: sw          $t8, 0x1E0($s1)
        MEM_W(0X1E0, ctx->r17) = ctx->r24;
            goto L_804B66E4;
    }
    // 0x804B669C: sw          $t8, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r24;
    // 0x804B66A0: jal         0x8004A73C
    // 0x804B66A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8004A73C(rdram, ctx);
        goto after_1;
    // 0x804B66A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x804B66A8: jal         0x8005FDC4
    // 0x804B66AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x804B66AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x804B66B0: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x804B66B4: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x804B66B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804B66BC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x804B66C0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x804B66C4: lh          $t0, 0x144($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X144);
    // 0x804B66C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B66CC: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
    // 0x804B66D0: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x804B66D4: jal         0x804B6FF0
    // 0x804B66D8: lbu         $a2, 0x30($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X30);
    func_804B6FF0(rdram, ctx);
        goto after_3;
    // 0x804B66D8: lbu         $a2, 0x30($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X30);
    after_3:
    // 0x804B66DC: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x804B66E0: sh          $t1, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r9;
L_804B66E4:
    // 0x804B66E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804B66E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804B66EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804B66F0: jr          $ra
    // 0x804B66F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804B66F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804B62A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B62A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B62A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B62A8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804B62AC: slti        $at, $v0, 0x4045
    ctx->r1 = SIGNED(ctx->r2) < 0X4045 ? 1 : 0;
    // 0x804B62B0: bne         $at, $zero, L_804B62FC
    if (ctx->r1 != 0) {
        // 0x804B62B4: slti        $at, $v0, 0x464F
        ctx->r1 = SIGNED(ctx->r2) < 0X464F ? 1 : 0;
            goto L_804B62FC;
    }
    // 0x804B62B4: slti        $at, $v0, 0x464F
    ctx->r1 = SIGNED(ctx->r2) < 0X464F ? 1 : 0;
    // 0x804B62B8: bne         $at, $zero, L_804B62E0
    if (ctx->r1 != 0) {
        // 0x804B62BC: addiu       $t6, $v0, -0x46DB
        ctx->r14 = ADD32(ctx->r2, -0X46DB);
            goto L_804B62E0;
    }
    // 0x804B62BC: addiu       $t6, $v0, -0x46DB
    ctx->r14 = ADD32(ctx->r2, -0X46DB);
    // 0x804B62C0: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x804B62C4: beq         $at, $zero, L_804B63B0
    if (ctx->r1 == 0) {
        // 0x804B62C8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_804B63B0;
    }
    // 0x804B62C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804B62CC: lui         $at, 0x804B
    ctx->r1 = S32(RELOC_HI16(182, 0X11A0) << 16);
    // 0x804B62D0: addu        $at, $at, $t6
    gpr jr_addend_804B62D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x804B62D4: lw          $t6, 0x7440($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(182, 0X11A0));
    // 0x804B62D8: jr          $t6
    // 0x804B62DC: nop

    switch (jr_addend_804B62D8 >> 2) {
        case 0: goto L_804B6380; break;
        case 1: goto L_804B6380; break;
        case 2: goto L_804B6380; break;
        case 3: goto L_804B6380; break;
        case 4: goto L_804B6380; break;
        case 5: goto L_804B6380; break;
        default: switch_error(__func__, 0x804B62D8, 0x804B7440);
    }
    // 0x804B62DC: nop

L_804B62E0:
    // 0x804B62E0: addiu       $at, $zero, 0x4045
    ctx->r1 = ADD32(0, 0X4045);
    // 0x804B62E4: beq         $v0, $at, L_804B63A4
    if (ctx->r2 == ctx->r1) {
        // 0x804B62E8: addiu       $at, $zero, 0x464E
        ctx->r1 = ADD32(0, 0X464E);
            goto L_804B63A4;
    }
    // 0x804B62E8: addiu       $at, $zero, 0x464E
    ctx->r1 = ADD32(0, 0X464E);
    // 0x804B62EC: beq         $v0, $at, L_804B6374
    if (ctx->r2 == ctx->r1) {
        // 0x804B62F0: nop
    
            goto L_804B6374;
    }
    // 0x804B62F0: nop

    // 0x804B62F4: b           L_804B63B0
    // 0x804B62F8: nop

        goto L_804B63B0;
    // 0x804B62F8: nop

L_804B62FC:
    // 0x804B62FC: addiu       $at, $zero, 0x403A
    ctx->r1 = ADD32(0, 0X403A);
    // 0x804B6300: beq         $v0, $at, L_804B6324
    if (ctx->r2 == ctx->r1) {
        // 0x804B6304: lui         $t7, 0x804B
        ctx->r15 = S32(RELOC_HI16(182, 0XF20) << 16);
            goto L_804B6324;
    }
    // 0x804B6304: lui         $t7, 0x804B
    ctx->r15 = S32(RELOC_HI16(182, 0XF20) << 16);
    // 0x804B6308: addiu       $at, $zero, 0x4043
    ctx->r1 = ADD32(0, 0X4043);
    // 0x804B630C: beq         $v0, $at, L_804B638C
    if (ctx->r2 == ctx->r1) {
        // 0x804B6310: addiu       $at, $zero, 0x4044
        ctx->r1 = ADD32(0, 0X4044);
            goto L_804B638C;
    }
    // 0x804B6310: addiu       $at, $zero, 0x4044
    ctx->r1 = ADD32(0, 0X4044);
    // 0x804B6314: beq         $v0, $at, L_804B6398
    if (ctx->r2 == ctx->r1) {
        // 0x804B6318: nop
    
            goto L_804B6398;
    }
    // 0x804B6318: nop

    // 0x804B631C: b           L_804B63B0
    // 0x804B6320: nop

        goto L_804B63B0;
    // 0x804B6320: nop

L_804B6324:
    // 0x804B6324: lw          $t7, 0x71C0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(182, 0XF20));
    // 0x804B6328: lui         $a0, 0x804B
    ctx->r4 = S32(RELOC_HI16(182, 0X13F0) << 16);
    // 0x804B632C: addiu       $a0, $a0, 0x7690
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(182, 0X13F0));
    // 0x804B6330: bne         $t7, $zero, L_804B6368
    if (ctx->r15 != 0) {
        // 0x804B6334: lui         $a1, 0x804B
        ctx->r5 = S32(RELOC_HI16(182, 0X1400) << 16);
            goto L_804B6368;
    }
    // 0x804B6334: lui         $a1, 0x804B
    ctx->r5 = S32(RELOC_HI16(182, 0X1400) << 16);
    // 0x804B6338: addiu       $a1, $a1, 0x76A0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(182, 0X1400));
    // 0x804B633C: jal         0x8004667C
    // 0x804B6340: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804B6340: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x804B6344: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804B6348: lui         $a2, 0x804B
    ctx->r6 = S32(RELOC_HI16(182, 0XE84) << 16);
    // 0x804B634C: addiu       $a2, $a2, 0x7124
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(182, 0XE84));
    // 0x804B6350: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804B6354: jal         0x80057B28
    // 0x804B6358: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804B6358: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_1:
    // 0x804B635C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804B6360: lui         $at, 0x804B
    ctx->r1 = S32(RELOC_HI16(182, 0XF20) << 16);
    // 0x804B6364: sw          $t8, 0x71C0($at)
    MEM_W((int16_t)RELOC_LO16(182, 0XF20), ctx->r1) = ctx->r24;
L_804B6368:
    // 0x804B6368: lui         $v0, 0x804B
    ctx->r2 = S32(RELOC_HI16(182, 0X9DC) << 16);
    // 0x804B636C: b           L_804B63B8
    // 0x804B6370: addiu       $v0, $v0, 0x6C7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0X9DC));
        goto L_804B63B8;
    // 0x804B6370: addiu       $v0, $v0, 0x6C7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0X9DC));
L_804B6374:
    // 0x804B6374: lui         $v0, 0x804B
    ctx->r2 = S32(RELOC_HI16(182, 0X9DC) << 16);
    // 0x804B6378: b           L_804B63B8
    // 0x804B637C: addiu       $v0, $v0, 0x6C7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0X9DC));
        goto L_804B63B8;
    // 0x804B637C: addiu       $v0, $v0, 0x6C7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0X9DC));
L_804B6380:
    // 0x804B6380: lui         $v0, 0x804B
    ctx->r2 = S32(RELOC_HI16(182, 0XB88) << 16);
    // 0x804B6384: b           L_804B63B8
    // 0x804B6388: addiu       $v0, $v0, 0x6E28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0XB88));
        goto L_804B63B8;
    // 0x804B6388: addiu       $v0, $v0, 0x6E28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0XB88));
L_804B638C:
    // 0x804B638C: lui         $v0, 0x804B
    ctx->r2 = S32(RELOC_HI16(182, 0XC08) << 16);
    // 0x804B6390: b           L_804B63B8
    // 0x804B6394: addiu       $v0, $v0, 0x6EA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0XC08));
        goto L_804B63B8;
    // 0x804B6394: addiu       $v0, $v0, 0x6EA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0XC08));
L_804B6398:
    // 0x804B6398: lui         $v0, 0x804B
    ctx->r2 = S32(RELOC_HI16(182, 0XC88) << 16);
    // 0x804B639C: b           L_804B63B8
    // 0x804B63A0: addiu       $v0, $v0, 0x6F28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0XC88));
        goto L_804B63B8;
    // 0x804B63A0: addiu       $v0, $v0, 0x6F28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0XC88));
L_804B63A4:
    // 0x804B63A4: lui         $v0, 0x804B
    ctx->r2 = S32(RELOC_HI16(182, 0XD08) << 16);
    // 0x804B63A8: b           L_804B63B8
    // 0x804B63AC: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0XD08));
        goto L_804B63B8;
    // 0x804B63AC: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0XD08));
L_804B63B0:
    // 0x804B63B0: lui         $v0, 0x804B
    ctx->r2 = S32(RELOC_HI16(182, 0X9DC) << 16);
    // 0x804B63B4: addiu       $v0, $v0, 0x6C7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(182, 0X9DC));
L_804B63B8:
    // 0x804B63B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B63BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B63C0: jr          $ra
    // 0x804B63C4: nop

    return;
    // 0x804B63C4: nop

;}
RECOMP_FUNC void func_8064C488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C488: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C48C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064C490: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8064C494: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C498: jr          $ra
    // 0x8064C49C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8064C49C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_800732C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800732C8: lhu         $t6, 0x8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8);
    // 0x800732CC: lbu         $t7, 0x5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5);
    // 0x800732D0: lbu         $t8, 0x4($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4);
    // 0x800732D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800732D8: sllv        $v0, $t6, $t7
    ctx->r2 = S32(ctx->r14 << (ctx->r15 & 31));
    // 0x800732DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800732E0: bne         $t8, $at, L_800732F0
    if (ctx->r24 != ctx->r1) {
        // 0x800732E4: sra         $v0, $v0, 1
        ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800732F0;
    }
    // 0x800732E4: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800732E8: b           L_800732F4
    // 0x800732EC: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
        goto L_800732F4;
    // 0x800732EC: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
L_800732F0:
    // 0x800732F0: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
L_800732F4:
    // 0x800732F4: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x800732F8: lhu         $a3, 0xA($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0XA);
    // 0x800732FC: mflo        $a1
    ctx->r5 = lo;
    // 0x80073300: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80073304: bne         $v0, $zero, L_80073310
    if (ctx->r2 != 0) {
        // 0x80073308: nop
    
            goto L_80073310;
    }
    // 0x80073308: nop

    // 0x8007330C: break       7
    do_break(2147955468);
L_80073310:
    // 0x80073310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80073314: bne         $v0, $at, L_80073328
    if (ctx->r2 != ctx->r1) {
        // 0x80073318: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80073328;
    }
    // 0x80073318: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007331C: bne         $v1, $at, L_80073328
    if (ctx->r3 != ctx->r1) {
        // 0x80073320: nop
    
            goto L_80073328;
    }
    // 0x80073320: nop

    // 0x80073324: break       6
    do_break(2147955492);
L_80073328:
    // 0x80073328: addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
    // 0x8007332C: blez        $t0, L_80073364
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80073330: sb          $zero, 0x15($a0)
        MEM_B(0X15, ctx->r4) = 0;
            goto L_80073364;
    }
    // 0x80073330: sb          $zero, 0x15($a0)
    MEM_B(0X15, ctx->r4) = 0;
L_80073334:
    // 0x80073334: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x80073338: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007333C: beql        $at, $zero, L_80073350
    if (ctx->r1 == 0) {
        // 0x80073340: lbu         $t9, 0x15($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X15);
            goto L_80073350;
    }
    goto skip_0;
    // 0x80073340: lbu         $t9, 0x15($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X15);
    skip_0:
    // 0x80073344: subu        $a1, $a3, $a2
    ctx->r5 = SUB32(ctx->r7, ctx->r6);
    // 0x80073348: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x8007334C: lbu         $t9, 0x15($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X15);
L_80073350:
    // 0x80073350: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x80073354: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80073358: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8007335C: bne         $at, $zero, L_80073334
    if (ctx->r1 != 0) {
        // 0x80073360: sb          $t1, 0x15($a0)
        MEM_B(0X15, ctx->r4) = ctx->r9;
            goto L_80073334;
    }
    // 0x80073360: sb          $t1, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r9;
L_80073364:
    // 0x80073364: jr          $ra
    // 0x80073368: nop

    return;
    // 0x80073368: nop

;}
RECOMP_FUNC void func_80444A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444A40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80444A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80444A48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80444A4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80444A50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80444A54: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80444A58: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80444A5C: jal         0x80047090
    // 0x80444A60: addiu       $a0, $zero, 0x40EE
    ctx->r4 = ADD32(0, 0X40EE);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80444A60: addiu       $a0, $zero, 0x40EE
    ctx->r4 = ADD32(0, 0X40EE);
    after_0:
    // 0x80444A64: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80444A68: beq         $v0, $at, L_80444AA0
    if (ctx->r2 == ctx->r1) {
        // 0x80444A6C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80444AA0;
    }
    // 0x80444A6C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80444A70: lui         $at, 0x40EE
    ctx->r1 = S32(0X40EE << 16);
    // 0x80444A74: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80444A78: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80444A7C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80444A80: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80444A84: jal         0x8004613C
    // 0x80444A88: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80444A88: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80444A8C: beq         $v0, $zero, L_80444AA0
    if (ctx->r2 == 0) {
        // 0x80444A90: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80444AA0;
    }
    // 0x80444A90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80444A94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80444A98: jal         0x80047F9C
    // 0x80444A9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444A9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_80444AA0:
    // 0x80444AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80444AA4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80444AA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80444AAC: jr          $ra
    // 0x80444AB0: nop

    return;
    // 0x80444AB0: nop

;}
RECOMP_FUNC void func_80062DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80062DDC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80062DE0: bltz        $a0, L_80062DF4
    if (SIGNED(ctx->r4) < 0) {
        // 0x80062DE4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80062DF4;
    }
    // 0x80062DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062DE8: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x80062DEC: bne         $at, $zero, L_80062DFC
    if (ctx->r1 != 0) {
        // 0x80062DF0: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80062DFC;
    }
    // 0x80062DF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
L_80062DF4:
    // 0x80062DF4: b           L_80062E14
    // 0x80062DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80062E14;
    // 0x80062DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80062DFC:
    // 0x80062DFC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80062E00: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80062E04: lw          $t9, 0x6570($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6570);
    // 0x80062E08: jalr        $t9
    // 0x80062E0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80062E0C: nop

    after_0:
    // 0x80062E10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80062E14:
    // 0x80062E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062E1C: jr          $ra
    // 0x80062E20: nop

    return;
    // 0x80062E20: nop

    // 0x80062E24: nop

    // 0x80062E28: nop

    // 0x80062E2C: nop

;}
RECOMP_FUNC void func_80028118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002811C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028120: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80028124: lbu         $t6, 0x1F8($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1F8);
    // 0x80028128: sw          $a1, 0x9C($a3)
    MEM_W(0X9C, ctx->r7) = ctx->r5;
    // 0x8002812C: addiu       $a1, $a0, 0x14C
    ctx->r5 = ADD32(ctx->r4, 0X14C);
    // 0x80028130: bne         $t6, $zero, L_80028144
    if (ctx->r14 != 0) {
        // 0x80028134: sw          $a2, 0xA0($a3)
        MEM_W(0XA0, ctx->r7) = ctx->r6;
            goto L_80028144;
    }
    // 0x80028134: sw          $a2, 0xA0($a3)
    MEM_W(0XA0, ctx->r7) = ctx->r6;
    // 0x80028138: lw          $t7, 0x12EC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X12EC);
    // 0x8002813C: beql        $t7, $zero, L_80028154
    if (ctx->r15 == 0) {
        // 0x80028140: lw          $t9, 0x9C($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X9C);
            goto L_80028154;
    }
    goto skip_0;
    // 0x80028140: lw          $t9, 0x9C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X9C);
    skip_0:
L_80028144:
    // 0x80028144: lw          $t8, 0xA0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XA0);
    // 0x80028148: b           L_80028158
    // 0x8002814C: sw          $t8, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r24;
        goto L_80028158;
    // 0x8002814C: sw          $t8, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r24;
    // 0x80028150: lw          $t9, 0x9C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X9C);
L_80028154:
    // 0x80028154: sw          $t9, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r25;
L_80028158:
    // 0x80028158: jal         0x80027F00
    // 0x8002815C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80027F00(rdram, ctx);
        goto after_0;
    // 0x8002815C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80028160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028168: jr          $ra
    // 0x8002816C: nop

    return;
    // 0x8002816C: nop

;}
RECOMP_FUNC void func_80530BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80530BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80530BDC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80530BE0: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(339, 0X400) << 16);
    // 0x80530BE4: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x80530BE8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80530BEC: addiu       $t6, $t6, 0xD20
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(339, 0X400));
    // 0x80530BF0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80530BF4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80530BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80530BFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80530C00: jal         0x80530C4C
    // 0x80530C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80530C4C(rdram, ctx);
        goto after_0;
    // 0x80530C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80530C08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80530C0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80530C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80530C14: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80530C18: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x80530C1C: jal         0x80045A34
    // 0x80530C20: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80530C20: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x80530C24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80530C28: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(339, 0X13C) << 16);
    // 0x80530C2C: addiu       $t9, $t9, 0xA5C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(339, 0X13C));
    // 0x80530C30: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80530C34: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80530C38: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80530C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80530C40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80530C44: jr          $ra
    // 0x80530C48: nop

    return;
    // 0x80530C48: nop

;}
RECOMP_FUNC void func_80554F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554F68: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80554F6C: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(357, 0XF54) << 16);
    // 0x80554F70: addiu       $t6, $t6, 0x5E44
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(357, 0XF54));
    // 0x80554F74: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80554F78: jr          $ra
    // 0x80554F7C: sw          $t6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r14;
    return;
    // 0x80554F7C: sw          $t6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void ViMode_LogPrint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E470: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007E474: jr          $ra
    // 0x8007E478: nop

    return;
    // 0x8007E478: nop

;}
RECOMP_FUNC void func_807AAA14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AAA14: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807AAA18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AAA1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807AAA20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807AAA24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807AAA28: jal         0x8004700C
    // 0x807AAA2C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807AAA2C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x807AAA30: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x807AAA34: lwc1        $f2, 0x40($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X40);
    // 0x807AAA38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AAA3C: jal         0x807A9D84
    // 0x807AAA40: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_807A9D84(rdram, ctx);
        goto after_1;
    // 0x807AAA40: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x807AAA44: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x807AAA48: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x807AAA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AAA50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AAA54: swc1        $f8, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f8.u32l;
    // 0x807AAA58: jal         0x807AA878
    // 0x807AAA5C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    func_807AA878(rdram, ctx);
        goto after_2;
    // 0x807AAA5C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    after_2:
    // 0x807AAA60: lw          $t6, 0xC8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC8);
    // 0x807AAA64: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x807AAA68: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x807AAA6C: beq         $t6, $zero, L_807AAB78
    if (ctx->r14 == 0) {
        // 0x807AAA70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807AAB78;
    }
    // 0x807AAA70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AAA74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807AAA78: lwc1        $f0, 0xF8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x807AAA7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x807AAA80: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x807AAA84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807AAA88: nop

    // 0x807AAA8C: bc1fl       L_807AAA9C
    if (!c1cs) {
        // 0x807AAA90: swc1        $f2, 0x40($s1)
        MEM_W(0X40, ctx->r17) = ctx->f2.u32l;
            goto L_807AAA9C;
    }
    goto skip_0;
    // 0x807AAA90: swc1        $f2, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f2.u32l;
    skip_0:
    // 0x807AAA94: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x807AAA98: swc1        $f2, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f2.u32l;
L_807AAA9C:
    // 0x807AAA9C: jal         0x807AA908
    // 0x807AAAA0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_807AA908(rdram, ctx);
        goto after_3;
    // 0x807AAAA0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x807AAAA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807AAAA8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807AAAAC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C08) << 16);
    // 0x807AAAB0: lwc1        $f16, -0x47B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C08));
    // 0x807AAAB4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C0C) << 16);
    // 0x807AAAB8: lwc1        $f4, -0x47B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C0C));
    // 0x807AAABC: lwc1        $f18, 0xCC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAAC0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x807AAAC4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807AAAC8: swc1        $f6, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f6.u32l;
    // 0x807AAACC: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAAD0: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x807AAAD4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x807AAAD8: nop

    // 0x807AAADC: bc1tl       L_807AAB0C
    if (c1cs) {
        // 0x807AAAE0: lwc1        $f10, 0xF8($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0XF8);
            goto L_807AAB0C;
    }
    goto skip_1;
    // 0x807AAAE0: lwc1        $f10, 0xF8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF8);
    skip_1:
    // 0x807AAAE4: add.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x807AAAE8: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x807AAAEC: nop

    // 0x807AAAF0: bc1tl       L_807AAB40
    if (c1cs) {
        // 0x807AAAF4: lui         $at, 0xC1C8
        ctx->r1 = S32(0XC1C8 << 16);
            goto L_807AAB40;
    }
    goto skip_2;
    // 0x807AAAF4: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    skip_2:
    // 0x807AAAF8: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x807AAAFC: nop

    // 0x807AAB00: bc1tl       L_807AAB40
    if (c1cs) {
        // 0x807AAB04: lui         $at, 0xC1C8
        ctx->r1 = S32(0XC1C8 << 16);
            goto L_807AAB40;
    }
    goto skip_3;
    // 0x807AAB04: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    skip_3:
    // 0x807AAB08: lwc1        $f10, 0xF8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF8);
L_807AAB0C:
    // 0x807AAB0C: swc1        $f14, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f14.u32l;
    // 0x807AAB10: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x807AAB14: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x807AAB18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807AAB1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AAB20: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807AAB24: bc1fl       L_807AAB40
    if (!c1cs) {
        // 0x807AAB28: lui         $at, 0xC1C8
        ctx->r1 = S32(0XC1C8 << 16);
            goto L_807AAB40;
    }
    goto skip_4;
    // 0x807AAB28: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    skip_4:
    // 0x807AAB2C: sw          $t7, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r15;
    // 0x807AAB30: sw          $zero, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = 0;
    // 0x807AAB34: jal         0x807AB278
    // 0x807AAB38: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_807AB278(rdram, ctx);
        goto after_4;
    // 0x807AAB38: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_4:
    // 0x807AAB3C: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
L_807AAB40:
    // 0x807AAB40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807AAB44: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x807AAB48: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x807AAB4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807AAB50: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x807AAB54: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x807AAB58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807AAB5C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807AAB60: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807AAB64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AAB68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AAB6C: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x807AAB70: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807AAB74: swc1        $f6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f6.u32l;
L_807AAB78:
    // 0x807AAB78: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807AAB7C: beql        $v0, $zero, L_807AABE4
    if (ctx->r2 == 0) {
        // 0x807AAB80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807AABE4;
    }
    goto skip_5;
    // 0x807AAB80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x807AAB84: lwc1        $f8, 0x84($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X84);
    // 0x807AAB88: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807AAB8C: jal         0x80065954
    // 0x807AAB90: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x807AAB90: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_5:
    // 0x807AAB94: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x807AAB98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807AAB9C: nop

    // 0x807AABA0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x807AABA4: nop

    // 0x807AABA8: bc1fl       L_807AABE4
    if (!c1cs) {
        // 0x807AABAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807AABE4;
    }
    goto skip_6;
    // 0x807AABAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x807AABB0: lw          $t8, 0xC8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC8);
    // 0x807AABB4: bnel        $t8, $zero, L_807AABE4
    if (ctx->r24 != 0) {
        // 0x807AABB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807AABE4;
    }
    goto skip_7;
    // 0x807AABB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x807AABBC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x807AABC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807AABC4: sw          $t9, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r25;
    // 0x807AABC8: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x807AABCC: jal         0x80067BBC
    // 0x807AABD0: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x807AABD0: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    after_6:
    // 0x807AABD4: addiu       $a0, $zero, 0x274
    ctx->r4 = ADD32(0, 0X274);
    // 0x807AABD8: jal         0x80067818
    // 0x807AABDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x807AABDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x807AABE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AABE4:
    // 0x807AABE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807AABE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807AABEC: jr          $ra
    // 0x807AABF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807AABF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800685F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685F0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800685F4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800685F8: lh          $t6, 0x992($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X992);
    // 0x800685FC: bne         $t6, $zero, L_80068610
    if (ctx->r14 != 0) {
        // 0x80068600: nop
    
            goto L_80068610;
    }
    // 0x80068600: nop

    // 0x80068604: lh          $t7, 0x9A6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X9A6);
    // 0x80068608: beql        $t7, $zero, L_8006861C
    if (ctx->r15 == 0) {
        // 0x8006860C: lw          $t8, 0x3EC($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X3EC);
            goto L_8006861C;
    }
    goto skip_0;
    // 0x8006860C: lw          $t8, 0x3EC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3EC);
    skip_0:
L_80068610:
    // 0x80068610: jr          $ra
    // 0x80068614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80068614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80068618: lw          $t8, 0x3EC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3EC);
L_8006861C:
    // 0x8006861C: bnel        $t8, $zero, L_80068630
    if (ctx->r24 != 0) {
        // 0x80068620: sw          $zero, 0x3F0($v0)
        MEM_W(0X3F0, ctx->r2) = 0;
            goto L_80068630;
    }
    goto skip_1;
    // 0x80068620: sw          $zero, 0x3F0($v0)
    MEM_W(0X3F0, ctx->r2) = 0;
    skip_1:
    // 0x80068624: b           L_80068630
    // 0x80068628: sw          $zero, 0x3F0($v0)
    MEM_W(0X3F0, ctx->r2) = 0;
        goto L_80068630;
    // 0x80068628: sw          $zero, 0x3F0($v0)
    MEM_W(0X3F0, ctx->r2) = 0;
    // 0x8006862C: sw          $zero, 0x3F0($v0)
    MEM_W(0X3F0, ctx->r2) = 0;
L_80068630:
    // 0x80068630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80068634: jr          $ra
    // 0x80068638: nop

    return;
    // 0x80068638: nop

;}
RECOMP_FUNC void func_8052C9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C9BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8052C9C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052C9C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8052C9C8: jal         0x80045A34
    // 0x8052C9CC: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8052C9CC: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_0:
    // 0x8052C9D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8052C9D4: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8052C9D8: bne         $v0, $zero, L_8052C9E8
    if (ctx->r2 != 0) {
        // 0x8052C9DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052C9E8;
    }
    // 0x8052C9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052C9E0: b           L_8052C9EC
    // 0x8052C9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8052C9EC;
    // 0x8052C9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8052C9E8:
    // 0x8052C9E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8052C9EC:
    // 0x8052C9EC: jr          $ra
    // 0x8052C9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8052C9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80519668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051966C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519670: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80519674: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80519678: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8051967C: jal         0x80067BBC
    // 0x80519680: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80519680: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80519684: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x80519688: jal         0x80067818
    // 0x8051968C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8051968C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80519690: jal         0x80517D80
    // 0x80519694: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80517D80(rdram, ctx);
        goto after_2;
    // 0x80519694: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80519698: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8051969C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805196A0: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x805196A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805196A8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805196AC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x805196B0: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x805196B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805196B8: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x805196BC: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    // 0x805196C0: jr          $ra
    // 0x805196C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805196C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804686B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804686B4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804686B8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804686BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804686C0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804686C4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804686C8: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x804686CC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804686D0: lui         $t1, 0x8047
    ctx->r9 = S32(RELOC_HI16(132, 0X1DB0) << 16);
    // 0x804686D4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804686D8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804686DC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804686E0: lw          $t1, -0x7910($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(132, 0X1DB0));
    // 0x804686E4: jr          $ra
    // 0x804686E8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804686E8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804686EC: nop

;}
RECOMP_FUNC void func_80736550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736550: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80736554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736558: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073655C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80736560: jal         0x8004700C
    // 0x80736564: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80736564: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80736568: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8073656C: beq         $v0, $zero, L_807366F8
    if (ctx->r2 == 0) {
        // 0x80736570: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_807366F8;
    }
    // 0x80736570: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80736574: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80736578: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8073657C: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x80736580: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B34) << 16);
    // 0x80736584: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80736588: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8073658C: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80736590: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80736594: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80736598: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8073659C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807365A0: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x807365A4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807365A8: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x807365AC: nop

    // 0x807365B0: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807365B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807365B8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x807365BC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x807365C0: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x807365C4: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x807365C8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x807365CC: nop

    // 0x807365D0: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x807365D4: lwc1        $f8, -0x6A6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B34));
    // 0x807365D8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B38) << 16);
    // 0x807365DC: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x807365E0: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x807365E4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807365E8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x807365EC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807365F0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x807365F4: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x807365F8: bc1t        L_80736624
    if (c1cs) {
        // 0x807365FC: nop
    
            goto L_80736624;
    }
    // 0x807365FC: nop

    // 0x80736600: lwc1        $f6, -0x6A68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B38));
    // 0x80736604: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80736608: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8073660C: nop

    // 0x80736610: bc1t        L_80736624
    if (c1cs) {
        // 0x80736614: nop
    
            goto L_80736624;
    }
    // 0x80736614: nop

    // 0x80736618: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8073661C: b           L_8073663C
    // 0x80736620: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8073663C;
    // 0x80736620: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_80736624:
    // 0x80736624: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80736628: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8073662C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80736630: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80736634: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80736638: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
L_8073663C:
    // 0x8073663C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80736640: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80736644: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80736648: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8073664C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80736650: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80736654: nop

    // 0x80736658: bc1fl       L_807366A8
    if (!c1cs) {
        // 0x8073665C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_807366A8;
    }
    goto skip_0;
    // 0x8073665C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x80736660: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80736664: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80736668: sub.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x8073666C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80736670: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80736674: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80736678: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8073667C: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80736680: swc1        $f6, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f6.u32l;
    // 0x80736684: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80736688: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8073668C: nop

    // 0x80736690: bc1fl       L_807366E4
    if (!c1cs) {
        // 0x80736694: lwc1        $f4, 0x50($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
            goto L_807366E4;
    }
    goto skip_1;
    // 0x80736694: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    skip_1:
    // 0x80736698: swc1        $f2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f2.u32l;
    // 0x8073669C: b           L_807366E0
    // 0x807366A0: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
        goto L_807366E0;
    // 0x807366A0: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x807366A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_807366A8:
    // 0x807366A8: sub.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x807366AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807366B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807366B4: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x807366B8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807366BC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x807366C0: swc1        $f8, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f8.u32l;
    // 0x807366C4: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x807366C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807366CC: nop

    // 0x807366D0: bc1fl       L_807366E4
    if (!c1cs) {
        // 0x807366D4: lwc1        $f4, 0x50($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
            goto L_807366E4;
    }
    goto skip_2;
    // 0x807366D4: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    skip_2:
    // 0x807366D8: swc1        $f2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f2.u32l;
    // 0x807366DC: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
L_807366E0:
    // 0x807366E0: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
L_807366E4:
    // 0x807366E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x807366E8: jal         0x800659EC
    // 0x807366EC: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x807366EC: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    after_1:
    // 0x807366F0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x807366F4: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_807366F8:
    // 0x807366F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807366FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80736700: jr          $ra
    // 0x80736704: nop

    return;
    // 0x80736704: nop

;}
RECOMP_FUNC void func_80038B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038B00: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80038B04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038B08: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80038B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038B10: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80038B14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80038B18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80038B1C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80038B20: jal         0x80038A6C
    // 0x80038B24: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80038A6C(rdram, ctx);
        goto after_0;
    // 0x80038B24: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_0:
    // 0x80038B28: bne         $v0, $zero, L_80038B38
    if (ctx->r2 != 0) {
        // 0x80038B2C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80038B38;
    }
    // 0x80038B2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80038B30: b           L_80038BC0
    // 0x80038B34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038BC0;
    // 0x80038B34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038B38:
    // 0x80038B38: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80038B3C: sw          $a1, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r5;
    // 0x80038B40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038B44: jal         0x80047F9C
    // 0x80038B48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x80038B48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80038B4C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80038B50: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80038B54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038B58: lwc1        $f2, 0x138($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X138);
    // 0x80038B5C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80038B60: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x80038B64: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80038B68: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80038B6C: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    // 0x80038B70: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x80038B74: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80038B78: swc1        $f8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f8.u32l;
    // 0x80038B7C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80038B80: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80038B84: swc1        $f0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->f0.u32l;
    // 0x80038B88: swc1        $f0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f0.u32l;
    // 0x80038B8C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80038B90: mul.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80038B94: swc1        $f0, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->f0.u32l;
    // 0x80038B98: swc1        $f0, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f0.u32l;
    // 0x80038B9C: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80038BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80038BA4: mul.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80038BA8: swc1        $f0, 0x80($a1)
    MEM_W(0X80, ctx->r5) = ctx->f0.u32l;
    // 0x80038BAC: swc1        $f0, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f0.u32l;
    // 0x80038BB0: swc1        $f4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f4.u32l;
    // 0x80038BB4: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x80038BB8: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80038BBC: swc1        $f6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f6.u32l;
L_80038BC0:
    // 0x80038BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038BC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80038BC8: jr          $ra
    // 0x80038BCC: nop

    return;
    // 0x80038BCC: nop

;}
RECOMP_FUNC void func_806EF998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF998: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EF99C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EF9A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EF9A4: jal         0x8004700C
    // 0x806EF9A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EF9A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EF9AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EF9B0: jal         0x806EC16C
    // 0x806EF9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC16C(rdram, ctx);
        goto after_1;
    // 0x806EF9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EF9B8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EF9BC: jal         0x800577D8
    // 0x806EF9C0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_2;
    // 0x806EF9C0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x806EF9C4: jal         0x806EF504
    // 0x806EF9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF504(rdram, ctx);
        goto after_3;
    // 0x806EF9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EF9CC: jal         0x806EF584
    // 0x806EF9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF584(rdram, ctx);
        goto after_4;
    // 0x806EF9D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EF9D4: jal         0x806EF5CC
    // 0x806EF9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF5CC(rdram, ctx);
        goto after_5;
    // 0x806EF9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EF9DC: jal         0x806EF638
    // 0x806EF9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF638(rdram, ctx);
        goto after_6;
    // 0x806EF9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806EF9E4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806EF9E8: beql        $t7, $zero, L_806EFAA8
    if (ctx->r15 == 0) {
        // 0x806EF9EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EFAA8;
    }
    goto skip_0;
    // 0x806EF9EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EF9F0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806EF9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF9F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF9FC: blez        $v0, L_806EFA9C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806EFA00: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_806EFA9C;
    }
    // 0x806EFA00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EFA04: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x806EFA08: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x806EFA0C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806EFA10: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x806EFA14: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806EFA18: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806EFA1C: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x806EFA20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806EFA24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFA28: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EFA2C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806EFA30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806EFA34: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806EFA38: nop

    // 0x806EFA3C: bc1f        L_806EFA68
    if (!c1cs) {
        // 0x806EFA40: nop
    
            goto L_806EFA68;
    }
    // 0x806EFA40: nop

    // 0x806EFA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EFA48: jal         0x806F0348
    // 0x806EFA4C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_7;
    // 0x806EFA4C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806EFA50: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D78) << 16);
    // 0x806EFA54: lwc1        $f14, 0xCC8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D78));
    // 0x806EFA58: jal         0x806EC03C
    // 0x806EFA5C: lwc1        $f12, 0xEC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
    func_806EC03C(rdram, ctx);
        goto after_8;
    // 0x806EFA5C: lwc1        $f12, 0xEC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
    after_8:
    // 0x806EFA60: b           L_806EFAA4
    // 0x806EFA64: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
        goto L_806EFAA4;
    // 0x806EFA64: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
L_806EFA68:
    // 0x806EFA68: jal         0x806EBFB8
    // 0x806EFA6C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_806EBFB8(rdram, ctx);
        goto after_9;
    // 0x806EFA6C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_9:
    // 0x806EFA70: bnel        $v0, $zero, L_806EFAA8
    if (ctx->r2 != 0) {
        // 0x806EFA74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EFAA8;
    }
    goto skip_1;
    // 0x806EFA74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806EFA78: jal         0x806EF560
    // 0x806EFA7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF560(rdram, ctx);
        goto after_10;
    // 0x806EFA7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x806EFA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EFA84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFA88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EFA8C: jal         0x806F0348
    // 0x806EFA90: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_11;
    // 0x806EFA90: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_11:
    // 0x806EFA94: b           L_806EFAA8
    // 0x806EFA98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EFAA8;
    // 0x806EFA98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EFA9C:
    // 0x806EFA9C: jal         0x806F0348
    // 0x806EFAA0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_12;
    // 0x806EFAA0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_12:
L_806EFAA4:
    // 0x806EFAA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EFAA8:
    // 0x806EFAA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EFAAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EFAB0: jr          $ra
    // 0x806EFAB4: nop

    return;
    // 0x806EFAB4: nop

;}
RECOMP_FUNC void func_8057F964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057F968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F96C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47D0) << 16);
    // 0x8057F970: lwc1        $f0, 0x35E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47D0));
    // 0x8057F974: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8057F978: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8057F97C: nop

    // 0x8057F980: bc1fl       L_8057F9A0
    if (!c1cs) {
        // 0x8057F984: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_8057F9A0;
    }
    goto skip_0;
    // 0x8057F984: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x8057F988: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8057F98C: jal         0x8057F8C4
    // 0x8057F990: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_8057F8C4(rdram, ctx);
        goto after_0;
    // 0x8057F990: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x8057F994: b           L_8057F9AC
    // 0x8057F998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8057F9AC;
    // 0x8057F998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F99C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_8057F9A0:
    // 0x8057F9A0: jal         0x8057F914
    // 0x8057F9A4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_8057F914(rdram, ctx);
        goto after_1;
    // 0x8057F9A4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_1:
    // 0x8057F9A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057F9AC:
    // 0x8057F9AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057F9B0: jr          $ra
    // 0x8057F9B4: nop

    return;
    // 0x8057F9B4: nop

;}
RECOMP_FUNC void func_8006CFC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CFC0: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8006CFC4: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8006CFC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CFCC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006CFD0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8006CFD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CFD8: sw          $zero, 0xE74($a3)
    MEM_W(0XE74, ctx->r7) = 0;
    // 0x8006CFDC: sw          $zero, 0xE8C($a3)
    MEM_W(0XE8C, ctx->r7) = 0;
    // 0x8006CFE0: sw          $zero, 0xEA4($a3)
    MEM_W(0XEA4, ctx->r7) = 0;
    // 0x8006CFE4: sw          $zero, 0xEB4($a3)
    MEM_W(0XEB4, ctx->r7) = 0;
    // 0x8006CFE8: sw          $zero, 0xC78($a3)
    MEM_W(0XC78, ctx->r7) = 0;
    // 0x8006CFEC: addiu       $v1, $v1, 0x7EC8
    ctx->r3 = ADD32(ctx->r3, 0X7EC8);
    // 0x8006CFF0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
L_8006CFF4:
    // 0x8006CFF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006CFF8: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8006CFFC: bne         $at, $zero, L_8006CFF4
    if (ctx->r1 != 0) {
        // 0x8006D000: sw          $zero, 0xC78($v0)
        MEM_W(0XC78, ctx->r2) = 0;
            goto L_8006CFF4;
    }
    // 0x8006D000: sw          $zero, 0xC78($v0)
    MEM_W(0XC78, ctx->r2) = 0;
    // 0x8006D004: sw          $zero, 0xB1C($a3)
    MEM_W(0XB1C, ctx->r7) = 0;
    // 0x8006D008: sw          $zero, 0xB20($a3)
    MEM_W(0XB20, ctx->r7) = 0;
    // 0x8006D00C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8006D010: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006D014: sw          $t6, -0x74E4($at)
    MEM_W(-0X74E4, ctx->r1) = ctx->r14;
    // 0x8006D018: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006D01C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8006D020: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006D024: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8006D028: addiu       $a0, $a0, 0x7EC8
    ctx->r4 = ADD32(ctx->r4, 0X7EC8);
    // 0x8006D02C: addiu       $v0, $v0, 0x7EA8
    ctx->r2 = ADD32(ctx->r2, 0X7EA8);
    // 0x8006D030: sw          $t7, -0x74E0($at)
    MEM_W(-0X74E0, ctx->r1) = ctx->r15;
    // 0x8006D034: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8006D038:
    // 0x8006D038: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006D03C: sw          $v1, 0xC70($v0)
    MEM_W(0XC70, ctx->r2) = ctx->r3;
    // 0x8006D040: sw          $v1, 0xC74($v0)
    MEM_W(0XC74, ctx->r2) = ctx->r3;
    // 0x8006D044: sw          $v1, 0xC78($v0)
    MEM_W(0XC78, ctx->r2) = ctx->r3;
    // 0x8006D048: bne         $v0, $a0, L_8006D038
    if (ctx->r2 != ctx->r4) {
        // 0x8006D04C: sw          $v1, 0xC6C($v0)
        MEM_W(0XC6C, ctx->r2) = ctx->r3;
            goto L_8006D038;
    }
    // 0x8006D04C: sw          $v1, 0xC6C($v0)
    MEM_W(0XC6C, ctx->r2) = ctx->r3;
    // 0x8006D050: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8006D054: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006D058: sw          $zero, 0xAB0($a3)
    MEM_W(0XAB0, ctx->r7) = 0;
    // 0x8006D05C: sw          $zero, 0xAB4($a3)
    MEM_W(0XAB4, ctx->r7) = 0;
    // 0x8006D060: sw          $zero, 0xAB8($a3)
    MEM_W(0XAB8, ctx->r7) = 0;
    // 0x8006D064: sw          $zero, 0xABC($a3)
    MEM_W(0XABC, ctx->r7) = 0;
    // 0x8006D068: sw          $zero, 0xAC0($a3)
    MEM_W(0XAC0, ctx->r7) = 0;
    // 0x8006D06C: sw          $zero, 0xAC4($a3)
    MEM_W(0XAC4, ctx->r7) = 0;
    // 0x8006D070: sw          $zero, 0xAC8($a3)
    MEM_W(0XAC8, ctx->r7) = 0;
    // 0x8006D074: sw          $zero, 0xACC($a3)
    MEM_W(0XACC, ctx->r7) = 0;
    // 0x8006D078: sw          $zero, 0xAD0($a3)
    MEM_W(0XAD0, ctx->r7) = 0;
    // 0x8006D07C: sw          $zero, 0xAD4($a3)
    MEM_W(0XAD4, ctx->r7) = 0;
    // 0x8006D080: sw          $t8, 0xAA8($a3)
    MEM_W(0XAA8, ctx->r7) = ctx->r24;
    // 0x8006D084: sw          $zero, 0xAAC($a3)
    MEM_W(0XAAC, ctx->r7) = 0;
    // 0x8006D088: sw          $zero, 0xB30($a3)
    MEM_W(0XB30, ctx->r7) = 0;
    // 0x8006D08C: sw          $zero, 0xBAC($a3)
    MEM_W(0XBAC, ctx->r7) = 0;
    // 0x8006D090: sw          $zero, 0xC28($a3)
    MEM_W(0XC28, ctx->r7) = 0;
    // 0x8006D094: addiu       $a0, $a0, -0x762C
    ctx->r4 = ADD32(ctx->r4, -0X762C);
    // 0x8006D098: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8006D09C: jal         0x80065728
    // 0x8006D0A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8006D0A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006D0A4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006D0A8: addiu       $a0, $a0, -0x75B0
    ctx->r4 = ADD32(ctx->r4, -0X75B0);
    // 0x8006D0AC: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8006D0B0: jal         0x80065728
    // 0x8006D0B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x8006D0B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8006D0B8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8006D0BC: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8006D0C0: lw          $t9, 0xF54($a3)
    ctx->r25 = MEM_W(ctx->r7, 0XF54);
    // 0x8006D0C4: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8006D0C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D0CC: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8006D0D0: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8006D0D4: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8006D0D8: sw          $t0, 0xF54($a3)
    MEM_W(0XF54, ctx->r7) = ctx->r8;
    // 0x8006D0DC: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x8006D0E0: sw          $t2, 0xF54($a3)
    MEM_W(0XF54, ctx->r7) = ctx->r10;
    // 0x8006D0E4: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8006D0E8: sw          $t4, 0xF54($a3)
    MEM_W(0XF54, ctx->r7) = ctx->r12;
    // 0x8006D0EC: jr          $ra
    // 0x8006D0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006D0F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80669E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80669E80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80669E84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80669E88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80669E8C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80669E90: lui         $at, 0x4138
    ctx->r1 = S32(0X4138 << 16);
    // 0x80669E94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80669E98: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80669E9C: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x80669EA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80669EA4: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80669EA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80669EAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80669EB0: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80669EB4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80669EB8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80669EBC: nop

    // 0x80669EC0: bc1fl       L_80669ED4
    if (!c1cs) {
        // 0x80669EC4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80669ED4;
    }
    goto skip_0;
    // 0x80669EC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x80669EC8: b           L_80669EFC
    // 0x80669ECC: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
        goto L_80669EFC;
    // 0x80669ECC: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x80669ED0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80669ED4:
    // 0x80669ED4: nop

    // 0x80669ED8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80669EDC: nop

    // 0x80669EE0: bc1fl       L_80669EF4
    if (!c1cs) {
        // 0x80669EE4: trunc.w.s   $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_80669EF4;
    }
    goto skip_1;
    // 0x80669EE4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_1:
    // 0x80669EE8: b           L_80669EFC
    // 0x80669EEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80669EFC;
    // 0x80669EEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80669EF0: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
L_80669EF4:
    // 0x80669EF4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80669EF8: nop

L_80669EFC:
    // 0x80669EFC: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80669F00: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80669F04: bne         $a1, $at, L_80669F30
    if (ctx->r5 != ctx->r1) {
        // 0x80669F08: nop
    
            goto L_80669F30;
    }
    // 0x80669F08: nop

    // 0x80669F0C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80669F10: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80669F14: jal         0x80067D5C
    // 0x80669F18: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80669F18: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x80669F1C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80669F20: jal         0x80067F78
    // 0x80669F24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80669F24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80669F28: b           L_80669F90
    // 0x80669F2C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80669F90;
    // 0x80669F2C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_80669F30:
    // 0x80669F30: jal         0x80067930
    // 0x80669F34: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x80669F34: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x80669F38: beq         $v0, $zero, L_80669F70
    if (ctx->r2 == 0) {
        // 0x80669F3C: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80669F70;
    }
    // 0x80669F3C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80669F40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80669F44: bne         $v0, $at, L_80669F90
    if (ctx->r2 != ctx->r1) {
        // 0x80669F48: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80669F90;
    }
    // 0x80669F48: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80669F4C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80669F50: jal         0x80067D5C
    // 0x80669F54: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x80669F54: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80669F58: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80669F5C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80669F60: jal         0x800678F0
    // 0x80669F64: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x80669F64: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80669F68: b           L_80669F94
    // 0x80669F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80669F94;
    // 0x80669F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80669F70:
    // 0x80669F70: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80669F74: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80669F78: jal         0x80067D5C
    // 0x80669F7C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_5;
    // 0x80669F7C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80669F80: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80669F84: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80669F88: jal         0x80067838
    // 0x80669F8C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x80669F8C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_80669F90:
    // 0x80669F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80669F94:
    // 0x80669F94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80669F98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80669F9C: jr          $ra
    // 0x80669FA0: nop

    return;
    // 0x80669FA0: nop

;}
RECOMP_FUNC void func_8006C56C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C56C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006C570: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C578: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8006C57C: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8006C580: lw          $s0, -0x7D6C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D6C);
    // 0x8006C584: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006C588: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006C58C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8006C590: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8006C594: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006C598: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8006C59C: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006C5A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006C5A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006C5A8: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8006C5AC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006C5B0: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8006C5B4: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8006C5B8: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006C5BC: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x8006C5C0: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006C5C4: swc1        $f14, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f14.u32l;
    // 0x8006C5C8: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x8006C5CC: lwc1        $f10, 0x107C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X107C);
    // 0x8006C5D0: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8006C5D4: jal         0x80081C30
    // 0x8006C5D8: nop

    Math_FTanF(rdram, ctx);
        goto after_0;
    // 0x8006C5D8: nop

    after_0:
    // 0x8006C5DC: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8006C5E0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006C5E4: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8006C5E8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C5EC: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8006C5F0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8006C5F4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8006C5F8: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006C5FC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006C600: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C604: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8006C608: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006C60C: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8006C610: jal         0x80067114
    // 0x8006C614: sqrt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = sqrtf(ctx->f0.fl);
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x8006C614: sqrt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x8006C618: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8006C61C: jal         0x80066DE4
    // 0x8006C620: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8006C620: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x8006C624: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8006C628: jal         0x80066E88
    // 0x8006C62C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8006C62C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8006C630: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006C634: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006C638: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x8006C63C: jal         0x80066E88
    // 0x8006C640: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8006C640: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x8006C644: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8006C648: jal         0x80066DE4
    // 0x8006C64C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x8006C64C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x8006C650: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8006C654: jal         0x80066DE4
    // 0x8006C658: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8006C658: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8006C65C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006C660: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8006C664: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x8006C668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C66C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006C674: jr          $ra
    // 0x8006C678: nop

    return;
    // 0x8006C678: nop

;}
RECOMP_FUNC void func_805D7DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7DA4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805D7DA8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805D7DAC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805D7DB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805D7DB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805D7DB8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805D7DBC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805D7DC0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805D7DC4: lui         $t1, 0x805E
    ctx->r9 = S32(RELOC_HI16(474, 0X24CC) << 16);
    // 0x805D7DC8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805D7DCC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D7DD0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D7DD4: lw          $t1, -0x6234($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(474, 0X24CC));
    // 0x805D7DD8: jr          $ra
    // 0x805D7DDC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805D7DDC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804A5164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A5164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A5168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A516C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A5170: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804A5174: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804A5178: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804A517C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804A5180: lw          $v1, 0x6ED4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6ED4);
    // 0x804A5184: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x804A5188: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A518C: bne         $v1, $zero, L_804A51BC
    if (ctx->r3 != 0) {
        // 0x804A5190: nop
    
            goto L_804A51BC;
    }
    // 0x804A5190: nop

    // 0x804A5194: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x804A5198: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x804A519C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x804A51A0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x804A51A4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804A51A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804A51AC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x804A51B0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804A51B4: b           L_804A51C4
    // 0x804A51B8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_804A51C4;
    // 0x804A51B8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_804A51BC:
    // 0x804A51BC: jal         0x804A4D44
    // 0x804A51C0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_804A4D44(rdram, ctx);
        goto after_0;
    // 0x804A51C0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_0:
L_804A51C4:
    // 0x804A51C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A51C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A51CC: jr          $ra
    // 0x804A51D0: nop

    return;
    // 0x804A51D0: nop

;}
RECOMP_FUNC void func_8049F9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F9DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8049F9E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8049F9E4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8049F9E8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8049F9EC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8049F9F0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8049F9F4: lui         $t7, 0x804A
    ctx->r15 = S32(RELOC_HI16(167, 0X1160) << 16);
    // 0x8049F9F8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8049F9FC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8049FA00: addiu       $t7, $t7, -0x320
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(167, 0X1160));
    // 0x8049FA04: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8049FA08: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8049FA0C: jal         0x8049F130
    // 0x8049FA10: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_8049F130(rdram, ctx);
        goto after_0;
    // 0x8049FA10: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_0:
    // 0x8049FA14: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8049FA18: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8049FA1C: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x8049FA20: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x8049FA24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8049FA28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8049FA2C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8049FA30: jal         0x80048378
    // 0x8049FA34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8049FA34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x8049FA38: lw          $t2, 0x174($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X174);
    // 0x8049FA3C: lui         $t1, 0x804A
    ctx->r9 = S32(RELOC_HI16(167, 0XA78) << 16);
    // 0x8049FA40: addiu       $t1, $t1, -0xA08
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(167, 0XA78));
    // 0x8049FA44: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8049FA48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049FA4C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8049FA50: jal         0x80045A34
    // 0x8049FA54: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8049FA54: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    after_2:
    // 0x8049FA58: lui         $t4, 0x804A
    ctx->r12 = S32(RELOC_HI16(167, 0XC9C) << 16);
    // 0x8049FA5C: addiu       $t4, $t4, -0x7E4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(167, 0XC9C));
    // 0x8049FA60: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x8049FA64: sw          $t4, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = ctx->r12;
    // 0x8049FA68: jal         0x80058958
    // 0x8049FA6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_80058958(rdram, ctx);
        goto after_3;
    // 0x8049FA6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_3:
    // 0x8049FA70: beq         $v0, $zero, L_8049FAE4
    if (ctx->r2 == 0) {
        // 0x8049FA74: lui         $t5, 0x8010
        ctx->r13 = S32(0X8010 << 16);
            goto L_8049FAE4;
    }
    // 0x8049FA74: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8049FA78: lw          $t5, -0x7BC4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7BC4);
    // 0x8049FA7C: lw          $t6, 0x10C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10C);
    // 0x8049FA80: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8049FA84: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8049FA88: beql        $t8, $zero, L_8049FAE8
    if (ctx->r24 == 0) {
        // 0x8049FA8C: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_8049FAE8;
    }
    goto skip_0;
    // 0x8049FA8C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_0:
    // 0x8049FA90: jal         0x80056564
    // 0x8049FA94: nop

    func_80056564(rdram, ctx);
        goto after_4;
    // 0x8049FA94: nop

    after_4:
    // 0x8049FA98: beq         $v0, $zero, L_8049FAE8
    if (ctx->r2 == 0) {
        // 0x8049FA9C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8049FAE8;
    }
    // 0x8049FA9C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8049FAA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049FAA4: jal         0x800457A0
    // 0x8049FAA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_5;
    // 0x8049FAA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8049FAAC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8049FAB0: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x8049FAB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8049FAB8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8049FABC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8049FAC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8049FAC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8049FAC8: jal         0x80056584
    // 0x8049FACC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_6;
    // 0x8049FACC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_6:
    // 0x8049FAD0: lw          $t1, 0x16C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X16C);
    // 0x8049FAD4: lui         $t2, 0x804A
    ctx->r10 = S32(RELOC_HI16(167, 0XC58) << 16);
    // 0x8049FAD8: addiu       $t2, $t2, -0x828
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(167, 0XC58));
    // 0x8049FADC: b           L_8049FAE8
    // 0x8049FAE0: sw          $t2, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r10;
        goto L_8049FAE8;
    // 0x8049FAE0: sw          $t2, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r10;
L_8049FAE4:
    // 0x8049FAE4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8049FAE8:
    // 0x8049FAE8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8049FAEC: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x8049FAF0: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8049FAF4: lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XC);
    // 0x8049FAF8: addiu       $at, $zero, 0x4054
    ctx->r1 = ADD32(0, 0X4054);
    // 0x8049FAFC: beq         $v0, $at, L_8049FB14
    if (ctx->r2 == ctx->r1) {
        // 0x8049FB00: addiu       $at, $zero, 0x4056
        ctx->r1 = ADD32(0, 0X4056);
            goto L_8049FB14;
    }
    // 0x8049FB00: addiu       $at, $zero, 0x4056
    ctx->r1 = ADD32(0, 0X4056);
    // 0x8049FB04: beql        $v0, $at, L_8049FB54
    if (ctx->r2 == ctx->r1) {
        // 0x8049FB08: lhu         $t8, 0x8($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X8);
            goto L_8049FB54;
    }
    goto skip_1;
    // 0x8049FB08: lhu         $t8, 0x8($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X8);
    skip_1:
    // 0x8049FB0C: b           L_8049FB9C
    // 0x8049FB10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8049FB9C;
    // 0x8049FB10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8049FB14:
    // 0x8049FB14: lhu         $t4, 0x8($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X8);
    // 0x8049FB18: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8049FB1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8049FB20: ori         $t6, $t4, 0x2
    ctx->r14 = ctx->r12 | 0X2;
    // 0x8049FB24: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x8049FB28: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8049FB2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8049FB30: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8049FB34: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8049FB38: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8049FB3C: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x8049FB40: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8049FB44: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8049FB48: b           L_8049FB98
    // 0x8049FB4C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
        goto L_8049FB98;
    // 0x8049FB4C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8049FB50: lhu         $t8, 0x8($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X8);
L_8049FB54:
    // 0x8049FB54: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x8049FB58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8049FB5C: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8049FB60: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x8049FB64: lwc1        $f16, 0x3C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8049FB68: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8049FB6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8049FB70: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8049FB74: lwc1        $f18, 0x40($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8049FB78: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8049FB7C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8049FB80: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8049FB84: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8049FB88: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8049FB8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8049FB90: nop

    // 0x8049FB94: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
L_8049FB98:
    // 0x8049FB98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8049FB9C:
    // 0x8049FB9C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8049FBA0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8049FBA4: jr          $ra
    // 0x8049FBA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8049FBA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80665030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80665034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80665038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8066503C: jal         0x80045A34
    // 0x80665040: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80665040: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x80665044: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80665048: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8066504C: bne         $v0, $zero, L_8066505C
    if (ctx->r2 != 0) {
        // 0x80665050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066505C;
    }
    // 0x80665050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80665054: b           L_80665060
    // 0x80665058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80665060;
    // 0x80665058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8066505C:
    // 0x8066505C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80665060:
    // 0x80665060: jr          $ra
    // 0x80665064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80665064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002FEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FEF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FF00: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FF04: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FF08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002FF0C: jal         0x8002F678
    // 0x8002FF10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FF10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FF14: beq         $v0, $zero, L_8002FF28
    if (ctx->r2 == 0) {
        // 0x8002FF18: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FF28;
    }
    // 0x8002FF18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FF1C: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FF20: addiu       $t6, $t6, -0x42B4
    ctx->r14 = ADD32(ctx->r14, -0X42B4);
    // 0x8002FF24: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FF28:
    // 0x8002FF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FF2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FF30: jr          $ra
    // 0x8002FF34: nop

    return;
    // 0x8002FF34: nop

;}
RECOMP_FUNC void func_8043D8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D8B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043D8B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043D8BC: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8043D8C0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A10) << 16);
    // 0x8043D8C4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8043D8C8: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8043D8CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043D8D0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8043D8D4: lwc1        $f6, -0x15B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A10));
    // 0x8043D8D8: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8043D8DC: jal         0x8043D708
    // 0x8043D8E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8043D708(rdram, ctx);
        goto after_0;
    // 0x8043D8E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043D8E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043D8E8: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8043D8EC: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8043D8F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043D8F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043D8F8: jr          $ra
    // 0x8043D8FC: nop

    return;
    // 0x8043D8FC: nop

;}
RECOMP_FUNC void func_8003507C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003507C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035084: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x80035088: bne         $t6, $zero, L_800350BC
    if (ctx->r14 != 0) {
        // 0x8003508C: nop
    
            goto L_800350BC;
    }
    // 0x8003508C: nop

    // 0x80035090: lbu         $t7, 0x22($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X22);
    // 0x80035094: beql        $t7, $zero, L_800350AC
    if (ctx->r15 == 0) {
        // 0x80035098: addiu       $a1, $zero, 0x15
        ctx->r5 = ADD32(0, 0X15);
            goto L_800350AC;
    }
    goto skip_0;
    // 0x80035098: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    skip_0:
    // 0x8003509C: lw          $t8, 0x24($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X24);
    // 0x800350A0: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x800350A4: bne         $t9, $zero, L_800350BC
    if (ctx->r25 != 0) {
        // 0x800350A8: addiu       $a1, $zero, 0x15
        ctx->r5 = ADD32(0, 0X15);
            goto L_800350BC;
    }
    // 0x800350A8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
L_800350AC:
    // 0x800350AC: jal         0x8002DBE4
    // 0x800350B0: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_0;
    // 0x800350B0: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x800350B4: b           L_80035100
    // 0x800350B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035100;
    // 0x800350B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800350BC:
    // 0x800350BC: jal         0x80040C9C
    // 0x800350C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80040C9C(rdram, ctx);
        goto after_1;
    // 0x800350C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800350C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800350C8: jal         0x80040E24
    // 0x800350CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80040E24(rdram, ctx);
        goto after_2;
    // 0x800350CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x800350D0: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800350D4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800350D8: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x800350DC: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x800350E0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800350E4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800350E8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800350EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800350F0: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x800350F4: jalr        $t9
    // 0x800350F8: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800350F8: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    after_3:
    // 0x800350FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035100:
    // 0x80035100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035104: jr          $ra
    // 0x80035108: nop

    return;
    // 0x80035108: nop

;}
RECOMP_FUNC void func_807092C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807092C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x807092CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807092D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807092D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807092D8: jal         0x80709540
    // 0x807092DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    func_80709540(rdram, ctx);
        goto after_0;
    // 0x807092DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x807092E0: beq         $v0, $zero, L_807094A0
    if (ctx->r2 == 0) {
        // 0x807092E4: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_807094A0;
    }
    // 0x807092E4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x807092E8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x807092EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807092F0: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x807092F4: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    // 0x807092F8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807092FC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80709300: jal         0x80709588
    // 0x80709304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80709588(rdram, ctx);
        goto after_1;
    // 0x80709304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80709308: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x8070930C: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(718, 0X1530) << 16);
    // 0x80709310: lwc1        $f0, -0x58F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(718, 0X1530));
    // 0x80709314: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80709318: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x8070931C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80709320: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80709324: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80709328: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8070932C: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x80709330: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x80709334: swc1        $f12, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f12.u32l;
    // 0x80709338: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x8070933C: lw          $t9, 0xE94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE94);
    // 0x80709340: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x80709344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80709348: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8070934C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80709350: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80709354: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x80709358: lw          $t0, 0xE94($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE94);
    // 0x8070935C: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80709360: jal         0x80709CB8
    // 0x80709364: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    func_80709CB8(rdram, ctx);
        goto after_2;
    // 0x80709364: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80709368: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(718, 0X14EC) << 16);
    // 0x8070936C: lw          $s1, 0x1F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1F4);
    // 0x80709370: addiu       $a0, $a0, -0x5934
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(718, 0X14EC));
    // 0x80709374: jal         0x80709D9C
    // 0x80709378: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    func_80709D9C(rdram, ctx);
        goto after_3;
    // 0x80709378: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    after_3:
    // 0x8070937C: bne         $v0, $zero, L_80709394
    if (ctx->r2 != 0) {
        // 0x80709380: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_80709394;
    }
    // 0x80709380: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80709384: jal         0x800445A4
    // 0x80709388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x80709388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8070938C: b           L_807094A4
    // 0x80709390: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_807094A4;
    // 0x80709390: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80709394:
    // 0x80709394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80709398: jal         0x80047F9C
    // 0x8070939C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8070939C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_5:
    // 0x807093A0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807093A4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807093A8: lw          $t1, 0xE94($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE94);
    // 0x807093AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807093B0: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x807093B4: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
    // 0x807093B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x807093BC: bne         $v0, $at, L_807093F4
    if (ctx->r2 != ctx->r1) {
        // 0x807093C0: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_807093F4;
    }
    // 0x807093C0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x807093C4: lw          $t4, 0xA68($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA68);
    // 0x807093C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807093CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x807093D0: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x807093D4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x807093D8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x807093DC: lw          $t9, 0x24($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X24);
    // 0x807093E0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x807093E4: jalr        $t9
    // 0x807093E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x807093E8: nop

    after_6:
    // 0x807093EC: b           L_80709430
    // 0x807093F0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_80709430;
    // 0x807093F0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_807093F4:
    // 0x807093F4: lw          $t7, 0xA68($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XA68);
    // 0x807093F8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x807093FC: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x80709400: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80709404: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x80709408: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8070940C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80709410: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80709414: sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    // 0x80709418: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8070941C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80709420: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x80709424: jalr        $t9
    // 0x80709428: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80709428: nop

    after_7:
    // 0x8070942C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80709430:
    // 0x80709430: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80709434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80709438: bne         $t0, $zero, L_80709450
    if (ctx->r8 != 0) {
        // 0x8070943C: nop
    
            goto L_80709450;
    }
    // 0x8070943C: nop

    // 0x80709440: jal         0x800445A4
    // 0x80709444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x80709444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80709448: b           L_807094A4
    // 0x8070944C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_807094A4;
    // 0x8070944C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80709450:
    // 0x80709450: jal         0x80709744
    // 0x80709454: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80709744(rdram, ctx);
        goto after_9;
    // 0x80709454: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80709458: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8070945C: addiu       $at, $zero, 0x4035
    ctx->r1 = ADD32(0, 0X4035);
    // 0x80709460: bne         $t1, $at, L_80709498
    if (ctx->r9 != ctx->r1) {
        // 0x80709464: nop
    
            goto L_80709498;
    }
    // 0x80709464: nop

    // 0x80709468: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
    // 0x8070946C: beql        $v0, $zero, L_807094A4
    if (ctx->r2 == 0) {
        // 0x80709470: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_807094A4;
    }
    goto skip_0;
    // 0x80709470: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80709474: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80709478: sw          $zero, 0x44($t2)
    MEM_W(0X44, ctx->r10) = 0;
    // 0x8070947C: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x80709480: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80709484: sw          $zero, 0x48($t4)
    MEM_W(0X48, ctx->r12) = 0;
    // 0x80709488: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x8070948C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80709490: b           L_807094A0
    // 0x80709494: sh          $zero, 0x4C($t6)
    MEM_H(0X4C, ctx->r14) = 0;
        goto L_807094A0;
    // 0x80709494: sh          $zero, 0x4C($t6)
    MEM_H(0X4C, ctx->r14) = 0;
L_80709498:
    // 0x80709498: jal         0x80052BA4
    // 0x8070949C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_10;
    // 0x8070949C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_807094A0:
    // 0x807094A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807094A4:
    // 0x807094A4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807094A8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807094AC: jr          $ra
    // 0x807094B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x807094B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8003F970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F970: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003F974: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003F978: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003F97C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003F980: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8003F984: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8003F988: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8003F98C: lbu         $s0, 0x12C8($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X12C8);
    // 0x8003F990: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003F994: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8003F998: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8003F99C: lwc1        $f10, 0x2C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2C8);
    // 0x8003F9A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003F9A4: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x8003F9A8: lwc1        $f8, 0x8C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x8003F9AC: addiu       $a1, $s1, 0x78
    ctx->r5 = ADD32(ctx->r17, 0X78);
    // 0x8003F9B0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8003F9B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003F9B8: jal         0x80065490
    // 0x8003F9BC: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x8003F9BC: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8003F9C0: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x8003F9C4: bne         $at, $zero, L_8003FA00
    if (ctx->r1 != 0) {
        // 0x8003F9C8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8003FA00;
    }
    // 0x8003F9C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003F9CC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003F9D0: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x8003F9D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003F9D8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8003F9DC: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    // 0x8003F9E0: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x8003F9E4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003F9E8: jal         0x8003F894
    // 0x8003F9EC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8003F894(rdram, ctx);
        goto after_1;
    // 0x8003F9EC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x8003F9F0: bne         $v0, $zero, L_8003FA7C
    if (ctx->r2 != 0) {
        // 0x8003F9F4: nop
    
            goto L_8003FA7C;
    }
    // 0x8003F9F4: nop

    // 0x8003F9F8: b           L_8003FA94
    // 0x8003F9FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003FA94;
    // 0x8003F9FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FA00:
    // 0x8003FA00: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003FA04: lw          $a3, 0x1EC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1EC);
    // 0x8003FA08: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8003FA0C: jal         0x8003BB20
    // 0x8003FA10: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_8003BB20(rdram, ctx);
        goto after_2;
    // 0x8003FA10: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x8003FA14: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8003FA18: addiu       $t0, $t0, -0x4D50
    ctx->r8 = ADD32(ctx->r8, -0X4D50);
    // 0x8003FA1C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003FA20: sw          $t0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r8;
    // 0x8003FA24: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
    // 0x8003FA28: jal         0x80065490
    // 0x8003FA2C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8003FA2C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x8003FA30: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8003FA34: jal         0x80065490
    // 0x8003FA38: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x8003FA38: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x8003FA3C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8003FA40: jal         0x80065490
    // 0x8003FA44: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80065490(rdram, ctx);
        goto after_5;
    // 0x8003FA44: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x8003FA48: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8003FA4C: jal         0x80047F9C
    // 0x8003FA50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8003FA50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8003FA54: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003FA58: sb          $t1, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r9;
    // 0x8003FA5C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8003FA60: addiu       $a3, $a3, -0x19E8
    ctx->r7 = ADD32(ctx->r7, -0X19E8);
    // 0x8003FA64: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8003FA68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003FA6C: jal         0x8003E658
    // 0x8003FA70: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_8003E658(rdram, ctx);
        goto after_7;
    // 0x8003FA70: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x8003FA74: jal         0x80044658
    // 0x8003FA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80044658(rdram, ctx);
        goto after_8;
    // 0x8003FA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_8003FA7C:
    // 0x8003FA7C: jal         0x8003F85C
    // 0x8003FA80: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_8003F85C(rdram, ctx);
        goto after_9;
    // 0x8003FA80: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x8003FA84: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003FA88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003FA8C: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x8003FA90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FA94:
    // 0x8003FA94: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003FA98: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003FA9C: jr          $ra
    // 0x8003FAA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003FAA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_806CFA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFA34: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x806CFA38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806CFA3C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AD0) << 16);
    // 0x806CFA40: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806CFA44: lwc1        $f6, 0x1270($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AD0));
    // 0x806CFA48: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CFA4C: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x806CFA50: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CFA54: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806CFA58: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x806CFA5C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x806CFA60: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806CFA64: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x806CFA68: nop

    // 0x806CFA6C: bc1fl       L_806CFA84
    if (!c1cs) {
        // 0x806CFA70: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_806CFA84;
    }
    goto skip_0;
    // 0x806CFA70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x806CFA74: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x806CFA78: b           L_806CFAA0
    // 0x806CFA7C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
        goto L_806CFAA0;
    // 0x806CFA7C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806CFA80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_806CFA84:
    // 0x806CFA84: nop

    // 0x806CFA88: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806CFA8C: nop

    // 0x806CFA90: bc1fl       L_806CFAA4
    if (!c1cs) {
        // 0x806CFA94: lui         $at, 0x43A2
        ctx->r1 = S32(0X43A2 << 16);
            goto L_806CFAA4;
    }
    goto skip_1;
    // 0x806CFA94: lui         $at, 0x43A2
    ctx->r1 = S32(0X43A2 << 16);
    skip_1:
    // 0x806CFA98: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806CFA9C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
L_806CFAA0:
    // 0x806CFAA0: lui         $at, 0x43A2
    ctx->r1 = S32(0X43A2 << 16);
L_806CFAA4:
    // 0x806CFAA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806CFAA8: nop

    // 0x806CFAAC: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x806CFAB0: jr          $ra
    // 0x806CFAB4: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x806CFAB4: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80737DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737DC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80737DC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80737DC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80737DCC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737DD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80737DD4: jal         0x80737B68
    // 0x80737DD8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80737B68(rdram, ctx);
        goto after_0;
    // 0x80737DD8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80737DDC: jal         0x80737194
    // 0x80737DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737194(rdram, ctx);
        goto after_1;
    // 0x80737DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80737DE4: jal         0x80737490
    // 0x80737DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737490(rdram, ctx);
        goto after_2;
    // 0x80737DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80737DEC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80737DF0: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x80737DF4: bne         $t7, $zero, L_80737E78
    if (ctx->r15 != 0) {
        // 0x80737DF8: nop
    
            goto L_80737E78;
    }
    // 0x80737DF8: nop

    // 0x80737DFC: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x80737E00: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80737E04: bne         $t8, $zero, L_80737E78
    if (ctx->r24 != 0) {
        // 0x80737E08: nop
    
            goto L_80737E78;
    }
    // 0x80737E08: nop

    // 0x80737E0C: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80737E10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80737E14: jal         0x800659EC
    // 0x80737E18: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800659EC(rdram, ctx);
        goto after_3;
    // 0x80737E18: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_3:
    // 0x80737E1C: lw          $t9, 0x12C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X12C);
    // 0x80737E20: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80737E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80737E28: bne         $t9, $zero, L_80737E4C
    if (ctx->r25 != 0) {
        // 0x80737E2C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80737E4C;
    }
    // 0x80737E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80737E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80737E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80737E38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80737E3C: jal         0x80738050
    // 0x80737E40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80738050(rdram, ctx);
        goto after_4;
    // 0x80737E40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80737E44: b           L_80737E58
    // 0x80737E48: nop

        goto L_80737E58;
    // 0x80737E48: nop

L_80737E4C:
    // 0x80737E4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80737E50: jal         0x80738050
    // 0x80737E54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80738050(rdram, ctx);
        goto after_5;
    // 0x80737E54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
L_80737E58:
    // 0x80737E58: jal         0x80737B68
    // 0x80737E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737B68(rdram, ctx);
        goto after_6;
    // 0x80737E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80737E60: jal         0x80737120
    // 0x80737E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737120(rdram, ctx);
        goto after_7;
    // 0x80737E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80737E68: jal         0x80737208
    // 0x80737E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737208(rdram, ctx);
        goto after_8;
    // 0x80737E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80737E70: b           L_80737E80
    // 0x80737E74: nop

        goto L_80737E80;
    // 0x80737E74: nop

L_80737E78:
    // 0x80737E78: jal         0x80737208
    // 0x80737E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737208(rdram, ctx);
        goto after_9;
    // 0x80737E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80737E80:
    // 0x80737E80: jal         0x80735B8C
    // 0x80737E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80735B8C(rdram, ctx);
        goto after_10;
    // 0x80737E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80737E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80737E8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80737E90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80737E94: jr          $ra
    // 0x80737E98: nop

    return;
    // 0x80737E98: nop

;}
RECOMP_FUNC void func_807880F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807880F0: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x807880F4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x807880F8: beq         $at, $zero, L_80788108
    if (ctx->r1 == 0) {
        // 0x807880FC: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_80788108;
    }
    // 0x807880FC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80788100: bgez        $a0, L_80788114
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80788104: lui         $v1, 0x8010
        ctx->r3 = S32(0X8010 << 16);
            goto L_80788114;
    }
    // 0x80788104: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
L_80788108:
    // 0x80788108: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078810C: jr          $ra
    // 0x80788110: nop

    return;
    // 0x80788110: nop

L_80788114:
    // 0x80788114: lw          $v1, -0x7290($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7290);
    // 0x80788118: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8078811C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80788120: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80788124: lw          $v0, 0x38($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X38);
    // 0x80788128: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8078812C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80788130: lw          $a1, 0x1F4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1F4);
    // 0x80788134: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
    // 0x80788138: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8078813C: lhu         $t5, 0x52F0($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X52F0);
    // 0x80788140: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80788144: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80788148: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x8078814C: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80788150: beq         $t6, $zero, L_80788180
    if (ctx->r14 == 0) {
        // 0x80788154: addu        $a2, $t2, $t3
        ctx->r6 = ADD32(ctx->r10, ctx->r11);
            goto L_80788180;
    }
    // 0x80788154: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x80788158: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8078815C: lwc1        $f10, 0x52C8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X52C8);
    // 0x80788160: lwc1        $f18, 0x52CC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X52CC);
    // 0x80788164: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80788168: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8078816C: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80788170: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80788174: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80788178: b           L_807881A0
    // 0x8078817C: add.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f4.fl;
        goto L_807881A0;
    // 0x8078817C: add.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f4.fl;
L_80788180:
    // 0x80788180: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80788184: lwc1        $f16, 0x52C8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X52C8);
    // 0x80788188: lwc1        $f6, 0x52CC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X52CC);
    // 0x8078818C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80788190: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80788194: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80788198: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8078819C: add.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f4.fl;
L_807881A0:
    // 0x807881A0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x807881A4: jr          $ra
    // 0x807881A8: nop

    return;
    // 0x807881A8: nop

;}
RECOMP_FUNC void func_80799F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799F28: jal         0x80058A14
    // 0x80799F2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80058A14(rdram, ctx);
        goto after_0;
    // 0x80799F2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80799F30: beq         $v0, $zero, L_80799F64
    if (ctx->r2 == 0) {
        // 0x80799F34: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80799F64;
    }
    // 0x80799F34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80799F38: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80799F3C: lw          $t9, -0x72BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72BC);
    // 0x80799F40: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80799F44: lwc1        $f14, 0x88($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80799F48: jalr        $t9
    // 0x80799F4C: lw          $a2, 0x8C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80799F4C: lw          $a2, 0x8C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8C);
    after_1:
    // 0x80799F50: jal         0x80067E68
    // 0x80799F54: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80067E68(rdram, ctx);
        goto after_2;
    // 0x80799F54: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x80799F58: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80799F5C: jal         0x80067818
    // 0x80799F60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80799F60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_80799F64:
    // 0x80799F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799F6C: jr          $ra
    // 0x80799F70: nop

    return;
    // 0x80799F70: nop

;}
RECOMP_FUNC void func_805216D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805216D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805216D4: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(309, 0X460) << 16);
    // 0x805216D8: lwc1        $f0, 0x1B20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(309, 0X460));
    // 0x805216DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805216E0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805216E4: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(309, 0X240) << 16);
    // 0x805216E8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805216EC: addiu       $t6, $t6, 0x1900
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(309, 0X240));
    // 0x805216F0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805216F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805216F8: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805216FC: jal         0x805218D8
    // 0x80521700: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    func_805218D8(rdram, ctx);
        goto after_0;
    // 0x80521700: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x80521704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521708: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8052170C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80521710: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x80521714: jr          $ra
    // 0x80521718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80521718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80430C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430C44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80430C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430C4C: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80430C50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430C54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80430C58: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80430C5C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80430C60: jal         0x80066DE4
    // 0x80430C64: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80430C64: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80430C68: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80430C6C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80430C70: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80430C74: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80430C78: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80430C7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80430C80: jal         0x80066E88
    // 0x80430C84: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80430C84: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80430C88: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80430C8C: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80430C90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80430C94: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80430C98: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80430C9C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80430CA0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80430CA4: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80430CA8: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80430CAC: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    // 0x80430CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80430CB8: jr          $ra
    // 0x80430CBC: nop

    return;
    // 0x80430CBC: nop

;}
RECOMP_FUNC void func_8002AFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AFDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AFE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AFE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002AFE8: jal         0x8003262C
    // 0x8002AFEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8003262C(rdram, ctx);
        goto after_0;
    // 0x8002AFEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002AFF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002AFF4: jal         0x80040C48
    // 0x8002AFF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80040C48(rdram, ctx);
        goto after_1;
    // 0x8002AFF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002AFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002B004: jr          $ra
    // 0x8002B008: nop

    return;
    // 0x8002B008: nop

;}
RECOMP_FUNC void func_8067A070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067A070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067A074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067A078: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8067A07C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8067A080: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8067A084: beq         $a1, $at, L_8067A0A0
    if (ctx->r5 == ctx->r1) {
        // 0x8067A088: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_8067A0A0;
    }
    // 0x8067A088: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8067A08C: jal         0x80067878
    // 0x8067A090: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8067A090: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8067A094: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8067A098: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8067A09C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8067A0A0:
    // 0x8067A0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067A0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067A0A8: jr          $ra
    // 0x8067A0AC: nop

    return;
    // 0x8067A0AC: nop

;}
RECOMP_FUNC void func_807AE060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE060: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x807AE064: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x807AE068: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807AE06C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807AE070: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x807AE074: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x807AE078: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AE07C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x807AE080: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AE084: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x807AE088: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807AE08C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807AE090: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x807AE094: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x807AE098: nop

    // 0x807AE09C: bc1fl       L_807AE0D8
    if (!c1cs) {
        // 0x807AE0A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807AE0D8;
    }
    goto skip_0;
    // 0x807AE0A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x807AE0A4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807AE0A8: lwc1        $f6, 0x28($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X28);
    // 0x807AE0AC: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x807AE0B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AE0B4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807AE0B8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x807AE0BC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x807AE0C0: nop

    // 0x807AE0C4: bc1fl       L_807AE0D8
    if (!c1cs) {
        // 0x807AE0C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807AE0D8;
    }
    goto skip_1;
    // 0x807AE0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x807AE0CC: jr          $ra
    // 0x807AE0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807AE0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807AE0D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AE0D8:
    // 0x807AE0D8: jr          $ra
    // 0x807AE0DC: nop

    return;
    // 0x807AE0DC: nop

;}
RECOMP_FUNC void func_8073FC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FC84: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8073FC88: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(748, 0X1440) << 16);
    // 0x8073FC8C: addiu       $t6, $t6, -0x3D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(748, 0X1440));
    // 0x8073FC90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8073FC94: jr          $ra
    // 0x8073FC98: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8073FC98: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80530A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530A5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80530A60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80530A64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80530A68: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80530A6C: jal         0x8053096C
    // 0x80530A70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8053096C(rdram, ctx);
        goto after_0;
    // 0x80530A70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80530A74: jal         0x80530998
    // 0x80530A78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80530998(rdram, ctx);
        goto after_1;
    // 0x80530A78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80530A7C: beql        $v0, $zero, L_80530AD0
    if (ctx->r2 == 0) {
        // 0x80530A80: lhu         $v0, 0x8($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X8);
            goto L_80530AD0;
    }
    goto skip_0;
    // 0x80530A80: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    skip_0:
    // 0x80530A84: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x80530A88: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80530A8C: bnel        $t7, $zero, L_80530AEC
    if (ctx->r15 != 0) {
        // 0x80530A90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80530AEC;
    }
    goto skip_1;
    // 0x80530A90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80530A94: jal         0x8006CAE0
    // 0x80530A98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CAE0(rdram, ctx);
        goto after_2;
    // 0x80530A98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80530A9C: lui         $at, 0x432B
    ctx->r1 = S32(0X432B << 16);
    // 0x80530AA0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80530AA4: jal         0x8006C9DC
    // 0x80530AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006C9DC(rdram, ctx);
        goto after_3;
    // 0x80530AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80530AAC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80530AB0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80530AB4: jal         0x8006CA74
    // 0x80530AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006CA74(rdram, ctx);
        goto after_4;
    // 0x80530AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80530ABC: lhu         $t8, 0x8($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X8);
    // 0x80530AC0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80530AC4: b           L_80530AE8
    // 0x80530AC8: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
        goto L_80530AE8;
    // 0x80530AC8: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x80530ACC: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
L_80530AD0:
    // 0x80530AD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80530AD4: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80530AD8: beq         $t0, $zero, L_80530AE8
    if (ctx->r8 == 0) {
        // 0x80530ADC: andi        $t1, $v0, 0xFFFE
        ctx->r9 = ctx->r2 & 0XFFFE;
            goto L_80530AE8;
    }
    // 0x80530ADC: andi        $t1, $v0, 0xFFFE
    ctx->r9 = ctx->r2 & 0XFFFE;
    // 0x80530AE0: jal         0x8006CAE0
    // 0x80530AE4: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    func_8006CAE0(rdram, ctx);
        goto after_5;
    // 0x80530AE4: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    after_5:
L_80530AE8:
    // 0x80530AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80530AEC:
    // 0x80530AEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80530AF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80530AF4: jr          $ra
    // 0x80530AF8: nop

    return;
    // 0x80530AF8: nop

;}
RECOMP_FUNC void func_80714F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714F38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80714F3C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80714F40: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80714F44: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80714F48: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80714F4C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80714F50: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80714F54: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80714F58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80714F5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80714F60: lw          $s1, 0x1E0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1E0);
    // 0x80714F64: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80714F68: lw          $s7, 0x1F4($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X1F4);
    // 0x80714F6C: addu        $at, $s1, $zero
    ctx->r1 = ADD32(ctx->r17, 0);
    // 0x80714F70: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80714F74: addu        $s1, $s1, $at
    ctx->r17 = ADD32(ctx->r17, ctx->r1);
    // 0x80714F78: jal         0x80047090
    // 0x80714F7C: addiu       $a0, $zero, 0x4636
    ctx->r4 = ADD32(0, 0X4636);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80714F7C: addiu       $a0, $zero, 0x4636
    ctx->r4 = ADD32(0, 0X4636);
    after_0:
    // 0x80714F80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80714F84: lui         $at, 0x4636
    ctx->r1 = S32(0X4636 << 16);
    // 0x80714F88: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80714F8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80714F90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80714F94: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80714F98: jal         0x8004613C
    // 0x80714F9C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80714F9C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80714FA0: bne         $v0, $zero, L_80714FB8
    if (ctx->r2 != 0) {
        // 0x80714FA4: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_80714FB8;
    }
    // 0x80714FA4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80714FA8: jal         0x80048D4C
    // 0x80714FAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80048D4C(rdram, ctx);
        goto after_2;
    // 0x80714FAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x80714FB0: b           L_8071513C
    // 0x80714FB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8071513C;
    // 0x80714FB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80714FB8:
    // 0x80714FB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80714FBC: jal         0x80047F9C
    // 0x80714FC0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80714FC0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_3:
    // 0x80714FC4: sb          $zero, 0x17C($s6)
    MEM_B(0X17C, ctx->r22) = 0;
    // 0x80714FC8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80714FCC:
    // 0x80714FCC: slti        $at, $s1, 0xF
    ctx->r1 = SIGNED(ctx->r17) < 0XF ? 1 : 0;
    // 0x80714FD0: bne         $at, $zero, L_80714FE0
    if (ctx->r1 != 0) {
        // 0x80714FD4: nop
    
            goto L_80714FE0;
    }
    // 0x80714FD4: nop

    // 0x80714FD8: b           L_80715080
    // 0x80714FDC: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
        goto L_80715080;
    // 0x80714FDC: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
L_80714FE0:
    // 0x80714FE0: jal         0x80047090
    // 0x80714FE4: addiu       $a0, $zero, 0x4626
    ctx->r4 = ADD32(0, 0X4626);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x80714FE4: addiu       $a0, $zero, 0x4626
    ctx->r4 = ADD32(0, 0X4626);
    after_4:
    // 0x80714FE8: lui         $at, 0x4626
    ctx->r1 = S32(0X4626 << 16);
    // 0x80714FEC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80714FF0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80714FF4: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(730, 0X1884) << 16);
    // 0x80714FF8: lwc1        $f6, 0x60A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(730, 0X1884));
    // 0x80714FFC: lwc1        $f4, 0x44($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X44);
    // 0x80715000: lw          $a1, 0x3C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X3C);
    // 0x80715004: lw          $a2, 0x40($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X40);
    // 0x80715008: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8071500C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80715010: jal         0x8004613C
    // 0x80715014: nop

    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x80715014: nop

    after_5:
    // 0x80715018: bne         $v0, $zero, L_80715030
    if (ctx->r2 != 0) {
        // 0x8071501C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80715030;
    }
    // 0x8071501C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80715020: jal         0x80048D4C
    // 0x80715024: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80048D4C(rdram, ctx);
        goto after_6;
    // 0x80715024: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x80715028: b           L_8071513C
    // 0x8071502C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8071513C;
    // 0x8071502C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80715030:
    // 0x80715030: sll         $s3, $s1, 2
    ctx->r19 = S32(ctx->r17 << 2);
    // 0x80715034: addu        $s3, $s3, $s1
    ctx->r19 = ADD32(ctx->r19, ctx->r17);
    // 0x80715038: sll         $s3, $s3, 1
    ctx->r19 = S32(ctx->r19 << 1);
    // 0x8071503C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80715040: addu        $s4, $s7, $t6
    ctx->r20 = ADD32(ctx->r23, ctx->r14);
    // 0x80715044: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    // 0x80715048: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8071504C: jal         0x80047F9C
    // 0x80715050: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x80715050: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80715054: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80715058: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x8071505C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80715060: sb          $t7, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r15;
    // 0x80715064: sw          $s3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r19;
    // 0x80715068: mfhi        $t8
    ctx->r24 = hi;
    // 0x8071506C: sw          $s0, 0x5A4($s4)
    MEM_W(0X5A4, ctx->r20) = ctx->r16;
    // 0x80715070: bnel        $t8, $zero, L_80715084
    if (ctx->r24 != 0) {
        // 0x80715074: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80715084;
    }
    goto skip_0;
    // 0x80715074: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80715078: jal         0x8005FDC4
    // 0x8071507C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_8;
    // 0x8071507C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80715080:
    // 0x80715080: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80715084:
    // 0x80715084: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x80715088: bne         $at, $zero, L_80714FCC
    if (ctx->r1 != 0) {
        // 0x8071508C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80714FCC;
    }
    // 0x8071508C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80715090: lw          $t9, 0x1E0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1E0);
    // 0x80715094: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80715098: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x8071509C: bne         $at, $zero, L_80715138
    if (ctx->r1 != 0) {
        // 0x807150A0: sw          $t0, 0x1E0($s5)
        MEM_W(0X1E0, ctx->r21) = ctx->r8;
            goto L_80715138;
    }
    // 0x807150A0: sw          $t0, 0x1E0($s5)
    MEM_W(0X1E0, ctx->r21) = ctx->r8;
    // 0x807150A4: lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0XC);
    // 0x807150A8: addiu       $at, $zero, 0x4621
    ctx->r1 = ADD32(0, 0X4621);
    // 0x807150AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x807150B0: beq         $v0, $at, L_80715100
    if (ctx->r2 == ctx->r1) {
        // 0x807150B4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80715100;
    }
    // 0x807150B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807150B8: addiu       $at, $zero, 0x4622
    ctx->r1 = ADD32(0, 0X4622);
    // 0x807150BC: beq         $v0, $at, L_80715100
    if (ctx->r2 == ctx->r1) {
        // 0x807150C0: addiu       $at, $zero, 0x4623
        ctx->r1 = ADD32(0, 0X4623);
            goto L_80715100;
    }
    // 0x807150C0: addiu       $at, $zero, 0x4623
    ctx->r1 = ADD32(0, 0X4623);
    // 0x807150C4: beq         $v0, $at, L_80715100
    if (ctx->r2 == ctx->r1) {
        // 0x807150C8: addiu       $at, $zero, 0x4624
        ctx->r1 = ADD32(0, 0X4624);
            goto L_80715100;
    }
    // 0x807150C8: addiu       $at, $zero, 0x4624
    ctx->r1 = ADD32(0, 0X4624);
    // 0x807150CC: beq         $v0, $at, L_80715100
    if (ctx->r2 == ctx->r1) {
        // 0x807150D0: addiu       $at, $zero, 0x4677
        ctx->r1 = ADD32(0, 0X4677);
            goto L_80715100;
    }
    // 0x807150D0: addiu       $at, $zero, 0x4677
    ctx->r1 = ADD32(0, 0X4677);
    // 0x807150D4: beq         $v0, $at, L_80715114
    if (ctx->r2 == ctx->r1) {
        // 0x807150D8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80715114;
    }
    // 0x807150D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x807150DC: addiu       $at, $zero, 0x4678
    ctx->r1 = ADD32(0, 0X4678);
    // 0x807150E0: beq         $v0, $at, L_80715114
    if (ctx->r2 == ctx->r1) {
        // 0x807150E4: addiu       $at, $zero, 0x4679
        ctx->r1 = ADD32(0, 0X4679);
            goto L_80715114;
    }
    // 0x807150E4: addiu       $at, $zero, 0x4679
    ctx->r1 = ADD32(0, 0X4679);
    // 0x807150E8: beq         $v0, $at, L_80715114
    if (ctx->r2 == ctx->r1) {
        // 0x807150EC: addiu       $at, $zero, 0x467A
        ctx->r1 = ADD32(0, 0X467A);
            goto L_80715114;
    }
    // 0x807150EC: addiu       $at, $zero, 0x467A
    ctx->r1 = ADD32(0, 0X467A);
    // 0x807150F0: beq         $v0, $at, L_80715114
    if (ctx->r2 == ctx->r1) {
        // 0x807150F4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80715114;
    }
    // 0x807150F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807150F8: b           L_8071512C
    // 0x807150FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_8071512C;
    // 0x807150FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80715100:
    // 0x80715100: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80715104: jal         0x80715C24
    // 0x80715108: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80715C24(rdram, ctx);
        goto after_9;
    // 0x80715108: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x8071510C: b           L_8071513C
    // 0x80715110: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8071513C;
    // 0x80715110: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80715114:
    // 0x80715114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80715118: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8071511C: jal         0x80715C24
    // 0x80715120: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80715C24(rdram, ctx);
        goto after_10;
    // 0x80715120: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x80715124: b           L_8071513C
    // 0x80715128: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8071513C;
    // 0x80715128: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8071512C:
    // 0x8071512C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80715130: jal         0x80715C24
    // 0x80715134: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80715C24(rdram, ctx);
        goto after_11;
    // 0x80715134: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
L_80715138:
    // 0x80715138: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8071513C:
    // 0x8071513C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80715140: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80715144: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80715148: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8071514C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80715150: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80715154: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80715158: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8071515C: jr          $ra
    // 0x80715160: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80715160: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80667D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80667D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80667D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80667D38: jal         0x8005FCA8
    // 0x80667D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x80667D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80667D40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80667D44: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80667D48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80667D4C: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80667D50: beql        $t6, $at, L_80667D60
    if (ctx->r14 == ctx->r1) {
        // 0x80667D54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80667D60;
    }
    goto skip_0;
    // 0x80667D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80667D58: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x80667D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80667D60:
    // 0x80667D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80667D64: jr          $ra
    // 0x80667D68: nop

    return;
    // 0x80667D68: nop

;}
RECOMP_FUNC void func_806F7338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F733C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F7340: jal         0x806F72C0
    // 0x806F7344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F72C0(rdram, ctx);
        goto after_0;
    // 0x806F7344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F7348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F734C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F7350: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806F7354: jal         0x806F73DC
    // 0x806F7358: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F73DC(rdram, ctx);
        goto after_1;
    // 0x806F7358: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806F735C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F7360: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F7364: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806F7368: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x806F736C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806F7370: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806F7374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F7378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F737C: jr          $ra
    // 0x806F7380: nop

    return;
    // 0x806F7380: nop

;}
RECOMP_FUNC void func_804CB974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CB978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CB97C: jal         0x804CB670
    // 0x804CB980: nop

    func_804CB670(rdram, ctx);
        goto after_0;
    // 0x804CB980: nop

    after_0:
    // 0x804CB984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CB988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CB98C: jr          $ra
    // 0x804CB990: nop

    return;
    // 0x804CB990: nop

;}
RECOMP_FUNC void func_80475A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475A50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475A54: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475A58: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80475A5C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475A60: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475A64: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475A68: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80475A6C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475A70: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475A74: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475A78: jr          $ra
    // 0x80475A7C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80475A7C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805274B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805274B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805274BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805274C0: jal         0x805275CC
    // 0x805274C4: nop

    func_805275CC(rdram, ctx);
        goto after_0;
    // 0x805274C4: nop

    after_0:
    // 0x805274C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805274CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805274D0: jr          $ra
    // 0x805274D4: nop

    return;
    // 0x805274D4: nop

;}
RECOMP_FUNC void func_80000724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000724: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x80000728: addiu       $t0, $t0, 0x4D10
    ctx->r8 = ADD32(ctx->r8, 0X4D10);
    // 0x8000072C: lw          $v1, 0x1DAC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X1DAC);
    // 0x80000730: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80000734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000738: blez        $v1, L_800007A8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000073C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800007A8;
    }
    // 0x8000073C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80000740:
    // 0x80000740: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000744: lw          $t6, 0x2A2C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X2A2C);
    // 0x80000748: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8000074C: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x80000750: lw          $t2, 0xB0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XB0);
    // 0x80000754: addiu       $a0, $a0, 0xB0
    ctx->r4 = ADD32(ctx->r4, 0XB0);
    // 0x80000758: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8000075C: mflo        $t7
    ctx->r15 = lo;
    // 0x80000760: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80000764: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80000768: beq         $t3, $zero, L_80000780
    if (ctx->r11 == 0) {
        // 0x8000076C: addu        $a2, $t9, $t1
        ctx->r6 = ADD32(ctx->r25, ctx->r9);
            goto L_80000780;
    }
    // 0x8000076C: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    // 0x80000770: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x80000774: andi        $t5, $t4, 0xFFBF
    ctx->r13 = ctx->r12 & 0XFFBF;
    // 0x80000778: b           L_8000078C
    // 0x8000077C: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000078C;
    // 0x8000077C: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_80000780:
    // 0x80000780: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80000784: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x80000788: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
L_8000078C:
    // 0x8000078C: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x80000790: lw          $v1, 0x1DAC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X1DAC);
    // 0x80000794: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000798: addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    // 0x8000079C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800007A0: bne         $at, $zero, L_80000740
    if (ctx->r1 != 0) {
        // 0x800007A4: nop
    
            goto L_80000740;
    }
    // 0x800007A4: nop

L_800007A8:
    // 0x800007A8: jr          $ra
    // 0x800007AC: nop

    return;
    // 0x800007AC: nop

;}
RECOMP_FUNC void func_8064C250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C258: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8064C25C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064C260: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064C264: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8064C268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C26C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064C270: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8064C274: bc1fl       L_8064C28C
    if (!c1cs) {
        // 0x8064C278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C28C;
    }
    goto skip_0;
    // 0x8064C278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C27C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064C280: jal         0x8064C5D8
    // 0x8064C284: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064C5D8(rdram, ctx);
        goto after_0;
    // 0x8064C284: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064C288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C28C:
    // 0x8064C28C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C290: jr          $ra
    // 0x8064C294: nop

    return;
    // 0x8064C294: nop

;}
RECOMP_FUNC void func_80535378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8053537C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80535380: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80535384: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80535388: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8053538C: lui         $t7, 0x8053
    ctx->r15 = S32(RELOC_HI16(348, 0XFAC) << 16);
    // 0x80535390: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80535394: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80535398: addiu       $t7, $t7, 0x55BC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(348, 0XFAC));
    // 0x8053539C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x805353A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805353A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805353A8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805353AC: sh          $t9, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r25;
    // 0x805353B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805353B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805353B8: jal         0x805350A0
    // 0x805353BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805350A0(rdram, ctx);
        goto after_0;
    // 0x805353BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x805353C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805353C4: jal         0x80045A34
    // 0x805353C8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805353C8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x805353CC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805353D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805353D4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805353D8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(348, 0X109C) << 16);
    // 0x805353DC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x805353E0: lwc1        $f6, 0x56AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X109C));
    // 0x805353E4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805353E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805353EC: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x805353F0: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x805353F4: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x805353F8: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x805353FC: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x80535400: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80535404: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80535408: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x8053540C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80535410: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80535414: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x80535418: jal         0x80535324
    // 0x8053541C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80535324(rdram, ctx);
        goto after_2;
    // 0x8053541C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80535420: lui         $t2, 0x8053
    ctx->r10 = S32(RELOC_HI16(348, 0XD40) << 16);
    // 0x80535424: addiu       $t2, $t2, 0x5350
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(348, 0XD40));
    // 0x80535428: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x8053542C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80535430: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80535434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80535438: jr          $ra
    // 0x8053543C: nop

    return;
    // 0x8053543C: nop

;}
RECOMP_FUNC void func_805A40C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A40C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x805A40CC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x805A40D0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x805A40D4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x805A40D8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x805A40DC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x805A40E0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x805A40E4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x805A40E8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x805A40EC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x805A40F0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x805A40F4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805A40F8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805A40FC: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A4100: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x805A4104: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x805A4108: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x805A410C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x805A4110: sw          $t6, 0x68($s4)
    MEM_W(0X68, ctx->r20) = ctx->r14;
    // 0x805A4114: sw          $v0, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r2;
    // 0x805A4118: sw          $v0, 0x4C($s4)
    MEM_W(0X4C, ctx->r20) = ctx->r2;
    // 0x805A411C: sw          $v0, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->r2;
    // 0x805A4120: sw          $t7, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->r15;
    // 0x805A4124: sw          $v0, 0x60($s4)
    MEM_W(0X60, ctx->r20) = ctx->r2;
    // 0x805A4128: sw          $v0, 0x5C($s4)
    MEM_W(0X5C, ctx->r20) = ctx->r2;
    // 0x805A412C: sw          $v0, 0x58($s4)
    MEM_W(0X58, ctx->r20) = ctx->r2;
    // 0x805A4130: jal         0x805A35B4
    // 0x805A4134: sw          $zero, 0x64($s4)
    MEM_W(0X64, ctx->r20) = 0;
    func_805A35B4(rdram, ctx);
        goto after_0;
    // 0x805A4134: sw          $zero, 0x64($s4)
    MEM_W(0X64, ctx->r20) = 0;
    after_0:
    // 0x805A4138: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D88) << 16);
    // 0x805A413C: lwc1        $f26, 0x5118($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D88));
    // 0x805A4140: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805A4144: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x805A4148: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x805A414C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x805A4150: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x805A4154: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
    // 0x805A4158: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_805A415C:
    // 0x805A415C: jal         0x800653D8
    // 0x805A4160: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x805A4160: nop

    after_1:
    // 0x805A4164: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x805A4168: andi        $t8, $v0, 0x3F
    ctx->r24 = ctx->r2 & 0X3F;
    // 0x805A416C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x805A4170: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805A4174: lwc1        $f4, 0x3C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x805A4178: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805A417C: addiu       $a1, $zero, 0x4506
    ctx->r5 = ADD32(0, 0X4506);
    // 0x805A4180: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805A4184: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x805A4188: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x805A418C: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x805A4190: jal         0x805A4068
    // 0x805A4194: add.s       $f20, $f8, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f16.fl;
    func_805A4068(rdram, ctx);
        goto after_2;
    // 0x805A4194: add.s       $f20, $f8, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f16.fl;
    after_2:
    // 0x805A4198: beq         $v0, $zero, L_805A41D4
    if (ctx->r2 == 0) {
        // 0x805A419C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805A41D4;
    }
    // 0x805A419C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805A41A0: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x805A41A4: addu        $s2, $s4, $t9
    ctx->r18 = ADD32(ctx->r20, ctx->r25);
    // 0x805A41A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805A41AC: jal         0x80047F9C
    // 0x805A41B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x805A41B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805A41B4: sb          $s5, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r21;
    // 0x805A41B8: sw          $s0, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r16;
    // 0x805A41BC: jal         0x805A4600
    // 0x805A41C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A4600(rdram, ctx);
        goto after_4;
    // 0x805A41C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A41C4: swc1        $f20, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f20.u32l;
    // 0x805A41C8: lwc1        $f4, 0x44($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X44);
    // 0x805A41CC: sub.s       $f10, $f4, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x805A41D0: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_805A41D4:
    // 0x805A41D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x805A41D8: bne         $s1, $s6, L_805A415C
    if (ctx->r17 != ctx->r22) {
        // 0x805A41DC: nop
    
            goto L_805A415C;
    }
    // 0x805A41DC: nop

    // 0x805A41E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805A41E4: jal         0x805A4068
    // 0x805A41E8: addiu       $a1, $zero, 0x450B
    ctx->r5 = ADD32(0, 0X450B);
    func_805A4068(rdram, ctx);
        goto after_5;
    // 0x805A41E8: addiu       $a1, $zero, 0x450B
    ctx->r5 = ADD32(0, 0X450B);
    after_5:
    // 0x805A41EC: beq         $v0, $zero, L_805A421C
    if (ctx->r2 == 0) {
        // 0x805A41F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805A421C;
    }
    // 0x805A41F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805A41F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805A41F8: jal         0x80047F9C
    // 0x805A41FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x805A41FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x805A4200: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x805A4204: jal         0x805A4504
    // 0x805A4208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A4504(rdram, ctx);
        goto after_7;
    // 0x805A4208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805A420C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x805A4210: swc1        $f26, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f26.u32l;
    // 0x805A4214: swc1        $f20, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f20.u32l;
    // 0x805A4218: swc1        $f20, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f20.u32l;
L_805A421C:
    // 0x805A421C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x805A4220: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805A4224: jal         0x805A4068
    // 0x805A4228: addiu       $a1, $zero, 0x450D
    ctx->r5 = ADD32(0, 0X450D);
    func_805A4068(rdram, ctx);
        goto after_8;
    // 0x805A4228: addiu       $a1, $zero, 0x450D
    ctx->r5 = ADD32(0, 0X450D);
    after_8:
    // 0x805A422C: beq         $v0, $zero, L_805A4260
    if (ctx->r2 == 0) {
        // 0x805A4230: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805A4260;
    }
    // 0x805A4230: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805A4234: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805A4238: jal         0x80047F9C
    // 0x805A423C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x805A423C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x805A4240: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x805A4244: jal         0x805A4588
    // 0x805A4248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A4588(rdram, ctx);
        goto after_10;
    // 0x805A4248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x805A424C: swc1        $f20, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f20.u32l;
    // 0x805A4250: swc1        $f20, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f20.u32l;
    // 0x805A4254: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D8C) << 16);
    // 0x805A4258: lwc1        $f18, 0x511C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D8C));
    // 0x805A425C: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
L_805A4260:
    // 0x805A4260: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x805A4264: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805A4268: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805A426C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x805A4270: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x805A4274: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x805A4278: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x805A427C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x805A4280: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x805A4284: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x805A4288: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x805A428C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x805A4290: jr          $ra
    // 0x805A4294: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x805A4294: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FD20: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8008FD24: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008FD28: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8008FD2C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8008FD30: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8008FD34: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8008FD38: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8008FD3C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8008FD40: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8008FD44: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x8008FD48: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x8008FD4C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8008FD50: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x8008FD54: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x8008FD58: bgez        $v0, L_8008FD68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008FD5C: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_8008FD68;
    }
    // 0x8008FD5C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8008FD60: b           L_8008FD94
    // 0x8008FD64: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_8008FD94;
    // 0x8008FD64: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_8008FD68:
    // 0x8008FD68: bne         $v0, $zero, L_8008FD94
    if (ctx->r2 != 0) {
        // 0x8008FD6C: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_8008FD94;
    }
    // 0x8008FD6C: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x8008FD70: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8008FD74: beq         $t8, $at, L_8008FD88
    if (ctx->r24 == ctx->r1) {
        // 0x8008FD78: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_8008FD88;
    }
    // 0x8008FD78: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8008FD7C: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x8008FD80: bnel        $t8, $at, L_8008FD98
    if (ctx->r24 != ctx->r1) {
        // 0x8008FD84: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_8008FD98;
    }
    goto skip_0;
    // 0x8008FD84: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_8008FD88:
    // 0x8008FD88: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x8008FD8C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008FD90: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_8008FD94:
    // 0x8008FD94: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_8008FD98:
    // 0x8008FD98: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x8008FD9C: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x8008FDA0: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x8008FDA4: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8008FDA8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8008FDAC: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8008FDB0: bne         $v1, $at, L_8008FE14
    if (ctx->r3 != ctx->r1) {
        // 0x8008FDB4: nop
    
            goto L_8008FE14;
    }
    // 0x8008FDB4: nop

    // 0x8008FDB8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x8008FDBC: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x8008FDC0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8008FDC4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8008FDC8: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8008FDCC: bnel        $t9, $zero, L_8008FDF8
    if (ctx->r25 != 0) {
        // 0x8008FDD0: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_8008FDF8;
    }
    goto skip_1;
    // 0x8008FDD0: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x8008FDD4: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x8008FDD8: bnel        $t7, $zero, L_8008FDF8
    if (ctx->r15 != 0) {
        // 0x8008FDDC: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_8008FDF8;
    }
    goto skip_2;
    // 0x8008FDDC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x8008FDE0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x8008FDE4: bnel        $t8, $zero, L_8008FDF8
    if (ctx->r24 != 0) {
        // 0x8008FDE8: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_8008FDF8;
    }
    goto skip_3;
    // 0x8008FDE8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x8008FDEC: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x8008FDF0: beq         $t9, $zero, L_8008FE00
    if (ctx->r25 == 0) {
        // 0x8008FDF4: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_8008FE00;
    }
    // 0x8008FDF4: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_8008FDF8:
    // 0x8008FDF8: b           L_8008FE4C
    // 0x8008FDFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8008FE4C;
    // 0x8008FDFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008FE00:
    // 0x8008FE00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8008FE04: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8008FE08: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008FE0C: b           L_8008FE4C
    // 0x8008FE10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8008FE4C;
    // 0x8008FE10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008FE14:
    // 0x8008FE14: blez        $v1, L_8008FE38
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008FE18: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_8008FE38;
    }
    // 0x8008FE18: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x8008FE1C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x8008FE20: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x8008FE24: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x8008FE28: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x8008FE2C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x8008FE30: b           L_8008FE4C
    // 0x8008FE34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008FE4C;
    // 0x8008FE34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008FE38:
    // 0x8008FE38: bgez        $v1, L_8008FE48
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008FE3C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008FE48;
    }
    // 0x8008FE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008FE40: b           L_8008FE4C
    // 0x8008FE44: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008FE4C;
    // 0x8008FE44: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8008FE48:
    // 0x8008FE48: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8008FE4C:
    // 0x8008FE4C: blez        $v0, L_8008FE98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008FE50: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_8008FE98;
    }
    // 0x8008FE50: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8008FE54: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8008FE58: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8008FE5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008FE60: bne         $t6, $at, L_8008FE74
    if (ctx->r14 != ctx->r1) {
        // 0x8008FE64: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_8008FE74;
    }
    // 0x8008FE64: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x8008FE68: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8008FE6C: b           L_8008FE7C
    // 0x8008FE70: addiu       $a1, $a1, 0x3498
    ctx->r5 = ADD32(ctx->r5, 0X3498);
        goto L_8008FE7C;
    // 0x8008FE70: addiu       $a1, $a1, 0x3498
    ctx->r5 = ADD32(ctx->r5, 0X3498);
L_8008FE74:
    // 0x8008FE74: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8008FE78: addiu       $a1, $a1, 0x349C
    ctx->r5 = ADD32(ctx->r5, 0X349C);
L_8008FE7C:
    // 0x8008FE7C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8008FE80: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x8008FE84: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x8008FE88: jal         0x8008AD80
    // 0x8008FE8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FE8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8008FE90: b           L_80090248
    // 0x8008FE94: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80090248;
    // 0x8008FE94: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008FE98:
    // 0x8008FE98: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8008FE9C: bne         $t6, $zero, L_8008FEAC
    if (ctx->r14 != 0) {
        // 0x8008FEA0: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8008FEAC;
    }
    // 0x8008FEA0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008FEA4: b           L_80090230
    // 0x8008FEA8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_80090230;
    // 0x8008FEA8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8008FEAC:
    // 0x8008FEAC: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x8008FEB0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008FEB4: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x8008FEB8: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x8008FEBC: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x8008FEC0: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x8008FEC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008FEC8: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x8008FECC: bc1f        L_8008FED8
    if (!c1cs) {
        // 0x8008FED0: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_8008FED8;
    }
    // 0x8008FED0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8008FED4: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_8008FED8:
    // 0x8008FED8: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008FEDC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8008FEE0: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8008FEE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8008FEE8: mflo        $t8
    ctx->r24 = lo;
    // 0x8008FEEC: nop

    // 0x8008FEF0: nop

    // 0x8008FEF4: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8008FEF8: mflo        $t6
    ctx->r14 = lo;
    // 0x8008FEFC: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x8008FF00: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8008FF04: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8008FF08: bgez        $t8, L_8008FF70
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008FF0C: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_8008FF70;
    }
    // 0x8008FF0C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x8008FF10: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8008FF14: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8008FF18: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8008FF1C: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x8008FF20: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008FF24: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x8008FF28: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x8008FF2C: blez        $v0, L_8008FFE0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008FF30: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_8008FFE0;
    }
    // 0x8008FF30: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x8008FF34: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8008FF38: addiu       $a0, $a0, 0x3450
    ctx->r4 = ADD32(ctx->r4, 0X3450);
L_8008FF3C:
    // 0x8008FF3C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8008FF40: beq         $t6, $zero, L_8008FF5C
    if (ctx->r14 == 0) {
        // 0x8008FF44: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8008FF5C;
    }
    // 0x8008FF44: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008FF48: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8008FF4C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x8008FF50: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x8008FF54: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x8008FF58: nop

L_8008FF5C:
    // 0x8008FF5C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8008FF60: bgtz        $t9, L_8008FF3C
    if (SIGNED(ctx->r25) > 0) {
        // 0x8008FF64: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8008FF3C;
    }
    // 0x8008FF64: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008FF68: b           L_8008FFE4
    // 0x8008FF6C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_8008FFE4;
    // 0x8008FF6C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_8008FF70:
    // 0x8008FF70: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x8008FF74: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8008FF78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008FF7C: blez        $t6, L_8008FFE0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8008FF80: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_8008FFE0;
    }
    // 0x8008FF80: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x8008FF84: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x8008FF88: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8008FF8C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8008FF90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008FF94: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8008FF98: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008FF9C: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x8008FFA0: blez        $t6, L_8008FFDC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8008FFA4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8008FFDC;
    }
    // 0x8008FFA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8008FFA8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8008FFAC: addiu       $a0, $a0, 0x3450
    ctx->r4 = ADD32(ctx->r4, 0X3450);
L_8008FFB0:
    // 0x8008FFB0: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8008FFB4: beq         $t7, $zero, L_8008FFD0
    if (ctx->r15 == 0) {
        // 0x8008FFB8: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8008FFD0;
    }
    // 0x8008FFB8: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008FFBC: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8008FFC0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8008FFC4: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x8008FFC8: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8008FFCC: nop

L_8008FFD0:
    // 0x8008FFD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008FFD4: bgtz        $t6, L_8008FFB0
    if (SIGNED(ctx->r14) > 0) {
        // 0x8008FFD8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8008FFB0;
    }
    // 0x8008FFD8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008FFDC:
    // 0x8008FFDC: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_8008FFE0:
    // 0x8008FFE0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_8008FFE4:
    // 0x8008FFE4: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x8008FFE8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8008FFEC: bne         $t7, $at, L_80090000
    if (ctx->r15 != ctx->r1) {
        // 0x8008FFF0: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_80090000;
    }
    // 0x8008FFF0: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x8008FFF4: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x8008FFF8: b           L_80090000
    // 0x8008FFFC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_80090000;
    // 0x8008FFFC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_80090000:
    // 0x80090000: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80090004: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x80090008: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x8009000C: bne         $at, $zero, L_80090018
    if (ctx->r1 != 0) {
        // 0x80090010: nop
    
            goto L_80090018;
    }
    // 0x80090010: nop

    // 0x80090014: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_80090018:
    // 0x80090018: blez        $s4, L_800900E8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8009001C: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_800900E8;
    }
    // 0x8009001C: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x80090020: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80090024: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x80090028: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x8009002C: bc1fl       L_800900EC
    if (!c1cs) {
        // 0x80090030: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_800900EC;
    }
    goto skip_4;
    // 0x80090030: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x80090034: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_80090038:
    // 0x80090038: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x8009003C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80090040: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80090044: blez        $s4, L_80090068
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80090048: nop
    
            goto L_80090068;
    }
    // 0x80090048: nop

    // 0x8009004C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80090050: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80090054: ldc1        $f8, 0x34A8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X34A8);
    // 0x80090058: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8009005C: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x80090060: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80090064: nop

L_80090068:
    // 0x80090068: blez        $s1, L_800900B0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8009006C: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_800900B0;
    }
    // 0x8009006C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80090070: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x80090074: bltz        $s0, L_800900B0
    if (SIGNED(ctx->r16) < 0) {
        // 0x80090078: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800900B0;
    }
    // 0x80090078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8009007C:
    // 0x8009007C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80090080: jal         0x80090370
    // 0x80090084: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x80090084: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x80090088: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8009008C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80090090: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x80090094: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x80090098: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8009009C: blezl       $s1, L_800900B4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800900A0: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_800900B4;
    }
    goto skip_5;
    // 0x800900A0: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x800900A4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800900A8: bgezl       $s0, L_8009007C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800900AC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8009007C;
    }
    goto skip_6;
    // 0x800900AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_800900B0:
    // 0x800900B0: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_800900B4:
    // 0x800900B4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800900B8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800900BC: bltz        $s0, L_800900D0
    if (SIGNED(ctx->r16) < 0) {
        // 0x800900C0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800900D0;
    }
L_800900C0:
    // 0x800900C0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800900C4: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800900C8: bgez        $s0, L_800900C0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800900CC: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_800900C0;
    }
    // 0x800900CC: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_800900D0:
    // 0x800900D0: blez        $s4, L_800900E8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800900D4: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800900E8;
    }
    // 0x800900D4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800900D8: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800900DC: nop

    // 0x800900E0: bc1tl       L_80090038
    if (c1cs) {
        // 0x800900E4: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_80090038;
    }
    goto skip_7;
    // 0x800900E4: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_800900E8:
    // 0x800900E8: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_800900EC:
    // 0x800900EC: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x800900F0: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x800900F4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800900F8: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x800900FC: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x80090100: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80090104: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80090108: bne         $v0, $t6, L_80090130
    if (ctx->r2 != ctx->r14) {
        // 0x8009010C: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_80090130;
    }
    // 0x8009010C: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x80090110: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_80090114:
    // 0x80090114: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80090118: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x8009011C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80090120: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x80090124: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x80090128: beql        $v0, $t9, L_80090114
    if (ctx->r2 == ctx->r25) {
        // 0x8009012C: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_80090114;
    }
    goto skip_8;
    // 0x8009012C: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_80090130:
    // 0x80090130: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80090134: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80090138: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8009013C: bne         $t6, $at, L_80090150
    if (ctx->r14 != ctx->r1) {
        // 0x80090140: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80090150;
    }
    // 0x80090140: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80090144: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x80090148: b           L_80090170
    // 0x8009014C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80090170;
    // 0x8009014C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80090150:
    // 0x80090150: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80090154: beq         $t7, $at, L_80090164
    if (ctx->r15 == ctx->r1) {
        // 0x80090158: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80090164;
    }
    // 0x80090158: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x8009015C: bne         $t7, $at, L_8009016C
    if (ctx->r15 != ctx->r1) {
        // 0x80090160: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009016C;
    }
    // 0x80090160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80090164:
    // 0x80090164: b           L_8009016C
    // 0x80090168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009016C;
    // 0x80090168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009016C:
    // 0x8009016C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80090170:
    // 0x80090170: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80090174: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x80090178: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8009017C: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80090180: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80090184: beq         $at, $zero, L_80090198
    if (ctx->r1 == 0) {
        // 0x80090188: nop
    
            goto L_80090198;
    }
    // 0x80090188: nop

    // 0x8009018C: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x80090190: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80090194: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_80090198:
    // 0x80090198: blez        $s3, L_80090230
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8009019C: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_80090230;
    }
    // 0x8009019C: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800901A0: beq         $at, $zero, L_800901C0
    if (ctx->r1 == 0) {
        // 0x800901A4: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_800901C0;
    }
    // 0x800901A4: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x800901A8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800901AC: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x800901B0: bnel        $at, $zero, L_800901C4
    if (ctx->r1 != 0) {
        // 0x800901B4: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800901C4;
    }
    goto skip_9;
    // 0x800901B4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x800901B8: b           L_800901C8
    // 0x800901BC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_800901C8;
    // 0x800901BC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_800901C0:
    // 0x800901C0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_800901C4:
    // 0x800901C4: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_800901C8:
    // 0x800901C8: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800901CC: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x800901D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800901D4: bne         $a1, $t6, L_800901FC
    if (ctx->r5 != ctx->r14) {
        // 0x800901D8: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_800901FC;
    }
    // 0x800901D8: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x800901DC: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_800901E0:
    // 0x800901E0: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x800901E4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800901E8: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800901EC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800901F0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800901F4: beq         $a0, $t9, L_800901E0
    if (ctx->r4 == ctx->r25) {
        // 0x800901F8: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800901E0;
    }
    // 0x800901F8: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_800901FC:
    // 0x800901FC: bne         $a0, $at, L_80090210
    if (ctx->r4 != ctx->r1) {
        // 0x80090200: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_80090210;
    }
    // 0x80090200: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x80090204: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80090208: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009020C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_80090210:
    // 0x80090210: bgez        $v1, L_80090230
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80090214: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_80090230;
    }
    // 0x80090214: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x80090218: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8009021C: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80090220: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80090224: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80090228: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8009022C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80090230:
    // 0x80090230: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x80090234: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x80090238: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x8009023C: jal         0x8008F7B0
    // 0x80090240: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    static_4_8008F7B0(rdram, ctx);
        goto after_2;
    // 0x80090240: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x80090244: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80090248:
    // 0x80090248: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8009024C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80090250: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80090254: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80090258: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8009025C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80090260: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80090264: jr          $ra
    // 0x80090268: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80090268: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_804395D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804395D0: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x804395D4: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x804395D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804395DC: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x804395E0: addu        $a3, $v1, $t6
    ctx->r7 = ADD32(ctx->r3, ctx->r14);
    // 0x804395E4: lwc1        $f0, 0xA1C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XA1C);
    // 0x804395E8: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x804395EC: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x804395F0: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x804395F4: lw          $v0, 0xD10($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XD10);
    // 0x804395F8: addiu       $a3, $a3, 0xA1C
    ctx->r7 = ADD32(ctx->r7, 0XA1C);
    // 0x804395FC: lwc1        $f2, 0x4($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80439600: bc1f        L_80439800
    if (!c1cs) {
        // 0x80439604: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_80439800;
    }
    // 0x80439604: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80439608: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8043960C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80439610: bc1f        L_80439800
    if (!c1cs) {
        // 0x80439614: nop
    
            goto L_80439800;
    }
    // 0x80439614: nop

    // 0x80439618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8043961C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80439620: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80439624: nop

    // 0x80439628: bc1f        L_80439BA4
    if (!c1cs) {
        // 0x8043962C: nop
    
            goto L_80439BA4;
    }
    // 0x8043962C: nop

    // 0x80439630: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80439634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80439638: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(80, 0X19F8) << 16);
    // 0x8043963C: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x80439640: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x80439644: bc1f        L_80439BA4
    if (!c1cs) {
        // 0x80439648: nop
    
            goto L_80439BA4;
    }
    // 0x80439648: nop

    // 0x8043964C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80439650: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80439654: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x80439658: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8043965C: cvt.w.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80439660: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80439664: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80439668: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8043966C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80439670: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80439674: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80439678: beql        $a1, $zero, L_804396C8
    if (ctx->r5 == 0) {
        // 0x8043967C: mfc1        $a1, $f8
        ctx->r5 = (int32_t)ctx->f8.u32l;
            goto L_804396C8;
    }
    goto skip_0;
    // 0x8043967C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80439680: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80439684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80439688: sub.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8043968C: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80439690: nop

    // 0x80439694: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80439698: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x8043969C: nop

    // 0x804396A0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x804396A4: bne         $a1, $zero, L_804396BC
    if (ctx->r5 != 0) {
        // 0x804396A8: nop
    
            goto L_804396BC;
    }
    // 0x804396A8: nop

    // 0x804396AC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x804396B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804396B4: b           L_804396D4
    // 0x804396B8: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_804396D4;
    // 0x804396B8: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_804396BC:
    // 0x804396BC: b           L_804396D4
    // 0x804396C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_804396D4;
    // 0x804396C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x804396C4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
L_804396C8:
    // 0x804396C8: nop

    // 0x804396CC: bltz        $a1, L_804396BC
    if (SIGNED(ctx->r5) < 0) {
        // 0x804396D0: nop
    
            goto L_804396BC;
    }
    // 0x804396D0: nop

L_804396D4:
    // 0x804396D4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x804396D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804396DC: lui         $t4, 0x8044
    ctx->r12 = S32(RELOC_HI16(80, 0X19EC) << 16);
    // 0x804396E0: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x804396E4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x804396E8: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x804396EC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x804396F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804396F4: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x804396F8: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x804396FC: nop

    // 0x80439700: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80439704: beql        $v1, $zero, L_80439754
    if (ctx->r3 == 0) {
        // 0x80439708: mfc1        $v1, $f10
        ctx->r3 = (int32_t)ctx->f10.u32l;
            goto L_80439754;
    }
    goto skip_1;
    // 0x80439708: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x8043970C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80439710: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80439714: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80439718: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x8043971C: nop

    // 0x80439720: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80439724: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80439728: nop

    // 0x8043972C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80439730: bne         $v1, $zero, L_80439748
    if (ctx->r3 != 0) {
        // 0x80439734: nop
    
            goto L_80439748;
    }
    // 0x80439734: nop

    // 0x80439738: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8043973C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80439740: b           L_80439760
    // 0x80439744: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80439760;
    // 0x80439744: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_80439748:
    // 0x80439748: b           L_80439760
    // 0x8043974C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80439760;
    // 0x8043974C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80439750: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
L_80439754:
    // 0x80439754: nop

    // 0x80439758: bltz        $v1, L_80439748
    if (SIGNED(ctx->r3) < 0) {
        // 0x8043975C: nop
    
            goto L_80439748;
    }
    // 0x8043975C: nop

L_80439760:
    // 0x80439760: lw          $t6, -0x5B48($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(80, 0X19F8));
    // 0x80439764: lw          $t4, -0x5B54($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(80, 0X19EC));
    // 0x80439768: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8043976C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80439770: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80439774: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80439778: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8043977C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80439780: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80439784: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80439788: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8043978C: andi        $t4, $v1, 0xFFF
    ctx->r12 = ctx->r3 & 0XFFF;
    // 0x80439790: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x80439794: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80439798: andi        $t6, $a1, 0xFFF
    ctx->r14 = ctx->r5 & 0XFFF;
    // 0x8043979C: or          $t9, $t5, $t6
    ctx->r25 = ctx->r13 | ctx->r14;
    // 0x804397A0: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x804397A4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x804397A8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804397AC: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x804397B0: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x804397B4: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x804397B8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804397BC: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x804397C0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x804397C4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804397C8: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(80, 0X1A04) << 16);
    // 0x804397CC: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(80, 0X1A0C) << 16);
    // 0x804397D0: addiu       $t4, $a3, 0x8
    ctx->r12 = ADD32(ctx->r7, 0X8);
    // 0x804397D4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x804397D8: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x804397DC: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x804397E0: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x804397E4: lh          $t8, -0x5B3C($t7)
    ctx->r24 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(80, 0X1A04));
    // 0x804397E8: lh          $t6, -0x5B34($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(80, 0X1A0C));
    // 0x804397EC: sll         $t4, $t8, 16
    ctx->r12 = S32(ctx->r24 << 16);
    // 0x804397F0: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x804397F4: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x804397F8: jr          $ra
    // 0x804397FC: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    return;
    // 0x804397FC: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
L_80439800:
    // 0x80439800: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(80, 0X19EC) << 16);
    // 0x80439804: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x80439808: lw          $t6, -0x5B54($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(80, 0X19EC));
    // 0x8043980C: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(80, 0X19F8) << 16);
    // 0x80439810: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80439814: srl         $t7, $t6, 2
    ctx->r15 = S32(U32(ctx->r14) >> 2);
    // 0x80439818: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8043981C: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x80439820: bgez        $t7, L_80439834
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80439824: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80439834;
    }
    // 0x80439824: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80439828: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043982C: nop

    // 0x80439830: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80439834:
    // 0x80439834: lw          $t8, -0x5B48($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(80, 0X19F8));
    // 0x80439838: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8043983C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80439840: srl         $t9, $t8, 2
    ctx->r25 = S32(U32(ctx->r24) >> 2);
    // 0x80439844: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80439848: bgez        $t9, L_8043985C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8043984C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8043985C;
    }
    // 0x8043984C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80439850: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80439854: nop

    // 0x80439858: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8043985C:
    // 0x8043985C: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80439860: add.s       $f14, $f10, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80439864: bc1f        L_80439BA4
    if (!c1cs) {
        // 0x80439868: nop
    
            goto L_80439BA4;
    }
    // 0x80439868: nop

    // 0x8043986C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x80439870: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80439874: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x80439878: bc1f        L_80439BA4
    if (!c1cs) {
        // 0x8043987C: nop
    
            goto L_80439BA4;
    }
    // 0x8043987C: nop

    // 0x80439880: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80439884: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(80, 0X1A14) << 16);
    // 0x80439888: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8043988C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80439890: bc1f        L_804398C0
    if (!c1cs) {
        // 0x80439894: addu        $at, $at, $t0
        ctx->r1 = ADD32(ctx->r1, ctx->r8);
            goto L_804398C0;
    }
    // 0x80439894: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80439898: lwc1        $f6, -0x5B2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(80, 0X1A14));
    // 0x8043989C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x804398A0: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804398A4: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x804398A8: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804398AC: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x804398B0: nop

    // 0x804398B4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x804398B8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x804398BC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_804398C0:
    // 0x804398C0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x804398C4: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(80, 0X1A14) << 16);
    // 0x804398C8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x804398CC: bc1fl       L_80439900
    if (!c1cs) {
        // 0x804398D0: cfc1        $t7, $FpcCsr
        ctx->r15 = get_cop1_cs();
            goto L_80439900;
    }
    goto skip_2;
    // 0x804398D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    skip_2:
    // 0x804398D4: lwc1        $f10, -0x5B2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(80, 0X1A14));
    // 0x804398D8: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x804398DC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804398E0: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x804398E4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804398E8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x804398EC: nop

    // 0x804398F0: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x804398F4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x804398F8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x804398FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_80439900:
    // 0x80439900: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80439904: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x80439908: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8043990C: cvt.w.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80439910: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x80439914: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80439918: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8043991C: nop

    // 0x80439920: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80439924: beql        $t8, $zero, L_80439974
    if (ctx->r24 == 0) {
        // 0x80439928: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_80439974;
    }
    goto skip_3;
    // 0x80439928: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x8043992C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80439930: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80439934: sub.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80439938: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8043993C: nop

    // 0x80439940: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80439944: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80439948: nop

    // 0x8043994C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80439950: bne         $t8, $zero, L_80439968
    if (ctx->r24 != 0) {
        // 0x80439954: nop
    
            goto L_80439968;
    }
    // 0x80439954: nop

    // 0x80439958: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8043995C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80439960: b           L_80439980
    // 0x80439964: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80439980;
    // 0x80439964: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80439968:
    // 0x80439968: b           L_80439980
    // 0x8043996C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80439980;
    // 0x8043996C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80439970: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_80439974:
    // 0x80439974: nop

    // 0x80439978: bltz        $t8, L_80439968
    if (SIGNED(ctx->r24) < 0) {
        // 0x8043997C: nop
    
            goto L_80439968;
    }
    // 0x8043997C: nop

L_80439980:
    // 0x80439980: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80439984: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80439988: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8043998C: andi        $t4, $t9, 0xFFF
    ctx->r12 = ctx->r25 & 0XFFF;
    // 0x80439990: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80439994: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80439998: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x8043999C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x804399A0: cvt.w.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = CVT_W_S(ctx->f14.fl);
    // 0x804399A4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x804399A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804399AC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x804399B0: nop

    // 0x804399B4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x804399B8: beql        $t8, $zero, L_80439A08
    if (ctx->r24 == 0) {
        // 0x804399BC: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_80439A08;
    }
    goto skip_4;
    // 0x804399BC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x804399C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804399C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804399C8: sub.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x804399CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x804399D0: nop

    // 0x804399D4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x804399D8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x804399DC: nop

    // 0x804399E0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x804399E4: bne         $t8, $zero, L_804399FC
    if (ctx->r24 != 0) {
        // 0x804399E8: nop
    
            goto L_804399FC;
    }
    // 0x804399E8: nop

    // 0x804399EC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x804399F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804399F4: b           L_80439A14
    // 0x804399F8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80439A14;
    // 0x804399F8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_804399FC:
    // 0x804399FC: b           L_80439A14
    // 0x80439A00: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80439A14;
    // 0x80439A00: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80439A04: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_80439A08:
    // 0x80439A08: nop

    // 0x80439A0C: bltz        $t8, L_804399FC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80439A10: nop
    
            goto L_804399FC;
    }
    // 0x80439A10: nop

L_80439A14:
    // 0x80439A14: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80439A18: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80439A1C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80439A20: andi        $t4, $t9, 0xFFF
    ctx->r12 = ctx->r25 & 0XFFF;
    // 0x80439A24: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80439A28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80439A2C: or          $t5, $t6, $t4
    ctx->r13 = ctx->r14 | ctx->r12;
    // 0x80439A30: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80439A34: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80439A38: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80439A3C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80439A40: nop

    // 0x80439A44: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80439A48: beql        $t8, $zero, L_80439A98
    if (ctx->r24 == 0) {
        // 0x80439A4C: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_80439A98;
    }
    goto skip_5;
    // 0x80439A4C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_5:
    // 0x80439A50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80439A54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80439A58: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80439A5C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80439A60: nop

    // 0x80439A64: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80439A68: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80439A6C: nop

    // 0x80439A70: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80439A74: bne         $t8, $zero, L_80439A8C
    if (ctx->r24 != 0) {
        // 0x80439A78: nop
    
            goto L_80439A8C;
    }
    // 0x80439A78: nop

    // 0x80439A7C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80439A80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80439A84: b           L_80439AA4
    // 0x80439A88: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80439AA4;
    // 0x80439A88: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80439A8C:
    // 0x80439A8C: b           L_80439AA4
    // 0x80439A90: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80439AA4;
    // 0x80439A90: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80439A94: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_80439A98:
    // 0x80439A98: nop

    // 0x80439A9C: bltz        $t8, L_80439A8C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80439AA0: nop
    
            goto L_80439A8C;
    }
    // 0x80439AA0: nop

L_80439AA4:
    // 0x80439AA4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80439AA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80439AAC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80439AB0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80439AB4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80439AB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80439ABC: sll         $t4, $t6, 12
    ctx->r12 = S32(ctx->r14 << 12);
    // 0x80439AC0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80439AC4: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80439AC8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80439ACC: nop

    // 0x80439AD0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80439AD4: beql        $t7, $zero, L_80439B24
    if (ctx->r15 == 0) {
        // 0x80439AD8: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_80439B24;
    }
    goto skip_6;
    // 0x80439AD8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_6:
    // 0x80439ADC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80439AE0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80439AE4: sub.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80439AE8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80439AEC: nop

    // 0x80439AF0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80439AF4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80439AF8: nop

    // 0x80439AFC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80439B00: bne         $t7, $zero, L_80439B18
    if (ctx->r15 != 0) {
        // 0x80439B04: nop
    
            goto L_80439B18;
    }
    // 0x80439B04: nop

    // 0x80439B08: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80439B0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80439B10: b           L_80439B30
    // 0x80439B14: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80439B30;
    // 0x80439B14: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80439B18:
    // 0x80439B18: b           L_80439B30
    // 0x80439B1C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80439B30;
    // 0x80439B1C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80439B20: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_80439B24:
    // 0x80439B24: nop

    // 0x80439B28: bltz        $t7, L_80439B18
    if (SIGNED(ctx->r15) < 0) {
        // 0x80439B2C: nop
    
            goto L_80439B18;
    }
    // 0x80439B2C: nop

L_80439B30:
    // 0x80439B30: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80439B34: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80439B38: or          $t6, $t4, $t9
    ctx->r14 = ctx->r12 | ctx->r25;
    // 0x80439B3C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80439B40: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80439B44: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80439B48: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x80439B4C: addiu       $t5, $a3, 0x8
    ctx->r13 = ADD32(ctx->r7, 0X8);
    // 0x80439B50: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80439B54: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x80439B58: or          $t6, $t4, $t9
    ctx->r14 = ctx->r12 | ctx->r25;
    // 0x80439B5C: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80439B60: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80439B64: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80439B68: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80439B6C: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80439B70: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(80, 0X1A04) << 16);
    // 0x80439B74: addiu       $t5, $a3, 0x8
    ctx->r13 = ADD32(ctx->r7, 0X8);
    // 0x80439B78: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80439B7C: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(80, 0X1A0C) << 16);
    // 0x80439B80: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80439B84: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x80439B88: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80439B8C: lh          $t6, -0x5B3C($t9)
    ctx->r14 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(80, 0X1A04));
    // 0x80439B90: lh          $t8, -0x5B34($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(80, 0X1A0C));
    // 0x80439B94: sll         $t5, $t6, 16
    ctx->r13 = S32(ctx->r14 << 16);
    // 0x80439B98: andi        $t4, $t8, 0xFFFF
    ctx->r12 = ctx->r24 & 0XFFFF;
    // 0x80439B9C: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80439BA0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
L_80439BA4:
    // 0x80439BA4: jr          $ra
    // 0x80439BA8: nop

    return;
    // 0x80439BA8: nop

;}
RECOMP_FUNC void func_805A2284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2284: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x805A2288: lw          $v1, 0x7F78($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7F78);
    // 0x805A228C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x805A2290: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805A2294: divu        $zero, $v1, $at
    lo = S32(U32(ctx->r3) / U32(ctx->r1)); hi = S32(U32(ctx->r3) % U32(ctx->r1));
    // 0x805A2298: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A229C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A22A0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805A22A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A22A8: mfhi        $t7
    ctx->r15 = hi;
    // 0x805A22AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A22B0: bne         $t7, $zero, L_805A22C4
    if (ctx->r15 != 0) {
        // 0x805A22B4: sw          $t6, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r14;
            goto L_805A22C4;
    }
    // 0x805A22B4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x805A22B8: jal         0x805A1BFC
    // 0x805A22BC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_805A1BFC(rdram, ctx);
        goto after_0;
    // 0x805A22BC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x805A22C0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_805A22C4:
    // 0x805A22C4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x805A22C8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x805A22CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x805A22D0: jal         0x80049D74
    // 0x805A22D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049D74(rdram, ctx);
        goto after_1;
    // 0x805A22D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A22D8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x805A22DC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x805A22E0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x805A22E4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805A22E8: lw          $v1, 0x40($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X40);
    // 0x805A22EC: lhu         $a0, 0x18($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X18);
    // 0x805A22F0: beql        $a0, $zero, L_805A2338
    if (ctx->r4 == 0) {
        // 0x805A22F4: lw          $t1, 0xC($v0)
        ctx->r9 = MEM_W(ctx->r2, 0XC);
            goto L_805A2338;
    }
    goto skip_0;
    // 0x805A22F4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x805A22F8: beql        $a0, $at, L_805A2338
    if (ctx->r4 == ctx->r1) {
        // 0x805A22FC: lw          $t1, 0xC($v0)
        ctx->r9 = MEM_W(ctx->r2, 0XC);
            goto L_805A2338;
    }
    goto skip_1;
    // 0x805A22FC: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    skip_1:
    // 0x805A2300: lbu         $a0, 0x18($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X18);
    // 0x805A2304: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x805A2308: andi        $a0, $a0, 0xF8
    ctx->r4 = ctx->r4 & 0XF8;
    // 0x805A230C: beq         $a0, $at, L_805A2334
    if (ctx->r4 == ctx->r1) {
        // 0x805A2310: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_805A2334;
    }
    // 0x805A2310: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x805A2314: beql        $a0, $at, L_805A2338
    if (ctx->r4 == ctx->r1) {
        // 0x805A2318: lw          $t1, 0xC($v0)
        ctx->r9 = MEM_W(ctx->r2, 0XC);
            goto L_805A2338;
    }
    goto skip_2;
    // 0x805A2318: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    skip_2:
    // 0x805A231C: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x805A2320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2324: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x805A2328: bnel        $t0, $zero, L_805A2338
    if (ctx->r8 != 0) {
        // 0x805A232C: lw          $t1, 0xC($v0)
        ctx->r9 = MEM_W(ctx->r2, 0XC);
            goto L_805A2338;
    }
    goto skip_3;
    // 0x805A232C: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    skip_3:
    // 0x805A2330: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
L_805A2334:
    // 0x805A2334: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
L_805A2338:
    // 0x805A2338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A233C: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x805A2340: bne         $t1, $zero, L_805A2358
    if (ctx->r9 != 0) {
        // 0x805A2344: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805A2358;
    }
    // 0x805A2344: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805A2348: beql        $v1, $zero, L_805A235C
    if (ctx->r3 == 0) {
        // 0x805A234C: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_805A235C;
    }
    goto skip_4;
    // 0x805A234C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    skip_4:
    // 0x805A2350: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x805A2354: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
L_805A2358:
    // 0x805A2358: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_805A235C:
    // 0x805A235C: beql        $at, $zero, L_805A2388
    if (ctx->r1 == 0) {
        // 0x805A2360: lw          $t3, 0x174($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X174);
            goto L_805A2388;
    }
    goto skip_5;
    // 0x805A2360: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    skip_5:
    // 0x805A2364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A2368: jal         0x80048F84
    // 0x805A236C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805A236C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x805A2370: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A2374: jal         0x80048F84
    // 0x805A2378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805A2378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805A237C: b           L_805A23C0
    // 0x805A2380: nop

        goto L_805A23C0;
    // 0x805A2380: nop

    // 0x805A2384: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
L_805A2388:
    // 0x805A2388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A238C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x805A2390: sh          $a1, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r5;
    // 0x805A2394: jal         0x8005FCA8
    // 0x805A2398: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8005FCA8(rdram, ctx);
        goto after_4;
    // 0x805A2398: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_4:
    // 0x805A239C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x805A23A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805A23A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A23A8: lw          $a3, 0x28($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X28);
    // 0x805A23AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A23B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A23B4: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x805A23B8: jal         0x805A2B28
    // 0x805A23BC: sw          $a3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r7;
    func_805A2B28(rdram, ctx);
        goto after_5;
    // 0x805A23BC: sw          $a3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r7;
    after_5:
L_805A23C0:
    // 0x805A23C0: jal         0x805A1BA8
    // 0x805A23C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1BA8(rdram, ctx);
        goto after_6;
    // 0x805A23C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805A23C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A23CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A23D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805A23D4: jr          $ra
    // 0x805A23D8: nop

    return;
    // 0x805A23D8: nop

;}
RECOMP_FUNC void func_8051F0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F0D0: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8051F0D4: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x8051F0D8: lh          $t4, 0x144($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X144);
    // 0x8051F0DC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8051F0E0: lw          $t3, 0x80($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X80);
    // 0x8051F0E4: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8051F0E8: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8051F0EC: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x8051F0F0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8051F0F4: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x8051F0F8: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x8051F0FC: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8051F100: addiu       $a0, $t5, 0x8
    ctx->r4 = ADD32(ctx->r13, 0X8);
    // 0x8051F104: addu        $a2, $t3, $t8
    ctx->r6 = ADD32(ctx->r11, ctx->r24);
    // 0x8051F108: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8051F10C: lui         $t9, 0x18
    ctx->r25 = S32(0X18 << 16);
    // 0x8051F110: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
    // 0x8051F114: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8051F118: ori         $t9, $t9, 0x2CF0
    ctx->r25 = ctx->r25 | 0X2CF0;
    // 0x8051F11C: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x8051F120: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8051F124: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8051F128: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8051F12C: addiu       $t2, $a0, 0x8
    ctx->r10 = ADD32(ctx->r4, 0X8);
    // 0x8051F130: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8051F134: lui         $t4, 0xC18
    ctx->r12 = S32(0XC18 << 16);
    // 0x8051F138: ori         $t4, $t4, 0x4340
    ctx->r12 = ctx->r12 | 0X4340;
    // 0x8051F13C: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x8051F140: addu        $a3, $t3, $t7
    ctx->r7 = ADD32(ctx->r11, ctx->r15);
    // 0x8051F144: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8051F148: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8051F14C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x8051F150: addiu       $v0, $t2, 0x8
    ctx->r2 = ADD32(ctx->r10, 0X8);
    // 0x8051F154: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8051F158: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8051F15C: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x8051F160: lui         $t8, 0xFC16
    ctx->r24 = S32(0XFC16 << 16);
    // 0x8051F164: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8051F168: ori         $t8, $t8, 0x1A60
    ctx->r24 = ctx->r24 | 0X1A60;
    // 0x8051F16C: lui         $t9, 0x25FD
    ctx->r25 = S32(0X25FD << 16);
    // 0x8051F170: ori         $t9, $t9, 0x2578
    ctx->r25 = ctx->r25 | 0X2578;
    // 0x8051F174: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8051F178: addiu       $t2, $a0, 0x8
    ctx->r10 = ADD32(ctx->r4, 0X8);
    // 0x8051F17C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8051F180: addiu       $t7, $zero, 0x204
    ctx->r15 = ADD32(0, 0X204);
    // 0x8051F184: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x8051F188: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8051F18C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8051F190: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8051F194: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8051F198: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8051F19C: lbu         $t8, 0xD($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XD);
    // 0x8051F1A0: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
    // 0x8051F1A4: addiu       $v0, $t3, 0x8
    ctx->r2 = ADD32(ctx->r11, 0X8);
    // 0x8051F1A8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8051F1AC: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8051F1B0: lbu         $t6, 0xE($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XE);
    // 0x8051F1B4: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x8051F1B8: lui         $t2, 0xFD68
    ctx->r10 = S32(0XFD68 << 16);
    // 0x8051F1BC: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8051F1C0: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8051F1C4: lbu         $t7, 0xF($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF);
    // 0x8051F1C8: ori         $t2, $t2, 0xF
    ctx->r10 = ctx->r10 | 0XF;
    // 0x8051F1CC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8051F1D0: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8051F1D4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8051F1D8: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8051F1DC: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8051F1E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8051F1E4: lbu         $t7, 0x11($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X11);
    // 0x8051F1E8: lbu         $t9, 0x10($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X10);
    // 0x8051F1EC: lui         $t3, 0xF568
    ctx->r11 = S32(0XF568 << 16);
    // 0x8051F1F0: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8051F1F4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8051F1F8: lbu         $t9, 0x12($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X12);
    // 0x8051F1FC: ori         $t3, $t3, 0x400
    ctx->r11 = ctx->r11 | 0X400;
    // 0x8051F200: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x8051F204: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8051F208: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8051F20C: lbu         $t6, 0x13($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13);
    // 0x8051F210: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8051F214: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8051F218: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8051F21C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8051F220: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8051F224: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x8051F228: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8051F22C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8051F230: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8051F234: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8051F238: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8051F23C: lui         $a2, 0xF200
    ctx->r6 = S32(0XF200 << 16);
    // 0x8051F240: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8051F244: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8051F248: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x8051F24C: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x8051F250: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8051F254: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8051F258: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8051F25C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8051F260: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8051F264: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8051F268: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x8051F26C: ori         $t8, $t8, 0xC03C
    ctx->r24 = ctx->r24 | 0XC03C;
    // 0x8051F270: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8051F274: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8051F278: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8051F27C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8051F280: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8051F284: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8051F288: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8051F28C: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8051F290: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8051F294: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8051F298: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8051F29C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8051F2A0: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8051F2A4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8051F2A8: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8051F2AC: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x8051F2B0: lui         $t6, 0x3
    ctx->r14 = S32(0X3 << 16);
    // 0x8051F2B4: ori         $t6, $t6, 0xC03C
    ctx->r14 = ctx->r14 | 0XC03C;
    // 0x8051F2B8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8051F2BC: sw          $v0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r2;
    // 0x8051F2C0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8051F2C4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8051F2C8: sw          $a2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r6;
    // 0x8051F2CC: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8051F2D0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8051F2D4: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x8051F2D8: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8051F2DC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8051F2E0: lui         $t6, 0xF568
    ctx->r14 = S32(0XF568 << 16);
    // 0x8051F2E4: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8051F2E8: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8051F2EC: ori         $t6, $t6, 0x420
    ctx->r14 = ctx->r14 | 0X420;
    // 0x8051F2F0: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x8051F2F4: sw          $a3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r7;
    // 0x8051F2F8: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8051F2FC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8051F300: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8051F304: lui         $t9, 0xF400
    ctx->r25 = S32(0XF400 << 16);
    // 0x8051F308: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8051F30C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8051F310: lui         $t6, 0x703
    ctx->r14 = S32(0X703 << 16);
    // 0x8051F314: ori         $t6, $t6, 0xC03C
    ctx->r14 = ctx->r14 | 0XC03C;
    // 0x8051F318: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x8051F31C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8051F320: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8051F324: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8051F328: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8051F32C: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    // 0x8051F330: addiu       $t2, $a3, 0x8
    ctx->r10 = ADD32(ctx->r7, 0X8);
    // 0x8051F334: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8051F338: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8051F33C: lui         $t8, 0x108
    ctx->r24 = S32(0X108 << 16);
    // 0x8051F340: lui         $t7, 0xF568
    ctx->r15 = S32(0XF568 << 16);
    // 0x8051F344: ori         $t7, $t7, 0x420
    ctx->r15 = ctx->r15 | 0X420;
    // 0x8051F348: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8051F34C: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8051F350: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8051F354: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8051F358: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x8051F35C: ori         $t9, $t9, 0xC03C
    ctx->r25 = ctx->r25 | 0XC03C;
    // 0x8051F360: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8051F364: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8051F368: sw          $a2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r6;
    // 0x8051F36C: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8051F370: ori         $t6, $t6, 0x103F
    ctx->r14 = ctx->r14 | 0X103F;
    // 0x8051F374: addiu       $v1, $t4, 0x8
    ctx->r3 = ADD32(ctx->r12, 0X8);
    // 0x8051F378: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8051F37C: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(303, 0X8D8) << 16);
    // 0x8051F380: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x8051F384: addiu       $t8, $t8, -0x6A8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(303, 0X8D8));
    // 0x8051F388: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8051F38C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8051F390: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8051F394: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8051F398: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8051F39C: jr          $ra
    // 0x8051F3A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8051F3A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8005AE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AE40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005AE44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005AE48: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005AE4C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005AE50: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8005AE54: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x8005AE58: lw          $s1, 0x20($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X20);
    // 0x8005AE5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005AE60: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005AE64: lh          $t9, 0x1C($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1C);
    // 0x8005AE68: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8005AE6C: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x8005AE70: mflo        $t8
    ctx->r24 = lo;
    // 0x8005AE74: nop

    // 0x8005AE78: nop

    // 0x8005AE7C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005AE80: mflo        $t0
    ctx->r8 = lo;
    // 0x8005AE84: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8005AE88: jal         0x80064F38
    // 0x8005AE8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80064F38(rdram, ctx);
        goto after_0;
    // 0x8005AE8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005AE90: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8005AE94: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005AE98: jal         0x800509EC
    // 0x8005AE9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800509EC(rdram, ctx);
        goto after_1;
    // 0x8005AE9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8005AEA0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005AEA4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005AEA8: addiu       $a2, $s0, 0x6
    ctx->r6 = ADD32(ctx->r16, 0X6);
    // 0x8005AEAC: bne         $v1, $zero, L_8005AEC8
    if (ctx->r3 != 0) {
        // 0x8005AEB0: sw          $v1, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r3;
            goto L_8005AEC8;
    }
    // 0x8005AEB0: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8005AEB4: addiu       $a0, $a0, 0xC30
    ctx->r4 = ADD32(ctx->r4, 0XC30);
    // 0x8005AEB8: jal         0x80071380
    // 0x8005AEBC: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8005AEBC: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    after_2:
    // 0x8005AEC0: b           L_8005AF04
    // 0x8005AEC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005AF04;
    // 0x8005AEC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005AEC8:
    // 0x8005AEC8: lh          $t3, 0x1C($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1C);
    // 0x8005AECC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8005AED0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8005AED4: lw          $a3, 0x20($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X20);
    // 0x8005AED8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005AEDC: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x8005AEE0: addu        $a0, $a1, $t2
    ctx->r4 = ADD32(ctx->r5, ctx->r10);
    // 0x8005AEE4: jal         0x8006BC70
    // 0x8005AEE8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_8006BC70(rdram, ctx);
        goto after_3;
    // 0x8005AEE8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_3:
    // 0x8005AEEC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8005AEF0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x8005AEF4: jal         0x80064E84
    // 0x8005AEF8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    func_80064E84(rdram, ctx);
        goto after_4;
    // 0x8005AEF8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    after_4:
    // 0x8005AEFC: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x8005AF00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005AF04:
    // 0x8005AF04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005AF08: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005AF0C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005AF10: jr          $ra
    // 0x8005AF14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005AF14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8001BABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001BAC4: jal         0x80019AC4
    // 0x8001BAC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x8001BAC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001BACC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8001BAD0: beq         $v0, $zero, L_8001BAF0
    if (ctx->r2 == 0) {
        // 0x8001BAD4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001BAF0;
    }
    // 0x8001BAD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001BAD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001BADC: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8001BAE0: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x8001BAE4: sh          $a0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r4;
    // 0x8001BAE8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8001BAEC: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
L_8001BAF0:
    // 0x8001BAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BAF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001BAF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001BAFC: jr          $ra
    // 0x8001BB00: nop

    return;
    // 0x8001BB00: nop

;}
RECOMP_FUNC void func_805181B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805181B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805181BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805181C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805181C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805181C8: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x805181CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805181D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805181D4: beq         $v0, $at, L_805181EC
    if (ctx->r2 == ctx->r1) {
        // 0x805181D8: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_805181EC;
    }
    // 0x805181D8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805181DC: beql        $v0, $at, L_8051824C
    if (ctx->r2 == ctx->r1) {
        // 0x805181E0: lw          $t8, 0x1F4($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X1F4);
            goto L_8051824C;
    }
    goto skip_0;
    // 0x805181E0: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x805181E4: b           L_8051826C
    // 0x805181E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8051826C;
    // 0x805181E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805181EC:
    // 0x805181EC: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x805181F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x805181F4: beql        $v0, $zero, L_8051826C
    if (ctx->r2 == 0) {
        // 0x805181F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8051826C;
    }
    goto skip_1;
    // 0x805181F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805181FC: bne         $v0, $at, L_80518234
    if (ctx->r2 != ctx->r1) {
        // 0x80518200: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80518234;
    }
    // 0x80518200: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80518204: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80518208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051820C: lbu         $t7, 0x18($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X18);
    // 0x80518210: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80518214: beql        $at, $zero, L_8051826C
    if (ctx->r1 == 0) {
        // 0x80518218: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8051826C;
    }
    goto skip_2;
    // 0x80518218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8051821C: jal         0x8004012C
    // 0x80518220: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8004012C(rdram, ctx);
        goto after_0;
    // 0x80518220: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x80518224: jal         0x80517D80
    // 0x80518228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80517D80(rdram, ctx);
        goto after_1;
    // 0x80518228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8051822C: b           L_8051826C
    // 0x80518230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8051826C;
    // 0x80518230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80518234:
    // 0x80518234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80518238: jal         0x8002F6E4
    // 0x8051823C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_2;
    // 0x8051823C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80518240: b           L_8051826C
    // 0x80518244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8051826C;
    // 0x80518244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80518248: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
L_8051824C:
    // 0x8051824C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80518250: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80518254: lw          $t9, 0x204($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X204);
    // 0x80518258: bnel        $t9, $zero, L_8051826C
    if (ctx->r25 != 0) {
        // 0x8051825C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8051826C;
    }
    goto skip_3;
    // 0x8051825C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80518260: jal         0x8002F6E4
    // 0x80518264: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_3;
    // 0x80518264: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80518268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8051826C:
    // 0x8051826C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80518270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80518274: jr          $ra
    // 0x80518278: nop

    return;
    // 0x80518278: nop

;}
RECOMP_FUNC void func_807BA3F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA3F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BA3F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807BA3F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BA3FC: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(892, 0X190) << 16);
    // 0x807BA400: lui         $a1, 0x807C
    ctx->r5 = S32(RELOC_HI16(892, 0X1A0) << 16);
    // 0x807BA404: addiu       $a1, $a1, -0x5A70
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(892, 0X1A0));
    // 0x807BA408: addiu       $a0, $a0, -0x5A80
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(892, 0X190));
    // 0x807BA40C: jal         0x8004667C
    // 0x807BA410: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x807BA410: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807BA414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BA418: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(892, 0X88) << 16);
    // 0x807BA41C: addiu       $t6, $t6, -0x5B88
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(892, 0X88));
    // 0x807BA420: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807BA424: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(892, 0X48) << 16);
    // 0x807BA428: sw          $t6, -0x727C($at)
    MEM_W(-0X727C, ctx->r1) = ctx->r14;
    // 0x807BA42C: addiu       $v0, $v0, -0x5BC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(892, 0X48));
    // 0x807BA430: jr          $ra
    // 0x807BA434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807BA434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804306E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804306E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804306E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804306EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804306F0: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x804306F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804306F8: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x804306FC: jal         0x80045A34
    // 0x80430700: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80430700: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80430704: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x80430708: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8043070C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X3150) << 16);
    // 0x80430710: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80430714: sw          $t7, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r15;
    // 0x80430718: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8043071C: addiu       $t8, $t8, 0x1230
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(56, 0X3150));
    // 0x80430720: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80430724: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x80430728: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8043072C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80430730: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80430734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80430738: jal         0x8005FCA8
    // 0x8043073C: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x8043073C: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    after_1:
    // 0x80430740: jal         0x804306CC
    // 0x80430744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804306CC(rdram, ctx);
        goto after_2;
    // 0x80430744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80430748: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8043074C: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x80430750: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80430754: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x80430758: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043075C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80430760: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
    // 0x80430764: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x80430768: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8043076C: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x80430770: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80430774: bnel        $t6, $zero, L_80430798
    if (ctx->r14 != 0) {
        // 0x80430778: lwc1        $f4, 0x3C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_80430798;
    }
    goto skip_0;
    // 0x80430778: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x8043077C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80430780: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80430784: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80430788: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8043078C: b           L_804307A8
    // 0x80430790: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
        goto L_804307A8;
    // 0x80430790: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x80430794: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
L_80430798:
    // 0x80430798: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043079C: nop

    // 0x804307A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804307A4: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
L_804307A8:
    // 0x804307A8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x804307AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804307B0: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804307B4: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x804307B8: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804307BC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804307C0: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x804307C4: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x804307C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804307CC: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x804307D0: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x804307D4: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x804307D8: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804307DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x804307E0: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    // 0x804307E4: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x804307E8: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x804307EC: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x804307F0: jal         0x8042F824
    // 0x804307F4: swc1        $f10, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f10.u32l;
    func_8042F824(rdram, ctx);
        goto after_3;
    // 0x804307F4: swc1        $f10, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f10.u32l;
    after_3:
    // 0x804307F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804307FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80430800: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80430804: jal         0x804303F0
    // 0x80430808: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_804303F0(rdram, ctx);
        goto after_4;
    // 0x80430808: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8043080C: lui         $t1, 0x8043
    ctx->r9 = S32(RELOC_HI16(56, 0X18C8) << 16);
    // 0x80430810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80430814: addiu       $t1, $t1, -0x658
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(56, 0X18C8));
    // 0x80430818: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x8043081C: sb          $v0, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r2;
    // 0x80430820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80430824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80430828: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043082C: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x80430830: jr          $ra
    // 0x80430834: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80430834: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8078ECBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078ECBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078ECC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078ECC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8078ECC8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8078ECCC: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078ECD0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8078ECD4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8078ECD8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8078ECDC: lw          $t9, 0x174($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X174);
    // 0x8078ECE0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8078ECE4: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
    // 0x8078ECE8: jal         0x8005FDC4
    // 0x8078ECEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x8078ECEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8078ECF0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8078ECF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078ECF8: sb          $zero, 0x165($a3)
    MEM_B(0X165, ctx->r7) = 0;
    // 0x8078ECFC: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x8078ED00: jal         0x8078F0A0
    // 0x8078ED04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8078F0A0(rdram, ctx);
        goto after_1;
    // 0x8078ED04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8078ED08: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8078ED0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8078ED10: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8078ED14: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8078ED18: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x8078ED1C: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8078ED20: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8078ED24: sw          $t1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r9;
    // 0x8078ED28: jal         0x8078EBE8
    // 0x8078ED2C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    func_8078EBE8(rdram, ctx);
        goto after_2;
    // 0x8078ED2C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    after_2:
    // 0x8078ED30: jal         0x80067E68
    // 0x8078ED34: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x8078ED34: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_3:
    // 0x8078ED38: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8078ED3C: jal         0x80067818
    // 0x8078ED40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8078ED40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8078ED44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078ED48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078ED4C: jr          $ra
    // 0x8078ED50: nop

    return;
    // 0x8078ED50: nop

;}
RECOMP_FUNC void func_8066B5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B5C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066B5CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B5D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8066B5D4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8066B5D8: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8066B5DC: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x8066B5E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B5E4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8066B5E8: jal         0x8066B970
    // 0x8066B5EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8066B970(rdram, ctx);
        goto after_0;
    // 0x8066B5EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8066B5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066B5F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8066B5F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8066B5FC: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x8066B600: jr          $ra
    // 0x8066B604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8066B604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8073ED7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073ED7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073ED80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073ED84: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8073ED88: blez        $v0, L_8073ED98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8073ED8C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8073ED98;
    }
    // 0x8073ED8C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8073ED90: b           L_8073EDBC
    // 0x8073ED94: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8073EDBC;
    // 0x8073ED94: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8073ED98:
    // 0x8073ED98: jal         0x8073ED1C
    // 0x8073ED9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8073ED1C(rdram, ctx);
        goto after_0;
    // 0x8073ED9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073EDA0: beq         $v0, $zero, L_8073EDB4
    if (ctx->r2 == 0) {
        // 0x8073EDA4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8073EDB4;
    }
    // 0x8073EDA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8073EDA8: addiu       $t7, $zero, 0x1F4
    ctx->r15 = ADD32(0, 0X1F4);
    // 0x8073EDAC: b           L_8073EDBC
    // 0x8073EDB0: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
        goto L_8073EDBC;
    // 0x8073EDB0: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
L_8073EDB4:
    // 0x8073EDB4: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8073EDB8: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
L_8073EDBC:
    // 0x8073EDBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EDC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073EDC4: jr          $ra
    // 0x8073EDC8: nop

    return;
    // 0x8073EDC8: nop

;}
RECOMP_FUNC void func_807104EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807104EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807104F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807104F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807104F8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807104FC: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80710500: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80710504: lbu         $t0, -0x7204($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X7204);
    // 0x80710508: lbu         $t6, 0x34($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X34);
    // 0x8071050C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80710510: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80710514: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80710518: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8071051C: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x80710520: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80710524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80710528: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8071052C: lw          $a1, 0x1E4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1E4);
    // 0x80710530: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
    // 0x80710534: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80710538: jal         0x8070FCFC
    // 0x8071053C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_8070FCFC(rdram, ctx);
        goto after_0;
    // 0x8071053C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_0:
    // 0x80710540: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80710544: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80710548: jal         0x8070FDDC
    // 0x8071054C: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    func_8070FDDC(rdram, ctx);
        goto after_1;
    // 0x8071054C: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    after_1:
    // 0x80710550: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80710554: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80710558: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8071055C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80710560: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80710564: lw          $t6, 0x1F4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1F4);
    // 0x80710568: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8071056C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80710570: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80710574: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80710578: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x8071057C: negu        $a2, $v0
    ctx->r6 = SUB32(0, ctx->r2);
    // 0x80710580: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80710584: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80710588: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8071058C: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80710590: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80710594: jal         0x8005C27C
    // 0x80710598: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x80710598: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8071059C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x807105A0: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x807105A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807105A8: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x807105AC: jal         0x80067818
    // 0x807105B0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x807105B0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    after_3:
    // 0x807105B4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x807105B8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x807105BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807105C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807105C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x807105C8: jal         0x807100BC
    // 0x807105CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_807100BC(rdram, ctx);
        goto after_4;
    // 0x807105CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_4:
    // 0x807105D0: beql        $v0, $zero, L_8071063C
    if (ctx->r2 == 0) {
        // 0x807105D4: lw          $t2, 0x1E4($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X1E4);
            goto L_8071063C;
    }
    goto skip_0;
    // 0x807105D4: lw          $t2, 0x1E4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1E4);
    skip_0:
    // 0x807105D8: jal         0x80710020
    // 0x807105DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80710020(rdram, ctx);
        goto after_5;
    // 0x807105DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807105E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807105E4: beq         $v0, $zero, L_80710600
    if (ctx->r2 == 0) {
        // 0x807105E8: sw          $v0, -0x7470($at)
        MEM_W(-0X7470, ctx->r1) = ctx->r2;
            goto L_80710600;
    }
    // 0x807105E8: sw          $v0, -0x7470($at)
    MEM_W(-0X7470, ctx->r1) = ctx->r2;
    // 0x807105EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807105F0: jal         0x80710C50
    // 0x807105F4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80710C50(rdram, ctx);
        goto after_6;
    // 0x807105F4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x807105F8: b           L_80710610
    // 0x807105FC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
        goto L_80710610;
    // 0x807105FC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
L_80710600:
    // 0x80710600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80710604: jal         0x80710C50
    // 0x80710608: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80710C50(rdram, ctx);
        goto after_7;
    // 0x80710608: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_7:
    // 0x8071060C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
L_80710610:
    // 0x80710610: jal         0x80067878
    // 0x80710614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_8;
    // 0x80710614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80710618: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    // 0x8071061C: jal         0x80067818
    // 0x80710620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x80710620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80710624: lw          $a0, 0x16C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X16C);
    // 0x80710628: jal         0x8070FFC0
    // 0x8071062C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8070FFC0(rdram, ctx);
        goto after_10;
    // 0x8071062C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x80710630: b           L_807106B8
    // 0x80710634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_807106B8;
    // 0x80710634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80710638: lw          $t2, 0x1E4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1E4);
L_8071063C:
    // 0x8071063C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80710640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80710644: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x80710648: bne         $at, $zero, L_807106AC
    if (ctx->r1 != 0) {
        // 0x8071064C: nop
    
            goto L_807106AC;
    }
    // 0x8071064C: nop

    // 0x80710650: jal         0x8070FFC0
    // 0x80710654: lw          $a0, 0x16C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X16C);
    func_8070FFC0(rdram, ctx);
        goto after_11;
    // 0x80710654: lw          $a0, 0x16C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X16C);
    after_11:
    // 0x80710658: jal         0x80710020
    // 0x8071065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80710020(rdram, ctx);
        goto after_12;
    // 0x8071065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80710660: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80710664: beq         $v0, $zero, L_80710680
    if (ctx->r2 == 0) {
        // 0x80710668: sw          $v0, -0x7470($at)
        MEM_W(-0X7470, ctx->r1) = ctx->r2;
            goto L_80710680;
    }
    // 0x80710668: sw          $v0, -0x7470($at)
    MEM_W(-0X7470, ctx->r1) = ctx->r2;
    // 0x8071066C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80710670: jal         0x80710C50
    // 0x80710674: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80710C50(rdram, ctx);
        goto after_13;
    // 0x80710674: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_13:
    // 0x80710678: b           L_80710690
    // 0x8071067C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
        goto L_80710690;
    // 0x8071067C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
L_80710680:
    // 0x80710680: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80710684: jal         0x80710C50
    // 0x80710688: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80710C50(rdram, ctx);
        goto after_14;
    // 0x80710688: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_14:
    // 0x8071068C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
L_80710690:
    // 0x80710690: jal         0x80067878
    // 0x80710694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_15;
    // 0x80710694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80710698: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    // 0x8071069C: jal         0x80067818
    // 0x807106A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_16;
    // 0x807106A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x807106A4: b           L_807106B8
    // 0x807106A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_807106B8;
    // 0x807106A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807106AC:
    // 0x807106AC: jal         0x80710C50
    // 0x807106B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80710C50(rdram, ctx);
        goto after_17;
    // 0x807106B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_17:
    // 0x807106B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_807106B8:
    // 0x807106B8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807106BC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807106C0: jr          $ra
    // 0x807106C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x807106C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80001470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001470: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80001474: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80001478: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000147C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80001480: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80001484: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80001488: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000148C: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80001490: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80001494: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80001498: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8000149C: addiu       $t7, $t7, 0x4D10
    ctx->r15 = ADD32(ctx->r15, 0X4D10);
    // 0x800014A0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800014A4: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x800014A8: lbu         $t8, 0x1C($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X1C);
    // 0x800014AC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800014B0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x800014B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800014B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800014BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800014C0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800014C4: bne         $t8, $at, L_800014E0
    if (ctx->r24 != ctx->r1) {
        // 0x800014C8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800014E0;
    }
    // 0x800014C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800014CC: sh          $a2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r6;
    // 0x800014D0: jal         0x80001264
    // 0x800014D4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_80001264(rdram, ctx);
        goto after_0;
    // 0x800014D4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x800014D8: b           L_800014F4
    // 0x800014DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
        goto L_800014F4;
    // 0x800014DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_800014E0:
    // 0x800014E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800014E4: sh          $a2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r6;
    // 0x800014E8: jal         0x80000C44
    // 0x800014EC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_80000C44(rdram, ctx);
        goto after_1;
    // 0x800014EC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_1:
    // 0x800014F0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_800014F4:
    // 0x800014F4: lhu         $t1, 0x22($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X22);
    // 0x800014F8: lui         $a1, 0xC34
    ctx->r5 = S32(0XC34 << 16);
    // 0x800014FC: lui         $t3, 0xC80
    ctx->r11 = S32(0XC80 << 16);
    // 0x80001500: ori         $t3, $t3, 0x940
    ctx->r11 = ctx->r11 | 0X940;
    // 0x80001504: or          $t2, $t1, $a1
    ctx->r10 = ctx->r9 | ctx->r5;
    // 0x80001508: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8000150C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80001510: lhu         $t4, 0x24($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X24);
    // 0x80001514: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80001518: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x8000151C: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80001520: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80001524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001528: lui         $t8, 0xC80
    ctx->r24 = S32(0XC80 << 16);
    // 0x8000152C: ori         $t8, $t8, 0xC80
    ctx->r24 = ctx->r24 | 0XC80;
    // 0x80001530: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80001534: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80001538: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8000153C: lhu         $t9, 0x28($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X28);
    // 0x80001540: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80001544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001548: bne         $t9, $zero, L_8000155C
    if (ctx->r25 != 0) {
        // 0x8000154C: nop
    
            goto L_8000155C;
    }
    // 0x8000154C: nop

    // 0x80001550: lhu         $t1, 0x2A($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2A);
    // 0x80001554: beql        $t1, $zero, L_8000156C
    if (ctx->r9 == 0) {
        // 0x80001558: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000156C;
    }
    goto skip_0;
    // 0x80001558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8000155C:
    // 0x8000155C: jal         0x80000BC0
    // 0x80001560: lh          $a1, 0x42($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X42);
    func_80000BC0(rdram, ctx);
        goto after_2;
    // 0x80001560: lh          $a1, 0x42($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X42);
    after_2:
    // 0x80001564: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80001568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000156C:
    // 0x8000156C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80001570: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001574: jr          $ra
    // 0x80001578: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80001578: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806CC6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CC6F8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x806CC6FC: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(604, 0X3AB4) << 16);
    // 0x806CC700: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x806CC704: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x806CC708: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x806CC70C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x806CC710: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x806CC714: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x806CC718: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x806CC71C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x806CC720: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x806CC724: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x806CC728: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806CC72C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806CC730: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x806CC734: addiu       $t8, $t8, -0xE2C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(604, 0X3AB4));
    // 0x806CC738: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x806CC73C: lw          $s7, 0x1F4($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CC740: addiu       $t7, $sp, 0x70
    ctx->r15 = ADD32(ctx->r29, 0X70);
    // 0x806CC744: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x806CC748: lhu         $t0, 0x8($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X8);
    // 0x806CC74C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x806CC750: lui         $t2, 0x806D
    ctx->r10 = S32(RELOC_HI16(604, 0X3AC0) << 16);
    // 0x806CC754: addiu       $t2, $t2, -0xE20
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(604, 0X3AC0));
    // 0x806CC758: sh          $t0, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r8;
    // 0x806CC75C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x806CC760: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x806CC764: addiu       $t1, $sp, 0x64
    ctx->r9 = ADD32(ctx->r29, 0X64);
    // 0x806CC768: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x806CC76C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x806CC770: lhu         $t4, 0x8($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X8);
    // 0x806CC774: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C1C) << 16);
    // 0x806CC778: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x806CC77C: sh          $t4, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r12;
    // 0x806CC780: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806CC784: lwc1        $f22, -0xCC4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C1C));
    // 0x806CC788: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806CC78C: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x806CC790: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x806CC794: addiu       $fp, $zero, 0x3FF
    ctx->r30 = ADD32(0, 0X3FF);
L_806CC798:
    // 0x806CC798: jal         0x80047090
    // 0x806CC79C: lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X0);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806CC79C: lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X0);
    after_0:
    // 0x806CC7A0: bne         $fp, $v0, L_806CC7B0
    if (ctx->r30 != ctx->r2) {
        // 0x806CC7A4: andi        $s6, $v0, 0xFFFF
        ctx->r22 = ctx->r2 & 0XFFFF;
            goto L_806CC7B0;
    }
    // 0x806CC7A4: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
    // 0x806CC7A8: b           L_806CC7D0
    // 0x806CC7AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_806CC7D0;
    // 0x806CC7AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_806CC7B0:
    // 0x806CC7B0: lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X0);
    // 0x806CC7B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806CC7B8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806CC7BC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806CC7C0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806CC7C4: jal         0x8004613C
    // 0x806CC7C8: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806CC7C8: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    after_1:
    // 0x806CC7CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_806CC7D0:
    // 0x806CC7D0: beq         $s0, $zero, L_806CC81C
    if (ctx->r16 == 0) {
        // 0x806CC7D4: andi        $t6, $s6, 0x3FF
        ctx->r14 = ctx->r22 & 0X3FF;
            goto L_806CC81C;
    }
    // 0x806CC7D4: andi        $t6, $s6, 0x3FF
    ctx->r14 = ctx->r22 & 0X3FF;
    // 0x806CC7D8: lhu         $t7, 0xE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XE);
    // 0x806CC7DC: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x806CC7E0: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x806CC7E4: andi        $t8, $t7, 0xFC00
    ctx->r24 = ctx->r15 & 0XFC00;
    // 0x806CC7E8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x806CC7EC: sh          $t9, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r25;
    // 0x806CC7F0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x806CC7F4: addu        $s1, $s7, $t1
    ctx->r17 = ADD32(ctx->r23, ctx->r9);
    // 0x806CC7F8: addu        $s4, $s5, $t0
    ctx->r20 = ADD32(ctx->r21, ctx->r8);
    // 0x806CC7FC: jal         0x80047F9C
    // 0x806CC800: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806CC800: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x806CC804: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x806CC808: swc1        $f22, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f22.u32l;
    // 0x806CC80C: lh          $t2, 0x0($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X0);
    // 0x806CC810: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806CC814: b           L_806CC824
    // 0x806CC818: sh          $t2, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r10;
        goto L_806CC824;
    // 0x806CC818: sh          $t2, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r10;
L_806CC81C:
    // 0x806CC81C: b           L_806CC850
    // 0x806CC820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806CC850;
    // 0x806CC820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806CC824:
    // 0x806CC824: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x806CC828: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x806CC82C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x806CC830: bne         $s2, $at, L_806CC798
    if (ctx->r18 != ctx->r1) {
        // 0x806CC834: sw          $s0, 0x874($s1)
        MEM_W(0X874, ctx->r17) = ctx->r16;
            goto L_806CC798;
    }
    // 0x806CC834: sw          $s0, 0x874($s1)
    MEM_W(0X874, ctx->r17) = ctx->r16;
    // 0x806CC838: sh          $zero, 0x872($s7)
    MEM_H(0X872, ctx->r23) = 0;
    // 0x806CC83C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C20) << 16);
    // 0x806CC840: lwc1        $f4, -0xCC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C20));
    // 0x806CC844: swc1        $f20, 0x864($s7)
    MEM_W(0X864, ctx->r23) = ctx->f20.u32l;
    // 0x806CC848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806CC84C: swc1        $f4, 0x868($s7)
    MEM_W(0X868, ctx->r23) = ctx->f4.u32l;
L_806CC850:
    // 0x806CC850: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x806CC854: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806CC858: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806CC85C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x806CC860: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x806CC864: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x806CC868: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x806CC86C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x806CC870: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x806CC874: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x806CC878: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x806CC87C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x806CC880: jr          $ra
    // 0x806CC884: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x806CC884: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
