#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80044B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044B84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80044B88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80044B8C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80044B90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80044B94: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044B98: bne         $t6, $zero, L_80044BB0
    if (ctx->r14 != 0) {
        // 0x80044B9C: addiu       $a0, $a0, 0x5D8
        ctx->r4 = ADD32(ctx->r4, 0X5D8);
            goto L_80044BB0;
    }
    // 0x80044B9C: addiu       $a0, $a0, 0x5D8
    ctx->r4 = ADD32(ctx->r4, 0X5D8);
    // 0x80044BA0: jal         0x80071380
    // 0x80044BA4: addiu       $a1, $zero, 0x657
    ctx->r5 = ADD32(0, 0X657);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80044BA4: addiu       $a1, $zero, 0x657
    ctx->r5 = ADD32(0, 0X657);
    after_0:
    // 0x80044BA8: b           L_80044C44
    // 0x80044BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044C44;
    // 0x80044BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80044BB0:
    // 0x80044BB0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80044BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80044BB8: jalr        $t9
    // 0x80044BBC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80044BBC: nop

    after_1:
    // 0x80044BC0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80044BC4: lw          $v0, 0x550($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X550);
    // 0x80044BC8: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80044BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80044BD0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80044BD4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80044BD8: lw          $t9, 0x554($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X554);
    // 0x80044BDC: jalr        $t9
    // 0x80044BE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80044BE0: nop

    after_2:
    // 0x80044BE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044BE8: sw          $v0, -0x7EAC($at)
    MEM_W(-0X7EAC, ctx->r1) = ctx->r2;
    // 0x80044BEC: jal         0x800451F0
    // 0x80044BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800451F0(rdram, ctx);
        goto after_3;
    // 0x80044BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80044BF4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80044BF8: lw          $t8, -0x7EAC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7EAC);
    // 0x80044BFC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80044C00: bne         $t8, $zero, L_80044C10
    if (ctx->r24 != 0) {
        // 0x80044C04: nop
    
            goto L_80044C10;
    }
    // 0x80044C04: nop

    // 0x80044C08: b           L_80044C44
    // 0x80044C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044C44;
    // 0x80044C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80044C10:
    // 0x80044C10: lw          $v0, 0x550($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X550);
    // 0x80044C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80044C18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80044C1C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80044C20: beq         $at, $zero, L_80044C34
    if (ctx->r1 == 0) {
        // 0x80044C24: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_80044C34;
    }
    // 0x80044C24: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80044C28: sw          $v0, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r2;
    // 0x80044C2C: b           L_80044C44
    // 0x80044C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80044C44;
    // 0x80044C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80044C34:
    // 0x80044C34: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80044C38: jal         0x800442E0
    // 0x80044C3C: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
    func_800442E0(rdram, ctx);
        goto after_4;
    // 0x80044C3C: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
    after_4:
    // 0x80044C40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80044C44:
    // 0x80044C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80044C48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044C50: jr          $ra
    // 0x80044C54: nop

    return;
    // 0x80044C54: nop

;}
RECOMP_FUNC void func_80066D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D08: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80066D0C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80066D10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80066D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80066D18: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80066D1C: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80066D20: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
L_80066D24:
    // 0x80066D24: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80066D28: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x80066D2C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80066D30: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80066D34: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80066D38: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x80066D3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80066D40: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80066D44: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80066D48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066D4C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80066D50: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80066D54: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80066D58: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80066D5C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80066D60: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80066D64: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80066D68: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80066D6C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80066D70: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80066D74: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80066D78: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80066D7C: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80066D80: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80066D84: nop

    // 0x80066D88: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80066D8C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80066D90: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80066D94: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80066D98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80066D9C: nop

    // 0x80066DA0: bc1fl       L_80066DC0
    if (!c1cs) {
        // 0x80066DA4: add.s       $f16, $f0, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_80066DC0;
    }
    goto skip_0;
    // 0x80066DA4: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    skip_0:
    // 0x80066DA8: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80066DAC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80066DB0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80066DB4: b           L_80066DD0
    // 0x80066DB8: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
        goto L_80066DD0;
    // 0x80066DB8: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x80066DBC: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
L_80066DC0:
    // 0x80066DC0: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80066DC4: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80066DC8: nop

    // 0x80066DCC: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
L_80066DD0:
    // 0x80066DD0: bne         $v0, $t1, L_80066D24
    if (ctx->r2 != ctx->r9) {
        // 0x80066DD4: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_80066D24;
    }
    // 0x80066DD4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80066DD8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80066DDC: jr          $ra
    // 0x80066DE0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    return;
    // 0x80066DE0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
;}
RECOMP_FUNC void func_8044650C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044650C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446510: jr          $ra
    // 0x80446514: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    return;
    // 0x80446514: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
;}
RECOMP_FUNC void func_804C5D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5D0C: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804C5D10: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(215, 0X4D4) << 16);
    // 0x804C5D14: addiu       $t8, $t8, 0x5EE4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(215, 0X4D4));
    // 0x804C5D18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C5D1C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804C5D20: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804C5D24: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804C5D28: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C5D2C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804C5D30: beql        $v1, $zero, L_804C5D68
    if (ctx->r3 == 0) {
        // 0x804C5D34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C5D68;
    }
    goto skip_0;
    // 0x804C5D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C5D38: jalr        $v1
    // 0x804C5D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804C5D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C5D40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C5D44: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804C5D48: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804C5D4C: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804C5D50: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804C5D54: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804C5D58: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804C5D5C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804C5D60: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804C5D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C5D68:
    // 0x804C5D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5D6C: jr          $ra
    // 0x804C5D70: nop

    return;
    // 0x804C5D70: nop

    // 0x804C5D74: nop

    // 0x804C5D78: nop

    // 0x804C5D7C: nop

;}
RECOMP_FUNC void func_80048720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048720: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80048724: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x80048728: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x8004872C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80048730: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80048734: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80048738: sltu        $at, $t7, $t0
    ctx->r1 = ctx->r15 < ctx->r8 ? 1 : 0;
    // 0x8004873C: bnel        $at, $zero, L_80048778
    if (ctx->r1 != 0) {
        // 0x80048740: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80048778;
    }
    goto skip_0;
    // 0x80048740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80048744: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80048748: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8004874C: beq         $v0, $zero, L_8004875C
    if (ctx->r2 == 0) {
        // 0x80048750: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_8004875C;
    }
    // 0x80048750: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80048754: b           L_80048774
    // 0x80048758: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_80048774;
    // 0x80048758: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8004875C:
    // 0x8004875C: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x80048760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80048764: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80048768: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8004876C: jr          $ra
    // 0x80048770: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    return;
    // 0x80048770: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80048774:
    // 0x80048774: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80048778:
    // 0x80048778: jr          $ra
    // 0x8004877C: nop

    return;
    // 0x8004877C: nop

;}
RECOMP_FUNC void func_806ED360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ED364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806ED368: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806ED36C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806ED370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ED374: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806ED378: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x806ED37C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806ED380: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806ED384: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806ED388: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806ED38C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806ED390: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(676, 0X45BC) << 16);
    // 0x806ED394: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806ED398: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806ED39C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806ED3A0: lw          $t2, 0x50C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(676, 0X45BC));
    // 0x806ED3A4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806ED3A8: jal         0x806ED114
    // 0x806ED3AC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_806ED114(rdram, ctx);
        goto after_0;
    // 0x806ED3AC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x806ED3B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ED3B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ED3B8: jr          $ra
    // 0x806ED3BC: nop

    return;
    // 0x806ED3BC: nop

;}
RECOMP_FUNC void Fault_PrintStackTrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070CA0: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x80070CA4: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x80070CA8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80070CAC: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_80070CB0:
    // 0x80070CB0: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x80070CB4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80070CB8: bne         $t9, $sp, L_80070CB0
    if (ctx->r25 != ctx->r29) {
        // 0x80070CBC: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_80070CB0;
    }
    // 0x80070CBC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80070CC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80070CC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80070CC8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80070CCC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80070CD0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80070CD4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80070CD8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80070CDC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80070CE0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80070CE4: lw          $s1, 0xF4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0XF4);
    // 0x80070CE8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80070CEC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80070CF0: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    // 0x80070CF4: jal         0x8006F600
    // 0x80070CF8: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    Fault_DrawRec(rdram, ctx);
        goto after_0;
    // 0x80070CF8: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    after_0:
    // 0x80070CFC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070D00: addiu       $a2, $a2, 0x18EC
    ctx->r6 = ADD32(ctx->r6, 0X18EC);
    // 0x80070D04: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80070D08: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80070D0C: jal         0x8006F884
    // 0x80070D10: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x80070D10: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x80070D14: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x80070D18: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x80070D1C: addiu       $s3, $s3, 0x1908
    ctx->r19 = ADD32(ctx->r19, 0X1908);
    // 0x80070D20: addiu       $s5, $s5, 0x1900
    ctx->r21 = ADD32(ctx->r21, 0X1900);
    // 0x80070D24: addiu       $s2, $zero, 0x1C
    ctx->r18 = ADD32(0, 0X1C);
    // 0x80070D28: addiu       $s6, $zero, 0xE2
    ctx->r22 = ADD32(0, 0XE2);
    // 0x80070D2C: addiu       $s4, $zero, 0x122
    ctx->r20 = ADD32(0, 0X122);
    // 0x80070D30: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
L_80070D34:
    // 0x80070D34: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80070D38: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80070D3C: jal         0x8006F884
    // 0x80070D40: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    Fault_Printf(rdram, ctx);
        goto after_2;
    // 0x80070D40: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_2:
    // 0x80070D44: addiu       $s0, $zero, 0x52
    ctx->r16 = ADD32(0, 0X52);
    // 0x80070D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80070D4C:
    // 0x80070D4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80070D50: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80070D54: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80070D58: jal         0x8006F884
    // 0x80070D5C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    Fault_Printf(rdram, ctx);
        goto after_3;
    // 0x80070D5C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    after_3:
    // 0x80070D60: addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // 0x80070D64: bnel        $s0, $s4, L_80070D4C
    if (ctx->r16 != ctx->r20) {
        // 0x80070D68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80070D4C;
    }
    goto skip_0;
    // 0x80070D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80070D6C: addiu       $s2, $s2, 0x9
    ctx->r18 = ADD32(ctx->r18, 0X9);
    // 0x80070D70: bnel        $s2, $s6, L_80070D34
    if (ctx->r18 != ctx->r22) {
        // 0x80070D74: addiu       $a0, $zero, 0x1C
        ctx->r4 = ADD32(0, 0X1C);
            goto L_80070D34;
    }
    goto skip_1;
    // 0x80070D74: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    skip_1:
    // 0x80070D78: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80070D7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80070D80: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80070D84: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80070D88: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80070D8C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80070D90: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80070D94: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80070D98: jr          $ra
    // 0x80070D9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80070D9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80046A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80046A3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80046A40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80046A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80046A48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80046A4C: jal         0x8005D96C
    // 0x80046A50: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    func_8005D96C(rdram, ctx);
        goto after_0;
    // 0x80046A50: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    after_0:
    // 0x80046A54: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80046A58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046A5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80046A60: bne         $v0, $at, L_80046A80
    if (ctx->r2 != ctx->r1) {
        // 0x80046A64: sw          $t6, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r14;
            goto L_80046A80;
    }
    // 0x80046A64: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x80046A68: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80046A6C: addiu       $a0, $a0, 0x760
    ctx->r4 = ADD32(ctx->r4, 0X760);
    // 0x80046A70: jal         0x80071380
    // 0x80046A74: addiu       $a1, $zero, 0x639
    ctx->r5 = ADD32(0, 0X639);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80046A74: addiu       $a1, $zero, 0x639
    ctx->r5 = ADD32(0, 0X639);
    after_1:
    // 0x80046A78: b           L_80046AAC
    // 0x80046A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046AAC;
    // 0x80046A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046A80:
    // 0x80046A80: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x80046A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046A88: jal         0x80047E70
    // 0x80046A8C: sw          $v1, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r3;
    func_80047E70(rdram, ctx);
        goto after_2;
    // 0x80046A8C: sw          $v1, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r3;
    after_2:
    // 0x80046A90: jal         0x80064F94
    // 0x80046A94: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    func_80064F94(rdram, ctx);
        goto after_3;
    // 0x80046A94: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    after_3:
    // 0x80046A98: beql        $v0, $zero, L_80046AA8
    if (ctx->r2 == 0) {
        // 0x80046A9C: sw          $zero, 0x1F8($s0)
        MEM_W(0X1F8, ctx->r16) = 0;
            goto L_80046AA8;
    }
    goto skip_0;
    // 0x80046A9C: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    skip_0:
    // 0x80046AA0: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x80046AA4: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
L_80046AA8:
    // 0x80046AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80046AAC:
    // 0x80046AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80046AB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80046AB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80046AB8: jr          $ra
    // 0x80046ABC: nop

    return;
    // 0x80046ABC: nop

;}
RECOMP_FUNC void func_80061C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061C7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061C80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061C84: jal         0x8004700C
    // 0x80061C88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80061C88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80061C8C: beq         $v0, $zero, L_80061EB8
    if (ctx->r2 == 0) {
        // 0x80061C90: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80061EB8;
    }
    // 0x80061C90: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80061C94: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80061C98: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x80061C9C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80061CA0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061CA4: lh          $t7, 0x56($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X56);
    // 0x80061CA8: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x80061CAC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80061CB0: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80061CB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80061CB8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80061CBC: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80061CC0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061CC4: lh          $t9, 0x58($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X58);
    // 0x80061CC8: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80061CCC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80061CD0: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80061CD4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061CD8: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80061CDC: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80061CE0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061CE4: lh          $t1, 0x5A($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X5A);
    // 0x80061CE8: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x80061CEC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80061CF0: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80061CF4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061CF8: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80061CFC: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    // 0x80061D00: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80061D04: jal         0x80060030
    // 0x80061D08: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80060030(rdram, ctx);
        goto after_1;
    // 0x80061D08: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_1:
    // 0x80061D0C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80061D10: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80061D14: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80061D18: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80061D1C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061D20: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80061D24: lh          $t3, 0x52($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X52);
    // 0x80061D28: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x80061D2C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80061D30: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80061D34: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80061D38: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80061D3C: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x80061D40: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061D44: lwc1        $f10, 0x8C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x80061D48: lh          $t5, 0x54($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X54);
    // 0x80061D4C: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x80061D50: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80061D54: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80061D58: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061D5C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80061D60: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80061D64: beq         $v1, $zero, L_80061EB8
    if (ctx->r3 == 0) {
        // 0x80061D68: swc1        $f8, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
            goto L_80061EB8;
    }
    // 0x80061D68: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80061D6C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80061D70: lbu         $t8, 0x79($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X79);
    // 0x80061D74: beql        $t8, $zero, L_80061EBC
    if (ctx->r24 == 0) {
        // 0x80061D78: lw          $t0, 0x4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X4);
            goto L_80061EBC;
    }
    goto skip_0;
    // 0x80061D78: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80061D7C: sw          $a2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r6;
    // 0x80061D80: lwc1        $f16, 0xC4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC4);
    // 0x80061D84: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80061D88: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80061D8C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80061D90: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80061D94: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    // 0x80061D98: lwc1        $f6, 0xC8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC8);
    // 0x80061D9C: lwc1        $f18, 0x5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80061DA0: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80061DA4: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80061DA8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80061DAC: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
    // 0x80061DB0: lwc1        $f10, 0x60($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80061DB4: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80061DB8: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80061DBC: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80061DC0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80061DC4: nop

    // 0x80061DC8: bc1fl       L_80061EBC
    if (!c1cs) {
        // 0x80061DCC: lw          $t0, 0x4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X4);
            goto L_80061EBC;
    }
    goto skip_1;
    // 0x80061DCC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80061DD0: sw          $v1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r3;
    // 0x80061DD4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80061DD8: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x80061DDC: bnel        $t9, $zero, L_80061EBC
    if (ctx->r25 != 0) {
        // 0x80061DE0: lw          $t0, 0x4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X4);
            goto L_80061EBC;
    }
    goto skip_2;
    // 0x80061DE0: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x80061DE4: lbu         $t0, 0x7EA5($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7EA5);
    // 0x80061DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061DEC: beq         $t0, $zero, L_80061E00
    if (ctx->r8 == 0) {
        // 0x80061DF0: nop
    
            goto L_80061E00;
    }
    // 0x80061DF0: nop

    // 0x80061DF4: lbu         $t2, 0x10($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X10);
    // 0x80061DF8: beql        $t2, $zero, L_80061EBC
    if (ctx->r10 == 0) {
        // 0x80061DFC: lw          $t0, 0x4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X4);
            goto L_80061EBC;
    }
    goto skip_3;
    // 0x80061DFC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    skip_3:
L_80061E00:
    // 0x80061E00: jal         0x800603E8
    // 0x80061E04: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800603E8(rdram, ctx);
        goto after_2;
    // 0x80061E04: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x80061E08: beq         $v0, $zero, L_80061EB8
    if (ctx->r2 == 0) {
        // 0x80061E0C: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80061EB8;
    }
    // 0x80061E0C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80061E10: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80061E14: lwc1        $f10, 0x84($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X84);
    // 0x80061E18: lwc1        $f6, 0x88($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X88);
    // 0x80061E1C: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80061E20: lwc1        $f18, 0x88($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80061E24: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80061E28: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80061E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061E30: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80061E34: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80061E38: jal         0x80060ED0
    // 0x80061E3C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_80060ED0(rdram, ctx);
        goto after_3;
    // 0x80061E3C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x80061E40: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x80061E44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80061E48: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80061E4C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80061E50: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80061E54: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80061E58: lhu         $t5, 0x5C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X5C);
    // 0x80061E5C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80061E60: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x80061E64: beql        $t6, $zero, L_80061E7C
    if (ctx->r14 == 0) {
        // 0x80061E68: swc1        $f16, 0x120($a2)
        MEM_W(0X120, ctx->r6) = ctx->f16.u32l;
            goto L_80061E7C;
    }
    goto skip_4;
    // 0x80061E68: swc1        $f16, 0x120($a2)
    MEM_W(0X120, ctx->r6) = ctx->f16.u32l;
    skip_4:
    // 0x80061E6C: lw          $t8, 0x1F4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1F4);
    // 0x80061E70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80061E74: sb          $t7, 0xDC($t8)
    MEM_B(0XDC, ctx->r24) = ctx->r15;
    // 0x80061E78: swc1        $f16, 0x120($a2)
    MEM_W(0X120, ctx->r6) = ctx->f16.u32l;
L_80061E7C:
    // 0x80061E7C: sb          $t9, 0x17C($a2)
    MEM_B(0X17C, ctx->r6) = ctx->r25;
    // 0x80061E80: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80061E84: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80061E88: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80061E8C: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x80061E90: mul.s       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80061E94: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80061E98: swc1        $f16, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f16.u32l;
    // 0x80061E9C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80061EA0: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80061EA4: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80061EA8: nop

    // 0x80061EAC: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80061EB0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80061EB4: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
L_80061EB8:
    // 0x80061EB8: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
L_80061EBC:
    // 0x80061EBC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80061EC0: lh          $t1, 0x184($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X184);
    // 0x80061EC4: beql        $t1, $zero, L_80061EEC
    if (ctx->r9 == 0) {
        // 0x80061EC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80061EEC;
    }
    goto skip_5;
    // 0x80061EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80061ECC: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80061ED0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80061ED4: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80061ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061EDC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80061EE0: jalr        $t9
    // 0x80061EE4: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80061EE4: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x80061EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80061EEC:
    // 0x80061EEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061EF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80061EF4: jr          $ra
    // 0x80061EF8: nop

    return;
    // 0x80061EF8: nop

;}
RECOMP_FUNC void func_8064A40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A40C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A414: jal         0x8005FD1C
    // 0x8064A418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x8064A418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064A41C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8064A420: lw          $t7, 0x174($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X174);
    // 0x8064A424: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064A428: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x8064A42C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064A430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A434: jr          $ra
    // 0x8064A438: nop

    return;
    // 0x8064A438: nop

;}
RECOMP_FUNC void func_80051D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051D64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051D6C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80051D70: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80051D74: beq         $a1, $zero, L_80051D88
    if (ctx->r5 == 0) {
        // 0x80051D78: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80051D88;
    }
    // 0x80051D78: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80051D7C: jal         0x80051C80
    // 0x80051D80: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80051C80(rdram, ctx);
        goto after_0;
    // 0x80051D80: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80051D84: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80051D88:
    // 0x80051D88: jal         0x80064E84
    // 0x80051D8C: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80051D8C: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    after_1:
    // 0x80051D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051D98: jr          $ra
    // 0x80051D9C: nop

    return;
    // 0x80051D9C: nop

;}
RECOMP_FUNC void func_8070F740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070F740: addiu       $v0, $zero, 0x2710
    ctx->r2 = ADD32(0, 0X2710);
    // 0x8070F744: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x8070F748: mflo        $t6
    ctx->r14 = lo;
    // 0x8070F74C: addiu       $v1, $zero, 0x3E8
    ctx->r3 = ADD32(0, 0X3E8);
    // 0x8070F750: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8070F754: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8070F758: bne         $v0, $zero, L_8070F764
    if (ctx->r2 != 0) {
        // 0x8070F75C: nop
    
            goto L_8070F764;
    }
    // 0x8070F75C: nop

    // 0x8070F760: break       7
    do_break(2154887008);
L_8070F764:
    // 0x8070F764: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8070F768: bne         $v0, $at, L_8070F77C
    if (ctx->r2 != ctx->r1) {
        // 0x8070F76C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8070F77C;
    }
    // 0x8070F76C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8070F770: bne         $a1, $at, L_8070F77C
    if (ctx->r5 != ctx->r1) {
        // 0x8070F774: nop
    
            goto L_8070F77C;
    }
    // 0x8070F774: nop

    // 0x8070F778: break       6
    do_break(2154887032);
