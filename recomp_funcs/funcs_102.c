#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80564E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80564E18: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80564E1C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80564E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80564E24: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80564E28: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // 0x80564E2C: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2590) << 16);
    // 0x80564E30: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80564E34: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80564E38: bc1t        L_80564EBC
    if (c1cs) {
        // 0x80564E3C: swc1        $f6, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
            goto L_80564EBC;
    }
    // 0x80564E3C: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x80564E40: lwc1        $f12, 0x5DF0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2590));
    // 0x80564E44: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80564E48: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80564E4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80564E50: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80564E54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80564E58: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80564E5C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80564E60: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80564E64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80564E68: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80564E6C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80564E70: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80564E74: nop

    // 0x80564E78: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80564E7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80564E80: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80564E84: nop

    // 0x80564E88: bc1f        L_80564EBC
    if (!c1cs) {
        // 0x80564E8C: nop
    
            goto L_80564EBC;
    }
    // 0x80564E8C: nop

    // 0x80564E90: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x80564E94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80564E98: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x80564E9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80564EA0: jalr        $t9
    // 0x80564EA4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80564EA4: nop

    after_0:
    // 0x80564EA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80564EAC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80564EB0: nop

    // 0x80564EB4: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
    // 0x80564EB8: swc1        $f14, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f14.u32l;
L_80564EBC:
    // 0x80564EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80564EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80564EC4: jr          $ra
    // 0x80564EC8: nop

    return;
    // 0x80564EC8: nop

;}
RECOMP_FUNC void func_80449288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449288: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044928C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449290: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449298: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044929C: bne         $a2, $zero, L_804492C4
    if (ctx->r6 != 0) {
        // 0x804492A0: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804492C4;
    }
    // 0x804492A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804492A4: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x804492A8: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x804492AC: bgtz        $t7, L_80449304
    if (SIGNED(ctx->r15) > 0) {
        // 0x804492B0: sw          $t7, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->r15;
            goto L_80449304;
    }
    // 0x804492B0: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x804492B4: jal         0x8044692C
    // 0x804492B8: nop

    func_8044692C(rdram, ctx);
        goto after_0;
    // 0x804492B8: nop

    after_0:
    // 0x804492BC: b           L_80449308
    // 0x804492C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449308;
    // 0x804492C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804492C4:
    // 0x804492C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804492C8: bnel        $a2, $at, L_804492F4
    if (ctx->r6 != ctx->r1) {
        // 0x804492CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804492F4;
    }
    goto skip_0;
    // 0x804492CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x804492D0: jal         0x804468D4
    // 0x804492D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804468D4(rdram, ctx);
        goto after_1;
    // 0x804492D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804492D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804492DC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804492E0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x804492E4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804492E8: b           L_80449304
    // 0x804492EC: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449304;
    // 0x804492EC: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x804492F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804492F4:
    // 0x804492F4: bnel        $a2, $at, L_80449308
    if (ctx->r6 != ctx->r1) {
        // 0x804492F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449308;
    }
    goto skip_1;
    // 0x804492F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804492FC: jal         0x8044692C
    // 0x80449300: nop

    func_8044692C(rdram, ctx);
        goto after_2;
    // 0x80449300: nop

    after_2:
L_80449304:
    // 0x80449304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449308:
    // 0x80449308: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044930C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449310: jr          $ra
    // 0x80449314: nop

    return;
    // 0x80449314: nop

;}
RECOMP_FUNC void func_8002B088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B088: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8002B08C: slti        $at, $v0, 0x45BD
    ctx->r1 = SIGNED(ctx->r2) < 0X45BD ? 1 : 0;
    // 0x8002B090: bne         $at, $zero, L_8002B0B0
    if (ctx->r1 != 0) {
        // 0x8002B094: addiu       $at, $zero, 0x45BF
        ctx->r1 = ADD32(0, 0X45BF);
            goto L_8002B0B0;
    }
    // 0x8002B094: addiu       $at, $zero, 0x45BF
    ctx->r1 = ADD32(0, 0X45BF);
    // 0x8002B098: beq         $v0, $at, L_8002B110
    if (ctx->r2 == ctx->r1) {
        // 0x8002B09C: addiu       $at, $zero, 0x45F3
        ctx->r1 = ADD32(0, 0X45F3);
            goto L_8002B110;
    }
    // 0x8002B09C: addiu       $at, $zero, 0x45F3
    ctx->r1 = ADD32(0, 0X45F3);
    // 0x8002B0A0: beq         $v0, $at, L_8002B110
    if (ctx->r2 == ctx->r1) {
        // 0x8002B0A4: nop
    
            goto L_8002B110;
    }
    // 0x8002B0A4: nop

    // 0x8002B0A8: b           L_8002B11C
    // 0x8002B0AC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8002B11C;
    // 0x8002B0AC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8002B0B0:
    // 0x8002B0B0: slti        $at, $v0, 0x4035
    ctx->r1 = SIGNED(ctx->r2) < 0X4035 ? 1 : 0;
    // 0x8002B0B4: bne         $at, $zero, L_8002B0D0
    if (ctx->r1 != 0) {
        // 0x8002B0B8: addiu       $t6, $v0, -0x4030
        ctx->r14 = ADD32(ctx->r2, -0X4030);
            goto L_8002B0D0;
    }
    // 0x8002B0B8: addiu       $t6, $v0, -0x4030
    ctx->r14 = ADD32(ctx->r2, -0X4030);
    // 0x8002B0BC: addiu       $at, $zero, 0x45BC
    ctx->r1 = ADD32(0, 0X45BC);
    // 0x8002B0C0: beq         $v0, $at, L_8002B110
    if (ctx->r2 == ctx->r1) {
        // 0x8002B0C4: nop
    
            goto L_8002B110;
    }
    // 0x8002B0C4: nop

    // 0x8002B0C8: b           L_8002B11C
    // 0x8002B0CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8002B11C;
    // 0x8002B0CC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8002B0D0:
    // 0x8002B0D0: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8002B0D4: beq         $at, $zero, L_8002B118
    if (ctx->r1 == 0) {
        // 0x8002B0D8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8002B118;
    }
    // 0x8002B0D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B0DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B0E0: addu        $at, $at, $t6
    gpr jr_addend_8002B0E8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002B0E4: lw          $t6, -0x190($at)
    ctx->r14 = ADD32(ctx->r1, -0X190);
    // 0x8002B0E8: jr          $t6
    // 0x8002B0EC: nop

    switch (jr_addend_8002B0E8 >> 2) {
        case 0: goto L_8002B0F0; break;
        case 1: goto L_8002B0F8; break;
        case 2: goto L_8002B100; break;
        case 3: goto L_8002B108; break;
        case 4: goto L_8002B110; break;
        default: switch_error(__func__, 0x8002B0E8, 0x800AFE70);
    }
    // 0x8002B0EC: nop

L_8002B0F0:
    // 0x8002B0F0: jr          $ra
    // 0x8002B0F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002B0F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B0F8:
    // 0x8002B0F8: jr          $ra
    // 0x8002B0FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8002B0FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002B100:
    // 0x8002B100: jr          $ra
    // 0x8002B104: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8002B104: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8002B108:
    // 0x8002B108: jr          $ra
    // 0x8002B10C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x8002B10C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8002B110:
    // 0x8002B110: jr          $ra
    // 0x8002B114: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x8002B114: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8002B118:
    // 0x8002B118: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8002B11C:
    // 0x8002B11C: jr          $ra
    // 0x8002B120: nop

    return;
    // 0x8002B120: nop

;}
RECOMP_FUNC void func_800677CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800677CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800677D0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800677D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800677D8: bltz        $a0, L_800677E8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800677DC: slti        $at, $a0, 0xA
        ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_800677E8;
    }
    // 0x800677DC: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x800677E0: bne         $at, $zero, L_800677F0
    if (ctx->r1 != 0) {
        // 0x800677E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800677F0;
    }
    // 0x800677E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800677E8:
    // 0x800677E8: jr          $ra
    // 0x800677EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800677EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800677F0:
    // 0x800677F0: jr          $ra
    // 0x800677F4: nop

    return;
    // 0x800677F4: nop

;}
RECOMP_FUNC void func_8066AD88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066AD88: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8066AD8C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8066AD90: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x8066AD94: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x8066AD98: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8066AD9C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8066ADA0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8066ADA4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8066ADA8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8066ADAC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8066ADB0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8066ADB4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8066ADB8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8066ADBC: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8066ADC0: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(514, 0X25A0) << 16);
    // 0x8066ADC4: addiu       $t9, $t9, -0x2E00
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(514, 0X25A0));
    // 0x8066ADC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8066ADCC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8066ADD0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8066ADD4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8066ADD8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8066ADDC: lw          $s7, 0x1F4($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066ADE0: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
    // 0x8066ADE4: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8066ADE8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8066ADEC: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8066ADF0: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8066ADF4: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x8066ADF8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8066ADFC: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8066AE00: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8066AE04: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x8066AE08: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8066AE0C: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x8066AE10: lwc1        $f22, 0x6C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8066AE14: jal         0x80049018
    // 0x8066AE18: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8066AE18: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x8066AE1C: beq         $v0, $zero, L_8066AE3C
    if (ctx->r2 == 0) {
        // 0x8066AE20: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_8066AE3C;
    }
    // 0x8066AE20: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8066AE24: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8066AE28: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8066AE2C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8066AE30: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x8066AE34: b           L_8066AE50
    // 0x8066AE38: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
        goto L_8066AE50;
    // 0x8066AE38: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_8066AE3C:
    // 0x8066AE3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8066AE40: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8066AE44: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8066AE48: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x8066AE4C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_8066AE50:
    // 0x8066AE50: lui         $s3, 0x8067
    ctx->r19 = S32(RELOC_HI16(514, 0X1020) << 16);
    // 0x8066AE54: addiu       $s3, $s3, -0x4380
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(514, 0X1020));
    // 0x8066AE58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8066AE5C: addiu       $s6, $zero, 0x78
    ctx->r22 = ADD32(0, 0X78);
    // 0x8066AE60: addiu       $s5, $sp, 0x78
    ctx->r21 = ADD32(ctx->r29, 0X78);
    // 0x8066AE64: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x8066AE68: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
L_8066AE6C:
    // 0x8066AE6C: lw          $t7, 0xC($s7)
    ctx->r15 = MEM_W(ctx->r23, 0XC);
    // 0x8066AE70: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8066AE74: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8066AE78: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8066AE7C: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8066AE80: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x8066AE84: multu       $t6, $s4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8066AE88: mflo        $t0
    ctx->r8 = lo;
    // 0x8066AE8C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8066AE90: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8066AE94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8066AE98: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8066AE9C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8066AEA0: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8066AEA4: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8066AEA8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8066AEAC: sw          $t4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r12;
    // 0x8066AEB0: lw          $t7, 0x8($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X8);
    // 0x8066AEB4: sw          $t7, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r15;
    // 0x8066AEB8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8066AEBC: sw          $t4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r12;
    // 0x8066AEC0: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x8066AEC4: beq         $a0, $zero, L_8066AF50
    if (ctx->r4 == 0) {
        // 0x8066AEC8: sw          $t7, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r15;
            goto L_8066AF50;
    }
    // 0x8066AEC8: sw          $t7, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r15;
    // 0x8066AECC: lh          $t5, 0x5C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X5C);
    // 0x8066AED0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8066AED4: nop

    // 0x8066AED8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8066AEDC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8066AEE0: nop

    // 0x8066AEE4: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8066AEE8: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8066AEEC: lh          $t8, 0x5E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5E);
    // 0x8066AEF0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8066AEF4: nop

    // 0x8066AEF8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8066AEFC: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8066AF00: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x8066AF04: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8066AF08: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8066AF0C: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x8066AF10: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8066AF14: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8066AF18: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x8066AF1C: lh          $t9, 0x68($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X68);
    // 0x8066AF20: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8066AF24: nop

    // 0x8066AF28: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8066AF2C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8066AF30: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x8066AF34: lh          $t6, 0x6C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6C);
    // 0x8066AF38: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8066AF3C: lbu         $t0, 0x6A($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6A);
    // 0x8066AF40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8066AF44: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x8066AF48: jal         0x8066ACCC
    // 0x8066AF4C: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    func_8066ACCC(rdram, ctx);
        goto after_1;
    // 0x8066AF4C: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    after_1:
L_8066AF50:
    // 0x8066AF50: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8066AF54: bne         $s0, $s6, L_8066AE6C
    if (ctx->r16 != ctx->r22) {
        // 0x8066AF58: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8066AE6C;
    }
    // 0x8066AF58: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8066AF5C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8066AF60: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8066AF64: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8066AF68: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8066AF6C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8066AF70: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8066AF74: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8066AF78: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8066AF7C: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8066AF80: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8066AF84: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x8066AF88: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x8066AF8C: jr          $ra
    // 0x8066AF90: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8066AF90: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80470104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80470104: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80470108: lw          $v1, 0xF3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF3C);
    // 0x8047010C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80470110: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80470114: sw          $t6, 0xF3C($v0)
    MEM_W(0XF3C, ctx->r2) = ctx->r14;
    // 0x80470118: bne         $at, $zero, L_80470124
    if (ctx->r1 != 0) {
        // 0x8047011C: sw          $v1, 0xF38($v0)
        MEM_W(0XF38, ctx->r2) = ctx->r3;
            goto L_80470124;
    }
    // 0x8047011C: sw          $v1, 0xF38($v0)
    MEM_W(0XF38, ctx->r2) = ctx->r3;
    // 0x80470120: sw          $zero, 0xF3C($v0)
    MEM_W(0XF3C, ctx->r2) = 0;
L_80470124:
    // 0x80470124: jr          $ra
    // 0x80470128: nop

    return;
    // 0x80470128: nop

;}
RECOMP_FUNC void func_80032B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032B58: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032B5C: lbu         $t6, 0x155($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X155);
    // 0x80032B60: beql        $t6, $zero, L_80032B94
    if (ctx->r14 == 0) {
        // 0x80032B64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032B94;
    }
    goto skip_0;
    // 0x80032B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80032B68: lh          $t8, 0x152($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X152);
    // 0x80032B6C: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80032B70: lh          $t7, 0x144($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X144);
    // 0x80032B74: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80032B78: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80032B7C: lh          $t0, -0x16F8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X16F8);
    // 0x80032B80: bnel        $t7, $t0, L_80032B94
    if (ctx->r15 != ctx->r8) {
        // 0x80032B84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032B94;
    }
    goto skip_1;
    // 0x80032B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80032B88: jal         0x80032A8C
    // 0x80032B8C: nop

    func_80032A8C(rdram, ctx);
        goto after_0;
    // 0x80032B8C: nop

    after_0:
    // 0x80032B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032B94:
    // 0x80032B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032B98: jr          $ra
    // 0x80032B9C: nop

    return;
    // 0x80032B9C: nop

;}
RECOMP_FUNC void func_8076D574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D574: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8076D578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076D57C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8076D580: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8076D584: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076D588: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8076D58C: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8076D590: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x8076D594: jal         0x8076C860
    // 0x8076D598: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    func_8076C860(rdram, ctx);
        goto after_0;
    // 0x8076D598: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x8076D59C: lui         $a1, 0x8077
    ctx->r5 = S32(RELOC_HI16(766, 0X34C8) << 16);
    // 0x8076D5A0: addiu       $a1, $a1, -0x348
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(766, 0X34C8));
    // 0x8076D5A4: jal         0x8076D134
    // 0x8076D5A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8076D134(rdram, ctx);
        goto after_1;
    // 0x8076D5A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8076D5AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076D5B0: jal         0x8076CD88
    // 0x8076D5B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8076CD88(rdram, ctx);
        goto after_2;
    // 0x8076D5B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8076D5B8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8076D5BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8076D5C0: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X3970) << 16);
    // 0x8076D5C4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8076D5C8: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X3970));
    // 0x8076D5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076D5D0: bne         $t9, $at, L_8076D61C
    if (ctx->r25 != ctx->r1) {
        // 0x8076D5D4: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8076D61C;
    }
    // 0x8076D5D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8076D5D8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8076D5DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076D5E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076D5E4: sw          $t0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r8;
    // 0x8076D5E8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8076D5EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8076D5F0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    // 0x8076D5F4: jal         0x8076DD8C
    // 0x8076D5F8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_3;
    // 0x8076D5F8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x8076D5FC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8076D600: jal         0x80067BBC
    // 0x8076D604: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x8076D604: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8076D608: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x8076D60C: jal         0x80067818
    // 0x8076D610: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8076D610: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8076D614: b           L_8076D734
    // 0x8076D618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076D734;
    // 0x8076D618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076D61C:
    // 0x8076D61C: jal         0x8076CEFC
    // 0x8076D620: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_8076CEFC(rdram, ctx);
        goto after_6;
    // 0x8076D620: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x8076D624: beq         $v0, $zero, L_8076D6E8
    if (ctx->r2 == 0) {
        // 0x8076D628: lwc1        $f12, 0x34($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8076D6E8;
    }
    // 0x8076D628: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8076D62C: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8076D630: jal         0x80067114
    // 0x8076D634: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_80067114(rdram, ctx);
        goto after_7;
    // 0x8076D634: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_7:
    // 0x8076D638: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8076D63C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076D640: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8076D644: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8076D648: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8076D64C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8076D650: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8076D654: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8076D658: bne         $v1, $at, L_8076D6E8
    if (ctx->r3 != ctx->r1) {
        // 0x8076D65C: swc1        $f10, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
            goto L_8076D6E8;
    }
    // 0x8076D65C: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8076D660: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8076D664: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8076D668: jal         0x80065954
    // 0x8076D66C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    func_80065954(rdram, ctx);
        goto after_8;
    // 0x8076D66C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_8:
    // 0x8076D670: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8076D674: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8076D678: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8076D67C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8076D680: nop

    // 0x8076D684: bc1fl       L_8076D6EC
    if (!c1cs) {
        // 0x8076D688: addiu       $a0, $s0, 0x50
        ctx->r4 = ADD32(ctx->r16, 0X50);
            goto L_8076D6EC;
    }
    goto skip_0;
    // 0x8076D688: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x8076D68C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8076D690: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X38C0) << 16);
    // 0x8076D694: addiu       $v0, $v0, 0xB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X38C0));
    // 0x8076D698: bnel        $t3, $zero, L_8076D6EC
    if (ctx->r11 != 0) {
        // 0x8076D69C: addiu       $a0, $s0, 0x50
        ctx->r4 = ADD32(ctx->r16, 0X50);
            goto L_8076D6EC;
    }
    goto skip_1;
    // 0x8076D69C: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    skip_1:
    // 0x8076D6A0: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8076D6A4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8076D6A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076D6AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076D6B0: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
    // 0x8076D6B4: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8076D6B8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8076D6BC: sw          $t5, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r13;
    // 0x8076D6C0: jal         0x8076DD8C
    // 0x8076D6C4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_9;
    // 0x8076D6C4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_9:
    // 0x8076D6C8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8076D6CC: jal         0x80067BBC
    // 0x8076D6D0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_10;
    // 0x8076D6D0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_10:
    // 0x8076D6D4: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    // 0x8076D6D8: jal         0x80067818
    // 0x8076D6DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x8076D6DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x8076D6E0: b           L_8076D734
    // 0x8076D6E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076D734;
    // 0x8076D6E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076D6E8:
    // 0x8076D6E8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
L_8076D6EC:
    // 0x8076D6EC: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    // 0x8076D6F0: jal         0x80067170
    // 0x8076D6F4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_80067170(rdram, ctx);
        goto after_12;
    // 0x8076D6F4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_12:
    // 0x8076D6F8: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8076D6FC: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8076D700: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8076D704: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8076D708: jal         0x80066E88
    // 0x8076D70C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_13;
    // 0x8076D70C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x8076D710: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8076D714: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8076D718: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8076D71C: jal         0x80066DE4
    // 0x8076D720: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_14;
    // 0x8076D720: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    after_14:
    // 0x8076D724: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8076D728: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8076D72C: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    // 0x8076D730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076D734:
    // 0x8076D734: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8076D738: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8076D73C: jr          $ra
    // 0x8076D740: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8076D740: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8066A3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A3B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066A3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A3B8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066A3BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8066A3C0: jal         0x80669E80
    // 0x8066A3C4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80669E80(rdram, ctx);
        goto after_0;
    // 0x8066A3C4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066A3C8: jal         0x80669FA4
    // 0x8066A3CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80669FA4(rdram, ctx);
        goto after_1;
    // 0x8066A3CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8066A3D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066A3D4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8066A3D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A3DC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8066A3E0: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8066A3E4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8066A3E8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066A3EC: nop

    // 0x8066A3F0: bc1fl       L_8066A404
    if (!c1cs) {
        // 0x8066A3F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A404;
    }
    goto skip_0;
    // 0x8066A3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A3F8: jal         0x8066A790
    // 0x8066A3FC: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8066A790(rdram, ctx);
        goto after_2;
    // 0x8066A3FC: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x8066A400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A404:
    // 0x8066A404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066A408: jr          $ra
    // 0x8066A40C: nop

    return;
    // 0x8066A40C: nop

;}
RECOMP_FUNC void func_8066706C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066706C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80667070: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80667074: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80667078: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8066707C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80667080: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80667084: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80667088: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8066708C: lui         $t1, 0x8066
    ctx->r9 = S32(RELOC_HI16(504, 0X2D58) << 16);
    // 0x80667090: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80667094: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80667098: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8066709C: lw          $t1, 0x7A28($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(504, 0X2D58));
    // 0x806670A0: jr          $ra
    // 0x806670A4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806670A4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80533444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80533448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8053344C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80533450: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80533454: jal         0x80533878
    // 0x80533458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80533878(rdram, ctx);
        goto after_0;
    // 0x80533458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8053345C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80533460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80533464: jr          $ra
    // 0x80533468: nop

    return;
    // 0x80533468: nop

;}
RECOMP_FUNC void func_806EF0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF0C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EF0CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EF0D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EF0D4: jal         0x806EC16C
    // 0x806EF0D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EF0D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EF0DC: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EF0E0: jal         0x800577D8
    // 0x806EF0E4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EF0E4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EF0E8: jal         0x806EE5E4
    // 0x806EF0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE5E4(rdram, ctx);
        goto after_2;
    // 0x806EF0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EF0F0: jal         0x806EE664
    // 0x806EF0F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE664(rdram, ctx);
        goto after_3;
    // 0x806EF0F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EF0F8: jal         0x806EEED0
    // 0x806EF0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EEED0(rdram, ctx);
        goto after_4;
    // 0x806EF0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EF100: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806EF104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF10C: blez        $v0, L_806EF120
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806EF110: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_806EF120;
    }
    // 0x806EF110: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806EF114: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806EF118: b           L_806EF15C
    // 0x806EF11C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
        goto L_806EF15C;
    // 0x806EF11C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_806EF120:
    // 0x806EF120: jal         0x806EF4A0
    // 0x806EF124: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EF4A0(rdram, ctx);
        goto after_5;
    // 0x806EF124: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x806EF128: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x806EF12C: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x806EF130: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806EF134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF138: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x806EF13C: jal         0x806EE584
    // 0x806EF140: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_6;
    // 0x806EF140: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_6:
    // 0x806EF144: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806EF148: jal         0x80067BBC
    // 0x806EF14C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x806EF14C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_7:
    // 0x806EF150: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x806EF154: jal         0x80067818
    // 0x806EF158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x806EF158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
L_806EF15C:
    // 0x806EF15C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EF160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EF164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EF168: jr          $ra
    // 0x806EF16C: nop

    return;
    // 0x806EF16C: nop

;}
RECOMP_FUNC void func_80742BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742BE4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742BE8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742BEC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742BF0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742BF4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742BF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742BFC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742C00: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742C04: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742C08: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742C0C: jr          $ra
    // 0x80742C10: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742C10: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8003669C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003669C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800366A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800366A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800366A8: jal         0x80065954
    // 0x800366AC: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800366AC: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x800366B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800366B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800366B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800366BC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800366C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800366C4: jal         0x80041214
    // 0x800366C8: nop

    func_80041214(rdram, ctx);
        goto after_1;
    // 0x800366C8: nop

    after_1:
    // 0x800366CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800366D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800366D4: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x800366D8: lw          $t7, 0x14C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14C);
    // 0x800366DC: bnel        $t7, $at, L_800366F0
    if (ctx->r15 != ctx->r1) {
        // 0x800366E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800366F0;
    }
    goto skip_0;
    // 0x800366E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800366E4: jal         0x8002288C
    // 0x800366E8: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    func_8002288C(rdram, ctx);
        goto after_2;
    // 0x800366E8: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    after_2:
    // 0x800366EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800366F0:
    // 0x800366F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800366F4: jr          $ra
    // 0x800366F8: nop

    return;
    // 0x800366F8: nop

