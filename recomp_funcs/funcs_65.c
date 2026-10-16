#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8003D6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D6E4: lw          $v0, 0x160($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X160);
    // 0x8003D6E8: lw          $v1, 0x15C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X15C);
    // 0x8003D6EC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8003D6F0: sb          $a3, 0x159($a1)
    MEM_B(0X159, ctx->r5) = ctx->r7;
    // 0x8003D6F4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003D6F8: sb          $a3, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r7;
    // 0x8003D6FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D700: addiu       $t6, $t6, -0x29E4
    ctx->r14 = ADD32(ctx->r14, -0X29E4);
    // 0x8003D704: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003D708: addiu       $t7, $t7, -0x2AB4
    ctx->r15 = ADD32(ctx->r15, -0X2AB4);
    // 0x8003D70C: sb          $a3, 0x17C($v1)
    MEM_B(0X17C, ctx->r3) = ctx->r7;
    // 0x8003D710: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x8003D714: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x8003D718: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x8003D71C: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x8003D720: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x8003D724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D728: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003D72C: bnel        $t8, $zero, L_8003D73C
    if (ctx->r24 != 0) {
        // 0x8003D730: sw          $a2, 0x138($v0)
        MEM_W(0X138, ctx->r2) = ctx->r6;
            goto L_8003D73C;
    }
    goto skip_0;
    // 0x8003D730: sw          $a2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r6;
    skip_0:
    // 0x8003D734: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D738: sw          $a2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r6;
L_8003D73C:
    // 0x8003D73C: sw          $a2, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r6;
    // 0x8003D740: sb          $t9, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r25;
    // 0x8003D744: lw          $t0, 0x1F4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1F4);
    // 0x8003D748: sb          $t9, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r25;
    // 0x8003D74C: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003D750: lw          $t1, 0x1F4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003D754: sb          $t9, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r25;
    // 0x8003D758: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8003D75C: lw          $t4, 0x174($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X174);
    // 0x8003D760: lbu         $t3, 0x10($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X10);
    // 0x8003D764: jr          $ra
    // 0x8003D768: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
    return;
    // 0x8003D768: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
;}
RECOMP_FUNC void func_806E4144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E4144: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806E4148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E414C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E4150: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(649, 0X2118) << 16);
    // 0x806E4154: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806E4158: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x806E415C: addiu       $t7, $t7, 0x5918
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(649, 0X2118));
    // 0x806E4160: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x806E4164: bgezl       $v1, L_806E4174
    if (SIGNED(ctx->r3) >= 0) {
        // 0x806E4168: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_806E4174;
    }
    goto skip_0;
    // 0x806E4168: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    skip_0:
    // 0x806E416C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806E4170: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_806E4174:
    // 0x806E4174: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x806E4178: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806E417C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x806E4180: jal         0x80066E88
    // 0x806E4184: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x806E4184: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_0:
    // 0x806E4188: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x806E418C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x806E4190: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806E4194: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x806E4198: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x806E419C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x806E41A0: jal         0x80066DE4
    // 0x806E41A4: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x806E41A4: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_1:
    // 0x806E41A8: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x806E41AC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806E41B0: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x806E41B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E41B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806E41BC: jr          $ra
    // 0x806E41C0: nop

    return;
    // 0x806E41C0: nop

;}
RECOMP_FUNC void func_80049FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049FD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049FD8: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x80049FDC: jal         0x80049F68
    // 0x80049FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80049F68(rdram, ctx);
        goto after_0;
    // 0x80049FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80049FE4: jal         0x8004E8DC
    // 0x80049FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8004E8DC(rdram, ctx);
        goto after_1;
    // 0x80049FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80049FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049FF4: jr          $ra
    // 0x80049FF8: nop

    return;
    // 0x80049FF8: nop

;}
RECOMP_FUNC void func_800699BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800699BC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800699C0: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x800699C4: addiu       $a1, $a0, 0x2
    ctx->r5 = ADD32(ctx->r4, 0X2);
    // 0x800699C8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800699CC: srl         $t7, $v1, 16
    ctx->r15 = S32(U32(ctx->r3) >> 16);
    // 0x800699D0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800699D4: andi        $t6, $v1, 0xFFFE
    ctx->r14 = ctx->r3 & 0XFFFE;
    // 0x800699D8: or          $v1, $t6, $t8
    ctx->r3 = ctx->r14 | ctx->r24;
    // 0x800699DC: xor         $v1, $v1, $t9
    ctx->r3 = ctx->r3 ^ ctx->r25;
    // 0x800699E0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800699E4: srl         $t1, $v1, 16
    ctx->r9 = S32(U32(ctx->r3) >> 16);
    // 0x800699E8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800699EC: andi        $t0, $v1, 0xFFFE
    ctx->r8 = ctx->r3 & 0XFFFE;
    // 0x800699F0: or          $v1, $t0, $t2
    ctx->r3 = ctx->r8 | ctx->r10;
    // 0x800699F4: addiu       $a0, $zero, 0x3FA
    ctx->r4 = ADD32(0, 0X3FA);
    // 0x800699F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800699FC:
    // 0x800699FC: lbu         $t3, 0x0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X0);
    // 0x80069A00: lbu         $t6, 0x1($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1);
    // 0x80069A04: lbu         $t0, 0x2($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2);
    // 0x80069A08: xor         $v1, $v1, $t3
    ctx->r3 = ctx->r3 ^ ctx->r11;
    // 0x80069A0C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80069A10: srl         $t5, $v1, 16
    ctx->r13 = S32(U32(ctx->r3) >> 16);
    // 0x80069A14: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80069A18: andi        $t4, $v1, 0xFFFE
    ctx->r12 = ctx->r3 & 0XFFFE;
    // 0x80069A1C: or          $v1, $t4, $t7
    ctx->r3 = ctx->r12 | ctx->r15;
    // 0x80069A20: xor         $v1, $v1, $t6
    ctx->r3 = ctx->r3 ^ ctx->r14;
    // 0x80069A24: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80069A28: srl         $t9, $v1, 16
    ctx->r25 = S32(U32(ctx->r3) >> 16);
    // 0x80069A2C: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x80069A30: andi        $t8, $v1, 0xFFFE
    ctx->r24 = ctx->r3 & 0XFFFE;
    // 0x80069A34: or          $v1, $t8, $t1
    ctx->r3 = ctx->r24 | ctx->r9;
    // 0x80069A38: xor         $v1, $v1, $t0
    ctx->r3 = ctx->r3 ^ ctx->r8;
    // 0x80069A3C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80069A40: lbu         $t4, 0x3($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X3);
    // 0x80069A44: srl         $t3, $v1, 16
    ctx->r11 = S32(U32(ctx->r3) >> 16);
    // 0x80069A48: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x80069A4C: andi        $t2, $v1, 0xFFFE
    ctx->r10 = ctx->r3 & 0XFFFE;
    // 0x80069A50: or          $v1, $t2, $t5
    ctx->r3 = ctx->r10 | ctx->r13;
    // 0x80069A54: xor         $v1, $v1, $t4
    ctx->r3 = ctx->r3 ^ ctx->r12;
    // 0x80069A58: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80069A5C: srl         $t6, $v1, 16
    ctx->r14 = S32(U32(ctx->r3) >> 16);
    // 0x80069A60: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x80069A64: andi        $t7, $v1, 0xFFFE
    ctx->r15 = ctx->r3 & 0XFFFE;
    // 0x80069A68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80069A6C: or          $v1, $t7, $t9
    ctx->r3 = ctx->r15 | ctx->r25;
    // 0x80069A70: bne         $v0, $a0, L_800699FC
    if (ctx->r2 != ctx->r4) {
        // 0x80069A74: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800699FC;
    }
    // 0x80069A74: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80069A78: jr          $ra
    // 0x80069A7C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // 0x80069A7C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
;}
RECOMP_FUNC void func_8003DBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DBDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DBE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DBE4: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8003DBE8: addiu       $t7, $t6, -0xA
    ctx->r15 = ADD32(ctx->r14, -0XA);
    // 0x8003DBEC: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x8003DBF0: beq         $at, $zero, L_8003DC08
    if (ctx->r1 == 0) {
        // 0x8003DBF4: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8003DC08;
    }
    // 0x8003DBF4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8003DBF8: jal         0x8003DAB8
    // 0x8003DBFC: nop

    func_8003DAB8(rdram, ctx);
        goto after_0;
    // 0x8003DBFC: nop

    after_0:
    // 0x8003DC00: b           L_8003DC6C
    // 0x8003DC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003DC6C;
    // 0x8003DC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DC08:
    // 0x8003DC08: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003DC0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003DC10: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003DC14: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8003DC18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003DC1C: nop

    // 0x8003DC20: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8003DC24: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8003DC28: nop

    // 0x8003DC2C: bc1fl       L_8003DC4C
    if (!c1cs) {
        // 0x8003DC30: swc1        $f0, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
            goto L_8003DC4C;
    }
    goto skip_0;
    // 0x8003DC30: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x8003DC34: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8003DC38:
    // 0x8003DC38: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8003DC3C: nop

    // 0x8003DC40: bc1tl       L_8003DC38
    if (c1cs) {
        // 0x8003DC44: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8003DC38;
    }
    goto skip_1;
    // 0x8003DC44: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x8003DC48: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_8003DC4C:
    // 0x8003DC4C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8003DC50: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8003DC54: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8003DC58: jal         0x80065ABC
    // 0x8003DC5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8003DC5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003DC60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DC64: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8003DC68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DC6C:
    // 0x8003DC6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DC70: jr          $ra
    // 0x8003DC74: nop

    return;
    // 0x8003DC74: nop

;}
RECOMP_FUNC void func_8007910C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007910C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80079110: jr          $ra
    // 0x80079114: nop

    return;
    // 0x80079114: nop

;}
RECOMP_FUNC void func_804CC7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC7EC: jr          $ra
    // 0x804CC7F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804CC7F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8057EE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057EE10: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8057EE14: slti        $at, $v0, 0x4505
    ctx->r1 = SIGNED(ctx->r2) < 0X4505 ? 1 : 0;
    // 0x8057EE18: bne         $at, $zero, L_8057EE38
    if (ctx->r1 != 0) {
        // 0x8057EE1C: addiu       $at, $zero, 0x4505
        ctx->r1 = ADD32(0, 0X4505);
            goto L_8057EE38;
    }
    // 0x8057EE1C: addiu       $at, $zero, 0x4505
    ctx->r1 = ADD32(0, 0X4505);
    // 0x8057EE20: beq         $v0, $at, L_8057EE78
    if (ctx->r2 == ctx->r1) {
        // 0x8057EE24: addiu       $at, $zero, 0x4710
        ctx->r1 = ADD32(0, 0X4710);
            goto L_8057EE78;
    }
    // 0x8057EE24: addiu       $at, $zero, 0x4710
    ctx->r1 = ADD32(0, 0X4710);
    // 0x8057EE28: beq         $v0, $at, L_8057EE9C
    if (ctx->r2 == ctx->r1) {
        // 0x8057EE2C: nop
    
            goto L_8057EE9C;
    }
    // 0x8057EE2C: nop

    // 0x8057EE30: b           L_8057EF0C
    // 0x8057EE34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8057EF0C;
    // 0x8057EE34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057EE38:
    // 0x8057EE38: slti        $at, $v0, 0x40F9
    ctx->r1 = SIGNED(ctx->r2) < 0X40F9 ? 1 : 0;
    // 0x8057EE3C: bne         $at, $zero, L_8057EE58
    if (ctx->r1 != 0) {
        // 0x8057EE40: addiu       $t6, $v0, -0x40ED
        ctx->r14 = ADD32(ctx->r2, -0X40ED);
            goto L_8057EE58;
    }
    // 0x8057EE40: addiu       $t6, $v0, -0x40ED
    ctx->r14 = ADD32(ctx->r2, -0X40ED);
    // 0x8057EE44: addiu       $at, $zero, 0x4504
    ctx->r1 = ADD32(0, 0X4504);
    // 0x8057EE48: beq         $v0, $at, L_8057EE84
    if (ctx->r2 == ctx->r1) {
        // 0x8057EE4C: nop
    
            goto L_8057EE84;
    }
    // 0x8057EE4C: nop

    // 0x8057EE50: b           L_8057EF0C
    // 0x8057EE54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8057EF0C;
    // 0x8057EE54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057EE58:
    // 0x8057EE58: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x8057EE5C: beq         $at, $zero, L_8057EF08
    if (ctx->r1 == 0) {
        // 0x8057EE60: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8057EF08;
    }
    // 0x8057EE60: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8057EE64: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X4798) << 16);
    // 0x8057EE68: addu        $at, $at, $t6
    gpr jr_addend_8057EE70 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8057EE6C: lw          $t6, 0x35A8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(399, 0X4798));
    // 0x8057EE70: jr          $t6
    // 0x8057EE74: nop

    switch (jr_addend_8057EE70 >> 2) {
        case 0: goto L_8057EE90; break;
        case 1: goto L_8057EE9C; break;
        case 2: goto L_8057EEA8; break;
        case 3: goto L_8057EEB4; break;
        case 4: goto L_8057EF08; break;
        case 5: goto L_8057EF08; break;
        case 6: goto L_8057EEC0; break;
        case 7: goto L_8057EECC; break;
        case 8: goto L_8057EED8; break;
        case 9: goto L_8057EEE4; break;
        case 10: goto L_8057EEFC; break;
        case 11: goto L_8057EEF0; break;
        default: switch_error(__func__, 0x8057EE70, 0x805835A8);
    }
    // 0x8057EE74: nop

L_8057EE78:
    // 0x8057EE78: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X8A8) << 16);
    // 0x8057EE7C: jr          $ra
    // 0x8057EE80: addiu       $v0, $v0, -0x948
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X8A8));
    return;
    // 0x8057EE80: addiu       $v0, $v0, -0x948
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X8A8));
L_8057EE84:
    // 0x8057EE84: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X1520) << 16);
    // 0x8057EE88: jr          $ra
    // 0x8057EE8C: addiu       $v0, $v0, 0x330
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X1520));
    return;
    // 0x8057EE8C: addiu       $v0, $v0, 0x330
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X1520));
L_8057EE90:
    // 0x8057EE90: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X18A4) << 16);
    // 0x8057EE94: jr          $ra
    // 0x8057EE98: addiu       $v0, $v0, 0x6B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X18A4));
    return;
    // 0x8057EE98: addiu       $v0, $v0, 0x6B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X18A4));
L_8057EE9C:
    // 0x8057EE9C: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X1B74) << 16);
    // 0x8057EEA0: jr          $ra
    // 0x8057EEA4: addiu       $v0, $v0, 0x984
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X1B74));
    return;
    // 0x8057EEA4: addiu       $v0, $v0, 0x984
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X1B74));
L_8057EEA8:
    // 0x8057EEA8: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X1DF8) << 16);
    // 0x8057EEAC: jr          $ra
    // 0x8057EEB0: addiu       $v0, $v0, 0xC08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X1DF8));
    return;
    // 0x8057EEB0: addiu       $v0, $v0, 0xC08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X1DF8));
L_8057EEB4:
    // 0x8057EEB4: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X2194) << 16);
    // 0x8057EEB8: jr          $ra
    // 0x8057EEBC: addiu       $v0, $v0, 0xFA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X2194));
    return;
    // 0x8057EEBC: addiu       $v0, $v0, 0xFA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X2194));
L_8057EEC0:
    // 0x8057EEC0: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X26F4) << 16);
    // 0x8057EEC4: jr          $ra
    // 0x8057EEC8: addiu       $v0, $v0, 0x1504
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X26F4));
    return;
    // 0x8057EEC8: addiu       $v0, $v0, 0x1504
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X26F4));
L_8057EECC:
    // 0x8057EECC: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X2CD4) << 16);
    // 0x8057EED0: jr          $ra
    // 0x8057EED4: addiu       $v0, $v0, 0x1AE4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X2CD4));
    return;
    // 0x8057EED4: addiu       $v0, $v0, 0x1AE4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X2CD4));
L_8057EED8:
    // 0x8057EED8: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X3188) << 16);
    // 0x8057EEDC: jr          $ra
    // 0x8057EEE0: addiu       $v0, $v0, 0x1F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X3188));
    return;
    // 0x8057EEE0: addiu       $v0, $v0, 0x1F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X3188));
L_8057EEE4:
    // 0x8057EEE4: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X3308) << 16);
    // 0x8057EEE8: jr          $ra
    // 0x8057EEEC: addiu       $v0, $v0, 0x2118
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X3308));
    return;
    // 0x8057EEEC: addiu       $v0, $v0, 0x2118
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X3308));
L_8057EEF0:
    // 0x8057EEF0: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X3FD8) << 16);
    // 0x8057EEF4: jr          $ra
    // 0x8057EEF8: addiu       $v0, $v0, 0x2DE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X3FD8));
    return;
    // 0x8057EEF8: addiu       $v0, $v0, 0x2DE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X3FD8));
L_8057EEFC:
    // 0x8057EEFC: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(399, 0X40E8) << 16);
    // 0x8057EF00: jr          $ra
    // 0x8057EF04: addiu       $v0, $v0, 0x2EF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X40E8));
    return;
    // 0x8057EF04: addiu       $v0, $v0, 0x2EF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(399, 0X40E8));
L_8057EF08:
    // 0x8057EF08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057EF0C:
    // 0x8057EF0C: jr          $ra
    // 0x8057EF10: nop

    return;
    // 0x8057EF10: nop

;}
RECOMP_FUNC void func_80716D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716D98: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716D9C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716DA0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716DA4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716DA8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716DAC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716DB0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716DB4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716DB8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716DBC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716DC0: jr          $ra
    // 0x80716DC4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716DC4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8077717C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077717C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80777180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80777184: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80777188: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8077718C: lui         $t7, 0x8077
    ctx->r15 = S32(RELOC_HI16(772, 0X838) << 16);
    // 0x80777190: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80777194: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80777198: addiu       $t7, $t7, 0x7308
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(772, 0X838));
    // 0x8077719C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807771A0: jal         0x800653D8
    // 0x807771A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x807771A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807771A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807771AC: andi        $t9, $v0, 0x3F
    ctx->r25 = ctx->r2 & 0X3F;
    // 0x807771B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807771B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807771B8: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    // 0x807771BC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807771C0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x807771C4: jal         0x80045A34
    // 0x807771C8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x807771C8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x807771CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807771D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807771D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807771D8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807771DC: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x807771E0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807771E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807771E8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x807771EC: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x807771F0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x807771F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807771F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807771FC: jr          $ra
    // 0x80777200: nop

    return;
    // 0x80777200: nop

;}
RECOMP_FUNC void func_8053137C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053137C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80531380: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80531384: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80531388: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8053138C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80531390: lui         $s4, 0x8053
    ctx->r20 = S32(RELOC_HI16(342, 0X199C) << 16);
    // 0x80531394: lui         $s5, 0x8053
    ctx->r21 = S32(RELOC_HI16(342, 0X1920) << 16);
    // 0x80531398: lui         $s7, 0x8053
    ctx->r23 = S32(RELOC_HI16(342, 0X192C) << 16);
    // 0x8053139C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x805313A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x805313A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x805313A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805313AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805313B0: addiu       $s7, $s7, 0x271C
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(342, 0X192C));
    // 0x805313B4: addiu       $s5, $s5, 0x2710
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(342, 0X1920));
    // 0x805313B8: addiu       $s4, $s4, 0x278C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(342, 0X199C));
    // 0x805313BC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
L_805313C0:
    // 0x805313C0: lui         $s0, 0x8053
    ctx->r16 = S32(RELOC_HI16(342, 0X198C) << 16);
    // 0x805313C4: addiu       $s0, $s0, 0x277C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(342, 0X198C));
    // 0x805313C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x805313CC: addiu       $s1, $s6, 0x278
    ctx->r17 = ADD32(ctx->r22, 0X278);
L_805313D0:
    // 0x805313D0: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x805313D4: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x805313D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805313DC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x805313E0: jal         0x80065528
    // 0x805313E4: addu        $a1, $t6, $s2
    ctx->r5 = ADD32(ctx->r14, ctx->r18);
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x805313E4: addu        $a1, $t6, $s2
    ctx->r5 = ADD32(ctx->r14, ctx->r18);
    after_0:
    // 0x805313E8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x805313EC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x805313F0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x805313F4: sh          $t7, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r15;
    // 0x805313F8: lh          $t8, -0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X2);
    // 0x805313FC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80531400: bne         $s0, $s4, L_805313D0
    if (ctx->r16 != ctx->r20) {
        // 0x80531404: sh          $t8, 0xA($s3)
        MEM_H(0XA, ctx->r19) = ctx->r24;
            goto L_805313D0;
    }
    // 0x80531404: sh          $t8, 0xA($s3)
    MEM_H(0XA, ctx->r19) = ctx->r24;
    // 0x80531408: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8053140C: bne         $s5, $s7, L_805313C0
    if (ctx->r21 != ctx->r23) {
        // 0x80531410: addiu       $s6, $s6, 0x40
        ctx->r22 = ADD32(ctx->r22, 0X40);
            goto L_805313C0;
    }
    // 0x80531410: addiu       $s6, $s6, 0x40
    ctx->r22 = ADD32(ctx->r22, 0X40);
    // 0x80531414: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80531418: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8053141C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80531420: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80531424: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80531428: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8053142C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80531430: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80531434: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80531438: jr          $ra
    // 0x8053143C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8053143C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80460470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460470: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80460474: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80460478: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8046047C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80460480: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80460484: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80460488: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8046048C: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(119, 0X420) << 16);
    // 0x80460490: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80460494: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80460498: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8046049C: lw          $t1, 0x510($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(119, 0X420));
    // 0x804604A0: jr          $ra
    // 0x804604A4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804604A4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804604A8: nop

    // 0x804604AC: nop

