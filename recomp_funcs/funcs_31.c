#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void StackCheck_Check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081A0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081A10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80081A14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80081A18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80081A1C: bne         $a0, $zero, L_80081A60
    if (ctx->r4 != 0) {
        // 0x80081A20: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80081A60;
    }
    // 0x80081A20: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80081A24: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80081A28: lw          $s0, -0x5C60($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5C60);
    // 0x80081A2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80081A30: beq         $s0, $zero, L_80081A58
    if (ctx->r16 == 0) {
        // 0x80081A34: nop
    
            goto L_80081A58;
    }
    // 0x80081A34: nop

L_80081A38:
    // 0x80081A38: jal         0x80081A0C
    // 0x80081A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    StackCheck_Check(rdram, ctx);
        goto after_0;
    // 0x80081A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80081A40: beql        $v0, $zero, L_80081A50
    if (ctx->r2 == 0) {
        // 0x80081A44: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80081A50;
    }
    goto skip_0;
    // 0x80081A44: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80081A48: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80081A4C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80081A50:
    // 0x80081A50: bne         $s0, $zero, L_80081A38
    if (ctx->r16 != 0) {
        // 0x80081A54: nop
    
            goto L_80081A38;
    }
    // 0x80081A54: nop

L_80081A58:
    // 0x80081A58: b           L_80081AD4
    // 0x80081A5C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80081AD4;
    // 0x80081A5C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80081A60:
    // 0x80081A60: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x80081A64: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    // 0x80081A68: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80081A6C: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80081A70: beql        $at, $zero, L_80081A9C
    if (ctx->r1 == 0) {
        // 0x80081A74: subu        $v1, $v0, $a2
        ctx->r3 = SUB32(ctx->r2, ctx->r6);
            goto L_80081A9C;
    }
    goto skip_1;
    // 0x80081A74: subu        $v1, $v0, $a2
    ctx->r3 = SUB32(ctx->r2, ctx->r6);
    skip_1:
    // 0x80081A78: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    // 0x80081A7C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_80081A80:
    // 0x80081A80: bnel        $a0, $t6, L_80081A9C
    if (ctx->r4 != ctx->r14) {
        // 0x80081A84: subu        $v1, $v0, $a2
        ctx->r3 = SUB32(ctx->r2, ctx->r6);
            goto L_80081A9C;
    }
    goto skip_2;
    // 0x80081A84: subu        $v1, $v0, $a2
    ctx->r3 = SUB32(ctx->r2, ctx->r6);
    skip_2:
    // 0x80081A88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80081A8C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80081A90: bnel        $at, $zero, L_80081A80
    if (ctx->r1 != 0) {
        // 0x80081A94: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80081A80;
    }
    goto skip_3;
    // 0x80081A94: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_3:
    // 0x80081A98: subu        $v1, $v0, $a2
    ctx->r3 = SUB32(ctx->r2, ctx->r6);
L_80081A9C:
    // 0x80081A9C: bnel        $v1, $zero, L_80081AB0
    if (ctx->r3 != 0) {
        // 0x80081AA0: lw          $v0, 0x14($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X14);
            goto L_80081AB0;
    }
    goto skip_4;
    // 0x80081AA0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    skip_4:
    // 0x80081AA4: b           L_80081AD0
    // 0x80081AA8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80081AD0;
    // 0x80081AA8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80081AAC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
L_80081AB0:
    // 0x80081AB0: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80081AB4: beq         $at, $zero, L_80081AD0
    if (ctx->r1 == 0) {
        // 0x80081AB8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80081AD0;
    }
    // 0x80081AB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80081ABC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081AC0: beq         $v0, $at, L_80081AD0
    if (ctx->r2 == ctx->r1) {
        // 0x80081AC4: nop
    
            goto L_80081AD0;
    }
    // 0x80081AC4: nop

    // 0x80081AC8: b           L_80081AD0
    // 0x80081ACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80081AD0;
    // 0x80081ACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80081AD0:
    // 0x80081AD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80081AD4:
    // 0x80081AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80081AD8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80081ADC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80081AE0: jr          $ra
    // 0x80081AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80081AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8067DF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067DF94: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8067DF98: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8067DF9C: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8067DFA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8067DFA4: nop

    // 0x8067DFA8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8067DFAC: nop

    // 0x8067DFB0: bc1fl       L_8067DFE0
    if (!c1cs) {
        // 0x8067DFB4: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8067DFE0;
    }
    goto skip_0;
    // 0x8067DFB4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8067DFB8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8067DFBC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8067DFC0: nop

    // 0x8067DFC4: bc1f        L_8067DFFC
    if (!c1cs) {
        // 0x8067DFC8: nop
    
            goto L_8067DFFC;
    }
    // 0x8067DFC8: nop

    // 0x8067DFCC: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8067DFD0: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8067DFD4: jr          $ra
    // 0x8067DFD8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8067DFD8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8067DFDC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_8067DFE0:
    // 0x8067DFE0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8067DFE4: nop

    // 0x8067DFE8: bc1f        L_8067DFFC
    if (!c1cs) {
        // 0x8067DFEC: nop
    
            goto L_8067DFFC;
    }
    // 0x8067DFEC: nop

    // 0x8067DFF0: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8067DFF4: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8067DFF8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8067DFFC:
    // 0x8067DFFC: jr          $ra
    // 0x8067E000: nop

    return;
    // 0x8067E000: nop

;}
RECOMP_FUNC void func_804A2024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A2024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A2028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A202C: jal         0x804A2910
    // 0x804A2030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A2030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A2034: beq         $v0, $zero, L_804A2070
    if (ctx->r2 == 0) {
        // 0x804A2038: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A2070;
    }
    // 0x804A2038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A203C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804A2040: lui         $t8, 0x804A
    ctx->r24 = S32(RELOC_HI16(173, 0X307C) << 16);
    // 0x804A2044: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804A2048: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804A204C: lw          $t8, 0x34BC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(173, 0X307C));
    // 0x804A2050: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
    // 0x804A2054: jal         0x804A1820
    // 0x804A2058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A1820(rdram, ctx);
        goto after_1;
    // 0x804A2058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x804A205C: bne         $v0, $zero, L_804A2070
    if (ctx->r2 != 0) {
        // 0x804A2060: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A2070;
    }
    // 0x804A2060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A2064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A2068: jal         0x804A27A0
    // 0x804A206C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_2;
    // 0x804A206C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_804A2070:
    // 0x804A2070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A2074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A2078: jr          $ra
    // 0x804A207C: nop

    return;
    // 0x804A207C: nop

;}
RECOMP_FUNC void func_80736AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80736AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736AF8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80736AFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80736B00: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80736B04: addiu       $at, $zero, 0x45D9
    ctx->r1 = ADD32(0, 0X45D9);
    // 0x80736B08: bnel        $v0, $at, L_80736B1C
    if (ctx->r2 != ctx->r1) {
        // 0x80736B0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80736B1C;
    }
    goto skip_0;
    // 0x80736B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80736B10: jal         0x8073605C
    // 0x80736B14: nop

    func_8073605C(rdram, ctx);
        goto after_0;
    // 0x80736B14: nop

    after_0:
    // 0x80736B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80736B1C:
    // 0x80736B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80736B20: jr          $ra
    // 0x80736B24: nop

    return;
    // 0x80736B24: nop

;}
RECOMP_FUNC void func_8040F0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040F0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040F0BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040F0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040F0C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8040F0C8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8040F0CC: lbu         $t7, 0x164($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X164);
    // 0x8040F0D0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8040F0D4: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8040F0D8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8040F0DC: bne         $t7, $zero, L_8040F110
    if (ctx->r15 != 0) {
        // 0x8040F0E0: sb          $t6, 0x30($a0)
        MEM_B(0X30, ctx->r4) = ctx->r14;
            goto L_8040F110;
    }
    // 0x8040F0E0: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x8040F0E4: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x8040F0E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8040F0EC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8040F0F0: andi        $t0, $t6, 0xFF
    ctx->r8 = ctx->r14 & 0XFF;
    // 0x8040F0F4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8040F0F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040F0FC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8040F100: lui         $t3, 0x8041
    ctx->r11 = S32(RELOC_HI16(23, 0XD30) << 16);
    // 0x8040F104: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8040F108: lw          $t3, -0xB30($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(23, 0XD30));
    // 0x8040F10C: sw          $t3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r11;
L_8040F110:
    // 0x8040F110: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8040F114: jal         0x8040E7C8
    // 0x8040F118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040E7C8(rdram, ctx);
        goto after_0;
    // 0x8040F118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040F11C: jal         0x8040E824
    // 0x8040F120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040E824(rdram, ctx);
        goto after_1;
    // 0x8040F120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8040F124: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x8040F128: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040F12C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040F130: bne         $v0, $at, L_8040F144
    if (ctx->r2 != ctx->r1) {
        // 0x8040F134: lui         $t4, 0x8005
        ctx->r12 = S32(0X8005 << 16);
            goto L_8040F144;
    }
    // 0x8040F134: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x8040F138: addiu       $t4, $t4, -0x7C48
    ctx->r12 = ADD32(ctx->r12, -0X7C48);
    // 0x8040F13C: b           L_8040F278
    // 0x8040F140: sw          $t4, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r12;
        goto L_8040F278;
    // 0x8040F140: sw          $t4, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r12;
L_8040F144:
    // 0x8040F144: bnel        $v0, $zero, L_8040F278
    if (ctx->r2 != 0) {
        // 0x8040F148: sw          $zero, 0x130($a0)
        MEM_W(0X130, ctx->r4) = 0;
            goto L_8040F278;
    }
    goto skip_0;
    // 0x8040F148: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    skip_0:
    // 0x8040F14C: jal         0x8004700C
    // 0x8040F150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x8040F150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8040F154: bne         $v0, $zero, L_8040F25C
    if (ctx->r2 != 0) {
        // 0x8040F158: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040F25C;
    }
    // 0x8040F158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040F15C: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x8040F160: addiu       $t5, $t5, -0x7C48
    ctx->r13 = ADD32(ctx->r13, -0X7C48);
    // 0x8040F164: sw          $t5, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r13;
    // 0x8040F168: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8040F16C: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8040F170: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8040F174: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8040F178: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040F17C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8040F180: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040F184: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8040F188: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(23, 0XD68) << 16);
    // 0x8040F18C: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8040F190: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8040F194: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x8040F198: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8040F19C: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8040F1A0: bc1f        L_8040F1DC
    if (!c1cs) {
        // 0x8040F1A4: sub.s       $f0, $f6, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
            goto L_8040F1DC;
    }
    // 0x8040F1A4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8040F1A8: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(23, 0XD60) << 16);
    // 0x8040F1AC: lwc1        $f16, -0xB00($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(23, 0XD60));
    // 0x8040F1B0: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8040F1B4: lui         $at, 0x4507
    ctx->r1 = S32(0X4507 << 16);
    // 0x8040F1B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040F1BC: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(23, 0XD64) << 16);
    // 0x8040F1C0: lwc1        $f8, -0xAFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(23, 0XD64));
    // 0x8040F1C4: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8040F1C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8040F1CC: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8040F1D0: div.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8040F1D4: b           L_8040F23C
    // 0x8040F1D8: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
        goto L_8040F23C;
    // 0x8040F1D8: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
L_8040F1DC:
    // 0x8040F1DC: lwc1        $f16, -0xAF8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(23, 0XD68));
    // 0x8040F1E0: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8040F1E4: lui         $at, 0x4507
    ctx->r1 = S32(0X4507 << 16);
    // 0x8040F1E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8040F1EC: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(23, 0XD6C) << 16);
    // 0x8040F1F0: mul.s       $f12, $f16, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8040F1F4: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8040F1F8: lwc1        $f6, -0xAF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(23, 0XD6C));
    // 0x8040F1FC: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040F200: nop

    // 0x8040F204: mul.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8040F208: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x8040F20C: nop

    // 0x8040F210: bc1f        L_8040F230
    if (!c1cs) {
        // 0x8040F214: nop
    
            goto L_8040F230;
    }
    // 0x8040F214: nop

    // 0x8040F218: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8040F21C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8040F220: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8040F224: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8040F228: b           L_8040F23C
    // 0x8040F22C: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
        goto L_8040F23C;
    // 0x8040F22C: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
L_8040F230:
    // 0x8040F230: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x8040F234: div.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8040F238: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
L_8040F23C:
    // 0x8040F23C: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8040F240: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8040F244: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8040F248: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040F24C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8040F250: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040F254: b           L_8040F278
    // 0x8040F258: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
        goto L_8040F278;
    // 0x8040F258: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
L_8040F25C:
    // 0x8040F25C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8040F260: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8040F264: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    // 0x8040F268: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
    // 0x8040F26C: b           L_8040F278
    // 0x8040F270: swc1        $f2, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f2.u32l;
        goto L_8040F278;
    // 0x8040F270: swc1        $f2, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f2.u32l;
    // 0x8040F274: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
L_8040F278:
    // 0x8040F278: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040F27C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8040F280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040F284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040F288: jr          $ra
    // 0x8040F28C: nop

    return;
    // 0x8040F28C: nop

;}
RECOMP_FUNC void func_806D227C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D227C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806D2280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D2284: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D2288: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x806D228C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x806D2290: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x806D2294: jal         0x8004700C
    // 0x806D2298: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D2298: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_0:
    // 0x806D229C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x806D22A0: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x806D22A4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x806D22A8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x806D22AC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x806D22B0: beq         $v0, $zero, L_806D2654
    if (ctx->r2 == 0) {
        // 0x806D22B4: lw          $t2, 0xD8($t0)
        ctx->r10 = MEM_W(ctx->r8, 0XD8);
            goto L_806D2654;
    }
    // 0x806D22B4: lw          $t2, 0xD8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XD8);
    // 0x806D22B8: lbu         $a0, 0x18($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X18);
    // 0x806D22BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x806D22C0: bne         $a1, $a0, L_806D2310
    if (ctx->r5 != ctx->r4) {
        // 0x806D22C4: nop
    
            goto L_806D2310;
    }
    // 0x806D22C4: nop

    // 0x806D22C8: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x806D22CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D22D0: bne         $t6, $zero, L_806D2308
    if (ctx->r14 != 0) {
        // 0x806D22D4: nop
    
            goto L_806D2308;
    }
    // 0x806D22D4: nop

    // 0x806D22D8: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x806D22DC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x806D22E0: beq         $v1, $at, L_806D2308
    if (ctx->r3 == ctx->r1) {
        // 0x806D22E4: nop
    
            goto L_806D2308;
    }
    // 0x806D22E4: nop

    // 0x806D22E8: beq         $a1, $v1, L_806D2308
    if (ctx->r5 == ctx->r3) {
        // 0x806D22EC: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_806D2308;
    }
    // 0x806D22EC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x806D22F0: beq         $v1, $at, L_806D2308
    if (ctx->r3 == ctx->r1) {
        // 0x806D22F4: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_806D2308;
    }
    // 0x806D22F4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x806D22F8: beq         $v1, $at, L_806D2308
    if (ctx->r3 == ctx->r1) {
        // 0x806D22FC: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_806D2308;
    }
    // 0x806D22FC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x806D2300: bne         $v1, $at, L_806D2310
    if (ctx->r3 != ctx->r1) {
        // 0x806D2304: nop
    
            goto L_806D2310;
    }
    // 0x806D2304: nop

L_806D2308:
    // 0x806D2308: b           L_806D2654
    // 0x806D230C: sw          $t7, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r15;
        goto L_806D2654;
    // 0x806D230C: sw          $t7, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r15;
L_806D2310:
    // 0x806D2310: bnel        $a1, $a0, L_806D238C
    if (ctx->r5 != ctx->r4) {
        // 0x806D2314: lw          $t5, 0xE88($t0)
        ctx->r13 = MEM_W(ctx->r8, 0XE88);
            goto L_806D238C;
    }
    goto skip_0;
    // 0x806D2314: lw          $t5, 0xE88($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XE88);
    skip_0:
    // 0x806D2318: lw          $t8, 0x30($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X30);
    // 0x806D231C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806D2320: bne         $t8, $zero, L_806D2380
    if (ctx->r24 != 0) {
        // 0x806D2324: nop
    
            goto L_806D2380;
    }
    // 0x806D2324: nop

    // 0x806D2328: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x806D232C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x806D2330: beq         $v1, $zero, L_806D2380
    if (ctx->r3 == 0) {
        // 0x806D2334: nop
    
            goto L_806D2380;
    }
    // 0x806D2334: nop

    // 0x806D2338: beq         $v1, $at, L_806D2380
    if (ctx->r3 == ctx->r1) {
        // 0x806D233C: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_806D2380;
    }
    // 0x806D233C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x806D2340: beq         $v1, $at, L_806D2380
    if (ctx->r3 == ctx->r1) {
        // 0x806D2344: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_806D2380;
    }
    // 0x806D2344: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x806D2348: beq         $v1, $at, L_806D2380
    if (ctx->r3 == ctx->r1) {
        // 0x806D234C: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_806D2380;
    }
    // 0x806D234C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x806D2350: beq         $v1, $at, L_806D2380
    if (ctx->r3 == ctx->r1) {
        // 0x806D2354: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_806D2380;
    }
    // 0x806D2354: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x806D2358: beq         $v1, $at, L_806D2380
    if (ctx->r3 == ctx->r1) {
        // 0x806D235C: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_806D2380;
    }
    // 0x806D235C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x806D2360: beq         $v1, $at, L_806D2380
    if (ctx->r3 == ctx->r1) {
        // 0x806D2364: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_806D2380;
    }
    // 0x806D2364: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x806D2368: beq         $v1, $at, L_806D2380
    if (ctx->r3 == ctx->r1) {
        // 0x806D236C: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_806D2380;
    }
    // 0x806D236C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x806D2370: beq         $v1, $at, L_806D2380
    if (ctx->r3 == ctx->r1) {
        // 0x806D2374: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_806D2380;
    }
    // 0x806D2374: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x806D2378: bnel        $v1, $at, L_806D238C
    if (ctx->r3 != ctx->r1) {
        // 0x806D237C: lw          $t5, 0xE88($t0)
        ctx->r13 = MEM_W(ctx->r8, 0XE88);
            goto L_806D238C;
    }
    goto skip_1;
    // 0x806D237C: lw          $t5, 0xE88($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XE88);
    skip_1:
L_806D2380:
    // 0x806D2380: b           L_806D2654
    // 0x806D2384: sw          $t9, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r25;
        goto L_806D2654;
    // 0x806D2384: sw          $t9, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r25;
    // 0x806D2388: lw          $t5, 0xE88($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XE88);
L_806D238C:
    // 0x806D238C: lw          $t3, 0x24($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X24);
    // 0x806D2390: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x806D2394: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x806D2398: bnel        $t4, $t6, L_806D243C
    if (ctx->r12 != ctx->r14) {
        // 0x806D239C: lw          $t8, 0x478($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X478);
            goto L_806D243C;
    }
    goto skip_2;
    // 0x806D239C: lw          $t8, 0x478($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X478);
    skip_2:
    // 0x806D23A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806D23A4: addiu       $v0, $a3, 0xC4
    ctx->r2 = ADD32(ctx->r7, 0XC4);
    // 0x806D23A8: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1728) << 16);
    // 0x806D23AC: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x806D23B0: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x806D23B4: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x806D23B8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x806D23BC: lwc1        $f4, 0x44($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X44);
    // 0x806D23C0: lwc1        $f6, 0x2CE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1728));
    // 0x806D23C4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x806D23C8: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x806D23CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806D23D0: swc1        $f8, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->f8.u32l;
    // 0x806D23D4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x806D23D8: jal         0x80067BBC
    // 0x806D23DC: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x806D23DC: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_1:
    // 0x806D23E0: addiu       $a0, $zero, 0x26E
    ctx->r4 = ADD32(0, 0X26E);
    // 0x806D23E4: jal         0x80067818
    // 0x806D23E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x806D23E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806D23EC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x806D23F0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x806D23F4: lw          $t7, 0x24($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X24);
    // 0x806D23F8: beql        $t7, $zero, L_806D2424
    if (ctx->r15 == 0) {
        // 0x806D23FC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_806D2424;
    }
    goto skip_3;
    // 0x806D23FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_3:
    // 0x806D2400: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x806D2404: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x806D2408: jal         0x80067BBC
    // 0x806D240C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x806D240C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_3:
    // 0x806D2410: addiu       $a0, $zero, 0x26D
    ctx->r4 = ADD32(0, 0X26D);
    // 0x806D2414: jal         0x80067818
    // 0x806D2418: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x806D2418: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x806D241C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x806D2420: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_806D2424:
    // 0x806D2424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D2428: jal         0x806D2BCC
    // 0x806D242C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_806D2BCC(rdram, ctx);
        goto after_5;
    // 0x806D242C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_5:
    // 0x806D2430: b           L_806D2658
    // 0x806D2434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D2658;
    // 0x806D2434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D2438: lw          $t8, 0x478($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X478);
L_806D243C:
    // 0x806D243C: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x806D2440: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D2444: lwc1        $f10, 0x34($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X34);
    // 0x806D2448: lwc1        $f4, 0x40($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X40);
    // 0x806D244C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806D2450: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x806D2454: nop

    // 0x806D2458: bc1fl       L_806D24B4
    if (!c1cs) {
        // 0x806D245C: lw          $t5, 0xC($a2)
        ctx->r13 = MEM_W(ctx->r6, 0XC);
            goto L_806D24B4;
    }
    goto skip_4;
    // 0x806D245C: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
    skip_4:
    // 0x806D2460: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806D2464: lwc1        $f6, 0xC8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x806D2468: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x806D246C: nop

    // 0x806D2470: bc1fl       L_806D24B4
    if (!c1cs) {
        // 0x806D2474: lw          $t5, 0xC($a2)
        ctx->r13 = MEM_W(ctx->r6, 0XC);
            goto L_806D24B4;
    }
    goto skip_5;
    // 0x806D2474: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
    skip_5:
    // 0x806D2478: lw          $t9, 0xA68($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XA68);
    // 0x806D247C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x806D2480: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(610, 0X16A0) << 16);
    // 0x806D2484: lw          $t3, 0x10($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X10);
    // 0x806D2488: addiu       $a1, $a1, 0x2C60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(610, 0X16A0));
    // 0x806D248C: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x806D2490: lw          $t9, 0x18($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X18);
    // 0x806D2494: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D2498: jalr        $t9
    // 0x806D249C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x806D249C: nop

    after_6:
    // 0x806D24A0: jal         0x800447C8
    // 0x806D24A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x806D24A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x806D24A8: b           L_806D2658
    // 0x806D24AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D2658;
    // 0x806D24AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D24B0: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
L_806D24B4:
    // 0x806D24B4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806D24B8: lwc1        $f0, 0x6C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x806D24BC: bne         $t5, $zero, L_806D2504
    if (ctx->r13 != 0) {
        // 0x806D24C0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806D2504;
    }
    // 0x806D24C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D24C4: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X172C) << 16);
    // 0x806D24C8: lwc1        $f12, 0x2CEC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X172C));
    // 0x806D24CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D24D0: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x806D24D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806D24D8: nop

    // 0x806D24DC: bc1fl       L_806D2530
    if (!c1cs) {
        // 0x806D24E0: swc1        $f0, 0x6C($a3)
        MEM_W(0X6C, ctx->r7) = ctx->f0.u32l;
            goto L_806D2530;
    }
    goto skip_6;
    // 0x806D24E0: swc1        $f0, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f0.u32l;
    skip_6:
    // 0x806D24E4: lw          $t4, 0x138($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X138);
    // 0x806D24E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806D24EC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806D24F0: subu        $t7, $t6, $t4
    ctx->r15 = SUB32(ctx->r14, ctx->r12);
    // 0x806D24F4: sw          $t7, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r15;
    // 0x806D24F8: sw          $t7, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->r15;
    // 0x806D24FC: b           L_806D252C
    // 0x806D2500: sw          $t3, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r11;
        goto L_806D252C;
    // 0x806D2500: sw          $t3, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r11;
L_806D2504:
    // 0x806D2504: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806D2508: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1730) << 16);
    // 0x806D250C: lwc1        $f12, 0x2CF0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1730));
    // 0x806D2510: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x806D2514: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806D2518: nop

    // 0x806D251C: bc1fl       L_806D2530
    if (!c1cs) {
        // 0x806D2520: swc1        $f0, 0x6C($a3)
        MEM_W(0X6C, ctx->r7) = ctx->f0.u32l;
            goto L_806D2530;
    }
    goto skip_7;
    // 0x806D2520: swc1        $f0, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f0.u32l;
    skip_7:
    // 0x806D2524: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x806D2528: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_806D252C:
    // 0x806D252C: swc1        $f0, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f0.u32l;
L_806D2530:
    // 0x806D2530: swc1        $f0, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f0.u32l;
    // 0x806D2534: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
    // 0x806D2538: addiu       $v0, $a3, 0xC4
    ctx->r2 = ADD32(ctx->r7, 0XC4);
    // 0x806D253C: beq         $v1, $zero, L_806D254C
    if (ctx->r3 == 0) {
        // 0x806D2540: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_806D254C;
    }
    // 0x806D2540: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x806D2544: sw          $t9, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r25;
    // 0x806D2548: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_806D254C:
    // 0x806D254C: bne         $v1, $zero, L_806D258C
    if (ctx->r3 != 0) {
        // 0x806D2550: nop
    
            goto L_806D258C;
    }
    // 0x806D2550: nop

    // 0x806D2554: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806D2558: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x806D255C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806D2560: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x806D2564: nop

    // 0x806D2568: bc1f        L_806D258C
    if (!c1cs) {
        // 0x806D256C: nop
    
            goto L_806D258C;
    }
    // 0x806D256C: nop

    // 0x806D2570: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D2574: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806D2578: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806D257C: swc1        $f12, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f12.u32l;
    // 0x806D2580: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x806D2584: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x806D2588: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
L_806D258C:
    // 0x806D258C: bnel        $v1, $zero, L_806D25DC
    if (ctx->r3 != 0) {
        // 0x806D2590: andi        $t4, $t2, 0xF
        ctx->r12 = ctx->r10 & 0XF;
            goto L_806D25DC;
    }
    goto skip_8;
    // 0x806D2590: andi        $t4, $t2, 0xF
    ctx->r12 = ctx->r10 & 0XF;
    skip_8:
    // 0x806D2594: lw          $t5, 0xE88($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XE88);
    // 0x806D2598: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x806D259C: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x806D25A0: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x806D25A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D25A8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x806D25AC: bne         $at, $zero, L_806D25BC
    if (ctx->r1 != 0) {
        // 0x806D25B0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_806D25BC;
    }
    // 0x806D25B0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x806D25B4: bnel        $v0, $at, L_806D25DC
    if (ctx->r2 != ctx->r1) {
        // 0x806D25B8: andi        $t4, $t2, 0xF
        ctx->r12 = ctx->r10 & 0XF;
            goto L_806D25DC;
    }
    goto skip_9;
    // 0x806D25B8: andi        $t4, $t2, 0xF
    ctx->r12 = ctx->r10 & 0XF;
    skip_9:
L_806D25BC:
    // 0x806D25BC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x806D25C0: jal         0x80048F84
    // 0x806D25C4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    func_80048F84(rdram, ctx);
        goto after_8;
    // 0x806D25C4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_8:
    // 0x806D25C8: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x806D25CC: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x806D25D0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x806D25D4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x806D25D8: andi        $t4, $t2, 0xF
    ctx->r12 = ctx->r10 & 0XF;
L_806D25DC:
    // 0x806D25DC: bnel        $t4, $zero, L_806D261C
    if (ctx->r12 != 0) {
        // 0x806D25E0: lhu         $t3, 0xC($a3)
        ctx->r11 = MEM_HU(ctx->r7, 0XC);
            goto L_806D261C;
    }
    goto skip_10;
    // 0x806D25E0: lhu         $t3, 0xC($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0XC);
    skip_10:
    // 0x806D25E4: lw          $t7, 0xA68($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XA68);
    // 0x806D25E8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x806D25EC: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(610, 0X1694) << 16);
    // 0x806D25F0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x806D25F4: addiu       $a1, $a1, 0x2C54
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(610, 0X1694));
    // 0x806D25F8: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x806D25FC: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x806D2600: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D2604: jalr        $t9
    // 0x806D2608: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x806D2608: nop

    after_9:
    // 0x806D260C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x806D2610: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x806D2614: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x806D2618: lhu         $t3, 0xC($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0XC);
L_806D261C:
    // 0x806D261C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x806D2620: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806D2624: addiu       $t5, $t3, -0x465E
    ctx->r13 = ADD32(ctx->r11, -0X465E);
    // 0x806D2628: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x806D262C: lw          $t6, 0x478($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X478);
    // 0x806D2630: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1734) << 16);
    // 0x806D2634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806D2638: lwc1        $f16, 0x30($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X30);
    // 0x806D263C: lwc1        $f4, 0x2CF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1734));
    // 0x806D2640: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806D2644: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x806D2648: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806D264C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x806D2650: swc1        $f6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f6.u32l;