L_8070F77C:
    // 0x8070F77C: mfhi        $a1
    ctx->r5 = hi;
    // 0x8070F780: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x8070F784: nop

    // 0x8070F788: div         $zero, $a1, $v1
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r3)));
    // 0x8070F78C: bne         $v1, $zero, L_8070F798
    if (ctx->r3 != 0) {
        // 0x8070F790: nop
    
            goto L_8070F798;
    }
    // 0x8070F790: nop

    // 0x8070F794: break       7
    do_break(2154887060);
L_8070F798:
    // 0x8070F798: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8070F79C: bne         $v1, $at, L_8070F7B0
    if (ctx->r3 != ctx->r1) {
        // 0x8070F7A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8070F7B0;
    }
    // 0x8070F7A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8070F7A4: bne         $a1, $at, L_8070F7B0
    if (ctx->r5 != ctx->r1) {
        // 0x8070F7A8: nop
    
            goto L_8070F7B0;
    }
    // 0x8070F7A8: nop

    // 0x8070F7AC: break       6
    do_break(2154887084);
L_8070F7B0:
    // 0x8070F7B0: mfhi        $a1
    ctx->r5 = hi;
    // 0x8070F7B4: mflo        $t7
    ctx->r15 = lo;
    // 0x8070F7B8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8070F7BC: nop

    // 0x8070F7C0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x8070F7C4: bne         $a2, $zero, L_8070F7D0
    if (ctx->r6 != 0) {
        // 0x8070F7C8: nop
    
            goto L_8070F7D0;
    }
    // 0x8070F7C8: nop

    // 0x8070F7CC: break       7
    do_break(2154887116);
L_8070F7D0:
    // 0x8070F7D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8070F7D4: bne         $a2, $at, L_8070F7E8
    if (ctx->r6 != ctx->r1) {
        // 0x8070F7D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8070F7E8;
    }
    // 0x8070F7D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8070F7DC: bne         $a1, $at, L_8070F7E8
    if (ctx->r5 != ctx->r1) {
        // 0x8070F7E0: nop
    
            goto L_8070F7E8;
    }
    // 0x8070F7E0: nop

    // 0x8070F7E4: break       6
    do_break(2154887140);
L_8070F7E8:
    // 0x8070F7E8: mfhi        $a1
    ctx->r5 = hi;
    // 0x8070F7EC: mflo        $t8
    ctx->r24 = lo;
    // 0x8070F7F0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8070F7F4: nop

    // 0x8070F7F8: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x8070F7FC: bne         $a3, $zero, L_8070F808
    if (ctx->r7 != 0) {
        // 0x8070F800: nop
    
            goto L_8070F808;
    }
    // 0x8070F800: nop

    // 0x8070F804: break       7
    do_break(2154887172);
L_8070F808:
    // 0x8070F808: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8070F80C: bne         $a3, $at, L_8070F820
    if (ctx->r7 != ctx->r1) {
        // 0x8070F810: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8070F820;
    }
    // 0x8070F810: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8070F814: bne         $a1, $at, L_8070F820
    if (ctx->r5 != ctx->r1) {
        // 0x8070F818: nop
    
            goto L_8070F820;
    }
    // 0x8070F818: nop

    // 0x8070F81C: break       6
    do_break(2154887196);
L_8070F820:
    // 0x8070F820: mflo        $t9
    ctx->r25 = lo;
    // 0x8070F824: mfhi        $a1
    ctx->r5 = hi;
    // 0x8070F828: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8070F82C: jr          $ra
    // 0x8070F830: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x8070F830: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_8002FB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FB50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FB54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FB58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FB5C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FB60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002FB64: jal         0x8002F678
    // 0x8002FB68: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FB68: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FB6C: beq         $v0, $zero, L_8002FB80
    if (ctx->r2 == 0) {
        // 0x8002FB70: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FB80;
    }
    // 0x8002FB70: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FB74: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FB78: addiu       $t6, $t6, -0x1168
    ctx->r14 = ADD32(ctx->r14, -0X1168);
    // 0x8002FB7C: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FB80:
    // 0x8002FB80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FB84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FB88: jr          $ra
    // 0x8002FB8C: nop

    return;
    // 0x8002FB8C: nop

;}
RECOMP_FUNC void func_80045CAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045CAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80045CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045CB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80045CB8: lw          $v1, 0x168($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X168);
    // 0x80045CBC: lui         $t7, 0x1997
    ctx->r15 = S32(0X1997 << 16);
    // 0x80045CC0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80045CC4: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80045CC8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80045CCC: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x80045CD0: ori         $t7, $t7, 0x1110
    ctx->r15 = ctx->r15 | 0X1110;
    // 0x80045CD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80045CD8: sh          $t6, 0x17E($a0)
    MEM_H(0X17E, ctx->r4) = ctx->r14;
    // 0x80045CDC: sb          $t5, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r13;
    // 0x80045CE0: sb          $t5, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r13;
    // 0x80045CE4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80045CE8: bne         $v1, $zero, L_80045D1C
    if (ctx->r3 != 0) {
        // 0x80045CEC: sw          $a1, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r5;
            goto L_80045D1C;
    }
    // 0x80045CEC: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x80045CF0: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x80045CF4: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80045CF8: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80045CFC: jal         0x80051194
    // 0x80045D00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80045D00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80045D04: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80045D08: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80045D0C: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80045D10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80045D14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80045D18: sw          $v0, 0x168($a2)
    MEM_W(0X168, ctx->r6) = ctx->r2;
L_80045D1C:
    // 0x80045D1C: bne         $v1, $zero, L_80045D3C
    if (ctx->r3 != 0) {
        // 0x80045D20: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80045D3C;
    }
    // 0x80045D20: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80045D24: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045D28: addiu       $a0, $a0, 0x6E0
    ctx->r4 = ADD32(ctx->r4, 0X6E0);
    // 0x80045D2C: jal         0x80071380
    // 0x80045D30: addiu       $a1, $zero, 0x308
    ctx->r5 = ADD32(0, 0X308);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80045D30: addiu       $a1, $zero, 0x308
    ctx->r5 = ADD32(0, 0X308);
    after_1:
    // 0x80045D34: b           L_80046004
    // 0x80045D38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046004;
    // 0x80045D38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80045D3C:
    // 0x80045D3C: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x80045D40: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80045D44: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80045D48: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80045D4C: bne         $t4, $t9, L_80045D70
    if (ctx->r12 != ctx->r25) {
        // 0x80045D50: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80045D70;
    }
    // 0x80045D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80045D54: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x80045D58: lbu         $t6, 0xE($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XE);
    // 0x80045D5C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80045D60: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x80045D64: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80045D68: b           L_80045D78
    // 0x80045D6C: sb          $t8, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r24;
        goto L_80045D78;
    // 0x80045D6C: sb          $t8, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r24;
L_80045D70:
    // 0x80045D70: lbu         $t6, 0x2($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X2);
    // 0x80045D74: sb          $t6, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r14;
L_80045D78:
    // 0x80045D78: sb          $t5, 0x165($a2)
    MEM_B(0X165, ctx->r6) = ctx->r13;
    // 0x80045D7C: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x80045D80: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x80045D84: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80045D88: sb          $t9, 0x164($a2)
    MEM_B(0X164, ctx->r6) = ctx->r25;
    // 0x80045D8C: lbu         $t7, 0x2E($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X2E);
    // 0x80045D90: srl         $t6, $t8, 30
    ctx->r14 = S32(U32(ctx->r24) >> 30);
    // 0x80045D94: sb          $zero, 0x18($a2)
    MEM_B(0X18, ctx->r6) = 0;
    // 0x80045D98: bne         $t4, $t6, L_80045DB0
    if (ctx->r12 != ctx->r14) {
        // 0x80045D9C: sb          $t7, 0x170($a2)
        MEM_B(0X170, ctx->r6) = ctx->r15;
            goto L_80045DB0;
    }
    // 0x80045D9C: sb          $t7, 0x170($a2)
    MEM_B(0X170, ctx->r6) = ctx->r15;
    // 0x80045DA0: lbu         $t9, 0x1($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1);
    // 0x80045DA4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80045DA8: b           L_80045DB8
    // 0x80045DAC: sb          $t9, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r25;
        goto L_80045DB8;
    // 0x80045DAC: sb          $t9, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r25;
L_80045DB0:
    // 0x80045DB0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80045DB4: sb          $t2, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r10;
L_80045DB8:
    // 0x80045DB8: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80045DBC: swc1        $f12, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->f12.u32l;
    // 0x80045DC0: swc1        $f12, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f12.u32l;
    // 0x80045DC4: swc1        $f14, 0x88($a2)
    MEM_W(0X88, ctx->r6) = ctx->f14.u32l;
    // 0x80045DC8: swc1        $f14, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f14.u32l;
    // 0x80045DCC: lwc1        $f4, 0x89C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X89C);
    // 0x80045DD0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80045DD4: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x80045DD8: nop

    // 0x80045DDC: bc1fl       L_80045DF0
    if (!c1cs) {
        // 0x80045DE0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80045DF0;
    }
    goto skip_0;
    // 0x80045DE0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x80045DE4: b           L_80045DF0
    // 0x80045DE8: lwc1        $f0, 0x4($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X4);
        goto L_80045DF0;
    // 0x80045DE8: lwc1        $f0, 0x4($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80045DEC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80045DF0:
    // 0x80045DF0: swc1        $f0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f0.u32l;
    // 0x80045DF4: swc1        $f0, 0x8C($a2)
    MEM_W(0X8C, ctx->r6) = ctx->f0.u32l;
L_80045DF8:
    // 0x80045DF8: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80045DFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80045E00: sltiu       $at, $a1, 0x3
    ctx->r1 = ctx->r5 < 0X3 ? 1 : 0;
    // 0x80045E04: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x80045E08: swc1        $f2, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f2.u32l;
    // 0x80045E0C: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80045E10: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80045E14: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80045E18: swc1        $f0, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f0.u32l;
    // 0x80045E1C: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
    // 0x80045E20: bne         $at, $zero, L_80045DF8
    if (ctx->r1 != 0) {
        // 0x80045E24: swc1        $f0, 0x98($v0)
        MEM_W(0X98, ctx->r2) = ctx->f0.u32l;
            goto L_80045DF8;
    }
    // 0x80045E24: swc1        $f0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f0.u32l;
    // 0x80045E28: lbu         $t7, 0x164($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X164);
    // 0x80045E2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80045E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80045E34: beq         $t7, $at, L_80045E9C
    if (ctx->r15 == ctx->r1) {
        // 0x80045E38: lui         $t3, 0x800F
        ctx->r11 = S32(0X800F << 16);
            goto L_80045E9C;
    }
    // 0x80045E38: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x80045E3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80045E40: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80045E44: addiu       $t3, $t3, 0x7EA0
    ctx->r11 = ADD32(ctx->r11, 0X7EA0);
    // 0x80045E48: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80045E4C: addiu       $a3, $zero, 0x40C3
    ctx->r7 = ADD32(0, 0X40C3);
    // 0x80045E50: lhu         $t8, 0xC($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0XC);
L_80045E54:
    // 0x80045E54: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80045E58: beql        $a3, $t8, L_80045E94
    if (ctx->r7 == ctx->r24) {
        // 0x80045E5C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80045E94;
    }
    goto skip_1;
    // 0x80045E5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x80045E60: lw          $t6, 0x59C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X59C);
    // 0x80045E64: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    // 0x80045E68: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80045E6C: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x80045E70: bne         $a1, $t2, L_80045E7C
    if (ctx->r5 != ctx->r10) {
        // 0x80045E74: lwc1        $f2, 0x3C($t9)
        ctx->f2.u32l = MEM_W(ctx->r25, 0X3C);
            goto L_80045E7C;
    }
    // 0x80045E74: lwc1        $f2, 0x3C($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x80045E78: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80045E7C:
    // 0x80045E7C: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80045E80: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80045E84: swc1        $f0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f0.u32l;
    // 0x80045E88: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x80045E8C: swc1        $f0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f0.u32l;
    // 0x80045E90: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80045E94:
    // 0x80045E94: bnel        $a1, $t0, L_80045E54
    if (ctx->r5 != ctx->r8) {
        // 0x80045E98: lhu         $t8, 0xC($a2)
        ctx->r24 = MEM_HU(ctx->r6, 0XC);
            goto L_80045E54;
    }
    goto skip_2;
    // 0x80045E98: lhu         $t8, 0xC($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0XC);
    skip_2:
L_80045E9C:
    // 0x80045E9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80045EA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80045EA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80045EA8: jal         0x8004921C
    // 0x80045EAC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x80045EAC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_2:
    // 0x80045EB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80045EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80045EB8: jal         0x8004921C
    // 0x80045EBC: sh          $v0, 0x13C($a0)
    MEM_H(0X13C, ctx->r4) = ctx->r2;
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x80045EBC: sh          $v0, 0x13C($a0)
    MEM_H(0X13C, ctx->r4) = ctx->r2;
    after_3:
    // 0x80045EC0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80045EC4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80045EC8: addiu       $a0, $zero, 0x7FFF
    ctx->r4 = ADD32(0, 0X7FFF);
    // 0x80045ECC: sh          $v0, 0x13E($a2)
    MEM_H(0X13E, ctx->r6) = ctx->r2;
    // 0x80045ED0: lh          $v1, 0x2A($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X2A);
    // 0x80045ED4: addiu       $a1, $a2, 0x38
    ctx->r5 = ADD32(ctx->r6, 0X38);
    // 0x80045ED8: bne         $a0, $v1, L_80045EEC
    if (ctx->r4 != ctx->r3) {
        // 0x80045EDC: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_80045EEC;
    }
    // 0x80045EDC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80045EE0: sh          $a0, 0xC0($a2)
    MEM_H(0XC0, ctx->r6) = ctx->r4;
    // 0x80045EE4: b           L_80045F4C
    // 0x80045EE8: sh          $a0, 0xC2($a2)
    MEM_H(0XC2, ctx->r6) = ctx->r4;
        goto L_80045F4C;
    // 0x80045EE8: sh          $a0, 0xC2($a2)
    MEM_H(0XC2, ctx->r6) = ctx->r4;
L_80045EEC:
    // 0x80045EEC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80045EF0: bne         $v0, $zero, L_80045F10
    if (ctx->r2 != 0) {
        // 0x80045EF4: lh          $a0, 0x2C($t1)
        ctx->r4 = MEM_H(ctx->r9, 0X2C);
            goto L_80045F10;
    }
    // 0x80045EF4: lh          $a0, 0x2C($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X2C);
    // 0x80045EF8: bnel        $a0, $zero, L_80045F14
    if (ctx->r4 != 0) {
        // 0x80045EFC: mtc1        $v0, $f8
        ctx->f8.u32l = ctx->r2;
            goto L_80045F14;
    }
    goto skip_3;
    // 0x80045EFC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    skip_3:
    // 0x80045F00: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x80045F04: sh          $v0, 0xC0($a2)
    MEM_H(0XC0, ctx->r6) = ctx->r2;
    // 0x80045F08: b           L_80045F4C
    // 0x80045F0C: sh          $v0, 0xC2($a2)
    MEM_H(0XC2, ctx->r6) = ctx->r2;
        goto L_80045F4C;
    // 0x80045F0C: sh          $v0, 0xC2($a2)
    MEM_H(0XC2, ctx->r6) = ctx->r2;
L_80045F10:
    // 0x80045F10: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
L_80045F14:
    // 0x80045F14: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80045F18: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80045F1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80045F20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80045F24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80045F28: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80045F2C: nop

    // 0x80045F30: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80045F34: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80045F38: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80045F3C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80045F40: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80045F44: sh          $t8, 0xC0($a2)
    MEM_H(0XC0, ctx->r6) = ctx->r24;
    // 0x80045F48: sh          $t9, 0xC2($a2)
    MEM_H(0XC2, ctx->r6) = ctx->r25;
L_80045F4C:
    // 0x80045F4C: addiu       $a0, $a2, 0x34
    ctx->r4 = ADD32(ctx->r6, 0X34);
    // 0x80045F50: jal         0x80047488
    // 0x80045F54: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80047488(rdram, ctx);
        goto after_4;
    // 0x80045F54: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_4:
    // 0x80045F58: jal         0x80047E70
    // 0x80045F5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80047E70(rdram, ctx);
        goto after_5;
    // 0x80045F5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80045F60: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80045F64: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80045F68: addiu       $t7, $t7, -0x7644
    ctx->r15 = ADD32(ctx->r15, -0X7644);
    // 0x80045F6C: lw          $t8, 0x168($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X168);
    // 0x80045F70: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
    // 0x80045F74: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x80045F78: lw          $t6, 0x44($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X44);
    // 0x80045F7C: addiu       $t3, $t3, 0x7EA0
    ctx->r11 = ADD32(ctx->r11, 0X7EA0);
    // 0x80045F80: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045F84: bne         $t6, $zero, L_80045FA8
    if (ctx->r14 != 0) {
        // 0x80045F88: sw          $t6, 0x20($a2)
        MEM_W(0X20, ctx->r6) = ctx->r14;
            goto L_80045FA8;
    }
    // 0x80045F88: sw          $t6, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r14;
    // 0x80045F8C: addiu       $a0, $a0, 0x6F0
    ctx->r4 = ADD32(ctx->r4, 0X6F0);
    // 0x80045F90: addiu       $a1, $zero, 0x366
    ctx->r5 = ADD32(0, 0X366);
    // 0x80045F94: jal         0x80071380
    // 0x80045F98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    Fault_HungUp(rdram, ctx);
        goto after_6;
    // 0x80045F98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_6:
    // 0x80045F9C: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x80045FA0: addiu       $t3, $t3, 0x7EA0
    ctx->r11 = ADD32(ctx->r11, 0X7EA0);
    // 0x80045FA4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_80045FA8:
    // 0x80045FA8: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x80045FAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045FB4: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80045FB8: bnel        $t8, $at, L_80045FF8
    if (ctx->r24 != ctx->r1) {
        // 0x80045FBC: sb          $zero, 0x1E8($a2)
        MEM_B(0X1E8, ctx->r6) = 0;
            goto L_80045FF8;
    }
    goto skip_4;
    // 0x80045FBC: sb          $zero, 0x1E8($a2)
    MEM_B(0X1E8, ctx->r6) = 0;
    skip_4:
    // 0x80045FC0: lhu         $t6, 0xC($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XC);
    // 0x80045FC4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80045FC8: beql        $t6, $at, L_80045FF8
    if (ctx->r14 == ctx->r1) {
        // 0x80045FCC: sb          $zero, 0x1E8($a2)
        MEM_B(0X1E8, ctx->r6) = 0;
            goto L_80045FF8;
    }
    goto skip_5;
    // 0x80045FCC: sb          $zero, 0x1E8($a2)
    MEM_B(0X1E8, ctx->r6) = 0;
    skip_5:
    // 0x80045FD0: lw          $t7, 0x59C($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X59C);
    // 0x80045FD4: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80045FD8: addiu       $t9, $t9, -0x602C
    ctx->r25 = ADD32(ctx->r25, -0X602C);
    // 0x80045FDC: lw          $t8, 0x110($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X110);
    // 0x80045FE0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80045FE4: addiu       $t6, $t6, -0x71D0
    ctx->r14 = ADD32(ctx->r14, -0X71D0);
    // 0x80045FE8: beql        $t9, $t8, L_80045FF8
    if (ctx->r25 == ctx->r24) {
        // 0x80045FEC: sb          $zero, 0x1E8($a2)
        MEM_B(0X1E8, ctx->r6) = 0;
            goto L_80045FF8;
    }
    goto skip_6;
    // 0x80045FEC: sb          $zero, 0x1E8($a2)
    MEM_B(0X1E8, ctx->r6) = 0;
    skip_6:
    // 0x80045FF0: sw          $t6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r14;
    // 0x80045FF4: sb          $zero, 0x1E8($a2)
    MEM_B(0X1E8, ctx->r6) = 0;
L_80045FF8:
    // 0x80045FF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80045FFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046000: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
L_80046004:
    // 0x80046004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046008: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004600C: jr          $ra
    // 0x80046010: nop

    return;
    // 0x80046010: nop

;}
RECOMP_FUNC void func_80574280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574280: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80574284: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80574288: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8057428C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80574290: swc1        $f4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f4.u32l;
    // 0x80574294: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80574298: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x8057429C: jr          $ra
    // 0x805742A0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x805742A0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
;}
RECOMP_FUNC void func_80058958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058958: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8005895C: lw          $v1, -0x6DA8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DA8);
    // 0x80058960: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80058964: jr          $ra
    // 0x80058968: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    return;
    // 0x80058968: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
;}
RECOMP_FUNC void func_807154E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807154E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807154E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807154E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807154EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807154F0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x807154F4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x807154F8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807154FC: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80715500: bne         $v0, $at, L_807155E8
    if (ctx->r2 != ctx->r1) {
        // 0x80715504: lw          $a3, 0x174($a1)
        ctx->r7 = MEM_W(ctx->r5, 0X174);
            goto L_807155E8;
    }
    // 0x80715504: lw          $a3, 0x174($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X174);
    // 0x80715508: addiu       $at, $zero, 0x4626
    ctx->r1 = ADD32(0, 0X4626);
    // 0x8071550C: beq         $v1, $at, L_80715528
    if (ctx->r3 == ctx->r1) {
        // 0x80715510: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80715528;
    }
    // 0x80715510: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80715514: addiu       $at, $zero, 0x4637
    ctx->r1 = ADD32(0, 0X4637);
    // 0x80715518: beq         $v1, $at, L_80715578
    if (ctx->r3 == ctx->r1) {
        // 0x8071551C: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80715578;
    }
    // 0x8071551C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80715520: b           L_807155DC
    // 0x80715524: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_807155DC;
    // 0x80715524: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80715528:
    // 0x80715528: lw          $v0, 0x1F4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X1F4);
    // 0x8071552C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80715530: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80715534: lbu         $a0, 0x6($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X6);
    // 0x80715538: beq         $a0, $zero, L_8071554C
    if (ctx->r4 == 0) {
        // 0x8071553C: nop
    
            goto L_8071554C;
    }
    // 0x8071553C: nop

    // 0x80715540: lbu         $v0, 0x10($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X10);
    // 0x80715544: bne         $v0, $zero, L_80715554
    if (ctx->r2 != 0) {
        // 0x80715548: nop
    
            goto L_80715554;
    }
    // 0x80715548: nop