;}
RECOMP_FUNC void func_805D7D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7D9C: jr          $ra
    // 0x805D7DA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805D7DA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80064920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064928: jal         0x8007C5EC
    // 0x8006492C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8007C5EC(rdram, ctx);
        goto after_0;
    // 0x8006492C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80064930: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80064934: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80064938: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8006493C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80064940: addiu       $a1, $a1, -0x20F0
    ctx->r5 = ADD32(ctx->r5, -0X20F0);
    // 0x80064944: addiu       $v1, $v1, -0x2120
    ctx->r3 = ADD32(ctx->r3, -0X2120);
    // 0x80064948: addiu       $v0, $v0, -0x6C70
    ctx->r2 = ADD32(ctx->r2, -0X6C70);
    // 0x8006494C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80064950:
    // 0x80064950: lwl         $t7, 0x0($v1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r3, 0X0);
    // 0x80064954: lwl         $t6, 0x4($v1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r3, 0X4);
    // 0x80064958: lwr         $t7, 0x3($v1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r3, 0X3);
    // 0x8006495C: lwr         $t6, 0x7($v1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r3, 0X7);
    // 0x80064960: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80064964: swl         $t7, 0x0($v0)
    do_swl(rdram, 0X0, ctx->r2, ctx->r15);
    // 0x80064968: swl         $t6, 0x4($v0)
    do_swl(rdram, 0X4, ctx->r2, ctx->r14);
    // 0x8006496C: swr         $t7, 0x3($v0)
    do_swr(rdram, 0X3, ctx->r2, ctx->r15);
    // 0x80064970: swr         $t6, 0x7($v0)
    do_swr(rdram, 0X7, ctx->r2, ctx->r14);
    // 0x80064974: lwl         $t7, -0x10($v1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r3, -0X10);
    // 0x80064978: lwl         $t6, -0xC($v1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r3, -0XC);
    // 0x8006497C: lwr         $t7, -0xD($v1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r3, -0XD);
    // 0x80064980: lwr         $t6, -0x9($v1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r3, -0X9);
    // 0x80064984: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80064988: swl         $t7, 0x8($v0)
    do_swl(rdram, 0X8, ctx->r2, ctx->r15);
    // 0x8006498C: swl         $t6, 0xC($v0)
    do_swl(rdram, 0XC, ctx->r2, ctx->r14);
    // 0x80064990: swr         $t7, 0xB($v0)
    do_swr(rdram, 0XB, ctx->r2, ctx->r15);
    // 0x80064994: swr         $t6, 0xF($v0)
    do_swr(rdram, 0XF, ctx->r2, ctx->r14);
    // 0x80064998: lwl         $t7, -0x8($v1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r3, -0X8);
    // 0x8006499C: lwl         $t6, -0x4($v1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r3, -0X4);
    // 0x800649A0: lwr         $t7, -0x5($v1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r3, -0X5);
    // 0x800649A4: lwr         $t6, -0x1($v1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r3, -0X1);
    // 0x800649A8: swl         $t7, 0x10($v0)
    do_swl(rdram, 0X10, ctx->r2, ctx->r15);
    // 0x800649AC: swl         $t6, 0x14($v0)
    do_swl(rdram, 0X14, ctx->r2, ctx->r14);
    // 0x800649B0: swr         $t7, 0x13($v0)
    do_swr(rdram, 0X13, ctx->r2, ctx->r15);
    // 0x800649B4: swr         $t6, 0x17($v0)
    do_swr(rdram, 0X17, ctx->r2, ctx->r14);
    // 0x800649B8: sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
    // 0x800649BC: bne         $v1, $a1, L_80064950
    if (ctx->r3 != ctx->r5) {
        // 0x800649C0: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80064950;
    }
    // 0x800649C0: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800649C4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800649C8: lbu         $t8, 0x7EB4($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7EB4);
    // 0x800649CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800649D0: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800649D4: bne         $t8, $at, L_80064A34
    if (ctx->r24 != ctx->r1) {
        // 0x800649D8: lui         $t2, 0x800A
        ctx->r10 = S32(0X800A << 16);
            goto L_80064A34;
    }
    // 0x800649D8: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800649DC: addiu       $t9, $t9, 0x6594
    ctx->r25 = ADD32(ctx->r25, 0X6594);
    // 0x800649E0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800649E4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800649E8: addiu       $v0, $v0, -0x6C70
    ctx->r2 = ADD32(ctx->r2, -0X6C70);
    // 0x800649EC: swl         $t1, 0x0($v0)
    do_swl(rdram, 0X0, ctx->r2, ctx->r9);
    // 0x800649F0: swr         $t1, 0x3($v0)
    do_swr(rdram, 0X3, ctx->r2, ctx->r9);
    // 0x800649F4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800649F8: swl         $t0, 0x4($v0)
    do_swl(rdram, 0X4, ctx->r2, ctx->r8);
    // 0x800649FC: swr         $t0, 0x7($v0)
    do_swr(rdram, 0X7, ctx->r2, ctx->r8);
    // 0x80064A00: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80064A04: swl         $t1, 0x8($v0)
    do_swl(rdram, 0X8, ctx->r2, ctx->r9);
    // 0x80064A08: swr         $t1, 0xB($v0)
    do_swr(rdram, 0XB, ctx->r2, ctx->r9);
    // 0x80064A0C: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80064A10: swl         $t0, 0xC($v0)
    do_swl(rdram, 0XC, ctx->r2, ctx->r8);
    // 0x80064A14: swr         $t0, 0xF($v0)
    do_swr(rdram, 0XF, ctx->r2, ctx->r8);
    // 0x80064A18: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80064A1C: swl         $t1, 0x10($v0)
    do_swl(rdram, 0X10, ctx->r2, ctx->r9);
    // 0x80064A20: swr         $t1, 0x13($v0)
    do_swr(rdram, 0X13, ctx->r2, ctx->r9);
    // 0x80064A24: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80064A28: swl         $t0, 0x14($v0)
    do_swl(rdram, 0X14, ctx->r2, ctx->r8);
    // 0x80064A2C: swr         $t0, 0x17($v0)
    do_swr(rdram, 0X17, ctx->r2, ctx->r8);
    // 0x80064A30: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80064A34:
    // 0x80064A34: lw          $t2, 0x6590($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6590);
    // 0x80064A38: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80064A3C: addiu       $v0, $v0, -0x6C70
    ctx->r2 = ADD32(ctx->r2, -0X6C70);
    // 0x80064A40: bne         $t2, $zero, L_80064A98
    if (ctx->r10 != 0) {
        // 0x80064A44: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_80064A98;
    }
    // 0x80064A44: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80064A48: addiu       $t3, $t3, 0x6594
    ctx->r11 = ADD32(ctx->r11, 0X6594);
    // 0x80064A4C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80064A50: swl         $t5, 0x0($v0)
    do_swl(rdram, 0X0, ctx->r2, ctx->r13);
    // 0x80064A54: swr         $t5, 0x3($v0)
    do_swr(rdram, 0X3, ctx->r2, ctx->r13);
    // 0x80064A58: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80064A5C: swl         $t4, 0x4($v0)
    do_swl(rdram, 0X4, ctx->r2, ctx->r12);
    // 0x80064A60: swr         $t4, 0x7($v0)
    do_swr(rdram, 0X7, ctx->r2, ctx->r12);
    // 0x80064A64: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80064A68: swl         $t5, 0x8($v0)
    do_swl(rdram, 0X8, ctx->r2, ctx->r13);
    // 0x80064A6C: swr         $t5, 0xB($v0)
    do_swr(rdram, 0XB, ctx->r2, ctx->r13);
    // 0x80064A70: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80064A74: swl         $t4, 0xC($v0)
    do_swl(rdram, 0XC, ctx->r2, ctx->r12);
    // 0x80064A78: swr         $t4, 0xF($v0)
    do_swr(rdram, 0XF, ctx->r2, ctx->r12);
    // 0x80064A7C: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x80064A80: swl         $t5, 0x10($v0)
    do_swl(rdram, 0X10, ctx->r2, ctx->r13);
    // 0x80064A84: swr         $t5, 0x13($v0)
    do_swr(rdram, 0X13, ctx->r2, ctx->r13);
    // 0x80064A88: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80064A8C: swl         $t4, 0x14($v0)
    do_swl(rdram, 0X14, ctx->r2, ctx->r12);
    // 0x80064A90: swr         $t4, 0x17($v0)
    do_swr(rdram, 0X17, ctx->r2, ctx->r12);
    // 0x80064A94: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80064A98:
    // 0x80064A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064AA0: jr          $ra
    // 0x80064AA4: nop

    return;
    // 0x80064AA4: nop

;}
RECOMP_FUNC void func_80034BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034BE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80034BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80034BF0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034BF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80034BF8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80034BFC: jal         0x80065954
    // 0x80034C00: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80034C00: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x80034C04: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80034C08: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80034C0C: jal         0x80081E8C
    // 0x80034C10: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    fatan2(rdram, ctx);
        goto after_1;
    // 0x80034C10: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80034C14: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80034C18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80034C1C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80034C20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034C24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034C28: lwc1        $f8, 0xC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XC4);
    // 0x80034C2C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80034C30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80034C34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034C38: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80034C3C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80034C40: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80034C44: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80034C48: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80034C4C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80034C50: nop

    // 0x80034C54: bc1fl       L_80034C68
    if (!c1cs) {
        // 0x80034C58: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80034C68;
    }
    goto skip_0;
    // 0x80034C58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x80034C5C: b           L_80034C8C
    // 0x80034C60: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_80034C8C;
    // 0x80034C60: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80034C64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80034C68:
    // 0x80034C68: nop

    // 0x80034C6C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80034C70: nop

    // 0x80034C74: bc1fl       L_80034C88
    if (!c1cs) {
        // 0x80034C78: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80034C88;
    }
    goto skip_1;
    // 0x80034C78: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_1:
    // 0x80034C7C: b           L_80034C88
    // 0x80034C80: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80034C88;
    // 0x80034C80: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80034C84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80034C88:
    // 0x80034C88: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80034C8C:
    // 0x80034C8C: swc1        $f2, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f2.u32l;
    // 0x80034C90: jal         0x80065954
    // 0x80034C94: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80034C94: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_2:
    // 0x80034C98: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80034C9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80034CA4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80034CA8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80034CAC: jal         0x80041214
    // 0x80034CB0: nop

    func_80041214(rdram, ctx);
        goto after_3;
    // 0x80034CB0: nop

    after_3:
    // 0x80034CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80034CB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80034CBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80034CC0: jr          $ra
    // 0x80034CC4: nop

    return;
    // 0x80034CC4: nop

;}
RECOMP_FUNC void func_804462D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804462D0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804462D4: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x804462D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804462DC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x804462E0: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x804462E4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804462E8: jr          $ra
    // 0x804462EC: sw          $t7, 0x6CA8($at)
    MEM_W(0X6CA8, ctx->r1) = ctx->r15;
    return;
    // 0x804462EC: sw          $t7, 0x6CA8($at)
    MEM_W(0X6CA8, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8004F970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F970: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x8004F974: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8004F978: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8004F97C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004F980: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8004F984: lw          $t9, 0x103C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X103C);
    // 0x8004F988: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004F98C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8004F990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F994: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004F998: jalr        $t9
    // 0x8004F99C: lw          $a1, 0x1058($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1058);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8004F99C: lw          $a1, 0x1058($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1058);
    after_0:
    // 0x8004F9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004F9A8: jr          $ra
    // 0x8004F9AC: nop

    return;
    // 0x8004F9AC: nop

;}
RECOMP_FUNC void func_80736B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80736B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736B78: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80736B7C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80736B80: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80736B84: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(736, 0X397C) << 16);
    // 0x80736B88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80736B8C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80736B90: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80736B94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80736B98: lw          $t8, -0x6C24($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(736, 0X397C));
    // 0x80736B9C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80736BA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80736BA4: jal         0x80048490
    // 0x80736BA8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80736BA8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80736BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80736BB4: jr          $ra
    // 0x80736BB8: nop

    return;
    // 0x80736BB8: nop

;}
RECOMP_FUNC void func_80453704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045370C: jal         0x80453644
    // 0x80453710: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80453644(rdram, ctx);
        goto after_0;
    // 0x80453710: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80453714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045371C: jr          $ra
    // 0x80453720: nop

    return;
    // 0x80453720: nop

;}
RECOMP_FUNC void func_807A10CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A10CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A10D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A10D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A10D8: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x807A10DC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807A10E0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x807A10E4: bne         $at, $zero, L_807A1130
    if (ctx->r1 != 0) {
        // 0x807A10E8: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_807A1130;
    }
    // 0x807A10E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x807A10EC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x807A10F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807A10F4: lui         $t3, 0x807A
    ctx->r11 = S32(RELOC_HI16(841, 0XD48) << 16);
    // 0x807A10F8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x807A10FC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x807A1100: lbu         $t2, 0x30($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X30);
    // 0x807A1104: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x807A1108: lbu         $t3, 0x1C88($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(841, 0XD48));
    // 0x807A110C: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x807A1110: bne         $at, $zero, L_807A1128
    if (ctx->r1 != 0) {
        // 0x807A1114: nop
    
            goto L_807A1128;
    }
    // 0x807A1114: nop

    // 0x807A1118: jal         0x807A106C
    // 0x807A111C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_807A106C(rdram, ctx);
        goto after_0;
    // 0x807A111C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_0:
    // 0x807A1120: b           L_807A1134
    // 0x807A1124: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_807A1134;
    // 0x807A1124: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_807A1128:
    // 0x807A1128: jal         0x807A106C
    // 0x807A112C: nop

    func_807A106C(rdram, ctx);
        goto after_1;
    // 0x807A112C: nop

    after_1:
L_807A1130:
    // 0x807A1130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A1134:
    // 0x807A1134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1138: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A113C: jr          $ra
    // 0x807A1140: nop

    return;
    // 0x807A1140: nop

;}
RECOMP_FUNC void func_8000A364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A36C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A370: jal         0x8000A2F4
    // 0x8000A374: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8000A2F4(rdram, ctx);
        goto after_0;
    // 0x8000A374: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8000A378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A37C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A380: jr          $ra
    // 0x8000A384: nop

    return;
    // 0x8000A384: nop

;}
RECOMP_FUNC void func_80516E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80516E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80516E48: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x80516E4C: beql        $v0, $zero, L_80516E84
    if (ctx->r2 == 0) {
        // 0x80516E50: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80516E84;
    }
    goto skip_0;
    // 0x80516E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80516E54: jalr        $v0
    // 0x80516E58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80516E58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80516E5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80516E60: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80516E64: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80516E68: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80516E6C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80516E70: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80516E74: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80516E78: b           L_80516E84
    // 0x80516E7C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_80516E84;
    // 0x80516E7C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80516E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80516E84:
    // 0x80516E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80516E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80516E8C: jr          $ra
    // 0x80516E90: nop

    return;
    // 0x80516E90: nop

;}
RECOMP_FUNC void func_80777138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077713C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80777140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80777144: jal         0x80776BD8
    // 0x80777148: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80776BD8(rdram, ctx);
        goto after_0;
    // 0x80777148: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_0:
    // 0x8077714C: jal         0x80045BD8
    // 0x80777150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80777150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80777154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80777158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8077715C: jr          $ra
    // 0x80777160: nop

    return;
    // 0x80777160: nop

;}
RECOMP_FUNC void func_806CDA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CDA88: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x806CDA8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x806CDA90: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x806CDA94: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x806CDA98: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x806CDA9C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x806CDAA0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x806CDAA4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x806CDAA8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x806CDAAC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x806CDAB0: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806CDAB4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806CDAB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CDABC: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x806CDAC0: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x806CDAC4: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806CDAC8: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x806CDACC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806CDAD0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x806CDAD4: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x806CDAD8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806CDADC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x806CDAE0: sh          $t6, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r14;
    // 0x806CDAE4: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x806CDAE8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806CDAEC: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x806CDAF0: sh          $v0, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r2;
    // 0x806CDAF4: sh          $v0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r2;
    // 0x806CDAF8: jal         0x8006A99C
    // 0x806CDAFC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x806CDAFC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x806CDB00: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x806CDB04: sll         $s6, $v0, 16
    ctx->r22 = S32(ctx->r2 << 16);
    // 0x806CDB08: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x806CDB0C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806CDB10: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x806CDB14: nop

    // 0x806CDB18: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806CDB1C: jal         0x8006A99C
    // 0x806CDB20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x806CDB20: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x806CDB24: sll         $s4, $v0, 16
    ctx->r20 = S32(ctx->r2 << 16);
    // 0x806CDB28: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x806CDB2C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x806CDB30: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x806CDB34: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x806CDB38: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x806CDB3C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x806CDB40: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806CDB44: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x806CDB48: jal         0x8006AFA0
    // 0x806CDB4C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8006AFA0(rdram, ctx);
        goto after_2;
    // 0x806CDB4C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x806CDB50: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806CDB54: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // 0x806CDB58: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x806CDB5C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x806CDB60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_806CDB64:
    // 0x806CDB64: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x806CDB68: addu        $a0, $s6, $s0
    ctx->r4 = ADD32(ctx->r22, ctx->r16);
    // 0x806CDB6C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806CDB70: beq         $s5, $v0, L_806CDB94
    if (ctx->r21 == ctx->r2) {
        // 0x806CDB74: andi        $a2, $v0, 0xF800
        ctx->r6 = ctx->r2 & 0XF800;
            goto L_806CDB94;
    }
    // 0x806CDB74: andi        $a2, $v0, 0xF800
    ctx->r6 = ctx->r2 & 0XF800;
    // 0x806CDB78: addu        $a1, $s4, $s2
    ctx->r5 = ADD32(ctx->r20, ctx->r18);
    // 0x806CDB7C: ori         $a2, $a2, 0x701
    ctx->r6 = ctx->r6 | 0X701;
    // 0x806CDB80: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x806CDB84: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x806CDB88: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806CDB8C: jal         0x8006B1C8
    // 0x806CDB90: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006B1C8(rdram, ctx);
        goto after_3;
    // 0x806CDB90: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
L_806CDB94:
    // 0x806CDB94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806CDB98: bne         $s0, $s3, L_806CDB64
    if (ctx->r16 != ctx->r19) {
        // 0x806CDB9C: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_806CDB64;
    }
    // 0x806CDB9C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x806CDBA0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806CDBA4: bnel        $s2, $s3, L_806CDB64
    if (ctx->r18 != ctx->r19) {
        // 0x806CDBA8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_806CDB64;
    }
    goto skip_0;
    // 0x806CDBA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x806CDBAC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806CDBB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806CDBB4: lwc1        $f8, 0x3C($s7)
    ctx->f8.u32l = MEM_W(ctx->r23, 0X3C);
    // 0x806CDBB8: lwc1        $f16, 0x40($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X40);
    // 0x806CDBBC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x806CDBC0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x806CDBC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CDBC8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x806CDBCC: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x806CDBD0: swc1        $f10, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->f10.u32l;
    // 0x806CDBD4: jal         0x806CED40
    // 0x806CDBD8: swc1        $f18, 0x40($s7)
    MEM_W(0X40, ctx->r23) = ctx->f18.u32l;
    func_806CED40(rdram, ctx);
        goto after_4;
    // 0x806CDBD8: swc1        $f18, 0x40($s7)
    MEM_W(0X40, ctx->r23) = ctx->f18.u32l;
    after_4:
    // 0x806CDBDC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x806CDBE0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x806CDBE4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x806CDBE8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x806CDBEC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x806CDBF0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x806CDBF4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x806CDBF8: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x806CDBFC: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x806CDC00: jr          $ra
    // 0x806CDC04: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x806CDC04: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800385BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800385BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800385C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800385C4: jal         0x80021958
    // 0x800385C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x800385C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800385CC: bne         $v0, $zero, L_800385DC
    if (ctx->r2 != 0) {
        // 0x800385D0: nop
    
            goto L_800385DC;
    }
    // 0x800385D0: nop

    // 0x800385D4: b           L_80038610
    // 0x800385D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038610;
    // 0x800385D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800385DC:
    // 0x800385DC: jal         0x800415FC
    // 0x800385E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x800385E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800385E4: beq         $v0, $zero, L_800385F4
    if (ctx->r2 == 0) {
        // 0x800385E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800385F4;
    }
    // 0x800385E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800385EC: b           L_80038610
    // 0x800385F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038610;
    // 0x800385F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800385F4:
    // 0x800385F4: jal         0x8003790C
    // 0x800385F8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8003790C(rdram, ctx);
        goto after_2;
    // 0x800385F8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_2:
    // 0x800385FC: bnel        $v0, $zero, L_80038610
    if (ctx->r2 != 0) {
        // 0x80038600: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038610;
    }
    goto skip_0;
    // 0x80038600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038604: b           L_80038610
    // 0x80038608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038610;
    // 0x80038608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003860C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038610:
    // 0x80038610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038618: jr          $ra
    // 0x8003861C: nop

    return;
    // 0x8003861C: nop

;}
RECOMP_FUNC void func_8006919C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006919C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800691A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800691A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800691A8: lbu         $t6, 0xF2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF2);
    // 0x800691AC: andi        $t8, $a2, 0x7
    ctx->r24 = ctx->r6 & 0X7;
    // 0x800691B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800691B4: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800691B8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800691BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800691C0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800691C4: lwc1        $f4, 0x6ED0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6ED0);
    // 0x800691C8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800691CC: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800691D0: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800691D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800691D8: jal         0x80065388
    // 0x800691DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065388(rdram, ctx);
        goto after_0;
    // 0x800691DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800691E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800691E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800691E8: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800691EC: lwc1        $f6, 0xB0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XB0);
    // 0x800691F0: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800691F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800691F8: swc1        $f10, 0xB0($a1)
    MEM_W(0XB0, ctx->r5) = ctx->f10.u32l;
    // 0x800691FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069204: jr          $ra
    // 0x80069208: nop

    return;
    // 0x80069208: nop

;}
RECOMP_FUNC void func_800404C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800404C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800404CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800404D0: lw          $t6, 0x1F4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F4);
    // 0x800404D4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800404D8: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x800404DC: beql        $v0, $zero, L_80040528
    if (ctx->r2 == 0) {
        // 0x800404E0: lw          $t8, 0x138($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X138);
            goto L_80040528;
    }
    goto skip_0;
    // 0x800404E0: lw          $t8, 0x138($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X138);
    skip_0:
    // 0x800404E4: lwc1        $f18, 0x88($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X88);
    // 0x800404E8: lwc1        $f16, 0x88($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X88);
    // 0x800404EC: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
    // 0x800404F0: lwc1        $f8, 0x84($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X84);
    // 0x800404F4: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800404F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800404FC: jal         0x80081E8C
    // 0x80040500: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80040500: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    after_0:
    // 0x80040504: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80040508: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004050C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80040510: lwc1        $f4, 0x2D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2D4);
    // 0x80040514: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80040518: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004051C: b           L_80040538
    // 0x80040520: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
        goto L_80040538;
    // 0x80040520: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80040524: lw          $t8, 0x138($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X138);
L_80040528:
    // 0x80040528: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004052C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80040530: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80040534: lwc1        $f12, -0x1038($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1038);
L_80040538:
    // 0x80040538: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004053C: jal         0x80066E88
    // 0x80040540: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80040540: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80040544: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80040548: lwc1        $f6, 0x2D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2D8);
    // 0x8004054C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80040550: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80040554: jal         0x80066DE4
    // 0x80040558: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80040558: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8004055C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80040560: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80040564: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80040568: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004056C: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    // 0x80040570: lwc1        $f8, 0x2DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2DC);
    // 0x80040574: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80040578: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004057C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80040580: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80040584: swc1        $f12, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f12.u32l;
    // 0x80040588: bc1f        L_80040594
    if (!c1cs) {
        // 0x8004058C: swc1        $f10, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
            goto L_80040594;
    }
    // 0x8004058C: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x80040590: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80040594:
    // 0x80040594: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80040598: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8004059C: lw          $v0, -0x1030($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1030);
    // 0x800405A0: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
    // 0x800405A4: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x800405A8: jal         0x80038F38
    // 0x800405AC: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
    func_80038F38(rdram, ctx);
        goto after_3;
    // 0x800405AC: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
    after_3:
    // 0x800405B0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800405B4: sw          $zero, 0x1F0($t2)
    MEM_W(0X1F0, ctx->r10) = 0;
    // 0x800405B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800405BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800405C0: jr          $ra
    // 0x800405C4: nop

    return;
    // 0x800405C4: nop

;}
RECOMP_FUNC void func_807BC514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC51C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807BC520: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(898, 0X6E50) << 16);
    // 0x807BC524: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807BC528: addiu       $t6, $t6, 0x2B10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(898, 0X6E50));
    // 0x807BC52C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807BC530: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x807BC534: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807BC538: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x807BC53C: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    // 0x807BC540: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807BC544: bne         $t9, $at, L_807BC560
    if (ctx->r25 != ctx->r1) {
        // 0x807BC548: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_807BC560;
    }
    // 0x807BC548: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807BC54C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BC550: jal         0x807BC5C0
    // 0x807BC554: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_807BC5C0(rdram, ctx);
        goto after_0;
    // 0x807BC554: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x807BC558: b           L_807BC570
    // 0x807BC55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807BC570;
    // 0x807BC55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807BC560:
    // 0x807BC560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BC564: jal         0x807BC5C0
    // 0x807BC568: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807BC5C0(rdram, ctx);
        goto after_1;
    // 0x807BC568: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x807BC56C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807BC570:
    // 0x807BC570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC574: jr          $ra
    // 0x807BC578: nop

    return;
    // 0x807BC578: nop

;}
RECOMP_FUNC void func_800190A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800190A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800190A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800190AC: jal         0x80019AC4
    // 0x800190B0: nop

    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x800190B0: nop

    after_0:
    // 0x800190B4: beq         $v0, $zero, L_800190C0
    if (ctx->r2 == 0) {
        // 0x800190B8: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_800190C0;
    }
    // 0x800190B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800190BC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800190C0:
    // 0x800190C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800190C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800190C8: jr          $ra
    // 0x800190CC: nop

    return;
    // 0x800190CC: nop

;}
RECOMP_FUNC void func_8056698C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056698C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80566990: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80566994: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80566998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8056699C: sh          $a2, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r6;
    // 0x805669A0: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805669A4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x805669A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805669AC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x805669B0: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805669B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805669B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805669BC: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x805669C0: addiu       $t6, $a2, -0x4159
    ctx->r14 = ADD32(ctx->r6, -0X4159);
    // 0x805669C4: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x805669C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805669CC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x805669D0: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x805669D4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805669D8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805669DC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x805669E0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x805669E4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x805669E8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x805669EC: beq         $at, $zero, L_80566ADC
    if (ctx->r1 == 0) {
        // 0x805669F0: swc1        $f10, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
            goto L_80566ADC;
    }
    // 0x805669F0: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x805669F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805669F8: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XD34) << 16);
    // 0x805669FC: addu        $at, $at, $t6
    gpr jr_addend_80566A04 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80566A00: lw          $t6, 0x7284($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(375, 0XD34));
    // 0x80566A04: jr          $t6
    // 0x80566A08: nop

    switch (jr_addend_80566A04 >> 2) {
        case 0: goto L_80566A0C; break;
        case 1: goto L_80566A0C; break;
        case 2: goto L_80566ADC; break;
        case 3: goto L_80566ADC; break;
        case 4: goto L_80566ADC; break;
        case 5: goto L_80566ADC; break;
        case 6: goto L_80566ADC; break;
        case 7: goto L_80566ADC; break;
        case 8: goto L_80566ADC; break;
        case 9: goto L_80566ADC; break;
        case 10: goto L_80566ADC; break;
        case 11: goto L_80566ADC; break;
        case 12: goto L_80566A4C; break;
        case 13: goto L_80566A4C; break;
        case 14: goto L_80566ADC; break;
        case 15: goto L_80566ADC; break;
        case 16: goto L_80566ADC; break;
        case 17: goto L_80566ADC; break;
        case 18: goto L_80566ADC; break;
        case 19: goto L_80566ADC; break;
        case 20: goto L_80566ADC; break;
        case 21: goto L_80566ADC; break;
        case 22: goto L_80566ADC; break;
        case 23: goto L_80566ADC; break;
        case 24: goto L_80566A80; break;
        case 25: goto L_80566A80; break;
        case 26: goto L_80566ADC; break;
        case 27: goto L_80566ADC; break;
        case 28: goto L_80566ADC; break;
        case 29: goto L_80566ADC; break;
        case 30: goto L_80566ADC; break;
        case 31: goto L_80566ADC; break;
        case 32: goto L_80566ADC; break;
        case 33: goto L_80566ADC; break;
        case 34: goto L_80566ADC; break;
        case 35: goto L_80566AC0; break;
        case 36: goto L_80566AD0; break;
        default: switch_error(__func__, 0x80566A04, 0x80567284);
    }
    // 0x80566A08: nop

