#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804F57E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F57E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F57E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F57EC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804F57F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x804F57F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F57F8: bne         $t6, $at, L_804F5820
    if (ctx->r14 != ctx->r1) {
        // 0x804F57FC: lui         $v1, 0x8051
        ctx->r3 = S32(RELOC_HI16(273, 0X14250) << 16);
            goto L_804F5820;
    }
    // 0x804F57FC: lui         $v1, 0x8051
    ctx->r3 = S32(RELOC_HI16(273, 0X14250) << 16);
    // 0x804F5800: addiu       $v1, $v1, -0x7B20
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(273, 0X14250));
    // 0x804F5804: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x804F5808: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804F580C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x804F5810: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x804F5814: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F5818: jal         0x804F5CE8
    // 0x804F581C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804F5CE8(rdram, ctx);
        goto after_0;
    // 0x804F581C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
L_804F5820:
    // 0x804F5820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F5824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F5828: jr          $ra
    // 0x804F582C: nop

    return;
    // 0x804F582C: nop

;}
RECOMP_FUNC void func_8067FA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067FA40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067FA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067FA48: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067FA4C: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8067FA50: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8067FA54: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8067FA58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8067FA5C: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8067FA60: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x8067FA64: addiu       $t6, $a3, 0xC4
    ctx->r14 = ADD32(ctx->r7, 0XC4);
    // 0x8067FA68: bc1tl       L_8067FAB4
    if (c1cs) {
        // 0x8067FA6C: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_8067FAB4;
    }
    goto skip_0;
    // 0x8067FA6C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    skip_0:
    // 0x8067FA70: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8067FA74: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067FA78: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8067FA7C: add.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8067FA80: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8067FA84: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8067FA88: nop

    // 0x8067FA8C: bc1fl       L_8067FA9C
    if (!c1cs) {
        // 0x8067FA90: c.lt.s      $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
            goto L_8067FA9C;
    }
    goto skip_1;
    // 0x8067FA90: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    skip_1:
    // 0x8067FA94: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8067FA98: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
L_8067FA9C:
    // 0x8067FA9C: nop

    // 0x8067FAA0: bc1fl       L_8067FAB0
    if (!c1cs) {
        // 0x8067FAA4: swc1        $f0, 0x50($a3)
        MEM_W(0X50, ctx->r7) = ctx->f0.u32l;
            goto L_8067FAB0;
    }
    goto skip_2;
    // 0x8067FAA4: swc1        $f0, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f0.u32l;
    skip_2:
    // 0x8067FAA8: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8067FAAC: swc1        $f0, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f0.u32l;
L_8067FAB0:
    // 0x8067FAB0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
L_8067FAB4:
    // 0x8067FAB4: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8067FAB8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8067FABC: nop

    // 0x8067FAC0: bc1fl       L_8067FB20
    if (!c1cs) {
        // 0x8067FAC4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8067FB20;
    }
    goto skip_3;
    // 0x8067FAC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_3:
    // 0x8067FAC8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8067FACC: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x8067FAD0: beql        $t9, $zero, L_8067FB20
    if (ctx->r25 == 0) {
        // 0x8067FAD4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8067FB20;
    }
    goto skip_4;
    // 0x8067FAD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_4:
    // 0x8067FAD8: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x8067FADC: andi        $t1, $t0, 0xF00
    ctx->r9 = ctx->r8 & 0XF00;
    // 0x8067FAE0: bnel        $t1, $zero, L_8067FB20
    if (ctx->r9 != 0) {
        // 0x8067FAE4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8067FB20;
    }
    goto skip_5;
    // 0x8067FAE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_5:
    // 0x8067FAE8: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8067FAEC: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x8067FAF0: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x8067FAF4: swc1        $f18, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f18.u32l;
    // 0x8067FAF8: jal         0x80067BBC
    // 0x8067FAFC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8067FAFC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8067FB00: addiu       $a0, $zero, 0x282
    ctx->r4 = ADD32(0, 0X282);
    // 0x8067FB04: jal         0x80067818
    // 0x8067FB08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8067FB08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8067FB0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8067FB10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067FB14: jal         0x80680194
    // 0x8067FB18: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80680194(rdram, ctx);
        goto after_2;
    // 0x8067FB18: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x8067FB1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8067FB20:
    // 0x8067FB20: jal         0x80048F84
    // 0x8067FB24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8067FB24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8067FB28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067FB2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8067FB30: jr          $ra
    // 0x8067FB34: nop

    return;
    // 0x8067FB34: nop

;}
RECOMP_FUNC void func_8000CFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CFD0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000CFD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000CFD8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000CFDC: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8000CFE0: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x8000CFE4: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8000CFE8: jr          $ra
    // 0x8000CFEC: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8000CFEC: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8079AB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079AB1C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8079AB20: lw          $t6, 0x138($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X138);
    // 0x8079AB24: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8079AB28: beql        $t6, $zero, L_8079AB8C
    if (ctx->r14 == 0) {
        // 0x8079AB2C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8079AB8C;
    }
    goto skip_0;
    // 0x8079AB2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8079AB30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8079AB34: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8079AB38: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8079AB3C: nop

    // 0x8079AB40: bc1fl       L_8079AB6C
    if (!c1cs) {
        // 0x8079AB44: lw          $t1, 0x34($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X34);
            goto L_8079AB6C;
    }
    goto skip_1;
    // 0x8079AB44: lw          $t1, 0x34($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X34);
    skip_1:
    // 0x8079AB48: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x8079AB4C: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8079AB50: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8079AB54: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8079AB58: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
    // 0x8079AB5C: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x8079AB60: b           L_8079ABDC
    // 0x8079AB64: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
        goto L_8079ABDC;
    // 0x8079AB64: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x8079AB68: lw          $t1, 0x34($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X34);
L_8079AB6C:
    // 0x8079AB6C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8079AB70: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8079AB74: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8079AB78: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x8079AB7C: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x8079AB80: b           L_8079ABDC
    // 0x8079AB84: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
        goto L_8079ABDC;
    // 0x8079AB84: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
    // 0x8079AB88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8079AB8C:
    // 0x8079AB8C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8079AB90: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8079AB94: nop

    // 0x8079AB98: bc1fl       L_8079ABC4
    if (!c1cs) {
        // 0x8079AB9C: lw          $t9, 0x34($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X34);
            goto L_8079ABC4;
    }
    goto skip_2;
    // 0x8079AB9C: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    skip_2:
    // 0x8079ABA0: lw          $t5, 0x34($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X34);
    // 0x8079ABA4: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8079ABA8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8079ABAC: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8079ABB0: sw          $t6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r14;
    // 0x8079ABB4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8079ABB8: b           L_8079ABDC
    // 0x8079ABBC: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
        goto L_8079ABDC;
    // 0x8079ABBC: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
    // 0x8079ABC0: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
L_8079ABC4:
    // 0x8079ABC4: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8079ABC8: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8079ABCC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8079ABD0: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x8079ABD4: or          $t2, $t0, $at
    ctx->r10 = ctx->r8 | ctx->r1;
    // 0x8079ABD8: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
L_8079ABDC:
    // 0x8079ABDC: jr          $ra
    // 0x8079ABE0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8079ABE0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8042182C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042182C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80421830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80421834: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80421838: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8042183C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80421840: bne         $t7, $zero, L_80421854
    if (ctx->r15 != 0) {
        // 0x80421844: lw          $v0, 0x88($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X88);
            goto L_80421854;
    }
    // 0x80421844: lw          $v0, 0x88($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X88);
    // 0x80421848: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8042184C: jal         0x8004590C
    // 0x80421850: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x80421850: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    after_0:
L_80421854:
    // 0x80421854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80421858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042185C: jr          $ra
    // 0x80421860: nop

    return;
    // 0x80421860: nop

;}
RECOMP_FUNC void func_80682E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682E94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682E98: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682E9C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682EA0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682EA4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682EA8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682EAC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682EB0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682EB4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682EB8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682EBC: jr          $ra
    // 0x80682EC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682EC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806D6F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D6F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D6F30: jal         0x806D6BC0
    // 0x806D6F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D6BC0(rdram, ctx);
        goto after_0;
    // 0x806D6F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D6F38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D6F3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D6F40: jal         0x80048F84
    // 0x806D6F44: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806D6F44: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_1:
    // 0x806D6F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D6F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D6F50: jr          $ra
    // 0x806D6F54: nop

    return;
    // 0x806D6F54: nop

;}
RECOMP_FUNC void func_804334B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804334B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804334B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804334B8: jal         0x80432E48
    // 0x804334BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80432E48(rdram, ctx);
        goto after_0;
    // 0x804334BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804334C0: jal         0x80045BD8
    // 0x804334C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x804334C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804334C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804334CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804334D0: jr          $ra
    // 0x804334D4: nop

    return;
    // 0x804334D4: nop

;}
RECOMP_FUNC void func_807BA8F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA8F4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807BA8F8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x807BA8FC: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1220) << 16);
    // 0x807BA900: lwc1        $f6, -0x45D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1220));
    // 0x807BA904: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807BA908: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807BA90C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x807BA910: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807BA914: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x807BA918: nop

    // 0x807BA91C: bc1f        L_807BA948
    if (!c1cs) {
        // 0x807BA920: swc1        $f8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
            goto L_807BA948;
    }
    // 0x807BA920: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x807BA924: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807BA928: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807BA92C: nop

    // 0x807BA930: bc1f        L_807BA968
    if (!c1cs) {
        // 0x807BA934: nop
    
            goto L_807BA968;
    }
    // 0x807BA934: nop

    // 0x807BA938: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807BA93C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x807BA940: jr          $ra
    // 0x807BA944: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x807BA944: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_807BA948:
    // 0x807BA948: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807BA94C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x807BA950: nop

    // 0x807BA954: bc1f        L_807BA968
    if (!c1cs) {
        // 0x807BA958: nop
    
            goto L_807BA968;
    }
    // 0x807BA958: nop

    // 0x807BA95C: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807BA960: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x807BA964: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_807BA968:
    // 0x807BA968: jr          $ra
    // 0x807BA96C: nop

    return;
    // 0x807BA96C: nop

;}
RECOMP_FUNC void func_80736218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073621C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80736220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80736224: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80736228: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073622C: jal         0x80735DE4
    // 0x80736230: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80735DE4(rdram, ctx);
        goto after_0;
    // 0x80736230: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80736234: jal         0x80735E58
    // 0x80736238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80735E58(rdram, ctx);
        goto after_1;
    // 0x80736238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8073623C: jal         0x807360A0
    // 0x80736240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807360A0(rdram, ctx);
        goto after_2;
    // 0x80736240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80736244: bnel        $v0, $zero, L_80736298
    if (ctx->r2 != 0) {
        // 0x80736248: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80736298;
    }
    goto skip_0;
    // 0x80736248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8073624C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x80736250: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80736254: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80736258: blez        $v0, L_8073626C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8073625C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8073626C;
    }
    // 0x8073625C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80736260: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80736264: b           L_80736294
    // 0x80736268: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
        goto L_80736294;
    // 0x80736268: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_8073626C:
    // 0x8073626C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80736270:
    // 0x80736270: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80736274: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80736278: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8073627C: bne         $v0, $a0, L_80736270
    if (ctx->r2 != ctx->r4) {
        // 0x80736280: sb          $zero, 0x165($t8)
        MEM_B(0X165, ctx->r24) = 0;
            goto L_80736270;
    }
    // 0x80736280: sb          $zero, 0x165($t8)
    MEM_B(0X165, ctx->r24) = 0;
    // 0x80736284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80736288: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8073628C: jal         0x80736D18
    // 0x80736290: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80736D18(rdram, ctx);
        goto after_3;
    // 0x80736290: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
L_80736294:
    // 0x80736294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80736298:
    // 0x80736298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073629C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807362A0: jr          $ra
    // 0x807362A4: nop

    return;
    // 0x807362A4: nop

;}
RECOMP_FUNC void func_805AA954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA954: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805AA958: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805AA95C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805AA960: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805AA964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805AA968: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805AA96C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805AA970: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805AA974: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x805AA978: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x805AA97C: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA980: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x805AA984: bnel        $t8, $at, L_805AA998
    if (ctx->r24 != ctx->r1) {
        // 0x805AA988: lwc1        $f4, 0x50($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
            goto L_805AA998;
    }
    goto skip_0;
    // 0x805AA988: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x805AA98C: jal         0x805AA6F4
    // 0x805AA990: nop

    func_805AA6F4(rdram, ctx);
        goto after_0;
    // 0x805AA990: nop

    after_0:
    // 0x805AA994: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
L_805AA998:
    // 0x805AA998: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x805AA99C: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x805AA9A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805AA9A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805AA9A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805AA9AC: jal         0x80048F84
    // 0x805AA9B0: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x805AA9B0: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x805AA9B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805AA9B8: jal         0x80048F84
    // 0x805AA9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805AA9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805AA9C0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805AA9C4: beql        $v1, $zero, L_805AAA78
    if (ctx->r3 == 0) {
        // 0x805AA9C8: lw          $t2, 0x8($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X8);
            goto L_805AAA78;
    }
    goto skip_1;
    // 0x805AA9C8: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
    skip_1:
    // 0x805AA9CC: jal         0x805AA920
    // 0x805AA9D0: lhu         $a0, 0xC($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XC);
    func_805AA920(rdram, ctx);
        goto after_3;
    // 0x805AA9D0: lhu         $a0, 0xC($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XC);
    after_3:
    // 0x805AA9D4: beq         $v0, $zero, L_805AAA64
    if (ctx->r2 == 0) {
        // 0x805AA9D8: nop
    
            goto L_805AAA64;
    }
    // 0x805AA9D8: nop

    // 0x805AA9DC: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x805AA9E0: bnel        $t9, $zero, L_805AAA04
    if (ctx->r25 != 0) {
        // 0x805AA9E4: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_805AAA04;
    }
    goto skip_2;
    // 0x805AA9E4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x805AA9E8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805AA9EC: jal         0x80067BBC
    // 0x805AA9F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x805AA9F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x805AA9F4: addiu       $a0, $zero, 0xD1
    ctx->r4 = ADD32(0, 0XD1);
    // 0x805AA9F8: jal         0x80067818
    // 0x805AA9FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x805AA9FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x805AAA00: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_805AAA04:
    // 0x805AAA04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805AAA08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805AAA0C: sw          $t0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r8;
    // 0x805AAA10: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x805AAA14: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x805AAA18: lwc1        $f12, 0x98($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X98);
    // 0x805AAA1C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x805AAA20: jal         0x80066E88
    // 0x805AAA24: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x805AAA24: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x805AAA28: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x805AAA2C: jal         0x80066DE4
    // 0x805AAA30: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x805AAA30: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x805AAA34: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x805AAA38: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805AAA3C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805AAA40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805AAA44: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805AAA48: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x805AAA4C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x805AAA50: nop

    // 0x805AAA54: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805AAA58: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    // 0x805AAA5C: b           L_805AAAB0
    // 0x805AAA60: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
        goto L_805AAAB0;
    // 0x805AAA60: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
L_805AAA64:
    // 0x805AAA64: jal         0x805AA840
    // 0x805AAA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AA840(rdram, ctx);
        goto after_8;
    // 0x805AAA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x805AAA6C: b           L_805AAAB4
    // 0x805AAA70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805AAAB4;
    // 0x805AAA70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805AAA74: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
L_805AAA78:
    // 0x805AAA78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AAA7C: beql        $t2, $zero, L_805AAA90
    if (ctx->r10 == 0) {
        // 0x805AAA80: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_805AAA90;
    }
    goto skip_3;
    // 0x805AAA80: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_3:
    // 0x805AAA84: jal         0x800483B8
    // 0x805AAA88: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    func_800483B8(rdram, ctx);
        goto after_9;
    // 0x805AAA88: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    after_9:
    // 0x805AAA8C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_805AAA90:
    // 0x805AAA90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805AAA94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AAA98: jal         0x805AA678
    // 0x805AAA9C: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    func_805AA678(rdram, ctx);
        goto after_10;
    // 0x805AAA9C: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    after_10:
    // 0x805AAAA0: beql        $v0, $zero, L_805AAAB4
    if (ctx->r2 == 0) {
        // 0x805AAAA4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_805AAAB4;
    }
    goto skip_4;
    // 0x805AAAA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x805AAAA8: jal         0x805AA840
    // 0x805AAAAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AA840(rdram, ctx);
        goto after_11;
    // 0x805AAAAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_805AAAB0:
    // 0x805AAAB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805AAAB4:
    // 0x805AAAB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805AAAB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805AAABC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805AAAC0: jr          $ra
    // 0x805AAAC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805AAAC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_805AE054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE054: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE058: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE05C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE060: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE064: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE068: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE06C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE070: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE074: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE078: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE07C: jr          $ra
    // 0x805AE080: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE080: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80438180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438180: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80438184: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80438188: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8043818C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80438190: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80438194: addiu       $v0, $a0, 0x50
    ctx->r2 = ADD32(ctx->r4, 0X50);
    // 0x80438198: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043819C: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x804381A0: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804381A4: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x804381A8: nop

    // 0x804381AC: bc1fl       L_804381CC
    if (!c1cs) {
        // 0x804381B0: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_804381CC;
    }
    goto skip_0;
    // 0x804381B0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x804381B4: addiu       $v0, $a0, 0x50
    ctx->r2 = ADD32(ctx->r4, 0X50);
    // 0x804381B8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804381BC: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x804381C0: jr          $ra
    // 0x804381C4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x804381C4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x804381C8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_804381CC:
    // 0x804381CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804381D0: nop

    // 0x804381D4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x804381D8: nop

    // 0x804381DC: bc1f        L_804381EC
    if (!c1cs) {
        // 0x804381E0: nop
    
            goto L_804381EC;
    }
    // 0x804381E0: nop

    // 0x804381E4: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804381E8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_804381EC:
    // 0x804381EC: jr          $ra
    // 0x804381F0: nop

    return;
    // 0x804381F0: nop

;}
RECOMP_FUNC void func_8057D7D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057D7D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8057D7D4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8057D7D8: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x8057D7DC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8057D7E0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8057D7E4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8057D7E8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8057D7EC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8057D7F0: addiu       $s2, $s2, 0x7EA0
    ctx->r18 = ADD32(ctx->r18, 0X7EA0);
    // 0x8057D7F4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8057D7F8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8057D7FC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8057D800: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8057D804: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8057D808: lwc1        $f20, 0x44($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8057D80C: lw          $s1, 0xF54($s2)
    ctx->r17 = MEM_W(ctx->r18, 0XF54);
    // 0x8057D810: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8057D814: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x8057D818: addiu       $s5, $zero, 0x7
    ctx->r21 = ADD32(0, 0X7);
L_8057D81C:
    // 0x8057D81C: andi        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 & 0X1;
    // 0x8057D820: beq         $t6, $zero, L_8057D8A4
    if (ctx->r14 == 0) {
        // 0x8057D824: slti        $at, $s0, 0x6
        ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
            goto L_8057D8A4;
    }
    // 0x8057D824: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x8057D828: bne         $at, $zero, L_8057D898
    if (ctx->r1 != 0) {
        // 0x8057D82C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8057D898;
    }
    // 0x8057D82C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8057D830: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8057D834: lw          $t7, -0x7478($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7478);
    // 0x8057D838: bnel        $t7, $zero, L_8057D8A8
    if (ctx->r15 != 0) {
        // 0x8057D83C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8057D8A8;
    }
    goto skip_0;
    // 0x8057D83C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8057D840: bne         $s0, $s4, L_8057D868
    if (ctx->r16 != ctx->r20) {
        // 0x8057D844: nop
    
            goto L_8057D868;
    }
    // 0x8057D844: nop

    // 0x8057D848: lw          $t8, 0xF54($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XF54);
    // 0x8057D84C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8057D850: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x8057D854: beq         $t9, $zero, L_8057D868
    if (ctx->r25 == 0) {
        // 0x8057D858: nop
    
            goto L_8057D868;
    }
    // 0x8057D858: nop

    // 0x8057D85C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8057D860: jal         0x8057D750
    // 0x8057D864: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8057D750(rdram, ctx);
        goto after_0;
    // 0x8057D864: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
L_8057D868:
    // 0x8057D868: bnel        $s0, $s5, L_8057D8A8
    if (ctx->r16 != ctx->r21) {
        // 0x8057D86C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8057D8A8;
    }
    goto skip_1;
    // 0x8057D86C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8057D870: lw          $t0, 0xF54($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XF54);
    // 0x8057D874: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8057D878: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x8057D87C: beql        $t1, $zero, L_8057D8A8
    if (ctx->r9 == 0) {
        // 0x8057D880: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8057D8A8;
    }
    goto skip_2;
    // 0x8057D880: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8057D884: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8057D888: jal         0x8057D750
    // 0x8057D88C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8057D750(rdram, ctx);
        goto after_1;
    // 0x8057D88C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8057D890: b           L_8057D8A8
    // 0x8057D894: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8057D8A8;
    // 0x8057D894: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8057D898:
    // 0x8057D898: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8057D89C: jal         0x8057D750
    // 0x8057D8A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8057D750(rdram, ctx);
        goto after_2;
    // 0x8057D8A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
