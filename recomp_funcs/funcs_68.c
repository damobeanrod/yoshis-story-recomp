#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80042E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042E2C: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80042E30: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x80042E34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042E38: lh          $v0, 0xADE($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XADE);
    // 0x80042E3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80042E40: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80042E44: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80042E48: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042E50: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80042E54: beq         $at, $zero, L_80042E68
    if (ctx->r1 == 0) {
        // 0x80042E58: lh          $v1, 0xAE0($a2)
        ctx->r3 = MEM_H(ctx->r6, 0XAE0);
            goto L_80042E68;
    }
    // 0x80042E58: lh          $v1, 0xAE0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XAE0);
    // 0x80042E5C: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80042E60: b           L_80042E80
    // 0x80042E64: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80042E80;
    // 0x80042E64: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80042E68:
    // 0x80042E68: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    // 0x80042E6C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042E70: beql        $at, $zero, L_80042E84
    if (ctx->r1 == 0) {
        // 0x80042E74: slti        $at, $v1, -0x27
        ctx->r1 = SIGNED(ctx->r3) < -0X27 ? 1 : 0;
            goto L_80042E84;
    }
    goto skip_0;
    // 0x80042E74: slti        $at, $v1, -0x27
    ctx->r1 = SIGNED(ctx->r3) < -0X27 ? 1 : 0;
    skip_0:
    // 0x80042E78: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80042E7C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80042E80:
    // 0x80042E80: slti        $at, $v1, -0x27
    ctx->r1 = SIGNED(ctx->r3) < -0X27 ? 1 : 0;
L_80042E84:
    // 0x80042E84: bne         $at, $zero, L_80042E90
    if (ctx->r1 != 0) {
        // 0x80042E88: nop
    
            goto L_80042E90;
    }
    // 0x80042E88: nop

    // 0x80042E8C: addiu       $v1, $zero, -0x28
    ctx->r3 = ADD32(0, -0X28);
L_80042E90:
    // 0x80042E90: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042E94: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80042E98: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80042E9C: sh          $v0, 0xADE($a2)
    MEM_H(0XADE, ctx->r6) = ctx->r2;
    // 0x80042EA0: sh          $v1, 0xAE0($a2)
    MEM_H(0XAE0, ctx->r6) = ctx->r3;
    // 0x80042EA4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80042EA8: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80042EAC: mflo        $t6
    ctx->r14 = lo;
    // 0x80042EB0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80042EB4: nop

    // 0x80042EB8: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042EBC: mflo        $t7
    ctx->r15 = lo;
    // 0x80042EC0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80042EC4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80042EC8: nop

    // 0x80042ECC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80042ED0: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80042ED4: jal         0x80081E8C
    // 0x80042ED8: swc1        $f0, 0xAE8($a2)
    MEM_W(0XAE8, ctx->r6) = ctx->f0.u32l;
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80042ED8: swc1        $f0, 0xAE8($a2)
    MEM_W(0XAE8, ctx->r6) = ctx->f0.u32l;
    after_0:
    // 0x80042EDC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80042EE0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80042EE4: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x80042EE8: swc1        $f0, 0xAF0($a2)
    MEM_W(0XAF0, ctx->r6) = ctx->f0.u32l;
    // 0x80042EEC: lbu         $t9, 0x12C9($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X12C9);
    // 0x80042EF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80042EF4: sh          $t1, 0x150($a3)
    MEM_H(0X150, ctx->r7) = ctx->r9;
    // 0x80042EF8: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x80042EFC: sb          $t0, 0x12C9($a3)
    MEM_B(0X12C9, ctx->r7) = ctx->r8;
    // 0x80042F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042F08: jr          $ra
    // 0x80042F0C: nop

    return;
    // 0x80042F0C: nop

;}
RECOMP_FUNC void func_8051AB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051AB48: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8051AB4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8051AB50: lui         $at, 0x4224
    ctx->r1 = S32(0X4224 << 16);
    // 0x8051AB54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8051AB58: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(294, 0XCD0) << 16);
    // 0x8051AB5C: lwc1        $f18, -0x4E10($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(294, 0XCD0));
    // 0x8051AB60: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8051AB64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051AB68: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8051AB6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8051AB70: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8051AB74: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8051AB78: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(294, 0XCD4) << 16);
    // 0x8051AB7C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8051AB80: lwc1        $f10, -0x4E0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(294, 0XCD4));
    // 0x8051AB84: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8051AB88: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8051AB8C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x8051AB90: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8051AB94: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8051AB98: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8051AB9C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8051ABA0: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8051ABA4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8051ABA8: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8051ABAC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8051ABB0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8051ABB4: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8051ABB8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8051ABBC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x8051ABC0: bnel        $t6, $zero, L_8051ABE4
    if (ctx->r14 != 0) {
        // 0x8051ABC4: lwc1        $f8, 0x3C($a3)
        ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
            goto L_8051ABE4;
    }
    goto skip_0;
    // 0x8051ABC4: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
    skip_0:
    // 0x8051ABC8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8051ABCC: nop

    // 0x8051ABD0: mul.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8051ABD4: nop

    // 0x8051ABD8: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8051ABDC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8051ABE0: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
L_8051ABE4:
    // 0x8051ABE4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8051ABE8: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8051ABEC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8051ABF0: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8051ABF4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8051ABF8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x8051ABFC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8051AC00: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8051AC04: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8051AC08: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8051AC0C: jalr        $t9
    // 0x8051AC10: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8051AC10: nop

    after_0:
    // 0x8051AC14: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8051AC18: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8051AC1C: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8051AC20: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8051AC24: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    // 0x8051AC28: jal         0x8051AAEC
    // 0x8051AC2C: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    func_8051AAEC(rdram, ctx);
        goto after_1;
    // 0x8051AC2C: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    after_1:
    // 0x8051AC30: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8051AC34: lw          $t0, 0x138($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X138);
    // 0x8051AC38: sw          $t0, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r8;
    // 0x8051AC3C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x8051AC40: jal         0x80067BBC
    // 0x8051AC44: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8051AC44: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    after_2:
    // 0x8051AC48: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8051AC4C: jal         0x80067818
    // 0x8051AC50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8051AC50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8051AC54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051AC58: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8051AC5C: jr          $ra
    // 0x8051AC60: nop

    return;
    // 0x8051AC60: nop

;}
RECOMP_FUNC void func_8059EBBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059EBBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8059EBC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059EBC4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8059EBC8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8059EBCC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8059EBD0: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(405, 0X7FC) << 16);
    // 0x8059EBD4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8059EBD8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8059EBDC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8059EBE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8059EBE4: lw          $t8, -0xDB4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(405, 0X7FC));
    // 0x8059EBE8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8059EBEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8059EBF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8059EBF4: jal         0x80048490
    // 0x8059EBF8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8059EBF8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8059EBFC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8059EC00: jal         0x80048378
    // 0x8059EC04: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8059EC04: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8059EC08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8059EC0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8059EC10: jr          $ra
    // 0x8059EC14: nop

    return;
    // 0x8059EC14: nop

;}
RECOMP_FUNC void func_804B8674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8674: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804B8678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B867C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x804B8680: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804B8684: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804B8688: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804B868C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x804B8690: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804B8694: lw          $t8, 0x1F0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F0);
    // 0x804B8698: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x804B869C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x804B86A0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x804B86A4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x804B86A8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x804B86AC: lw          $t1, 0x168($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X168);
    // 0x804B86B0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804B86B4: lw          $t2, 0x88($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X88);
    // 0x804B86B8: jal         0x80077338
    // 0x804B86BC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x804B86BC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    after_0:
    // 0x804B86C0: jal         0x80058958
    // 0x804B86C4: nop

    func_80058958(rdram, ctx);
        goto after_1;
    // 0x804B86C4: nop

    after_1:
    // 0x804B86C8: beq         $v0, $zero, L_804B8728
    if (ctx->r2 == 0) {
        // 0x804B86CC: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_804B8728;
    }
    // 0x804B86CC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804B86D0: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804B86D4: lw          $t3, -0x7BC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7BC4);
    // 0x804B86D8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x804B86DC: lui         $t9, 0xFC11
    ctx->r25 = S32(0XFC11 << 16);
    // 0x804B86E0: lw          $t4, 0x10C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10C);
    // 0x804B86E4: ori         $t9, $t9, 0xFE23
    ctx->r25 = ctx->r25 | 0XFE23;
    // 0x804B86E8: addiu       $t0, $zero, -0xC07
    ctx->r8 = ADD32(0, -0XC07);
    // 0x804B86EC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x804B86F0: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x804B86F4: beq         $t6, $zero, L_804B8728
    if (ctx->r14 == 0) {
        // 0x804B86F8: addiu       $t8, $t7, 0x8
        ctx->r24 = ADD32(ctx->r15, 0X8);
            goto L_804B8728;
    }
    // 0x804B86F8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804B86FC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x804B8700: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x804B8704: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x804B8708: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x804B870C: lui         $t4, 0x7A84
    ctx->r12 = S32(0X7A84 << 16);
    // 0x804B8710: ori         $t4, $t4, 0x7AFF
    ctx->r12 = ctx->r12 | 0X7AFF;
    // 0x804B8714: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x804B8718: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x804B871C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x804B8720: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x804B8724: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_804B8728:
    // 0x804B8728: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804B872C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804B8730: jal         0x8007711C
    // 0x804B8734: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8007711C(rdram, ctx);
        goto after_2;
    // 0x804B8734: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x804B8738: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x804B873C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804B8740: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x804B8744: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x804B8748: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x804B874C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x804B8750: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x804B8754: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804B8758: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x804B875C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x804B8760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B8764: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804B8768: jr          $ra
    // 0x804B876C: nop

    return;
    // 0x804B876C: nop

;}
RECOMP_FUNC void func_8066AC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066AC60: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8066AC64: addiu       $at, $zero, 0x4520
    ctx->r1 = ADD32(0, 0X4520);
    // 0x8066AC68: beq         $v0, $at, L_8066AC90
    if (ctx->r2 == ctx->r1) {
        // 0x8066AC6C: addiu       $at, $zero, 0x4521
        ctx->r1 = ADD32(0, 0X4521);
            goto L_8066AC90;
    }
    // 0x8066AC6C: addiu       $at, $zero, 0x4521
    ctx->r1 = ADD32(0, 0X4521);
    // 0x8066AC70: beq         $v0, $at, L_8066AC9C
    if (ctx->r2 == ctx->r1) {
        // 0x8066AC74: addiu       $at, $zero, 0x4522
        ctx->r1 = ADD32(0, 0X4522);
            goto L_8066AC9C;
    }
    // 0x8066AC74: addiu       $at, $zero, 0x4522
    ctx->r1 = ADD32(0, 0X4522);
    // 0x8066AC78: beq         $v0, $at, L_8066ACA8
    if (ctx->r2 == ctx->r1) {
        // 0x8066AC7C: addiu       $at, $zero, 0x4523
        ctx->r1 = ADD32(0, 0X4523);
            goto L_8066ACA8;
    }
    // 0x8066AC7C: addiu       $at, $zero, 0x4523
    ctx->r1 = ADD32(0, 0X4523);
    // 0x8066AC80: beq         $v0, $at, L_8066ACB4
    if (ctx->r2 == ctx->r1) {
        // 0x8066AC84: nop
    
            goto L_8066ACB4;
    }
    // 0x8066AC84: nop

    // 0x8066AC88: b           L_8066ACC0
    // 0x8066AC8C: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(514, 0XBE0) << 16);
        goto L_8066ACC0;
    // 0x8066AC8C: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(514, 0XBE0) << 16);
L_8066AC90:
    // 0x8066AC90: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(514, 0XBE0) << 16);
    // 0x8066AC94: jr          $ra
    // 0x8066AC98: addiu       $v0, $v0, -0x47C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XBE0));
    return;
    // 0x8066AC98: addiu       $v0, $v0, -0x47C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XBE0));
L_8066AC9C:
    // 0x8066AC9C: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(514, 0XC14) << 16);
    // 0x8066ACA0: jr          $ra
    // 0x8066ACA4: addiu       $v0, $v0, -0x478C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XC14));
    return;
    // 0x8066ACA4: addiu       $v0, $v0, -0x478C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XC14));
L_8066ACA8:
    // 0x8066ACA8: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(514, 0XC68) << 16);
    // 0x8066ACAC: jr          $ra
    // 0x8066ACB0: addiu       $v0, $v0, -0x4738
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XC68));
    return;
    // 0x8066ACB0: addiu       $v0, $v0, -0x4738
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XC68));
L_8066ACB4:
    // 0x8066ACB4: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(514, 0XCB8) << 16);
    // 0x8066ACB8: jr          $ra
    // 0x8066ACBC: addiu       $v0, $v0, -0x46E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XCB8));
    return;
    // 0x8066ACBC: addiu       $v0, $v0, -0x46E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XCB8));
L_8066ACC0:
    // 0x8066ACC0: addiu       $v0, $v0, -0x47C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(514, 0XBE0));
    // 0x8066ACC4: jr          $ra
    // 0x8066ACC8: nop

    return;
    // 0x8066ACC8: nop

;}
RECOMP_FUNC void func_805158B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805158B4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x805158B8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x805158BC: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x805158C0: lw          $t6, 0x478($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X478);
    // 0x805158C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805158C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805158CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805158D0: lwc1        $f12, 0x38($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X38);
    // 0x805158D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805158D8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x805158DC: jal         0x80081C64
    // 0x805158E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x805158E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x805158E4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x805158E8: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x805158EC: lw          $v1, 0x3F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X3F4);
    // 0x805158F0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x805158F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805158F8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x805158FC: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80515900: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80515904: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80515908: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8051590C: lw          $t7, 0x478($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X478);
    // 0x80515910: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80515914: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80515918: lwc1        $f10, 0x30($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8051591C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80515920: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80515924: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1148) << 16);
    // 0x80515928: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8051592C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80515930: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x80515934: lwc1        $f18, 0x65E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0X1148));
    // 0x80515938: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8051593C: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80515940: div.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80515944: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80515948: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8051594C: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1140) << 16);
    // 0x80515950: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80515954: swc1        $f8, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f8.u32l;
    // 0x80515958: lw          $t9, 0x478($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X478);
    // 0x8051595C: lwc1        $f6, 0x34($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X34);
    // 0x80515960: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80515964: lw          $t0, 0x478($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X478);
    // 0x80515968: lwc1        $f10, 0x38($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X38);
    // 0x8051596C: swc1        $f14, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f14.u32l;
    // 0x80515970: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80515974: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x80515978: lwc1        $f8, 0x65E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0X1140));
    // 0x8051597C: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80515980: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE58) << 16);
    // 0x80515984: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80515988: nop

    // 0x8051598C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80515990: swc1        $f10, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f10.u32l;
    // 0x80515994: lwc1        $f18, 0x62F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE58));
    // 0x80515998: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8051599C: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0X1144) << 16);
    // 0x805159A0: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x805159A4: nop

    // 0x805159A8: mul.s       $f16, $f4, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x805159AC: swc1        $f16, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f16.u32l;
    // 0x805159B0: swc1        $f14, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f14.u32l;
    // 0x805159B4: lwc1        $f8, 0x65E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0X1144));
    // 0x805159B8: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x805159BC: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x805159C0: nop

    // 0x805159C4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x805159C8: swc1        $f10, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f10.u32l;
    // 0x805159CC: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x805159D0: swc1        $f16, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f16.u32l;
    // 0x805159D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805159D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805159DC: jr          $ra
    // 0x805159E0: nop

    return;
    // 0x805159E0: nop

;}
RECOMP_FUNC void func_80435B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435B10: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80435B14: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x80435B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80435B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80435B20: beq         $t6, $zero, L_80435B40
    if (ctx->r14 == 0) {
        // 0x80435B24: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80435B40;
    }
    // 0x80435B24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80435B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80435B2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80435B30: jal         0x80436234
    // 0x80435B34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80436234(rdram, ctx);
        goto after_0;
    // 0x80435B34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80435B38: jal         0x80435380
    // 0x80435B3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80435380(rdram, ctx);
        goto after_1;
    // 0x80435B3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80435B40:
    // 0x80435B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80435B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80435B48: jr          $ra
    // 0x80435B4C: nop

    return;
    // 0x80435B4C: nop

;}
RECOMP_FUNC void func_8005558C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005558C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80055590: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80055594: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80055598: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8005559C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800555A0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800555A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800555A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800555AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800555B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800555B4: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x800555B8: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800555BC: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800555C0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800555C4: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800555C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800555CC: jal         0x8004921C
    // 0x800555D0: lw          $s0, 0x88($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X88);
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x800555D0: lw          $s0, 0x88($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X88);
    after_0:
    // 0x800555D4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800555D8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800555DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800555E0: jal         0x8004921C
    // 0x800555E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x800555E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800555E8: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800555EC: lh          $t8, 0xBA($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XBA);
    // 0x800555F0: lw          $t6, 0x168($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X168);
    // 0x800555F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800555F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800555FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80055600: nop

    // 0x80055604: nop

    // 0x80055608: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005560C: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x80055610: mflo        $t9
    ctx->r25 = lo;
    // 0x80055614: addu        $s3, $t9, $t7
    ctx->r19 = ADD32(ctx->r25, ctx->r15);
    // 0x80055618: jal         0x8004921C
    // 0x8005561C: nop

    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x8005561C: nop

    after_2:
    // 0x80055620: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x80055624: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80055628: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005562C: subu        $t6, $t8, $v0
    ctx->r14 = SUB32(ctx->r24, ctx->r2);
    // 0x80055630: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80055634: jal         0x8004921C
    // 0x80055638: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x80055638: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    after_3:
    // 0x8005563C: lh          $t7, 0x2($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2);
    // 0x80055640: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80055644: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80055648: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x8005564C: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80055650: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x80055654: addiu       $s1, $s1, 0x6128
    ctx->r17 = ADD32(ctx->r17, 0X6128);
    // 0x80055658: addiu       $v1, $v1, 0x6104
    ctx->r3 = ADD32(ctx->r3, 0X6104);
    // 0x8005565C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x80055660: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80055664:
    // 0x80055664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80055668: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x8005566C: jal         0x8004921C
    // 0x80055670: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x80055670: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_4:
    // 0x80055674: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80055678: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8005567C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80055680: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80055684: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80055688: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005568C: mflo        $t7
    ctx->r15 = lo;
    // 0x80055690: sw          $t7, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r15;
    // 0x80055694: bnel        $v1, $s1, L_80055664
    if (ctx->r3 != ctx->r17) {
        // 0x80055698: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80055664;
    }
    goto skip_0;
    // 0x80055698: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x8005569C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800556A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800556A4: jal         0x8004921C
    // 0x800556A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x800556A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800556AC: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800556B0: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x800556B4: jal         0x80049018
    // 0x800556B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80049018(rdram, ctx);
        goto after_6;
    // 0x800556B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x800556BC: beq         $v0, $zero, L_80055884
    if (ctx->r2 == 0) {
        // 0x800556C0: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80055884;
    }
    // 0x800556C0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800556C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800556C8: jal         0x8004921C
    // 0x800556CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x800556CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800556D0: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x800556D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800556D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800556DC: subu        $t9, $v0, $t6
    ctx->r25 = SUB32(ctx->r2, ctx->r14);
    // 0x800556E0: addu        $s1, $t9, $s3
    ctx->r17 = ADD32(ctx->r25, ctx->r19);
    // 0x800556E4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800556E8: jal         0x8004921C
    // 0x800556EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_8;
    // 0x800556EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x800556F0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800556F4: blezl       $t7, L_8005574C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800556F8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8005574C;
    }
    goto skip_1;
    // 0x800556F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_1:
    // 0x800556FC: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
L_80055700:
    // 0x80055700: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80055704: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80055708: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x8005570C: lhu         $t7, 0x0($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X0);
    // 0x80055710: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80055714: bnel        $t8, $zero, L_8005574C
    if (ctx->r24 != 0) {
        // 0x80055718: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8005574C;
    }
    goto skip_2;
    // 0x80055718: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_2:
    // 0x8005571C: jal         0x8004921C
    // 0x80055720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_9;
    // 0x80055720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80055724: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80055728: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005572C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80055730: jal         0x8004921C
    // 0x80055734: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    func_8004921C(rdram, ctx);
        goto after_10;
    // 0x80055734: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    after_10:
    // 0x80055738: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8005573C: slt         $at, $s2, $t6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80055740: bnel        $at, $zero, L_80055700
    if (ctx->r1 != 0) {
        // 0x80055744: lbu         $t8, 0x0($s1)
        ctx->r24 = MEM_BU(ctx->r17, 0X0);
            goto L_80055700;
    }
    goto skip_3;
    // 0x80055744: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    skip_3:
    // 0x80055748: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8005574C:
    // 0x8005574C: jal         0x8004921C
    // 0x80055750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_11;
    // 0x80055750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80055754: bne         $v0, $s2, L_80055764
    if (ctx->r2 != ctx->r18) {
        // 0x80055758: lw          $t9, 0x9C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X9C);
            goto L_80055764;
    }
    // 0x80055758: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8005575C: b           L_80055A0C
    // 0x80055760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055A0C;
    // 0x80055760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80055764:
    // 0x80055764: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80055768: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005576C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80055770: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80055774: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x80055778: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8005577C: addu        $t9, $s2, $t6
    ctx->r25 = ADD32(ctx->r18, ctx->r14);
    // 0x80055780: jal         0x8004921C
    // 0x80055784: sb          $t9, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r25;
    func_8004921C(rdram, ctx);
        goto after_12;
    // 0x80055784: sb          $t9, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r25;
    after_12:
    // 0x80055788: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8005578C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80055790: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80055794: jal         0x8004921C
    // 0x80055798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_13;
    // 0x80055798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x8005579C: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800557A0: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x800557A4: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800557A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800557AC: addiu       $t3, $t3, 0x60E0
    ctx->r11 = ADD32(ctx->r11, 0X60E0);
    // 0x800557B0: addiu       $t2, $sp, 0x54
    ctx->r10 = ADD32(ctx->r29, 0X54);
    // 0x800557B4: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x800557B8: mflo        $t7
    ctx->r15 = lo;
    // 0x800557BC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800557C0: subu        $v1, $t8, $t6
    ctx->r3 = SUB32(ctx->r24, ctx->r14);
    // 0x800557C4: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x800557C8: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x800557CC: or          $ra, $t4, $zero
    ctx->r31 = ctx->r12 | 0;
    // 0x800557D0: addiu       $s1, $s1, 0x6104
    ctx->r17 = ADD32(ctx->r17, 0X6104);
    // 0x800557D4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800557D8:
    // 0x800557D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800557DC: addu        $t0, $s3, $t4
    ctx->r8 = ADD32(ctx->r19, ctx->r12);