L_80566A0C:
    // 0x80566A0C: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XDC8) << 16);
    // 0x80566A10: lwc1        $f16, 0x7318($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(375, 0XDC8));
    // 0x80566A14: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XDCC) << 16);
    // 0x80566A18: lwc1        $f4, 0x731C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(375, 0XDCC));
    // 0x80566A1C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80566A20: lwc1        $f18, 0x44($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X44);
    // 0x80566A24: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80566A28: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80566A2C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80566A30: jal         0x80067BBC
    // 0x80566A34: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80566A34: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    after_0:
    // 0x80566A38: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x80566A3C: jal         0x80067818
    // 0x80566A40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80566A40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80566A44: b           L_80566ADC
    // 0x80566A48: nop

        goto L_80566ADC;
    // 0x80566A48: nop

L_80566A4C:
    // 0x80566A4C: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XDD0) << 16);
    // 0x80566A50: lwc1        $f10, 0x7320($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(375, 0XDD0));
    // 0x80566A54: lwc1        $f8, 0x44($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X44);
    // 0x80566A58: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80566A5C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80566A60: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80566A64: jal         0x80067BBC
    // 0x80566A68: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80566A68: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    after_2:
    // 0x80566A6C: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x80566A70: jal         0x80067818
    // 0x80566A74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80566A74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80566A78: b           L_80566ADC
    // 0x80566A7C: nop

        goto L_80566ADC;
    // 0x80566A7C: nop

L_80566A80:
    // 0x80566A80: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XDD4) << 16);
    // 0x80566A84: lwc1        $f18, 0x7324($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(375, 0XDD4));
    // 0x80566A88: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XDD8) << 16);
    // 0x80566A8C: lwc1        $f6, 0x7328($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(375, 0XDD8));
    // 0x80566A90: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80566A94: lwc1        $f4, 0x44($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X44);
    // 0x80566A98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80566A9C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80566AA0: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80566AA4: jal         0x80067BBC
    // 0x80566AA8: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x80566AA8: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    after_4:
    // 0x80566AAC: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x80566AB0: jal         0x80067818
    // 0x80566AB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80566AB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80566AB8: b           L_80566ADC
    // 0x80566ABC: nop

        goto L_80566ADC;
    // 0x80566ABC: nop

L_80566AC0:
    // 0x80566AC0: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XDDC) << 16);
    // 0x80566AC4: lwc1        $f10, 0x732C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(375, 0XDDC));
    // 0x80566AC8: b           L_80566ADC
    // 0x80566ACC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
        goto L_80566ADC;
    // 0x80566ACC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
L_80566AD0:
    // 0x80566AD0: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XDE0) << 16);
    // 0x80566AD4: lwc1        $f16, 0x7330($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(375, 0XDE0));
    // 0x80566AD8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_80566ADC:
    // 0x80566ADC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80566AE0: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x80566AE4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80566AE8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80566AEC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x80566AF0: jalr        $t9
    // 0x80566AF4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80566AF4: nop

    after_6:
    // 0x80566AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566AFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80566B00: jr          $ra
    // 0x80566B04: nop

    return;
    // 0x80566B04: nop

;}
RECOMP_FUNC void func_8002CB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CB1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CB20: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002CB24: addiu       $a1, $a1, -0x2AF4
    ctx->r5 = ADD32(ctx->r5, -0X2AF4);
    // 0x8002CB28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CB2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002CB30: jal         0x80028118
    // 0x8002CB34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002CB34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002CB38: jal         0x8002CAB0
    // 0x8002CB3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002CAB0(rdram, ctx);
        goto after_1;
    // 0x8002CB3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002CB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CB44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CB48: jr          $ra
    // 0x8002CB4C: nop

    return;
    // 0x8002CB4C: nop

;}
RECOMP_FUNC void func_805CF068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CF068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CF06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CF070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805CF074: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x805CF078: jalr        $t9
    // 0x805CF07C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805CF07C: nop

    after_0:
    // 0x805CF080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805CF084: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x805CF088: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x805CF08C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x805CF090: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x805CF094: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x805CF098: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x805CF09C: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x805CF0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CF0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CF0A8: jr          $ra
    // 0x805CF0AC: nop

    return;
    // 0x805CF0AC: nop

;}
RECOMP_FUNC void func_8003A524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A524: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003A528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A52C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8003A530: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x8003A534: beq         $t7, $zero, L_8003A5A4
    if (ctx->r15 == 0) {
        // 0x8003A538: nop
    
            goto L_8003A5A4;
    }
    // 0x8003A538: nop

    // 0x8003A53C: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8003A540: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003A544: jal         0x80065954
    // 0x8003A548: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8003A548: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8003A54C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003A550: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A554: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003A558: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003A55C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003A560: nop

    // 0x8003A564: bc1fl       L_8003A598
    if (!c1cs) {
        // 0x8003A568: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8003A598;
    }
    goto skip_0;
    // 0x8003A568: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8003A56C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003A570: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8003A574: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8003A578: nop

    // 0x8003A57C: bc1fl       L_8003A594
    if (!c1cs) {
        // 0x8003A580: swc1        $f2, 0xC4($a0)
        MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
            goto L_8003A594;
    }
    goto skip_1;
    // 0x8003A580: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x8003A584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003A588: b           L_8003A594
    // 0x8003A58C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
        goto L_8003A594;
    // 0x8003A58C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8003A590: swc1        $f2, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f2.u32l;
L_8003A594:
    // 0x8003A594: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8003A598:
    // 0x8003A598: nop

    // 0x8003A59C: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8003A5A0: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
L_8003A5A4:
    // 0x8003A5A4: jal         0x8003A4EC
    // 0x8003A5A8: nop

    func_8003A4EC(rdram, ctx);
        goto after_1;
    // 0x8003A5A8: nop

    after_1:
    // 0x8003A5AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A5B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003A5B4: jr          $ra
    // 0x8003A5B8: nop

    return;
    // 0x8003A5B8: nop

;}
RECOMP_FUNC void func_807041E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807041E0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807041E4: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(709, 0XB20) << 16);
    // 0x807041E8: addiu       $t6, $t6, 0x3F90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(709, 0XB20));
    // 0x807041EC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807041F0: jr          $ra
    // 0x807041F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x807041F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8000DCB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DCB4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8000DCB8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8000DCBC: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x8000DCC0: jr          $ra
    // 0x8000DCC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x8000DCC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_804C4C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4C30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C4C34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C4C38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C4C3C: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x804C4C40: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x804C4C44: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x804C4C48: addiu       $at, $zero, 0x405F
    ctx->r1 = ADD32(0, 0X405F);
    // 0x804C4C4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C4C50: sw          $a3, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r7;
    // 0x804C4C54: beq         $t6, $at, L_804C4C64
    if (ctx->r14 == ctx->r1) {
        // 0x804C4C58: addiu       $v0, $v0, 0xD
        ctx->r2 = ADD32(ctx->r2, 0XD);
            goto L_804C4C64;
    }
    // 0x804C4C58: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x804C4C5C: b           L_804C4C6C
    // 0x804C4C60: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
        goto L_804C4C6C;
    // 0x804C4C60: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_804C4C64:
    // 0x804C4C64: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804C4C68: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
L_804C4C6C:
    // 0x804C4C6C: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x804C4C70: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(209, 0XE30) << 16);
    // 0x804C4C74: addiu       $t8, $t8, 0x4E20
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(209, 0XE30));
    // 0x804C4C78: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804C4C7C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804C4C80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804C4C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C4C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C4C8C: jal         0x804C4D54
    // 0x804C4C90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804C4D54(rdram, ctx);
        goto after_0;
    // 0x804C4C90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x804C4C94: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x804C4C98: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x804C4C9C: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x804C4CA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804C4CA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C4CA8: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x804C4CAC: jal         0x804C4C18
    // 0x804C4CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C4C18(rdram, ctx);
        goto after_1;
    // 0x804C4CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C4CB4: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C4CB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804C4CBC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x804C4CC0: beq         $v1, $at, L_804C4CE8
    if (ctx->r3 == ctx->r1) {
        // 0x804C4CC4: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_804C4CE8;
    }
    // 0x804C4CC4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x804C4CC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804C4CCC: beq         $v1, $at, L_804C4CFC
    if (ctx->r3 == ctx->r1) {
        // 0x804C4CD0: addiu       $t5, $zero, 0x40
        ctx->r13 = ADD32(0, 0X40);
            goto L_804C4CFC;
    }
    // 0x804C4CD0: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x804C4CD4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804C4CD8: beq         $v1, $at, L_804C4D0C
    if (ctx->r3 == ctx->r1) {
        // 0x804C4CDC: addiu       $t7, $zero, 0x40
        ctx->r15 = ADD32(0, 0X40);
            goto L_804C4D0C;
    }
    // 0x804C4CDC: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x804C4CE0: b           L_804C4D1C
    // 0x804C4CE4: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
        goto L_804C4D1C;
    // 0x804C4CE4: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
L_804C4CE8:
    // 0x804C4CE8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x804C4CEC: sb          $t3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r11;
    // 0x804C4CF0: sb          $a3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r7;
    // 0x804C4CF4: b           L_804C4D18
    // 0x804C4CF8: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
        goto L_804C4D18;
    // 0x804C4CF8: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
L_804C4CFC:
    // 0x804C4CFC: sb          $a3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r7;
    // 0x804C4D00: sb          $t5, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r13;
    // 0x804C4D04: b           L_804C4D18
    // 0x804C4D08: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
        goto L_804C4D18;
    // 0x804C4D08: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
L_804C4D0C:
    // 0x804C4D0C: sb          $a3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r7;
    // 0x804C4D10: sb          $a3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r7;
    // 0x804C4D14: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_804C4D18:
    // 0x804C4D18: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
L_804C4D1C:
    // 0x804C4D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C4D20: jal         0x80045A34
    // 0x804C4D24: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x804C4D24: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x804C4D28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C4D2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804C4D30: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804C4D34: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x804C4D38: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    // 0x804C4D3C: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x804C4D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C4D44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C4D48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C4D4C: jr          $ra
    // 0x804C4D50: nop

    return;
    // 0x804C4D50: nop

;}
RECOMP_FUNC void func_80070DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070DA0: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x80070DA4: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x80070DA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80070DAC: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_80070DB0:
    // 0x80070DB0: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x80070DB4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80070DB8: bne         $t9, $sp, L_80070DB0
    if (ctx->r25 != ctx->r29) {
        // 0x80070DBC: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_80070DB0;
    }
    // 0x80070DBC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80070DC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80070DC4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80070DC8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80070DCC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80070DD0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80070DD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80070DD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80070DDC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80070DE0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80070DE4: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    // 0x80070DE8: jal         0x8006F600
    // 0x80070DEC: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    Fault_DrawRec(rdram, ctx);
        goto after_0;
    // 0x80070DEC: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    after_0:
    // 0x80070DF0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070DF4: addiu       $a2, $a2, 0x1910
    ctx->r6 = ADD32(ctx->r6, 0X1910);
    // 0x80070DF8: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80070DFC: jal         0x8006F884
    // 0x80070E00: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x80070E00: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_1:
    // 0x80070E04: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80070E08: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x80070E0C: addiu       $s4, $s4, 0x191C
    ctx->r20 = ADD32(ctx->r20, 0X191C);
    // 0x80070E10: addiu       $s1, $s1, -0x6F70
    ctx->r17 = ADD32(ctx->r17, -0X6F70);
    // 0x80070E14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80070E18: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x80070E1C: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
    // 0x80070E20: addiu       $s2, $zero, 0x34
    ctx->r18 = ADD32(0, 0X34);
L_80070E24:
    // 0x80070E24: bgez        $s0, L_80070E38
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80070E28: andi        $t6, $s0, 0x3
        ctx->r14 = ctx->r16 & 0X3;
            goto L_80070E38;
    }
    // 0x80070E28: andi        $t6, $s0, 0x3
    ctx->r14 = ctx->r16 & 0X3;
    // 0x80070E2C: beq         $t6, $zero, L_80070E38
    if (ctx->r14 == 0) {
        // 0x80070E30: nop
    
            goto L_80070E38;
    }
    // 0x80070E30: nop

    // 0x80070E34: addiu       $t6, $t6, -0x4
    ctx->r14 = ADD32(ctx->r14, -0X4);
L_80070E38:
    // 0x80070E38: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070E3C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80070E40: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80070E44: mflo        $a0
    ctx->r4 = lo;
    // 0x80070E48: addiu       $a0, $a0, 0x52
    ctx->r4 = ADD32(ctx->r4, 0X52);
    // 0x80070E4C: bgez        $s0, L_80070E5C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80070E50: sra         $t7, $s0, 2
        ctx->r15 = S32(SIGNED(ctx->r16) >> 2);
            goto L_80070E5C;
    }
    // 0x80070E50: sra         $t7, $s0, 2
    ctx->r15 = S32(SIGNED(ctx->r16) >> 2);
    // 0x80070E54: addiu       $at, $s0, 0x3
    ctx->r1 = ADD32(ctx->r16, 0X3);
    // 0x80070E58: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_80070E5C:
    // 0x80070E5C: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070E60: mflo        $a1
    ctx->r5 = lo;
    // 0x80070E64: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x80070E68: jal         0x8006F884
    // 0x80070E6C: nop

    Fault_Printf(rdram, ctx);
        goto after_2;
    // 0x80070E6C: nop

    after_2:
    // 0x80070E70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80070E74: bne         $s0, $s5, L_80070E24
    if (ctx->r16 != ctx->r21) {
        // 0x80070E78: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80070E24;
    }
    // 0x80070E78: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80070E7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80070E80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80070E84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80070E88: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80070E8C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80070E90: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80070E94: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80070E98: jr          $ra
    // 0x80070E9C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80070E9C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806F7D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7D04: lw          $t6, 0x168($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X168);
    // 0x806F7D08: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7D0C: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x806F7D10: lw          $v0, 0x80($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X80);
    // 0x806F7D14: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x806F7D18: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806F7D1C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x806F7D20: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x806F7D24: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7D28: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x806F7D2C: ori         $t3, $t3, 0x150
    ctx->r11 = ctx->r11 | 0X150;
    // 0x806F7D30: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x806F7D34: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7D38: lui         $t2, 0xF550
    ctx->r10 = S32(0XF550 << 16);
    // 0x806F7D3C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x806F7D40: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x806F7D44: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7D48: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x806F7D4C: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x806F7D50: addiu       $t4, $a2, 0x8
    ctx->r12 = ADD32(ctx->r6, 0X8);
    // 0x806F7D54: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x806F7D58: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x806F7D5C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x806F7D60: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7D64: ori         $t8, $t8, 0xF200
    ctx->r24 = ctx->r24 | 0XF200;
    // 0x806F7D68: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x806F7D6C: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x806F7D70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806F7D74: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x806F7D78: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x806F7D7C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7D80: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x806F7D84: lui         $t4, 0xF548
    ctx->r12 = S32(0XF548 << 16);
    // 0x806F7D88: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x806F7D8C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7D90: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x806F7D94: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x806F7D98: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7D9C: ori         $t4, $t4, 0x800
    ctx->r12 = ctx->r12 | 0X800;
    // 0x806F7DA0: addiu       $t5, $zero, 0x150
    ctx->r13 = ADD32(0, 0X150);
    // 0x806F7DA4: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x806F7DA8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x806F7DAC: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x806F7DB0: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x806F7DB4: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7DB8: lui         $t8, 0x7
    ctx->r24 = S32(0X7 << 16);
    // 0x806F7DBC: ori         $t8, $t8, 0xC0FC
    ctx->r24 = ctx->r24 | 0XC0FC;
    // 0x806F7DC0: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x806F7DC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806F7DC8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x806F7DCC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x806F7DD0: jr          $ra
    // 0x806F7DD4: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    return;
    // 0x806F7DD4: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
;}
RECOMP_FUNC void func_80735CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735CC0: jr          $ra
    // 0x80735CC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80735CC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006D630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D630: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D634: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006D638: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006D63C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006D640: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006D644: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8006D648: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006D64C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D650: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8006D654: addiu       $s3, $zero, 0x2C
    ctx->r19 = ADD32(0, 0X2C);
    // 0x8006D658: lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X10);
L_8006D65C:
    // 0x8006D65C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8006D660: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8006D664: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D668: beql        $s2, $t8, L_8006D690
    if (ctx->r18 == ctx->r24) {
        // 0x8006D66C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006D690;
    }
    goto skip_0;
    // 0x8006D66C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8006D670: jal         0x8006D5F0
    // 0x8006D674: nop

    func_8006D5F0(rdram, ctx);
        goto after_0;
    // 0x8006D674: nop

    after_0:
    // 0x8006D678: beql        $v0, $zero, L_8006D690
    if (ctx->r2 == 0) {
        // 0x8006D67C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006D690;
    }
    goto skip_1;
    // 0x8006D67C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x8006D680: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8006D684: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8006D688: sh          $t0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r8;
    // 0x8006D68C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006D690:
    // 0x8006D690: bnel        $s0, $s3, L_8006D65C
    if (ctx->r16 != ctx->r19) {
        // 0x8006D694: lw          $t6, 0x10($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X10);
            goto L_8006D65C;
    }
    goto skip_2;
    // 0x8006D694: lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X10);
    skip_2:
    // 0x8006D698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006D69C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006D6A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006D6A4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D6A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006D6AC: jr          $ra
    // 0x8006D6B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006D6B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804D8878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D887C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804D8880: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804D8884: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804D8888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D888C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804D8890: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804D8894: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x804D8898: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804D889C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804D88A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804D88A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804D88A8: lui         $t2, 0x804E
    ctx->r10 = S32(RELOC_HI16(255, 0X7B4) << 16);
    // 0x804D88AC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804D88B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804D88B4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804D88B8: lw          $t2, -0x751C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(255, 0X7B4));
    // 0x804D88BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804D88C0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804D88C4: jal         0x804D88E4
    // 0x804D88C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804D88E4(rdram, ctx);
        goto after_0;
    // 0x804D88C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804D88CC: jal         0x804D895C
    // 0x804D88D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804D895C(rdram, ctx);
        goto after_1;
    // 0x804D88D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804D88D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D88D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D88DC: jr          $ra
    // 0x804D88E0: nop

    return;
    // 0x804D88E0: nop

;}
RECOMP_FUNC void func_80409B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409B1C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80409B20: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80409B24: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80409B28: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80409B2C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80409B30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80409B34: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_80409B38:
    // 0x80409B38: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80409B3C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80409B40: bne         $t6, $zero, L_80409B98
    if (ctx->r14 != 0) {
        // 0x80409B44: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80409B98;
    }
    // 0x80409B44: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409B48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80409B4C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80409B50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80409B54: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(11, 0X1F10) << 16);
    // 0x80409B58: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(11, 0X110C) << 16);
    // 0x80409B5C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80409B60: addiu       $t8, $t8, -0x6720
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(11, 0X1F10));
    // 0x80409B64: addiu       $t9, $t9, -0x7524
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(11, 0X110C));
    // 0x80409B68: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409B6C: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409B70: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409B74: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80409B78: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80409B7C: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x80409B80: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x80409B84: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x80409B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80409B8C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80409B90: b           L_80409CC4
    // 0x80409B94: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
        goto L_80409CC4;
    // 0x80409B94: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_80409B98:
    // 0x80409B98: lw          $t0, 0x58($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X58);
    // 0x80409B9C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409BA0: bne         $t0, $zero, L_80409BF8
    if (ctx->r8 != 0) {
        // 0x80409BA4: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80409BF8;
    }
    // 0x80409BA4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409BA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80409BAC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80409BB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80409BB4: lui         $t2, 0x8041
    ctx->r10 = S32(RELOC_HI16(11, 0X1F10) << 16);
    // 0x80409BB8: lui         $t3, 0x8041
    ctx->r11 = S32(RELOC_HI16(11, 0X110C) << 16);
    // 0x80409BBC: addiu       $t3, $t3, -0x7524
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(11, 0X110C));
    // 0x80409BC0: addiu       $t2, $t2, -0x6720
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(11, 0X1F10));
    // 0x80409BC4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80409BC8: sw          $t1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r9;
    // 0x80409BCC: sw          $t2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r10;
    // 0x80409BD0: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
    // 0x80409BD4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409BD8: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409BDC: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409BE0: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80409BE4: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80409BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80409BEC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80409BF0: b           L_80409CC4
    // 0x80409BF4: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
        goto L_80409CC4;
    // 0x80409BF4: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
L_80409BF8:
    // 0x80409BF8: lw          $t4, 0x58($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X58);
    // 0x80409BFC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409C00: bne         $t4, $zero, L_80409C58
    if (ctx->r12 != 0) {
        // 0x80409C04: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80409C58;
    }
    // 0x80409C04: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409C08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80409C0C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80409C10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80409C14: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0X1F10) << 16);
    // 0x80409C18: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(11, 0X110C) << 16);
    // 0x80409C1C: addiu       $t7, $t7, -0x7524
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(11, 0X110C));
    // 0x80409C20: addiu       $t6, $t6, -0x6720
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0X1F10));
    // 0x80409C24: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80409C28: sw          $t5, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r13;
    // 0x80409C2C: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x80409C30: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x80409C34: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409C38: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409C3C: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409C40: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80409C44: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80409C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80409C4C: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x80409C50: b           L_80409CC4
    // 0x80409C54: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
        goto L_80409CC4;
    // 0x80409C54: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
L_80409C58:
    // 0x80409C58: lw          $t8, 0x58($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X58);
    // 0x80409C5C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409C60: bne         $t8, $zero, L_80409CB8
    if (ctx->r24 != 0) {
        // 0x80409C64: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80409CB8;
    }
    // 0x80409C64: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80409C68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80409C6C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80409C70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80409C74: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(11, 0X1F10) << 16);
    // 0x80409C78: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(11, 0X110C) << 16);
    // 0x80409C7C: addiu       $t1, $t1, -0x7524
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(11, 0X110C));
    // 0x80409C80: addiu       $t0, $t0, -0x6720
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(11, 0X1F10));
    // 0x80409C84: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80409C88: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80409C8C: sw          $t0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r8;
    // 0x80409C90: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80409C94: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80409C98: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80409C9C: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80409CA0: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80409CA4: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80409CA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80409CAC: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80409CB0: b           L_80409CC4
    // 0x80409CB4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
        goto L_80409CC4;
    // 0x80409CB4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_80409CB8:
    // 0x80409CB8: bne         $v0, $v1, L_80409B38
    if (ctx->r2 != ctx->r3) {
        // 0x80409CBC: addiu       $a0, $a0, 0x30
        ctx->r4 = ADD32(ctx->r4, 0X30);
            goto L_80409B38;
    }
    // 0x80409CBC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80409CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80409CC4:
    // 0x80409CC4: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80409CC8: jr          $ra
    // 0x80409CCC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80409CCC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_807B9D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9D48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B9D4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B9D50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B9D54: jal         0x807B9C04
    // 0x807B9D58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807B9C04(rdram, ctx);
        goto after_0;
    // 0x807B9D58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807B9D5C: bne         $v0, $zero, L_807B9D6C
    if (ctx->r2 != 0) {
        // 0x807B9D60: nop
    
            goto L_807B9D6C;
    }
    // 0x807B9D60: nop

    // 0x807B9D64: b           L_807B9DA8
    // 0x807B9D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B9DA8;
    // 0x807B9D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B9D6C:
    // 0x807B9D6C: jal         0x807B9C48
    // 0x807B9D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B9C48(rdram, ctx);
        goto after_1;
    // 0x807B9D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807B9D74: bne         $v0, $zero, L_807B9D84
    if (ctx->r2 != 0) {
        // 0x807B9D78: nop
    
            goto L_807B9D84;
    }
    // 0x807B9D78: nop

    // 0x807B9D7C: b           L_807B9DA8
    // 0x807B9D80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B9DA8;
    // 0x807B9D80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B9D84:
    // 0x807B9D84: jal         0x807B9D04
    // 0x807B9D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B9D04(rdram, ctx);
        goto after_2;
    // 0x807B9D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807B9D8C: jal         0x807B845C
    // 0x807B9D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B845C(rdram, ctx);
        goto after_3;
    // 0x807B9D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807B9D94: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B9D98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B9D9C: lw          $t6, 0x44($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X44);
    // 0x807B9DA0: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x807B9DA4: sw          $t7, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r15;
L_807B9DA8:
    // 0x807B9DA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B9DAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B9DB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B9DB4: jr          $ra
    // 0x807B9DB8: nop

    return;
    // 0x807B9DB8: nop

;}
RECOMP_FUNC void func_8004CF54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CF54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004CF58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004CF5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004CF60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004CF64: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8004CF68: jal         0x8004BA14
    // 0x8004CF6C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_8004BA14(rdram, ctx);
        goto after_0;
    // 0x8004CF6C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x8004CF70: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8004CF74: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x8004CF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004CF7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004CF80: jr          $ra
    // 0x8004CF84: nop

    return;
    // 0x8004CF84: nop