;}
RECOMP_FUNC void func_804469C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804469C0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804469C4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804469C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804469CC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x804469D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804469D4: sw          $t6, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = ctx->r14;
    // 0x804469D8: addiu       $v1, $zero, 0x744
    ctx->r3 = ADD32(0, 0X744);
    // 0x804469DC: addiu       $t7, $zero, 0x3C0
    ctx->r15 = ADD32(0, 0X3C0);
    // 0x804469E0: addiu       $t8, $zero, 0xAC8
    ctx->r24 = ADD32(0, 0XAC8);
    // 0x804469E4: sw          $t7, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r15;
    // 0x804469E8: sw          $v1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r3;
    // 0x804469EC: sw          $v1, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r3;
    // 0x804469F0: sw          $v1, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->r3;
    // 0x804469F4: jr          $ra
    // 0x804469F8: sw          $t8, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->r24;
    return;
    // 0x804469F8: sw          $t8, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_806E0004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E0004: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E0008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E000C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x806E0010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E0014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806E0018: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806E001C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806E0020: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806E0024: jal         0x80062AEC
    // 0x806E0028: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x806E0028: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x806E002C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806E0030: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x806E0034: beq         $v0, $at, L_806E0058
    if (ctx->r2 == ctx->r1) {
        // 0x806E0038: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_806E0058;
    }
    // 0x806E0038: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x806E003C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806E0040: beq         $v0, $at, L_806E00BC
    if (ctx->r2 == ctx->r1) {
        // 0x806E0044: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_806E00BC;
    }
    // 0x806E0044: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806E0048: beq         $v0, $at, L_806E0120
    if (ctx->r2 == ctx->r1) {
        // 0x806E004C: nop
    
            goto L_806E0120;
    }
    // 0x806E004C: nop

    // 0x806E0050: b           L_806E01B8
    // 0x806E0054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806E01B8;
    // 0x806E0054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E0058:
    // 0x806E0058: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11B8) << 16);
    // 0x806E005C: lwc1        $f4, 0x5E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11B8));
    // 0x806E0060: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806E0064: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806E0068: nop

    // 0x806E006C: bc1fl       L_806E00A8
    if (!c1cs) {
        // 0x806E0070: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806E00A8;
    }
    goto skip_0;
    // 0x806E0070: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x806E0074: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806E0078: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x806E007C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E0080: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E0084: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806E0088: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x806E008C: nop

    // 0x806E0090: bc1fl       L_806E00A8
    if (!c1cs) {
        // 0x806E0094: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806E00A8;
    }
    goto skip_1;
    // 0x806E0094: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x806E0098: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806E009C: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x806E00A0: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x806E00A4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806E00A8:
    // 0x806E00A8: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x806E00AC: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x806E00B0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x806E00B4: b           L_806E01B4
    // 0x806E00B8: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
        goto L_806E01B4;
    // 0x806E00B8: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
L_806E00BC:
    // 0x806E00BC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11BC) << 16);
    // 0x806E00C0: lwc1        $f8, 0x5EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11BC));
    // 0x806E00C4: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806E00C8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806E00CC: nop

    // 0x806E00D0: bc1fl       L_806E010C
    if (!c1cs) {
        // 0x806E00D4: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806E010C;
    }
    goto skip_2;
    // 0x806E00D4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_2:
    // 0x806E00D8: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x806E00DC: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806E00E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E00E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E00E8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806E00EC: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x806E00F0: nop

    // 0x806E00F4: bc1fl       L_806E010C
    if (!c1cs) {
        // 0x806E00F8: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806E010C;
    }
    goto skip_3;
    // 0x806E00F8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_3:
    // 0x806E00FC: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806E0100: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x806E0104: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x806E0108: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806E010C:
    // 0x806E010C: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x806E0110: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x806E0114: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x806E0118: b           L_806E01B4
    // 0x806E011C: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_806E01B4;
    // 0x806E011C: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_806E0120:
    // 0x806E0120: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11C0) << 16);
    // 0x806E0124: lwc1        $f8, 0x5F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11C0));
    // 0x806E0128: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806E012C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806E0130: nop

    // 0x806E0134: bc1fl       L_806E0178
    if (!c1cs) {
        // 0x806E0138: lwc1        $f18, 0x4($a2)
        ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
            goto L_806E0178;
    }
    goto skip_4;
    // 0x806E0138: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    skip_4:
    // 0x806E013C: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806E0140: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806E0144: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E0148: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E014C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806E0150: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806E0154: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11C4) << 16);
    // 0x806E0158: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x806E015C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806E0160: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x806E0164: lwc1        $f10, 0x5F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11C4));
    // 0x806E0168: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806E016C: b           L_806E01A4
    // 0x806E0170: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
        goto L_806E01A4;
    // 0x806E0170: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x806E0174: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
L_806E0178:
    // 0x806E0178: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806E017C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E0180: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E0184: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806E0188: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x806E018C: nop

    // 0x806E0190: bc1fl       L_806E01A8
    if (!c1cs) {
        // 0x806E0194: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806E01A8;
    }
    goto skip_5;
    // 0x806E0194: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_5:
    // 0x806E0198: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806E019C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x806E01A0: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
L_806E01A4:
    // 0x806E01A4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806E01A8:
    // 0x806E01A8: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x806E01AC: ori         $t1, $t0, 0x3000
    ctx->r9 = ctx->r8 | 0X3000;
    // 0x806E01B0: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
L_806E01B4:
    // 0x806E01B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E01B8:
    // 0x806E01B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E01BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E01C0: jr          $ra
    // 0x806E01C4: nop

    return;
    // 0x806E01C4: nop

;}
RECOMP_FUNC void func_8043E3C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E3C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043E3C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E3CC: jal         0x8004700C
    // 0x8043E3D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043E3D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043E3D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043E3D8: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8043E3DC: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8043E3E0: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8043E3E4: jal         0x80065ABC
    // 0x8043E3E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8043E3E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8043E3EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E3F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043E3F4: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(92, 0X1A00) << 16);
    // 0x8043E3F8: beq         $v1, $zero, L_8043E430
    if (ctx->r3 == 0) {
        // 0x8043E3FC: swc1        $f0, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
            goto L_8043E430;
    }
    // 0x8043E3FC: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8043E400: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8043E404: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8043E408: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8043E40C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8043E410: nop

    // 0x8043E414: bc1fl       L_8043E424
    if (!c1cs) {
        // 0x8043E418: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_8043E424;
    }
    goto skip_0;
    // 0x8043E418: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    skip_0:
    // 0x8043E41C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8043E420: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
L_8043E424:
    // 0x8043E424: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043E428: lw          $t8, -0x15C0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(92, 0X1A00));
    // 0x8043E42C: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
L_8043E430:
    // 0x8043E430: jal         0x8043DCF4
    // 0x8043E434: nop

    func_8043DCF4(rdram, ctx);
        goto after_2;
    // 0x8043E434: nop

    after_2:
    // 0x8043E438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E43C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043E440: jr          $ra
    // 0x8043E444: nop

    return;
    // 0x8043E444: nop

;}
RECOMP_FUNC void func_804CF8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF8D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CF8D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF8DC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804CF8E0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804CF8E4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804CF8E8: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(240, 0X1ACC) << 16);
    // 0x804CF8EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CF8F0: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804CF8F4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804CF8F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804CF8FC: lw          $t8, -0x284($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(240, 0X1ACC));
    // 0x804CF900: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804CF904: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804CF908: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CF90C: jal         0x80048490
    // 0x804CF910: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804CF910: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804CF914: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804CF918: jal         0x80048378
    // 0x804CF91C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804CF91C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804CF920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CF924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CF928: jr          $ra
    // 0x804CF92C: nop

    return;
    // 0x804CF92C: nop

;}
RECOMP_FUNC void func_80436870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436870: jr          $ra
    // 0x80436874: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80436874: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80436878: nop

    // 0x8043687C: nop

;}
RECOMP_FUNC void func_805A58AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A58AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805A58B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A58B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805A58B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805A58BC: lw          $t5, 0x1F4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A58C0: lh          $a2, 0x184($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X184);
    // 0x805A58C4: addiu       $a3, $a0, 0x188
    ctx->r7 = ADD32(ctx->r4, 0X188);
    // 0x805A58C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805A58CC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x805A58D0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x805A58D4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x805A58D8: jal         0x80062684
    // 0x805A58DC: sh          $a2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r6;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x805A58DC: sh          $a2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r6;
    after_0:
    // 0x805A58E0: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    // 0x805A58E4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x805A58E8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x805A58EC: beq         $a2, $zero, L_805A5C24
    if (ctx->r6 == 0) {
        // 0x805A58F0: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_805A5C24;
    }
    // 0x805A58F0: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x805A58F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805A58F8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805A58FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805A5900: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A5904: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x805A5908: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x805A590C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x805A5910: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x805A5914: addiu       $a1, $zero, 0x4001
    ctx->r5 = ADD32(0, 0X4001);
    // 0x805A5918: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_805A591C:
    // 0x805A591C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x805A5920: beq         $v0, $zero, L_805A5C1C
    if (ctx->r2 == 0) {
        // 0x805A5924: nop
    
            goto L_805A5C1C;
    }
    // 0x805A5924: nop

    // 0x805A5928: beq         $a0, $v0, L_805A5C14
    if (ctx->r4 == ctx->r2) {
        // 0x805A592C: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_805A5C14;
    }
    // 0x805A592C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x805A5930: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x805A5934: bnel        $a1, $t6, L_805A5C18
    if (ctx->r5 != ctx->r14) {
        // 0x805A5938: sll         $a2, $a2, 16
        ctx->r6 = S32(ctx->r6 << 16);
            goto L_805A5C18;
    }
    goto skip_0;
    // 0x805A5938: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    skip_0:
    // 0x805A593C: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805A5940: lwc1        $f6, 0x84($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X84);
    // 0x805A5944: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805A5948: lbu         $v1, 0x30($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X30);
    // 0x805A594C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805A5950: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x805A5954: nop

    // 0x805A5958: bc1fl       L_805A596C
    if (!c1cs) {
        // 0x805A595C: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_805A596C;
    }
    goto skip_1;
    // 0x805A595C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_1:
    // 0x805A5960: b           L_805A597C
    // 0x805A5964: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_805A597C;
    // 0x805A5964: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x805A5968: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_805A596C:
    // 0x805A596C: nop

    // 0x805A5970: bc1f        L_805A597C
    if (!c1cs) {
        // 0x805A5974: nop
    
            goto L_805A597C;
    }
    // 0x805A5974: nop

    // 0x805A5978: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_805A597C:
    // 0x805A597C: bne         $v1, $zero, L_805A59F8
    if (ctx->r3 != 0) {
        // 0x805A5980: div.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
            goto L_805A59F8;
    }
    // 0x805A5980: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x805A5984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A5988: jal         0x805A5628
    // 0x805A598C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_805A5628(rdram, ctx);
        goto after_1;
    // 0x805A598C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x805A5990: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x805A5994: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A5998: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805A599C: bne         $t4, $t7, L_805A59B4
    if (ctx->r12 != ctx->r15) {
        // 0x805A59A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A59B4;
    }
    // 0x805A59A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A59A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A59A8: lui         $a2, 0xC0E0
    ctx->r6 = S32(0XC0E0 << 16);
    // 0x805A59AC: jal         0x8002F96C
    // 0x805A59B0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8002F96C(rdram, ctx);
        goto after_2;
    // 0x805A59B0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_2:
L_805A59B4:
    // 0x805A59B4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x805A59B8: jal         0x80067BBC
    // 0x805A59BC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x805A59BC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_3:
    // 0x805A59C0: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    // 0x805A59C4: jal         0x80067818
    // 0x805A59C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x805A59C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x805A59CC: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x805A59D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A59D4: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x805A59D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A59DC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x805A59E0: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x805A59E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A59E8: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x805A59EC: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    // 0x805A59F0: b           L_805A5C28
    // 0x805A59F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805A5C28;
    // 0x805A59F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A59F8:
    // 0x805A59F8: bne         $t4, $v1, L_805A5A64
    if (ctx->r12 != ctx->r3) {
        // 0x805A59FC: nop
    
            goto L_805A5A64;
    }
    // 0x805A59FC: nop

    // 0x805A5A00: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x805A5A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A5A08: lui         $a2, 0xC0E0
    ctx->r6 = S32(0XC0E0 << 16);
    // 0x805A5A0C: bnel        $t4, $t7, L_805A5A24
    if (ctx->r12 != ctx->r15) {
        // 0x805A5A10: lw          $a0, 0x34($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X34);
            goto L_805A5A24;
    }
    goto skip_2;
    // 0x805A5A10: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    skip_2:
    // 0x805A5A14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A5A18: jal         0x8002F96C
    // 0x805A5A1C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8002F96C(rdram, ctx);
        goto after_5;
    // 0x805A5A1C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x805A5A20: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
L_805A5A24:
    // 0x805A5A24: jal         0x80067BBC
    // 0x805A5A28: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x805A5A28: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_6:
    // 0x805A5A2C: addiu       $a0, $zero, 0x22F
    ctx->r4 = ADD32(0, 0X22F);
    // 0x805A5A30: jal         0x80067818
    // 0x805A5A34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x805A5A34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x805A5A38: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x805A5A3C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A5A40: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x805A5A44: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A5A48: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x805A5A4C: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x805A5A50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A5A54: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x805A5A58: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    // 0x805A5A5C: b           L_805A5C28
    // 0x805A5A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805A5C28;
    // 0x805A5A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A5A64:
    // 0x805A5A64: beql        $t0, $v1, L_805A5C18
    if (ctx->r8 == ctx->r3) {
        // 0x805A5A68: sll         $a2, $a2, 16
        ctx->r6 = S32(ctx->r6 << 16);
            goto L_805A5C18;
    }
    goto skip_3;
    // 0x805A5A68: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    skip_3:
    // 0x805A5A6C: beql        $t1, $v1, L_805A5C18
    if (ctx->r9 == ctx->r3) {
        // 0x805A5A70: sll         $a2, $a2, 16
        ctx->r6 = S32(ctx->r6 << 16);
            goto L_805A5C18;
    }
    goto skip_4;
    // 0x805A5A70: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    skip_4:
    // 0x805A5A74: beql        $t2, $v1, L_805A5C18
    if (ctx->r10 == ctx->r3) {
        // 0x805A5A78: sll         $a2, $a2, 16
        ctx->r6 = S32(ctx->r6 << 16);
            goto L_805A5C18;
    }
    goto skip_5;
    // 0x805A5A78: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    skip_5:
    // 0x805A5A7C: beql        $t3, $v1, L_805A5C18
    if (ctx->r11 == ctx->r3) {
        // 0x805A5A80: sll         $a2, $a2, 16
        ctx->r6 = S32(ctx->r6 << 16);
            goto L_805A5C18;
    }
    goto skip_6;
    // 0x805A5A80: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    skip_6:
    // 0x805A5A84: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x805A5A88: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805A5A8C: lw          $a0, 0x27C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X27C);
    // 0x805A5A90: beq         $v0, $at, L_805A5AA0
    if (ctx->r2 == ctx->r1) {
        // 0x805A5A94: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_805A5AA0;
    }
    // 0x805A5A94: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x805A5A98: bnel        $v0, $at, L_805A5AAC
    if (ctx->r2 != ctx->r1) {
        // 0x805A5A9C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_805A5AAC;
    }
    goto skip_7;
    // 0x805A5A9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    skip_7:
L_805A5AA0:
    // 0x805A5AA0: b           L_805A5C28
    // 0x805A5AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805A5C28;
    // 0x805A5AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805A5AA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_805A5AAC:
    // 0x805A5AAC: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x805A5AB0: jal         0x805A585C
    // 0x805A5AB4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_805A585C(rdram, ctx);
        goto after_8;
    // 0x805A5AB4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x805A5AB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A5ABC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A5AC0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x805A5AC4: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805A5AC8: bne         $v0, $a0, L_805A5B28
    if (ctx->r2 != ctx->r4) {
        // 0x805A5ACC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_805A5B28;
    }
    // 0x805A5ACC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805A5AD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A5AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A5AD8: lui         $a2, 0xC0E0
    ctx->r6 = S32(0XC0E0 << 16);
    // 0x805A5ADC: jal         0x8002F96C
    // 0x805A5AE0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8002F96C(rdram, ctx);
        goto after_9;
    // 0x805A5AE0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_9:
    // 0x805A5AE4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x805A5AE8: jal         0x80067BBC
    // 0x805A5AEC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_10;
    // 0x805A5AEC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_10:
    // 0x805A5AF0: addiu       $a0, $zero, 0x22F
    ctx->r4 = ADD32(0, 0X22F);
    // 0x805A5AF4: jal         0x80067818
    // 0x805A5AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x805A5AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x805A5AFC: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x805A5B00: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A5B04: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x805A5B08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A5B0C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x805A5B10: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x805A5B14: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A5B18: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x805A5B1C: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x805A5B20: b           L_805A5C28
    // 0x805A5B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805A5C28;
    // 0x805A5B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A5B28:
    // 0x805A5B28: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x805A5B2C: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x805A5B30: lbu         $t6, 0xAF6($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XAF6);
    // 0x805A5B34: beql        $t6, $zero, L_805A5B50
    if (ctx->r14 == 0) {
        // 0x805A5B38: lw          $t8, 0x278($t5)
        ctx->r24 = MEM_W(ctx->r13, 0X278);
            goto L_805A5B50;
    }
    goto skip_8;
    // 0x805A5B38: lw          $t8, 0x278($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X278);
    skip_8:
    // 0x805A5B3C: lw          $t7, 0x278($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X278);
    // 0x805A5B40: bnel        $t7, $zero, L_805A5B50
    if (ctx->r15 != 0) {
        // 0x805A5B44: lw          $t8, 0x278($t5)
        ctx->r24 = MEM_W(ctx->r13, 0X278);
            goto L_805A5B50;
    }
    goto skip_9;
    // 0x805A5B44: lw          $t8, 0x278($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X278);
    skip_9:
    // 0x805A5B48: sw          $t4, 0x278($t5)
    MEM_W(0X278, ctx->r13) = ctx->r12;
    // 0x805A5B4C: lw          $t8, 0x278($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X278);
L_805A5B50:
    // 0x805A5B50: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A5B54: beq         $t8, $zero, L_805A5BBC
    if (ctx->r24 == 0) {
        // 0x805A5B58: nop
    
            goto L_805A5BBC;
    }
    // 0x805A5B58: nop

    // 0x805A5B5C: lbu         $t9, 0x18($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18);
    // 0x805A5B60: bne         $t4, $t9, L_805A5BBC
    if (ctx->r12 != ctx->r25) {
        // 0x805A5B64: nop
    
            goto L_805A5BBC;
    }
    // 0x805A5B64: nop

    // 0x805A5B68: lw          $t6, 0x12EC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X12EC);
    // 0x805A5B6C: bne         $t6, $zero, L_805A5BBC
    if (ctx->r14 != 0) {
        // 0x805A5B70: nop
    
            goto L_805A5BBC;
    }
    // 0x805A5B70: nop

    // 0x805A5B74: lbu         $t7, 0xF4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF4);
    // 0x805A5B78: bne         $t7, $zero, L_805A5BBC
    if (ctx->r15 != 0) {
        // 0x805A5B7C: nop
    
            goto L_805A5BBC;
    }
    // 0x805A5B7C: nop

    // 0x805A5B80: lbu         $t8, 0x154($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X154);
    // 0x805A5B84: bne         $t8, $zero, L_805A5BBC
    if (ctx->r24 != 0) {
        // 0x805A5B88: nop
    
            goto L_805A5BBC;
    }
    // 0x805A5B88: nop

    // 0x805A5B8C: lbu         $t9, 0x155($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X155);
    // 0x805A5B90: bne         $t9, $zero, L_805A5BBC
    if (ctx->r25 != 0) {
        // 0x805A5B94: nop
    
            goto L_805A5BBC;
    }
    // 0x805A5B94: nop

    // 0x805A5B98: lbu         $t6, 0x1F8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1F8);
    // 0x805A5B9C: bne         $t6, $zero, L_805A5BBC
    if (ctx->r14 != 0) {
        // 0x805A5BA0: nop
    
            goto L_805A5BBC;
    }
    // 0x805A5BA0: nop

    // 0x805A5BA4: lw          $t7, 0xB30($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XB30);
    // 0x805A5BA8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x805A5BAC: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x805A5BB0: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x805A5BB4: bne         $at, $zero, L_805A5BC4
    if (ctx->r1 != 0) {
        // 0x805A5BB8: sll         $t8, $t8, 3
        ctx->r24 = S32(ctx->r24 << 3);
            goto L_805A5BC4;
    }
    // 0x805A5BB8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
L_805A5BBC:
    // 0x805A5BBC: b           L_805A5C28
    // 0x805A5BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805A5C28;
    // 0x805A5BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A5BC4:
    // 0x805A5BC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A5BC8: lwc1        $f8, 0xC8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x805A5BCC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x805A5BD0: addiu       $t6, $t9, 0x5CC
    ctx->r14 = ADD32(ctx->r25, 0X5CC);
    // 0x805A5BD4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x805A5BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A5BDC: bc1fl       L_805A5BEC
    if (!c1cs) {
        // 0x805A5BE0: sw          $t6, 0x260($t5)
        MEM_W(0X260, ctx->r13) = ctx->r14;
            goto L_805A5BEC;
    }
    goto skip_10;
    // 0x805A5BE0: sw          $t6, 0x260($t5)
    MEM_W(0X260, ctx->r13) = ctx->r14;
    skip_10:
    // 0x805A5BE4: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
    // 0x805A5BE8: sw          $t6, 0x260($t5)
    MEM_W(0X260, ctx->r13) = ctx->r14;
L_805A5BEC:
    // 0x805A5BEC: jal         0x8002FF88
    // 0x805A5BF0: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    func_8002FF88(rdram, ctx);
        goto after_12;
    // 0x805A5BF0: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    after_12:
    // 0x805A5BF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A5BF8: jal         0x805A6730
    // 0x805A5BFC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_805A6730(rdram, ctx);
        goto after_13;
    // 0x805A5BFC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x805A5C00: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x805A5C04: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x805A5C08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805A5C0C: b           L_805A5C28
    // 0x805A5C10: swc1        $f10, 0x274($t5)
    MEM_W(0X274, ctx->r13) = ctx->f10.u32l;
        goto L_805A5C28;
    // 0x805A5C10: swc1        $f10, 0x274($t5)
    MEM_W(0X274, ctx->r13) = ctx->f10.u32l;
L_805A5C14:
    // 0x805A5C14: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
L_805A5C18:
    // 0x805A5C18: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_805A5C1C:
    // 0x805A5C1C: bne         $a2, $zero, L_805A591C
    if (ctx->r6 != 0) {
        // 0x805A5C20: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_805A591C;
    }
    // 0x805A5C20: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_805A5C24:
    // 0x805A5C24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A5C28:
    // 0x805A5C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A5C2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805A5C30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805A5C34: jr          $ra
    // 0x805A5C38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x805A5C38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800323A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800323A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800323A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800323AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800323B0: lw          $a3, 0x164($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X164);
    // 0x800323B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800323B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800323BC: beq         $a3, $zero, L_8003240C
    if (ctx->r7 == 0) {
        // 0x800323C0: nop
    
            goto L_8003240C;
    }
    // 0x800323C0: nop

    // 0x800323C4: lbu         $t6, 0x155($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X155);
    // 0x800323C8: bne         $t6, $zero, L_8003240C
    if (ctx->r14 != 0) {
        // 0x800323CC: nop
    
            goto L_8003240C;
    }
    // 0x800323CC: nop

    // 0x800323D0: lhu         $t7, 0xC($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0XC);
    // 0x800323D4: addiu       $at, $zero, 0x41DA
    ctx->r1 = ADD32(0, 0X41DA);
    // 0x800323D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800323DC: bne         $t7, $at, L_800323FC
    if (ctx->r15 != ctx->r1) {
        // 0x800323E0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800323FC;
    }
    // 0x800323E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800323E4: jal         0x80032284
    // 0x800323E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80032284(rdram, ctx);
        goto after_0;
    // 0x800323E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800323EC: jal         0x8002D5EC
    // 0x800323F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002D5EC(rdram, ctx);
        goto after_1;
    // 0x800323F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800323F4: b           L_8003240C
    // 0x800323F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003240C;
    // 0x800323F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800323FC:
    // 0x800323FC: jal         0x80032284
    // 0x80032400: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80032284(rdram, ctx);
        goto after_2;
    // 0x80032400: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80032404: b           L_8003240C
    // 0x80032408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003240C;
    // 0x80032408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003240C:
    // 0x8003240C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032414: jr          $ra
    // 0x80032418: nop

    return;
    // 0x80032418: nop

;}
RECOMP_FUNC void func_80432FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432FC0: lhu         $v1, 0x6C($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6C);
    // 0x80432FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80432FC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80432FCC: blezl       $v1, L_80432FFC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80432FD0: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80432FFC;
    }
    goto skip_0;
    // 0x80432FD0: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    skip_0:
L_80432FD4:
    // 0x80432FD4: lw          $t6, 0x1C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1C);
    // 0x80432FD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80432FDC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80432FE0: bne         $a1, $t6, L_80432FF0
    if (ctx->r5 != ctx->r14) {
        // 0x80432FE4: nop
    
            goto L_80432FF0;
    }
    // 0x80432FE4: nop

    // 0x80432FE8: jr          $ra
    // 0x80432FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80432FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80432FF0:
    // 0x80432FF0: bne         $at, $zero, L_80432FD4
    if (ctx->r1 != 0) {
        // 0x80432FF4: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80432FD4;
    }
    // 0x80432FF4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80432FF8: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
L_80432FFC:
    // 0x80432FFC: beq         $at, $zero, L_80433018
    if (ctx->r1 == 0) {
        // 0x80433000: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80433018;
    }
    // 0x80433000: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80433004: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80433008: sw          $a1, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r5;
    // 0x8043300C: lhu         $t9, 0x6C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6C);
    // 0x80433010: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80433014: sh          $t0, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r8;
L_80433018:
    // 0x80433018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8043301C: jr          $ra
    // 0x80433020: nop

    return;
    // 0x80433020: nop

;}
RECOMP_FUNC void func_80027FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027FC4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80027FC8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80027FCC: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80027FD0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80027FD4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80027FD8: lw          $t8, -0x24FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X24FC);
    // 0x80027FDC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80027FE0: lbu         $t2, 0x1F8($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1F8);
    // 0x80027FE4: sw          $t8, 0x9C($a2)
    MEM_W(0X9C, ctx->r6) = ctx->r24;
    // 0x80027FE8: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x80027FEC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80027FF0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80027FF4: lw          $t1, -0x23BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X23BC);
    // 0x80027FF8: bne         $t2, $zero, L_8002800C
    if (ctx->r10 != 0) {
        // 0x80027FFC: sw          $t1, 0xA0($a2)
        MEM_W(0XA0, ctx->r6) = ctx->r9;
            goto L_8002800C;
    }
    // 0x80027FFC: sw          $t1, 0xA0($a2)
    MEM_W(0XA0, ctx->r6) = ctx->r9;
    // 0x80028000: lw          $t3, 0x12EC($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X12EC);
    // 0x80028004: beql        $t3, $zero, L_8002801C
    if (ctx->r11 == 0) {
        // 0x80028008: lw          $t5, 0x9C($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X9C);
            goto L_8002801C;
    }
    goto skip_0;
    // 0x80028008: lw          $t5, 0x9C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X9C);
    skip_0:
L_8002800C:
    // 0x8002800C: lw          $t4, 0xA0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XA0);
    // 0x80028010: b           L_80028020
    // 0x80028014: sw          $t4, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r12;
        goto L_80028020;
    // 0x80028014: sw          $t4, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r12;
    // 0x80028018: lw          $t5, 0x9C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X9C);
L_8002801C:
    // 0x8002801C: sw          $t5, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r13;
L_80028020:
    // 0x80028020: jal         0x80027F00
    // 0x80028024: addiu       $a1, $a0, 0x14C
    ctx->r5 = ADD32(ctx->r4, 0X14C);
    func_80027F00(rdram, ctx);
        goto after_0;
    // 0x80028024: addiu       $a1, $a0, 0x14C
    ctx->r5 = ADD32(ctx->r4, 0X14C);
    after_0:
    // 0x80028028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002802C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028030: jr          $ra
    // 0x80028034: nop

    return;
    // 0x80028034: nop

;}
RECOMP_FUNC void func_80789F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789F84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80789F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80789F8C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80789F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80789F94: blez        $v0, L_80789FA4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80789F98: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80789FA4;
    }
    // 0x80789F98: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80789F9C: b           L_80789FAC
    // 0x80789FA0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_80789FAC;
    // 0x80789FA0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80789FA4:
    // 0x80789FA4: jal         0x8078A148
    // 0x80789FA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8078A148(rdram, ctx);
        goto after_0;
    // 0x80789FA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
L_80789FAC:
    // 0x80789FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80789FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80789FB4: jr          $ra
    // 0x80789FB8: nop

    return;
    // 0x80789FB8: nop

;}
RECOMP_FUNC void func_80441454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80441458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044145C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80441460: jal         0x8043F33C
    // 0x80441464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8043F33C(rdram, ctx);
        goto after_0;
    // 0x80441464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80441468: jal         0x8043FDF0
    // 0x8044146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FDF0(rdram, ctx);
        goto after_1;
    // 0x8044146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80441470: jal         0x8043F150
    // 0x80441474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_2;
    // 0x80441474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80441478: jal         0x8044045C
    // 0x8044147C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044045C(rdram, ctx);
        goto after_3;
    // 0x8044147C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80441480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441484: jal         0x8043EF80
    // 0x80441488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043EF80(rdram, ctx);
        goto after_4;
    // 0x80441488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8044148C: jal         0x8043F360
    // 0x80441490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F360(rdram, ctx);
        goto after_5;
    // 0x80441490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80441494: beq         $v0, $zero, L_804414AC
    if (ctx->r2 == 0) {
        // 0x80441498: nop
    
            goto L_804414AC;
    }
    // 0x80441498: nop

    // 0x8044149C: jal         0x804413E0
    // 0x804414A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804413E0(rdram, ctx);
        goto after_6;
    // 0x804414A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804414A4: b           L_804414B8
    // 0x804414A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804414B8;
    // 0x804414A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804414AC:
    // 0x804414AC: jal         0x8043F93C
    // 0x804414B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_7;
    // 0x804414B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804414B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804414B8:
    // 0x804414B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804414BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804414C0: jr          $ra
    // 0x804414C4: nop

    return;
    // 0x804414C4: nop

;}
RECOMP_FUNC void func_80048A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048A38: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x80048A3C: addiu       $a1, $zero, 0xBFA
    ctx->r5 = ADD32(0, 0XBFA);
    // 0x80048A40: bne         $t6, $zero, L_80048A5C
    if (ctx->r14 != 0) {
        // 0x80048A44: nop
    
            goto L_80048A5C;
    }
    // 0x80048A44: nop

    // 0x80048A48: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80048A4C: jal         0x80071380
    // 0x80048A50: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80048A50: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    after_0:
    // 0x80048A54: b           L_80048A78
    // 0x80048A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048A78;
    // 0x80048A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048A5C:
    // 0x80048A5C: jal         0x8004A028
    // 0x80048A60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004A028(rdram, ctx);
        goto after_1;
    // 0x80048A60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80048A64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80048A68: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    // 0x80048A6C: jalr        $t9
    // 0x80048A70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80048A70: nop

    after_2:
    // 0x80048A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048A78:
    // 0x80048A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048A7C: jr          $ra
    // 0x80048A80: nop

    return;
    // 0x80048A80: nop

;}
RECOMP_FUNC void func_8066DB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DB84: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066DB88: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(517, 0X1048) << 16);
    // 0x8066DB8C: addiu       $t8, $t8, -0x19F8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(517, 0X1048));
    // 0x8066DB90: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x8066DB94: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8066DB98: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8066DB9C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8066DBA0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8066DBA4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8066DBA8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8066DBAC: lw          $t3, 0x14($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X14);
    // 0x8066DBB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8066DBB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8066DBB8: xor         $t4, $t9, $t3
    ctx->r12 = ctx->r25 ^ ctx->r11;
    // 0x8066DBBC: sw          $t4, 0x138($t5)
    MEM_W(0X138, ctx->r13) = ctx->r12;
    // 0x8066DBC0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8066DBC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8066DBC8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8066DBCC: beql        $t6, $zero, L_8066DBE0
    if (ctx->r14 == 0) {
        // 0x8066DBD0: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_8066DBE0;
    }
    goto skip_0;
    // 0x8066DBD0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8066DBD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8066DBD8: nop

    // 0x8066DBDC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_8066DBE0:
    // 0x8066DBE0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8066DBE4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8066DBE8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8066DBEC: lui         $a3, 0x8067
    ctx->r7 = S32(RELOC_HI16(517, 0X27D0) << 16);
    // 0x8066DBF0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8066DBF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8066DBF8: addiu       $a3, $a3, -0x270
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(517, 0X27D0));
    // 0x8066DBFC: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8066DC00: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8066DC04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8066DC08: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8066DC0C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8066DC10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8066DC14: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8066DC18: swc1        $f8, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f8.u32l;
    // 0x8066DC1C: lw          $t9, -0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X14);
    // 0x8066DC20: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8066DC24: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8066DC28: nop

    // 0x8066DC2C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8066DC30: swc1        $f16, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f16.u32l;
    // 0x8066DC34: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8066DC38: lwc1        $f18, -0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8066DC3C: swc1        $f18, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f18.u32l;
    // 0x8066DC40: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8066DC44: lwc1        $f4, -0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8066DC48: swc1        $f4, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f4.u32l;
    // 0x8066DC4C: lwc1        $f6, -0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, -0X8);
    // 0x8066DC50: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8066DC54: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8066DC58: swc1        $f8, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f8.u32l;
L_8066DC5C:
    // 0x8066DC5C: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8066DC60: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x8066DC64: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8066DC68: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8066DC6C: xor         $t9, $t7, $t8
    ctx->r25 = ctx->r15 ^ ctx->r24;
    // 0x8066DC70: sw          $t9, 0x138($t3)
    MEM_W(0X138, ctx->r11) = ctx->r25;
    // 0x8066DC74: lw          $t4, 0x138($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X138);
    // 0x8066DC78: beql        $t4, $zero, L_8066DC88
    if (ctx->r12 == 0) {
        // 0x8066DC7C: lw          $t5, 0x0($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X0);
            goto L_8066DC88;
    }
    goto skip_1;
    // 0x8066DC7C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8066DC80: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8066DC84: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
L_8066DC88:
    // 0x8066DC88: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8066DC8C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8066DC90: nop

    // 0x8066DC94: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8066DC98: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8066DC9C: swc1        $f18, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f18.u32l;
    // 0x8066DCA0: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8066DCA4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8066DCA8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8066DCAC: nop

    // 0x8066DCB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8066DCB4: swc1        $f6, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f6.u32l;
    // 0x8066DCB8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8066DCBC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8066DCC0: swc1        $f8, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f8.u32l;
    // 0x8066DCC4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8066DCC8: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8066DCCC: swc1        $f10, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f10.u32l;
    // 0x8066DCD0: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8066DCD4: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8066DCD8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8066DCDC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8066DCE0: bne         $a2, $t0, L_8066DD00
    if (ctx->r6 != ctx->r8) {
        // 0x8066DCE4: swc1        $f18, 0x50($t4)
        MEM_W(0X50, ctx->r12) = ctx->f18.u32l;
            goto L_8066DD00;
    }
    // 0x8066DCE4: swc1        $f18, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f18.u32l;
    // 0x8066DCE8: lw          $t5, 0x28($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X28);
    // 0x8066DCEC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8066DCF0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8066DCF4: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8066DCF8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8066DCFC: sh          $t8, 0x144($t9)
    MEM_H(0X144, ctx->r25) = ctx->r24;
L_8066DD00:
    // 0x8066DD00: lw          $t3, 0x138($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X138);
    // 0x8066DD04: lw          $t4, 0x2C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2C);
    // 0x8066DD08: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8066DD0C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8066DD10: xor         $t5, $t3, $t4
    ctx->r13 = ctx->r11 ^ ctx->r12;
    // 0x8066DD14: sw          $t5, 0x138($t6)
    MEM_W(0X138, ctx->r14) = ctx->r13;
    // 0x8066DD18: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8066DD1C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8066DD20: beql        $t7, $zero, L_8066DD30
    if (ctx->r15 == 0) {
        // 0x8066DD24: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_8066DD30;
    }
    goto skip_2;
    // 0x8066DD24: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x8066DD28: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8066DD2C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_8066DD30:
    // 0x8066DD30: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8066DD34: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8066DD38: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8066DD3C: nop

    // 0x8066DD40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8066DD44: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8066DD48: swc1        $f8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f8.u32l;
    // 0x8066DD4C: lw          $t3, -0x14($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X14);
    // 0x8066DD50: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8066DD54: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8066DD58: nop

    // 0x8066DD5C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8066DD60: swc1        $f16, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f16.u32l;
    // 0x8066DD64: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8066DD68: lwc1        $f18, -0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8066DD6C: swc1        $f18, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f18.u32l;
    // 0x8066DD70: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8066DD74: lwc1        $f4, -0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8066DD78: swc1        $f4, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f4.u32l;
    // 0x8066DD7C: lwc1        $f6, -0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, -0X8);
    // 0x8066DD80: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8066DD84: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8066DD88: bne         $a2, $t1, L_8066DDA8
    if (ctx->r6 != ctx->r9) {
        // 0x8066DD8C: swc1        $f8, 0x50($t7)
        MEM_W(0X50, ctx->r15) = ctx->f8.u32l;
            goto L_8066DDA8;
    }
    // 0x8066DD8C: swc1        $f8, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f8.u32l;
    // 0x8066DD90: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x8066DD94: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8066DD98: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8066DD9C: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x8066DDA0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8066DDA4: sh          $t4, 0x144($t5)
    MEM_H(0X144, ctx->r13) = ctx->r12;
L_8066DDA8:
    // 0x8066DDA8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8066DDAC: bne         $a2, $t2, L_8066DC5C
    if (ctx->r6 != ctx->r10) {
        // 0x8066DDB0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8066DC5C;
    }
    // 0x8066DDB0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8066DDB4: jr          $ra
    // 0x8066DDB8: nop

    return;
    // 0x8066DDB8: nop

;}
RECOMP_FUNC void func_8045C8E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045C8E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8045C8E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8045C8EC: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x8045C8F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045C8F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8045C8F8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8045C8FC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8045C900: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22C0) << 16);
    // 0x8045C904: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8045C908: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8045C90C: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8045C910: lwc1        $f4, -0x24B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22C0));
    // 0x8045C914: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8045C918: nop

    // 0x8045C91C: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8045C920: jr          $ra
    // 0x8045C924: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x8045C924: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80562C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80562C14: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80562C18: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80562C1C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80562C20: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80562C24: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80562C28: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80562C2C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80562C30: jal         0x8004700C
    // 0x80562C34: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80562C34: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    after_0:
    // 0x80562C38: beq         $v0, $zero, L_80562E64
    if (ctx->r2 == 0) {
        // 0x80562C3C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80562E64;
    }
    // 0x80562C3C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80562C40: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x80562C44: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80562C48: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80562C4C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80562C50: addiu       $a3, $a3, 0x6C0
    ctx->r7 = ADD32(ctx->r7, 0X6C0);
    // 0x80562C54: lh          $t8, 0xC($a2)
    ctx->r24 = MEM_H(ctx->r6, 0XC);
    // 0x80562C58: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x80562C5C: lw          $t7, 0x70($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X70);
    // 0x80562C60: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80562C64: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80562C68: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80562C6C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80562C70: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80562C74: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80562C78: mul.s       $f26, $f0, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80562C7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80562C80: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80562C84: add.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x80562C88: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80562C8C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80562C90: lw          $t1, 0x180($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X180);
    // 0x80562C94: bnel        $t1, $zero, L_80562E68
    if (ctx->r9 != 0) {
        // 0x80562C98: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80562E68;
    }
    goto skip_0;
    // 0x80562C98: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80562C9C: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80562CA0: andi        $t3, $t2, 0xF00
    ctx->r11 = ctx->r10 & 0XF00;
    // 0x80562CA4: bnel        $t3, $zero, L_80562E68
    if (ctx->r11 != 0) {
        // 0x80562CA8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80562E68;
    }
    goto skip_1;
    // 0x80562CA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80562CAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80562CB0: lwc1        $f6, 0xC8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80562CB4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80562CB8: nop

    // 0x80562CBC: bc1fl       L_80562E68
    if (!c1cs) {
        // 0x80562CC0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80562E68;
    }
    goto skip_2;
    // 0x80562CC0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80562CC4: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80562CC8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80562CCC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80562CD0: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x80562CD4: lw          $t4, 0x174($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X174);
    // 0x80562CD8: addiu       $v1, $a3, 0x8
    ctx->r3 = ADD32(ctx->r7, 0X8);
    // 0x80562CDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80562CE0: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x80562CE4: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x80562CE8: lw          $t5, 0x70($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X70);
    // 0x80562CEC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80562CF0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80562CF4: lwc1        $f10, 0x4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80562CF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80562CFC: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80562D00: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80562D04: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80562D08: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
L_80562D0C:
    // 0x80562D0C: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80562D10: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80562D14: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80562D18: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80562D1C: nop

    // 0x80562D20: bc1fl       L_80562DC4
    if (!c1cs) {
        // 0x80562D24: c.le.s      $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
            goto L_80562DC4;
    }
    goto skip_3;
    // 0x80562D24: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    skip_3:
    // 0x80562D28: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80562D2C: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    // 0x80562D30: nop

    // 0x80562D34: bc1fl       L_80562E58
    if (!c1cs) {
        // 0x80562D38: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80562E58;
    }
    goto skip_4;
    // 0x80562D38: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_4:
    // 0x80562D3C: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80562D40: nop

    // 0x80562D44: bc1fl       L_80562E58
    if (!c1cs) {
        // 0x80562D48: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80562E58;
    }
    goto skip_5;
    // 0x80562D48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_5:
    // 0x80562D4C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80562D50: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80562D54: sub.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x80562D58: sub.s       $f20, $f2, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80562D5C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80562D60: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80562D64: div.s       $f10, $f20, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80562D68: add.s       $f0, $f6, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x80562D6C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80562D70: sub.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80562D74: sub.s       $f22, $f12, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f12.fl - ctx->f24.fl;
    // 0x80562D78: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80562D7C: nop

    // 0x80562D80: bc1fl       L_80562E58
    if (!c1cs) {
        // 0x80562D84: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80562E58;
    }
    goto skip_6;
    // 0x80562D84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_6:
    // 0x80562D88: add.s       $f4, $f12, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f24.fl;
    // 0x80562D8C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80562D90: nop

    // 0x80562D94: bc1fl       L_80562E58
    if (!c1cs) {
        // 0x80562D98: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80562E58;
    }
    goto skip_7;
    // 0x80562D98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_7:
    // 0x80562D9C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80562DA0: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80562DA4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80562DA8: sub.s       $f8, $f22, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x80562DAC: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x80562DB0: lw          $t7, 0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X34);
    // 0x80562DB4: ori         $t8, $t7, 0x700
    ctx->r24 = ctx->r15 | 0X700;
    // 0x80562DB8: b           L_80562E64
    // 0x80562DBC: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
        goto L_80562E64;
    // 0x80562DBC: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
    // 0x80562DC0: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
L_80562DC4:
    // 0x80562DC4: nop

    // 0x80562DC8: bc1fl       L_80562E58
    if (!c1cs) {
        // 0x80562DCC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80562E58;
    }
    goto skip_8;
    // 0x80562DCC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_8:
    // 0x80562DD0: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x80562DD4: nop

    // 0x80562DD8: bc1fl       L_80562E58
    if (!c1cs) {
        // 0x80562DDC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80562E58;
    }
    goto skip_9;
    // 0x80562DDC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_9:
    // 0x80562DE0: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80562DE4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80562DE8: sub.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80562DEC: sub.s       $f20, $f2, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80562DF0: sub.s       $f10, $f14, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80562DF4: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80562DF8: div.s       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80562DFC: add.s       $f0, $f6, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x80562E00: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80562E04: sub.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80562E08: sub.s       $f22, $f12, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f12.fl - ctx->f24.fl;
    // 0x80562E0C: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80562E10: nop

    // 0x80562E14: bc1fl       L_80562E58
    if (!c1cs) {
        // 0x80562E18: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80562E58;
    }
    goto skip_10;
    // 0x80562E18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_10:
    // 0x80562E1C: add.s       $f10, $f12, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f24.fl;
    // 0x80562E20: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80562E24: nop

    // 0x80562E28: bc1fl       L_80562E58
    if (!c1cs) {
        // 0x80562E2C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80562E58;
    }
    goto skip_11;
    // 0x80562E2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_11:
    // 0x80562E30: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80562E34: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80562E38: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80562E3C: sub.s       $f4, $f22, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x80562E40: swc1        $f4, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f4.u32l;
    // 0x80562E44: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x80562E48: ori         $t1, $t9, 0x700
    ctx->r9 = ctx->r25 | 0X700;
    // 0x80562E4C: b           L_80562E64
    // 0x80562E50: sw          $t1, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r9;
        goto L_80562E64;
    // 0x80562E50: sw          $t1, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r9;
    // 0x80562E54: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80562E58:
    // 0x80562E58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80562E5C: bne         $a1, $a2, L_80562D0C
    if (ctx->r5 != ctx->r6) {
        // 0x80562E60: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80562D0C;
    }
    // 0x80562E60: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80562E64:
    // 0x80562E64: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80562E68:
    // 0x80562E68: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80562E6C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80562E70: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80562E74: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80562E78: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80562E7C: jr          $ra
    // 0x80562E80: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x80562E80: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void func_806FD720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD728: jal         0x806FD700
    // 0x806FD72C: nop

    func_806FD700(rdram, ctx);
        goto after_0;
    // 0x806FD72C: nop

    after_0:
    // 0x806FD730: bne         $v0, $zero, L_806FD740
    if (ctx->r2 != 0) {
        // 0x806FD734: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FD740;
    }
    // 0x806FD734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD738: b           L_806FD760
    // 0x806FD73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806FD760;
    // 0x806FD73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806FD740:
    // 0x806FD740: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x806FD744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806FD748: lhu         $t8, 0x10($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X10);
    // 0x806FD74C: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x806FD750: beq         $t9, $zero, L_806FD760
    if (ctx->r25 == 0) {
        // 0x806FD754: nop
    
            goto L_806FD760;
    }
    // 0x806FD754: nop

    // 0x806FD758: b           L_806FD760
    // 0x806FD75C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806FD760;
    // 0x806FD75C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FD760:
    // 0x806FD760: jr          $ra
    // 0x806FD764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806FD764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806ADD40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ADD40: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x806ADD44: addiu       $at, $zero, 0x4599
    ctx->r1 = ADD32(0, 0X4599);
    // 0x806ADD48: lui         $v0, 0x806B
    ctx->r2 = S32(RELOC_HI16(595, 0X18B8) << 16);
    // 0x806ADD4C: bne         $t6, $at, L_806ADD60
    if (ctx->r14 != ctx->r1) {
        // 0x806ADD50: addiu       $v0, $v0, -0xA08
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(595, 0X18B8));
            goto L_806ADD60;
    }
    // 0x806ADD50: addiu       $v0, $v0, -0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(595, 0X18B8));
    // 0x806ADD54: lui         $v0, 0x806B
    ctx->r2 = S32(RELOC_HI16(595, 0X18B8) << 16);
    // 0x806ADD58: jr          $ra
    // 0x806ADD5C: addiu       $v0, $v0, -0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(595, 0X18B8));
    return;
    // 0x806ADD5C: addiu       $v0, $v0, -0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(595, 0X18B8));
L_806ADD60:
    // 0x806ADD60: jr          $ra
    // 0x806ADD64: nop

    return;
    // 0x806ADD64: nop

;}
RECOMP_FUNC void func_80047534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004753C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80047540: lh          $t6, 0x13C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13C);
    // 0x80047544: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80047548: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8004754C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80047550: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80047554: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80047558: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004755C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80047560: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047564: jal         0x800471D8
    // 0x80047568: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    func_800471D8(rdram, ctx);
        goto after_0;
    // 0x80047568: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    after_0:
    // 0x8004756C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80047570: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80047574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004757C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80047580: nop

    // 0x80047584: slt         $v0, $t9, $t0
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80047588: jr          $ra
    // 0x8004758C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x8004758C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
;}
RECOMP_FUNC void func_806B1FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1FFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B2000: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B2004: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B2008: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B200C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B2010: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B2014: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B2018: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B201C: addiu       $t6, $zero, 0x1C5C
    ctx->r14 = ADD32(0, 0X1C5C);
    // 0x806B2020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B2024: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B2028: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B202C: addiu       $a1, $zero, 0x2D0
    ctx->r5 = ADD32(0, 0X2D0);
    // 0x806B2030: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B2034: jal         0x806B195C
    // 0x806B2038: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B2038: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B203C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B2040: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B2044: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806B2048: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B204C: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x806B2050: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x806B2054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B2058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B205C: jr          $ra
    // 0x806B2060: nop

    return;
    // 0x806B2060: nop