L_800557E0:
    // 0x800557E0: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800557E4: addu        $a0, $t3, $v0
    ctx->r4 = ADD32(ctx->r11, ctx->r2);
    // 0x800557E8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800557EC: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x800557F0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800557F4: subu        $t7, $t0, $a1
    ctx->r15 = SUB32(ctx->r8, ctx->r5);
    // 0x800557F8: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800557FC: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x80055800: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x80055804: addu        $t7, $s0, $t9
    ctx->r15 = ADD32(ctx->r16, ctx->r25);
    // 0x80055808: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8005580C: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x80055810: beql        $t6, $zero, L_80055860
    if (ctx->r14 == 0) {
        // 0x80055814: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80055860;
    }
    goto skip_4;
    // 0x80055814: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_4:
    // 0x80055818: addu        $t0, $s6, $s5
    ctx->r8 = ADD32(ctx->r22, ctx->r21);
    // 0x8005581C: lbu         $t9, -0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, -0X1);
    // 0x80055820: addu        $t5, $s7, $s5
    ctx->r13 = ADD32(ctx->r23, ctx->r21);
    // 0x80055824: addu        $t8, $s1, $v0
    ctx->r24 = ADD32(ctx->r17, ctx->r2);
    // 0x80055828: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x8005582C: sb          $t7, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r15;
    // 0x80055830: lbu         $t9, -0x1($t5)
    ctx->r25 = MEM_BU(ctx->r13, -0X1);
    // 0x80055834: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80055838: addiu       $a2, $a2, 0x5
    ctx->r6 = ADD32(ctx->r6, 0X5);
    // 0x8005583C: andi        $a2, $a2, 0x7
    ctx->r6 = ctx->r6 & 0X7;
    // 0x80055840: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80055844: sb          $t7, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r15;
    // 0x80055848: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8005584C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80055850: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x80055854: b           L_8005586C
    // 0x80055858: subu        $t4, $t6, $t9
    ctx->r12 = SUB32(ctx->r14, ctx->r25);
        goto L_8005586C;
    // 0x80055858: subu        $t4, $t6, $t9
    ctx->r12 = SUB32(ctx->r14, ctx->r25);
    // 0x8005585C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80055860:
    // 0x80055860: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80055864: bne         $a3, $t1, L_800557E0
    if (ctx->r7 != ctx->r9) {
        // 0x80055868: andi        $a2, $a2, 0x7
        ctx->r6 = ctx->r6 & 0X7;
            goto L_800557E0;
    }
    // 0x80055868: andi        $a2, $a2, 0x7
    ctx->r6 = ctx->r6 & 0X7;
L_8005586C:
    // 0x8005586C: beql        $a3, $t1, L_80055A0C
    if (ctx->r7 == ctx->r9) {
        // 0x80055870: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_80055A0C;
    }
    goto skip_5;
    // 0x80055870: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    skip_5:
    // 0x80055874: bnel        $t4, $ra, L_800557D8
    if (ctx->r12 != ctx->r31) {
        // 0x80055878: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800557D8;
    }
    goto skip_6;
    // 0x80055878: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_6:
    // 0x8005587C: b           L_80055A0C
    // 0x80055880: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
        goto L_80055A0C;
    // 0x80055880: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_80055884:
    // 0x80055884: addu        $s1, $s3, $t7
    ctx->r17 = ADD32(ctx->r19, ctx->r15);
    // 0x80055888: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005588C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80055890: jal         0x8004921C
    // 0x80055894: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_14;
    // 0x80055894: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80055898: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8005589C: blezl       $t8, L_800558F4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800558A0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800558F4;
    }
    goto skip_7;
    // 0x800558A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_7:
    // 0x800558A4: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
L_800558A8:
    // 0x800558A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800558AC: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800558B0: addu        $t7, $s0, $t9
    ctx->r15 = ADD32(ctx->r16, ctx->r25);
    // 0x800558B4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800558B8: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x800558BC: bnel        $t6, $zero, L_800558F4
    if (ctx->r14 != 0) {
        // 0x800558C0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800558F4;
    }
    goto skip_8;
    // 0x800558C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_8:
    // 0x800558C4: jal         0x8004921C
    // 0x800558C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_15;
    // 0x800558C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800558CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800558D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800558D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800558D8: jal         0x8004921C
    // 0x800558DC: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    func_8004921C(rdram, ctx);
        goto after_16;
    // 0x800558DC: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    after_16:
    // 0x800558E0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800558E4: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800558E8: bnel        $at, $zero, L_800558A8
    if (ctx->r1 != 0) {
        // 0x800558EC: lbu         $t6, 0x0($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X0);
            goto L_800558A8;
    }
    goto skip_9;
    // 0x800558EC: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    skip_9:
    // 0x800558F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800558F4:
    // 0x800558F4: jal         0x8004921C
    // 0x800558F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_17;
    // 0x800558F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x800558FC: bne         $v0, $s2, L_8005590C
    if (ctx->r2 != ctx->r18) {
        // 0x80055900: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_8005590C;
    }
    // 0x80055900: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80055904: b           L_80055A0C
    // 0x80055908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055A0C;
    // 0x80055908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005590C:
    // 0x8005590C: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80055910: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80055914: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80055918: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8005591C: sb          $t6, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r14;
    // 0x80055920: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80055924: addu        $t7, $s2, $t9
    ctx->r15 = ADD32(ctx->r18, ctx->r25);
    // 0x80055928: jal         0x8004921C
    // 0x8005592C: sb          $t7, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_18;
    // 0x8005592C: sb          $t7, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r15;
    after_18:
    // 0x80055930: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055934: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80055938: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8005593C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80055940: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055944: addiu       $t3, $t3, 0x60E0
    ctx->r11 = ADD32(ctx->r11, 0X60E0);
    // 0x80055948: addiu       $s1, $s1, 0x6104
    ctx->r17 = ADD32(ctx->r17, 0X6104);
    // 0x8005594C: addiu       $t2, $sp, 0x54
    ctx->r10 = ADD32(ctx->r29, 0X54);
    // 0x80055950: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80055954: mflo        $t8
    ctx->r24 = lo;
    // 0x80055958: addu        $t4, $t8, $t6
    ctx->r12 = ADD32(ctx->r24, ctx->r14);
    // 0x8005595C: or          $ra, $t4, $zero
    ctx->r31 = ctx->r12 | 0;
    // 0x80055960: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80055964:
    // 0x80055964: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80055968:
    // 0x80055968: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8005596C: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x80055970: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80055974: addu        $a0, $t3, $v0
    ctx->r4 = ADD32(ctx->r11, ctx->r2);
    // 0x80055978: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8005597C: addu        $t7, $t9, $s3
    ctx->r15 = ADD32(ctx->r25, ctx->r19);
    // 0x80055980: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80055984: addu        $t6, $t8, $a1
    ctx->r14 = ADD32(ctx->r24, ctx->r5);
    // 0x80055988: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8005598C: addu        $t0, $s6, $s5
    ctx->r8 = ADD32(ctx->r22, ctx->r21);
    // 0x80055990: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80055994: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80055998: lhu         $t6, 0x0($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X0);
    // 0x8005599C: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x800559A0: beql        $t9, $zero, L_800559EC
    if (ctx->r25 == 0) {
        // 0x800559A4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800559EC;
    }
    goto skip_10;
    // 0x800559A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_10:
    // 0x800559A8: lbu         $t7, -0x1($t0)
    ctx->r15 = MEM_BU(ctx->r8, -0X1);
    // 0x800559AC: addu        $t5, $s7, $s5
    ctx->r13 = ADD32(ctx->r23, ctx->r21);
    // 0x800559B0: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
    // 0x800559B4: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800559B8: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x800559BC: lbu         $t7, -0x1($t5)
    ctx->r15 = MEM_BU(ctx->r13, -0X1);
    // 0x800559C0: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x800559C4: addiu       $a2, $a2, 0x5
    ctx->r6 = ADD32(ctx->r6, 0X5);
    // 0x800559C8: andi        $a2, $a2, 0x7
    ctx->r6 = ctx->r6 & 0X7;
    // 0x800559CC: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800559D0: sb          $t8, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r24;
    // 0x800559D4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800559D8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800559DC: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x800559E0: b           L_800559F8
    // 0x800559E4: addu        $t4, $t9, $t7
    ctx->r12 = ADD32(ctx->r25, ctx->r15);
        goto L_800559F8;
    // 0x800559E4: addu        $t4, $t9, $t7
    ctx->r12 = ADD32(ctx->r25, ctx->r15);
    // 0x800559E8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800559EC:
    // 0x800559EC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800559F0: bne         $a3, $t1, L_80055968
    if (ctx->r7 != ctx->r9) {
        // 0x800559F4: andi        $a2, $a2, 0x7
        ctx->r6 = ctx->r6 & 0X7;
            goto L_80055968;
    }
    // 0x800559F4: andi        $a2, $a2, 0x7
    ctx->r6 = ctx->r6 & 0X7;
L_800559F8:
    // 0x800559F8: beql        $a3, $t1, L_80055A0C
    if (ctx->r7 == ctx->r9) {
        // 0x800559FC: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_80055A0C;
    }
    goto skip_11;
    // 0x800559FC: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    skip_11:
    // 0x80055A00: bnel        $t4, $ra, L_80055964
    if (ctx->r12 != ctx->r31) {
        // 0x80055A04: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80055964;
    }
    goto skip_12;
    // 0x80055A04: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_12:
    // 0x80055A08: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_80055A0C:
    // 0x80055A0C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80055A10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80055A14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80055A18: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80055A1C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80055A20: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80055A24: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80055A28: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80055A2C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80055A30: jr          $ra
    // 0x80055A34: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80055A34: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_806B2B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2B5C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2B60: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2B64: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2B68: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2B6C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2B70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2B74: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2B78: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2B7C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2B80: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2B84: jr          $ra
    // 0x806B2B88: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2B88: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80799B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799B70: jal         0x800498D4
    // 0x80799B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800498D4(rdram, ctx);
        goto after_0;
    // 0x80799B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80799B78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80799B7C: jal         0x80049D74
    // 0x80799B80: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    func_80049D74(rdram, ctx);
        goto after_1;
    // 0x80799B80: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    after_1:
    // 0x80799B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799B8C: jr          $ra
    // 0x80799B90: nop

    return;
    // 0x80799B90: nop

;}
RECOMP_FUNC void func_8073D2A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073D2A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073D2AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073D2B0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073D2B4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8073D2B8: bnel        $t6, $zero, L_8073D2E0
    if (ctx->r14 != 0) {
        // 0x8073D2BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8073D2E0;
    }
    goto skip_0;
    // 0x8073D2BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8073D2C0: jal         0x80045A34
    // 0x8073D2C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8073D2C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073D2C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8073D2CC: bne         $v0, $zero, L_8073D2DC
    if (ctx->r2 != 0) {
        // 0x8073D2D0: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8073D2DC;
    }
    // 0x8073D2D0: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8073D2D4: b           L_8073D2E0
    // 0x8073D2D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073D2E0;
    // 0x8073D2D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073D2DC:
    // 0x8073D2DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8073D2E0:
    // 0x8073D2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073D2E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073D2E8: jr          $ra
    // 0x8073D2EC: nop

    return;
    // 0x8073D2EC: nop

;}
RECOMP_FUNC void func_80428A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428A88: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80428A8C: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80428A90: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80428A94: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80428A98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80428A9C: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
    // 0x80428AA0: ori         $s0, $s0, 0xC2F
    ctx->r16 = ctx->r16 | 0XC2F;
    // 0x80428AA4: lw          $v1, 0x690($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X690);
    // 0x80428AA8: lui         $s1, 0xBF00
    ctx->r17 = S32(0XBF00 << 16);
    // 0x80428AAC: addiu       $s2, $zero, 0x204
    ctx->r18 = ADD32(0, 0X204);
    // 0x80428AB0: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80428AB4: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80428AB8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80428ABC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80428AC0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80428AC4: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80428AC8: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80428ACC: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80428AD0: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80428AD4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80428AD8: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    // 0x80428ADC: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x80428AE0: addu        $a0, $v0, $t7
    ctx->r4 = ADD32(ctx->r2, ctx->r15);
    // 0x80428AE4: addiu       $a0, $a0, 0x698
    ctx->r4 = ADD32(ctx->r4, 0X698);
    // 0x80428AE8: addiu       $a1, $a2, 0x8
    ctx->r5 = ADD32(ctx->r6, 0X8);
    // 0x80428AEC: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x80428AF0: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x80428AF4: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80428AF8: sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // 0x80428AFC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428B00: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80428B04: sw          $s2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r18;
    // 0x80428B08: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80428B0C: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80428B10: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80428B14: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428B18: addiu       $t2, $a0, 0x60
    ctx->r10 = ADD32(ctx->r4, 0X60);
    // 0x80428B1C: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80428B20: addiu       $t6, $t9, 0x30
    ctx->r14 = ADD32(ctx->r25, 0X30);
    // 0x80428B24: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80428B28: sw          $s2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r18;
    // 0x80428B2C: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80428B30: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428B34: addiu       $t3, $t2, 0x30
    ctx->r11 = ADD32(ctx->r10, 0X30);
    // 0x80428B38: addiu       $t4, $t2, 0x60
    ctx->r12 = ADD32(ctx->r10, 0X60);
    // 0x80428B3C: addiu       $t5, $t2, 0x90
    ctx->r13 = ADD32(ctx->r10, 0X90);
    // 0x80428B40: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80428B44: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_80428B48:
    // 0x80428B48: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80428B4C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428B50: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80428B54: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80428B58: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80428B5C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428B60: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80428B64: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80428B68: sw          $s2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r18;
    // 0x80428B6C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428B70: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80428B74: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80428B78: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80428B7C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428B80: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80428B84: sw          $s2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r18;
    // 0x80428B88: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80428B8C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428B90: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80428B94: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80428B98: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80428B9C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428BA0: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80428BA4: sw          $s2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r18;
    // 0x80428BA8: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80428BAC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428BB0: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80428BB4: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80428BB8: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80428BBC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80428BC0: sw          $s2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r18;
    // 0x80428BC4: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80428BC8: addiu       $t5, $t5, 0xC0
    ctx->r13 = ADD32(ctx->r13, 0XC0);
    // 0x80428BCC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80428BD0: addiu       $t4, $t4, 0xC0
    ctx->r12 = ADD32(ctx->r12, 0XC0);
    // 0x80428BD4: addiu       $t3, $t3, 0xC0
    ctx->r11 = ADD32(ctx->r11, 0XC0);
    // 0x80428BD8: bne         $a3, $a0, L_80428B48
    if (ctx->r7 != ctx->r4) {
        // 0x80428BDC: addiu       $t2, $t2, 0xC0
        ctx->r10 = ADD32(ctx->r10, 0XC0);
            goto L_80428B48;
    }
    // 0x80428BDC: addiu       $t2, $t2, 0xC0
    ctx->r10 = ADD32(ctx->r10, 0XC0);
    // 0x80428BE0: lui         $t7, 0xB800
    ctx->r15 = S32(0XB800 << 16);
    // 0x80428BE4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80428BE8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80428BEC: sw          $v1, 0x690($v0)
    MEM_W(0X690, ctx->r2) = ctx->r3;
    // 0x80428BF0: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80428BF4: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80428BF8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80428BFC: jr          $ra
    // 0x80428C00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80428C00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80027168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002716C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027170: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80027174: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80027178: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8002717C: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80027180: addiu       $t8, $t8, 0x7134
    ctx->r24 = ADD32(ctx->r24, 0X7134);
    // 0x80027184: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80027188: bne         $t7, $at, L_800271A0
    if (ctx->r15 != ctx->r1) {
        // 0x8002718C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800271A0;
    }
    // 0x8002718C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80027190: jal         0x800270C8
    // 0x80027194: nop

    func_800270C8(rdram, ctx);
        goto after_0;
    // 0x80027194: nop

    after_0:
    // 0x80027198: b           L_800271B8
    // 0x8002719C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800271B8;
    // 0x8002719C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800271A0:
    // 0x800271A0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x800271A4: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800271A8: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    // 0x800271AC: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
    // 0x800271B0: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800271B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800271B8:
    // 0x800271B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800271BC: jr          $ra
    // 0x800271C0: nop

    return;
    // 0x800271C0: nop

;}
RECOMP_FUNC void func_8078B1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B1E0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1AC8) << 16);
    // 0x8078B1E4: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8078B1E8: lwc1        $f4, -0x33A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1AC8));
    // 0x8078B1EC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8078B1F0: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8078B1F4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8078B1F8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1ADC) << 16);
    // 0x8078B1FC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8078B200: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8078B204: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(796, 0X1AC8) << 16);
    // 0x8078B208: addiu       $t9, $t9, -0x33A8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(796, 0X1AC8));
    // 0x8078B20C: lui         $t2, 0x8079
    ctx->r10 = S32(RELOC_HI16(796, 0X1ADC) << 16);
    // 0x8078B210: swc1        $f6, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f6.u32l;
    // 0x8078B214: lwc1        $f10, 0x58($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8078B218: lwc1        $f8, -0x3394($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1ADC));
    // 0x8078B21C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8078B220: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1AF0) << 16);
    // 0x8078B224: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8078B228: addiu       $t2, $t2, -0x3394
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(796, 0X1ADC));
    // 0x8078B22C: lui         $t4, 0x8079
    ctx->r12 = S32(RELOC_HI16(796, 0X1AF0) << 16);
    // 0x8078B230: addiu       $t4, $t4, -0x3380
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(796, 0X1AF0));
    // 0x8078B234: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8078B238: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8078B23C: swc1        $f18, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f18.u32l;
    // 0x8078B240: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8078B244: lwc1        $f4, -0x3380($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1AF0));
    // 0x8078B248: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x8078B24C: addu        $a2, $a1, $t9
    ctx->r6 = ADD32(ctx->r5, ctx->r25);
    // 0x8078B250: swc1        $f4, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f4.u32l;
    // 0x8078B254: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8078B258: lw          $t1, -0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, -0XC);
    // 0x8078B25C: addu        $a3, $a1, $t2
    ctx->r7 = ADD32(ctx->r5, ctx->r10);
    // 0x8078B260: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8078B264: addu        $t0, $a1, $t4
    ctx->r8 = ADD32(ctx->r5, ctx->r12);
    // 0x8078B268: swc1        $f8, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f8.u32l;
    // 0x8078B26C: lwc1        $f16, 0x58($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8078B270: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8078B274: lw          $t3, -0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, -0XC);
    // 0x8078B278: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8078B27C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8078B280: swc1        $f4, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f4.u32l;
    // 0x8078B284: lw          $t5, -0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, -0XC);
    // 0x8078B288: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8078B28C: swc1        $f6, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f6.u32l;
    // 0x8078B290: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8078B294: lw          $t6, -0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X8);
    // 0x8078B298: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8078B29C: swc1        $f10, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f10.u32l;
    // 0x8078B2A0: lwc1        $f18, 0x58($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8078B2A4: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8078B2A8: lw          $t7, -0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X8);
    // 0x8078B2AC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8078B2B0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8078B2B4: swc1        $f6, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f6.u32l;
    // 0x8078B2B8: lw          $t8, -0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X8);
    // 0x8078B2BC: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8078B2C0: swc1        $f8, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f8.u32l;
    // 0x8078B2C4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8078B2C8: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x8078B2CC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8078B2D0: swc1        $f16, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f16.u32l;
    // 0x8078B2D4: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8078B2D8: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8078B2DC: lw          $t1, -0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, -0X4);
    // 0x8078B2E0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8078B2E4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8078B2E8: swc1        $f8, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f8.u32l;
    // 0x8078B2EC: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x8078B2F0: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8078B2F4: swc1        $f10, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->f10.u32l;
    // 0x8078B2F8: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8078B2FC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8078B300: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8078B304: swc1        $f18, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f18.u32l;
    // 0x8078B308: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8078B30C: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8078B310: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8078B314: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8078B318: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8078B31C: swc1        $f10, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f10.u32l;
    // 0x8078B320: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8078B324: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8078B328: jr          $ra
    // 0x8078B32C: swc1        $f16, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f16.u32l;
    return;
    // 0x8078B32C: swc1        $f16, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_8002E274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E274: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002E278: sb          $zero, 0xF4($a0)
    MEM_B(0XF4, ctx->r4) = 0;
    // 0x8002E27C: sb          $zero, 0xF5($a0)
    MEM_B(0XF5, ctx->r4) = 0;
    // 0x8002E280: sb          $t6, 0xF7($a0)
    MEM_B(0XF7, ctx->r4) = ctx->r14;
    // 0x8002E284: lw          $t7, 0x174($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X174);
    // 0x8002E288: jr          $ra
    // 0x8002E28C: sb          $zero, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = 0;
    return;
    // 0x8002E28C: sb          $zero, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = 0;