L_806D2654:
    // 0x806D2654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D2658:
    // 0x806D2658: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806D265C: jr          $ra
    // 0x806D2660: nop

    return;
    // 0x806D2660: nop

;}
RECOMP_FUNC void func_8002BE88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BE88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BE8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BE90: jal         0x8002BE60
    // 0x8002BE94: nop

    func_8002BE60(rdram, ctx);
        goto after_0;
    // 0x8002BE94: nop

    after_0:
    // 0x8002BE98: jal         0x80039CD0
    // 0x8002BE9C: nop

    func_80039CD0(rdram, ctx);
        goto after_1;
    // 0x8002BE9C: nop

    after_1:
    // 0x8002BEA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BEA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002BEA8: jr          $ra
    // 0x8002BEAC: nop

    return;
    // 0x8002BEAC: nop

;}
RECOMP_FUNC void func_80453828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045382C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453830: jal         0x80453784
    // 0x80453834: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80453784(rdram, ctx);
        goto after_0;
    // 0x80453834: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80453838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045383C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453840: jr          $ra
    // 0x80453844: nop

    return;
    // 0x80453844: nop

;}
RECOMP_FUNC void func_804B9400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B9400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B9404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B9408: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804B940C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804B9410: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804B9414: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(185, 0X2A10) << 16);
    // 0x804B9418: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804B941C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804B9420: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804B9424: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804B9428: lw          $t8, -0x57D0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(185, 0X2A10));
    // 0x804B942C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804B9430: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804B9434: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B9438: jal         0x80048490
    // 0x804B943C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804B943C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804B9440: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804B9444: jal         0x80048378
    // 0x804B9448: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804B9448: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804B944C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B9450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B9454: jr          $ra
    // 0x804B9458: nop

    return;
    // 0x804B9458: nop

;}
RECOMP_FUNC void func_80040AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040AC8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80040ACC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80040AD4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80040AD8: lwc1        $f14, 0xC4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80040ADC: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80040AE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80040AE4: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80040AE8: nop

    // 0x80040AEC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80040AF0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80040AF4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80040AF8: jal         0x80081E8C
    // 0x80040AFC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80040AFC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80040B00: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80040B04: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80040B08: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80040B0C: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80040B10: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80040B14: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80040B18: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80040B1C: jal         0x80081E8C
    // 0x80040B20: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    fatan2(rdram, ctx);
        goto after_1;
    // 0x80040B20: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x80040B24: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80040B28: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80040B2C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80040B30: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80040B34: add.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80040B38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80040B3C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80040B40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040B44: sub.s       $f2, $f18, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80040B48: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80040B4C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80040B50: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80040B54: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80040B58: nop

    // 0x80040B5C: bc1fl       L_80040B7C
    if (!c1cs) {
        // 0x80040B60: c.le.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
            goto L_80040B7C;
    }
    goto skip_0;
    // 0x80040B60: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    skip_0:
    // 0x80040B64: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
L_80040B68:
    // 0x80040B68: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80040B6C: nop

    // 0x80040B70: bc1tl       L_80040B68
    if (c1cs) {
        // 0x80040B74: sub.s       $f2, $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_80040B68;
    }
    goto skip_1;
    // 0x80040B74: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    skip_1:
    // 0x80040B78: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
L_80040B7C:
    // 0x80040B7C: nop

    // 0x80040B80: bc1fl       L_80040BA0
    if (!c1cs) {
        // 0x80040B84: c.le.s      $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
            goto L_80040BA0;
    }
    goto skip_2;
    // 0x80040B84: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    skip_2:
    // 0x80040B88: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
L_80040B8C:
    // 0x80040B8C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80040B90: nop

    // 0x80040B94: bc1tl       L_80040B8C
    if (c1cs) {
        // 0x80040B98: add.s       $f2, $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_80040B8C;
    }
    goto skip_3;
    // 0x80040B98: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    skip_3:
    // 0x80040B9C: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
L_80040BA0:
    // 0x80040BA0: nop

    // 0x80040BA4: bc1tl       L_80040BC8
    if (c1cs) {
        // 0x80040BA8: add.s       $f6, $f4, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f4.fl;
            goto L_80040BC8;
    }
    goto skip_4;
    // 0x80040BA8: add.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f4.fl;
    skip_4:
    // 0x80040BAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80040BB0: nop

    // 0x80040BB4: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80040BB8: nop

    // 0x80040BBC: bc1fl       L_80040BFC
    if (!c1cs) {
        // 0x80040BC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80040BFC;
    }
    goto skip_5;
    // 0x80040BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80040BC4: add.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f4.fl;
L_80040BC8:
    // 0x80040BC8: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80040BCC: sub.s       $f12, $f14, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80040BD0: jal         0x80066E88
    // 0x80040BD4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80040BD4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80040BD8: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80040BDC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80040BE0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80040BE4: jal         0x80066DE4
    // 0x80040BE8: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80040BE8: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80040BEC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80040BF0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80040BF4: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x80040BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80040BFC:
    // 0x80040BFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80040C00: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80040C04: jr          $ra
    // 0x80040C08: nop

    return;
    // 0x80040C08: nop

;}
RECOMP_FUNC void func_80760090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80760090: lui         $v0, 0x8076
    ctx->r2 = S32(RELOC_HI16(763, 0X7F0) << 16);
    // 0x80760094: jr          $ra
    // 0x80760098: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(763, 0X7F0));
    return;
    // 0x80760098: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(763, 0X7F0));
;}
RECOMP_FUNC void func_80072320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072320: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80072324: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80072328: lui         $fp, 0x8011
    ctx->r30 = S32(0X8011 << 16);
    // 0x8007232C: addiu       $fp, $fp, -0x2770
    ctx->r30 = ADD32(ctx->r30, -0X2770);
    // 0x80072330: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80072334: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80072338: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007233C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80072340: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80072344: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80072348: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007234C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80072350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072354: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80072358: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8007235C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80072360: jal         0x80082210
    // 0x80072364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80072364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80072368: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x8007236C: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80072370: addiu       $s1, $s1, -0x2790
    ctx->r17 = ADD32(ctx->r17, -0X2790);
    // 0x80072374: addiu       $s3, $s3, -0x26D0
    ctx->r19 = ADD32(ctx->r19, -0X26D0);
    // 0x80072378: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    // 0x8007237C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x80072380: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80072384: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80072388: addiu       $s2, $sp, 0x4C
    ctx->r18 = ADD32(ctx->r29, 0X4C);
    // 0x8007238C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_80072390:
    // 0x80072390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80072394: jal         0x800824B0
    // 0x80072398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80072398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007239C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800723A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800723A4: jal         0x800824B0
    // 0x800723A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800723A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800723AC: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x800723B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800723B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800723B8: jal         0x800824B0
    // 0x800723BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800723BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800723C0: bne         $v0, $zero, L_800723D4
    if (ctx->r2 != 0) {
        // 0x800723C4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800723D4;
    }
    // 0x800723C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800723C8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800723CC: jal         0x8008AFE0
    // 0x800723D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osJamMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800723D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_800723D4:
    // 0x800723D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800723D8: beq         $v0, $s4, L_80072410
    if (ctx->r2 == ctx->r20) {
        // 0x800723DC: nop
    
            goto L_80072410;
    }
    // 0x800723DC: nop

    // 0x800723E0: beq         $v0, $s5, L_80072400
    if (ctx->r2 == ctx->r21) {
        // 0x800723E4: nop
    
            goto L_80072400;
    }
    // 0x800723E4: nop

    // 0x800723E8: beq         $v0, $s6, L_80072420
    if (ctx->r2 == ctx->r22) {
        // 0x800723EC: nop
    
            goto L_80072420;
    }
    // 0x800723EC: nop

    // 0x800723F0: beq         $v0, $s7, L_80072430
    if (ctx->r2 == ctx->r23) {
        // 0x800723F4: nop
    
            goto L_80072430;
    }
    // 0x800723F4: nop

    // 0x800723F8: b           L_80072390
    // 0x800723FC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_80072390;
    // 0x800723FC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_80072400:
    // 0x80072400: jal         0x800721F8
    // 0x80072404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800721F8(rdram, ctx);
        goto after_5;
    // 0x80072404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80072408: b           L_80072390
    // 0x8007240C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_80072390;
    // 0x8007240C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_80072410:
    // 0x80072410: jal         0x80072278
    // 0x80072414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80072278(rdram, ctx);
        goto after_6;
    // 0x80072414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80072418: b           L_80072390
    // 0x8007241C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_80072390;
    // 0x8007241C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_80072420:
    // 0x80072420: jal         0x800720E8
    // 0x80072424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800720E8(rdram, ctx);
        goto after_7;
    // 0x80072424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80072428: b           L_80072390
    // 0x8007242C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_80072390;
    // 0x8007242C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_80072430:
    // 0x80072430: jal         0x80072150
    // 0x80072434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80072150(rdram, ctx);
        goto after_8;
    // 0x80072434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80072438: b           L_80072390
    // 0x8007243C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_80072390;
    // 0x8007243C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80072440: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80072444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80072448: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007244C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80072450: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80072454: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80072458: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007245C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80072460: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80072464: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80072468: jr          $ra
    // 0x8007246C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007246C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_805AA678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA678: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AA67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA680: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x805AA684: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805AA688: jal         0x80049D74
    // 0x805AA68C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x805AA68C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805AA690: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AA694: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x805AA698: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805AA69C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805AA6A0: jal         0x8004D150
    // 0x805AA6A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x805AA6A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x805AA6A8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x805AA6AC: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(432, 0XB20) << 16);
    // 0x805AA6B0: lwc1        $f4, -0x51F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(432, 0XB20));
    // 0x805AA6B4: lwc1        $f6, 0xC8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x805AA6B8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x805AA6BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AA6C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805AA6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805AA6C8: bc1f        L_805AA6EC
    if (!c1cs) {
        // 0x805AA6CC: nop
    
            goto L_805AA6EC;
    }
    // 0x805AA6CC: nop

    // 0x805AA6D0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805AA6D4: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x805AA6D8: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x805AA6DC: beq         $t0, $zero, L_805AA6EC
    if (ctx->r8 == 0) {
        // 0x805AA6E0: nop
    
            goto L_805AA6EC;
    }
    // 0x805AA6E0: nop

    // 0x805AA6E4: b           L_805AA6EC
    // 0x805AA6E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805AA6EC;
    // 0x805AA6E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805AA6EC:
    // 0x805AA6EC: jr          $ra
    // 0x805AA6F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805AA6F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804287CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804287CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804287D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804287D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804287D8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804287DC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804287E0: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(41, 0X1D18) << 16);
    // 0x804287E4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804287E8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804287EC: addiu       $t7, $t7, -0x69A8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(41, 0X1D18));
    // 0x804287F0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804287F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804287F8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804287FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80428800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80428804: jal         0x804288A0
    // 0x80428808: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804288A0(rdram, ctx);
        goto after_0;
    // 0x80428808: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8042880C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80428810: jal         0x80045A34
    // 0x80428814: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80428814: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x80428818: bne         $v0, $zero, L_80428830
    if (ctx->r2 != 0) {
        // 0x8042881C: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_80428830;
    }
    // 0x8042881C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80428820: jal         0x800445A4
    // 0x80428824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80428824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80428828: b           L_80428890
    // 0x8042882C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80428890;
    // 0x8042882C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80428830:
    // 0x80428830: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x80428834: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80428838: jal         0x800657CC
    // 0x8042883C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_3;
    // 0x8042883C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80428840: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80428844: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x80428848: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8042884C: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80428850: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x80428854: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x80428858: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8042885C: lui         $t3, 0x8042
    ctx->r11 = S32(RELOC_HI16(41, 0X458) << 16);
    // 0x80428860: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x80428864: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x80428868: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042886C: addiu       $t3, $t3, 0x7D98
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(41, 0X458));
    // 0x80428870: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80428874: sh          $v0, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r2;
    // 0x80428878: sw          $t2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r10;
    // 0x8042887C: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    // 0x80428880: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80428884: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    // 0x80428888: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8042888C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80428890:
    // 0x80428890: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80428894: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80428898: jr          $ra
    // 0x8042889C: nop

    return;
    // 0x8042889C: nop

;}
RECOMP_FUNC void func_800800CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800800CC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800800D0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800800D4: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800800D8: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800800DC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800800E0: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800800E4: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800800E8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800800EC: lwc1        $f14, 0x30($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800800F0: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800800F4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800800F8: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800800FC: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80080100: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80080104: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80080108: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8008010C: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80080110: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80080114: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80080118: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8008011C: nop

    // 0x80080120: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80080124: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80080128: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8008012C: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80080130: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80080134: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80080138: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8008013C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80080140: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80080144: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80080148: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8008014C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80080150: nop

    // 0x80080154: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080158: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8008015C: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80080160: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80080164: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80080168: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008016C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80080170: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x80080174: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80080178: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8008017C: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80080180: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80080184: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80080188: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8008018C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80080190: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80080194: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80080198: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8008019C: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800801A0: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800801A4: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800801A8: lwc1        $f14, 0x34($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800801AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800801B0: swc1        $f18, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f18.u32l;
    // 0x800801B4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800801B8: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800801BC: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800801C0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800801C4: nop

    // 0x800801C8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800801CC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800801D0: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800801D4: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800801D8: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800801DC: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800801E0: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800801E4: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800801E8: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800801EC: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800801F0: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800801F4: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800801F8: nop

    // 0x800801FC: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80080200: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80080204: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80080208: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8008020C: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80080210: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80080214: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80080218: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8008021C: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80080220: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80080224: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80080228: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8008022C: nop

    // 0x80080230: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080234: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80080238: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8008023C: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80080240: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80080244: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080248: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8008024C: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80080250: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80080254: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80080258: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8008025C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80080260: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80080264: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80080268: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8008026C: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80080270: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80080274: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80080278: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8008027C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80080280: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080284: lwc1        $f14, 0x38($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80080288: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008028C: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x80080290: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80080294: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80080298: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8008029C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800802A0: nop

    // 0x800802A4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800802A8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800802AC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800802B0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800802B4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800802B8: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800802BC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800802C0: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x800802C4: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800802C8: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800802CC: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800802D0: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800802D4: nop

    // 0x800802D8: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800802DC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800802E0: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800802E4: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800802E8: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800802EC: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800802F0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800802F4: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800802F8: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800802FC: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80080300: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80080304: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80080308: nop

    // 0x8008030C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080310: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80080314: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80080318: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8008031C: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80080320: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080324: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80080328: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x8008032C: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80080330: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80080334: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80080338: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8008033C: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80080340: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80080344: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80080348: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8008034C: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80080350: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80080354: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80080358: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8008035C: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080360: lwc1        $f14, 0x3C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80080364: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080368: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    // 0x8008036C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80080370: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80080374: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80080378: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8008037C: nop

    // 0x80080380: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80080384: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080388: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8008038C: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80080390: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80080394: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80080398: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8008039C: swc1        $f18, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f18.u32l;
    // 0x800803A0: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800803A4: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800803A8: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800803AC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800803B0: nop

    // 0x800803B4: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800803B8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800803BC: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800803C0: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800803C4: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800803C8: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800803CC: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800803D0: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
    // 0x800803D4: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800803D8: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800803DC: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800803E0: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800803E4: nop

    // 0x800803E8: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800803EC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800803F0: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800803F4: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800803F8: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800803FC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080400: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80080404: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x80080408: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8008040C: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80080410: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80080414: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80080418: nop

    // 0x8008041C: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80080420: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80080424: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80080428: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8008042C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80080430: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080434: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80080438: jr          $ra
    // 0x8008043C: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x8008043C: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_806EC324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC324: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806EC328: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x806EC32C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EC330: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EC334: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x806EC338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EC33C: jal         0x806EC03C
    // 0x806EC340: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_806EC03C(rdram, ctx);
        goto after_0;
    // 0x806EC340: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EC344: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x806EC348: jal         0x80047090
    // 0x806EC34C: addiu       $a0, $zero, 0x45E3
    ctx->r4 = ADD32(0, 0X45E3);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x806EC34C: addiu       $a0, $zero, 0x45E3
    ctx->r4 = ADD32(0, 0X45E3);
    after_1:
    // 0x806EC350: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x806EC354: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x806EC358: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806EC35C: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x806EC360: lui         $at, 0x45E3
    ctx->r1 = S32(0X45E3 << 16);
    // 0x806EC364: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x806EC368: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806EC36C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EC370: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x806EC374: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806EC378: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806EC37C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CC0) << 16);
    // 0x806EC380: lwc1        $f6, 0xC10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CC0));
    // 0x806EC384: lwc1        $f4, 0x8C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x806EC388: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x806EC38C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x806EC390: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EC394: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806EC398: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x806EC39C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x806EC3A0: jal         0x8004613C
    // 0x806EC3A4: nop

    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x806EC3A4: nop

    after_2:
    // 0x806EC3A8: beq         $v0, $zero, L_806EC430
    if (ctx->r2 == 0) {
        // 0x806EC3AC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806EC430;
    }
    // 0x806EC3AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806EC3B0: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x806EC3B4: lhu         $t0, 0xE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XE);
    // 0x806EC3B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806EC3BC: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x806EC3C0: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x806EC3C4: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x806EC3C8: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x806EC3CC: jal         0x80047F9C
    // 0x806EC3D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x806EC3D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x806EC3D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806EC3D8: sb          $t3, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r11;
    // 0x806EC3DC: jal         0x8005FDC4
    // 0x806EC3E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x806EC3E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EC3E4: jal         0x806F02A0
    // 0x806EC3E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F02A0(rdram, ctx);
        goto after_5;
    // 0x806EC3E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EC3EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806EC3F0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806EC3F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806EC3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC3FC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806EC400: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC404: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EC408: bc1f        L_806EC428
    if (!c1cs) {
        // 0x806EC40C: nop
    
            goto L_806EC428;
    }
    // 0x806EC40C: nop

    // 0x806EC410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC418: jal         0x806F0348
    // 0x806EC41C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806F0348(rdram, ctx);
        goto after_6;
    // 0x806EC41C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x806EC420: b           L_806EC434
    // 0x806EC424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EC434;
    // 0x806EC424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC428:
    // 0x806EC428: jal         0x806F0348
    // 0x806EC42C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806F0348(rdram, ctx);
        goto after_7;
    // 0x806EC42C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
L_806EC430:
    // 0x806EC430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC434:
    // 0x806EC434: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EC438: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806EC43C: jr          $ra
    // 0x806EC440: nop

    return;
    // 0x806EC440: nop

;}
RECOMP_FUNC void func_806E93E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E93E4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x806E93E8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x806E93EC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x806E93F0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x806E93F4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x806E93F8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x806E93FC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x806E9400: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x806E9404: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x806E9408: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x806E940C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x806E9410: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x806E9414: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x806E9418: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806E941C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806E9420: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x806E9424: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x806E9428: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E942C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x806E9430: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806E9434: lwc1        $f4, 0x5D4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X5D4);
    // 0x806E9438: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E943C: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x806E9440: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x806E9444: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806E9448: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806E944C: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x806E9450: jal         0x80049018
    // 0x806E9454: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x806E9454: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
    after_0:
    // 0x806E9458: beq         $v0, $zero, L_806E9464
    if (ctx->r2 == 0) {
        // 0x806E945C: addiu       $t7, $zero, 0x2E
        ctx->r15 = ADD32(0, 0X2E);
            goto L_806E9464;
    }
    // 0x806E945C: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x806E9460: subu        $s6, $t7, $s0
    ctx->r22 = SUB32(ctx->r15, ctx->r16);
L_806E9464:
    // 0x806E9464: slti        $at, $s6, -0x3
    ctx->r1 = SIGNED(ctx->r22) < -0X3 ? 1 : 0;
    // 0x806E9468: bne         $at, $zero, L_806E9688
    if (ctx->r1 != 0) {
        // 0x806E946C: slti        $at, $s6, 0x31
        ctx->r1 = SIGNED(ctx->r22) < 0X31 ? 1 : 0;
            goto L_806E9688;
    }
    // 0x806E946C: slti        $at, $s6, 0x31
    ctx->r1 = SIGNED(ctx->r22) < 0X31 ? 1 : 0;
    // 0x806E9470: beq         $at, $zero, L_806E9688
    if (ctx->r1 == 0) {
        // 0x806E9474: lwc1        $f18, 0xB8($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
            goto L_806E9688;
    }
    // 0x806E9474: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x806E9478: bgez        $s6, L_806E9484
    if (SIGNED(ctx->r22) >= 0) {
        // 0x806E947C: or          $v0, $s6, $zero
        ctx->r2 = ctx->r22 | 0;
            goto L_806E9484;
    }
    // 0x806E947C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x806E9480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806E9484:
    // 0x806E9484: slti        $at, $s6, 0x2E
    ctx->r1 = SIGNED(ctx->r22) < 0X2E ? 1 : 0;
    // 0x806E9488: bne         $at, $zero, L_806E9494
    if (ctx->r1 != 0) {
        // 0x806E948C: or          $s1, $s6, $zero
        ctx->r17 = ctx->r22 | 0;
            goto L_806E9494;
    }
    // 0x806E948C: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x806E9490: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_806E9494:
    // 0x806E9494: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x806E9498: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x806E949C: lwc1        $f16, 0x458($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X458);
    // 0x806E94A0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806E94A4: addiu       $s4, $s6, -0x3
    ctx->r20 = ADD32(ctx->r22, -0X3);
    // 0x806E94A8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806E94AC: nop

    // 0x806E94B0: bc1fl       L_806E968C
    if (!c1cs) {
        // 0x806E94B4: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_806E968C;
    }
    goto skip_0;
    // 0x806E94B4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x806E94B8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x806E94BC: slt         $at, $s4, $s6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x806E94C0: beq         $at, $zero, L_806E9598
    if (ctx->r1 == 0) {
        // 0x806E94C4: mov.s       $f24, $f26
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
            goto L_806E9598;
    }
    // 0x806E94C4: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x806E94C8: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x806E94CC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x806E94D0: lwc1        $f28, 0xC0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x806E94D4: addiu       $s3, $sp, 0x7C
    ctx->r19 = ADD32(ctx->r29, 0X7C);
L_806E94D8:
    // 0x806E94D8: slti        $at, $s1, 0x2E
    ctx->r1 = SIGNED(ctx->r17) < 0X2E ? 1 : 0;
    // 0x806E94DC: beql        $at, $zero, L_806E9588
    if (ctx->r1 == 0) {
        // 0x806E94E0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_806E9588;
    }
    goto skip_1;
    // 0x806E94E0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x806E94E4: bltzl       $s1, L_806E9588
    if (SIGNED(ctx->r17) < 0) {
        // 0x806E94E8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_806E9588;
    }
    goto skip_2;
    // 0x806E94E8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x806E94EC: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    // 0x806E94F0: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x806E94F4: addu        $s0, $s5, $t0
    ctx->r16 = ADD32(ctx->r21, ctx->r8);
    // 0x806E94F8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E94FC: lwc1        $f16, 0x510($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X510);
    // 0x806E9500: lwc1        $f14, 0x458($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X458);
    // 0x806E9504: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x806E9508: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806E950C: add.s       $f20, $f16, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x806E9510: mul.s       $f12, $f18, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x806E9514: jal         0x80066E88
    // 0x806E9518: sub.s       $f22, $f28, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f28.fl - ctx->f10.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806E9518: sub.s       $f22, $f28, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f28.fl - ctx->f10.fl;
    after_1:
    // 0x806E951C: add.s       $f18, $f20, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x806E9520: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x806E9524: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x806E9528: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806E952C: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806E9530: c.lt.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl < ctx->f2.fl;
    // 0x806E9534: nop

    // 0x806E9538: bc1fl       L_806E9588
    if (!c1cs) {
        // 0x806E953C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_806E9588;
    }
    goto skip_3;
    // 0x806E953C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_3:
    // 0x806E9540: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x806E9544: jal         0x806E9350
    // 0x806E9548: lw          $a1, 0x510($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X510);
    func_806E9350(rdram, ctx);
        goto after_2;
    // 0x806E9548: lw          $a1, 0x510($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X510);
    after_2:
    // 0x806E954C: lwc1        $f8, 0x510($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X510);
    // 0x806E9550: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x806E9554: lwc1        $f18, 0x458($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X458);
    // 0x806E9558: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806E955C: swc1        $f16, 0x510($s0)
    MEM_W(0X510, ctx->r16) = ctx->f16.u32l;
    // 0x806E9560: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x806E9564: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806E9568: swc1        $f6, 0x458($s0)
    MEM_W(0X458, ctx->r16) = ctx->f6.u32l;
    // 0x806E956C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x806E9570: c.lt.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl < ctx->f8.fl;
    // 0x806E9574: nop

    // 0x806E9578: bc1fl       L_806E9588
    if (!c1cs) {
        // 0x806E957C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_806E9588;
    }
    goto skip_4;
    // 0x806E957C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_4:
    // 0x806E9580: mov.s       $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = ctx->f8.fl;
    // 0x806E9584: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_806E9588:
    // 0x806E9588: slt         $at, $s4, $s1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x806E958C: bne         $at, $zero, L_806E94D8
    if (ctx->r1 != 0) {
        // 0x806E9590: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806E94D8;
    }
    // 0x806E9590: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806E9594: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_806E9598:
    // 0x806E9598: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x806E959C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x806E95A0: addiu       $s1, $s6, 0x1
    ctx->r17 = ADD32(ctx->r22, 0X1);
    // 0x806E95A4: addiu       $s4, $s6, 0x3
    ctx->r20 = ADD32(ctx->r22, 0X3);
    // 0x806E95A8: slt         $at, $s4, $s1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x806E95AC: addiu       $s3, $sp, 0x7C
    ctx->r19 = ADD32(ctx->r29, 0X7C);
    // 0x806E95B0: bne         $at, $zero, L_806E9674
    if (ctx->r1 != 0) {
        // 0x806E95B4: lwc1        $f28, 0xC0($sp)
        ctx->f28.u32l = MEM_W(ctx->r29, 0XC0);
            goto L_806E9674;
    }
    // 0x806E95B4: lwc1        $f28, 0xC0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XC0);
L_806E95B8:
    // 0x806E95B8: slti        $at, $s1, 0x2E
    ctx->r1 = SIGNED(ctx->r17) < 0X2E ? 1 : 0;
    // 0x806E95BC: beql        $at, $zero, L_806E9668
    if (ctx->r1 == 0) {
        // 0x806E95C0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806E9668;
    }
    goto skip_5;
    // 0x806E95C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x806E95C4: bltzl       $s1, L_806E9668
    if (SIGNED(ctx->r17) < 0) {
        // 0x806E95C8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806E9668;
    }
    goto skip_6;
    // 0x806E95C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_6:
    // 0x806E95CC: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    // 0x806E95D0: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x806E95D4: addu        $s0, $s5, $t1
    ctx->r16 = ADD32(ctx->r21, ctx->r9);
    // 0x806E95D8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806E95DC: lwc1        $f16, 0x510($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X510);
    // 0x806E95E0: lwc1        $f14, 0x458($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X458);
    // 0x806E95E4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x806E95E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806E95EC: add.s       $f20, $f16, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x806E95F0: mul.s       $f12, $f18, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x806E95F4: jal         0x80066E88
    // 0x806E95F8: sub.s       $f22, $f28, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f28.fl - ctx->f10.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x806E95F8: sub.s       $f22, $f28, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f28.fl - ctx->f10.fl;
    after_3:
    // 0x806E95FC: add.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x806E9600: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x806E9604: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x806E9608: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806E960C: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806E9610: c.lt.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl < ctx->f2.fl;
    // 0x806E9614: nop

    // 0x806E9618: bc1fl       L_806E9668
    if (!c1cs) {
        // 0x806E961C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806E9668;
    }
    goto skip_7;
    // 0x806E961C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x806E9620: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x806E9624: jal         0x806E9350
    // 0x806E9628: lw          $a1, 0x510($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X510);
    func_806E9350(rdram, ctx);
        goto after_4;
    // 0x806E9628: lw          $a1, 0x510($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X510);
    after_4:
    // 0x806E962C: lwc1        $f18, 0x510($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X510);
    // 0x806E9630: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x806E9634: lwc1        $f8, 0x458($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X458);
    // 0x806E9638: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806E963C: swc1        $f6, 0x510($s0)
    MEM_W(0X510, ctx->r16) = ctx->f6.u32l;
    // 0x806E9640: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x806E9644: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806E9648: swc1        $f16, 0x458($s0)
    MEM_W(0X458, ctx->r16) = ctx->f16.u32l;
    // 0x806E964C: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x806E9650: c.lt.s      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.fl < ctx->f18.fl;
    // 0x806E9654: nop

    // 0x806E9658: bc1fl       L_806E9668
    if (!c1cs) {
        // 0x806E965C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806E9668;
    }
    goto skip_8;
    // 0x806E965C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x806E9660: mov.s       $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    ctx->f24.fl = ctx->f18.fl;
    // 0x806E9664: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_806E9668:
    // 0x806E9668: slt         $at, $s4, $s1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x806E966C: beq         $at, $zero, L_806E95B8
    if (ctx->r1 == 0) {
        // 0x806E9670: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_806E95B8;
    }
    // 0x806E9670: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_806E9674:
    // 0x806E9674: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x806E9678: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x806E967C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x806E9680: jalr        $t9
    // 0x806E9684: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x806E9684: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    after_5:
L_806E9688:
    // 0x806E9688: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_806E968C:
    // 0x806E968C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806E9690: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806E9694: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806E9698: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x806E969C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x806E96A0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x806E96A4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x806E96A8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x806E96AC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x806E96B0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x806E96B4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x806E96B8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x806E96BC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x806E96C0: jr          $ra
    // 0x806E96C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x806E96C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_804538C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804538C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804538CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804538D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804538D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804538D8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x804538DC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804538E0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x804538E4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x804538E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804538EC: jal         0x8044EFA0
    // 0x804538F0: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x804538F0: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    after_0:
    // 0x804538F4: jal         0x8044DED8
    // 0x804538F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044DED8(rdram, ctx);
        goto after_1;
    // 0x804538F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804538FC: jal         0x8044E87C
    // 0x80453900: nop

    func_8044E87C(rdram, ctx);
        goto after_2;
    // 0x80453900: nop

    after_2:
    // 0x80453904: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453908: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8045390C: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80453910: sw          $t7, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r15;
    // 0x80453914: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80453918: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045391C: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80453920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80453924: jal         0x80445DF0
    // 0x80453928: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    func_80445DF0(rdram, ctx);
        goto after_3;
    // 0x80453928: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    after_3:
    // 0x8045392C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80453930: jal         0x80445E2C
    // 0x80453934: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80445E2C(rdram, ctx);
        goto after_4;
    // 0x80453934: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80453938: jal         0x80445B34
    // 0x8045393C: nop

    func_80445B34(rdram, ctx);
        goto after_5;
    // 0x8045393C: nop

    after_5:
    // 0x80453940: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453944: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80453948: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8045394C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80453950: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80453954: sw          $t8, 0x6F08($at)
    MEM_W(0X6F08, ctx->r1) = ctx->r24;
    // 0x80453958: lbu         $t0, 0xF5C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF5C);
    // 0x8045395C: lbu         $t9, 0xF5D($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF5D);
    // 0x80453960: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80453964: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80453968: sb          $t9, 0xF64($t1)
    MEM_B(0XF64, ctx->r9) = ctx->r25;
    // 0x8045396C: lw          $v1, 0xCEC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XCEC);
    // 0x80453970: slti        $at, $v1, 0x2710
    ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
    // 0x80453974: beql        $at, $zero, L_80453990
    if (ctx->r1 == 0) {
        // 0x80453978: slti        $at, $v1, 0x3A98
        ctx->r1 = SIGNED(ctx->r3) < 0X3A98 ? 1 : 0;
            goto L_80453990;
    }
    goto skip_0;
    // 0x80453978: slti        $at, $v1, 0x3A98
    ctx->r1 = SIGNED(ctx->r3) < 0X3A98 ? 1 : 0;
    skip_0:
    // 0x8045397C: jal         0x80445B74
    // 0x80453980: sb          $zero, 0xF6A($v0)
    MEM_B(0XF6A, ctx->r2) = 0;
    func_80445B74(rdram, ctx);
        goto after_6;
    // 0x80453980: sb          $zero, 0xF6A($v0)
    MEM_B(0XF6A, ctx->r2) = 0;
    after_6:
    // 0x80453984: b           L_804539E0
    // 0x80453988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804539E0;
    // 0x80453988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045398C: slti        $at, $v1, 0x3A98
    ctx->r1 = SIGNED(ctx->r3) < 0X3A98 ? 1 : 0;
L_80453990:
    // 0x80453990: beq         $at, $zero, L_804539AC
    if (ctx->r1 == 0) {
        // 0x80453994: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_804539AC;
    }
    // 0x80453994: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80453998: sb          $t2, 0xF6A($v0)
    MEM_B(0XF6A, ctx->r2) = ctx->r10;
    // 0x8045399C: jal         0x80445B74
    // 0x804539A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80445B74(rdram, ctx);
        goto after_7;
    // 0x804539A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x804539A4: b           L_804539E0
    // 0x804539A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804539E0;
    // 0x804539A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804539AC:
    // 0x804539AC: slti        $at, $v1, 0x7530
    ctx->r1 = SIGNED(ctx->r3) < 0X7530 ? 1 : 0;
    // 0x804539B0: beq         $at, $zero, L_804539D0
    if (ctx->r1 == 0) {
        // 0x804539B4: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_804539D0;
    }
    // 0x804539B4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x804539B8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x804539BC: sb          $t3, 0xF6A($v0)
    MEM_B(0XF6A, ctx->r2) = ctx->r11;
    // 0x804539C0: jal         0x80445B74
    // 0x804539C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80445B74(rdram, ctx);
        goto after_8;
    // 0x804539C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x804539C8: b           L_804539E0
    // 0x804539CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804539E0;
    // 0x804539CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804539D0:
    // 0x804539D0: sb          $t4, 0xF6A($v0)
    MEM_B(0XF6A, ctx->r2) = ctx->r12;
    // 0x804539D4: jal         0x80445B74
    // 0x804539D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80445B74(rdram, ctx);
        goto after_9;
    // 0x804539D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x804539DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804539E0:
    // 0x804539E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804539E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804539E8: jr          $ra
    // 0x804539EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804539EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8003B2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B2B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B2B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B2B8: jal         0x8003B26C
    // 0x8003B2BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003B26C(rdram, ctx);
        goto after_0;
    // 0x8003B2BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B2C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B2C4: jal         0x8003B694
    // 0x8003B2C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003B694(rdram, ctx);
        goto after_1;
    // 0x8003B2C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8003B2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B2D4: jr          $ra
    // 0x8003B2D8: nop

    return;
    // 0x8003B2D8: nop

;}
RECOMP_FUNC void func_8056682C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056682C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80566830: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80566834: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(375, 0XC9C) << 16);
    // 0x80566838: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8056683C: lui         $t0, 0x8056
    ctx->r8 = S32(RELOC_HI16(375, 0XC54) << 16);
    // 0x80566840: beq         $v1, $zero, L_80566850
    if (ctx->r3 == 0) {
        // 0x80566844: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80566850;
    }
    // 0x80566844: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80566848: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8056684C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80566850:
    // 0x80566850: bne         $v1, $zero, L_805668F8
    if (ctx->r3 != 0) {
        // 0x80566854: nop
    
            goto L_805668F8;
    }
    // 0x80566854: nop

    // 0x80566858: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8056685C: addiu       $t0, $t0, 0x71A4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(375, 0XC54));
    // 0x80566860: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80566864: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80566868: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8056686C: lw          $t8, 0x71EC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(375, 0XC9C));
    // 0x80566870: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80566874: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x80566878: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8056687C: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80566880: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80566884: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80566888: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x8056688C: nop

    // 0x80566890: bc1tl       L_805668AC
    if (c1cs) {
        // 0x80566894: lwc1        $f2, 0x4($a2)
        ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
            goto L_805668AC;
    }
    goto skip_0;
    // 0x80566894: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    skip_0:
    // 0x80566898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8056689C: nop

    // 0x805668A0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x805668A4: nop

    // 0x805668A8: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
L_805668AC:
    // 0x805668AC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805668B0: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x805668B4: nop

    // 0x805668B8: bc1tl       L_805668D4
    if (c1cs) {
        // 0x805668BC: swc1        $f0, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
            goto L_805668D4;
    }
    goto skip_1;
    // 0x805668BC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x805668C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805668C4: nop

    // 0x805668C8: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x805668CC: nop

    // 0x805668D0: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
L_805668D4:
    // 0x805668D4: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x805668D8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x805668DC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x805668E0: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x805668E4: bne         $at, $zero, L_805668F8
    if (ctx->r1 != 0) {
        // 0x805668E8: sw          $t2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r10;
            goto L_805668F8;
    }
    // 0x805668E8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x805668EC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x805668F0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x805668F4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_805668F8:
    // 0x805668F8: jr          $ra
    // 0x805668FC: nop

    return;
    // 0x805668FC: nop

;}
RECOMP_FUNC void func_8040DB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040DB88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040DB8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040DB90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040DB94: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040DB98: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1F1C) << 16);
    // 0x8040DB9C: lwc1        $f6, -0x1AE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1F1C));
    // 0x8040DBA0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8040DBA4: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8040DBA8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8040DBAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040DBB0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040DBB4: lui         $a1, 0x8041
    ctx->r5 = S32(RELOC_HI16(20, 0X1E68) << 16);
    // 0x8040DBB8: addiu       $a1, $a1, -0x1B98
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(20, 0X1E68));
    // 0x8040DBBC: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8040DBC0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8040DBC4: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8040DBC8: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8040DBCC: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8040DBD0: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8040DBD4: jalr        $t9
    // 0x8040DBD8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040DBD8: nop

    after_0:
    // 0x8040DBDC: jal         0x800610A0
    // 0x8040DBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800610A0(rdram, ctx);
        goto after_1;
    // 0x8040DBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8040DBE4: jal         0x80044658
    // 0x8040DBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_2;
    // 0x8040DBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8040DBEC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8040DBF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8040DBF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8040DBF8: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8040DBFC: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x8040DC00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8040DC04: bnel        $t2, $at, L_8040DC28
    if (ctx->r10 != ctx->r1) {
        // 0x8040DC08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040DC28;
    }
    goto skip_0;
    // 0x8040DC08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8040DC0C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8040DC10: jal         0x80067BBC
    // 0x8040DC14: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8040DC14: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8040DC18: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    // 0x8040DC1C: jal         0x80067818
    // 0x8040DC20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8040DC20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8040DC24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040DC28:
    // 0x8040DC28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040DC2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040DC30: jr          $ra
    // 0x8040DC34: nop

    return;
    // 0x8040DC34: nop

;}
RECOMP_FUNC void func_805D7F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7F40: jr          $ra
    // 0x805D7F44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805D7F44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80475150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475150: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475154: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475158: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047515C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475160: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475164: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475168: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047516C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475170: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475174: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475178: jr          $ra
    // 0x8047517C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047517C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8057A928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057A928: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8057A92C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057A930: jal         0x8004700C
    // 0x8057A934: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8057A934: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057A938: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8057A93C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8057A940: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8057A944: lw          $a1, 0x1F4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1F4);
    // 0x8057A948: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x8057A94C: addiu       $v1, $a1, 0x484
    ctx->r3 = ADD32(ctx->r5, 0X484);
L_8057A950:
    // 0x8057A950: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8057A954: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8057A958: beq         $a1, $zero, L_8057A964
    if (ctx->r5 == 0) {
        // 0x8057A95C: addiu       $t7, $a1, -0x1
        ctx->r15 = ADD32(ctx->r5, -0X1);
            goto L_8057A964;
    }
    // 0x8057A95C: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8057A960: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8057A964:
    // 0x8057A964: bne         $a0, $a2, L_8057A950
    if (ctx->r4 != ctx->r6) {
        // 0x8057A968: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8057A950;
    }
    // 0x8057A968: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8057A96C: beq         $v0, $zero, L_8057AA44
    if (ctx->r2 == 0) {
        // 0x8057A970: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_8057AA44;
    }
    // 0x8057A970: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8057A974: lw          $a0, -0x7630($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7630);
    // 0x8057A978: jal         0x800495AC
    // 0x8057A97C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800495AC(rdram, ctx);
        goto after_1;
    // 0x8057A97C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8057A980: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8057A984: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8057A988: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8057A98C: lw          $t8, 0xB30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB30);
    // 0x8057A990: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8057A994: beql        $a3, $t8, L_8057A9B8
    if (ctx->r7 == ctx->r24) {
        // 0x8057A998: slti        $at, $a3, 0x1E
        ctx->r1 = SIGNED(ctx->r7) < 0X1E ? 1 : 0;
            goto L_8057A9B8;
    }
    goto skip_0;
    // 0x8057A998: slti        $at, $a3, 0x1E
    ctx->r1 = SIGNED(ctx->r7) < 0X1E ? 1 : 0;
    skip_0:
    // 0x8057A99C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057A9A0: jal         0x8057B444
    // 0x8057A9A4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8057B444(rdram, ctx);
        goto after_2;
    // 0x8057A9A4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8057A9A8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8057A9AC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8057A9B0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8057A9B4: slti        $at, $a3, 0x1E
    ctx->r1 = SIGNED(ctx->r7) < 0X1E ? 1 : 0;
L_8057A9B8:
    // 0x8057A9B8: bne         $at, $zero, L_8057AA3C
    if (ctx->r1 != 0) {
        // 0x8057A9BC: nop
    
            goto L_8057AA3C;
    }
    // 0x8057A9BC: nop

    // 0x8057A9C0: lw          $t9, 0xB1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB1C);
    // 0x8057A9C4: beql        $t9, $zero, L_8057A9F8
    if (ctx->r25 == 0) {
        // 0x8057A9C8: lw          $t1, 0x5B4($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X5B4);
            goto L_8057A9F8;
    }
    goto skip_1;
    // 0x8057A9C8: lw          $t1, 0x5B4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X5B4);
    skip_1:
    // 0x8057A9CC: lbu         $t0, 0x3E8($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X3E8);
    // 0x8057A9D0: beq         $t0, $zero, L_8057AA3C
    if (ctx->r8 == 0) {
        // 0x8057A9D4: nop
    
            goto L_8057AA3C;
    }
    // 0x8057A9D4: nop

    // 0x8057A9D8: jal         0x8057A7E0
    // 0x8057A9DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8057A7E0(rdram, ctx);
        goto after_3;
    // 0x8057A9DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8057A9E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057A9E4: jal         0x8057B444
    // 0x8057A9E8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8057B444(rdram, ctx);
        goto after_4;
    // 0x8057A9E8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x8057A9EC: b           L_8057AA3C
    // 0x8057A9F0: nop

        goto L_8057AA3C;
    // 0x8057A9F0: nop

    // 0x8057A9F4: lw          $t1, 0x5B4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X5B4);
L_8057A9F8:
    // 0x8057A9F8: addiu       $t2, $t1, -0x9
    ctx->r10 = ADD32(ctx->r9, -0X9);
    // 0x8057A9FC: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x8057AA00: beq         $at, $zero, L_8057AA38
    if (ctx->r1 == 0) {
        // 0x8057AA04: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8057AA38;
    }
    // 0x8057AA04: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8057AA08: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B34) << 16);
    // 0x8057AA0C: addu        $at, $at, $t2
    gpr jr_addend_8057AA14 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8057AA10: lw          $t2, -0x4A8C($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B34));
    // 0x8057AA14: jr          $t2
    // 0x8057AA18: nop

    switch (jr_addend_8057AA14 >> 2) {
        case 0: goto L_8057AA1C; break;
        case 1: goto L_8057AA1C; break;
        case 2: goto L_8057AA1C; break;
        case 3: goto L_8057AA1C; break;
        case 4: goto L_8057AA38; break;
        case 5: goto L_8057AA38; break;
        case 6: goto L_8057AA38; break;
        case 7: goto L_8057AA38; break;
        case 8: goto L_8057AA38; break;
        case 9: goto L_8057AA38; break;
        case 10: goto L_8057AA38; break;
        case 11: goto L_8057AA38; break;
        case 12: goto L_8057AA1C; break;
        case 13: goto L_8057AA1C; break;
        case 14: goto L_8057AA1C; break;
        case 15: goto L_8057AA1C; break;
        default: switch_error(__func__, 0x8057AA14, 0x8057B574);
    }
    // 0x8057AA18: nop

L_8057AA1C:
    // 0x8057AA1C: jal         0x8057A7E0
    // 0x8057AA20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8057A7E0(rdram, ctx);
        goto after_5;
    // 0x8057AA20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8057AA24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8057AA28: jal         0x8057B444
    // 0x8057AA2C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8057B444(rdram, ctx);
        goto after_6;
    // 0x8057AA2C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x8057AA30: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8057AA34: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
L_8057AA38:
    // 0x8057AA38: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
L_8057AA3C:
    // 0x8057AA3C: jal         0x8057A2B8
    // 0x8057AA40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8057A2B8(rdram, ctx);
        goto after_7;
    // 0x8057AA40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
L_8057AA44:
    // 0x8057AA44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057AA48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8057AA4C: jr          $ra
    // 0x8057AA50: nop

    return;
    // 0x8057AA50: nop

;}
RECOMP_FUNC void func_807BA810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA810: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x807BA814: addiu       $at, $zero, 0x403E
    ctx->r1 = ADD32(0, 0X403E);
    // 0x807BA818: beq         $v0, $at, L_807BA82C
    if (ctx->r2 == ctx->r1) {
        // 0x807BA81C: addiu       $at, $zero, 0x4057
        ctx->r1 = ADD32(0, 0X4057);
            goto L_807BA82C;
    }
    // 0x807BA81C: addiu       $at, $zero, 0x4057
    ctx->r1 = ADD32(0, 0X4057);
    // 0x807BA820: beq         $v0, $at, L_807BA82C
    if (ctx->r2 == ctx->r1) {
        // 0x807BA824: addiu       $at, $zero, 0x4601
        ctx->r1 = ADD32(0, 0X4601);
            goto L_807BA82C;
    }
    // 0x807BA824: addiu       $at, $zero, 0x4601
    ctx->r1 = ADD32(0, 0X4601);
    // 0x807BA828: bne         $v0, $at, L_807BA838
    if (ctx->r2 != ctx->r1) {
        // 0x807BA82C: lui         $v0, 0x807C
        ctx->r2 = S32(RELOC_HI16(895, 0XE28) << 16);
            goto L_807BA838;
    }
L_807BA82C:
    // 0x807BA82C: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(895, 0XE28) << 16);
    // 0x807BA830: jr          $ra
    // 0x807BA834: addiu       $v0, $v0, -0x49C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(895, 0XE28));
    return;
    // 0x807BA834: addiu       $v0, $v0, -0x49C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(895, 0XE28));
L_807BA838:
    // 0x807BA838: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(895, 0XE28) << 16);
    // 0x807BA83C: addiu       $v0, $v0, -0x49C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(895, 0XE28));
    // 0x807BA840: jr          $ra
    // 0x807BA844: nop

    return;
    // 0x807BA844: nop

;}
RECOMP_FUNC void eepmgr_Write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D0B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007D0B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007D0B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007D0BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D0C0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8007D0C4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8007D0C8: jal         0x8007CDA0
    // 0x8007D0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007CDA0(rdram, ctx);
        goto after_0;
    // 0x8007D0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007D0D0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007D0D4: jal         0x8008B920
    // 0x8007D0D8: sb          $t6, 0x225($s0)
    MEM_B(0X225, ctx->r16) = ctx->r14;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8007D0D8: sb          $t6, 0x225($s0)
    MEM_B(0X225, ctx->r16) = ctx->r14;
    after_1:
    // 0x8007D0DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007D0E0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8007D0E4: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8007D0E8: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x8007D0EC: jal         0x800855C0
    // 0x8007D0F0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    osEepromWrite_recomp(rdram, ctx);
        goto after_2;
    // 0x8007D0F0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x8007D0F4: jal         0x8008B920
    // 0x8007D0F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x8007D0F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_3:
    // 0x8007D0FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8007D100: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8007D104: sb          $zero, 0x225($s0)
    MEM_B(0X225, ctx->r16) = 0;
    // 0x8007D108: jal         0x8007CDCC
    // 0x8007D10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007CDCC(rdram, ctx);
        goto after_4;
    // 0x8007D10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8007D110: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8007D114: addiu       $s0, $s0, -0x65E0
    ctx->r16 = ADD32(ctx->r16, -0X65E0);
    // 0x8007D118: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8007D11C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007D120: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007D124: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8007D128: bne         $at, $zero, L_8007D188
    if (ctx->r1 != 0) {
        // 0x8007D12C: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_8007D188;
    }
    // 0x8007D12C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8007D130: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D134: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x8007D138: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007D13C: sltu        $at, $t9, $t1
    ctx->r1 = ctx->r25 < ctx->r9 ? 1 : 0;
    // 0x8007D140: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x8007D144: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8007D148: jal         0x80082D88
    // 0x8007D14C: subu        $a1, $t9, $t1
    ctx->r5 = SUB32(ctx->r25, ctx->r9);
    __ll_mul_recomp(rdram, ctx);
        goto after_5;
    // 0x8007D14C: subu        $a1, $t9, $t1
    ctx->r5 = SUB32(ctx->r25, ctx->r9);
    after_5:
    // 0x8007D150: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007D154: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8007D158: lw          $a1, -0x53BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X53BC);
    // 0x8007D15C: lw          $a0, -0x53C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53C0);
    // 0x8007D160: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007D164: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007D168: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007D16C: jal         0x80082C88
    // 0x8007D170: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_6;
    // 0x8007D170: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_6:
    // 0x8007D174: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007D178: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8007D17C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8007D180: jal         0x80082C88
    // 0x8007D184: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x8007D184: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_7:
L_8007D188:
    // 0x8007D188: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8007D18C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8007D190: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8007D194: beq         $t2, $zero, L_8007D1A4
    if (ctx->r10 == 0) {
        // 0x8007D198: lui         $a2, 0x800B
        ctx->r6 = S32(0X800B << 16);
            goto L_8007D1A4;
    }
    // 0x8007D198: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8007D19C: b           L_8007D1D8
    // 0x8007D1A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007D1D8;
    // 0x8007D1A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007D1A4:
    // 0x8007D1A4: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8007D1A8: lw          $a3, -0x53BC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X53BC);
    // 0x8007D1AC: jal         0x80082D88
    // 0x8007D1B0: lw          $a2, -0x53C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X53C0);
    __ll_mul_recomp(rdram, ctx);
        goto after_8;
    // 0x8007D1B0: lw          $a2, -0x53C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X53C0);
    after_8:
    // 0x8007D1B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007D1B8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8007D1BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007D1C0: jal         0x80082C88
    // 0x8007D1C4: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    __ull_div_recomp(rdram, ctx);
        goto after_9;
    // 0x8007D1C4: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    after_9:
    // 0x8007D1C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007D1CC: jal         0x800821A0
    // 0x8007D1D0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    csleep(rdram, ctx);
        goto after_10;
    // 0x8007D1D0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_10:
    // 0x8007D1D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007D1D8:
    // 0x8007D1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D1DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007D1E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8007D1E4: jr          $ra
    // 0x8007D1E8: nop

    return;
    // 0x8007D1E8: nop

;}
RECOMP_FUNC void func_80423038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423038: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8042303C: jr          $ra
    // 0x80423040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80423040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80445F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445F10: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445F14: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80445F18: jr          $ra
    // 0x80445F1C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x80445F1C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_806AA178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AA17C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AA180: jal         0x806A98AC
    // 0x806AA184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806A98AC(rdram, ctx);
        goto after_0;
    // 0x806AA184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AA188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AA18C: bne         $v0, $at, L_806AA1A4
    if (ctx->r2 != ctx->r1) {
        // 0x806AA190: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AA1A4;
    }
    // 0x806AA190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AA194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA198: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806AA19C: jal         0x806AA784
    // 0x806AA1A0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806AA1A0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
L_806AA1A4:
    // 0x806AA1A4: jal         0x806AA06C
    // 0x806AA1A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806AA06C(rdram, ctx);
        goto after_2;
    // 0x806AA1A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806AA1AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AA1B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AA1B4: jr          $ra
    // 0x806AA1B8: nop

    return;
    // 0x806AA1B8: nop

;}
RECOMP_FUNC void func_80455688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455688: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x8045568C: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80455690: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80455694: lw          $a2, 0xA5C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XA5C);
    // 0x80455698: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8045569C: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x804556A0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x804556A4: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x804556A8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x804556AC: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x804556B0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x804556B4: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x804556B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804556BC: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x804556C0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x804556C4: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x804556C8: addiu       $t9, $t8, 0xAE0
    ctx->r25 = ADD32(ctx->r24, 0XAE0);
    // 0x804556CC: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x804556D0: jr          $ra
    // 0x804556D4: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    return;
    // 0x804556D4: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8052DC40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052DC40: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8052DC44: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8052DC48: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8052DC4C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8052DC50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8052DC54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8052DC58: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8052DC5C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8052DC60: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(330, 0X1700) << 16);
    // 0x8052DC64: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8052DC68: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8052DC6C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8052DC70: lw          $t1, -0x2330($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(330, 0X1700));
    // 0x8052DC74: jr          $ra
    // 0x8052DC78: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8052DC78: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8052DC7C: nop

;}
RECOMP_FUNC void func_804C23BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C23BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C23C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C23C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804C23C8: jal         0x80047090
    // 0x804C23CC: addiu       $a0, $zero, 0x4122
    ctx->r4 = ADD32(0, 0X4122);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804C23CC: addiu       $a0, $zero, 0x4122
    ctx->r4 = ADD32(0, 0X4122);
    after_0:
    // 0x804C23D0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804C23D4: bne         $v0, $at, L_804C23E4
    if (ctx->r2 != ctx->r1) {
        // 0x804C23D8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804C23E4;
    }
    // 0x804C23D8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804C23DC: b           L_804C2444
    // 0x804C23E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C2444;
    // 0x804C23E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C23E4:
    // 0x804C23E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804C23E8: lui         $at, 0x4122
    ctx->r1 = S32(0X4122 << 16);
    // 0x804C23EC: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x804C23F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804C23F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804C23F8: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x804C23FC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804C2400: jal         0x8004613C
    // 0x804C2404: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804C2404: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x804C2408: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x804C240C: bne         $v0, $zero, L_804C241C
    if (ctx->r2 != 0) {
        // 0x804C2410: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804C241C;
    }
    // 0x804C2410: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804C2414: b           L_804C2444
    // 0x804C2418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C2444;
    // 0x804C2418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C241C:
    // 0x804C241C: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x804C2420: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804C2424: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x804C2428: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804C242C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804C2430: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x804C2434: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x804C2438: jal         0x80047F9C
    // 0x804C243C: sw          $t1, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r9;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804C243C: sw          $t1, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r9;
    after_2:
    // 0x804C2440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C2444:
    // 0x804C2444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C2448: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C244C: jr          $ra
    // 0x804C2450: nop

    return;
    // 0x804C2450: nop

;}
RECOMP_FUNC void func_8004A0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A0DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004A0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A0E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004A0E8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8004A0EC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8004A0F0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8004A0F4: lw          $a0, 0x30($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X30);
    // 0x8004A0F8: jal         0x80064E84
    // 0x8004A0FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8004A0FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8004A100: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8004A104: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8004A108: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004A10C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8004A110: sw          $zero, 0x30($t1)
    MEM_W(0X30, ctx->r9) = 0;
    // 0x8004A114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004A11C: jr          $ra
    // 0x8004A120: nop

    return;
    // 0x8004A120: nop

;}
RECOMP_FUNC void func_8044A81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A81C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044A820: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13464) << 16);
    // 0x8044A824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A828: addiu       $t6, $t6, 0x7844
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13464));
    // 0x8044A82C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044A830: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044A834: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044A838: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044A83C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044A840: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A844: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044A848: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044A84C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044A850: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044A854: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044A858: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A85C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A860: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044A864: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044A868: jal         0x80050A50
    // 0x8044A86C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044A86C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044A870: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044A874: jalr        $v0
    // 0x8044A878: sw          $v0, 0x6A54($v1)
    MEM_W(0X6A54, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044A878: sw          $v0, 0x6A54($v1)
    MEM_W(0X6A54, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044A87C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A880: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x8044A884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A888: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044A88C: jr          $ra
    // 0x8044A890: nop

    return;
    // 0x8044A890: nop

;}
RECOMP_FUNC void func_8057DC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DC28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057DC2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057DC30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057DC34: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8057DC38: addiu       $at, $zero, 0x41C7
    ctx->r1 = ADD32(0, 0X41C7);
    // 0x8057DC3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057DC40: beq         $v0, $at, L_8057DC50
    if (ctx->r2 == ctx->r1) {
        // 0x8057DC44: addiu       $at, $zero, 0x41D0
        ctx->r1 = ADD32(0, 0X41D0);
            goto L_8057DC50;
    }
    // 0x8057DC44: addiu       $at, $zero, 0x41D0
    ctx->r1 = ADD32(0, 0X41D0);
    // 0x8057DC48: bne         $v0, $at, L_8057DC58
    if (ctx->r2 != ctx->r1) {
        // 0x8057DC4C: nop
    
            goto L_8057DC58;
    }
    // 0x8057DC4C: nop

L_8057DC50:
    // 0x8057DC50: jal         0x8057DC94
    // 0x8057DC54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057DC94(rdram, ctx);
        goto after_0;
    // 0x8057DC54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_8057DC58:
    // 0x8057DC58: lui         $t6, 0x8058
    ctx->r14 = S32(RELOC_HI16(393, 0XC0) << 16);
    // 0x8057DC5C: addiu       $t6, $t6, -0x2400
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(393, 0XC0));
    // 0x8057DC60: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x8057DC64: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8057DC68: jal         0x80067BBC
    // 0x8057DC6C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8057DC6C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8057DC70: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8057DC74: jal         0x80067F78
    // 0x8057DC78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x8057DC78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8057DC7C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8057DC80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057DC84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057DC88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057DC8C: jr          $ra
    // 0x8057DC90: nop

    return;
    // 0x8057DC90: nop