;}
RECOMP_FUNC void func_807ACCB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ACCB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807ACCBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ACCC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807ACCC4: jal         0x80045A34
    // 0x807ACCC8: addiu       $a1, $zero, 0x478
    ctx->r5 = ADD32(0, 0X478);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807ACCC8: addiu       $a1, $zero, 0x478
    ctx->r5 = ADD32(0, 0X478);
    after_0:
    // 0x807ACCCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807ACCD0: bne         $v0, $zero, L_807ACCE0
    if (ctx->r2 != 0) {
        // 0x807ACCD4: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807ACCE0;
    }
    // 0x807ACCD4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807ACCD8: b           L_807ACCEC
    // 0x807ACCDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807ACCEC;
    // 0x807ACCDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807ACCE0:
    // 0x807ACCE0: jal         0x807ACC5C
    // 0x807ACCE4: nop

    func_807ACC5C(rdram, ctx);
        goto after_1;
    // 0x807ACCE4: nop

    after_1:
    // 0x807ACCE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807ACCEC:
    // 0x807ACCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ACCF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807ACCF4: jr          $ra
    // 0x807ACCF8: nop

    return;
    // 0x807ACCF8: nop

;}
RECOMP_FUNC void _VirtualToPhysicalTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082968: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8008296C: addiu       $a1, $a1, -0xF40
    ctx->r5 = ADD32(ctx->r5, -0XF40);
    // 0x80082970: jal         0x8008C1F0
    // 0x80082974: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    bcopy_recomp(rdram, ctx);
        goto after_0;
    // 0x80082974: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x80082978: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8008297C: lw          $a0, -0xF30($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XF30);
    // 0x80082980: beq         $a0, $zero, L_80082998
    if (ctx->r4 == 0) {
        // 0x80082984: nop
    
            goto L_80082998;
    }
    // 0x80082984: nop

    // 0x80082988: jal         0x80085F60
    // 0x8008298C: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8008298C: nop

    after_1:
    // 0x80082990: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80082994: sw          $v0, -0xF30($at)
    MEM_W(-0XF30, ctx->r1) = ctx->r2;
L_80082998:
    // 0x80082998: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8008299C: lw          $a0, -0xF28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XF28);
    // 0x800829A0: beq         $a0, $zero, L_800829B8
    if (ctx->r4 == 0) {
        // 0x800829A4: nop
    
            goto L_800829B8;
    }
    // 0x800829A4: nop

    // 0x800829A8: jal         0x80085F60
    // 0x800829AC: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800829AC: nop

    after_2:
    // 0x800829B0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800829B4: sw          $v0, -0xF28($at)
    MEM_W(-0XF28, ctx->r1) = ctx->r2;
L_800829B8:
    // 0x800829B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800829BC: lw          $a0, -0xF20($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XF20);
    // 0x800829C0: beq         $a0, $zero, L_800829D8
    if (ctx->r4 == 0) {
        // 0x800829C4: nop
    
            goto L_800829D8;
    }
    // 0x800829C4: nop

    // 0x800829C8: jal         0x80085F60
    // 0x800829CC: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800829CC: nop

    after_3:
    // 0x800829D0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800829D4: sw          $v0, -0xF20($at)
    MEM_W(-0XF20, ctx->r1) = ctx->r2;
L_800829D8:
    // 0x800829D8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800829DC: lw          $a0, -0xF18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XF18);
    // 0x800829E0: beq         $a0, $zero, L_800829F8
    if (ctx->r4 == 0) {
        // 0x800829E4: nop
    
            goto L_800829F8;
    }
    // 0x800829E4: nop

    // 0x800829E8: jal         0x80085F60
    // 0x800829EC: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800829EC: nop

    after_4:
    // 0x800829F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800829F4: sw          $v0, -0xF18($at)
    MEM_W(-0XF18, ctx->r1) = ctx->r2;
L_800829F8:
    // 0x800829F8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800829FC: lw          $a0, -0xF14($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XF14);
    // 0x80082A00: beq         $a0, $zero, L_80082A18
    if (ctx->r4 == 0) {
        // 0x80082A04: nop
    
            goto L_80082A18;
    }
    // 0x80082A04: nop

    // 0x80082A08: jal         0x80085F60
    // 0x80082A0C: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x80082A0C: nop

    after_5:
    // 0x80082A10: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80082A14: sw          $v0, -0xF14($at)
    MEM_W(-0XF14, ctx->r1) = ctx->r2;
L_80082A18:
    // 0x80082A18: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80082A1C: lw          $a0, -0xF10($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XF10);
    // 0x80082A20: beq         $a0, $zero, L_80082A38
    if (ctx->r4 == 0) {
        // 0x80082A24: nop
    
            goto L_80082A38;
    }
    // 0x80082A24: nop

    // 0x80082A28: jal         0x80085F60
    // 0x80082A2C: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x80082A2C: nop

    after_6:
    // 0x80082A30: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80082A34: sw          $v0, -0xF10($at)
    MEM_W(-0XF10, ctx->r1) = ctx->r2;
L_80082A38:
    // 0x80082A38: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80082A3C: lw          $a0, -0xF08($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XF08);
    // 0x80082A40: beql        $a0, $zero, L_80082A5C
    if (ctx->r4 == 0) {
        // 0x80082A44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80082A5C;
    }
    goto skip_0;
    // 0x80082A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80082A48: jal         0x80085F60
    // 0x80082A4C: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x80082A4C: nop

    after_7:
    // 0x80082A50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80082A54: sw          $v0, -0xF08($at)
    MEM_W(-0XF08, ctx->r1) = ctx->r2;
    // 0x80082A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80082A5C:
    // 0x80082A5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80082A60: addiu       $v0, $v0, -0xF40
    ctx->r2 = ADD32(ctx->r2, -0XF40);
    // 0x80082A64: jr          $ra
    // 0x80082A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80082A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800116C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800116C4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800116C8: lh          $t6, -0x6D90($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6D90);
    // 0x800116CC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800116D0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800116D4: sltiu       $at, $t7, 0x44
    ctx->r1 = ctx->r15 < 0X44 ? 1 : 0;
    // 0x800116D8: beq         $at, $zero, L_80011910
    if (ctx->r1 == 0) {
        // 0x800116DC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80011910;
    }
    // 0x800116DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800116E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800116E4: addu        $at, $at, $t7
    gpr jr_addend_800116EC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800116E8: lw          $t7, -0x328C($at)
    ctx->r15 = ADD32(ctx->r1, -0X328C);
    // 0x800116EC: jr          $t7
    // 0x800116F0: nop

    switch (jr_addend_800116EC >> 2) {
        case 0: goto L_800116F4; break;
        case 1: goto L_800116FC; break;
        case 2: goto L_80011704; break;
        case 3: goto L_8001170C; break;
        case 4: goto L_80011714; break;
        case 5: goto L_8001171C; break;
        case 6: goto L_80011724; break;
        case 7: goto L_8001172C; break;
        case 8: goto L_80011734; break;
        case 9: goto L_8001173C; break;
        case 10: goto L_80011774; break;
        case 11: goto L_80011824; break;
        case 12: goto L_8001182C; break;
        case 13: goto L_8001180C; break;
        case 14: goto L_80011814; break;
        case 15: goto L_80011884; break;
        case 16: goto L_800117AC; break;
        case 17: goto L_800117EC; break;
        case 18: goto L_800117F4; break;
        case 19: goto L_800117FC; break;
        case 20: goto L_80011804; break;
        case 21: goto L_80011744; break;
        case 22: goto L_8001177C; break;
        case 23: goto L_80011784; break;
        case 24: goto L_800117A4; break;
        case 25: goto L_8001179C; break;
        case 26: goto L_80011794; break;
        case 27: goto L_8001178C; break;
        case 28: goto L_800117B4; break;
        case 29: goto L_800117C4; break;
        case 30: goto L_800117CC; break;
        case 31: goto L_800117D4; break;
        case 32: goto L_800117DC; break;
        case 33: goto L_8001176C; break;
        case 34: goto L_80011834; break;
        case 35: goto L_8001174C; break;
        case 36: goto L_800117BC; break;
        case 37: goto L_80011754; break;
        case 38: goto L_8001181C; break;
        case 39: goto L_8001183C; break;
        case 40: goto L_800117E4; break;
        case 41: goto L_80011844; break;
        case 42: goto L_8001186C; break;
        case 43: goto L_80011764; break;
        case 44: goto L_8001185C; break;
        case 45: goto L_80011864; break;
        case 46: goto L_8001184C; break;
        case 47: goto L_80011854; break;
        case 48: goto L_80011874; break;
        case 49: goto L_8001187C; break;
        case 50: goto L_8001188C; break;
        case 51: goto L_80011894; break;
        case 52: goto L_8001189C; break;
        case 53: goto L_800118A4; break;
        case 54: goto L_800118AC; break;
        case 55: goto L_8001175C; break;
        case 56: goto L_800118B4; break;
        case 57: goto L_800118BC; break;
        case 58: goto L_800118C4; break;
        case 59: goto L_800118CC; break;
        case 60: goto L_800118D4; break;
        case 61: goto L_800118DC; break;
        case 62: goto L_800118E4; break;
        case 63: goto L_800118EC; break;
        case 64: goto L_800118F4; break;
        case 65: goto L_800118FC; break;
        case 66: goto L_80011904; break;
        case 67: goto L_8001190C; break;
        default: switch_error(__func__, 0x800116EC, 0x800ACD74);
    }
    // 0x800116F0: nop

L_800116F4:
    // 0x800116F4: jr          $ra
    // 0x800116F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800116F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800116FC:
    // 0x800116FC: jr          $ra
    // 0x80011700: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80011700: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80011704:
    // 0x80011704: jr          $ra
    // 0x80011708: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80011708: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8001170C:
    // 0x8001170C: jr          $ra
    // 0x80011710: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80011710: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80011714:
    // 0x80011714: jr          $ra
    // 0x80011718: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80011718: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8001171C:
    // 0x8001171C: jr          $ra
    // 0x80011720: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x80011720: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80011724:
    // 0x80011724: jr          $ra
    // 0x80011728: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x80011728: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8001172C:
    // 0x8001172C: jr          $ra
    // 0x80011730: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80011730: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80011734:
    // 0x80011734: jr          $ra
    // 0x80011738: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80011738: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8001173C:
    // 0x8001173C: jr          $ra
    // 0x80011740: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x80011740: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80011744:
    // 0x80011744: jr          $ra
    // 0x80011748: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80011748: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8001174C:
    // 0x8001174C: jr          $ra
    // 0x80011750: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x80011750: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80011754:
    // 0x80011754: jr          $ra
    // 0x80011758: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    return;
    // 0x80011758: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_8001175C:
    // 0x8001175C: jr          $ra
    // 0x80011760: addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    return;
    // 0x80011760: addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
L_80011764:
    // 0x80011764: jr          $ra
    // 0x80011768: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    return;
    // 0x80011768: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_8001176C:
    // 0x8001176C: jr          $ra
    // 0x80011770: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x80011770: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80011774:
    // 0x80011774: jr          $ra
    // 0x80011778: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x80011778: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_8001177C:
    // 0x8001177C: jr          $ra
    // 0x80011780: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80011780: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80011784:
    // 0x80011784: jr          $ra
    // 0x80011788: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80011788: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_8001178C:
    // 0x8001178C: jr          $ra
    // 0x80011790: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x80011790: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80011794:
    // 0x80011794: jr          $ra
    // 0x80011798: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    return;
    // 0x80011798: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_8001179C:
    // 0x8001179C: jr          $ra
    // 0x800117A0: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x800117A0: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800117A4:
    // 0x800117A4: jr          $ra
    // 0x800117A8: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    return;
    // 0x800117A8: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_800117AC:
    // 0x800117AC: jr          $ra
    // 0x800117B0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x800117B0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_800117B4:
    // 0x800117B4: jr          $ra
    // 0x800117B8: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x800117B8: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_800117BC:
    // 0x800117BC: jr          $ra
    // 0x800117C0: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    return;
    // 0x800117C0: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_800117C4:
    // 0x800117C4: jr          $ra
    // 0x800117C8: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    return;
    // 0x800117C8: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_800117CC:
    // 0x800117CC: jr          $ra
    // 0x800117D0: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x800117D0: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_800117D4:
    // 0x800117D4: jr          $ra
    // 0x800117D8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x800117D8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_800117DC:
    // 0x800117DC: jr          $ra
    // 0x800117E0: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    return;
    // 0x800117E0: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_800117E4:
    // 0x800117E4: jr          $ra
    // 0x800117E8: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    return;
    // 0x800117E8: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_800117EC:
    // 0x800117EC: jr          $ra
    // 0x800117F0: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    return;
    // 0x800117F0: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_800117F4:
    // 0x800117F4: jr          $ra
    // 0x800117F8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x800117F8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_800117FC:
    // 0x800117FC: jr          $ra
    // 0x80011800: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    return;
    // 0x80011800: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
L_80011804:
    // 0x80011804: jr          $ra
    // 0x80011808: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    return;
    // 0x80011808: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
L_8001180C:
    // 0x8001180C: jr          $ra
    // 0x80011810: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    return;
    // 0x80011810: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
L_80011814:
    // 0x80011814: jr          $ra
    // 0x80011818: addiu       $v0, $zero, 0x24
    ctx->r2 = ADD32(0, 0X24);
    return;
    // 0x80011818: addiu       $v0, $zero, 0x24
    ctx->r2 = ADD32(0, 0X24);
L_8001181C:
    // 0x8001181C: jr          $ra
    // 0x80011820: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    return;
    // 0x80011820: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
L_80011824:
    // 0x80011824: jr          $ra
    // 0x80011828: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80011828: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001182C:
    // 0x8001182C: jr          $ra
    // 0x80011830: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80011830: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80011834:
    // 0x80011834: jr          $ra
    // 0x80011838: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    return;
    // 0x80011838: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
L_8001183C:
    // 0x8001183C: jr          $ra
    // 0x80011840: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    return;
    // 0x80011840: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
L_80011844:
    // 0x80011844: jr          $ra
    // 0x80011848: addiu       $v0, $zero, 0x27
    ctx->r2 = ADD32(0, 0X27);
    return;
    // 0x80011848: addiu       $v0, $zero, 0x27
    ctx->r2 = ADD32(0, 0X27);
L_8001184C:
    // 0x8001184C: jr          $ra
    // 0x80011850: addiu       $v0, $zero, 0x25
    ctx->r2 = ADD32(0, 0X25);
    return;
    // 0x80011850: addiu       $v0, $zero, 0x25
    ctx->r2 = ADD32(0, 0X25);
L_80011854:
    // 0x80011854: jr          $ra
    // 0x80011858: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
    return;
    // 0x80011858: addiu       $v0, $zero, 0x35
    ctx->r2 = ADD32(0, 0X35);
L_8001185C:
    // 0x8001185C: jr          $ra
    // 0x80011860: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    return;
    // 0x80011860: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
L_80011864:
    // 0x80011864: jr          $ra
    // 0x80011868: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    return;
    // 0x80011868: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
L_8001186C:
    // 0x8001186C: jr          $ra
    // 0x80011870: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
    return;
    // 0x80011870: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
L_80011874:
    // 0x80011874: jr          $ra
    // 0x80011878: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x80011878: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_8001187C:
    // 0x8001187C: jr          $ra
    // 0x80011880: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    return;
    // 0x80011880: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
L_80011884:
    // 0x80011884: jr          $ra
    // 0x80011888: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    return;
    // 0x80011888: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_8001188C:
    // 0x8001188C: jr          $ra
    // 0x80011890: addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    return;
    // 0x80011890: addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
L_80011894:
    // 0x80011894: jr          $ra
    // 0x80011898: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80011898: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_8001189C:
    // 0x8001189C: jr          $ra
    // 0x800118A0: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    return;
    // 0x800118A0: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
L_800118A4:
    // 0x800118A4: jr          $ra
    // 0x800118A8: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800118A8: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800118AC:
    // 0x800118AC: jr          $ra
    // 0x800118B0: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    return;
    // 0x800118B0: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
L_800118B4:
    // 0x800118B4: jr          $ra
    // 0x800118B8: addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
    return;
    // 0x800118B8: addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
L_800118BC:
    // 0x800118BC: jr          $ra
    // 0x800118C0: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    return;
    // 0x800118C0: addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
L_800118C4:
    // 0x800118C4: jr          $ra
    // 0x800118C8: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    return;
    // 0x800118C8: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
L_800118CC:
    // 0x800118CC: jr          $ra
    // 0x800118D0: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    return;
    // 0x800118D0: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
L_800118D4:
    // 0x800118D4: jr          $ra
    // 0x800118D8: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    return;
    // 0x800118D8: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
L_800118DC:
    // 0x800118DC: jr          $ra
    // 0x800118E0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    return;
    // 0x800118E0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_800118E4:
    // 0x800118E4: jr          $ra
    // 0x800118E8: addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
    return;
    // 0x800118E8: addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
L_800118EC:
    // 0x800118EC: jr          $ra
    // 0x800118F0: addiu       $v0, $zero, 0x3E
    ctx->r2 = ADD32(0, 0X3E);
    return;
    // 0x800118F0: addiu       $v0, $zero, 0x3E
    ctx->r2 = ADD32(0, 0X3E);
L_800118F4:
    // 0x800118F4: jr          $ra
    // 0x800118F8: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    return;
    // 0x800118F8: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
L_800118FC:
    // 0x800118FC: jr          $ra
    // 0x80011900: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    return;
    // 0x80011900: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80011904:
    // 0x80011904: jr          $ra
    // 0x80011908: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    return;
    // 0x80011908: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
L_8001190C:
    // 0x8001190C: addiu       $v1, $zero, 0x42
    ctx->r3 = ADD32(0, 0X42);
L_80011910:
    // 0x80011910: jr          $ra
    // 0x80011914: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80011914: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80011918: nop

    // 0x8001191C: nop

;}
RECOMP_FUNC void func_806993C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806993C0: jr          $ra
    // 0x806993C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806993C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80568CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568CE0: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80568CE4: addiu       $at, $zero, 0x4155
    ctx->r1 = ADD32(0, 0X4155);
    // 0x80568CE8: beq         $v0, $at, L_80568D08
    if (ctx->r2 == ctx->r1) {
        // 0x80568CEC: addiu       $at, $zero, 0x4161
        ctx->r1 = ADD32(0, 0X4161);
            goto L_80568D08;
    }
    // 0x80568CEC: addiu       $at, $zero, 0x4161
    ctx->r1 = ADD32(0, 0X4161);
    // 0x80568CF0: beq         $v0, $at, L_80568D18
    if (ctx->r2 == ctx->r1) {
        // 0x80568CF4: addiu       $at, $zero, 0x416D
        ctx->r1 = ADD32(0, 0X416D);
            goto L_80568D18;
    }
    // 0x80568CF4: addiu       $at, $zero, 0x416D
    ctx->r1 = ADD32(0, 0X416D);
    // 0x80568CF8: beql        $v0, $at, L_80568D2C
    if (ctx->r2 == ctx->r1) {
        // 0x80568CFC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80568D2C;
    }
    goto skip_0;
    // 0x80568CFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80568D00: b           L_80568D38
    // 0x80568D04: nop

        goto L_80568D38;
    // 0x80568D04: nop

L_80568D08:
    // 0x80568D08: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568D0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568D10: b           L_80568D38
    // 0x80568D14: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
        goto L_80568D38;
    // 0x80568D14: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
L_80568D18:
    // 0x80568D18: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21F0) << 16);
    // 0x80568D1C: lwc1        $f6, -0x6860($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21F0));
    // 0x80568D20: b           L_80568D38
    // 0x80568D24: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
        goto L_80568D38;
    // 0x80568D24: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x80568D28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80568D2C:
    // 0x80568D2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568D30: nop

    // 0x80568D34: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
L_80568D38:
    // 0x80568D38: jal         0x80568710
    // 0x80568D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568D40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568D44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568D48: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80568D4C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568D50: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568D54: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568D58: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568D5C: jal         0x80569310
    // 0x80568D60: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    func_80569310(rdram, ctx);
        goto after_1;
    // 0x80568D60: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x80568D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568D6C: jr          $ra
    // 0x80568D70: nop

    return;
    // 0x80568D70: nop

;}
RECOMP_FUNC void func_804BE358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE358: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804BE35C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BE360: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804BE364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BE368: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BE36C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41E4) << 16);
    // 0x804BE370: lw          $v0, 0x370($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X370);
    // 0x804BE374: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x804BE378: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804BE37C: swc1        $f8, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f8.u32l;
    // 0x804BE380: lwc1        $f10, -0x4EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41E4));
    // 0x804BE384: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x804BE388: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41E8) << 16);
    // 0x804BE38C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804BE390: nop

    // 0x804BE394: bc1t        L_804BE3C8
    if (c1cs) {
        // 0x804BE398: nop
    
            goto L_804BE3C8;
    }
    // 0x804BE398: nop

    // 0x804BE39C: lwc1        $f16, -0x4E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41E8));
    // 0x804BE3A0: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X2AA0) << 16);
    // 0x804BE3A4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x804BE3A8: nop

    // 0x804BE3AC: bc1t        L_804BE3C8
    if (c1cs) {
        // 0x804BE3B0: nop
    
            goto L_804BE3C8;
    }
    // 0x804BE3B0: nop

    // 0x804BE3B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804BE3B8: sh          $zero, 0x144($v0)
    MEM_H(0X144, ctx->r2) = 0;
    // 0x804BE3BC: addiu       $t8, $t8, -0x1C30
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(191, 0X2AA0));
    // 0x804BE3C0: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x804BE3C4: sw          $t8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r24;
L_804BE3C8:
    // 0x804BE3C8: jr          $ra
    // 0x804BE3CC: nop

    return;
    // 0x804BE3CC: nop

;}
RECOMP_FUNC void func_80077930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077930: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80077934: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80077938: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007793C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077940: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80077944: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80077948: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8007794C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80077950: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80077954: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80077958: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x8007795C: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80077960: lw          $t1, 0x8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X8);
    // 0x80077964: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80077968: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x8007796C: lwc1        $f6, 0x18($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80077970: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x80077974: lwc1        $f8, 0x1C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80077978: lwc1        $f10, 0x20($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X20);
    // 0x8007797C: lwc1        $f12, 0x24($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80077980: mul.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80077984: nop

    // 0x80077988: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8007798C: nop

    // 0x80077990: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x80077994: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80077998: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8007799C: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800779A0: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800779A4: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800779A8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800779AC: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x800779B0: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800779B4: lw          $t5, 0x30($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X30);
    // 0x800779B8: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x800779BC: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800779C0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800779C4: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x800779C8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800779CC: lw          $t9, 0x34($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X34);
    // 0x800779D0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800779D4: lhu         $a1, 0x6($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X6);
    // 0x800779D8: lbu         $a2, 0x2C($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X2C);
    // 0x800779DC: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800779E0: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x800779E4: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x800779E8: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800779EC: jal         0x800773A4
    // 0x800779F0: sw          $a3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r7;
    func_800773A4(rdram, ctx);
        goto after_0;
    // 0x800779F0: sw          $a3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r7;
    after_0:
    // 0x800779F4: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x800779F8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800779FC: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x80077A00: lw          $t2, 0x28($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X28);
    // 0x80077A04: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80077A08: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80077A0C: beq         $t2, $zero, L_80077A30
    if (ctx->r10 == 0) {
        // 0x80077A10: lwc1        $f18, 0x74($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
            goto L_80077A30;
    }
    // 0x80077A10: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80077A14: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80077A18: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80077A1C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80077A20: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x80077A24: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80077A28: lw          $t6, 0x28($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X28);
    // 0x80077A2C: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
L_80077A30:
    // 0x80077A30: lwc1        $f4, 0x24($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80077A34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80077A38: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x80077A3C: nop

    // 0x80077A40: bc1f        L_80077A74
    if (!c1cs) {
        // 0x80077A44: nop
    
            goto L_80077A74;
    }
    // 0x80077A44: nop

    // 0x80077A48: lwc1        $f6, 0x1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80077A4C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80077A50: nop

    // 0x80077A54: bc1t        L_80077A74
    if (c1cs) {
        // 0x80077A58: nop
    
            goto L_80077A74;
    }
    // 0x80077A58: nop

    // 0x80077A5C: lwc1        $f8, 0x20($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80077A60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80077A64: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80077A68: nop

    // 0x80077A6C: bc1fl       L_80077BD8
    if (!c1cs) {
        // 0x80077A70: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80077BD8;
    }
    goto skip_0;
    // 0x80077A70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