;}
RECOMP_FUNC void func_804CE928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CE92C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CE930: jal         0x804CE8CC
    // 0x804CE934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804CE8CC(rdram, ctx);
        goto after_0;
    // 0x804CE934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CE938: bne         $v0, $zero, L_804CE948
    if (ctx->r2 != 0) {
        // 0x804CE93C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804CE948;
    }
    // 0x804CE93C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CE940: b           L_804CE98C
    // 0x804CE944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CE98C;
    // 0x804CE944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CE948:
    // 0x804CE948: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804CE94C: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(240, 0X19C4) << 16);
    // 0x804CE950: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x804CE954: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804CE958: addiu       $t6, $t6, -0x38C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(240, 0X19C4));
    // 0x804CE95C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804CE960: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804CE964: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804CE968: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
    // 0x804CE96C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CE970: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CE974: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CE978: jal         0x804CE99C
    // 0x804CE97C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_804CE99C(rdram, ctx);
        goto after_1;
    // 0x804CE97C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x804CE980: jal         0x804CE910
    // 0x804CE984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804CE910(rdram, ctx);
        goto after_2;
    // 0x804CE984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x804CE988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CE98C:
    // 0x804CE98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CE990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CE994: jr          $ra
    // 0x804CE998: nop

    return;
    // 0x804CE998: nop

;}
RECOMP_FUNC void func_804CEE78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEE78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CEE7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CEE80: jal         0x8004700C
    // 0x804CEE84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CEE84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CEE88: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804CEE8C: beq         $v0, $zero, L_804CEF18
    if (ctx->r2 == 0) {
        // 0x804CEE90: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_804CEF18;
    }
    // 0x804CEE90: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x804CEE94: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804CEE98: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CEE9C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B24) << 16);
    // 0x804CEEA0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804CEEA4: nop

    // 0x804CEEA8: bc1f        L_804CEEE8
    if (!c1cs) {
        // 0x804CEEAC: nop
    
            goto L_804CEEE8;
    }
    // 0x804CEEAC: nop

    // 0x804CEEB0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B1C) << 16);
    // 0x804CEEB4: lwc1        $f0, -0x234($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B1C));
    // 0x804CEEB8: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B20) << 16);
    // 0x804CEEBC: lwc1        $f10, -0x230($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B20));
    // 0x804CEEC0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CEEC4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804CEEC8: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x804CEECC: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CEED0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x804CEED4: nop

    // 0x804CEED8: bc1fl       L_804CEF1C
    if (!c1cs) {
        // 0x804CEEDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CEF1C;
    }
    goto skip_0;
    // 0x804CEEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804CEEE0: b           L_804CEF18
    // 0x804CEEE4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_804CEF18;
    // 0x804CEEE4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
L_804CEEE8:
    // 0x804CEEE8: lwc1        $f0, -0x22C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B24));
    // 0x804CEEEC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B28) << 16);
    // 0x804CEEF0: lwc1        $f6, -0x228($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B28));
    // 0x804CEEF4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CEEF8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804CEEFC: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x804CEF00: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CEF04: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804CEF08: nop

    // 0x804CEF0C: bc1fl       L_804CEF1C
    if (!c1cs) {
        // 0x804CEF10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CEF1C;
    }
    goto skip_1;
    // 0x804CEF10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804CEF14: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
L_804CEF18:
    // 0x804CEF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CEF1C:
    // 0x804CEF1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CEF20: jr          $ra
    // 0x804CEF24: nop

    return;
    // 0x804CEF24: nop

;}
RECOMP_FUNC void func_80580F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580F6C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80580F70: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80580F74: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80580F78: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80580F7C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80580F80: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80580F84: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80580F88: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(399, 0X4614) << 16);
    // 0x80580F8C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80580F90: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80580F94: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80580F98: lw          $t1, 0x3424($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(399, 0X4614));
    // 0x80580F9C: jr          $ra
    // 0x80580FA0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80580FA0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8044BAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BAA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044BAA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044BAAC: jal         0x8044B740
    // 0x8044BAB0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8044B740(rdram, ctx);
        goto after_0;
    // 0x8044BAB0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x8044BAB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044BAB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044BABC: jr          $ra
    // 0x8044BAC0: nop

    return;
    // 0x8044BAC0: nop

;}
RECOMP_FUNC void func_8078F0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F0A0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8078F0A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078F0A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8078F0AC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8078F0B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078F0B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078F0B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078F0BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8078F0C0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8078F0C4: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(811, 0X5E0) << 16);
    // 0x8078F0C8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8078F0CC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078F0D0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078F0D4: lw          $t1, -0xF20($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(811, 0X5E0));
    // 0x8078F0D8: jr          $ra
    // 0x8078F0DC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8078F0DC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8004FC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FC60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004FC64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FC68: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8004FC6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004FC70: beql        $a2, $zero, L_8004FC9C
    if (ctx->r6 == 0) {
        // 0x8004FC74: sw          $zero, 0x10($a1)
        MEM_W(0X10, ctx->r5) = 0;
            goto L_8004FC9C;
    }
    goto skip_0;
    // 0x8004FC74: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    skip_0:
    // 0x8004FC78: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x8004FC7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004FC80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004FC84: bnel        $t6, $at, L_8004FC9C
    if (ctx->r14 != ctx->r1) {
        // 0x8004FC88: sw          $zero, 0x10($a1)
        MEM_W(0X10, ctx->r5) = 0;
            goto L_8004FC9C;
    }
    goto skip_1;
    // 0x8004FC88: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    skip_1:
    // 0x8004FC8C: jal         0x80064E84
    // 0x8004FC90: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8004FC90: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004FC94: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8004FC98: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
L_8004FC9C:
    // 0x8004FC9C: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    // 0x8004FCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004FCA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004FCA8: jr          $ra
    // 0x8004FCAC: nop

    return;
    // 0x8004FCAC: nop

;}
RECOMP_FUNC void func_80408ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408ADC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80408AE0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80408AE4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80408AE8: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80408AEC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80408AF0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80408AF4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80408AF8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80408AFC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80408B00: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80408B04: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80408B08: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80408B0C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80408B10: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80408B14: beq         $t6, $zero, L_80408C90
    if (ctx->r14 == 0) {
        // 0x80408B18: addiu       $s4, $a1, 0xA00
        ctx->r20 = ADD32(ctx->r5, 0XA00);
            goto L_80408C90;
    }
    // 0x80408B18: addiu       $s4, $a1, 0xA00
    ctx->r20 = ADD32(ctx->r5, 0XA00);
    // 0x80408B1C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80408B20: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80408B24: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80408B28: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80408B2C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80408B30: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80408B34: nop

    // 0x80408B38: bgezl       $v0, L_80408B80
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80408B3C: lwc1        $f0, 0x10($s2)
        ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
            goto L_80408B80;
    }
    goto skip_0;
    // 0x80408B3C: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    skip_0:
    // 0x80408B40: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80408B44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80408B48: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80408B4C: bgez        $v0, L_80408B60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80408B50: andi        $t8, $v0, 0x7
        ctx->r24 = ctx->r2 & 0X7;
            goto L_80408B60;
    }
    // 0x80408B50: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x80408B54: beq         $t8, $zero, L_80408B60
    if (ctx->r24 == 0) {
        // 0x80408B58: nop
    
            goto L_80408B60;
    }
    // 0x80408B58: nop

    // 0x80408B5C: addiu       $t8, $t8, -0x8
    ctx->r24 = ADD32(ctx->r24, -0X8);
L_80408B60:
    // 0x80408B60: div.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80408B64: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80408B68: nop

    // 0x80408B6C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80408B70: mul.s       $f22, $f16, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80408B74: b           L_80408BC0
    // 0x80408B78: lw          $t4, 0x24($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X24);
        goto L_80408BC0;
    // 0x80408B78: lw          $t4, 0x24($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X24);
    // 0x80408B7C: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
L_80408B80:
    // 0x80408B80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80408B84: bgez        $v0, L_80408B98
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80408B88: andi        $t9, $v0, 0x7
        ctx->r25 = ctx->r2 & 0X7;
            goto L_80408B98;
    }
    // 0x80408B88: andi        $t9, $v0, 0x7
    ctx->r25 = ctx->r2 & 0X7;
    // 0x80408B8C: beq         $t9, $zero, L_80408B98
    if (ctx->r25 == 0) {
        // 0x80408B90: nop
    
            goto L_80408B98;
    }
    // 0x80408B90: nop

    // 0x80408B94: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_80408B98:
    // 0x80408B98: div.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80408B9C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80408BA0: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x80408BA4: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80408BA8: nop

    // 0x80408BAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80408BB0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80408BB4: mul.s       $f22, $f10, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80408BB8: nop

    // 0x80408BBC: lw          $t4, 0x24($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X24);
L_80408BC0:
    // 0x80408BC0: bgez        $v0, L_80408BD0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80408BC4: sra         $t2, $v0, 3
        ctx->r10 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80408BD0;
    }
    // 0x80408BC4: sra         $t2, $v0, 3
    ctx->r10 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80408BC8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80408BCC: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_80408BD0:
    // 0x80408BD0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80408BD4: addu        $s1, $s4, $t3
    ctx->r17 = ADD32(ctx->r20, ctx->r11);
    // 0x80408BD8: addiu       $s0, $s1, -0x4
    ctx->r16 = ADD32(ctx->r17, -0X4);
    // 0x80408BDC: blez        $t4, L_80408C90
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80408BE0: add.s       $f20, $f0, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f22.fl;
            goto L_80408C90;
    }
    // 0x80408BE0: add.s       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f22.fl;
L_80408BE4:
    // 0x80408BE4: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x80408BE8: bne         $at, $zero, L_80408C28
    if (ctx->r1 != 0) {
        // 0x80408BEC: addiu       $t5, $s5, 0xB40
        ctx->r13 = ADD32(ctx->r21, 0XB40);
            goto L_80408C28;
    }
    // 0x80408BEC: addiu       $t5, $s5, 0xB40
    ctx->r13 = ADD32(ctx->r21, 0XB40);
    // 0x80408BF0: sltu        $at, $s1, $t5
    ctx->r1 = ctx->r17 < ctx->r13 ? 1 : 0;
    // 0x80408BF4: beql        $at, $zero, L_80408C2C
    if (ctx->r1 == 0) {
        // 0x80408BF8: sltu        $at, $s0, $s4
        ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
            goto L_80408C2C;
    }
    goto skip_1;
    // 0x80408BF8: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    skip_1:
    // 0x80408BFC: jal         0x80066E88
    // 0x80408C00: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80408C00: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80408C04: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80408C08: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80408C0C: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80408C10: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80408C14: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80408C18: nop

    // 0x80408C1C: bc1fl       L_80408C2C
    if (!c1cs) {
        // 0x80408C20: sltu        $at, $s0, $s4
        ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
            goto L_80408C2C;
    }
    goto skip_2;
    // 0x80408C20: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    skip_2:
    // 0x80408C24: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
L_80408C28:
    // 0x80408C28: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
L_80408C2C:
    // 0x80408C2C: bne         $at, $zero, L_80408C6C
    if (ctx->r1 != 0) {
        // 0x80408C30: addiu       $t6, $s5, 0xB40
        ctx->r14 = ADD32(ctx->r21, 0XB40);
            goto L_80408C6C;
    }
    // 0x80408C30: addiu       $t6, $s5, 0xB40
    ctx->r14 = ADD32(ctx->r21, 0XB40);
    // 0x80408C34: sltu        $at, $s0, $t6
    ctx->r1 = ctx->r16 < ctx->r14 ? 1 : 0;
    // 0x80408C38: beql        $at, $zero, L_80408C70
    if (ctx->r1 == 0) {
        // 0x80408C3C: lwc1        $f18, 0x10($s2)
        ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
            goto L_80408C70;
    }
    goto skip_3;
    // 0x80408C3C: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
    skip_3:
    // 0x80408C40: jal         0x80066E88
    // 0x80408C44: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80408C44: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80408C48: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80408C4C: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x80408C50: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80408C54: mul.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80408C58: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80408C5C: nop

    // 0x80408C60: bc1fl       L_80408C70
    if (!c1cs) {
        // 0x80408C64: lwc1        $f18, 0x10($s2)
        ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
            goto L_80408C70;
    }
    goto skip_4;
    // 0x80408C64: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
    skip_4:
    // 0x80408C68: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_80408C6C:
    // 0x80408C6C: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
L_80408C70:
    // 0x80408C70: lw          $t7, 0x24($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X24);
    // 0x80408C74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80408C78: sub.s       $f22, $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f18.fl;
    // 0x80408C7C: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80408C80: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80408C84: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x80408C88: bne         $at, $zero, L_80408BE4
    if (ctx->r1 != 0) {
        // 0x80408C8C: addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
            goto L_80408BE4;
    }
    // 0x80408C8C: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_80408C90:
    // 0x80408C90: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80408C94: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80408C98: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80408C9C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80408CA0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80408CA4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80408CA8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80408CAC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80408CB0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80408CB4: jr          $ra
    // 0x80408CB8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80408CB8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_804085E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804085E4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804085E8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804085EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804085F0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804085F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804085F8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804085FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80408600: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80408604: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80408608: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8040860C: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(11, 0X2DC8) << 16);
    // 0x80408610: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80408614: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80408618: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8040861C: lw          $t1, -0x5868($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(11, 0X2DC8));
    // 0x80408620: jr          $ra
    // 0x80408624: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80408624: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_807AD2EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD2EC: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x807AD2F0: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x807AD2F4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807AD2F8: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x807AD2FC: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(859, 0X25EC) << 16);
    // 0x807AD300: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807AD304: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x807AD308: addiu       $t8, $t8, -0x13B4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(859, 0X25EC));
    // 0x807AD30C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x807AD310: lui         $t9, 0x807B
    ctx->r25 = S32(RELOC_HI16(859, 0XB6C) << 16);
    // 0x807AD314: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AD318: addiu       $t9, $t9, -0x2E34
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(859, 0XB6C));
    // 0x807AD31C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807AD320: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807AD324: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x807AD328: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x807AD32C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AD330: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x807AD334: addiu       $v0, $v1, 0xD
    ctx->r2 = ADD32(ctx->r3, 0XD);
    // 0x807AD338: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
    // 0x807AD33C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807AD340: jr          $ra
    // 0x807AD344: sb          $a1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r5;
    return;
    // 0x807AD344: sb          $a1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_80451F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451F0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80451F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80451F14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80451F18: jal         0x80450F94
    // 0x80451F1C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80450F94(rdram, ctx);
        goto after_0;
    // 0x80451F1C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80451F20: jal         0x804507C4
    // 0x80451F24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804507C4(rdram, ctx);
        goto after_1;
    // 0x80451F24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80451F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80451F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80451F30: jr          $ra
    // 0x80451F34: nop

    return;
    // 0x80451F34: nop

;}
RECOMP_FUNC void func_806EE924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE924: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EE928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EE92C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806EE930: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806EE934: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806EE938: jal         0x806EC16C
    // 0x806EE93C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EE93C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x806EE940: lw          $t6, 0x1F4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1F4);
    // 0x806EE944: jal         0x800577D8
    // 0x806EE948: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EE948: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EE94C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806EE950: lui         $v1, 0x806F
    ctx->r3 = S32(RELOC_HI16(676, 0X4A14) << 16);
    // 0x806EE954: addiu       $v1, $v1, 0x964
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(676, 0X4A14));
    // 0x806EE958: swc1        $f4, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f4.u32l;
    // 0x806EE95C: lh          $t7, 0x12($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X12);
    // 0x806EE960: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x806EE964: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x806EE968: sh          $t8, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r24;
    // 0x806EE96C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x806EE970: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x806EE974: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x806EE978: lh          $t9, 0x12($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X12);
    // 0x806EE97C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x806EE980: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x806EE984: bne         $at, $zero, L_806EEA24
    if (ctx->r1 != 0) {
        // 0x806EE988: nop
    
            goto L_806EEA24;
    }
    // 0x806EE988: nop

    // 0x806EE98C: sh          $t3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r11;
    // 0x806EE990: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x806EE994: sh          $zero, 0x12($s0)
    MEM_H(0X12, ctx->r16) = 0;
    // 0x806EE998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806EE99C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x806EE9A0: bne         $at, $zero, L_806EE9C8
    if (ctx->r1 != 0) {
        // 0x806EE9A4: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_806EE9C8;
    }
    // 0x806EE9A4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x806EE9A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EE9AC: lbu         $a2, 0x8($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X8);
    // 0x806EE9B0: jal         0x806EF4A0
    // 0x806EE9B4: lw          $a3, 0x12C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X12C);
    func_806EF4A0(rdram, ctx);
        goto after_2;
    // 0x806EE9B4: lw          $a3, 0x12C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X12C);
    after_2:
    // 0x806EE9B8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x806EE9BC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x806EE9C0: b           L_806EEA24
    // 0x806EE9C4: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
        goto L_806EEA24;
    // 0x806EE9C4: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
L_806EE9C8:
    // 0x806EE9C8: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x806EE9CC: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x806EE9D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806EE9D4: sh          $t6, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r14;
    // 0x806EE9D8: lh          $t7, 0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X10);
    // 0x806EE9DC: bne         $t7, $at, L_806EEA24
    if (ctx->r15 != ctx->r1) {
        // 0x806EE9E0: nop
    
            goto L_806EEA24;
    }
    // 0x806EE9E0: nop

    // 0x806EE9E4: lw          $t8, 0x12C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X12C);
    // 0x806EE9E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EE9EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806EE9F0: bne         $t8, $zero, L_806EEA08
    if (ctx->r24 != 0) {
        // 0x806EE9F4: nop
    
            goto L_806EEA08;
    }
    // 0x806EE9F4: nop

    // 0x806EE9F8: jal         0x806EF1E4
    // 0x806EE9FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806EF1E4(rdram, ctx);
        goto after_3;
    // 0x806EE9FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x806EEA00: b           L_806EEA14
    // 0x806EEA04: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_806EEA14;
    // 0x806EEA04: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_806EEA08:
    // 0x806EEA08: jal         0x806EF1E4
    // 0x806EEA0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806EF1E4(rdram, ctx);
        goto after_4;
    // 0x806EEA0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x806EEA10: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_806EEA14:
    // 0x806EEA14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806EEA18: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806EEA1C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806EEA20: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
L_806EEA24:
    // 0x806EEA24: jal         0x806EE664
    // 0x806EEA28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806EE664(rdram, ctx);
        goto after_5;
    // 0x806EEA28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x806EEA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EEA30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806EEA34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806EEA38: jr          $ra
    // 0x806EEA3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806EEA3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80036CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036CBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036CC0: lw          $t6, 0x78($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X78);
    // 0x80036CC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036CC8: beq         $t6, $zero, L_80036CE0
    if (ctx->r14 == 0) {
        // 0x80036CCC: nop
    
            goto L_80036CE0;
    }
    // 0x80036CCC: nop

    // 0x80036CD0: jal         0x8002F15C
    // 0x80036CD4: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_8002F15C(rdram, ctx);
        goto after_0;
    // 0x80036CD4: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x80036CD8: b           L_80036CE0
    // 0x80036CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036CE0;
    // 0x80036CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036CE0:
    // 0x80036CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036CE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036CE8: jr          $ra
    // 0x80036CEC: nop

    return;
    // 0x80036CEC: nop

;}
RECOMP_FUNC void func_8045FD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FD78: jr          $ra
    // 0x8045FD7C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8045FD7C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80434120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434120: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434124: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80434128: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    // 0x8043412C: addiu       $v1, $v0, 0x7B0
    ctx->r3 = ADD32(ctx->r2, 0X7B0);
L_80434130:
    // 0x80434130: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80434134: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80434138: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8043413C: nop

    // 0x80434140: bc1f        L_80434150
    if (!c1cs) {
        // 0x80434144: nop
    
            goto L_80434150;
    }
    // 0x80434144: nop

    // 0x80434148: jr          $ra
    // 0x8043414C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8043414C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80434150:
    // 0x80434150: bgez        $a1, L_80434130
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80434154: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80434130;
    }
    // 0x80434154: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80434158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043415C: jr          $ra
    // 0x80434160: nop

    return;
    // 0x80434160: nop

;}
RECOMP_FUNC void func_8070C798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070C798: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8070C79C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070C7A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070C7A4: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x8070C7A8: nop

    // 0x8070C7AC: bc1fl       L_8070C7C0
    if (!c1cs) {
        // 0x8070C7B0: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_8070C7C0;
    }
    goto skip_0;
    // 0x8070C7B0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x8070C7B4: b           L_8070C7E4
    // 0x8070C7B8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8070C7E4;
    // 0x8070C7B8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8070C7BC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_8070C7C0:
    // 0x8070C7C0: jal         0x80065414
    // 0x8070C7C4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x8070C7C4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8070C7C8: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x8070C7CC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8070C7D0: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8070C7D4: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8070C7D8: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8070C7DC: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8070C7E0: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_8070C7E4:
    // 0x8070C7E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070C7E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070C7EC: jr          $ra
    // 0x8070C7F0: nop

    return;
    // 0x8070C7F0: nop

;}
RECOMP_FUNC void func_806DF6E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF6E0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806DF6E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806DF6E8: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x806DF6EC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_806DF6F0:
    // 0x806DF6F0: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x806DF6F4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806DF6F8: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x806DF6FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806DF700: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806DF704: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806DF708: bc1f        L_806DF72C
    if (!c1cs) {
        // 0x806DF70C: swc1        $f8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
            goto L_806DF72C;
    }
    // 0x806DF70C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x806DF710: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806DF714: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806DF718: nop

    // 0x806DF71C: bc1f        L_806DF744
    if (!c1cs) {
        // 0x806DF720: nop
    
            goto L_806DF744;
    }
    // 0x806DF720: nop

    // 0x806DF724: b           L_806DF744
    // 0x806DF728: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_806DF744;
    // 0x806DF728: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_806DF72C:
    // 0x806DF72C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806DF730: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806DF734: nop

    // 0x806DF738: bc1f        L_806DF744
    if (!c1cs) {
        // 0x806DF73C: nop
    
            goto L_806DF744;
    }
    // 0x806DF73C: nop

    // 0x806DF740: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_806DF744:
    // 0x806DF744: bne         $v1, $v0, L_806DF6F0
    if (ctx->r3 != ctx->r2) {
        // 0x806DF748: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_806DF6F0;
    }
    // 0x806DF748: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806DF74C: jr          $ra
    // 0x806DF750: nop

    return;
    // 0x806DF750: nop

;}
RECOMP_FUNC void func_804649C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804649C8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x804649CC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x804649D0: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x804649D4: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x804649D8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x804649DC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x804649E0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x804649E4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x804649E8: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x804649EC: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804649F0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804649F4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804649F8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804649FC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80464A00: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x80464A04: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80464A08: lw          $v0, 0x1250($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X1250);
    // 0x80464A0C: addiu       $s1, $s5, 0x1254
    ctx->r17 = ADD32(ctx->r21, 0X1254);
    // 0x80464A10: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80464A14: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80464A18: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80464A1C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80464A20: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80464A24: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80464A28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80464A2C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80464A30: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80464A34: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80464A38: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80464A3C: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x80464A40: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80464A44: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80464A48: sll         $t8, $t8, 9
    ctx->r24 = S32(ctx->r24 << 9);
    // 0x80464A4C: lwc1        $f14, 0xC4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80464A50: addu        $s0, $s5, $t8
    ctx->r16 = ADD32(ctx->r21, ctx->r24);
    // 0x80464A54: addiu       $s0, $s0, 0x1318
    ctx->r16 = ADD32(ctx->r16, 0X1318);
    // 0x80464A58: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x80464A5C: jal         0x80067114
    // 0x80464A60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x80464A60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x80464A64: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80464A68: jal         0x80066DE4
    // 0x80464A6C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80464A6C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80464A70: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80464A74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80464A78: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80464A7C: mul.s       $f30, $f0, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80464A80: jal         0x80066E88
    // 0x80464A84: nop

    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80464A84: nop

    after_2:
    // 0x80464A88: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80464A8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80464A90: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80464A94: mul.s       $f26, $f0, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80464A98: jal         0x80066E88
    // 0x80464A9C: nop

    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x80464A9C: nop

    after_3:
    // 0x80464AA0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80464AA4: jal         0x80066DE4
    // 0x80464AA8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x80464AA8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_4:
    // 0x80464AAC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E00) << 16);
    // 0x80464AB0: lwc1        $f8, 0x63D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E00));
    // 0x80464AB4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80464AB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80464ABC: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80464AC0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80464AC4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80464AC8: jal         0x80066DE4
    // 0x80464ACC: sub.s       $f28, $f10, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f10.fl - ctx->f18.fl;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x80464ACC: sub.s       $f28, $f10, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f10.fl - ctx->f18.fl;
    after_5:
    // 0x80464AD0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80464AD4: jal         0x80066E88
    // 0x80464AD8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x80464AD8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_6:
    // 0x80464ADC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80464AE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80464AE4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E04) << 16);
    // 0x80464AE8: lwc1        $f8, 0x63D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E04));
    // 0x80464AEC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80464AF0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80464AF4: mul.s       $f16, $f8, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80464AF8: jal         0x80066E88
    // 0x80464AFC: add.s       $f20, $f6, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f16.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x80464AFC: add.s       $f20, $f6, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f16.fl;
    after_7:
    // 0x80464B00: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E08) << 16);
    // 0x80464B04: lwc1        $f10, 0x63D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E08));
    // 0x80464B08: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80464B0C: mul.s       $f22, $f0, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80464B10: jal         0x80066DE4
    // 0x80464B14: nop

    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x80464B14: nop

    after_8:
    // 0x80464B18: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E0C) << 16);
    // 0x80464B1C: lwc1        $f18, 0x63DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E0C));
    // 0x80464B20: lw          $s2, 0x1F18($s5)
    ctx->r18 = MEM_W(ctx->r21, 0X1F18);
    // 0x80464B24: addiu       $s4, $sp, 0xA0
    ctx->r20 = ADD32(ctx->r29, 0XA0);
    // 0x80464B28: mul.s       $f24, $f0, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80464B2C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80464B30: bltz        $s2, L_80464BEC
    if (SIGNED(ctx->r18) < 0) {
        // 0x80464B34: nop
    
            goto L_80464BEC;
    }
    // 0x80464B34: nop

    // 0x80464B38: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