L_8057D8A4:
    // 0x8057D8A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8057D8A8:
    // 0x8057D8A8: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8057D8AC: bne         $at, $zero, L_8057D81C
    if (ctx->r1 != 0) {
        // 0x8057D8B0: srl         $s1, $s1, 1
        ctx->r17 = S32(U32(ctx->r17) >> 1);
            goto L_8057D81C;
    }
    // 0x8057D8B0: srl         $s1, $s1, 1
    ctx->r17 = S32(U32(ctx->r17) >> 1);
    // 0x8057D8B4: lw          $t2, 0x188($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X188);
    // 0x8057D8B8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8057D8BC: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8057D8C0: beql        $t2, $zero, L_8057D968
    if (ctx->r10 == 0) {
        // 0x8057D8C4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8057D968;
    }
    goto skip_3;
    // 0x8057D8C4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x8057D8C8: lw          $s1, 0xF54($s2)
    ctx->r17 = MEM_W(ctx->r18, 0XF54);
    // 0x8057D8CC: lw          $t3, -0x7478($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7478);
    // 0x8057D8D0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8057D8D4: and         $s1, $s1, $at
    ctx->r17 = ctx->r17 & ctx->r1;
    // 0x8057D8D8: beq         $t3, $zero, L_8057D8E4
    if (ctx->r11 == 0) {
        // 0x8057D8DC: srl         $s1, $s1, 14
        ctx->r17 = S32(U32(ctx->r17) >> 14);
            goto L_8057D8E4;
    }
    // 0x8057D8DC: srl         $s1, $s1, 14
    ctx->r17 = S32(U32(ctx->r17) >> 14);
    // 0x8057D8E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8057D8E4:
    // 0x8057D8E4: beq         $s1, $zero, L_8057D93C
    if (ctx->r17 == 0) {
        // 0x8057D8E8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8057D93C;
    }
    // 0x8057D8E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8057D8EC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8057D8F0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8057D8F4: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8057D8F8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8057D8FC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8057D900: lui         $s4, 0x41F9
    ctx->r20 = S32(0X41F9 << 16);
L_8057D904:
    // 0x8057D904: addiu       $t4, $s0, 0x200
    ctx->r12 = ADD32(ctx->r16, 0X200);
    // 0x8057D908: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8057D90C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8057D910: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8057D914: jal         0x8004613C
    // 0x8057D918: or          $a0, $t4, $s4
    ctx->r4 = ctx->r12 | ctx->r20;
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x8057D918: or          $a0, $t4, $s4
    ctx->r4 = ctx->r12 | ctx->r20;
    after_3:
    // 0x8057D91C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8057D920: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8057D924: jal         0x80047F9C
    // 0x8057D928: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x8057D928: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8057D92C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8057D930: sb          $s5, 0x17C($s2)
    MEM_B(0X17C, ctx->r18) = ctx->r21;
    // 0x8057D934: bne         $s1, $zero, L_8057D904
    if (ctx->r17 != 0) {
        // 0x8057D938: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8057D904;
    }
    // 0x8057D938: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8057D93C:
    // 0x8057D93C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8057D940: lui         $a0, 0x41FA
    ctx->r4 = S32(0X41FA << 16);
    // 0x8057D944: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8057D948: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8057D94C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8057D950: jal         0x8004613C
    // 0x8057D954: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x8057D954: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    after_5:
    // 0x8057D958: lw          $a0, 0x188($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X188);
    // 0x8057D95C: jal         0x80047F9C
    // 0x8057D960: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8057D960: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8057D964: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8057D968:
    // 0x8057D968: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8057D96C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8057D970: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8057D974: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8057D978: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8057D97C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8057D980: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8057D984: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8057D988: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8057D98C: jr          $ra
    // 0x8057D990: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8057D990: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80462D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462D6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80462D70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80462D74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80462D78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80462D7C: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x80462D80: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80462D84: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80462D88: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80462D8C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80462D90: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80462D94: jal         0x80062AEC
    // 0x80462D98: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x80462D98: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x80462D9C: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x80462DA0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80462DA4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80462DA8: bne         $t7, $at, L_80462F20
    if (ctx->r15 != ctx->r1) {
        // 0x80462DAC: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_80462F20;
    }
    // 0x80462DAC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80462DB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80462DB4: beq         $v0, $at, L_80462DD4
    if (ctx->r2 == ctx->r1) {
        // 0x80462DB8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80462DD4;
    }
    // 0x80462DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80462DBC: beq         $v0, $at, L_80462E2C
    if (ctx->r2 == ctx->r1) {
        // 0x80462DC0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80462E2C;
    }
    // 0x80462DC0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80462DC4: beql        $v0, $at, L_80462E88
    if (ctx->r2 == ctx->r1) {
        // 0x80462DC8: lbu         $t2, 0x18($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X18);
            goto L_80462E88;
    }
    goto skip_0;
    // 0x80462DC8: lbu         $t2, 0x18($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X18);
    skip_0:
    // 0x80462DCC: b           L_80462F24
    // 0x80462DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80462F24;
    // 0x80462DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80462DD4:
    // 0x80462DD4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A78) << 16);
    // 0x80462DD8: lwc1        $f4, 0x4008($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A78));
    // 0x80462DDC: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80462DE0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80462DE4: nop

    // 0x80462DE8: bc1fl       L_80462E18
    if (!c1cs) {
        // 0x80462DEC: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80462E18;
    }
    goto skip_1;
    // 0x80462DEC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x80462DF0: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80462DF4: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80462DF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80462DFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80462E00: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80462E04: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80462E08: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80462E0C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80462E10: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80462E14: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80462E18:
    // 0x80462E18: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80462E1C: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80462E20: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80462E24: b           L_80462F20
    // 0x80462E28: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_80462F20;
    // 0x80462E28: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_80462E2C:
    // 0x80462E2C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A7C) << 16);
    // 0x80462E30: lwc1        $f16, 0x400C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A7C));
    // 0x80462E34: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80462E38: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80462E3C: nop

    // 0x80462E40: bc1fl       L_80462E70
    if (!c1cs) {
        // 0x80462E44: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80462E70;
    }
    goto skip_2;
    // 0x80462E44: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_2:
    // 0x80462E48: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80462E4C: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80462E50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80462E54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80462E58: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80462E5C: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80462E60: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80462E64: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80462E68: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x80462E6C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80462E70:
    // 0x80462E70: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80462E74: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x80462E78: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80462E7C: b           L_80462F20
    // 0x80462E80: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
        goto L_80462F20;
    // 0x80462E80: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x80462E84: lbu         $t2, 0x18($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X18);
L_80462E88:
    // 0x80462E88: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80462E8C: beql        $t2, $at, L_80462F24
    if (ctx->r10 == ctx->r1) {
        // 0x80462E90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80462F24;
    }
    goto skip_3;
    // 0x80462E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80462E94: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x80462E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462E9C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80462EA0: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80462EA4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A80) << 16);
    // 0x80462EA8: andi        $t5, $t4, 0xF00
    ctx->r13 = ctx->r12 & 0XF00;
    // 0x80462EAC: beql        $t5, $zero, L_80462EC8
    if (ctx->r13 == 0) {
        // 0x80462EB0: lwc1        $f0, 0xC8($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80462EC8;
    }
    goto skip_4;
    // 0x80462EB0: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    skip_4:
    // 0x80462EB4: jal         0x8002F6E4
    // 0x80462EB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x80462EB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80462EBC: b           L_80462F24
    // 0x80462EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80462F24;
    // 0x80462EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80462EC4: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
L_80462EC8:
    // 0x80462EC8: lwc1        $f6, 0x4010($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A80));
    // 0x80462ECC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80462ED0: nop

    // 0x80462ED4: bc1fl       L_80462F14
    if (!c1cs) {
        // 0x80462ED8: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80462F14;
    }
    goto skip_5;
    // 0x80462ED8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_5:
    // 0x80462EDC: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80462EE0: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80462EE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80462EE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80462EEC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80462EF0: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80462EF4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A84) << 16);
    // 0x80462EF8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80462EFC: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80462F00: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x80462F04: lwc1        $f8, 0x4014($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A84));
    // 0x80462F08: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80462F0C: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x80462F10: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80462F14:
    // 0x80462F14: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x80462F18: ori         $t7, $t6, 0x3000
    ctx->r15 = ctx->r14 | 0X3000;
    // 0x80462F1C: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
L_80462F20:
    // 0x80462F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80462F24:
    // 0x80462F24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80462F28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80462F2C: jr          $ra
    // 0x80462F30: nop

    return;
    // 0x80462F30: nop

;}
RECOMP_FUNC void func_80043D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043D34: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80043D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80043D3C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80043D40: beq         $t7, $zero, L_80043D50
    if (ctx->r15 == 0) {
        // 0x80043D44: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80043D50;
    }
    // 0x80043D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043D48: b           L_80043DC4
    // 0x80043D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043DC4;
    // 0x80043D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043D50:
    // 0x80043D50: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80043D54: lw          $t8, -0x77F0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X77F0);
    // 0x80043D58: bnel        $a0, $t8, L_80043D6C
    if (ctx->r4 != ctx->r24) {
        // 0x80043D5C: lh          $t9, 0x17E($a1)
        ctx->r25 = MEM_H(ctx->r5, 0X17E);
            goto L_80043D6C;
    }
    goto skip_0;
    // 0x80043D5C: lh          $t9, 0x17E($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X17E);
    skip_0:
    // 0x80043D60: b           L_80043DC4
    // 0x80043D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043DC4;
    // 0x80043D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80043D68: lh          $t9, 0x17E($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X17E);
L_80043D6C:
    // 0x80043D6C: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80043D70: beq         $t9, $at, L_80043D80
    if (ctx->r25 == ctx->r1) {
        // 0x80043D74: nop
    
            goto L_80043D80;
    }
    // 0x80043D74: nop

    // 0x80043D78: b           L_80043DC4
    // 0x80043D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043DC4;
    // 0x80043D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043D80:
    // 0x80043D80: jal         0x80057C08
    // 0x80043D84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80057C08(rdram, ctx);
        goto after_0;
    // 0x80043D84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80043D88: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80043D8C: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80043D90: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80043D94: bne         $v0, $at, L_80043DB4
    if (ctx->r2 != ctx->r1) {
        // 0x80043D98: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80043DB4;
    }
    // 0x80043D98: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80043D9C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043DA0: addiu       $a0, $a0, 0x3B0
    ctx->r4 = ADD32(ctx->r4, 0X3B0);
    // 0x80043DA4: jal         0x80071380
    // 0x80043DA8: addiu       $a1, $zero, 0x2AB
    ctx->r5 = ADD32(0, 0X2AB);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80043DA8: addiu       $a1, $zero, 0x2AB
    ctx->r5 = ADD32(0, 0X2AB);
    after_1:
    // 0x80043DAC: b           L_80043DC4
    // 0x80043DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043DC4;
    // 0x80043DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043DB4:
    // 0x80043DB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80043DB8: sh          $v1, 0x17E($a1)
    MEM_H(0X17E, ctx->r5) = ctx->r3;
    // 0x80043DBC: sb          $t0, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r8;
    // 0x80043DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80043DC4:
    // 0x80043DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80043DCC: jr          $ra
    // 0x80043DD0: nop

    return;
    // 0x80043DD0: nop

;}
RECOMP_FUNC void func_80466A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80466A0C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466A10: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80466A14: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80466A18: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80466A1C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80466A20: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80466A24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80466A28: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80466A2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466A30: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80466A34: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x80466A38: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80466A3C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80466A40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80466A44: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80466A48: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466A4C: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x80466A50: ori         $t3, $zero, 0xAC80
    ctx->r11 = 0 | 0XAC80;
    // 0x80466A54: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80466A58: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80466A5C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80466A60: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80466A64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466A68: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x80466A6C: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x80466A70: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80466A74: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80466A78: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x80466A7C: ori         $a3, $a3, 0x4340
    ctx->r7 = ctx->r7 | 0X4340;
    // 0x80466A80: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80466A84: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80466A88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466A8C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80466A90: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80466A94: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80466A98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80466A9C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80466AA0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80466AA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466AA8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80466AAC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80466AB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80466AB4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80466AB8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80466ABC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80466AC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466AC4: lui         $t2, 0xFC11
    ctx->r10 = S32(0XFC11 << 16);
    // 0x80466AC8: lui         $t3, 0xFF2F
    ctx->r11 = S32(0XFF2F << 16);
    // 0x80466ACC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80466AD0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80466AD4: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x80466AD8: ori         $t2, $t2, 0x9623
    ctx->r10 = ctx->r10 | 0X9623;
    // 0x80466ADC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80466AE0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80466AE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466AE8: addiu       $t6, $zero, 0x204
    ctx->r14 = ADD32(0, 0X204);
    // 0x80466AEC: lui         $t5, 0xB700
    ctx->r13 = S32(0XB700 << 16);
    // 0x80466AF0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80466AF4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80466AF8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80466AFC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80466B00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80466B04: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80466B08: lui         $t8, 0xBB00
    ctx->r24 = S32(0XBB00 << 16);
    // 0x80466B0C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80466B10: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80466B14: ori         $t8, $t8, 0x1
    ctx->r24 = ctx->r24 | 0X1;
    // 0x80466B18: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x80466B1C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80466B20: jr          $ra
    // 0x80466B24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x80466B24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_805D1D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1D0C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805D1D10: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x805D1D14: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805D1D18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805D1D1C: nop

    // 0x805D1D20: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x805D1D24: nop

    // 0x805D1D28: bc1fl       L_805D1D58
    if (!c1cs) {
        // 0x805D1D2C: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_805D1D58;
    }
    goto skip_0;
    // 0x805D1D2C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x805D1D30: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805D1D34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805D1D38: nop

    // 0x805D1D3C: bc1f        L_805D1D74
    if (!c1cs) {
        // 0x805D1D40: nop
    
            goto L_805D1D74;
    }
    // 0x805D1D40: nop

    // 0x805D1D44: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x805D1D48: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x805D1D4C: jr          $ra
    // 0x805D1D50: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x805D1D50: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x805D1D54: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_805D1D58:
    // 0x805D1D58: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x805D1D5C: nop

    // 0x805D1D60: bc1f        L_805D1D74
    if (!c1cs) {
        // 0x805D1D64: nop
    
            goto L_805D1D74;
    }
    // 0x805D1D64: nop

    // 0x805D1D68: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x805D1D6C: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x805D1D70: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_805D1D74:
    // 0x805D1D74: jr          $ra
    // 0x805D1D78: nop

    return;
    // 0x805D1D78: nop

;}
RECOMP_FUNC void func_8000C21C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C21C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000C220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C224: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8000C228: sw          $t6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r14;
    // 0x8000C22C: sw          $a1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r5;
    // 0x8000C230: lw          $t7, 0x50($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X50);
    // 0x8000C234: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000C238: lbu         $t8, 0x5($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5);
    // 0x8000C23C: sb          $t8, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r24;
    // 0x8000C240: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x8000C244: lw          $t5, 0x50($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X50);
    // 0x8000C248: sw          $a0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r4;
    // 0x8000C24C: ori         $t3, $t0, 0x1
    ctx->r11 = ctx->r8 | 0X1;
    // 0x8000C250: sb          $t3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r11;
    // 0x8000C254: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x8000C258: sb          $t4, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r12;
    // 0x8000C25C: sw          $a0, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r4;
    // 0x8000C260: lw          $t6, 0x50($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X50);
    // 0x8000C264: sw          $a1, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r5;
    // 0x8000C268: swc1        $f4, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f4.u32l;
    // 0x8000C26C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000C270: jal         0x8000B214
    // 0x8000C274: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_8000B214(rdram, ctx);
        goto after_0;
    // 0x8000C274: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000C278: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C27C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000C280: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000C284: lbu         $a2, 0x2($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X2);
    // 0x8000C288: addiu       $v0, $a0, 0xB0
    ctx->r2 = ADD32(ctx->r4, 0XB0);
    // 0x8000C28C: bnel        $a2, $at, L_8000C2A0
    if (ctx->r6 != ctx->r1) {
        // 0x8000C290: lw          $t8, 0x4C($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X4C);
            goto L_8000C2A0;
    }
    goto skip_0;
    // 0x8000C290: lw          $t8, 0x4C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4C);
    skip_0:
    // 0x8000C294: lw          $t7, 0x50($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X50);
    // 0x8000C298: lh          $a2, 0x24($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X24);
    // 0x8000C29C: lw          $t8, 0x4C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4C);
L_8000C2A0:
    // 0x8000C2A0: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x8000C2A4: bne         $at, $zero, L_8000C2CC
    if (ctx->r1 != 0) {
        // 0x8000C2A8: sw          $t8, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r24;
            goto L_8000C2CC;
    }
    // 0x8000C2A8: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x8000C2AC: slti        $at, $a2, 0xC0
    ctx->r1 = SIGNED(ctx->r6) < 0XC0 ? 1 : 0;
    // 0x8000C2B0: beql        $at, $zero, L_8000C2D0
    if (ctx->r1 == 0) {
        // 0x8000C2B4: lbu         $t2, 0x1($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X1);
            goto L_8000C2D0;
    }
    goto skip_1;
    // 0x8000C2B4: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    skip_1:
    // 0x8000C2B8: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C2BC: andi        $t0, $t9, 0xFFF9
    ctx->r8 = ctx->r25 & 0XFFF9;
    // 0x8000C2C0: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x8000C2C4: b           L_8000C2D8
    // 0x8000C2C8: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
        goto L_8000C2D8;
    // 0x8000C2C8: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
L_8000C2CC:
    // 0x8000C2CC: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
L_8000C2D0:
    // 0x8000C2D0: andi        $t3, $t2, 0xFFF9
    ctx->r11 = ctx->r10 & 0XFFF9;
    // 0x8000C2D4: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
L_8000C2D8:
    // 0x8000C2D8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8000C2DC: sll         $t5, $t4, 13
    ctx->r13 = S32(ctx->r12 << 13);
    // 0x8000C2E0: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x8000C2E4: beql        $t6, $zero, L_8000C30C
    if (ctx->r14 == 0) {
        // 0x8000C2E8: lw          $t7, 0x50($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X50);
            goto L_8000C30C;
    }
    goto skip_2;
    // 0x8000C2E8: lw          $t7, 0x50($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X50);
    skip_2:
    // 0x8000C2EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000C2F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000C2F4: jal         0x8000BC34
    // 0x8000C2F8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_8000BC34(rdram, ctx);
        goto after_1;
    // 0x8000C2F8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8000C2FC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C300: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000C304: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C308: lw          $t7, 0x50($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X50);
L_8000C30C:
    // 0x8000C30C: lbu         $t8, 0x7($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X7);
    // 0x8000C310: sb          $t8, 0x33($a0)
    MEM_B(0X33, ctx->r4) = ctx->r24;
    // 0x8000C314: lw          $t9, 0x50($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X50);
    // 0x8000C318: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C31C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000C320: andi        $t6, $t5, 0xFFFD
    ctx->r14 = ctx->r13 & 0XFFFD;
    // 0x8000C324: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C328: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x8000C32C: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x8000C330: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8000C334: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x8000C338: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8000C33C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8000C340: lw          $t8, 0x50($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X50);
    // 0x8000C344: andi        $t4, $t5, 0xFF1F
    ctx->r12 = ctx->r13 & 0XFF1F;
    // 0x8000C348: lbu         $t9, 0x8($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X8);
    // 0x8000C34C: andi        $t1, $t9, 0x3
    ctx->r9 = ctx->r25 & 0X3;
    // 0x8000C350: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x8000C354: or          $t6, $t3, $t4
    ctx->r14 = ctx->r11 | ctx->r12;
    // 0x8000C358: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x8000C35C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C360: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000C364: jr          $ra
    // 0x8000C368: nop

    return;
    // 0x8000C368: nop

;}
RECOMP_FUNC void func_80058924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058928: bne         $a0, $zero, L_80058940
    if (ctx->r4 != 0) {
        // 0x8005892C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80058940;
    }
    // 0x8005892C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058930: jal         0x800582E4
    // 0x80058934: nop

    func_800582E4(rdram, ctx);
        goto after_0;
    // 0x80058934: nop

    after_0:
    // 0x80058938: b           L_8005894C
    // 0x8005893C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005894C;
    // 0x8005893C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058940:
    // 0x80058940: jal         0x800587A0
    // 0x80058944: nop

    func_800587A0(rdram, ctx);
        goto after_1;
    // 0x80058944: nop

    after_1:
    // 0x80058948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005894C:
    // 0x8005894C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058950: jr          $ra
    // 0x80058954: nop

    return;
    // 0x80058954: nop

;}
RECOMP_FUNC void func_8006B6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8006B6E8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8006B6EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006B6F0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8006B6F4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B6F8: blez        $a3, L_8006B7C0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8006B6FC: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8006B7C0;
    }
    // 0x8006B6FC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006B700: bgez        $a2, L_8006B70C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006B704: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006B70C;
    }
    // 0x8006B704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B708: addiu       $v0, $zero, 0x320
    ctx->r2 = ADD32(0, 0X320);