L_8071554C:
    // 0x8071554C: b           L_80715560
    // 0x80715550: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80715560;
    // 0x80715550: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80715554:
    // 0x80715554: bne         $v0, $a0, L_80715560
    if (ctx->r2 != ctx->r4) {
        // 0x80715558: nop
    
            goto L_80715560;
    }
    // 0x80715558: nop

    // 0x8071555C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80715560:
    // 0x80715560: beq         $v1, $zero, L_807155E8
    if (ctx->r3 == 0) {
        // 0x80715564: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_807155E8;
    }
    // 0x80715564: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80715568: jal         0x8002F6E4
    // 0x8071556C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x8071556C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80715570: b           L_807155EC
    // 0x80715574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807155EC;
    // 0x80715574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715578:
    // 0x80715578: lw          $a0, 0x180($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X180);
    // 0x8071557C: beql        $a0, $zero, L_807155EC
    if (ctx->r4 == 0) {
        // 0x80715580: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807155EC;
    }
    goto skip_0;
    // 0x80715580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80715584: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80715588: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8071558C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80715590: lh          $t0, 0x5E0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X5E0);
    // 0x80715594: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80715598: lbu         $a1, 0x500($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X500);
    // 0x8071559C: beq         $a1, $zero, L_807155B0
    if (ctx->r5 == 0) {
        // 0x807155A0: nop
    
            goto L_807155B0;
    }
    // 0x807155A0: nop

    // 0x807155A4: lbu         $v0, 0x10($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X10);
    // 0x807155A8: bne         $v0, $zero, L_807155B8
    if (ctx->r2 != 0) {
        // 0x807155AC: nop
    
            goto L_807155B8;
    }
    // 0x807155AC: nop

L_807155B0:
    // 0x807155B0: b           L_807155C4
    // 0x807155B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_807155C4;
    // 0x807155B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_807155B8:
    // 0x807155B8: bne         $v0, $a1, L_807155C4
    if (ctx->r2 != ctx->r5) {
        // 0x807155BC: nop
    
            goto L_807155C4;
    }
    // 0x807155BC: nop

    // 0x807155C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_807155C4:
    // 0x807155C4: beq         $v1, $zero, L_807155E8
    if (ctx->r3 == 0) {
        // 0x807155C8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_807155E8;
    }
    // 0x807155C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x807155CC: jal         0x8002F6E4
    // 0x807155D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x807155D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807155D4: b           L_807155EC
    // 0x807155D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807155EC;
    // 0x807155D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807155DC:
    // 0x807155DC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x807155E0: jal         0x8002F6E4
    // 0x807155E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_2;
    // 0x807155E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_807155E8:
    // 0x807155E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807155EC:
    // 0x807155EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807155F0: jr          $ra
    // 0x807155F4: nop

    return;
    // 0x807155F4: nop

;}
RECOMP_FUNC void func_806E8030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E8030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E8034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E8038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806E803C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806E8040: jal         0x80047090
    // 0x806E8044: addiu       $a0, $zero, 0x4027
    ctx->r4 = ADD32(0, 0X4027);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806E8044: addiu       $a0, $zero, 0x4027
    ctx->r4 = ADD32(0, 0X4027);
    after_0:
    // 0x806E8048: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806E804C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x806E8050: beq         $v0, $at, L_806E80A8
    if (ctx->r2 == ctx->r1) {
        // 0x806E8054: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806E80A8;
    }
    // 0x806E8054: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806E8058: lui         $at, 0x4027
    ctx->r1 = S32(0X4027 << 16);
    // 0x806E805C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806E8060: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x806E8064: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x806E8068: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x806E806C: jal         0x8004613C
    // 0x806E8070: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806E8070: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x806E8074: beq         $v0, $zero, L_806E80A8
    if (ctx->r2 == 0) {
        // 0x806E8078: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806E80A8;
    }
    // 0x806E8078: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806E807C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E8080: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806E8084: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x806E8088: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806E808C: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x806E8090: jal         0x80047F9C
    // 0x806E8094: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806E8094: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x806E8098: jal         0x806E7F18
    // 0x806E809C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806E7F18(rdram, ctx);
        goto after_3;
    // 0x806E809C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x806E80A0: b           L_806E80AC
    // 0x806E80A4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_806E80AC;
    // 0x806E80A4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_806E80A8:
    // 0x806E80A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806E80AC:
    // 0x806E80AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E80B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E80B4: jr          $ra
    // 0x806E80B8: nop

    return;
    // 0x806E80B8: nop

    // 0x806E80BC: nop

;}
RECOMP_FUNC void func_804711B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804711B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804711B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804711B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804711BC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804711C0: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804711C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804711C8: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x804711CC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x804711D0: jal         0x80471168
    // 0x804711D4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    func_80471168(rdram, ctx);
        goto after_0;
    // 0x804711D4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x804711D8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(155, 0X3D4) << 16);
    // 0x804711DC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x804711E0: lwc1        $f6, 0x1414($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(155, 0X3D4));
    // 0x804711E4: lui         $t7, 0x8047
    ctx->r15 = S32(RELOC_HI16(155, 0X3A4) << 16);
    // 0x804711E8: addiu       $t7, $t7, 0x13E4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(155, 0X3A4));
    // 0x804711EC: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x804711F0: nop

    // 0x804711F4: bc1f        L_80471248
    if (!c1cs) {
        // 0x804711F8: nop
    
            goto L_80471248;
    }
    // 0x804711F8: nop

    // 0x804711FC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80471200: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80471204: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x80471208: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8047120C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80471210: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80471214: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80471218: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x8047121C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80471220: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x80471224: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80471228: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    // 0x8047122C: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80471230: sw          $t8, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r24;
    // 0x80471234: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80471238: sw          $t9, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r25;
    // 0x8047123C: jal         0x80067818
    // 0x80471240: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80471240: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80471244: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
L_80471248:
    // 0x80471248: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(155, 0X3D8) << 16);
    // 0x8047124C: lwc1        $f8, 0x1418($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(155, 0X3D8));
    // 0x80471250: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80471254: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80471258: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8047125C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80471260: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80471264: nop

    // 0x80471268: bc1fl       L_8047128C
    if (!c1cs) {
        // 0x8047126C: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_8047128C;
    }
    goto skip_0;
    // 0x8047126C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    skip_0:
    // 0x80471270: jal         0x8047139C
    // 0x80471274: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8047139C(rdram, ctx);
        goto after_2;
    // 0x80471274: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80471278: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8047127C: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80471280: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80471284: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x80471288: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
L_8047128C:
    // 0x8047128C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80471290: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80471294: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x80471298: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8047129C: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x804712A0: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    // 0x804712A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804712A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804712AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x804712B0: jr          $ra
    // 0x804712B4: nop

    return;
    // 0x804712B4: nop

;}
RECOMP_FUNC void func_8005F5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F5D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005F5D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005F5D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005F5DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005F5E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005F5E4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8005F5E8: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x8005F5EC: lw          $s0, 0xC($a0)
    ctx->r16 = MEM_W(ctx->r4, 0XC);
    // 0x8005F5F0: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8005F5F4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8005F5F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005F5FC: jal         0x8005EFE8
    // 0x8005F600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005EFE8(rdram, ctx);
        goto after_0;
    // 0x8005F600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8005F604: addiu       $s2, $sp, 0x30
    ctx->r18 = ADD32(ctx->r29, 0X30);
    // 0x8005F608: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005F60C: jal         0x80073728
    // 0x8005F610: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80073728(rdram, ctx);
        goto after_1;
    // 0x8005F610: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8005F614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F618: jal         0x8005F0EC
    // 0x8005F61C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005F0EC(rdram, ctx);
        goto after_2;
    // 0x8005F61C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8005F620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F624: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005F628: jal         0x80073844
    // 0x8005F62C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80073844(rdram, ctx);
        goto after_3;
    // 0x8005F62C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8005F630: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005F634: jal         0x8005F3F4
    // 0x8005F638: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005F3F4(rdram, ctx);
        goto after_4;
    // 0x8005F638: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8005F63C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005F640: jal         0x8005F510
    // 0x8005F644: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005F510(rdram, ctx);
        goto after_5;
    // 0x8005F644: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8005F648: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F64C: jal         0x80073A78
    // 0x8005F650: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80073A78(rdram, ctx);
        goto after_6;
    // 0x8005F650: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x8005F654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F658: jal         0x8007DB34
    // 0x8005F65C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8007DB34(rdram, ctx);
        goto after_7;
    // 0x8005F65C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x8005F660: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005F664: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F668: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x8005F66C: addiu       $t0, $t0, -0x970
    ctx->r8 = ADD32(ctx->r8, -0X970);
    // 0x8005F670: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8005F674: sw          $t0, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = ctx->r8;
    // 0x8005F678: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F67C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005F680: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005F688: jr          $ra
    // 0x8005F68C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005F68C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8002F7AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F7AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002F7B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002F7B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002F7B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002F7BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002F7C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002F7C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8002F7C8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F7CC: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8002F7D0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002F7D4: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8002F7D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002F7DC: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8002F7E0: lw          $a1, -0x17E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17E0);
    // 0x8002F7E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002F7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F7EC: jal         0x8002F678
    // 0x8002F7F0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002F7F0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002F7F4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8002F7F8: beq         $v0, $zero, L_8002F858
    if (ctx->r2 == 0) {
        // 0x8002F7FC: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_8002F858;
    }
    // 0x8002F7FC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8002F800: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002F804: addiu       $t8, $t8, -0x3C4C
    ctx->r24 = ADD32(ctx->r24, -0X3C4C);
    // 0x8002F808: sw          $t8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r24;
    // 0x8002F80C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002F810: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002F814: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8002F818: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8002F81C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8002F820: nop

    // 0x8002F824: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002F828: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x8002F82C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F830: sw          $t0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->r8;
    // 0x8002F834: jal         0x8005FE48
    // 0x8002F838: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x8002F838: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002F83C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8002F840: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8002F844: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x8002F848: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8002F84C: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    // 0x8002F850: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8002F854: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
L_8002F858:
    // 0x8002F858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F85C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002F860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002F864: jr          $ra
    // 0x8002F868: nop

    return;
    // 0x8002F868: nop

;}
RECOMP_FUNC void func_806AF314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF314: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806AF318: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806AF31C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806AF320: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x806AF324: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(595, 0X1EC4) << 16);
    // 0x806AF328: addiu       $t7, $t7, -0x3FC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(595, 0X1EC4));
    // 0x806AF32C: addiu       $t6, $v0, 0xD
    ctx->r14 = ADD32(ctx->r2, 0XD);
    // 0x806AF330: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x806AF334: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806AF338: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x806AF33C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806AF340: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806AF344: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806AF348: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806AF34C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AF350: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806AF354: jal         0x80045A34
    // 0x806AF358: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806AF358: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x806AF35C: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(595, 0X1550) << 16);
    // 0x806AF360: addiu       $t9, $t9, -0xD70
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(595, 0X1550));
    // 0x806AF364: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806AF368: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x806AF36C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x806AF370: lui         $t1, 0x806B
    ctx->r9 = S32(RELOC_HI16(595, 0X1ECC) << 16);
    // 0x806AF374: addiu       $t1, $t1, -0x3F4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(595, 0X1ECC));
    // 0x806AF378: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x806AF37C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x806AF380: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x806AF384: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AF388: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x806AF38C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x806AF390: jal         0x80054530
    // 0x806AF394: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80054530(rdram, ctx);
        goto after_1;
    // 0x806AF394: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x806AF398: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x806AF39C: lui         $t3, 0x806B
    ctx->r11 = S32(RELOC_HI16(595, 0X13C) << 16);
    // 0x806AF3A0: addiu       $t3, $t3, -0x2184
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(595, 0X13C));
    // 0x806AF3A4: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x806AF3A8: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x806AF3AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AF3B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AF3B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x806AF3B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806AF3BC: jal         0x806AF64C
    // 0x806AF3C0: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    func_806AF64C(rdram, ctx);
        goto after_2;
    // 0x806AF3C0: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    after_2:
    // 0x806AF3C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806AF3C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806AF3CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806AF3D0: jr          $ra
    // 0x806AF3D4: nop

    return;
    // 0x806AF3D4: nop

;}
RECOMP_FUNC void func_806D9928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D992C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9930: jal         0x806D98EC
    // 0x806D9934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D98EC(rdram, ctx);
        goto after_0;
    // 0x806D9934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D9938: bnel        $v0, $zero, L_806D9960
    if (ctx->r2 != 0) {
        // 0x806D993C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D9960;
    }
    goto skip_0;
    // 0x806D993C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D9940: jal         0x806D97BC
    // 0x806D9944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806D97BC(rdram, ctx);
        goto after_1;
    // 0x806D9944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806D9948: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D994C: bnel        $v0, $at, L_806D9960
    if (ctx->r2 != ctx->r1) {
        // 0x806D9950: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D9960;
    }
    goto skip_1;
    // 0x806D9950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806D9954: jal         0x800447C8
    // 0x806D9958: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x806D9958: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806D995C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D9960:
    // 0x806D9960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D9964: jr          $ra
    // 0x806D9968: nop

    return;
    // 0x806D9968: nop

;}
RECOMP_FUNC void func_806ADDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ADDC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ADDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ADDC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806ADDCC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806ADDD0: lw          $t6, 0x1E4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E4);
    // 0x806ADDD4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x806ADDD8: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x806ADDDC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x806ADDE0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x806ADDE4: jal         0x80067D5C
    // 0x806ADDE8: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x806ADDE8: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    after_0:
    // 0x806ADDEC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806ADDF0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806ADDF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806ADDF8: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    // 0x806ADDFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806ADE00: bne         $a1, $at, L_806ADE20
    if (ctx->r5 != ctx->r1) {
        // 0x806ADE04: nop
    
            goto L_806ADE20;
    }
    // 0x806ADE04: nop

    // 0x806ADE08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806ADE0C: jal         0x80067F78
    // 0x806ADE10: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x806ADE10: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x806ADE14: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806ADE18: b           L_806ADE28
    // 0x806ADE1C: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
        goto L_806ADE28;
    // 0x806ADE1C: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
L_806ADE20:
    // 0x806ADE20: jal         0x800678F0
    // 0x806ADE24: nop

    func_800678F0(rdram, ctx);
        goto after_2;
    // 0x806ADE24: nop

    after_2:
L_806ADE28:
    // 0x806ADE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ADE2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ADE30: jr          $ra
    // 0x806ADE34: nop

    return;
    // 0x806ADE34: nop

;}
RECOMP_FUNC void func_800310A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800310A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800310A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800310A8: jal         0x80042880
    // 0x800310AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80042880(rdram, ctx);
        goto after_0;
    // 0x800310AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800310B0: jal         0x80041D3C
    // 0x800310B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041D3C(rdram, ctx);
        goto after_1;
    // 0x800310B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800310B8: jal         0x8001EA24
    // 0x800310BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8001EA24(rdram, ctx);
        goto after_2;
    // 0x800310BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800310C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800310C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800310C8: jr          $ra
    // 0x800310CC: nop

    return;
    // 0x800310CC: nop

;}
RECOMP_FUNC void func_805AAF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AAF40: lui         $t6, 0x805B
    ctx->r14 = S32(RELOC_HI16(435, 0XA30) << 16);
    // 0x805AAF44: addiu       $t6, $t6, -0x4690
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(435, 0XA30));
    // 0x805AAF48: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805AAF4C: lui         $v0, 0x805B
    ctx->r2 = S32(RELOC_HI16(435, 0X960) << 16);
    // 0x805AAF50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805AAF54: sw          $t6, -0x7298($at)
    MEM_W(-0X7298, ctx->r1) = ctx->r14;
    // 0x805AAF58: jr          $ra
    // 0x805AAF5C: addiu       $v0, $v0, -0x4760
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(435, 0X960));
    return;
    // 0x805AAF5C: addiu       $v0, $v0, -0x4760
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(435, 0X960));
;}
RECOMP_FUNC void func_806D8DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D8DC4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806D8DC8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806D8DCC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806D8DD0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806D8DD4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D8DD8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806D8DDC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806D8DE0: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(625, 0X554) << 16);
    // 0x806D8DE4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806D8DE8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D8DEC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806D8DF0: lw          $t1, -0x71EC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(625, 0X554));
    // 0x806D8DF4: jr          $ra
    // 0x806D8DF8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806D8DF8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x806D8DFC: nop

;}
RECOMP_FUNC void func_80557AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557AA0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80557AA4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80557AA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80557AAC: lui         $t8, 0x8055
    ctx->r24 = S32(RELOC_HI16(360, 0X1A8) << 16);
    // 0x80557AB0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80557AB4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80557AB8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80557ABC: lw          $t8, 0x7AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(360, 0X1A8));
    // 0x80557AC0: jr          $ra
    // 0x80557AC4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80557AC4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80557AC8: nop

    // 0x80557ACC: nop

;}
RECOMP_FUNC void func_8002F3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F3FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F404: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F408: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002F40C: lw          $v1, 0x11C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X11C);
    // 0x8002F410: sltiu       $at, $v1, 0x7
    ctx->r1 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8002F414: bne         $at, $zero, L_8002F428
    if (ctx->r1 != 0) {
        // 0x8002F418: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_8002F428;
    }
    // 0x8002F418: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8002F41C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002F420: b           L_8002F438
    // 0x8002F424: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
        goto L_8002F438;
    // 0x8002F424: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
L_8002F428:
    // 0x8002F428: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002F42C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002F430: nop

    // 0x8002F434: swc1        $f6, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f6.u32l;
L_8002F438:
    // 0x8002F438: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8002F43C: jal         0x8002DB78
    // 0x8002F440: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8002DB78(rdram, ctx);
        goto after_0;
    // 0x8002F440: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8002F444: jal         0x8001D770
    // 0x8002F448: nop

    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x8002F448: nop

    after_1:
    // 0x8002F44C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002F450: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002F454: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x8002F458: jal         0x80067BF8
    // 0x8002F45C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x8002F45C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x8002F460: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x8002F464: jal         0x80067818
    // 0x8002F468: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8002F468: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8002F46C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F474: jr          $ra
    // 0x8002F478: nop

    return;
    // 0x8002F478: nop

;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008C844: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8008C848: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x8008C84C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008C850: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C854: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8008C858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C85C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008C860: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8008C864: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8008C868: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8008C86C: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x8008C870: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8008C874: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
    // 0x8008C878: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x8008C87C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C880: beq         $t4, $at, L_8008C8B0
    if (ctx->r12 == ctx->r1) {
        // 0x8008C884: nop
    
            goto L_8008C8B0;
    }
    // 0x8008C884: nop

    // 0x8008C888: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x8008C88C: blez        $t5, L_8008C8A0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8008C890: nop
    
            goto L_8008C8A0;
    }
    // 0x8008C890: nop

    // 0x8008C894: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008C898: b           L_8008C8D4
    // 0x8008C89C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_8008C8D4;
    // 0x8008C89C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_8008C8A0:
    // 0x8008C8A0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008C8A4: lw          $t9, 0x60($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X60);
    // 0x8008C8A8: b           L_8008C8D4
    // 0x8008C8AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_8008C8D4;
    // 0x8008C8AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_8008C8B0:
    // 0x8008C8B0: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x8008C8B4: blez        $t2, L_8008C8C8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8008C8B8: nop
    
            goto L_8008C8C8;
    }
    // 0x8008C8B8: nop

    // 0x8008C8BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008C8C0: b           L_8008C8D4
    // 0x8008C8C4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
        goto L_8008C8D4;
    // 0x8008C8C4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_8008C8C8:
    // 0x8008C8C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008C8CC: lw          $t0, 0x60($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X60);
    // 0x8008C8D0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_8008C8D4:
    // 0x8008C8D4: lbu         $t3, 0x25($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X25);
    // 0x8008C8D8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8008C8DC: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008C8E0: beq         $at, $zero, L_8008C900
    if (ctx->r1 == 0) {
        // 0x8008C8E4: nop
    
            goto L_8008C900;
    }
    // 0x8008C8E4: nop

    // 0x8008C8E8: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x8008C8EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C8F0: beq         $t5, $at, L_8008C900
    if (ctx->r13 == ctx->r1) {
        // 0x8008C8F4: nop
    
            goto L_8008C900;
    }
    // 0x8008C8F4: nop

    // 0x8008C8F8: b           L_8008CA78
    // 0x8008C8FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8008CA78;
    // 0x8008C8FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8008C900:
    // 0x8008C900: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x8008C904: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x8008C908: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8008C90C: sh          $at, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r1;
    // 0x8008C910: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008C914: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C918: bne         $t1, $at, L_8008C938
    if (ctx->r9 != ctx->r1) {
        // 0x8008C91C: nop
    
            goto L_8008C938;
    }
    // 0x8008C91C: nop

    // 0x8008C920: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x8008C924: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C928: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8008C92C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8008C930: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8008C934: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_8008C938:
    // 0x8008C938: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008C93C: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x8008C940: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8008C944: jal         0x8008CA88
    // 0x8008C948: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    __osBlockSum(rdram, ctx);
        goto after_0;
    // 0x8008C948: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x8008C94C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008C950: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C954: beq         $t9, $zero, L_8008C964
    if (ctx->r25 == 0) {
        // 0x8008C958: nop
    
            goto L_8008C964;
    }
    // 0x8008C958: nop

    // 0x8008C95C: b           L_8008CA78
    // 0x8008C960: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8008CA78;
    // 0x8008C960: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8008C964:
    // 0x8008C964: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x8008C968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C96C: bne         $t8, $at, L_8008C97C
    if (ctx->r24 != ctx->r1) {
        // 0x8008C970: nop
    
            goto L_8008C97C;
    }
    // 0x8008C970: nop

    // 0x8008C974: b           L_8008CA78
    // 0x8008C978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CA78;
    // 0x8008C978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C97C:
    // 0x8008C97C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008C980: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x8008C984: lw          $t1, 0x60($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X60);
    // 0x8008C988: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8008C98C: bne         $at, $zero, L_8008CA24
    if (ctx->r1 != 0) {
        // 0x8008C990: nop
    
            goto L_8008CA24;
    }
    // 0x8008C990: nop