;}
RECOMP_FUNC void func_80006FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006FE8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006FEC: jal         0x800073BC
    // 0x80006FF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x80006FF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006FF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80006FF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80006FFC: jal         0x800071C8
    // 0x80007000: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800071C8(rdram, ctx);
        goto after_1;
    // 0x80007000: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80007004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007008: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000700C: jr          $ra
    // 0x80007010: nop

    return;
    // 0x80007010: nop

;}
RECOMP_FUNC void func_8043ACF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043ACF0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043ACF4: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043ACF8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8043ACFC: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8043AD00: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8043AD04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043AD08: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8043AD0C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043AD10: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8043AD14: nop

    // 0x8043AD18: bc1fl       L_8043AD30
    if (!c1cs) {
        // 0x8043AD1C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8043AD30;
    }
    goto skip_0;
    // 0x8043AD1C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x8043AD20: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8043AD24: jr          $ra
    // 0x8043AD28: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8043AD28: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x8043AD2C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8043AD30:
    // 0x8043AD30: nop

    // 0x8043AD34: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8043AD38: nop

    // 0x8043AD3C: bc1f        L_8043AD4C
    if (!c1cs) {
        // 0x8043AD40: nop
    
            goto L_8043AD4C;
    }
    // 0x8043AD40: nop

    // 0x8043AD44: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8043AD48: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
L_8043AD4C:
    // 0x8043AD4C: jr          $ra
    // 0x8043AD50: nop

    return;
    // 0x8043AD50: nop

;}
RECOMP_FUNC void func_804D2C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D2C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D2C20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D2C24: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804D2C28: jalr        $t9
    // 0x804D2C2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804D2C2C: nop

    after_0:
    // 0x804D2C30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D2C34: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x804D2C38: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x804D2C3C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x804D2C40: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x804D2C44: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x804D2C48: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x804D2C4C: jal         0x8004894C
    // 0x804D2C50: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    func_8004894C(rdram, ctx);
        goto after_1;
    // 0x804D2C50: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    after_1:
    // 0x804D2C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D2C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D2C5C: jr          $ra
    // 0x804D2C60: nop

    return;
    // 0x804D2C60: nop

;}
RECOMP_FUNC void func_800494C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800494C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800494C8: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800494CC: beq         $a0, $at, L_800494E8
    if (ctx->r4 == ctx->r1) {
        // 0x800494D0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800494E8;
    }
    // 0x800494D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800494D4: jal         0x8004937C
    // 0x800494D8: nop

    func_8004937C(rdram, ctx);
        goto after_0;
    // 0x800494D8: nop

    after_0:
    // 0x800494DC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800494E0: b           L_80049514
    // 0x800494E4: sb          $zero, 0x5A8($at)
    MEM_B(0X5A8, ctx->r1) = 0;
        goto L_80049514;
    // 0x800494E4: sb          $zero, 0x5A8($at)
    MEM_B(0X5A8, ctx->r1) = 0;
L_800494E8:
    // 0x800494E8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800494EC: lbu         $t6, 0x5A8($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5A8);
    // 0x800494F0: bne         $t6, $zero, L_8004950C
    if (ctx->r14 != 0) {
        // 0x800494F4: nop
    
            goto L_8004950C;
    }
    // 0x800494F4: nop

    // 0x800494F8: jal         0x800492C0
    // 0x800494FC: addiu       $a0, $zero, -0x9A
    ctx->r4 = ADD32(0, -0X9A);
    func_800492C0(rdram, ctx);
        goto after_1;
    // 0x800494FC: addiu       $a0, $zero, -0x9A
    ctx->r4 = ADD32(0, -0X9A);
    after_1:
    // 0x80049500: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80049504: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80049508: sb          $t7, 0x5A8($at)
    MEM_B(0X5A8, ctx->r1) = ctx->r15;
L_8004950C:
    // 0x8004950C: jal         0x8004941C
    // 0x80049510: nop

    func_8004941C(rdram, ctx);
        goto after_2;
    // 0x80049510: nop

    after_2:
L_80049514:
    // 0x80049514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004951C: jr          $ra
    // 0x80049520: nop

    return;
    // 0x80049520: nop

;}
RECOMP_FUNC void func_80438690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438690: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80438694: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80438698: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8043869C: addiu       $at, $zero, 0x407B
    ctx->r1 = ADD32(0, 0X407B);
    // 0x804386A0: bne         $t6, $at, L_804386D4
    if (ctx->r14 != ctx->r1) {
        // 0x804386A4: nop
    
            goto L_804386D4;
    }
    // 0x804386A4: nop

    // 0x804386A8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804386AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804386B0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804386B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804386B8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x804386BC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x804386C0: bc1fl       L_804386D4
    if (!c1cs) {
        // 0x804386C4: sw          $t8, 0x54($v0)
        MEM_W(0X54, ctx->r2) = ctx->r24;
            goto L_804386D4;
    }
    goto skip_0;
    // 0x804386C4: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
    skip_0:
    // 0x804386C8: jr          $ra
    // 0x804386CC: sw          $t7, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r15;
    return;
    // 0x804386CC: sw          $t7, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r15;
    // 0x804386D0: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
L_804386D4:
    // 0x804386D4: jr          $ra
    // 0x804386D8: nop

    return;
    // 0x804386D8: nop

;}
RECOMP_FUNC void func_8064B69C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B69C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B6A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B6A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064B6A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064B6AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064B6B0: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8064B6B4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8064B6B8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064B6BC: bne         $v0, $at, L_8064B6E4
    if (ctx->r2 != ctx->r1) {
        // 0x8064B6C0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8064B6E4;
    }
    // 0x8064B6C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064B6C4: jal         0x8064A1C8
    // 0x8064B6C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8064A1C8(rdram, ctx);
        goto after_0;
    // 0x8064B6C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8064B6CC: beq         $v0, $zero, L_8064B6E4
    if (ctx->r2 == 0) {
        // 0x8064B6D0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8064B6E4;
    }
    // 0x8064B6D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8064B6D4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8064B6D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8064B6DC: jal         0x8002F6E4
    // 0x8064B6E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8064B6E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8064B6E4:
    // 0x8064B6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B6EC: jr          $ra
    // 0x8064B6F0: nop

    return;
    // 0x8064B6F0: nop

;}
RECOMP_FUNC void func_80043E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043E14: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80043E18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043E1C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80043E20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80043E24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80043E28: beq         $t7, $zero, L_80043E48
    if (ctx->r15 == 0) {
        // 0x80043E2C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80043E48;
    }
    // 0x80043E2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80043E30: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043E34: addiu       $a0, $a0, 0x3C0
    ctx->r4 = ADD32(ctx->r4, 0X3C0);
    // 0x80043E38: jal         0x80071380
    // 0x80043E3C: addiu       $a1, $zero, 0x2D9
    ctx->r5 = ADD32(0, 0X2D9);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80043E3C: addiu       $a1, $zero, 0x2D9
    ctx->r5 = ADD32(0, 0X2D9);
    after_0:
    // 0x80043E40: b           L_80043E78
    // 0x80043E44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80043E78;
    // 0x80043E44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043E48:
    // 0x80043E48: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80043E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043E50: jalr        $t9
    // 0x80043E54: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80043E54: nop

    after_1:
    // 0x80043E58: lh          $a1, 0x184($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X184);
    // 0x80043E5C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80043E60: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x80043E64: beq         $a1, $zero, L_80043E74
    if (ctx->r5 == 0) {
        // 0x80043E68: addiu       $a0, $s0, 0x188
        ctx->r4 = ADD32(ctx->r16, 0X188);
            goto L_80043E74;
    }
    // 0x80043E68: addiu       $a0, $s0, 0x188
    ctx->r4 = ADD32(ctx->r16, 0X188);
    // 0x80043E6C: jal         0x80057F74
    // 0x80043E70: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80057F74(rdram, ctx);
        goto after_2;
    // 0x80043E70: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_2:
L_80043E74:
    // 0x80043E74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043E78:
    // 0x80043E78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043E80: jr          $ra
    // 0x80043E84: nop

    return;
    // 0x80043E84: nop

;}
RECOMP_FUNC void func_8004EEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EEEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004EEF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004EEF4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8004EEF8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004EEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004EF00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004EF04: sh          $a0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r4;
    // 0x8004EF08: jal         0x8004EE68
    // 0x8004EF0C: sh          $a1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r5;
    func_8004EE68(rdram, ctx);
        goto after_0;
    // 0x8004EF0C: sh          $a1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004EF10: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x8004EF14: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x8004EF18: bne         $v0, $zero, L_8004EF38
    if (ctx->r2 != 0) {
        // 0x8004EF1C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8004EF38;
    }
    // 0x8004EF1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004EF20: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004EF24: addiu       $a0, $a0, 0x924
    ctx->r4 = ADD32(ctx->r4, 0X924);
    // 0x8004EF28: jal         0x80071380
    // 0x8004EF2C: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8004EF2C: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    after_1:
    // 0x8004EF30: b           L_8004EFCC
    // 0x8004EF34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004EFCC;
    // 0x8004EF34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EF38:
    // 0x8004EF38: addiu       $t7, $a2, 0x10
    ctx->r15 = ADD32(ctx->r6, 0X10);
    // 0x8004EF3C: addiu       $t8, $a1, 0x12
    ctx->r24 = ADD32(ctx->r5, 0X12);
    // 0x8004EF40: sh          $t7, 0x56($v1)
    MEM_H(0X56, ctx->r3) = ctx->r15;
    // 0x8004EF44: sh          $t8, 0x58($v1)
    MEM_H(0X58, ctx->r3) = ctx->r24;
    // 0x8004EF48: lh          $t9, 0x58($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X58);
    // 0x8004EF4C: lh          $t0, 0x56($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X56);
    // 0x8004EF50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004EF54: sb          $t6, 0x4D($v1)
    MEM_B(0X4D, ctx->r3) = ctx->r14;
    // 0x8004EF58: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004EF5C: sh          $a2, 0x4E($v1)
    MEM_H(0X4E, ctx->r3) = ctx->r6;
    // 0x8004EF60: sh          $a1, 0x50($v1)
    MEM_H(0X50, ctx->r3) = ctx->r5;
    // 0x8004EF64: sh          $a2, 0x52($v1)
    MEM_H(0X52, ctx->r3) = ctx->r6;
    // 0x8004EF68: sh          $a1, 0x54($v1)
    MEM_H(0X54, ctx->r3) = ctx->r5;
    // 0x8004EF6C: mflo        $v0
    ctx->r2 = lo;
    // 0x8004EF70: sw          $v0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r2;
    // 0x8004EF74: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8004EF78: jal         0x8004EDD8
    // 0x8004EF7C: addiu       $a0, $v0, 0x40
    ctx->r4 = ADD32(ctx->r2, 0X40);
    func_8004EDD8(rdram, ctx);
        goto after_2;
    // 0x8004EF7C: addiu       $a0, $v0, 0x40
    ctx->r4 = ADD32(ctx->r2, 0X40);
    after_2:
    // 0x8004EF80: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004EF84: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004EF88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004EF8C: bne         $v1, $zero, L_8004EFA8
    if (ctx->r3 != 0) {
        // 0x8004EF90: sw          $v0, 0x64($v1)
        MEM_W(0X64, ctx->r3) = ctx->r2;
            goto L_8004EFA8;
    }
    // 0x8004EF90: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
    // 0x8004EF94: addiu       $a0, $a0, 0x930
    ctx->r4 = ADD32(ctx->r4, 0X930);
    // 0x8004EF98: jal         0x80071380
    // 0x8004EF9C: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x8004EF9C: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_3:
    // 0x8004EFA0: b           L_8004EFCC
    // 0x8004EFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004EFCC;
    // 0x8004EFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EFA8:
    // 0x8004EFA8: lw          $t1, 0x64($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X64);
    // 0x8004EFAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004EFB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004EFB4: addiu       $t2, $t1, 0x3F
    ctx->r10 = ADD32(ctx->r9, 0X3F);
    // 0x8004EFB8: srl         $t3, $t2, 6
    ctx->r11 = S32(U32(ctx->r10) >> 6);
    // 0x8004EFBC: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8004EFC0: sw          $t4, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r12;
    // 0x8004EFC4: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8004EFC8: swc1        $f0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f0.u32l;
L_8004EFCC:
    // 0x8004EFCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004EFD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004EFD4: jr          $ra
    // 0x8004EFD8: nop

    return;
    // 0x8004EFD8: nop

;}
RECOMP_FUNC void func_80421478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421478: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8042147C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80421480: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80421484: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80421488: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8042148C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80421490: lwc1        $f4, 0x18($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80421494: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x80421498: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042149C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804214A0: beq         $a1, $zero, L_80421564
    if (ctx->r5 == 0) {
        // 0x804214A4: swc1        $f8, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
            goto L_80421564;
    }
    // 0x804214A4: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x804214A8: jal         0x80047AB8
    // 0x804214AC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x804214AC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x804214B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804214B4: jal         0x80421424
    // 0x804214B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80421424(rdram, ctx);
        goto after_1;
    // 0x804214B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x804214BC: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x804214C0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804214C4: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x804214C8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804214CC: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x804214D0: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804214D4: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x804214D8: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x804214DC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x804214E0: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804214E4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x804214E8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804214EC: nop

    // 0x804214F0: bc1fl       L_80421550
    if (!c1cs) {
        // 0x804214F4: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80421550;
    }
    goto skip_0;
    // 0x804214F4: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x804214F8: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x804214FC: jal         0x80081E8C
    // 0x80421500: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    fatan2(rdram, ctx);
        goto after_2;
    // 0x80421500: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80421504: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X1764) << 16);
    // 0x80421508: lwc1        $f16, 0x2824($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X1764));
    // 0x8042150C: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80421510: jal         0x80066E88
    // 0x80421514: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x80421514: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80421518: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8042151C: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80421520: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80421524: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80421528: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8042152C: jal         0x80066DE4
    // 0x80421530: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x80421530: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80421534: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80421538: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8042153C: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80421540: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80421544: b           L_80421564
    // 0x80421548: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
        goto L_80421564;
    // 0x80421548: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8042154C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_80421550:
    // 0x80421550: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x80421554: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x80421558: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x8042155C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80421560: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
L_80421564:
    // 0x80421564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80421568: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042156C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80421570: jr          $ra
    // 0x80421574: nop

    return;
    // 0x80421574: nop

;}
RECOMP_FUNC void func_805A0658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A0658: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805A065C: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(408, 0X1CCC) << 16);
    // 0x805A0660: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A0664: addiu       $t6, $t6, 0x102C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(408, 0X1CCC));
    // 0x805A0668: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805A066C: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(408, 0XBB0) << 16);
    // 0x805A0670: addiu       $t8, $t8, -0xF0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(408, 0XBB0));
    // 0x805A0674: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A0678: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x805A067C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805A0680: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805A0684: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A0688: jr          $ra
    // 0x805A068C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    return;
    // 0x805A068C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void func_8043A6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A6B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043A6B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043A6BC: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8043A6C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8043A6C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043A6C8: beq         $a1, $at, L_8043A6E4
    if (ctx->r5 == ctx->r1) {
        // 0x8043A6CC: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8043A6E4;
    }
    // 0x8043A6CC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8043A6D0: jal         0x80067878
    // 0x8043A6D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8043A6D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8043A6D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043A6DC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8043A6E0: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8043A6E4:
    // 0x8043A6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043A6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043A6EC: jr          $ra
    // 0x8043A6F0: nop

    return;
    // 0x8043A6F0: nop

;}
RECOMP_FUNC void func_807ADCC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADCC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807ADCCC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807ADCD0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807ADCD4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807ADCD8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807ADCDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807ADCE0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x807ADCE4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807ADCE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807ADCEC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807ADCF0: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x807ADCF4: addiu       $s4, $zero, 0x30
    ctx->r20 = ADD32(0, 0X30);
L_807ADCF8:
    // 0x807ADCF8: lwc1        $f4, 0xAC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XAC);
    // 0x807ADCFC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x807ADD00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807ADD04: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x807ADD08: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x807ADD0C: lwc1        $f10, 0xB0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XB0);
    // 0x807ADD10: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807ADD14: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807ADD18: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x807ADD1C: jal         0x80053924
    // 0x807ADD20: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x807ADD20: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x807ADD24: bne         $s3, $v0, L_807ADD34
    if (ctx->r19 != ctx->r2) {
        // 0x807ADD28: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_807ADD34;
    }
    // 0x807ADD28: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x807ADD2C: b           L_807ADD40
    // 0x807ADD30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807ADD40;
    // 0x807ADD30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807ADD34:
    // 0x807ADD34: bne         $s1, $s4, L_807ADCF8
    if (ctx->r17 != ctx->r20) {
        // 0x807ADD38: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_807ADCF8;
    }
    // 0x807ADD38: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x807ADD3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807ADD40:
    // 0x807ADD40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807ADD44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807ADD48: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807ADD4C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807ADD50: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x807ADD54: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x807ADD58: jr          $ra
    // 0x807ADD5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x807ADD5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807BA86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA86C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BA870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BA874: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x807BA878: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x807BA87C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x807BA880: lui         $t8, 0x807C
    ctx->r24 = S32(RELOC_HI16(895, 0X10F8) << 16);
    // 0x807BA884: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807BA888: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x807BA88C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807BA890: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807BA894: lw          $t8, -0x46F8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(895, 0X10F8));
    // 0x807BA898: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x807BA89C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807BA8A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807BA8A4: jal         0x80048490
    // 0x807BA8A8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x807BA8A8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x807BA8AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BA8B0: addiu       $at, $zero, 0x4057
    ctx->r1 = ADD32(0, 0X4057);
    // 0x807BA8B4: lhu         $t0, 0xC($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XC);
    // 0x807BA8B8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x807BA8BC: bne         $t0, $at, L_807BA8E4
    if (ctx->r8 != ctx->r1) {
        // 0x807BA8C0: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_807BA8E4;
    }
    // 0x807BA8C0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x807BA8C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807BA8C8: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807BA8CC: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x807BA8D0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x807BA8D4: nop

    // 0x807BA8D8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807BA8DC: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x807BA8E0: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
L_807BA8E4:
    // 0x807BA8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BA8E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BA8EC: jr          $ra
    // 0x807BA8F0: nop

    return;
    // 0x807BA8F0: nop

;}
RECOMP_FUNC void func_806B258C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B258C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2590: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2594: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2598: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B259C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B25A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B25A4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B25A8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B25AC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B25B0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B25B4: jr          $ra
    // 0x806B25B8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B25B8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073E98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073E98C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073E990: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073E994: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073E998: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073E99C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8073E9A0: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8073E9A4: jal         0x80065ABC
    // 0x8073E9A8: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x8073E9A8: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    after_0:
    // 0x8073E9AC: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8073E9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073E9B4: jal         0x80049D74
    // 0x8073E9B8: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_1;
    // 0x8073E9B8: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_1:
    // 0x8073E9BC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8073E9C0: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8073E9C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073E9C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073E9CC: jal         0x8004D150
    // 0x8073E9D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_2;
    // 0x8073E9D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8073E9D4: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x8073E9D8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8073E9DC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8073E9E0: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x8073E9E4: beql        $t9, $zero, L_8073E9F8
    if (ctx->r25 == 0) {
        // 0x8073E9E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073E9F8;
    }
    goto skip_0;
    // 0x8073E9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8073E9EC: jal         0x8073E8FC
    // 0x8073E9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073E8FC(rdram, ctx);
        goto after_3;
    // 0x8073E9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8073E9F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073E9F8:
    // 0x8073E9F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073E9FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073EA00: jr          $ra
    // 0x8073EA04: nop

    return;
    // 0x8073EA04: nop

;}
RECOMP_FUNC void func_8043037C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043037C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430384: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80430388: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8043038C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80430390: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80430394: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80430398: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8043039C: bc1tl       L_804303B8
    if (c1cs) {
        // 0x804303A0: lwc1        $f18, 0x50($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0X50);
            goto L_804303B8;
    }
    goto skip_0;
    // 0x804303A0: lwc1        $f18, 0x50($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X50);
    skip_0:
    // 0x804303A4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804303A8: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x804303AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804303B0: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x804303B4: lwc1        $f18, 0x50($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X50);
L_804303B8:
    // 0x804303B8: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x804303BC: addiu       $a2, $zero, 0x154
    ctx->r6 = ADD32(0, 0X154);
    // 0x804303C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804303C4: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x804303C8: jal         0x800475EC
    // 0x804303CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800475EC(rdram, ctx);
        goto after_0;
    // 0x804303CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804303D0: beq         $v0, $zero, L_804303E0
    if (ctx->r2 == 0) {
        // 0x804303D4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804303E0;
    }
    // 0x804303D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804303D8: jal         0x800447C8
    // 0x804303DC: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804303DC: nop

    after_1:
L_804303E0:
    // 0x804303E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804303E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804303E8: jr          $ra
    // 0x804303EC: nop

    return;
    // 0x804303EC: nop

;}
RECOMP_FUNC void func_80065DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065DE4: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80065DE8: beq         $at, $zero, L_80065DF4
    if (ctx->r1 == 0) {
        // 0x80065DEC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80065DF4;
    }
    // 0x80065DEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065DF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80065DF4:
    // 0x80065DF4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80065DF8: beql        $at, $zero, L_80065E0C
    if (ctx->r1 == 0) {
        // 0x80065DFC: slt         $at, $a3, $a1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80065E0C;
    }
    goto skip_0;
    // 0x80065DFC: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    skip_0:
    // 0x80065E00: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x80065E04: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80065E08: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
L_80065E0C:
    // 0x80065E0C: beql        $at, $zero, L_80065E20
    if (ctx->r1 == 0) {
        // 0x80065E10: slt         $at, $a1, $a3
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80065E20;
    }
    goto skip_1;
    // 0x80065E10: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    skip_1:
    // 0x80065E14: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x80065E18: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80065E1C: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