L_8006B70C:
    // 0x8006B70C: addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // 0x8006B710: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8006B714: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8006B718: bgez        $v1, L_8006B734
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006B71C: addu        $t0, $v1, $a3
        ctx->r8 = ADD32(ctx->r3, ctx->r7);
            goto L_8006B734;
    }
    // 0x8006B71C: addu        $t0, $v1, $a3
    ctx->r8 = ADD32(ctx->r3, ctx->r7);
    // 0x8006B720: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8006B724: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8006B728: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B72C: jr          $ra
    // 0x8006B730: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x8006B730: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
L_8006B734:
    // 0x8006B734: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006B738: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8006B73C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8006B740: sra         $t1, $t0, 4
    ctx->r9 = S32(SIGNED(ctx->r8) >> 4);
    // 0x8006B744: sra         $a2, $v1, 4
    ctx->r6 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8006B748: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8006B74C: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x8006B750: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8006B754: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006B758: beq         $t1, $a2, L_8006B7C0
    if (ctx->r9 == ctx->r6) {
        // 0x8006B75C: subu        $t7, $t1, $a2
        ctx->r15 = SUB32(ctx->r9, ctx->r6);
            goto L_8006B7C0;
    }
    // 0x8006B75C: subu        $t7, $t1, $a2
    ctx->r15 = SUB32(ctx->r9, ctx->r6);
    // 0x8006B760: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B764: bne         $t7, $at, L_8006B794
    if (ctx->r15 != ctx->r1) {
        // 0x8006B768: addiu       $t6, $a2, 0x1
        ctx->r14 = ADD32(ctx->r6, 0X1);
            goto L_8006B794;
    }
    // 0x8006B768: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x8006B76C: andi        $t8, $t0, 0xF
    ctx->r24 = ctx->r8 & 0XF;
    // 0x8006B770: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006B774: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x8006B778: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x8006B77C: subu        $t2, $t0, $v0
    ctx->r10 = SUB32(ctx->r8, ctx->r2);
    // 0x8006B780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B784: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x8006B788: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006B78C: jr          $ra
    // 0x8006B790: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    return;
    // 0x8006B790: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
L_8006B794:
    // 0x8006B794: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8006B798: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8006B79C: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8006B7A0: subu        $t9, $t0, $t8
    ctx->r25 = SUB32(ctx->r8, ctx->r24);
    // 0x8006B7A4: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8006B7A8: sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
    // 0x8006B7AC: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x8006B7B0: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x8006B7B4: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8006B7B8: jr          $ra
    // 0x8006B7BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006B7BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006B7C0:
    // 0x8006B7C0: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8006B7C4: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x8006B7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B7CC: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x8006B7D0: jr          $ra
    // 0x8006B7D4: nop

    return;
    // 0x8006B7D4: nop

;}
RECOMP_FUNC void func_80673D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673D34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80673D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80673D40: jal         0x80045A34
    // 0x80673D44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80673D44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80673D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80673D4C: bne         $v0, $zero, L_80673D5C
    if (ctx->r2 != 0) {
        // 0x80673D50: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80673D5C;
    }
    // 0x80673D50: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80673D54: b           L_80673D68
    // 0x80673D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80673D68;
    // 0x80673D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80673D5C:
    // 0x80673D5C: jal         0x80673D24
    // 0x80673D60: nop

    func_80673D24(rdram, ctx);
        goto after_1;
    // 0x80673D60: nop

    after_1:
    // 0x80673D64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80673D68:
    // 0x80673D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80673D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80673D70: jr          $ra
    // 0x80673D74: nop

    return;
    // 0x80673D74: nop

;}
RECOMP_FUNC void func_8064AD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AD74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AD78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AD7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064AD80: jal         0x80045A34
    // 0x8064AD84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8064AD84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8064AD88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064AD8C: bne         $v0, $zero, L_8064AD9C
    if (ctx->r2 != 0) {
        // 0x8064AD90: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8064AD9C;
    }
    // 0x8064AD90: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8064AD94: b           L_8064ADA8
    // 0x8064AD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8064ADA8;
    // 0x8064AD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064AD9C:
    // 0x8064AD9C: jal         0x8064AD64
    // 0x8064ADA0: nop

    func_8064AD64(rdram, ctx);
        goto after_1;
    // 0x8064ADA0: nop

    after_1:
    // 0x8064ADA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064ADA8:
    // 0x8064ADA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064ADAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064ADB0: jr          $ra
    // 0x8064ADB4: nop

    return;
    // 0x8064ADB4: nop

;}
RECOMP_FUNC void func_80473980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80473984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80473988: jal         0x80473904
    // 0x8047398C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80473904(rdram, ctx);
        goto after_0;
    // 0x8047398C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80473990: jal         0x804736C0
    // 0x80473994: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804736C0(rdram, ctx);
        goto after_1;
    // 0x80473994: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80473998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8047399C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804739A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x804739A4: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x804739A8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804739AC: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x804739B0: bne         $at, $zero, L_804739C8
    if (ctx->r1 != 0) {
        // 0x804739B4: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_804739C8;
    }
    // 0x804739B4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x804739B8: jal         0x80473DF8
    // 0x804739BC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_80473DF8(rdram, ctx);
        goto after_2;
    // 0x804739BC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_2:
    // 0x804739C0: b           L_804739F0
    // 0x804739C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804739F0;
    // 0x804739C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804739C8:
    // 0x804739C8: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x804739CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804739D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804739D4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x804739D8: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x804739DC: beql        $t1, $zero, L_804739F0
    if (ctx->r9 == 0) {
        // 0x804739E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804739F0;
    }
    goto skip_0;
    // 0x804739E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804739E4: jal         0x80473DF8
    // 0x804739E8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_80473DF8(rdram, ctx);
        goto after_3;
    // 0x804739E8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_3:
    // 0x804739EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804739F0:
    // 0x804739F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804739F4: jr          $ra
    // 0x804739F8: nop

    return;
    // 0x804739F8: nop

;}
RECOMP_FUNC void func_80452690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452698: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8045269C: jal         0x804525A8
    // 0x804526A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804525A8(rdram, ctx);
        goto after_0;
    // 0x804526A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x804526A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804526A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804526AC: jr          $ra
    // 0x804526B0: nop

    return;
    // 0x804526B0: nop

;}
RECOMP_FUNC void func_80460830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460838: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8046083C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80460840: beq         $t6, $zero, L_8046087C
    if (ctx->r14 == 0) {
        // 0x80460844: nop
    
            goto L_8046087C;
    }
    // 0x80460844: nop

    // 0x80460848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046084C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80460850: jalr        $t9
    // 0x80460854: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80460854: nop

    after_0:
    // 0x80460858: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046085C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80460860: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80460864: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80460868: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8046086C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80460870: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80460874: b           L_8046087C
    // 0x80460878: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8046087C;
    // 0x80460878: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8046087C:
    // 0x8046087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460884: jr          $ra
    // 0x80460888: nop

    return;
    // 0x80460888: nop

;}
RECOMP_FUNC void func_8044B33C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B33C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044B340: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13524) << 16);
    // 0x8044B344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B348: addiu       $t6, $t6, 0x7904
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13524));
    // 0x8044B34C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044B350: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044B354: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044B358: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044B35C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044B360: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B364: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044B368: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044B36C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044B370: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044B374: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044B378: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044B37C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B380: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044B384: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044B388: jal         0x80050A50
    // 0x8044B38C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044B38C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044B390: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044B394: jalr        $v0
    // 0x8044B398: sw          $v0, 0x6A74($v1)
    MEM_W(0X6A74, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044B398: sw          $v0, 0x6A74($v1)
    MEM_W(0X6A74, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044B39C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B3A0: sw          $v0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r2;
    // 0x8044B3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B3A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044B3AC: jr          $ra
    // 0x8044B3B0: nop

    return;
    // 0x8044B3B0: nop

;}
RECOMP_FUNC void func_80584374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584374: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80584378: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A398) << 16);
    // 0x8058437C: lwc1        $f0, -0x1FA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A398));
    // 0x80584380: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A39C) << 16);
    // 0x80584384: lwc1        $f4, -0x1FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A39C));
    // 0x80584388: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8058438C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80584390: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80584394: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80584398: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8058439C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805843A0: addiu       $t6, $zero, 0x1C98
    ctx->r14 = ADD32(0, 0X1C98);
    // 0x805843A4: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x805843A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x805843AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805843B0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805843B4: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805843B8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x805843BC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x805843C0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x805843C4: jal         0x80583D88
    // 0x805843C8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_80583D88(rdram, ctx);
        goto after_0;
    // 0x805843C8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x805843CC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x805843D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805843D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805843D8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805843DC: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x805843E0: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805843E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x805843E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805843EC: jr          $ra
    // 0x805843F0: nop

    return;
    // 0x805843F0: nop

;}
RECOMP_FUNC void func_804C3330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3338: jal         0x804C3310
    // 0x804C333C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C3310(rdram, ctx);
        goto after_0;
    // 0x804C333C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C3340: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C3344: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(206, 0X710) << 16);
    // 0x804C3348: addiu       $t6, $t6, 0x3190
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(206, 0X710));
    // 0x804C334C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804C3350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C3354: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804C3358: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x804C335C: jal         0x804C3618
    // 0x804C3360: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_804C3618(rdram, ctx);
        goto after_1;
    // 0x804C3360: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x804C3364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C336C: jr          $ra
    // 0x804C3370: nop

    return;
    // 0x804C3370: nop

;}
RECOMP_FUNC void func_806FB050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FB050: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806FB054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FB058: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x806FB05C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x806FB060: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x806FB064: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x806FB068: jal         0x80066DE4
    // 0x806FB06C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806FB06C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FB070: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x806FB074: jal         0x80066E88
    // 0x806FB078: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806FB078: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x806FB07C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x806FB080: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806FB084: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x806FB088: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806FB08C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x806FB090: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806FB094: mul.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x806FB098: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x806FB09C: addiu       $v1, $a0, 0x10
    ctx->r3 = ADD32(ctx->r4, 0X10);
    // 0x806FB0A0: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x806FB0A4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806FB0A8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806FB0AC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x806FB0B0: nop

    // 0x806FB0B4: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x806FB0B8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x806FB0BC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x806FB0C0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x806FB0C4: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806FB0C8: nop

    // 0x806FB0CC: mul.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x806FB0D0: add.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x806FB0D4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806FB0D8: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x806FB0DC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806FB0E0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x806FB0E4: nop

    // 0x806FB0E8: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x806FB0EC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x806FB0F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806FB0F4: sub.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x806FB0F8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806FB0FC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x806FB100: nop

    // 0x806FB104: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x806FB108: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x806FB10C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806FB110: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806FB114: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x806FB118: nop

    // 0x806FB11C: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x806FB120: lh          $t4, 0x4A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X4A);
    // 0x806FB124: sh          $t4, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r12;
    // 0x806FB128: lh          $t5, 0x8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X8);
    // 0x806FB12C: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
    // 0x806FB130: lh          $t6, 0x52($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X52);
    // 0x806FB134: sh          $t6, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r14;
    // 0x806FB138: lh          $t7, 0x4E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4E);
    // 0x806FB13C: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x806FB140: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x806FB144: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x806FB148: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x806FB14C: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x806FB150: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x806FB154: sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // 0x806FB158: sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
    // 0x806FB15C: sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    // 0x806FB160: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    // 0x806FB164: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x806FB168: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x806FB16C: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x806FB170: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x806FB174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FB178: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806FB17C: jr          $ra
    // 0x806FB180: nop

    return;
    // 0x806FB180: nop

;}
RECOMP_FUNC void func_806EA92C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EA92C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EA930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EA934: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806EA938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EA93C: beq         $t6, $zero, L_806EA978
    if (ctx->r14 == 0) {
        // 0x806EA940: nop
    
            goto L_806EA978;
    }
    // 0x806EA940: nop

    // 0x806EA944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EA948: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806EA94C: jalr        $t9
    // 0x806EA950: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806EA950: nop

    after_0:
    // 0x806EA954: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EA958: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806EA95C: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806EA960: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806EA964: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806EA968: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806EA96C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806EA970: b           L_806EA978
    // 0x806EA974: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806EA978;
    // 0x806EA974: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806EA978:
    // 0x806EA978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EA97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EA980: jr          $ra
    // 0x806EA984: nop

    return;
    // 0x806EA984: nop

;}
RECOMP_FUNC void func_80704A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80704A04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80704A08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80704A0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80704A10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80704A14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80704A18: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80704A1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80704A20: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80704A24: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80704A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80704A2C: bc1fl       L_80704AEC
    if (!c1cs) {
        // 0x80704A30: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_80704AEC;
    }
    goto skip_0;
    // 0x80704A30: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x80704A34: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x80704A38: beql        $t6, $zero, L_80704AEC
    if (ctx->r14 == 0) {
        // 0x80704A3C: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_80704AEC;
    }
    goto skip_1;
    // 0x80704A3C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x80704A40: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80704A44: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80704A48: jal         0x80067BBC
    // 0x80704A4C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80704A4C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80704A50: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x80704A54: jal         0x80067818
    // 0x80704A58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80704A58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80704A5C: jal         0x807041F8
    // 0x80704A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807041F8(rdram, ctx);
        goto after_2;
    // 0x80704A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80704A64: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80704A68: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80704A6C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3898) << 16);
    // 0x80704A70: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    // 0x80704A74: lwc1        $f8, 0x6D08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3898));
    // 0x80704A78: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80704A7C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X389C) << 16);
    // 0x80704A80: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x80704A84: lwc1        $f10, 0x6D0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X389C));
    // 0x80704A88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80704A8C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80704A90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80704A94: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    // 0x80704A98: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80704A9C: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80704AA0: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80704AA4: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
    // 0x80704AA8: addiu       $at, $zero, 0x461F
    ctx->r1 = ADD32(0, 0X461F);
    // 0x80704AAC: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x80704AB0: bne         $t8, $at, L_80704ACC
    if (ctx->r24 != ctx->r1) {
        // 0x80704AB4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80704ACC;
    }
    // 0x80704AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80704AB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80704ABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80704AC0: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80704AC4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80704AC8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
L_80704ACC:
    // 0x80704ACC: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x80704AD0: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x80704AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80704AD8: jal         0x80705A5C
    // 0x80704ADC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80705A5C(rdram, ctx);
        goto after_3;
    // 0x80704ADC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
    // 0x80704AE0: b           L_80704B14
    // 0x80704AE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80704B14;
    // 0x80704AE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80704AE8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_80704AEC:
    // 0x80704AEC: jal         0x80048F84
    // 0x80704AF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x80704AF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_4:
    // 0x80704AF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80704AF8: jal         0x80048F84
    // 0x80704AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x80704AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80704B00: jal         0x8070384C
    // 0x80704B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070384C(rdram, ctx);
        goto after_6;
    // 0x80704B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80704B08: jal         0x80703F10
    // 0x80704B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80703F10(rdram, ctx);
        goto after_7;
    // 0x80704B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80704B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80704B14:
    // 0x80704B14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80704B18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80704B1C: jr          $ra
    // 0x80704B20: nop

    return;
    // 0x80704B20: nop

;}
RECOMP_FUNC void func_800216C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800216C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800216C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800216CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800216D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800216D4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800216D8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800216DC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800216E0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800216E4: addiu       $t8, $t7, 0xD8
    ctx->r24 = ADD32(ctx->r15, 0XD8);
    // 0x800216E8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800216EC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800216F0: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x800216F4: addiu       $t1, $t0, 0xF0
    ctx->r9 = ADD32(ctx->r8, 0XF0);
    // 0x800216F8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800216FC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80021700: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x80021704: addiu       $t4, $t3, 0x108
    ctx->r12 = ADD32(ctx->r11, 0X108);
    // 0x80021708: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8002170C: lw          $t5, 0x138($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X138);
    // 0x80021710: beq         $t5, $zero, L_80021774
    if (ctx->r13 == 0) {
        // 0x80021714: nop
    
            goto L_80021774;
    }
    // 0x80021714: nop

    // 0x80021718: jal         0x80021444
    // 0x8002171C: nop

    func_80021444(rdram, ctx);
        goto after_0;
    // 0x8002171C: nop

    after_0:
    // 0x80021720: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80021724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021728: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002172C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80021730: beq         $t7, $zero, L_8002174C
    if (ctx->r15 == 0) {
        // 0x80021734: addiu       $a2, $sp, 0x24
        ctx->r6 = ADD32(ctx->r29, 0X24);
            goto L_8002174C;
    }
    // 0x80021734: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80021738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002173C: jal         0x80020E4C
    // 0x80021740: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80020E4C(rdram, ctx);
        goto after_1;
    // 0x80021740: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80021744: b           L_8002175C
    // 0x80021748: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
        goto L_8002175C;
    // 0x80021748: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
L_8002174C:
    // 0x8002174C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80021750: jal         0x80020EB4
    // 0x80021754: addiu       $a3, $a3, -0x6534
    ctx->r7 = ADD32(ctx->r7, -0X6534);
    func_80020EB4(rdram, ctx);
        goto after_2;
    // 0x80021754: addiu       $a3, $a3, -0x6534
    ctx->r7 = ADD32(ctx->r7, -0X6534);
    after_2:
    // 0x80021758: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
L_8002175C:
    // 0x8002175C: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80021760: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80021764: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80021768: or          $t0, $v0, $t9
    ctx->r8 = ctx->r2 | ctx->r25;
    // 0x8002176C: b           L_800217CC
    // 0x80021770: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
        goto L_800217CC;
    // 0x80021770: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
L_80021774:
    // 0x80021774: jal         0x80021584
    // 0x80021778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80021584(rdram, ctx);
        goto after_3;
    // 0x80021778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8002177C: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x80021780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021784: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80021788: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x8002178C: beq         $t2, $zero, L_800217A8
    if (ctx->r10 == 0) {
        // 0x80021790: addiu       $a2, $sp, 0x24
        ctx->r6 = ADD32(ctx->r29, 0X24);
            goto L_800217A8;
    }
    // 0x80021790: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80021794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021798: jal         0x80020F24
    // 0x8002179C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80020F24(rdram, ctx);
        goto after_4;
    // 0x8002179C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x800217A0: b           L_800217B8
    // 0x800217A4: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
        goto L_800217B8;
    // 0x800217A4: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
L_800217A8:
    // 0x800217A8: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x800217AC: jal         0x80020F8C
    // 0x800217B0: addiu       $a3, $a3, -0x6534
    ctx->r7 = ADD32(ctx->r7, -0X6534);
    func_80020F8C(rdram, ctx);
        goto after_5;
    // 0x800217B0: addiu       $a3, $a3, -0x6534
    ctx->r7 = ADD32(ctx->r7, -0X6534);
    after_5:
    // 0x800217B4: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
L_800217B8:
    // 0x800217B8: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x800217BC: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x800217C0: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800217C4: or          $t5, $v0, $t4
    ctx->r13 = ctx->r2 | ctx->r12;
    // 0x800217C8: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
L_800217CC:
    // 0x800217CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800217D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800217D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800217D8: jr          $ra
    // 0x800217DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800217DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80678CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678CF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80678CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80678CFC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x80678D00: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80678D04: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x80678D08: bne         $at, $zero, L_80678D68
    if (ctx->r1 != 0) {
        // 0x80678D0C: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_80678D68;
    }
    // 0x80678D0C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x80678D10: jal         0x800653D8
    // 0x80678D14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80678D14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80678D18: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x80678D1C: beq         $v1, $zero, L_80678D4C
    if (ctx->r3 == 0) {
        // 0x80678D20: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80678D4C;
    }
    // 0x80678D20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80678D24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80678D28: beq         $v1, $at, L_80678D58
    if (ctx->r3 == ctx->r1) {
        // 0x80678D2C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80678D58;
    }
    // 0x80678D2C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80678D30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80678D34: beq         $v1, $at, L_80678D58
    if (ctx->r3 == ctx->r1) {
        // 0x80678D38: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80678D58;
    }
    // 0x80678D38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80678D3C: beq         $v1, $at, L_80678D60
    if (ctx->r3 == ctx->r1) {
        // 0x80678D40: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80678D60;
    }
    // 0x80678D40: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80678D44: b           L_80678D68
    // 0x80678D48: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
        goto L_80678D68;
    // 0x80678D48: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
L_80678D4C:
    // 0x80678D4C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80678D50: b           L_80678D64
    // 0x80678D54: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
        goto L_80678D64;
    // 0x80678D54: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
L_80678D58:
    // 0x80678D58: b           L_80678D64
    // 0x80678D5C: sb          $t0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r8;
        goto L_80678D64;
    // 0x80678D5C: sb          $t0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r8;
L_80678D60:
    // 0x80678D60: sb          $t1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r9;
L_80678D64:
    // 0x80678D64: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