L_8008C994:
    // 0x8008C994: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x8008C998: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x8008C99C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C9A0: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x8008C9A4: sh          $t3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r11;
    // 0x8008C9A8: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x8008C9AC: lhu         $at, 0x0($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X0);
    // 0x8008C9B0: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x8008C9B4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8008C9B8: sh          $at, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r1;
    // 0x8008C9BC: lbu         $t3, 0x21($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X21);
    // 0x8008C9C0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C9C4: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x8008C9C8: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x8008C9CC: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x8008C9D0: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    // 0x8008C9D4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8008C9D8: lbu         $a1, 0x21($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X21);
    // 0x8008C9DC: jal         0x8008CA88
    // 0x8008C9E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osBlockSum(rdram, ctx);
        goto after_1;
    // 0x8008C9E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8008C9E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008C9E8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C9EC: beq         $t5, $zero, L_8008C9FC
    if (ctx->r13 == 0) {
        // 0x8008C9F0: nop
    
            goto L_8008C9FC;
    }
    // 0x8008C9F0: nop

    // 0x8008C9F4: b           L_8008CA78
    // 0x8008C9F8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_8008CA78;
    // 0x8008C9F8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8008C9FC:
    // 0x8008C9FC: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x8008CA00: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x8008CA04: bne         $t8, $t0, L_8008CA24
    if (ctx->r24 != ctx->r8) {
        // 0x8008CA08: nop
    
            goto L_8008CA24;
    }
    // 0x8008CA08: nop

    // 0x8008CA0C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008CA10: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x8008CA14: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x8008CA18: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8008CA1C: beq         $at, $zero, L_8008C994
    if (ctx->r1 == 0) {
        // 0x8008CA20: nop
    
            goto L_8008C994;
    }
    // 0x8008CA20: nop

L_8008CA24:
    // 0x8008CA24: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008CA28: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x8008CA2C: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x8008CA30: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008CA34: bne         $at, $zero, L_8008CA64
    if (ctx->r1 != 0) {
        // 0x8008CA38: nop
    
            goto L_8008CA64;
    }
    // 0x8008CA38: nop

    // 0x8008CA3C: lbu         $t4, 0x24($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X24);
    // 0x8008CA40: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x8008CA44: bne         $t4, $t5, L_8008CA64
    if (ctx->r12 != ctx->r13) {
        // 0x8008CA48: nop
    
            goto L_8008CA64;
    }
    // 0x8008CA48: nop

    // 0x8008CA4C: lbu         $t2, 0x25($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X25);
    // 0x8008CA50: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CA54: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8008CA58: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x8008CA5C: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x8008CA60: sh          $t8, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r24;
L_8008CA64:
    // 0x8008CA64: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x8008CA68: lhu         $at, 0x0($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X0);
    // 0x8008CA6C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8008CA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008CA74: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
L_8008CA78:
    // 0x8008CA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CA7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008CA80: jr          $ra
    // 0x8008CA84: nop

    return;
    // 0x8008CA84: nop

;}
RECOMP_FUNC void func_80023EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023EA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80023EA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023EA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80023EAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80023EB0: lwc1        $f14, 0xDC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80023EB4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80023EB8: lwc1        $f4, 0xE0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80023EBC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80023EC0: c.eq.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl == ctx->f6.fl;
    // 0x80023EC4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80023EC8: lwc1        $f0, 0xE8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x80023ECC: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x80023ED0: bc1tl       L_80023F20
    if (c1cs) {
        // 0x80023ED4: lwc1        $f12, 0x0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80023F20;
    }
    goto skip_0;
    // 0x80023ED4: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80023ED8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023EDC: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x80023EE0: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x80023EE4: nop

    // 0x80023EE8: bc1fl       L_80023F0C
    if (!c1cs) {
        // 0x80023EEC: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_80023F0C;
    }
    goto skip_1;
    // 0x80023EEC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x80023EF0: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x80023EF4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80023EF8: jal         0x80023DD0
    // 0x80023EFC: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80023DD0(rdram, ctx);
        goto after_0;
    // 0x80023EFC: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80023F00: b           L_80023F14
    // 0x80023F04: nop

        goto L_80023F14;
    // 0x80023F04: nop

    // 0x80023F08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80023F0C:
    // 0x80023F0C: jal         0x80023E18
    // 0x80023F10: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80023E18(rdram, ctx);
        goto after_1;
    // 0x80023F10: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_1:
L_80023F14:
    // 0x80023F14: b           L_80023F5C
    // 0x80023F18: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_80023F5C;
    // 0x80023F18: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80023F1C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
L_80023F20:
    // 0x80023F20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023F24: nop

    // 0x80023F28: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80023F2C: nop

    // 0x80023F30: bc1fl       L_80023F50
    if (!c1cs) {
        // 0x80023F34: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_80023F50;
    }
    goto skip_2;
    // 0x80023F34: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_2:
    // 0x80023F38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80023F3C: jal         0x80023DD0
    // 0x80023F40: nop

    func_80023DD0(rdram, ctx);
        goto after_2;
    // 0x80023F40: nop

    after_2:
    // 0x80023F44: b           L_80023F5C
    // 0x80023F48: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_80023F5C;
    // 0x80023F48: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80023F4C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80023F50:
    // 0x80023F50: jal         0x80023E18
    // 0x80023F54: nop

    func_80023E18(rdram, ctx);
        goto after_3;
    // 0x80023F54: nop

    after_3:
    // 0x80023F58: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80023F5C:
    // 0x80023F5C: addiu       $s0, $s1, 0xC8
    ctx->r16 = ADD32(ctx->r17, 0XC8);
    // 0x80023F60: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80023F64: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80023F68: jal         0x80023DD0
    // 0x80023F6C: lw          $a2, 0xEC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XEC);
    func_80023DD0(rdram, ctx);
        goto after_4;
    // 0x80023F6C: lw          $a2, 0xEC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XEC);
    after_4:
    // 0x80023F70: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80023F74: jal         0x80023E64
    // 0x80023F78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80023E64(rdram, ctx);
        goto after_5;
    // 0x80023F78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80023F7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023F80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80023F84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80023F88: jr          $ra
    // 0x80023F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80023F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8069A088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069A088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069A08C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069A090: jal         0x80699C60
    // 0x8069A094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x8069A094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069A098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069A09C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069A0A0: jal         0x8069A0F0
    // 0x8069A0A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x8069A0A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8069A0A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069A0AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069A0B0: jr          $ra
    // 0x8069A0B4: nop

    return;
    // 0x8069A0B4: nop

;}
RECOMP_FUNC void func_80474F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474F40: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474F44: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474F48: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474F4C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474F50: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474F54: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474F58: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474F5C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474F60: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474F64: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474F68: jr          $ra
    // 0x80474F6C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474F6C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F2D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2D54: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806F2D58: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(679, 0X1700) << 16);
    // 0x806F2D5C: addiu       $t6, $t6, 0x2C80
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(679, 0X1700));
    // 0x806F2D60: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F2D64: jr          $ra
    // 0x806F2D68: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806F2D68: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806CF7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CF7A0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806CF7A4: addiu       $at, $zero, 0x45A6
    ctx->r1 = ADD32(0, 0X45A6);
    // 0x806CF7A8: beq         $v0, $at, L_806CF7C0
    if (ctx->r2 == ctx->r1) {
        // 0x806CF7AC: addiu       $at, $zero, 0x45A7
        ctx->r1 = ADD32(0, 0X45A7);
            goto L_806CF7C0;
    }
    // 0x806CF7AC: addiu       $at, $zero, 0x45A7
    ctx->r1 = ADD32(0, 0X45A7);
    // 0x806CF7B0: beq         $v0, $at, L_806CF7CC
    if (ctx->r2 == ctx->r1) {
        // 0x806CF7B4: nop
    
            goto L_806CF7CC;
    }
    // 0x806CF7B4: nop

    // 0x806CF7B8: b           L_806CF7D8
    // 0x806CF7BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806CF7D8;
    // 0x806CF7BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806CF7C0:
    // 0x806CF7C0: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(607, 0X16A0) << 16);
    // 0x806CF7C4: jr          $ra
    // 0x806CF7C8: addiu       $v0, $v0, 0xE40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(607, 0X16A0));
    return;
    // 0x806CF7C8: addiu       $v0, $v0, 0xE40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(607, 0X16A0));
L_806CF7CC:
    // 0x806CF7CC: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(607, 0X1108) << 16);
    // 0x806CF7D0: jr          $ra
    // 0x806CF7D4: addiu       $v0, $v0, 0x8A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(607, 0X1108));
    return;
    // 0x806CF7D4: addiu       $v0, $v0, 0x8A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(607, 0X1108));
L_806CF7D8:
    // 0x806CF7D8: jr          $ra
    // 0x806CF7DC: nop

    return;
    // 0x806CF7DC: nop

;}
RECOMP_FUNC void func_804A4430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4430: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804A4434: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x804A4438: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x804A443C: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x804A4440: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x804A4444: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x804A4448: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804A444C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804A4450: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804A4454: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804A4458: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804A445C: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A4460: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804A4464: lwc1        $f26, 0x3C($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A4468: addiu       $s0, $v0, 0x188
    ctx->r16 = ADD32(ctx->r2, 0X188);
    // 0x804A446C: lwc1        $f28, 0x40($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A4470: bne         $s0, $zero, L_804A4480
    if (ctx->r16 != 0) {
        // 0x804A4474: lh          $s1, 0x184($v0)
        ctx->r17 = MEM_H(ctx->r2, 0X184);
            goto L_804A4480;
    }
    // 0x804A4474: lh          $s1, 0x184($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X184);
    // 0x804A4478: b           L_804A452C
    // 0x804A447C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_804A452C;
    // 0x804A447C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_804A4480:
    // 0x804A4480: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A4484: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804A4488: beq         $s1, $zero, L_804A4508
    if (ctx->r17 == 0) {
        // 0x804A448C: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_804A4508;
    }
    // 0x804A448C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_804A4490:
    // 0x804A4490: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804A4494: beq         $v0, $zero, L_804A4500
    if (ctx->r2 == 0) {
        // 0x804A4498: nop
    
            goto L_804A4500;
    }
    // 0x804A4498: nop

    // 0x804A449C: lwc1        $f14, 0x3C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A44A0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x804A44A4: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x804A44A8: c.lt.s      $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f26.fl < ctx->f14.fl;
    // 0x804A44AC: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804A44B0: lwc1        $f20, 0x40($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A44B4: bc1t        L_804A44CC
    if (c1cs) {
        // 0x804A44B8: nop
    
            goto L_804A44CC;
    }
    // 0x804A44B8: nop

    // 0x804A44BC: c.lt.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl < ctx->f20.fl;
    // 0x804A44C0: nop

    // 0x804A44C4: bc1f        L_804A4500
    if (!c1cs) {
        // 0x804A44C8: nop
    
            goto L_804A4500;
    }
    // 0x804A44C8: nop

L_804A44CC:
    // 0x804A44CC: jal         0x804A3C08
    // 0x804A44D0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_804A3C08(rdram, ctx);
        goto after_0;
    // 0x804A44D0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_0:
    // 0x804A44D4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804A44D8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x804A44DC: jal         0x804A3C08
    // 0x804A44E0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_804A3C08(rdram, ctx);
        goto after_1;
    // 0x804A44E0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x804A44E4: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804A44E8: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x804A44EC: nop

    // 0x804A44F0: bc1f        L_804A4500
    if (!c1cs) {
        // 0x804A44F4: nop
    
            goto L_804A4500;
    }
    // 0x804A44F4: nop

    // 0x804A44F8: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804A44FC: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_804A4500:
    // 0x804A4500: bne         $s1, $zero, L_804A4490
    if (ctx->r17 != 0) {
        // 0x804A4504: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804A4490;
    }
    // 0x804A4504: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804A4508:
    // 0x804A4508: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A450C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A4510: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x804A4514: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x804A4518: nop

    // 0x804A451C: bc1f        L_804A452C
    if (!c1cs) {
        // 0x804A4520: nop
    
            goto L_804A452C;
    }
    // 0x804A4520: nop

    // 0x804A4524: b           L_804A452C
    // 0x804A4528: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_804A452C;
    // 0x804A4528: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_804A452C:
    // 0x804A452C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x804A4530: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804A4534: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804A4538: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804A453C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804A4540: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804A4544: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x804A4548: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x804A454C: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x804A4550: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x804A4554: jr          $ra
    // 0x804A4558: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804A4558: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80076B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B50: lui         $t0, 0xF900
    ctx->r8 = S32(0XF900 << 16);
    // 0x80076B54: lui         $t1, 0xEE00
    ctx->r9 = S32(0XEE00 << 16);
    // 0x80076B58: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80076B5C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80076B60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076B64: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80076B68: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80076B6C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076B70: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076B74: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80076B78: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076B7C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80076B80: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80076B84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076B88: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80076B8C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80076B90: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076B94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076B98: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80076B9C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076BA0: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80076BA4: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80076BA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80076BAC: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80076BB0: addiu       $t9, $t9, -0x7AD0
    ctx->r25 = ADD32(ctx->r25, -0X7AD0);
    // 0x80076BB4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80076BB8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80076BBC: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x80076BC0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076BC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076BC8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80076BCC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80076BD0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80076BD4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076BD8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80076BDC: jr          $ra
    // 0x80076BE0: nop

    return;
    // 0x80076BE0: nop

    // 0x80076BE4: nop

    // 0x80076BE8: nop

    // 0x80076BEC: nop

;}
RECOMP_FUNC void func_8079A4B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A4B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079A4B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079A4BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079A4C0: jal         0x80799B68
    // 0x8079A4C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80799B68(rdram, ctx);
        goto after_0;
    // 0x8079A4C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8079A4C8: jal         0x80799BE0
    // 0x8079A4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80799BE0(rdram, ctx);
        goto after_1;
    // 0x8079A4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8079A4D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079A4D4: jal         0x80062684
    // 0x8079A4D8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062684(rdram, ctx);
        goto after_2;
    // 0x8079A4D8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x8079A4DC: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8079A4E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079A4E4: blez        $t6, L_8079A50C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8079A4E8: nop
    
            goto L_8079A50C;
    }
    // 0x8079A4E8: nop

    // 0x8079A4EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8079A4F0: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x8079A4F4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8079A4F8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8079A4FC: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x8079A500: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8079A504: b           L_8079A53C
    // 0x8079A508: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
        goto L_8079A53C;
    // 0x8079A508: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_8079A50C:
    // 0x8079A50C: jal         0x80799DF0
    // 0x8079A510: addiu       $a1, $zero, 0x4034
    ctx->r5 = ADD32(0, 0X4034);
    func_80799DF0(rdram, ctx);
        goto after_3;
    // 0x8079A510: addiu       $a1, $zero, 0x4034
    ctx->r5 = ADD32(0, 0X4034);
    after_3:
    // 0x8079A514: jal         0x80067E68
    // 0x8079A518: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_4;
    // 0x8079A518: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8079A51C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8079A520: jal         0x80067818
    // 0x8079A524: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8079A524: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8079A528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079A52C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079A530: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8079A534: jal         0x8079AEDC
    // 0x8079A538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079AEDC(rdram, ctx);
        goto after_6;
    // 0x8079A538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
L_8079A53C:
    // 0x8079A53C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079A540: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079A544: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079A548: jr          $ra
    // 0x8079A54C: nop

    return;
    // 0x8079A54C: nop

;}
RECOMP_FUNC void func_8057E7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057E7D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057E7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057E7DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8057E7E0: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8057E7E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8057E7E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8057E7EC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8057E7F0: addiu       $v0, $a1, 0x208
    ctx->r2 = ADD32(ctx->r5, 0X208);
    // 0x8057E7F4: bc1fl       L_8057E87C
    if (!c1cs) {
        // 0x8057E7F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057E87C;
    }
    goto skip_0;
    // 0x8057E7F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057E7FC: lwc1        $f6, 0x2C4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C4);
    // 0x8057E800: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8057E804: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8057E808: nop

    // 0x8057E80C: bc1fl       L_8057E87C
    if (!c1cs) {
        // 0x8057E810: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057E87C;
    }
    goto skip_1;
    // 0x8057E810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8057E814: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8057E818: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x8057E81C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8057E820: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8057E824: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057E828: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8057E82C: lwc1        $f16, 0x2C4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C4);
    // 0x8057E830: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x8057E834: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8057E838: addiu       $a1, $a3, 0x3C
    ctx->r5 = ADD32(ctx->r7, 0X3C);
    // 0x8057E83C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8057E840: jal         0x8057DD6C
    // 0x8057E844: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8057DD6C(rdram, ctx);
        goto after_0;
    // 0x8057E844: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8057E848: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8057E84C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8057E850: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8057E854: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8057E858: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8057E85C: sw          $zero, 0x2B4($a2)
    MEM_W(0X2B4, ctx->r6) = 0;
    // 0x8057E860: sw          $t6, 0x2CC($a2)
    MEM_W(0X2CC, ctx->r6) = ctx->r14;
    // 0x8057E864: swc1        $f18, 0x2D0($a2)
    MEM_W(0X2D0, ctx->r6) = ctx->f18.u32l;
    // 0x8057E868: sw          $zero, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = 0;
    // 0x8057E86C: lw          $t7, 0x2C8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X2C8);
    // 0x8057E870: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8057E874: sw          $t8, 0x2C8($a2)
    MEM_W(0X2C8, ctx->r6) = ctx->r24;
    // 0x8057E878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057E87C:
    // 0x8057E87C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057E880: jr          $ra
    // 0x8057E884: nop

    return;
    // 0x8057E884: nop

;}
RECOMP_FUNC void func_806E41C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E41C4: jr          $ra
    // 0x806E41C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806E41C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804459C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804459C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804459CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804459D0: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x804459D4: jal         0x80067818
    // 0x804459D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x804459D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804459DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804459E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804459E4: jr          $ra
    // 0x804459E8: nop

    return;
    // 0x804459E8: nop

;}
RECOMP_FUNC void func_80474B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474B18: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80474B1C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80474B20: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80474B24: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80474B28: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80474B2C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80474B30: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80474B34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80474B38: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80474B3C: lw          $t6, 0x6D10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X6D10);
    // 0x80474B40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80474B44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80474B48: beq         $t6, $at, L_80474B94
    if (ctx->r14 == ctx->r1) {
        // 0x80474B4C: addiu       $a1, $zero, 0x21C
        ctx->r5 = ADD32(0, 0X21C);
            goto L_80474B94;
    }
    // 0x80474B4C: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x80474B50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474B54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80474B58: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X294F8) << 16);
    // 0x80474B5C: lwc1        $f4, -0x2348($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X294F8));
    // 0x80474B60: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80474B64: addiu       $t7, $zero, 0x1D10
    ctx->r15 = ADD32(0, 0X1D10);
    // 0x80474B68: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80474B6C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80474B70: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x80474B74: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80474B78: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80474B7C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80474B80: jal         0x804747CC
    // 0x80474B84: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_804747CC(rdram, ctx);
        goto after_0;
    // 0x80474B84: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80474B88: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80474B8C: b           L_80474BE4
    // 0x80474B90: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_80474BE4;
    // 0x80474B90: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80474B94:
    // 0x80474B94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474B98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80474B9C: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X294FC) << 16);
    // 0x80474BA0: lwc1        $f8, -0x2344($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X294FC));
    // 0x80474BA4: lwc1        $f0, 0x6AA0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6AA0);
    // 0x80474BA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474BAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80474BB0: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X29500) << 16);
    // 0x80474BB4: lwc1        $f16, -0x2340($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X29500));
    // 0x80474BB8: addiu       $t8, $zero, 0x1D10
    ctx->r24 = ADD32(0, 0X1D10);
    // 0x80474BBC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80474BC0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80474BC4: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80474BC8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80474BCC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80474BD0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80474BD4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80474BD8: jal         0x804748D0
    // 0x80474BDC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_804748D0(rdram, ctx);
        goto after_1;
    // 0x80474BDC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80474BE0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_80474BE4:
    // 0x80474BE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474BE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80474BEC: nop

    // 0x80474BF0: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80474BF4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80474BF8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80474BFC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80474C00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80474C04: jr          $ra
    // 0x80474C08: nop

    return;
    // 0x80474C08: nop

;}
RECOMP_FUNC void func_804CC79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC79C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CC7A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CC7A4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804CC7A8: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804CC7AC: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804CC7B0: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(237, 0X1C44) << 16);
    // 0x804CC7B4: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x804CC7B8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804CC7BC: addiu       $t7, $t7, -0x1F4C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(237, 0X1C44));
    // 0x804CC7C0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804CC7C4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804CC7C8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804CC7CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CC7D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CC7D4: jal         0x804CC7F4
    // 0x804CC7D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804CC7F4(rdram, ctx);
        goto after_0;
    // 0x804CC7D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804CC7DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CC7E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CC7E4: jr          $ra
    // 0x804CC7E8: nop

    return;
    // 0x804CC7E8: nop