;}
RECOMP_FUNC void func_806D093C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D093C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D0940: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806D0944: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806D0948: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806D094C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0950: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806D0954: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x806D0958: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806D095C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806D0960: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806D0964: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806D0968: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806D096C: lui         $t2, 0x806D
    ctx->r10 = S32(RELOC_HI16(607, 0X19D0) << 16);
    // 0x806D0970: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D0974: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806D0978: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806D097C: lw          $t2, 0x1170($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(607, 0X19D0));
    // 0x806D0980: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806D0984: jal         0x806CF8C0
    // 0x806D0988: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_806CF8C0(rdram, ctx);
        goto after_0;
    // 0x806D0988: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x806D098C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D0990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0994: jr          $ra
    // 0x806D0998: nop

    return;
    // 0x806D0998: nop

;}
RECOMP_FUNC void func_806791CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806791CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806791D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806791D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806791D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806791DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806791E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806791E4: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x806791E8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806791EC: lw          $t8, 0x304($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X304);
    // 0x806791F0: sll         $t9, $t8, 7
    ctx->r25 = S32(ctx->r24 << 7);
    // 0x806791F4: addu        $a3, $v0, $t9
    ctx->r7 = ADD32(ctx->r2, ctx->r25);
    // 0x806791F8: bne         $v1, $at, L_8067925C
    if (ctx->r3 != ctx->r1) {
        // 0x806791FC: addiu       $a3, $a3, 0x180
        ctx->r7 = ADD32(ctx->r7, 0X180);
            goto L_8067925C;
    }
    // 0x806791FC: addiu       $a3, $a3, 0x180
    ctx->r7 = ADD32(ctx->r7, 0X180);
    // 0x80679200: lh          $t0, 0x40($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X40);
    // 0x80679204: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(538, 0X1470) << 16);
    // 0x80679208: lwc1        $f8, -0x6C20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(538, 0X1470));
    // 0x8067920C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80679210: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80679214: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80679218: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8067921C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80679220: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80679224: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80679228: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8067922C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80679230: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80679234: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80679238: nop

    // 0x8067923C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80679240: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80679244: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80679248: nop

    // 0x8067924C: bc1f        L_8067925C
    if (!c1cs) {
        // 0x80679250: nop
    
            goto L_8067925C;
    }
    // 0x80679250: nop

    // 0x80679254: jal         0x8002F6E4
    // 0x80679258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x80679258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_8067925C:
    // 0x8067925C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80679260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80679264: jr          $ra
    // 0x80679268: nop

    return;
    // 0x80679268: nop

;}
RECOMP_FUNC void func_807B9C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9C48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B9C4C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x807B9C50: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x807B9C54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B9C58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B9C5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B9C60: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x807B9C64: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9C68: lw          $t9, 0xAC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XAC);
    // 0x807B9C6C: jalr        $t9
    // 0x807B9C70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807B9C70: nop

    after_0:
    // 0x807B9C74: bne         $v0, $zero, L_807B9C84
    if (ctx->r2 != 0) {
        // 0x807B9C78: sw          $v0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r2;
            goto L_807B9C84;
    }
    // 0x807B9C78: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x807B9C7C: b           L_807B9CF0
    // 0x807B9C80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B9CF0;
    // 0x807B9C80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B9C84:
    // 0x807B9C84: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(886, 0X1DCC) << 16);
    // 0x807B9C88: lwc1        $f4, -0x5FC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(886, 0X1DCC));
    // 0x807B9C8C: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
    // 0x807B9C90: swc1        $f4, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f4.u32l;
    // 0x807B9C94: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x807B9C98: jal         0x80047F9C
    // 0x807B9C9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x807B9C9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x807B9CA0: jal         0x807B8EE8
    // 0x807B9CA4: nop

    func_807B8EE8(rdram, ctx);
        goto after_2;
    // 0x807B9CA4: nop

    after_2:
    // 0x807B9CA8: bne         $v0, $zero, L_807B9CB8
    if (ctx->r2 != 0) {
        // 0x807B9CAC: sw          $v0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r2;
            goto L_807B9CB8;
    }
    // 0x807B9CAC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x807B9CB0: b           L_807B9CF0
    // 0x807B9CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B9CF0;
    // 0x807B9CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B9CB8:
    // 0x807B9CB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807B9CBC: jal         0x80047F9C
    // 0x807B9CC0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x807B9CC0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_3:
    // 0x807B9CC4: jal         0x80046E88
    // 0x807B9CC8: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80046E88(rdram, ctx);
        goto after_4;
    // 0x807B9CC8: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_4:
    // 0x807B9CCC: bne         $v0, $zero, L_807B9CDC
    if (ctx->r2 != 0) {
        // 0x807B9CD0: sw          $v0, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r2;
            goto L_807B9CDC;
    }
    // 0x807B9CD0: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x807B9CD4: b           L_807B9CF0
    // 0x807B9CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B9CF0;
    // 0x807B9CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B9CDC:
    // 0x807B9CDC: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x807B9CE0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x807B9CE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B9CE8: lw          $v1, 0x16C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X16C);
    // 0x807B9CEC: sb          $t2, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r10;
L_807B9CF0:
    // 0x807B9CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B9CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B9CF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B9CFC: jr          $ra
    // 0x807B9D00: nop

    return;
    // 0x807B9D00: nop

;}
RECOMP_FUNC void func_8076DB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DB18: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8076DB1C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8076DB20: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8076DB24: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8076DB28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8076DB2C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8076DB30: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076DB34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8076DB38: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8076DB3C: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x8076DB40: jal         0x8004700C
    // 0x8076DB44: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8076DB44: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_0:
    // 0x8076DB48: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8076DB4C: jal         0x8076D2B4
    // 0x8076DB50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8076D2B4(rdram, ctx);
        goto after_1;
    // 0x8076DB50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8076DB54: beq         $v0, $zero, L_8076DB88
    if (ctx->r2 == 0) {
        // 0x8076DB58: lui         $v0, 0x8077
        ctx->r2 = S32(RELOC_HI16(766, 0X34C8) << 16);
            goto L_8076DB88;
    }
    // 0x8076DB58: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X34C8) << 16);
    // 0x8076DB5C: addiu       $v0, $v0, -0x348
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X34C8));
    // 0x8076DB60: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8076DB64: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8076DB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076DB6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076DB70: sw          $t8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r24;
    // 0x8076DB74: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8076DB78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8076DB7C: sw          $t9, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r25;
    // 0x8076DB80: jal         0x8076DD8C
    // 0x8076DB84: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_2;
    // 0x8076DB84: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
L_8076DB88:
    // 0x8076DB88: lw          $t0, 0x14($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X14);
    // 0x8076DB8C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8076DB90: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8076DB94: bnel        $t0, $at, L_8076DC88
    if (ctx->r8 != ctx->r1) {
        // 0x8076DB98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8076DC88;
    }
    goto skip_0;
    // 0x8076DB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8076DB9C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8076DBA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8076DBA4: bnel        $t2, $at, L_8076DC88
    if (ctx->r10 != ctx->r1) {
        // 0x8076DBA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8076DC88;
    }
    goto skip_1;
    // 0x8076DBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8076DBAC: beql        $s2, $zero, L_8076DC88
    if (ctx->r18 == 0) {
        // 0x8076DBB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8076DC88;
    }
    goto skip_2;
    // 0x8076DBB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8076DBB4: lwc1        $f20, 0x50($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8076DBB8: jal         0x80066E88
    // 0x8076DBBC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8076DBBC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8076DBC0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8076DBC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8076DBC8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8076DBCC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8076DBD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8076DBD4: jal         0x80066DE4
    // 0x8076DBD8: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8076DBD8: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8076DBDC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8076DBE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8076DBE4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8076DBE8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8076DBEC: jal         0x80066E88
    // 0x8076DBF0: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x8076DBF0: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8076DBF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8076DBF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076DBFC: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8076DC00: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8076DC04: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8076DC08: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8076DC0C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8076DC10: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8076DC14: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8076DC18: jal         0x80066DE4
    // 0x8076DC1C: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8076DC1C: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8076DC20: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8076DC24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076DC28: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8076DC2C: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8076DC30: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8076DC34: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8076DC38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8076DC3C: swc1        $f18, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f18.u32l;
    // 0x8076DC40: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8076DC44: add.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8076DC48: swc1        $f2, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f2.u32l;
    // 0x8076DC4C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8076DC50: jal         0x8076CBC0
    // 0x8076DC54: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_8076CBC0(rdram, ctx);
        goto after_7;
    // 0x8076DC54: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x8076DC58: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8076DC5C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8076DC60: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x8076DC64: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8076DC68: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x8076DC6C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8076DC70: jal         0x80067BBC
    // 0x8076DC74: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_8;
    // 0x8076DC74: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_8:
    // 0x8076DC78: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x8076DC7C: jal         0x80067818
    // 0x8076DC80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x8076DC80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8076DC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8076DC88:
    // 0x8076DC88: jal         0x8076CD88
    // 0x8076DC8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8076CD88(rdram, ctx);
        goto after_10;
    // 0x8076DC8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x8076DC90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8076DC94: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8076DC98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8076DC9C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8076DCA0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8076DCA4: jr          $ra
    // 0x8076DCA8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8076DCA8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8043F814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F814: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043F818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F81C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F820: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8043F824: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8043F828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F82C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8043F830: jal         0x80442188
    // 0x8043F834: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F834: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043F838: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8043F83C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8043F840: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F844: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043F848: swc1        $f0, 0x1C88($v0)
    MEM_W(0X1C88, ctx->r2) = ctx->f0.u32l;
    // 0x8043F84C: jal         0x8043F310
    // 0x8043F850: swc1        $f0, 0x1C8C($v0)
    MEM_W(0X1C8C, ctx->r2) = ctx->f0.u32l;
    func_8043F310(rdram, ctx);
        goto after_1;
    // 0x8043F850: swc1        $f0, 0x1C8C($v0)
    MEM_W(0X1C8C, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x8043F854: jal         0x8043F1A0
    // 0x8043F858: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8043F1A0(rdram, ctx);
        goto after_2;
    // 0x8043F858: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8043F85C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043F864: jr          $ra
    // 0x8043F868: nop

    return;
    // 0x8043F868: nop

;}
RECOMP_FUNC void func_80737F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737F40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80737F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80737F48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80737F4C: jal         0x80045A34
    // 0x80737F50: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80737F50: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_0:
    // 0x80737F54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80737F58: bne         $v0, $zero, L_80737F68
    if (ctx->r2 != 0) {
        // 0x80737F5C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80737F68;
    }
    // 0x80737F5C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80737F60: b           L_80737F74
    // 0x80737F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80737F74;
    // 0x80737F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80737F68:
    // 0x80737F68: jal         0x80737EE8
    // 0x80737F6C: nop

    func_80737EE8(rdram, ctx);
        goto after_1;
    // 0x80737F6C: nop

    after_1:
    // 0x80737F70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80737F74:
    // 0x80737F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80737F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80737F7C: jr          $ra
    // 0x80737F80: nop

    return;
    // 0x80737F80: nop

;}
RECOMP_FUNC void func_807A1900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1900: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807A1904: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A1908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A190C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x807A1910: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x807A1914: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x807A1918: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x807A191C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A1920: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x807A1924: jal         0x8004700C
    // 0x807A1928: sh          $t6, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807A1928: sh          $t6, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r14;
    after_0:
    // 0x807A192C: lhu         $v1, 0x36($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X36);
    // 0x807A1930: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x807A1934: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x807A1938: beq         $v1, $at, L_807A1990
    if (ctx->r3 == ctx->r1) {
        // 0x807A193C: addiu       $at, $zero, 0x400C
        ctx->r1 = ADD32(0, 0X400C);
            goto L_807A1990;
    }
    // 0x807A193C: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x807A1940: bnel        $v1, $at, L_807A1A14
    if (ctx->r3 != ctx->r1) {
        // 0x807A1944: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807A1A14;
    }
    goto skip_0;
    // 0x807A1944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807A1948: beq         $v0, $zero, L_807A1A10
    if (ctx->r2 == 0) {
        // 0x807A194C: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_807A1A10;
    }
    // 0x807A194C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x807A1950: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x807A1954: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807A1958: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807A195C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807A1960: nop

    // 0x807A1964: bc1fl       L_807A1980
    if (!c1cs) {
        // 0x807A1968: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_807A1980;
    }
    goto skip_1;
    // 0x807A1968: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x807A196C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807A1970: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807A1974: b           L_807A1988
    // 0x807A1978: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
        goto L_807A1988;
    // 0x807A1978: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x807A197C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_807A1980:
    // 0x807A1980: nop

    // 0x807A1984: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
L_807A1988:
    // 0x807A1988: b           L_807A1A10
    // 0x807A198C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
        goto L_807A1A10;
    // 0x807A198C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_807A1990:
    // 0x807A1990: lbu         $t8, 0x18($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X18);
    // 0x807A1994: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x807A1998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A199C: bne         $t8, $at, L_807A1A10
    if (ctx->r24 != ctx->r1) {
        // 0x807A19A0: addiu       $a1, $zero, 0xC0
        ctx->r5 = ADD32(0, 0XC0);
            goto L_807A1A10;
    }
    // 0x807A19A0: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x807A19A4: jal         0x807A0F78
    // 0x807A19A8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    func_807A0F78(rdram, ctx);
        goto after_1;
    // 0x807A19A8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_1:
    // 0x807A19AC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x807A19B0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(841, 0XDB0) << 16);
    // 0x807A19B4: lwc1        $f18, 0x1CF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(841, 0XDB0));
    // 0x807A19B8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x807A19BC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A19C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807A19C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A19C8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x807A19CC: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x807A19D0: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
    // 0x807A19D4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x807A19D8: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x807A19DC: jalr        $t9
    // 0x807A19E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x807A19E0: nop

    after_2:
    // 0x807A19E4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x807A19E8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807A19EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807A19F0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x807A19F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807A19F8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807A19FC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x807A1A00: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x807A1A04: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807A1A08: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x807A1A0C: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
L_807A1A10:
    // 0x807A1A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A1A14:
    // 0x807A1A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A1A18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x807A1A1C: jr          $ra
    // 0x807A1A20: nop

    return;
    // 0x807A1A20: nop

;}
RECOMP_FUNC void func_80522A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522A74: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80522A78: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(321, 0X334) << 16);
    // 0x80522A7C: addiu       $t6, $t6, 0x25E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(321, 0X334));
    // 0x80522A80: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80522A84: jr          $ra
    // 0x80522A88: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80522A88: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8004D4C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D4C0: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D4C4: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8004D4C8: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8004D4CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D4D0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004D4D4: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D4D8: addu        $a2, $t7, $v1
    ctx->r6 = ADD32(ctx->r15, ctx->r3);
    // 0x8004D4DC: lbu         $t8, 0x14($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X14);
    // 0x8004D4E0: beq         $t8, $zero, L_8004D514
    if (ctx->r24 == 0) {
        // 0x8004D4E4: nop
    
            goto L_8004D514;
    }
    // 0x8004D4E4: nop

    // 0x8004D4E8: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8004D4EC: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8004D4F0: bne         $t0, $zero, L_8004D514
    if (ctx->r8 != 0) {
        // 0x8004D4F4: nop
    
            goto L_8004D514;
    }
    // 0x8004D4F4: nop

    // 0x8004D4F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D4FC: nop

    // 0x8004D500: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8004D504: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8004D508: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8004D50C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8004D510: sb          $zero, 0x14($t3)
    MEM_B(0X14, ctx->r11) = 0;
L_8004D514:
    // 0x8004D514: jr          $ra
    // 0x8004D518: nop

    return;
    // 0x8004D518: nop

;}
RECOMP_FUNC void func_804C04C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C04C0: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(197, 0X3A4) << 16);
    // 0x804C04C4: addiu       $v0, $v0, 0x864
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(197, 0X3A4));
    // 0x804C04C8: jr          $ra
    // 0x804C04CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804C04CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805A9210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A9210: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805A9214: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A9218: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(429, 0X1494) << 16);
    // 0x805A921C: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x805A9220: lwc1        $f6, -0x5E6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(429, 0X1494));
    // 0x805A9224: jr          $ra
    // 0x805A9228: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x805A9228: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_804734C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804734C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804734C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804734CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804734D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804734D4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804734D8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x804734DC: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x804734E0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804734E4: nop

    // 0x804734E8: bc1fl       L_80473514
    if (!c1cs) {
        // 0x804734EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80473514;
    }
    goto skip_0;
    // 0x804734EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804734F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x804734F4: jal         0x8004D1F0
    // 0x804734F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x804734F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804734FC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80473500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80473504: addiu       $a2, $a2, -0x2B90
    ctx->r6 = ADD32(ctx->r6, -0X2B90);
    // 0x80473508: jal         0x8004D698
    // 0x8047350C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x8047350C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80473510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80473514:
    // 0x80473514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80473518: jr          $ra
    // 0x8047351C: nop

    return;
    // 0x8047351C: nop

;}
RECOMP_FUNC void func_80682AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80682ADC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80682AE0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80682AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80682AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80682AEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80682AF0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80682AF4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80682AF8: jal         0x806829D0
    // 0x80682AFC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_806829D0(rdram, ctx);
        goto after_0;
    // 0x80682AFC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80682B00: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80682B04: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80682B08: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80682B0C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80682B10: jal         0x8068293C
    // 0x80682B14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8068293C(rdram, ctx);
        goto after_1;
    // 0x80682B14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80682B18: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80682B1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80682B20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80682B24: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80682B28: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80682B2C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80682B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80682B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80682B38: jr          $ra
    // 0x80682B3C: nop

    return;
    // 0x80682B3C: nop

;}
RECOMP_FUNC void func_807C36B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C36B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x807C36BC: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(907, 0X14B0) << 16);
    // 0x807C36C0: lwc1        $f0, 0x4810($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(907, 0X14B0));
    // 0x807C36C4: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x807C36C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807C36CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807C36D0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807C36D4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807C36D8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807C36DC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807C36E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807C36E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807C36E8: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x807C36EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C36F0: lui         $s2, 0x807C
    ctx->r18 = S32(RELOC_HI16(907, 0X13D0) << 16);
    // 0x807C36F4: lui         $s3, 0x807C
    ctx->r19 = S32(RELOC_HI16(907, 0X13D4) << 16);
    // 0x807C36F8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x807C36FC: addiu       $s2, $s2, 0x4730
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(907, 0X13D0));
    // 0x807C3700: addiu       $s3, $s3, 0x4734
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(907, 0X13D4));
    // 0x807C3704: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x807C3708: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x807C370C: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x807C3710: jal         0x807C35A8
    // 0x807C3714: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    func_807C35A8(rdram, ctx);
        goto after_0;
    // 0x807C3714: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x807C3718: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x807C371C: jal         0x807C3844
    // 0x807C3720: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_807C3844(rdram, ctx);
        goto after_1;
    // 0x807C3720: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x807C3724: beq         $v0, $zero, L_807C3818
    if (ctx->r2 == 0) {
        // 0x807C3728: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_807C3818;
    }
    // 0x807C3728: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x807C372C: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x807C3730: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x807C3734: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807C3738: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x807C373C: sw          $t6, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r14;
    // 0x807C3740: sb          $t7, 0x165($s4)
    MEM_B(0X165, ctx->r20) = ctx->r15;
    // 0x807C3744: sw          $zero, 0x1E0($s4)
    MEM_W(0X1E0, ctx->r20) = 0;
    // 0x807C3748: sw          $t8, 0x1E4($s4)
    MEM_W(0X1E4, ctx->r20) = ctx->r24;
    // 0x807C374C: sw          $zero, 0x138($s4)
    MEM_W(0X138, ctx->r20) = 0;
    // 0x807C3750: sh          $v0, 0x13C($s4)
    MEM_H(0X13C, ctx->r20) = ctx->r2;
    // 0x807C3754: sh          $v0, 0x13E($s4)
    MEM_H(0X13E, ctx->r20) = ctx->r2;
    // 0x807C3758: sw          $zero, 0x24($s4)
    MEM_W(0X24, ctx->r20) = 0;
    // 0x807C375C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807C3760: jal         0x800461F4
    // 0x807C3764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800461F4(rdram, ctx);
        goto after_2;
    // 0x807C3764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x807C3768: jal         0x807C388C
    // 0x807C376C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_807C388C(rdram, ctx);
        goto after_3;
    // 0x807C376C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x807C3770: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807C3774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C3778: jal         0x807C3EC0
    // 0x807C377C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807C3EC0(rdram, ctx);
        goto after_4;
    // 0x807C377C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x807C3780: lw          $s0, 0x1F4($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X1F4);
    // 0x807C3784: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807C3788: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x807C378C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
L_807C3790:
    // 0x807C3790: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807C3794: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x807C3798: jal         0x807C4180
    // 0x807C379C: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    func_807C4180(rdram, ctx);
        goto after_5;
    // 0x807C379C: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    after_5:
    // 0x807C37A0: bne         $v0, $zero, L_807C37B8
    if (ctx->r2 != 0) {
        // 0x807C37A4: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_807C37B8;
    }
    // 0x807C37A4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x807C37A8: jal         0x800445A4
    // 0x807C37AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x807C37AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x807C37B0: b           L_807C3824
    // 0x807C37B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_807C3824;
    // 0x807C37B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807C37B8:
    // 0x807C37B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x807C37BC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x807C37C0: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x807C37C4: bne         $s1, $s5, L_807C3790
    if (ctx->r17 != ctx->r21) {
        // 0x807C37C8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_807C3790;
    }
    // 0x807C37C8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x807C37CC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x807C37D0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x807C37D4: lui         $t3, 0x807C
    ctx->r11 = S32(RELOC_HI16(907, 0X13D8) << 16);
    // 0x807C37D8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x807C37DC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x807C37E0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x807C37E4: lw          $t0, 0x168($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X168);
    // 0x807C37E8: lw          $t3, 0x4738($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(907, 0X13D8));
    // 0x807C37EC: lw          $v0, 0x88($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X88);
    // 0x807C37F0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x807C37F4: jal         0x8004590C
    // 0x807C37F8: addu        $a1, $t4, $v0
    ctx->r5 = ADD32(ctx->r12, ctx->r2);
    func_8004590C(rdram, ctx);
        goto after_7;
    // 0x807C37F8: addu        $a1, $t4, $v0
    ctx->r5 = ADD32(ctx->r12, ctx->r2);
    after_7:
    // 0x807C37FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807C3800: jal         0x807C38CC
    // 0x807C3804: addiu       $a1, $s4, 0x6C
    ctx->r5 = ADD32(ctx->r20, 0X6C);
    func_807C38CC(rdram, ctx);
        goto after_8;
    // 0x807C3804: addiu       $a1, $s4, 0x6C
    ctx->r5 = ADD32(ctx->r20, 0X6C);
    after_8:
    // 0x807C3808: jal         0x807C33B4
    // 0x807C380C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_807C33B4(rdram, ctx);
        goto after_9;
    // 0x807C380C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
    // 0x807C3810: b           L_807C3824
    // 0x807C3814: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_807C3824;
    // 0x807C3814: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807C3818:
    // 0x807C3818: jal         0x800445A4
    // 0x807C381C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_10;
    // 0x807C381C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_10:
    // 0x807C3820: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807C3824:
    // 0x807C3824: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807C3828: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807C382C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807C3830: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807C3834: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807C3838: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807C383C: jr          $ra
    // 0x807C3840: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x807C3840: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80471D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80471D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80471D88: jal         0x80045A34
    // 0x80471D8C: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80471D8C: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_0:
    // 0x80471D90: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80471D94: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80471D98: bne         $v0, $zero, L_80471DA8
    if (ctx->r2 != 0) {
        // 0x80471D9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80471DA8;
    }
    // 0x80471D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80471DA0: b           L_80471DAC
    // 0x80471DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80471DAC;
    // 0x80471DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80471DA8:
    // 0x80471DA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80471DAC:
    // 0x80471DAC: jr          $ra
    // 0x80471DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80471DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8057DF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DF98: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8057DF9C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8057DFA0: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8057DFA4: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8057DFA8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8057DFAC: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8057DFB0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8057DFB4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8057DFB8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8057DFBC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8057DFC0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8057DFC4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8057DFC8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8057DFCC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8057DFD0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8057DFD4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8057DFD8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8057DFDC: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8057DFE0: lw          $v1, 0x2B4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2B4);
    // 0x8057DFE4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057DFE8: lui         $s5, 0x8058
    ctx->r21 = S32(RELOC_HI16(393, 0XFF0) << 16);
    // 0x8057DFEC: addiu       $a3, $a0, 0x1E0
    ctx->r7 = ADD32(ctx->r4, 0X1E0);
    // 0x8057DFF0: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8057DFF4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057DFF8: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8057DFFC: addiu       $s5, $s5, -0x14D0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(393, 0XFF0));
    // 0x8057E000: addiu       $s2, $a0, 0x210
    ctx->r18 = ADD32(ctx->r4, 0X210);
    // 0x8057E004: addiu       $s3, $a0, 0x220
    ctx->r19 = ADD32(ctx->r4, 0X220);
    // 0x8057E008: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8057E00C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8057E010: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8057E014:
    // 0x8057E014: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057E018: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x8057E01C: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8057E020: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8057E024: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8057E028: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x8057E02C: bne         $at, $zero, L_8057E03C
    if (ctx->r1 != 0) {
        // 0x8057E030: swc1        $f6, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
            goto L_8057E03C;
    }
    // 0x8057E030: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8057E034: addiu       $v1, $v1, -0x3C
    ctx->r3 = ADD32(ctx->r3, -0X3C);
    // 0x8057E038: addiu       $v0, $v0, -0x1E0
    ctx->r2 = ADD32(ctx->r2, -0X1E0);
L_8057E03C:
    // 0x8057E03C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8057E040: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x8057E044: bne         $at, $zero, L_8057E014
    if (ctx->r1 != 0) {
        // 0x8057E048: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8057E014;
    }
    // 0x8057E048: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8057E04C: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8057E050: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8057E054: addiu       $fp, $a1, -0x1
    ctx->r30 = ADD32(ctx->r5, -0X1);
    // 0x8057E058: sll         $fp, $fp, 6
    ctx->r30 = S32(ctx->r30 << 6);
    // 0x8057E05C: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8057E060: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8057E064: addiu       $s4, $a0, 0x1E8
    ctx->r20 = ADD32(ctx->r4, 0X1E8);
    // 0x8057E068: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8057E06C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8057E070: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    // 0x8057E074: cvt.s.w     $f30, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    ctx->f30.fl = CVT_S_W(ctx->f8.u32l);