L_80678D68:
    // 0x80678D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80678D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80678D70: jr          $ra
    // 0x80678D74: nop

    return;
    // 0x80678D74: nop

;}
RECOMP_FUNC void func_805D1F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1F64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805D1F68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805D1F6C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x805D1F70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805D1F74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805D1F78: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x805D1F7C: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(471, 0X2A30) << 16);
    // 0x805D1F80: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x805D1F84: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x805D1F88: addiu       $a0, $a0, 0x4460
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(471, 0X2A30));
    // 0x805D1F8C: lui         $a1, 0x4525
    ctx->r5 = S32(0X4525 << 16);
    // 0x805D1F90: jal         0x80046804
    // 0x805D1F94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x805D1F94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x805D1F98: bne         $v0, $zero, L_805D1FA8
    if (ctx->r2 != 0) {
        // 0x805D1F9C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805D1FA8;
    }
    // 0x805D1F9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805D1FA0: b           L_805D1FF0
    // 0x805D1FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805D1FF0;
    // 0x805D1FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D1FA8:
    // 0x805D1FA8: jal         0x80047090
    // 0x805D1FAC: addiu       $a0, $zero, 0x4525
    ctx->r4 = ADD32(0, 0X4525);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x805D1FAC: addiu       $a0, $zero, 0x4525
    ctx->r4 = ADD32(0, 0X4525);
    after_1:
    // 0x805D1FB0: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x805D1FB4: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x805D1FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1FBC: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x805D1FC0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x805D1FC4: jal         0x80044194
    // 0x805D1FC8: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805D1FC8: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    after_2:
    // 0x805D1FCC: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x805D1FD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805D1FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1FD8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x805D1FDC: jal         0x80052BA4
    // 0x805D1FE0: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    func_80052BA4(rdram, ctx);
        goto after_3;
    // 0x805D1FE0: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    after_3:
    // 0x805D1FE4: jal         0x8005FDC4
    // 0x805D1FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x805D1FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805D1FEC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_805D1FF0:
    // 0x805D1FF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805D1FF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805D1FF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805D1FFC: jr          $ra
    // 0x805D2000: nop

    return;
    // 0x805D2000: nop

;}
RECOMP_FUNC void func_80442380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442380: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80442384: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(95, 0X33D0) << 16);
    // 0x80442388: addiu       $t6, $t6, 0x22D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(95, 0X33D0));
    // 0x8044238C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80442390: jr          $ra
    // 0x80442394: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80442394: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_805217E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805217E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805217E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805217E8: jal         0x80521818
    // 0x805217EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80521818(rdram, ctx);
        goto after_0;
    // 0x805217EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805217F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805217F4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x805217F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805217FC: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80521800: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80521804: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x80521808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052180C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80521810: jr          $ra
    // 0x80521814: nop

    return;
    // 0x80521814: nop

;}
RECOMP_FUNC void func_805ADED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADED4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADED8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADEDC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADEE0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADEE4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADEE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADEEC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADEF0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADEF4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADEF8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADEFC: jr          $ra
    // 0x805ADF00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADF00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807C5274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C5274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C5278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807C527C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807C5280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807C5284: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807C5288: jal         0x80045A34
    // 0x807C528C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807C528C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_0:
    // 0x807C5290: bne         $v0, $zero, L_807C52A8
    if (ctx->r2 != 0) {
        // 0x807C5294: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_807C52A8;
    }
    // 0x807C5294: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x807C5298: jal         0x800445A4
    // 0x807C529C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x807C529C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807C52A0: b           L_807C5454
    // 0x807C52A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807C5454;
    // 0x807C52A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807C52A8:
    // 0x807C52A8: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x807C52AC: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(910, 0X1304) << 16);
    // 0x807C52B0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807C52B4: addiu       $t6, $t6, 0x5CC4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(910, 0X1304));
    // 0x807C52B8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807C52BC: lw          $s1, 0x1F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1F4);
    // 0x807C52C0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x807C52C4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x807C52C8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x807C52CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807C52D0: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x807C52D4: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x807C52D8: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x807C52DC: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x807C52E0: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x807C52E4: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x807C52E8: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x807C52EC: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x807C52F0: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x807C52F4: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807C52F8: addiu       $a0, $zero, 0x46EA
    ctx->r4 = ADD32(0, 0X46EA);
    // 0x807C52FC: jal         0x80047090
    // 0x807C5300: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x807C5300: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    after_2:
    // 0x807C5304: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C5308: lui         $at, 0x46EA
    ctx->r1 = S32(0X46EA << 16);
    // 0x807C530C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807C5310: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x807C5314: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807C5318: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807C531C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x807C5320: jal         0x8004613C
    // 0x807C5324: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x807C5324: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_3:
    // 0x807C5328: bne         $v0, $zero, L_807C5340
    if (ctx->r2 != 0) {
        // 0x807C532C: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_807C5340;
    }
    // 0x807C532C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x807C5330: jal         0x800445A4
    // 0x807C5334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x807C5334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807C5338: b           L_807C5454
    // 0x807C533C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807C5454;
    // 0x807C533C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807C5340:
    // 0x807C5340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C5344: jal         0x80047F9C
    // 0x807C5348: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x807C5348: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x807C534C: jal         0x80047090
    // 0x807C5350: addiu       $a0, $zero, 0x45C2
    ctx->r4 = ADD32(0, 0X45C2);
    func_80047090(rdram, ctx);
        goto after_6;
    // 0x807C5350: addiu       $a0, $zero, 0x45C2
    ctx->r4 = ADD32(0, 0X45C2);
    after_6:
    // 0x807C5354: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C5358: lui         $at, 0x45C2
    ctx->r1 = S32(0X45C2 << 16);
    // 0x807C535C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807C5360: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x807C5364: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807C5368: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807C536C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x807C5370: jal         0x8004613C
    // 0x807C5374: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x807C5374: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_7:
    // 0x807C5378: bne         $v0, $zero, L_807C5390
    if (ctx->r2 != 0) {
        // 0x807C537C: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_807C5390;
    }
    // 0x807C537C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x807C5380: jal         0x800445A4
    // 0x807C5384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x807C5384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x807C5388: b           L_807C5454
    // 0x807C538C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807C5454;
    // 0x807C538C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807C5390:
    // 0x807C5390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C5394: jal         0x80047F9C
    // 0x807C5398: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x807C5398: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_9:
    // 0x807C539C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(910, 0X134C) << 16);
    // 0x807C53A0: lwc1        $f2, 0x5D0C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(910, 0X134C));
    // 0x807C53A4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807C53A8: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x807C53AC: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    // 0x807C53B0: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
    // 0x807C53B4: lbu         $v0, -0x7204($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7204);
    // 0x807C53B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807C53BC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x807C53C0: bne         $v0, $zero, L_807C53E0
    if (ctx->r2 != 0) {
        // 0x807C53C4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_807C53E0;
    }
    // 0x807C53C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x807C53C8: lbu         $a1, -0x7203($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7203);
    // 0x807C53CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807C53D0: bne         $a1, $at, L_807C53E0
    if (ctx->r5 != ctx->r1) {
        // 0x807C53D4: lui         $at, 0xC100
        ctx->r1 = S32(0XC100 << 16);
            goto L_807C53E0;
    }
    // 0x807C53D4: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x807C53D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807C53DC: nop

L_807C53E0:
    // 0x807C53E0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x807C53E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807C53E8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x807C53EC: bne         $a0, $v0, L_807C5400
    if (ctx->r4 != ctx->r2) {
        // 0x807C53F0: lbu         $a1, -0x7203($a1)
        ctx->r5 = MEM_BU(ctx->r5, -0X7203);
            goto L_807C5400;
    }
    // 0x807C53F0: lbu         $a1, -0x7203($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7203);
    // 0x807C53F4: bnel        $a0, $a1, L_807C5404
    if (ctx->r4 != ctx->r5) {
        // 0x807C53F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_807C5404;
    }
    goto skip_0;
    // 0x807C53F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_0:
    // 0x807C53FC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_807C5400:
    // 0x807C5400: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_807C5404:
    // 0x807C5404: bne         $v0, $at, L_807C5418
    if (ctx->r2 != ctx->r1) {
        // 0x807C5408: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_807C5418;
    }
    // 0x807C5408: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807C540C: bnel        $a1, $at, L_807C541C
    if (ctx->r5 != ctx->r1) {
        // 0x807C5410: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_807C541C;
    }
    goto skip_1;
    // 0x807C5410: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_1:
    // 0x807C5414: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_807C5418:
    // 0x807C5418: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_807C541C:
    // 0x807C541C: bne         $v0, $at, L_807C542C
    if (ctx->r2 != ctx->r1) {
        // 0x807C5420: lui         $at, 0xC040
        ctx->r1 = S32(0XC040 << 16);
            goto L_807C542C;
    }
    // 0x807C5420: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x807C5424: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807C5428: nop

L_807C542C:
    // 0x807C542C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807C5430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C5434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C5438: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x807C543C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807C5440: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x807C5444: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807C5448: jal         0x807C5464
    // 0x807C544C: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    func_807C5464(rdram, ctx);
        goto after_10;
    // 0x807C544C: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    after_10:
    // 0x807C5450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807C5454:
    // 0x807C5454: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807C5458: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807C545C: jr          $ra
    // 0x807C5460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807C5460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805DB140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DB140: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805DB144: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805DB148: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x805DB14C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805DB150: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x805DB154: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x805DB158: jal         0x80047090
    // 0x805DB15C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805DB15C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_0:
    // 0x805DB160: addiu       $at, $zero, 0x4194
    ctx->r1 = ADD32(0, 0X4194);
    // 0x805DB164: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x805DB168: bne         $s0, $at, L_805DB19C
    if (ctx->r16 != ctx->r1) {
        // 0x805DB16C: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_805DB19C;
    }
    // 0x805DB16C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805DB170: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805DB174: lui         $a0, 0x805E
    ctx->r4 = S32(RELOC_HI16(480, 0X2D80) << 16);
    // 0x805DB178: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x805DB17C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805DB180: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805DB184: ori         $a1, $a1, 0x2800
    ctx->r5 = ctx->r5 | 0X2800;
    // 0x805DB188: addiu       $a0, $a0, -0x2580
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(480, 0X2D80));
    // 0x805DB18C: jal         0x80046804
    // 0x805DB190: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x805DB190: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x805DB194: b           L_805DB1C0
    // 0x805DB198: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_805DB1C0;
    // 0x805DB198: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_805DB19C:
    // 0x805DB19C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805DB1A0: lui         $a0, 0x805E
    ctx->r4 = S32(RELOC_HI16(480, 0X2D80) << 16);
    // 0x805DB1A4: addiu       $a0, $a0, -0x2580
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(480, 0X2D80));
    // 0x805DB1A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805DB1AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805DB1B0: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x805DB1B4: jal         0x80046804
    // 0x805DB1B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80046804(rdram, ctx);
        goto after_2;
    // 0x805DB1B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x805DB1BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_805DB1C0:
    // 0x805DB1C0: bne         $v0, $zero, L_805DB1D0
    if (ctx->r2 != 0) {
        // 0x805DB1C4: lhu         $t7, 0x2E($sp)
        ctx->r15 = MEM_HU(ctx->r29, 0X2E);
            goto L_805DB1D0;
    }
    // 0x805DB1C4: lhu         $t7, 0x2E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2E);
    // 0x805DB1C8: b           L_805DB218
    // 0x805DB1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805DB218;
    // 0x805DB1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805DB1D0:
    // 0x805DB1D0: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x805DB1D4: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x805DB1D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805DB1DC: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x805DB1E0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x805DB1E4: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    // 0x805DB1E8: jal         0x80047F9C
    // 0x805DB1EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x805DB1EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x805DB1F0: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x805DB1F4: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x805DB1F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805DB1FC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x805DB200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DB204: jal         0x80052BA4
    // 0x805DB208: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    func_80052BA4(rdram, ctx);
        goto after_4;
    // 0x805DB208: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    after_4:
    // 0x805DB20C: jal         0x8005FDC4
    // 0x805DB210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_5;
    // 0x805DB210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805DB214: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_805DB218:
    // 0x805DB218: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805DB21C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805DB220: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805DB224: jr          $ra
    // 0x805DB228: nop

    return;
    // 0x805DB228: nop

;}
RECOMP_FUNC void func_805A8D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A8D00: lui         $v0, 0x805B
    ctx->r2 = S32(RELOC_HI16(429, 0X10) << 16);
    // 0x805A8D04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805A8D08: jr          $ra
    // 0x805A8D0C: addiu       $v0, $v0, -0x72F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(429, 0X10));
    return;
    // 0x805A8D0C: addiu       $v0, $v0, -0x72F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(429, 0X10));
;}
RECOMP_FUNC void func_805E482C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E482C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805E4830: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E4834: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E4838: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805E483C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E4840: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4844: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x805E4848: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x805E484C: lbu         $t8, 0x44($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X44);
    // 0x805E4850: beql        $t8, $zero, L_805E4880
    if (ctx->r24 == 0) {
        // 0x805E4854: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805E4880;
    }
    goto skip_0;
    // 0x805E4854: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x805E4858: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805E485C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805E4860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4864: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x805E4868: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x805E486C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805E4870: sb          $t9, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r25;
    // 0x805E4874: jal         0x805E4D78
    // 0x805E4878: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_805E4D78(rdram, ctx);
        goto after_0;
    // 0x805E4878: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_0:
    // 0x805E487C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805E4880:
    // 0x805E4880: jal         0x805E4378
    // 0x805E4884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805E4378(rdram, ctx);
        goto after_1;
    // 0x805E4884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x805E4888: jal         0x805E478C
    // 0x805E488C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E478C(rdram, ctx);
        goto after_2;
    // 0x805E488C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805E4890: jal         0x805E4460
    // 0x805E4894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4460(rdram, ctx);
        goto after_3;
    // 0x805E4894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805E4898: jal         0x805E4674
    // 0x805E489C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4674(rdram, ctx);
        goto after_4;
    // 0x805E489C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805E48A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E48A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E48A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805E48AC: jr          $ra
    // 0x805E48B0: nop

    return;
    // 0x805E48B0: nop

;}
RECOMP_FUNC void func_8044620C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044620C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446210: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446214: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80446218: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8044621C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80446220: sw          $t6, 0x6CA8($v1)
    MEM_W(0X6CA8, ctx->r3) = ctx->r14;
    // 0x80446224: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80446228: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x8044622C: addiu       $a2, $zero, 0x1B6C
    ctx->r6 = ADD32(0, 0X1B6C);
    // 0x80446230: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x80446234: sw          $a1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r5;
    // 0x80446238: sw          $a2, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r6;
    // 0x8044623C: sw          $a1, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r5;
    // 0x80446240: sw          $a2, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r6;
    // 0x80446244: sw          $t7, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = ctx->r15;
    // 0x80446248: swc1        $f0, 0x6B18($v1)
    MEM_W(0X6B18, ctx->r3) = ctx->f0.u32l;
    // 0x8044624C: swc1        $f0, 0x6B1C($v1)
    MEM_W(0X6B1C, ctx->r3) = ctx->f0.u32l;
    // 0x80446250: swc1        $f0, 0x6B20($v1)
    MEM_W(0X6B20, ctx->r3) = ctx->f0.u32l;
    // 0x80446254: jr          $ra
    // 0x80446258: swc1        $f0, 0x6B24($v1)
    MEM_W(0X6B24, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x80446258: swc1        $f0, 0x6B24($v1)
    MEM_W(0X6B24, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_804A0060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0060: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(170, 0XA0) << 16);
    // 0x804A0064: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(170, 0XA0));
    // 0x804A0068: jr          $ra
    // 0x804A006C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804A006C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8004937C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004937C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80049380: lh          $a1, 0x5A0($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X5A0);
    // 0x80049384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049388: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004938C: beq         $a1, $at, L_800493A8
    if (ctx->r5 == ctx->r1) {
        // 0x80049390: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800493A8;
    }
    // 0x80049390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049394: jal         0x80067878
    // 0x80049398: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80049398: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    after_0:
    // 0x8004939C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800493A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800493A4: sh          $t6, 0x5A0($at)
    MEM_H(0X5A0, ctx->r1) = ctx->r14;
L_800493A8:
    // 0x800493A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800493AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800493B0: jr          $ra
    // 0x800493B4: nop

    return;
    // 0x800493B4: nop

;}
RECOMP_FUNC void func_80074588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007458C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074590: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80074594: addiu       $a0, $a3, 0x40
    ctx->r4 = ADD32(ctx->r7, 0X40);
    // 0x80074598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007459C: jal         0x800824B0
    // 0x800745A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800745A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800745A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800745A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800745AC: jr          $ra
    // 0x800745B0: nop

    return;
    // 0x800745B0: nop

;}
RECOMP_FUNC void func_80008298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000829C: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x800082A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800082A4: beq         $at, $zero, L_800082CC
    if (ctx->r1 == 0) {
        // 0x800082A8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800082CC;
    }
    // 0x800082A8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800082AC: jal         0x8000B808
    // 0x800082B0: nop

    func_8000B808(rdram, ctx);
        goto after_0;
    // 0x800082B0: nop

    after_0:
    // 0x800082B4: bne         $v0, $zero, L_800082C4
    if (ctx->r2 != 0) {
        // 0x800082B8: nop
    
            goto L_800082C4;
    }
    // 0x800082B8: nop

    // 0x800082BC: b           L_800082EC
    // 0x800082C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800082EC;
    // 0x800082C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800082C4:
    // 0x800082C4: b           L_800082E8
    // 0x800082C8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
        goto L_800082E8;
    // 0x800082C8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_800082CC:
    // 0x800082CC: jal         0x8000B8DC
    // 0x800082D0: addiu       $a1, $a2, -0x80
    ctx->r5 = ADD32(ctx->r6, -0X80);
    func_8000B8DC(rdram, ctx);
        goto after_1;
    // 0x800082D0: addiu       $a1, $a2, -0x80
    ctx->r5 = ADD32(ctx->r6, -0X80);
    after_1:
    // 0x800082D4: bnel        $v0, $zero, L_800082E8
    if (ctx->r2 != 0) {
        // 0x800082D8: lw          $v1, 0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X4);
            goto L_800082E8;
    }
    goto skip_0;
    // 0x800082D8: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x800082DC: b           L_800082EC
    // 0x800082E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800082EC;
    // 0x800082E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800082E4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
L_800082E8:
    // 0x800082E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800082EC:
    // 0x800082EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800082F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800082F4: jr          $ra
    // 0x800082F8: nop

    return;
    // 0x800082F8: nop

    // 0x800082FC: jr          $ra
    // 0x80008300: nop

    return;
    // 0x80008300: nop

;}
RECOMP_FUNC void func_80008668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008668: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000866C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80008670: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80008674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008678: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000867C: addiu       $v1, $v1, 0x5250
    ctx->r3 = ADD32(ctx->r3, 0X5250);
    // 0x80008680: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80008684: lb          $t6, 0xD88($v0)
    ctx->r14 = MEM_B(ctx->r2, 0XD88);
L_80008688:
    // 0x80008688: bnel        $t6, $zero, L_8000869C
    if (ctx->r14 != 0) {
        // 0x8000868C: addiu       $v0, $v0, 0x54
        ctx->r2 = ADD32(ctx->r2, 0X54);
            goto L_8000869C;
    }
    goto skip_0;
    // 0x8000868C: addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    skip_0:
    // 0x80008690: b           L_800086A8
    // 0x80008694: addiu       $v1, $v0, 0xD88
    ctx->r3 = ADD32(ctx->r2, 0XD88);
        goto L_800086A8;
    // 0x80008694: addiu       $v1, $v0, 0xD88
    ctx->r3 = ADD32(ctx->r2, 0XD88);
    // 0x80008698: addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
L_8000869C:
    // 0x8000869C: bnel        $v0, $v1, L_80008688
    if (ctx->r2 != ctx->r3) {
        // 0x800086A0: lb          $t6, 0xD88($v0)
        ctx->r14 = MEM_B(ctx->r2, 0XD88);
            goto L_80008688;
    }
    goto skip_1;
    // 0x800086A0: lb          $t6, 0xD88($v0)
    ctx->r14 = MEM_B(ctx->r2, 0XD88);
    skip_1:
    // 0x800086A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800086A8:
    // 0x800086A8: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800086AC: addiu       $t7, $t7, 0x5250
    ctx->r15 = ADD32(ctx->r15, 0X5250);
    // 0x800086B0: bne         $v0, $t7, L_800086C0
    if (ctx->r2 != ctx->r15) {
        // 0x800086B4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800086C0;
    }
    // 0x800086B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800086B8: b           L_8000876C
    // 0x800086BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000876C;
    // 0x800086BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800086C0:
    // 0x800086C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800086C4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800086C8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800086CC: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800086D0: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x800086D4: sw          $a2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r6;
    // 0x800086D8: bne         $a0, $zero, L_800086EC
    if (ctx->r4 != 0) {
        // 0x800086DC: sw          $t9, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r25;
            goto L_800086EC;
    }
    // 0x800086DC: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800086E0: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x800086E4: b           L_80008738
    // 0x800086E8: sw          $t0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r8;
        goto L_80008738;
    // 0x800086E8: sw          $t0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r8;