;}
RECOMP_FUNC void func_80742898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742898: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8074289C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807428A0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x807428A4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x807428A8: addu        $t0, $v0, $at
    ctx->r8 = ADD32(ctx->r2, ctx->r1);
    // 0x807428AC: lw          $v1, 0x6E6C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6E6C);
    // 0x807428B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807428B4: lw          $t1, 0x6E68($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6E68);
    // 0x807428B8: bne         $v1, $at, L_807428C8
    if (ctx->r3 != ctx->r1) {
        // 0x807428BC: nop
    
            goto L_807428C8;
    }
    // 0x807428BC: nop

    // 0x807428C0: beq         $t1, $zero, L_807428D8
    if (ctx->r9 == 0) {
        // 0x807428C4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_807428D8;
    }
    // 0x807428C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_807428C8:
    // 0x807428C8: jal         0x807424D8
    // 0x807428CC: nop

    func_807424D8(rdram, ctx);
        goto after_0;
    // 0x807428CC: nop

    after_0:
    // 0x807428D0: b           L_80742938
    // 0x807428D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742938;
    // 0x807428D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807428D8:
    // 0x807428D8: lwc1        $f12, 0x6BE4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X6BE4);
    // 0x807428DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807428E0: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x807428E4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x807428E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807428EC: jal         0x80742308
    // 0x807428F0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80742308(rdram, ctx);
        goto after_1;
    // 0x807428F0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x807428F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807428F8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807428FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742900: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80742904: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80742908: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8074290C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80742910: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80742914: jal         0x80742354
    // 0x80742918: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    func_80742354(rdram, ctx);
        goto after_2;
    // 0x80742918: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_2:
    // 0x8074291C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80742920: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742924: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80742928: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8074292C: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80742930: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80742934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742938:
    // 0x80742938: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8074293C: jr          $ra
    // 0x80742940: nop

    return;
    // 0x80742940: nop

;}
RECOMP_FUNC void func_8079E268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079E268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079E26C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8079E270: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8079E274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079E278: sb          $v0, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = ctx->r2;
    // 0x8079E27C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8079E280: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(835, 0X1720) << 16);
    // 0x8079E284: sb          $v0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r2;
    // 0x8079E288: addiu       $t6, $t6, -0xDF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(835, 0X1720));
    // 0x8079E28C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8079E290: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8079E294: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8079E298: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8079E29C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8079E2A0: jal         0x80045A34
    // 0x8079E2A4: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8079E2A4: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_0:
    // 0x8079E2A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079E2AC: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(835, 0X10) << 16);
    // 0x8079E2B0: addiu       $t9, $t9, -0x2500
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(835, 0X10));
    // 0x8079E2B4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8079E2B8: jal         0x8079DEA0
    // 0x8079E2BC: sw          $t9, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r25;
    func_8079DEA0(rdram, ctx);
        goto after_1;
    // 0x8079E2BC: sw          $t9, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r25;
    after_1:
    // 0x8079E2C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079E2C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079E2C8: jal         0x8079F1C0
    // 0x8079E2CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8079F1C0(rdram, ctx);
        goto after_2;
    // 0x8079E2CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8079E2D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079E2D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8079E2D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079E2DC: sw          $t0, -0x7478($at)
    MEM_W(-0X7478, ctx->r1) = ctx->r8;
    // 0x8079E2E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8079E2E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8079E2E8: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x8079E2EC: jr          $ra
    // 0x8079E2F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8079E2F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804A3AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3AB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A3AB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A3AB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A3ABC: lh          $t7, 0x144($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X144);
    // 0x804A3AC0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A3AC4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x804A3AC8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x804A3ACC: lw          $s0, 0x4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X4);
    // 0x804A3AD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804A3AD4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804A3AD8: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x804A3ADC: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x804A3AE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804A3AE4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x804A3AE8: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x804A3AEC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804A3AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A3AF4: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x804A3AF8: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804A3AFC: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
    // 0x804A3B00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804A3B04: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x804A3B08: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x804A3B0C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804A3B10: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x804A3B14: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x804A3B18: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x804A3B1C: bne         $t8, $zero, L_804A3B7C
    if (ctx->r24 != 0) {
        // 0x804A3B20: swc1        $f10, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
            goto L_804A3B7C;
    }
    // 0x804A3B20: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x804A3B24: lw          $t9, -0x71E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X71E0);
    // 0x804A3B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A3B2C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x804A3B30: bnel        $t9, $zero, L_804A3B58
    if (ctx->r25 != 0) {
        // 0x804A3B34: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_804A3B58;
    }
    goto skip_0;
    // 0x804A3B34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x804A3B38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A3B3C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804A3B40: jal         0x804A491C
    // 0x804A3B44: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_804A491C(rdram, ctx);
        goto after_0;
    // 0x804A3B44: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x804A3B48: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804A3B4C: b           L_804A3B64
    // 0x804A3B50: sb          $zero, 0x165($a3)
    MEM_B(0X165, ctx->r7) = 0;
        goto L_804A3B64;
    // 0x804A3B50: sb          $zero, 0x165($a3)
    MEM_B(0X165, ctx->r7) = 0;
    // 0x804A3B54: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_804A3B58:
    // 0x804A3B58: jal         0x804A491C
    // 0x804A3B5C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_804A491C(rdram, ctx);
        goto after_1;
    // 0x804A3B5C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x804A3B60: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_804A3B64:
    // 0x804A3B64: jal         0x804A4960
    // 0x804A3B68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_804A4960(rdram, ctx);
        goto after_2;
    // 0x804A3B68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x804A3B6C: jal         0x804A3A9C
    // 0x804A3B70: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    func_804A3A9C(rdram, ctx);
        goto after_3;
    // 0x804A3B70: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    after_3:
    // 0x804A3B74: b           L_804A3B88
    // 0x804A3B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804A3B88;
    // 0x804A3B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A3B7C:
    // 0x804A3B7C: jal         0x80047F9C
    // 0x804A3B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x804A3B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804A3B84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A3B88:
    // 0x804A3B88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804A3B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804A3B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A3B94: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804A3B98: jr          $ra
    // 0x804A3B9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x804A3B9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8070F428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070F428: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8070F42C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8070F430: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x8070F434: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8070F438: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8070F43C: lw          $t9, 0x1F4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1F4);
    // 0x8070F440: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8070F444: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8070F448: lw          $t1, 0x1F4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1F4);
    // 0x8070F44C: jr          $ra
    // 0x8070F450: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    return;
    // 0x8070F450: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
;}
RECOMP_FUNC void func_8003F6E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F6E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003F6E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003F6EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003F6F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003F6F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8003F6F8: jal         0x8003EBD4
    // 0x8003F6FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EBD4(rdram, ctx);
        goto after_0;
    // 0x8003F6FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003F700: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003F704: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x8003F708: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8003F70C: jalr        $t9
    // 0x8003F710: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8003F710: nop

    after_1:
    // 0x8003F714: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003F718: addiu       $t6, $t6, -0x1A14
    ctx->r14 = ADD32(ctx->r14, -0X1A14);
    // 0x8003F71C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F720: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F724: lhu         $a1, 0x2A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2A);
    // 0x8003F728: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003F72C: jal         0x8003E6C4
    // 0x8003F730: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8003E6C4(rdram, ctx);
        goto after_2;
    // 0x8003F730: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8003F734: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8003F738: addiu       $a2, $a2, -0x7C48
    ctx->r6 = ADD32(ctx->r6, -0X7C48);
    // 0x8003F73C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003F740: jal         0x8003F14C
    // 0x8003F744: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8003F14C(rdram, ctx);
        goto after_3;
    // 0x8003F744: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8003F748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F74C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003F750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F754: jr          $ra
    // 0x8003F758: nop

    return;
    // 0x8003F758: nop

;}
RECOMP_FUNC void func_8042EC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EC04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042EC08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042EC0C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042EC10: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8042EC14: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X33F0) << 16);
    // 0x8042EC18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042EC1C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042EC20: lw          $t8, 0x14D0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X33F0));
    // 0x8042EC24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042EC28: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8042EC2C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8042EC30: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8042EC34: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042EC38: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8042EC3C: beql        $v1, $zero, L_8042EC70
    if (ctx->r3 == 0) {
        // 0x8042EC40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042EC70;
    }
    goto skip_0;
    // 0x8042EC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042EC44: jalr        $v1
    // 0x8042EC48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042EC48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042EC4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042EC50: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8042EC54: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042EC58: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8042EC5C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8042EC60: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8042EC64: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042EC68: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8042EC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042EC70:
    // 0x8042EC70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042EC74: jr          $ra
    // 0x8042EC78: nop

    return;
    // 0x8042EC78: nop

;}
RECOMP_FUNC void func_804F3AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F3AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F3AC8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x804F3ACC: beql        $a1, $zero, L_804F3AE0
    if (ctx->r5 == 0) {
        // 0x804F3AD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804F3AE0;
    }
    goto skip_0;
    // 0x804F3AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804F3AD4: jal         0x800568E0
    // 0x804F3AD8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x804F3AD8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x804F3ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F3AE0:
    // 0x804F3AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F3AE4: jr          $ra
    // 0x804F3AE8: nop

    return;
    // 0x804F3AE8: nop

;}
RECOMP_FUNC void func_800669C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800669C0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800669C4: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800669C8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800669CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800669D0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800669D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800669D8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_800669DC:
    // 0x800669DC: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800669E0: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800669E4: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800669E8: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800669EC: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800669F0: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800669F4: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800669F8: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800669FC: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80066A00: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80066A04: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80066A08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066A0C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80066A10: mul.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80066A14: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80066A18: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80066A1C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80066A20: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80066A24: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80066A28: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80066A2C: add.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80066A30: bne         $v0, $t0, L_800669DC
    if (ctx->r2 != ctx->r8) {
        // 0x80066A34: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800669DC;
    }
    // 0x80066A34: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80066A38: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80066A3C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80066A40: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80066A44: jr          $ra
    // 0x80066A48: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80066A48: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005DBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DBF0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8005DBF4: lh          $t6, 0x78($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X78);
    // 0x8005DBF8: lh          $t0, 0x7C($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X7C);
    // 0x8005DBFC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8005DC00: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005DC04: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8005DC08: lw          $t8, 0x80($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X80);
    // 0x8005DC0C: mflo        $t7
    ctx->r15 = lo;
    // 0x8005DC10: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005DC14: nop

    // 0x8005DC18: multu       $t0, $a3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005DC1C: mflo        $t1
    ctx->r9 = lo;
    // 0x8005DC20: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8005DC24: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x8005DC28: lw          $t3, 0x84($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X84);
    // 0x8005DC2C: jr          $ra
    // 0x8005DC30: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    return;
    // 0x8005DC30: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void func_806A97C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A97C0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x806A97C4: addiu       $at, $zero, 0x4598
    ctx->r1 = ADD32(0, 0X4598);
    // 0x806A97C8: lui         $v0, 0x806B
    ctx->r2 = S32(RELOC_HI16(589, 0XCD0) << 16);
    // 0x806A97CC: bne         $t6, $at, L_806A97E0
    if (ctx->r14 != ctx->r1) {
        // 0x806A97D0: addiu       $v0, $v0, -0x5B70
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(589, 0XCD0));
            goto L_806A97E0;
    }
    // 0x806A97D0: addiu       $v0, $v0, -0x5B70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(589, 0XCD0));
    // 0x806A97D4: lui         $v0, 0x806B
    ctx->r2 = S32(RELOC_HI16(589, 0XDD0) << 16);
    // 0x806A97D8: jr          $ra
    // 0x806A97DC: addiu       $v0, $v0, -0x5A70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(589, 0XDD0));
    return;
    // 0x806A97DC: addiu       $v0, $v0, -0x5A70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(589, 0XDD0));
L_806A97E0:
    // 0x806A97E0: jr          $ra
    // 0x806A97E4: nop

    return;
    // 0x806A97E4: nop

;}
RECOMP_FUNC void func_807AB2EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AB2EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AB2F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AB2F4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807AB2F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AB2FC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807AB300: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(853, 0X1BA0) << 16);
    // 0x807AB304: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807AB308: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807AB30C: addiu       $t6, $t6, -0x4820
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(853, 0X1BA0));
    // 0x807AB310: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x807AB314: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807AB318: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AB31C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807AB320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807AB324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AB328: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807AB32C: jal         0x807AB3EC
    // 0x807AB330: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807AB3EC(rdram, ctx);
        goto after_0;
    // 0x807AB330: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x807AB334: jal         0x807AB2BC
    // 0x807AB338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807AB2BC(rdram, ctx);
        goto after_1;
    // 0x807AB338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807AB33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AB340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AB344: jr          $ra
    // 0x807AB348: nop

    return;
    // 0x807AB348: nop

;}
RECOMP_FUNC void osSyncPrintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    yoshi_sync_printf(rdram, ctx);
    // 0x8008AD5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008AD60: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8008AD64: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8008AD68: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8008AD6C: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8008AD70: jr          $ra
    // 0x8008AD74: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008AD74: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006AA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AA74: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8006AA78: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8006AA7C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006AA80: lh          $v1, 0x12($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X12);
    // 0x8006AA84: bltz        $a3, L_8006AA9C
    if (SIGNED(ctx->r7) < 0) {
        // 0x8006AA88: lw          $t0, 0x18($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X18);
            goto L_8006AA9C;
    }
    // 0x8006AA88: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x8006AA8C: lh          $v0, 0x12($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X12);
    // 0x8006AA90: sra         $t6, $a3, 4
    ctx->r14 = S32(SIGNED(ctx->r7) >> 4);
    // 0x8006AA94: bgez        $v0, L_8006AAA4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006AA98: sra         $t7, $v0, 4
        ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
            goto L_8006AAA4;
    }
    // 0x8006AA98: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
L_8006AA9C:
    // 0x8006AA9C: jr          $ra
    // 0x8006AAA0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x8006AAA0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006AAA4:
    // 0x8006AAA4: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    // 0x8006AAA8: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x8006AAAC: lbu         $t8, 0x28($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X28);
    // 0x8006AAB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006AAB4: bnel        $t8, $at, L_8006AB38
    if (ctx->r24 != ctx->r1) {
        // 0x8006AAB8: lbu         $a3, 0x0($a1)
        ctx->r7 = MEM_BU(ctx->r5, 0X0);
            goto L_8006AB38;
    }
    goto skip_0;
    // 0x8006AAB8: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x8006AABC: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8006AAC0: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x8006AAC4: mfhi        $t2
    ctx->r10 = hi;
    // 0x8006AAC8: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
    // 0x8006AACC: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x8006AAD0: lh          $t4, 0x14($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X14);
    // 0x8006AAD4: bne         $v1, $zero, L_8006AAE0
    if (ctx->r3 != 0) {
        // 0x8006AAD8: nop
    
            goto L_8006AAE0;
    }
    // 0x8006AAD8: nop

    // 0x8006AADC: break       7
    do_break(2147920604);
L_8006AAE0:
    // 0x8006AAE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006AAE4: bne         $v1, $at, L_8006AAF8
    if (ctx->r3 != ctx->r1) {
        // 0x8006AAE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006AAF8;
    }
    // 0x8006AAE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006AAEC: bne         $t9, $at, L_8006AAF8
    if (ctx->r25 != ctx->r1) {
        // 0x8006AAF0: nop
    
            goto L_8006AAF8;
    }
    // 0x8006AAF0: nop

    // 0x8006AAF4: break       6
    do_break(2147920628);
L_8006AAF8:
    // 0x8006AAF8: div         $zero, $t3, $t4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r12)));
    // 0x8006AAFC: mfhi        $t5
    ctx->r13 = hi;
    // 0x8006AB00: sb          $t5, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r13;
    // 0x8006AB04: bne         $t4, $zero, L_8006AB10
    if (ctx->r12 != 0) {
        // 0x8006AB08: nop
    
            goto L_8006AB10;
    }
    // 0x8006AB08: nop

    // 0x8006AB0C: break       7
    do_break(2147920652);
L_8006AB10:
    // 0x8006AB10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006AB14: bne         $t4, $at, L_8006AB28
    if (ctx->r12 != ctx->r1) {
        // 0x8006AB18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006AB28;
    }
    // 0x8006AB18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006AB1C: bne         $t3, $at, L_8006AB28
    if (ctx->r11 != ctx->r1) {
        // 0x8006AB20: nop
    
            goto L_8006AB28;
    }
    // 0x8006AB20: nop

    // 0x8006AB24: break       6
    do_break(2147920676);
L_8006AB28:
    // 0x8006AB28: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
    // 0x8006AB2C: b           L_8006AB60
    // 0x8006AB30: andi        $t1, $t5, 0xFF
    ctx->r9 = ctx->r13 & 0XFF;
        goto L_8006AB60;
    // 0x8006AB30: andi        $t1, $t5, 0xFF
    ctx->r9 = ctx->r13 & 0XFF;
    // 0x8006AB34: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
L_8006AB38:
    // 0x8006AB38: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006AB3C: beq         $at, $zero, L_8006AB58
    if (ctx->r1 == 0) {
        // 0x8006AB40: nop
    
            goto L_8006AB58;
    }
    // 0x8006AB40: nop

    // 0x8006AB44: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x8006AB48: lh          $t6, 0x14($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X14);
    // 0x8006AB4C: slt         $at, $t1, $t6
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006AB50: bne         $at, $zero, L_8006AB60
    if (ctx->r1 != 0) {
        // 0x8006AB54: nop
    
            goto L_8006AB60;
    }
    // 0x8006AB54: nop

L_8006AB58:
    // 0x8006AB58: jr          $ra
    // 0x8006AB5C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x8006AB5C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006AB60:
    // 0x8006AB60: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AB64: mflo        $t7
    ctx->r15 = lo;
    // 0x8006AB68: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x8006AB6C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x8006AB70: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x8006AB74: jr          $ra
    // 0x8006AB78: nop

    return;
    // 0x8006AB78: nop

;}
RECOMP_FUNC void func_80709540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80709544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80709548: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070954C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80709550: bnel        $t6, $zero, L_80709578
    if (ctx->r14 != 0) {
        // 0x80709554: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80709578;
    }
    goto skip_0;
    // 0x80709554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80709558: jal         0x80045A34
    // 0x8070955C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8070955C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80709560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80709564: bne         $v0, $zero, L_80709574
    if (ctx->r2 != 0) {
        // 0x80709568: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80709574;
    }
    // 0x80709568: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8070956C: b           L_80709578
    // 0x80709570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80709578;
    // 0x80709570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80709574:
    // 0x80709574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80709578:
    // 0x80709578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070957C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80709580: jr          $ra
    // 0x80709584: nop

    return;
    // 0x80709584: nop

;}
RECOMP_FUNC void func_80527BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527BAC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80527BB0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X619C) << 16);
    // 0x80527BB4: lwc1        $f6, -0x3F64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X619C));
    // 0x80527BB8: lwc1        $f2, 0x30($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527BBC: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80527BC0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X61A0) << 16);
    // 0x80527BC4: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80527BC8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80527BCC: nop

    // 0x80527BD0: bc1tl       L_80527C38
    if (c1cs) {
        // 0x80527BD4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80527C38;
    }
    goto skip_0;
    // 0x80527BD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80527BD8: lwc1        $f8, -0x3F60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X61A0));
    // 0x80527BDC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80527BE0: nop

    // 0x80527BE4: bc1tl       L_80527C38
    if (c1cs) {
        // 0x80527BE8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80527C38;
    }
    goto skip_1;
    // 0x80527BE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80527BEC: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80527BF0: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x80527BF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80527BF8: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x80527BFC: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80527C00: bgez        $v0, L_80527C18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80527C04: swc1        $f10, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
            goto L_80527C18;
    }
    // 0x80527C04: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
    // 0x80527C08: jal         0x805276E0
    // 0x80527C0C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_805276E0(rdram, ctx);
        goto after_0;
    // 0x80527C0C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80527C10: b           L_80527C4C
    // 0x80527C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80527C4C;
    // 0x80527C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527C18:
    // 0x80527C18: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80527C1C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80527C20: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80527C24: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80527C28: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80527C2C: b           L_80527C48
    // 0x80527C30: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80527C48;
    // 0x80527C30: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80527C34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80527C38:
    // 0x80527C38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80527C3C: nop

    // 0x80527C40: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80527C44: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
L_80527C48:
    // 0x80527C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527C4C:
    // 0x80527C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527C50: jr          $ra
    // 0x80527C54: nop

    return;
    // 0x80527C54: nop

;}
RECOMP_FUNC void func_8044C8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C8BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044C8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044C8C4: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8044C8C8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8044C8CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044C8D0: jal         0x80066E88
    // 0x8044C8D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8044C8D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8044C8D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8044C8DC: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044C8E0: jal         0x80066DE4
    // 0x8044C8E4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8044C8E4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8044C8E8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8044C8EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8044C8F0: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8044C8F4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8044C8F8: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x8044C8FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044C900: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C904: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8044C908: swc1        $f14, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
    // 0x8044C90C: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x8044C910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044C914: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8044C918: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C91C: swc1        $f2, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8044C920: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8044C924: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8044C928: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8044C92C: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x8044C930: swc1        $f14, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f14.u32l;
    // 0x8044C934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044C938: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8044C93C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044C940: jr          $ra
    // 0x8044C944: nop

    return;
    // 0x8044C944: nop