L_8057E078:
    // 0x8057E078: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8057E07C: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8057E080: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8057E084: lwc1        $f6, 0x4($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8057E088: sub.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8057E08C: lwc1        $f10, 0x0($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8057E090: lwc1        $f18, 0x4($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X4);
    // 0x8057E094: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8057E098: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8057E09C: sub.s       $f20, $f2, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8057E0A0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8057E0A4: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8057E0A8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8057E0AC: jal         0x80067114
    // 0x8057E0B0: sqrt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = sqrtf(ctx->f0.fl);
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x8057E0B0: sqrt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x8057E0B4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x8057E0B8: jal         0x80066DE4
    // 0x8057E0BC: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8057E0BC: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    after_1:
    // 0x8057E0C0: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x8057E0C4: jal         0x80066E88
    // 0x8057E0C8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8057E0C8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_2:
    // 0x8057E0CC: mul.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8057E0D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8057E0D4: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x8057E0D8: mul.s       $f14, $f30, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = MUL_S(ctx->f30.fl, ctx->f26.fl);
    // 0x8057E0DC: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x8057E0E0: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x8057E0E4: mul.s       $f16, $f30, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x8057E0E8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8057E0EC: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8057E0F0: mul.s       $f12, $f24, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x8057E0F4: sub.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8057E0F8: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8057E0FC: add.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8057E100: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8057E104: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x8057E108: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8057E10C: add.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8057E110: sh          $t9, -0x20($s2)
    MEM_H(-0X20, ctx->r18) = ctx->r25;
    // 0x8057E114: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8057E118: sub.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x8057E11C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8057E120: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8057E124: sh          $t1, -0x1E($s2)
    MEM_H(-0X1E, ctx->r18) = ctx->r9;
    // 0x8057E128: sub.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x8057E12C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8057E130: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8057E134: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8057E138: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8057E13C: sh          $t3, -0x20($s3)
    MEM_H(-0X20, ctx->r19) = ctx->r11;
    // 0x8057E140: sh          $t5, -0x1E($s3)
    MEM_H(-0X1E, ctx->r19) = ctx->r13;
    // 0x8057E144: lh          $v0, -0x2($s5)
    ctx->r2 = MEM_H(ctx->r21, -0X2);
    // 0x8057E148: sh          $v0, -0x18($s3)
    MEM_H(-0X18, ctx->r19) = ctx->r2;
    // 0x8057E14C: sh          $fp, -0x16($s2)
    MEM_H(-0X16, ctx->r18) = ctx->r30;
    // 0x8057E150: sh          $v0, -0x18($s2)
    MEM_H(-0X18, ctx->r18) = ctx->r2;
    // 0x8057E154: bne         $s1, $s7, L_8057E078
    if (ctx->r17 != ctx->r23) {
        // 0x8057E158: sh          $zero, -0x16($s3)
        MEM_H(-0X16, ctx->r19) = 0;
            goto L_8057E078;
    }
    // 0x8057E158: sh          $zero, -0x16($s3)
    MEM_H(-0X16, ctx->r19) = 0;
    // 0x8057E15C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8057E160: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8057E164: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8057E168: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8057E16C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8057E170: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8057E174: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8057E178: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8057E17C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8057E180: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8057E184: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8057E188: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8057E18C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8057E190: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8057E194: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8057E198: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8057E19C: jr          $ra
    // 0x8057E1A0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8057E1A0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8040B820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040B824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B828: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8040B82C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040B830: jal         0x8040AE28
    // 0x8040B834: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_8040AE28(rdram, ctx);
        goto after_0;
    // 0x8040B834: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8040B838: jal         0x8040B6F0
    // 0x8040B83C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8040B6F0(rdram, ctx);
        goto after_1;
    // 0x8040B83C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8040B840: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8040B844: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8040B848: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8040B84C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8040B850: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040B854: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8040B858: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(14, 0XBD4) << 16);
    // 0x8040B85C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8040B860: nop

    // 0x8040B864: bc1fl       L_8040B878
    if (!c1cs) {
        // 0x8040B868: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8040B878;
    }
    goto skip_0;
    // 0x8040B868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8040B86C: b           L_8040B890
    // 0x8040B870: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
        goto L_8040B890;
    // 0x8040B870: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8040B874: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8040B878:
    // 0x8040B878: nop

    // 0x8040B87C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8040B880: nop

    // 0x8040B884: bc1fl       L_8040B894
    if (!c1cs) {
        // 0x8040B888: lw          $t6, 0x1F4($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X1F4);
            goto L_8040B894;
    }
    goto skip_1;
    // 0x8040B888: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    skip_1:
    // 0x8040B88C: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
L_8040B890:
    // 0x8040B890: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
L_8040B894:
    // 0x8040B894: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
    // 0x8040B898: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(14, 0X1378) << 16);
    // 0x8040B89C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8040B8A0: beql        $t7, $zero, L_8040B8BC
    if (ctx->r15 == 0) {
        // 0x8040B8A4: lw          $t9, 0x12C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X12C);
            goto L_8040B8BC;
    }
    goto skip_2;
    // 0x8040B8A4: lw          $t9, 0x12C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X12C);
    skip_2:
    // 0x8040B8A8: lwc1        $f6, -0x4128($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(14, 0X1378));
    // 0x8040B8AC: addiu       $t8, $t8, -0x48CC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(14, 0XBD4));
    // 0x8040B8B0: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8040B8B4: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
    // 0x8040B8B8: lw          $t9, 0x12C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X12C);
L_8040B8BC:
    // 0x8040B8BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8040B8C0: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(14, 0X1338) << 16);
    // 0x8040B8C4: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8040B8C8: lw          $t9, -0x4168($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(14, 0X1338));
    // 0x8040B8CC: jalr        $t9
    // 0x8040B8D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8040B8D0: nop

    after_2:
    // 0x8040B8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040B8D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040B8DC: jr          $ra
    // 0x8040B8E0: nop

    return;
    // 0x8040B8E0: nop

;}
RECOMP_FUNC void func_804505B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804505B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804505B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804505B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804505BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804505C0: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804505C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804505C8: lw          $v0, 0xA5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA5C);
    // 0x804505CC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x804505D0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x804505D4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x804505D8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x804505DC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x804505E0: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x804505E4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x804505E8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x804505EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804505F0: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x804505F4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x804505F8: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x804505FC: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x80450600: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80450604: jal         0x80446D70
    // 0x80450608: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x80450608: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_0:
    // 0x8045060C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80450610: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80450614: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80450618: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045061C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80450620: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80450624: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80450628: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045062C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80450630: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x80450634: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x80450638: jal         0x8044ED68
    // 0x8045063C: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_1;
    // 0x8045063C: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_1:
    // 0x80450640: jal         0x80450568
    // 0x80450644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80450568(rdram, ctx);
        goto after_2;
    // 0x80450644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80450648: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8045064C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450650: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x80450654: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80450658: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    // 0x8045065C: lwc1        $f4, 0x6C84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x80450660: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80450664: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450668: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8045066C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80450670: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80450674: swc1        $f8, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f8.u32l;
    // 0x80450678: lwc1        $f12, 0x6C84($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X6C84);
    // 0x8045067C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80450680: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x80450684: nop

    // 0x80450688: bc1fl       L_804506B4
    if (!c1cs) {
        // 0x8045068C: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_804506B4;
    }
    goto skip_0;
    // 0x8045068C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_0:
    // 0x80450690: jal         0x80445730
    // 0x80450694: nop

    func_80445730(rdram, ctx);
        goto after_3;
    // 0x80450694: nop

    after_3:
    // 0x80450698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8045069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804506A0: jal         0x80457164
    // 0x804506A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80457164(rdram, ctx);
        goto after_4;
    // 0x804506A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x804506A8: b           L_804506C0
    // 0x804506AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804506C0;
    // 0x804506AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804506B0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_804506B4:
    // 0x804506B4: jal         0x80450490
    // 0x804506B8: nop

    func_80450490(rdram, ctx);
        goto after_5;
    // 0x804506B8: nop

    after_5:
    // 0x804506BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804506C0:
    // 0x804506C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804506C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804506C8: jr          $ra
    // 0x804506CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x804506CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807B5598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B5598: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x807B559C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B55A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B55A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B55A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B55AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B55B0: lw          $s3, 0x10($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X10);
    // 0x807B55B4: jal         0x807B4D10
    // 0x807B55B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_807B4D10(rdram, ctx);
        goto after_0;
    // 0x807B55B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x807B55BC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807B55C0: lw          $t6, -0x7250($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7250);
    // 0x807B55C4: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x807B55C8: bne         $at, $zero, L_807B55E0
    if (ctx->r1 != 0) {
        // 0x807B55CC: nop
    
            goto L_807B55E0;
    }
    // 0x807B55CC: nop

    // 0x807B55D0: jal         0x807B4D88
    // 0x807B55D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_807B4D88(rdram, ctx);
        goto after_1;
    // 0x807B55D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x807B55D8: b           L_807B55E8
    // 0x807B55DC: nop

        goto L_807B55E8;
    // 0x807B55DC: nop

L_807B55E0:
    // 0x807B55E0: jal         0x807B4D4C
    // 0x807B55E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_807B4D4C(rdram, ctx);
        goto after_2;
    // 0x807B55E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
L_807B55E8:
    // 0x807B55E8: jal         0x807B4DC4
    // 0x807B55EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_807B4DC4(rdram, ctx);
        goto after_3;
    // 0x807B55EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x807B55F0: jal         0x807B4A74
    // 0x807B55F4: nop

    func_807B4A74(rdram, ctx);
        goto after_4;
    // 0x807B55F4: nop

    after_4:
    // 0x807B55F8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x807B55FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807B5600: jal         0x807B4B3C
    // 0x807B5604: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807B4B3C(rdram, ctx);
        goto after_5;
    // 0x807B5604: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x807B5608: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x807B560C: addiu       $s0, $zero, 0x58
    ctx->r16 = ADD32(0, 0X58);
    // 0x807B5610: addiu       $s2, $zero, 0x78
    ctx->r18 = ADD32(0, 0X78);
L_807B5614:
    // 0x807B5614: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5618: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x807B561C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5620: jal         0x8005C27C
    // 0x807B5624: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x807B5624: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_6:
    // 0x807B5628: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B562C: bne         $s0, $s2, L_807B5614
    if (ctx->r16 != ctx->r18) {
        // 0x807B5630: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_807B5614;
    }
    // 0x807B5630: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807B5634: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B563C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B5640: jal         0x8005C27C
    // 0x807B5644: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_7;
    // 0x807B5644: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_7:
    // 0x807B5648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B564C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B5650: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B5654: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B5658: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B565C: jr          $ra
    // 0x807B5660: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x807B5660: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8003E5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003E5F0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8003E5F4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8003E5F8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8003E5FC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003E600: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8003E604: addiu       $t7, $zero, 0x23
    ctx->r15 = ADD32(0, 0X23);
    // 0x8003E608: sb          $zero, 0x1202($v0)
    MEM_B(0X1202, ctx->r2) = 0;
    // 0x8003E60C: sh          $t7, 0x1210($v0)
    MEM_H(0X1210, ctx->r2) = ctx->r15;
    // 0x8003E610: jr          $ra
    // 0x8003E614: sw          $a2, 0x11FC($v0)
    MEM_W(0X11FC, ctx->r2) = ctx->r6;
    return;
    // 0x8003E614: sw          $a2, 0x11FC($v0)
    MEM_W(0X11FC, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_800248FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800248FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80024900: jr          $ra
    // 0x80024904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80024904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80453CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453CFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80453D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453D04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80453D08: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453D0C: jal         0x80445760
    // 0x80453D10: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80445760(rdram, ctx);
        goto after_0;
    // 0x80453D10: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80453D14: lui         $at, 0x421C
    ctx->r1 = S32(0X421C << 16);
    // 0x80453D18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80453D1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80453D20: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453D24: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80453D28: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    // 0x80453D2C: jal         0x80453C6C
    // 0x80453D30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80453C6C(rdram, ctx);
        goto after_1;
    // 0x80453D30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80453D34: jal         0x80445B9C
    // 0x80453D38: nop

    func_80445B9C(rdram, ctx);
        goto after_2;
    // 0x80453D38: nop

    after_2:
    // 0x80453D3C: jal         0x80445D30
    // 0x80453D40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80445D30(rdram, ctx);
        goto after_3;
    // 0x80453D40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80453D44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80453D48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80453D4C: jal         0x80457164
    // 0x80453D50: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_80457164(rdram, ctx);
        goto after_4;
    // 0x80453D50: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_4:
    // 0x80453D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453D58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80453D5C: jr          $ra
    // 0x80453D60: nop

    return;
    // 0x80453D60: nop

;}
RECOMP_FUNC void func_80666438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80666438: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8066643C: lui         $t6, 0x8066
    ctx->r14 = S32(RELOC_HI16(504, 0X2D40) << 16);
    // 0x80666440: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80666444: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80666448: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8066644C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80666450: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80666454: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80666458: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8066645C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80666460: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80666464: addiu       $t6, $t6, 0x7A10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(504, 0X2D40));
    // 0x80666468: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8066646C: addiu       $s6, $sp, 0x54
    ctx->r22 = ADD32(ctx->r29, 0X54);
    // 0x80666470: lui         $t9, 0x8066
    ctx->r25 = S32(RELOC_HI16(504, 0X2D4C) << 16);
    // 0x80666474: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x80666478: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8066647C: addiu       $t9, $t9, 0x7A1C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(504, 0X2D4C));
    // 0x80666480: addiu       $s7, $sp, 0x48
    ctx->r23 = ADD32(ctx->r29, 0X48);
    // 0x80666484: sw          $t7, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r15;
    // 0x80666488: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8066648C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80666490: sw          $t8, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r24;
    // 0x80666494: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80666498: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
    // 0x8066649C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x806664A0: sw          $t0, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r8;
    // 0x806664A4: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x806664A8: jal         0x806665CC
    // 0x806664AC: sw          $t1, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r9;
    func_806665CC(rdram, ctx);
        goto after_0;
    // 0x806664AC: sw          $t1, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r9;
    after_0:
    // 0x806664B0: beq         $v0, $zero, L_80666590
    if (ctx->r2 == 0) {
        // 0x806664B4: nop
    
            goto L_80666590;
    }
    // 0x806664B4: nop

    // 0x806664B8: jal         0x80666604
    // 0x806664BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80666604(rdram, ctx);
        goto after_1;
    // 0x806664BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x806664C0: lw          $t3, 0x16C($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X16C);
    // 0x806664C4: lui         $t2, 0x8066
    ctx->r10 = S32(RELOC_HI16(504, 0X2758) << 16);
    // 0x806664C8: sw          $zero, 0x130($s5)
    MEM_W(0X130, ctx->r21) = 0;
    // 0x806664CC: sb          $zero, 0x165($s5)
    MEM_B(0X165, ctx->r21) = 0;
    // 0x806664D0: addiu       $t2, $t2, 0x7428
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(504, 0X2758));
    // 0x806664D4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x806664D8: sw          $zero, 0x1E0($s5)
    MEM_W(0X1E0, ctx->r21) = 0;
    // 0x806664DC: lw          $a3, 0x138($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X138);
    // 0x806664E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x806664E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806664E8: jal         0x8066706C
    // 0x806664EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8066706C(rdram, ctx);
        goto after_2;
    // 0x806664EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x806664F0: lw          $t5, 0x16C($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X16C);
    // 0x806664F4: lui         $t4, 0x8066
    ctx->r12 = S32(RELOC_HI16(504, 0X197C) << 16);
    // 0x806664F8: addiu       $t4, $t4, 0x664C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(504, 0X197C));
    // 0x806664FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80666500: jal         0x80666418
    // 0x80666504: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    func_80666418(rdram, ctx);
        goto after_3;
    // 0x80666504: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    after_3:
    // 0x80666508: lw          $s2, 0x1F4($s5)
    ctx->r18 = MEM_W(ctx->r21, 0X1F4);
    // 0x8066650C: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x80666510: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x80666514: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80666518: addiu       $s4, $zero, 0x30
    ctx->r20 = ADD32(0, 0X30);
    // 0x8066651C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80666520:
    // 0x80666520: lw          $t6, 0xA68($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XA68);
    // 0x80666524: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80666528: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8066652C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80666530: lw          $t9, 0x5C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X5C);
    // 0x80666534: jalr        $t9
    // 0x80666538: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80666538: nop

    after_4:
    // 0x8066653C: beq         $v0, $zero, L_80666564
    if (ctx->r2 == 0) {
        // 0x80666540: sw          $v0, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->r2;
            goto L_80666564;
    }
    // 0x80666540: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x80666544: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80666548: jal         0x80047F9C
    // 0x8066654C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8066654C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80666550: lw          $t8, 0x84($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X84);
    // 0x80666554: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80666558: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8066655C: b           L_80666574
    // 0x80666560: sw          $t0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r8;
        goto L_80666574;
    // 0x80666560: sw          $t0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r8;
L_80666564:
    // 0x80666564: jal         0x800445A4
    // 0x80666568: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80666568: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x8066656C: b           L_806665A0
    // 0x80666570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806665A0;
    // 0x80666570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80666574:
    // 0x80666574: bne         $s1, $s4, L_80666520
    if (ctx->r17 != ctx->r20) {
        // 0x80666578: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80666520;
    }
    // 0x80666578: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8066657C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80666580: jal         0x80666CF8
    // 0x80666584: addiu       $a1, $s5, 0x6C
    ctx->r5 = ADD32(ctx->r21, 0X6C);
    func_80666CF8(rdram, ctx);
        goto after_7;
    // 0x80666584: addiu       $a1, $s5, 0x6C
    ctx->r5 = ADD32(ctx->r21, 0X6C);
    after_7:
    // 0x80666588: b           L_806665A0
    // 0x8066658C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806665A0;
    // 0x8066658C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80666590:
    // 0x80666590: jal         0x800445A4
    // 0x80666594: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x80666594: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x80666598: b           L_806665A0
    // 0x8066659C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806665A0;
    // 0x8066659C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806665A0:
    // 0x806665A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x806665A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806665A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806665AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x806665B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x806665B4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x806665B8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x806665BC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x806665C0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x806665C4: jr          $ra
    // 0x806665C8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x806665C8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8040165C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040165C: lui         $t6, 0x8040
    ctx->r14 = S32(RELOC_HI16(8, 0X7604) << 16);
    // 0x80401660: addiu       $t6, $t6, 0x7644
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(8, 0X7604));
    // 0x80401664: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80401668: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040166C: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    // 0x80401670: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80401674: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80401678: lui         $t9, 0x8040
    ctx->r25 = S32(RELOC_HI16(8, 0X7624) << 16);
    // 0x8040167C: addiu       $t9, $t9, 0x7664
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(8, 0X7624));
    // 0x80401680: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80401684: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80401688: addiu       $a3, $sp, 0x8
    ctx->r7 = ADD32(ctx->r29, 0X8);
    // 0x8040168C: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x80401690: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80401694: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80401698: addiu       $v1, $sp, 0xE
    ctx->r3 = ADD32(ctx->r29, 0XE);
    // 0x8040169C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x804016A0: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x804016A4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x804016A8: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x804016AC: sw          $t8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r24;
    // 0x804016B0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x804016B4: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
    // 0x804016B8: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x804016BC: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x804016C0: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x804016C4: sw          $t7, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r15;
    // 0x804016C8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x804016CC: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x804016D0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x804016D4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x804016D8: lh          $t2, 0x14($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X14);
    // 0x804016DC: sh          $t2, -0x18($a0)
    MEM_H(-0X18, ctx->r4) = ctx->r10;
    // 0x804016E0: lh          $t3, 0x16($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X16);
    // 0x804016E4: sh          $t3, -0x16($a0)
    MEM_H(-0X16, ctx->r4) = ctx->r11;
    // 0x804016E8: lh          $t4, 0x18($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X18);
    // 0x804016EC: sh          $t4, -0x14($a0)
    MEM_H(-0X14, ctx->r4) = ctx->r12;
    // 0x804016F0: lh          $t5, 0x1A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1A);
    // 0x804016F4: sh          $t5, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = ctx->r13;
    // 0x804016F8: lhu         $t6, 0x8($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X8);
    // 0x804016FC: sh          $t6, -0x6($a1)
    MEM_H(-0X6, ctx->r5) = ctx->r14;
    // 0x80401700: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x80401704: sh          $t7, -0x10($a0)
    MEM_H(-0X10, ctx->r4) = ctx->r15;
    // 0x80401708: lh          $t8, 0x1E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X1E);
    // 0x8040170C: sh          $t8, -0xE($a0)
    MEM_H(-0XE, ctx->r4) = ctx->r24;
    // 0x80401710: lh          $t9, 0x20($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X20);
    // 0x80401714: sh          $t9, -0xC($a0)
    MEM_H(-0XC, ctx->r4) = ctx->r25;
    // 0x80401718: lh          $t0, 0x22($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X22);
    // 0x8040171C: sh          $t0, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r8;
    // 0x80401720: lhu         $t1, 0xA($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0XA);
    // 0x80401724: sh          $t1, -0x4($a1)
    MEM_H(-0X4, ctx->r5) = ctx->r9;
    // 0x80401728: lh          $t2, 0x24($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X24);
    // 0x8040172C: sh          $t2, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = ctx->r10;
    // 0x80401730: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80401734: sh          $t3, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r11;
    // 0x80401738: lh          $t4, 0x28($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X28);
    // 0x8040173C: sh          $t4, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r12;
    // 0x80401740: lh          $t5, 0x2A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2A);
    // 0x80401744: sh          $t5, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r13;
    // 0x80401748: lhu         $t6, 0xC($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XC);
    // 0x8040174C: sh          $t6, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r14;
    // 0x80401750: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80401754: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80401758: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8040175C: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x80401760: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80401764: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x80401768: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x8040176C: sh          $t0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r8;
    // 0x80401770: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x80401774: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80401778: jr          $ra
    // 0x8040177C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    return;
    // 0x8040177C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void func_806AEC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEC38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806AEC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AEC40: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AEC44: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x806AEC48: lw          $t6, 0x7F78($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7F78);
    // 0x806AEC4C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x806AEC50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806AEC54: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x806AEC58: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x806AEC5C: jalr        $t9
    // 0x806AEC60: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806AEC60: nop

    after_0:
    // 0x806AEC64: jal         0x806AE458
    // 0x806AEC68: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_806AE458(rdram, ctx);
        goto after_1;
    // 0x806AEC68: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x806AEC6C: beq         $v0, $zero, L_806AECB0
    if (ctx->r2 == 0) {
        // 0x806AEC70: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_806AECB0;
    }
    // 0x806AEC70: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806AEC74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AEC78: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806AEC7C: jal         0x806AF64C
    // 0x806AEC80: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806AF64C(rdram, ctx);
        goto after_2;
    // 0x806AEC80: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x806AEC84: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806AEC88: lw          $v1, 0x28($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X28);
    // 0x806AEC8C: beql        $v1, $zero, L_806AED24
    if (ctx->r3 == 0) {
        // 0x806AEC90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806AED24;
    }
    goto skip_0;
    // 0x806AEC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806AEC94: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x806AEC98: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x806AEC9C: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x806AECA0: sb          $a0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r4;
    // 0x806AECA4: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x806AECA8: b           L_806AED20
    // 0x806AECAC: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
        goto L_806AED20;
    // 0x806AECAC: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_806AECB0:
    // 0x806AECB0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806AECB4: lw          $v1, 0x28($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X28);
    // 0x806AECB8: beql        $v1, $zero, L_806AED24
    if (ctx->r3 == 0) {
        // 0x806AECBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806AED24;
    }
    goto skip_1;
    // 0x806AECBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806AECC0: lw          $t0, 0x1E0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1E0);
    // 0x806AECC4: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x806AECC8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x806AECCC: slti        $at, $t0, 0x33
    ctx->r1 = SIGNED(ctx->r8) < 0X33 ? 1 : 0;
    // 0x806AECD0: bne         $at, $zero, L_806AECEC
    if (ctx->r1 != 0) {
        // 0x806AECD4: addiu       $v0, $v0, 0xD
        ctx->r2 = ADD32(ctx->r2, 0XD);
            goto L_806AECEC;
    }
    // 0x806AECD4: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x806AECD8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x806AECDC: sb          $a0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r4;
    // 0x806AECE0: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x806AECE4: b           L_806AED20
    // 0x806AECE8: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
        goto L_806AED20;
    // 0x806AECE8: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_806AECEC:
    // 0x806AECEC: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x806AECF0: beq         $t2, $zero, L_806AED10
    if (ctx->r10 == 0) {
        // 0x806AECF4: addiu       $v1, $zero, 0x80
        ctx->r3 = ADD32(0, 0X80);
            goto L_806AED10;
    }
    // 0x806AECF4: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x806AECF8: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x806AECFC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x806AED00: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x806AED04: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x806AED08: b           L_806AED20
    // 0x806AED0C: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
        goto L_806AED20;
    // 0x806AED0C: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
L_806AED10:
    // 0x806AED10: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x806AED14: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x806AED18: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x806AED1C: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
L_806AED20:
    // 0x806AED20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806AED24:
    // 0x806AED24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806AED28: jr          $ra
    // 0x806AED2C: nop

    return;
    // 0x806AED2C: nop

;}
RECOMP_FUNC void func_80699A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699A78: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80699A7C: jal         0x80048F84
    // 0x80699A80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80699A80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80699A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699A8C: jr          $ra
    // 0x80699A90: nop

    return;
    // 0x80699A90: nop

;}
RECOMP_FUNC void func_8042C750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C750: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042C754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042C758: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042C75C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042C760: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042C764: jal         0x8004700C
    // 0x8042C768: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8042C768: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8042C76C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8042C770: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8042C774: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x8042C778: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C77C: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042C780: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8042C784: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x8042C788: jal         0x8042A9DC
    // 0x8042C78C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_8042A9DC(rdram, ctx);
        goto after_1;
    // 0x8042C78C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8042C790: jal         0x8042BB3C
    // 0x8042C794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BB3C(rdram, ctx);
        goto after_2;
    // 0x8042C794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8042C798: jal         0x8042BA84
    // 0x8042C79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BA84(rdram, ctx);
        goto after_3;
    // 0x8042C79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042C7A0: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C7A4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8042C7A8: bnel        $v1, $at, L_8042C7C0
    if (ctx->r3 != ctx->r1) {
        // 0x8042C7AC: slti        $at, $v1, 0x1E3
        ctx->r1 = SIGNED(ctx->r3) < 0X1E3 ? 1 : 0;
            goto L_8042C7C0;
    }
    goto skip_0;
    // 0x8042C7AC: slti        $at, $v1, 0x1E3
    ctx->r1 = SIGNED(ctx->r3) < 0X1E3 ? 1 : 0;
    skip_0:
    // 0x8042C7B0: jal         0x800677F8
    // 0x8042C7B4: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x8042C7B4: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_4:
    // 0x8042C7B8: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C7BC: slti        $at, $v1, 0x1E3
    ctx->r1 = SIGNED(ctx->r3) < 0X1E3 ? 1 : 0;
L_8042C7C0:
    // 0x8042C7C0: beq         $at, $zero, L_8042C7DC
    if (ctx->r1 == 0) {
        // 0x8042C7C4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8042C7DC;
    }
    // 0x8042C7C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042C7C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042C7CC: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8042C7D0: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C7D4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8042C7D8: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
L_8042C7DC:
    // 0x8042C7DC: addiu       $at, $zero, 0x238
    ctx->r1 = ADD32(0, 0X238);
    // 0x8042C7E0: bnel        $v1, $at, L_8042C814
    if (ctx->r3 != ctx->r1) {
        // 0x8042C7E4: addiu       $at, $zero, 0x23C
        ctx->r1 = ADD32(0, 0X23C);
            goto L_8042C814;
    }
    goto skip_1;
    // 0x8042C7E4: addiu       $at, $zero, 0x23C
    ctx->r1 = ADD32(0, 0X23C);
    skip_1:
    // 0x8042C7E8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8042C7EC: jal         0x80067BBC
    // 0x8042C7F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8042C7F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8042C7F4: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x8042C7F8: jal         0x80067F78
    // 0x8042C7FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_6;
    // 0x8042C7FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8042C800: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8042C804: jal         0x800492C0
    // 0x8042C808: addiu       $a0, $zero, -0x65
    ctx->r4 = ADD32(0, -0X65);
    func_800492C0(rdram, ctx);
        goto after_7;
    // 0x8042C808: addiu       $a0, $zero, -0x65
    ctx->r4 = ADD32(0, -0X65);
    after_7:
    // 0x8042C80C: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C810: addiu       $at, $zero, 0x23C
    ctx->r1 = ADD32(0, 0X23C);
L_8042C814:
    // 0x8042C814: bne         $v1, $at, L_8042C84C
    if (ctx->r3 != ctx->r1) {
        // 0x8042C818: addiu       $a0, $zero, 0x68
        ctx->r4 = ADD32(0, 0X68);
            goto L_8042C84C;
    }
    // 0x8042C818: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x8042C81C: jal         0x80067930
    // 0x8042C820: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    func_80067930(rdram, ctx);
        goto after_8;
    // 0x8042C820: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    after_8:
    // 0x8042C824: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042C828: bne         $v0, $at, L_8042C840
    if (ctx->r2 != ctx->r1) {
        // 0x8042C82C: addiu       $a0, $zero, 0x68
        ctx->r4 = ADD32(0, 0X68);
            goto L_8042C840;
    }
    // 0x8042C82C: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x8042C830: jal         0x80067878
    // 0x8042C834: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_9;
    // 0x8042C834: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    after_9:
    // 0x8042C838: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8042C83C: sh          $t0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r8;
L_8042C840:
    // 0x8042C840: jal         0x800677F8
    // 0x8042C844: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800677F8(rdram, ctx);
        goto after_10;
    // 0x8042C844: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_10:
    // 0x8042C848: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
L_8042C84C:
    // 0x8042C84C: slti        $at, $v1, 0x27D
    ctx->r1 = SIGNED(ctx->r3) < 0X27D ? 1 : 0;
    // 0x8042C850: bne         $at, $zero, L_8042C8DC
    if (ctx->r1 != 0) {
        // 0x8042C854: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8042C8DC;
    }
    // 0x8042C854: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8042C858: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8042C85C: sb          $t1, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = ctx->r9;
    // 0x8042C860: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8042C864: jal         0x8002FE38
    // 0x8042C868: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002FE38(rdram, ctx);
        goto after_11;
    // 0x8042C868: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x8042C86C: jal         0x800653D8
    // 0x8042C870: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    func_800653D8(rdram, ctx);
        goto after_12;
    // 0x8042C870: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    after_12:
    // 0x8042C874: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x8042C878: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8042C87C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8042C880: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042C884: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8042C888: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8042C88C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042C890: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042C894: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x8042C898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C89C: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8042C8A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C8A4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8042C8A8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8042C8AC: bne         $t3, $at, L_8042C8CC
    if (ctx->r11 != ctx->r1) {
        // 0x8042C8B0: swc1        $f4, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
            goto L_8042C8CC;
    }
    // 0x8042C8B0: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
    // 0x8042C8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C8B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C8BC: jal         0x8042D50C
    // 0x8042C8C0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8042D50C(rdram, ctx);
        goto after_13;
    // 0x8042C8C0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_13:
    // 0x8042C8C4: b           L_8042C8D4
    // 0x8042C8C8: nop

        goto L_8042C8D4;
    // 0x8042C8C8: nop