L_800086EC:
    // 0x800086EC: div         $zero, $a2, $a0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r4)));
    // 0x800086F0: bne         $a0, $zero, L_800086FC
    if (ctx->r4 != 0) {
        // 0x800086F4: nop
    
            goto L_800086FC;
    }
    // 0x800086F4: nop

    // 0x800086F8: break       7
    do_break(2147518200);
L_800086FC:
    // 0x800086FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008700: bne         $a0, $at, L_80008714
    if (ctx->r4 != ctx->r1) {
        // 0x80008704: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80008714;
    }
    // 0x80008704: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80008708: bne         $a2, $at, L_80008714
    if (ctx->r6 != ctx->r1) {
        // 0x8000870C: nop
    
            goto L_80008714;
    }
    // 0x8000870C: nop

    // 0x80008710: break       6
    do_break(2147518224);
L_80008714:
    // 0x80008714: mflo        $v0
    ctx->r2 = lo;
    // 0x80008718: addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
    // 0x8000871C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80008720: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x80008724: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x80008728: beq         $at, $zero, L_80008738
    if (ctx->r1 == 0) {
        // 0x8000872C: sw          $v0, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r2;
            goto L_80008738;
    }
    // 0x8000872C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80008730: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x80008734: sw          $t1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r9;
L_80008738:
    // 0x80008738: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8000873C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80008740: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    // 0x80008744: sb          $a3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r7;
    // 0x80008748: sw          $t2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r10;
    // 0x8000874C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80008750: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    // 0x80008754: addiu       $a1, $v1, 0x38
    ctx->r5 = ADD32(ctx->r3, 0X38);
    // 0x80008758: sw          $t4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r12;
    // 0x8000875C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80008760: jal         0x8008AE20
    // 0x80008764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80008764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80008768: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8000876C:
    // 0x8000876C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80008774: jr          $ra
    // 0x80008778: nop

    return;
    // 0x80008778: nop

;}
RECOMP_FUNC void func_806D7374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D7374: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D7378: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D737C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806D7380: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806D7384: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D7388: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(622, 0X1940) << 16);
    // 0x806D738C: lui         $t0, 0x806D
    ctx->r8 = S32(RELOC_HI16(622, 0XEB0) << 16);
    // 0x806D7390: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x806D7394: addiu       $t0, $t0, 0x7A60
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(622, 0XEB0));
    // 0x806D7398: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806D739C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D73A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806D73A4: lw          $t8, -0x7B10($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(622, 0X1940));
    // 0x806D73A8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D73AC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x806D73B0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x806D73B4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x806D73B8: jal         0x806D6BC0
    // 0x806D73BC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_806D6BC0(rdram, ctx);
        goto after_0;
    // 0x806D73BC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_0:
    // 0x806D73C0: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x806D73C4: jal         0x80048F84
    // 0x806D73C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806D73C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x806D73CC: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x806D73D0: beq         $v1, $zero, L_806D73E0
    if (ctx->r3 == 0) {
        // 0x806D73D4: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_806D73E0;
    }
    // 0x806D73D4: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x806D73D8: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x806D73DC: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_806D73E0:
    // 0x806D73E0: bnel        $v1, $zero, L_806D74E0
    if (ctx->r3 != 0) {
        // 0x806D73E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D74E0;
    }
    goto skip_0;
    // 0x806D73E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806D73E8: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x806D73EC: bnel        $v0, $zero, L_806D7454
    if (ctx->r2 != 0) {
        // 0x806D73F0: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_806D7454;
    }
    goto skip_1;
    // 0x806D73F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x806D73F4: jal         0x80047090
    // 0x806D73F8: addiu       $a0, $zero, 0x45B8
    ctx->r4 = ADD32(0, 0X45B8);
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x806D73F8: addiu       $a0, $zero, 0x45B8
    ctx->r4 = ADD32(0, 0X45B8);
    after_2:
    // 0x806D73FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D7400: lui         $at, 0x45B8
    ctx->r1 = S32(0X45B8 << 16);
    // 0x806D7404: lui         $a3, 0xBC23
    ctx->r7 = S32(0XBC23 << 16);
    // 0x806D7408: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806D740C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806D7410: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x806D7414: jal         0x8004613C
    // 0x806D7418: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x806D7418: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_3:
    // 0x806D741C: bne         $v0, $zero, L_806D7434
    if (ctx->r2 != 0) {
        // 0x806D7420: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_806D7434;
    }
    // 0x806D7420: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x806D7424: jal         0x800445A4
    // 0x806D7428: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x806D7428: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x806D742C: b           L_806D74E0
    // 0x806D7430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D74E0;
    // 0x806D7430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D7434:
    // 0x806D7434: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D7438: jal         0x80047F9C
    // 0x806D743C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x806D743C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x806D7440: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x806D7444: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x806D7448: sb          $t3, 0x17C($t4)
    MEM_B(0X17C, ctx->r12) = ctx->r11;
    // 0x806D744C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x806D7450: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_806D7454:
    // 0x806D7454: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x806D7458: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x806D745C: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(622, 0X1A18) << 16);
    // 0x806D7460: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
    // 0x806D7464: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806D7468: lw          $t7, -0x7A38($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(622, 0X1A18));
    // 0x806D746C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D7470: lui         $a1, 0x806E
    ctx->r5 = S32(RELOC_HI16(622, 0X19AC) << 16);
    // 0x806D7474: sh          $t7, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r15;
    // 0x806D7478: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x806D747C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D7480: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    // 0x806D7484: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x806D7488: swc1        $f6, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f6.u32l;
    // 0x806D748C: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x806D7490: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
    // 0x806D7494: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x806D7498: addiu       $v0, $t8, 0x1
    ctx->r2 = ADD32(ctx->r24, 0X1);
    // 0x806D749C: slti        $at, $v0, 0x1B
    ctx->r1 = SIGNED(ctx->r2) < 0X1B ? 1 : 0;
    // 0x806D74A0: bne         $at, $zero, L_806D74CC
    if (ctx->r1 != 0) {
        // 0x806D74A4: sw          $v0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r2;
            goto L_806D74CC;
    }
    // 0x806D74A4: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x806D74A8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x806D74AC: jal         0x806D6D60
    // 0x806D74B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806D6D60(rdram, ctx);
        goto after_6;
    // 0x806D74B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x806D74B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D74B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D74BC: jal         0x806D7A20
    // 0x806D74C0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_806D7A20(rdram, ctx);
        goto after_7;
    // 0x806D74C0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_7:
    // 0x806D74C4: b           L_806D74E0
    // 0x806D74C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D74E0;
    // 0x806D74C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D74CC:
    // 0x806D74CC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x806D74D0: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x806D74D4: jal         0x806D6C6C
    // 0x806D74D8: lw          $a1, -0x7AA4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(622, 0X19AC));
    func_806D6C6C(rdram, ctx);
        goto after_8;
    // 0x806D74D8: lw          $a1, -0x7AA4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(622, 0X19AC));
    after_8:
    // 0x806D74DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D74E0:
    // 0x806D74E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806D74E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806D74E8: jr          $ra
    // 0x806D74EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806D74EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80665578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066557C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80665580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80665584: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80665588: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8066558C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80665590: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80665594: bne         $v0, $at, L_806655AC
    if (ctx->r2 != ctx->r1) {
        // 0x80665598: addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
            goto L_806655AC;
    }
    // 0x80665598: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x8066559C: jal         0x800677F8
    // 0x806655A0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x806655A0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x806655A4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806655A8: lw          $v0, 0x1E0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1E0);
L_806655AC:
    // 0x806655AC: beq         $v0, $zero, L_806655C0
    if (ctx->r2 == 0) {
        // 0x806655B0: addiu       $t7, $zero, 0x50
        ctx->r15 = ADD32(0, 0X50);
            goto L_806655C0;
    }
    // 0x806655B0: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x806655B4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806655B8: b           L_806655D4
    // 0x806655BC: sw          $t6, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r14;
        goto L_806655D4;
    // 0x806655BC: sw          $t6, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r14;
L_806655C0:
    // 0x806655C0: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x806655C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806655C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806655CC: jal         0x8066622C
    // 0x806655D0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_8066622C(rdram, ctx);
        goto after_1;
    // 0x806655D0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_1:
L_806655D4:
    // 0x806655D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806655D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806655DC: jr          $ra
    // 0x806655E0: nop

    return;
    // 0x806655E0: nop

;}
RECOMP_FUNC void func_8040D4A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D4A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040D4A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D4A8: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D4AC: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8040D4B0: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F14) << 16);
    // 0x8040D4B4: lwc1        $f0, 0x38($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8040D4B8: lwc1        $f2, 0x3C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8040D4BC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8040D4C0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8040D4C4: nop

    // 0x8040D4C8: bc1fl       L_8040D4FC
    if (!c1cs) {
        // 0x8040D4CC: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8040D4FC;
    }
    goto skip_0;
    // 0x8040D4CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8040D4D0: lwc1        $f4, -0x1AEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F14));
    // 0x8040D4D4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8040D4D8: swc1        $f6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f6.u32l;
    // 0x8040D4DC: lwc1        $f8, 0x38($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8040D4E0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8040D4E4: nop

    // 0x8040D4E8: bc1fl       L_8040D530
    if (!c1cs) {
        // 0x8040D4EC: swc1        $f12, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
            goto L_8040D530;
    }
    goto skip_1;
    // 0x8040D4EC: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    skip_1:
    // 0x8040D4F0: b           L_8040D52C
    // 0x8040D4F4: swc1        $f2, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f2.u32l;
        goto L_8040D52C;
    // 0x8040D4F4: swc1        $f2, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f2.u32l;
    // 0x8040D4F8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8040D4FC:
    // 0x8040D4FC: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F18) << 16);
    // 0x8040D500: bc1fl       L_8040D530
    if (!c1cs) {
        // 0x8040D504: swc1        $f12, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
            goto L_8040D530;
    }
    goto skip_2;
    // 0x8040D504: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    skip_2:
    // 0x8040D508: lwc1        $f10, -0x1AE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F18));
    // 0x8040D50C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8040D510: swc1        $f16, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f16.u32l;
    // 0x8040D514: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8040D518: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8040D51C: nop

    // 0x8040D520: bc1fl       L_8040D530
    if (!c1cs) {
        // 0x8040D524: swc1        $f12, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
            goto L_8040D530;
    }
    goto skip_3;
    // 0x8040D524: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    skip_3:
    // 0x8040D528: swc1        $f2, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f2.u32l;
L_8040D52C:
    // 0x8040D52C: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
L_8040D530:
    // 0x8040D530: lw          $t6, 0x34($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X34);
    // 0x8040D534: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(20, 0X1E60) << 16);
    // 0x8040D538: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8040D53C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040D540: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8040D544: lw          $t9, -0x1BA0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(20, 0X1E60));
    // 0x8040D548: jalr        $t9
    // 0x8040D54C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040D54C: nop

    after_0:
    // 0x8040D550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040D554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040D558: jr          $ra
    // 0x8040D55C: nop

    return;
    // 0x8040D55C: nop

;}
RECOMP_FUNC void func_8044680C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044680C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446810: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446814: ori         $at, $at, 0x6E54
    ctx->r1 = ctx->r1 | 0X6E54;
    // 0x80446818: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044681C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80446820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80446824:
    // 0x80446824: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80446828: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8044682C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80446830: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80446834: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80446838: bne         $a1, $v0, L_80446824
    if (ctx->r5 != ctx->r2) {
        // 0x8044683C: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_80446824;
    }
    // 0x8044683C: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x80446840: jr          $ra
    // 0x80446844: nop

    return;
    // 0x80446844: nop

;}
RECOMP_FUNC void func_804647B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804647B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804647BC: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x804647C0: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x804647C4: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x804647C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804647CC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x804647D0: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x804647D4: lw          $a2, 0x1F18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F18);
    // 0x804647D8: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x804647DC: lwc1        $f10, 0x78($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X78);
    // 0x804647E0: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x804647E4: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x804647E8: lwc1        $f4, 0x7C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X7C);
    // 0x804647EC: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x804647F0: lwc1        $f14, 0xC8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804647F4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x804647F8: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x804647FC: bltz        $a2, L_804648D8
    if (SIGNED(ctx->r6) < 0) {
        // 0x80464800: addiu       $a1, $v0, 0x1254
        ctx->r5 = ADD32(ctx->r2, 0X1254);
            goto L_804648D8;
    }
    // 0x80464800: addiu       $a1, $v0, 0x1254
    ctx->r5 = ADD32(ctx->r2, 0X1254);
    // 0x80464804: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x80464808: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8046480C: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80464810: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80464814: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80464818: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8046481C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80464820: sub.s       $f2, $f18, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x80464824: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80464828: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8046482C: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80464830: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80464834: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80464838: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8046483C: nop

L_80464840:
    // 0x80464840: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80464844: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80464848: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8046484C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80464850: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80464854: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80464858: nop

    // 0x8046485C: bc1fl       L_80464874
    if (!c1cs) {
        // 0x80464860: c.lt.s      $f12, $f24
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
            goto L_80464874;
    }
    goto skip_0;
    // 0x80464860: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
    skip_0:
    // 0x80464864: sub.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80464868: b           L_80464888
    // 0x8046486C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
        goto L_80464888;
    // 0x8046486C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80464870: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
L_80464874:
    // 0x80464874: nop

    // 0x80464878: bc1fl       L_8046488C
    if (!c1cs) {
        // 0x8046487C: lwc1        $f4, 0x4($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
            goto L_8046488C;
    }
    goto skip_1;
    // 0x8046487C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x80464880: add.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80464884: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_80464888:
    // 0x80464888: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
L_8046488C:
    // 0x8046488C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80464890: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80464894: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80464898: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8046489C: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x804648A0: nop

    // 0x804648A4: bc1fl       L_804648BC
    if (!c1cs) {
        // 0x804648A8: c.lt.s      $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
            goto L_804648BC;
    }
    goto skip_2;
    // 0x804648A8: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
    skip_2:
    // 0x804648AC: sub.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f20.fl;
    // 0x804648B0: b           L_804648D0
    // 0x804648B4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
        goto L_804648D0;
    // 0x804648B4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x804648B8: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
L_804648BC:
    // 0x804648BC: nop

    // 0x804648C0: bc1f        L_804648D0
    if (!c1cs) {
        // 0x804648C4: nop
    
            goto L_804648D0;
    }
    // 0x804648C4: nop

    // 0x804648C8: add.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x804648CC: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_804648D0:
    // 0x804648D0: bgez        $a2, L_80464840
    if (SIGNED(ctx->r6) >= 0) {
        // 0x804648D4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80464840;
    }
    // 0x804648D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_804648D8:
    // 0x804648D8: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x804648DC: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x804648E0: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x804648E4: jr          $ra
    // 0x804648E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804648E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8043F6CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F6CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043F6D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F6D4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8043F6D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F6DC: jal         0x80442188
    // 0x8043F6E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F6E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x8043F6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043F6EC: jr          $ra
    // 0x8043F6F0: nop

    return;
    // 0x8043F6F0: nop

;}
RECOMP_FUNC void func_804C1E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1E6C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804C1E70: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(203, 0X20C) << 16);
    // 0x804C1E74: addiu       $t6, $t6, 0x197C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(203, 0X20C));
    // 0x804C1E78: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804C1E7C: jr          $ra
    // 0x804C1E80: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804C1E80: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8053080C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053080C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80530810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80530814: jal         0x80044658
    // 0x80530818: nop

    func_80044658(rdram, ctx);
        goto after_0;
    // 0x80530818: nop

    after_0:
    // 0x8053081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80530820: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80530824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80530828: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x8053082C: jr          $ra
    // 0x80530830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80530830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80716664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716664: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80716668: lui         $at, 0x8073
    ctx->r1 = S32(RELOC_HI16(733, 0X1F0A0) << 16);
    // 0x8071666C: lwc1        $f4, 0x5410($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(733, 0X1F0A0));
    // 0x80716670: lui         $at, 0x8073
    ctx->r1 = S32(RELOC_HI16(733, 0X1F0A4) << 16);
    // 0x80716674: lwc1        $f6, 0x5414($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(733, 0X1F0A4));
    // 0x80716678: lui         $at, 0x8073
    ctx->r1 = S32(RELOC_HI16(733, 0X1F0A8) << 16);
    // 0x8071667C: lwc1        $f8, 0x5418($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(733, 0X1F0A8));
    // 0x80716680: lui         $at, 0x8073
    ctx->r1 = S32(RELOC_HI16(733, 0X1F0AC) << 16);
    // 0x80716684: lwc1        $f10, 0x541C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(733, 0X1F0AC));
    // 0x80716688: lui         $at, 0x8073
    ctx->r1 = S32(RELOC_HI16(733, 0X1F0B0) << 16);
    // 0x8071668C: lwc1        $f16, 0x5420($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(733, 0X1F0B0));
    // 0x80716690: lui         $at, 0x8073
    ctx->r1 = S32(RELOC_HI16(733, 0X1F0B4) << 16);
    // 0x80716694: lwc1        $f18, 0x5424($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(733, 0X1F0B4));
    // 0x80716698: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8071669C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x807166A0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x807166A4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x807166A8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x807166AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807166B0: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x807166B4: addiu       $t7, $zero, 0x744
    ctx->r15 = ADD32(0, 0X744);
    // 0x807166B8: addiu       $t8, $zero, 0x7F8
    ctx->r24 = ADD32(0, 0X7F8);
    // 0x807166BC: addiu       $t9, $zero, 0x870
    ctx->r25 = ADD32(0, 0X870);
    // 0x807166C0: addiu       $t0, $zero, 0xA8C
    ctx->r8 = ADD32(0, 0XA8C);
    // 0x807166C4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x807166C8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x807166CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x807166D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x807166D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807166D8: addiu       $a2, $zero, 0x2D0
    ctx->r6 = ADD32(0, 0X2D0);
    // 0x807166DC: addiu       $a3, $zero, 0x348
    ctx->r7 = ADD32(0, 0X348);
    // 0x807166E0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x807166E4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x807166E8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x807166EC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x807166F0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x807166F4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x807166F8: jal         0x80716438
    // 0x807166FC: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_80716438(rdram, ctx);
        goto after_0;
    // 0x807166FC: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80716700: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80716704: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80716708: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8071670C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80716710: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x80716714: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80716718: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8071671C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80716720: jr          $ra
    // 0x80716724: nop

    return;
    // 0x80716724: nop

;}
RECOMP_FUNC void func_804759C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804759C0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804759C4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804759C8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804759CC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804759D0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804759D4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804759D8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804759DC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804759E0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804759E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804759E8: jr          $ra
    // 0x804759EC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804759EC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80468020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80468020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80468024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80468028: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046802C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80468030: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80468034: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80468038: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x8046803C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80468040: sb          $t6, 0x165($t7)
    MEM_B(0X165, ctx->r15) = ctx->r14;
    // 0x80468044: lwc1        $f4, 0x2CF4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2CF4);
    // 0x80468048: lw          $t8, 0x2CF8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2CF8);
    // 0x8046804C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80468050: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80468054: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80468058: slti        $at, $t9, 0x11
    ctx->r1 = SIGNED(ctx->r25) < 0X11 ? 1 : 0;
    // 0x8046805C: sw          $t9, 0x2CF8($v0)
    MEM_W(0X2CF8, ctx->r2) = ctx->r25;
    // 0x80468060: bne         $at, $zero, L_804680C0
    if (ctx->r1 != 0) {
        // 0x80468064: swc1        $f8, 0x2CF4($v0)
        MEM_W(0X2CF4, ctx->r2) = ctx->f8.u32l;
            goto L_804680C0;
    }
    // 0x80468064: swc1        $f8, 0x2CF4($v0)
    MEM_W(0X2CF4, ctx->r2) = ctx->f8.u32l;
    // 0x80468068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046806C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80468070: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80468074: jal         0x804686B4
    // 0x80468078: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804686B4(rdram, ctx);
        goto after_0;
    // 0x80468078: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046807C: jal         0x80466950
    // 0x80468080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80466950(rdram, ctx);
        goto after_1;
    // 0x80468080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80468084: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80468088: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8046808C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80468090: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80468094: swc1        $f10, 0x2CF4($v0)
    MEM_W(0X2CF4, ctx->r2) = ctx->f10.u32l;
    // 0x80468098: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x8046809C: beql        $t1, $zero, L_804680B8
    if (ctx->r9 == 0) {
        // 0x804680A0: lw          $t2, 0x8($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X8);
            goto L_804680B8;
    }
    goto skip_0;
    // 0x804680A0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x804680A4: jal         0x8005FCA8
    // 0x804680A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005FCA8(rdram, ctx);
        goto after_2;
    // 0x804680A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x804680AC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804680B0: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x804680B4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
L_804680B8:
    // 0x804680B8: b           L_804680F0
    // 0x804680BC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
        goto L_804680F0;
    // 0x804680BC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