L_80077A74:
    // 0x80077A74: lw          $v0, -0x260C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X260C);
    // 0x80077A78: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077A7C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80077A80: addiu       $v1, $v1, -0x18
    ctx->r3 = ADD32(ctx->r3, -0X18);
    // 0x80077A84: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80077A88: lwc1        $f10, 0x27F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X27F0);
    // 0x80077A8C: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x80077A90: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x80077A94: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80077A98: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x80077A9C: sw          $a3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r7;
    // 0x80077AA0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80077AA4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80077AA8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80077AAC: nop

    // 0x80077AB0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80077AB4: jal         0x8008D3C0
    // 0x80077AB8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    coss(rdram, ctx);
        goto after_1;
    // 0x80077AB8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80077ABC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80077AC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077AC4: lwc1        $f4, 0x27F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X27F4);
    // 0x80077AC8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80077ACC: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80077AD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80077AD4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80077AD8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80077ADC: nop

    // 0x80077AE0: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80077AE4: jal         0x800828F0
    // 0x80077AE8: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    sins(rdram, ctx);
        goto after_2;
    // 0x80077AE8: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80077AEC: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80077AF0: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80077AF4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80077AF8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80077AFC: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80077B00: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80077B04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80077B08: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80077B0C: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x80077B10: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x80077B14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80077B18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077B1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80077B20: lui         $t6, 0x517
    ctx->r14 = S32(0X517 << 16);
    // 0x80077B24: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80077B28: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80077B2C: nop

    // 0x80077B30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077B34: lwc1        $f10, 0x27F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X27F8);
    // 0x80077B38: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80077B3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80077B40: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80077B44: nop

    // 0x80077B48: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80077B4C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80077B50: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80077B54: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80077B58: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80077B5C: nop

    // 0x80077B60: mul.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80077B64: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80077B68: nop

    // 0x80077B6C: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x80077B70: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80077B74: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80077B78: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80077B7C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80077B80: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80077B84: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x80077B88: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80077B8C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80077B90: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80077B94: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80077B98: nop

    // 0x80077B9C: sh          $t9, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r25;
    // 0x80077BA0: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80077BA4: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80077BA8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80077BAC: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80077BB0: nop

    // 0x80077BB4: sh          $t3, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r11;
    // 0x80077BB8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80077BBC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80077BC0: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    // 0x80077BC4: sw          $v1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r3;
    // 0x80077BC8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80077BCC: b           L_80077CF0
    // 0x80077BD0: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
        goto L_80077CF0;
    // 0x80077BD0: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
    // 0x80077BD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80077BD8:
    // 0x80077BD8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80077BDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80077BE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80077BE4: lw          $v0, -0x260C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X260C);
    // 0x80077BE8: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x80077BEC: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x80077BF0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80077BF4: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80077BF8: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x80077BFC: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x80077C00: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80077C04: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80077C08: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80077C0C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80077C10: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80077C14: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80077C18: nop

    // 0x80077C1C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80077C20: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80077C24: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80077C28: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80077C2C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80077C30: bc1f        L_80077C40
    if (!c1cs) {
        // 0x80077C34: sh          $t2, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r10;
            goto L_80077C40;
    }
    // 0x80077C34: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x80077C38: b           L_80077C7C
    // 0x80077C3C: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
        goto L_80077C7C;
    // 0x80077C3C: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
L_80077C40:
    // 0x80077C40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80077C44: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80077C48: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    // 0x80077C4C: nop

    // 0x80077C50: bc1fl       L_80077C64
    if (!c1cs) {
        // 0x80077C54: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80077C64;
    }
    goto skip_1;
    // 0x80077C54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80077C58: b           L_80077C78
    // 0x80077C5C: addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
        goto L_80077C78;
    // 0x80077C5C: addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
    // 0x80077C60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80077C64:
    // 0x80077C64: nop

    // 0x80077C68: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80077C6C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80077C70: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80077C74: nop

L_80077C78:
    // 0x80077C78: sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
L_80077C7C:
    // 0x80077C7C: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x80077C80: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x80077C84: bc1fl       L_80077C98
    if (!c1cs) {
        // 0x80077C88: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80077C98;
    }
    goto skip_2;
    // 0x80077C88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_2:
    // 0x80077C8C: b           L_80077CD0
    // 0x80077C90: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
        goto L_80077CD0;
    // 0x80077C90: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    // 0x80077C94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80077C98:
    // 0x80077C98: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80077C9C: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x80077CA0: nop

    // 0x80077CA4: bc1fl       L_80077CB8
    if (!c1cs) {
        // 0x80077CA8: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80077CB8;
    }
    goto skip_3;
    // 0x80077CA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x80077CAC: b           L_80077CCC
    // 0x80077CB0: addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
        goto L_80077CCC;
    // 0x80077CB0: addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
    // 0x80077CB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80077CB8:
    // 0x80077CB8: nop

    // 0x80077CBC: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80077CC0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80077CC4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80077CC8: nop

L_80077CCC:
    // 0x80077CCC: sh          $v1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r3;
L_80077CD0:
    // 0x80077CD0: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x80077CD4: lui         $t9, 0x507
    ctx->r25 = S32(0X507 << 16);
    // 0x80077CD8: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x80077CDC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80077CE0: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x80077CE4: sw          $a0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r4;
    // 0x80077CE8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80077CEC: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
L_80077CF0:
    // 0x80077CF0: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80077CF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077CF8: beq         $v0, $zero, L_80077D5C
    if (ctx->r2 == 0) {
        // 0x80077CFC: addiu       $t3, $t2, 0x8
        ctx->r11 = ADD32(ctx->r10, 0X8);
            goto L_80077D5C;
    }
    // 0x80077CFC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80077D00: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x80077D04: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80077D08: ori         $t4, $t4, 0x2C06
    ctx->r12 = ctx->r12 | 0X2C06;
    // 0x80077D0C: beq         $a0, $zero, L_80077D1C
    if (ctx->r4 == 0) {
        // 0x80077D10: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80077D1C;
    }
    // 0x80077D10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077D14: b           L_80077D20
    // 0x80077D18: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80077D20;
    // 0x80077D18: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80077D1C:
    // 0x80077D1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80077D20:
    // 0x80077D20: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x80077D24: sw          $v1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r3;
    // 0x80077D28: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80077D2C: lw          $t5, 0x1C($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X1C);
    // 0x80077D30: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x80077D34: lui         $t8, 0xC100
    ctx->r24 = S32(0XC100 << 16);
    // 0x80077D38: beq         $t5, $zero, L_80077D54
    if (ctx->r13 == 0) {
        // 0x80077D3C: addiu       $t7, $t6, 0x8
        ctx->r15 = ADD32(ctx->r14, 0X8);
            goto L_80077D54;
    }
    // 0x80077D3C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80077D40: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x80077D44: ori         $t8, $t8, 0x17
    ctx->r24 = ctx->r24 | 0X17;
    // 0x80077D48: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80077D4C: lw          $t9, 0x1C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X1C);
    // 0x80077D50: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
L_80077D54:
    // 0x80077D54: b           L_80077D60
    // 0x80077D58: sw          $v1, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = ctx->r3;
        goto L_80077D60;
    // 0x80077D58: sw          $v1, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = ctx->r3;
L_80077D5C:
    // 0x80077D5C: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
L_80077D60:
    // 0x80077D60: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x80077D64: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80077D68: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80077D6C: beq         $v0, $zero, L_80077D7C
    if (ctx->r2 == 0) {
        // 0x80077D70: addiu       $t3, $t2, 0x8
        ctx->r11 = ADD32(ctx->r10, 0X8);
            goto L_80077D7C;
    }
    // 0x80077D70: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80077D74: b           L_80077D80
    // 0x80077D78: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80077D80;
    // 0x80077D78: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80077D7C:
    // 0x80077D7C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
L_80077D80:
    // 0x80077D80: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x80077D84: ori         $t4, $t4, 0x3006
    ctx->r12 = ctx->r12 | 0X3006;
    // 0x80077D88: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80077D8C: sw          $a2, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r6;
    // 0x80077D90: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80077D94: lui         $t7, 0xB100
    ctx->r15 = S32(0XB100 << 16);
    // 0x80077D98: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80077D9C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80077DA0: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x80077DA4: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80077DA8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80077DAC: lbu         $t9, 0x15($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X15);
    // 0x80077DB0: lw          $v1, 0x18($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X18);
    // 0x80077DB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80077DB8: blez        $t9, L_80077E58
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80077DBC: lui         $t0, 0xC200
        ctx->r8 = S32(0XC200 << 16);
            goto L_80077E58;
    }
    // 0x80077DBC: lui         $t0, 0xC200
    ctx->r8 = S32(0XC200 << 16);
    // 0x80077DC0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80077DC4: lui         $a1, 0xC400
    ctx->r5 = S32(0XC400 << 16);
    // 0x80077DC8: ori         $a1, $a1, 0x2F
    ctx->r5 = ctx->r5 | 0X2F;
    // 0x80077DCC: addiu       $a2, $a2, -0x7A1C
    ctx->r6 = ADD32(ctx->r6, -0X7A1C);
    // 0x80077DD0: ori         $t0, $t0, 0x2F
    ctx->r8 = ctx->r8 | 0X2F;
    // 0x80077DD4: lwc1        $f6, 0x24($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
L_80077DD8:
    // 0x80077DD8: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80077DDC: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x80077DE0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80077DE4: bc1fl       L_80077E1C
    if (!c1cs) {
        // 0x80077DE8: sw          $t3, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r11;
            goto L_80077E1C;
    }
    goto skip_4;
    // 0x80077DE8: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    skip_4:
    // 0x80077DEC: lwc1        $f8, 0x1C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80077DF0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80077DF4: nop

    // 0x80077DF8: bc1tl       L_80077E1C
    if (c1cs) {
        // 0x80077DFC: sw          $t3, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r11;
            goto L_80077E1C;
    }
    goto skip_5;
    // 0x80077DFC: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    skip_5:
    // 0x80077E00: lwc1        $f10, 0x20($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80077E04: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80077E08: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80077E0C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80077E10: bc1fl       L_80077E30
    if (!c1cs) {
        // 0x80077E14: sw          $t5, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r13;
            goto L_80077E30;
    }
    goto skip_6;
    // 0x80077E14: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    skip_6:
    // 0x80077E18: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
L_80077E1C:
    // 0x80077E1C: sw          $v1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r3;
    // 0x80077E20: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x80077E24: b           L_80077E3C
    // 0x80077E28: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
        goto L_80077E3C;
    // 0x80077E28: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80077E2C: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
L_80077E30:
    // 0x80077E30: sw          $v1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r3;
    // 0x80077E34: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
    // 0x80077E38: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
L_80077E3C:
    // 0x80077E3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80077E40: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x80077E44: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80077E48: lbu         $t7, 0x15($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X15);
    // 0x80077E4C: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80077E50: bnel        $at, $zero, L_80077DD8
    if (ctx->r1 != 0) {
        // 0x80077E54: lwc1        $f6, 0x24($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
            goto L_80077DD8;
    }
    goto skip_7;
    // 0x80077E54: lwc1        $f6, 0x24($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
    skip_7:
L_80077E58:
    // 0x80077E58: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80077E5C: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80077E60: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80077E64: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x80077E68: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80077E6C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80077E70: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80077E74: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80077E78: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80077E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077E80: jr          $ra
    // 0x80077E84: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80077E84: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_805A75E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A75E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A75E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A75E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A75EC: jal         0x8004700C
    // 0x805A75F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A75F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805A75F4: beq         $v0, $zero, L_805A7610
    if (ctx->r2 == 0) {
        // 0x805A75F8: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_805A7610;
    }
    // 0x805A75F8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805A75FC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x805A7600: bnel        $t6, $at, L_805A7614
    if (ctx->r14 != ctx->r1) {
        // 0x805A7604: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A7614;
    }
    goto skip_0;
    // 0x805A7604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A7608: jal         0x805A7504
    // 0x805A760C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805A7504(rdram, ctx);
        goto after_1;
    // 0x805A760C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_805A7610:
    // 0x805A7610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A7614:
    // 0x805A7614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A7618: jr          $ra
    // 0x805A761C: nop

    return;
    // 0x805A761C: nop

;}
RECOMP_FUNC void func_804C93A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C93A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C93A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C93AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C93B0: jal         0x80062684
    // 0x804C93B4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x804C93B4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x804C93B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804C93BC: addiu       $a1, $zero, 0x4001
    ctx->r5 = ADD32(0, 0X4001);
    // 0x804C93C0: lh          $v1, 0x184($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X184);
    // 0x804C93C4: addiu       $a0, $a2, 0x188
    ctx->r4 = ADD32(ctx->r6, 0X188);
    // 0x804C93C8: lw          $a3, 0x174($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X174);
    // 0x804C93CC: beql        $v1, $zero, L_804C9424
    if (ctx->r3 == 0) {
        // 0x804C93D0: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_804C9424;
    }
    goto skip_0;
    // 0x804C93D0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    skip_0:
L_804C93D4:
    // 0x804C93D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804C93D8: beq         $v0, $zero, L_804C9418
    if (ctx->r2 == 0) {
        // 0x804C93DC: nop
    
            goto L_804C9418;
    }
    // 0x804C93DC: nop

    // 0x804C93E0: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x804C93E4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x804C93E8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x804C93EC: bne         $a1, $t6, L_804C9418
    if (ctx->r5 != ctx->r14) {
        // 0x804C93F0: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_804C9418;
    }
    // 0x804C93F0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x804C93F4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x804C93F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804C93FC: lbu         $t7, 0x77($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X77);
    // 0x804C9400: beql        $t7, $zero, L_804C9444
    if (ctx->r15 == 0) {
        // 0x804C9404: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C9444;
    }
    goto skip_1;
    // 0x804C9404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804C9408: jal         0x8005FB2C
    // 0x804C940C: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
    func_8005FB2C(rdram, ctx);
        goto after_1;
    // 0x804C940C: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
    after_1:
    // 0x804C9410: b           L_804C9444
    // 0x804C9414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C9444;
    // 0x804C9414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C9418:
    // 0x804C9418: bne         $v1, $zero, L_804C93D4
    if (ctx->r3 != 0) {
        // 0x804C941C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_804C93D4;
    }
    // 0x804C941C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804C9420: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_804C9424:
    // 0x804C9424: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804C9428: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804C942C: lbu         $t8, 0x77($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X77);
    // 0x804C9430: bnel        $t8, $zero, L_804C9444
    if (ctx->r24 != 0) {
        // 0x804C9434: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C9444;
    }
    goto skip_2;
    // 0x804C9434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804C9438: jal         0x8005FAE0
    // 0x804C943C: sb          $t9, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r25;
    func_8005FAE0(rdram, ctx);
        goto after_2;
    // 0x804C943C: sb          $t9, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r25;
    after_2:
    // 0x804C9440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C9444:
    // 0x804C9444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C9448: jr          $ra
    // 0x804C944C: nop

    return;
    // 0x804C944C: nop

;}
RECOMP_FUNC void func_80048378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048378: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004837C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80048380: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80048384: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80048388: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8004838C:
    // 0x8004838C: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80048390: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80048394: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80048398: nop

    // 0x8004839C: bc1f        L_800483A8
    if (!c1cs) {
        // 0x800483A0: nop
    
            goto L_800483A8;
    }
    // 0x800483A0: nop

    // 0x800483A4: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
L_800483A8:
    // 0x800483A8: bne         $v1, $v0, L_8004838C
    if (ctx->r3 != ctx->r2) {
        // 0x800483AC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8004838C;
    }
    // 0x800483AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800483B0: jr          $ra
    // 0x800483B4: nop

    return;
    // 0x800483B4: nop

;}
RECOMP_FUNC void func_806EAD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAD24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EAD28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EAD2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EAD30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EAD34: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806EAD38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806EAD3C: jal         0x806EA844
    // 0x806EAD40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806EA844(rdram, ctx);
        goto after_0;
    // 0x806EAD40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x806EAD44: jal         0x806EA9C0
    // 0x806EAD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EA9C0(rdram, ctx);
        goto after_1;
    // 0x806EAD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EAD4C: jal         0x806EA92C
    // 0x806EAD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EA92C(rdram, ctx);
        goto after_2;
    // 0x806EAD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EAD54: beq         $v0, $zero, L_806EAD94
    if (ctx->r2 == 0) {
        // 0x806EAD58: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_806EAD94;
    }
    // 0x806EAD58: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x806EAD5C: lw          $t7, 0x68($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X68);
    // 0x806EAD60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAD64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EAD68: bne         $t7, $zero, L_806EAD8C
    if (ctx->r15 != 0) {
        // 0x806EAD6C: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_806EAD8C;
    }
    // 0x806EAD6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806EAD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAD74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EAD78: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806EAD7C: jal         0x806EB43C
    // 0x806EAD80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806EB43C(rdram, ctx);
        goto after_3;
    // 0x806EAD80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x806EAD84: b           L_806EAD98
    // 0x806EAD88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EAD98;
    // 0x806EAD88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EAD8C:
    // 0x806EAD8C: jal         0x806EB43C
    // 0x806EAD90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806EB43C(rdram, ctx);
        goto after_4;
    // 0x806EAD90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_806EAD94:
    // 0x806EAD94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EAD98:
    // 0x806EAD98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EAD9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EADA0: jr          $ra
    // 0x806EADA4: nop

    return;
    // 0x806EADA4: nop

;}
RECOMP_FUNC void func_806DF0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF0FC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806DF100: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(640, 0X80) << 16);
    // 0x806DF104: addiu       $t6, $t6, -0xF80
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(640, 0X80));
    // 0x806DF108: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806DF10C: jr          $ra
    // 0x806DF110: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806DF110: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80024020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80024024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80024028: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002402C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80024030: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80024038: addiu       $s1, $a0, 0xC8
    ctx->r17 = ADD32(ctx->r4, 0XC8);
    // 0x8002403C: lbu         $t7, 0x111($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X111);
    // 0x80024040: beql        $t7, $zero, L_80024064
    if (ctx->r15 == 0) {
        // 0x80024044: lwc1        $f14, 0xE0($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0XE0);
            goto L_80024064;
    }
    goto skip_0;
    // 0x80024044: lwc1        $f14, 0xE0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XE0);
    skip_0:
    // 0x80024048: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002404C: lwc1        $f14, 0xE0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80024050: jal         0x80023E18
    // 0x80024054: lw          $a2, 0xEC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XEC);
    func_80023E18(rdram, ctx);
        goto after_0;
    // 0x80024054: lw          $a2, 0xEC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XEC);
    after_0:
    // 0x80024058: b           L_800240A4
    // 0x8002405C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_800240A4;
    // 0x8002405C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80024060: lwc1        $f14, 0xE0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XE0);
L_80024064:
    // 0x80024064: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024068: addiu       $s1, $s0, 0xC8
    ctx->r17 = ADD32(ctx->r16, 0XC8);
    // 0x8002406C: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x80024070: nop

    // 0x80024074: bc1fl       L_80024098
    if (!c1cs) {
        // 0x80024078: lwc1        $f12, 0x0($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80024098;
    }
    goto skip_1;
    // 0x80024078: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x8002407C: addiu       $s1, $s0, 0xC8
    ctx->r17 = ADD32(ctx->r16, 0XC8);
    // 0x80024080: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80024084: jal         0x80023E18
    // 0x80024088: lw          $a2, 0xEC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XEC);
    func_80023E18(rdram, ctx);
        goto after_1;
    // 0x80024088: lw          $a2, 0xEC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XEC);
    after_1:
    // 0x8002408C: b           L_800240A4
    // 0x80024090: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_800240A4;
    // 0x80024090: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80024094: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
L_80024098:
    // 0x80024098: jal         0x80023DD0
    // 0x8002409C: lw          $a2, 0xEC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XEC);
    func_80023DD0(rdram, ctx);
        goto after_2;
    // 0x8002409C: lw          $a2, 0xEC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XEC);
    after_2:
    // 0x800240A0: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_800240A4:
    // 0x800240A4: jal         0x80023E64
    // 0x800240A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80023E64(rdram, ctx);
        goto after_3;
    // 0x800240A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800240AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800240B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800240B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800240B8: jr          $ra
    // 0x800240BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800240BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80792328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792328: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079232C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80792330: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80792334: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80792338: jal         0x80790714
    // 0x8079233C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80790714(rdram, ctx);
        goto after_0;
    // 0x8079233C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80792340: beq         $v0, $zero, L_80792390
    if (ctx->r2 == 0) {
        // 0x80792344: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80792390;
    }
    // 0x80792344: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80792348: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8079234C: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x80792350: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80792354: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80792358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079235C: jal         0x8079393C
    // 0x80792360: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_8079393C(rdram, ctx);
        goto after_1;
    // 0x80792360: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_1:
    // 0x80792364: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80792368: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8079236C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AF4) << 16);
    // 0x80792370: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80792374: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80792378: lwc1        $f10, 0x7E44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AF4));
    // 0x8079237C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80792380: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80792384: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80792388: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8079238C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
L_80792390:
    // 0x80792390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80792394: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80792398: jr          $ra
    // 0x8079239C: nop

    return;
    // 0x8079239C: nop

;}
RECOMP_FUNC void func_805C9154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C9154: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805C9158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C915C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C9160: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C9164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C9168: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805C916C: lw          $v0, 0x38($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X38);
    // 0x805C9170: beql        $v0, $zero, L_805C9194
    if (ctx->r2 == 0) {
        // 0x805C9174: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805C9194;
    }
    goto skip_0;
    // 0x805C9174: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x805C9178: beq         $v0, $at, L_805C91F4
    if (ctx->r2 == ctx->r1) {
        // 0x805C917C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_805C91F4;
    }
    // 0x805C917C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805C9180: beql        $v0, $at, L_805C9268
    if (ctx->r2 == ctx->r1) {
        // 0x805C9184: lui         $at, 0x43B5
        ctx->r1 = S32(0X43B5 << 16);
            goto L_805C9268;
    }
    goto skip_1;
    // 0x805C9184: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
    skip_1:
    // 0x805C9188: b           L_805C92D4
    // 0x805C918C: addiu       $a3, $a0, 0xC4
    ctx->r7 = ADD32(ctx->r4, 0XC4);
        goto L_805C92D4;
    // 0x805C918C: addiu       $a3, $a0, 0xC4
    ctx->r7 = ADD32(ctx->r4, 0XC4);
    // 0x805C9190: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_805C9194:
    // 0x805C9194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9198: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x805C919C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805C91A0: jal         0x805C70B0
    // 0x805C91A4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805C70B0(rdram, ctx);
        goto after_0;
    // 0x805C91A4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C91A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C91AC: beq         $v0, $zero, L_805C91EC
    if (ctx->r2 == 0) {
        // 0x805C91B0: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_805C91EC;
    }
    // 0x805C91B0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805C91B4: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x805C91B8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x805C91BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C91C0: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x805C91C4: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C91C8: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C91CC: sw          $t6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r14;
    // 0x805C91D0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x805C91D4: jal         0x805C74C8
    // 0x805C91D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C74C8(rdram, ctx);
        goto after_1;
    // 0x805C91D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805C91DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C91E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C91E4: jal         0x805C9D10
    // 0x805C91E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C91E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_805C91EC:
    // 0x805C91EC: b           L_805C92D4
    // 0x805C91F0: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
        goto L_805C92D4;
    // 0x805C91F0: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
L_805C91F4:
    // 0x805C91F4: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
    // 0x805C91F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C91FC: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C9200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9204: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805C9208: nop

    // 0x805C920C: bc1fl       L_805C9250
    if (!c1cs) {
        // 0x805C9210: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805C9250;
    }
    goto skip_2;
    // 0x805C9210: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x805C9214: jal         0x805C6AF0
    // 0x805C9218: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805C6AF0(rdram, ctx);
        goto after_3;
    // 0x805C9218: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x805C921C: bne         $v0, $zero, L_805C924C
    if (ctx->r2 != 0) {
        // 0x805C9220: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_805C924C;
    }
    // 0x805C9220: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805C9224: lui         $a1, 0x439D
    ctx->r5 = S32(0X439D << 16);
    // 0x805C9228: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x805C922C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9230: jal         0x805C70B0
    // 0x805C9234: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_805C70B0(rdram, ctx);
        goto after_4;
    // 0x805C9234: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_4:
    // 0x805C9238: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x805C923C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C9240: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C9244: b           L_805C92D4
    // 0x805C9248: swc1        $f8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f8.u32l;
        goto L_805C92D4;
    // 0x805C9248: swc1        $f8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f8.u32l;
L_805C924C:
    // 0x805C924C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_805C9250:
    // 0x805C9250: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C9254: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x805C9258: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x805C925C: b           L_805C92D4
    // 0x805C9260: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
        goto L_805C92D4;
    // 0x805C9260: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x805C9264: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
L_805C9268:
    // 0x805C9268: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C926C: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C9270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9274: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805C9278: nop

    // 0x805C927C: bc1fl       L_805C92C4
    if (!c1cs) {
        // 0x805C9280: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805C92C4;
    }
    goto skip_3;
    // 0x805C9280: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x805C9284: jal         0x805C6AF0
    // 0x805C9288: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805C6AF0(rdram, ctx);
        goto after_5;
    // 0x805C9288: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x805C928C: bne         $v0, $zero, L_805C92C0
    if (ctx->r2 != 0) {
        // 0x805C9290: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_805C92C0;
    }
    // 0x805C9290: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805C9294: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805C9298: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C929C: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C92A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C92A4: swc1        $f18, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f18.u32l;
    // 0x805C92A8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x805C92AC: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x805C92B0: jal         0x805C70B0
    // 0x805C92B4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_805C70B0(rdram, ctx);
        goto after_6;
    // 0x805C92B4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_6:
    // 0x805C92B8: b           L_805C92D4
    // 0x805C92BC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
        goto L_805C92D4;
    // 0x805C92BC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_805C92C0:
    // 0x805C92C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_805C92C4:
    // 0x805C92C4: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C92C8: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x805C92CC: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x805C92D0: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