L_80464B3C:
    // 0x80464B3C: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80464B40: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80464B44: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80464B48: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80464B4C: slti        $at, $s3, 0x20
    ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
    // 0x80464B50: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80464B54: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80464B58: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80464B5C: add.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f30.fl;
    // 0x80464B60: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80464B64: sh          $t0, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = ctx->r8;
    // 0x80464B68: add.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f28.fl;
    // 0x80464B6C: sh          $t2, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = ctx->r10;
    // 0x80464B70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80464B74: add.s       $f10, $f2, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f26.fl;
    // 0x80464B78: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80464B7C: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80464B80: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80464B84: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80464B88: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80464B8C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80464B90: sh          $t4, -0x30($s0)
    MEM_H(-0X30, ctx->r16) = ctx->r12;
    // 0x80464B94: add.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80464B98: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80464B9C: sh          $t6, -0x2E($s0)
    MEM_H(-0X2E, ctx->r16) = ctx->r14;
    // 0x80464BA0: add.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x80464BA4: sh          $t8, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r24;
    // 0x80464BA8: add.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80464BAC: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80464BB0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80464BB4: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80464BB8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80464BBC: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80464BC0: sh          $t0, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r8;
    // 0x80464BC4: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80464BC8: sh          $t2, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r10;
    // 0x80464BCC: bne         $at, $zero, L_80464BE0
    if (ctx->r1 != 0) {
        // 0x80464BD0: sh          $t4, -0xE($s0)
        MEM_H(-0XE, ctx->r16) = ctx->r12;
            goto L_80464BE0;
    }
    // 0x80464BD0: sh          $t4, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r12;
    // 0x80464BD4: jal         0x804648EC
    // 0x80464BD8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_804648EC(rdram, ctx);
        goto after_9;
    // 0x80464BD8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_9:
    // 0x80464BDC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80464BE0:
    // 0x80464BE0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80464BE4: bgezl       $s2, L_80464B3C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80464BE8: lwc1        $f0, 0x0($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80464B3C;
    }
    goto skip_0;
    // 0x80464BE8: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    skip_0:
L_80464BEC:
    // 0x80464BEC: blez        $s3, L_80464C04
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80464BF0: addiu       $s4, $sp, 0xA0
        ctx->r20 = ADD32(ctx->r29, 0XA0);
            goto L_80464C04;
    }
    // 0x80464BF0: addiu       $s4, $sp, 0xA0
    ctx->r20 = ADD32(ctx->r29, 0XA0);
    // 0x80464BF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80464BF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80464BFC: jal         0x804648EC
    // 0x80464C00: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_804648EC(rdram, ctx);
        goto after_10;
    // 0x80464C00: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_10:
L_80464C04:
    // 0x80464C04: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x80464C08: lui         $t7, 0xB800
    ctx->r15 = S32(0XB800 << 16);
    // 0x80464C0C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80464C10: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x80464C14: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80464C18: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80464C1C: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80464C20: sw          $t8, 0x1250($s5)
    MEM_W(0X1250, ctx->r21) = ctx->r24;
    // 0x80464C24: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80464C28: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80464C2C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80464C30: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80464C34: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80464C38: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80464C3C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80464C40: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80464C44: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80464C48: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80464C4C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80464C50: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80464C54: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80464C58: jr          $ra
    // 0x80464C5C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80464C5C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80792220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792220: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80792224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80792228: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8079222C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80792230: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80792234: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80792238: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x8079223C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80792240: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792244: jal         0x807903C4
    // 0x80792248: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80792248: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8079224C: jal         0x80790714
    // 0x80792250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80792250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80792254: beq         $v0, $zero, L_807922A8
    if (ctx->r2 == 0) {
        // 0x80792258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807922A8;
    }
    // 0x80792258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079225C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792260: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80792264: jal         0x8079393C
    // 0x80792268: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80792268: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_2:
    // 0x8079226C: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80792270: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80792274: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x80792278: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8079227C: swc1        $f4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f4.u32l;
    // 0x80792280: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AEC) << 16);
    // 0x80792284: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80792288: lwc1        $f8, 0x7E3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AEC));
    // 0x8079228C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792290: jal         0x80790C34
    // 0x80792294: swc1        $f8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f8.u32l;
    func_80790C34(rdram, ctx);
        goto after_3;
    // 0x80792294: swc1        $f8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f8.u32l;
    after_3:
    // 0x80792298: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AF0) << 16);
    // 0x8079229C: lwc1        $f10, 0x7E40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AF0));
    // 0x807922A0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807922A4: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
L_807922A8:
    // 0x807922A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807922AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807922B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807922B4: jr          $ra
    // 0x807922B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807922B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804709D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804709D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804709D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804709DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804709E0: jal         0x80470104
    // 0x804709E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80470104(rdram, ctx);
        goto after_0;
    // 0x804709E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804709E8: jal         0x8046FC20
    // 0x804709EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046FC20(rdram, ctx);
        goto after_1;
    // 0x804709EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804709F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804709F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804709F8: jal         0x80470DE8
    // 0x804709FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80470DE8(rdram, ctx);
        goto after_2;
    // 0x804709FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80470A00: jal         0x800564D0
    // 0x80470A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800564D0(rdram, ctx);
        goto after_3;
    // 0x80470A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80470A08: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80470A0C: jal         0x8046FC9C
    // 0x80470A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046FC9C(rdram, ctx);
        goto after_4;
    // 0x80470A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80470A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80470A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80470A1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80470A20: jr          $ra
    // 0x80470A24: nop

    return;
    // 0x80470A24: nop

;}
RECOMP_FUNC void func_8040A2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040A2F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040A2F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040A2FC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8040A300: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040A304: addiu       $a2, $a1, 0xB50
    ctx->r6 = ADD32(ctx->r5, 0XB50);
    // 0x8040A308: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8040A30C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8040A310: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8040A314: jal         0x80409188
    // 0x8040A318: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80409188(rdram, ctx);
        goto after_0;
    // 0x8040A318: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x8040A31C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8040A320: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8040A324: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8040A328: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8040A32C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8040A330: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040A334: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8040A338: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8040A33C: sw          $zero, 0xB4C($a1)
    MEM_W(0XB4C, ctx->r5) = 0;
    // 0x8040A340: swc1        $f0, 0xB40($a1)
    MEM_W(0XB40, ctx->r5) = ctx->f0.u32l;
    // 0x8040A344: swc1        $f0, 0xB48($a1)
    MEM_W(0XB48, ctx->r5) = ctx->f0.u32l;
    // 0x8040A348: swc1        $f4, 0xB44($a1)
    MEM_W(0XB44, ctx->r5) = ctx->f4.u32l;
L_8040A34C:
    // 0x8040A34C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8040A350: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x8040A354: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x8040A358: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x8040A35C: sw          $zero, 0x50($v0)
    MEM_W(0X50, ctx->r2) = 0;
    // 0x8040A360: sw          $zero, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = 0;
    // 0x8040A364: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x8040A368: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x8040A36C: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
    // 0x8040A370: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x8040A374: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x8040A378: sw          $zero, 0x80($v0)
    MEM_W(0X80, ctx->r2) = 0;
    // 0x8040A37C: sw          $zero, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = 0;
    // 0x8040A380: sw          $zero, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = 0;
    // 0x8040A384: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x8040A388: swc1        $f0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f0.u32l;
    // 0x8040A38C: swc1        $f0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f0.u32l;
    // 0x8040A390: swc1        $f0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f0.u32l;
    // 0x8040A394: sw          $zero, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = 0;
    // 0x8040A398: sw          $zero, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = 0;
    // 0x8040A39C: sw          $zero, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = 0;
    // 0x8040A3A0: sw          $zero, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = 0;
    // 0x8040A3A4: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x8040A3A8: swc1        $f0, -0xB8($v0)
    MEM_W(-0XB8, ctx->r2) = ctx->f0.u32l;
    // 0x8040A3AC: swc1        $f0, -0xBC($v0)
    MEM_W(-0XBC, ctx->r2) = ctx->f0.u32l;
    // 0x8040A3B0: swc1        $f0, -0xC0($v0)
    MEM_W(-0XC0, ctx->r2) = ctx->f0.u32l;
    // 0x8040A3B4: sw          $zero, -0xA0($v0)
    MEM_W(-0XA0, ctx->r2) = 0;
    // 0x8040A3B8: sw          $zero, -0xA4($v0)
    MEM_W(-0XA4, ctx->r2) = 0;
    // 0x8040A3BC: sw          $zero, -0x94($v0)
    MEM_W(-0X94, ctx->r2) = 0;
    // 0x8040A3C0: bne         $v1, $a0, L_8040A34C
    if (ctx->r3 != ctx->r4) {
        // 0x8040A3C4: sw          $zero, -0x98($v0)
        MEM_W(-0X98, ctx->r2) = 0;
            goto L_8040A34C;
    }
    // 0x8040A3C4: sw          $zero, -0x98($v0)
    MEM_W(-0X98, ctx->r2) = 0;
    // 0x8040A3C8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8040A3CC: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(11, 0X2720) << 16);
    // 0x8040A3D0: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(11, 0X276C) << 16);
    // 0x8040A3D4: addiu       $t8, $t8, -0x5F10
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(11, 0X2720));
    // 0x8040A3D8: addiu       $t9, $t9, -0x5EC4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(11, 0X276C));
    // 0x8040A3DC: sw          $a2, 0x115C($a1)
    MEM_W(0X115C, ctx->r5) = ctx->r6;
    // 0x8040A3E0: sw          $t8, 0x1160($a1)
    MEM_W(0X1160, ctx->r5) = ctx->r24;
    // 0x8040A3E4: sw          $t9, 0x1164($a1)
    MEM_W(0X1164, ctx->r5) = ctx->r25;
    // 0x8040A3E8: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8040A3EC: sw          $t7, 0x1150($a1)
    MEM_W(0X1150, ctx->r5) = ctx->r15;
    // 0x8040A3F0: lw          $t1, -0x6DA8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6DA8);
    // 0x8040A3F4: addiu       $t0, $a1, 0x1150
    ctx->r8 = ADD32(ctx->r5, 0X1150);
    // 0x8040A3F8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8040A3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040A400: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8040A404: jr          $ra
    // 0x8040A408: nop

    return;
    // 0x8040A408: nop

;}
RECOMP_FUNC void func_804F5134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5134: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x804F5138: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x804F513C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804F5140: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804F5144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F5148: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x804F514C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804F5150: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804F5154: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x804F5158: bc1f        L_804F51D8
    if (!c1cs) {
        // 0x804F515C: lw          $s1, 0x1F4($a0)
        ctx->r17 = MEM_W(ctx->r4, 0X1F4);
            goto L_804F51D8;
    }
    // 0x804F515C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F5160: lui         $at, 0x4378
    ctx->r1 = S32(0X4378 << 16);
    // 0x804F5164: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804F5168: nop

    // 0x804F516C: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x804F5170: nop

    // 0x804F5174: bc1f        L_804F51D8
    if (!c1cs) {
        // 0x804F5178: nop
    
            goto L_804F51D8;
    }
    // 0x804F5178: nop

    // 0x804F517C: lw          $t6, 0x6C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X6C);
    // 0x804F5180: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x804F5184: addiu       $s0, $s1, 0x68
    ctx->r16 = ADD32(ctx->r17, 0X68);
    // 0x804F5188: beq         $t6, $zero, L_804F51BC
    if (ctx->r14 == 0) {
        // 0x804F518C: addiu       $v0, $v0, 0x6
        ctx->r2 = ADD32(ctx->r2, 0X6);
            goto L_804F51BC;
    }
    // 0x804F518C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x804F5190: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x804F5194: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X207E8) << 16);
    // 0x804F5198: addiu       $a1, $a1, 0x4A78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X207E8));
    // 0x804F519C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x804F51A0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x804F51A4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x804F51A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F51AC: jal         0x804F4C88
    // 0x804F51B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804F4C88(rdram, ctx);
        goto after_0;
    // 0x804F51B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x804F51B4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x804F51B8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_804F51BC:
    // 0x804F51BC: lw          $t9, 0x6C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X6C);
    // 0x804F51C0: lui         $t1, 0x8051
    ctx->r9 = S32(RELOC_HI16(273, 0X207AC) << 16);
    // 0x804F51C4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x804F51C8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804F51CC: lhu         $t1, 0x4A3C($t1)
    ctx->r9 = MEM_HU(ctx->r9, (int16_t)RELOC_LO16(273, 0X207AC));
    // 0x804F51D0: b           L_804F5284
    // 0x804F51D4: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
        goto L_804F5284;
    // 0x804F51D4: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_804F51D8:
    // 0x804F51D8: jal         0x804F4CF8
    // 0x804F51DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804F4CF8(rdram, ctx);
        goto after_1;
    // 0x804F51DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x804F51E0: bne         $v0, $zero, L_804F5284
    if (ctx->r2 != 0) {
        // 0x804F51E4: nop
    
            goto L_804F5284;
    }
    // 0x804F51E4: nop

    // 0x804F51E8: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x804F51EC: addiu       $s0, $s1, 0x68
    ctx->r16 = ADD32(ctx->r17, 0X68);
    // 0x804F51F0: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X207F0) << 16);
    // 0x804F51F4: addiu       $t3, $t2, 0x6
    ctx->r11 = ADD32(ctx->r10, 0X6);
    // 0x804F51F8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x804F51FC: lw          $t4, 0x7C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X7C);
    // 0x804F5200: addiu       $a1, $a1, 0x4A80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X207F0));
    // 0x804F5204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F5208: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x804F520C: blez        $t5, L_804F5234
    if (SIGNED(ctx->r13) <= 0) {
        // 0x804F5210: sw          $t5, 0x7C($s1)
        MEM_W(0X7C, ctx->r17) = ctx->r13;
            goto L_804F5234;
    }
    // 0x804F5210: sw          $t5, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r13;
    // 0x804F5214: addiu       $s0, $s1, 0x68
    ctx->r16 = ADD32(ctx->r17, 0X68);
    // 0x804F5218: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X207E8) << 16);
    // 0x804F521C: addiu       $a1, $a1, 0x4A78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X207E8));
    // 0x804F5220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F5224: jal         0x804F4C88
    // 0x804F5228: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804F4C88(rdram, ctx);
        goto after_2;
    // 0x804F5228: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x804F522C: b           L_804F5250
    // 0x804F5230: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
        goto L_804F5250;
    // 0x804F5230: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_804F5234:
    // 0x804F5234: jal         0x804F4C88
    // 0x804F5238: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_804F4C88(rdram, ctx);
        goto after_3;
    // 0x804F5238: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x804F523C: jal         0x800653D8
    // 0x804F5240: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x804F5240: nop

    after_4:
    // 0x804F5244: andi        $t7, $v0, 0x7
    ctx->r15 = ctx->r2 & 0X7;
    // 0x804F5248: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x804F524C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_804F5250:
    // 0x804F5250: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x804F5254: lui         $t3, 0x8051
    ctx->r11 = S32(RELOC_HI16(273, 0X207AC) << 16);
    // 0x804F5258: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804F525C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804F5260: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x804F5264: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x804F5268: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x804F526C: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x804F5270: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x804F5274: lhu         $t3, 0x4A3C($t3)
    ctx->r11 = MEM_HU(ctx->r11, (int16_t)RELOC_LO16(273, 0X207AC));
    // 0x804F5278: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x804F527C: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x804F5280: sw          $t5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r13;
L_804F5284:
    // 0x804F5284: jal         0x804F4D88
    // 0x804F5288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804F4D88(rdram, ctx);
        goto after_5;
    // 0x804F5288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x804F528C: bne         $v0, $zero, L_804F5350
    if (ctx->r2 != 0) {
        // 0x804F5290: nop
    
            goto L_804F5350;
    }
    // 0x804F5290: nop

    // 0x804F5294: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x804F5298: addiu       $s0, $s1, 0x80
    ctx->r16 = ADD32(ctx->r17, 0X80);
    // 0x804F529C: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20830) << 16);
    // 0x804F52A0: addiu       $t6, $v0, 0xC
    ctx->r14 = ADD32(ctx->r2, 0XC);
    // 0x804F52A4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x804F52A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804F52AC: lw          $t7, 0x94($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X94);
    // 0x804F52B0: addiu       $a1, $a1, 0x4AC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20830));
    // 0x804F52B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F52B8: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x804F52BC: blez        $t9, L_804F52E4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x804F52C0: sw          $t9, 0x94($s1)
        MEM_W(0X94, ctx->r17) = ctx->r25;
            goto L_804F52E4;
    }
    // 0x804F52C0: sw          $t9, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r25;
    // 0x804F52C4: addiu       $s0, $s1, 0x80
    ctx->r16 = ADD32(ctx->r17, 0X80);
    // 0x804F52C8: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20840) << 16);
    // 0x804F52CC: addiu       $a1, $a1, 0x4AD0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20840));
    // 0x804F52D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F52D4: jal         0x804F4C88
    // 0x804F52D8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_804F4C88(rdram, ctx);
        goto after_6;
    // 0x804F52D8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x804F52DC: b           L_804F5300
    // 0x804F52E0: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
        goto L_804F5300;
    // 0x804F52E0: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
L_804F52E4:
    // 0x804F52E4: jal         0x804F4C88
    // 0x804F52E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_804F4C88(rdram, ctx);
        goto after_7;
    // 0x804F52E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x804F52EC: jal         0x800653D8
    // 0x804F52F0: nop

    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x804F52F0: nop

    after_8:
    // 0x804F52F4: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x804F52F8: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    // 0x804F52FC: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
L_804F5300:
    // 0x804F5300: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x804F5304: lui         $t6, 0x8051
    ctx->r14 = S32(RELOC_HI16(273, 0X207BC) << 16);
    // 0x804F5308: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x804F530C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804F5310: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x804F5314: lui         $t0, 0x8051
    ctx->r8 = S32(RELOC_HI16(273, 0X207B4) << 16);
    // 0x804F5318: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804F531C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x804F5320: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x804F5324: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x804F5328: lhu         $t6, 0x4A4C($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(273, 0X207BC));
    // 0x804F532C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x804F5330: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x804F5334: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x804F5338: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x804F533C: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x804F5340: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x804F5344: lhu         $t0, 0x4A44($t0)
    ctx->r8 = MEM_HU(ctx->r8, (int16_t)RELOC_LO16(273, 0X207B4));
    // 0x804F5348: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x804F534C: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
L_804F5350:
    // 0x804F5350: jal         0x804F4E30
    // 0x804F5354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804F4E30(rdram, ctx);
        goto after_9;
    // 0x804F5354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x804F5358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804F535C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804F5360: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804F5364: jr          $ra
    // 0x804F5368: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x804F5368: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80018B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018B54: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018B58: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018B5C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80018B60: jal         0x8001AEDC
    // 0x80018B64: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_8001AEDC(rdram, ctx);
        goto after_0;
    // 0x80018B64: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_0:
    // 0x80018B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018B70: jr          $ra
    // 0x80018B74: nop

    return;
    // 0x80018B74: nop

;}
RECOMP_FUNC void func_800591D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800591D0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800591D4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800591D8: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800591DC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800591E0: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800591E4: jr          $ra
    // 0x800591E8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x800591E8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80709CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709CF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80709CF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80709CFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80709D00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80709D04: jal         0x80047090
    // 0x80709D08: addiu       $a0, $zero, 0x4019
    ctx->r4 = ADD32(0, 0X4019);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80709D08: addiu       $a0, $zero, 0x4019
    ctx->r4 = ADD32(0, 0X4019);
    after_0:
    // 0x80709D0C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80709D10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80709D14: beq         $v0, $at, L_80709D88
    if (ctx->r2 == ctx->r1) {
        // 0x80709D18: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_80709D88;
    }
    // 0x80709D18: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80709D1C: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80709D20: lui         $at, 0x4019
    ctx->r1 = S32(0X4019 << 16);
    // 0x80709D24: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80709D28: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(718, 0X1680) << 16);
    // 0x80709D2C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80709D30: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x80709D34: addiu       $a0, $a0, -0x57A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(718, 0X1680));
    // 0x80709D38: or          $a1, $t0, $at
    ctx->r5 = ctx->r8 | ctx->r1;
    // 0x80709D3C: jal         0x80046804
    // 0x80709D40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x80709D40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80709D44: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80709D48: beq         $v0, $zero, L_80709D88
    if (ctx->r2 == 0) {
        // 0x80709D4C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80709D88;
    }
    // 0x80709D4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80709D50: beq         $v1, $zero, L_80709D70
    if (ctx->r3 == 0) {
        // 0x80709D54: nop
    
            goto L_80709D70;
    }
    // 0x80709D54: nop

    // 0x80709D58: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80709D5C: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x80709D60: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80709D64: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x80709D68: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80709D6C: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_80709D70:
    // 0x80709D70: jal         0x807092C8
    // 0x80709D74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_807092C8(rdram, ctx);
        goto after_2;
    // 0x80709D74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80709D78: jal         0x80044194
    // 0x80709D7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x80709D7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80709D80: b           L_80709D8C
    // 0x80709D84: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80709D8C;
    // 0x80709D84: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80709D88:
    // 0x80709D88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80709D8C:
    // 0x80709D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80709D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80709D94: jr          $ra
    // 0x80709D98: nop

    return;
    // 0x80709D98: nop

;}
RECOMP_FUNC void func_800445A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800445A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800445A8: bne         $a0, $zero, L_800445C8
    if (ctx->r4 != 0) {
        // 0x800445AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800445C8;
    }
    // 0x800445AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800445B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800445B4: addiu       $a0, $a0, 0x4B0
    ctx->r4 = ADD32(ctx->r4, 0X4B0);
    // 0x800445B8: jal         0x80071380
    // 0x800445BC: addiu       $a1, $zero, 0x4D4
    ctx->r5 = ADD32(0, 0X4D4);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x800445BC: addiu       $a1, $zero, 0x4D4
    ctx->r5 = ADD32(0, 0X4D4);
    after_0:
    // 0x800445C0: b           L_80044648
    // 0x800445C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044648;
    // 0x800445C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800445C8:
    // 0x800445C8: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800445CC: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800445D0: beq         $t7, $zero, L_800445EC
    if (ctx->r15 == 0) {
        // 0x800445D4: addiu       $a1, $zero, 0x4DD
        ctx->r5 = ADD32(0, 0X4DD);
            goto L_800445EC;
    }
    // 0x800445D4: addiu       $a1, $zero, 0x4DD
    ctx->r5 = ADD32(0, 0X4DD);
    // 0x800445D8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800445DC: jal         0x80071380
    // 0x800445E0: addiu       $a0, $a0, 0x4C0
    ctx->r4 = ADD32(ctx->r4, 0X4C0);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x800445E0: addiu       $a0, $a0, 0x4C0
    ctx->r4 = ADD32(ctx->r4, 0X4C0);
    after_1:
    // 0x800445E4: b           L_80044648
    // 0x800445E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044648;
    // 0x800445E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800445EC:
    // 0x800445EC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800445F0: lui         $at, 0x1997
    ctx->r1 = S32(0X1997 << 16);
    // 0x800445F4: ori         $at, $at, 0x1110
    ctx->r1 = ctx->r1 | 0X1110;
    // 0x800445F8: beq         $t8, $at, L_80044614
    if (ctx->r24 == ctx->r1) {
        // 0x800445FC: addiu       $a1, $zero, 0x4E6
        ctx->r5 = ADD32(0, 0X4E6);
            goto L_80044614;
    }
    // 0x800445FC: addiu       $a1, $zero, 0x4E6
    ctx->r5 = ADD32(0, 0X4E6);
    // 0x80044600: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044604: jal         0x80071380
    // 0x80044608: addiu       $a0, $a0, 0x4D0
    ctx->r4 = ADD32(ctx->r4, 0X4D0);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x80044608: addiu       $a0, $a0, 0x4D0
    ctx->r4 = ADD32(ctx->r4, 0X4D0);
    after_2:
    // 0x8004460C: b           L_80044648
    // 0x80044610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044648;
    // 0x80044610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80044614:
    // 0x80044614: jal         0x80048CC0
    // 0x80044618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048CC0(rdram, ctx);
        goto after_3;
    // 0x80044618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x8004461C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80044620: lh          $t9, 0x17E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X17E);
    // 0x80044624: bne         $t9, $zero, L_8004463C
    if (ctx->r25 != 0) {
        // 0x80044628: nop
    
            goto L_8004463C;
    }
    // 0x80044628: nop

    // 0x8004462C: jal         0x80048BA0
    // 0x80044630: nop

    func_80048BA0(rdram, ctx);
        goto after_4;
    // 0x80044630: nop

    after_4:
    // 0x80044634: b           L_80044648
    // 0x80044638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80044648;
    // 0x80044638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004463C:
    // 0x8004463C: jal         0x800447C8
    // 0x80044640: nop

    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x80044640: nop

    after_5:
    // 0x80044644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80044648:
    // 0x80044648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004464C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044650: jr          $ra
    // 0x80044654: nop

    return;
    // 0x80044654: nop