L_804680C0:
    // 0x804680C0: lw          $v1, 0x1FA0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1FA0);
    // 0x804680C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804680C8: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x804680CC: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x804680D0: sw          $t3, 0x1FA0($v0)
    MEM_W(0X1FA0, ctx->r2) = ctx->r11;
    // 0x804680D4: bne         $at, $zero, L_804680E0
    if (ctx->r1 != 0) {
        // 0x804680D8: sw          $v1, 0x1F9C($v0)
        MEM_W(0X1F9C, ctx->r2) = ctx->r3;
            goto L_804680E0;
    }
    // 0x804680D8: sw          $v1, 0x1F9C($v0)
    MEM_W(0X1F9C, ctx->r2) = ctx->r3;
    // 0x804680DC: sw          $zero, 0x1FA0($v0)
    MEM_W(0X1FA0, ctx->r2) = 0;
L_804680E0:
    // 0x804680E0: jal         0x804686B4
    // 0x804680E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804686B4(rdram, ctx);
        goto after_3;
    // 0x804680E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x804680E8: jal         0x80466950
    // 0x804680EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80466950(rdram, ctx);
        goto after_4;
    // 0x804680EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
L_804680F0:
    // 0x804680F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804680F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804680F8: jr          $ra
    // 0x804680FC: nop

    return;
    // 0x804680FC: nop

;}
RECOMP_FUNC void func_805AE504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE504: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE508: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE50C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE510: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE514: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE518: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE51C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE520: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE524: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE528: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE52C: jr          $ra
    // 0x805AE530: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE530: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80446440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446440: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446444: addiu       $v1, $zero, 0x1EF0
    ctx->r3 = ADD32(0, 0X1EF0);
    // 0x80446448: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044644C: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x80446450: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446454: sw          $zero, 0x6CB0($at)
    MEM_W(0X6CB0, ctx->r1) = 0;
    // 0x80446458: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x8044645C: addiu       $a2, $zero, 0x1B6C
    ctx->r6 = ADD32(0, 0X1B6C);
    // 0x80446460: sw          $a1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r5;
    // 0x80446464: sw          $a2, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r6;
    // 0x80446468: sw          $a1, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r5;
    // 0x8044646C: sw          $a2, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r6;
    // 0x80446470: jr          $ra
    // 0x80446474: sw          $v1, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r3;
    return;
    // 0x80446474: sw          $v1, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_807B101C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B101C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B1020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B1024: jal         0x807B07B0
    // 0x807B1028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807B07B0(rdram, ctx);
        goto after_0;
    // 0x807B1028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B102C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x807B1030: jal         0x807B0F14
    // 0x807B1034: lw          $a0, 0x1F4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X1F4);
    func_807B0F14(rdram, ctx);
        goto after_1;
    // 0x807B1034: lw          $a0, 0x1F4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X1F4);
    after_1:
    // 0x807B1038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B103C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B1040: jr          $ra
    // 0x807B1044: nop

    return;
    // 0x807B1044: nop

;}
RECOMP_FUNC void func_8002F26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F26C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002F270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F274: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8002F278: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8002F27C: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F280: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8002F284: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x8002F288: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002F28C: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8002F290: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002F294: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8002F298: jal         0x8002F15C
    // 0x8002F29C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8002F15C(rdram, ctx);
        goto after_0;
    // 0x8002F29C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8002F2A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002F2A4: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8002F2A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002F2AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002F2B0: sb          $zero, 0x113($a0)
    MEM_B(0X113, ctx->r4) = 0;
    // 0x8002F2B4: sw          $zero, 0x128($a0)
    MEM_W(0X128, ctx->r4) = 0;
    // 0x8002F2B8: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x8002F2BC: jal         0x80036900
    // 0x8002F2C0: swc1        $f8, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f8.u32l;
    func_80036900(rdram, ctx);
        goto after_1;
    // 0x8002F2C0: swc1        $f8, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f8.u32l;
    after_1:
    // 0x8002F2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F2C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002F2CC: jr          $ra
    // 0x8002F2D0: nop

    return;
    // 0x8002F2D0: nop

;}
RECOMP_FUNC void func_80001114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001114: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80001118: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x8000111C: lui         $t6, 0x1600
    ctx->r14 = S32(0X1600 << 16);
    // 0x80001120: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80001124: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80001128: jr          $ra
    // 0x8000112C: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x8000112C: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_80582EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582EC0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80582EC4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80582EC8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80582ECC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80582ED0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80582ED4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80582ED8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80582EDC: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(399, 0X4744) << 16);
    // 0x80582EE0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80582EE4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80582EE8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80582EEC: lw          $t1, 0x3554($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(399, 0X4744));
    // 0x80582EF0: jr          $ra
    // 0x80582EF4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80582EF4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8058225C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058225C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80582260: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80582264: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80582268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8058226C: jal         0x8057EF14
    // 0x80582270: addiu       $a1, $zero, 0x40F1
    ctx->r5 = ADD32(0, 0X40F1);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x80582270: addiu       $a1, $zero, 0x40F1
    ctx->r5 = ADD32(0, 0X40F1);
    after_0:
    // 0x80582274: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80582278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8058227C: jal         0x8057EF14
    // 0x80582280: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    func_8057EF14(rdram, ctx);
        goto after_1;
    // 0x80582280: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    after_1:
    // 0x80582284: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80582288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8058228C: jal         0x8057EF14
    // 0x80582290: addiu       $a1, $zero, 0x4021
    ctx->r5 = ADD32(0, 0X4021);
    func_8057EF14(rdram, ctx);
        goto after_2;
    // 0x80582290: addiu       $a1, $zero, 0x4021
    ctx->r5 = ADD32(0, 0X4021);
    after_2:
    // 0x80582294: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80582298: jal         0x80580C70
    // 0x8058229C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80580C70(rdram, ctx);
        goto after_3;
    // 0x8058229C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805822A0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x805822A4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x805822A8: beql        $t6, $zero, L_80582348
    if (ctx->r14 == 0) {
        // 0x805822AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80582348;
    }
    goto skip_0;
    // 0x805822AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805822B0: beq         $t7, $zero, L_80582344
    if (ctx->r15 == 0) {
        // 0x805822B4: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80582344;
    }
    // 0x805822B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805822B8: beql        $t8, $zero, L_80582348
    if (ctx->r24 == 0) {
        // 0x805822BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80582348;
    }
    goto skip_1;
    // 0x805822BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805822C0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x805822C4: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x805822C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805822CC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805822D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805822D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805822D8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x805822DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805822E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805822E4: bc1f        L_8058232C
    if (!c1cs) {
        // 0x805822E8: nop
    
            goto L_8058232C;
    }
    // 0x805822E8: nop

    // 0x805822EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805822F0: nop

    // 0x805822F4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x805822F8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x805822FC: jal         0x80582144
    // 0x80582300: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    func_80582144(rdram, ctx);
        goto after_4;
    // 0x80582300: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    after_4:
    // 0x80582304: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80582308: lw          $t0, 0x16C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X16C);
    // 0x8058230C: sb          $v0, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r2;
    // 0x80582310: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80582314: lw          $t2, 0x16C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X16C);
    // 0x80582318: sb          $v0, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r2;
    // 0x8058231C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80582320: lw          $t4, 0x16C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X16C);
    // 0x80582324: b           L_80582344
    // 0x80582328: sb          $v0, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r2;
        goto L_80582344;
    // 0x80582328: sb          $v0, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r2;
L_8058232C:
    // 0x8058232C: jal         0x80582498
    // 0x80582330: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80582498(rdram, ctx);
        goto after_5;
    // 0x80582330: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_5:
    // 0x80582334: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80582338: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8058233C: nop

    // 0x80582340: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80582344:
    // 0x80582344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80582348:
    // 0x80582348: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8058234C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80582350: jr          $ra
    // 0x80582354: nop

    return;
    // 0x80582354: nop

;}
RECOMP_FUNC void func_80579A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80579A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80579A44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80579A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80579A4C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1E4C) << 16);
    // 0x80579A50: lui         $a0, 0x8058
    ctx->r4 = S32(RELOC_HI16(384, 0X1E40) << 16);
    // 0x80579A54: lui         $a1, 0x8058
    ctx->r5 = S32(RELOC_HI16(384, 0X1E50) << 16);
    // 0x80579A58: sw          $zero, -0x4774($at)
    MEM_W((int16_t)RELOC_LO16(384, 0X1E4C), ctx->r1) = 0;
    // 0x80579A5C: addiu       $a1, $a1, -0x4770
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(384, 0X1E50));
    // 0x80579A60: addiu       $a0, $a0, -0x4780
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(384, 0X1E40));
    // 0x80579A64: jal         0x8004667C
    // 0x80579A68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80579A68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80579A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80579A70: lui         $t6, 0x8058
    ctx->r14 = S32(RELOC_HI16(384, 0X1A30) << 16);
    // 0x80579A74: addiu       $t6, $t6, -0x4B90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(384, 0X1A30));
    // 0x80579A78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80579A7C: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(384, 0X298) << 16);
    // 0x80579A80: sw          $t6, -0x763C($at)
    MEM_W(-0X763C, ctx->r1) = ctx->r14;
    // 0x80579A84: addiu       $v0, $v0, -0x6328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(384, 0X298));
    // 0x80579A88: jr          $ra
    // 0x80579A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80579A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804C97B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C97B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C97B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C97B8: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x804C97BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804C97C0: beq         $v0, $zero, L_804C97D0
    if (ctx->r2 == 0) {
        // 0x804C97C4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_804C97D0;
    }
    // 0x804C97C4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x804C97C8: b           L_804C97F8
    // 0x804C97CC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_804C97F8;
    // 0x804C97CC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_804C97D0:
    // 0x804C97D0: jal         0x8004700C
    // 0x804C97D4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804C97D4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x804C97D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x804C97DC: beq         $v0, $zero, L_804C97F8
    if (ctx->r2 == 0) {
        // 0x804C97E0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804C97F8;
    }
    // 0x804C97E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804C97E4: jal         0x804C9A54
    // 0x804C97E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_804C9A54(rdram, ctx);
        goto after_1;
    // 0x804C97E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x804C97EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x804C97F0: addiu       $t7, $zero, 0x90
    ctx->r15 = ADD32(0, 0X90);
    // 0x804C97F4: sw          $t7, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r15;
L_804C97F8:
    // 0x804C97F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C97FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C9800: jr          $ra
    // 0x804C9804: nop

    return;
    // 0x804C9804: nop

;}
RECOMP_FUNC void func_8005FDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FDC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FDC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FDCC: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8005FDD0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FDD4: beql        $v1, $zero, L_8005FE3C
    if (ctx->r3 == 0) {
        // 0x8005FDD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FE3C;
    }
    goto skip_0;
    // 0x8005FDD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FDDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FDE0: lbu         $t6, 0x74($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X74);
    // 0x8005FDE4: beql        $t6, $zero, L_8005FE08
    if (ctx->r14 == 0) {
        // 0x8005FDE8: lbu         $t7, 0x75($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X75);
            goto L_8005FE08;
    }
    goto skip_1;
    // 0x8005FDE8: lbu         $t7, 0x75($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X75);
    skip_1:
    // 0x8005FDEC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8005FDF0: jal         0x8005FCA8
    // 0x8005FDF4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x8005FDF4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005FDF8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FDFC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8005FE00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FE04: lbu         $t7, 0x75($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X75);
L_8005FE08:
    // 0x8005FE08: beql        $t7, $zero, L_8005FE3C
    if (ctx->r15 == 0) {
        // 0x8005FE0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FE3C;
    }
    goto skip_2;
    // 0x8005FE0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8005FE10: lbu         $t8, 0x78($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X78);
    // 0x8005FE14: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005FE18: bnel        $t8, $zero, L_8005FE3C
    if (ctx->r24 != 0) {
        // 0x8005FE1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FE3C;
    }
    goto skip_3;
    // 0x8005FE1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8005FE20: jal         0x8005F9A8
    // 0x8005FE24: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005F9A8(rdram, ctx);
        goto after_1;
    // 0x8005FE24: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8005FE28: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FE2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005FE30: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8005FE34: sb          $t9, 0x78($t0)
    MEM_B(0X78, ctx->r8) = ctx->r25;
    // 0x8005FE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FE3C:
    // 0x8005FE3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FE40: jr          $ra
    // 0x8005FE44: nop

    return;
    // 0x8005FE44: nop

;}
RECOMP_FUNC void func_80670A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670A50: jr          $ra
    // 0x80670A54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80670A54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8040EF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EF80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EF88: jal         0x8040EDB0
    // 0x8040EF8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040EDB0(rdram, ctx);
        goto after_0;
    // 0x8040EF8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040EF90: jal         0x8040EB60
    // 0x8040EF94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040EB60(rdram, ctx);
        goto after_1;
    // 0x8040EF94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8040EF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EF9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EFA0: jr          $ra
    // 0x8040EFA4: nop

    return;
    // 0x8040EFA4: nop

;}
RECOMP_FUNC void func_80583FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80583FC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80583FC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80583FCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80583FD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80583FD4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80583FD8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80583FDC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80583FE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80583FE4: addiu       $t6, $zero, 0x1E00
    ctx->r14 = ADD32(0, 0X1E00);
    // 0x80583FE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80583FEC: addiu       $a2, $zero, 0x1A4
    ctx->r6 = ADD32(0, 0X1A4);
    // 0x80583FF0: addiu       $a3, $zero, 0x1D88
    ctx->r7 = ADD32(0, 0X1D88);
    // 0x80583FF4: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80583FF8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80583FFC: jal         0x80583CCC
    // 0x80584000: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80583CCC(rdram, ctx);
        goto after_0;
    // 0x80584000: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80584004: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80584008: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8058400C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80584010: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80584014: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80584018: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8058401C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80584020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80584024: jr          $ra
    // 0x80584028: nop

    return;
    // 0x80584028: nop

;}
RECOMP_FUNC void func_8003200C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003200C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032014: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    // 0x80032018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003201C: beql        $a1, $at, L_800320B4
    if (ctx->r5 == ctx->r1) {
        // 0x80032020: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800320B4;
    }
    goto skip_0;
    // 0x80032020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80032024: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032028: lbu         $t6, 0x155($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X155);
    // 0x8003202C: beql        $t6, $zero, L_800320B4
    if (ctx->r14 == 0) {
        // 0x80032030: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800320B4;
    }
    goto skip_1;
    // 0x80032030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80032034: lbu         $t7, 0x157($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X157);
    // 0x80032038: lw          $v0, 0x164($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X164);
    // 0x8003203C: bne         $t7, $zero, L_8003205C
    if (ctx->r15 != 0) {
        // 0x80032040: lw          $a2, 0x174($v0)
        ctx->r6 = MEM_W(ctx->r2, 0X174);
            goto L_8003205C;
    }
    // 0x80032040: lw          $a2, 0x174($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X174);
    // 0x80032044: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80032048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003204C: lhu         $t9, 0x1C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1C);
    // 0x80032050: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x80032054: beq         $t0, $zero, L_80032064
    if (ctx->r8 == 0) {
        // 0x80032058: nop
    
            goto L_80032064;
    }
    // 0x80032058: nop

L_8003205C:
    // 0x8003205C: b           L_800320B4
    // 0x80032060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800320B4;
    // 0x80032060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032064:
    // 0x80032064: bne         $a1, $at, L_800320B0
    if (ctx->r5 != ctx->r1) {
        // 0x80032068: lui         $t1, 0x8010
        ctx->r9 = S32(0X8010 << 16);
            goto L_800320B0;
    }
    // 0x80032068: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8003206C: lh          $t1, -0x7680($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7680);
    // 0x80032070: slti        $at, $t1, -0x32
    ctx->r1 = SIGNED(ctx->r9) < -0X32 ? 1 : 0;
    // 0x80032074: beql        $at, $zero, L_80032090
    if (ctx->r1 == 0) {
        // 0x80032078: lw          $v0, 0x170($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X170);
            goto L_80032090;
    }
    goto skip_2;
    // 0x80032078: lw          $v0, 0x170($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X170);
    skip_2:
    // 0x8003207C: jal         0x8002EED8
    // 0x80032080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002EED8(rdram, ctx);
        goto after_0;
    // 0x80032080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80032084: b           L_800320B4
    // 0x80032088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800320B4;
    // 0x80032088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003208C: lw          $v0, 0x170($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X170);
L_80032090:
    // 0x80032090: beq         $v0, $zero, L_800320B0
    if (ctx->r2 == 0) {
        // 0x80032094: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800320B0;
    }
    // 0x80032094: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80032098: bne         $v0, $zero, L_800320B0
    if (ctx->r2 != 0) {
        // 0x8003209C: sw          $v0, 0x170($v1)
        MEM_W(0X170, ctx->r3) = ctx->r2;
            goto L_800320B0;
    }
    // 0x8003209C: sw          $v0, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->r2;
    // 0x800320A0: jal         0x8002EED8
    // 0x800320A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002EED8(rdram, ctx);
        goto after_1;
    // 0x800320A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800320A8: b           L_800320B4
    // 0x800320AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800320B4;
    // 0x800320AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800320B0:
    // 0x800320B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800320B4:
    // 0x800320B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800320B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800320BC: jr          $ra
    // 0x800320C0: nop

    return;
    // 0x800320C0: nop

;}
RECOMP_FUNC void func_80422BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422BDC: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80422BE0: beq         $v0, $zero, L_80422BEC
    if (ctx->r2 == 0) {
        // 0x80422BE4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80422BEC;
    }
    // 0x80422BE4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80422BE8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80422BEC:
    // 0x80422BEC: jr          $ra
    // 0x80422BF0: nop

    return;
    // 0x80422BF0: nop

;}
RECOMP_FUNC void func_806B038C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B038C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806B0390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B0394: lwc1        $f4, 0x50($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X50);
    // 0x806B0398: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x806B039C: lwc1        $f2, 0x40($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806B03A0: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806B03A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806B03A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806B03AC: jal         0x80066E88
    // 0x806B03B0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x806B03B0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x806B03B4: jal         0x80066E88
    // 0x806B03B8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806B03B8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x806B03BC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806B03C0: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x806B03C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806B03C8: lwc1        $f8, 0x70($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X70);
    // 0x806B03CC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806B03D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B03D4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806B03D8: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806B03DC: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806B03E0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806B03E4: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x806B03E8: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x806B03EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806B03F0: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x806B03F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B03F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806B03FC: jr          $ra
    // 0x806B0400: nop

    return;
    // 0x806B0400: nop

;}
RECOMP_FUNC void func_806CED40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CED40: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806CED44: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806CED48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CED4C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806CED50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806CED54: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806CED58: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806CED5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CED60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806CED64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806CED68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806CED6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806CED70: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806CED74: lui         $t1, 0x806D
    ctx->r9 = S32(RELOC_HI16(604, 0X3B3C) << 16);
    // 0x806CED78: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806CED7C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806CED80: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806CED84: lw          $t1, -0xDA4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(604, 0X3B3C));
    // 0x806CED88: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806CED8C: jal         0x80048378
    // 0x806CED90: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x806CED90: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    after_0:
    // 0x806CED94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CED98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CED9C: jr          $ra
    // 0x806CEDA0: nop

    return;
    // 0x806CEDA0: nop

    // 0x806CEDA4: nop

    // 0x806CEDA8: nop

    // 0x806CEDAC: nop

;}
RECOMP_FUNC void func_80682F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682F24: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682F28: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682F2C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682F30: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682F34: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682F38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682F3C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682F40: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682F44: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682F48: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682F4C: jr          $ra
    // 0x80682F50: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682F50: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80044E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044E38: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80044E3C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80044E40: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80044E44: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80044E48: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044E4C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80044E50: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80044E54: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80044E58: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80044E5C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80044E60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80044E64: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80044E68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80044E6C: addiu       $a1, $a1, -0x7EA8
    ctx->r5 = ADD32(ctx->r5, -0X7EA8);
    // 0x80044E70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80044E74: jal         0x80058110
    // 0x80044E78: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_80058110(rdram, ctx);
        goto after_0;
    // 0x80044E78: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_0:
    // 0x80044E7C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80044E80: addiu       $t6, $t6, 0x55C
    ctx->r14 = ADD32(ctx->r14, 0X55C);
    // 0x80044E84: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044E88: sw          $t6, 0x10($s7)
    MEM_W(0X10, ctx->r23) = ctx->r14;
    // 0x80044E8C: addiu       $a1, $a1, -0x7D18
    ctx->r5 = ADD32(ctx->r5, -0X7D18);
    // 0x80044E90: addiu       $a0, $s7, 0x1C
    ctx->r4 = ADD32(ctx->r23, 0X1C);
    // 0x80044E94: jal         0x80058110
    // 0x80044E98: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_80058110(rdram, ctx);
        goto after_1;
    // 0x80044E98: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_1:
    // 0x80044E9C: lui         $fp, 0x800F
    ctx->r30 = S32(0X800F << 16);
    // 0x80044EA0: addiu       $fp, $fp, 0x7EA0
    ctx->r30 = ADD32(ctx->r30, 0X7EA0);
    // 0x80044EA4: lw          $t7, 0x3EC($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X3EC);
    // 0x80044EA8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80044EAC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80044EB0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80044EB4: addu        $t9, $fp, $t8
    ctx->r25 = ADD32(ctx->r30, ctx->r24);
    // 0x80044EB8: addiu       $t0, $t9, 0x974
    ctx->r8 = ADD32(ctx->r25, 0X974);
    // 0x80044EBC: jal         0x80047058
    // 0x80044EC0: sw          $t0, 0x970($fp)
    MEM_W(0X970, ctx->r30) = ctx->r8;
    func_80047058(rdram, ctx);
        goto after_2;
    // 0x80044EC0: sw          $t0, 0x970($fp)
    MEM_W(0X970, ctx->r30) = ctx->r8;
    after_2:
    // 0x80044EC4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80044EC8: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80044ECC: sw          $v0, 0x30($s7)
    MEM_W(0X30, ctx->r23) = ctx->r2;
    // 0x80044ED0: addiu       $s6, $s6, -0x7160
    ctx->r22 = ADD32(ctx->r22, -0X7160);
    // 0x80044ED4: addiu       $s4, $s4, -0x7AC0
    ctx->r20 = ADD32(ctx->r20, -0X7AC0);
    // 0x80044ED8: or          $s5, $s7, $zero
    ctx->r21 = ctx->r23 | 0;
    // 0x80044EDC: addiu       $s3, $zero, 0x960
    ctx->r19 = ADD32(0, 0X960);