;}
RECOMP_FUNC void func_80028D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028D3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028D40: lwc1        $f4, -0x21C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X21C);
    // 0x80028D44: lwc1        $f0, 0xAC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x80028D48: lw          $v0, 0x34($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X34);
    // 0x80028D4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028D50: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80028D54: nop

    // 0x80028D58: bc1tl       L_80028D78
    if (c1cs) {
        // 0x80028D5C: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80028D78;
    }
    goto skip_0;
    // 0x80028D5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x80028D60: lwc1        $f6, -0x218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X218);
    // 0x80028D64: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80028D68: nop

    // 0x80028D6C: bc1fl       L_80028DA4
    if (!c1cs) {
        // 0x80028D70: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80028DA4;
    }
    goto skip_1;
    // 0x80028D70: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x80028D74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80028D78:
    // 0x80028D78: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80028D7C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80028D80: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80028D84: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80028D88: bc1fl       L_80028DA4
    if (!c1cs) {
        // 0x80028D8C: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80028DA4;
    }
    goto skip_2;
    // 0x80028D8C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x80028D90: lw          $t7, -0x2234($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2234);
    // 0x80028D94: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80028D98: bne         $at, $zero, L_80028DAC
    if (ctx->r1 != 0) {
        // 0x80028D9C: nop
    
            goto L_80028DAC;
    }
    // 0x80028D9C: nop

    // 0x80028DA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80028DA4:
    // 0x80028DA4: nop

    // 0x80028DA8: swc1        $f10, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f10.u32l;
L_80028DAC:
    // 0x80028DAC: jr          $ra
    // 0x80028DB0: nop

    return;
    // 0x80028DB0: nop

;}
RECOMP_FUNC void func_806B02D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B02D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806B02D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B02DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806B02E0: lwc1        $f16, 0x3C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x806B02E4: lwc1        $f12, 0x50($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X50);
    // 0x806B02E8: lwc1        $f14, 0x10C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10C);
    // 0x806B02EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x806B02F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x806B02F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x806B02F8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x806B02FC: jal         0x80066DE4
    // 0x806B0300: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806B0300: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x806B0304: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806B0308: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x806B030C: jal         0x80066DE4
    // 0x806B0310: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x806B0310: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    after_1:
    // 0x806B0314: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x806B0318: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x806B031C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B0320: lwc1        $f6, 0x6C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X6C);
    // 0x806B0324: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806B0328: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806B032C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806B0330: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1710) << 16);
    // 0x806B0334: lwc1        $f4, 0x16A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1710));
    // 0x806B0338: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x806B033C: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806B0340: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806B0344: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806B0348: lwc1        $f8, 0x68($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X68);
    // 0x806B034C: sub.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x806B0350: add.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x806B0354: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806B0358: nop

    // 0x806B035C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806B0360: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x806B0364: swc1        $f14, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f14.u32l;
    // 0x806B0368: lwc1        $f18, 0x3C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806B036C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806B0370: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x806B0374: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806B0378: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x806B037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B0380: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806B0384: jr          $ra
    // 0x806B0388: nop

    return;
    // 0x806B0388: nop

;}
RECOMP_FUNC void func_80699C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699C60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80699C64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80699C68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80699C6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80699C70: jal         0x80045A34
    // 0x80699C74: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80699C74: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_0:
    // 0x80699C78: bne         $v0, $zero, L_80699C90
    if (ctx->r2 != 0) {
        // 0x80699C7C: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_80699C90;
    }
    // 0x80699C7C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80699C80: jal         0x800445A4
    // 0x80699C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80699C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80699C88: b           L_80699EE8
    // 0x80699C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80699EE8;
    // 0x80699C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80699C90:
    // 0x80699C90: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x80699C94: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(562, 0X1618) << 16);
    // 0x80699C98: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80699C9C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80699CA0: addiu       $t6, $t6, -0x5518
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(562, 0X1618));
    // 0x80699CA4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80699CA8: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x80699CAC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80699CB0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80699CB4: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80699CB8: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x80699CBC: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x80699CC0: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(562, 0XD10) << 16);
    // 0x80699CC4: lui         $a2, 0x806A
    ctx->r6 = S32(RELOC_HI16(562, 0XD20) << 16);
    // 0x80699CC8: lui         $t0, 0x806A
    ctx->r8 = S32(RELOC_HI16(562, 0XD30) << 16);
    // 0x80699CCC: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(562, 0XD40) << 16);
    // 0x80699CD0: lui         $t2, 0x806A
    ctx->r10 = S32(RELOC_HI16(562, 0XDC0) << 16);
    // 0x80699CD4: addiu       $t2, $t2, -0x5D70
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(562, 0XDC0));
    // 0x80699CD8: addiu       $v0, $v0, -0x5DF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(562, 0XD40));
    // 0x80699CDC: addiu       $t0, $t0, -0x5E00
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(562, 0XD30));
    // 0x80699CE0: addiu       $a2, $a2, -0x5E10
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(562, 0XD20));
    // 0x80699CE4: addiu       $a0, $a0, -0x5E20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(562, 0XD10));
    // 0x80699CE8: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x80699CEC: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x80699CF0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80699CF4: addiu       $v1, $t3, 0x10
    ctx->r3 = ADD32(ctx->r11, 0X10);
    // 0x80699CF8: addiu       $a1, $t3, 0x20
    ctx->r5 = ADD32(ctx->r11, 0X20);
    // 0x80699CFC: addiu       $a3, $t3, 0x30
    ctx->r7 = ADD32(ctx->r11, 0X30);
    // 0x80699D00: addiu       $t1, $t3, 0x40
    ctx->r9 = ADD32(ctx->r11, 0X40);
L_80699D04:
    // 0x80699D04: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80699D08: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80699D0C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80699D10: sw          $t6, -0x40($v1)
    MEM_W(-0X40, ctx->r3) = ctx->r14;
    // 0x80699D14: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x80699D18: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80699D1C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x80699D20: sw          $t5, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->r13;
    // 0x80699D24: lw          $t6, -0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, -0X38);
    // 0x80699D28: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x80699D2C: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x80699D30: sw          $t6, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = ctx->r14;
    // 0x80699D34: lw          $t5, -0x34($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X34);
    // 0x80699D38: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x80699D3C: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x80699D40: sw          $t5, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r13;
    // 0x80699D44: lw          $t8, -0x40($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X40);
    // 0x80699D48: sw          $t8, -0x40($a1)
    MEM_W(-0X40, ctx->r5) = ctx->r24;
    // 0x80699D4C: lw          $t7, -0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X3C);
    // 0x80699D50: sw          $t7, -0x3C($a1)
    MEM_W(-0X3C, ctx->r5) = ctx->r15;
    // 0x80699D54: lw          $t8, -0x38($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X38);
    // 0x80699D58: sw          $t8, -0x38($a1)
    MEM_W(-0X38, ctx->r5) = ctx->r24;
    // 0x80699D5C: lw          $t7, -0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X34);
    // 0x80699D60: sw          $t7, -0x34($a1)
    MEM_W(-0X34, ctx->r5) = ctx->r15;
    // 0x80699D64: lw          $t5, -0x40($t0)
    ctx->r13 = MEM_W(ctx->r8, -0X40);
    // 0x80699D68: sw          $t5, -0x40($a3)
    MEM_W(-0X40, ctx->r7) = ctx->r13;
    // 0x80699D6C: lw          $t9, -0x3C($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X3C);
    // 0x80699D70: sw          $t9, -0x3C($a3)
    MEM_W(-0X3C, ctx->r7) = ctx->r25;
    // 0x80699D74: lw          $t5, -0x38($t0)
    ctx->r13 = MEM_W(ctx->r8, -0X38);
    // 0x80699D78: sw          $t5, -0x38($a3)
    MEM_W(-0X38, ctx->r7) = ctx->r13;
    // 0x80699D7C: lw          $t9, -0x34($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X34);
    // 0x80699D80: sw          $t9, -0x34($a3)
    MEM_W(-0X34, ctx->r7) = ctx->r25;
    // 0x80699D84: lw          $t7, -0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X40);
    // 0x80699D88: sw          $t7, -0x40($t1)
    MEM_W(-0X40, ctx->r9) = ctx->r15;
    // 0x80699D8C: lw          $t6, -0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X3C);
    // 0x80699D90: sw          $t6, -0x3C($t1)
    MEM_W(-0X3C, ctx->r9) = ctx->r14;
    // 0x80699D94: lw          $t7, -0x38($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X38);
    // 0x80699D98: sw          $t7, -0x38($t1)
    MEM_W(-0X38, ctx->r9) = ctx->r15;
    // 0x80699D9C: lw          $t6, -0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X34);
    // 0x80699DA0: bne         $v0, $t2, L_80699D04
    if (ctx->r2 != ctx->r10) {
        // 0x80699DA4: sw          $t6, -0x34($t1)
        MEM_W(-0X34, ctx->r9) = ctx->r14;
            goto L_80699D04;
    }
    // 0x80699DA4: sw          $t6, -0x34($t1)
    MEM_W(-0X34, ctx->r9) = ctx->r14;
    // 0x80699DA8: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x80699DAC: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(562, 0XE8) << 16);
    // 0x80699DB0: addiu       $t8, $t8, -0x6A48
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(562, 0XE8));
    // 0x80699DB4: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x80699DB8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80699DBC: jal         0x80047090
    // 0x80699DC0: addiu       $a0, $zero, 0x458E
    ctx->r4 = ADD32(0, 0X458E);
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x80699DC0: addiu       $a0, $zero, 0x458E
    ctx->r4 = ADD32(0, 0X458E);
    after_2:
    // 0x80699DC4: lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XC);
    // 0x80699DC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80699DCC: addiu       $at, $zero, 0x458C
    ctx->r1 = ADD32(0, 0X458C);
    // 0x80699DD0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80699DD4: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80699DD8: beq         $v1, $at, L_80699DE8
    if (ctx->r3 == ctx->r1) {
        // 0x80699DDC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80699DE8;
    }
    // 0x80699DDC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80699DE0: addiu       $at, $zero, 0x458D
    ctx->r1 = ADD32(0, 0X458D);
    // 0x80699DE4: bne         $v1, $at, L_80699DF4
    if (ctx->r3 != ctx->r1) {
        // 0x80699DE8: lui         $at, 0xC188
        ctx->r1 = S32(0XC188 << 16);
            goto L_80699DF4;
    }
L_80699DE8:
    // 0x80699DE8: lui         $at, 0xC188
    ctx->r1 = S32(0XC188 << 16);
    // 0x80699DEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80699DF0: nop

L_80699DF4:
    // 0x80699DF4: lui         $at, 0x458E
    ctx->r1 = S32(0X458E << 16);
    // 0x80699DF8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80699DFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80699E00: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80699E04: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80699E08: or          $a0, $t0, $at
    ctx->r4 = ctx->r8 | ctx->r1;
    // 0x80699E0C: jal         0x8004613C
    // 0x80699E10: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x80699E10: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_3:
    // 0x80699E14: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80699E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80699E1C: bne         $v0, $zero, L_80699E34
    if (ctx->r2 != 0) {
        // 0x80699E20: sw          $v0, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r2;
            goto L_80699E34;
    }
    // 0x80699E20: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80699E24: jal         0x800445A4
    // 0x80699E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x80699E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80699E2C: b           L_80699EE8
    // 0x80699E30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80699EE8;
    // 0x80699E30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80699E34:
    // 0x80699E34: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80699E38: jal         0x80047F9C
    // 0x80699E3C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x80699E3C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_5:
    // 0x80699E40: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80699E44: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80699E48: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80699E4C: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80699E50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80699E54: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80699E58: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
    // 0x80699E5C: lbu         $t7, -0x7204($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X7204);
    // 0x80699E60: bnel        $t7, $at, L_80699EE8
    if (ctx->r15 != ctx->r1) {
        // 0x80699E64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80699EE8;
    }
    goto skip_0;
    // 0x80699E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80699E68: lbu         $t8, -0x7203($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X7203);
    // 0x80699E6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80699E70: bnel        $t8, $at, L_80699EE8
    if (ctx->r24 != ctx->r1) {
        // 0x80699E74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80699EE8;
    }
    goto skip_1;
    // 0x80699E74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80699E78: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80699E7C: addiu       $at, $zero, 0x4584
    ctx->r1 = ADD32(0, 0X4584);
    // 0x80699E80: beq         $v0, $at, L_80699EA0
    if (ctx->r2 == ctx->r1) {
        // 0x80699E84: addiu       $at, $zero, 0x4586
        ctx->r1 = ADD32(0, 0X4586);
            goto L_80699EA0;
    }
    // 0x80699E84: addiu       $at, $zero, 0x4586
    ctx->r1 = ADD32(0, 0X4586);
    // 0x80699E88: beq         $v0, $at, L_80699EB8
    if (ctx->r2 == ctx->r1) {
        // 0x80699E8C: addiu       $at, $zero, 0x458D
        ctx->r1 = ADD32(0, 0X458D);
            goto L_80699EB8;
    }
    // 0x80699E8C: addiu       $at, $zero, 0x458D
    ctx->r1 = ADD32(0, 0X458D);
    // 0x80699E90: beql        $v0, $at, L_80699ED4
    if (ctx->r2 == ctx->r1) {
        // 0x80699E94: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80699ED4;
    }
    goto skip_2;
    // 0x80699E94: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_2:
    // 0x80699E98: b           L_80699EE8
    // 0x80699E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80699EE8;
    // 0x80699E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80699EA0:
    // 0x80699EA0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80699EA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80699EA8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80699EAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80699EB0: b           L_80699EE4
    // 0x80699EB4: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
        goto L_80699EE4;
    // 0x80699EB4: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
L_80699EB8:
    // 0x80699EB8: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80699EBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80699EC0: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80699EC4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80699EC8: b           L_80699EE4
    // 0x80699ECC: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
        goto L_80699EE4;
    // 0x80699ECC: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x80699ED0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_80699ED4:
    // 0x80699ED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80699ED8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80699EDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80699EE0: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
L_80699EE4:
    // 0x80699EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80699EE8:
    // 0x80699EE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80699EEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80699EF0: jr          $ra
    // 0x80699EF4: nop

    return;
    // 0x80699EF4: nop

;}
RECOMP_FUNC void func_807151C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807151C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807151CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807151D0: jal         0x80714DD4
    // 0x807151D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80714DD4(rdram, ctx);
        goto after_0;
    // 0x807151D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807151D8: jal         0x80714E64
    // 0x807151DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80714E64(rdram, ctx);
        goto after_1;
    // 0x807151DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807151E0: jal         0x80714D40
    // 0x807151E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80714D40(rdram, ctx);
        goto after_2;
    // 0x807151E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x807151E8: beq         $v0, $zero, L_80715200
    if (ctx->r2 == 0) {
        // 0x807151EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80715200;
    }
    // 0x807151EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807151F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807151F4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x807151F8: jal         0x80715C24
    // 0x807151FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80715C24(rdram, ctx);
        goto after_3;
    // 0x807151FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_80715200:
    // 0x80715200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80715204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715208: jr          $ra
    // 0x8071520C: nop

    return;
    // 0x8071520C: nop

;}
RECOMP_FUNC void func_80456D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456D98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80456D9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80456DA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80456DA4: jal         0x80444998
    // 0x80456DA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80444998(rdram, ctx);
        goto after_0;
    // 0x80456DA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80456DAC: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80456DB0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80456DB4: lui         $t7, 0x8045
    ctx->r15 = S32(RELOC_HI16(98, 0X139E8) << 16);
    // 0x80456DB8: sw          $t6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r14;
    // 0x80456DBC: addiu       $t7, $t7, 0x7DC8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(98, 0X139E8));
    // 0x80456DC0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80456DC4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80456DC8: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80456DCC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80456DD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80456DD4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80456DD8: jal         0x80051194
    // 0x80456DDC: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    func_80051194(rdram, ctx);
        goto after_1;
    // 0x80456DDC: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    after_1:
    // 0x80456DE0: jal         0x800683A4
    // 0x80456DE4: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    func_800683A4(rdram, ctx);
        goto after_2;
    // 0x80456DE4: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    after_2:
    // 0x80456DE8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80456DEC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80456DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80456DF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80456DF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80456DFC: jr          $ra
    // 0x80456E00: nop

    return;
    // 0x80456E00: nop

;}
RECOMP_FUNC void func_8004FB98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FB98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004FB9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FBA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004FBA4: lw          $a0, 0x1B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004FBA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004FBAC: jal         0x8004F42C
    // 0x8004FBB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004F42C(rdram, ctx);
        goto after_0;
    // 0x8004FBB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004FBB4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8004FBB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004FBBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004FBC0: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x8004FBC4: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x8004FBC8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8004FBCC: jal         0x8004F9B0
    // 0x8004FBD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8004F9B0(rdram, ctx);
        goto after_1;
    // 0x8004FBD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8004FBD4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004FBD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004FBDC: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x8004FBE0: sh          $t7, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r15;
    // 0x8004FBE4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8004FBE8: lw          $t9, 0x1B0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1B0);
    // 0x8004FBEC: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x8004FBF0: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
    // 0x8004FBF4: sh          $t1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r9;
    // 0x8004FBF8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8004FBFC: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x8004FC00: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8004FC04: beql        $t4, $zero, L_8004FC1C
    if (ctx->r12 == 0) {
        // 0x8004FC08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004FC1C;
    }
    goto skip_0;
    // 0x8004FC08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004FC0C: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x8004FC10: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8004FC14: sh          $t6, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r14;
    // 0x8004FC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004FC1C:
    // 0x8004FC1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004FC20: jr          $ra
    // 0x8004FC24: nop

    return;
    // 0x8004FC24: nop

;}
RECOMP_FUNC void func_805DC318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC318: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DC31C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x805DC320: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805DC324: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805DC328: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x805DC32C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805DC330: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC334: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x805DC338: addiu       $s3, $zero, 0x50
    ctx->r19 = ADD32(0, 0X50);
L_805DC33C:
    // 0x805DC33C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x805DC340: beq         $v0, $zero, L_805DC368
    if (ctx->r2 == 0) {
        // 0x805DC344: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805DC368;
    }
    // 0x805DC344: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805DC348: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x805DC34C: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x805DC350: beql        $a1, $zero, L_805DC368
    if (ctx->r5 == 0) {
        // 0x805DC354: sb          $zero, 0x165($s0)
        MEM_B(0X165, ctx->r16) = 0;
            goto L_805DC368;
    }
    goto skip_0;
    // 0x805DC354: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    skip_0:
    // 0x805DC358: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x805DC35C: jal         0x8005FDC4
    // 0x805DC360: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x805DC360: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    after_0:
    // 0x805DC364: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
L_805DC368:
    // 0x805DC368: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x805DC36C: bne         $s1, $s3, L_805DC33C
    if (ctx->r17 != ctx->r19) {
        // 0x805DC370: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_805DC33C;
    }
    // 0x805DC370: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x805DC374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805DC378: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805DC37C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805DC380: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC384: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x805DC388: jr          $ra
    // 0x805DC38C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805DC38C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80046BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046BE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80046BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046BEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80046BF0: jal         0x80045B2C
    // 0x80046BF4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80045B2C(rdram, ctx);
        goto after_0;
    // 0x80046BF4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80046BF8: bne         $v0, $zero, L_80046C18
    if (ctx->r2 != 0) {
        // 0x80046BFC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80046C18;
    }
    // 0x80046BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80046C00: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80046C04: addiu       $a0, $a0, 0x790
    ctx->r4 = ADD32(ctx->r4, 0X790);
    // 0x80046C08: jal         0x80071380
    // 0x80046C0C: addiu       $a1, $zero, 0x6A6
    ctx->r5 = ADD32(0, 0X6A6);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80046C0C: addiu       $a1, $zero, 0x6A6
    ctx->r5 = ADD32(0, 0X6A6);
    after_1:
    // 0x80046C10: b           L_80046C48
    // 0x80046C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046C48;
    // 0x80046C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046C18:
    // 0x80046C18: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80046C1C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80046C20: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80046C24: jal         0x80046B70
    // 0x80046C28: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80046B70(rdram, ctx);
        goto after_2;
    // 0x80046C28: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_2:
    // 0x80046C2C: bne         $v0, $zero, L_80046C44
    if (ctx->r2 != 0) {
        // 0x80046C30: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80046C44;
    }
    // 0x80046C30: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80046C34: jal         0x80045AE8
    // 0x80046C38: nop

    func_80045AE8(rdram, ctx);
        goto after_3;
    // 0x80046C38: nop

    after_3:
    // 0x80046C3C: b           L_80046C48
    // 0x80046C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046C48;
    // 0x80046C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046C44:
    // 0x80046C44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80046C48:
    // 0x80046C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80046C50: jr          $ra
    // 0x80046C54: nop

    return;
    // 0x80046C54: nop

;}
RECOMP_FUNC void func_8057F74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F74C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057F750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F754: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    // 0x8057F758: jal         0x80067818
    // 0x8057F75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x8057F75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8057F760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057F768: jr          $ra
    // 0x8057F76C: nop

    return;
    // 0x8057F76C: nop

;}
RECOMP_FUNC void func_80770500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80770500: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(769, 0X130) << 16);
    // 0x80770504: jr          $ra
    // 0x80770508: addiu       $v0, $v0, 0x630
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(769, 0X130));
    return;
    // 0x80770508: addiu       $v0, $v0, 0x630
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(769, 0X130));
;}
RECOMP_FUNC void func_80453B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453B80: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80453B84: lw          $t6, -0x71A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71A8);
    // 0x80453B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453B8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80453B90: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80453B94: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80453B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453B9C: bne         $t8, $at, L_80453BBC
    if (ctx->r24 != ctx->r1) {
        // 0x80453BA0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80453BBC;
    }
    // 0x80453BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80453BA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80453BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80453BAC: jal         0x8006E0FC
    // 0x80453BB0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x80453BB0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_0:
    // 0x80453BB4: b           L_80453BD0
    // 0x80453BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80453BD0;
    // 0x80453BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453BBC:
    // 0x80453BBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80453BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80453BC4: jal         0x8006E0FC
    // 0x80453BC8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x80453BC8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    after_1:
    // 0x80453BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80453BD0:
    // 0x80453BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453BD4: jr          $ra
    // 0x80453BD8: nop

    return;
    // 0x80453BD8: nop