L_8042C8CC:
    // 0x8042C8CC: jal         0x8042D50C
    // 0x8042C8D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_14;
    // 0x8042C8D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
L_8042C8D4:
    // 0x8042C8D4: jal         0x8006CAE0
    // 0x8042C8D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CAE0(rdram, ctx);
        goto after_15;
    // 0x8042C8D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
L_8042C8DC:
    // 0x8042C8DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042C8E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042C8E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8042C8E8: jr          $ra
    // 0x8042C8EC: nop

    return;
    // 0x8042C8EC: nop

;}
RECOMP_FUNC void func_8042F894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F894: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8042F898: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8042F89C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8042F8A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8042F8A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042F8A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042F8AC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BA0) << 16);
    // 0x8042F8B0: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8042F8B4: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8042F8B8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8042F8BC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8042F8C0: lwc1        $f20, 0x28($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8042F8C4: bnel        $t6, $zero, L_8042F938
    if (ctx->r14 != 0) {
        // 0x8042F8C8: lwc1        $f8, 0x50($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
            goto L_8042F938;
    }
    goto skip_0;
    // 0x8042F8C8: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x8042F8CC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B98) << 16);
    // 0x8042F8D0: lwc1        $f8, 0x1C78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B98));
    // 0x8042F8D4: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8042F8D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8042F8DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042F8E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8042F8E4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8042F8E8: jal         0x80082730
    // 0x8042F8EC: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    fsin(rdram, ctx);
        goto after_0;
    // 0x8042F8EC: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    after_0:
    // 0x8042F8F0: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8042F8F4: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8042F8F8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B9C) << 16);
    // 0x8042F8FC: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8042F900: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8042F904: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8042F908: lwc1        $f8, 0x1C7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B9C));
    // 0x8042F90C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8042F910: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042F914: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8042F918: jal         0x8008D250
    // 0x8042F91C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    fcos(rdram, ctx);
        goto after_1;
    // 0x8042F91C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    after_1:
    // 0x8042F920: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8042F924: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8042F928: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8042F92C: b           L_8042F994
    // 0x8042F930: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
        goto L_8042F994;
    // 0x8042F930: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8042F934: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
L_8042F938:
    // 0x8042F938: lwc1        $f10, 0x1C80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BA0));
    // 0x8042F93C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8042F940: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042F944: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8042F948: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8042F94C: jal         0x80082730
    // 0x8042F950: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    fsin(rdram, ctx);
        goto after_2;
    // 0x8042F950: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_2:
    // 0x8042F954: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8042F958: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8042F95C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BA4) << 16);
    // 0x8042F960: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8042F964: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8042F968: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x8042F96C: lwc1        $f10, 0x1C84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BA4));
    // 0x8042F970: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8042F974: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042F978: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8042F97C: jal         0x8008D250
    // 0x8042F980: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    fcos(rdram, ctx);
        goto after_3;
    // 0x8042F980: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_3:
    // 0x8042F984: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8042F988: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8042F98C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8042F990: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
L_8042F994:
    // 0x8042F994: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8042F998: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8042F99C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8042F9A0: jr          $ra
    // 0x8042F9A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8042F9A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8044B58C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B58C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044B590: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13544) << 16);
    // 0x8044B594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B598: addiu       $t6, $t6, 0x7924
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13544));
    // 0x8044B59C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044B5A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044B5A4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044B5A8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044B5AC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044B5B0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B5B4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044B5B8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044B5BC: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044B5C0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044B5C4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044B5C8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044B5CC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B5D0: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044B5D4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044B5D8: jal         0x80050A50
    // 0x8044B5DC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044B5DC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044B5E0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044B5E4: jalr        $v0
    // 0x8044B5E8: sw          $v0, 0x6A8C($v1)
    MEM_W(0X6A8C, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044B5E8: sw          $v0, 0x6A8C($v1)
    MEM_W(0X6A8C, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044B5EC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B5F0: sw          $v0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r2;
    // 0x8044B5F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B5F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044B5FC: jr          $ra
    // 0x8044B600: nop

    return;
    // 0x8044B600: nop

;}
RECOMP_FUNC void func_806B294C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B294C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2950: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2954: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2958: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B295C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2960: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2964: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2968: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B296C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2970: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2974: jr          $ra
    // 0x806B2978: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2978: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8069D374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D37C: jal         0x8069D320
    // 0x8069D380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069D320(rdram, ctx);
        goto after_0;
    // 0x8069D380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D384: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D388: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(571, 0X3F8) << 16);
    // 0x8069D38C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8069D390: addiu       $t7, $t7, -0x2F18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(571, 0X3F8));
    // 0x8069D394: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8069D398: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8069D39C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D3A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D3A4: jr          $ra
    // 0x8069D3A8: nop

    return;
    // 0x8069D3A8: nop

    // 0x8069D3AC: nop

;}
RECOMP_FUNC void func_8079ADA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079ADA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079ADA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079ADA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8079ADAC: jal         0x80045A34
    // 0x8079ADB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8079ADB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8079ADB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079ADB8: bne         $v0, $zero, L_8079ADC8
    if (ctx->r2 != 0) {
        // 0x8079ADBC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8079ADC8;
    }
    // 0x8079ADBC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8079ADC0: b           L_8079ADD4
    // 0x8079ADC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8079ADD4;
    // 0x8079ADC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079ADC8:
    // 0x8079ADC8: jal         0x8079AD94
    // 0x8079ADCC: nop

    func_8079AD94(rdram, ctx);
        goto after_1;
    // 0x8079ADCC: nop

    after_1:
    // 0x8079ADD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8079ADD4:
    // 0x8079ADD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079ADD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079ADDC: jr          $ra
    // 0x8079ADE0: nop

    return;
    // 0x8079ADE0: nop

;}
RECOMP_FUNC void func_80699BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699BEC: jal         0x80699A94
    // 0x80699BF0: nop

    func_80699A94(rdram, ctx);
        goto after_0;
    // 0x80699BF0: nop

    after_0:
    // 0x80699BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699BFC: jr          $ra
    // 0x80699C00: nop

    return;
    // 0x80699C00: nop

;}
RECOMP_FUNC void func_8064EF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EF20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064EF24: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D48) << 16);
    // 0x8064EF28: lwc1        $f4, 0x4748($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D48));
    // 0x8064EF2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8064EF30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064EF34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8064EF38: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8064EF3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8064EF40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064EF44: addiu       $t6, $zero, 0x1C98
    ctx->r14 = ADD32(0, 0X1C98);
    // 0x8064EF48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8064EF4C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064EF50: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064EF54: addiu       $a1, $zero, 0x294
    ctx->r5 = ADD32(0, 0X294);
    // 0x8064EF58: jal         0x8064EAC8
    // 0x8064EF5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_8064EAC8(rdram, ctx);
        goto after_0;
    // 0x8064EF5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8064EF60: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8064EF64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EF68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064EF6C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8064EF70: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8064EF74: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8064EF78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064EF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064EF80: jr          $ra
    // 0x8064EF84: nop

    return;
    // 0x8064EF84: nop

;}
RECOMP_FUNC void func_804A4960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A4964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A4968: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804A496C: lui         $t8, 0x804A
    ctx->r24 = S32(RELOC_HI16(176, 0X105C) << 16);
    // 0x804A4970: addiu       $t8, $t8, 0x4A5C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(176, 0X105C));
    // 0x804A4974: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804A4978: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804A497C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804A4980: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804A4984: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804A4988: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804A498C: beql        $v1, $zero, L_804A49C0
    if (ctx->r3 == 0) {
        // 0x804A4990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A49C0;
    }
    goto skip_0;
    // 0x804A4990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A4994: jalr        $v1
    // 0x804A4998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804A4998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A499C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A49A0: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x804A49A4: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x804A49A8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x804A49AC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x804A49B0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x804A49B4: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x804A49B8: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x804A49BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A49C0:
    // 0x804A49C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A49C4: jr          $ra
    // 0x804A49C8: nop

    return;
    // 0x804A49C8: nop

;}
RECOMP_FUNC void func_805331DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805331DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805331E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805331E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805331E8: jal         0x8004700C
    // 0x805331EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805331EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805331F0: beql        $v0, $zero, L_805332CC
    if (ctx->r2 == 0) {
        // 0x805331F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805332CC;
    }
    goto skip_0;
    // 0x805331F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805331F8: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x805331FC: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80533200: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80533204: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80533208: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8053320C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80533210: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80533214: nop

    // 0x80533218: bc1fl       L_805332CC
    if (!c1cs) {
        // 0x8053321C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805332CC;
    }
    goto skip_1;
    // 0x8053321C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80533220: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80533224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8053322C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80533230: nop

    // 0x80533234: bc1fl       L_805332CC
    if (!c1cs) {
        // 0x80533238: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805332CC;
    }
    goto skip_2;
    // 0x80533238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8053323C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80533240: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80533244: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80533248: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8053324C: jal         0x80533878
    // 0x80533250: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    func_80533878(rdram, ctx);
        goto after_1;
    // 0x80533250: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    after_1:
    // 0x80533254: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80533258: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8053325C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80533260: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80533264: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80533268: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8053326C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80533270: sw          $t7, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r15;
    // 0x80533274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533278: jal         0x8053319C
    // 0x8053327C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    func_8053319C(rdram, ctx);
        goto after_2;
    // 0x8053327C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x80533280: jal         0x80533108
    // 0x80533284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80533108(rdram, ctx);
        goto after_3;
    // 0x80533284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80533288: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8053328C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80533290: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80533294: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x80533298: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8053329C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x805332A0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x805332A4: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805332A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805332AC: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x805332B0: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805332B4: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805332B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805332BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805332C0: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x805332C4: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x805332C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805332CC:
    // 0x805332CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805332D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805332D4: jr          $ra
    // 0x805332D8: nop

    return;
    // 0x805332D8: nop

;}
RECOMP_FUNC void func_806AEBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEBDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AEBE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AEBE4: jal         0x8004700C
    // 0x806AEBE8: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806AEBE8: nop

    after_0:
    // 0x806AEBEC: beq         $v0, $zero, L_806AEC2C
    if (ctx->r2 == 0) {
        // 0x806AEBF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806AEC2C;
    }
    // 0x806AEBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AEBF4: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x806AEBF8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x806AEBFC: bnel        $a0, $t6, L_806AEC30
    if (ctx->r4 != ctx->r14) {
        // 0x806AEC00: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806AEC30;
    }
    goto skip_0;
    // 0x806AEC00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806AEC04: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x806AEC08: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x806AEC0C: beq         $v1, $a0, L_806AEC24
    if (ctx->r3 == ctx->r4) {
        // 0x806AEC10: nop
    
            goto L_806AEC24;
    }
    // 0x806AEC10: nop

    // 0x806AEC14: beq         $v1, $at, L_806AEC24
    if (ctx->r3 == ctx->r1) {
        // 0x806AEC18: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_806AEC24;
    }
    // 0x806AEC18: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x806AEC1C: bnel        $v1, $at, L_806AEC30
    if (ctx->r3 != ctx->r1) {
        // 0x806AEC20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806AEC30;
    }
    goto skip_1;
    // 0x806AEC20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_806AEC24:
    // 0x806AEC24: b           L_806AEC30
    // 0x806AEC28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806AEC30;
    // 0x806AEC28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806AEC2C:
    // 0x806AEC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AEC30:
    // 0x806AEC30: jr          $ra
    // 0x806AEC34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806AEC34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_807B1100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B1100: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807B1104: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x807B1108: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x807B110C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807B1110: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807B1114: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B1118: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B111C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B1120: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B1124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B1128: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x807B112C: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x807B1130: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x807B1134: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x807B1138: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B113C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x807B1140: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x807B1144: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
L_807B1148:
    // 0x807B1148: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x807B114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B1150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x807B1154: beq         $t6, $zero, L_807B118C
    if (ctx->r14 == 0) {
        // 0x807B1158: nop
    
            goto L_807B118C;
    }
    // 0x807B1158: nop

    // 0x807B115C: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x807B1160: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807B1164: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x807B1168: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x807B116C: nop

    // 0x807B1170: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x807B1174: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x807B1178: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807B117C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x807B1180: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x807B1184: b           L_807B1194
    // 0x807B1188: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
        goto L_807B1194;
    // 0x807B1188: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
L_807B118C:
    // 0x807B118C: jal         0x807B1048
    // 0x807B1190: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_807B1048(rdram, ctx);
        goto after_0;
    // 0x807B1190: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_0:
L_807B1194:
    // 0x807B1194: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x807B1198: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x807B119C: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x807B11A0: addiu       $s6, $s6, 0x6
    ctx->r22 = ADD32(ctx->r22, 0X6);
    // 0x807B11A4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x807B11A8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x807B11AC: bne         $s2, $s7, L_807B1148
    if (ctx->r18 != ctx->r23) {
        // 0x807B11B0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_807B1148;
    }
    // 0x807B11B0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x807B11B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x807B11B8: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x807B11BC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x807B11C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B11C4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807B11C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B11CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B11D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B11D4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807B11D8: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x807B11DC: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x807B11E0: jr          $ra
    // 0x807B11E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x807B11E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807B3A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B3A94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B3A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B3A9C: lui         $a0, 0x807B
    ctx->r4 = S32(RELOC_HI16(877, 0X360) << 16);
    // 0x807B3AA0: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(877, 0X370) << 16);
    // 0x807B3AA4: addiu       $a1, $a1, 0x3E00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(877, 0X370));
    // 0x807B3AA8: addiu       $a0, $a0, 0x3DF0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(877, 0X360));
    // 0x807B3AAC: jal         0x8004667C
    // 0x807B3AB0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x807B3AB0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x807B3AB4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807B3AB8: lui         $a2, 0x807B
    ctx->r6 = S32(RELOC_HI16(877, 0X19C) << 16);
    // 0x807B3ABC: addiu       $a2, $a2, 0x3C2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(877, 0X19C));
    // 0x807B3AC0: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x807B3AC4: jal         0x80057B28
    // 0x807B3AC8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x807B3AC8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_1:
    // 0x807B3ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B3AD0: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(877, 0X50) << 16);
    // 0x807B3AD4: addiu       $v0, $v0, 0x3AE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(877, 0X50));
    // 0x807B3AD8: jr          $ra
    // 0x807B3ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807B3ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80473350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473350: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80473354: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80473358: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8047335C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80473360: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80473364: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80473368: bne         $v0, $at, L_80473384
    if (ctx->r2 != ctx->r1) {
        // 0x8047336C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80473384;
    }
    // 0x8047336C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80473370: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(161, 0XA4) << 16);
    // 0x80473374: addiu       $t6, $t6, 0x3234
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(161, 0XA4));
    // 0x80473378: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8047337C: b           L_804733DC
    // 0x80473380: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
        goto L_804733DC;
    // 0x80473380: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
L_80473384:
    // 0x80473384: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80473388: bne         $v0, $at, L_804733DC
    if (ctx->r2 != ctx->r1) {
        // 0x8047338C: lui         $t7, 0x8005
        ctx->r15 = S32(0X8005 << 16);
            goto L_804733DC;
    }
    // 0x8047338C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80473390: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X147C) << 16);
    // 0x80473394: lwc1        $f0, 0x460C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X147C));
    // 0x80473398: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8047339C: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x804733A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804733A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804733A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804733AC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x804733B0: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x804733B4: jal         0x80473DF8
    // 0x804733B8: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    func_80473DF8(rdram, ctx);
        goto after_0;
    // 0x804733B8: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    after_0:
    // 0x804733BC: jal         0x8004700C
    // 0x804733C0: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x804733C0: nop

    after_1:
    // 0x804733C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804733C8: jal         0x80473248
    // 0x804733CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80473248(rdram, ctx);
        goto after_2;
    // 0x804733CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x804733D0: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x804733D4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x804733D8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_804733DC:
    // 0x804733DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804733E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804733E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804733E8: jr          $ra
    // 0x804733EC: nop

    return;
    // 0x804733EC: nop

;}
RECOMP_FUNC void func_80401260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80401260: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80401264: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80401268: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040126C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80401270: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80401274: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80401278: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x8040127C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80401280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80401284: bne         $t7, $at, L_8040129C
    if (ctx->r15 != ctx->r1) {
        // 0x80401288: lw          $t0, 0x1F4($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X1F4);
            goto L_8040129C;
    }
    // 0x80401288: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040128C: jal         0x804011D8
    // 0x80401290: nop

    func_804011D8(rdram, ctx);
        goto after_0;
    // 0x80401290: nop

    after_0:
    // 0x80401294: b           L_80401428
    // 0x80401298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80401428;
    // 0x80401298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040129C:
    // 0x8040129C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x804012A0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804012A4: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x804012A8: lhu         $v0, 0xC($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XC);
    // 0x804012AC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x804012B0: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x804012B4: beq         $v0, $at, L_804012CC
    if (ctx->r2 == ctx->r1) {
        // 0x804012B8: addiu       $at, $zero, 0x400C
        ctx->r1 = ADD32(0, 0X400C);
            goto L_804012CC;
    }
    // 0x804012B8: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x804012BC: beql        $v0, $at, L_804013B4
    if (ctx->r2 == ctx->r1) {
        // 0x804012C0: lhu         $v0, 0xC($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XC);
            goto L_804013B4;
    }
    goto skip_0;
    // 0x804012C0: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    skip_0:
    // 0x804012C4: b           L_80401428
    // 0x804012C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80401428;
    // 0x804012C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804012CC:
    // 0x804012CC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804012D0: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x804012D4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804012D8: sb          $t1, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r9;
    // 0x804012DC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804012E0: sb          $t2, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r10;
    // 0x804012E4: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x804012E8: beq         $v0, $zero, L_80401318
    if (ctx->r2 == 0) {
        // 0x804012EC: nop
    
            goto L_80401318;
    }
    // 0x804012EC: nop

    // 0x804012F0: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x804012F4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x804012F8: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x804012FC: beq         $v1, $zero, L_8040130C
    if (ctx->r3 == 0) {
        // 0x80401300: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_8040130C;
    }
    // 0x80401300: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80401304: b           L_80401328
    // 0x80401308: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
        goto L_80401328;
    // 0x80401308: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
L_8040130C:
    // 0x8040130C: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
    // 0x80401310: b           L_80401328
    // 0x80401314: sw          $t5, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r13;
        goto L_80401328;
    // 0x80401314: sw          $t5, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r13;
L_80401318:
    // 0x80401318: jal         0x804011D8
    // 0x8040131C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804011D8(rdram, ctx);
        goto after_1;
    // 0x8040131C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80401320: b           L_80401428
    // 0x80401324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80401428;
    // 0x80401324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80401328:
    // 0x80401328: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8040132C: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x80401330: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80401334: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80401338: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8040133C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80401340: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80401344: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80401348: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8040134C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80401350: bc1fl       L_80401374
    if (!c1cs) {
        // 0x80401354: lw          $t1, 0x38($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X38);
            goto L_80401374;
    }
    goto skip_1;
    // 0x80401354: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80401358: lw          $t8, 0x138($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X138);
    // 0x8040135C: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X75FC) << 16);
    // 0x80401360: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80401364: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80401368: lwc1        $f16, 0x763C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(8, 0X75FC));
    // 0x8040136C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80401370: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
L_80401374:
    // 0x80401374: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x80401378: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040137C: lwc1        $f18, 0x4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80401380: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80401384: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80401388: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8040138C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80401390: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80401394: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80401398: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8040139C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x804013A0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x804013A4: jal         0x8002F96C
    // 0x804013A8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    func_8002F96C(rdram, ctx);
        goto after_2;
    // 0x804013A8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x804013AC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x804013B0: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_804013B4:
    // 0x804013B4: addiu       $at, $zero, 0x46AC
    ctx->r1 = ADD32(0, 0X46AC);
    // 0x804013B8: beq         $v0, $at, L_80401408
    if (ctx->r2 == ctx->r1) {
        // 0x804013BC: addiu       $at, $zero, 0x46AD
        ctx->r1 = ADD32(0, 0X46AD);
            goto L_80401408;
    }
    // 0x804013BC: addiu       $at, $zero, 0x46AD
    ctx->r1 = ADD32(0, 0X46AD);
    // 0x804013C0: beq         $v0, $at, L_80401408
    if (ctx->r2 == ctx->r1) {
        // 0x804013C4: addiu       $at, $zero, 0x46AE
        ctx->r1 = ADD32(0, 0X46AE);
            goto L_80401408;
    }
    // 0x804013C4: addiu       $at, $zero, 0x46AE
    ctx->r1 = ADD32(0, 0X46AE);
    // 0x804013C8: beq         $v0, $at, L_80401408
    if (ctx->r2 == ctx->r1) {
        // 0x804013CC: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_80401408;
    }
    // 0x804013CC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x804013D0: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x804013D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804013D8: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x804013DC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804013E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x804013E4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x804013E8: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x804013EC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x804013F0: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x804013F4: swc1        $f2, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f2.u32l;
    // 0x804013F8: swc1        $f2, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f2.u32l;
    // 0x804013FC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80401400: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80401404: sw          $t4, 0x130($t0)
    MEM_W(0X130, ctx->r8) = ctx->r12;
L_80401408:
    // 0x80401408: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8040140C: lw          $a0, 0x34($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X34);
    // 0x80401410: jal         0x80067BBC
    // 0x80401414: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x80401414: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    after_3:
    // 0x80401418: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8040141C: jal         0x80067818
    // 0x80401420: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80401420: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80401424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80401428:
    // 0x80401428: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040142C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80401430: jr          $ra
    // 0x80401434: nop

    return;
    // 0x80401434: nop

;}
RECOMP_FUNC void func_804C498C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C498C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x804C4990: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804C4994: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x804C4998: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x804C499C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x804C49A0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x804C49A4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x804C49A8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x804C49AC: lbu         $t7, 0x7EA5($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7EA5);
    // 0x804C49B0: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
    // 0x804C49B4: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x804C49B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C49BC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x804C49C0: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804C49C4: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C49C8: bne         $t7, $zero, L_804C4C04
    if (ctx->r15 != 0) {
        // 0x804C49CC: addiu       $v1, $v1, 0xD
        ctx->r3 = ADD32(ctx->r3, 0XD);
            goto L_804C4C04;
    }
    // 0x804C49CC: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x804C49D0: beql        $v0, $zero, L_804C4AA4
    if (ctx->r2 == 0) {
        // 0x804C49D4: lh          $a0, 0x1C($a3)
        ctx->r4 = MEM_H(ctx->r7, 0X1C);
            goto L_804C4AA4;
    }
    goto skip_0;
    // 0x804C49D4: lh          $a0, 0x1C($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X1C);
    skip_0:
    // 0x804C49D8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x804C49DC: addiu       $at, $zero, 0x405E
    ctx->r1 = ADD32(0, 0X405E);
    // 0x804C49E0: beq         $a0, $at, L_804C4A58
    if (ctx->r4 == ctx->r1) {
        // 0x804C49E4: addiu       $at, $zero, 0x405F
        ctx->r1 = ADD32(0, 0X405F);
            goto L_804C4A58;
    }
    // 0x804C49E4: addiu       $at, $zero, 0x405F
    ctx->r1 = ADD32(0, 0X405F);
    // 0x804C49E8: beql        $a0, $at, L_804C4A88
    if (ctx->r4 == ctx->r1) {
        // 0x804C49EC: lbu         $t0, 0x0($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X0);
            goto L_804C4A88;
    }
    goto skip_1;
    // 0x804C49EC: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    skip_1:
    // 0x804C49F0: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x804C49F4: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x804C49F8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x804C49FC: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x804C4A00: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C4A04: mflo        $t1
    ctx->r9 = lo;
    // 0x804C4A08: andi        $t2, $t1, 0xFFF8
    ctx->r10 = ctx->r9 & 0XFFF8;
    // 0x804C4A0C: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x804C4A10: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x804C4A14: lh          $t5, 0x144($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X144);
    // 0x804C4A18: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x804C4A1C: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x804C4A20: multu       $t4, $t6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C4A24: mflo        $t7
    ctx->r15 = lo;
    // 0x804C4A28: andi        $t9, $t7, 0xFFF8
    ctx->r25 = ctx->r15 & 0XFFF8;
    // 0x804C4A2C: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x804C4A30: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x804C4A34: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
    // 0x804C4A38: lbu         $t0, 0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2);
    // 0x804C4A3C: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x804C4A40: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C4A44: mflo        $t3
    ctx->r11 = lo;
    // 0x804C4A48: andi        $t5, $t3, 0xFFF8
    ctx->r13 = ctx->r11 & 0XFFF8;
    // 0x804C4A4C: sra         $t4, $t5, 3
    ctx->r12 = S32(SIGNED(ctx->r13) >> 3);
    // 0x804C4A50: b           L_804C4B28
    // 0x804C4A54: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
        goto L_804C4B28;
    // 0x804C4A54: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
L_804C4A58:
    // 0x804C4A58: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
    // 0x804C4A5C: lbu         $t6, 0xD($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XD);
    // 0x804C4A60: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x804C4A64: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x804C4A68: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x804C4A6C: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x804C4A70: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x804C4A74: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x804C4A78: sra         $t1, $t8, 1
    ctx->r9 = S32(SIGNED(ctx->r24) >> 1);
    // 0x804C4A7C: b           L_804C4B28
    // 0x804C4A80: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
        goto L_804C4B28;
    // 0x804C4A80: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x804C4A84: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
L_804C4A88:
    // 0x804C4A88: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x804C4A8C: lbu         $t2, 0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1);
    // 0x804C4A90: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x804C4A94: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x804C4A98: b           L_804C4B28
    // 0x804C4A9C: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
        goto L_804C4B28;
    // 0x804C4A9C: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x804C4AA0: lh          $a0, 0x1C($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X1C);
L_804C4AA4:
    // 0x804C4AA4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x804C4AA8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x804C4AAC: jal         0x8006593C
    // 0x804C4AB0: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x804C4AB0: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    after_0:
    // 0x804C4AB4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x804C4AB8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x804C4ABC: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x804C4AC0: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C4AC4: mflo        $t4
    ctx->r12 = lo;
    // 0x804C4AC8: andi        $t6, $t4, 0xFF80
    ctx->r14 = ctx->r12 & 0XFF80;
    // 0x804C4ACC: sra         $t7, $t6, 7
    ctx->r15 = S32(SIGNED(ctx->r14) >> 7);
    // 0x804C4AD0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x804C4AD4: lh          $a0, 0x1C($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X1C);
    // 0x804C4AD8: jal         0x8006593C
    // 0x804C4ADC: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x804C4ADC: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    after_1:
    // 0x804C4AE0: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x804C4AE4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x804C4AE8: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x804C4AEC: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C4AF0: mflo        $t1
    ctx->r9 = lo;
    // 0x804C4AF4: andi        $t0, $t1, 0xFF80
    ctx->r8 = ctx->r9 & 0XFF80;
    // 0x804C4AF8: sra         $t2, $t0, 7
    ctx->r10 = S32(SIGNED(ctx->r8) >> 7);
    // 0x804C4AFC: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x804C4B00: lh          $a0, 0x1C($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X1C);
    // 0x804C4B04: jal         0x8006593C
    // 0x804C4B08: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    func_8006593C(rdram, ctx);
        goto after_2;
    // 0x804C4B08: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    after_2:
    // 0x804C4B0C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x804C4B10: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    // 0x804C4B14: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C4B18: mflo        $t4
    ctx->r12 = lo;
    // 0x804C4B1C: andi        $t6, $t4, 0xFF80
    ctx->r14 = ctx->r12 & 0XFF80;
    // 0x804C4B20: sra         $t7, $t6, 7
    ctx->r15 = S32(SIGNED(ctx->r14) >> 7);
    // 0x804C4B24: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
L_804C4B28:
    // 0x804C4B28: lhu         $t9, 0x56($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X56);
    // 0x804C4B2C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804C4B30: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x804C4B34: bne         $t9, $at, L_804C4B44
    if (ctx->r25 != ctx->r1) {
        // 0x804C4B38: addiu       $a2, $sp, 0x48
        ctx->r6 = ADD32(ctx->r29, 0X48);
            goto L_804C4B44;
    }
    // 0x804C4B38: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x804C4B3C: jal         0x804C44B4
    // 0x804C4B40: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    func_804C44B4(rdram, ctx);
        goto after_3;
    // 0x804C4B40: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    after_3:
L_804C4B44:
    // 0x804C4B44: lw          $t8, 0x174($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X174);
    // 0x804C4B48: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x804C4B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C4B50: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x804C4B54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x804C4B58: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x804C4B5C: lhu         $v1, 0x16($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X16);
    // 0x804C4B60: andi        $v1, $v1, 0x1800
    ctx->r3 = ctx->r3 & 0X1800;
    // 0x804C4B64: bnel        $v1, $at, L_804C4B88
    if (ctx->r3 != ctx->r1) {
        // 0x804C4B68: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_804C4B88;
    }
    goto skip_2;
    // 0x804C4B68: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    skip_2:
    // 0x804C4B6C: jal         0x804C44EC
    // 0x804C4B70: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    func_804C44EC(rdram, ctx);
        goto after_4;
    // 0x804C4B70: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_4:
    // 0x804C4B74: lw          $t0, 0x174($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X174);
    // 0x804C4B78: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x804C4B7C: lhu         $v1, 0x16($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X16);
    // 0x804C4B80: andi        $v1, $v1, 0x1800
    ctx->r3 = ctx->r3 & 0X1800;
    // 0x804C4B84: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