L_80044EE0:
    // 0x80044EE0: addiu       $s0, $s5, 0xAC
    ctx->r16 = ADD32(ctx->r21, 0XAC);
    // 0x80044EE4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80044EE8: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_80044EEC:
    // 0x80044EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80044EF0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80044EF4: jal         0x80058110
    // 0x80044EF8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_80058110(rdram, ctx);
        goto after_3;
    // 0x80044EF8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_3:
    // 0x80044EFC: addiu       $s1, $s1, 0x258
    ctx->r17 = ADD32(ctx->r17, 0X258);
    // 0x80044F00: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80044F04: bne         $s1, $s3, L_80044EEC
    if (ctx->r17 != ctx->r19) {
        // 0x80044F08: addiu       $s2, $s2, 0x258
        ctx->r18 = ADD32(ctx->r18, 0X258);
            goto L_80044EEC;
    }
    // 0x80044F08: addiu       $s2, $s2, 0x258
    ctx->r18 = ADD32(ctx->r18, 0X258);
    // 0x80044F0C: addiu       $s4, $s4, 0x960
    ctx->r20 = ADD32(ctx->r20, 0X960);
    // 0x80044F10: bne         $s4, $s6, L_80044EE0
    if (ctx->r20 != ctx->r22) {
        // 0x80044F14: addiu       $s5, $s5, 0x50
        ctx->r21 = ADD32(ctx->r21, 0X50);
            goto L_80044EE0;
    }
    // 0x80044F14: addiu       $s5, $s5, 0x50
    ctx->r21 = ADD32(ctx->r21, 0X50);
    // 0x80044F18: jal         0x80044CA0
    // 0x80044F1C: nop

    func_80044CA0(rdram, ctx);
        goto after_4;
    // 0x80044F1C: nop

    after_4:
    // 0x80044F20: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044F24: addiu       $a1, $a1, -0x7160
    ctx->r5 = ADD32(ctx->r5, -0X7160);
    // 0x80044F28: addiu       $a0, $s7, 0x34
    ctx->r4 = ADD32(ctx->r23, 0X34);
    // 0x80044F2C: jal         0x80058110
    // 0x80044F30: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_80058110(rdram, ctx);
        goto after_5;
    // 0x80044F30: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_5:
    // 0x80044F34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044F38: addiu       $a1, $a1, -0x6F08
    ctx->r5 = ADD32(ctx->r5, -0X6F08);
    // 0x80044F3C: addiu       $a0, $s7, 0x48
    ctx->r4 = ADD32(ctx->r23, 0X48);
    // 0x80044F40: jal         0x80058110
    // 0x80044F44: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_80058110(rdram, ctx);
        goto after_6;
    // 0x80044F44: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_6:
    // 0x80044F48: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044F4C: addiu       $a1, $a1, -0x6CB0
    ctx->r5 = ADD32(ctx->r5, -0X6CB0);
    // 0x80044F50: addiu       $a0, $s7, 0x5C
    ctx->r4 = ADD32(ctx->r23, 0X5C);
    // 0x80044F54: jal         0x80058110
    // 0x80044F58: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_80058110(rdram, ctx);
        goto after_7;
    // 0x80044F58: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_7:
    // 0x80044F5C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044F60: addiu       $a1, $a1, -0x6A58
    ctx->r5 = ADD32(ctx->r5, -0X6A58);
    // 0x80044F64: addiu       $a0, $s7, 0x70
    ctx->r4 = ADD32(ctx->r23, 0X70);
    // 0x80044F68: jal         0x80058110
    // 0x80044F6C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_80058110(rdram, ctx);
        goto after_8;
    // 0x80044F6C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_8:
    // 0x80044F70: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044F74: addiu       $a1, $a1, -0x6800
    ctx->r5 = ADD32(ctx->r5, -0X6800);
    // 0x80044F78: addiu       $a0, $s7, 0x88
    ctx->r4 = ADD32(ctx->r23, 0X88);
    // 0x80044F7C: jal         0x80058110
    // 0x80044F80: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    func_80058110(rdram, ctx);
        goto after_9;
    // 0x80044F80: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_9:
    // 0x80044F84: lw          $t1, 0x3EC($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X3EC);
    // 0x80044F88: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80044F8C: addiu       $a1, $a1, -0x65A8
    ctx->r5 = ADD32(ctx->r5, -0X65A8);
    // 0x80044F90: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80044F94: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80044F98: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80044F9C: addu        $t3, $fp, $t2
    ctx->r11 = ADD32(ctx->r30, ctx->r10);
    // 0x80044FA0: addiu       $t4, $t3, 0x9E0
    ctx->r12 = ADD32(ctx->r11, 0X9E0);
    // 0x80044FA4: sw          $t4, 0x9DC($fp)
    MEM_W(0X9DC, ctx->r30) = ctx->r12;
    // 0x80044FA8: addiu       $a0, $s7, 0xFC
    ctx->r4 = ADD32(ctx->r23, 0XFC);
    // 0x80044FAC: jal         0x80058110
    // 0x80044FB0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_80058110(rdram, ctx);
        goto after_10;
    // 0x80044FB0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_10:
    // 0x80044FB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80044FB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044FBC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80044FC0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80044FC4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80044FC8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80044FCC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80044FD0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80044FD4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80044FD8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80044FDC: jr          $ra
    // 0x80044FE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80044FE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80526C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526C98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80526C9C: jal         0x800653D8
    // 0x80526CA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80526CA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80526CA4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80526CA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80526CAC: beq         $t6, $zero, L_80526CC4
    if (ctx->r14 == 0) {
        // 0x80526CB0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80526CC4;
    }
    // 0x80526CB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80526CB4: jal         0x805271D4
    // 0x80526CB8: nop

    func_805271D4(rdram, ctx);
        goto after_1;
    // 0x80526CB8: nop

    after_1:
    // 0x80526CBC: b           L_80526CD0
    // 0x80526CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80526CD0;
    // 0x80526CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526CC4:
    // 0x80526CC4: jal         0x80526B0C
    // 0x80526CC8: nop

    func_80526B0C(rdram, ctx);
        goto after_2;
    // 0x80526CC8: nop

    after_2:
    // 0x80526CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526CD0:
    // 0x80526CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526CD4: jr          $ra
    // 0x80526CD8: nop

    return;
    // 0x80526CD8: nop

;}
RECOMP_FUNC void func_80569310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80569310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80569314: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80569318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8056931C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80569320: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80569324: lui         $t8, 0x8057
    ctx->r24 = S32(RELOC_HI16(378, 0X1FE0) << 16);
    // 0x80569328: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8056932C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80569330: lw          $t8, -0x6A70($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(378, 0X1FE0));
    // 0x80569334: jal         0x805692A4
    // 0x80569338: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    func_805692A4(rdram, ctx);
        goto after_0;
    // 0x80569338: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    after_0:
    // 0x8056933C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80569340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80569344: jr          $ra
    // 0x80569348: nop

    return;
    // 0x80569348: nop

;}
RECOMP_FUNC void func_8078B3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B3E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8078B3EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8078B3F0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8078B3F4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8078B3F8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8078B3FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8078B400: jal         0x8078B4F0
    // 0x8078B404: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8078B4F0(rdram, ctx);
        goto after_0;
    // 0x8078B404: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8078B408: beq         $v0, $zero, L_8078B4CC
    if (ctx->r2 == 0) {
        // 0x8078B40C: lui         $at, 0x41A8
        ctx->r1 = S32(0X41A8 << 16);
            goto L_8078B4CC;
    }
    // 0x8078B40C: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x8078B410: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078B414: lw          $t8, 0x16C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X16C);
    // 0x8078B418: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8078B41C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8078B420: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(796, 0X1B04) << 16);
    // 0x8078B424: sw          $t6, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->r14;
    // 0x8078B428: sb          $zero, 0x165($s2)
    MEM_B(0X165, ctx->r18) = 0;
    // 0x8078B42C: addiu       $t7, $t7, -0x336C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(796, 0X1B04));
    // 0x8078B430: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
    // 0x8078B434: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8078B438: sw          $zero, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = 0;
    // 0x8078B43C: sw          $zero, 0x138($s2)
    MEM_W(0X138, ctx->r18) = 0;
    // 0x8078B440: jal         0x8078B528
    // 0x8078B444: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8078B528(rdram, ctx);
        goto after_1;
    // 0x8078B444: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8078B448: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8078B44C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8078B450: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B44) << 16);
    // 0x8078B454: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8078B458: swc1        $f6, 0xE0($s2)
    MEM_W(0XE0, ctx->r18) = ctx->f6.u32l;
    // 0x8078B45C: lwc1        $f8, -0x332C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B44));
    // 0x8078B460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078B464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8078B468: lw          $a3, 0x138($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X138);
    // 0x8078B46C: jal         0x8078B840
    // 0x8078B470: swc1        $f8, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f8.u32l;
    func_8078B840(rdram, ctx);
        goto after_2;
    // 0x8078B470: swc1        $f8, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f8.u32l;
    after_2:
    // 0x8078B474: jal         0x8078B1C8
    // 0x8078B478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8078B1C8(rdram, ctx);
        goto after_3;
    // 0x8078B478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8078B47C: lw          $s1, 0x1F4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X1F4);
    // 0x8078B480: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8078B484: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x8078B488: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
L_8078B48C:
    // 0x8078B48C: jal         0x8078C7E0
    // 0x8078B490: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8078C7E0(rdram, ctx);
        goto after_4;
    // 0x8078B490: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8078B494: bne         $v0, $zero, L_8078B4AC
    if (ctx->r2 != 0) {
        // 0x8078B498: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8078B4AC;
    }
    // 0x8078B498: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8078B49C: jal         0x800445A4
    // 0x8078B4A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x8078B4A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x8078B4A4: b           L_8078B4D8
    // 0x8078B4A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8078B4D8;
    // 0x8078B4A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8078B4AC:
    // 0x8078B4AC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8078B4B0: bne         $s0, $s3, L_8078B48C
    if (ctx->r16 != ctx->r19) {
        // 0x8078B4B4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8078B48C;
    }
    // 0x8078B4B4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8078B4B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8078B4BC: jal         0x8078B1E0
    // 0x8078B4C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8078B1E0(rdram, ctx);
        goto after_6;
    // 0x8078B4C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8078B4C4: b           L_8078B4D8
    // 0x8078B4C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8078B4D8;
    // 0x8078B4C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8078B4CC:
    // 0x8078B4CC: jal         0x800445A4
    // 0x8078B4D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x8078B4D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8078B4D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8078B4D8:
    // 0x8078B4D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8078B4DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8078B4E0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8078B4E4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8078B4E8: jr          $ra
    // 0x8078B4EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8078B4EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8066B918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066B91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B920: jal         0x8066B7C0
    // 0x8066B924: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066B7C0(rdram, ctx);
        goto after_0;
    // 0x8066B924: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066B928: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066B92C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B930: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8066B934: jal         0x8066B970
    // 0x8066B938: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8066B970(rdram, ctx);
        goto after_1;
    // 0x8066B938: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8066B93C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066B940: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8066B944: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8066B948: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B94C: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8066B950: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8066B954: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8066B958: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8066B95C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8066B960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066B964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066B968: jr          $ra
    // 0x8066B96C: nop

    return;
    // 0x8066B96C: nop

;}
RECOMP_FUNC void func_80709278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070927C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80709280: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80709284: addiu       $at, $zero, 0x4019
    ctx->r1 = ADD32(0, 0X4019);
    // 0x80709288: beq         $v0, $at, L_807092A0
    if (ctx->r2 == ctx->r1) {
        // 0x8070928C: addiu       $at, $zero, 0x401A
        ctx->r1 = ADD32(0, 0X401A);
            goto L_807092A0;
    }
    // 0x8070928C: addiu       $at, $zero, 0x401A
    ctx->r1 = ADD32(0, 0X401A);
    // 0x80709290: beq         $v0, $at, L_807092B0
    if (ctx->r2 == ctx->r1) {
        // 0x80709294: nop
    
            goto L_807092B0;
    }
    // 0x80709294: nop

    // 0x80709298: b           L_807092BC
    // 0x8070929C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807092BC;
    // 0x8070929C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807092A0:
    // 0x807092A0: jal         0x807092C8
    // 0x807092A4: nop

    func_807092C8(rdram, ctx);
        goto after_0;
    // 0x807092A4: nop

    after_0:
    // 0x807092A8: b           L_807092BC
    // 0x807092AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807092BC;
    // 0x807092AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807092B0:
    // 0x807092B0: jal         0x807094B4
    // 0x807092B4: nop

    func_807094B4(rdram, ctx);
        goto after_1;
    // 0x807092B4: nop

    after_1:
    // 0x807092B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807092BC:
    // 0x807092BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807092C0: jr          $ra
    // 0x807092C4: nop

    return;
    // 0x807092C4: nop

;}
RECOMP_FUNC void func_800342C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800342C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800342C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800342C8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x800342CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800342D0: lbu         $v0, 0xF6($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XF6);
    // 0x800342D4: beq         $v0, $zero, L_800342EC
    if (ctx->r2 == 0) {
        // 0x800342D8: nop
    
            goto L_800342EC;
    }
    // 0x800342D8: nop

    // 0x800342DC: beq         $v0, $at, L_800342FC
    if (ctx->r2 == ctx->r1) {
        // 0x800342E0: nop
    
            goto L_800342FC;
    }
    // 0x800342E0: nop

    // 0x800342E4: b           L_8003430C
    // 0x800342E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003430C;
    // 0x800342E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800342EC:
    // 0x800342EC: jal         0x8003420C
    // 0x800342F0: nop

    func_8003420C(rdram, ctx);
        goto after_0;
    // 0x800342F0: nop

    after_0:
    // 0x800342F4: b           L_80034310
    // 0x800342F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80034310;
    // 0x800342F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800342FC:
    // 0x800342FC: jal         0x80034174
    // 0x80034300: nop

    func_80034174(rdram, ctx);
        goto after_1;
    // 0x80034300: nop

    after_1:
    // 0x80034304: b           L_80034310
    // 0x80034308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80034310;
    // 0x80034308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003430C:
    // 0x8003430C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80034310:
    // 0x80034310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034314: jr          $ra
    // 0x80034318: nop

    return;
    // 0x80034318: nop

;}
RECOMP_FUNC void func_806D0568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0568: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D056C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D0570: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D0574: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D0578: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D057C: jal         0x806D03E8
    // 0x806D0580: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_806D03E8(rdram, ctx);
        goto after_0;
    // 0x806D0580: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D0584: jal         0x806D0408
    // 0x806D0588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D0408(rdram, ctx);
        goto after_1;
    // 0x806D0588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D058C: lw          $t7, 0x12C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X12C);
    // 0x806D0590: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806D0594: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x806D0598: bnel        $t7, $zero, L_806D061C
    if (ctx->r15 != 0) {
        // 0x806D059C: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_806D061C;
    }
    goto skip_0;
    // 0x806D059C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x806D05A0: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x806D05A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806D05A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806D05AC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D05B0: nop

    // 0x806D05B4: bc1fl       L_806D068C
    if (!c1cs) {
        // 0x806D05B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D068C;
    }
    goto skip_1;
    // 0x806D05B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806D05BC: jal         0x806CF7E0
    // 0x806D05C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_806CF7E0(rdram, ctx);
        goto after_2;
    // 0x806D05C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x806D05C4: beq         $v0, $zero, L_806D05F4
    if (ctx->r2 == 0) {
        // 0x806D05C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D05F4;
    }
    // 0x806D05C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D05CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D05D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D05D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806D05D8: jal         0x806D093C
    // 0x806D05DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D093C(rdram, ctx);
        goto after_3;
    // 0x806D05DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x806D05E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D05E4: jal         0x806CFE48
    // 0x806D05E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806CFE48(rdram, ctx);
        goto after_4;
    // 0x806D05E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x806D05EC: b           L_806D068C
    // 0x806D05F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D068C;
    // 0x806D05F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D05F4:
    // 0x806D05F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D05F8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806D05FC: jal         0x806D093C
    // 0x806D0600: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D093C(rdram, ctx);
        goto after_5;
    // 0x806D0600: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x806D0604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0608: jal         0x806D02A4
    // 0x806D060C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806D02A4(rdram, ctx);
        goto after_6;
    // 0x806D060C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x806D0610: b           L_806D068C
    // 0x806D0614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D068C;
    // 0x806D0614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D0618: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_806D061C:
    // 0x806D061C: lwc1        $f10, 0x1C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x806D0620: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806D0624: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806D0628: nop

    // 0x806D062C: bc1fl       L_806D068C
    if (!c1cs) {
        // 0x806D0630: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D068C;
    }
    goto skip_2;
    // 0x806D0630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806D0634: jal         0x806CF7E0
    // 0x806D0638: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_806CF7E0(rdram, ctx);
        goto after_7;
    // 0x806D0638: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x806D063C: beq         $v0, $zero, L_806D066C
    if (ctx->r2 == 0) {
        // 0x806D0640: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D066C;
    }
    // 0x806D0640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D064C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806D0650: jal         0x806D093C
    // 0x806D0654: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806D093C(rdram, ctx);
        goto after_8;
    // 0x806D0654: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x806D0658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D065C: jal         0x806CFE48
    // 0x806D0660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806CFE48(rdram, ctx);
        goto after_9;
    // 0x806D0660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x806D0664: b           L_806D068C
    // 0x806D0668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D068C;
    // 0x806D0668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D066C:
    // 0x806D066C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0670: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806D0674: jal         0x806D093C
    // 0x806D0678: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806D093C(rdram, ctx);
        goto after_10;
    // 0x806D0678: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x806D067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0680: jal         0x806D02A4
    // 0x806D0684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806D02A4(rdram, ctx);
        goto after_11;
    // 0x806D0684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x806D0688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D068C:
    // 0x806D068C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D0690: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D0694: jr          $ra
    // 0x806D0698: nop

    return;
    // 0x806D0698: nop

;}
RECOMP_FUNC void func_805663A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805663A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805663A4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805663A8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805663AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805663B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805663B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805663B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805663BC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805663C0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805663C4: lui         $t1, 0x8056
    ctx->r9 = S32(RELOC_HI16(372, 0X468) << 16);
    // 0x805663C8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805663CC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805663D0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805663D4: lw          $t1, 0x64C8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(372, 0X468));
    // 0x805663D8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805663DC: jal         0x80048378
    // 0x805663E0: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x805663E0: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    after_0:
    // 0x805663E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805663E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805663EC: jr          $ra
    // 0x805663F0: nop

    return;
    // 0x805663F0: nop

    // 0x805663F4: nop

    // 0x805663F8: nop

    // 0x805663FC: nop

;}
RECOMP_FUNC void func_80682D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682D44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682D48: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682D4C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682D50: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682D54: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682D58: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682D5C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682D60: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682D64: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682D68: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682D6C: jr          $ra
    // 0x80682D70: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682D70: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80032984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003298C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80032990: lw          $a0, 0x164($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X164);
    // 0x80032994: jal         0x800447C8
    // 0x80032998: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80032998: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003299C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800329A0: sw          $zero, 0x164($a1)
    MEM_W(0X164, ctx->r5) = 0;
    // 0x800329A4: sb          $zero, 0x155($a1)
    MEM_B(0X155, ctx->r5) = 0;
    // 0x800329A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800329AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800329B0: jr          $ra
    // 0x800329B4: nop

    return;
    // 0x800329B4: nop