;}
RECOMP_FUNC void func_8045323C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045323C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453244: jal         0x804531D0
    // 0x80453248: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804531D0(rdram, ctx);
        goto after_0;
    // 0x80453248: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045324C: beql        $v0, $zero, L_80453260
    if (ctx->r2 == 0) {
        // 0x80453250: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80453260;
    }
    goto skip_0;
    // 0x80453250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80453254: jal         0x80452834
    // 0x80453258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80452834(rdram, ctx);
        goto after_1;
    // 0x80453258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045325C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453260:
    // 0x80453260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453264: jr          $ra
    // 0x80453268: nop

    return;
    // 0x80453268: nop

;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090400: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80090404: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80090408: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8009040C: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x80090410: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80090414: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80090418: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8009041C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80090420: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80090424: bne         $v1, $v0, L_80090438
    if (ctx->r3 != ctx->r2) {
        // 0x80090428: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_80090438;
    }
    // 0x80090428: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8009042C: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x80090430: b           L_80090440
    // 0x80090434: addiu       $s3, $s3, -0x445C
    ctx->r19 = ADD32(ctx->r19, -0X445C);
        goto L_80090440;
    // 0x80090434: addiu       $s3, $s3, -0x445C
    ctx->r19 = ADD32(ctx->r19, -0X445C);
L_80090438:
    // 0x80090438: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x8009043C: addiu       $s3, $s3, -0x4470
    ctx->r19 = ADD32(ctx->r19, -0X4470);
L_80090440:
    // 0x80090440: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x80090444: bne         $v0, $at, L_80090454
    if (ctx->r2 != ctx->r1) {
        // 0x80090448: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_80090454;
    }
    // 0x80090448: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x8009044C: b           L_80090474
    // 0x80090450: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_80090474;
    // 0x80090450: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_80090454:
    // 0x80090454: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80090458: beq         $v0, $at, L_80090470
    if (ctx->r2 == ctx->r1) {
        // 0x8009045C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_80090470;
    }
    // 0x8009045C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80090460: beq         $v1, $v0, L_80090470
    if (ctx->r3 == ctx->r2) {
        // 0x80090464: nop
    
            goto L_80090470;
    }
    // 0x80090464: nop

    // 0x80090468: b           L_80090470
    // 0x8009046C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_80090470;
    // 0x8009046C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_80090470:
    // 0x80090470: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80090474:
    // 0x80090474: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80090478: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8009047C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80090480: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80090484: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80090488: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8009048C: beq         $v0, $at, L_800904A0
    if (ctx->r2 == ctx->r1) {
        // 0x80090490: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_800904A0;
    }
    // 0x80090490: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80090494: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80090498: bnel        $v0, $at, L_800904DC
    if (ctx->r2 != ctx->r1) {
        // 0x8009049C: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800904DC;
    }
    goto skip_0;
    // 0x8009049C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_800904A0:
    // 0x800904A0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800904A4: bgtzl       $t4, L_800904DC
    if (SIGNED(ctx->r12) > 0) {
        // 0x800904A8: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800904DC;
    }
    goto skip_1;
    // 0x800904A8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x800904AC: bltz        $t4, L_800904BC
    if (SIGNED(ctx->r12) < 0) {
        // 0x800904B0: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_800904BC;
    }
    // 0x800904B0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800904B4: b           L_800904DC
    // 0x800904B8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_800904DC;
    // 0x800904B8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800904BC:
    // 0x800904BC: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800904C0: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800904C4: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800904C8: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800904CC: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800904D0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800904D4: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800904D8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800904DC:
    // 0x800904DC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800904E0: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x800904E4: bne         $t2, $zero, L_80090500
    if (ctx->r10 != 0) {
        // 0x800904E8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80090500;
    }
    // 0x800904E8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800904EC: bnel        $t3, $zero, L_80090504
    if (ctx->r11 != 0) {
        // 0x800904F0: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_80090504;
    }
    goto skip_2;
    // 0x800904F0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x800904F4: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x800904F8: beql        $t4, $zero, L_8009053C
    if (ctx->r12 == 0) {
        // 0x800904FC: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_8009053C;
    }
    goto skip_3;
    // 0x800904FC: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_80090500:
    // 0x80090500: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_80090504:
    // 0x80090504: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80090508: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8009050C: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80090510: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80090514: jal         0x80082C4C
    // 0x80090518: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x80090518: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x8009051C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80090520: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x80090524: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80090528: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x8009052C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80090530: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x80090534: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80090538: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_8009053C:
    // 0x8009053C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80090540: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80090544: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80090548: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x8009054C: jal         0x80082C88
    // 0x80090550: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80090550: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x80090554: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80090558: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x8009055C: bltz        $v0, L_8009060C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80090560: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8009060C;
    }
    // 0x80090560: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80090564: bgtz        $v0, L_80090574
    if (SIGNED(ctx->r2) > 0) {
        // 0x80090568: nop
    
            goto L_80090574;
    }
    // 0x80090568: nop

    // 0x8009056C: beql        $v1, $zero, L_80090610
    if (ctx->r3 == 0) {
        // 0x80090570: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80090610;
    }
    goto skip_4;
    // 0x80090570: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_80090574:
    // 0x80090574: blez        $s0, L_8009060C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80090578: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_8009060C;
    }
    // 0x80090578: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x8009057C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80090580: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x80090584: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80090588: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8009058C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80090590: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80090594: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80090598:
    // 0x80090598: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8009059C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800905A0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800905A4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800905A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800905AC: jal         0x80090270
    // 0x800905B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x800905B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800905B4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800905B8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800905BC: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x800905C0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800905C4: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800905C8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800905CC: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x800905D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800905D4: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x800905D8: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800905DC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800905E0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800905E4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800905E8: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800905EC: bltz        $t8, L_8009060C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800905F0: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_8009060C;
    }
    // 0x800905F0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800905F4: bgtz        $t8, L_80090604
    if (SIGNED(ctx->r24) > 0) {
        // 0x800905F8: nop
    
            goto L_80090604;
    }
    // 0x800905F8: nop

    // 0x800905FC: beql        $t9, $zero, L_80090610
    if (ctx->r25 == 0) {
        // 0x80090600: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80090610;
    }
    goto skip_5;
    // 0x80090600: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_80090604:
    // 0x80090604: bgtzl       $s0, L_80090598
    if (SIGNED(ctx->r16) > 0) {
        // 0x80090608: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80090598;
    }
    goto skip_6;
    // 0x80090608: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_8009060C:
    // 0x8009060C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_80090610:
    // 0x80090610: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x80090614: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x80090618: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x8009061C: jal         0x8008AD80
    // 0x80090620: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80090620: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x80090624: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80090628: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x8009062C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80090630: beq         $at, $zero, L_8009063C
    if (ctx->r1 == 0) {
        // 0x80090634: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_8009063C;
    }
    // 0x80090634: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x80090638: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_8009063C:
    // 0x8009063C: bgezl       $a0, L_80090680
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80090640: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80090680;
    }
    goto skip_7;
    // 0x80090640: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80090644: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x80090648: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8009064C: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x80090650: bnel        $t7, $at, L_80090680
    if (ctx->r15 != ctx->r1) {
        // 0x80090654: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80090680;
    }
    goto skip_8;
    // 0x80090654: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80090658: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x8009065C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80090660: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80090664: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x80090668: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x8009066C: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x80090670: blez        $s0, L_8009067C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80090674: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_8009067C;
    }
    // 0x80090674: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x80090678: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_8009067C:
    // 0x8009067C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80090680:
    // 0x80090680: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80090684: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80090688: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8009068C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80090690: jr          $ra
    // 0x80090694: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80090694: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_806746B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806746B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806746B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806746BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806746C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806746C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806746C8: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806746CC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806746D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806746D4: beq         $v0, $at, L_806746F0
    if (ctx->r2 == ctx->r1) {
        // 0x806746D8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_806746F0;
    }
    // 0x806746D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806746DC: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806746E0: beq         $v0, $at, L_80674704
    if (ctx->r2 == ctx->r1) {
        // 0x806746E4: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80674704;
    }
    // 0x806746E4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x806746E8: b           L_80674724
    // 0x806746EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80674724;
    // 0x806746EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806746F0:
    // 0x806746F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806746F4: jal         0x8002F6E4
    // 0x806746F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x806746F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806746FC: b           L_80674724
    // 0x80674700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80674724;
    // 0x80674700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80674704:
    // 0x80674704: lw          $t9, 0x1F4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1F4);
    // 0x80674708: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067470C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80674710: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x80674714: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80674718: jal         0x806730B0
    // 0x8067471C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_806730B0(rdram, ctx);
        goto after_1;
    // 0x8067471C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80674720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80674724:
    // 0x80674724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80674728: jr          $ra
    // 0x8067472C: nop

    return;
    // 0x8067472C: nop

;}
RECOMP_FUNC void func_800486F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800486F4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800486F8: addiu       $t6, $t6, -0x7970
    ctx->r14 = ADD32(ctx->r14, -0X7970);
    // 0x800486FC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80048700: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x80048704: jr          $ra
    // 0x80048708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80048708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8078E780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E780: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078E784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078E788: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078E78C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8078E790: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XAB0) << 16);
    // 0x8078E794: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8078E798: beq         $v1, $zero, L_8078E7A8
    if (ctx->r3 == 0) {
        // 0x8078E79C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8078E7A8;
    }
    // 0x8078E79C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8078E7A0: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8078E7A4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8078E7A8:
    // 0x8078E7A8: bne         $v1, $zero, L_8078E7CC
    if (ctx->r3 != 0) {
        // 0x8078E7AC: nop
    
            goto L_8078E7CC;
    }
    // 0x8078E7AC: nop

    // 0x8078E7B0: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8078E7B4: lh          $t8, 0x144($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X144);
    // 0x8078E7B8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8078E7BC: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x8078E7C0: lh          $t0, 0x144($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X144);
    // 0x8078E7C4: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x8078E7C8: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
L_8078E7CC:
    // 0x8078E7CC: lwc1        $f12, -0x1630($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XAB0));
    // 0x8078E7D0: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8078E7D4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XAB4) << 16);
    // 0x8078E7D8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8078E7DC: nop

    // 0x8078E7E0: bc1fl       L_8078E7F0
    if (!c1cs) {
        // 0x8078E7E4: lwc1        $f0, 0x70($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
            goto L_8078E7F0;
    }
    goto skip_0;
    // 0x8078E7E4: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    skip_0:
    // 0x8078E7E8: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8078E7EC: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
L_8078E7F0:
    // 0x8078E7F0: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x8078E7F4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8078E7F8: nop

    // 0x8078E7FC: bc1fl       L_8078E814
    if (!c1cs) {
        // 0x8078E800: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8078E814;
    }
    goto skip_1;
    // 0x8078E800: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    skip_1:
    // 0x8078E804: lwc1        $f4, -0x162C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XAB4));
    // 0x8078E808: b           L_8078E824
    // 0x8078E80C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
        goto L_8078E824;
    // 0x8078E80C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8078E810: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
L_8078E814:
    // 0x8078E814: jal         0x80044658
    // 0x8078E818: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80044658(rdram, ctx);
        goto after_0;
    // 0x8078E818: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8078E81C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8078E820: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
L_8078E824:
    // 0x8078E824: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x8078E828: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XAB8) << 16);
    // 0x8078E82C: lwc1        $f6, -0x1628($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XAB8));
    // 0x8078E830: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8078E834: nop

    // 0x8078E838: bc1fl       L_8078E84C
    if (!c1cs) {
        // 0x8078E83C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078E84C;
    }
    goto skip_2;
    // 0x8078E83C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8078E840: jal         0x8078E35C
    // 0x8078E844: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8078E35C(rdram, ctx);
        goto after_1;
    // 0x8078E844: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x8078E848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078E84C:
    // 0x8078E84C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078E850: jr          $ra
    // 0x8078E854: nop

    return;
    // 0x8078E854: nop

;}
RECOMP_FUNC void func_8079921C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079921C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80799220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80799224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80799228: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8079922C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80799230: blez        $v0, L_80799240
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80799234: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80799240;
    }
    // 0x80799234: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80799238: b           L_80799350
    // 0x8079923C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_80799350;
    // 0x8079923C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80799240:
    // 0x80799240: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80799244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80799248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079924C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80799250: blez        $v1, L_80799348
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80799254: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80799348;
    }
    // 0x80799254: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80799258: jal         0x8004700C
    // 0x8079925C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8079925C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    after_0:
    // 0x80799260: beq         $v0, $zero, L_80799298
    if (ctx->r2 == 0) {
        // 0x80799264: lui         $at, 0x807A
        ctx->r1 = S32(RELOC_HI16(826, 0X25E8) << 16);
            goto L_80799298;
    }
    // 0x80799264: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25E8) << 16);
    // 0x80799268: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8079926C: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80799270: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25E4) << 16);
    // 0x80799274: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80799278: nop

    // 0x8079927C: bc1f        L_80799290
    if (!c1cs) {
        // 0x80799280: nop
    
            goto L_80799290;
    }
    // 0x80799280: nop

    // 0x80799284: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25E0) << 16);
    // 0x80799288: b           L_8079929C
    // 0x8079928C: lwc1        $f12, -0x4F00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25E0));
        goto L_8079929C;
    // 0x8079928C: lwc1        $f12, -0x4F00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25E0));
L_80799290:
    // 0x80799290: b           L_8079929C
    // 0x80799294: lwc1        $f12, -0x4EFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25E4));
        goto L_8079929C;
    // 0x80799294: lwc1        $f12, -0x4EFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25E4));
L_80799298:
    // 0x80799298: lwc1        $f12, -0x4EF8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25E8));
L_8079929C:
    // 0x8079929C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807992A0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807992A4: lw          $t9, 0xE94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE94);
    // 0x807992A8: addiu       $t8, $zero, 0x4034
    ctx->r24 = ADD32(0, 0X4034);
    // 0x807992AC: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25EC) << 16);
    // 0x807992B0: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x807992B4: jal         0x80798C80
    // 0x807992B8: lwc1        $f14, -0x4EF4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25EC));
    func_80798C80(rdram, ctx);
        goto after_1;
    // 0x807992B8: lwc1        $f14, -0x4EF4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25EC));
    after_1:
    // 0x807992BC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807992C0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807992C4: lw          $t0, 0xE94($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE94);
    // 0x807992C8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25F0) << 16);
    // 0x807992CC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x807992D0: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
    // 0x807992D4: lw          $t1, 0xE94($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XE94);
    // 0x807992D8: lwc1        $f8, -0x4EF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25F0));
    // 0x807992DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807992E0: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x807992E4: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x807992E8: lw          $t2, 0xE94($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XE94);
    // 0x807992EC: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x807992F0: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x807992F4: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x807992F8: lwc1        $f18, 0x8C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x807992FC: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80799300: lw          $t9, 0xC($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XC);
    // 0x80799304: jalr        $t9
    // 0x80799308: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80799308: nop

    after_2:
    // 0x8079930C: beq         $v0, $zero, L_8079933C
    if (ctx->r2 == 0) {
        // 0x80799310: lui         $at, 0x807A
        ctx->r1 = S32(RELOC_HI16(826, 0X25F4) << 16);
            goto L_8079933C;
    }
    // 0x80799310: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25F4) << 16);
    // 0x80799314: lwc1        $f4, -0x4EEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25F4));
    // 0x80799318: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25F8) << 16);
    // 0x8079931C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80799320: swc1        $f4, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f4.u32l;
    // 0x80799324: lwc1        $f6, -0x4EE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25F8));
    // 0x80799328: jal         0x80067E68
    // 0x8079932C: swc1        $f6, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->f6.u32l;
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x8079932C: swc1        $f6, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x80799330: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80799334: jal         0x80067818
    // 0x80799338: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80799338: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_8079933C:
    // 0x8079933C: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80799340: b           L_80799350
    // 0x80799344: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
        goto L_80799350;
    // 0x80799344: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
L_80799348:
    // 0x80799348: jal         0x80799654
    // 0x8079934C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80799654(rdram, ctx);
        goto after_5;
    // 0x8079934C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80799350:
    // 0x80799350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80799354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80799358: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8079935C: jr          $ra
    // 0x80799360: nop

    return;
    // 0x80799360: nop

;}
RECOMP_FUNC void func_805ACD0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ACD0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805ACD10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805ACD14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805ACD18: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805ACD1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805ACD20: jal         0x805AC884
    // 0x805ACD24: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_805AC884(rdram, ctx);
        goto after_0;
    // 0x805ACD24: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x805ACD28: jal         0x805AC528
    // 0x805ACD2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AC528(rdram, ctx);
        goto after_1;
    // 0x805ACD2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805ACD30: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ACD34: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x805ACD38: beq         $v1, $zero, L_805ACD48
    if (ctx->r3 == 0) {
        // 0x805ACD3C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_805ACD48;
    }
    // 0x805ACD3C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x805ACD40: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x805ACD44: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_805ACD48:
    // 0x805ACD48: bnel        $v1, $zero, L_805ACDAC
    if (ctx->r3 != 0) {
        // 0x805ACD4C: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805ACDAC;
    }
    goto skip_0;
    // 0x805ACD4C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x805ACD50: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x805ACD54: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(441, 0X121C) << 16);
    // 0x805ACD58: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x805ACD5C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x805ACD60: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805ACD64: lh          $t9, -0x2BF4($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(441, 0X121C));
    // 0x805ACD68: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805ACD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ACD70: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
    // 0x805ACD74: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    // 0x805ACD78: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
    // 0x805ACD7C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x805ACD80: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x805ACD84: bne         $at, $zero, L_805ACDA8
    if (ctx->r1 != 0) {
        // 0x805ACD88: sw          $t1, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r9;
            goto L_805ACDA8;
    }
    // 0x805ACD88: sw          $t1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r9;
    // 0x805ACD8C: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x805ACD90: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x805ACD94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ACD98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805ACD9C: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x805ACDA0: jal         0x805AD274
    // 0x805ACDA4: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    func_805AD274(rdram, ctx);
        goto after_2;
    // 0x805ACDA4: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    after_2:
L_805ACDA8:
    // 0x805ACDA8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805ACDAC:
    // 0x805ACDAC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805ACDB0: jal         0x80048F84
    // 0x805ACDB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805ACDB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x805ACDB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805ACDBC: jal         0x80048F84
    // 0x805ACDC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805ACDC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x805ACDC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805ACDC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805ACDCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805ACDD0: jr          $ra
    // 0x805ACDD4: nop

    return;
    // 0x805ACDD4: nop

;}
RECOMP_FUNC void func_8003E7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E7E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003E7E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003E7E8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003E7EC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003E7F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003E7F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003E7F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003E7FC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8003E800: lhu         $t6, 0x12BE($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12BE);
    // 0x8003E804: lbu         $s4, 0x12C8($a0)
    ctx->r20 = MEM_BU(ctx->r4, 0X12C8);
    // 0x8003E808: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8003E80C: addu        $s0, $t6, $a1
    ctx->r16 = ADD32(ctx->r14, ctx->r5);
    // 0x8003E810: andi        $s0, $s0, 0x7
    ctx->r16 = ctx->r16 & 0X7;
    // 0x8003E814: subu        $v0, $s4, $a1
    ctx->r2 = SUB32(ctx->r20, ctx->r5);
    // 0x8003E818: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8003E81C: addiu       $s1, $v0, -0x1
    ctx->r17 = ADD32(ctx->r2, -0X1);
    // 0x8003E820: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8003E824: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8003E828: beq         $s1, $zero, L_8003E87C
    if (ctx->r17 == 0) {
        // 0x8003E82C: sh          $s0, 0x40($sp)
        MEM_H(0X40, ctx->r29) = ctx->r16;
            goto L_8003E87C;
    }
    // 0x8003E82C: sh          $s0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r16;
    // 0x8003E830: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003E834: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x8003E838: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
L_8003E83C:
    // 0x8003E83C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003E840: andi        $s0, $s0, 0x7
    ctx->r16 = ctx->r16 & 0X7;
    // 0x8003E844: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8003E848: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003E84C: mflo        $t7
    ctx->r15 = lo;
    // 0x8003E850: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8003E854: lw          $a0, 0x11FC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X11FC);
    // 0x8003E858: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003E85C: mflo        $t9
    ctx->r25 = lo;
    // 0x8003E860: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x8003E864: jal         0x8003E4C8
    // 0x8003E868: sw          $a0, 0x11FC($t0)
    MEM_W(0X11FC, ctx->r8) = ctx->r4;
    func_8003E4C8(rdram, ctx);
        goto after_0;
    // 0x8003E868: sw          $a0, 0x11FC($t0)
    MEM_W(0X11FC, ctx->r8) = ctx->r4;
    after_0:
    // 0x8003E86C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8003E870: bnel        $s1, $zero, L_8003E83C
    if (ctx->r17 != 0) {
        // 0x8003E874: andi        $a1, $s0, 0xFFFF
        ctx->r5 = ctx->r16 & 0XFFFF;
            goto L_8003E83C;
    }
    goto skip_0;
    // 0x8003E874: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    skip_0:
    // 0x8003E878: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8003E87C:
    // 0x8003E87C: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x8003E880: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x8003E884: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
    // 0x8003E888: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003E88C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8003E890: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003E894: jal         0x8003E590
    // 0x8003E898: lhu         $a1, 0x40($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X40);
    func_8003E590(rdram, ctx);
        goto after_1;
    // 0x8003E898: lhu         $a1, 0x40($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X40);
    after_1:
    // 0x8003E89C: sb          $s4, 0x12C8($s3)
    MEM_B(0X12C8, ctx->r19) = ctx->r20;
    // 0x8003E8A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003E8A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003E8A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003E8AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003E8B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E8B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003E8B8: jr          $ra
    // 0x8003E8BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003E8BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8002C2CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C2CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C2D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002C2D4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C2D8: addiu       $a1, $a1, -0x39E0
    ctx->r5 = ADD32(ctx->r5, -0X39E0);
    // 0x8002C2DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002C2E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002C2E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002C2E8: jal         0x80028118
    // 0x8002C2EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C2EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C2F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002C2F4: jal         0x8002B00C
    // 0x8002C2F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8002B00C(rdram, ctx);
        goto after_1;
    // 0x8002C2F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8002C2FC: jal         0x8002AE90
    // 0x8002C300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002AE90(rdram, ctx);
        goto after_2;
    // 0x8002C300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002C304: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C308: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8002C30C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002C310: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x8002C314: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x8002C318: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8002C31C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8002C320: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8002C324: lw          $v0, -0x727C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X727C);
    // 0x8002C328: beql        $v0, $zero, L_8002C344
    if (ctx->r2 == 0) {
        // 0x8002C32C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8002C344;
    }
    goto skip_0;
    // 0x8002C32C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x8002C330: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8002C334: lwc1        $f14, 0x88($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8002C338: jalr        $v0
    // 0x8002C33C: lw          $a2, 0x8C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x8002C33C: lw          $a2, 0x8C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8C);
    after_3:
    // 0x8002C340: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_8002C344:
    // 0x8002C344: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    // 0x8002C348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C34C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002C350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C354: jr          $ra
    // 0x8002C358: nop

    return;
    // 0x8002C358: nop

;}
RECOMP_FUNC void func_800363BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800363BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800363C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800363C4: jal         0x80021958
    // 0x800363C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x800363C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800363CC: bne         $v0, $zero, L_800363DC
    if (ctx->r2 != 0) {
        // 0x800363D0: nop
    
            goto L_800363DC;
    }
    // 0x800363D0: nop

    // 0x800363D4: b           L_80036410
    // 0x800363D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036410;
    // 0x800363D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800363DC:
    // 0x800363DC: jal         0x800415FC
    // 0x800363E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x800363E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800363E4: beq         $v0, $zero, L_800363F4
    if (ctx->r2 == 0) {
        // 0x800363E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800363F4;
    }
    // 0x800363E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800363EC: b           L_80036410
    // 0x800363F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036410;
    // 0x800363F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800363F4:
    // 0x800363F4: jal         0x800351BC
    // 0x800363F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800351BC(rdram, ctx);
        goto after_2;
    // 0x800363F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x800363FC: bnel        $v0, $zero, L_80036410
    if (ctx->r2 != 0) {
        // 0x80036400: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80036410;
    }
    goto skip_0;
    // 0x80036400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80036404: b           L_80036410
    // 0x80036408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036410;
    // 0x80036408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003640C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036410:
    // 0x80036410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036418: jr          $ra
    // 0x8003641C: nop

    return;
    // 0x8003641C: nop

;}
RECOMP_FUNC void func_8002CCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CCF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002CCF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002CCFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002CD00: jal         0x8002AF8C
    // 0x8002CD04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8002AF8C(rdram, ctx);
        goto after_0;
    // 0x8002CD04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8002CD08: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002CD0C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002CD10: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8002CD14: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8002CD18: lw          $t9, 0xEDC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XEDC);
    // 0x8002CD1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002CD20: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8002CD24: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8002CD28: lwc1        $f8, -0x5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5C);
    // 0x8002CD2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002CD30: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8002CD34: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8002CD38: jalr        $t9
    // 0x8002CD3C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002CD3C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8002CD40: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002CD44: addiu       $a1, $a1, -0x250C
    ctx->r5 = ADD32(ctx->r5, -0X250C);
    // 0x8002CD48: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002CD4C: jal         0x80028118
    // 0x8002CD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028118(rdram, ctx);
        goto after_2;
    // 0x8002CD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002CD54: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002CD58: addiu       $t6, $t6, 0x1A04
    ctx->r14 = ADD32(ctx->r14, 0X1A04);
    // 0x8002CD5C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8002CD60: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x8002CD64: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x8002CD68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CD6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002CD70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002CD74: jr          $ra
    // 0x8002CD78: nop

    return;
    // 0x8002CD78: nop