L_804C4B88:
    // 0x804C4B88: bnel        $v1, $at, L_804C4BD0
    if (ctx->r3 != ctx->r1) {
        // 0x804C4B8C: addiu       $at, $zero, 0x1800
        ctx->r1 = ADD32(0, 0X1800);
            goto L_804C4BD0;
    }
    goto skip_3;
    // 0x804C4B8C: addiu       $at, $zero, 0x1800
    ctx->r1 = ADD32(0, 0X1800);
    skip_3:
    // 0x804C4B90: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    // 0x804C4B94: beql        $v0, $zero, L_804C4BD0
    if (ctx->r2 == 0) {
        // 0x804C4B98: addiu       $at, $zero, 0x1800
        ctx->r1 = ADD32(0, 0X1800);
            goto L_804C4BD0;
    }
    goto skip_4;
    // 0x804C4B98: addiu       $at, $zero, 0x1800
    ctx->r1 = ADD32(0, 0X1800);
    skip_4:
    // 0x804C4B9C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x804C4BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C4BA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x804C4BA8: beq         $a2, $zero, L_804C4BCC
    if (ctx->r6 == 0) {
        // 0x804C4BAC: lw          $a3, 0x60($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X60);
            goto L_804C4BCC;
    }
    // 0x804C4BAC: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x804C4BB0: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x804C4BB4: jal         0x804C462C
    // 0x804C4BB8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_804C462C(rdram, ctx);
        goto after_5;
    // 0x804C4BB8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_5:
    // 0x804C4BBC: lw          $t5, 0x174($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X174);
    // 0x804C4BC0: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x804C4BC4: lhu         $v1, 0x16($t4)
    ctx->r3 = MEM_HU(ctx->r12, 0X16);
    // 0x804C4BC8: andi        $v1, $v1, 0x1800
    ctx->r3 = ctx->r3 & 0X1800;
L_804C4BCC:
    // 0x804C4BCC: addiu       $at, $zero, 0x1800
    ctx->r1 = ADD32(0, 0X1800);
L_804C4BD0:
    // 0x804C4BD0: bnel        $v1, $at, L_804C4C08
    if (ctx->r3 != ctx->r1) {
        // 0x804C4BD4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804C4C08;
    }
    goto skip_5;
    // 0x804C4BD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x804C4BD8: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    // 0x804C4BDC: beql        $v0, $zero, L_804C4C08
    if (ctx->r2 == 0) {
        // 0x804C4BE0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804C4C08;
    }
    goto skip_6;
    // 0x804C4BE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x804C4BE4: lw          $a2, 0x268($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X268);
    // 0x804C4BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C4BEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x804C4BF0: beq         $a2, $zero, L_804C4C04
    if (ctx->r6 == 0) {
        // 0x804C4BF4: lw          $a3, 0x60($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X60);
            goto L_804C4C04;
    }
    // 0x804C4BF4: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x804C4BF8: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x804C4BFC: jal         0x804C462C
    // 0x804C4C00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_804C462C(rdram, ctx);
        goto after_6;
    // 0x804C4C00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_6:
L_804C4C04:
    // 0x804C4C04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804C4C08:
    // 0x804C4C08: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x804C4C0C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x804C4C10: jr          $ra
    // 0x804C4C14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x804C4C14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80053690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053690: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80053694: lw          $t6, 0x60D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X60D0);
    // 0x80053698: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005369C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800536A0: bne         $t6, $zero, L_800536C0
    if (ctx->r14 != 0) {
        // 0x800536A4: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800536C0;
    }
    // 0x800536A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800536A8: jal         0x80052CDC
    // 0x800536AC: nop

    func_80052CDC(rdram, ctx);
        goto after_0;
    // 0x800536AC: nop

    after_0:
    // 0x800536B0: bnel        $v0, $zero, L_800536C4
    if (ctx->r2 != 0) {
        // 0x800536B4: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_800536C4;
    }
    goto skip_0;
    // 0x800536B4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800536B8: b           L_80053780
    // 0x800536BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053780;
    // 0x800536BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800536C0:
    // 0x800536C0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800536C4:
    // 0x800536C4: lwc1        $f0, 0x3C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x800536C8: lwc1        $f4, 0x40($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X40);
    // 0x800536CC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800536D0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800536D4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800536D8: nop

    // 0x800536DC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800536E0: jal         0x8006A99C
    // 0x800536E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x800536E4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x800536E8: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800536EC: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x800536F0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800536F4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800536F8: nop

    // 0x800536FC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80053700: jal         0x8006A99C
    // 0x80053704: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_2;
    // 0x80053704: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x80053708: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8005370C: bltz        $v0, L_80053720
    if (SIGNED(ctx->r2) < 0) {
        // 0x80053710: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_80053720;
    }
    // 0x80053710: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80053714: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x80053718: bgez        $a0, L_80053728
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005371C: nop
    
            goto L_80053728;
    }
    // 0x8005371C: nop

L_80053720:
    // 0x80053720: b           L_80053780
    // 0x80053724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053780;
    // 0x80053724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80053728:
    // 0x80053728: jal         0x8006ABF0
    // 0x8005372C: sh          $a1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r5;
    func_8006ABF0(rdram, ctx);
        goto after_3;
    // 0x8005372C: sh          $a1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x80053730: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80053734: lh          $a1, 0x24($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X24);
    // 0x80053738: bne         $v0, $at, L_80053748
    if (ctx->r2 != ctx->r1) {
        // 0x8005373C: andi        $a2, $v0, 0xFFFF
        ctx->r6 = ctx->r2 & 0XFFFF;
            goto L_80053748;
    }
    // 0x8005373C: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x80053740: b           L_80053780
    // 0x80053744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053780;
    // 0x80053744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80053748:
    // 0x80053748: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005374C: andi        $t2, $a2, 0xF800
    ctx->r10 = ctx->r6 & 0XF800;
    // 0x80053750: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x80053754: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x80053758: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8005375C: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80053760: bne         $at, $zero, L_80053770
    if (ctx->r1 != 0) {
        // 0x80053764: ori         $t1, $v0, 0xC0
        ctx->r9 = ctx->r2 | 0XC0;
            goto L_80053770;
    }
    // 0x80053764: ori         $t1, $v0, 0xC0
    ctx->r9 = ctx->r2 | 0XC0;
    // 0x80053768: b           L_80053780
    // 0x8005376C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053780;
    // 0x8005376C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80053770:
    // 0x80053770: or          $a2, $t1, $t2
    ctx->r6 = ctx->r9 | ctx->r10;
    // 0x80053774: jal         0x8006B1C8
    // 0x80053778: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8006B1C8(rdram, ctx);
        goto after_4;
    // 0x80053778: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_4:
    // 0x8005377C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80053780:
    // 0x80053780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053784: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80053788: jr          $ra
    // 0x8005378C: nop

    return;
    // 0x8005378C: nop

;}
RECOMP_FUNC void func_805362C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805362C4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805362C8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805362CC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805362D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805362D4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805362D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805362DC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805362E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805362E4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805362E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805362EC: jr          $ra
    // 0x805362F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805362F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804CF930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF930: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CF934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF938: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804CF93C: jal         0x80047090
    // 0x804CF940: addiu       $a0, $zero, 0x4126
    ctx->r4 = ADD32(0, 0X4126);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804CF940: addiu       $a0, $zero, 0x4126
    ctx->r4 = ADD32(0, 0X4126);
    after_0:
    // 0x804CF944: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804CF948: bne         $v0, $at, L_804CF958
    if (ctx->r2 != ctx->r1) {
        // 0x804CF94C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804CF958;
    }
    // 0x804CF94C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804CF950: b           L_804CF9C8
    // 0x804CF954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CF9C8;
    // 0x804CF954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CF958:
    // 0x804CF958: lui         $at, 0x4126
    ctx->r1 = S32(0X4126 << 16);
    // 0x804CF95C: lui         $a3, 0xBC23
    ctx->r7 = S32(0XBC23 << 16);
    // 0x804CF960: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x804CF964: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804CF968: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    // 0x804CF96C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x804CF970: jal         0x8004613C
    // 0x804CF974: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804CF974: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x804CF978: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x804CF97C: bne         $v0, $zero, L_804CF98C
    if (ctx->r2 != 0) {
        // 0x804CF980: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804CF98C;
    }
    // 0x804CF980: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804CF984: b           L_804CF9C8
    // 0x804CF988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CF9C8;
    // 0x804CF988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CF98C:
    // 0x804CF98C: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x804CF990: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x804CF994: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804CF998: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804CF99C: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x804CF9A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CF9A4: jal         0x80047F9C
    // 0x804CF9A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804CF9A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804CF9AC: jal         0x804CEC28
    // 0x804CF9B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_804CEC28(rdram, ctx);
        goto after_3;
    // 0x804CF9B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x804CF9B4: bnel        $v0, $zero, L_804CF9C8
    if (ctx->r2 != 0) {
        // 0x804CF9B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_804CF9C8;
    }
    goto skip_0;
    // 0x804CF9B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x804CF9BC: b           L_804CF9C8
    // 0x804CF9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CF9C8;
    // 0x804CF9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804CF9C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CF9C8:
    // 0x804CF9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CF9CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CF9D0: jr          $ra
    // 0x804CF9D4: nop

    return;
    // 0x804CF9D4: nop

;}
RECOMP_FUNC void func_8078D340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D340: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8078D344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078D348: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078D34C: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8078D350: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8078D354: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8078D358: jal         0x8004700C
    // 0x8078D35C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078D35C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_0:
    // 0x8078D360: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078D364: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8078D368: beq         $v0, $zero, L_8078D740
    if (ctx->r2 == 0) {
        // 0x8078D36C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078D740;
    }
    // 0x8078D36C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8078D370: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    // 0x8078D374: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8078D378: beq         $v0, $zero, L_8078D3A0
    if (ctx->r2 == 0) {
        // 0x8078D37C: nop
    
            goto L_8078D3A0;
    }
    // 0x8078D37C: nop

    // 0x8078D380: beq         $v0, $t0, L_8078D3A8
    if (ctx->r2 == ctx->r8) {
        // 0x8078D384: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8078D3A8;
    }
    // 0x8078D384: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8078D388: beq         $v0, $at, L_8078D664
    if (ctx->r2 == ctx->r1) {
        // 0x8078D38C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8078D664;
    }
    // 0x8078D38C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8078D390: beql        $v0, $at, L_8078D3AC
    if (ctx->r2 == ctx->r1) {
        // 0x8078D394: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8078D3AC;
    }
    goto skip_0;
    // 0x8078D394: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x8078D398: b           L_8078D734
    // 0x8078D39C: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
        goto L_8078D734;
    // 0x8078D39C: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
L_8078D3A0:
    // 0x8078D3A0: b           L_8078D734
    // 0x8078D3A4: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
        goto L_8078D734;
    // 0x8078D3A4: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
L_8078D3A8:
    // 0x8078D3A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8078D3AC:
    // 0x8078D3AC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8078D3B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8078D3B4: jal         0x8078D138
    // 0x8078D3B8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_8078D138(rdram, ctx);
        goto after_1;
    // 0x8078D3B8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x8078D3BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8078D3C0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8078D3C4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078D3C8: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    // 0x8078D3CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8078D3D0: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8078D3D4: lw          $t8, 0x1A4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A4);
    // 0x8078D3D8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8078D3DC: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    // 0x8078D3E0: beql        $t8, $zero, L_8078D418
    if (ctx->r24 == 0) {
        // 0x8078D3E4: lw          $v0, 0x14($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X14);
            goto L_8078D418;
    }
    goto skip_1;
    // 0x8078D3E4: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    skip_1:
    // 0x8078D3E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8078D3EC: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x8078D3F0: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D3F4: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8078D3F8: swc1        $f2, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f2.u32l;
    // 0x8078D3FC: sw          $t1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r9;
    // 0x8078D400: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    // 0x8078D404: jal         0x80067878
    // 0x8078D408: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_2;
    // 0x8078D408: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_2:
    // 0x8078D40C: b           L_8078D744
    // 0x8078D410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078D744;
    // 0x8078D410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078D414: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
L_8078D418:
    // 0x8078D418: beq         $v0, $zero, L_8078D424
    if (ctx->r2 == 0) {
        // 0x8078D41C: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8078D424;
    }
    // 0x8078D41C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8078D420: sw          $t2, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r10;
L_8078D424:
    // 0x8078D424: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x8078D428: beq         $v0, $zero, L_8078D434
    if (ctx->r2 == 0) {
        // 0x8078D42C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8078D434;
    }
    // 0x8078D42C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8078D430: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
L_8078D434:
    // 0x8078D434: lw          $t4, 0x14($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X14);
    // 0x8078D438: bnel        $t4, $zero, L_8078D570
    if (ctx->r12 != 0) {
        // 0x8078D43C: lw          $t2, 0x1C($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X1C);
            goto L_8078D570;
    }
    goto skip_2;
    // 0x8078D43C: lw          $t2, 0x1C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1C);
    skip_2:
    // 0x8078D440: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x8078D444: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8078D448: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8078D44C: bne         $v0, $t6, L_8078D458
    if (ctx->r2 != ctx->r14) {
        // 0x8078D450: sw          $t5, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r13;
            goto L_8078D458;
    }
    // 0x8078D450: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x8078D454: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8078D458:
    // 0x8078D458: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8078D45C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8078D460: slti        $at, $t8, 0x9
    ctx->r1 = SIGNED(ctx->r24) < 0X9 ? 1 : 0;
    // 0x8078D464: bne         $at, $zero, L_8078D56C
    if (ctx->r1 != 0) {
        // 0x8078D468: sw          $t8, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r24;
            goto L_8078D56C;
    }
    // 0x8078D468: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x8078D46C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x8078D470: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8078D474: jal         0x800653D8
    // 0x8078D478: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x8078D478: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_3:
    // 0x8078D47C: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8078D480: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078D484: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8078D488: bne         $t1, $zero, L_8078D55C
    if (ctx->r9 != 0) {
        // 0x8078D48C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8078D55C;
    }
    // 0x8078D48C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8078D490: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8078D494: jal         0x800653D8
    // 0x8078D498: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x8078D498: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_4:
    // 0x8078D49C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8078D4A0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078D4A4: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x8078D4A8: lw          $t2, 0x138($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X138);
    // 0x8078D4AC: beq         $t2, $zero, L_8078D4CC
    if (ctx->r10 == 0) {
        // 0x8078D4B0: nop
    
            goto L_8078D4CC;
    }
    // 0x8078D4B0: nop

    // 0x8078D4B4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8078D4B8: jal         0x800653D8
    // 0x8078D4BC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x8078D4BC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_5:
    // 0x8078D4C0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078D4C4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8078D4C8: andi        $a0, $v0, 0x1
    ctx->r4 = ctx->r2 & 0X1;
L_8078D4CC:
    // 0x8078D4CC: bne         $a0, $zero, L_8078D528
    if (ctx->r4 != 0) {
        // 0x8078D4D0: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_8078D528;
    }
    // 0x8078D4D0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8078D4D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8078D4D8: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8078D4DC: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x8078D4E0: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    // 0x8078D4E4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8078D4E8: swc1        $f2, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f2.u32l;
    // 0x8078D4EC: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8078D4F0: sw          $t4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r12;
    // 0x8078D4F4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8078D4F8: jal         0x800653D8
    // 0x8078D4FC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_6;
    // 0x8078D4FC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_6:
    // 0x8078D500: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078D504: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8078D508: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8078D50C: sw          $t5, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r13;
    // 0x8078D510: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D514: jal         0x80067878
    // 0x8078D518: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_7;
    // 0x8078D518: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_7:
    // 0x8078D51C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078D520: b           L_8078D56C
    // 0x8078D524: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
        goto L_8078D56C;
    // 0x8078D524: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
L_8078D528:
    // 0x8078D528: sw          $t6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r14;
    // 0x8078D52C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8078D530: jal         0x800653D8
    // 0x8078D534: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x8078D534: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_8:
    // 0x8078D538: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8078D53C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8078D540: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8078D544: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078D548: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8078D54C: addiu       $t9, $t8, 0x1E
    ctx->r25 = ADD32(ctx->r24, 0X1E);
    // 0x8078D550: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8078D554: b           L_8078D56C
    // 0x8078D558: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
        goto L_8078D56C;
    // 0x8078D558: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
L_8078D55C:
    // 0x8078D55C: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x8078D560: bnel        $t1, $zero, L_8078D570
    if (ctx->r9 != 0) {
        // 0x8078D564: lw          $t2, 0x1C($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X1C);
            goto L_8078D570;
    }
    goto skip_3;
    // 0x8078D564: lw          $t2, 0x1C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1C);
    skip_3:
    // 0x8078D568: sw          $t0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r8;
L_8078D56C:
    // 0x8078D56C: lw          $t2, 0x1C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1C);
L_8078D570:
    // 0x8078D570: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(802, 0XBA0) << 16);
    // 0x8078D574: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    // 0x8078D578: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8078D57C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8078D580: lwc1        $f4, -0x2350($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(802, 0XBA0));
    // 0x8078D584: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8078D588: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x8078D58C: lw          $t4, 0x138($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X138);
    // 0x8078D590: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8078D594: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8078D598: bnel        $t4, $zero, L_8078D5FC
    if (ctx->r12 != 0) {
        // 0x8078D59C: lwc1        $f16, 0x3C($t8)
        ctx->f16.u32l = MEM_W(ctx->r24, 0X3C);
            goto L_8078D5FC;
    }
    goto skip_4;
    // 0x8078D59C: lwc1        $f16, 0x3C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X3C);
    skip_4:
    // 0x8078D5A0: lwc1        $f6, 0x3C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X3C);
    // 0x8078D5A4: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8078D5A8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8078D5AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078D5B0: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8078D5B4: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8078D5B8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8078D5BC: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D5C0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8078D5C4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8078D5C8: nop

    // 0x8078D5CC: bc1fl       L_8078D650
    if (!c1cs) {
        // 0x8078D5D0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8078D650;
    }
    goto skip_5;
    // 0x8078D5D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_5:
    // 0x8078D5D4: sw          $t6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r14;
    // 0x8078D5D8: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8078D5DC: swc1        $f2, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f2.u32l;
    // 0x8078D5E0: sw          $t7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r15;
    // 0x8078D5E4: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    // 0x8078D5E8: jal         0x80067878
    // 0x8078D5EC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_9;
    // 0x8078D5EC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_9:
    // 0x8078D5F0: b           L_8078D64C
    // 0x8078D5F4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_8078D64C;
    // 0x8078D5F4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8078D5F8: lwc1        $f16, 0x3C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X3C);
L_8078D5FC:
    // 0x8078D5FC: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8078D600: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x8078D604: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078D608: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8078D60C: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8078D610: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8078D614: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D618: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8078D61C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8078D620: nop

    // 0x8078D624: bc1fl       L_8078D650
    if (!c1cs) {
        // 0x8078D628: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8078D650;
    }
    goto skip_6;
    // 0x8078D628: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_6:
    // 0x8078D62C: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x8078D630: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8078D634: swc1        $f2, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f2.u32l;
    // 0x8078D638: sw          $t1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r9;
    // 0x8078D63C: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    // 0x8078D640: jal         0x80067878
    // 0x8078D644: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_10;
    // 0x8078D644: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_10:
    // 0x8078D648: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_8078D64C:
    // 0x8078D64C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8078D650:
    // 0x8078D650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8078D654: jal         0x80048F84
    // 0x8078D658: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80048F84(rdram, ctx);
        goto after_11;
    // 0x8078D658: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_11:
    // 0x8078D65C: b           L_8078D734
    // 0x8078D660: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_8078D734;
    // 0x8078D660: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_8078D664:
    // 0x8078D664: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8078D668: beq         $v0, $zero, L_8078D678
    if (ctx->r2 == 0) {
        // 0x8078D66C: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8078D678;
    }
    // 0x8078D66C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8078D670: sw          $t2, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r10;
    // 0x8078D674: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8078D678:
    // 0x8078D678: bnel        $v0, $zero, L_8078D734
    if (ctx->r2 != 0) {
        // 0x8078D67C: addiu       $a2, $a3, 0xC4
        ctx->r6 = ADD32(ctx->r7, 0XC4);
            goto L_8078D734;
    }
    goto skip_7;
    // 0x8078D67C: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    skip_7:
    // 0x8078D680: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8078D684: lui         $t4, 0x8079
    ctx->r12 = S32(RELOC_HI16(802, 0XB60) << 16);
    // 0x8078D688: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8078D68C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8078D690: lw          $t4, -0x2390($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(802, 0XB60));
    // 0x8078D694: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8078D698: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x8078D69C: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x8078D6A0: bne         $at, $zero, L_8078D6BC
    if (ctx->r1 != 0) {
        // 0x8078D6A4: sw          $t4, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r12;
            goto L_8078D6BC;
    }
    // 0x8078D6A4: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
    // 0x8078D6A8: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x8078D6AC: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8078D6B0: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x8078D6B4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8078D6B8: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
L_8078D6BC:
    // 0x8078D6BC: lw          $t1, 0x20($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X20);
    // 0x8078D6C0: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8078D6C4: bnel        $at, $zero, L_8078D6DC
    if (ctx->r1 != 0) {
        // 0x8078D6C8: lw          $t2, 0x138($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X138);
            goto L_8078D6DC;
    }
    goto skip_8;
    // 0x8078D6C8: lw          $t2, 0x138($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X138);
    skip_8:
    // 0x8078D6CC: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x8078D6D0: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x8078D6D4: sw          $t0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r8;
    // 0x8078D6D8: lw          $t2, 0x138($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X138);
L_8078D6DC:
    // 0x8078D6DC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8078D6E0: bnel        $t2, $zero, L_8078D734
    if (ctx->r10 != 0) {
        // 0x8078D6E4: addiu       $a2, $a3, 0xC4
        ctx->r6 = ADD32(ctx->r7, 0XC4);
            goto L_8078D734;
    }
    goto skip_9;
    // 0x8078D6E4: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    skip_9:
    // 0x8078D6E8: lwc1        $f6, 0x3C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X3C);
    // 0x8078D6EC: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8078D6F0: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x8078D6F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078D6F8: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8078D6FC: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    // 0x8078D700: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8078D704: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8078D708: nop

    // 0x8078D70C: bc1fl       L_8078D734
    if (!c1cs) {
        // 0x8078D710: addiu       $a2, $a3, 0xC4
        ctx->r6 = ADD32(ctx->r7, 0XC4);
            goto L_8078D734;
    }
    goto skip_10;
    // 0x8078D710: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
    skip_10:
    // 0x8078D714: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8078D718: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8078D71C: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x8078D720: swc1        $f2, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f2.u32l;
    // 0x8078D724: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8078D728: sw          $t4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r12;
    // 0x8078D72C: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x8078D730: addiu       $a2, $a3, 0xC4
    ctx->r6 = ADD32(ctx->r7, 0XC4);
L_8078D734:
    // 0x8078D734: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8078D738: jal         0x80048F84
    // 0x8078D73C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_12;
    // 0x8078D73C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
L_8078D740:
    // 0x8078D740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078D744:
    // 0x8078D744: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8078D748: jr          $ra
    // 0x8078D74C: nop

    return;
    // 0x8078D74C: nop

;}
RECOMP_FUNC void func_80446AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446AAC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446AB0: addiu       $v1, $zero, 0xAC8
    ctx->r3 = ADD32(0, 0XAC8);
    // 0x80446AB4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446AB8: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80446ABC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446AC0: sw          $zero, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = 0;
    // 0x80446AC4: addiu       $a1, $zero, 0x744
    ctx->r5 = ADD32(0, 0X744);
    // 0x80446AC8: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446ACC: addiu       $t7, $zero, 0x618
    ctx->r15 = ADD32(0, 0X618);
    // 0x80446AD0: sw          $t6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r14;
    // 0x80446AD4: sw          $t7, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r15;
    // 0x80446AD8: sw          $a1, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->r5;
    // 0x80446ADC: sw          $a1, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->r5;
    // 0x80446AE0: jr          $ra
    // 0x80446AE4: sw          $v1, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r3;
    return;
    // 0x80446AE4: sw          $v1, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_8064A848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A84C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064A854: jal         0x80045A34
    // 0x8064A858: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8064A858: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8064A85C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064A860: bne         $v0, $zero, L_8064A870
    if (ctx->r2 != 0) {
        // 0x8064A864: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8064A870;
    }
    // 0x8064A864: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8064A868: b           L_8064A87C
    // 0x8064A86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8064A87C;
    // 0x8064A86C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064A870:
    // 0x8064A870: jal         0x8064A838
    // 0x8064A874: nop

    func_8064A838(rdram, ctx);
        goto after_1;
    // 0x8064A874: nop

    after_1:
    // 0x8064A878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064A87C:
    // 0x8064A87C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064A880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A884: jr          $ra
    // 0x8064A888: nop

    return;
    // 0x8064A888: nop

;}
RECOMP_FUNC void func_805DA0C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA0C0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x805DA0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA0C8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x805DA0CC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805DA0D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805DA0D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805DA0D8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x805DA0DC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805DA0E0: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(477, 0XBA0) << 16);
    // 0x805DA0E4: lwc1        $f18, -0x5420($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(477, 0XBA0));
    // 0x805DA0E8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805DA0EC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805DA0F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805DA0F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805DA0F8: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x805DA0FC: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x805DA100: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805DA104: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805DA108: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805DA10C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805DA110: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x805DA114: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x805DA118: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805DA11C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805DA120: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x805DA124: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805DA128: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x805DA12C: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x805DA130: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x805DA134: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x805DA138: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x805DA13C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x805DA140: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x805DA144: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x805DA148: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x805DA14C: jalr        $t9
    // 0x805DA150: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805DA150: nop

    after_0:
    // 0x805DA154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA158: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x805DA15C: jr          $ra
    // 0x805DA160: nop

    return;
    // 0x805DA160: nop

;}
RECOMP_FUNC void func_804343F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804343F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804343F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804343F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804343FC: jal         0x80433C0C
    // 0x80434400: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80433C0C(rdram, ctx);
        goto after_0;
    // 0x80434400: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80434404: jal         0x80433BD8
    // 0x80434408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80433BD8(rdram, ctx);
        goto after_1;
    // 0x80434408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043440C: jal         0x80433D20
    // 0x80434410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80433D20(rdram, ctx);
        goto after_2;
    // 0x80434410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80434414: jal         0x80433E8C
    // 0x80434418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80433E8C(rdram, ctx);
        goto after_3;
    // 0x80434418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043441C: jal         0x80434000
    // 0x80434420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434000(rdram, ctx);
        goto after_4;
    // 0x80434420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80434424: jal         0x80434164
    // 0x80434428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434164(rdram, ctx);
        goto after_5;
    // 0x80434428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8043442C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80434430: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80434434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80434438: jr          $ra
    // 0x8043443C: nop

    return;
    // 0x8043443C: nop