L_80065E20:
    // 0x80065E20: beq         $at, $zero, L_80065E30
    if (ctx->r1 == 0) {
        // 0x80065E24: nop
    
            goto L_80065E30;
    }
    // 0x80065E24: nop

    // 0x80065E28: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x80065E2C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_80065E30:
    // 0x80065E30: bne         $a2, $a0, L_80065E44
    if (ctx->r6 != ctx->r4) {
        // 0x80065E34: nop
    
            goto L_80065E44;
    }
    // 0x80065E34: nop

    // 0x80065E38: bne         $a3, $a1, L_80065E44
    if (ctx->r7 != ctx->r5) {
        // 0x80065E3C: nop
    
            goto L_80065E44;
    }
    // 0x80065E3C: nop

    // 0x80065E40: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_80065E44:
    // 0x80065E44: jr          $ra
    // 0x80065E48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80065E48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8044E684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044E684: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8044E688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044E68C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044E690: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044E694: lui         $t9, 0x8045
    ctx->r25 = S32(RELOC_HI16(98, 0X139F0) << 16);
    // 0x8044E698: addu        $v0, $a1, $at
    ctx->r2 = ADD32(ctx->r5, ctx->r1);
    // 0x8044E69C: lw          $t0, 0x6A28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X6A28);
    // 0x8044E6A0: lw          $a2, 0x6A20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X6A20);
    // 0x8044E6A4: lw          $v1, 0x6A24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6A24);
    // 0x8044E6A8: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x8044E6AC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8044E6B0: bne         $t0, $at, L_8044E844
    if (ctx->r8 != ctx->r1) {
        // 0x8044E6B4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8044E844;
    }
    // 0x8044E6B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8044E6B8: lw          $t6, 0x6A2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6A2C);
    // 0x8044E6BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8044E6C0: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x8044E6C4: bne         $t6, $at, L_8044E6D4
    if (ctx->r14 != ctx->r1) {
        // 0x8044E6C8: lui         $t4, 0x8045
        ctx->r12 = S32(RELOC_HI16(98, 0X13760) << 16);
            goto L_8044E6D4;
    }
    // 0x8044E6C8: lui         $t4, 0x8045
    ctx->r12 = S32(RELOC_HI16(98, 0X13760) << 16);
    // 0x8044E6CC: b           L_8044E6D8
    // 0x8044E6D0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_8044E6D8;
    // 0x8044E6D0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_8044E6D4:
    // 0x8044E6D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8044E6D8:
    // 0x8044E6D8: bgtz        $v1, L_8044E6F0
    if (SIGNED(ctx->r3) > 0) {
        // 0x8044E6DC: addu        $t4, $t4, $t3
        ctx->r12 = ADD32(ctx->r12, ctx->r11);
            goto L_8044E6F0;
    }
    // 0x8044E6DC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8044E6E0: lw          $t7, 0x6A3C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X6A3C);
    // 0x8044E6E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8044E6E8: b           L_8044E720
    // 0x8044E6EC: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
        goto L_8044E720;
    // 0x8044E6EC: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
L_8044E6F0:
    // 0x8044E6F0: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x8044E6F4: beq         $at, $zero, L_8044E710
    if (ctx->r1 == 0) {
        // 0x8044E6F8: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8044E710;
    }
    // 0x8044E6F8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8044E6FC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8044E700: lw          $t1, -0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, -0X4);
    // 0x8044E704: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8044E708: b           L_8044E720
    // 0x8044E70C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
        goto L_8044E720;
    // 0x8044E70C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
L_8044E710:
    // 0x8044E710: lw          $t2, 0x6A38($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X6A38);
    // 0x8044E714: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8044E718: nop

    // 0x8044E71C: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
L_8044E720:
    // 0x8044E720: lh          $t4, 0x7B40($t4)
    ctx->r12 = MEM_H(ctx->r12, (int16_t)RELOC_LO16(98, 0X13760));
    // 0x8044E724: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8044E728: nop

    // 0x8044E72C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8044E730: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8044E734: nop

    // 0x8044E738: bc1tl       L_8044E870
    if (c1cs) {
        // 0x8044E73C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044E870;
    }
    goto skip_0;
    // 0x8044E73C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044E740: bnel        $a0, $a2, L_8044E758
    if (ctx->r4 != ctx->r6) {
        // 0x8044E744: div.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
            goto L_8044E758;
    }
    goto skip_1;
    // 0x8044E744: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    skip_1:
    // 0x8044E748: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8044E74C: b           L_8044E758
    // 0x8044E750: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
        goto L_8044E758;
    // 0x8044E750: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8044E754: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
L_8044E758:
    // 0x8044E758: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x8044E75C: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8044E760: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8044E764: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X139F0) << 16);
    // 0x8044E768: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044E76C: ori         $at, $at, 0x6CF0
    ctx->r1 = ctx->r1 | 0X6CF0;
    // 0x8044E770: addiu       $t6, $t6, 0x7DD0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X139F0));
    // 0x8044E774: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8044E778: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8044E77C: addu        $t0, $a1, $at
    ctx->r8 = ADD32(ctx->r5, ctx->r1);
    // 0x8044E780: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8044E784: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8044E788: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8044E78C: sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7 << 2);
    // 0x8044E790: addu        $v1, $a2, $a1
    ctx->r3 = ADD32(ctx->r6, ctx->r5);
    // 0x8044E794: addu        $a0, $t0, $a1
    ctx->r4 = ADD32(ctx->r8, ctx->r5);
    // 0x8044E798: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x8044E79C: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x8044E7A0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8044E7A4: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8044E7A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8044E7AC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8044E7B0: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8044E7B4: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8044E7B8: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8044E7BC: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8044E7C0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8044E7C4: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8044E7C8: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8044E7CC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8044E7D0: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8044E7D4: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8044E7D8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8044E7DC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8044E7E0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8044E7E4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8044E7E8: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8044E7EC: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8044E7F0: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8044E7F4: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8044E7F8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8044E7FC: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8044E800: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8044E804: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8044E808: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8044E80C: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8044E810: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8044E814: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8044E818: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8044E81C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8044E820: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8044E824: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8044E828: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8044E82C: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8044E830: lw          $a3, 0x1C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1C);
    // 0x8044E834: jal         0x8006C56C
    // 0x8044E838: lw          $a2, 0x18($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X18);
    func_8006C56C(rdram, ctx);
        goto after_0;
    // 0x8044E838: lw          $a2, 0x18($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X18);
    after_0:
    // 0x8044E83C: b           L_8044E870
    // 0x8044E840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044E870;
    // 0x8044E840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044E844:
    // 0x8044E844: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8044E848: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x8044E84C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8044E850: addiu       $t9, $t9, 0x7DD0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(98, 0X139F0));
    // 0x8044E854: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8044E858: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x8044E85C: addiu       $a1, $v0, 0x24
    ctx->r5 = ADD32(ctx->r2, 0X24);
    // 0x8044E860: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8044E864: jal         0x8006C56C
    // 0x8044E868: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_8006C56C(rdram, ctx);
        goto after_1;
    // 0x8044E868: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_1:
    // 0x8044E86C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044E870:
    // 0x8044E870: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8044E874: jr          $ra
    // 0x8044E878: nop

    return;
    // 0x8044E878: nop

;}
RECOMP_FUNC void func_80445C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445CA4: jal         0x80445C74
    // 0x80445CA8: nop

    func_80445C74(rdram, ctx);
        goto after_0;
    // 0x80445CA8: nop

    after_0:
    // 0x80445CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445CB4: jr          $ra
    // 0x80445CB8: nop

    return;
    // 0x80445CB8: nop

;}
RECOMP_FUNC void func_80475DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475DC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475DCC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475DD0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475DD4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475DD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475DDC: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26DF8) << 16);
    // 0x80475DE0: addiu       $a2, $a2, -0x4A48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26DF8));
    // 0x80475DE4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80475DE8: jal         0x80475B40
    // 0x80475DEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475DEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475DF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475DF8: jr          $ra
    // 0x80475DFC: nop

    return;
    // 0x80475DFC: nop

;}
RECOMP_FUNC void func_80469F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469F9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80469FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80469FA4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80469FA8: jal         0x80469C44
    // 0x80469FAC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80469C44(rdram, ctx);
        goto after_0;
    // 0x80469FAC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80469FB0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80469FB4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80469FB8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80469FBC: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80469FC0: lwc1        $f4, 0x4C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x80469FC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80469FC8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80469FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80469FD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80469FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80469FD8: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80469FDC: nop

    // 0x80469FE0: bc1f        L_80469FEC
    if (!c1cs) {
        // 0x80469FE4: nop
    
            goto L_80469FEC;
    }
    // 0x80469FE4: nop

    // 0x80469FE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80469FEC:
    // 0x80469FEC: jr          $ra
    // 0x80469FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80469FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80566EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566EC8: jal         0x80566E48
    // 0x80566ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80566E48(rdram, ctx);
        goto after_0;
    // 0x80566ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566ED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566ED4: jal         0x805670F4
    // 0x80566ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805670F4(rdram, ctx);
        goto after_1;
    // 0x80566ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80566EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80566EE4: jr          $ra
    // 0x80566EE8: nop

    return;
    // 0x80566EE8: nop

;}
RECOMP_FUNC void func_804414C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804414C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804414CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804414D0: jal         0x8004700C
    // 0x804414D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804414D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804414D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804414DC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x804414E0: beq         $v0, $zero, L_80441534
    if (ctx->r2 == 0) {
        // 0x804414E4: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_80441534;
    }
    // 0x804414E4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804414E8: lwc1        $f4, 0x1C78($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C78);
    // 0x804414EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804414F0: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804414F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804414F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804414FC: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80441500: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80441504: nop

    // 0x80441508: bc1fl       L_80441524
    if (!c1cs) {
        // 0x8044150C: lw          $t6, 0x138($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X138);
            goto L_80441524;
    }
    goto skip_0;
    // 0x8044150C: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    skip_0:
    // 0x80441510: jal         0x8043F46C
    // 0x80441514: nop

    func_8043F46C(rdram, ctx);
        goto after_1;
    // 0x80441514: nop

    after_1:
    // 0x80441518: b           L_80441538
    // 0x8044151C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80441538;
    // 0x8044151C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80441520: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
L_80441524:
    // 0x80441524: bnel        $t6, $zero, L_80441538
    if (ctx->r14 != 0) {
        // 0x80441528: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80441538;
    }
    goto skip_1;
    // 0x80441528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8044152C: jal         0x8043F6F4
    // 0x80441530: nop

    func_8043F6F4(rdram, ctx);
        goto after_2;
    // 0x80441530: nop

    after_2:
L_80441534:
    // 0x80441534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80441538:
    // 0x80441538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044153C: jr          $ra
    // 0x80441540: nop

    return;
    // 0x80441540: nop

;}
RECOMP_FUNC void func_805682CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805682CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805682D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805682D4: jal         0x80567DD4
    // 0x805682D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80567DD4(rdram, ctx);
        goto after_0;
    // 0x805682D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x805682DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805682E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805682E4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805682E8: jal         0x80048F84
    // 0x805682EC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x805682EC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x805682F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805682F4: jal         0x80048F84
    // 0x805682F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805682F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805682FC: jal         0x805677F4
    // 0x80568300: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805677F4(rdram, ctx);
        goto after_3;
    // 0x80568300: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80568304: jal         0x80567E60
    // 0x80568308: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80567E60(rdram, ctx);
        goto after_4;
    // 0x80568308: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8056830C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80568314: jr          $ra
    // 0x80568318: nop

    return;
    // 0x80568318: nop

;}
RECOMP_FUNC void func_80421A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421A34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80421A38: beq         $v0, $zero, L_80421A44
    if (ctx->r2 == 0) {
        // 0x80421A3C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80421A44;
    }
    // 0x80421A3C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80421A40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_80421A44:
    // 0x80421A44: jr          $ra
    // 0x80421A48: nop

    return;
    // 0x80421A48: nop

;}
RECOMP_FUNC void func_8042F060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F068: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042F06C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8042F070: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042F074: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X35D4) << 16);
    // 0x8042F078: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042F07C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8042F080: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042F084: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042F088: lw          $t8, 0x16B4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X35D4));
    // 0x8042F08C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042F090: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042F094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042F098: jal         0x80048490
    // 0x8042F09C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8042F09C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8042F0A0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042F0A4: jal         0x80048378
    // 0x8042F0A8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8042F0A8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8042F0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F0B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F0B4: jr          $ra
    // 0x8042F0B8: nop

    return;
    // 0x8042F0B8: nop

;}
RECOMP_FUNC void func_80447E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447E94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447E98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447EA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447EA4: bne         $a2, $zero, L_80447EE4
    if (ctx->r6 != 0) {
        // 0x80447EA8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80447EE4;
    }
    // 0x80447EA8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80447EAC: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80447EB0: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x80447EB4: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80447EB8: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80447EBC: bne         $at, $zero, L_80447F24
    if (ctx->r1 != 0) {
        // 0x80447EC0: sw          $t7, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r15;
            goto L_80447F24;
    }
    // 0x80447EC0: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80447EC4: jal         0x80446384
    // 0x80447EC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446384(rdram, ctx);
        goto after_0;
    // 0x80447EC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80447ECC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447ED0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447ED4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80447ED8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447EDC: b           L_80447F24
    // 0x80447EE0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80447F24;
    // 0x80447EE0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80447EE4:
    // 0x80447EE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447EE8: bnel        $a2, $at, L_80447F14
    if (ctx->r6 != ctx->r1) {
        // 0x80447EEC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80447F14;
    }
    goto skip_0;
    // 0x80447EEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80447EF0: jal         0x80446384
    // 0x80447EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446384(rdram, ctx);
        goto after_1;
    // 0x80447EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80447EF8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447EFC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447F00: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80447F04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447F08: b           L_80447F24
    // 0x80447F0C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80447F24;
    // 0x80447F0C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80447F10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80447F14:
    // 0x80447F14: bnel        $a2, $at, L_80447F28
    if (ctx->r6 != ctx->r1) {
        // 0x80447F18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447F28;
    }
    goto skip_1;
    // 0x80447F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447F1C: jal         0x804463E8
    // 0x80447F20: nop

    func_804463E8(rdram, ctx);
        goto after_2;
    // 0x80447F20: nop

    after_2:
L_80447F24:
    // 0x80447F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447F28:
    // 0x80447F28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447F30: jr          $ra
    // 0x80447F34: nop

    return;
    // 0x80447F34: nop

;}
RECOMP_FUNC void func_805D1DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D1DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1E00: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x805D1E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805D1E08: beq         $t6, $zero, L_805D1E44
    if (ctx->r14 == 0) {
        // 0x805D1E0C: nop
    
            goto L_805D1E44;
    }
    // 0x805D1E0C: nop

    // 0x805D1E10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D1E14: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x805D1E18: jalr        $t9
    // 0x805D1E1C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805D1E1C: nop

    after_0:
    // 0x805D1E20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D1E24: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x805D1E28: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x805D1E2C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x805D1E30: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x805D1E34: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x805D1E38: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x805D1E3C: b           L_805D1E44
    // 0x805D1E40: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_805D1E44;
    // 0x805D1E40: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_805D1E44:
    // 0x805D1E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D1E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D1E4C: jr          $ra
    // 0x805D1E50: nop

    return;
    // 0x805D1E50: nop

;}
RECOMP_FUNC void func_800677F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800677F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800677FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067800: jal         0x80010A74
    // 0x80067804: nop

    func_80010A74(rdram, ctx);
        goto after_0;
    // 0x80067804: nop

    after_0:
    // 0x80067808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006780C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067810: jr          $ra
    // 0x80067814: nop

    return;
    // 0x80067814: nop

;}
RECOMP_FUNC void func_806EF5CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF5CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806EF5D0: lwc1        $f16, 0xE0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x806EF5D4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806EF5D8: lwc1        $f6, 0xEC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806EF5DC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806EF5E0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806EF5E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EF5E8: bc1f        L_806EF614
    if (!c1cs) {
        // 0x806EF5EC: swc1        $f8, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
            goto L_806EF614;
    }
    // 0x806EF5EC: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x806EF5F0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806EF5F4: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x806EF5F8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EF5FC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x806EF600: nop

    // 0x806EF604: bc1f        L_806EF630
    if (!c1cs) {
        // 0x806EF608: nop
    
            goto L_806EF630;
    }
    // 0x806EF608: nop

    // 0x806EF60C: jr          $ra
    // 0x806EF610: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x806EF610: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_806EF614:
    // 0x806EF614: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x806EF618: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EF61C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EF620: nop

    // 0x806EF624: bc1f        L_806EF630
    if (!c1cs) {
        // 0x806EF628: nop
    
            goto L_806EF630;
    }
    // 0x806EF628: nop

    // 0x806EF62C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_806EF630:
    // 0x806EF630: jr          $ra
    // 0x806EF634: nop

    return;
    // 0x806EF634: nop

;}
RECOMP_FUNC void func_807A00F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A00F8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x807A00FC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x807A0100: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(838, 0X1718) << 16);
    // 0x807A0104: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x807A0108: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x807A010C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x807A0110: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x807A0114: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x807A0118: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x807A011C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807A0120: lwc1        $f24, 0xD78($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(838, 0X1718));
    // 0x807A0124: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x807A0128: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x807A012C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x807A0130: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x807A0134: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x807A0138: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x807A013C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(838, 0X171C) << 16);
    // 0x807A0140: lui         $s6, 0x4042
    ctx->r22 = S32(0X4042 << 16);
    // 0x807A0144: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x807A0148: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x807A014C: lw          $fp, 0x1F4($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A0150: ori         $s6, $s6, 0x2000
    ctx->r22 = ctx->r22 | 0X2000;
    // 0x807A0154: lwc1        $f22, 0xD7C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(838, 0X171C));
    // 0x807A0158: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807A015C: addiu       $s5, $zero, 0x3FF
    ctx->r21 = ADD32(0, 0X3FF);
    // 0x807A0160: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_807A0164:
    // 0x807A0164: jal         0x80047090
    // 0x807A0168: addiu       $a0, $zero, 0x4042
    ctx->r4 = ADD32(0, 0X4042);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807A0168: addiu       $a0, $zero, 0x4042
    ctx->r4 = ADD32(0, 0X4042);
    after_0:
    // 0x807A016C: bne         $s5, $v0, L_807A017C
    if (ctx->r21 != ctx->r2) {
        // 0x807A0170: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_807A017C;
    }
    // 0x807A0170: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x807A0174: b           L_807A0208
    // 0x807A0178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A0208;
    // 0x807A0178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A017C:
    // 0x807A017C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x807A0180: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807A0184: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x807A0188: jal         0x8004613C
    // 0x807A018C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807A018C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x807A0190: beq         $v0, $zero, L_807A01E8
    if (ctx->r2 == 0) {
        // 0x807A0194: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_807A01E8;
    }
    // 0x807A0194: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x807A0198: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x807A019C: andi        $t7, $s3, 0x3FF
    ctx->r15 = ctx->r19 & 0X3FF;
    // 0x807A01A0: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x807A01A4: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x807A01A8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x807A01AC: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    // 0x807A01B0: addu        $s1, $fp, $t1
    ctx->r17 = ADD32(ctx->r30, ctx->r9);
    // 0x807A01B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807A01B8: jal         0x80047F9C
    // 0x807A01BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807A01BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x807A01C0: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x807A01C4: jal         0x807A00AC
    // 0x807A01C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A00AC(rdram, ctx);
        goto after_3;
    // 0x807A01C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807A01CC: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x807A01D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x807A01D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807A01D8: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x807A01DC: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x807A01E0: b           L_807A01F0
    // 0x807A01E4: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
        goto L_807A01F0;
    // 0x807A01E4: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_807A01E8:
    // 0x807A01E8: b           L_807A0208
    // 0x807A01EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A0208;
    // 0x807A01EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A01F0:
    // 0x807A01F0: bne         $s2, $s7, L_807A0164
    if (ctx->r18 != ctx->r23) {
        // 0x807A01F4: sw          $s0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r16;
            goto L_807A0164;
    }
    // 0x807A01F4: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
    // 0x807A01F8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x807A01FC: sw          $zero, 0x20($fp)
    MEM_W(0X20, ctx->r30) = 0;
    // 0x807A0200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807A0204: sw          $t2, 0x14($fp)
    MEM_W(0X14, ctx->r30) = ctx->r10;
L_807A0208:
    // 0x807A0208: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x807A020C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807A0210: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x807A0214: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x807A0218: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x807A021C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x807A0220: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x807A0224: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x807A0228: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x807A022C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x807A0230: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x807A0234: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x807A0238: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x807A023C: jr          $ra
    // 0x807A0240: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x807A0240: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_807AC4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC4CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807AC4D0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807AC4D4: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x807AC4D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807AC4DC: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(856, 0XB38) << 16);
    // 0x807AC4E0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807AC4E4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807AC4E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807AC4EC: lw          $t8, -0x3A78($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(856, 0XB38));
    // 0x807AC4F0: jr          $ra
    // 0x807AC4F4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x807AC4F4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x807AC4F8: nop

    // 0x807AC4FC: nop

;}
RECOMP_FUNC void func_80738050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80738050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80738054: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80738058: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8073805C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80738060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80738064: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80738068: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8073806C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80738070: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80738074: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80738078: lui         $t2, 0x8074
    ctx->r10 = S32(RELOC_HI16(736, 0X3AD8) << 16);
    // 0x8073807C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80738080: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80738084: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80738088: lw          $t2, -0x6AC8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(736, 0X3AD8));
    // 0x8073808C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80738090: jal         0x80737E9C
    // 0x80738094: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80737E9C(rdram, ctx);
        goto after_0;
    // 0x80738094: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x80738098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073809C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807380A0: jr          $ra
    // 0x807380A4: nop

    return;
    // 0x807380A4: nop

    // 0x807380A8: nop

    // 0x807380AC: nop