;}
RECOMP_FUNC void func_806B2AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2AFC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2B00: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2B04: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2B08: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2B0C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2B14: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2B18: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2B1C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2B20: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2B24: jr          $ra
    // 0x806B2B28: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2B28: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800517A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800517A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800517A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800517A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800517AC: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x800517B0: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800517B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800517B8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800517BC: lw          $t9, 0x5AC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5AC0);
    // 0x800517C0: jalr        $t9
    // 0x800517C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800517C4: nop

    after_0:
    // 0x800517C8: beql        $v0, $zero, L_800517E4
    if (ctx->r2 == 0) {
        // 0x800517CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800517E4;
    }
    goto skip_0;
    // 0x800517CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800517D0: jalr        $v0
    // 0x800517D4: addiu       $a0, $sp, 0x1E
    ctx->r4 = ADD32(ctx->r29, 0X1E);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800517D4: addiu       $a0, $sp, 0x1E
    ctx->r4 = ADD32(ctx->r29, 0X1E);
    after_1:
    // 0x800517D8: b           L_800517E8
    // 0x800517DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800517E8;
    // 0x800517DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800517E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800517E4:
    // 0x800517E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800517E8:
    // 0x800517E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800517EC: jr          $ra
    // 0x800517F0: nop

    return;
    // 0x800517F0: nop

;}
RECOMP_FUNC void func_8075FC88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075FC88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8075FC8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8075FC90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8075FC94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8075FC98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8075FC9C: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8075FCA0: addiu       $at, $zero, 0x46EC
    ctx->r1 = ADD32(0, 0X46EC);
    // 0x8075FCA4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8075FCA8: bne         $t6, $at, L_8075FCC0
    if (ctx->r14 != ctx->r1) {
        // 0x8075FCAC: lui         $t7, 0x8076
        ctx->r15 = S32(RELOC_HI16(760, 0X490) << 16);
            goto L_8075FCC0;
    }
    // 0x8075FCAC: lui         $t7, 0x8076
    ctx->r15 = S32(RELOC_HI16(760, 0X490) << 16);
    // 0x8075FCB0: jal         0x8075FE00
    // 0x8075FCB4: nop

    func_8075FE00(rdram, ctx);
        goto after_0;
    // 0x8075FCB4: nop

    after_0:
    // 0x8075FCB8: b           L_8075FDEC
    // 0x8075FCBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8075FDEC;
    // 0x8075FCBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8075FCC0:
    // 0x8075FCC0: lw          $t8, 0x16C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X16C);
    // 0x8075FCC4: sw          $zero, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = 0;
    // 0x8075FCC8: addiu       $t7, $t7, 0x10
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(760, 0X490));
    // 0x8075FCCC: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8075FCD0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8075FCD4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8075FCD8: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8075FCDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8075FCE0: sw          $t9, 0x124($s2)
    MEM_W(0X124, ctx->r18) = ctx->r25;
    // 0x8075FCE4: sw          $t0, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->r8;
    // 0x8075FCE8: sb          $t1, 0x165($s2)
    MEM_B(0X165, ctx->r18) = ctx->r9;
    // 0x8075FCEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8075FCF0: jal         0x80045A34
    // 0x8075FCF4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8075FCF4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_1:
    // 0x8075FCF8: sw          $v0, 0x1F4($s2)
    MEM_W(0X1F4, ctx->r18) = ctx->r2;
    // 0x8075FCFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8075FD00: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8075FD04: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8075FD08: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8075FD0C: jal         0x80047090
    // 0x8075FD10: addiu       $a0, $zero, 0x4645
    ctx->r4 = ADD32(0, 0X4645);
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x8075FD10: addiu       $a0, $zero, 0x4645
    ctx->r4 = ADD32(0, 0X4645);
    after_2:
    // 0x8075FD14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8075FD18: lui         $at, 0x4645
    ctx->r1 = S32(0X4645 << 16);
    // 0x8075FD1C: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x8075FD20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8075FD24: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8075FD28: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8075FD2C: jal         0x8004613C
    // 0x8075FD30: lui         $a1, 0xC238
    ctx->r5 = S32(0XC238 << 16);
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x8075FD30: lui         $a1, 0xC238
    ctx->r5 = S32(0XC238 << 16);
    after_3:
    // 0x8075FD34: bne         $v0, $zero, L_8075FD4C
    if (ctx->r2 != 0) {
        // 0x8075FD38: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8075FD4C;
    }
    // 0x8075FD38: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8075FD3C: jal         0x800445A4
    // 0x8075FD40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8075FD40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8075FD44: b           L_8075FDEC
    // 0x8075FD48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8075FDEC;
    // 0x8075FD48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8075FD4C:
    // 0x8075FD4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8075FD50: jal         0x80047F9C
    // 0x8075FD54: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8075FD54: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x8075FD58: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8075FD5C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8075FD60: sb          $t2, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = ctx->r10;
    // 0x8075FD64: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8075FD68: jal         0x8005FDC4
    // 0x8075FD6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_6;
    // 0x8075FD6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8075FD70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8075FD74: sw          $zero, 0x138($s1)
    MEM_W(0X138, ctx->r17) = 0;
    // 0x8075FD78: lhu         $a0, 0x2E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2E);
    // 0x8075FD7C: lui         $at, 0x4645
    ctx->r1 = S32(0X4645 << 16);
    // 0x8075FD80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8075FD84: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8075FD88: lui         $a1, 0x4238
    ctx->r5 = S32(0X4238 << 16);
    // 0x8075FD8C: jal         0x8004613C
    // 0x8075FD90: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x8075FD90: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_7:
    // 0x8075FD94: bne         $v0, $zero, L_8075FDAC
    if (ctx->r2 != 0) {
        // 0x8075FD98: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_8075FDAC;
    }
    // 0x8075FD98: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8075FD9C: jal         0x800445A4
    // 0x8075FDA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x8075FDA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x8075FDA4: b           L_8075FDEC
    // 0x8075FDA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8075FDEC;
    // 0x8075FDA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8075FDAC:
    // 0x8075FDAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8075FDB0: jal         0x80047F9C
    // 0x8075FDB4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x8075FDB4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_9:
    // 0x8075FDB8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8075FDBC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8075FDC0: sb          $t4, 0x17C($t5)
    MEM_B(0X17C, ctx->r13) = ctx->r12;
    // 0x8075FDC4: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x8075FDC8: jal         0x8005FDC4
    // 0x8075FDCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_10;
    // 0x8075FDCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8075FDD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8075FDD4: sw          $t6, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->r14;
    // 0x8075FDD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8075FDDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8075FDE0: jal         0x8075FF58
    // 0x8075FDE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8075FF58(rdram, ctx);
        goto after_11;
    // 0x8075FDE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8075FDE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8075FDEC:
    // 0x8075FDEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8075FDF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8075FDF4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8075FDF8: jr          $ra
    // 0x8075FDFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8075FDFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8043D9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D9D0: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8043D9D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8043D9D8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8043D9DC: beq         $t7, $zero, L_8043DA10
    if (ctx->r15 == 0) {
        // 0x8043D9E0: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_8043DA10;
    }
    // 0x8043D9E0: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x8043D9E4: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x8043D9E8: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8043D9EC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8043D9F0: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
    // 0x8043D9F4: lh          $t1, 0x144($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X144);
    // 0x8043D9F8: slti        $at, $t1, 0xC
    ctx->r1 = SIGNED(ctx->r9) < 0XC ? 1 : 0;
    // 0x8043D9FC: bne         $at, $zero, L_8043DA10
    if (ctx->r1 != 0) {
        // 0x8043DA00: nop
    
            goto L_8043DA10;
    }
    // 0x8043DA00: nop

    // 0x8043DA04: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8043DA08: jr          $ra
    // 0x8043DA0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8043DA0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8043DA10:
    // 0x8043DA10: jr          $ra
    // 0x8043DA14: nop

    return;
    // 0x8043DA14: nop

;}
RECOMP_FUNC void func_80044250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044250: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80044258: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004425C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80044260: lh          $t6, 0x3A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X3A);
    // 0x80044264: addiu       $s0, $a0, 0x34
    ctx->r16 = ADD32(ctx->r4, 0X34);
    // 0x80044268: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8004426C: beql        $t6, $zero, L_800442B4
    if (ctx->r14 == 0) {
        // 0x80044270: lh          $t8, 0x6($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X6);
            goto L_800442B4;
    }
    goto skip_0;
    // 0x80044270: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    skip_0:
L_80044274:
    // 0x80044274: jal         0x80043DD4
    // 0x80044278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80043DD4(rdram, ctx);
        goto after_0;
    // 0x80044278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8004427C: bne         $v0, $zero, L_8004429C
    if (ctx->r2 != 0) {
        // 0x80044280: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8004429C;
    }
    // 0x80044280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80044284: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044288: addiu       $a0, $a0, 0x430
    ctx->r4 = ADD32(ctx->r4, 0X430);
    // 0x8004428C: jal         0x80071380
    // 0x80044290: addiu       $a1, $zero, 0x3F1
    ctx->r5 = ADD32(0, 0X3F1);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80044290: addiu       $a1, $zero, 0x3F1
    ctx->r5 = ADD32(0, 0X3F1);
    after_1:
    // 0x80044294: b           L_800442D0
    // 0x80044298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800442D0;
    // 0x80044298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004429C:
    // 0x8004429C: jal         0x80044214
    // 0x800442A0: nop

    func_80044214(rdram, ctx);
        goto after_2;
    // 0x800442A0: nop

    after_2:
    // 0x800442A4: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x800442A8: bne         $t7, $zero, L_80044274
    if (ctx->r15 != 0) {
        // 0x800442AC: nop
    
            goto L_80044274;
    }
    // 0x800442AC: nop

    // 0x800442B0: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
L_800442B4:
    // 0x800442B4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800442B8: addiu       $a0, $a0, 0x440
    ctx->r4 = ADD32(ctx->r4, 0X440);
    // 0x800442BC: beql        $t8, $zero, L_800442D0
    if (ctx->r24 == 0) {
        // 0x800442C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800442D0;
    }
    goto skip_1;
    // 0x800442C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800442C4: jal         0x80071380
    // 0x800442C8: addiu       $a1, $zero, 0x3FC
    ctx->r5 = ADD32(0, 0X3FC);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x800442C8: addiu       $a1, $zero, 0x3FC
    ctx->r5 = ADD32(0, 0X3FC);
    after_3:
    // 0x800442CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800442D0:
    // 0x800442D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800442D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800442D8: jr          $ra
    // 0x800442DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800442DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_807B7C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B7C40: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x807B7C44: addiu       $at, $zero, 0x4708
    ctx->r1 = ADD32(0, 0X4708);
    // 0x807B7C48: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(883, 0X494) << 16);
    // 0x807B7C4C: bne         $t6, $at, L_807B7C60
    if (ctx->r14 != ctx->r1) {
        // 0x807B7C50: addiu       $v0, $v0, -0x7F2C
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(883, 0X494));
            goto L_807B7C60;
    }
    // 0x807B7C50: addiu       $v0, $v0, -0x7F2C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(883, 0X494));
    // 0x807B7C54: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(883, 0X494) << 16);
    // 0x807B7C58: jr          $ra
    // 0x807B7C5C: addiu       $v0, $v0, -0x7F2C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(883, 0X494));
    return;
    // 0x807B7C5C: addiu       $v0, $v0, -0x7F2C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(883, 0X494));
L_807B7C60:
    // 0x807B7C60: jr          $ra
    // 0x807B7C64: nop

    return;
    // 0x807B7C64: nop

;}
RECOMP_FUNC void func_805A61AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A61AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A61B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A61B4: lwc1        $f2, 0xC8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805A61B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805A61BC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A61C0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x805A61C4: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x805A61C8: nop

    // 0x805A61CC: bc1fl       L_805A6200
    if (!c1cs) {
        // 0x805A61D0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_805A6200;
    }
    goto skip_0;
    // 0x805A61D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x805A61D4: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805A61D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A61DC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805A61E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A61E4: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x805A61E8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x805A61EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805A61F0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805A61F4: b           L_805A621C
    // 0x805A61F8: sub.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f16.fl;
        goto L_805A621C;
    // 0x805A61F8: sub.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x805A61FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_805A6200:
    // 0x805A6200: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805A6204: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805A6208: div.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x805A620C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x805A6210: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805A6214: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805A6218: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
L_805A621C:
    // 0x805A621C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805A6220: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805A6224: nop

    // 0x805A6228: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x805A622C: nop

    // 0x805A6230: bc1fl       L_805A6250
    if (!c1cs) {
        // 0x805A6234: swc1        $f0, 0x274($v0)
        MEM_W(0X274, ctx->r2) = ctx->f0.u32l;
            goto L_805A6250;
    }
    goto skip_1;
    // 0x805A6234: swc1        $f0, 0x274($v0)
    MEM_W(0X274, ctx->r2) = ctx->f0.u32l;
    skip_1:
    // 0x805A6238: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_805A623C:
    // 0x805A623C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x805A6240: nop

    // 0x805A6244: bc1tl       L_805A623C
    if (c1cs) {
        // 0x805A6248: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_805A623C;
    }
    goto skip_2;
    // 0x805A6248: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x805A624C: swc1        $f0, 0x274($v0)
    MEM_W(0X274, ctx->r2) = ctx->f0.u32l;
L_805A6250:
    // 0x805A6250: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805A6254: jal         0x805A6098
    // 0x805A6258: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_805A6098(rdram, ctx);
        goto after_0;
    // 0x805A6258: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805A625C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805A6260: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805A6264: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A6268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805A626C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A6270: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x805A6274: nop

    // 0x805A6278: bc1f        L_805A6284
    if (!c1cs) {
        // 0x805A627C: nop
    
            goto L_805A6284;
    }
    // 0x805A627C: nop

    // 0x805A6280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A6284:
    // 0x805A6284: jr          $ra
    // 0x805A6288: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805A6288: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8077FEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FEDC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8077FEE0: lui         $t6, 0x8078
    ctx->r14 = S32(RELOC_HI16(781, 0X6C) << 16);
    // 0x8077FEE4: addiu       $t6, $t6, -0x684
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(781, 0X6C));
    // 0x8077FEE8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8077FEEC: jr          $ra
    // 0x8077FEF0: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x8077FEF0: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807B7144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B7144: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B7148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B714C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B7150: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B7154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B7158: jal         0x8004700C
    // 0x807B715C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807B715C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x807B7160: beq         $v0, $zero, L_807B739C
    if (ctx->r2 == 0) {
        // 0x807B7164: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_807B739C;
    }
    // 0x807B7164: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x807B7168: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x807B716C: lw          $t8, 0x1E4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E4);
    // 0x807B7170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B7174: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807B7178: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x807B717C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x807B7180: sw          $t9, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r25;
    // 0x807B7184: jal         0x807B67D8
    // 0x807B7188: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_807B67D8(rdram, ctx);
        goto after_1;
    // 0x807B7188: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x807B718C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x807B7190: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x807B7194: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x807B7198: bnel        $v0, $at, L_807B71C0
    if (ctx->r2 != ctx->r1) {
        // 0x807B719C: slti        $at, $v0, 0x5A
        ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
            goto L_807B71C0;
    }
    goto skip_0;
    // 0x807B719C: slti        $at, $v0, 0x5A
    ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
    skip_0:
    // 0x807B71A0: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x807B71A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x807B71A8: beq         $v0, $zero, L_807B71B4
    if (ctx->r2 == 0) {
        // 0x807B71AC: nop
    
            goto L_807B71B4;
    }
    // 0x807B71AC: nop

    // 0x807B71B0: sb          $a3, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r7;
L_807B71B4:
    // 0x807B71B4: b           L_807B71E0
    // 0x807B71B8: lw          $a0, 0x1E4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1E4);
        goto L_807B71E0;
    // 0x807B71B8: lw          $a0, 0x1E4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1E4);
    // 0x807B71BC: slti        $at, $v0, 0x5A
    ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
L_807B71C0:
    // 0x807B71C0: bnel        $at, $zero, L_807B71E0
    if (ctx->r1 != 0) {
        // 0x807B71C4: lw          $a0, 0x1E4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X1E4);
            goto L_807B71E0;
    }
    goto skip_1;
    // 0x807B71C4: lw          $a0, 0x1E4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1E4);
    skip_1:
    // 0x807B71C8: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x807B71CC: beql        $v0, $zero, L_807B71DC
    if (ctx->r2 == 0) {
        // 0x807B71D0: sw          $zero, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = 0;
            goto L_807B71DC;
    }
    goto skip_2;
    // 0x807B71D0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    skip_2:
    // 0x807B71D4: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x807B71D8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_807B71DC:
    // 0x807B71DC: lw          $a0, 0x1E4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1E4);
L_807B71E0:
    // 0x807B71E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x807B71E4: jal         0x8006593C
    // 0x807B71E8: addiu       $a0, $a0, -0x3C
    ctx->r4 = ADD32(ctx->r4, -0X3C);
    func_8006593C(rdram, ctx);
        goto after_2;
    // 0x807B71E8: addiu       $a0, $a0, -0x3C
    ctx->r4 = ADD32(ctx->r4, -0X3C);
    after_2:
    // 0x807B71EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x807B71F0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x807B71F4: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x807B71F8: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    // 0x807B71FC: beql        $v1, $zero, L_807B7230
    if (ctx->r3 == 0) {
        // 0x807B7200: lw          $t2, 0x1E4($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1E4);
            goto L_807B7230;
    }
    goto skip_3;
    // 0x807B7200: lw          $t2, 0x1E4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E4);
    skip_3:
    // 0x807B7204: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x807B7208: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x807B720C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807B7210: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B7214: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807B7218: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x807B721C: lw          $t0, 0x20($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X20);
    // 0x807B7220: swc1        $f0, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f0.u32l;
    // 0x807B7224: lw          $t1, 0x24($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X24);
    // 0x807B7228: swc1        $f0, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f0.u32l;
    // 0x807B722C: lw          $t2, 0x1E4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E4);
L_807B7230:
    // 0x807B7230: slti        $at, $t2, 0x78
    ctx->r1 = SIGNED(ctx->r10) < 0X78 ? 1 : 0;
    // 0x807B7234: bnel        $at, $zero, L_807B7244
    if (ctx->r1 != 0) {
        // 0x807B7238: lw          $t3, 0x8($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X8);
            goto L_807B7244;
    }
    goto skip_4;
    // 0x807B7238: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
    skip_4:
    // 0x807B723C: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x807B7240: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
L_807B7244:
    // 0x807B7244: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x807B7248: lhu         $t4, 0xC($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC);
    // 0x807B724C: andi        $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 & 0X1000;
    // 0x807B7250: bnel        $t5, $at, L_807B7388
    if (ctx->r13 != ctx->r1) {
        // 0x807B7254: lw          $t8, 0x478($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X478);
            goto L_807B7388;
    }
    goto skip_5;
    // 0x807B7254: lw          $t8, 0x478($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X478);
    skip_5:
    // 0x807B7258: jal         0x80067990
    // 0x807B725C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80067990(rdram, ctx);
        goto after_3;
    // 0x807B725C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x807B7260: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x807B7264: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x807B7268: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x807B726C: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x807B7270: jal         0x80046E88
    // 0x807B7274: addiu       $a0, $zero, 0x4013
    ctx->r4 = ADD32(0, 0X4013);
    func_80046E88(rdram, ctx);
        goto after_4;
    // 0x807B7274: addiu       $a0, $zero, 0x4013
    ctx->r4 = ADD32(0, 0X4013);
    after_4:
    // 0x807B7278: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x807B727C: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x807B7280: lw          $t6, 0x3EC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X3EC);
    // 0x807B7284: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x807B7288: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x807B728C: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x807B7290: lbu         $v1, 0x598($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X598);
    // 0x807B7294: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807B7298: beq         $v1, $at, L_807B72F4
    if (ctx->r3 == ctx->r1) {
        // 0x807B729C: addiu       $at, $zero, 0xA7
        ctx->r1 = ADD32(0, 0XA7);
            goto L_807B72F4;
    }
    // 0x807B729C: addiu       $at, $zero, 0xA7
    ctx->r1 = ADD32(0, 0XA7);
    // 0x807B72A0: beq         $v1, $at, L_807B72F4
    if (ctx->r3 == ctx->r1) {
        // 0x807B72A4: addiu       $at, $zero, 0xA8
        ctx->r1 = ADD32(0, 0XA8);
            goto L_807B72F4;
    }
    // 0x807B72A4: addiu       $at, $zero, 0xA8
    ctx->r1 = ADD32(0, 0XA8);
    // 0x807B72A8: beq         $v1, $at, L_807B72F4
    if (ctx->r3 == ctx->r1) {
        // 0x807B72AC: addiu       $at, $zero, 0xA9
        ctx->r1 = ADD32(0, 0XA9);
            goto L_807B72F4;
    }
    // 0x807B72AC: addiu       $at, $zero, 0xA9
    ctx->r1 = ADD32(0, 0XA9);
    // 0x807B72B0: beq         $v1, $at, L_807B72F4
    if (ctx->r3 == ctx->r1) {
        // 0x807B72B4: addiu       $at, $zero, 0xA2
        ctx->r1 = ADD32(0, 0XA2);
            goto L_807B72F4;
    }
    // 0x807B72B4: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x807B72B8: beq         $v1, $at, L_807B72F4
    if (ctx->r3 == ctx->r1) {
        // 0x807B72BC: addiu       $at, $zero, 0xA4
        ctx->r1 = ADD32(0, 0XA4);
            goto L_807B72F4;
    }
    // 0x807B72BC: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x807B72C0: beq         $v1, $at, L_807B72F4
    if (ctx->r3 == ctx->r1) {
        // 0x807B72C4: addiu       $at, $zero, 0xA3
        ctx->r1 = ADD32(0, 0XA3);
            goto L_807B72F4;
    }
    // 0x807B72C4: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x807B72C8: beq         $v1, $at, L_807B72F4
    if (ctx->r3 == ctx->r1) {
        // 0x807B72CC: addiu       $at, $zero, 0xA5
        ctx->r1 = ADD32(0, 0XA5);
            goto L_807B72F4;
    }
    // 0x807B72CC: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x807B72D0: beq         $v1, $at, L_807B72F4
    if (ctx->r3 == ctx->r1) {
        // 0x807B72D4: nop
    
            goto L_807B72F4;
    }
    // 0x807B72D4: nop

    // 0x807B72D8: beq         $v0, $zero, L_807B72F4
    if (ctx->r2 == 0) {
        // 0x807B72DC: nop
    
            goto L_807B72F4;
    }
    // 0x807B72DC: nop

    // 0x807B72E0: lw          $t8, 0xB20($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XB20);
    // 0x807B72E4: bne         $t8, $zero, L_807B72F4
    if (ctx->r24 != 0) {
        // 0x807B72E8: nop
    
            goto L_807B72F4;
    }
    // 0x807B72E8: nop

    // 0x807B72EC: lbu         $t9, 0xB2C($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XB2C);
    // 0x807B72F0: sb          $t9, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r25;
L_807B72F4:
    // 0x807B72F4: jal         0x8002ADE4
    // 0x807B72F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8002ADE4(rdram, ctx);
        goto after_5;
    // 0x807B72F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_5:
    // 0x807B72FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x807B7300: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x807B7304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B7308: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x807B730C: sb          $a3, 0x165($t0)
    MEM_B(0X165, ctx->r8) = ctx->r7;
    // 0x807B7310: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x807B7314: sb          $a3, 0x165($t1)
    MEM_B(0X165, ctx->r9) = ctx->r7;
    // 0x807B7318: lw          $t2, 0xC($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XC);
    // 0x807B731C: sb          $a3, 0x165($t2)
    MEM_B(0X165, ctx->r10) = ctx->r7;
    // 0x807B7320: lw          $t3, 0x10($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X10);
    // 0x807B7324: sb          $a3, 0x165($t3)
    MEM_B(0X165, ctx->r11) = ctx->r7;
    // 0x807B7328: lw          $t4, 0x14($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X14);
    // 0x807B732C: sb          $a3, 0x165($t4)
    MEM_B(0X165, ctx->r12) = ctx->r7;
    // 0x807B7330: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x807B7334: beql        $v0, $zero, L_807B7344
    if (ctx->r2 == 0) {
        // 0x807B7338: lw          $t5, 0x8($a1)
        ctx->r13 = MEM_W(ctx->r5, 0X8);
            goto L_807B7344;
    }
    goto skip_6;
    // 0x807B7338: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
    skip_6:
    // 0x807B733C: sb          $a3, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r7;
    // 0x807B7340: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