;}
RECOMP_FUNC void func_80437130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437130: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437134: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80437138: lwc1        $f6, 0x50($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8043713C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80437140: jr          $ra
    // 0x80437144: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80437144: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80068C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068C08: jal         0x80068B2C
    // 0x80068C0C: nop

    func_80068B2C(rdram, ctx);
        goto after_0;
    // 0x80068C0C: nop

    after_0:
    // 0x80068C10: bne         $v0, $zero, L_80068C20
    if (ctx->r2 != 0) {
        // 0x80068C14: lui         $v1, 0x800F
        ctx->r3 = S32(0X800F << 16);
            goto L_80068C20;
    }
    // 0x80068C14: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80068C18: b           L_80068C64
    // 0x80068C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80068C64;
    // 0x80068C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80068C20:
    // 0x80068C20: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80068C24: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x80068C28: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80068C2C: beq         $v0, $at, L_80068C40
    if (ctx->r2 == ctx->r1) {
        // 0x80068C30: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80068C40;
    }
    // 0x80068C30: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80068C34: beq         $v0, $at, L_80068C40
    if (ctx->r2 == ctx->r1) {
        // 0x80068C38: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80068C40;
    }
    // 0x80068C38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80068C3C: bne         $v0, $at, L_80068C54
    if (ctx->r2 != ctx->r1) {
        // 0x80068C40: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80068C54;
    }
L_80068C40:
    // 0x80068C40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80068C44: beq         $v0, $at, L_80068C54
    if (ctx->r2 == ctx->r1) {
        // 0x80068C48: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80068C54;
    }
    // 0x80068C48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068C4C: b           L_80068C58
    // 0x80068C50: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
        goto L_80068C58;
    // 0x80068C50: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
L_80068C54:
    // 0x80068C54: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
L_80068C58:
    // 0x80068C58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80068C5C: sw          $zero, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = 0;
    // 0x80068C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80068C64:
    // 0x80068C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068C68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068C6C: jr          $ra
    // 0x80068C70: nop

    return;
    // 0x80068C70: nop

;}
RECOMP_FUNC void func_80026AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026AB0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026AB4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80026AB8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80026ABC: lw          $v0, 0x60($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X60);
    // 0x80026AC0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80026AC4: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80026AC8: lw          $t7, -0x3A48($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3A48);
    // 0x80026ACC: sb          $zero, 0x158($a0)
    MEM_B(0X158, ctx->r4) = 0;
    // 0x80026AD0: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80026AD4: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
    // 0x80026AD8: lw          $t8, -0x3A40($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3A40);
    // 0x80026ADC: jr          $ra
    // 0x80026AE0: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    return;
    // 0x80026AE0: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8067AC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067AC38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067AC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067AC40: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8067AC44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8067AC48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067AC4C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8067AC50: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067AC54: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067AC58: lbu         $v1, 0x37($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X37);
    // 0x8067AC5C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8067AC60: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067AC64: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X2778) << 16);
    // 0x8067AC68: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8067AC6C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8067AC70: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x8067AC74: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8067AC78: beql        $v0, $zero, L_8067ACC8
    if (ctx->r2 == 0) {
        // 0x8067AC7C: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_8067ACC8;
    }
    goto skip_0;
    // 0x8067AC7C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8067AC80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067AC84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067AC88: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8067AC8C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8067AC90: nop

    // 0x8067AC94: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8067AC98: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8067AC9C: nop

    // 0x8067ACA0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8067ACA4: bne         $v0, $zero, L_8067ACBC
    if (ctx->r2 != 0) {
        // 0x8067ACA8: nop
    
            goto L_8067ACBC;
    }
    // 0x8067ACA8: nop

    // 0x8067ACAC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8067ACB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067ACB4: b           L_8067ACD4
    // 0x8067ACB8: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8067ACD4;
    // 0x8067ACB8: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8067ACBC:
    // 0x8067ACBC: b           L_8067ACD4
    // 0x8067ACC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8067ACD4;
    // 0x8067ACC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8067ACC4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_8067ACC8:
    // 0x8067ACC8: nop

    // 0x8067ACCC: bltz        $v0, L_8067ACBC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8067ACD0: nop
    
            goto L_8067ACBC;
    }
    // 0x8067ACD0: nop

L_8067ACD4:
    // 0x8067ACD4: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8067ACD8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8067ACDC: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x8067ACE0: beq         $at, $zero, L_8067AD3C
    if (ctx->r1 == 0) {
        // 0x8067ACE4: addiu       $v1, $v1, -0xD
        ctx->r3 = ADD32(ctx->r3, -0XD);
            goto L_8067AD3C;
    }
    // 0x8067ACE4: addiu       $v1, $v1, -0xD
    ctx->r3 = ADD32(ctx->r3, -0XD);
    // 0x8067ACE8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8067ACEC: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X2768) << 16);
    // 0x8067ACF0: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8067ACF4: lw          $t9, -0x3BE8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(541, 0X2768));
    // 0x8067ACF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8067ACFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8067AD00: jalr        $t9
    // 0x8067AD04: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8067AD04: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8067AD08: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8067AD0C: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2788) << 16);
    // 0x8067AD10: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8067AD14: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067AD18: lwc1        $f8, -0x3BC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2788));
    // 0x8067AD1C: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2798) << 16);
    // 0x8067AD20: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8067AD24: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8067AD28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067AD2C: bc1fl       L_8067AD8C
    if (!c1cs) {
        // 0x8067AD30: swc1        $f0, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
            goto L_8067AD8C;
    }
    goto skip_1;
    // 0x8067AD30: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    skip_1:
    // 0x8067AD34: b           L_8067AD88
    // 0x8067AD38: lwc1        $f0, -0x3BB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2798));
        goto L_8067AD88;
    // 0x8067AD38: lwc1        $f0, -0x3BB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2798));
L_8067AD3C:
    // 0x8067AD3C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8067AD40: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8067AD44: lw          $t9, -0x3BD8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(541, 0X2778));
    // 0x8067AD48: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8067AD4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8067AD50: jalr        $t9
    // 0x8067AD54: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8067AD54: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8067AD58: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8067AD5C: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X27A8) << 16);
    // 0x8067AD60: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8067AD64: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067AD68: lwc1        $f10, -0x3BA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X27A8));
    // 0x8067AD6C: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X27B8) << 16);
    // 0x8067AD70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8067AD74: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8067AD78: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8067AD7C: bc1fl       L_8067AD8C
    if (!c1cs) {
        // 0x8067AD80: swc1        $f0, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
            goto L_8067AD8C;
    }
    goto skip_2;
    // 0x8067AD80: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    skip_2:
    // 0x8067AD84: lwc1        $f0, -0x3B98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X27B8));
L_8067AD88:
    // 0x8067AD88: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
L_8067AD8C:
    // 0x8067AD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067AD90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8067AD94: jr          $ra
    // 0x8067AD98: nop

    return;
    // 0x8067AD98: nop

;}
RECOMP_FUNC void func_80024A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024A74: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80024A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024A7C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024A80: lw          $a1, 0x1F4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X1F4);
    // 0x80024A84: beq         $a1, $zero, L_80024C00
    if (ctx->r5 == 0) {
        // 0x80024A88: nop
    
            goto L_80024C00;
    }
    // 0x80024A88: nop

    // 0x80024A8C: lw          $v0, 0x1F0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F0);
    // 0x80024A90: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80024A94: lwc1        $f16, 0x68($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80024A98: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80024A9C: lwc1        $f8, 0x88($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X88);
    // 0x80024AA0: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80024AA4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80024AA8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80024AAC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80024AB0: mul.s       $f14, $f16, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80024AB4: jal         0x80081E8C
    // 0x80024AB8: nop

    fatan2(rdram, ctx);
        goto after_0;
    // 0x80024AB8: nop

    after_0:
    // 0x80024ABC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80024AC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80024AC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80024AC8: lwc1        $f6, -0x280($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X280);
    // 0x80024ACC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80024AD0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80024AD4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80024AD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024ADC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80024AE0: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024AE4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80024AE8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80024AEC: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80024AF0: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x80024AF4: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x80024AF8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80024AFC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80024B00: bgez        $v1, L_80024B14
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80024B04: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80024B14;
    }
    // 0x80024B04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80024B08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80024B0C: nop

    // 0x80024B10: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80024B14:
    // 0x80024B14: div.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80024B18: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80024B1C: bgez        $v0, L_80024B30
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80024B20: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80024B30;
    }
    // 0x80024B20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80024B24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80024B28: nop

    // 0x80024B2C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80024B30:
    // 0x80024B30: mul.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80024B34: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80024B38: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80024B3C: jal         0x80065954
    // 0x80024B40: sub.s       $f12, $f2, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f18.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80024B40: sub.s       $f12, $f2, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f18.fl;
    after_1:
    // 0x80024B44: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80024B48: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80024B4C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80024B50: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x80024B54: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80024B58: bc1fl       L_80024C0C
    if (!c1cs) {
        // 0x80024B5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80024C0C;
    }
    goto skip_0;
    // 0x80024B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80024B60: div.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80024B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024B68: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80024B6C: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80024B70: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80024B74: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024B78: nop

    // 0x80024B7C: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80024B80: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024B84: nop

    // 0x80024B88: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80024B8C: beql        $v0, $zero, L_80024BDC
    if (ctx->r2 == 0) {
        // 0x80024B90: mfc1        $v0, $f4
        ctx->r2 = (int32_t)ctx->f4.u32l;
            goto L_80024BDC;
    }
    goto skip_1;
    // 0x80024B90: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x80024B94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80024B98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024B9C: sub.s       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80024BA0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024BA4: nop

    // 0x80024BA8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80024BAC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024BB0: nop

    // 0x80024BB4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80024BB8: bne         $v0, $zero, L_80024BD0
    if (ctx->r2 != 0) {
        // 0x80024BBC: nop
    
            goto L_80024BD0;
    }
    // 0x80024BBC: nop

    // 0x80024BC0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80024BC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024BC8: b           L_80024BE8
    // 0x80024BCC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80024BE8;
    // 0x80024BCC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80024BD0:
    // 0x80024BD0: b           L_80024BE8
    // 0x80024BD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80024BE8;
    // 0x80024BD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80024BD8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
L_80024BDC:
    // 0x80024BDC: nop

    // 0x80024BE0: bltz        $v0, L_80024BD0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80024BE4: nop
    
            goto L_80024BD0;
    }
    // 0x80024BE4: nop

L_80024BE8:
    // 0x80024BE8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80024BEC: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80024BF0: bne         $at, $zero, L_80024C08
    if (ctx->r1 != 0) {
        // 0x80024BF4: sw          $v0, 0x14C($a0)
        MEM_W(0X14C, ctx->r4) = ctx->r2;
            goto L_80024C08;
    }
    // 0x80024BF4: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
    // 0x80024BF8: b           L_80024C08
    // 0x80024BFC: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
        goto L_80024C08;
    // 0x80024BFC: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
L_80024C00:
    // 0x80024C00: jal         0x8002491C
    // 0x80024C04: nop

    func_8002491C(rdram, ctx);
        goto after_2;
    // 0x80024C04: nop

    after_2:
L_80024C08:
    // 0x80024C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80024C0C:
    // 0x80024C0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80024C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024C14: jr          $ra
    // 0x80024C18: nop

    return;
    // 0x80024C18: nop

;}
RECOMP_FUNC void func_806FD854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD854: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FD858: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806FD85C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(706, 0X12BC) << 16);
    // 0x806FD860: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806FD864: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806FD868: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806FD86C: nop

    // 0x806FD870: bc1fl       L_806FD8B0
    if (!c1cs) {
        // 0x806FD874: lwc1        $f0, 0x4($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806FD8B0;
    }
    goto skip_0;
    // 0x806FD874: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x806FD878: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806FD87C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(706, 0X12B4) << 16);
    // 0x806FD880: lwc1        $f8, -0x18EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(706, 0X12B4));
    // 0x806FD884: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806FD888: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(706, 0X12B8) << 16);
    // 0x806FD88C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806FD890: nop

    // 0x806FD894: bc1f        L_806FD8D4
    if (!c1cs) {
        // 0x806FD898: nop
    
            goto L_806FD8D4;
    }
    // 0x806FD898: nop

    // 0x806FD89C: lwc1        $f10, -0x18E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(706, 0X12B8));
    // 0x806FD8A0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x806FD8A4: jr          $ra
    // 0x806FD8A8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x806FD8A8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x806FD8AC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_806FD8B0:
    // 0x806FD8B0: lwc1        $f18, -0x18E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(706, 0X12BC));
    // 0x806FD8B4: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(706, 0X12C0) << 16);
    // 0x806FD8B8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x806FD8BC: nop

    // 0x806FD8C0: bc1f        L_806FD8D4
    if (!c1cs) {
        // 0x806FD8C4: nop
    
            goto L_806FD8D4;
    }
    // 0x806FD8C4: nop

    // 0x806FD8C8: lwc1        $f4, -0x18E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(706, 0X12C0));
    // 0x806FD8CC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x806FD8D0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_806FD8D4:
    // 0x806FD8D4: jr          $ra
    // 0x806FD8D8: nop

    return;
    // 0x806FD8D8: nop

;}
RECOMP_FUNC void func_80039368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039368: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8003936C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80039370: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80039374: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x80039378: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8003937C: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x80039380: nop

    // 0x80039384: bc1fl       L_800393B0
    if (!c1cs) {
        // 0x80039388: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800393B0;
    }
    goto skip_0;
    // 0x80039388: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x8003938C: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80039390: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80039394: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x80039398: nop

    // 0x8003939C: bc1fl       L_800393B0
    if (!c1cs) {
        // 0x800393A0: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800393B0;
    }
    goto skip_1;
    // 0x800393A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x800393A4: jr          $ra
    // 0x800393A8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800393A8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800393AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800393B0:
    // 0x800393B0: nop

    // 0x800393B4: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800393B8: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800393BC: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800393C0: jr          $ra
    // 0x800393C4: nop

    return;
    // 0x800393C4: nop

;}
RECOMP_FUNC void func_8006D6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D6B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D6B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D6BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006D6C0: jal         0x8006D5F0
    // 0x8006D6C4: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    func_8006D5F0(rdram, ctx);
        goto after_0;
    // 0x8006D6C4: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    after_0:
    // 0x8006D6C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006D6CC: jal         0x8006D630
    // 0x8006D6D0: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_8006D630(rdram, ctx);
        goto after_1;
    // 0x8006D6D0: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_1:
    // 0x8006D6D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D6D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D6DC: jr          $ra
    // 0x8006D6E0: nop

    return;
    // 0x8006D6E0: nop

;}
RECOMP_FUNC void func_806A79C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A79C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A79C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806A79C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A79CC: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(586, 0X4F0) << 16);
    // 0x806A79D0: lui         $a1, 0x806A
    ctx->r5 = S32(RELOC_HI16(586, 0X500) << 16);
    // 0x806A79D4: addiu       $a1, $a1, 0x7EC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(586, 0X500));
    // 0x806A79D8: addiu       $a0, $a0, 0x7EB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(586, 0X4F0));
    // 0x806A79DC: jal         0x8004667C
    // 0x806A79E0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x806A79E0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x806A79E4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806A79E8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806A79EC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x806A79F0: lui         $a2, 0x806A
    ctx->r6 = S32(RELOC_HI16(586, 0X374) << 16);
    // 0x806A79F4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x806A79F8: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x806A79FC: bnel        $t7, $zero, L_806A7A10
    if (ctx->r15 != 0) {
        // 0x806A7A00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806A7A10;
    }
    goto skip_0;
    // 0x806A7A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806A7A04: jal         0x80057B28
    // 0x806A7A08: addiu       $a2, $a2, 0x7D34
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(586, 0X374));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x806A7A08: addiu       $a2, $a2, 0x7D34
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(586, 0X374));
    after_1:
    // 0x806A7A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806A7A10:
    // 0x806A7A10: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(586, 0X60) << 16);
    // 0x806A7A14: addiu       $v0, $v0, 0x7A20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(586, 0X60));
    // 0x806A7A18: jr          $ra
    // 0x806A7A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806A7A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805A058C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A058C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A0590: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805A0594: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805A0598: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x805A059C: lui         $t7, 0x805A
    ctx->r15 = S32(RELOC_HI16(408, 0X1CCC) << 16);
    // 0x805A05A0: addiu       $t7, $t7, 0x102C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(408, 0X1CCC));
    // 0x805A05A4: addiu       $t6, $v0, 0xD
    ctx->r14 = ADD32(ctx->r2, 0XD);
    // 0x805A05A8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x805A05AC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A05B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805A05B4: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(408, 0XBB0) << 16);
    // 0x805A05B8: addiu       $t8, $t8, -0xF0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(408, 0XBB0));
    // 0x805A05BC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A05C0: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x805A05C4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805A05C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805A05CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A05D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A05D4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x805A05D8: jal         0x80045A34
    // 0x805A05DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805A05DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x805A05E0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805A05E4: lui         $t0, 0x805A
    ctx->r8 = S32(RELOC_HI16(408, 0XE48) << 16);
    // 0x805A05E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x805A05EC: addiu       $t0, $t0, 0x1A8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(408, 0XE48));
    // 0x805A05F0: sw          $t0, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r8;
    // 0x805A05F4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x805A05F8: lui         $t2, 0x805A
    ctx->r10 = S32(RELOC_HI16(408, 0X1CD4) << 16);
    // 0x805A05FC: addiu       $t2, $t2, 0x1034
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(408, 0X1CD4));
    // 0x805A0600: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x805A0604: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x805A0608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A060C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x805A0610: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x805A0614: jal         0x80054530
    // 0x805A0618: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_80054530(rdram, ctx);
        goto after_1;
    // 0x805A0618: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x805A061C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x805A0620: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A0624: bne         $v0, $zero, L_805A0634
    if (ctx->r2 != 0) {
        // 0x805A0628: sw          $v0, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r2;
            goto L_805A0634;
    }
    // 0x805A0628: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x805A062C: b           L_805A0644
    // 0x805A0630: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
        goto L_805A0644;
    // 0x805A0630: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
L_805A0634:
    // 0x805A0634: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x805A0638: lui         $t5, 0x805A
    ctx->r13 = S32(RELOC_HI16(408, 0XE74) << 16);
    // 0x805A063C: addiu       $t5, $t5, 0x1D4
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(408, 0XE74));
    // 0x805A0640: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
L_805A0644:
    // 0x805A0644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805A0648: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805A064C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A0650: jr          $ra
    // 0x805A0654: nop

    return;
    // 0x805A0654: nop

;}
RECOMP_FUNC void func_807B7E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B7E18: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x807B7E1C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x807B7E20: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(883, 0X594) << 16);
    // 0x807B7E24: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x807B7E28: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x807B7E2C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x807B7E30: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x807B7E34: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x807B7E38: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x807B7E3C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x807B7E40: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x807B7E44: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x807B7E48: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807B7E4C: lwc1        $f24, -0x7E2C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(883, 0X594));
    // 0x807B7E50: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B7E54: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(883, 0X598) << 16);
    // 0x807B7E58: lwc1        $f22, -0x7E28($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(883, 0X598));
    // 0x807B7E5C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(883, 0X59C) << 16);
    // 0x807B7E60: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x807B7E64: lwc1        $f20, -0x7E24($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(883, 0X59C));
    // 0x807B7E68: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B7E6C: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    // 0x807B7E70: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x807B7E74: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_807B7E78:
    // 0x807B7E78: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x807B7E7C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B7E80: beql        $s0, $zero, L_807B7F10
    if (ctx->r16 == 0) {
        // 0x807B7E84: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_807B7F10;
    }
    goto skip_0;
    // 0x807B7E84: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x807B7E88: jal         0x80047EB0
    // 0x807B7E8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047EB0(rdram, ctx);
        goto after_0;
    // 0x807B7E8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x807B7E90: beq         $v0, $zero, L_807B7F0C
    if (ctx->r2 == 0) {
        // 0x807B7E94: sll         $t6, $s2, 1
        ctx->r14 = S32(ctx->r18 << 1);
            goto L_807B7F0C;
    }
    // 0x807B7E94: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    // 0x807B7E98: addu        $v0, $s3, $t6
    ctx->r2 = ADD32(ctx->r19, ctx->r14);
    // 0x807B7E9C: lh          $v1, 0x28($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X28);
    // 0x807B7EA0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x807B7EA4: bne         $at, $zero, L_807B7EF8
    if (ctx->r1 != 0) {
        // 0x807B7EA8: nop
    
            goto L_807B7EF8;
    }
    // 0x807B7EA8: nop

    // 0x807B7EAC: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x807B7EB0: lwc1        $f4, 0x34($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X34);
    // 0x807B7EB4: sub.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x807B7EB8: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x807B7EBC: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x807B7EC0: swc1        $f16, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f16.u32l;
    // 0x807B7EC4: lwc1        $f18, 0x34($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X34);
    // 0x807B7EC8: mul.s       $f6, $f18, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x807B7ECC: swc1        $f6, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f6.u32l;
    // 0x807B7ED0: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x807B7ED4: lwc1        $f8, 0x34($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X34);
    // 0x807B7ED8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x807B7EDC: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    // 0x807B7EE0: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x807B7EE4: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    // 0x807B7EE8: lh          $t7, 0x28($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X28);
    // 0x807B7EEC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x807B7EF0: b           L_807B7F0C
    // 0x807B7EF4: sh          $t8, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r24;
        goto L_807B7F0C;
    // 0x807B7EF4: sh          $t8, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r24;
L_807B7EF8:
    // 0x807B7EF8: bnel        $s6, $v1, L_807B7F10
    if (ctx->r22 != ctx->r3) {
        // 0x807B7EFC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_807B7F10;
    }
    goto skip_1;
    // 0x807B7EFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x807B7F00: swc1        $f20, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
    // 0x807B7F04: swc1        $f20, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f20.u32l;
    // 0x807B7F08: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
L_807B7F0C:
    // 0x807B7F0C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_807B7F10:
    // 0x807B7F10: bne         $s2, $s5, L_807B7E78
    if (ctx->r18 != ctx->r21) {
        // 0x807B7F14: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_807B7E78;
    }
    // 0x807B7F14: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807B7F18: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x807B7F1C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807B7F20: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x807B7F24: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x807B7F28: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x807B7F2C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x807B7F30: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x807B7F34: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x807B7F38: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x807B7F3C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x807B7F40: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x807B7F44: jr          $ra
    // 0x807B7F48: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x807B7F48: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80020F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F24: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80020F28: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x80020F2C: beql        $t7, $zero, L_80020F48
    if (ctx->r15 == 0) {
        // 0x80020F30: lw          $t0, 0x4($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X4);
            goto L_80020F48;
    }
    goto skip_0;
    // 0x80020F30: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x80020F34: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80020F38: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80020F3C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80020F40: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x80020F44: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
L_80020F48:
    // 0x80020F48: lbu         $t1, 0x14($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X14);
    // 0x80020F4C: beql        $t1, $zero, L_80020F68
    if (ctx->r9 == 0) {
        // 0x80020F50: lw          $t4, 0x8($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X8);
            goto L_80020F68;
    }
    goto skip_1;
    // 0x80020F50: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    skip_1:
    // 0x80020F54: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80020F58: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80020F5C: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80020F60: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
    // 0x80020F64: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
L_80020F68:
    // 0x80020F68: lbu         $t5, 0x14($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X14);
    // 0x80020F6C: beq         $t5, $zero, L_80020F84
    if (ctx->r13 == 0) {
        // 0x80020F70: nop
    
            goto L_80020F84;
    }
    // 0x80020F70: nop

    // 0x80020F74: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80020F78: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80020F7C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80020F80: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
L_80020F84:
    // 0x80020F84: jr          $ra
    // 0x80020F88: nop

    return;
    // 0x80020F88: nop

;}
RECOMP_FUNC void func_8003776C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003776C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80037770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80037778: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003777C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80037780: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037784: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037788: lbu         $t6, 0x1F8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1F8);
    // 0x8003778C: beq         $t6, $zero, L_800377E4
    if (ctx->r14 == 0) {
        // 0x80037790: nop
    
            goto L_800377E4;
    }
    // 0x80037790: nop

    // 0x80037794: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80037798: lwc1        $f4, 0x104($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X104);
    // 0x8003779C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800377A0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800377A4: nop

    // 0x800377A8: bc1t        L_800377E4
    if (c1cs) {
        // 0x800377AC: nop
    
            goto L_800377E4;
    }
    // 0x800377AC: nop

    // 0x800377B0: lwc1        $f6, 0x108($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X108);
    // 0x800377B4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800377B8: nop

    // 0x800377BC: bc1t        L_800377E4
    if (c1cs) {
        // 0x800377C0: nop
    
            goto L_800377E4;
    }
    // 0x800377C0: nop

    // 0x800377C4: jal         0x80040E24
    // 0x800377C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80040E24(rdram, ctx);
        goto after_0;
    // 0x800377C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800377CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800377D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800377D4: jal         0x8004115C
    // 0x800377D8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004115C(rdram, ctx);
        goto after_1;
    // 0x800377D8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800377DC: b           L_800378FC
    // 0x800377E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800378FC;
    // 0x800377E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800377E4:
    // 0x800377E4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800377E8: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    // 0x800377EC: jal         0x8006593C
    // 0x800377F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8006593C(rdram, ctx);
        goto after_2;
    // 0x800377F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x800377F4: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800377F8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800377FC: beq         $t8, $zero, L_80037880
    if (ctx->r24 == 0) {
        // 0x80037800: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80037880;
    }
    // 0x80037800: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80037804: lw          $t9, 0x78($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X78);
    // 0x80037808: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8003780C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80037810: beq         $t9, $zero, L_800378F8
    if (ctx->r25 == 0) {
        // 0x80037814: nop
    
            goto L_800378F8;
    }
    // 0x80037814: nop

    // 0x80037818: lbu         $t0, -0x7684($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X7684);
    // 0x8003781C: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x80037820: bnel        $t0, $t1, L_80037848
    if (ctx->r8 != ctx->r9) {
        // 0x80037824: lw          $t2, 0x12EC($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X12EC);
            goto L_80037848;
    }
    goto skip_0;
    // 0x80037824: lw          $t2, 0x12EC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X12EC);
    skip_0:
    // 0x80037828: jal         0x80040CE0
    // 0x8003782C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040CE0(rdram, ctx);
        goto after_3;
    // 0x8003782C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80037830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037834: jal         0x80040E24
    // 0x80037838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80040E24(rdram, ctx);
        goto after_4;
    // 0x80037838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8003783C: b           L_8003786C
    // 0x80037840: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8003786C;
    // 0x80037840: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80037844: lw          $t2, 0x12EC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X12EC);
L_80037848:
    // 0x80037848: beq         $t2, $zero, L_80037860
    if (ctx->r10 == 0) {
        // 0x8003784C: nop
    
            goto L_80037860;
    }
    // 0x8003784C: nop

    // 0x80037850: jal         0x80040CE0
    // 0x80037854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040CE0(rdram, ctx);
        goto after_5;
    // 0x80037854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80037858: b           L_8003786C
    // 0x8003785C: addiu       $a1, $v0, 0xB
    ctx->r5 = ADD32(ctx->r2, 0XB);
        goto L_8003786C;
    // 0x8003785C: addiu       $a1, $v0, 0xB
    ctx->r5 = ADD32(ctx->r2, 0XB);
L_80037860:
    // 0x80037860: jal         0x80040F5C
    // 0x80037864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040F5C(rdram, ctx);
        goto after_6;
    // 0x80037864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80037868: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8003786C:
    // 0x8003786C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037870: jal         0x8004115C
    // 0x80037874: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004115C(rdram, ctx);
        goto after_7;
    // 0x80037874: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80037878: b           L_800378FC
    // 0x8003787C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800378FC;
    // 0x8003787C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037880:
    // 0x80037880: lwc1        $f8, 0x10C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80037884: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80037888: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003788C: lwc1        $f16, 0x10C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X10C);
    // 0x80037890: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80037894: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003789C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x800378A0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800378A4: nop

    // 0x800378A8: bc1t        L_800378E8
    if (c1cs) {
        // 0x800378AC: nop
    
            goto L_800378E8;
    }
    // 0x800378AC: nop

    // 0x800378B0: lwc1        $f18, 0x110($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X110);
    // 0x800378B4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800378B8: nop

    // 0x800378BC: bc1t        L_800378E8
    if (c1cs) {
        // 0x800378C0: nop
    
            goto L_800378E8;
    }
    // 0x800378C0: nop

    // 0x800378C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800378C8: jal         0x80040E24
    // 0x800378CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80040E24(rdram, ctx);
        goto after_8;
    // 0x800378CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800378D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800378D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800378D8: jal         0x8004115C
    // 0x800378DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004115C(rdram, ctx);
        goto after_9;
    // 0x800378DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x800378E0: b           L_800378FC
    // 0x800378E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800378FC;
    // 0x800378E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800378E8:
    // 0x800378E8: jal         0x8004115C
    // 0x800378EC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8004115C(rdram, ctx);
        goto after_10;
    // 0x800378EC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x800378F0: b           L_800378FC
    // 0x800378F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800378FC;
    // 0x800378F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800378F8:
    // 0x800378F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800378FC:
    // 0x800378FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80037904: jr          $ra
    // 0x80037908: nop

    return;
    // 0x80037908: nop

;}
RECOMP_FUNC void func_8069E4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069E4E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069E4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069E4F0: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8069E4F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8069E4F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8069E4FC: beq         $a1, $at, L_8069E518
    if (ctx->r5 == ctx->r1) {
        // 0x8069E500: addiu       $a0, $zero, 0x25
        ctx->r4 = ADD32(0, 0X25);
            goto L_8069E518;
    }
    // 0x8069E500: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8069E504: jal         0x80067878
    // 0x8069E508: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8069E508: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8069E50C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8069E510: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8069E514: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8069E518:
    // 0x8069E518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069E51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069E520: jr          $ra
    // 0x8069E524: nop

    return;
    // 0x8069E524: nop

;}
RECOMP_FUNC void func_800213EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800213EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800213F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800213F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800213F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800213FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80021400: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80021404: jal         0x80049C70
    // 0x80021408: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_80049C70(rdram, ctx);
        goto after_0;
    // 0x80021408: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_0:
    // 0x8002140C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80021410: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021414: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80021418: jal         0x80049C70
    // 0x8002141C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80049C70(rdram, ctx);
        goto after_1;
    // 0x8002141C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80021420: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80021424: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021428: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8002142C: jal         0x80049C70
    // 0x80021430: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80049C70(rdram, ctx);
        goto after_2;
    // 0x80021430: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80021434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002143C: jr          $ra
    // 0x80021440: nop

    return;
    // 0x80021440: nop

;}