;}
RECOMP_FUNC void func_8005ABF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ABF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005ABF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005ABFC: jal         0x80065528
    // 0x8005AC00: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x8005AC00: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_0:
    // 0x8005AC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005AC08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005AC0C: jr          $ra
    // 0x8005AC10: nop

    return;
    // 0x8005AC10: nop

;}
RECOMP_FUNC void func_80526814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526814: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80526818: bne         $v0, $zero, L_80526870
    if (ctx->r2 != 0) {
        // 0x8052681C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80526870;
    }
    // 0x8052681C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80526820: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80526824: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(327, 0X60F4) << 16);
    // 0x80526828: blez        $v0, L_80526868
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8052682C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80526868;
    }
    // 0x8052682C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80526830: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80526834: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80526838: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8052683C: lw          $t9, -0x400C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(327, 0X60F4));
    // 0x80526840: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x80526844: lw          $t5, 0x14($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14);
    // 0x80526848: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8052684C: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80526850: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80526854: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80526858: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8052685C: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80526860: b           L_80526874
    // 0x80526864: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
        goto L_80526874;
    // 0x80526864: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_80526868:
    // 0x80526868: jr          $ra
    // 0x8052686C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8052686C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80526870:
    // 0x80526870: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80526874:
    // 0x80526874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80526878: jr          $ra
    // 0x8052687C: nop

    return;
    // 0x8052687C: nop

;}
RECOMP_FUNC void func_804BED04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BED04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BED08: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804BED0C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BED10: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804BED14: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804BED18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BED1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804BED20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804BED24: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804BED28: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804BED2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804BED30: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804BED34: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(191, 0X40D0) << 16);
    // 0x804BED38: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804BED3C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804BED40: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804BED44: lw          $t1, -0x600($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(191, 0X40D0));
    // 0x804BED48: jal         0x804BD600
    // 0x804BED4C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804BD600(rdram, ctx);
        goto after_0;
    // 0x804BED4C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804BED50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BED54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BED58: jr          $ra
    // 0x804BED5C: nop

    return;
    // 0x804BED5C: nop

;}
RECOMP_FUNC void func_8079A65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A65C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8079A660: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8079A664: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8079A668: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X272C) << 16);
    // 0x8079A66C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8079A670: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8079A674: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8079A678: bc1f        L_8079A6A8
    if (!c1cs) {
        // 0x8079A67C: swc1        $f6, 0xC4($a0)
        MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
            goto L_8079A6A8;
    }
    // 0x8079A67C: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8079A680: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2728) << 16);
    // 0x8079A684: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8079A688: lwc1        $f0, -0x4DB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2728));
    // 0x8079A68C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079A690: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8079A694: nop

    // 0x8079A698: bc1f        L_8079A6C4
    if (!c1cs) {
        // 0x8079A69C: nop
    
            goto L_8079A6C4;
    }
    // 0x8079A69C: nop

    // 0x8079A6A0: jr          $ra
    // 0x8079A6A4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x8079A6A4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8079A6A8:
    // 0x8079A6A8: lwc1        $f0, -0x4DB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X272C));
    // 0x8079A6AC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079A6B0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8079A6B4: nop

    // 0x8079A6B8: bc1f        L_8079A6C4
    if (!c1cs) {
        // 0x8079A6BC: nop
    
            goto L_8079A6C4;
    }
    // 0x8079A6BC: nop

    // 0x8079A6C0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8079A6C4:
    // 0x8079A6C4: jr          $ra
    // 0x8079A6C8: nop

    return;
    // 0x8079A6C8: nop

;}
RECOMP_FUNC void func_80679364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679364: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80679368: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8067936C: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80679370: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80679374: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(538, 0X1450) << 16);
    // 0x80679378: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8067937C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80679380: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80679384: lw          $t8, -0x6C40($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(538, 0X1450));
    // 0x80679388: jr          $ra
    // 0x8067938C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8067938C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8005EC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005EC64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005EC68: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8005EC6C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8005EC70: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8005EC74: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8005EC78: lw          $t9, 0x6460($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6460);
    // 0x8005EC7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005EC80: jalr        $t9
    // 0x8005EC84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005EC84: nop

    after_0:
    // 0x8005EC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005EC8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005EC90: jr          $ra
    // 0x8005EC94: nop

    return;
    // 0x8005EC94: nop

;}
RECOMP_FUNC void func_804C5A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5A10: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(215, 0X170) << 16);
    // 0x804C5A14: addiu       $v0, $v0, 0x5B80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(215, 0X170));
    // 0x804C5A18: jr          $ra
    // 0x804C5A1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804C5A1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80469FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469FF4: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80469FF8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80469FFC: beq         $v1, $zero, L_8046A010
    if (ctx->r3 == 0) {
        // 0x8046A000: nop
    
            goto L_8046A010;
    }
    // 0x8046A000: nop

    // 0x8046A004: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x8046A008: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8046A00C: swc1        $f4, 0xE08($a0)
    MEM_W(0XE08, ctx->r4) = ctx->f4.u32l;
L_8046A010:
    // 0x8046A010: jr          $ra
    // 0x8046A014: nop

    return;
    // 0x8046A014: nop

;}
RECOMP_FUNC void func_8067E510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E510: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067E514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067E518: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067E51C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8067E520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067E524: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067E528: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8067E52C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8067E530: lbu         $t8, 0x44($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X44);
    // 0x8067E534: beql        $t8, $zero, L_8067E570
    if (ctx->r24 == 0) {
        // 0x8067E538: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8067E570;
    }
    goto skip_0;
    // 0x8067E538: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x8067E53C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8067E540: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8067E544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067E548: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8067E54C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8067E550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8067E554: sb          $t9, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r25;
    // 0x8067E558: jal         0x8067EAE0
    // 0x8067E55C: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_8067EAE0(rdram, ctx);
        goto after_0;
    // 0x8067E55C: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_0:
    // 0x8067E560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067E564: jal         0x8067E3E8
    // 0x8067E568: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    func_8067E3E8(rdram, ctx);
        goto after_1;
    // 0x8067E568: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_1:
    // 0x8067E56C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8067E570:
    // 0x8067E570: jal         0x8067DF94
    // 0x8067E574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8067DF94(rdram, ctx);
        goto after_2;
    // 0x8067E574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8067E578: jal         0x8067E480
    // 0x8067E57C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E480(rdram, ctx);
        goto after_3;
    // 0x8067E57C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8067E580: jal         0x8067E420
    // 0x8067E584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E420(rdram, ctx);
        goto after_4;
    // 0x8067E584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8067E588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067E58C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067E590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067E594: jr          $ra
    // 0x8067E598: nop

    return;
    // 0x8067E598: nop

;}
RECOMP_FUNC void func_8045F450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045F454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045F458: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045F45C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8045F460: jal         0x8045F2A0
    // 0x8045F464: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8045F2A0(rdram, ctx);
        goto after_0;
    // 0x8045F464: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8045F468: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8045F46C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8045F470: beq         $t6, $zero, L_8045F494
    if (ctx->r14 == 0) {
        // 0x8045F474: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8045F494;
    }
    // 0x8045F474: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045F478: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8045F47C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F480: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x8045F484: nop

    // 0x8045F488: bc1fl       L_8045F498
    if (!c1cs) {
        // 0x8045F48C: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_8045F498;
    }
    goto skip_0;
    // 0x8045F48C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x8045F490: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8045F494:
    // 0x8045F494: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_8045F498:
    // 0x8045F498: andi        $t7, $v0, 0xFF00
    ctx->r15 = ctx->r2 & 0XFF00;
    // 0x8045F49C: beq         $t7, $zero, L_8045F4BC
    if (ctx->r15 == 0) {
        // 0x8045F4A0: lwc1        $f2, 0x0($v1)
        ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8045F4BC;
    }
    // 0x8045F4A0: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F4A4: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x8045F4A8: nop

    // 0x8045F4AC: bc1fl       L_8045F4C0
    if (!c1cs) {
        // 0x8045F4B0: lwc1        $f6, 0x50($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
            goto L_8045F4C0;
    }
    goto skip_1;
    // 0x8045F4B0: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    skip_1:
    // 0x8045F4B4: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x8045F4B8: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
L_8045F4BC:
    // 0x8045F4BC: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
L_8045F4C0:
    // 0x8045F4C0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8045F4C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8045F4C8: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8045F4CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8045F4D0: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8045F4D4: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8045F4D8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8045F4DC: nop

    // 0x8045F4E0: bc1fl       L_8045F4F8
    if (!c1cs) {
        // 0x8045F4E4: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_8045F4F8;
    }
    goto skip_2;
    // 0x8045F4E4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_2:
    // 0x8045F4E8: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8045F4EC: b           L_8045F50C
    // 0x8045F4F0: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
        goto L_8045F50C;
    // 0x8045F4F0: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x8045F4F4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_8045F4F8:
    // 0x8045F4F8: nop

    // 0x8045F4FC: bc1fl       L_8045F510
    if (!c1cs) {
        // 0x8045F500: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8045F510;
    }
    goto skip_3;
    // 0x8045F500: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x8045F504: add.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8045F508: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
L_8045F50C:
    // 0x8045F50C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8045F510:
    // 0x8045F510: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(113, 0XAC0) << 16);
    // 0x8045F514: lwc1        $f4, -0x420($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(113, 0XAC0));
    // 0x8045F518: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F51C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(113, 0XAC4) << 16);
    // 0x8045F520: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045F524: nop

    // 0x8045F528: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8045F52C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8045F530: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8045F534: swc1        $f16, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f16.u32l;
    // 0x8045F538: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F53C: lwc1        $f4, -0x41C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(113, 0XAC4));
    // 0x8045F540: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045F544: jal         0x8045F1BC
    // 0x8045F548: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    func_8045F1BC(rdram, ctx);
        goto after_1;
    // 0x8045F548: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    after_1:
    // 0x8045F54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045F550: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045F554: jr          $ra
    // 0x8045F558: nop

    return;
    // 0x8045F558: nop

;}
RECOMP_FUNC void func_80430A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430A58: jr          $ra
    // 0x80430A5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80430A5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80681FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681FC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80681FC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80681FC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80681FCC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80681FD0: jal         0x80086F28
    // 0x80681FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gMtxIdent(rdram, ctx);
        goto after_0;
    // 0x80681FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80681FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80681FDC: jal         0x8007FF58
    // 0x80681FE0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8007FF58(rdram, ctx);
        goto after_1;
    // 0x80681FE0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80681FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80681FE8: jal         0x8007FF0C
    // 0x80681FEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8007FF0C(rdram, ctx);
        goto after_2;
    // 0x80681FEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80681FF0: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80681FF4: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80681FF8: jal         0x8007FEC8
    // 0x80681FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007FEC8(rdram, ctx);
        goto after_3;
    // 0x80681FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80682000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80682004: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80682008: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8068200C: jr          $ra
    // 0x80682010: nop

    return;
    // 0x80682010: nop

;}
RECOMP_FUNC void func_8001DBEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DBEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DBF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DBF4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001DBF8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8001DBFC: lbu         $t6, -0x764C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X764C);
    // 0x8001DC00: lbu         $t8, 0x22($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X22);
    // 0x8001DC04: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8001DC08: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001DC0C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001DC10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001DC14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001DC18: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001DC1C: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8001DC20: jal         0x8001D908
    // 0x8001DC24: lw          $a1, -0x6780($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6780);
    func_8001D908(rdram, ctx);
        goto after_0;
    // 0x8001DC24: lw          $a1, -0x6780($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6780);
    after_0:
    // 0x8001DC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001DC30: jr          $ra
    // 0x8001DC34: nop

    return;
    // 0x8001DC34: nop

;}
RECOMP_FUNC void func_80521E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521E50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521E58: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80521E5C: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(315, 0X250) << 16);
    // 0x80521E60: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80521E64: addiu       $t6, $t6, 0x2090
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(315, 0X250));
    // 0x80521E68: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80521E6C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80521E70: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80521E74: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80521E78: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x80521E7C: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x80521E80: jal         0x80522014
    // 0x80521E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80522014(rdram, ctx);
        goto after_0;
    // 0x80521E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80521E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521E8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80521E90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80521E94: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x80521E98: jr          $ra
    // 0x80521E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80521E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8041DAD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DAD8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8041DADC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8041DAE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8041DAE4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8041DAE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8041DAEC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8041DAF0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8041DAF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8041DAF8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8041DAFC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8041DB00: lui         $t1, 0x8042
    ctx->r9 = S32(RELOC_HI16(29, 0X2FF8) << 16);
    // 0x8041DB04: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8041DB08: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8041DB0C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8041DB10: lw          $t1, 0x658($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(29, 0X2FF8));
    // 0x8041DB14: jr          $ra
    // 0x8041DB18: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8041DB18: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804B6EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6EB0: jal         0x804B6BF8
    // 0x804B6EB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804B6BF8(rdram, ctx);
        goto after_0;
    // 0x804B6EB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B6EB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6EBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6EC0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804B6EC4: jal         0x804B6FF0
    // 0x804B6EC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6EC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6ECC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6ED0: lui         $t6, 0x804B
    ctx->r14 = S32(RELOC_HI16(182, 0XBD0) << 16);
    // 0x804B6ED4: addiu       $t6, $t6, 0x6E70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(182, 0XBD0));
    // 0x804B6ED8: jal         0x80057978
    // 0x804B6EDC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    func_80057978(rdram, ctx);
        goto after_2;
    // 0x804B6EDC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    after_2:
    // 0x804B6EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6EE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6EE8: jr          $ra
    // 0x804B6EEC: nop

    return;
    // 0x804B6EEC: nop

;}
RECOMP_FUNC void func_805582E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805582E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805582E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805582E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805582EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805582F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805582F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805582F8: lw          $t6, 0x14C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X14C);
    // 0x805582FC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558300: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80558304: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80558308: lw          $s2, 0x14($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X14);
    // 0x8055830C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80558310: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80558314: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80558318: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8055831C: addu        $a1, $t7, $s2
    ctx->r5 = ADD32(ctx->r15, ctx->r18);
    // 0x80558320: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80558324: jal         0x8055824C
    // 0x80558328: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8055824C(rdram, ctx);
        goto after_0;
    // 0x80558328: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8055832C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80558330: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80558334: addiu       $s0, $a2, 0x14C
    ctx->r16 = ADD32(ctx->r6, 0X14C);
    // 0x80558338: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8055833C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80558340: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80558344: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80558348: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8055834C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80558350: jal         0x8055824C
    // 0x80558354: addu        $a1, $t9, $s2
    ctx->r5 = ADD32(ctx->r25, ctx->r18);
    func_8055824C(rdram, ctx);
        goto after_1;
    // 0x80558354: addu        $a1, $t9, $s2
    ctx->r5 = ADD32(ctx->r25, ctx->r18);
    after_1:
    // 0x80558358: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8055835C: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x80558360: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80558364: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80558368: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8055836C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80558370: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80558374: addu        $a1, $t1, $s2
    ctx->r5 = ADD32(ctx->r9, ctx->r18);
    // 0x80558378: jal         0x8055824C
    // 0x8055837C: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_8055824C(rdram, ctx);
        goto after_2;
    // 0x8055837C: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_2:
    // 0x80558380: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80558384: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80558388: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8055838C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80558390: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80558394: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80558398: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8055839C: addu        $a1, $t3, $s2
    ctx->r5 = ADD32(ctx->r11, ctx->r18);
    // 0x805583A0: jal         0x8055824C
    // 0x805583A4: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    func_8055824C(rdram, ctx);
        goto after_3;
    // 0x805583A4: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    after_3:
    // 0x805583A8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x805583AC: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x805583B0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x805583B4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x805583B8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x805583BC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x805583C0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x805583C4: addu        $a1, $t5, $s2
    ctx->r5 = ADD32(ctx->r13, ctx->r18);
    // 0x805583C8: jal         0x8055824C
    // 0x805583CC: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    func_8055824C(rdram, ctx);
        goto after_4;
    // 0x805583CC: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    after_4:
    // 0x805583D0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x805583D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805583D8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805583DC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x805583E0: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    // 0x805583E4: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x805583E8: bne         $at, $zero, L_80558418
    if (ctx->r1 != 0) {
        // 0x805583EC: nop
    
            goto L_80558418;
    }
    // 0x805583EC: nop

    // 0x805583F0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x805583F4: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x805583F8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x805583FC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80558400: lw          $t2, 0x1C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1C);
    // 0x80558404: bne         $t2, $t1, L_80558418
    if (ctx->r10 != ctx->r9) {
        // 0x80558408: nop
    
            goto L_80558418;
    }
    // 0x80558408: nop

    // 0x8055840C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80558410: b           L_80558418
    // 0x80558414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80558418;
    // 0x80558414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80558418:
    // 0x80558418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8055841C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558420: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80558424: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80558428: jr          $ra
    // 0x8055842C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8055842C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80776CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80776CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80776CAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80776CB0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80776CB4: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80776CB8: jal         0x80067BBC
    // 0x80776CBC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80776CBC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80776CC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80776CC4: jal         0x80067818
    // 0x80776CC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80776CC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80776CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80776CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80776CD4: jr          $ra
    // 0x80776CD8: nop

    return;
    // 0x80776CD8: nop

;}
RECOMP_FUNC void func_8070FEF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FEF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8070FEF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070FEF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070FEFC: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8070FF00: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070FF04: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8070FF08: lbu         $t6, 0x34($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X34);
    // 0x8070FF0C: lbu         $v1, -0x7204($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7204);
    // 0x8070FF10: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8070FF14: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8070FF18: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8070FF1C: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x8070FF20: sll         $a2, $v1, 4
    ctx->r6 = S32(ctx->r3 << 4);
    // 0x8070FF24: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8070FF28: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8070FF2C: lw          $a1, 0x1E4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X1E4);
    // 0x8070FF30: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8070FF34: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8070FF38: jal         0x8070FC30
    // 0x8070FF3C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8070FC30(rdram, ctx);
        goto after_0;
    // 0x8070FF3C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8070FF40: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8070FF44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8070FF48: jal         0x8070FCFC
    // 0x8070FF4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8070FCFC(rdram, ctx);
        goto after_1;
    // 0x8070FF4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8070FF50: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8070FF54: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8070FF58: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8070FF5C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8070FF60: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8070FF64: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8070FF68: jal         0x8070FDDC
    // 0x8070FF6C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    func_8070FDDC(rdram, ctx);
        goto after_2;
    // 0x8070FF6C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x8070FF70: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8070FF74: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8070FF78: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8070FF7C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8070FF80: lw          $t5, 0x1E0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X1E0);
    // 0x8070FF84: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8070FF88: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x8070FF8C: bne         $at, $zero, L_8070FFAC
    if (ctx->r1 != 0) {
        // 0x8070FF90: sw          $t6, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r14;
            goto L_8070FFAC;
    }
    // 0x8070FF90: sw          $t6, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r14;
    // 0x8070FF94: lw          $t8, 0x1E4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1E4);
    // 0x8070FF98: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8070FF9C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8070FFA0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8070FFA4: jal         0x80710C50
    // 0x8070FFA8: sw          $t9, 0x1E4($a3)
    MEM_W(0X1E4, ctx->r7) = ctx->r25;
    func_80710C50(rdram, ctx);
        goto after_3;
    // 0x8070FFA8: sw          $t9, 0x1E4($a3)
    MEM_W(0X1E4, ctx->r7) = ctx->r25;
    after_3:
L_8070FFAC:
    // 0x8070FFAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8070FFB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8070FFB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8070FFB8: jr          $ra
    // 0x8070FFBC: nop

    return;
    // 0x8070FFBC: nop

;}
RECOMP_FUNC void func_8079E2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079E2F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079E2F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079E2FC: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079E300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079E304: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8079E308: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x8079E30C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8079E310: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8079E314: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8079E318: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8079E31C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8079E320: jal         0x8079F1C0
    // 0x8079E324: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8079F1C0(rdram, ctx);
        goto after_0;
    // 0x8079E324: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8079E328: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8079E32C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8079E330: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x8079E334: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8079E338: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8079E33C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079E340: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8079E344:
    // 0x8079E344: lw          $t2, 0xFBC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XFBC);
    // 0x8079E348: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8079E34C: sllv        $t1, $t0, $v1
    ctx->r9 = S32(ctx->r8 << (ctx->r3 & 31));
    // 0x8079E350: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8079E354: beq         $t3, $zero, L_8079E368
    if (ctx->r11 == 0) {
        // 0x8079E358: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8079E368;
    }
    // 0x8079E358: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8079E35C: lw          $t4, 0x8C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8C);
    // 0x8079E360: b           L_8079E370
    // 0x8079E364: sb          $zero, 0x165($t4)
    MEM_B(0X165, ctx->r12) = 0;
        goto L_8079E370;
    // 0x8079E364: sb          $zero, 0x165($t4)
    MEM_B(0X165, ctx->r12) = 0;
L_8079E368:
    // 0x8079E368: lw          $t5, 0x8C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8C);
    // 0x8079E36C: sb          $a1, 0x165($t5)
    MEM_B(0X165, ctx->r13) = ctx->r5;
L_8079E370:
    // 0x8079E370: lw          $t9, 0xFBC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XFBC);
    // 0x8079E374: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8079E378: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8079E37C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8079E380: beq         $t0, $zero, L_8079E394
    if (ctx->r8 == 0) {
        // 0x8079E384: addiu       $t3, $v1, 0x2
        ctx->r11 = ADD32(ctx->r3, 0X2);
            goto L_8079E394;
    }
    // 0x8079E384: addiu       $t3, $v1, 0x2
    ctx->r11 = ADD32(ctx->r3, 0X2);
    // 0x8079E388: lw          $t1, 0x90($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X90);
    // 0x8079E38C: b           L_8079E39C
    // 0x8079E390: sb          $zero, 0x165($t1)
    MEM_B(0X165, ctx->r9) = 0;
        goto L_8079E39C;
    // 0x8079E390: sb          $zero, 0x165($t1)
    MEM_B(0X165, ctx->r9) = 0;