L_807B7344:
    // 0x807B7344: sb          $a3, 0x165($t5)
    MEM_B(0X165, ctx->r13) = ctx->r7;
    // 0x807B7348: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    // 0x807B734C: beq         $v1, $zero, L_807B7368
    if (ctx->r3 == 0) {
        // 0x807B7350: nop
    
            goto L_807B7368;
    }
    // 0x807B7350: nop

    // 0x807B7354: sb          $a3, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r7;
    // 0x807B7358: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // 0x807B735C: sb          $a3, 0x165($t6)
    MEM_B(0X165, ctx->r14) = ctx->r7;
    // 0x807B7360: lw          $t7, 0x24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X24);
    // 0x807B7364: sb          $a3, 0x165($t7)
    MEM_B(0X165, ctx->r15) = ctx->r7;
L_807B7368:
    // 0x807B7368: jal         0x807B73B0
    // 0x807B736C: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    func_807B73B0(rdram, ctx);
        goto after_6;
    // 0x807B736C: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_6:
    // 0x807B7370: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x807B7374: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x807B7378: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807B737C: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x807B7380: sb          $a3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r7;
    // 0x807B7384: lw          $t8, 0x478($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X478);
L_807B7388:
    // 0x807B7388: lwc1        $f10, 0x30($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X30);
    // 0x807B738C: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x807B7390: lw          $t9, 0x478($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X478);
    // 0x807B7394: lwc1        $f16, 0x34($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X34);
    // 0x807B7398: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
L_807B739C:
    // 0x807B739C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B73A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B73A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B73A8: jr          $ra
    // 0x807B73AC: nop

    return;
    // 0x807B73AC: nop

;}
RECOMP_FUNC void func_807B03A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B03A4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x807B03A8: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x807B03AC: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x807B03B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x807B03B4: lw          $t1, 0x20($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X20);
    // 0x807B03B8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x807B03BC: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x807B03C0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x807B03C4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807B03C8: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x807B03CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807B03D0: ori         $t7, $t7, 0x18
    ctx->r15 = ctx->r15 | 0X18;
    // 0x807B03D4: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x807B03D8: ori         $t8, $t8, 0x2CF0
    ctx->r24 = ctx->r24 | 0X2CF0;
    // 0x807B03DC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x807B03E0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x807B03E4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x807B03E8: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x807B03EC: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x807B03F0: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x807B03F4: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x807B03F8: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x807B03FC: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x807B0400: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x807B0404: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x807B0408: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x807B040C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x807B0410: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x807B0414: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x807B0418: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x807B041C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x807B0420: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x807B0424: lbu         $t9, 0x3($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3);
    // 0x807B0428: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x807B042C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x807B0430: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x807B0434: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x807B0438: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x807B043C: lui         $t4, 0x402
    ctx->r12 = S32(0X402 << 16);
    // 0x807B0440: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x807B0444: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x807B0448: lbu         $t6, 0x2($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X2);
    // 0x807B044C: ori         $t4, $t4, 0x3CEF
    ctx->r12 = ctx->r12 | 0X3CEF;
    // 0x807B0450: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x807B0454: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x807B0458: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x807B045C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x807B0460: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x807B0464: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807B0468: lbu         $t6, 0x4($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X4);
    // 0x807B046C: lbu         $t8, 0x7($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X7);
    // 0x807B0470: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x807B0474: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x807B0478: lbu         $t8, 0x5($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X5);
    // 0x807B047C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x807B0480: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x807B0484: lbu         $t9, 0x6($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X6);
    // 0x807B0488: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x807B048C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x807B0490: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x807B0494: lui         $t6, 0x44FE
    ctx->r14 = S32(0X44FE << 16);
    // 0x807B0498: lui         $t9, 0xFC30
    ctx->r25 = S32(0XFC30 << 16);
    // 0x807B049C: ori         $t9, $t9, 0xFE61
    ctx->r25 = ctx->r25 | 0XFE61;
    // 0x807B04A0: ori         $t6, $t6, 0x7339
    ctx->r14 = ctx->r14 | 0X7339;
    // 0x807B04A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x807B04A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x807B04AC: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x807B04B0: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x807B04B4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x807B04B8: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x807B04BC: addiu       $t8, $zero, 0x204
    ctx->r24 = ADD32(0, 0X204);
    // 0x807B04C0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x807B04C4: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x807B04C8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x807B04CC: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x807B04D0: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x807B04D4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807B04D8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x807B04DC: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x807B04E0: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x807B04E4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x807B04E8: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x807B04EC: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x807B04F0: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x807B04F4: addiu       $t9, $t8, 0x800
    ctx->r25 = ADD32(ctx->r24, 0X800);
    // 0x807B04F8: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x807B04FC: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x807B0500: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x807B0504: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x807B0508: addiu       $v1, $a3, 0x8
    ctx->r3 = ADD32(ctx->r7, 0X8);
    // 0x807B050C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x807B0510: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x807B0514: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x807B0518: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x807B051C: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x807B0520: ori         $t6, $t6, 0xF200
    ctx->r14 = ctx->r14 | 0XF200;
    // 0x807B0524: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x807B0528: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x807B052C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x807B0530: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x807B0534: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x807B0538: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x807B053C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x807B0540: lui         $t7, 0xF568
    ctx->r15 = S32(0XF568 << 16);
    // 0x807B0544: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x807B0548: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x807B054C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x807B0550: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x807B0554: lui         $t9, 0x7
    ctx->r25 = S32(0X7 << 16);
    // 0x807B0558: ori         $t9, $t9, 0xC0FC
    ctx->r25 = ctx->r25 | 0XC0FC;
    // 0x807B055C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x807B0560: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x807B0564: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x807B0568: addiu       $t2, $a3, 0x8
    ctx->r10 = ADD32(ctx->r7, 0X8);
    // 0x807B056C: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x807B0570: ori         $t6, $t6, 0x40F
    ctx->r14 = ctx->r14 | 0X40F;
    // 0x807B0574: addiu       $v1, $t2, 0x8
    ctx->r3 = ADD32(ctx->r10, 0X8);
    // 0x807B0578: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x807B057C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x807B0580: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x807B0584: addiu       $t7, $t1, 0x20
    ctx->r15 = ADD32(ctx->r9, 0X20);
    // 0x807B0588: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x807B058C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x807B0590: lui         $a3, 0x807B
    ctx->r7 = S32(RELOC_HI16(871, 0X3510) << 16);
    // 0x807B0594: addiu       $a3, $a3, 0x3060
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(871, 0X3510));
    // 0x807B0598: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x807B059C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x807B05A0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x807B05A4: addiu       $a2, $v0, 0x8
    ctx->r6 = ADD32(ctx->r2, 0X8);
    // 0x807B05A8: addiu       $t8, $t1, 0x100
    ctx->r24 = ADD32(ctx->r9, 0X100);
    // 0x807B05AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807B05B0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807B05B4: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x807B05B8: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
    // 0x807B05BC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x807B05C0: lui         $t9, 0x402
    ctx->r25 = S32(0X402 << 16);
    // 0x807B05C4: ori         $t9, $t9, 0x144F
    ctx->r25 = ctx->r25 | 0X144F;
    // 0x807B05C8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x807B05CC: addiu       $t6, $t1, 0x1E0
    ctx->r14 = ADD32(ctx->r9, 0X1E0);
    // 0x807B05D0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x807B05D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x807B05D8: lui         $t2, 0x807B
    ctx->r10 = S32(RELOC_HI16(871, 0X3588) << 16);
    // 0x807B05DC: addiu       $t2, $t2, 0x30D8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(871, 0X3588));
    // 0x807B05E0: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x807B05E4: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x807B05E8: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x807B05EC: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x807B05F0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x807B05F4: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x807B05F8: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x807B05FC: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x807B0600: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x807B0604: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x807B0608: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x807B060C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x807B0610: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x807B0614: addiu       $a0, $t3, 0x8
    ctx->r4 = ADD32(ctx->r11, 0X8);
    // 0x807B0618: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x807B061C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x807B0620: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x807B0624: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x807B0628: ori         $t9, $t9, 0xF200
    ctx->r25 = ctx->r25 | 0XF200;
    // 0x807B062C: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x807B0630: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x807B0634: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x807B0638: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x807B063C: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x807B0640: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x807B0644: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x807B0648: lui         $t6, 0xF568
    ctx->r14 = S32(0XF568 << 16);
    // 0x807B064C: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x807B0650: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x807B0654: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x807B0658: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x807B065C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x807B0660: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x807B0664: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x807B0668: lui         $t9, 0x7
    ctx->r25 = S32(0X7 << 16);
    // 0x807B066C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807B0670: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x807B0674: ori         $t9, $t9, 0xC0FC
    ctx->r25 = ctx->r25 | 0XC0FC;
    // 0x807B0678: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x807B067C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x807B0680: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x807B0684: ori         $t7, $t7, 0x40F
    ctx->r15 = ctx->r15 | 0X40F;
    // 0x807B0688: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x807B068C: addiu       $t8, $t1, 0x10
    ctx->r24 = ADD32(ctx->r9, 0X10);
    // 0x807B0690: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x807B0694: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x807B0698: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x807B069C: addiu       $t9, $t1, 0x230
    ctx->r25 = ADD32(ctx->r9, 0X230);
    // 0x807B06A0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x807B06A4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807B06A8: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x807B06AC: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x807B06B0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x807B06B4: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x807B06B8: addiu       $t6, $t1, 0x310
    ctx->r14 = ADD32(ctx->r9, 0X310);
    // 0x807B06BC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x807B06C0: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x807B06C4: addiu       $v1, $t3, 0x8
    ctx->r3 = ADD32(ctx->r11, 0X8);
    // 0x807B06C8: sw          $a3, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r7;
    // 0x807B06CC: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x807B06D0: lui         $t7, 0x402
    ctx->r15 = S32(0X402 << 16);
    // 0x807B06D4: ori         $t7, $t7, 0x144F
    ctx->r15 = ctx->r15 | 0X144F;
    // 0x807B06D8: addiu       $t8, $t1, 0x3F0
    ctx->r24 = ADD32(ctx->r9, 0X3F0);
    // 0x807B06DC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x807B06E0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x807B06E4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x807B06E8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x807B06EC: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x807B06F0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x807B06F4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x807B06F8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x807B06FC: jr          $ra
    // 0x807B0700: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    return;
    // 0x807B0700: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
;}
RECOMP_FUNC void func_804F4E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4E30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804F4E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F4E38: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x804F4E3C: lw          $t6, 0xA8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA8);
    // 0x804F4E40: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804F4E44: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x804F4E48: bne         $t6, $zero, L_804F4F30
    if (ctx->r14 != 0) {
        // 0x804F4E4C: addiu       $a3, $v0, 0x8
        ctx->r7 = ADD32(ctx->r2, 0X8);
            goto L_804F4F30;
    }
    // 0x804F4E4C: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    // 0x804F4E50: lw          $a2, 0xA4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XA4);
    // 0x804F4E54: lw          $t7, 0xA0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XA0);
    // 0x804F4E58: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20850) << 16);
    // 0x804F4E5C: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    // 0x804F4E60: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x804F4E64: beq         $at, $zero, L_804F4EBC
    if (ctx->r1 == 0) {
        // 0x804F4E68: addiu       $a1, $a1, 0x4AE0
        ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20850));
            goto L_804F4EBC;
    }
    // 0x804F4E68: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20850));
    // 0x804F4E6C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x804F4E70: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x804F4E74: lui         $t2, 0x8051
    ctx->r10 = S32(RELOC_HI16(273, 0X207C4) << 16);
    // 0x804F4E78: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804F4E7C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x804F4E80: lui         $t5, 0x8051
    ctx->r13 = S32(RELOC_HI16(273, 0X207CC) << 16);
    // 0x804F4E84: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x804F4E88: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804F4E8C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x804F4E90: lhu         $t2, 0x4A54($t2)
    ctx->r10 = MEM_HU(ctx->r10, (int16_t)RELOC_LO16(273, 0X207C4));
    // 0x804F4E94: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x804F4E98: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x804F4E9C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804F4EA0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x804F4EA4: lhu         $t5, 0x4A5C($t5)
    ctx->r13 = MEM_HU(ctx->r13, (int16_t)RELOC_LO16(273, 0X207CC));
    // 0x804F4EA8: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
    // 0x804F4EAC: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x804F4EB0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804F4EB4: b           L_804F4F24
    // 0x804F4EB8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
        goto L_804F4F24;
    // 0x804F4EB8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
L_804F4EBC:
    // 0x804F4EBC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x804F4EC0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x804F4EC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804F4EC8: jal         0x804F4C88
    // 0x804F4ECC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_804F4C88(rdram, ctx);
        goto after_0;
    // 0x804F4ECC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x804F4ED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804F4ED4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804F4ED8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804F4EDC: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x804F4EE0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x804F4EE4: lui         $t3, 0x8051
    ctx->r11 = S32(RELOC_HI16(273, 0X207C4) << 16);
    // 0x804F4EE8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804F4EEC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804F4EF0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x804F4EF4: lui         $t6, 0x8051
    ctx->r14 = S32(RELOC_HI16(273, 0X207CC) << 16);
    // 0x804F4EF8: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x804F4EFC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x804F4F00: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x804F4F04: lhu         $t3, 0x4A54($t3)
    ctx->r11 = MEM_HU(ctx->r11, (int16_t)RELOC_LO16(273, 0X207C4));
    // 0x804F4F08: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x804F4F0C: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x804F4F10: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x804F4F14: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x804F4F18: lhu         $t6, 0x4A5C($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(273, 0X207CC));
    // 0x804F4F1C: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x804F4F20: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
L_804F4F24:
    // 0x804F4F24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804F4F28: b           L_804F4F40
    // 0x804F4F2C: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
        goto L_804F4F40;
    // 0x804F4F2C: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
L_804F4F30:
    // 0x804F4F30: addiu       $a0, $a1, 0x98
    ctx->r4 = ADD32(ctx->r5, 0X98);
    // 0x804F4F34: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    // 0x804F4F38: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x804F4F3C: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
L_804F4F40:
    // 0x804F4F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F4F44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804F4F48: jr          $ra
    // 0x804F4F4C: nop

    return;
    // 0x804F4F4C: nop

;}
RECOMP_FUNC void func_8052D6A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D6A8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8052D6AC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8052D6B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8052D6B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8052D6B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8052D6BC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8052D6C0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8052D6C4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8052D6C8: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(330, 0X16D0) << 16);
    // 0x8052D6CC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8052D6D0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8052D6D4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8052D6D8: lw          $t1, -0x2360($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(330, 0X16D0));
    // 0x8052D6DC: jr          $ra
    // 0x8052D6E0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8052D6E0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80029080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002908C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80029090: jal         0x80028A78
    // 0x80029094: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80028A78(rdram, ctx);
        goto after_0;
    // 0x80029094: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80029098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002909C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800290A0: jal         0x80028DB4
    // 0x800290A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80028DB4(rdram, ctx);
        goto after_1;
    // 0x800290A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800290A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800290AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800290B0: jr          $ra
    // 0x800290B4: nop

    return;
    // 0x800290B4: nop

;}
RECOMP_FUNC void func_8078CEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078CEC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078CECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078CED0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078CED4: jal         0x8004700C
    // 0x8078CED8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078CED8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8078CEDC: beq         $v0, $zero, L_8078CF4C
    if (ctx->r2 == 0) {
        // 0x8078CEE0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8078CF4C;
    }
    // 0x8078CEE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8078CEE4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8078CEE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8078CEEC: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x8078CEF0: beq         $v0, $zero, L_8078CF00
    if (ctx->r2 == 0) {
        // 0x8078CEF4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8078CF00;
    }
    // 0x8078CEF4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8078CEF8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8078CEFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8078CF00:
    // 0x8078CF00: bne         $v0, $zero, L_8078CF4C
    if (ctx->r2 != 0) {
        // 0x8078CF04: lui         $t1, 0x8079
        ctx->r9 = S32(RELOC_HI16(799, 0X188) << 16);
            goto L_8078CF4C;
    }
    // 0x8078CF04: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(799, 0X188) << 16);
    // 0x8078CF08: lw          $v0, 0xEC0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XEC0);
    // 0x8078CF0C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8078CF10: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8078CF14: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8078CF18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8078CF1C: lw          $v0, 0xEC0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XEC0);
    // 0x8078CF20: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8078CF24: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x8078CF28: bnel        $at, $zero, L_8078CF40
    if (ctx->r1 != 0) {
        // 0x8078CF2C: sll         $t0, $v1, 2
        ctx->r8 = S32(ctx->r3 << 2);
            goto L_8078CF40;
    }
    goto skip_0;
    // 0x8078CF2C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    skip_0:
    // 0x8078CF30: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8078CF34: lw          $t9, -0x72A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72A0);
    // 0x8078CF38: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8078CF3C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
L_8078CF40:
    // 0x8078CF40: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078CF44: lw          $t1, -0x2FD8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(799, 0X188));
    // 0x8078CF48: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_8078CF4C:
    // 0x8078CF4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078CF50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078CF54: jr          $ra
    // 0x8078CF58: nop

    return;
    // 0x8078CF58: nop

;}
RECOMP_FUNC void func_8051AC64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051AC64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051AC68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051AC6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8051AC70: jal         0x8051A530
    // 0x8051AC74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8051A530(rdram, ctx);
        goto after_0;
    // 0x8051AC74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8051AC78: jal         0x8051A8E0
    // 0x8051AC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A8E0(rdram, ctx);
        goto after_1;
    // 0x8051AC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8051AC80: beq         $v0, $zero, L_8051ACB4
    if (ctx->r2 == 0) {
        // 0x8051AC84: lui         $t8, 0x8005
        ctx->r24 = S32(0X8005 << 16);
            goto L_8051ACB4;
    }
    // 0x8051AC84: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8051AC88: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8051AC8C: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x8051AC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051AC94: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8051AC98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051AC9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8051ACA0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8051ACA4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8051ACA8: sw          $t8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r24;
    // 0x8051ACAC: jal         0x8051ADC0
    // 0x8051ACB0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8051ADC0(rdram, ctx);
        goto after_2;
    // 0x8051ACB0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
L_8051ACB4:
    // 0x8051ACB4: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x8051ACB8: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8051ACBC: bne         $t9, $at, L_8051ACCC
    if (ctx->r25 != ctx->r1) {
        // 0x8051ACC0: nop
    
            goto L_8051ACCC;
    }
    // 0x8051ACC0: nop

    // 0x8051ACC4: jal         0x8051AB48
    // 0x8051ACC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051AB48(rdram, ctx);
        goto after_3;
    // 0x8051ACC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8051ACCC:
    // 0x8051ACCC: jal         0x8051A568
    // 0x8051ACD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A568(rdram, ctx);
        goto after_4;
    // 0x8051ACD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8051ACD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8051ACD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8051ACDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051ACE0: jr          $ra
    // 0x8051ACE4: nop

    return;
    // 0x8051ACE4: nop

;}
RECOMP_FUNC void func_8045C8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045C8A4: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x8045C8A8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8045C8AC: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8045C8B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8045C8B4: bc1f        L_8045C8C0
    if (!c1cs) {
        // 0x8045C8B8: nop
    
            goto L_8045C8C0;
    }
    // 0x8045C8B8: nop

    // 0x8045C8BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8045C8C0:
    // 0x8045C8C0: beq         $v0, $zero, L_8045C8DC
    if (ctx->r2 == 0) {
        // 0x8045C8C4: nop
    
            goto L_8045C8DC;
    }
    // 0x8045C8C4: nop

    // 0x8045C8C8: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x8045C8CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8045C8D0: bc1f        L_8045C8DC
    if (!c1cs) {
        // 0x8045C8D4: nop
    
            goto L_8045C8DC;
    }
    // 0x8045C8D4: nop

    // 0x8045C8D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8045C8DC:
    // 0x8045C8DC: jr          $ra
    // 0x8045C8E0: nop

    return;
    // 0x8045C8E0: nop

;}
RECOMP_FUNC void func_806F2B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2B8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806F2B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2B94: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806F2B98: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806F2B9C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806F2BA0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806F2BA4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x806F2BA8: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806F2BAC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BF0) << 16);
    // 0x806F2BB0: lwc1        $f10, 0x3170($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BF0));
    // 0x806F2BB4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x806F2BB8: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x806F2BBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F2BC0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806F2BC4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806F2BC8: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806F2BCC: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x806F2BD0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x806F2BD4: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x806F2BD8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806F2BDC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806F2BE0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806F2BE4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806F2BE8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806F2BEC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806F2BF0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x806F2BF4: jalr        $t9
    // 0x806F2BF8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806F2BF8: nop

    after_0:
    // 0x806F2BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2C00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806F2C04: jr          $ra
    // 0x806F2C08: nop

    return;
    // 0x806F2C08: nop

;}
RECOMP_FUNC void func_80447A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447A3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447A40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447A48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447A4C: bne         $a2, $zero, L_80447A8C
    if (ctx->r6 != 0) {
        // 0x80447A50: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80447A8C;
    }
    // 0x80447A50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80447A54: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80447A58: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x80447A5C: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80447A60: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80447A64: bne         $at, $zero, L_80447ACC
    if (ctx->r1 != 0) {
        // 0x80447A68: sw          $t7, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r15;
            goto L_80447ACC;
    }
    // 0x80447A68: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80447A6C: jal         0x8044625C
    // 0x80447A70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044625C(rdram, ctx);
        goto after_0;
    // 0x80447A70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80447A74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447A78: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447A7C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80447A80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447A84: b           L_80447ACC
    // 0x80447A88: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80447ACC;
    // 0x80447A88: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80447A8C:
    // 0x80447A8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447A90: bnel        $a2, $at, L_80447ABC
    if (ctx->r6 != ctx->r1) {
        // 0x80447A94: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80447ABC;
    }
    goto skip_0;
    // 0x80447A94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80447A98: jal         0x8044625C
    // 0x80447A9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044625C(rdram, ctx);
        goto after_1;
    // 0x80447A9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80447AA0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447AA4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447AA8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80447AAC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447AB0: b           L_80447ACC
    // 0x80447AB4: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80447ACC;
    // 0x80447AB4: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80447AB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80447ABC:
    // 0x80447ABC: bnel        $a2, $at, L_80447AD0
    if (ctx->r6 != ctx->r1) {
        // 0x80447AC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447AD0;
    }
    goto skip_1;
    // 0x80447AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447AC4: jal         0x804462C0
    // 0x80447AC8: nop

    func_804462C0(rdram, ctx);
        goto after_2;
    // 0x80447AC8: nop

    after_2:
L_80447ACC:
    // 0x80447ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447AD0:
    // 0x80447AD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447AD8: jr          $ra
    // 0x80447ADC: nop

    return;
    // 0x80447ADC: nop

;}
RECOMP_FUNC void func_8046BD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BD28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046BD2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046BD30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046BD34: jal         0x80045A34
    // 0x8046BD38: addiu       $a1, $zero, 0xEA8
    ctx->r5 = ADD32(0, 0XEA8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8046BD38: addiu       $a1, $zero, 0xEA8
    ctx->r5 = ADD32(0, 0XEA8);
    after_0:
    // 0x8046BD3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046BD40: bne         $v0, $zero, L_8046BD50
    if (ctx->r2 != 0) {
        // 0x8046BD44: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8046BD50;
    }
    // 0x8046BD44: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8046BD48: b           L_8046BD5C
    // 0x8046BD4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8046BD5C;
    // 0x8046BD4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046BD50:
    // 0x8046BD50: jal         0x8046BC90
    // 0x8046BD54: nop

    func_8046BC90(rdram, ctx);
        goto after_1;
    // 0x8046BD54: nop

    after_1:
    // 0x8046BD58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8046BD5C:
    // 0x8046BD5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046BD60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046BD64: jr          $ra
    // 0x8046BD68: nop

    return;
    // 0x8046BD68: nop

;}
RECOMP_FUNC void func_804C2A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2A80: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804C2A84: addiu       $at, $zero, 0x4121
    ctx->r1 = ADD32(0, 0X4121);
    // 0x804C2A88: beq         $v0, $at, L_804C2AA0
    if (ctx->r2 == ctx->r1) {
        // 0x804C2A8C: addiu       $at, $zero, 0x4122
        ctx->r1 = ADD32(0, 0X4122);
            goto L_804C2AA0;
    }
    // 0x804C2A8C: addiu       $at, $zero, 0x4122
    ctx->r1 = ADD32(0, 0X4122);
    // 0x804C2A90: beq         $v0, $at, L_804C2AAC
    if (ctx->r2 == ctx->r1) {
        // 0x804C2A94: nop
    
            goto L_804C2AAC;
    }
    // 0x804C2A94: nop

    // 0x804C2A98: b           L_804C2AB8
    // 0x804C2A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C2AB8;
    // 0x804C2A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C2AA0:
    // 0x804C2AA0: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(206, 0XB0C) << 16);
    // 0x804C2AA4: jr          $ra
    // 0x804C2AA8: addiu       $v0, $v0, 0x358C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(206, 0XB0C));
    return;
    // 0x804C2AA8: addiu       $v0, $v0, 0x358C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(206, 0XB0C));
L_804C2AAC:
    // 0x804C2AAC: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(206, 0X1300) << 16);
    // 0x804C2AB0: jr          $ra
    // 0x804C2AB4: addiu       $v0, $v0, 0x3D80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(206, 0X1300));
    return;
    // 0x804C2AB4: addiu       $v0, $v0, 0x3D80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(206, 0X1300));
L_804C2AB8:
    // 0x804C2AB8: jr          $ra
    // 0x804C2ABC: nop

    return;
    // 0x804C2ABC: nop

;}