L_805C92D4:
    // 0x805C92D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805C92D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C92DC: jal         0x80048F84
    // 0x805C92E0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x805C92E0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_7:
    // 0x805C92E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805C92E8: jal         0x80048F84
    // 0x805C92EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_8;
    // 0x805C92EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x805C92F0: jal         0x805C7844
    // 0x805C92F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_9;
    // 0x805C92F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x805C92F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C92FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C9300: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805C9304: jr          $ra
    // 0x805C9308: nop

    return;
    // 0x805C9308: nop

;}
RECOMP_FUNC void func_805C781C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C781C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805C7820: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C7824: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C7828: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805C782C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805C7830: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x805C7834: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x805C7838: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x805C783C: jr          $ra
    // 0x805C7840: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    return;
    // 0x805C7840: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8052DF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052DF90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8052DF94: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8052DF98: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8052DF9C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8052DFA0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8052DFA4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8052DFA8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8052DFAC: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8052DFB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8052DFB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8052DFB8: lw          $t3, 0xF60($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XF60);
    // 0x8052DFBC: lw          $t0, 0x1164($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1164);
    // 0x8052DFC0: addiu       $t4, $v0, 0x1174
    ctx->r12 = ADD32(ctx->r2, 0X1174);
    // 0x8052DFC4: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8052DFC8: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x8052DFCC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8052DFD0: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x8052DFD4: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8052DFD8: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8052DFDC: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
    // 0x8052DFE0: sllv        $t5, $t7, $t3
    ctx->r13 = S32(ctx->r15 << (ctx->r11 & 31));
    // 0x8052DFE4: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
    // 0x8052DFE8: andi        $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 & 0XFF;
    // 0x8052DFEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8052DFF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8052DFF4: beq         $t0, $zero, L_8052E0C4
    if (ctx->r8 == 0) {
        // 0x8052DFF8: addu        $t2, $v0, $t6
        ctx->r10 = ADD32(ctx->r2, ctx->r14);
            goto L_8052E0C4;
    }
    // 0x8052DFF8: addu        $t2, $v0, $t6
    ctx->r10 = ADD32(ctx->r2, ctx->r14);
    // 0x8052DFFC: lui         $s2, 0x404
    ctx->r18 = S32(0X404 << 16);
    // 0x8052E000: lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // 0x8052E004: ori         $s1, $s1, 0x81F
    ctx->r17 = ctx->r17 | 0X81F;
    // 0x8052E008: ori         $s2, $s2, 0x81F
    ctx->r18 = ctx->r18 | 0X81F;
    // 0x8052E00C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8052E010: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8052E014: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8052E018: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8052E01C: addiu       $s5, $zero, 0x604
    ctx->r21 = ADD32(0, 0X604);
    // 0x8052E020: addiu       $s4, $zero, 0x206
    ctx->r20 = ADD32(0, 0X206);
    // 0x8052E024: lui         $s3, 0xBF00
    ctx->r19 = S32(0XBF00 << 16);
L_8052E028:
    // 0x8052E028: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8052E02C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8052E030: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8052E034: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x8052E038: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8052E03C: sw          $s0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r16;
    // 0x8052E040: sw          $s1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r17;
    // 0x8052E044: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8052E048: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8052E04C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8052E050: and         $t6, $t9, $a1
    ctx->r14 = ctx->r25 & ctx->r5;
    // 0x8052E054: bne         $t6, $zero, L_8052E07C
    if (ctx->r14 != 0) {
        // 0x8052E058: addu        $t2, $t1, $v1
        ctx->r10 = ADD32(ctx->r9, ctx->r3);
            goto L_8052E07C;
    }
    // 0x8052E058: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
L_8052E05C:
    // 0x8052E05C: lbu         $t7, 0x1($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X1);
    // 0x8052E060: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8052E064: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8052E068: and         $t8, $t7, $a1
    ctx->r24 = ctx->r15 & ctx->r5;
    // 0x8052E06C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8052E070: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8052E074: beq         $t8, $zero, L_8052E05C
    if (ctx->r24 == 0) {
        // 0x8052E078: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_8052E05C;
    }
    // 0x8052E078: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_8052E07C:
    // 0x8052E07C: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8052E080: sltu        $at, $a2, $t0
    ctx->r1 = ctx->r6 < ctx->r8 ? 1 : 0;
    // 0x8052E084: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8052E088: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x8052E08C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8052E090: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x8052E094: sw          $s2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r18;
    // 0x8052E098: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8052E09C: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8052E0A0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8052E0A4: sw          $s4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r20;
    // 0x8052E0A8: sw          $s3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r19;
    // 0x8052E0AC: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8052E0B0: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x8052E0B4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8052E0B8: sw          $s5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r21;
    // 0x8052E0BC: bne         $at, $zero, L_8052E028
    if (ctx->r1 != 0) {
        // 0x8052E0C0: sw          $s3, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r19;
            goto L_8052E028;
    }
    // 0x8052E0C0: sw          $s3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r19;
L_8052E0C4:
    // 0x8052E0C4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8052E0C8: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8052E0CC: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8052E0D0: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8052E0D4: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8052E0D8: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8052E0DC: jr          $ra
    // 0x8052E0E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8052E0E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005DBCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DBCC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005DBD0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8005DBD4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8005DBD8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8005DBDC: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x8005DBE0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005DBE4: lw          $t7, 0x63D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63D0);
    // 0x8005DBE8: jr          $ra
    // 0x8005DBEC: sb          $t7, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r15;
    return;
    // 0x8005DBEC: sb          $t7, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_804011D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804011D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804011DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804011E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804011E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804011E8: lh          $a1, 0x184($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X184);
    // 0x804011EC: jal         0x800481E0
    // 0x804011F0: addiu       $a0, $a0, 0x188
    ctx->r4 = ADD32(ctx->r4, 0X188);
    func_800481E0(rdram, ctx);
        goto after_0;
    // 0x804011F0: addiu       $a0, $a0, 0x188
    ctx->r4 = ADD32(ctx->r4, 0X188);
    after_0:
    // 0x804011F4: jal         0x8005FE48
    // 0x804011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x804011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804011FC: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x80401200: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80401204: sw          $zero, 0x44($t7)
    MEM_W(0X44, ctx->r15) = 0;
    // 0x80401208: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x8040120C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80401210: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
    // 0x80401214: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80401218: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8040121C: sh          $zero, 0x4C($t1)
    MEM_H(0X4C, ctx->r9) = 0;
    // 0x80401220: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80401224: jal         0x80067BBC
    // 0x80401228: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80401228: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x8040122C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x80401230: jal         0x80067818
    // 0x80401234: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80401234: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80401238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040123C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80401240: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80401244: jal         0x80401B90
    // 0x80401248: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80401B90(rdram, ctx);
        goto after_4;
    // 0x80401248: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x8040124C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80401250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80401254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80401258: jr          $ra
    // 0x8040125C: nop

    return;
    // 0x8040125C: nop

;}
RECOMP_FUNC void func_80434440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434440: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80434444: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80434448: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X27F0) << 16);
    // 0x8043444C: lw          $t6, 0x7A0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7A0);
    // 0x80434450: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80434454: addiu       $t8, $t8, 0x62A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(71, 0X27F0));
    // 0x80434458: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8043445C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80434460: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80434464: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80434468: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8043446C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80434470: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80434474: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80434478: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x8043447C: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80434480: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80434484: addiu       $v1, $t0, 0x8
    ctx->r3 = ADD32(ctx->r8, 0X8);
    // 0x80434488: jr          $ra
    // 0x8043448C: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    return;
    // 0x8043448C: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_8005D64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D64C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D654: jal         0x8005D5A8
    // 0x8005D658: nop

    func_8005D5A8(rdram, ctx);
        goto after_0;
    // 0x8005D658: nop

    after_0:
    // 0x8005D65C: jal         0x80047058
    // 0x8005D660: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047058(rdram, ctx);
        goto after_1;
    // 0x8005D660: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005D664: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D668: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005D66C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005D670: bne         $v1, $zero, L_8005D680
    if (ctx->r3 != 0) {
        // 0x8005D674: nop
    
            goto L_8005D680;
    }
    // 0x8005D674: nop

    // 0x8005D678: b           L_8005D6E0
    // 0x8005D67C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D6E0;
    // 0x8005D67C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005D680:
    // 0x8005D680: beq         $v0, $zero, L_8005D6A0
    if (ctx->r2 == 0) {
        // 0x8005D684: nop
    
            goto L_8005D6A0;
    }
    // 0x8005D684: nop

    // 0x8005D688: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8005D68C: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8005D690: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8005D694: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x8005D698: lwc1        $f8, 0x8C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x8005D69C: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
L_8005D6A0:
    // 0x8005D6A0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005D6A4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8005D6A8: sw          $t6, 0xEAC($v0)
    MEM_W(0XEAC, ctx->r2) = ctx->r14;
    // 0x8005D6AC: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x8005D6B0: lw          $t8, 0x3EC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3EC);
    // 0x8005D6B4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8005D6B8: lbu         $t0, 0x598($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X598);
    // 0x8005D6BC: sb          $t0, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r8;
    // 0x8005D6C0: lw          $t1, 0x478($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X478);
    // 0x8005D6C4: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8005D6C8: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
    // 0x8005D6CC: lw          $t2, 0x478($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X478);
    // 0x8005D6D0: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8005D6D4: swc1        $f16, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x8005D6D8: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8005D6DC: sb          $t3, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r11;
L_8005D6E0:
    // 0x8005D6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D6E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D6E8: jr          $ra
    // 0x8005D6EC: nop

    return;
    // 0x8005D6EC: nop

;}
RECOMP_FUNC void func_8042EBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EBA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042EBAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042EBB0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042EBB4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8042EBB8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042EBBC: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X33E4) << 16);
    // 0x8042EBC0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042EBC4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8042EBC8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042EBCC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042EBD0: lw          $t8, 0x14C4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X33E4));
    // 0x8042EBD4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042EBD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042EBDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042EBE0: jal         0x80048490
    // 0x8042EBE4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8042EBE4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8042EBE8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042EBEC: jal         0x80048378
    // 0x8042EBF0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8042EBF0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8042EBF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042EBF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042EBFC: jr          $ra
    // 0x8042EC00: nop

    return;
    // 0x8042EC00: nop

;}
RECOMP_FUNC void func_8042247C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042247C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80422480: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80422484: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80422488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042248C: jal         0x804222E4
    // 0x80422490: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    func_804222E4(rdram, ctx);
        goto after_0;
    // 0x80422490: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    after_0:
    // 0x80422494: beq         $v0, $zero, L_8042253C
    if (ctx->r2 == 0) {
        // 0x80422498: nop
    
            goto L_8042253C;
    }
    // 0x80422498: nop

    // 0x8042249C: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    // 0x804224A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804224A4: jal         0x8042231C
    // 0x804224A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8042231C(rdram, ctx);
        goto after_1;
    // 0x804224A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x804224AC: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804224B0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804224B4: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804224B8: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(32, 0X15B8) << 16);
    // 0x804224BC: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x804224C0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804224C4: addiu       $t7, $t7, 0x2678
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(32, 0X15B8));
    // 0x804224C8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804224CC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804224D0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804224D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804224D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804224DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804224E0: jal         0x80422558
    // 0x804224E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80422558(rdram, ctx);
        goto after_2;
    // 0x804224E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804224E8: lui         $t9, 0x8042
    ctx->r25 = S32(RELOC_HI16(32, 0X11FC) << 16);
    // 0x804224EC: addiu       $t9, $t9, 0x22BC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(32, 0X11FC));
    // 0x804224F0: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x804224F4: jal         0x8042227C
    // 0x804224F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042227C(rdram, ctx);
        goto after_3;
    // 0x804224F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804224FC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80422500: jal         0x80067BBC
    // 0x80422504: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x80422504: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80422508: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8042250C: jal         0x80067F78
    // 0x80422510: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_5;
    // 0x80422510: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80422514: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x80422518: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8042251C: jal         0x804220FC
    // 0x80422520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804220FC(rdram, ctx);
        goto after_6;
    // 0x80422520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80422524: bnel        $v0, $zero, L_80422548
    if (ctx->r2 != 0) {
        // 0x80422528: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80422548;
    }
    goto skip_0;
    // 0x80422528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8042252C: jal         0x800445A4
    // 0x80422530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x80422530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80422534: b           L_80422548
    // 0x80422538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80422548;
    // 0x80422538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042253C:
    // 0x8042253C: jal         0x800445A4
    // 0x80422540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x80422540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80422544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80422548:
    // 0x80422548: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042254C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80422550: jr          $ra
    // 0x80422554: nop

    return;
    // 0x80422554: nop

;}
RECOMP_FUNC void func_80442478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044247C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80442480: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EF0) << 16);
    // 0x80442484: lwc1        $f4, 0x3DF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EF0));
    // 0x80442488: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8044248C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x80442490: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80442494: nop

    // 0x80442498: bc1fl       L_804424D0
    if (!c1cs) {
        // 0x8044249C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804424D0;
    }
    goto skip_0;
    // 0x8044249C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804424A0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x804424A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804424A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804424AC: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x804424B0: lbu         $t8, 0x14($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X14);
    // 0x804424B4: beql        $t8, $zero, L_804424D0
    if (ctx->r24 == 0) {
        // 0x804424B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804424D0;
    }
    goto skip_1;
    // 0x804424B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804424BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804424C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804424C4: jal         0x8044284C
    // 0x804424C8: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    func_8044284C(rdram, ctx);
        goto after_0;
    // 0x804424C8: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x804424CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804424D0:
    // 0x804424D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804424D4: jr          $ra
    // 0x804424D8: nop

    return;
    // 0x804424D8: nop

;}
RECOMP_FUNC void func_8006DD34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DD3C: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8006DD40: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8006DD44: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8006DD48: swc1        $f4, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f4.u32l;
    // 0x8006DD4C: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x8006DD50: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006DD54: beq         $v0, $at, L_8006DD6C
    if (ctx->r2 == ctx->r1) {
        // 0x8006DD58: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8006DD6C;
    }
    // 0x8006DD58: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006DD5C: beq         $v0, $at, L_8006DD6C
    if (ctx->r2 == ctx->r1) {
        // 0x8006DD60: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006DD6C;
    }
    // 0x8006DD60: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006DD64: bnel        $v0, $at, L_8006DDB0
    if (ctx->r2 != ctx->r1) {
        // 0x8006DD68: lwc1        $f6, 0x2C($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
            goto L_8006DDB0;
    }
    goto skip_0;
    // 0x8006DD68: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    skip_0:
L_8006DD6C:
    // 0x8006DD6C: lw          $v0, 0x8D0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8D0);
    // 0x8006DD70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006DD74: lh          $t6, 0x7C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X7C);
    // 0x8006DD78: bnel        $t6, $at, L_8006DD94
    if (ctx->r14 != ctx->r1) {
        // 0x8006DD7C: lw          $a1, 0x62C($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X62C);
            goto L_8006DD94;
    }
    goto skip_1;
    // 0x8006DD7C: lw          $a1, 0x62C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X62C);
    skip_1:
    // 0x8006DD80: jal         0x8006DC38
    // 0x8006DD84: lw          $a1, 0x80($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X80);
    func_8006DC38(rdram, ctx);
        goto after_0;
    // 0x8006DD84: lw          $a1, 0x80($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X80);
    after_0:
    // 0x8006DD88: b           L_8006DDC0
    // 0x8006DD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006DDC0;
    // 0x8006DD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DD90: lw          $a1, 0x62C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X62C);
L_8006DD94:
    // 0x8006DD94: beql        $a1, $zero, L_8006DDB0
    if (ctx->r5 == 0) {
        // 0x8006DD98: lwc1        $f6, 0x2C($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
            goto L_8006DDB0;
    }
    goto skip_2;
    // 0x8006DD98: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    skip_2:
    // 0x8006DD9C: jal         0x8006DC38
    // 0x8006DDA0: nop

    func_8006DC38(rdram, ctx);
        goto after_1;
    // 0x8006DDA0: nop

    after_1:
    // 0x8006DDA4: b           L_8006DDC0
    // 0x8006DDA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006DDC0;
    // 0x8006DDA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DDAC: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
L_8006DDB0:
    // 0x8006DDB0: lwc1        $f8, 0x30($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006DDB4: swc1        $f6, 0x11C($a0)
    MEM_W(0X11C, ctx->r4) = ctx->f6.u32l;
    // 0x8006DDB8: swc1        $f8, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f8.u32l;
    // 0x8006DDBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006DDC0:
    // 0x8006DDC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DDC4: jr          $ra
    // 0x8006DDC8: nop

    return;
    // 0x8006DDC8: nop

;}
RECOMP_FUNC void func_80681428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8068142C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80681430: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80681434: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(550, 0X21D8) << 16);
    // 0x80681438: addiu       $t8, $t8, 0x25E8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(550, 0X21D8));
    // 0x8068143C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80681440: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80681444: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80681448: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8068144C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80681450: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80681454: beql        $v1, $zero, L_80681474
    if (ctx->r3 == 0) {
        // 0x80681458: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80681474;
    }
    goto skip_0;
    // 0x80681458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8068145C: jalr        $v1
    // 0x80681460: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80681460: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80681464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80681468: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8068146C: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80681470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80681474:
    // 0x80681474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80681478: jr          $ra
    // 0x8068147C: nop

    return;
    // 0x8068147C: nop

;}
RECOMP_FUNC void func_8078ED54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078ED54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078ED58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078ED5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078ED60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8078ED64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8078ED68: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078ED6C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8078ED70: jal         0x8004700C
    // 0x8078ED74: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078ED74: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x8078ED78: beq         $v0, $zero, L_8078ED94
    if (ctx->r2 == 0) {
        // 0x8078ED7C: nop
    
            goto L_8078ED94;
    }
    // 0x8078ED7C: nop

    // 0x8078ED80: lw          $t8, 0x180($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X180);
    // 0x8078ED84: bne         $s0, $t8, L_8078ED94
    if (ctx->r16 != ctx->r24) {
        // 0x8078ED88: nop
    
            goto L_8078ED94;
    }
    // 0x8078ED88: nop

    // 0x8078ED8C: jal         0x80060FE0
    // 0x8078ED90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060FE0(rdram, ctx);
        goto after_1;
    // 0x8078ED90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8078ED94:
    // 0x8078ED94: jal         0x8005FE48
    // 0x8078ED98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8078ED98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8078ED9C: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x8078EDA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8078EDA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078EDA8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8078EDAC: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    // 0x8078EDB0: sb          $t1, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r9;
    // 0x8078EDB4: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x8078EDB8: jal         0x8078F0A0
    // 0x8078EDBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8078F0A0(rdram, ctx);
        goto after_3;
    // 0x8078EDBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8078EDC0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8078EDC4: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8078EDC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078EDCC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8078EDD0: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8078EDD4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8078EDD8: jal         0x8078EBE8
    // 0x8078EDDC: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    func_8078EBE8(rdram, ctx);
        goto after_4;
    // 0x8078EDDC: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    after_4:
    // 0x8078EDE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078EDE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078EDE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078EDEC: jr          $ra
    // 0x8078EDF0: nop

    return;
    // 0x8078EDF0: nop

;}
RECOMP_FUNC void func_806FE3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FE3B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FE3BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FE3C0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806FE3C4: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(706, 0X1270) << 16);
    // 0x806FE3C8: addiu       $t6, $t6, -0x1930
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(706, 0X1270));
    // 0x806FE3CC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FE3D0: jal         0x806FE318
    // 0x806FE3D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806FE318(rdram, ctx);
        goto after_0;
    // 0x806FE3D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FE3D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FE3DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FE3E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806FE3E4: jal         0x806FE468
    // 0x806FE3E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806FE468(rdram, ctx);
        goto after_1;
    // 0x806FE3E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806FE3EC: jal         0x806FE2E0
    // 0x806FE3F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806FE2E0(rdram, ctx);
        goto after_2;
    // 0x806FE3F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806FE3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FE3F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FE3FC: jr          $ra
    // 0x806FE400: nop

    return;
    // 0x806FE400: nop

;}
RECOMP_FUNC void func_806CFAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFAB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CFABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CFAC0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CFAC4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x806CFAC8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806CFACC: lbu         $v0, 0x18($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X18);
    // 0x806CFAD0: beq         $v0, $at, L_806CFAE0
    if (ctx->r2 == ctx->r1) {
        // 0x806CFAD4: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_806CFAE0;
    }
    // 0x806CFAD4: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x806CFAD8: bnel        $v0, $at, L_806CFB1C
    if (ctx->r2 != ctx->r1) {
        // 0x806CFADC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806CFB1C;
    }
    goto skip_0;
    // 0x806CFADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_806CFAE0:
    // 0x806CFAE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806CFAE4: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806CFAE8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806CFAEC: nop

    // 0x806CFAF0: bc1f        L_806CFB08
    if (!c1cs) {
        // 0x806CFAF4: nop
    
            goto L_806CFB08;
    }
    // 0x806CFAF4: nop

    // 0x806CFAF8: jal         0x806CFDA8
    // 0x806CFAFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806CFDA8(rdram, ctx);
        goto after_0;
    // 0x806CFAFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x806CFB00: b           L_806CFB1C
    // 0x806CFB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806CFB1C;
    // 0x806CFB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806CFB08:
    // 0x806CFB08: jal         0x806CFDA8
    // 0x806CFB0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806CFDA8(rdram, ctx);
        goto after_1;
    // 0x806CFB0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806CFB10: b           L_806CFB1C
    // 0x806CFB14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806CFB1C;
    // 0x806CFB14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806CFB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806CFB1C:
    // 0x806CFB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CFB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CFB24: jr          $ra
    // 0x806CFB28: nop

    return;
    // 0x806CFB28: nop

;}
RECOMP_FUNC void func_80074C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074C88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074C8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80074C90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80074C94: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80074C98: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80074C9C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80074CA0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80074CA4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074CA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074CAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80074CB0: jal         0x80074588
    // 0x80074CB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80074588(rdram, ctx);
        goto after_0;
    // 0x80074CB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80074CB8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80074CBC: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80074CC0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80074CC4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80074CC8: addiu       $s1, $s1, 0x230
    ctx->r17 = ADD32(ctx->r17, 0X230);
L_80074CCC:
    // 0x80074CCC: beql        $s4, $zero, L_80074D4C
    if (ctx->r20 == 0) {
        // 0x80074CD0: lwl         $t9, 0x0($s0)
        ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r16, 0X0);
            goto L_80074D4C;
    }
    goto skip_0;
    // 0x80074CD0: lwl         $t9, 0x0($s0)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r16, 0X0);
    skip_0:
    // 0x80074CD4: lwl         $t7, 0x0($s1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r17, 0X0);
    // 0x80074CD8: lwr         $t7, 0x3($s1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r17, 0X3);
    // 0x80074CDC: swl         $t7, 0x0($s0)
    do_swl(rdram, 0X0, ctx->r16, ctx->r15);
    // 0x80074CE0: swr         $t7, 0x3($s0)
    do_swr(rdram, 0X3, ctx->r16, ctx->r15);
    // 0x80074CE4: lwl         $t6, 0x4($s1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r17, 0X4);
    // 0x80074CE8: lwr         $t6, 0x7($s1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r17, 0X7);
    // 0x80074CEC: swl         $t6, 0x4($s0)
    do_swl(rdram, 0X4, ctx->r16, ctx->r14);
    // 0x80074CF0: swr         $t6, 0x7($s0)
    do_swr(rdram, 0X7, ctx->r16, ctx->r14);
    // 0x80074CF4: lwl         $t7, 0x8($s1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r17, 0X8);
    // 0x80074CF8: lwr         $t7, 0xB($s1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r17, 0XB);
    // 0x80074CFC: swl         $t7, 0x8($s0)
    do_swl(rdram, 0X8, ctx->r16, ctx->r15);
    // 0x80074D00: swr         $t7, 0xB($s0)
    do_swr(rdram, 0XB, ctx->r16, ctx->r15);
    // 0x80074D04: lwl         $t6, 0xC($s1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r17, 0XC);
    // 0x80074D08: lwr         $t6, 0xF($s1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r17, 0XF);
    // 0x80074D0C: swl         $t6, 0xC($s0)
    do_swl(rdram, 0XC, ctx->r16, ctx->r14);
    // 0x80074D10: swr         $t6, 0xF($s0)
    do_swr(rdram, 0XF, ctx->r16, ctx->r14);
    // 0x80074D14: lwl         $t7, 0x10($s1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r17, 0X10);
    // 0x80074D18: lwr         $t7, 0x13($s1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r17, 0X13);
    // 0x80074D1C: swl         $t7, 0x10($s0)
    do_swl(rdram, 0X10, ctx->r16, ctx->r15);
    // 0x80074D20: swr         $t7, 0x13($s0)
    do_swr(rdram, 0X13, ctx->r16, ctx->r15);
    // 0x80074D24: lwl         $t6, 0x14($s1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r17, 0X14);
    // 0x80074D28: lwr         $t6, 0x17($s1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r17, 0X17);
    // 0x80074D2C: swl         $t6, 0x14($s0)
    do_swl(rdram, 0X14, ctx->r16, ctx->r14);
    // 0x80074D30: swr         $t6, 0x17($s0)
    do_swr(rdram, 0X17, ctx->r16, ctx->r14);
    // 0x80074D34: sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // 0x80074D38: sb          $zero, 0xE($s1)
    MEM_B(0XE, ctx->r17) = 0;
    // 0x80074D3C: sb          $zero, 0xF($s1)
    MEM_B(0XF, ctx->r17) = 0;
    // 0x80074D40: b           L_80074DCC
    // 0x80074D44: sh          $zero, 0x12($s1)
    MEM_H(0X12, ctx->r17) = 0;
        goto L_80074DCC;
    // 0x80074D44: sh          $zero, 0x12($s1)
    MEM_H(0X12, ctx->r17) = 0;
    // 0x80074D48: lwl         $t9, 0x0($s0)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r16, 0X0);