L_8079E394:
    // 0x8079E394: lw          $t2, 0x90($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X90);
    // 0x8079E398: sb          $a1, 0x165($t2)
    MEM_B(0X165, ctx->r10) = ctx->r5;
L_8079E39C:
    // 0x8079E39C: lw          $t7, 0xFBC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XFBC);
    // 0x8079E3A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8079E3A4: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8079E3A8: and         $t6, $t5, $t7
    ctx->r14 = ctx->r13 & ctx->r15;
    // 0x8079E3AC: beq         $t6, $zero, L_8079E3C0
    if (ctx->r14 == 0) {
        // 0x8079E3B0: addiu       $t0, $v1, 0x3
        ctx->r8 = ADD32(ctx->r3, 0X3);
            goto L_8079E3C0;
    }
    // 0x8079E3B0: addiu       $t0, $v1, 0x3
    ctx->r8 = ADD32(ctx->r3, 0X3);
    // 0x8079E3B4: lw          $t8, 0x94($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X94);
    // 0x8079E3B8: b           L_8079E3C8
    // 0x8079E3BC: sb          $zero, 0x165($t8)
    MEM_B(0X165, ctx->r24) = 0;
        goto L_8079E3C8;
    // 0x8079E3BC: sb          $zero, 0x165($t8)
    MEM_B(0X165, ctx->r24) = 0;
L_8079E3C0:
    // 0x8079E3C0: lw          $t9, 0x94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X94);
    // 0x8079E3C4: sb          $a1, 0x165($t9)
    MEM_B(0X165, ctx->r25) = ctx->r5;
L_8079E3C8:
    // 0x8079E3C8: lw          $t4, 0xFBC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XFBC);
    // 0x8079E3CC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8079E3D0: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8079E3D4: and         $t3, $t2, $t4
    ctx->r11 = ctx->r10 & ctx->r12;
    // 0x8079E3D8: beq         $t3, $zero, L_8079E3EC
    if (ctx->r11 == 0) {
        // 0x8079E3DC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8079E3EC;
    }
    // 0x8079E3DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8079E3E0: lw          $t5, 0x98($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X98);
    // 0x8079E3E4: b           L_8079E3F4
    // 0x8079E3E8: sb          $zero, 0x165($t5)
    MEM_B(0X165, ctx->r13) = 0;
        goto L_8079E3F4;
    // 0x8079E3E8: sb          $zero, 0x165($t5)
    MEM_B(0X165, ctx->r13) = 0;
L_8079E3EC:
    // 0x8079E3EC: lw          $t7, 0x98($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X98);
    // 0x8079E3F0: sb          $a1, 0x165($t7)
    MEM_B(0X165, ctx->r15) = ctx->r5;
L_8079E3F4:
    // 0x8079E3F4: bne         $v1, $a2, L_8079E344
    if (ctx->r3 != ctx->r6) {
        // 0x8079E3F8: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_8079E344;
    }
    // 0x8079E3F8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8079E3FC: lw          $t6, 0x84($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X84);
    // 0x8079E400: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1970) << 16);
    // 0x8079E404: sb          $zero, 0x165($t6)
    MEM_B(0X165, ctx->r14) = 0;
    // 0x8079E408: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8079E40C: lw          $t0, 0x84($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X84);
    // 0x8079E410: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8079E414: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x8079E418: lw          $t1, 0x8C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8C);
    // 0x8079E41C: lwc1        $f4, 0x3C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X3C);
    // 0x8079E420: swc1        $f4, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f4.u32l;
    // 0x8079E424: lw          $t2, 0x8C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8C);
    // 0x8079E428: lw          $t4, 0x84($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X84);
    // 0x8079E42C: lwc1        $f6, 0x40($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X40);
    // 0x8079E430: swc1        $f6, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f6.u32l;
    // 0x8079E434: lw          $t3, 0x84($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X84);
    // 0x8079E438: lwc1        $f8, -0xBA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1970));
    // 0x8079E43C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1974) << 16);
    // 0x8079E440: swc1        $f8, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f8.u32l;
    // 0x8079E444: lw          $t5, 0x84($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X84);
    // 0x8079E448: lwc1        $f10, -0xB9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1974));
    // 0x8079E44C: swc1        $f10, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f10.u32l;
    // 0x8079E450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079E454: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8079E458: jr          $ra
    // 0x8079E45C: nop

    return;
    // 0x8079E45C: nop

;}
RECOMP_FUNC void func_804467EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804467EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804467F0: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x804467F4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804467F8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x804467FC: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x80446800: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446804: jr          $ra
    // 0x80446808: sw          $t7, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = ctx->r15;
    return;
    // 0x80446808: sw          $t7, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8000CEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CEEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CEF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000CEF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000CEF8: sb          $t6, 0xA0($a0)
    MEM_B(0XA0, ctx->r4) = ctx->r14;
    // 0x8000CEFC: sw          $zero, 0x90($a0)
    MEM_W(0X90, ctx->r4) = 0;
    // 0x8000CF00: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8000CF04: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8000CF08: lw          $t7, 0x61B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X61B8);
    // 0x8000CF0C: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x8000CF10: sw          $t7, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r15;
    // 0x8000CF14: lw          $t9, 0x50($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X50);
    // 0x8000CF18: sw          $t9, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r25;
    // 0x8000CF1C: lhu         $a1, 0x1A($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X1A);
    // 0x8000CF20: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8000CF24: bne         $a1, $zero, L_8000CF48
    if (ctx->r5 != 0) {
        // 0x8000CF28: sh          $a1, 0xA4($a0)
        MEM_H(0XA4, ctx->r4) = ctx->r5;
            goto L_8000CF48;
    }
    // 0x8000CF28: sh          $a1, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r5;
    // 0x8000CF2C: lhu         $t0, 0x16($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X16);
    // 0x8000CF30: addiu       $v0, $a0, 0x8C
    ctx->r2 = ADD32(ctx->r4, 0X8C);
    // 0x8000CF34: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8000CF38: nop

    // 0x8000CF3C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000CF40: b           L_8000CF60
    // 0x8000CF44: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
        goto L_8000CF60;
    // 0x8000CF44: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
L_8000CF48:
    // 0x8000CF48: lhu         $t1, 0x12($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X12);
    // 0x8000CF4C: addiu       $v0, $a0, 0x8C
    ctx->r2 = ADD32(ctx->r4, 0X8C);
    // 0x8000CF50: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8000CF54: nop

    // 0x8000CF58: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000CF5C: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
L_8000CF60:
    // 0x8000CF60: lhu         $a1, 0x18($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X18);
    // 0x8000CF64: bne         $a1, $zero, L_8000CF84
    if (ctx->r5 != 0) {
        // 0x8000CF68: sh          $a1, 0x16($v0)
        MEM_H(0X16, ctx->r2) = ctx->r5;
            goto L_8000CF84;
    }
    // 0x8000CF68: sh          $a1, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r5;
    // 0x8000CF6C: lhu         $t2, 0x14($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X14);
    // 0x8000CF70: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8000CF74: nop

    // 0x8000CF78: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000CF7C: b           L_8000CF98
    // 0x8000CF80: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
        goto L_8000CF98;
    // 0x8000CF80: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
L_8000CF84:
    // 0x8000CF84: lhu         $t3, 0x10($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X10);
    // 0x8000CF88: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8000CF8C: nop

    // 0x8000CF90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000CF94: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
L_8000CF98:
    // 0x8000CF98: lhu         $t4, 0x1C($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X1C);
    // 0x8000CF9C: jr          $ra
    // 0x8000CFA0: sh          $t4, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r12;
    return;
    // 0x8000CFA0: sh          $t4, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r12;
;}
RECOMP_FUNC void func_80464C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80464C60: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80464C64: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x80464C68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80464C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80464C70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80464C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80464C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80464C7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80464C80: jal         0x804653B8
    // 0x80464C84: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_804653B8(rdram, ctx);
        goto after_0;
    // 0x80464C84: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80464C88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80464C8C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80464C90: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80464C94: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80464C98: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80464C9C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80464CA0: nop

    // 0x80464CA4: bc1tl       L_80464CB4
    if (c1cs) {
        // 0x80464CA8: lwc1        $f6, 0x30($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
            goto L_80464CB4;
    }
    goto skip_0;
    // 0x80464CA8: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    skip_0:
    // 0x80464CAC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80464CB0: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
L_80464CB4:
    // 0x80464CB4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x80464CB8: lwc1        $f8, 0x34($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80464CBC: jal         0x80464650
    // 0x80464CC0: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    func_80464650(rdram, ctx);
        goto after_1;
    // 0x80464CC0: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    after_1:
    // 0x80464CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80464CC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80464CCC: jr          $ra
    // 0x80464CD0: nop

    return;
    // 0x80464CD0: nop

;}
RECOMP_FUNC void Fault_DisplayFramebuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070F1C: lui         $t9, 0xFFFA
    ctx->r25 = S32(0XFFFA << 16);
    // 0x80070F20: or          $t0, $sp, $zero
    ctx->r8 = ctx->r29 | 0;
    // 0x80070F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070F28: ori         $t9, $t9, 0x5A5A
    ctx->r25 = ctx->r25 | 0X5A5A;
L_80070F2C:
    // 0x80070F2C: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x80070F30: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80070F34: bne         $t0, $sp, L_80070F2C
    if (ctx->r8 != ctx->r29) {
        // 0x80070F38: sw          $t9, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r25;
            goto L_80070F2C;
    }
    // 0x80070F38: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80070F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070F40: jal         0x800867A0
    // 0x80070F44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_0;
    // 0x80070F44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80070F48: jal         0x800914F0
    // 0x80070F4C: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80070F4C: nop

    after_1:
    // 0x80070F50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80070F54: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x80070F58: bne         $at, $zero, L_80070F78
    if (ctx->r1 != 0) {
        // 0x80070F5C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80070F78;
    }
    // 0x80070F5C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80070F60: jal         0x800914F0
    // 0x80070F64: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x80070F64: nop

    after_2:
    // 0x80070F68: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80070F6C: addiu       $v1, $v1, -0x7968
    ctx->r3 = ADD32(ctx->r3, -0X7968);
    // 0x80070F70: b           L_80070FA0
    // 0x80070F74: sw          $v0, 0x5CC($v1)
    MEM_W(0X5CC, ctx->r3) = ctx->r2;
        goto L_80070FA0;
    // 0x80070F74: sw          $v0, 0x5CC($v1)
    MEM_W(0X5CC, ctx->r3) = ctx->r2;
L_80070F78:
    // 0x80070F78: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80070F7C: lw          $t6, 0x318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X318);
    // 0x80070F80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80070F84: addiu       $v1, $v1, -0x7968
    ctx->r3 = ADD32(ctx->r3, -0X7968);
    // 0x80070F88: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80070F8C: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80070F90: ori         $at, $at, 0xA800
    ctx->r1 = ctx->r1 | 0XA800;
    // 0x80070F94: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    // 0x80070F98: jal         0x8008B230
    // 0x80070F9C: sw          $a0, 0x5CC($v1)
    MEM_W(0X5CC, ctx->r3) = ctx->r4;
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80070F9C: sw          $a0, 0x5CC($v1)
    MEM_W(0X5CC, ctx->r3) = ctx->r4;
    after_3:
L_80070FA0:
    // 0x80070FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070FA8: jr          $ra
    // 0x80070FAC: nop

    return;
    // 0x80070FAC: nop

;}
RECOMP_FUNC void func_80036924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036924: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80036928: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8003692C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80036930: lw          $t6, 0xA68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA68);
    // 0x80036934: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80036938: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8003693C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80036940: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80036944: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80036948: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8003694C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80036950: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80036954: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80036958: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8003695C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80036960: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80036964: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80036968: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8003696C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80036970: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80036974: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80036978: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8003697C: lw          $t8, 0x70($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X70);
    // 0x80036980: beql        $t8, $zero, L_80036B0C
    if (ctx->r24 == 0) {
        // 0x80036984: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80036B0C;
    }
    goto skip_0;
    // 0x80036984: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x80036988: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x8003698C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80036990: bnel        $t0, $zero, L_80036B0C
    if (ctx->r8 != 0) {
        // 0x80036994: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80036B0C;
    }
    goto skip_1;
    // 0x80036994: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_1:
    // 0x80036998: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x8003699C: lbu         $t2, 0x12($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X12);
    // 0x800369A0: beql        $t2, $zero, L_80036B0C
    if (ctx->r10 == 0) {
        // 0x800369A4: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80036B0C;
    }
    goto skip_2;
    // 0x800369A4: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_2:
    // 0x800369A8: lw          $t3, 0x1F4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1F4);
    // 0x800369AC: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800369B0: lwc1        $f22, 0x50($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800369B4: jal         0x80066DE4
    // 0x800369B8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x800369B8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x800369BC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800369C0: jal         0x80066E88
    // 0x800369C4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x800369C4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x800369C8: jal         0x800653D8
    // 0x800369CC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x800369CC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_2:
    // 0x800369D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800369D4: lwc1        $f6, 0xE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE0);
    // 0x800369D8: lwc1        $f4, 0x8C($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X8C);
    // 0x800369DC: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x800369E0: lui         $s6, 0x800A
    ctx->r22 = S32(0X800A << 16);
    // 0x800369E4: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x800369E8: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x800369EC: andi        $s3, $v0, 0x7
    ctx->r19 = ctx->r2 & 0X7;
    // 0x800369F0: lwc1        $f28, 0x84($fp)
    ctx->f28.u32l = MEM_W(ctx->r30, 0X84);
    // 0x800369F4: lwc1        $f30, 0x88($fp)
    ctx->f30.u32l = MEM_W(ctx->r30, 0X88);
    // 0x800369F8: addiu       $s4, $s4, -0x1514
    ctx->r20 = ADD32(ctx->r20, -0X1514);
    // 0x800369FC: addiu       $s5, $s5, -0x14B4
    ctx->r21 = ADD32(ctx->r21, -0X14B4);
    // 0x80036A00: addiu       $s6, $s6, -0x1454
    ctx->r22 = ADD32(ctx->r22, -0X1454);
    // 0x80036A04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80036A08: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80036A0C: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80036A10: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80036A14: lwc1        $f26, 0x64($s1)
    ctx->f26.u32l = MEM_W(ctx->r17, 0X64);
L_80036A18:
    // 0x80036A18: lw          $t5, 0x130($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X130);
    // 0x80036A1C: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x80036A20: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x80036A24: beq         $t5, $zero, L_80036AAC
    if (ctx->r13 == 0) {
        // 0x80036A28: sll         $v0, $s3, 2
        ctx->r2 = S32(ctx->r19 << 2);
            goto L_80036AAC;
    }
    // 0x80036A28: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80036A2C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80036A30: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80036A34: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    // 0x80036A38: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x80036A3C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80036A40: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80036A44: lwc1        $f2, 0x0($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80036A48: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80036A4C: addu        $t2, $s6, $s2
    ctx->r10 = ADD32(ctx->r22, ctx->r18);
    // 0x80036A50: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80036A54: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80036A58: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80036A5C: lw          $t4, -0x76F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76F8);
    // 0x80036A60: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x80036A64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80036A68: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80036A6C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80036A70: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80036A74: lw          $t9, 0x70($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X70);
    // 0x80036A78: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80036A7C: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80036A80: nop

    // 0x80036A84: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80036A88: nop

    // 0x80036A8C: mul.s       $f8, $f2, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80036A90: add.s       $f12, $f18, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x80036A94: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80036A98: jalr        $t9
    // 0x80036A9C: add.s       $f14, $f10, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f30.fl;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80036A9C: add.s       $f14, $f10, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f30.fl;
    after_3:
    // 0x80036AA0: lw          $t6, 0x130($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X130);
    // 0x80036AA4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80036AA8: sw          $t7, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->r15;
L_80036AAC:
    // 0x80036AAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80036AB0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80036AB4: bne         $s0, $s7, L_80036A18
    if (ctx->r16 != ctx->r23) {
        // 0x80036AB8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80036A18;
    }
    // 0x80036AB8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80036ABC: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80036AC0: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80036AC4: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80036AC8: lw          $t0, 0x138($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X138);
    // 0x80036ACC: beql        $t0, $zero, L_80036AE0
    if (ctx->r8 == 0) {
        // 0x80036AD0: lw          $v0, 0x13C($t2)
        ctx->r2 = MEM_W(ctx->r10, 0X13C);
            goto L_80036AE0;
    }
    goto skip_3;
    // 0x80036AD0: lw          $v0, 0x13C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X13C);
    skip_3:
    // 0x80036AD4: b           L_80036B08
    // 0x80036AD8: sw          $t1, 0x13C($t8)
    MEM_W(0X13C, ctx->r24) = ctx->r9;
        goto L_80036B08;
    // 0x80036AD8: sw          $t1, 0x13C($t8)
    MEM_W(0X13C, ctx->r24) = ctx->r9;
    // 0x80036ADC: lw          $v0, 0x13C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X13C);
L_80036AE0:
    // 0x80036AE0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80036AE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80036AE8: bne         $v0, $zero, L_80036B00
    if (ctx->r2 != 0) {
        // 0x80036AEC: lw          $t4, 0x7C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X7C);
            goto L_80036B00;
    }
    // 0x80036AEC: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80036AF0: jal         0x80036900
    // 0x80036AF4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80036900(rdram, ctx);
        goto after_4;
    // 0x80036AF4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80036AF8: b           L_80036B0C
    // 0x80036AFC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
        goto L_80036B0C;
    // 0x80036AFC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80036B00:
    // 0x80036B00: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80036B04: sw          $t3, 0x13C($t4)
    MEM_W(0X13C, ctx->r12) = ctx->r11;
L_80036B08:
    // 0x80036B08: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80036B0C:
    // 0x80036B0C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80036B10: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80036B14: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80036B18: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80036B1C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80036B20: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80036B24: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80036B28: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80036B2C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80036B30: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80036B34: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80036B38: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80036B3C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80036B40: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80036B44: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80036B48: jr          $ra
    // 0x80036B4C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80036B4C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_804BAC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BAC0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BAC10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BAC14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BAC18: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x804BAC1C: lui         $at, 0x41FB
    ctx->r1 = S32(0X41FB << 16);
    // 0x804BAC20: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x804BAC24: addiu       $v0, $v0, -0x41F1
    ctx->r2 = ADD32(ctx->r2, -0X41F1);
    // 0x804BAC28: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x804BAC2C: addiu       $a0, $v0, 0x200
    ctx->r4 = ADD32(ctx->r2, 0X200);
    // 0x804BAC30: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // 0x804BAC34: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x804BAC38: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x804BAC3C: jal         0x8004613C
    // 0x804BAC40: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x804BAC40: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_0:
    // 0x804BAC44: beq         $v0, $zero, L_804BAC6C
    if (ctx->r2 == 0) {
        // 0x804BAC48: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804BAC6C;
    }
    // 0x804BAC48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804BAC4C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC30) << 16);
    // 0x804BAC50: lwc1        $f4, -0x4870($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC30));
    // 0x804BAC54: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC34) << 16);
    // 0x804BAC58: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
    // 0x804BAC5C: lwc1        $f6, -0x486C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC34));
    // 0x804BAC60: swc1        $f6, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f6.u32l;
    // 0x804BAC64: jal         0x80047F9C
    // 0x804BAC68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x804BAC68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_804BAC6C:
    // 0x804BAC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BAC70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BAC74: jr          $ra
    // 0x804BAC78: nop

    return;
    // 0x804BAC78: nop

;}
RECOMP_FUNC void func_806B24CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B24CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B24D0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B24D4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B24D8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B24DC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B24E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B24E4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B24E8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B24EC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B24F0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B24F4: jr          $ra
    // 0x806B24F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B24F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C6D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C6D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C6D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C6D10: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804C6D14: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804C6D18: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(221, 0X318) << 16);
    // 0x804C6D1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C6D20: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804C6D24: lw          $t8, 0x6F78($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(221, 0X318));
    // 0x804C6D28: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804C6D2C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804C6D30: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804C6D34: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804C6D38: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C6D3C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804C6D40: beql        $v1, $zero, L_804C6D74
    if (ctx->r3 == 0) {
        // 0x804C6D44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C6D74;
    }
    goto skip_0;
    // 0x804C6D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C6D48: jalr        $v1
    // 0x804C6D4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804C6D4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C6D50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C6D54: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804C6D58: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804C6D5C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804C6D60: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804C6D64: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804C6D68: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804C6D6C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804C6D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6D74:
    // 0x804C6D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C6D78: jr          $ra
    // 0x804C6D7C: nop

    return;
    // 0x804C6D7C: nop

;}
RECOMP_FUNC void func_806B279C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B279C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B27A0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B27A4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B27A8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B27AC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B27B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B27B4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B27B8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B27BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B27C0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B27C4: jr          $ra
    // 0x806B27C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B27C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8066E4C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066E4C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8066E4CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066E4D0: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x8066E4D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8066E4D8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8066E4DC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8066E4E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066E4E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8066E4E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8066E4EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8066E4F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8066E4F4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8066E4F8: lui         $t1, 0x8067
    ctx->r9 = S32(RELOC_HI16(517, 0X2B60) << 16);
    // 0x8066E4FC: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x8066E500: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8066E504: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8066E508: lw          $t1, 0x120($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(517, 0X2B60));
    // 0x8066E50C: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x8066E510: jal         0x8066E1AC
    // 0x8066E514: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_8066E1AC(rdram, ctx);
        goto after_0;
    // 0x8066E514: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x8066E518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066E51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066E520: jr          $ra
    // 0x8066E524: nop

    return;
    // 0x8066E524: nop

    // 0x8066E528: nop

    // 0x8066E52C: nop

;}