;}
RECOMP_FUNC void func_80426D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426D8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80426D90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80426D94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80426D98: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80426D9C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80426DA0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80426DA4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80426DA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80426DAC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80426DB0: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x80426DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80426DB8: jal         0x8004921C
    // 0x80426DBC: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80426DBC: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x80426DC0: sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // 0x80426DC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80426DC8: jal         0x8004921C
    // 0x80426DCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80426DCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80426DD0: lbu         $t0, 0x25($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X25);
    // 0x80426DD4: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x80426DD8: lbu         $t2, 0x145($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X145);
    // 0x80426DDC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80426DE0: lw          $v1, 0x168($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X168);
    // 0x80426DE4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80426DE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80426DEC: lw          $t4, 0x80($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X80);
    // 0x80426DF0: lw          $a3, 0x88($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X88);
    // 0x80426DF4: mflo        $t1
    ctx->r9 = lo;
    // 0x80426DF8: nop

    // 0x80426DFC: nop

    // 0x80426E00: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80426E04: mflo        $t3
    ctx->r11 = lo;
    // 0x80426E08: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80426E0C: jal         0x80426BE4
    // 0x80426E10: nop

    func_80426BE4(rdram, ctx);
        goto after_2;
    // 0x80426E10: nop

    after_2:
    // 0x80426E14: lh          $t5, 0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C);
    // 0x80426E18: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80426E1C: sh          $t6, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r14;
    // 0x80426E20: lh          $t7, 0x1C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1C);
    // 0x80426E24: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80426E28: bnel        $at, $zero, L_80426E38
    if (ctx->r1 != 0) {
        // 0x80426E2C: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80426E38;
    }
    goto skip_0;
    // 0x80426E2C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80426E30: sh          $zero, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = 0;
    // 0x80426E34: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80426E38:
    // 0x80426E38: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80426E3C: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x80426E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80426E44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80426E48: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80426E4C: jr          $ra
    // 0x80426E50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80426E50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804091BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804091BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804091C0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x804091C4: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x804091C8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x804091CC: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x804091D0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x804091D4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804091D8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804091DC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804091E0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804091E4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x804091E8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804091EC: lwc1        $f20, 0xB40($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0XB40);
    // 0x804091F0: lwc1        $f24, 0xB44($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0XB44);
    // 0x804091F4: lwc1        $f26, 0xB48($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0XB48);
    // 0x804091F8: jal         0x80409188
    // 0x804091FC: addiu       $s1, $a0, 0xA00
    ctx->r17 = ADD32(ctx->r4, 0XA00);
    func_80409188(rdram, ctx);
        goto after_0;
    // 0x804091FC: addiu       $s1, $a0, 0xA00
    ctx->r17 = ADD32(ctx->r4, 0XA00);
    after_0:
    // 0x80409200: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80409204: jal         0x80409110
    // 0x80409208: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80409110(rdram, ctx);
        goto after_1;
    // 0x80409208: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x8040920C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80409210: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80409214: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80409218: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8040921C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80409220: addiu       $s2, $zero, 0xA0
    ctx->r18 = ADD32(0, 0XA0);
    // 0x80409224: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80409228: nop

    // 0x8040922C: bgez        $t7, L_8040923C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80409230: sra         $t8, $t7, 3
        ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
            goto L_8040923C;
    }
    // 0x80409230: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80409234: addiu       $at, $t7, 0x7
    ctx->r1 = ADD32(ctx->r15, 0X7);
    // 0x80409238: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8040923C:
    // 0x8040923C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80409240: nop

    // 0x80409244: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80409248: mul.s       $f16, $f24, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x8040924C: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x80409250: div.s       $f18, $f20, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80409254: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80409258: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8040925C: nop

    // 0x80409260: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80409264: nop

    // 0x80409268: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8040926C: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80409270: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
L_80409274:
    // 0x80409274: jal         0x80066DE4
    // 0x80409278: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80409278: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x8040927C: mul.s       $f18, $f0, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80409280: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x80409284: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80409288: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8040928C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80409290: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80409294: bc1f        L_804092A0
    if (!c1cs) {
        // 0x80409298: swc1        $f4, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
            goto L_804092A0;
    }
    // 0x80409298: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x8040929C: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
L_804092A0:
    // 0x804092A0: bne         $s0, $s2, L_80409274
    if (ctx->r16 != ctx->r18) {
        // 0x804092A4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80409274;
    }
    // 0x804092A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x804092A8: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x804092AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804092B0: lwc1        $f6, 0xB40($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XB40);
    // 0x804092B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804092B8: swc1        $f10, 0xB40($s3)
    MEM_W(0XB40, ctx->r19) = ctx->f10.u32l;
    // 0x804092BC: lwc1        $f0, 0xB40($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XB40);
    // 0x804092C0: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x804092C4: nop

    // 0x804092C8: bc1fl       L_804092DC
    if (!c1cs) {
        // 0x804092CC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_804092DC;
    }
    goto skip_0;
    // 0x804092CC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x804092D0: sub.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x804092D4: swc1        $f16, 0xB40($s3)
    MEM_W(0XB40, ctx->r19) = ctx->f16.u32l;
    // 0x804092D8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_804092DC:
    // 0x804092DC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804092E0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804092E4: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804092E8: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804092EC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x804092F0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x804092F4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x804092F8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x804092FC: jr          $ra
    // 0x80409300: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80409300: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80429040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429044: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80429048: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042904C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80429050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429054: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80429058: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042905C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80429060: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80429064: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80429068: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(41, 0X1E2C) << 16);
    // 0x8042906C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80429070: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80429074: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80429078: lw          $t2, -0x6894($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(41, 0X1E2C));
    // 0x8042907C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80429080: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80429084: jal         0x80428904
    // 0x80429088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80428904(rdram, ctx);
        goto after_0;
    // 0x80429088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042908C: jal         0x80428960
    // 0x80429090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80428960(rdram, ctx);
        goto after_1;
    // 0x80429090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80429094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80429098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042909C: jr          $ra
    // 0x804290A0: nop

    return;
    // 0x804290A0: nop

;}
RECOMP_FUNC void func_805364A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805364A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805364A8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805364AC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805364B0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805364B4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805364B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805364BC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805364C0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805364C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805364C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805364CC: jr          $ra
    // 0x805364D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805364D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F9D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9D60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F9D64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F9D68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F9D6C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806F9D70: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806F9D74: lbu         $t8, -0x7204($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X7204);
    // 0x806F9D78: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x806F9D7C: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x806F9D80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806F9D84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F9D88: bne         $t8, $at, L_806F9D98
    if (ctx->r24 != ctx->r1) {
        // 0x806F9D8C: lw          $v0, 0x88($t7)
        ctx->r2 = MEM_W(ctx->r15, 0X88);
            goto L_806F9D98;
    }
    // 0x806F9D8C: lw          $v0, 0x88($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X88);
    // 0x806F9D90: jal         0x8004590C
    // 0x806F9D94: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x806F9D94: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    after_0:
L_806F9D98:
    // 0x806F9D98: jal         0x806FA6F0
    // 0x806F9D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FA6F0(rdram, ctx);
        goto after_1;
    // 0x806F9D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F9DA0: beq         $v0, $zero, L_806F9E88
    if (ctx->r2 == 0) {
        // 0x806F9DA4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_806F9E88;
    }
    // 0x806F9DA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F9DA8: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x806F9DAC: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(700, 0X2900) << 16);
    // 0x806F9DB0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806F9DB4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806F9DB8: sw          $t9, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r25;
    // 0x806F9DBC: addiu       $t0, $t0, -0x3AD0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(700, 0X2900));
    // 0x806F9DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F9DC4: jal         0x806FA8F8
    // 0x806F9DC8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    func_806FA8F8(rdram, ctx);
        goto after_2;
    // 0x806F9DC8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    after_2:
    // 0x806F9DCC: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x806F9DD0: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x806F9DD4: sw          $t2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r10;
    // 0x806F9DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F9DDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F9DE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F9DE4: jal         0x806FC1EC
    // 0x806F9DE8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_806FC1EC(rdram, ctx);
        goto after_3;
    // 0x806F9DE8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x806F9DEC: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x806F9DF0: lui         $t3, 0x8070
    ctx->r11 = S32(RELOC_HI16(700, 0X178C) << 16);
    // 0x806F9DF4: addiu       $t3, $t3, -0x4C44
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(700, 0X178C));
    // 0x806F9DF8: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    // 0x806F9DFC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x806F9E00: lui         $t5, 0x8070
    ctx->r13 = S32(RELOC_HI16(700, 0X104C) << 16);
    // 0x806F9E04: addiu       $t5, $t5, -0x5384
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(700, 0X104C));
    // 0x806F9E08: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806F9E0C: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(700, 0X1250) << 16);
    // 0x806F9E10: addiu       $t8, $t8, -0x5180
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(700, 0X1250));
    // 0x806F9E14: sw          $t5, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r13;
    // 0x806F9E18: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x806F9E1C: lui         $a1, 0x8070
    ctx->r5 = S32(RELOC_HI16(700, 0X2908) << 16);
    // 0x806F9E20: addiu       $a1, $a1, -0x3AC8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(700, 0X2908));
    // 0x806F9E24: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806F9E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F9E2C: addiu       $a2, $s0, 0x6C
    ctx->r6 = ADD32(ctx->r16, 0X6C);
    // 0x806F9E30: sw          $t8, 0x68($t0)
    MEM_W(0X68, ctx->r8) = ctx->r24;
    // 0x806F9E34: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x806F9E38: jal         0x806FA644
    // 0x806F9E3C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_806FA644(rdram, ctx);
        goto after_4;
    // 0x806F9E3C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_4:
    // 0x806F9E40: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x806F9E44: lui         $t3, 0x8070
    ctx->r11 = S32(RELOC_HI16(700, 0X108) << 16);
    // 0x806F9E48: bne         $v0, $zero, L_806F9E60
    if (ctx->r2 != 0) {
        // 0x806F9E4C: sw          $v0, 0x14B0($t2)
        MEM_W(0X14B0, ctx->r10) = ctx->r2;
            goto L_806F9E60;
    }
    // 0x806F9E4C: sw          $v0, 0x14B0($t2)
    MEM_W(0X14B0, ctx->r10) = ctx->r2;
    // 0x806F9E50: jal         0x800445A4
    // 0x806F9E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x806F9E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806F9E58: b           L_806F9E94
    // 0x806F9E5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F9E94;
    // 0x806F9E5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F9E60:
    // 0x806F9E60: addiu       $t3, $t3, -0x62C8
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(700, 0X108));
    // 0x806F9E64: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    // 0x806F9E68: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806F9E6C: jal         0x80067BBC
    // 0x806F9E70: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x806F9E70: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x806F9E74: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x806F9E78: jal         0x80067F78
    // 0x806F9E7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_7;
    // 0x806F9E7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x806F9E80: b           L_806F9E90
    // 0x806F9E84: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_806F9E90;
    // 0x806F9E84: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_806F9E88:
    // 0x806F9E88: jal         0x800445A4
    // 0x806F9E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x806F9E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_806F9E90:
    // 0x806F9E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F9E94:
    // 0x806F9E94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F9E98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F9E9C: jr          $ra
    // 0x806F9EA0: nop

    return;
    // 0x806F9EA0: nop

;}
RECOMP_FUNC void func_806E3810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3810: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E3814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E3818: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806E381C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E3820: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x806E3824: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x806E3828: beql        $t6, $zero, L_806E38BC
    if (ctx->r14 == 0) {
        // 0x806E382C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E38BC;
    }
    goto skip_0;
    // 0x806E382C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E3830: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x806E3834: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E3838: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x806E383C: beq         $t7, $zero, L_806E3884
    if (ctx->r15 == 0) {
        // 0x806E3840: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_806E3884;
    }
    // 0x806E3840: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x806E3844: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E3848: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x806E384C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x806E3850: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x806E3854: jal         0x8004D1F0
    // 0x806E3858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x806E3858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E385C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E3860: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E3864: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x806E3868: jal         0x8004D698
    // 0x806E386C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x806E386C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x806E3870: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806E3874: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x806E3878: ori         $t9, $t8, 0xF
    ctx->r25 = ctx->r24 | 0XF;
    // 0x806E387C: b           L_806E38B8
    // 0x806E3880: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
        goto L_806E38B8;
    // 0x806E3880: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
L_806E3884:
    // 0x806E3884: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806E3888: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x806E388C: jal         0x8004D1F0
    // 0x806E3890: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x806E3890: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x806E3894: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E3898: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E389C: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x806E38A0: jal         0x8004D698
    // 0x806E38A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x806E38A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x806E38A8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806E38AC: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x806E38B0: ori         $t1, $t0, 0xF0
    ctx->r9 = ctx->r8 | 0XF0;
    // 0x806E38B4: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
L_806E38B8:
    // 0x806E38B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E38BC:
    // 0x806E38BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E38C0: jr          $ra
    // 0x806E38C4: nop

    return;
    // 0x806E38C4: nop

;}
RECOMP_FUNC void func_80799DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799DF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80799DF4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80799DF8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80799DFC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80799E00: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x80799E04: lw          $t7, 0xE94($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XE94);
    // 0x80799E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799E0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80799E10: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80799E14: lw          $t8, 0xE94($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE94);
    // 0x80799E18: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80799E1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80799E20: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80799E24: lw          $t9, 0xE94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE94);
    // 0x80799E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80799E2C: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x80799E30: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80799E34: lw          $t0, 0xE94($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE94);
    // 0x80799E38: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80799E3C: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80799E40: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80799E44: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80799E48: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80799E4C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80799E50: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x80799E54: jalr        $t9
    // 0x80799E58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80799E58: nop

    after_0:
    // 0x80799E5C: lhu         $v1, 0x36($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X36);
    // 0x80799E60: addiu       $at, $zero, 0x4034
    ctx->r1 = ADD32(0, 0X4034);
    // 0x80799E64: beq         $v1, $at, L_80799E7C
    if (ctx->r3 == ctx->r1) {
        // 0x80799E68: addiu       $at, $zero, 0x4035
        ctx->r1 = ADD32(0, 0X4035);
            goto L_80799E7C;
    }
    // 0x80799E68: addiu       $at, $zero, 0x4035
    ctx->r1 = ADD32(0, 0X4035);
    // 0x80799E6C: beq         $v1, $at, L_80799E98
    if (ctx->r3 == ctx->r1) {
        // 0x80799E70: nop
    
            goto L_80799E98;
    }
    // 0x80799E70: nop

    // 0x80799E74: b           L_80799EB0
    // 0x80799E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80799EB0;
    // 0x80799E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80799E7C:
    // 0x80799E7C: jal         0x80067E68
    // 0x80799E80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x80799E80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80799E84: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80799E88: jal         0x80067818
    // 0x80799E8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80799E8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80799E90: b           L_80799EB0
    // 0x80799E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80799EB0;
    // 0x80799E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80799E98:
    // 0x80799E98: jal         0x80067E68
    // 0x80799E9C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x80799E9C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80799EA0: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80799EA4: jal         0x80067818
    // 0x80799EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80799EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80799EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80799EB0:
    // 0x80799EB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80799EB4: jr          $ra
    // 0x80799EB8: nop

    return;
    // 0x80799EB8: nop

;}
RECOMP_FUNC void func_8005F0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F0EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005F0F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F0F4: lwc1        $f0, 0x20($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8005F0F8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005F0FC: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8005F100: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8005F104: nop

    // 0x8005F108: bc1tl       L_8005F128
    if (c1cs) {
        // 0x8005F10C: lh          $t7, 0x28($a1)
        ctx->r15 = MEM_H(ctx->r5, 0X28);
            goto L_8005F128;
    }
    goto skip_0;
    // 0x8005F10C: lh          $t7, 0x28($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X28);
    skip_0:
    // 0x8005F110: lwc1        $f2, 0x24($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8005F114: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8005F118: nop

    // 0x8005F11C: bc1fl       L_8005F150
    if (!c1cs) {
        // 0x8005F120: lh          $t3, 0x28($a1)
        ctx->r11 = MEM_H(ctx->r5, 0X28);
            goto L_8005F150;
    }
    goto skip_1;
    // 0x8005F120: lh          $t3, 0x28($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X28);
    skip_1:
    // 0x8005F124: lh          $t7, 0x28($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X28);
L_8005F128:
    // 0x8005F128: lh          $t0, 0x2A($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X2A);
    // 0x8005F12C: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x8005F130: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8005F134: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005F138: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005F13C: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x8005F140: subu        $v0, $t6, $t8
    ctx->r2 = SUB32(ctx->r14, ctx->r24);
    // 0x8005F144: b           L_8005F1B4
    // 0x8005F148: subu        $v1, $t9, $t1
    ctx->r3 = SUB32(ctx->r25, ctx->r9);
        goto L_8005F1B4;
    // 0x8005F148: subu        $v1, $t9, $t1
    ctx->r3 = SUB32(ctx->r25, ctx->r9);
    // 0x8005F14C: lh          $t3, 0x28($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X28);
L_8005F150:
    // 0x8005F150: lh          $t6, 0x2A($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2A);
    // 0x8005F154: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005F158: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8005F15C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8005F160: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F164: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005F168: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x8005F16C: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x8005F170: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8005F174: sw          $a3, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r7;
    // 0x8005F178: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005F17C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005F180: nop

    // 0x8005F184: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8005F188: nop

    // 0x8005F18C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005F190: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8005F194: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8005F198: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8005F19C: nop

    // 0x8005F1A0: subu        $v0, $t2, $t5
    ctx->r2 = SUB32(ctx->r10, ctx->r13);
    // 0x8005F1A4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005F1A8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8005F1AC: nop

    // 0x8005F1B0: subu        $v1, $t7, $t0
    ctx->r3 = SUB32(ctx->r15, ctx->r8);
L_8005F1B4:
    // 0x8005F1B4: lw          $a2, -0x7D6C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D6C);
    // 0x8005F1B8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005F1BC: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8005F1C0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8005F1C4: nop

    // 0x8005F1C8: bc1fl       L_8005F1E8
    if (!c1cs) {
        // 0x8005F1CC: lwc1        $f18, 0x20($a1)
        ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
            goto L_8005F1E8;
    }
    goto skip_2;
    // 0x8005F1CC: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    skip_2:
    // 0x8005F1D0: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8005F1D4: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
    // 0x8005F1D8: nop

    // 0x8005F1DC: bc1tl       L_8005F218
    if (c1cs) {
        // 0x8005F1E0: sh          $v0, 0x1C($a0)
        MEM_H(0X1C, ctx->r4) = ctx->r2;
            goto L_8005F218;
    }
    goto skip_3;
    // 0x8005F1E0: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
    skip_3:
    // 0x8005F1E4: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
L_8005F1E8:
    // 0x8005F1E8: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8005F1EC: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8005F1F0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8005F1F4: sw          $a3, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r7;
    // 0x8005F1F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005F1FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005F200: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005F204: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8005F208: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8005F20C: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x8005F210: subu        $v1, $v1, $t4
    ctx->r3 = SUB32(ctx->r3, ctx->r12);
    // 0x8005F214: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
L_8005F218:
    // 0x8005F218: sh          $v1, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r3;
    // 0x8005F21C: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8005F220: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x8005F224: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8005F228: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    // 0x8005F22C: lw          $t2, 0x19C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X19C);
    // 0x8005F230: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
    // 0x8005F234: lw          $t5, 0x19C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X19C);
    // 0x8005F238: bnel        $t5, $zero, L_8005F254
    if (ctx->r13 != 0) {
        // 0x8005F23C: sw          $a3, 0x34($a0)
        MEM_W(0X34, ctx->r4) = ctx->r7;
            goto L_8005F254;
    }
    goto skip_4;
    // 0x8005F23C: sw          $a3, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r7;
    skip_4:
    // 0x8005F240: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x8005F244: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F248: bne         $t6, $at, L_8005F254
    if (ctx->r14 != ctx->r1) {
        // 0x8005F24C: nop
    
            goto L_8005F254;
    }
    // 0x8005F24C: nop

    // 0x8005F250: sw          $a3, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r7;
L_8005F254:
    // 0x8005F254: jr          $ra
    // 0x8005F258: nop

    return;
    // 0x8005F258: nop

;}
RECOMP_FUNC void func_8006C4C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4C8: jr          $ra
    // 0x8006C4CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006C4CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80434568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043456C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80434570: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80434574: jal         0x80045A34
    // 0x80434578: addiu       $a1, $zero, 0xF38
    ctx->r5 = ADD32(0, 0XF38);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80434578: addiu       $a1, $zero, 0xF38
    ctx->r5 = ADD32(0, 0XF38);
    after_0:
    // 0x8043457C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80434580: beq         $v0, $zero, L_80434598
    if (ctx->r2 == 0) {
        // 0x80434584: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80434598;
    }
    // 0x80434584: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80434588: jal         0x8043453C
    // 0x8043458C: nop

    func_8043453C(rdram, ctx);
        goto after_1;
    // 0x8043458C: nop

    after_1:
    // 0x80434590: jal         0x804344E0
    // 0x80434594: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804344E0(rdram, ctx);
        goto after_2;
    // 0x80434594: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80434598:
    // 0x80434598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043459C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804345A0: jr          $ra
    // 0x804345A4: nop

    return;
    // 0x804345A4: nop

;}
RECOMP_FUNC void func_8046A29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A29C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046A2A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046A2A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046A2A8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046A2AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8046A2B0: jal         0x80060FE0
    // 0x8046A2B4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80060FE0(rdram, ctx);
        goto after_0;
    // 0x8046A2B4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8046A2B8: jal         0x8005FE48
    // 0x8046A2BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x8046A2BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046A2C0: jal         0x80469BA4
    // 0x8046A2C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469BA4(rdram, ctx);
        goto after_2;
    // 0x8046A2C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8046A2C8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8046A2CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046A2D0: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8046A2D4: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8046A2D8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8046A2DC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8046A2E0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8046A2E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8046A2E8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8046A2EC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8046A2F0: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x8046A2F4: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8046A2F8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8046A2FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046A300: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046A304: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046A308: jr          $ra
    // 0x8046A30C: nop

    return;
    // 0x8046A30C: nop