L_80074D4C:
    // 0x80074D4C: lwr         $t9, 0x3($s0)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r16, 0X3);
    // 0x80074D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074D54: swl         $t9, 0x6($s0)
    do_swl(rdram, 0X6, ctx->r16, ctx->r25);
    // 0x80074D58: swr         $t9, 0x9($s0)
    do_swr(rdram, 0X9, ctx->r16, ctx->r25);
    // 0x80074D5C: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x80074D60: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x80074D64: sh          $t9, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r25;
    // 0x80074D68: lwl         $t1, 0x0($s1)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r17, 0X0);
    // 0x80074D6C: lwr         $t1, 0x3($s1)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r17, 0X3);
    // 0x80074D70: swl         $t1, 0x0($s0)
    do_swl(rdram, 0X0, ctx->r16, ctx->r9);
    // 0x80074D74: swr         $t1, 0x3($s0)
    do_swr(rdram, 0X3, ctx->r16, ctx->r9);
    // 0x80074D78: lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X0);
    // 0x80074D7C: lhu         $t1, 0x4($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X4);
    // 0x80074D80: xor         $v0, $v1, $a1
    ctx->r2 = ctx->r3 ^ ctx->r5;
    // 0x80074D84: and         $t3, $v1, $v0
    ctx->r11 = ctx->r3 & ctx->r2;
    // 0x80074D88: and         $t2, $a1, $v0
    ctx->r10 = ctx->r5 & ctx->r2;
    // 0x80074D8C: sh          $t2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r10;
    // 0x80074D90: sh          $t3, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r11;
    // 0x80074D94: jal         0x8007FC14
    // 0x80074D98: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    pad_correct_stick(rdram, ctx);
        goto after_1;
    // 0x80074D98: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    after_1:
    // 0x80074D9C: lb          $t4, 0x2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X2);
    // 0x80074DA0: lb          $t5, 0x8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X8);
    // 0x80074DA4: lb          $t1, 0x3($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X3);
    // 0x80074DA8: lb          $t2, 0x9($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X9);
    // 0x80074DAC: lb          $t9, 0xE($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XE);
    // 0x80074DB0: lb          $t6, 0xF($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XF);
    // 0x80074DB4: subu        $t8, $t4, $t5
    ctx->r24 = SUB32(ctx->r12, ctx->r13);
    // 0x80074DB8: subu        $t5, $t1, $t2
    ctx->r13 = SUB32(ctx->r9, ctx->r10);
    // 0x80074DBC: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80074DC0: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80074DC4: sb          $t0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r8;
    // 0x80074DC8: sb          $t7, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r15;
L_80074DCC:
    // 0x80074DCC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80074DD0: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x80074DD4: bne         $s2, $s3, L_80074CCC
    if (ctx->r18 != ctx->r19) {
        // 0x80074DD8: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80074CCC;
    }
    // 0x80074DD8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80074DDC: jal         0x800745B4
    // 0x80074DE0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800745B4(rdram, ctx);
        goto after_2;
    // 0x80074DE0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80074DE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80074DE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074DEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074DF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074DF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80074DF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80074DFC: jr          $ra
    // 0x80074E00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80074E00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Main_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069008: jal         0x8007127C
    // 0x8006900C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Fault_Init(rdram, ctx);
        goto after_0;
    // 0x8006900C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80069010: jal         0x80068F10
    // 0x80069014: nop

    func_80068F10(rdram, ctx);
        goto after_1;
    // 0x80069014: nop

    after_1:
    // 0x80069018: jal         0x80068E24
    // 0x8006901C: nop

    func_80068E24(rdram, ctx);
        goto after_2;
    // 0x8006901C: nop

    after_2:
    // 0x80069020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069028: jr          $ra
    // 0x8006902C: nop

    return;
    // 0x8006902C: nop

;}
RECOMP_FUNC void func_80741E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741E3C: jr          $ra
    // 0x80741E40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80741E40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804B6DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6DF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B6DFC: jal         0x804B6CE4
    // 0x804B6E00: addiu       $a1, $zero, 0x4041
    ctx->r5 = ADD32(0, 0X4041);
    func_804B6CE4(rdram, ctx);
        goto after_0;
    // 0x804B6E00: addiu       $a1, $zero, 0x4041
    ctx->r5 = ADD32(0, 0X4041);
    after_0:
    // 0x804B6E04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6E08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6E0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804B6E10: jal         0x804B6FF0
    // 0x804B6E14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6E14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6E20: jr          $ra
    // 0x804B6E24: nop

    return;
    // 0x804B6E24: nop

;}
RECOMP_FUNC void func_806780B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806780B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806780B8: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x806780BC: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x806780C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x806780C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806780C8: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x806780CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x806780D0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x806780D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806780D8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x806780DC: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x806780E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x806780E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806780E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806780EC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x806780F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806780F4: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x806780F8: addiu       $t3, $zero, 0x2C80
    ctx->r11 = ADD32(0, 0X2C80);
    // 0x806780FC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80678100: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80678104: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80678108: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8067810C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80678110: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x80678114: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x80678118: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8067811C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80678120: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x80678124: ori         $a3, $a3, 0x41C8
    ctx->r7 = ctx->r7 | 0X41C8;
    // 0x80678128: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8067812C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80678130: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80678134: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80678138: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8067813C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80678140: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80678144: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80678148: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8067814C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80678150: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x80678154: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80678158: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8067815C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80678160: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80678164: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x80678168: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8067816C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80678170: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80678174: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x80678178: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x8067817C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80678180: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80678184: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80678188: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8067818C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80678190: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80678194: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80678198: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8067819C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x806781A0: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x806781A4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x806781A8: jr          $ra
    // 0x806781AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x806781AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_806E01C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E01C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E01CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E01D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806E01D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806E01D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806E01DC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806E01E0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806E01E4: bnel        $v0, $at, L_806E0210
    if (ctx->r2 != ctx->r1) {
        // 0x806E01E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E0210;
    }
    goto skip_0;
    // 0x806E01E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E01EC: jal         0x806DFE34
    // 0x806E01F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_806DFE34(rdram, ctx);
        goto after_0;
    // 0x806E01F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806E01F4: bne         $v0, $zero, L_806E020C
    if (ctx->r2 != 0) {
        // 0x806E01F8: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_806E020C;
    }
    // 0x806E01F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806E01FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E0200: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806E0204: jal         0x806E0004
    // 0x806E0208: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_806E0004(rdram, ctx);
        goto after_1;
    // 0x806E0208: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
L_806E020C:
    // 0x806E020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E0210:
    // 0x806E0210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E0214: jr          $ra
    // 0x806E0218: nop

    return;
    // 0x806E0218: nop

;}
RECOMP_FUNC void func_804CB83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB83C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CB840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CB844: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CB848: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804CB84C: jal         0x80065954
    // 0x804CB850: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x804CB850: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    after_0:
    // 0x804CB854: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804CB858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804CB85C: nop

    // 0x804CB860: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x804CB864: nop

    // 0x804CB868: bc1t        L_804CB888
    if (c1cs) {
        // 0x804CB86C: nop
    
            goto L_804CB888;
    }
    // 0x804CB86C: nop

    // 0x804CB870: jal         0x8004700C
    // 0x804CB874: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x804CB874: nop

    after_1:
    // 0x804CB878: lbu         $t7, 0x18($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18);
    // 0x804CB87C: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x804CB880: bnel        $at, $zero, L_804CB920
    if (ctx->r1 != 0) {
        // 0x804CB884: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CB920;
    }
    goto skip_0;
    // 0x804CB884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_804CB888:
    // 0x804CB888: jal         0x8004700C
    // 0x804CB88C: nop

    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x804CB88C: nop

    after_2:
    // 0x804CB890: beql        $v0, $zero, L_804CB920
    if (ctx->r2 == 0) {
        // 0x804CB894: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CB920;
    }
    goto skip_1;
    // 0x804CB894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x804CB898: lw          $s0, 0x1F4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X1F4);
    // 0x804CB89C: jal         0x800653D8
    // 0x804CB8A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x804CB8A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x804CB8A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804CB8A8: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x804CB8AC: jal         0x804CB704
    // 0x804CB8B0: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    func_804CB704(rdram, ctx);
        goto after_4;
    // 0x804CB8B0: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    after_4:
    // 0x804CB8B4: jal         0x8001D770
    // 0x804CB8B8: nop

    func_8001D770(rdram, ctx);
        goto after_5;
    // 0x804CB8B8: nop

    after_5:
    // 0x804CB8BC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x804CB8C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804CB8C4: lw          $a1, 0x34($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X34);
    // 0x804CB8C8: jal         0x80067BF8
    // 0x804CB8CC: lw          $a2, 0x38($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_6;
    // 0x804CB8CC: lw          $a2, 0x38($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X38);
    after_6:
    // 0x804CB8D0: addiu       $a0, $zero, 0x21A
    ctx->r4 = ADD32(0, 0X21A);
    // 0x804CB8D4: jal         0x80067818
    // 0x804CB8D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x804CB8D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x804CB8DC: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x804CB8E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CB8E4: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x804CB8E8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CB8EC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x804CB8F0: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x804CB8F4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CB8F8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x804CB8FC: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
    // 0x804CB900: lbu         $t2, 0x12C9($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12C9);
    // 0x804CB904: sb          $zero, 0x12E8($s0)
    MEM_B(0X12E8, ctx->r16) = 0;
    // 0x804CB908: sw          $zero, 0x12EC($s0)
    MEM_W(0X12EC, ctx->r16) = 0;
    // 0x804CB90C: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x804CB910: sb          $t3, 0x12C9($s0)
    MEM_B(0X12C9, ctx->r16) = ctx->r11;
    // 0x804CB914: jal         0x8002FF38
    // 0x804CB918: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8002FF38(rdram, ctx);
        goto after_8;
    // 0x804CB918: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x804CB91C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CB920:
    // 0x804CB920: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CB924: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CB928: jr          $ra
    // 0x804CB92C: nop

    return;
    // 0x804CB92C: nop

;}
RECOMP_FUNC void func_80444C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444C94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80444C98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80444C9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80444CA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80444CA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80444CA8: jal         0x80047090
    // 0x80444CAC: addiu       $a0, $zero, 0x40F5
    ctx->r4 = ADD32(0, 0X40F5);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80444CAC: addiu       $a0, $zero, 0x40F5
    ctx->r4 = ADD32(0, 0X40F5);
    after_0:
    // 0x80444CB0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80444CB4: beq         $v0, $at, L_80444D48
    if (ctx->r2 == ctx->r1) {
        // 0x80444CB8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80444D48;
    }
    // 0x80444CB8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80444CBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80444CC0: lui         $at, 0x40F5
    ctx->r1 = S32(0X40F5 << 16);
    // 0x80444CC4: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80444CC8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80444CCC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80444CD0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80444CD4: jal         0x8004613C
    // 0x80444CD8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80444CD8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x80444CDC: beq         $v0, $zero, L_80444D48
    if (ctx->r2 == 0) {
        // 0x80444CE0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80444D48;
    }
    // 0x80444CE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80444CE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80444CE8: jal         0x80047F9C
    // 0x80444CEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444CEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80444CF0: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x80444CF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80444CF8: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x80444CFC: jalr        $t9
    // 0x80444D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80444D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80444D04: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80444D08: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80444D0C: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x80444D10: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FE4) << 16);
    // 0x80444D14: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80444D18: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x80444D1C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80444D20: lw          $t8, 0x478($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X478);
    // 0x80444D24: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80444D28: swc1        $f0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f0.u32l;
    // 0x80444D2C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80444D30: lw          $t0, 0x478($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X478);
    // 0x80444D34: lwc1        $f6, -0x7C3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FE4));
    // 0x80444D38: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80444D3C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80444D40: swc1        $f0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f0.u32l;
    // 0x80444D44: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_80444D48:
    // 0x80444D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80444D4C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80444D50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80444D54: jr          $ra
    // 0x80444D58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80444D58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_807A5DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A5DC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807A5DCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A5DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A5DD4: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x807A5DD8: nop

    // 0x807A5DDC: bc1fl       L_807A5DF0
    if (!c1cs) {
        // 0x807A5DE0: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_807A5DF0;
    }
    goto skip_0;
    // 0x807A5DE0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x807A5DE4: b           L_807A5E14
    // 0x807A5DE8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_807A5E14;
    // 0x807A5DE8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x807A5DEC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_807A5DF0:
    // 0x807A5DF0: jal         0x80065414
    // 0x807A5DF4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x807A5DF4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x807A5DF8: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x807A5DFC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807A5E00: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807A5E04: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x807A5E08: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x807A5E0C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x807A5E10: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_807A5E14:
    // 0x807A5E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A5E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A5E1C: jr          $ra
    // 0x807A5E20: nop

    return;
    // 0x807A5E20: nop

;}
RECOMP_FUNC void func_80067D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067D9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067DA0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80067DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067DA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067DAC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80067DB0: jal         0x80067D5C
    // 0x80067DB4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80067DB4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80067DB8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067DBC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067DC0: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067DC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80067DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067DD0: jr          $ra
    // 0x80067DD4: nop

    return;
    // 0x80067DD4: nop

;}
RECOMP_FUNC void func_804334D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804334D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804334DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804334E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804334E4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804334E8: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(65, 0X928) << 16);
    // 0x804334EC: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x804334F0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804334F4: addiu       $t6, $t6, 0x3708
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(65, 0X928));
    // 0x804334F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804334FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80433500: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80433504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80433508: jal         0x80433634
    // 0x8043350C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80433634(rdram, ctx);
        goto after_0;
    // 0x8043350C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80433510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80433514: jal         0x80045A34
    // 0x80433518: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80433518: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_1:
    // 0x8043351C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80433520: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80433524: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(65, 0X964) << 16);
    // 0x80433528: lwc1        $f2, 0x3744($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X964));
    // 0x8043352C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80433530: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80433534: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80433538: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8043353C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80433540: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80433544: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80433548: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8043354C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80433550: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80433554: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80433558: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(65, 0X968) << 16);
    // 0x8043355C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80433560: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80433564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80433568: div.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8043356C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80433570: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x80433574: lwc1        $f8, 0x3748($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X968));
    // 0x80433578: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043357C: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x80433580: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80433584: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80433588: sh          $zero, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = 0;
    // 0x8043358C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80433590: div.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80433594: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80433598: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x8043359C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804335A0: jal         0x80433430
    // 0x804335A4: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    func_80433430(rdram, ctx);
        goto after_2;
    // 0x804335A4: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    after_2:
    // 0x804335A8: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(65, 0X6D0) << 16);
    // 0x804335AC: addiu       $t9, $t9, 0x34B0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(65, 0X6D0));
    // 0x804335B0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x804335B4: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x804335B8: sh          $t0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r8;
    // 0x804335BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804335C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804335C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804335C8: jr          $ra
    // 0x804335CC: nop

    return;
    // 0x804335CC: nop

;}
RECOMP_FUNC void func_807C3F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3F00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C3F04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807C3F08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807C3F0C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x807C3F10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C3F14: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807C3F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807C3F1C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807C3F20: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x807C3F24: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x807C3F28: nop

    // 0x807C3F2C: slti        $at, $a3, 0x80
    ctx->r1 = SIGNED(ctx->r7) < 0X80 ? 1 : 0;
    // 0x807C3F30: bne         $at, $zero, L_807C3F40
    if (ctx->r1 != 0) {
        // 0x807C3F34: nop
    
            goto L_807C3F40;
    }
    // 0x807C3F34: nop

    // 0x807C3F38: b           L_807C3F4C
    // 0x807C3F3C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
        goto L_807C3F4C;
    // 0x807C3F3C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
L_807C3F40:
    // 0x807C3F40: bgezl       $a3, L_807C3F50
    if (SIGNED(ctx->r7) >= 0) {
        // 0x807C3F44: lh          $t7, 0x1F0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X1F0);
            goto L_807C3F50;
    }
    goto skip_0;
    // 0x807C3F44: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
    skip_0:
    // 0x807C3F48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_807C3F4C:
    // 0x807C3F4C: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
L_807C3F50:
    // 0x807C3F50: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x807C3F54: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C3F58: bnel        $t7, $at, L_807C3F88
    if (ctx->r15 != ctx->r1) {
        // 0x807C3F5C: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_807C3F88;
    }
    goto skip_1;
    // 0x807C3F5C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x807C3F60: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C3F64: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x807C3F68: jal         0x80067D5C
    // 0x807C3F6C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x807C3F6C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x807C3F70: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x807C3F74: jal         0x80067F78
    // 0x807C3F78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x807C3F78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807C3F7C: b           L_807C3FA0
    // 0x807C3F80: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_807C3FA0;
    // 0x807C3F80: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x807C3F84: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_807C3F88:
    // 0x807C3F88: jal         0x80067D5C
    // 0x807C3F8C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x807C3F8C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x807C3F90: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x807C3F94: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x807C3F98: jal         0x800678F0
    // 0x807C3F9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x807C3F9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_807C3FA0:
    // 0x807C3FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807C3FA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807C3FA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C3FAC: jr          $ra
    // 0x807C3FB0: nop

    return;
    // 0x807C3FB0: nop

;}
RECOMP_FUNC void func_8045FF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FF6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045FF70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8045FF74: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8045FF78: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8045FF7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045FF80: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8045FF84: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8045FF88: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8045FF8C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045FF90: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8045FF94: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(116, 0X388) << 16);
    // 0x8045FF98: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8045FF9C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8045FFA0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8045FFA4: lw          $t2, 0x58($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(116, 0X388));
    // 0x8045FFA8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8045FFAC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8045FFB0: jal         0x8045FD80
    // 0x8045FFB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045FD80(rdram, ctx);
        goto after_0;
    // 0x8045FFB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045FFB8: jal         0x8045FDDC
    // 0x8045FFBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8045FDDC(rdram, ctx);
        goto after_1;
    // 0x8045FFBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045FFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045FFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045FFC8: jr          $ra
    // 0x8045FFCC: nop

    return;
    // 0x8045FFCC: nop

;}
RECOMP_FUNC void func_807B90E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B90E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B90EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B90F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B90F4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x807B90F8: addiu       $a1, $a1, -0x71A8
    ctx->r5 = ADD32(ctx->r5, -0X71A8);
    // 0x807B90FC: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x807B9100: jal         0x800655F4
    // 0x807B9104: addiu       $a0, $v0, 0x4C
    ctx->r4 = ADD32(ctx->r2, 0X4C);
    func_800655F4(rdram, ctx);
        goto after_0;
    // 0x807B9104: addiu       $a0, $v0, 0x4C
    ctx->r4 = ADD32(ctx->r2, 0X4C);
    after_0:
    // 0x807B9108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B910C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B9110: jr          $ra
    // 0x807B9114: nop

    return;
    // 0x807B9114: nop

;}
RECOMP_FUNC void func_8044FE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044FE40: blez        $a0, L_8044FE58
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8044FE44: slti        $at, $a0, 0x7
        ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
            goto L_8044FE58;
    }
    // 0x8044FE44: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x8044FE48: beql        $at, $zero, L_8044FE5C
    if (ctx->r1 == 0) {
        // 0x8044FE4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8044FE5C;
    }
    goto skip_0;
    // 0x8044FE4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8044FE50: jr          $ra
    // 0x8044FE54: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    return;
    // 0x8044FE54: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_8044FE58:
    // 0x8044FE58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8044FE5C:
    // 0x8044FE5C: jr          $ra
    // 0x8044FE60: nop

    return;
    // 0x8044FE60: nop

;}
RECOMP_FUNC void func_804747CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804747CC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x804747D0: beql        $at, $zero, L_804747E4
    if (ctx->r1 == 0) {
        // 0x804747D4: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_804747E4;
    }
    goto skip_0;
    // 0x804747D4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x804747D8: jr          $ra
    // 0x804747DC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x804747DC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x804747E0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_804747E4:
    // 0x804747E4: beq         $at, $zero, L_8047481C
    if (ctx->r1 == 0) {
        // 0x804747E8: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_8047481C;
    }
    // 0x804747E8: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x804747EC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x804747F0: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x804747F4: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804747F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804747FC: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x80474800: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80474804: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80474808: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8047480C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80474810: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80474814: jr          $ra
    // 0x80474818: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x80474818: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_8047481C:
    // 0x8047481C: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80474820: beq         $at, $zero, L_80474830
    if (ctx->r1 == 0) {
        // 0x80474824: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_80474830;
    }
    // 0x80474824: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80474828: jr          $ra
    // 0x8047482C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    return;
    // 0x8047482C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
L_80474830:
    // 0x80474830: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80474834: beq         $at, $zero, L_80474870
    if (ctx->r1 == 0) {
        // 0x80474838: lwc1        $f0, 0x1C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80474870;
    }
    // 0x80474838: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8047483C: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x80474840: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80474844: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80474848: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8047484C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80474850: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x80474854: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80474858: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8047485C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80474860: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80474864: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80474868: jr          $ra
    // 0x8047486C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x8047486C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_80474870:
    // 0x80474870: jr          $ra
    // 0x80474874: nop

    return;
    // 0x80474874: nop

;}
RECOMP_FUNC void func_80058CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058CC0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80058CC4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80058CC8: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x80058CCC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80058CD0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80058CD4: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80058CD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80058CDC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80058CE0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80058CE4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80058CE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058CEC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80058CF0: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80058CF4: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x80058CF8: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80058CFC: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80058D00: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80058D04: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80058D08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058D0C: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80058D10: lw          $t8, 0x478($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X478);
    // 0x80058D14: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80058D18: lwc1        $f18, 0x38($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X38);
    // 0x80058D1C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80058D20: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80058D24: jr          $ra
    // 0x80058D28: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80058D28: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8046DCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046DCDC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8046DCE0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8046DCE4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8046DCE8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8046DCEC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8046DCF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8046DCF4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8046DCF8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8046DCFC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8046DD00: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8046DD04: jr          $ra
    // 0x8046DD08: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8046DD08: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8003F75C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F75C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003F760: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F764: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003F768: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8003F76C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8003F770: slti        $at, $v0, 0x406D
    ctx->r1 = SIGNED(ctx->r2) < 0X406D ? 1 : 0;
    // 0x8003F774: bne         $at, $zero, L_8003F794
    if (ctx->r1 != 0) {
        // 0x8003F778: addiu       $at, $zero, 0x4144
        ctx->r1 = ADD32(0, 0X4144);
            goto L_8003F794;
    }
    // 0x8003F778: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003F77C: beq         $v0, $at, L_8003F7DC
    if (ctx->r2 == ctx->r1) {
        // 0x8003F780: addiu       $at, $zero, 0x4301
        ctx->r1 = ADD32(0, 0X4301);
            goto L_8003F7DC;
    }
    // 0x8003F780: addiu       $at, $zero, 0x4301
    ctx->r1 = ADD32(0, 0X4301);
    // 0x8003F784: beql        $v0, $at, L_8003F7EC
    if (ctx->r2 == ctx->r1) {
        // 0x8003F788: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8003F7EC;
    }
    goto skip_0;
    // 0x8003F788: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    skip_0:
    // 0x8003F78C: b           L_8003F7F4
    // 0x8003F790: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
        goto L_8003F7F4;
    // 0x8003F790: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_8003F794:
    // 0x8003F794: slti        $at, $v0, 0x4020
    ctx->r1 = SIGNED(ctx->r2) < 0X4020 ? 1 : 0;
    // 0x8003F798: bne         $at, $zero, L_8003F7B4
    if (ctx->r1 != 0) {
        // 0x8003F79C: addiu       $t6, $v0, -0x4002
        ctx->r14 = ADD32(ctx->r2, -0X4002);
            goto L_8003F7B4;
    }
    // 0x8003F79C: addiu       $t6, $v0, -0x4002
    ctx->r14 = ADD32(ctx->r2, -0X4002);
    // 0x8003F7A0: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8003F7A4: beql        $v0, $at, L_8003F7E0
    if (ctx->r2 == ctx->r1) {
        // 0x8003F7A8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003F7E0;
    }
    goto skip_1;
    // 0x8003F7A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_1:
    // 0x8003F7AC: b           L_8003F7F4
    // 0x8003F7B0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
        goto L_8003F7F4;
    // 0x8003F7B0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_8003F7B4:
    // 0x8003F7B4: sltiu       $at, $t6, 0x1E
    ctx->r1 = ctx->r14 < 0X1E ? 1 : 0;
    // 0x8003F7B8: beq         $at, $zero, L_8003F7F0
    if (ctx->r1 == 0) {
        // 0x8003F7BC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8003F7F0;
    }
    // 0x8003F7BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003F7C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003F7C4: addu        $at, $at, $t6
    gpr jr_addend_8003F7CC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003F7C8: lw          $t6, 0x250($at)
    ctx->r14 = ADD32(ctx->r1, 0X250);
    // 0x8003F7CC: jr          $t6
    // 0x8003F7D0: nop

    switch (jr_addend_8003F7CC >> 2) {
        case 0: goto L_8003F7D4; break;
        case 1: goto L_8003F7F0; break;
        case 2: goto L_8003F7D4; break;
        case 3: goto L_8003F7D4; break;
        case 4: goto L_8003F7F0; break;
        case 5: goto L_8003F7F0; break;
        case 6: goto L_8003F7F0; break;
        case 7: goto L_8003F7F0; break;
        case 8: goto L_8003F7F0; break;
        case 9: goto L_8003F7F0; break;
        case 10: goto L_8003F7F0; break;
        case 11: goto L_8003F7F0; break;
        case 12: goto L_8003F7F0; break;
        case 13: goto L_8003F7F0; break;
        case 14: goto L_8003F7F0; break;
        case 15: goto L_8003F7F0; break;
        case 16: goto L_8003F7F0; break;
        case 17: goto L_8003F7F0; break;
        case 18: goto L_8003F7F0; break;
        case 19: goto L_8003F7F0; break;
        case 20: goto L_8003F7F0; break;
        case 21: goto L_8003F7F0; break;
        case 22: goto L_8003F7F0; break;
        case 23: goto L_8003F7F0; break;
        case 24: goto L_8003F7F0; break;
        case 25: goto L_8003F7F0; break;
        case 26: goto L_8003F7E8; break;
        case 27: goto L_8003F7E8; break;
        case 28: goto L_8003F7F0; break;
        case 29: goto L_8003F7E8; break;
        default: switch_error(__func__, 0x8003F7CC, 0x800B0250);
    }
    // 0x8003F7D0: nop