;}
RECOMP_FUNC void func_806DB538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB53C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB540: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806DB544: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806DB548: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806DB54C: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(634, 0X620) << 16);
    // 0x806DB550: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x806DB554: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806DB558: addiu       $t7, $t7, -0x4520
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(634, 0X620));
    // 0x806DB55C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806DB560: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806DB564: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x806DB568: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DB56C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806DB570: jal         0x806DB928
    // 0x806DB574: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806DB928(rdram, ctx);
        goto after_0;
    // 0x806DB574: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x806DB578: jal         0x806DB520
    // 0x806DB57C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806DB520(rdram, ctx);
        goto after_1;
    // 0x806DB57C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806DB580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DB588: jr          $ra
    // 0x806DB58C: nop

    return;
    // 0x806DB58C: nop

;}
RECOMP_FUNC void func_80670A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80670A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80670A60: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80670A64: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(523, 0XA0) << 16);
    // 0x80670A68: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80670A6C: addiu       $t6, $t6, 0xAE0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(523, 0XA0));
    // 0x80670A70: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80670A74: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80670A78: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80670A7C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80670A80: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80670A84: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x80670A88: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x80670A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80670A90: jal         0x80670AA8
    // 0x80670A94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80670AA8(rdram, ctx);
        goto after_0;
    // 0x80670A94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80670A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80670A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80670AA0: jr          $ra
    // 0x80670AA4: nop

    return;
    // 0x80670AA4: nop

;}
RECOMP_FUNC void func_806DB590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB598: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806DB59C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806DB5A0: beq         $t6, $zero, L_806DB5DC
    if (ctx->r14 == 0) {
        // 0x806DB5A4: nop
    
            goto L_806DB5DC;
    }
    // 0x806DB5A4: nop

    // 0x806DB5A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DB5AC: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806DB5B0: jalr        $t9
    // 0x806DB5B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806DB5B4: nop

    after_0:
    // 0x806DB5B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806DB5BC: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806DB5C0: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806DB5C4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806DB5C8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806DB5CC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806DB5D0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806DB5D4: b           L_806DB5DC
    // 0x806DB5D8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806DB5DC;
    // 0x806DB5D8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806DB5DC:
    // 0x806DB5DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB5E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DB5E4: jr          $ra
    // 0x806DB5E8: nop

    return;
    // 0x806DB5E8: nop

;}
RECOMP_FUNC void func_804D1528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D1528: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804D152C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804D1530: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804D1534: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x804D1538: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x804D153C: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x804D1540: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x804D1544: lui         $t9, 0x804D
    ctx->r25 = S32(RELOC_HI16(246, 0X3A8) << 16);
    // 0x804D1548: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804D154C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804D1550: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804D1554: lw          $t9, 0x1678($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(246, 0X3A8));
    // 0x804D1558: jr          $ra
    // 0x804D155C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    return;
    // 0x804D155C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80051348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051348: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005134C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80051350: sw          $zero, -0x57D0($at)
    MEM_W(-0X57D0, ctx->r1) = 0;
    // 0x80051354: addiu       $v0, $v0, -0x57CC
    ctx->r2 = ADD32(ctx->r2, -0X57CC);
    // 0x80051358: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8005135C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051360: jr          $ra
    // 0x80051364: sw          $a0, -0x57C8($at)
    MEM_W(-0X57C8, ctx->r1) = ctx->r4;
    return;
    // 0x80051364: sw          $a0, -0x57C8($at)
    MEM_W(-0X57C8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80793618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80793618: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x8079361C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80793620: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80793624: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80793628: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(817, 0X3140) << 16);
    // 0x8079362C: addiu       $t7, $t7, 0x3490
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(817, 0X3140));
    // 0x80793630: sw          $t7, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r15;
    // 0x80793634: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x80793638: lui         $t0, 0x8079
    ctx->r8 = S32(RELOC_HI16(817, 0X3290) << 16);
    // 0x8079363C: addiu       $t0, $t0, 0x35E0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(817, 0X3290));
    // 0x80793640: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80793644: jr          $ra
    // 0x80793648: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    return;
    // 0x80793648: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
;}
RECOMP_FUNC void func_8040DC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040DC38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040DC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040DC40: jal         0x8040C758
    // 0x8040DC44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8040C758(rdram, ctx);
        goto after_0;
    // 0x8040DC44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040DC48: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8040DC4C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8040DC50: lw          $t7, 0xE94($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XE94);
    // 0x8040DC54: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8040DC58: addiu       $t6, $zero, 0x4034
    ctx->r14 = ADD32(0, 0X4034);
    // 0x8040DC5C: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8040DC60: lw          $t8, 0xE94($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE94);
    // 0x8040DC64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8040DC68: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8040DC6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040DC70: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x8040DC74: lw          $t9, 0xE94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE94);
    // 0x8040DC78: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8040DC7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040DC80: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x8040DC84: lwc1        $f8, 0x3C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x8040DC88: lw          $t0, 0xE94($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE94);
    // 0x8040DC8C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8040DC90: lwc1        $f10, 0x40($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X40);
    // 0x8040DC94: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8040DC98: lwc1        $f16, 0x44($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X44);
    // 0x8040DC9C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8040DCA0: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x8040DCA4: jalr        $t9
    // 0x8040DCA8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8040DCA8: nop

    after_1:
    // 0x8040DCAC: jal         0x8040DB88
    // 0x8040DCB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8040DB88(rdram, ctx);
        goto after_2;
    // 0x8040DCB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8040DCB4: jal         0x80067E68
    // 0x8040DCB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x8040DCB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8040DCBC: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8040DCC0: jal         0x80067818
    // 0x8040DCC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8040DCC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8040DCC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040DCCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040DCD0: jr          $ra
    // 0x8040DCD4: nop

    return;
    // 0x8040DCD4: nop

;}
RECOMP_FUNC void func_804BAB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BAB70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804BAB74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BAB78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BAB7C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x804BAB80: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(188, 0XB10) << 16);
    // 0x804BAB84: addiu       $t8, $t8, -0x4990
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(188, 0XB10));
    // 0x804BAB88: lw          $t7, 0x88($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X88);
    // 0x804BAB8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BAB90: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x804BAB94: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x804BAB98: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804BAB9C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804BABA0: jal         0x804BAC7C
    // 0x804BABA4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_804BAC7C(rdram, ctx);
        goto after_0;
    // 0x804BABA4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_0:
    // 0x804BABA8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x804BABAC: sw          $zero, 0x60($v0)
    MEM_W(0X60, ctx->r2) = 0;
    // 0x804BABB0: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x804BABB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x804BABB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BABBC: jal         0x8004590C
    // 0x804BABC0: addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x804BABC0: addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    after_1:
    // 0x804BABC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BABC8: jal         0x80045A34
    // 0x804BABCC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x804BABCC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x804BABD0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804BABD4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804BABD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BABDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BABE0: jal         0x804BB4C4
    // 0x804BABE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804BB4C4(rdram, ctx);
        goto after_3;
    // 0x804BABE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x804BABE8: jal         0x804BAC0C
    // 0x804BABEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BAC0C(rdram, ctx);
        goto after_4;
    // 0x804BABEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804BABF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BABF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804BABF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804BABFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BAC00: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804BAC04: jr          $ra
    // 0x804BAC08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804BAC08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006872C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006872C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80068730: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068734: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068738: jal         0x800682D4
    // 0x8006873C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800682D4(rdram, ctx);
        goto after_0;
    // 0x8006873C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80068740: jal         0x80052290
    // 0x80068744: addiu       $a0, $s0, 0xAA0
    ctx->r4 = ADD32(ctx->r16, 0XAA0);
    func_80052290(rdram, ctx);
        goto after_1;
    // 0x80068744: addiu       $a0, $s0, 0xAA0
    ctx->r4 = ADD32(ctx->r16, 0XAA0);
    after_1:
    // 0x80068748: lw          $a0, 0x478($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X478);
    // 0x8006874C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068750: jal         0x8005A994
    // 0x80068754: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8005A994(rdram, ctx);
        goto after_2;
    // 0x80068754: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80068758: jal         0x80045250
    // 0x8006875C: nop

    func_80045250(rdram, ctx);
        goto after_3;
    // 0x8006875C: nop

    after_3:
    // 0x80068760: jal         0x800581AC
    // 0x80068764: addiu       $a0, $s0, 0xA68
    ctx->r4 = ADD32(ctx->r16, 0XA68);
    func_800581AC(rdram, ctx);
        goto after_4;
    // 0x80068764: addiu       $a0, $s0, 0xA68
    ctx->r4 = ADD32(ctx->r16, 0XA68);
    after_4:
    // 0x80068768: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    // 0x8006876C: jal         0x8004404C
    // 0x80068770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004404C(rdram, ctx);
        goto after_5;
    // 0x80068770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80068774: jal         0x8005D160
    // 0x80068778: addiu       $a0, $s0, 0x8D0
    ctx->r4 = ADD32(ctx->r16, 0X8D0);
    func_8005D160(rdram, ctx);
        goto after_6;
    // 0x80068778: addiu       $a0, $s0, 0x8D0
    ctx->r4 = ADD32(ctx->r16, 0X8D0);
    after_6:
    // 0x8006877C: jal         0x80046560
    // 0x80068780: nop

    func_80046560(rdram, ctx);
        goto after_7;
    // 0x80068780: nop

    after_7:
    // 0x80068784: jal         0x80051BE8
    // 0x80068788: lw          $a0, 0x634($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X634);
    func_80051BE8(rdram, ctx);
        goto after_8;
    // 0x80068788: lw          $a0, 0x634($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X634);
    after_8:
    // 0x8006878C: addiu       $a0, $s0, 0x478
    ctx->r4 = ADD32(ctx->r16, 0X478);
    // 0x80068790: addiu       $a1, $zero, 0x104
    ctx->r5 = ADD32(0, 0X104);
    // 0x80068794: jal         0x80065728
    // 0x80068798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_9;
    // 0x80068798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8006879C: jal         0x8006D6B4
    // 0x800687A0: addiu       $a0, $s0, 0x57C
    ctx->r4 = ADD32(ctx->r16, 0X57C);
    func_8006D6B4(rdram, ctx);
        goto after_10;
    // 0x800687A0: addiu       $a0, $s0, 0x57C
    ctx->r4 = ADD32(ctx->r16, 0X57C);
    after_10:
    // 0x800687A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800687A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800687AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800687B0: jr          $ra
    // 0x800687B4: nop

    return;
    // 0x800687B4: nop

;}
RECOMP_FUNC void func_8043311C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043311C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80433120: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80433124: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80433128: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8043312C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80433130: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80433134: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80433138: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8043313C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80433140: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80433144: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80433148: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8043314C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80433150: jal         0x8004700C
    // 0x80433154: lh          $s4, 0x184($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X184);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80433154: lh          $s4, 0x184($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X184);
    after_0:
    // 0x80433158: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8043315C: jal         0x80432E28
    // 0x80433160: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80432E28(rdram, ctx);
        goto after_1;
    // 0x80433160: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x80433164: beql        $s0, $zero, L_804333E4
    if (ctx->r16 == 0) {
        // 0x80433168: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_804333E4;
    }
    goto skip_0;
    // 0x80433168: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8043316C: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x80433170: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80433174: beql        $t6, $at, L_804333E4
    if (ctx->r14 == ctx->r1) {
        // 0x80433178: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_804333E4;
    }
    goto skip_1;
    // 0x80433178: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x8043317C: lwc1        $f4, 0x50($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X50);
    // 0x80433180: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80433184: sll         $s2, $zero, 2
    ctx->r18 = S32(0 << 2);
    // 0x80433188: addu        $s3, $s5, $s2
    ctx->r19 = ADD32(ctx->r21, ctx->r18);
    // 0x8043318C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80433190: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(65, 0X950) << 16);
    // 0x80433194: blez        $s4, L_80433318
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80433198: swc1        $f8, 0x50($s5)
        MEM_W(0X50, ctx->r21) = ctx->f8.u32l;
            goto L_80433318;
    }
    // 0x80433198: swc1        $f8, 0x50($s5)
    MEM_W(0X50, ctx->r21) = ctx->f8.u32l;
    // 0x8043319C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x804331A0: lwc1        $f22, 0x3730($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X950));
    // 0x804331A4: lw          $s0, 0x188($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X188);
L_804331A8:
    // 0x804331A8: beql        $s0, $zero, L_80433304
    if (ctx->r16 == 0) {
        // 0x804331AC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80433304;
    }
    goto skip_2;
    // 0x804331AC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_2:
    // 0x804331B0: lw          $v1, 0x174($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X174);
    // 0x804331B4: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x804331B8: beql        $v1, $zero, L_80433304
    if (ctx->r3 == 0) {
        // 0x804331BC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80433304;
    }
    goto skip_3;
    // 0x804331BC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_3:
    // 0x804331C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x804331C4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x804331C8: beql        $v0, $zero, L_80433304
    if (ctx->r2 == 0) {
        // 0x804331CC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80433304;
    }
    goto skip_4;
    // 0x804331CC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_4:
    // 0x804331D0: beql        $v0, $at, L_80433304
    if (ctx->r2 == ctx->r1) {
        // 0x804331D4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80433304;
    }
    goto skip_5;
    // 0x804331D4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_5:
    // 0x804331D8: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x804331DC: beql        $t7, $zero, L_80433304
    if (ctx->r15 == 0) {
        // 0x804331E0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80433304;
    }
    goto skip_6;
    // 0x804331E0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_6:
    // 0x804331E4: lh          $t8, 0x13E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X13E);
    // 0x804331E8: lh          $t9, 0x13C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X13C);
    // 0x804331EC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(65, 0X954) << 16);
    // 0x804331F0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x804331F4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x804331F8: lwc1        $f8, 0x3734($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X954));
    // 0x804331FC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80433200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80433204: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80433208: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8043320C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80433210: nop

    // 0x80433214: mul.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80433218: jal         0x80432FC0
    // 0x8043321C: nop

    func_80432FC0(rdram, ctx);
        goto after_2;
    // 0x8043321C: nop

    after_2:
    // 0x80433220: bne         $v0, $zero, L_8043327C
    if (ctx->r2 != 0) {
        // 0x80433224: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8043327C;
    }
    // 0x80433224: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80433228: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043322C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80433230: addiu       $at, $zero, 0x40B4
    ctx->r1 = ADD32(0, 0X40B4);
    // 0x80433234: mul.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80433238: bne         $v0, $at, L_80433250
    if (ctx->r2 != ctx->r1) {
        // 0x8043323C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80433250;
    }
    // 0x8043323C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80433240: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80433244: nop

    // 0x80433248: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8043324C: nop

L_80433250:
    // 0x80433250: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80433254: bnel        $v0, $at, L_80433280
    if (ctx->r2 != ctx->r1) {
        // 0x80433258: lwc1        $f4, 0x14($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
            goto L_80433280;
    }
    goto skip_7;
    // 0x80433258: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    skip_7:
    // 0x8043325C: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
    // 0x80433260: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80433264: bne         $t0, $at, L_8043327C
    if (ctx->r8 != ctx->r1) {
        // 0x80433268: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8043327C;
    }
    // 0x80433268: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8043326C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80433270: nop

    // 0x80433274: mul.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80433278: nop

L_8043327C:
    // 0x8043327C: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
L_80433280:
    // 0x80433280: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80433284: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80433288: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8043328C: nop

    // 0x80433290: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80433294: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80433298: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x8043329C: jal         0x80066DE4
    // 0x804332A0: lwc1        $f12, 0x50($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x804332A0: lwc1        $f12, 0x50($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X50);
    after_3:
    // 0x804332A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804332A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804332AC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(65, 0X958) << 16);
    // 0x804332B0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804332B4: nop

    // 0x804332B8: bc1f        L_804332D4
    if (!c1cs) {
        // 0x804332BC: nop
    
            goto L_804332D4;
    }
    // 0x804332BC: nop

    // 0x804332C0: sub.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x804332C4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x804332C8: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x804332CC: b           L_80433300
    // 0x804332D0: swc1        $f6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f6.u32l;
        goto L_80433300;
    // 0x804332D0: swc1        $f6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f6.u32l;
L_804332D4:
    // 0x804332D4: lwc1        $f8, 0x3738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X958));
    // 0x804332D8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x804332DC: nop

    // 0x804332E0: bc1fl       L_80433300
    if (!c1cs) {
        // 0x804332E4: swc1        $f24, 0x10C($s0)
        MEM_W(0X10C, ctx->r16) = ctx->f24.u32l;
            goto L_80433300;
    }
    goto skip_8;
    // 0x804332E4: swc1        $f24, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f24.u32l;
    skip_8:
    // 0x804332E8: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804332EC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x804332F0: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x804332F4: b           L_80433300
    // 0x804332F8: swc1        $f18, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f18.u32l;
        goto L_80433300;
    // 0x804332F8: swc1        $f18, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f18.u32l;
    // 0x804332FC: swc1        $f24, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f24.u32l;
L_80433300:
    // 0x80433300: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80433304:
    // 0x80433304: slti        $at, $s2, 0x50
    ctx->r1 = SIGNED(ctx->r18) < 0X50 ? 1 : 0;
    // 0x80433308: beq         $at, $zero, L_80433318
    if (ctx->r1 == 0) {
        // 0x8043330C: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80433318;
    }
    // 0x8043330C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80433310: bgtzl       $s4, L_804331A8
    if (SIGNED(ctx->r20) > 0) {
        // 0x80433314: lw          $s0, 0x188($s3)
        ctx->r16 = MEM_W(ctx->r19, 0X188);
            goto L_804331A8;
    }
    goto skip_9;
    // 0x80433314: lw          $s0, 0x188($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X188);
    skip_9:
L_80433318:
    // 0x80433318: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8043331C: jal         0x80433024
    // 0x80433320: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80433024(rdram, ctx);
        goto after_4;
    // 0x80433320: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x80433324: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80433328: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8043332C: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80433330: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x80433334: lwc1        $f16, 0x50($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X50);
    // 0x80433338: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8043333C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80433340: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80433344: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x80433348: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8043334C: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80433350: jal         0x804330F4
    // 0x80433354: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    func_804330F4(rdram, ctx);
        goto after_5;
    // 0x80433354: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    after_5:
    // 0x80433358: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8043335C: lwc1        $f16, 0x50($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X50);
    // 0x80433360: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80433364: nop

    // 0x80433368: bc1fl       L_8043339C
    if (!c1cs) {
        // 0x8043336C: lwc1        $f2, 0x8($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
            goto L_8043339C;
    }
    goto skip_10;
    // 0x8043336C: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    skip_10:
    // 0x80433370: swc1        $f2, 0x50($s5)
    MEM_W(0X50, ctx->r21) = ctx->f2.u32l;
    // 0x80433374: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80433378: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(65, 0X95C) << 16);
    // 0x8043337C: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80433380: nop

    // 0x80433384: bc1fl       L_8043339C
    if (!c1cs) {
        // 0x80433388: lwc1        $f2, 0x8($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
            goto L_8043339C;
    }
    goto skip_11;
    // 0x80433388: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    skip_11:
    // 0x8043338C: lwc1        $f4, 0x373C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X95C));
    // 0x80433390: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80433394: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x80433398: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
L_8043339C:
    // 0x8043339C: lwc1        $f8, 0x50($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X50);
    // 0x804333A0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x804333A4: nop

    // 0x804333A8: bc1f        L_804333D8
    if (!c1cs) {
        // 0x804333AC: nop
    
            goto L_804333D8;
    }
    // 0x804333AC: nop

    // 0x804333B0: swc1        $f2, 0x50($s5)
    MEM_W(0X50, ctx->r21) = ctx->f2.u32l;
    // 0x804333B4: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x804333B8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(65, 0X960) << 16);
    // 0x804333BC: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x804333C0: nop

    // 0x804333C4: bc1f        L_804333D8
    if (!c1cs) {
        // 0x804333C8: nop
    
            goto L_804333D8;
    }
    // 0x804333C8: nop

    // 0x804333CC: lwc1        $f18, 0x3740($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X960));
    // 0x804333D0: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x804333D4: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_804333D8:
    // 0x804333D8: jal         0x80432EA0
    // 0x804333DC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80432EA0(rdram, ctx);
        goto after_6;
    // 0x804333DC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x804333E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_804333E4:
    // 0x804333E4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804333E8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804333EC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804333F0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x804333F4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x804333F8: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x804333FC: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80433400: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80433404: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80433408: jr          $ra
    // 0x8043340C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8043340C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_804215C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804215C8: jr          $ra
    // 0x804215CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804215CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80066468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006646C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066470: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066474: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80066478: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006647C: jal         0x800663F4
    // 0x80066480: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800663F4(rdram, ctx);
        goto after_0;
    // 0x80066480: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80066484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80066488: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006648C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80066490: jal         0x80066428
    // 0x80066494: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80066428(rdram, ctx);
        goto after_1;
    // 0x80066494: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80066498: jal         0x80066448
    // 0x8006649C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80066448(rdram, ctx);
        goto after_2;
    // 0x8006649C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800664A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800664A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800664A8: jr          $ra
    // 0x800664AC: nop

    return;
    // 0x800664AC: nop

;}