;}
RECOMP_FUNC void func_80584A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584A2C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584A30: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584A34: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584A38: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584A3C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584A40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584A44: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584A48: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584A4C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584A50: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584A54: jr          $ra
    // 0x80584A58: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584A58: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80432BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80432BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432BB8: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80432BBC: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(62, 0X578) << 16);
    // 0x80432BC0: addiu       $t8, $t8, 0x2D18
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(62, 0X578));
    // 0x80432BC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80432BC8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80432BCC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80432BD0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80432BD4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80432BD8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80432BDC: beql        $v1, $zero, L_80432C14
    if (ctx->r3 == 0) {
        // 0x80432BE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80432C14;
    }
    goto skip_0;
    // 0x80432BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80432BE4: jalr        $v1
    // 0x80432BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80432BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80432BEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80432BF0: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x80432BF4: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x80432BF8: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x80432BFC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80432C00: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x80432C04: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80432C08: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80432C0C: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x80432C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80432C14:
    // 0x80432C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432C18: jr          $ra
    // 0x80432C1C: nop

    return;
    // 0x80432C1C: nop

;}
RECOMP_FUNC void func_80068190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068190: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80068194: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x80068198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006819C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800681A0: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x800681A4: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x800681A8: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x800681AC: bne         $t7, $at, L_800681F8
    if (ctx->r15 != ctx->r1) {
        // 0x800681B0: andi        $t8, $v0, 0x20
        ctx->r24 = ctx->r2 & 0X20;
            goto L_800681F8;
    }
    // 0x800681B0: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x800681B4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800681B8: bne         $t8, $at, L_800681F8
    if (ctx->r24 != ctx->r1) {
        // 0x800681BC: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_800681F8;
    }
    // 0x800681BC: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800681C0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800681C4: bne         $t9, $at, L_800681F8
    if (ctx->r25 != ctx->r1) {
        // 0x800681C8: andi        $t0, $v0, 0x4000
        ctx->r8 = ctx->r2 & 0X4000;
            goto L_800681F8;
    }
    // 0x800681C8: andi        $t0, $v0, 0x4000
    ctx->r8 = ctx->r2 & 0X4000;
    // 0x800681CC: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800681D0: bnel        $t0, $at, L_800681FC
    if (ctx->r8 != ctx->r1) {
        // 0x800681D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800681FC;
    }
    goto skip_0;
    // 0x800681D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800681D8: jal         0x80047058
    // 0x800681DC: nop

    func_80047058(rdram, ctx);
        goto after_0;
    // 0x800681DC: nop

    after_0:
    // 0x800681E0: beq         $v0, $zero, L_800681F8
    if (ctx->r2 == 0) {
        // 0x800681E4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800681F8;
    }
    // 0x800681E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800681E8: jal         0x8002FC3C
    // 0x800681EC: nop

    func_8002FC3C(rdram, ctx);
        goto after_1;
    // 0x800681EC: nop

    after_1:
    // 0x800681F0: b           L_800681FC
    // 0x800681F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800681FC;
    // 0x800681F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800681F8:
    // 0x800681F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800681FC:
    // 0x800681FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068204: jr          $ra
    // 0x80068208: nop

    return;
    // 0x80068208: nop

;}
RECOMP_FUNC void func_8040A260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040A260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040A264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040A268: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040A26C: jal         0x80045A34
    // 0x8040A270: addiu       $a1, $zero, 0x1168
    ctx->r5 = ADD32(0, 0X1168);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8040A270: addiu       $a1, $zero, 0x1168
    ctx->r5 = ADD32(0, 0X1168);
    after_0:
    // 0x8040A274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040A278: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8040A27C: bne         $v0, $zero, L_8040A28C
    if (ctx->r2 != 0) {
        // 0x8040A280: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8040A28C;
    }
    // 0x8040A280: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8040A284: b           L_8040A2E4
    // 0x8040A288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8040A2E4;
    // 0x8040A288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040A28C:
    // 0x8040A28C: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0XD2C) << 16);
    // 0x8040A290: addiu       $t6, $t6, -0x7904
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0XD2C));
    // 0x8040A294: sw          $t6, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r14;
    // 0x8040A298: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040A29C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8040A2A0: jal         0x8040A4D0
    // 0x8040A2A4: addiu       $a1, $zero, 0x4104
    ctx->r5 = ADD32(0, 0X4104);
    func_8040A4D0(rdram, ctx);
        goto after_1;
    // 0x8040A2A4: addiu       $a1, $zero, 0x4104
    ctx->r5 = ADD32(0, 0X4104);
    after_1:
    // 0x8040A2A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8040A2AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040A2B0: bne         $v0, $zero, L_8040A2C0
    if (ctx->r2 != 0) {
        // 0x8040A2B4: sw          $v0, 0x1154($v1)
        MEM_W(0X1154, ctx->r3) = ctx->r2;
            goto L_8040A2C0;
    }
    // 0x8040A2B4: sw          $v0, 0x1154($v1)
    MEM_W(0X1154, ctx->r3) = ctx->r2;
    // 0x8040A2B8: b           L_8040A2E4
    // 0x8040A2BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8040A2E4;
    // 0x8040A2BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040A2C0:
    // 0x8040A2C0: addiu       $a1, $zero, 0x4105
    ctx->r5 = ADD32(0, 0X4105);
    // 0x8040A2C4: jal         0x8040A4D0
    // 0x8040A2C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8040A4D0(rdram, ctx);
        goto after_2;
    // 0x8040A2C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8040A2CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8040A2D0: bne         $v0, $zero, L_8040A2E0
    if (ctx->r2 != 0) {
        // 0x8040A2D4: sw          $v0, 0x1158($v1)
        MEM_W(0X1158, ctx->r3) = ctx->r2;
            goto L_8040A2E0;
    }
    // 0x8040A2D4: sw          $v0, 0x1158($v1)
    MEM_W(0X1158, ctx->r3) = ctx->r2;
    // 0x8040A2D8: b           L_8040A2E4
    // 0x8040A2DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8040A2E4;
    // 0x8040A2DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040A2E0:
    // 0x8040A2E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8040A2E4:
    // 0x8040A2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040A2E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040A2EC: jr          $ra
    // 0x8040A2F0: nop

    return;
    // 0x8040A2F0: nop

;}
RECOMP_FUNC void func_807BAAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAAFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BAB00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BAB04: jal         0x8004700C
    // 0x807BAB08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807BAB08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BAB0C: bne         $v0, $zero, L_807BAB1C
    if (ctx->r2 != 0) {
        // 0x807BAB10: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_807BAB1C;
    }
    // 0x807BAB10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807BAB14: b           L_807BAB84
    // 0x807BAB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807BAB84;
    // 0x807BAB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BAB1C:
    // 0x807BAB1C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x807BAB20: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x807BAB24: lwc1        $f4, 0x84($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X84);
    // 0x807BAB28: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x807BAB2C: jal         0x80065954
    // 0x807BAB30: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x807BAB30: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x807BAB34: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x807BAB38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807BAB3C: nop

    // 0x807BAB40: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x807BAB44: nop

    // 0x807BAB48: bc1f        L_807BAB58
    if (!c1cs) {
        // 0x807BAB4C: nop
    
            goto L_807BAB58;
    }
    // 0x807BAB4C: nop

    // 0x807BAB50: b           L_807BAB84
    // 0x807BAB54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807BAB84;
    // 0x807BAB54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807BAB58:
    // 0x807BAB58: jal         0x80049018
    // 0x807BAB5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x807BAB5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x807BAB60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x807BAB64: jal         0x80049018
    // 0x807BAB68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80049018(rdram, ctx);
        goto after_3;
    // 0x807BAB68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x807BAB6C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x807BAB70: bnel        $v0, $t7, L_807BAB84
    if (ctx->r2 != ctx->r15) {
        // 0x807BAB74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_807BAB84;
    }
    goto skip_0;
    // 0x807BAB74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x807BAB78: b           L_807BAB84
    // 0x807BAB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807BAB84;
    // 0x807BAB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807BAB80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807BAB84:
    // 0x807BAB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BAB88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BAB8C: jr          $ra
    // 0x807BAB90: nop

    return;
    // 0x807BAB90: nop

;}
RECOMP_FUNC void func_805C930C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C930C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805C9310: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805C9314: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805C9318: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C931C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C9320: jal         0x8004700C
    // 0x805C9324: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C9324: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C9328: beq         $v0, $zero, L_805C9464
    if (ctx->r2 == 0) {
        // 0x805C932C: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_805C9464;
    }
    // 0x805C932C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C9330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9334: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x805C9338: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x805C933C: jal         0x805C71D4
    // 0x805C9340: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_805C71D4(rdram, ctx);
        goto after_1;
    // 0x805C9340: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x805C9344: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C9348: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x805C934C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9350: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x805C9354: bnel        $t6, $zero, L_805C9408
    if (ctx->r14 != 0) {
        // 0x805C9358: lw          $t5, 0x2C($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X2C);
            goto L_805C9408;
    }
    goto skip_0;
    // 0x805C9358: lw          $t5, 0x2C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2C);
    skip_0:
    // 0x805C935C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x805C9360: jal         0x805C7BAC
    // 0x805C9364: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_805C7BAC(rdram, ctx);
        goto after_2;
    // 0x805C9364: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_2:
    // 0x805C9368: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C936C: beq         $v0, $zero, L_805C9404
    if (ctx->r2 == 0) {
        // 0x805C9370: lw          $a2, 0x38($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X38);
            goto L_805C9404;
    }
    // 0x805C9370: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x805C9374: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x805C9378: sw          $t7, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r15;
    // 0x805C937C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x805C9380: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805C9384: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x805C9388: lw          $t3, 0xA68($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XA68);
    // 0x805C938C: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x805C9390: lw          $t8, 0xF10($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XF10);
    // 0x805C9394: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x805C9398: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x805C939C: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x805C93A0: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(447, 0X3950) << 16);
    // 0x805C93A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805C93A8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x805C93AC: lw          $t9, 0x40($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X40);
    // 0x805C93B0: lw          $v0, -0x61C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(447, 0X3950));
    // 0x805C93B4: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(447, 0X3948) << 16);
    // 0x805C93B8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x805C93BC: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x805C93C0: lw          $a2, -0x61C8($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(447, 0X3948));
    // 0x805C93C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C93C8: lui         $a3, 0xC214
    ctx->r7 = S32(0XC214 << 16);
    // 0x805C93CC: jalr        $t9
    // 0x805C93D0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x805C93D0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_3:
    // 0x805C93D4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805C93D8: jal         0x80067BBC
    // 0x805C93DC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x805C93DC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x805C93E0: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    // 0x805C93E4: jal         0x80067818
    // 0x805C93E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x805C93E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x805C93EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C93F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C93F4: jal         0x805C9D10
    // 0x805C93F8: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    func_805C9D10(rdram, ctx);
        goto after_6;
    // 0x805C93F8: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_6:
    // 0x805C93FC: b           L_805C9468
    // 0x805C9400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805C9468;
    // 0x805C9400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805C9404:
    // 0x805C9404: lw          $t5, 0x2C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2C);
L_805C9408:
    // 0x805C9408: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805C940C: bnel        $t5, $at, L_805C941C
    if (ctx->r13 != ctx->r1) {
        // 0x805C9410: lwc1        $f6, 0x84($a2)
        ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
            goto L_805C941C;
    }
    goto skip_1;
    // 0x805C9410: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
    skip_1:
    // 0x805C9414: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C9418: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
L_805C941C:
    // 0x805C941C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x805C9420: lwc1        $f16, 0x88($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X88);
    // 0x805C9424: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805C9428: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805C942C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C9430: swc1        $f10, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f10.u32l;
    // 0x805C9434: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x805C9438: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x805C943C: swc1        $f4, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f4.u32l;
    // 0x805C9440: jal         0x80048F84
    // 0x805C9444: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x805C9444: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_7:
    // 0x805C9448: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805C944C: jal         0x80048F84
    // 0x805C9450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_8;
    // 0x805C9450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x805C9454: jal         0x805C6CA4
    // 0x805C9458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C6CA4(rdram, ctx);
        goto after_9;
    // 0x805C9458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x805C945C: jal         0x805C7ABC
    // 0x805C9460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7ABC(rdram, ctx);
        goto after_10;
    // 0x805C9460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_805C9464:
    // 0x805C9464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805C9468:
    // 0x805C9468: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805C946C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805C9470: jr          $ra
    // 0x805C9474: nop

    return;
    // 0x805C9474: nop

;}
RECOMP_FUNC void func_807A13F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A13F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A13F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A13F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807A13FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807A1400: lw          $a2, 0x174($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X174);
    // 0x807A1404: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A1408: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x807A140C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807A1410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A1414: jal         0x807A0FFC
    // 0x807A1418: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_807A0FFC(rdram, ctx);
        goto after_0;
    // 0x807A1418: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x807A141C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x807A1420: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x807A1424: blez        $v0, L_807A1430
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A1428: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807A1430;
    }
    // 0x807A1428: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A142C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_807A1430:
    // 0x807A1430: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x807A1434: lw          $v1, 0x40($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X40);
    // 0x807A1438: lbu         $t8, 0x44($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X44);
    // 0x807A143C: beql        $t8, $zero, L_807A1460
    if (ctx->r24 == 0) {
        // 0x807A1440: lbu         $t2, 0x2C($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X2C);
            goto L_807A1460;
    }
    goto skip_0;
    // 0x807A1440: lbu         $t2, 0x2C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2C);
    skip_0:
    // 0x807A1444: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x807A1448: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x807A144C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x807A1450: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    // 0x807A1454: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x807A1458: lw          $v1, 0x40($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X40);
    // 0x807A145C: lbu         $t2, 0x2C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2C);
L_807A1460:
    // 0x807A1460: beql        $t2, $zero, L_807A14DC
    if (ctx->r10 == 0) {
        // 0x807A1464: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807A14DC;
    }
    goto skip_1;
    // 0x807A1464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x807A1468: lw          $t3, 0x1E4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E4);
    // 0x807A146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A1470: beql        $t3, $zero, L_807A1488
    if (ctx->r11 == 0) {
        // 0x807A1474: lw          $t4, 0x1E0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X1E0);
            goto L_807A1488;
    }
    goto skip_2;
    // 0x807A1474: lw          $t4, 0x1E0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E0);
    skip_2:
    // 0x807A1478: jal         0x807A0F78
    // 0x807A147C: addiu       $a1, $zero, 0x257
    ctx->r5 = ADD32(0, 0X257);
    func_807A0F78(rdram, ctx);
        goto after_1;
    // 0x807A147C: addiu       $a1, $zero, 0x257
    ctx->r5 = ADD32(0, 0X257);
    after_1:
    // 0x807A1480: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x807A1484: lw          $t4, 0x1E0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E0);
L_807A1488:
    // 0x807A1488: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(841, 0XDA0) << 16);
    // 0x807A148C: beql        $t4, $zero, L_807A14AC
    if (ctx->r12 == 0) {
        // 0x807A1490: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_807A14AC;
    }
    goto skip_3;
    // 0x807A1490: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_3:
    // 0x807A1494: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x807A1498: lwc1        $f6, 0x1CE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(841, 0XDA0));
    // 0x807A149C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807A14A0: b           L_807A14B4
    // 0x807A14A4: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_807A14B4;
    // 0x807A14A4: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x807A14A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_807A14AC:
    // 0x807A14AC: nop

    // 0x807A14B0: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_807A14B4:
    // 0x807A14B4: jal         0x807A10CC
    // 0x807A14B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A10CC(rdram, ctx);
        goto after_2;
    // 0x807A14B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807A14BC: beq         $v0, $zero, L_807A14D8
    if (ctx->r2 == 0) {
        // 0x807A14C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807A14D8;
    }
    // 0x807A14C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A14C4: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x807A14C8: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    // 0x807A14CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A14D0: jal         0x807A1AE4
    // 0x807A14D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_807A1AE4(rdram, ctx);
        goto after_3;
    // 0x807A14D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
L_807A14D8:
    // 0x807A14D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A14DC:
    // 0x807A14DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807A14E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807A14E4: jr          $ra
    // 0x807A14E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807A14E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805E11E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E11E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805E11E4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805E11E8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805E11EC: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(483, 0X688) << 16);
    // 0x805E11F0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805E11F4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805E11F8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805E11FC: lw          $t8, 0x1318($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(483, 0X688));
    // 0x805E1200: jr          $ra
    // 0x805E1204: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x805E1204: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80436CAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436CAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436CB4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80436CB8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80436CBC: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(77, 0X1F3C) << 16);
    // 0x80436CC0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80436CC4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80436CC8: lw          $t8, -0x7824($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(77, 0X1F3C));
    // 0x80436CCC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80436CD0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80436CD4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80436CD8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80436CDC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80436CE0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80436CE4: beql        $v1, $zero, L_80436D18
    if (ctx->r3 == 0) {
        // 0x80436CE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80436D18;
    }
    goto skip_0;
    // 0x80436CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80436CEC: jalr        $v1
    // 0x80436CF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80436CF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80436CF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80436CF8: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80436CFC: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80436D00: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80436D04: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80436D08: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80436D0C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80436D10: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80436D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80436D18:
    // 0x80436D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436D1C: jr          $ra
    // 0x80436D20: nop

    return;
    // 0x80436D20: nop

;}
RECOMP_FUNC void func_8042C358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042C35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042C360: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042C364: jal         0x8042BFF4
    // 0x8042C368: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    func_8042BFF4(rdram, ctx);
        goto after_0;
    // 0x8042C368: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_0:
    // 0x8042C36C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042C370: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(50, 0X1A40) << 16);
    // 0x8042C374: addiu       $t9, $t9, -0x3D20
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(50, 0X1A40));
    // 0x8042C378: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8042C37C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8042C380: slti        $at, $t7, 0x12C
    ctx->r1 = SIGNED(ctx->r15) < 0X12C ? 1 : 0;
    // 0x8042C384: bne         $at, $zero, L_8042C390
    if (ctx->r1 != 0) {
        // 0x8042C388: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8042C390;
    }
    // 0x8042C388: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8042C38C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
L_8042C390:
    // 0x8042C390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042C394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042C398: jr          $ra
    // 0x8042C39C: nop

    return;
    // 0x8042C39C: nop

;}
RECOMP_FUNC void func_80068560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068568: jal         0x80072FF0
    // 0x8006856C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80072FF0(rdram, ctx);
        goto after_0;
    // 0x8006856C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068570: jal         0x800684E8
    // 0x80068574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800684E8(rdram, ctx);
        goto after_1;
    // 0x80068574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80068578: jal         0x800675F0
    // 0x8006857C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800675F0(rdram, ctx);
        goto after_2;
    // 0x8006857C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80068580: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068584: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068588: lw          $t6, 0x158($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X158);
    // 0x8006858C: jal         0x800716C0
    // 0x80068590: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
    func_800716C0(rdram, ctx);
        goto after_3;
    // 0x80068590: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
    after_3:
    // 0x80068594: jal         0x800716F8
    // 0x80068598: nop

    func_800716F8(rdram, ctx);
        goto after_4;
    // 0x80068598: nop

    after_4:
    // 0x8006859C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800685A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800685A4: jr          $ra
    // 0x800685A8: nop

    return;
    // 0x800685A8: nop

;}
RECOMP_FUNC void func_8043B624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043B628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043B62C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043B630: jal         0x80045A34
    // 0x8043B634: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8043B634: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8043B638: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043B63C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8043B640: bne         $v0, $zero, L_8043B650
    if (ctx->r2 != 0) {
        // 0x8043B644: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8043B650;
    }
    // 0x8043B644: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8043B648: b           L_8043B660
    // 0x8043B64C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043B660;
    // 0x8043B64C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043B650:
    // 0x8043B650: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8043B654: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043B658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043B65C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_8043B660:
    // 0x8043B660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043B664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043B668: jr          $ra
    // 0x8043B66C: nop

    return;
    // 0x8043B66C: nop

;}
RECOMP_FUNC void func_806FDCA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDCA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FDCA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FDCA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FDCAC: jal         0x80057754
    // 0x806FDCB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80057754(rdram, ctx);
        goto after_0;
    // 0x806FDCB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806FDCB4: jal         0x806FD7F8
    // 0x806FDCB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD7F8(rdram, ctx);
        goto after_1;
    // 0x806FDCB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806FDCBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806FDCC0: bne         $v0, $at, L_806FDCF0
    if (ctx->r2 != ctx->r1) {
        // 0x806FDCC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806FDCF0;
    }
    // 0x806FDCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDCC8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806FDCCC: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x806FDCD0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x806FDCD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDCD8: jal         0x806FE468
    // 0x806FDCDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806FE468(rdram, ctx);
        goto after_2;
    // 0x806FDCDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x806FDCE0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806FDCE4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806FDCE8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806FDCEC: sw          $t6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r14;
L_806FDCF0:
    // 0x806FDCF0: jal         0x806FDA5C
    // 0x806FDCF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FDA5C(rdram, ctx);
        goto after_3;
    // 0x806FDCF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806FDCF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FDCFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FDD00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FDD04: jr          $ra
    // 0x806FDD08: nop

    return;
    // 0x806FDD08: nop