L_8003F7D4:
    // 0x8003F7D4: b           L_8003F7F0
    // 0x8003F7D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
        goto L_8003F7F0;
    // 0x8003F7D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8003F7DC:
    // 0x8003F7DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8003F7E0:
    // 0x8003F7E0: b           L_8003F7F0
    // 0x8003F7E4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_8003F7F0;
    // 0x8003F7E4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8003F7E8:
    // 0x8003F7E8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
L_8003F7EC:
    // 0x8003F7EC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8003F7F0:
    // 0x8003F7F0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_8003F7F4:
    // 0x8003F7F4: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8003F7F8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8003F7FC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003F800: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8003F804: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003F808: lhu         $t4, 0xC($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0XC);
    // 0x8003F80C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F810: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8003F814: xori        $t5, $t4, 0x4004
    ctx->r13 = ctx->r12 ^ 0X4004;
    // 0x8003F818: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8003F81C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8003F820: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8003F824: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8003F828: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003F82C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8003F830: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003F834: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8003F838: lw          $t9, -0x1068($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1068);
    // 0x8003F83C: lhu         $a2, 0x3E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X3E);
    // 0x8003F840: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8003F844: jalr        $t9
    // 0x8003F848: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003F848: nop

    after_0:
    // 0x8003F84C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F850: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003F854: jr          $ra
    // 0x8003F858: nop

    return;
    // 0x8003F858: nop

;}
RECOMP_FUNC void func_8005BF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BF50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005BF54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005BF58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005BF5C: sll         $s0, $a3, 16
    ctx->r16 = S32(ctx->r7 << 16);
    // 0x8005BF60: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005BF64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005BF68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005BF6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005BF70: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8005BF74: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8005BF78: lhu         $a1, 0x2A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2A);
    // 0x8005BF7C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8005BF80: jal         0x8005BE80
    // 0x8005BF84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8005BE80(rdram, ctx);
        goto after_0;
    // 0x8005BF84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8005BF88: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005BF8C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8005BF90: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
L_8005BF94:
    // 0x8005BF94: blez        $a2, L_8005C040
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8005BF98: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005C040;
    }
    // 0x8005BF98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005BF9C: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BFA0: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x8005BFA4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8005BFA8: sll         $a0, $t0, 3
    ctx->r4 = S32(ctx->r8 << 3);
    // 0x8005BFAC: mflo        $t6
    ctx->r14 = lo;
    // 0x8005BFB0: addu        $t1, $s1, $t6
    ctx->r9 = ADD32(ctx->r17, ctx->r14);
    // 0x8005BFB4: beq         $a3, $zero, L_8005BFE0
    if (ctx->r7 == 0) {
        // 0x8005BFB8: addu        $v0, $t1, $zero
        ctx->r2 = ADD32(ctx->r9, 0);
            goto L_8005BFE0;
    }
    // 0x8005BFB8: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
L_8005BFBC:
    // 0x8005BFBC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005BFC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005BFC4: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8005BFC8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8005BFCC: lbu         $t3, 0x0($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X0);
    // 0x8005BFD0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005BFD4: bne         $a1, $v1, L_8005BFBC
    if (ctx->r5 != ctx->r3) {
        // 0x8005BFD8: sb          $t3, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r11;
            goto L_8005BFBC;
    }
    // 0x8005BFD8: sb          $t3, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r11;
    // 0x8005BFDC: beq         $v1, $a2, L_8005C040
    if (ctx->r3 == ctx->r6) {
        // 0x8005BFE0: addu        $v0, $t1, $v1
        ctx->r2 = ADD32(ctx->r9, ctx->r3);
            goto L_8005C040;
    }
L_8005BFE0:
    // 0x8005BFE0: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
L_8005BFE4:
    // 0x8005BFE4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8005BFE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005BFEC: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x8005BFF0: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8005BFF4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8005BFF8: sb          $t7, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r15;
    // 0x8005BFFC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005C000: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8005C004: addu        $t3, $t9, $v1
    ctx->r11 = ADD32(ctx->r25, ctx->r3);
    // 0x8005C008: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8005C00C: sb          $t4, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r12;
    // 0x8005C010: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8005C014: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x8005C018: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8005C01C: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x8005C020: sb          $t8, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r24;
    // 0x8005C024: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005C028: addu        $t3, $t9, $a0
    ctx->r11 = ADD32(ctx->r25, ctx->r4);
    // 0x8005C02C: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8005C030: lbu         $t5, 0x3($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X3);
    // 0x8005C034: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005C038: bne         $v1, $a2, L_8005BFE4
    if (ctx->r3 != ctx->r6) {
        // 0x8005C03C: sb          $t5, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r13;
            goto L_8005BFE4;
    }
    // 0x8005C03C: sb          $t5, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r13;
L_8005C040:
    // 0x8005C040: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005C044: bne         $t0, $t2, L_8005BF94
    if (ctx->r8 != ctx->r10) {
        // 0x8005C048: nop
    
            goto L_8005BF94;
    }
    // 0x8005C048: nop

    // 0x8005C04C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C050: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005C054: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005C058: jr          $ra
    // 0x8005C05C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005C05C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80448AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448AA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448AAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80448AB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80448AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448AB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80448ABC: bne         $a2, $zero, L_80448AFC
    if (ctx->r6 != 0) {
        // 0x80448AC0: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80448AFC;
    }
    // 0x80448AC0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448AC4: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80448AC8: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x80448ACC: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80448AD0: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80448AD4: bne         $at, $zero, L_80448B3C
    if (ctx->r1 != 0) {
        // 0x80448AD8: sw          $t7, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r15;
            goto L_80448B3C;
    }
    // 0x80448AD8: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x80448ADC: jal         0x80446758
    // 0x80448AE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446758(rdram, ctx);
        goto after_0;
    // 0x80448AE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80448AE4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448AE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448AEC: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80448AF0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448AF4: b           L_80448B3C
    // 0x80448AF8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80448B3C;
    // 0x80448AF8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80448AFC:
    // 0x80448AFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448B00: bnel        $a2, $at, L_80448B2C
    if (ctx->r6 != ctx->r1) {
        // 0x80448B04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80448B2C;
    }
    goto skip_0;
    // 0x80448B04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448B08: jal         0x80446758
    // 0x80448B0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446758(rdram, ctx);
        goto after_1;
    // 0x80448B0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448B10: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448B14: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448B18: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80448B1C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448B20: b           L_80448B3C
    // 0x80448B24: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80448B3C;
    // 0x80448B24: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80448B28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80448B2C:
    // 0x80448B2C: bnel        $a2, $at, L_80448B40
    if (ctx->r6 != ctx->r1) {
        // 0x80448B30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448B40;
    }
    goto skip_1;
    // 0x80448B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80448B34: jal         0x804467B0
    // 0x80448B38: nop

    func_804467B0(rdram, ctx);
        goto after_2;
    // 0x80448B38: nop

    after_2:
L_80448B3C:
    // 0x80448B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448B40:
    // 0x80448B40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80448B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448B48: jr          $ra
    // 0x80448B4C: nop

    return;
    // 0x80448B4C: nop

;}
RECOMP_FUNC void func_8042A8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A8A0: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(50, 0X2A9C) << 16);
    // 0x8042A8A4: addiu       $v0, $v0, -0x2CC4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(50, 0X2A9C));
    // 0x8042A8A8: jr          $ra
    // 0x8042A8AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8042A8AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805E420C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E420C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805E4210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E4214: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E4218: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x805E421C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805E4220: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4224: sra         $v1, $v1, 3
    ctx->r3 = S32(SIGNED(ctx->r3) >> 3);
    // 0x805E4228: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x805E422C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805E4230: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x805E4234: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x805E4238: jal         0x80067BBC
    // 0x805E423C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805E423C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x805E4240: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805E4244: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x805E4248: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x805E424C: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x805E4250: beq         $at, $zero, L_805E4260
    if (ctx->r1 == 0) {
        // 0x805E4254: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_805E4260;
    }
    // 0x805E4254: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805E4258: b           L_805E4264
    // 0x805E425C: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
        goto L_805E4264;
    // 0x805E425C: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
L_805E4260:
    // 0x805E4260: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
L_805E4264:
    // 0x805E4264: lh          $a1, 0xA($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XA);
    // 0x805E4268: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805E426C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x805E4270: bne         $a1, $at, L_805E42B4
    if (ctx->r5 != ctx->r1) {
        // 0x805E4274: nop
    
            goto L_805E42B4;
    }
    // 0x805E4274: nop

    // 0x805E4278: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x805E427C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x805E4280: jal         0x80067F78
    // 0x805E4284: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x805E4284: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x805E4288: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x805E428C: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x805E4290: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x805E4294: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x805E4298: bnel        $at, $zero, L_805E42E4
    if (ctx->r1 != 0) {
        // 0x805E429C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805E42E4;
    }
    goto skip_0;
    // 0x805E429C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805E42A0: jal         0x805E41AC
    // 0x805E42A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_805E41AC(rdram, ctx);
        goto after_2;
    // 0x805E42A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x805E42A8: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x805E42AC: b           L_805E42E0
    // 0x805E42B0: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
        goto L_805E42E0;
    // 0x805E42B0: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
L_805E42B4:
    // 0x805E42B4: jal         0x800678F0
    // 0x805E42B8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x805E42B8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_3:
    // 0x805E42BC: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x805E42C0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x805E42C4: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x805E42C8: bnel        $at, $zero, L_805E42E4
    if (ctx->r1 != 0) {
        // 0x805E42CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805E42E4;
    }
    goto skip_1;
    // 0x805E42CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805E42D0: jal         0x805E41AC
    // 0x805E42D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_805E41AC(rdram, ctx);
        goto after_4;
    // 0x805E42D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x805E42D8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x805E42DC: sh          $t0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r8;
L_805E42E0:
    // 0x805E42E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805E42E4:
    // 0x805E42E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E42E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805E42EC: jr          $ra
    // 0x805E42F0: nop

    return;
    // 0x805E42F0: nop

;}
RECOMP_FUNC void func_8078D2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D2BC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8078D2C0: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(802, 0X108) << 16);
    // 0x8078D2C4: addiu       $t6, $t6, -0x2DE8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(802, 0X108));
    // 0x8078D2C8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8078D2CC: jr          $ra
    // 0x8078D2D0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8078D2D0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806EB970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EB970: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(673, 0X470) << 16);
    // 0x806EB974: addiu       $v0, $v0, -0x4220
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(673, 0X470));
    // 0x806EB978: jr          $ra
    // 0x806EB97C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806EB97C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80031290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031290: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80031294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031298: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003129C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800312A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800312A4: jal         0x800310A0
    // 0x800312A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x800312A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800312AC: jal         0x80030D78
    // 0x800312B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80030D78(rdram, ctx);
        goto after_1;
    // 0x800312B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800312B4: beq         $v0, $zero, L_800312DC
    if (ctx->r2 == 0) {
        // 0x800312B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800312DC;
    }
    // 0x800312B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800312BC: jal         0x800310D0
    // 0x800312C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x800312C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800312C4: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x800312C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800312CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800312D0: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x800312D4: jal         0x80031170
    // 0x800312D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80031170(rdram, ctx);
        goto after_3;
    // 0x800312D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
L_800312DC:
    // 0x800312DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800312E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800312E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800312E8: jr          $ra
    // 0x800312EC: nop

    return;
    // 0x800312EC: nop

;}
RECOMP_FUNC void func_8057BE58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BE58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057BE5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057BE60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057BE64: jal         0x8057BDD8
    // 0x8057BE68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8057BDD8(rdram, ctx);
        goto after_0;
    // 0x8057BE68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8057BE6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057BE70: jal         0x8057BDD8
    // 0x8057BE74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8057BDD8(rdram, ctx);
        goto after_1;
    // 0x8057BE74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8057BE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057BE7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057BE80: jr          $ra
    // 0x8057BE84: nop

    return;
    // 0x8057BE84: nop

;}
RECOMP_FUNC void func_80469F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469F34: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80469F38: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2944) << 16);
    // 0x80469F3C: lwc1        $f2, -0x3F7C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2944));
    // 0x80469F40: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80469F44: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80469F48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80469F4C: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80469F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80469F54: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80469F58: nop

    // 0x80469F5C: bc1fl       L_80469F6C
    if (!c1cs) {
        // 0x80469F60: sltiu       $v0, $v0, 0x1
        ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
            goto L_80469F6C;
    }
    goto skip_0;
    // 0x80469F60: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    skip_0:
    // 0x80469F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80469F68: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80469F6C:
    // 0x80469F6C: beq         $v0, $zero, L_80469F94
    if (ctx->r2 == 0) {
        // 0x80469F70: nop
    
            goto L_80469F94;
    }
    // 0x80469F70: nop

    // 0x80469F74: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80469F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80469F7C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80469F80: nop

    // 0x80469F84: bc1fl       L_80469F94
    if (!c1cs) {
        // 0x80469F88: sltiu       $v0, $v0, 0x1
        ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
            goto L_80469F94;
    }
    goto skip_1;
    // 0x80469F88: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    skip_1:
    // 0x80469F8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80469F90: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80469F94:
    // 0x80469F94: jr          $ra
    // 0x80469F98: nop

    return;
    // 0x80469F98: nop

;}
RECOMP_FUNC void func_804BB464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB464: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BB468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB46C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BB470: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804BB474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804BB478: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x804BB47C: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    // 0x804BB480: lw          $a3, 0x16C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X16C);
    // 0x804BB484: lbu         $v0, 0x10($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X10);
    // 0x804BB488: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x804BB48C: sltiu       $at, $v0, 0xFF
    ctx->r1 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x804BB490: bnel        $at, $zero, L_804BB4B4
    if (ctx->r1 != 0) {
        // 0x804BB494: sb          $v0, 0x10($a3)
        MEM_B(0X10, ctx->r7) = ctx->r2;
            goto L_804BB4B4;
    }
    goto skip_0;
    // 0x804BB494: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
    skip_0:
    // 0x804BB498: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804BB49C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x804BB4A0: jal         0x8006E0FC
    // 0x804BB4A4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x804BB4A4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x804BB4A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804BB4AC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804BB4B0: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
L_804BB4B4:
    // 0x804BB4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BB4B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BB4BC: jr          $ra
    // 0x804BB4C0: nop

    return;
    // 0x804BB4C0: nop

;}
RECOMP_FUNC void func_804084C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804084C8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x804084CC: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x804084D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804084D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804084D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804084DC: lhu         $t8, 0xC($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XC);
    // 0x804084E0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804084E4: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x804084E8: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x804084EC: bne         $t9, $at, L_80408554
    if (ctx->r25 != ctx->r1) {
        // 0x804084F0: addiu       $a0, $zero, 0x4103
        ctx->r4 = ADD32(0, 0X4103);
            goto L_80408554;
    }
    // 0x804084F0: addiu       $a0, $zero, 0x4103
    ctx->r4 = ADD32(0, 0X4103);
    // 0x804084F4: jal         0x80046E88
    // 0x804084F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x804084F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x804084FC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80408500: beq         $v0, $zero, L_80408554
    if (ctx->r2 == 0) {
        // 0x80408504: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80408554;
    }
    // 0x80408504: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80408508: lw          $v0, 0x1F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1F4);
    // 0x8040850C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80408510: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80408514: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80408518: addiu       $a0, $v0, 0xB50
    ctx->r4 = ADD32(ctx->r2, 0XB50);
    // 0x8040851C: lwc1        $f4, 0x3C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X3C);
    // 0x80408520: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80408524: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80408528: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x8040852C: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x80408530: jal         0x80409F1C
    // 0x80408534: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80409F1C(rdram, ctx);
        goto after_1;
    // 0x80408534: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80408538: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8040853C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80408540: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80408544: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80408548: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040854C: jal         0x804085E4
    // 0x80408550: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804085E4(rdram, ctx);
        goto after_2;
    // 0x80408550: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_80408554:
    // 0x80408554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80408558: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040855C: jr          $ra
    // 0x80408560: nop

    return;
    // 0x80408560: nop

;}
RECOMP_FUNC void func_800751FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800751FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075200: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075204: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80075208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007520C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80075210: lw          $s0, 0x248($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X248);
    // 0x80075214: beql        $s0, $zero, L_8007523C
    if (ctx->r16 == 0) {
        // 0x80075218: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007523C;
    }
    goto skip_0;
    // 0x80075218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8007521C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_80075220:
    // 0x80075220: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80075224: jal         0x80082210
    // 0x80075228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80075228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8007522C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80075230: bnel        $s0, $zero, L_80075220
    if (ctx->r16 != 0) {
        // 0x80075234: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_80075220;
    }
    goto skip_1;
    // 0x80075234: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80075238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007523C:
    // 0x8007523C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80075240: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80075244: jr          $ra
    // 0x80075248: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80075248: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80446880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80446884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446888: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044688C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446890: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80446894: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80446898: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044689C: sw          $t6, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = ctx->r14;
    // 0x804468A0: addiu       $v1, $zero, 0x744
    ctx->r3 = ADD32(0, 0X744);
    // 0x804468A4: addiu       $t7, $zero, 0x3C0
    ctx->r15 = ADD32(0, 0X3C0);
    // 0x804468A8: addiu       $t8, $zero, 0xAC8
    ctx->r24 = ADD32(0, 0XAC8);
    // 0x804468AC: sw          $t7, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r15;
    // 0x804468B0: sw          $v1, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r3;
    // 0x804468B4: sw          $v1, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->r3;
    // 0x804468B8: sw          $v1, 0xE0($v0)
    MEM_W(0XE0, ctx->r2) = ctx->r3;
    // 0x804468BC: jal         0x8044680C
    // 0x804468C0: sw          $t8, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r24;
    func_8044680C(rdram, ctx);
        goto after_0;
    // 0x804468C0: sw          $t8, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r24;
    after_0:
    // 0x804468C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804468C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804468CC: jr          $ra
    // 0x804468D0: nop

    return;
    // 0x804468D0: nop

;}
RECOMP_FUNC void func_806F27E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F27E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F27E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F27EC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806F27F0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x806F27F4: jal         0x80048F84
    // 0x806F27F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x806F27F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x806F27FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806F2800: jal         0x80048F84
    // 0x806F2804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806F2804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806F2808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F280C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F2810: jr          $ra
    // 0x806F2814: nop

    return;
    // 0x806F2814: nop

;}
RECOMP_FUNC void func_806653A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806653A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806653AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806653B0: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x806653B4: bnel        $t6, $zero, L_806653FC
    if (ctx->r14 != 0) {
        // 0x806653B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806653FC;
    }
    goto skip_0;
    // 0x806653B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806653BC: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x806653C0: lui         $t0, 0x8066
    ctx->r8 = S32(RELOC_HI16(504, 0X2B44) << 16);
    // 0x806653C4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x806653C8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x806653CC: beq         $at, $zero, L_806653F0
    if (ctx->r1 == 0) {
        // 0x806653D0: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_806653F0;
    }
    // 0x806653D0: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x806653D4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x806653D8: sw          $t7, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r15;
    // 0x806653DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806653E0: lw          $t0, 0x7814($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(504, 0X2B44));
    // 0x806653E4: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x806653E8: b           L_806653F8
    // 0x806653EC: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
        goto L_806653F8;
    // 0x806653EC: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
L_806653F0:
    // 0x806653F0: jal         0x80665408
    // 0x806653F4: nop

    func_80665408(rdram, ctx);
        goto after_0;
    // 0x806653F4: nop

    after_0:
L_806653F8:
    // 0x806653F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806653FC:
    // 0x806653FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80665400: jr          $ra
    // 0x80665404: nop

    return;
    // 0x80665404: nop

;}
RECOMP_FUNC void func_804CEC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEC7C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804CEC80: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804CEC84: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804CEC88: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804CEC8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804CEC90: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804CEC94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CEC98: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804CEC9C: lui         $t1, 0x804D
    ctx->r9 = S32(RELOC_HI16(240, 0X1A50) << 16);
    // 0x804CECA0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804CECA4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804CECA8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804CECAC: lw          $t1, -0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(240, 0X1A50));
    // 0x804CECB0: jr          $ra
    // 0x804CECB4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804CECB4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80025A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025A64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025A68: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80025A6C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80025A70: addiu       $t7, $t7, 0x59FC
    ctx->r15 = ADD32(ctx->r15, 0X59FC);
    // 0x80025A74: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x80025A78: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x80025A7C: lbu         $t8, 0x1F8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1F8);
    // 0x80025A80: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80025A84: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80025A88: addiu       $a1, $a1, -0x33D0
    ctx->r5 = ADD32(ctx->r5, -0X33D0);
    // 0x80025A8C: addiu       $v1, $v1, -0x33E0
    ctx->r3 = ADD32(ctx->r3, -0X33E0);
    // 0x80025A90: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80025A94: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80025A98: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80025A9C: sw          $v1, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r3;
    // 0x80025AA0: sw          $a1, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r5;
    // 0x80025AA4: lw          $t0, -0x3A90($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3A90);
    // 0x80025AA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025AAC: sw          $t0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r8;
    // 0x80025AB0: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80025AB4: jr          $ra
    // 0x80025AB8: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    return;
    // 0x80025AB8: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_8056924C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056924C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80569250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80569254: jal         0x80568710
    // 0x80569258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80569258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8056925C: jal         0x80567AAC
    // 0x80569260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80567AAC(rdram, ctx);
        goto after_1;
    // 0x80569260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80569264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80569268: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2224) << 16);
    // 0x8056926C: lwc1        $f0, -0x682C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2224));
    // 0x80569270: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80569274: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80569278: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8056927C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80569280: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x80569284: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x80569288: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8056928C: jal         0x80569310
    // 0x80569290: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80569290: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x80569294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80569298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8056929C: jr          $ra
    // 0x805692A0: nop

    return;
    // 0x805692A0: nop

;}
RECOMP_FUNC void func_8007FFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FFF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007FFF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FFF8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8007FFFC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80080000: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80080004: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80080008: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8008000C: jal         0x800818E8
    // 0x80080010: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x80080010: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80080014: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80080018: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8008001C: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80080020: jal         0x80080C84
    // 0x80080024: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    func_80080C84(rdram, ctx);
        goto after_1;
    // 0x80080024: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_1:
    // 0x80080028: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8008002C: jal         0x800817A0
    // 0x80080030: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    MtxConv_F2L(rdram, ctx);
        goto after_2;
    // 0x80080030: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x80080034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080038: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8008003C: jr          $ra
    // 0x80080040: nop

    return;
    // 0x80080040: nop

;}