;}
RECOMP_FUNC void func_807AB02C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AB02C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x807AB030: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AB034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AB038: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807AB03C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807AB040: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AB044: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x807AB048: jal         0x807A9D84
    // 0x807AB04C: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    func_807A9D84(rdram, ctx);
        goto after_0;
    // 0x807AB04C: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AB050: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x807AB054: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x807AB058: lwc1        $f6, 0xC0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC0);
    // 0x807AB05C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AB060: swc1        $f8, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->f8.u32l;
    // 0x807AB064: jal         0x807AA878
    // 0x807AB068: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    func_807AA878(rdram, ctx);
        goto after_1;
    // 0x807AB068: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    after_1:
    // 0x807AB06C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x807AB070: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x807AB074: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x807AB078: lw          $v0, 0xD8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XD8);
    // 0x807AB07C: beq         $v0, $zero, L_807AB0B4
    if (ctx->r2 == 0) {
        // 0x807AB080: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807AB0B4;
    }
    // 0x807AB080: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807AB084: bne         $t6, $zero, L_807AB264
    if (ctx->r14 != 0) {
        // 0x807AB088: sw          $t6, 0xD8($a0)
        MEM_W(0XD8, ctx->r4) = ctx->r14;
            goto L_807AB264;
    }
    // 0x807AB088: sw          $t6, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->r14;
    // 0x807AB08C: addiu       $t8, $zero, 0x46
    ctx->r24 = ADD32(0, 0X46);
    // 0x807AB090: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AB094: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x807AB098: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AB09C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x807AB0A0: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x807AB0A4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AB0A8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x807AB0AC: b           L_807AB264
    // 0x807AB0B0: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
        goto L_807AB264;
    // 0x807AB0B0: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
L_807AB0B4:
    // 0x807AB0B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807AB0B8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C30) << 16);
    // 0x807AB0BC: lwc1        $f0, 0xF4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x807AB0C0: lwc1        $f10, -0x4790($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C30));
    // 0x807AB0C4: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x807AB0C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AB0CC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x807AB0D0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x807AB0D4: swc1        $f16, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f16.u32l;
    // 0x807AB0D8: lwc1        $f18, 0xF4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XF4);
    // 0x807AB0DC: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x807AB0E0: nop

    // 0x807AB0E4: bc1fl       L_807AB0F4
    if (!c1cs) {
        // 0x807AB0E8: c.lt.s      $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
            goto L_807AB0F4;
    }
    goto skip_0;
    // 0x807AB0E8: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    skip_0:
    // 0x807AB0EC: swc1        $f12, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f12.u32l;
    // 0x807AB0F0: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
L_807AB0F4:
    // 0x807AB0F4: nop

    // 0x807AB0F8: bc1fl       L_807AB114
    if (!c1cs) {
        // 0x807AB0FC: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_807AB114;
    }
    goto skip_1;
    // 0x807AB0FC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_1:
    // 0x807AB100: jal         0x800447C8
    // 0x807AB104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x807AB104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807AB108: b           L_807AB268
    // 0x807AB10C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807AB268;
    // 0x807AB10C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AB110: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_807AB114:
    // 0x807AB114: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    // 0x807AB118: beq         $v0, $zero, L_807AB128
    if (ctx->r2 == 0) {
        // 0x807AB11C: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_807AB128;
    }
    // 0x807AB11C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x807AB120: b           L_807AB264
    // 0x807AB124: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
        goto L_807AB264;
    // 0x807AB124: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
L_807AB128:
    // 0x807AB128: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x807AB12C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x807AB130: jal         0x80067BBC
    // 0x807AB134: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x807AB134: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x807AB138: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x807AB13C: jal         0x80067818
    // 0x807AB140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x807AB140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x807AB144: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x807AB148: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807AB14C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x807AB150: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x807AB154: nop

    // 0x807AB158: bc1fl       L_807AB268
    if (!c1cs) {
        // 0x807AB15C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807AB268;
    }
    goto skip_2;
    // 0x807AB15C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x807AB160: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807AB164: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x807AB168: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AB16C: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x807AB170: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x807AB174: sw          $t2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r10;
    // 0x807AB178: jal         0x80065954
    // 0x807AB17C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x807AB17C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    after_5:
    // 0x807AB180: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807AB184: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x807AB188: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x807AB18C: nop

    // 0x807AB190: addiu       $t5, $t4, 0x6
    ctx->r13 = ADD32(ctx->r12, 0X6);
    // 0x807AB194: jal         0x800653D8
    // 0x807AB198: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    func_800653D8(rdram, ctx);
        goto after_6;
    // 0x807AB198: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    after_6:
    // 0x807AB19C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x807AB1A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807AB1A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807AB1A8: div         $zero, $v0, $t6
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r14)));
    // 0x807AB1AC: mfhi        $t7
    ctx->r15 = hi;
    // 0x807AB1B0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x807AB1B4: bne         $t6, $zero, L_807AB1C0
    if (ctx->r14 != 0) {
        // 0x807AB1B8: nop
    
            goto L_807AB1C0;
    }
    // 0x807AB1B8: nop

    // 0x807AB1BC: break       7
    do_break(2155524540);
L_807AB1C0:
    // 0x807AB1C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x807AB1C4: bne         $t6, $at, L_807AB1D8
    if (ctx->r14 != ctx->r1) {
        // 0x807AB1C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_807AB1D8;
    }
    // 0x807AB1C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807AB1CC: bne         $v0, $at, L_807AB1D8
    if (ctx->r2 != ctx->r1) {
        // 0x807AB1D0: nop
    
            goto L_807AB1D8;
    }
    // 0x807AB1D0: nop

    // 0x807AB1D4: break       6
    do_break(2155524564);
L_807AB1D8:
    // 0x807AB1D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807AB1DC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x807AB1E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807AB1E4: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x807AB1E8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807AB1EC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x807AB1F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807AB1F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807AB1F8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C34) << 16);
    // 0x807AB1FC: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x807AB200: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x807AB204: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807AB208: lwc1        $f10, -0x478C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C34));
    // 0x807AB20C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807AB210: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x807AB214: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x807AB218: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x807AB21C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807AB220: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C38) << 16);
    // 0x807AB224: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807AB228: lwc1        $f4, -0x4788($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C38));
    // 0x807AB22C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C3C) << 16);
    // 0x807AB230: lwc1        $f6, -0x4784($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C3C));
    // 0x807AB234: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x807AB238: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x807AB23C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x807AB240: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x807AB244: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x807AB248: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x807AB24C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x807AB250: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x807AB254: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x807AB258: lw          $t9, 0x28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X28);
    // 0x807AB25C: jalr        $t9
    // 0x807AB260: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x807AB260: nop

    after_7:
L_807AB264:
    // 0x807AB264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AB268:
    // 0x807AB268: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AB26C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x807AB270: jr          $ra
    // 0x807AB274: nop

    return;
    // 0x807AB274: nop

;}
RECOMP_FUNC void func_80675704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675704: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675708: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8067570C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80675710: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x80675714: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x80675718: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8067571C: jr          $ra
    // 0x80675720: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    return;
    // 0x80675720: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8006D85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D85C: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x8006D860: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006D864: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006D868: or          $s4, $sp, $zero
    ctx->r20 = ctx->r29 | 0;
    // 0x8006D86C: or          $s0, $sp, $zero
    ctx->r16 = ctx->r29 | 0;
    // 0x8006D870: addiu       $s4, $s4, 0x5B
    ctx->r20 = ADD32(ctx->r20, 0X5B);
    // 0x8006D874: addiu       $s0, $s0, 0x7F
    ctx->r16 = ADD32(ctx->r16, 0X7F);
    // 0x8006D878: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006D87C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006D880: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006D884: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006D888: sw          $a0, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r4;
    // 0x8006D88C: srl         $s4, $s4, 3
    ctx->r20 = S32(U32(ctx->r20) >> 3);
    // 0x8006D890: srl         $s0, $s0, 3
    ctx->r16 = S32(U32(ctx->r16) >> 3);
    // 0x8006D894: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8006D898: sll         $s4, $s4, 3
    ctx->r20 = S32(ctx->r20 << 3);
    // 0x8006D89C: lw          $s2, 0x5C($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X5C);
    // 0x8006D8A0: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8006D8A4: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x8006D8A8: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
    // 0x8006D8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006D8B0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8006D8B4: jal         0x800675D0
    // 0x8006D8B8: addiu       $a2, $zero, 0x118
    ctx->r6 = ADD32(0, 0X118);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x8006D8B8: addiu       $a2, $zero, 0x118
    ctx->r6 = ADD32(0, 0X118);
    after_0:
    // 0x8006D8BC: lw          $a0, 0x198($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X198);
    // 0x8006D8C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006D8C4: jal         0x80065528
    // 0x8006D8C8: addiu       $a2, $zero, 0x118
    ctx->r6 = ADD32(0, 0X118);
    func_80065528(rdram, ctx);
        goto after_1;
    // 0x8006D8C8: addiu       $a2, $zero, 0x118
    ctx->r6 = ADD32(0, 0X118);
    after_1:
    // 0x8006D8CC: lw          $t7, 0x198($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X198);
    // 0x8006D8D0: or          $s1, $sp, $zero
    ctx->r17 = ctx->r29 | 0;
    // 0x8006D8D4: addiu       $s1, $s1, 0x6F
    ctx->r17 = ADD32(ctx->r17, 0X6F);
    // 0x8006D8D8: srl         $s1, $s1, 3
    ctx->r17 = S32(U32(ctx->r17) >> 3);
    // 0x8006D8DC: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8006D8E0: sw          $s2, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->r18;
    // 0x8006D8E4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8006D8E8: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x8006D8EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006D8F0: jal         0x800675D0
    // 0x8006D8F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8006D8F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8006D8F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006D8FC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8006D900: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8006D904: jal         0x800675D0
    // 0x8006D908: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800675D0(rdram, ctx);
        goto after_3;
    // 0x8006D908: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8006D90C: jal         0x80064D1C
    // 0x8006D910: addiu       $a0, $zero, 0x708
    ctx->r4 = ADD32(0, 0X708);
    func_80064D1C(rdram, ctx);
        goto after_4;
    // 0x8006D910: addiu       $a0, $zero, 0x708
    ctx->r4 = ADD32(0, 0X708);
    after_4:
    // 0x8006D914: bne         $v0, $zero, L_8006D92C
    if (ctx->r2 != 0) {
        // 0x8006D918: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D92C;
    }
    // 0x8006D918: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D91C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006D920: addiu       $a0, $a0, 0x10C4
    ctx->r4 = ADD32(ctx->r4, 0X10C4);
    // 0x8006D924: jal         0x80071380
    // 0x8006D928: addiu       $a1, $zero, 0x196
    ctx->r5 = ADD32(0, 0X196);
    Fault_HungUp(rdram, ctx);
        goto after_5;
    // 0x8006D928: addiu       $a1, $zero, 0x196
    ctx->r5 = ADD32(0, 0X196);
    after_5:
L_8006D92C:
    // 0x8006D92C: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x8006D930: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006D934: addiu       $a0, $a0, 0x10D4
    ctx->r4 = ADD32(ctx->r4, 0X10D4);
    // 0x8006D938: slti        $at, $v0, 0x96
    ctx->r1 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x8006D93C: bnel        $at, $zero, L_8006D954
    if (ctx->r1 != 0) {
        // 0x8006D940: sll         $a2, $v0, 2
        ctx->r6 = S32(ctx->r2 << 2);
            goto L_8006D954;
    }
    goto skip_0;
    // 0x8006D940: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    skip_0:
    // 0x8006D944: jal         0x80071380
    // 0x8006D948: addiu       $a1, $zero, 0x1A0
    ctx->r5 = ADD32(0, 0X1A0);
    Fault_HungUp(rdram, ctx);
        goto after_6;
    // 0x8006D948: addiu       $a1, $zero, 0x1A0
    ctx->r5 = ADD32(0, 0X1A0);
    after_6:
    // 0x8006D94C: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x8006D950: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
L_8006D954:
    // 0x8006D954: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x8006D958: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8006D95C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8006D960: lw          $a1, 0x4($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X4);
    // 0x8006D964: jal         0x800675D0
    // 0x8006D968: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800675D0(rdram, ctx);
        goto after_7;
    // 0x8006D968: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8006D96C: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x8006D970: addiu       $a1, $zero, 0x960
    ctx->r5 = ADD32(0, 0X960);
    // 0x8006D974: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006D978: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x8006D97C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8006D980: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x8006D984: jal         0x80065728
    // 0x8006D988: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_8;
    // 0x8006D988: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_8:
    // 0x8006D98C: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x8006D990: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8006D994: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D998: blez        $v0, L_8006D9D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006D99C: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_8006D9D0;
    }
    // 0x8006D99C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8006D9A0: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
L_8006D9A4:
    // 0x8006D9A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006D9A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006D9AC: jal         0x80065528
    // 0x8006D9B0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80065528(rdram, ctx);
        goto after_9;
    // 0x8006D9B0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_9:
    // 0x8006D9B4: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
    // 0x8006D9B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006D9BC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8006D9C0: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8006D9C4: bne         $at, $zero, L_8006D9A4
    if (ctx->r1 != 0) {
        // 0x8006D9C8: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_8006D9A4;
    }
    // 0x8006D9C8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x8006D9CC: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
L_8006D9D0:
    // 0x8006D9D0: lw          $t2, 0x198($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X198);
    // 0x8006D9D4: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x8006D9D8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006D9DC: sh          $v0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r2;
    // 0x8006D9E0: jal         0x80064E84
    // 0x8006D9E4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_80064E84(rdram, ctx);
        goto after_10;
    // 0x8006D9E4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_10:
    // 0x8006D9E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D9EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006D9F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D9F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006D9F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006D9FC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006DA00: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    // 0x8006DA04: jr          $ra
    // 0x8006DA08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006DA08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_804D6544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D6544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D6548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D654C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804D6550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804D6554: beq         $t6, $zero, L_804D6590
    if (ctx->r14 == 0) {
        // 0x804D6558: nop
    
            goto L_804D6590;
    }
    // 0x804D6558: nop

    // 0x804D655C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D6560: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804D6564: jalr        $t9
    // 0x804D6568: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804D6568: nop

    after_0:
    // 0x804D656C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D6570: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804D6574: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804D6578: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804D657C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804D6580: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804D6584: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804D6588: b           L_804D6590
    // 0x804D658C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804D6590;
    // 0x804D658C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804D6590:
    // 0x804D6590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D6594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D6598: jr          $ra
    // 0x804D659C: nop

    return;
    // 0x804D659C: nop

;}
RECOMP_FUNC void func_806E4C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E4C58: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806E4C5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E4C60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E4C64: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E4C68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E4C6C: jal         0x8004700C
    // 0x806E4C70: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806E4C70: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x806E4C74: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x806E4C78: jal         0x806E3DD0
    // 0x806E4C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E3DD0(rdram, ctx);
        goto after_1;
    // 0x806E4C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806E4C80: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x806E4C84: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x806E4C88: beql        $t6, $zero, L_806E4E74
    if (ctx->r14 == 0) {
        // 0x806E4C8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E4E74;
    }
    goto skip_0;
    // 0x806E4C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806E4C90: lw          $t7, 0x58($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X58);
    // 0x806E4C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4C98: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x806E4C9C: bne         $t7, $zero, L_806E4E70
    if (ctx->r15 != 0) {
        // 0x806E4CA0: addiu       $a2, $zero, 0x140
        ctx->r6 = ADD32(0, 0X140);
            goto L_806E4E70;
    }
    // 0x806E4CA0: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x806E4CA4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x806E4CA8: jal         0x80047534
    // 0x806E4CAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80047534(rdram, ctx);
        goto after_2;
    // 0x806E4CAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x806E4CB0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x806E4CB4: bne         $v0, $zero, L_806E4E70
    if (ctx->r2 != 0) {
        // 0x806E4CB8: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_806E4E70;
    }
    // 0x806E4CB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806E4CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4CC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E4CC4: jal         0x800474D8
    // 0x806E4CC8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800474D8(rdram, ctx);
        goto after_3;
    // 0x806E4CC8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_3:
    // 0x806E4CCC: bne         $v0, $zero, L_806E4E70
    if (ctx->r2 != 0) {
        // 0x806E4CD0: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_806E4E70;
    }
    // 0x806E4CD0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x806E4CD4: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x806E4CD8: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x806E4CDC: beq         $v0, $zero, L_806E4CEC
    if (ctx->r2 == 0) {
        // 0x806E4CE0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_806E4CEC;
    }
    // 0x806E4CE0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x806E4CE4: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
    // 0x806E4CE8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_806E4CEC:
    // 0x806E4CEC: bnel        $v0, $zero, L_806E4D70
    if (ctx->r2 != 0) {
        // 0x806E4CF0: lw          $v0, 0x68($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X68);
            goto L_806E4D70;
    }
    goto skip_1;
    // 0x806E4CF0: lw          $v0, 0x68($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X68);
    skip_1:
    // 0x806E4CF4: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x806E4CF8: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(649, 0X1D58) << 16);
    // 0x806E4CFC: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
    // 0x806E4D00: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x806E4D04: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E4D08: lw          $t1, 0x5558($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(649, 0X1D58));
    // 0x806E4D0C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x806E4D10: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x806E4D14: sw          $t2, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r10;
    // 0x806E4D18: bne         $at, $zero, L_806E4D6C
    if (ctx->r1 != 0) {
        // 0x806E4D1C: sw          $t1, 0x3C($v1)
        MEM_W(0X3C, ctx->r3) = ctx->r9;
            goto L_806E4D6C;
    }
    // 0x806E4D1C: sw          $t1, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r9;
    // 0x806E4D20: lw          $t4, 0x48($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X48);
    // 0x806E4D24: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E4D28: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x806E4D2C: sw          $t5, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r13;
    // 0x806E4D30: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806E4D34: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806E4D38: jal         0x80067BBC
    // 0x806E4D3C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806E4D3C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_4:
    // 0x806E4D40: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    // 0x806E4D44: jal         0x80067818
    // 0x806E4D48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806E4D48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806E4D4C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x806E4D50: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x806E4D54: lw          $t6, 0x48($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X48);
    // 0x806E4D58: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x806E4D5C: bnel        $at, $zero, L_806E4D70
    if (ctx->r1 != 0) {
        // 0x806E4D60: lw          $v0, 0x68($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X68);
            goto L_806E4D70;
    }
    goto skip_2;
    // 0x806E4D60: lw          $v0, 0x68($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X68);
    skip_2:
    // 0x806E4D64: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    // 0x806E4D68: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
L_806E4D6C:
    // 0x806E4D6C: lw          $v0, 0x68($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X68);
L_806E4D70:
    // 0x806E4D70: beq         $v0, $zero, L_806E4D7C
    if (ctx->r2 == 0) {
        // 0x806E4D74: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_806E4D7C;
    }
    // 0x806E4D74: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x806E4D78: sw          $t8, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r24;
L_806E4D7C:
    // 0x806E4D7C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x806E4D80: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806E4D84: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x806E4D88: lwc1        $f2, 0x84($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806E4D8C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806E4D90: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x806E4D94: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E4D98: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x806E4D9C: nop

    // 0x806E4DA0: bc1fl       L_806E4E3C
    if (!c1cs) {
        // 0x806E4DA4: lwc1        $f10, 0x84($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
            goto L_806E4E3C;
    }
    goto skip_3;
    // 0x806E4DA4: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    skip_3:
    // 0x806E4DA8: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x806E4DAC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806E4DB0: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806E4DB4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E4DB8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x806E4DBC: nop

    // 0x806E4DC0: bc1fl       L_806E4E3C
    if (!c1cs) {
        // 0x806E4DC4: lwc1        $f10, 0x84($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
            goto L_806E4E3C;
    }
    goto skip_4;
    // 0x806E4DC4: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    skip_4:
    // 0x806E4DC8: lw          $t9, 0x68($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X68);
    // 0x806E4DCC: bnel        $t9, $zero, L_806E4E3C
    if (ctx->r25 != 0) {
        // 0x806E4DD0: lwc1        $f10, 0x84($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
            goto L_806E4E3C;
    }
    goto skip_5;
    // 0x806E4DD0: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    skip_5:
    // 0x806E4DD4: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
    // 0x806E4DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4DDC: slti        $at, $t0, 0x17
    ctx->r1 = SIGNED(ctx->r8) < 0X17 ? 1 : 0;
    // 0x806E4DE0: beql        $at, $zero, L_806E4E74
    if (ctx->r1 == 0) {
        // 0x806E4DE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E4E74;
    }
    goto skip_6;
    // 0x806E4DE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x806E4DE8: jal         0x806E4144
    // 0x806E4DEC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_806E4144(rdram, ctx);
        goto after_6;
    // 0x806E4DEC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_6:
    // 0x806E4DF0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x806E4DF4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806E4DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4DFC: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x806E4E00: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
    // 0x806E4E04: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x806E4E08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4E0C: bne         $t1, $zero, L_806E4E28
    if (ctx->r9 != 0) {
        // 0x806E4E10: nop
    
            goto L_806E4E28;
    }
    // 0x806E4E10: nop

    // 0x806E4E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4E18: jal         0x806E511C
    // 0x806E4E1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806E511C(rdram, ctx);
        goto after_7;
    // 0x806E4E1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x806E4E20: b           L_806E4E74
    // 0x806E4E24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806E4E74;
    // 0x806E4E24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E4E28:
    // 0x806E4E28: jal         0x806E511C
    // 0x806E4E2C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806E511C(rdram, ctx);
        goto after_8;
    // 0x806E4E2C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x806E4E30: b           L_806E4E74
    // 0x806E4E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806E4E74;
    // 0x806E4E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806E4E38: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
L_806E4E3C:
    // 0x806E4E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806E4E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4E44: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x806E4E48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4E4C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806E4E50: bc1fl       L_806E4E60
    if (!c1cs) {
        // 0x806E4E54: lw          $t2, 0x138($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X138);
            goto L_806E4E60;
    }
    goto skip_7;
    // 0x806E4E54: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    skip_7:
    // 0x806E4E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806E4E5C: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
L_806E4E60:
    // 0x806E4E60: beql        $v0, $t2, L_806E4E74
    if (ctx->r2 == ctx->r10) {
        // 0x806E4E64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E4E74;
    }
    goto skip_8;
    // 0x806E4E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x806E4E68: jal         0x806E511C
    // 0x806E4E6C: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    func_806E511C(rdram, ctx);
        goto after_9;
    // 0x806E4E6C: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    after_9:
L_806E4E70:
    // 0x806E4E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E4E74:
    // 0x806E4E74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E4E78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806E4E7C: jr          $ra
    // 0x806E4E80: nop

    return;
    // 0x806E4E80: nop

;}
RECOMP_FUNC void func_805D1974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1974: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805D1978: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805D197C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805D1980: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805D1984: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805D1988: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805D198C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805D1990: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805D1994: lui         $t1, 0x805D
    ctx->r9 = S32(RELOC_HI16(468, 0X2A8) << 16);
    // 0x805D1998: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805D199C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D19A0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D19A4: lw          $t1, 0x19B8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(468, 0X2A8));
    // 0x805D19A8: jr          $ra
    // 0x805D19AC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805D19AC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8046075C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046075C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460764: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80460768: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8046076C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80460770: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3648) << 16);
    // 0x80460774: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80460778: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8046077C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80460780: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80460784: lw          $t8, 0x3BD8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X3648));
    // 0x80460788: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8046078C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80460790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80460794: jal         0x80048490
    // 0x80460798: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80460798: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8046079C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804607A0: jal         0x80048378
    // 0x804607A4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804607A4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804607A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804607AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804607B0: jr          $ra
    // 0x804607B4: nop

    return;
    // 0x804607B4: nop

;}
RECOMP_FUNC void func_80475840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475840: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475844: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475848: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047584C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475850: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475854: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475858: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047585C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475860: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475864: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475868: jr          $ra
    // 0x8047586C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047586C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804D87D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D87D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804D87D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804D87DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804D87E0: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804D87E4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804D87E8: lui         $t7, 0x804E
    ctx->r15 = S32(RELOC_HI16(255, 0X7AC) << 16);
    // 0x804D87EC: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804D87F0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804D87F4: addiu       $t7, $t7, -0x7524
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(255, 0X7AC));
    // 0x804D87F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804D87FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804D8800: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804D8804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D8808: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804D880C: jal         0x804D8878
    // 0x804D8810: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804D8878(rdram, ctx);
        goto after_0;
    // 0x804D8810: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804D8814: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804D8818: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804D881C: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x804D8820: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804D8824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804D8828: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804D882C: jal         0x804D87BC
    // 0x804D8830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804D87BC(rdram, ctx);
        goto after_1;
    // 0x804D8830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804D8834: jal         0x800653D8
    // 0x804D8838: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x804D8838: nop

    after_2:
    // 0x804D883C: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x804D8840: sh          $t1, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r9;
    // 0x804D8844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804D8848: jal         0x80045A34
    // 0x804D884C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_3;
    // 0x804D884C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x804D8850: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x804D8854: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804D8858: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804D885C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x804D8860: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804D8864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804D8868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804D886C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804D8870: jr          $ra
    // 0x804D8874: nop

    return;
    // 0x804D8874: nop

;}
RECOMP_FUNC void func_807B73B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B73B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807B73B4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x807B73B8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807B73BC: lui         $t7, 0x807B
    ctx->r15 = S32(RELOC_HI16(880, 0X2EAC) << 16);
    // 0x807B73C0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807B73C4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x807B73C8: lw          $t7, 0x76AC($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(880, 0X2EAC));
    // 0x807B73CC: jr          $ra
    // 0x807B73D0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x807B73D0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80435C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435C30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80435C34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80435C38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80435C3C: jal         0x80435B50
    // 0x80435C40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80435B50(rdram, ctx);
        goto after_0;
    // 0x80435C40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80435C44: jal         0x8043535C
    // 0x80435C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043535C(rdram, ctx);
        goto after_1;
    // 0x80435C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80435C4C: jal         0x80435328
    // 0x80435C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80435328(rdram, ctx);
        goto after_2;
    // 0x80435C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80435C54: jal         0x80435470
    // 0x80435C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80435470(rdram, ctx);
        goto after_3;
    // 0x80435C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80435C5C: jal         0x804355DC
    // 0x80435C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804355DC(rdram, ctx);
        goto after_4;
    // 0x80435C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80435C64: jal         0x80435748
    // 0x80435C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80435748(rdram, ctx);
        goto after_5;
    // 0x80435C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80435C6C: jal         0x804358AC
    // 0x80435C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804358AC(rdram, ctx);
        goto after_6;
    // 0x80435C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80435C74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80435C78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80435C7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80435C80: jr          $ra
    // 0x80435C84: nop

    return;
    // 0x80435C84: nop

;}
RECOMP_FUNC void func_8046A36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A36C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046A370: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046A374: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046A378: jal         0x8004700C
    // 0x8046A37C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046A37C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046A380: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8046A384: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046A388: beq         $v0, $zero, L_8046A410
    if (ctx->r2 == 0) {
        // 0x8046A38C: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_8046A410;
    }
    // 0x8046A38C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8046A390: jal         0x8046B08C
    // 0x8046A394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046B08C(rdram, ctx);
        goto after_1;
    // 0x8046A394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046A398: jal         0x8046A1F8
    // 0x8046A39C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A1F8(rdram, ctx);
        goto after_2;
    // 0x8046A39C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8046A3A0: jal         0x80469FF4
    // 0x8046A3A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469FF4(rdram, ctx);
        goto after_3;
    // 0x8046A3A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8046A3A8: jal         0x80048378
    // 0x8046A3AC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    func_80048378(rdram, ctx);
        goto after_4;
    // 0x8046A3AC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    after_4:
    // 0x8046A3B0: jal         0x80469F00
    // 0x8046A3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469F00(rdram, ctx);
        goto after_5;
    // 0x8046A3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8046A3B8: beq         $v0, $zero, L_8046A3DC
    if (ctx->r2 == 0) {
        // 0x8046A3BC: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_8046A3DC;
    }
    // 0x8046A3BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8046A3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A3C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046A3C8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8046A3CC: jal         0x8046B2D8
    // 0x8046A3D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_6;
    // 0x8046A3D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8046A3D4: b           L_8046A414
    // 0x8046A3D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046A414;
    // 0x8046A3D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046A3DC:
    // 0x8046A3DC: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x8046A3E0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8046A3E4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8046A3E8: bne         $s0, $t8, L_8046A410
    if (ctx->r16 != ctx->r24) {
        // 0x8046A3EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8046A410;
    }
    // 0x8046A3EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046A3F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046A3F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8046A3F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046A3FC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8046A400: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8046A404: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8046A408: jal         0x8046B2D8
    // 0x8046A40C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    func_8046B2D8(rdram, ctx);
        goto after_7;
    // 0x8046A40C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    after_7:
L_8046A410:
    // 0x8046A410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046A414:
    // 0x8046A414: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046A418: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046A41C: jr          $ra
    // 0x8046A420: nop

    return;
    // 0x8046A420: nop

;}
RECOMP_FUNC void func_80567088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8056708C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80567090: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80567094: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(375, 0XCD0) << 16);
    // 0x80567098: addiu       $t8, $t8, 0x7220
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(375, 0XCD0));
    // 0x8056709C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805670A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805670A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805670A8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x805670AC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805670B0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805670B4: beql        $v1, $zero, L_805670E8
    if (ctx->r3 == 0) {
        // 0x805670B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805670E8;
    }
    goto skip_0;
    // 0x805670B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805670BC: jalr        $v1
    // 0x805670C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805670C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805670C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805670C8: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x805670CC: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x805670D0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x805670D4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x805670D8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x805670DC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x805670E0: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x805670E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805670E8:
    // 0x805670E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805670EC: jr          $ra
    // 0x805670F0: nop

    return;
    // 0x805670F0: nop

;}
RECOMP_FUNC void func_8067C074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067C074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067C078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067C07C: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8067C080: lui         $a3, 0x8067
    ctx->r7 = S32(0X8067 << 16);
    // 0x8067C084: lui         $a1, 0x8068
    ctx->r5 = S32(RELOC_HI16(541, 0X1EE4) << 16);
    // 0x8067C088: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8067C08C: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x8067C090: addiu       $t8, $zero, 0x34
    ctx->r24 = ADD32(0, 0X34);
    // 0x8067C094: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8067C098: lw          $a3, -0x40E0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X40E0);
    // 0x8067C09C: addiu       $a1, $a1, -0x446C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(541, 0X1EE4));
    // 0x8067C0A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067C0A4: jal         0x8067BF84
    // 0x8067C0A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8067BF84(rdram, ctx);
        goto after_0;
    // 0x8067C0A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8067C0AC: beq         $v0, $zero, L_8067C0D4
    if (ctx->r2 == 0) {
        // 0x8067C0B0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8067C0D4;
    }
    // 0x8067C0B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067C0B4: jal         0x8067BEDC
    // 0x8067C0B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8067BEDC(rdram, ctx);
        goto after_1;
    // 0x8067C0B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8067C0BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067C0C0: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X2284) << 16);
    // 0x8067C0C4: addiu       $t9, $t9, -0x40CC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(541, 0X2284));
    // 0x8067C0C8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8067C0CC: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x8067C0D0: sh          $t0, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r8;
L_8067C0D4:
    // 0x8067C0D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067C0D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067C0DC: jr          $ra
    // 0x8067C0E0: nop

    return;
    // 0x8067C0E0: nop

;}
RECOMP_FUNC void func_805ADFC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADFC4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADFC8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADFCC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADFD0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADFD4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADFD8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADFDC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADFE0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADFE4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADFE8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADFEC: jr          $ra
    // 0x805ADFF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADFF0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80010520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010528: jal         0x80007B8C
    // 0x8001052C: nop

    func_80007B8C(rdram, ctx);
        goto after_0;
    // 0x8001052C: nop

    after_0:
    // 0x80010530: jal         0x80018F90
    // 0x80010534: nop

    func_80018F90(rdram, ctx);
        goto after_1;
    // 0x80010534: nop

    after_1:
    // 0x80010538: jal         0x80011360
    // 0x8001053C: nop

    func_80011360(rdram, ctx);
        goto after_2;
    // 0x8001053C: nop

    after_2:
    // 0x80010540: jal         0x80011A1C
    // 0x80010544: nop

    func_80011A1C(rdram, ctx);
        goto after_3;
    // 0x80010544: nop

    after_3:
    // 0x80010548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001054C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010550: jr          $ra
    // 0x80010554: nop

    return;
    // 0x80010554: nop

;}
RECOMP_FUNC void func_807ADC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADC10: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807ADC14: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807ADC18: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807ADC1C: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x807ADC20: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
    // 0x807ADC24: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807ADC28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807ADC2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807ADC30: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
    // 0x807ADC34: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807ADC38: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807ADC3C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x807ADC40: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x807ADC44: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807ADC48: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807ADC4C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807ADC50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807ADC54: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807ADC58: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x807ADC5C: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x807ADC60: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807ADC64: lwc1        $f8, 0x28($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X28);
    // 0x807ADC68: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x807ADC6C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807ADC70: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807ADC74: lwc1        $f16, 0x0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X0);
    // 0x807ADC78: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x807ADC7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807ADC80: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x807ADC84: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x807ADC88: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x807ADC8C: nop

    // 0x807ADC90: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x807ADC94: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x807ADC98: mul.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x807ADC9C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807ADCA0: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x807ADCA4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807ADCA8: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    // 0x807ADCAC: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x807ADCB0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x807ADCB4: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x807ADCB8: nop

    // 0x807ADCBC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807ADCC0: jr          $ra
    // 0x807ADCC4: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x807ADCC4: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80430B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430B78: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80430B7C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80430B80: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X3A54) << 16);
    // 0x80430B84: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80430B88: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80430B8C: lw          $t8, 0x1B34($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X3A54));
    // 0x80430B90: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80430B94: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80430B98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80430B9C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80430BA0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80430BA4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80430BA8: beql        $v1, $zero, L_80430BDC
    if (ctx->r3 == 0) {
        // 0x80430BAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80430BDC;
    }
    goto skip_0;
    // 0x80430BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80430BB0: jalr        $v1
    // 0x80430BB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80430BB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430BB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80430BBC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80430BC0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80430BC4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80430BC8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80430BCC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80430BD0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80430BD4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80430BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80430BDC:
    // 0x80430BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430BE0: jr          $ra
    // 0x80430BE4: nop

    return;
    // 0x80430BE4: nop

;}
RECOMP_FUNC void func_80069964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006996C: jal         0x80069C10
    // 0x80069970: nop

    func_80069C10(rdram, ctx);
        goto after_0;
    // 0x80069970: nop

    after_0:
    // 0x80069974: jal         0x800697F0
    // 0x80069978: nop

    func_800697F0(rdram, ctx);
        goto after_1;
    // 0x80069978: nop

    after_1:
    // 0x8006997C: beq         $v0, $zero, L_8006999C
    if (ctx->r2 == 0) {
        // 0x80069980: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_8006999C;
    }
    // 0x80069980: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069984: addiu       $a0, $a0, -0x71A8
    ctx->r4 = ADD32(ctx->r4, -0X71A8);
    // 0x80069988: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8006998C: jal         0x80065728
    // 0x80069990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80069990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80069994: jal         0x80069900
    // 0x80069998: nop

    func_80069900(rdram, ctx);
        goto after_3;
    // 0x80069998: nop

    after_3:
L_8006999C:
    // 0x8006999C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800699A0: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    // 0x800699A4: jal         0x800694BC
    // 0x800699A8: srl         $a0, $a0, 30
    ctx->r4 = S32(U32(ctx->r4) >> 30);
    func_800694BC(rdram, ctx);
        goto after_4;
    // 0x800699A8: srl         $a0, $a0, 30
    ctx->r4 = S32(U32(ctx->r4) >> 30);
    after_4:
    // 0x800699AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800699B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800699B4: jr          $ra
    // 0x800699B8: nop

    return;
    // 0x800699B8: nop

;}
RECOMP_FUNC void func_805E43E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E43E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E43EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E43F0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805E43F4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x805E43F8: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(486, 0XF3C) << 16);
    // 0x805E43FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805E4400: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805E4404: lw          $t8, 0x507C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(486, 0XF3C));
    // 0x805E4408: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805E440C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805E4410: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x805E4414: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x805E4418: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805E441C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805E4420: beql        $v1, $zero, L_805E4454
    if (ctx->r3 == 0) {
        // 0x805E4424: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805E4454;
    }
    goto skip_0;
    // 0x805E4424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805E4428: jalr        $v1
    // 0x805E442C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805E442C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E4434: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x805E4438: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x805E443C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x805E4440: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x805E4444: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805E4448: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x805E444C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x805E4450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805E4454:
    // 0x805E4454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4458: jr          $ra
    // 0x805E445C: nop

    return;
    // 0x805E445C: nop

;}
RECOMP_FUNC void func_80567FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567FD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80567FDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80567FE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80567FE4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80567FE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80567FEC: jal         0x8004700C
    // 0x80567FF0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80567FF0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80567FF4: beq         $v0, $zero, L_80568070
    if (ctx->r2 == 0) {
        // 0x80567FF8: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80568070;
    }
    // 0x80567FF8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80567FFC: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x80568000: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80568004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80568008: bne         $s0, $t6, L_80568068
    if (ctx->r16 != ctx->r14) {
        // 0x8056800C: nop
    
            goto L_80568068;
    }
    // 0x8056800C: nop

    // 0x80568010: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80568014: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80568018: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21A4) << 16);
    // 0x8056801C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80568020: lwc1        $f6, -0x68AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21A4));
    // 0x80568024: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80568028: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x8056802C: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x80568030: beql        $t7, $zero, L_8056804C
    if (ctx->r15 == 0) {
        // 0x80568034: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8056804C;
    }
    goto skip_0;
    // 0x80568034: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x80568038: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8056803C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568040: b           L_80568054
    // 0x80568044: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
        goto L_80568054;
    // 0x80568044: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x80568048: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8056804C:
    // 0x8056804C: nop

    // 0x80568050: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
L_80568054:
    // 0x80568054: jal         0x80048F84
    // 0x80568058: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80568058: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    after_1:
    // 0x8056805C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80568060: jal         0x80569310
    // 0x80568064: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80568064: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
L_80568068:
    // 0x80568068: jal         0x80567E60
    // 0x8056806C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80567E60(rdram, ctx);
        goto after_3;
    // 0x8056806C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80568070:
    // 0x80568070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80568074: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80568078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8056807C: jr          $ra
    // 0x80568080: nop

    return;
    // 0x80568080: nop

;}
RECOMP_FUNC void func_8006E778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E778: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E77C: addiu       $v0, $v0, -0x1878
    ctx->r2 = ADD32(ctx->r2, -0X1878);
    // 0x8006E780: jr          $ra
    // 0x8006E784: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006E784: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80798970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80798974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798978: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8079897C: beq         $v0, $zero, L_8079898C
    if (ctx->r2 == 0) {
        // 0x80798980: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8079898C;
    }
    // 0x80798980: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80798984: b           L_80798994
    // 0x80798988: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_80798994;
    // 0x80798988: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8079898C:
    // 0x8079898C: jal         0x800447C8
    // 0x80798990: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80798990: nop

    after_0:
L_80798994:
    // 0x80798994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079899C: jr          $ra
    // 0x807989A0: nop

    return;
    // 0x807989A0: nop

;}
RECOMP_FUNC void func_807AF954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AF958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF95C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807AF960: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x807AF964: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x807AF968: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AF96C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807AF970: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AF974: jal         0x807AFA3C
    // 0x807AF978: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807AFA3C(rdram, ctx);
        goto after_0;
    // 0x807AF978: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807AF97C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AF980: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807AF984: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807AF988: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807AF98C: jal         0x807AF8BC
    // 0x807AF990: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    func_807AF8BC(rdram, ctx);
        goto after_1;
    // 0x807AF990: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    after_1:
    // 0x807AF994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AF998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AF99C: jr          $ra
    // 0x807AF9A0: nop

    return;
    // 0x807AF9A0: nop

;}
RECOMP_FUNC void func_80022FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022FE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022FE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80022FEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80022FF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022FF4: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80022FF8: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x80022FFC: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80023000: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x80023004: lwc1        $f6, -0x334($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X334);
    // 0x80023008: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002300C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023010: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x80023014: jr          $ra
    // 0x80023018: swc1        $f8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80023018: swc1        $f8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8067BF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BF84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067BF88: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8067BF8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067BF90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067BF94: jal         0x8067BE38
    // 0x8067BF98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8067BE38(rdram, ctx);
        goto after_0;
    // 0x8067BF98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8067BF9C: bne         $v0, $zero, L_8067BFAC
    if (ctx->r2 != 0) {
        // 0x8067BFA0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8067BFAC;
    }
    // 0x8067BFA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067BFA4: b           L_8067C010
    // 0x8067BFA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8067C010;
    // 0x8067BFA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8067BFAC:
    // 0x8067BFAC: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x8067BFB0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8067BFB4: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(541, 0X2650) << 16);
    // 0x8067BFB8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8067BFBC: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x8067BFC0: addiu       $t8, $t8, -0x3D00
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(541, 0X2650));
    // 0x8067BFC4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8067BFC8: lui         $t0, 0x8068
    ctx->r8 = S32(RELOC_HI16(541, 0X208C) << 16);
    // 0x8067BFCC: addiu       $t0, $t0, -0x42C4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(541, 0X208C));
    // 0x8067BFD0: sb          $zero, 0x18($a0)
    MEM_B(0X18, ctx->r4) = 0;
    // 0x8067BFD4: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8067BFD8: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x8067BFDC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3D90) << 16);
    // 0x8067BFE0: lwc1        $f4, -0x25C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3D90));
    // 0x8067BFE4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8067BFE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067BFEC: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8067BFF0: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x8067BFF4: sw          $t1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r9;
    // 0x8067BFF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8067BFFC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8067C000: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x8067C004: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x8067C008: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x8067C00C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8067C010:
    // 0x8067C010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067C014: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067C018: jr          $ra
    // 0x8067C01C: nop

    return;
    // 0x8067C01C: nop

;}
RECOMP_FUNC void func_80077010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077010: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80077014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077018: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007701C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80077020: jal         0x80076DB8
    // 0x80077024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80076DB8(rdram, ctx);
        goto after_0;
    // 0x80077024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80077028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007702C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80077030: jr          $ra
    // 0x80077034: nop

    return;
    // 0x80077034: nop

;}
RECOMP_FUNC void func_8005FE48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FE48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FE4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FE50: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8005FE54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FE58: beql        $v1, $zero, L_8005FEB0
    if (ctx->r3 == 0) {
        // 0x8005FE5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FEB0;
    }
    goto skip_0;
    // 0x8005FE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FE60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FE64: lbu         $t6, 0x74($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X74);
    // 0x8005FE68: beql        $t6, $zero, L_8005FE8C
    if (ctx->r14 == 0) {
        // 0x8005FE6C: lbu         $t7, 0x78($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X78);
            goto L_8005FE8C;
    }
    goto skip_1;
    // 0x8005FE6C: lbu         $t7, 0x78($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X78);
    skip_1:
    // 0x8005FE70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8005FE74: jal         0x8005FD1C
    // 0x8005FE78: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x8005FE78: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005FE7C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FE80: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8005FE84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FE88: lbu         $t7, 0x78($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X78);
L_8005FE8C:
    // 0x8005FE8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005FE90: beql        $t7, $zero, L_8005FEB0
    if (ctx->r15 == 0) {
        // 0x8005FE94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FEB0;
    }
    goto skip_2;
    // 0x8005FE94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8005FE98: jal         0x8005F9F4
    // 0x8005FE9C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005F9F4(rdram, ctx);
        goto after_1;
    // 0x8005FE9C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8005FEA0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FEA4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8005FEA8: sb          $zero, 0x78($t8)
    MEM_B(0X78, ctx->r24) = 0;
    // 0x8005FEAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FEB0:
    // 0x8005FEB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FEB4: jr          $ra
    // 0x8005FEB8: nop

    return;
    // 0x8005FEB8: nop

;}
