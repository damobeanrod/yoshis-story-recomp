#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804BB3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB3E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BB3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB3E8: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(188, 0XC54) << 16);
    // 0x804BB3EC: lwc1        $f6, -0x484C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(188, 0XC54));
    // 0x804BB3F0: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BB3F4: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804BB3F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804BB3FC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804BB400: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x804BB404: jal         0x804BB604
    // 0x804BB408: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_804BB604(rdram, ctx);
        goto after_0;
    // 0x804BB408: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x804BB40C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804BB410: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804BB414: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x804BB418: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804BB41C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x804BB420: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804BB424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB428: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x804BB42C: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x804BB430: swc1        $f0, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f0.u32l;
    // 0x804BB434: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804BB438: bc1f        L_804BB44C
    if (!c1cs) {
        // 0x804BB43C: nop
    
            goto L_804BB44C;
    }
    // 0x804BB43C: nop

    // 0x804BB440: jal         0x804BB4C4
    // 0x804BB444: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_804BB4C4(rdram, ctx);
        goto after_1;
    // 0x804BB444: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x804BB448: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_804BB44C:
    // 0x804BB44C: jal         0x804BAFE4
    // 0x804BB450: lw          $a0, 0x16C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X16C);
    func_804BAFE4(rdram, ctx);
        goto after_2;
    // 0x804BB450: lw          $a0, 0x16C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X16C);
    after_2:
    // 0x804BB454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BB458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BB45C: jr          $ra
    // 0x804BB460: nop

    return;
    // 0x804BB460: nop

;}
RECOMP_FUNC void func_80062E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062E30: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80062E34: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062E38: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80062E3C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062E40: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80062E44: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80062E48: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062E4C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062E50: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062E54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062E58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062E5C: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x80062E60: sw          $a1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r5;
    // 0x80062E64: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80062E68: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80062E6C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80062E70: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
    // 0x80062E74: lw          $t5, 0xC($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XC);
    // 0x80062E78: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80062E7C: lw          $t0, 0x8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X8);
    // 0x80062E80: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x80062E84: mflo        $s1
    ctx->r17 = lo;
    // 0x80062E88: sll         $ra, $t5, 2
    ctx->r31 = S32(ctx->r13 << 2);
    // 0x80062E8C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80062E90: subu        $s2, $ra, $t5
    ctx->r18 = SUB32(ctx->r31, ctx->r13);
    // 0x80062E94: div         $zero, $s2, $at
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r1)));
    // 0x80062E98: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80062E9C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80062EA0: lw          $s3, 0x4($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X4);
    // 0x80062EA4: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x80062EA8: lw          $s5, 0x18($a3)
    ctx->r21 = MEM_W(ctx->r7, 0X18);
    // 0x80062EAC: lw          $fp, 0x1C($a3)
    ctx->r30 = MEM_W(ctx->r7, 0X1C);
    // 0x80062EB0: addiu       $s6, $sp, 0xD4
    ctx->r22 = ADD32(ctx->r29, 0XD4);
    // 0x80062EB4: mfhi        $t4
    ctx->r12 = hi;
    // 0x80062EB8: addiu       $t1, $v1, 0x2
    ctx->r9 = ADD32(ctx->r3, 0X2);
    // 0x80062EBC: addiu       $t2, $v1, 0x4
    ctx->r10 = ADD32(ctx->r3, 0X4);
    // 0x80062EC0: addiu       $t3, $v1, 0x6
    ctx->r11 = ADD32(ctx->r3, 0X6);
    // 0x80062EC4: sw          $t3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r11;
    // 0x80062EC8: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x80062ECC: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x80062ED0: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x80062ED4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80062ED8: sw          $a3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r7;
    // 0x80062EDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80062EE0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80062EE4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x80062EE8: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
    // 0x80062EEC: addiu       $s0, $s3, 0x2
    ctx->r16 = ADD32(ctx->r19, 0X2);
    // 0x80062EF0: jal         0x80077338
    // 0x80062EF4: sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x80062EF4: sw          $s3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r19;
    after_0:
    // 0x80062EF8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80062EFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80062F00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80062F04: jal         0x8007711C
    // 0x80062F08: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x80062F08: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x80062F0C: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x80062F10: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80062F14: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x80062F18: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x80062F1C: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
    // 0x80062F20: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80062F24: blez        $s2, L_80063098
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80062F28: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80063098;
    }
    // 0x80062F28: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80062F2C: andi        $v0, $s2, 0x3
    ctx->r2 = ctx->r18 & 0X3;
    // 0x80062F30: beq         $v0, $zero, L_80062F94
    if (ctx->r2 == 0) {
        // 0x80062F34: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80062F94;
    }
    // 0x80062F34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80062F38: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80062F3C:
    // 0x80062F3C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80062F40: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80062F44: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80062F48: sh          $t9, -0x10($t0)
    MEM_H(-0X10, ctx->r8) = ctx->r25;
    // 0x80062F4C: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80062F50: sh          $zero, -0xA($t0)
    MEM_H(-0XA, ctx->r8) = 0;
    // 0x80062F54: sh          $zero, -0xC($t0)
    MEM_H(-0XC, ctx->r8) = 0;
    // 0x80062F58: sh          $t6, -0xE($t0)
    MEM_H(-0XE, ctx->r8) = ctx->r14;
    // 0x80062F5C: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x80062F60: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80062F64: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80062F68: sh          $t7, -0x8($t0)
    MEM_H(-0X8, ctx->r8) = ctx->r15;
    // 0x80062F6C: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x80062F70: sb          $a0, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r4;
    // 0x80062F74: sb          $a0, -0x3($t0)
    MEM_B(-0X3, ctx->r8) = ctx->r4;
    // 0x80062F78: sb          $a0, -0x2($t0)
    MEM_B(-0X2, ctx->r8) = ctx->r4;
    // 0x80062F7C: sb          $a0, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r4;
    // 0x80062F80: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80062F84: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x80062F88: bne         $a1, $s4, L_80062F3C
    if (ctx->r5 != ctx->r20) {
        // 0x80062F8C: sh          $t8, -0x6($t0)
        MEM_H(-0X6, ctx->r8) = ctx->r24;
            goto L_80062F3C;
    }
    // 0x80062F8C: sh          $t8, -0x6($t0)
    MEM_H(-0X6, ctx->r8) = ctx->r24;
    // 0x80062F90: beq         $s4, $s2, L_80063094
    if (ctx->r20 == ctx->r18) {
        // 0x80062F94: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80063094;
    }
L_80062F94:
    // 0x80062F94: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80062F98:
    // 0x80062F98: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80062F9C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80062FA0: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x80062FA4: sh          $t9, -0x40($t0)
    MEM_H(-0X40, ctx->r8) = ctx->r25;
    // 0x80062FA8: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80062FAC: sh          $zero, -0x3C($t0)
    MEM_H(-0X3C, ctx->r8) = 0;
    // 0x80062FB0: sh          $zero, -0x3A($t0)
    MEM_H(-0X3A, ctx->r8) = 0;
    // 0x80062FB4: sh          $t6, -0x3E($t0)
    MEM_H(-0X3E, ctx->r8) = ctx->r14;
    // 0x80062FB8: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x80062FBC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80062FC0: addiu       $t1, $t1, 0x20
    ctx->r9 = ADD32(ctx->r9, 0X20);
    // 0x80062FC4: sh          $t7, -0x38($t0)
    MEM_H(-0X38, ctx->r8) = ctx->r15;
    // 0x80062FC8: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x80062FCC: sb          $a0, -0x34($t0)
    MEM_B(-0X34, ctx->r8) = ctx->r4;
    // 0x80062FD0: sb          $a0, -0x33($t0)
    MEM_B(-0X33, ctx->r8) = ctx->r4;
    // 0x80062FD4: sb          $a0, -0x32($t0)
    MEM_B(-0X32, ctx->r8) = ctx->r4;
    // 0x80062FD8: sb          $a0, -0x31($t0)
    MEM_B(-0X31, ctx->r8) = ctx->r4;
    // 0x80062FDC: sh          $t8, -0x36($t0)
    MEM_H(-0X36, ctx->r8) = ctx->r24;
    // 0x80062FE0: lh          $t9, -0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, -0X18);
    // 0x80062FE4: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80062FE8: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x80062FEC: sh          $t9, -0x30($t0)
    MEM_H(-0X30, ctx->r8) = ctx->r25;
    // 0x80062FF0: lh          $t6, -0x18($t1)
    ctx->r14 = MEM_H(ctx->r9, -0X18);
    // 0x80062FF4: sh          $zero, -0x2A($t0)
    MEM_H(-0X2A, ctx->r8) = 0;
    // 0x80062FF8: sh          $zero, -0x2C($t0)
    MEM_H(-0X2C, ctx->r8) = 0;
    // 0x80062FFC: sh          $t6, -0x2E($t0)
    MEM_H(-0X2E, ctx->r8) = ctx->r14;
    // 0x80063000: lh          $t7, -0x18($t2)
    ctx->r15 = MEM_H(ctx->r10, -0X18);
    // 0x80063004: sh          $t7, -0x28($t0)
    MEM_H(-0X28, ctx->r8) = ctx->r15;
    // 0x80063008: lh          $t8, -0x18($t3)
    ctx->r24 = MEM_H(ctx->r11, -0X18);
    // 0x8006300C: sb          $a0, -0x24($t0)
    MEM_B(-0X24, ctx->r8) = ctx->r4;
    // 0x80063010: sb          $a0, -0x23($t0)
    MEM_B(-0X23, ctx->r8) = ctx->r4;
    // 0x80063014: sb          $a0, -0x22($t0)
    MEM_B(-0X22, ctx->r8) = ctx->r4;
    // 0x80063018: sb          $a0, -0x21($t0)
    MEM_B(-0X21, ctx->r8) = ctx->r4;
    // 0x8006301C: sh          $t8, -0x26($t0)
    MEM_H(-0X26, ctx->r8) = ctx->r24;
    // 0x80063020: lh          $t9, -0x10($v1)
    ctx->r25 = MEM_H(ctx->r3, -0X10);
    // 0x80063024: sh          $t9, -0x20($t0)
    MEM_H(-0X20, ctx->r8) = ctx->r25;
    // 0x80063028: lh          $t6, -0x10($t1)
    ctx->r14 = MEM_H(ctx->r9, -0X10);
    // 0x8006302C: sh          $zero, -0x1A($t0)
    MEM_H(-0X1A, ctx->r8) = 0;
    // 0x80063030: sh          $zero, -0x1C($t0)
    MEM_H(-0X1C, ctx->r8) = 0;
    // 0x80063034: sh          $t6, -0x1E($t0)
    MEM_H(-0X1E, ctx->r8) = ctx->r14;
    // 0x80063038: lh          $t7, -0x10($t2)
    ctx->r15 = MEM_H(ctx->r10, -0X10);
    // 0x8006303C: sh          $t7, -0x18($t0)
    MEM_H(-0X18, ctx->r8) = ctx->r15;
    // 0x80063040: lh          $t8, -0x10($t3)
    ctx->r24 = MEM_H(ctx->r11, -0X10);
    // 0x80063044: sb          $a0, -0x14($t0)
    MEM_B(-0X14, ctx->r8) = ctx->r4;
    // 0x80063048: sb          $a0, -0x13($t0)
    MEM_B(-0X13, ctx->r8) = ctx->r4;
    // 0x8006304C: sb          $a0, -0x12($t0)
    MEM_B(-0X12, ctx->r8) = ctx->r4;
    // 0x80063050: sb          $a0, -0x11($t0)
    MEM_B(-0X11, ctx->r8) = ctx->r4;
    // 0x80063054: sh          $t8, -0x16($t0)
    MEM_H(-0X16, ctx->r8) = ctx->r24;
    // 0x80063058: lh          $t9, -0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, -0X8);
    // 0x8006305C: sh          $t9, -0x10($t0)
    MEM_H(-0X10, ctx->r8) = ctx->r25;
    // 0x80063060: lh          $t6, -0x8($t1)
    ctx->r14 = MEM_H(ctx->r9, -0X8);
    // 0x80063064: sh          $zero, -0xA($t0)
    MEM_H(-0XA, ctx->r8) = 0;
    // 0x80063068: sh          $zero, -0xC($t0)
    MEM_H(-0XC, ctx->r8) = 0;
    // 0x8006306C: sh          $t6, -0xE($t0)
    MEM_H(-0XE, ctx->r8) = ctx->r14;
    // 0x80063070: lh          $t7, -0x8($t2)
    ctx->r15 = MEM_H(ctx->r10, -0X8);
    // 0x80063074: sh          $t7, -0x8($t0)
    MEM_H(-0X8, ctx->r8) = ctx->r15;
    // 0x80063078: lh          $t8, -0x8($t3)
    ctx->r24 = MEM_H(ctx->r11, -0X8);
    // 0x8006307C: sb          $a0, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r4;
    // 0x80063080: sb          $a0, -0x3($t0)
    MEM_B(-0X3, ctx->r8) = ctx->r4;
    // 0x80063084: sb          $a0, -0x2($t0)
    MEM_B(-0X2, ctx->r8) = ctx->r4;
    // 0x80063088: sb          $a0, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r4;
    // 0x8006308C: bne         $s4, $s2, L_80062F98
    if (ctx->r20 != ctx->r18) {
        // 0x80063090: sh          $t8, -0x6($t0)
        MEM_H(-0X6, ctx->r8) = ctx->r24;
            goto L_80062F98;
    }
    // 0x80063090: sh          $t8, -0x6($t0)
    MEM_H(-0X6, ctx->r8) = ctx->r24;
L_80063094:
    // 0x80063094: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80063098:
    // 0x80063098: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x8006309C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800630A0: beq         $s1, $zero, L_800630CC
    if (ctx->r17 == 0) {
        // 0x800630A4: lw          $t0, 0x8($t9)
        ctx->r8 = MEM_W(ctx->r25, 0X8);
            goto L_800630CC;
    }
    // 0x800630A4: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800630A8: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800630AC: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800630B0: ori         $t5, $t5, 0x79DF
    ctx->r13 = ctx->r13 | 0X79DF;
    // 0x800630B4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800630B8: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
    // 0x800630BC: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800630C0: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800630C4: b           L_80063104
    // 0x800630C8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_80063104;
    // 0x800630C8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_800630CC:
    // 0x800630CC: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
    // 0x800630D0: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x800630D4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800630D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800630DC: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    // 0x800630E0: sll         $t6, $t4, 10
    ctx->r14 = S32(ctx->r12 << 10);
    // 0x800630E4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800630E8: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800630EC: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800630F0: or          $t6, $t7, $ra
    ctx->r14 = ctx->r15 | ctx->r31;
    // 0x800630F4: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800630F8: ori         $t5, $t5, 0x79DF
    ctx->r13 = ctx->r13 | 0X79DF;
    // 0x800630FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80063100: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_80063104:
    // 0x80063104: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x80063108: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006310C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80063110: blez        $t8, L_800633D8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80063114: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_800633D8;
    }
    // 0x80063114: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80063118: multu       $s5, $fp
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006311C: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x80063120: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80063124: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x80063128: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8006312C: addiu       $t7, $s5, -0x1
    ctx->r15 = ADD32(ctx->r21, -0X1);
    // 0x80063130: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80063134: addiu       $t7, $fp, -0x1
    ctx->r15 = ADD32(ctx->r30, -0X1);
    // 0x80063138: lui         $fp, 0x700
    ctx->r30 = S32(0X700 << 16);
    // 0x8006313C: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
    // 0x80063140: mflo        $s7
    ctx->r23 = lo;
    // 0x80063144: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80063148: sra         $s7, $s7, 1
    ctx->r23 = S32(SIGNED(ctx->r23) >> 1);
    // 0x8006314C: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80063150: bgez        $v0, L_80063160
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80063154: sra         $s6, $v0, 3
        ctx->r22 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80063160;
    }
    // 0x80063154: sra         $s6, $v0, 3
    ctx->r22 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80063158: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8006315C: sra         $s6, $at, 3
    ctx->r22 = S32(SIGNED(ctx->r1) >> 3);
L_80063160:
    // 0x80063160: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80063164: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80063168: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8006316C: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80063170: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80063174: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80063178: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8006317C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80063180: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80063184:
    // 0x80063184: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80063188: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8006318C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
    // 0x80063190: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x80063194: lw          $t9, 0x24($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X24);
    // 0x80063198: slti        $at, $s7, 0x7FF
    ctx->r1 = SIGNED(ctx->r23) < 0X7FF ? 1 : 0;
    // 0x8006319C: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800631A0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800631A4: lhu         $t7, 0x0($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X0);
    // 0x800631A8: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x800631AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800631B0: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
    // 0x800631B4: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x800631B8: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x800631BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800631C0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800631C4: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x800631C8: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x800631CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800631D0: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800631D4: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
    // 0x800631D8: sw          $fp, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r30;
    // 0x800631DC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800631E0: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800631E4: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800631E8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800631EC: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800631F0: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    // 0x800631F4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800631F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800631FC: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x80063200: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80063204: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80063208: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8006320C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
    // 0x80063210: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80063214: beq         $at, $zero, L_80063224
    if (ctx->r1 == 0) {
        // 0x80063218: or          $s5, $t8, $zero
        ctx->r21 = ctx->r24 | 0;
            goto L_80063224;
    }
    // 0x80063218: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x8006321C: b           L_80063228
    // 0x80063220: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
        goto L_80063228;
    // 0x80063220: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_80063224:
    // 0x80063224: addiu       $s2, $zero, 0x7FF
    ctx->r18 = ADD32(0, 0X7FF);
L_80063228:
    // 0x80063228: bgtz        $s6, L_80063238
    if (SIGNED(ctx->r22) > 0) {
        // 0x8006322C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80063238;
    }
    // 0x8006322C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80063230: b           L_8006323C
    // 0x80063234: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_8006323C;
    // 0x80063234: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80063238:
    // 0x80063238: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
L_8006323C:
    // 0x8006323C: bgtz        $s6, L_8006324C
    if (SIGNED(ctx->r22) > 0) {
        // 0x80063240: addiu       $t6, $s3, 0x7FF
        ctx->r14 = ADD32(ctx->r19, 0X7FF);
            goto L_8006324C;
    }
    // 0x80063240: addiu       $t6, $s3, 0x7FF
    ctx->r14 = ADD32(ctx->r19, 0X7FF);
    // 0x80063244: b           L_80063250
    // 0x80063248: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80063250;
    // 0x80063248: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8006324C:
    // 0x8006324C: or          $t2, $s6, $zero
    ctx->r10 = ctx->r22 | 0;
L_80063250:
    // 0x80063250: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x80063254: mflo        $t8
    ctx->r24 = lo;
    // 0x80063258: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8006325C: bne         $t2, $zero, L_80063268
    if (ctx->r10 != 0) {
        // 0x80063260: nop
    
            goto L_80063268;
    }
    // 0x80063260: nop

    // 0x80063264: break       7
    do_break(2147889764);
L_80063268:
    // 0x80063268: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006326C: bne         $t2, $at, L_80063280
    if (ctx->r10 != ctx->r1) {
        // 0x80063270: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80063280;
    }
    // 0x80063270: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063274: bne         $t6, $at, L_80063280
    if (ctx->r14 != ctx->r1) {
        // 0x80063278: nop
    
            goto L_80063280;
    }
    // 0x80063278: nop

    // 0x8006327C: break       6
    do_break(2147889788);
L_80063280:
    // 0x80063280: andi        $t6, $s2, 0xFFF
    ctx->r14 = ctx->r18 & 0XFFF;
    // 0x80063284: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80063288: or          $t9, $t7, $fp
    ctx->r25 = ctx->r15 | ctx->r30;
    // 0x8006328C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80063290: sw          $t7, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r15;
    // 0x80063294: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x80063298: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8006329C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800632A0: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    // 0x800632A4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800632A8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800632AC: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800632B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800632B4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800632B8: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x800632BC: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
    // 0x800632C0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800632C4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800632C8: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x800632CC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800632D0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800632D4: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800632D8: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
    // 0x800632DC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800632E0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800632E4: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800632E8: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800632EC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800632F0: blezl       $t8, L_800633C4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800632F4: lw          $t8, 0xBC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XBC);
            goto L_800633C4;
    }
    goto skip_0;
    // 0x800632F4: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    skip_0:
    // 0x800632F8: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
L_800632FC:
    // 0x800632FC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80063300: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x80063304: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80063308: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
    // 0x8006330C: addiu       $t7, $v0, 0x2
    ctx->r15 = ADD32(ctx->r2, 0X2);
    // 0x80063310: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x80063314: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80063318: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x8006331C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80063320: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x80063324: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80063328: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8006332C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80063330: slti        $at, $a0, 0x1E
    ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
    // 0x80063334: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80063338: bne         $at, $zero, L_800633AC
    if (ctx->r1 != 0) {
        // 0x8006333C: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_800633AC;
    }
    // 0x8006333C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80063340: slt         $at, $a3, $s1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80063344: beq         $at, $zero, L_8006336C
    if (ctx->r1 == 0) {
        // 0x80063348: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8006336C;
    }
    // 0x80063348: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006334C: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x80063350: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80063354: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80063358: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8006335C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
    // 0x80063360: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80063364: b           L_800633A4
    // 0x80063368: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_800633A4;
    // 0x80063368: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8006336C:
    // 0x8006336C: blez        $t4, L_800633A4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80063370: lw          $v0, 0xD4($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XD4);
            goto L_800633A4;
    }
    // 0x80063370: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
    // 0x80063374: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80063378: sll         $t9, $t4, 4
    ctx->r25 = S32(ctx->r12 << 4);
    // 0x8006337C: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80063380: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
    // 0x80063384: sll         $t8, $t4, 10
    ctx->r24 = S32(ctx->r12 << 10);
    // 0x80063388: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8006338C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80063390: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80063394: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80063398: or          $t8, $t9, $ra
    ctx->r24 = ctx->r25 | ctx->r31;
    // 0x8006339C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800633A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800633A4:
    // 0x800633A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800633A8: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
L_800633AC:
    // 0x800633AC: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800633B0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800633B4: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800633B8: bnel        $at, $zero, L_800632FC
    if (ctx->r1 != 0) {
        // 0x800633BC: lw          $v1, 0xD4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XD4);
            goto L_800632FC;
    }
    goto skip_1;
    // 0x800633BC: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    skip_1:
    // 0x800633C0: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
L_800633C4:
    // 0x800633C4: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800633C8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800633CC: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800633D0: bne         $s4, $t7, L_80063184
    if (ctx->r20 != ctx->r15) {
        // 0x800633D4: sw          $t6, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r14;
            goto L_80063184;
    }
    // 0x800633D4: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
L_800633D8:
    // 0x800633D8: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x800633DC: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x800633E0: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800633E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800633E8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800633EC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800633F0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800633F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800633F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800633FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80063400: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80063404: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80063408: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006340C: jr          $ra
    // 0x80063410: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x80063410: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_800358B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800358B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800358BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800358C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800358C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800358C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800358CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800358D0: jal         0x8003588C
    // 0x800358D4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8003588C(rdram, ctx);
        goto after_0;
    // 0x800358D4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800358D8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800358DC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800358E0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800358E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800358E8: lbu         $t7, -0x1570($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1570);
    // 0x800358EC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800358F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800358F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800358F8: jr          $ra
    // 0x800358FC: nop

    return;
    // 0x800358FC: nop

;}
RECOMP_FUNC void func_8073EB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EB6C: jr          $ra
    // 0x8073EB70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8073EB70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807412E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807412E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807412E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807412EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807412F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807412F4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x807412F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807412FC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80741300: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x80741304: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80741308: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8074130C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80741310: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x80741314: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80741318: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x8074131C: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80741320: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80741324: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80741328: jal         0x80048378
    // 0x8074132C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x8074132C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x80741330: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80741334: addiu       $at, $zero, 0x4639
    ctx->r1 = ADD32(0, 0X4639);
    // 0x80741338: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(751, 0X10BC) << 16);
    // 0x8074133C: beq         $v0, $at, L_8074137C
    if (ctx->r2 == ctx->r1) {
        // 0x80741340: addiu       $t8, $t8, 0x1F1C
        ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(751, 0X10BC));
            goto L_8074137C;
    }
    // 0x80741340: addiu       $t8, $t8, 0x1F1C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(751, 0X10BC));
    // 0x80741344: addiu       $at, $zero, 0x463A
    ctx->r1 = ADD32(0, 0X463A);
    // 0x80741348: beq         $v0, $at, L_807413A8
    if (ctx->r2 == ctx->r1) {
        // 0x8074134C: lui         $t1, 0x8074
        ctx->r9 = S32(RELOC_HI16(751, 0X10BC) << 16);
            goto L_807413A8;
    }
    // 0x8074134C: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(751, 0X10BC) << 16);
    // 0x80741350: addiu       $at, $zero, 0x463D
    ctx->r1 = ADD32(0, 0X463D);
    // 0x80741354: beq         $v0, $at, L_807413C8
    if (ctx->r2 == ctx->r1) {
        // 0x80741358: lui         $t5, 0x8074
        ctx->r13 = S32(RELOC_HI16(751, 0X10BC) << 16);
            goto L_807413C8;
    }
    // 0x80741358: lui         $t5, 0x8074
    ctx->r13 = S32(RELOC_HI16(751, 0X10BC) << 16);
    // 0x8074135C: addiu       $at, $zero, 0x463F
    ctx->r1 = ADD32(0, 0X463F);
    // 0x80741360: beq         $v0, $at, L_807413F4
    if (ctx->r2 == ctx->r1) {
        // 0x80741364: lui         $t9, 0x8074
        ctx->r25 = S32(RELOC_HI16(751, 0X10BC) << 16);
            goto L_807413F4;
    }
    // 0x80741364: lui         $t9, 0x8074
    ctx->r25 = S32(RELOC_HI16(751, 0X10BC) << 16);
    // 0x80741368: addiu       $at, $zero, 0x4672
    ctx->r1 = ADD32(0, 0X4672);
    // 0x8074136C: beq         $v0, $at, L_8074141C
    if (ctx->r2 == ctx->r1) {
        // 0x80741370: lui         $t3, 0x8074
        ctx->r11 = S32(RELOC_HI16(751, 0X10BC) << 16);
            goto L_8074141C;
    }
    // 0x80741370: lui         $t3, 0x8074
    ctx->r11 = S32(RELOC_HI16(751, 0X10BC) << 16);
    // 0x80741374: b           L_80741444
    // 0x80741378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80741444;
    // 0x80741378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8074137C:
    // 0x8074137C: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x80741380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80741384: jal         0x80740F2C
    // 0x80741388: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    func_80740F2C(rdram, ctx);
        goto after_1;
    // 0x80741388: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    after_1:
    // 0x8074138C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80741390: jal         0x80740F4C
    // 0x80741394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80740F4C(rdram, ctx);
        goto after_2;
    // 0x80741394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80741398: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8074139C: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    // 0x807413A0: b           L_80741440
    // 0x807413A4: sb          $t0, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r8;
        goto L_80741440;
    // 0x807413A4: sb          $t0, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r8;
L_807413A8:
    // 0x807413A8: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x807413AC: addiu       $t1, $t1, 0x1F1C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(751, 0X10BC));
    // 0x807413B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807413B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x807413B8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x807413BC: sb          $t3, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r11;
    // 0x807413C0: b           L_80741440
    // 0x807413C4: sb          $t4, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r12;
        goto L_80741440;
    // 0x807413C4: sb          $t4, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r12;
L_807413C8:
    // 0x807413C8: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x807413CC: addiu       $t5, $t5, 0x1F1C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(751, 0X10BC));
    // 0x807413D0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x807413D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807413D8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x807413DC: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
    // 0x807413E0: sb          $t8, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r24;
    // 0x807413E4: jal         0x8074118C
    // 0x807413E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8074118C(rdram, ctx);
        goto after_3;
    // 0x807413E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807413EC: b           L_80741444
    // 0x807413F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80741444;
    // 0x807413F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_807413F4:
    // 0x807413F4: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x807413F8: addiu       $t9, $t9, 0x1F1C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(751, 0X10BC));
    // 0x807413FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80741400: jal         0x80741148
    // 0x80741404: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    func_80741148(rdram, ctx);
        goto after_4;
    // 0x80741404: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    after_4:
    // 0x80741408: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8074140C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80741410: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x80741414: b           L_80741440
    // 0x80741418: sb          $t2, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r10;
        goto L_80741440;
    // 0x80741418: sb          $t2, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r10;
L_8074141C:
    // 0x8074141C: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x80741420: addiu       $t3, $t3, 0x1F1C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(751, 0X10BC));
    // 0x80741424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80741428: jal         0x80741288
    // 0x8074142C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    func_80741288(rdram, ctx);
        goto after_5;
    // 0x8074142C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    after_5:
    // 0x80741430: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80741434: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80741438: sb          $t5, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r13;
    // 0x8074143C: sb          $t6, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r14;
L_80741440:
    // 0x80741440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80741444:
    // 0x80741444: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x80741448: jal         0x80741E44
    // 0x8074144C: lbu         $a2, 0x26($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X26);
    func_80741E44(rdram, ctx);
        goto after_6;
    // 0x8074144C: lbu         $a2, 0x26($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X26);
    after_6:
    // 0x80741450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80741454: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80741458: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8074145C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80741460: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x80741464: jr          $ra
    // 0x80741468: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80741468: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80446038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446038: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044603C: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80446040: jr          $ra
    // 0x80446044: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x80446044: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8064BE3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BE3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BE40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BE44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064BE48: jal         0x80045A34
    // 0x8064BE4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8064BE4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8064BE50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064BE54: bne         $v0, $zero, L_8064BE64
    if (ctx->r2 != 0) {
        // 0x8064BE58: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8064BE64;
    }
    // 0x8064BE58: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8064BE5C: b           L_8064BE70
    // 0x8064BE60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8064BE70;
    // 0x8064BE60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064BE64:
    // 0x8064BE64: jal         0x8064BE24
    // 0x8064BE68: nop

    func_8064BE24(rdram, ctx);
        goto after_1;
    // 0x8064BE68: nop

    after_1:
    // 0x8064BE6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064BE70:
    // 0x8064BE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064BE74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BE78: jr          $ra
    // 0x8064BE7C: nop

    return;
    // 0x8064BE7C: nop

;}
RECOMP_FUNC void func_804444D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804444D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804444D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804444DC: jal         0x804444B0
    // 0x804444E0: nop

    func_804444B0(rdram, ctx);
        goto after_0;
    // 0x804444E0: nop

    after_0:
    // 0x804444E4: jal         0x804444C4
    // 0x804444E8: nop

    func_804444C4(rdram, ctx);
        goto after_1;
    // 0x804444E8: nop

    after_1:
    // 0x804444EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804444F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804444F4: jr          $ra
    // 0x804444F8: nop

    return;
    // 0x804444F8: nop

    // 0x804444FC: jr          $ra
    // 0x80444500: nop

    return;
    // 0x80444500: nop

;}
RECOMP_FUNC void func_80715A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715A1C: jal         0x80715864
    // 0x80715A20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80715864(rdram, ctx);
        goto after_0;
    // 0x80715A20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80715A24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80715A28: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(730, 0X1710) << 16);
    // 0x80715A2C: addiu       $t6, $t6, 0x5F30
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(730, 0X1710));
    // 0x80715A30: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80715A34: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80715A38: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80715A3C: sw          $t6, 0x5F8($v0)
    MEM_W(0X5F8, ctx->r2) = ctx->r14;
    // 0x80715A40: sh          $t7, 0x5FC($v0)
    MEM_H(0X5FC, ctx->r2) = ctx->r15;
    // 0x80715A44: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80715A48: addiu       $at, $zero, 0x4679
    ctx->r1 = ADD32(0, 0X4679);
    // 0x80715A4C: beq         $v1, $at, L_80715A64
    if (ctx->r3 == ctx->r1) {
        // 0x80715A50: addiu       $at, $zero, 0x467A
        ctx->r1 = ADD32(0, 0X467A);
            goto L_80715A64;
    }
    // 0x80715A50: addiu       $at, $zero, 0x467A
    ctx->r1 = ADD32(0, 0X467A);
    // 0x80715A54: beq         $v1, $at, L_80715A6C
    if (ctx->r3 == ctx->r1) {
        // 0x80715A58: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80715A6C;
    }
    // 0x80715A58: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80715A5C: b           L_80715A74
    // 0x80715A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80715A74;
    // 0x80715A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715A64:
    // 0x80715A64: b           L_80715A70
    // 0x80715A68: sw          $zero, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = 0;
        goto L_80715A70;
    // 0x80715A68: sw          $zero, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = 0;
L_80715A6C:
    // 0x80715A6C: sw          $t8, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->r24;
L_80715A70:
    // 0x80715A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715A74:
    // 0x80715A74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715A78: jr          $ra
    // 0x80715A7C: nop

    return;
    // 0x80715A7C: nop

;}
RECOMP_FUNC void func_805A23DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A23DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A23E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A23E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805A23E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805A23EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805A23F0: jal         0x8004700C
    // 0x805A23F4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A23F4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805A23F8: beq         $v0, $zero, L_805A253C
    if (ctx->r2 == 0) {
        // 0x805A23FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_805A253C;
    }
    // 0x805A23FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805A2400: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x805A2404: beq         $v0, $zero, L_805A2410
    if (ctx->r2 == 0) {
        // 0x805A2408: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805A2410;
    }
    // 0x805A2408: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805A240C: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
L_805A2410:
    // 0x805A2410: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x805A2414: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(411, 0X1C5C) << 16);
    // 0x805A2418: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805A241C: lbu         $t8, 0x2FCC($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(411, 0X1C5C));
    // 0x805A2420: sh          $t8, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r24;
    // 0x805A2424: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x805A2428: bnel        $t9, $zero, L_805A24A8
    if (ctx->r25 != 0) {
        // 0x805A242C: lwc1        $f16, 0x84($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X84);
            goto L_805A24A8;
    }
    goto skip_0;
    // 0x805A242C: lwc1        $f16, 0x84($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X84);
    skip_0:
    // 0x805A2430: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x805A2434: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(411, 0X1C50) << 16);
    // 0x805A2438: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x805A243C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805A2440: lw          $t1, 0x2FC0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(411, 0X1C50));
    // 0x805A2444: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x805A2448: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x805A244C: sw          $t2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r10;
    // 0x805A2450: bne         $at, $zero, L_805A24A4
    if (ctx->r1 != 0) {
        // 0x805A2454: sw          $t1, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r9;
            goto L_805A24A4;
    }
    // 0x805A2454: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
    // 0x805A2458: jal         0x80065414
    // 0x805A245C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80065414(rdram, ctx);
        goto after_1;
    // 0x805A245C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x805A2460: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x805A2464: cvt.s.d     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f4.fl = CVT_S_D(ctx->f0.d);
    // 0x805A2468: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x805A246C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x805A2470: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A2474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2478: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805A247C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805A2480: mul.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x805A2484: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x805A2488: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x805A248C: nop

    // 0x805A2490: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x805A2494: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x805A2498: jal         0x805A2B28
    // 0x805A249C: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_2;
    // 0x805A249C: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_2:
    // 0x805A24A0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_805A24A4:
    // 0x805A24A4: lwc1        $f16, 0x84($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X84);
L_805A24A8:
    // 0x805A24A8: lwc1        $f18, 0x84($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X84);
    // 0x805A24AC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(411, 0X1D58) << 16);
    // 0x805A24B0: lwc1        $f6, 0x30C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(411, 0X1D58));
    // 0x805A24B4: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805A24B8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A24BC: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x805A24C0: nop

    // 0x805A24C4: bc1f        L_805A2534
    if (!c1cs) {
        // 0x805A24C8: nop
    
            goto L_805A2534;
    }
    // 0x805A24C8: nop

    // 0x805A24CC: lwc1        $f4, 0x88($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X88);
    // 0x805A24D0: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
    // 0x805A24D4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x805A24D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A24DC: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x805A24E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A24E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A24E8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805A24EC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A24F0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x805A24F4: nop

    // 0x805A24F8: bc1f        L_805A2534
    if (!c1cs) {
        // 0x805A24FC: nop
    
            goto L_805A2534;
    }
    // 0x805A24FC: nop

    // 0x805A2500: lw          $t7, 0x138($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X138);
    // 0x805A2504: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A2508: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x805A250C: sw          $zero, 0x138($s1)
    MEM_W(0X138, ctx->r17) = 0;
    // 0x805A2510: lwc1        $f16, 0x84($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X84);
    // 0x805A2514: lwc1        $f18, 0x3C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x805A2518: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x805A251C: nop

    // 0x805A2520: bc1f        L_805A252C
    if (!c1cs) {
        // 0x805A2524: nop
    
            goto L_805A252C;
    }
    // 0x805A2524: nop

    // 0x805A2528: sw          $t8, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->r24;
L_805A252C:
    // 0x805A252C: jal         0x805A2B28
    // 0x805A2530: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_3;
    // 0x805A2530: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_3:
L_805A2534:
    // 0x805A2534: jal         0x805A1BA8
    // 0x805A2538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805A1BA8(rdram, ctx);
        goto after_4;
    // 0x805A2538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_805A253C:
    // 0x805A253C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A2540: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805A2544: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805A2548: jr          $ra
    // 0x805A254C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805A254C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80437314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80437318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043731C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80437320: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80437324: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80437328: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8043732C: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80437330: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80437334: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x80437338: nop

    // 0x8043733C: bc1f        L_8043734C
    if (!c1cs) {
        // 0x80437340: nop
    
            goto L_8043734C;
    }
    // 0x80437340: nop

    // 0x80437344: b           L_804373CC
    // 0x80437348: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_804373CC;
    // 0x80437348: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8043734C:
    // 0x8043734C: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80437350: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80437354: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80437358: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8043735C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80437360: nop

    // 0x80437364: bc1fl       L_80437378
    if (!c1cs) {
        // 0x80437368: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80437378;
    }
    goto skip_0;
    // 0x80437368: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_0:
    // 0x8043736C: b           L_804373CC
    // 0x80437370: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_804373CC;
    // 0x80437370: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80437374: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80437378:
    // 0x80437378: nop

    // 0x8043737C: bc1fl       L_804373A4
    if (!c1cs) {
        // 0x80437380: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_804373A4;
    }
    goto skip_1;
    // 0x80437380: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_1:
    // 0x80437384: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x80437388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043738C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80437390: jal         0x804371BC
    // 0x80437394: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_804371BC(rdram, ctx);
        goto after_0;
    // 0x80437394: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80437398: b           L_804373CC
    // 0x8043739C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
        goto L_804373CC;
    // 0x8043739C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804373A0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_804373A4:
    // 0x804373A4: nop

    // 0x804373A8: bc1fl       L_804373D0
    if (!c1cs) {
        // 0x804373AC: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_804373D0;
    }
    goto skip_2;
    // 0x804373AC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x804373B0: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x804373B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804373B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x804373BC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x804373C0: jal         0x80437268
    // 0x804373C4: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80437268(rdram, ctx);
        goto after_1;
    // 0x804373C4: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x804373C8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
L_804373CC:
    // 0x804373CC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_804373D0:
    // 0x804373D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x804373D4: lwc1        $f10, 0x3C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x804373D8: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x804373DC: swc1        $f16, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f16.u32l;
    // 0x804373E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804373E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804373E8: jr          $ra
    // 0x804373EC: nop

    return;
    // 0x804373EC: nop

;}
RECOMP_FUNC void func_806A2B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A2B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A2B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A2B58: jal         0x800653D8
    // 0x806A2B5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x806A2B5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806A2B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806A2B64: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806A2B68: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(583, 0X520) << 16);
    // 0x806A2B6C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806A2B70: addiu       $t7, $t7, 0x2D80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(583, 0X520));
    // 0x806A2B74: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806A2B78: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806A2B7C: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A2B80: lui         $t0, 0x806A
    ctx->r8 = S32(RELOC_HI16(583, 0X1DC) << 16);
    // 0x806A2B84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806A2B88: addiu       $t0, $t0, 0x2A3C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(583, 0X1DC));
    // 0x806A2B8C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806A2B90: sb          $t9, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r25;
    // 0x806A2B94: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806A2B98: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x806A2B9C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x806A2BA0: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x806A2BA4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x806A2BA8: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x806A2BAC: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x806A2BB0: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(583, 0X528) << 16);
    // 0x806A2BB4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x806A2BB8: lwc1        $f0, 0x2D88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(583, 0X528));
    // 0x806A2BBC: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(583, 0X548) << 16);
    // 0x806A2BC0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x806A2BC4: swc1        $f0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f0.u32l;
    // 0x806A2BC8: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
    // 0x806A2BCC: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x806A2BD0: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x806A2BD4: lwc1        $f4, 0x2DA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(583, 0X548));
    // 0x806A2BD8: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(583, 0X590) << 16);
    // 0x806A2BDC: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x806A2BE0: lwc1        $f6, 0x2DF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(583, 0X590));
    // 0x806A2BE4: jal         0x800653D8
    // 0x806A2BE8: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x806A2BE8: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x806A2BEC: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x806A2BF0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x806A2BF4: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(583, 0X558) << 16);
    // 0x806A2BF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806A2BFC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806A2C00: lw          $t7, 0x2DB8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(583, 0X558));
    // 0x806A2C04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806A2C08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806A2C0C: lui         $t9, 0x806A
    ctx->r25 = S32(RELOC_HI16(583, 0X70) << 16);
    // 0x806A2C10: addiu       $t9, $t9, 0x28D0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(583, 0X70));
    // 0x806A2C14: addiu       $t8, $t7, 0x80
    ctx->r24 = ADD32(ctx->r15, 0X80);
    // 0x806A2C18: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x806A2C1C: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806A2C20: swc1        $f0, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f0.u32l;
    // 0x806A2C24: swc1        $f0, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->f0.u32l;
    // 0x806A2C28: swc1        $f0, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f0.u32l;
    // 0x806A2C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A2C30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806A2C34: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806A2C38: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806A2C3C: jr          $ra
    // 0x806A2C40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806A2C40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80037074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003707C: jal         0x80036F00
    // 0x80037080: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    func_80036F00(rdram, ctx);
        goto after_0;
    // 0x80037080: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80037084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003708C: jr          $ra
    // 0x80037090: nop

    return;
    // 0x80037090: nop

;}
RECOMP_FUNC void func_8005EC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005EC34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005EC38: jal         0x8005EBE8
    // 0x8005EC3C: nop

    func_8005EBE8(rdram, ctx);
        goto after_0;
    // 0x8005EC3C: nop

    after_0:
    // 0x8005EC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005EC44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005EC48: jr          $ra
    // 0x8005EC4C: nop

    return;
    // 0x8005EC4C: nop

;}
RECOMP_FUNC void func_80584ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584ABC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584AC0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584AC4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584AC8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584ACC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584AD0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584AD4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584AD8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584ADC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584AE0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584AE4: jr          $ra
    // 0x80584AE8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584AE8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80674534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80674538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067453C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80674540: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80674544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80674548: jal         0x806741B8
    // 0x8067454C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_806741B8(rdram, ctx);
        goto after_0;
    // 0x8067454C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80674550: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80674554: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80674558: jal         0x80065ABC
    // 0x8067455C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8067455C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x80674560: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80674564: jal         0x8067424C
    // 0x80674568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067424C(rdram, ctx);
        goto after_2;
    // 0x80674568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8067456C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80674570: jal         0x80049D74
    // 0x80674574: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_3;
    // 0x80674574: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_3:
    // 0x80674578: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8067457C: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80674580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80674584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80674588: jal         0x8004D150
    // 0x8067458C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_4;
    // 0x8067458C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80674590: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x80674594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80674598: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8067459C: lw          $v0, 0x40($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X40);
    // 0x806745A0: lbu         $t9, 0x14($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X14);
    // 0x806745A4: beql        $t9, $zero, L_80674664
    if (ctx->r25 == 0) {
        // 0x806745A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80674664;
    }
    goto skip_0;
    // 0x806745A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806745AC: jal         0x8004A97C
    // 0x806745B0: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x806745B0: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    after_5:
    // 0x806745B4: jal         0x800659EC
    // 0x806745B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800659EC(rdram, ctx);
        goto after_6;
    // 0x806745B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x806745BC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C54) << 16);
    // 0x806745C0: lwc1        $f4, 0x4C34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C54));
    // 0x806745C4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x806745C8: jal         0x80065414
    // 0x806745CC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_80065414(rdram, ctx);
        goto after_7;
    // 0x806745CC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x806745D0: cvt.s.d     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f8.fl = CVT_S_D(ctx->f0.d);
    // 0x806745D4: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C58) << 16);
    // 0x806745D8: lwc1        $f10, 0x4C38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C58));
    // 0x806745DC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C5C) << 16);
    // 0x806745E0: lwc1        $f18, 0x4C3C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C5C));
    // 0x806745E4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806745E8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806745EC: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806745F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806745F4: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C60) << 16);
    // 0x806745F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806745FC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80674600: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80674604: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80674608: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8067460C: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x80674610: lwc1        $f4, 0x4C40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C60));
    // 0x80674614: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80674618: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x8067461C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80674620: jal         0x80065414
    // 0x80674624: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    func_80065414(rdram, ctx);
        goto after_8;
    // 0x80674624: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    after_8:
    // 0x80674628: cvt.s.d     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
    // 0x8067462C: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80674630: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80674634: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80674638: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067463C: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80674640: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80674644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80674648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067464C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80674650: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80674654: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80674658: jal         0x806748E4
    // 0x8067465C: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    func_806748E4(rdram, ctx);
        goto after_9;
    // 0x8067465C: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    after_9:
    // 0x80674660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80674664:
    // 0x80674664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80674668: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8067466C: jr          $ra
    // 0x80674670: nop

    return;
    // 0x80674670: nop

;}
RECOMP_FUNC void func_80445BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445BDC: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80445BE0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445BE4: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x80445BE8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445BEC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80445BF0: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x80445BF4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445BF8: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80445BFC: jr          $ra
    // 0x80445C00: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    return;
    // 0x80445C00: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_805AA510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AA51C: jal         0x80045A34
    // 0x805AA520: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805AA520: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x805AA524: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x805AA528: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x805AA52C: bne         $v0, $zero, L_805AA53C
    if (ctx->r2 != 0) {
        // 0x805AA530: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_805AA53C;
    }
    // 0x805AA530: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x805AA534: b           L_805AA54C
    // 0x805AA538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805AA54C;
    // 0x805AA538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805AA53C:
    // 0x805AA53C: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x805AA540: jal         0x80065728
    // 0x805AA544: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x805AA544: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x805AA548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805AA54C:
    // 0x805AA54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AA550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA554: jr          $ra
    // 0x805AA558: nop

    return;
    // 0x805AA558: nop

;}
RECOMP_FUNC void func_807A7138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A7138: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807A713C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807A7140: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807A7144: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807A7148: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807A714C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807A7150: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807A7154: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x807A7158: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807A715C: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(847, 0X1510) << 16);
    // 0x807A7160: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807A7164: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807A7168: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807A716C: lw          $t1, 0x7210($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(847, 0X1510));
    // 0x807A7170: jr          $ra
    // 0x807A7174: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807A7174: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x807A7178: nop

    // 0x807A717C: nop

;}
RECOMP_FUNC void func_806E75D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E75D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806E75DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806E75E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806E75E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806E75E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E75EC: jal         0x806E7B70
    // 0x806E75F0: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    func_806E7B70(rdram, ctx);
        goto after_0;
    // 0x806E75F0: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    after_0:
    // 0x806E75F4: bne         $v0, $zero, L_806E7664
    if (ctx->r2 != 0) {
        // 0x806E75F8: nop
    
            goto L_806E7664;
    }
    // 0x806E75F8: nop

    // 0x806E75FC: jal         0x806E72B8
    // 0x806E7600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E72B8(rdram, ctx);
        goto after_1;
    // 0x806E7600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806E7604: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x806E7608: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E760C: nop

    // 0x806E7610: mul.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x806E7614: jal         0x80066E88
    // 0x806E7618: nop

    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x806E7618: nop

    after_2:
    // 0x806E761C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x806E7620: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E7624: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806E7628: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E762C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E7630: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806E7634: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806E7638: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x806E763C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x806E7640: nop

    // 0x806E7644: bc1f        L_806E7654
    if (!c1cs) {
        // 0x806E7648: nop
    
            goto L_806E7654;
    }
    // 0x806E7648: nop

    // 0x806E764C: b           L_806E766C
    // 0x806E7650: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
        goto L_806E766C;
    // 0x806E7650: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
L_806E7654:
    // 0x806E7654: jal         0x806E7E4C
    // 0x806E7658: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    func_806E7E4C(rdram, ctx);
        goto after_3;
    // 0x806E7658: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    after_3:
    // 0x806E765C: b           L_806E7670
    // 0x806E7660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806E7670;
    // 0x806E7660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E7664:
    // 0x806E7664: jal         0x806E7328
    // 0x806E7668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E7328(rdram, ctx);
        goto after_4;
    // 0x806E7668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_806E766C:
    // 0x806E766C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E7670:
    // 0x806E7670: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806E7674: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806E7678: jr          $ra
    // 0x806E767C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806E767C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000BC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC34: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x8000BC38: beq         $at, $zero, L_8000BC44
    if (ctx->r1 == 0) {
        // 0x8000BC3C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000BC44;
    }
    // 0x8000BC3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000BC40: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
L_8000BC44:
    // 0x8000BC44: lbu         $t6, 0x20($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X20);
    // 0x8000BC48: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8000BC4C: beq         $t6, $zero, L_8000BC84
    if (ctx->r14 == 0) {
        // 0x8000BC50: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8000BC84;
    }
    // 0x8000BC50: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8000BC54: lwc1        $f12, 0x28($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8000BC58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000BC5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BC60: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8000BC64: nop

    // 0x8000BC68: bc1f        L_8000BC84
    if (!c1cs) {
        // 0x8000BC6C: nop
    
            goto L_8000BC84;
    }
    // 0x8000BC6C: nop

    // 0x8000BC70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000BC74: nop

    // 0x8000BC78: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8000BC7C: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8000BC80: nop

L_8000BC84:
    // 0x8000BC84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BC88: lwc1        $f10, -0x42DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X42DC);
    // 0x8000BC8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BC90: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8000BC94: nop

    // 0x8000BC98: bc1f        L_8000BCAC
    if (!c1cs) {
        // 0x8000BC9C: nop
    
            goto L_8000BCAC;
    }
    // 0x8000BC9C: nop

    // 0x8000BCA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BCA4: b           L_8000BD04
    // 0x8000BCA8: lwc1        $f2, -0x42D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42D8);
        goto L_8000BD04;
    // 0x8000BCA8: lwc1        $f2, -0x42D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42D8);
L_8000BCAC:
    // 0x8000BCAC: lwc1        $f16, -0x42D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X42D4);
    // 0x8000BCB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000BCB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BCB8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8000BCBC: nop

    // 0x8000BCC0: bc1f        L_8000BCD4
    if (!c1cs) {
        // 0x8000BCC4: nop
    
            goto L_8000BCD4;
    }
    // 0x8000BCC4: nop

    // 0x8000BCC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BCCC: b           L_8000BD04
    // 0x8000BCD0: lwc1        $f2, -0x42D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42D0);
        goto L_8000BD04;
    // 0x8000BCD0: lwc1        $f2, -0x42D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42D0);
L_8000BCD4:
    // 0x8000BCD4: lwc1        $f18, -0x42CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X42CC);
    // 0x8000BCD8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8000BCDC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BCE0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8000BCE4: nop

    // 0x8000BCE8: bc1f        L_8000BD00
    if (!c1cs) {
        // 0x8000BCEC: nop
    
            goto L_8000BD00;
    }
    // 0x8000BCEC: nop

    // 0x8000BCF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BCF4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8000BCF8: b           L_8000BD04
    // 0x8000BCFC: lwc1        $f2, -0x42C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42C8);
        goto L_8000BD04;
    // 0x8000BCFC: lwc1        $f2, -0x42C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42C8);
L_8000BD00:
    // 0x8000BD00: lwc1        $f2, -0x42C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42C4);
L_8000BD04:
    // 0x8000BD04: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8000BD08: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8000BD0C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8000BD10: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000BD14: sll         $t9, $v1, 7
    ctx->r25 = S32(ctx->r3 << 7);
    // 0x8000BD18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000BD1C: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x8000BD20: sb          $a2, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r6;
    // 0x8000BD24: sb          $v1, 0x32($a0)
    MEM_B(0X32, ctx->r4) = ctx->r3;
    // 0x8000BD28: lw          $t8, 0x5FB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5FB0);
    // 0x8000BD2C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8000BD30: jr          $ra
    // 0x8000BD34: sw          $t0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r8;
    return;
    // 0x8000BD34: sw          $t0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_80446170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446170: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446174: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80446178: jr          $ra
    // 0x8044617C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    return;
    // 0x8044617C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80533D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533D14: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80533D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80533D1C: addiu       $v1, $a0, 0x188
    ctx->r3 = ADD32(ctx->r4, 0X188);
    // 0x80533D20: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x80533D24: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80533D28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80533D2C:
    // 0x80533D2C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_80533D30:
    // 0x80533D30: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80533D34: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80533D38: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80533D3C: beql        $a0, $zero, L_80533D54
    if (ctx->r4 == 0) {
        // 0x80533D40: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80533D54;
    }
    goto skip_0;
    // 0x80533D40: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_0:
    // 0x80533D44: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80533D48: beql        $t8, $a0, L_80533D60
    if (ctx->r24 == ctx->r4) {
        // 0x80533D4C: slti        $at, $a2, 0x50
        ctx->r1 = SIGNED(ctx->r6) < 0X50 ? 1 : 0;
            goto L_80533D60;
    }
    goto skip_1;
    // 0x80533D4C: slti        $at, $a2, 0x50
    ctx->r1 = SIGNED(ctx->r6) < 0X50 ? 1 : 0;
    skip_1:
    // 0x80533D50: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80533D54:
    // 0x80533D54: bne         $a2, $t1, L_80533D30
    if (ctx->r6 != ctx->r9) {
        // 0x80533D58: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80533D30;
    }
    // 0x80533D58: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80533D5C: slti        $at, $a2, 0x50
    ctx->r1 = SIGNED(ctx->r6) < 0X50 ? 1 : 0;
L_80533D60:
    // 0x80533D60: bne         $at, $zero, L_80533D70
    if (ctx->r1 != 0) {
        // 0x80533D64: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_80533D70;
    }
    // 0x80533D64: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80533D68: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80533D6C: sw          $zero, 0x10($t2)
    MEM_W(0X10, ctx->r10) = 0;
L_80533D70:
    // 0x80533D70: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80533D74: bnel        $a1, $t0, L_80533D2C
    if (ctx->r5 != ctx->r8) {
        // 0x80533D78: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80533D2C;
    }
    goto skip_2;
    // 0x80533D78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    skip_2:
    // 0x80533D7C: jr          $ra
    // 0x80533D80: nop

    return;
    // 0x80533D80: nop

;}
RECOMP_FUNC void func_8040D8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D8B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040D8B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040D8BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8040D8C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8040D8C4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D8C8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8040D8CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040D8D0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8040D8D4: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8040D8D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040D8DC: mul.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8040D8E0: jal         0x80066E88
    // 0x8040D8E4: nop

    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8040D8E4: nop

    after_0:
    // 0x8040D8E8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8040D8EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040D8F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8040D8F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D8F8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8040D8FC: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x8040D900: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8040D904: nop

    // 0x8040D908: bc1fl       L_8040D930
    if (!c1cs) {
        // 0x8040D90C: swc1        $f20, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
            goto L_8040D930;
    }
    goto skip_0;
    // 0x8040D90C: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x8040D910: jal         0x8005FDC4
    // 0x8040D914: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x8040D914: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    after_1:
    // 0x8040D918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D91C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D920: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040D924: jal         0x8040E254
    // 0x8040D928: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040D928: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8040D92C: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
L_8040D930:
    // 0x8040D930: jal         0x80066E88
    // 0x8040D934: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8040D934: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8040D938: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8040D93C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040D940: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8040D944: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8040D948: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8040D94C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8040D950: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8040D954: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8040D958: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8040D95C: jal         0x80066DE4
    // 0x8040D960: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8040D960: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8040D964: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8040D968: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8040D96C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8040D970: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8040D974: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8040D978: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8040D97C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8040D980: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8040D984: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8040D988: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8040D98C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8040D990: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8040D994: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8040D998: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8040D99C: jr          $ra
    // 0x8040D9A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8040D9A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80435380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435380: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80435384: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80435388: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8043538C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80435390: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80435394: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80435398: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8043539C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804353A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804353A4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x804353A8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x804353AC: addiu       $s1, $zero, 0x3B
    ctx->r17 = ADD32(0, 0X3B);
    // 0x804353B0: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x804353B4: addiu       $s3, $zero, 0xF0
    ctx->r19 = ADD32(0, 0XF0);
    // 0x804353B8: addiu       $s0, $v0, 0xE8C
    ctx->r16 = ADD32(ctx->r2, 0XE8C);
L_804353BC:
    // 0x804353BC: jal         0x800653D8
    // 0x804353C0: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804353C0: nop

    after_0:
    // 0x804353C4: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x804353C8: mfhi        $t6
    ctx->r14 = hi;
    // 0x804353CC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804353D0: bne         $s2, $zero, L_804353DC
    if (ctx->r18 != 0) {
        // 0x804353D4: nop
    
            goto L_804353DC;
    }
    // 0x804353D4: nop

    // 0x804353D8: break       7
    do_break(2151896024);
L_804353DC:
    // 0x804353DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x804353E0: bne         $s2, $at, L_804353F4
    if (ctx->r18 != ctx->r1) {
        // 0x804353E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_804353F4;
    }
    // 0x804353E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804353E8: bne         $v0, $at, L_804353F4
    if (ctx->r2 != ctx->r1) {
        // 0x804353EC: nop
    
            goto L_804353F4;
    }
    // 0x804353EC: nop

    // 0x804353F0: break       6
    do_break(2151896048);
L_804353F4:
    // 0x804353F4: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804353F8: jal         0x800653D8
    // 0x804353FC: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x804353FC: nop

    after_1:
    // 0x80435400: div         $zero, $v0, $s3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19)));
    // 0x80435404: mfhi        $t7
    ctx->r15 = hi;
    // 0x80435408: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8043540C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80435410: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x80435414: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80435418: bne         $s3, $zero, L_80435424
    if (ctx->r19 != 0) {
        // 0x8043541C: nop
    
            goto L_80435424;
    }
    // 0x8043541C: nop

    // 0x80435420: break       7
    do_break(2151896096);
L_80435424:
    // 0x80435424: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80435428: bne         $s3, $at, L_8043543C
    if (ctx->r19 != ctx->r1) {
        // 0x8043542C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8043543C;
    }
    // 0x8043542C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80435430: bne         $v0, $at, L_8043543C
    if (ctx->r2 != ctx->r1) {
        // 0x80435434: nop
    
            goto L_8043543C;
    }
    // 0x80435434: nop

    // 0x80435438: break       6
    do_break(2151896120);
L_8043543C:
    // 0x8043543C: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x80435440: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80435444: bgez        $s1, L_804353BC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80435448: swc1        $f10, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
            goto L_804353BC;
    }
    // 0x80435448: swc1        $f10, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8043544C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80435450: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80435454: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80435458: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8043545C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80435460: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80435464: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80435468: jr          $ra
    // 0x8043546C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8043546C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805A6C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A6C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6C94: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805A6C98: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805A6C9C: lui         $t7, 0x805A
    ctx->r15 = S32(RELOC_HI16(420, 0X390) << 16);
    // 0x805A6CA0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805A6CA4: addiu       $t7, $t7, 0x6D70
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(420, 0X390));
    // 0x805A6CA8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805A6CAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805A6CB0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A6CB4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805A6CB8: sb          $v1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r3;
    // 0x805A6CBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A6CC0: sb          $v1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r3;
    // 0x805A6CC4: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805A6CC8: addiu       $at, $zero, 0x40B8
    ctx->r1 = ADD32(0, 0X40B8);
    // 0x805A6CCC: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(420, 0XD0) << 16);
    // 0x805A6CD0: beq         $v0, $at, L_805A6CEC
    if (ctx->r2 == ctx->r1) {
        // 0x805A6CD4: addiu       $t9, $t9, 0x6AB0
        ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(420, 0XD0));
            goto L_805A6CEC;
    }
    // 0x805A6CD4: addiu       $t9, $t9, 0x6AB0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(420, 0XD0));
    // 0x805A6CD8: addiu       $at, $zero, 0x466A
    ctx->r1 = ADD32(0, 0X466A);
    // 0x805A6CDC: beq         $v0, $at, L_805A6CFC
    if (ctx->r2 == ctx->r1) {
        // 0x805A6CE0: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_805A6CFC;
    }
    // 0x805A6CE0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x805A6CE4: b           L_805A6D18
    // 0x805A6CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A6D18;
    // 0x805A6CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A6CEC:
    // 0x805A6CEC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A6CF0: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x805A6CF4: b           L_805A6D14
    // 0x805A6CF8: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
        goto L_805A6D14;
    // 0x805A6CF8: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
L_805A6CFC:
    // 0x805A6CFC: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(420, 0X260) << 16);
    // 0x805A6D00: addiu       $t1, $t1, 0x6C40
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(420, 0X260));
    // 0x805A6D04: sb          $v1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r3;
    // 0x805A6D08: sb          $t0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r8;
    // 0x805A6D0C: jal         0x8005FE48
    // 0x805A6D10: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x805A6D10: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
L_805A6D14:
    // 0x805A6D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A6D18:
    // 0x805A6D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A6D1C: jr          $ra
    // 0x805A6D20: nop

    return;
    // 0x805A6D20: nop

;}
RECOMP_FUNC void func_805325B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805325B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805325B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805325B8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805325BC: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(342, 0X1838) << 16);
    // 0x805325C0: addiu       $t6, $t6, 0x2628
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(342, 0X1838));
    // 0x805325C4: jal         0x80532554
    // 0x805325C8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    func_80532554(rdram, ctx);
        goto after_0;
    // 0x805325C8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_0:
    // 0x805325CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805325D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805325D4: jr          $ra
    // 0x805325D8: nop

    return;
    // 0x805325D8: nop

;}
RECOMP_FUNC void func_8051EA10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EA10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051EA14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8051EA18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051EA1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8051EA20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8051EA24: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(300, 0X590) << 16);
    // 0x8051EA28: swc1        $f0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f0.u32l;
    // 0x8051EA2C: swc1        $f0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f0.u32l;
    // 0x8051EA30: lwc1        $f4, -0x1070($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X590));
    // 0x8051EA34: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8051EA38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8051EA3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8051EA40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8051EA44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8051EA48: lui         $a0, 0x45DE
    ctx->r4 = S32(0X45DE << 16);
    // 0x8051EA4C: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x8051EA50: swc1        $f4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f4.u32l;
    // 0x8051EA54: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8051EA58: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x8051EA5C: lui         $a1, 0xC2B4
    ctx->r5 = S32(0XC2B4 << 16);
    // 0x8051EA60: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8051EA64: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8051EA68: jal         0x8004613C
    // 0x8051EA6C: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x8051EA6C: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    after_0:
    // 0x8051EA70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8051EA74: jal         0x80047F9C
    // 0x8051EA78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x8051EA78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8051EA7C: lui         $a0, 0x45DF
    ctx->r4 = S32(0X45DF << 16);
    // 0x8051EA80: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x8051EA84: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8051EA88: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8051EA8C: lui         $a1, 0xC1F0
    ctx->r5 = S32(0XC1F0 << 16);
    // 0x8051EA90: jal         0x8004613C
    // 0x8051EA94: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x8051EA94: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    after_2:
    // 0x8051EA98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8051EA9C: jal         0x80047F9C
    // 0x8051EAA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8051EAA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8051EAA4: lui         $a0, 0x45E0
    ctx->r4 = S32(0X45E0 << 16);
    // 0x8051EAA8: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x8051EAAC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8051EAB0: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8051EAB4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8051EAB8: jal         0x8004613C
    // 0x8051EABC: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x8051EABC: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    after_4:
    // 0x8051EAC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8051EAC4: jal         0x80047F9C
    // 0x8051EAC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8051EAC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8051EACC: lui         $a0, 0x45E1
    ctx->r4 = S32(0X45E1 << 16);
    // 0x8051EAD0: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x8051EAD4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8051EAD8: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8051EADC: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x8051EAE0: jal         0x8004613C
    // 0x8051EAE4: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    func_8004613C(rdram, ctx);
        goto after_6;
    // 0x8051EAE4: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    after_6:
    // 0x8051EAE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8051EAEC: jal         0x80047F9C
    // 0x8051EAF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x8051EAF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8051EAF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8051EAF8: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x8051EAFC: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8051EB00: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8051EB04: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8051EB08: jal         0x8004613C
    // 0x8051EB0C: lw          $a3, 0x44($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X44);
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x8051EB0C: lw          $a3, 0x44($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X44);
    after_8:
    // 0x8051EB10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8051EB14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8051EB18: jal         0x80047F9C
    // 0x8051EB1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x8051EB1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8051EB20: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8051EB24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8051EB28: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x8051EB2C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8051EB30: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
    // 0x8051EB34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8051EB38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8051EB3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8051EB40: jr          $ra
    // 0x8051EB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8051EB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8007451C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007451C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80074528: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007452C: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80074530: lw          $t6, -0x7B30($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B30);
    // 0x80074534: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80074538: bnel        $at, $zero, L_8007454C
    if (ctx->r1 != 0) {
        // 0x8007453C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8007454C;
    }
    goto skip_0;
    // 0x8007453C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80074540: jal         0x80086880
    // 0x80074544: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_0;
    // 0x80074544: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80074548: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007454C:
    // 0x8007454C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80074550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80074554: jal         0x80082210
    // 0x80074558: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80074558: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x8007455C: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80074560: lw          $t7, -0x7B30($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B30);
    // 0x80074564: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80074568: bnel        $at, $zero, L_8007457C
    if (ctx->r1 != 0) {
        // 0x8007456C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007457C;
    }
    goto skip_1;
    // 0x8007456C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80074570: jal         0x80086880
    // 0x80074574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_2;
    // 0x80074574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80074578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007457C:
    // 0x8007457C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074580: jr          $ra
    // 0x80074584: nop

    return;
    // 0x80074584: nop

;}
RECOMP_FUNC void func_8003A8F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A8F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003A8F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003A8FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003A900: jal         0x8003A620
    // 0x8003A904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8003A620(rdram, ctx);
        goto after_0;
    // 0x8003A904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8003A908: jal         0x8003A4EC
    // 0x8003A90C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A4EC(rdram, ctx);
        goto after_1;
    // 0x8003A90C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003A910: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8003A914: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8003A918: jal         0x80065ABC
    // 0x8003A91C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_2;
    // 0x8003A91C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_2:
    // 0x8003A920: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003A924: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8003A928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A92C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003A930: nop

    // 0x8003A934: bc1fl       L_8003A948
    if (!c1cs) {
        // 0x8003A938: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003A948;
    }
    goto skip_0;
    // 0x8003A938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003A93C: jal         0x8003B540
    // 0x8003A940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003B540(rdram, ctx);
        goto after_3;
    // 0x8003A940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8003A944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003A948:
    // 0x8003A948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003A94C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003A950: jr          $ra
    // 0x8003A954: nop

    return;
    // 0x8003A954: nop

;}
RECOMP_FUNC void func_8045341C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045341C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80453420: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80453424: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80453428: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8045342C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453430: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80453434: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80453438: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8045343C: lw          $a1, 0x6A28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6A28);
    // 0x80453440: jal         0x804503F8
    // 0x80453444: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_804503F8(rdram, ctx);
        goto after_0;
    // 0x80453444: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80453448: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8045344C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80453450: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453454: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80453458: sw          $t6, 0x6A20($at)
    MEM_W(0X6A20, ctx->r1) = ctx->r14;
    // 0x8045345C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453460: ori         $at, $at, 0x6A24
    ctx->r1 = ctx->r1 | 0X6A24;
    // 0x80453464: addu        $a3, $v0, $at
    ctx->r7 = ADD32(ctx->r2, ctx->r1);
    // 0x80453468: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045346C: ori         $at, $at, 0x6A28
    ctx->r1 = ctx->r1 | 0X6A28;
    // 0x80453470: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80453474: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80453478: addiu       $t8, $zero, -0x64
    ctx->r24 = ADD32(0, -0X64);
    // 0x8045347C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453480: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80453484: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80453488: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8045348C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80453490: sw          $t9, 0x6A2C($at)
    MEM_W(0X6A2C, ctx->r1) = ctx->r25;
    // 0x80453494: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453498: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8045349C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804534A0: sw          $t0, 0x6A30($at)
    MEM_W(0X6A30, ctx->r1) = ctx->r8;
    // 0x804534A4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804534A8: jal         0x8044EFA0
    // 0x804534AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044EFA0(rdram, ctx);
        goto after_1;
    // 0x804534AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804534B0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x804534B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804534B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x804534BC: jal         0x80446CD0
    // 0x804534C0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    func_80446CD0(rdram, ctx);
        goto after_2;
    // 0x804534C0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_2:
    // 0x804534C4: jal         0x8044DED8
    // 0x804534C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044DED8(rdram, ctx);
        goto after_3;
    // 0x804534C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804534CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804534D0: jal         0x8044FEC4
    // 0x804534D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8044FEC4(rdram, ctx);
        goto after_4;
    // 0x804534D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x804534D8: jal         0x80445C74
    // 0x804534DC: nop

    func_80445C74(rdram, ctx);
        goto after_5;
    // 0x804534DC: nop

    after_5:
    // 0x804534E0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x804534E4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x804534E8: lbu         $t2, 0xF5C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XF5C);
    // 0x804534EC: lbu         $t1, 0xF5D($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XF5D);
    // 0x804534F0: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x804534F4: sb          $t1, 0xF64($t3)
    MEM_B(0XF64, ctx->r11) = ctx->r9;
    // 0x804534F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804534FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80453500: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80453504: jr          $ra
    // 0x80453508: nop

    return;
    // 0x80453508: nop

;}
RECOMP_FUNC void func_80424E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80424E58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80424E5C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80424E60: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80424E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80424E68: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80424E6C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80424E70: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80424E74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80424E78: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80424E7C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80424E80: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80424E84: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X34C0) << 16);
    // 0x80424E88: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80424E8C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80424E90: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80424E94: lw          $t2, 0x5EC0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(35, 0X34C0));
    // 0x80424E98: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80424E9C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80424EA0: jal         0x804245BC
    // 0x80424EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804245BC(rdram, ctx);
        goto after_0;
    // 0x80424EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80424EA8: jal         0x80424618
    // 0x80424EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80424618(rdram, ctx);
        goto after_1;
    // 0x80424EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80424EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80424EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80424EB8: jr          $ra
    // 0x80424EBC: nop

    return;
    // 0x80424EBC: nop

;}
RECOMP_FUNC void func_807B845C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B845C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807B8460: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x807B8464: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x807B8468: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x807B846C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x807B8470: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x807B8474: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807B8478: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807B847C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B8480: jal         0x807B8298
    // 0x807B8484: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    func_807B8298(rdram, ctx);
        goto after_0;
    // 0x807B8484: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x807B8488: lw          $t6, 0x44($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X44);
    // 0x807B848C: lw          $v0, 0x3C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X3C);
    // 0x807B8490: lui         $s1, 0x807C
    ctx->r17 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B8494: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B8498: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807B849C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B84A0: addiu       $s1, $s1, -0x6180
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B84A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B84A8: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x807B84AC: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x807B84B0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x807B84B4: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x807B84B8: lui         $a2, 0x4188
    ctx->r6 = S32(0X4188 << 16);
    // 0x807B84BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B84C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807B84C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807B84C8: ori         $a2, $a2, 0x51EB
    ctx->r6 = ctx->r6 | 0X51EB;
    // 0x807B84CC: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x807B84D0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x807B84D4: jal         0x8005CEBC
    // 0x807B84D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_1;
    // 0x807B84D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x807B84DC: lw          $t2, 0x3C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X3C);
    // 0x807B84E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B84E4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B84E8: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x807B84EC: jal         0x807B8314
    // 0x807B84F0: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_2;
    // 0x807B84F0: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    after_2:
    // 0x807B84F4: lw          $t5, 0x44($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X44);
    // 0x807B84F8: lw          $t8, 0x3C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X3C);
    // 0x807B84FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807B8500: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x807B8504: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x807B8508: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807B850C: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x807B8510: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x807B8514: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807B8518: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x807B851C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B8520: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807B8524: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x807B8528: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x807B852C: lui         $a3, 0xC220
    ctx->r7 = S32(0XC220 << 16);
    // 0x807B8530: jal         0x8005CEBC
    // 0x807B8534: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_3;
    // 0x807B8534: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x807B8538: lw          $t2, 0x3C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X3C);
    // 0x807B853C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B8540: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B8544: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x807B8548: jal         0x807B8314
    // 0x807B854C: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_4;
    // 0x807B854C: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    after_4:
    // 0x807B8550: lw          $t5, 0x44($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X44);
    // 0x807B8554: lw          $t7, 0x3C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X3C);
    // 0x807B8558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807B855C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x807B8560: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x807B8564: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807B8568: addu        $t8, $s1, $t6
    ctx->r24 = ADD32(ctx->r17, ctx->r14);
    // 0x807B856C: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x807B8570: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x807B8574: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x807B8578: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B857C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807B8580: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x807B8584: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x807B8588: lui         $a3, 0x4260
    ctx->r7 = S32(0X4260 << 16);
    // 0x807B858C: jal         0x8005CEBC
    // 0x807B8590: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_5;
    // 0x807B8590: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x807B8594: lw          $t2, 0x3C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X3C);
    // 0x807B8598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B859C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B85A0: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x807B85A4: jal         0x807B8314
    // 0x807B85A8: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_6;
    // 0x807B85A8: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    after_6:
    // 0x807B85AC: jal         0x807B8340
    // 0x807B85B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B8340(rdram, ctx);
        goto after_7;
    // 0x807B85B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x807B85B4: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x807B85B8: addu        $s2, $s3, $t5
    ctx->r18 = ADD32(ctx->r19, ctx->r13);
    // 0x807B85BC: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x807B85C0: lui         $s4, 0x807C
    ctx->r20 = S32(RELOC_HI16(886, 0X1C28) << 16);
    // 0x807B85C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B85C8: beq         $t6, $zero, L_807B865C
    if (ctx->r14 == 0) {
        // 0x807B85CC: addiu       $s1, $zero, 0xC0
        ctx->r17 = ADD32(0, 0XC0);
            goto L_807B865C;
    }
    // 0x807B85CC: addiu       $s1, $zero, 0xC0
    ctx->r17 = ADD32(0, 0XC0);
    // 0x807B85D0: addiu       $s4, $s4, -0x6168
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(886, 0X1C28));
L_807B85D4:
    // 0x807B85D4: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x807B85D8: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    // 0x807B85DC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x807B85E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807B85E4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x807B85E8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x807B85EC: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x807B85F0: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x807B85F4: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x807B85F8: jal         0x8005C27C
    // 0x807B85FC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_8;
    // 0x807B85FC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_8:
    // 0x807B8600: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B8604: slti        $at, $s1, 0x120
    ctx->r1 = SIGNED(ctx->r17) < 0X120 ? 1 : 0;
    // 0x807B8608: bne         $at, $zero, L_807B85D4
    if (ctx->r1 != 0) {
        // 0x807B860C: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_807B85D4;
    }
    // 0x807B860C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x807B8610: lui         $s4, 0x807C
    ctx->r20 = S32(RELOC_HI16(886, 0X1C70) << 16);
    // 0x807B8614: addiu       $s4, $s4, -0x6120
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(886, 0X1C70));
    // 0x807B8618: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B861C: addiu       $s1, $zero, 0xD8
    ctx->r17 = ADD32(0, 0XD8);
    // 0x807B8620: addiu       $s5, $zero, 0x100
    ctx->r21 = ADD32(0, 0X100);
L_807B8624:
    // 0x807B8624: lw          $t1, 0xC($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XC);
    // 0x807B8628: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    // 0x807B862C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x807B8630: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x807B8634: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x807B8638: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x807B863C: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x807B8640: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x807B8644: lhu         $a1, 0x0($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X0);
    // 0x807B8648: jal         0x8005C27C
    // 0x807B864C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    func_8005C27C(rdram, ctx);
        goto after_9;
    // 0x807B864C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_9:
    // 0x807B8650: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B8654: bne         $s1, $s5, L_807B8624
    if (ctx->r17 != ctx->r21) {
        // 0x807B8658: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_807B8624;
    }
    // 0x807B8658: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_807B865C:
    // 0x807B865C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x807B8660: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807B8664: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807B8668: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x807B866C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x807B8670: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x807B8674: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x807B8678: jr          $ra
    // 0x807B867C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x807B867C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805551CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805551CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805551D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805551D4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805551D8: addiu       $a1, $zero, 0x558
    ctx->r5 = ADD32(0, 0X558);
    // 0x805551DC: bnel        $t6, $zero, L_80555204
    if (ctx->r14 != 0) {
        // 0x805551E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80555204;
    }
    goto skip_0;
    // 0x805551E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x805551E4: jal         0x80045A34
    // 0x805551E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805551E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805551EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805551F0: bne         $v0, $zero, L_80555200
    if (ctx->r2 != 0) {
        // 0x805551F4: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80555200;
    }
    // 0x805551F4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805551F8: b           L_80555204
    // 0x805551FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80555204;
    // 0x805551FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80555200:
    // 0x80555200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80555204:
    // 0x80555204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80555208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8055520C: jr          $ra
    // 0x80555210: nop

    return;
    // 0x80555210: nop

;}
RECOMP_FUNC void func_800448BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800448BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800448C0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800448C4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800448C8: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x800448CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800448D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800448D4: lw          $s0, 0x18($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X18);
    // 0x800448D8: lw          $t6, 0x9F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9F4);
    // 0x800448DC: lw          $t7, 0x9FC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9FC);
    // 0x800448E0: sltu        $t9, $zero, $t8
    ctx->r25 = 0 < ctx->r24 ? 1 : 0;
    // 0x800448E4: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800448E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800448EC: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800448F0: jal         0x80057F24
    // 0x800448F4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    func_80057F24(rdram, ctx);
        goto after_0;
    // 0x800448F4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_0:
    // 0x800448F8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800448FC: addiu       $a2, $a2, 0x3E88
    ctx->r6 = ADD32(ctx->r6, 0X3E88);
    // 0x80044900: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80044904: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x80044908: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x8004490C: addiu       $a3, $a3, -0x7124
    ctx->r7 = ADD32(ctx->r7, -0X7124);
    // 0x80044910: jal         0x80057F74
    // 0x80044914: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80057F74(rdram, ctx);
        goto after_1;
    // 0x80044914: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80044918: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8004491C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80044920: jal         0x80060CF0
    // 0x80044924: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    func_80060CF0(rdram, ctx);
        goto after_2;
    // 0x80044924: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    after_2:
    // 0x80044928: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8004492C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80044930: jal         0x800623C8
    // 0x80044934: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    func_800623C8(rdram, ctx);
        goto after_3;
    // 0x80044934: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    after_3:
    // 0x80044938: jal         0x8004700C
    // 0x8004493C: nop

    func_8004700C(rdram, ctx);
        goto after_4;
    // 0x8004493C: nop

    after_4:
    // 0x80044940: beq         $v0, $zero, L_80044960
    if (ctx->r2 == 0) {
        // 0x80044944: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_80044960;
    }
    // 0x80044944: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80044948: lw          $t0, -0x6DA8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6DA8);
    // 0x8004494C: lw          $v0, 0x58($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X58);
    // 0x80044950: beq         $v0, $zero, L_80044960
    if (ctx->r2 == 0) {
        // 0x80044954: nop
    
            goto L_80044960;
    }
    // 0x80044954: nop

    // 0x80044958: jalr        $v0
    // 0x8004495C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x8004495C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_80044960:
    // 0x80044960: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80044964: lw          $v0, -0x6DA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DA8);
    // 0x80044968: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8004496C: beql        $v1, $zero, L_80044988
    if (ctx->r3 == 0) {
        // 0x80044970: lw          $v1, 0x38($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X38);
            goto L_80044988;
    }
    goto skip_0;
    // 0x80044970: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
    skip_0:
    // 0x80044974: jalr        $v1
    // 0x80044978: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_6;
    // 0x80044978: nop

    after_6:
    // 0x8004497C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80044980: lw          $v0, -0x6DA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DA8);
    // 0x80044984: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
L_80044988:
    // 0x80044988: beql        $v1, $zero, L_8004499C
    if (ctx->r3 == 0) {
        // 0x8004498C: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_8004499C;
    }
    goto skip_1;
    // 0x8004498C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x80044990: jalr        $v1
    // 0x80044994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_7;
    // 0x80044994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80044998: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_8004499C:
    // 0x8004499C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800449A0: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x800449A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800449A8: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800449AC: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x800449B0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x800449B4: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x800449B8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x800449BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800449C0: jal         0x80057F74
    // 0x800449C4: lw          $a3, 0x540($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X540);
    func_80057F74(rdram, ctx);
        goto after_8;
    // 0x800449C4: lw          $a3, 0x540($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X540);
    after_8:
    // 0x800449C8: jal         0x8004700C
    // 0x800449CC: nop

    func_8004700C(rdram, ctx);
        goto after_9;
    // 0x800449CC: nop

    after_9:
    // 0x800449D0: beq         $v0, $zero, L_800449F0
    if (ctx->r2 == 0) {
        // 0x800449D4: lui         $t1, 0x8010
        ctx->r9 = S32(0X8010 << 16);
            goto L_800449F0;
    }
    // 0x800449D4: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x800449D8: lw          $t1, -0x6DA8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6DA8);
    // 0x800449DC: lw          $v0, 0x58($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X58);
    // 0x800449E0: beq         $v0, $zero, L_800449F0
    if (ctx->r2 == 0) {
        // 0x800449E4: nop
    
            goto L_800449F0;
    }
    // 0x800449E4: nop

    // 0x800449E8: jalr        $v0
    // 0x800449EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_10;
    // 0x800449EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
L_800449F0:
    // 0x800449F0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800449F4: addiu       $a3, $a3, 0x7C38
    ctx->r7 = ADD32(ctx->r7, 0X7C38);
    // 0x800449F8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x800449FC: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x80044A00: jal         0x80057F74
    // 0x80044A04: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80057F74(rdram, ctx);
        goto after_11;
    // 0x80044A04: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80044A08: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80044A0C: addiu       $a3, $a3, 0x74B0
    ctx->r7 = ADD32(ctx->r7, 0X74B0);
    // 0x80044A10: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80044A14: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x80044A18: jal         0x80057F74
    // 0x80044A1C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80057F74(rdram, ctx);
        goto after_12;
    // 0x80044A1C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80044A20: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80044A24: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80044A28: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80044A2C: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x80044A30: lw          $a3, 0x548($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X548);
    // 0x80044A34: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x80044A38: jal         0x80057F74
    // 0x80044A3C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80057F74(rdram, ctx);
        goto after_13;
    // 0x80044A3C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80044A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80044A44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044A48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80044A4C: jr          $ra
    // 0x80044A50: nop

    return;
    // 0x80044A50: nop

;}
RECOMP_FUNC void func_8055386C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055386C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80553870: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80553874: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80553878: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4168) << 16);
    // 0x8055387C: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x80553880: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x80553884: lwc1        $f4, 0x4C88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4168));
    // 0x80553888: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8055388C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80553890: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
    // 0x80553894: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
    // 0x80553898: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x8055389C: jr          $ra
    // 0x805538A0: sw          $t6, 0xDB4($v0)
    MEM_W(0XDB4, ctx->r2) = ctx->r14;
    return;
    // 0x805538A0: sw          $t6, 0xDB4($v0)
    MEM_W(0XDB4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80036BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036BB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036BB8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036BBC: lw          $t6, 0x78($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X78);
    // 0x80036BC0: beql        $t6, $zero, L_80036C44
    if (ctx->r14 == 0) {
        // 0x80036BC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80036C44;
    }
    goto skip_0;
    // 0x80036BC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80036BC8: lw          $t7, 0x120($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X120);
    // 0x80036BCC: sltiu       $at, $t7, 0x3C
    ctx->r1 = ctx->r15 < 0X3C ? 1 : 0;
    // 0x80036BD0: bnel        $at, $zero, L_80036BEC
    if (ctx->r1 != 0) {
        // 0x80036BD4: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_80036BEC;
    }
    goto skip_1;
    // 0x80036BD4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_1:
    // 0x80036BD8: jal         0x8002F2D4
    // 0x80036BDC: sw          $zero, 0x120($v1)
    MEM_W(0X120, ctx->r3) = 0;
    func_8002F2D4(rdram, ctx);
        goto after_0;
    // 0x80036BDC: sw          $zero, 0x120($v1)
    MEM_W(0X120, ctx->r3) = 0;
    after_0:
    // 0x80036BE0: b           L_80036C44
    // 0x80036BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036C44;
    // 0x80036BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036BE8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_80036BEC:
    // 0x80036BEC: jal         0x80036B80
    // 0x80036BF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80036B80(rdram, ctx);
        goto after_1;
    // 0x80036BF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80036BF4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80036BF8: beq         $v0, $zero, L_80036C30
    if (ctx->r2 == 0) {
        // 0x80036BFC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80036C30;
    }
    // 0x80036BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80036C00: lw          $v0, 0x12C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X12C);
    // 0x80036C04: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x80036C08: addiu       $t9, $t9, 0x7074
    ctx->r25 = ADD32(ctx->r25, 0X7074);
    // 0x80036C0C: bne         $v0, $zero, L_80036C24
    if (ctx->r2 != 0) {
        // 0x80036C10: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80036C24;
    }
    // 0x80036C10: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80036C14: jal         0x8002F15C
    // 0x80036C18: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_8002F15C(rdram, ctx);
        goto after_2;
    // 0x80036C18: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_2:
    // 0x80036C1C: b           L_80036C44
    // 0x80036C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036C44;
    // 0x80036C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036C24:
    // 0x80036C24: sw          $t8, 0x12C($v1)
    MEM_W(0X12C, ctx->r3) = ctx->r24;
    // 0x80036C28: b           L_80036C40
    // 0x80036C2C: sw          $t9, 0xBC($v1)
    MEM_W(0XBC, ctx->r3) = ctx->r25;
        goto L_80036C40;
    // 0x80036C2C: sw          $t9, 0xBC($v1)
    MEM_W(0XBC, ctx->r3) = ctx->r25;
L_80036C30:
    // 0x80036C30: jal         0x8002F15C
    // 0x80036C34: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_8002F15C(rdram, ctx);
        goto after_3;
    // 0x80036C34: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_3:
    // 0x80036C38: b           L_80036C44
    // 0x80036C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036C44;
    // 0x80036C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036C40:
    // 0x80036C40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036C44:
    // 0x80036C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036C48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036C4C: jr          $ra
    // 0x80036C50: nop

    return;
    // 0x80036C50: nop

;}
RECOMP_FUNC void func_8051A820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A820: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8051A824: lw          $t7, 0x14C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14C);
    // 0x8051A828: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x8051A82C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8051A830: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8051A834: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8051A838: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8051A83C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8051A840: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8051A844: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8051A848: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8051A84C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8051A850: jr          $ra
    // 0x8051A854: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8051A854: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80742A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742A64: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742A68: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742A6C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742A70: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742A74: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742A78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742A7C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742A80: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742A84: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742A88: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742A8C: jr          $ra
    // 0x80742A90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742A90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80061170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061170: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80061174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061178: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8006117C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80061180: lhu         $v0, 0xE($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XE);
    // 0x80061184: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80061188: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8006118C: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x80061190: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80061194: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80061198: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006119C: lw          $t9, 0x64D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X64D0);
    // 0x800611A0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800611A4: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800611A8: jalr        $t9
    // 0x800611AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800611AC: nop

    after_0:
    // 0x800611B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800611B4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x800611B8: jr          $ra
    // 0x800611BC: nop

    return;
    // 0x800611BC: nop

;}
RECOMP_FUNC void func_8000A2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2F4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8000A2F8: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x8000A2FC: lbu         $t7, 0x4F7C($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4F7C);
    // 0x8000A300: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8000A304: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x8000A308: sw          $a0, 0x4FF4($v0)
    MEM_W(0X4FF4, ctx->r2) = ctx->r4;
    // 0x8000A30C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8000A310: addiu       $v0, $v0, 0x4FF4
    ctx->r2 = ADD32(ctx->r2, 0X4FF4);
    // 0x8000A314: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000A318: lbu         $t0, 0x4F7C($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X4F7C);
    // 0x8000A31C: lbu         $t2, 0x4F7D($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X4F7D);
    // 0x8000A320: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000A324: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x8000A328: bne         $t2, $v1, L_8000A338
    if (ctx->r10 != ctx->r3) {
        // 0x8000A32C: sb          $t1, 0x4F7C($a2)
        MEM_B(0X4F7C, ctx->r6) = ctx->r9;
            goto L_8000A338;
    }
    // 0x8000A32C: sb          $t1, 0x4F7C($a2)
    MEM_B(0X4F7C, ctx->r6) = ctx->r9;
    // 0x8000A330: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8000A334: sb          $t3, 0x4F7C($a2)
    MEM_B(0X4F7C, ctx->r6) = ctx->r11;
L_8000A338:
    // 0x8000A338: jr          $ra
    // 0x8000A33C: nop

    return;
    // 0x8000A33C: nop

;}
RECOMP_FUNC void func_80065528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065528: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006552C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065530: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065534: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065538: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006553C: jal         0x800654B4
    // 0x80065540: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800654B4(rdram, ctx);
        goto after_0;
    // 0x80065540: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x80065544: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80065548: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8006554C: bne         $v0, $zero, L_8006557C
    if (ctx->r2 != 0) {
        // 0x80065550: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8006557C;
    }
    // 0x80065550: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80065554: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80065558: addiu       $a0, $a0, 0xDAC
    ctx->r4 = ADD32(ctx->r4, 0XDAC);
    // 0x8006555C: addiu       $a1, $zero, 0x1C8
    ctx->r5 = ADD32(0, 0X1C8);
    // 0x80065560: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80065564: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065568: jal         0x80071380
    // 0x8006556C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006556C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80065570: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80065574: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80065578: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_8006557C:
    // 0x8006557C: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x80065580: beq         $a2, $zero, L_800655E4
    if (ctx->r6 == 0) {
        // 0x80065584: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800655E4;
    }
    // 0x80065584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80065588: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x8006558C: beq         $a1, $zero, L_800655B4
    if (ctx->r5 == 0) {
        // 0x80065590: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800655B4;
    }
    // 0x80065590: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80065594:
    // 0x80065594: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x80065598: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006559C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800655A0: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800655A4: bne         $a0, $v0, L_80065594
    if (ctx->r4 != ctx->r2) {
        // 0x800655A8: sh          $t6, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r14;
            goto L_80065594;
    }
    // 0x800655A8: sh          $t6, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r14;
    // 0x800655AC: beql        $v0, $a2, L_800655E8
    if (ctx->r2 == ctx->r6) {
        // 0x800655B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800655E8;
    }
    goto skip_0;
    // 0x800655B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800655B4:
    // 0x800655B4: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x800655B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800655BC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800655C0: sh          $t7, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r15;
    // 0x800655C4: lhu         $t8, 0x2($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X2);
    // 0x800655C8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800655CC: sh          $t8, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r24;
    // 0x800655D0: lhu         $t9, -0x4($t0)
    ctx->r25 = MEM_HU(ctx->r8, -0X4);
    // 0x800655D4: sh          $t9, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r25;
    // 0x800655D8: lhu         $t1, -0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, -0X2);
    // 0x800655DC: bne         $v0, $a2, L_800655B4
    if (ctx->r2 != ctx->r6) {
        // 0x800655E0: sh          $t1, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r9;
            goto L_800655B4;
    }
    // 0x800655E0: sh          $t1, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r9;
L_800655E4:
    // 0x800655E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800655E8:
    // 0x800655E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800655EC: jr          $ra
    // 0x800655F0: nop

    return;
    // 0x800655F0: nop

;}
RECOMP_FUNC void func_806D414C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D414C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D4150: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806D4154: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806D4158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D415C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806D4160: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x806D4164: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806D4168: lui         $t9, 0x806D
    ctx->r25 = S32(RELOC_HI16(616, 0X3628) << 16);
    // 0x806D416C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D4170: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x806D4174: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806D4178: lw          $t9, 0x65D8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(616, 0X3628));
    // 0x806D417C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806D4180: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x806D4184: jal         0x806D301C
    // 0x806D4188: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D301C(rdram, ctx);
        goto after_0;
    // 0x806D4188: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D418C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D4190: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x806D4194: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x806D4198: lbu         $t0, 0x30($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X30);
    // 0x806D419C: beql        $t0, $at, L_806D41BC
    if (ctx->r8 == ctx->r1) {
        // 0x806D41A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D41BC;
    }
    goto skip_0;
    // 0x806D41A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D41A4: beq         $t1, $zero, L_806D41B8
    if (ctx->r9 == 0) {
        // 0x806D41A8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_806D41B8;
    }
    // 0x806D41A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D41AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806D41B0: jal         0x806D3134
    // 0x806D41B4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    func_806D3134(rdram, ctx);
        goto after_1;
    // 0x806D41B4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    after_1:
L_806D41B8:
    // 0x806D41B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D41BC:
    // 0x806D41BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D41C0: jr          $ra
    // 0x806D41C4: nop

    return;
    // 0x806D41C4: nop

    // 0x806D41C8: nop

    // 0x806D41CC: nop

;}
RECOMP_FUNC void func_8040EAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EAE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EAEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040EAF0: bne         $a1, $at, L_8040EB14
    if (ctx->r5 != ctx->r1) {
        // 0x8040EAF4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8040EB14;
    }
    // 0x8040EAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EAF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8040EAFC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040EB00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EB04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040EB08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8040EB0C: jal         0x8040F0B8
    // 0x8040EB10: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    func_8040F0B8(rdram, ctx);
        goto after_0;
    // 0x8040EB10: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    after_0:
L_8040EB14:
    // 0x8040EB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EB18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EB1C: jr          $ra
    // 0x8040EB20: nop

    return;
    // 0x8040EB20: nop

;}
RECOMP_FUNC void func_806F7EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7EB0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x806F7EB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806F7EB8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x806F7EBC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x806F7EC0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x806F7EC4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x806F7EC8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F7ECC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F7ED0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x806F7ED4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806F7ED8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x806F7EDC: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x806F7EE0: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x806F7EE4: lw          $t8, 0x168($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X168);
    // 0x806F7EE8: lw          $t9, 0x26C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X26C);
    // 0x806F7EEC: lw          $s0, 0x88($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X88);
    // 0x806F7EF0: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x806F7EF4: jal         0x806F7870
    // 0x806F7EF8: sw          $t0, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r8;
    func_806F7870(rdram, ctx);
        goto after_0;
    // 0x806F7EF8: sw          $t0, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r8;
    after_0:
    // 0x806F7EFC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x806F7F00: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x806F7F04: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x806F7F08: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x806F7F0C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x806F7F10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x806F7F14: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x806F7F18: jal         0x806F7B28
    // 0x806F7F1C: sw          $s5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r21;
    func_806F7B28(rdram, ctx);
        goto after_1;
    // 0x806F7F1C: sw          $s5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r21;
    after_1:
    // 0x806F7F20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x806F7F24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806F7F28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F7F2C: jal         0x8007711C
    // 0x806F7F30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8007711C(rdram, ctx);
        goto after_2;
    // 0x806F7F30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x806F7F34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806F7F38: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x806F7F3C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x806F7F40: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
L_806F7F44:
    // 0x806F7F44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x806F7F48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x806F7F4C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x806F7F50: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x806F7F54: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x806F7F58: beq         $s0, $s3, L_806F7F68
    if (ctx->r16 == ctx->r19) {
        // 0x806F7F5C: sw          $s5, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r21;
            goto L_806F7F68;
    }
    // 0x806F7F5C: sw          $s5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r21;
    // 0x806F7F60: jal         0x806F7C14
    // 0x806F7F64: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_806F7C14(rdram, ctx);
        goto after_3;
    // 0x806F7F64: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
L_806F7F68:
    // 0x806F7F68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x806F7F6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x806F7F70: jal         0x806F7A58
    // 0x806F7F74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_806F7A58(rdram, ctx);
        goto after_4;
    // 0x806F7F74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x806F7F78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806F7F7C: bnel        $s0, $s4, L_806F7F44
    if (ctx->r16 != ctx->r20) {
        // 0x806F7F80: lw          $t3, 0x44($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X44);
            goto L_806F7F44;
    }
    goto skip_0;
    // 0x806F7F80: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x806F7F84: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x806F7F88: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x806F7F8C: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x806F7F90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x806F7F94: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x806F7F98: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x806F7F9C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x806F7FA0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x806F7FA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F7FA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F7FAC: jr          $ra
    // 0x806F7FB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x806F7FB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void gfxprint_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FA00: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8007FA04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007FA08: addiu       $t6, $t6, -0x62C
    ctx->r14 = ADD32(ctx->r14, -0X62C);
    // 0x8007FA0C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8007FA10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007FA14: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007FA18: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8007FA1C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8007FA20: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x8007FA24: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8007FA28: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8007FA2C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8007FA30: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x8007FA34: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    // 0x8007FA38: jr          $ra
    // 0x8007FA3C: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    return;
    // 0x8007FA3C: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80034A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034A44: jal         0x80034878
    // 0x80034A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80034878(rdram, ctx);
        goto after_0;
    // 0x80034A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034A4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80034A50: jal         0x80023A2C
    // 0x80034A54: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    func_80023A2C(rdram, ctx);
        goto after_1;
    // 0x80034A54: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x80034A58: jal         0x80023EA0
    // 0x80034A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80023EA0(rdram, ctx);
        goto after_2;
    // 0x80034A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80034A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034A68: jr          $ra
    // 0x80034A6C: nop

    return;
    // 0x80034A6C: nop

;}
RECOMP_FUNC void func_8043D898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D898: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(92, 0X6C8) << 16);
    // 0x8043D89C: addiu       $t6, $t6, -0x28F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(92, 0X6C8));
    // 0x8043D8A0: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8043D8A4: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8043D8A8: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x8043D8AC: jr          $ra
    // 0x8043D8B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8043D8B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_804001DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804001DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804001E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804001E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804001E8: jal         0x80400118
    // 0x804001EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80400118(rdram, ctx);
        goto after_0;
    // 0x804001EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804001F0: beq         $v0, $zero, L_80400208
    if (ctx->r2 == 0) {
        // 0x804001F4: nop
    
            goto L_80400208;
    }
    // 0x804001F4: nop

    // 0x804001F8: jal         0x800445A4
    // 0x804001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80400200: b           L_80400A14
    // 0x80400204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80400A14;
    // 0x80400204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80400208:
    // 0x80400208: jal         0x80051194
    // 0x8040020C: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    func_80051194(rdram, ctx);
        goto after_2;
    // 0x8040020C: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    after_2:
    // 0x80400210: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80400214: jal         0x80400A24
    // 0x80400218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80400A24(rdram, ctx);
        goto after_3;
    // 0x80400218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8040021C: bne         $v0, $zero, L_80400234
    if (ctx->r2 != 0) {
        // 0x80400220: nop
    
            goto L_80400234;
    }
    // 0x80400220: nop

    // 0x80400224: jal         0x800445A4
    // 0x80400228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x80400228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8040022C: b           L_80400A14
    // 0x80400230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80400A14;
    // 0x80400230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80400234:
    // 0x80400234: jal         0x80400A5C
    // 0x80400238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80400A5C(rdram, ctx);
        goto after_5;
    // 0x80400238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8040023C: jal         0x80400F7C
    // 0x80400240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80400F7C(rdram, ctx);
        goto after_6;
    // 0x80400240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80400244: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X7650) << 16);
    // 0x80400248: lwc1        $f0, 0x7690($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(8, 0X7650));
    // 0x8040024C: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80400250: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80400254: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80400258: lui         $t7, 0x8040
    ctx->r15 = S32(RELOC_HI16(8, 0X75C4) << 16);
    // 0x8040025C: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80400260: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80400264: addiu       $t7, $t7, 0x7604
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(8, 0X75C4));
    // 0x80400268: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8040026C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80400270: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80400274: addiu       $at, $zero, 0x46AC
    ctx->r1 = ADD32(0, 0X46AC);
    // 0x80400278: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8040027C: sw          $t9, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r25;
    // 0x80400280: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80400284: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x80400288: beq         $v0, $at, L_804002BC
    if (ctx->r2 == ctx->r1) {
        // 0x8040028C: swc1        $f0, 0xEC($s0)
        MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
            goto L_804002BC;
    }
    // 0x8040028C: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x80400290: addiu       $at, $zero, 0x46AD
    ctx->r1 = ADD32(0, 0X46AD);
    // 0x80400294: beq         $v0, $at, L_804002BC
    if (ctx->r2 == ctx->r1) {
        // 0x80400298: addiu       $at, $zero, 0x46AE
        ctx->r1 = ADD32(0, 0X46AE);
            goto L_804002BC;
    }
    // 0x80400298: addiu       $at, $zero, 0x46AE
    ctx->r1 = ADD32(0, 0X46AE);
    // 0x8040029C: beq         $v0, $at, L_804002BC
    if (ctx->r2 == ctx->r1) {
        // 0x804002A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804002BC;
    }
    // 0x804002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804002A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804002A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804002AC: jal         0x80401B90
    // 0x804002B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80401B90(rdram, ctx);
        goto after_7;
    // 0x804002B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x804002B4: b           L_804002D4
    // 0x804002B8: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
        goto L_804002D4;
    // 0x804002B8: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
L_804002BC:
    // 0x804002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804002C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804002C4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804002C8: jal         0x80401B90
    // 0x804002CC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80401B90(rdram, ctx);
        goto after_8;
    // 0x804002CC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_8:
    // 0x804002D0: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
L_804002D4:
    // 0x804002D4: lui         $t0, 0x8040
    ctx->r8 = S32(RELOC_HI16(8, 0XC18) << 16);
    // 0x804002D8: addiu       $t0, $t0, 0xC58
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(8, 0XC18));
    // 0x804002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804002E0: jal         0x80400050
    // 0x804002E4: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    func_80400050(rdram, ctx);
        goto after_9;
    // 0x804002E4: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    after_9:
    // 0x804002E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804002EC: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X7654) << 16);
    // 0x804002F0: lwc1        $f4, 0x7694($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(8, 0X7654));
    // 0x804002F4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x804002F8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x804002FC: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80400300: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80400304: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80400308: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8040030C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80400310: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80400314: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80400318: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8040031C: slti        $at, $v0, 0x46AF
    ctx->r1 = SIGNED(ctx->r2) < 0X46AF ? 1 : 0;
    // 0x80400320: bne         $at, $zero, L_80400354
    if (ctx->r1 != 0) {
        // 0x80400324: addiu       $t3, $v0, -0x468D
        ctx->r11 = ADD32(ctx->r2, -0X468D);
            goto L_80400354;
    }
    // 0x80400324: addiu       $t3, $v0, -0x468D
    ctx->r11 = ADD32(ctx->r2, -0X468D);
    // 0x80400328: addiu       $at, $zero, 0x4722
    ctx->r1 = ADD32(0, 0X4722);
    // 0x8040032C: beq         $v0, $at, L_80400794
    if (ctx->r2 == ctx->r1) {
        // 0x80400330: addiu       $a1, $zero, 0x41CE
        ctx->r5 = ADD32(0, 0X41CE);
            goto L_80400794;
    }
    // 0x80400330: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400334: addiu       $at, $zero, 0x4723
    ctx->r1 = ADD32(0, 0X4723);
    // 0x80400338: beq         $v0, $at, L_804007C4
    if (ctx->r2 == ctx->r1) {
        // 0x8040033C: addiu       $a1, $zero, 0x41CE
        ctx->r5 = ADD32(0, 0X41CE);
            goto L_804007C4;
    }
    // 0x8040033C: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400340: addiu       $at, $zero, 0x4724
    ctx->r1 = ADD32(0, 0X4724);
    // 0x80400344: beq         $v0, $at, L_804007F4
    if (ctx->r2 == ctx->r1) {
        // 0x80400348: addiu       $a1, $zero, 0x41CE
        ctx->r5 = ADD32(0, 0X41CE);
            goto L_804007F4;
    }
    // 0x80400348: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x8040034C: b           L_80400A00
    // 0x80400350: nop

        goto L_80400A00;
    // 0x80400350: nop

L_80400354:
    // 0x80400354: slti        $at, $v0, 0x4531
    ctx->r1 = SIGNED(ctx->r2) < 0X4531 ? 1 : 0;
    // 0x80400358: bne         $at, $zero, L_80400398
    if (ctx->r1 != 0) {
        // 0x8040035C: slti        $at, $v0, 0x4648
        ctx->r1 = SIGNED(ctx->r2) < 0X4648 ? 1 : 0;
            goto L_80400398;
    }
    // 0x8040035C: slti        $at, $v0, 0x4648
    ctx->r1 = SIGNED(ctx->r2) < 0X4648 ? 1 : 0;
    // 0x80400360: bne         $at, $zero, L_80400384
    if (ctx->r1 != 0) {
        // 0x80400364: sltiu       $at, $t3, 0x22
        ctx->r1 = ctx->r11 < 0X22 ? 1 : 0;
            goto L_80400384;
    }
    // 0x80400364: sltiu       $at, $t3, 0x22
    ctx->r1 = ctx->r11 < 0X22 ? 1 : 0;
    // 0x80400368: beq         $at, $zero, L_80400A00
    if (ctx->r1 == 0) {
        // 0x8040036C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80400A00;
    }
    // 0x8040036C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80400370: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X7658) << 16);
    // 0x80400374: addu        $at, $at, $t3
    gpr jr_addend_8040037C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80400378: lw          $t3, 0x7698($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(8, 0X7658));
    // 0x8040037C: jr          $t3
    // 0x80400380: nop

    switch (jr_addend_8040037C >> 2) {
        case 0: goto L_8040086C; break;
        case 1: goto L_804006FC; break;
        case 2: goto L_80400730; break;
        case 3: goto L_80400748; break;
        case 4: goto L_80400760; break;
        case 5: goto L_80400968; break;
        case 6: goto L_8040099C; break;
        case 7: goto L_80400824; break;
        case 8: goto L_80400A00; break;
        case 9: goto L_80400A00; break;
        case 10: goto L_80400A00; break;
        case 11: goto L_80400A00; break;
        case 12: goto L_80400A00; break;
        case 13: goto L_80400A00; break;
        case 14: goto L_80400A00; break;
        case 15: goto L_80400A00; break;
        case 16: goto L_80400A00; break;
        case 17: goto L_80400A00; break;
        case 18: goto L_80400A00; break;
        case 19: goto L_80400A00; break;
        case 20: goto L_80400A00; break;
        case 21: goto L_80400A00; break;
        case 22: goto L_80400A00; break;
        case 23: goto L_80400A00; break;
        case 24: goto L_80400A00; break;
        case 25: goto L_80400A00; break;
        case 26: goto L_80400A00; break;
        case 27: goto L_804006A0; break;
        case 28: goto L_8040083C; break;
        case 29: goto L_80400854; break;
        case 30: goto L_804009D0; break;
        case 31: goto L_80400884; break;
        case 32: goto L_804008D0; break;
        case 33: goto L_8040091C; break;
        default: switch_error(__func__, 0x8040037C, 0x80407698);
    }
    // 0x80400380: nop

L_80400384:
    // 0x80400384: addiu       $at, $zero, 0x4647
    ctx->r1 = ADD32(0, 0X4647);
    // 0x80400388: beq         $v0, $at, L_8040060C
    if (ctx->r2 == ctx->r1) {
        // 0x8040038C: addiu       $a1, $zero, 0x41CE
        ctx->r5 = ADD32(0, 0X41CE);
            goto L_8040060C;
    }
    // 0x8040038C: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400390: b           L_80400A00
    // 0x80400394: nop

        goto L_80400A00;
    // 0x80400394: nop

L_80400398:
    // 0x80400398: slti        $at, $v0, 0x41D8
    ctx->r1 = SIGNED(ctx->r2) < 0X41D8 ? 1 : 0;
    // 0x8040039C: bne         $at, $zero, L_804003C8
    if (ctx->r1 != 0) {
        // 0x804003A0: addiu       $t5, $v0, -0x41D1
        ctx->r13 = ADD32(ctx->r2, -0X41D1);
            goto L_804003C8;
    }
    // 0x804003A0: addiu       $t5, $v0, -0x41D1
    ctx->r13 = ADD32(ctx->r2, -0X41D1);
    // 0x804003A4: addiu       $t4, $v0, -0x452A
    ctx->r12 = ADD32(ctx->r2, -0X452A);
    // 0x804003A8: sltiu       $at, $t4, 0x7
    ctx->r1 = ctx->r12 < 0X7 ? 1 : 0;
    // 0x804003AC: beq         $at, $zero, L_80400A00
    if (ctx->r1 == 0) {
        // 0x804003B0: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80400A00;
    }
    // 0x804003B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x804003B4: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X76E0) << 16);
    // 0x804003B8: addu        $at, $at, $t4
    gpr jr_addend_804003C0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x804003BC: lw          $t4, 0x7720($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(8, 0X76E0));
    // 0x804003C0: jr          $t4
    // 0x804003C4: nop

    switch (jr_addend_804003C0 >> 2) {
        case 0: goto L_8040057C; break;
        case 1: goto L_80400594; break;
        case 2: goto L_804005AC; break;
        case 3: goto L_804005C4; break;
        case 4: goto L_804005DC; break;
        case 5: goto L_804005F4; break;
        case 6: goto L_80400620; break;
        default: switch_error(__func__, 0x804003C0, 0x80407720);
    }
    // 0x804003C4: nop

L_804003C8:
    // 0x804003C8: sltiu       $at, $t5, 0x7
    ctx->r1 = ctx->r13 < 0X7 ? 1 : 0;
    // 0x804003CC: beq         $at, $zero, L_80400A00
    if (ctx->r1 == 0) {
        // 0x804003D0: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80400A00;
    }
    // 0x804003D0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x804003D4: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X76FC) << 16);
    // 0x804003D8: addu        $at, $at, $t5
    gpr jr_addend_804003E0 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x804003DC: lw          $t5, 0x773C($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(8, 0X76FC));
    // 0x804003E0: jr          $t5
    // 0x804003E4: nop

    switch (jr_addend_804003E0 >> 2) {
        case 0: goto L_804003E8; break;
        case 1: goto L_80400434; break;
        case 2: goto L_80400480; break;
        case 3: goto L_804004CC; break;
        case 4: goto L_80400518; break;
        case 5: goto L_80400638; break;
        case 6: goto L_80400564; break;
        default: switch_error(__func__, 0x804003E0, 0x8040773C);
    }
    // 0x804003E4: nop

L_804003E8:
    // 0x804003E8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x804003EC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x804003F0: lw          $t7, 0xA68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XA68);
    // 0x804003F4: addiu       $t6, $zero, 0x4030
    ctx->r14 = ADD32(0, 0X4030);
    // 0x804003F8: sh          $t6, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r14;
    // 0x804003FC: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80400400: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80400404: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x80400408: jalr        $t9
    // 0x8040040C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x8040040C: nop

    after_10:
    // 0x80400410: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x80400414: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x80400414: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400418: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x8040041C: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x80400420: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80400424: jal         0x80048BE8
    // 0x80400428: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_11;
    // 0x80400428: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_11:
    // 0x8040042C: b           L_80400A00
    // 0x80400430: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x80400430: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80400434:
    // 0x80400434: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80400438: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8040043C: lw          $t3, 0xA68($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XA68);
    // 0x80400440: addiu       $t2, $zero, 0x4031
    ctx->r10 = ADD32(0, 0X4031);
    // 0x80400444: sh          $t2, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r10;
    // 0x80400448: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8040044C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80400450: lw          $t9, 0x54($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X54);
    // 0x80400454: jalr        $t9
    // 0x80400458: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x80400458: nop

    after_12:
    // 0x8040045C: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x80400460: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x80400460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400464: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x80400468: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x8040046C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80400470: jal         0x80048BE8
    // 0x80400474: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_13;
    // 0x80400474: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_13:
    // 0x80400478: b           L_80400A00
    // 0x8040047C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x8040047C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80400480:
    // 0x80400480: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80400484: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80400488: lw          $t8, 0xA68($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XA68);
    // 0x8040048C: addiu       $t7, $zero, 0x4032
    ctx->r15 = ADD32(0, 0X4032);
    // 0x80400490: sh          $t7, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r15;
    // 0x80400494: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x80400498: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8040049C: lw          $t9, 0x54($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X54);
    // 0x804004A0: jalr        $t9
    // 0x804004A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x804004A4: nop

    after_14:
    // 0x804004A8: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x804004AC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x804004AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804004B0: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x804004B4: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x804004B8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x804004BC: jal         0x80048BE8
    // 0x804004C0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_15;
    // 0x804004C0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_15:
    // 0x804004C4: b           L_80400A00
    // 0x804004C8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x804004C8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_804004CC:
    // 0x804004CC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x804004D0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x804004D4: lw          $t4, 0xA68($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XA68);
    // 0x804004D8: addiu       $t3, $zero, 0x4033
    ctx->r11 = ADD32(0, 0X4033);
    // 0x804004DC: sh          $t3, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r11;
    // 0x804004E0: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x804004E4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804004E8: lw          $t9, 0x54($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X54);
    // 0x804004EC: jalr        $t9
    // 0x804004F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_16;
    // 0x804004F0: nop

    after_16:
    // 0x804004F4: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x804004F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x804004F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804004FC: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x80400500: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x80400504: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80400508: jal         0x80048BE8
    // 0x8040050C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_17;
    // 0x8040050C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_17:
    // 0x80400510: b           L_80400A00
    // 0x80400514: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x80400514: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80400518:
    // 0x80400518: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8040051C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80400520: lw          $t0, 0xA68($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA68);
    // 0x80400524: addiu       $t8, $zero, 0x4034
    ctx->r24 = ADD32(0, 0X4034);
    // 0x80400528: sh          $t8, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r24;
    // 0x8040052C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80400530: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80400534: lw          $t9, 0x54($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X54);
    // 0x80400538: jalr        $t9
    // 0x8040053C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_18;
    // 0x8040053C: nop

    after_18:
    // 0x80400540: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x80400544: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x80400544: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400548: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x8040054C: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x80400550: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80400554: jal         0x80048BE8
    // 0x80400558: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_19;
    // 0x80400558: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_19:
    // 0x8040055C: b           L_80400A00
    // 0x80400560: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x80400560: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80400564:
    // 0x80400564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400568: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x8040056C: jal         0x80400068
    // 0x80400570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80400068(rdram, ctx);
        goto after_20;
    // 0x80400570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80400574: b           L_80400A00
    // 0x80400578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8040057C:
    // 0x8040057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400580: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400584: jal         0x80400068
    // 0x80400588: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80400068(rdram, ctx);
        goto after_21;
    // 0x80400588: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_21:
    // 0x8040058C: b           L_80400A00
    // 0x80400590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80400594:
    // 0x80400594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400598: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x8040059C: jal         0x80400068
    // 0x804005A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80400068(rdram, ctx);
        goto after_22;
    // 0x804005A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_22:
    // 0x804005A4: b           L_80400A00
    // 0x804005A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x804005A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_804005AC:
    // 0x804005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804005B0: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x804005B4: jal         0x80400068
    // 0x804005B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80400068(rdram, ctx);
        goto after_23;
    // 0x804005B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_23:
    // 0x804005BC: b           L_80400A00
    // 0x804005C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x804005C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_804005C4:
    // 0x804005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804005C8: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x804005CC: jal         0x80400068
    // 0x804005D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80400068(rdram, ctx);
        goto after_24;
    // 0x804005D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_24:
    // 0x804005D4: b           L_80400A00
    // 0x804005D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x804005D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_804005DC:
    // 0x804005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804005E0: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x804005E4: jal         0x80400068
    // 0x804005E8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80400068(rdram, ctx);
        goto after_25;
    // 0x804005E8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_25:
    // 0x804005EC: b           L_80400A00
    // 0x804005F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x804005F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_804005F4:
    // 0x804005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804005F8: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x804005FC: jal         0x80400068
    // 0x80400600: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80400068(rdram, ctx);
        goto after_26;
    // 0x80400600: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_26:
    // 0x80400604: b           L_80400A00
    // 0x80400608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8040060C:
    // 0x8040060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400610: jal         0x80400068
    // 0x80400614: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80400068(rdram, ctx);
        goto after_27;
    // 0x80400614: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_27:
    // 0x80400618: b           L_80400A00
    // 0x8040061C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x8040061C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80400620:
    // 0x80400620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400624: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400628: jal         0x80400068
    // 0x8040062C: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    func_80400068(rdram, ctx);
        goto after_28;
    // 0x8040062C: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    after_28:
    // 0x80400630: b           L_80400A00
    // 0x80400634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80400638:
    // 0x80400638: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8040063C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80400640: lw          $t5, 0xA68($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XA68);
    // 0x80400644: addiu       $t4, $zero, 0x4035
    ctx->r12 = ADD32(0, 0X4035);
    // 0x80400648: sh          $t4, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r12;
    // 0x8040064C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80400650: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80400654: lw          $t9, 0x54($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X54);
    // 0x80400658: jalr        $t9
    // 0x8040065C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_29;
    // 0x8040065C: nop

    after_29:
    // 0x80400660: beq         $v0, $zero, L_80400680
    if (ctx->r2 == 0) {
        // 0x80400664: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400680;
    }
    // 0x80400664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400668: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x8040066C: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x80400670: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80400674: jal         0x80048BE8
    // 0x80400678: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_30;
    // 0x80400678: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_30:
    // 0x8040067C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80400680:
    // 0x80400680: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80400684: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80400688: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040068C: swc1        $f6, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->f6.u32l;
    // 0x80400690: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x80400694: lwc1        $f8, 0x138($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X138);
    // 0x80400698: b           L_80400A00
    // 0x8040069C: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
        goto L_80400A00;
    // 0x8040069C: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
L_804006A0:
    // 0x804006A0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x804006A4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x804006A8: lw          $t2, 0xAA0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XAA0);
    // 0x804006AC: lui         $t4, 0x8040
    ctx->r12 = S32(RELOC_HI16(8, 0X75B8) << 16);
    // 0x804006B0: lw          $t5, 0xA68($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XA68);
    // 0x804006B4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x804006B8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x804006BC: lhu         $t4, 0x75F8($t4)
    ctx->r12 = MEM_HU(ctx->r12, (int16_t)RELOC_LO16(8, 0X75B8));
    // 0x804006C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804006C4: sh          $t4, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r12;
    // 0x804006C8: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x804006CC: lw          $t9, 0x54($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X54);
    // 0x804006D0: jalr        $t9
    // 0x804006D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_31;
    // 0x804006D4: nop

    after_31:
    // 0x804006D8: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x804006DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x804006DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804006E0: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x804006E4: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x804006E8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x804006EC: jal         0x80048BE8
    // 0x804006F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_32;
    // 0x804006F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_32:
    // 0x804006F4: b           L_80400A00
    // 0x804006F8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x804006F8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_804006FC:
    // 0x804006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400700: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400704: jal         0x80400068
    // 0x80400708: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80400068(rdram, ctx);
        goto after_33;
    // 0x80400708: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_33:
    // 0x8040070C: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x80400710: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x80400710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400714: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x80400718: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x8040071C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80400720: jal         0x80048BE8
    // 0x80400724: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_34;
    // 0x80400724: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_34:
    // 0x80400728: b           L_80400A00
    // 0x8040072C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x8040072C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80400730:
    // 0x80400730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400734: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400738: jal         0x80400068
    // 0x8040073C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_80400068(rdram, ctx);
        goto after_35;
    // 0x8040073C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_35:
    // 0x80400740: b           L_80400A00
    // 0x80400744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80400748:
    // 0x80400748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040074C: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400750: jal         0x80400068
    // 0x80400754: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_80400068(rdram, ctx);
        goto after_36;
    // 0x80400754: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_36:
    // 0x80400758: b           L_80400A00
    // 0x8040075C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x8040075C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80400760:
    // 0x80400760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400764: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400768: jal         0x80400068
    // 0x8040076C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80400068(rdram, ctx);
        goto after_37;
    // 0x8040076C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_37:
    // 0x80400770: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x80400774: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x80400774: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400778: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x8040077C: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x80400780: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80400784: jal         0x80048BE8
    // 0x80400788: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_38;
    // 0x80400788: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_38:
    // 0x8040078C: b           L_80400A00
    // 0x80400790: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x80400790: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80400794:
    // 0x80400794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400798: jal         0x80400068
    // 0x8040079C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80400068(rdram, ctx);
        goto after_39;
    // 0x8040079C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_39:
    // 0x804007A0: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x804007A4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x804007A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804007A8: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x804007AC: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x804007B0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x804007B4: jal         0x80048BE8
    // 0x804007B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_40;
    // 0x804007B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_40:
    // 0x804007BC: b           L_80400A00
    // 0x804007C0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x804007C0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_804007C4:
    // 0x804007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804007C8: jal         0x80400068
    // 0x804007CC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_80400068(rdram, ctx);
        goto after_41;
    // 0x804007CC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_41:
    // 0x804007D0: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x804007D4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x804007D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804007D8: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x804007DC: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x804007E0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x804007E4: jal         0x80048BE8
    // 0x804007E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_42;
    // 0x804007E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_42:
    // 0x804007EC: b           L_80400A00
    // 0x804007F0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x804007F0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_804007F4:
    // 0x804007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804007F8: jal         0x80400068
    // 0x804007FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_80400068(rdram, ctx);
        goto after_43;
    // 0x804007FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_43:
    // 0x80400800: beq         $v0, $zero, L_80400A00
    if (ctx->r2 == 0) {
        // 0x80400804: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80400A00;
    }
    // 0x80400804: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400808: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x8040080C: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x80400810: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80400814: jal         0x80048BE8
    // 0x80400818: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_44;
    // 0x80400818: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_44:
    // 0x8040081C: b           L_80400A00
    // 0x80400820: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
        goto L_80400A00;
    // 0x80400820: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
L_80400824:
    // 0x80400824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400828: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x8040082C: jal         0x80400068
    // 0x80400830: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80400068(rdram, ctx);
        goto after_45;
    // 0x80400830: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_45:
    // 0x80400834: b           L_80400A00
    // 0x80400838: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400838: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8040083C:
    // 0x8040083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400840: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400844: jal         0x80400068
    // 0x80400848: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80400068(rdram, ctx);
        goto after_46;
    // 0x80400848: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_46:
    // 0x8040084C: b           L_80400A00
    // 0x80400850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80400854:
    // 0x80400854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400858: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x8040085C: jal         0x80400068
    // 0x80400860: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    func_80400068(rdram, ctx);
        goto after_47;
    // 0x80400860: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_47:
    // 0x80400864: b           L_80400A00
    // 0x80400868: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400868: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8040086C:
    // 0x8040086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400870: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400874: jal         0x80400068
    // 0x80400878: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    func_80400068(rdram, ctx);
        goto after_48;
    // 0x80400878: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_48:
    // 0x8040087C: b           L_80400A00
    // 0x80400880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80400A00;
    // 0x80400880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80400884:
    // 0x80400884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400888: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x8040088C: jal         0x80400068
    // 0x80400890: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80400068(rdram, ctx);
        goto after_49;
    // 0x80400890: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_49:
    // 0x80400894: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80400898: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040089C: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x804008A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804008A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804008A8: swc1        $f10, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->f10.u32l;
    // 0x804008AC: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x804008B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804008B4: lwc1        $f16, 0x138($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X138);
    // 0x804008B8: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
    // 0x804008BC: swc1        $f18, 0x13C($v1)
    MEM_W(0X13C, ctx->r3) = ctx->f18.u32l;
    // 0x804008C0: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804008C4: lwc1        $f4, 0x13C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X13C);
    // 0x804008C8: b           L_80400A00
    // 0x804008CC: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
        goto L_80400A00;
    // 0x804008CC: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
L_804008D0:
    // 0x804008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804008D4: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x804008D8: jal         0x80400068
    // 0x804008DC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80400068(rdram, ctx);
        goto after_50;
    // 0x804008DC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_50:
    // 0x804008E0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804008E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804008E8: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x804008EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804008F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804008F4: swc1        $f6, 0x138($t2)
    MEM_W(0X138, ctx->r10) = ctx->f6.u32l;
    // 0x804008F8: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x804008FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400900: lwc1        $f8, 0x138($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X138);
    // 0x80400904: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x80400908: swc1        $f10, 0x13C($v1)
    MEM_W(0X13C, ctx->r3) = ctx->f10.u32l;
    // 0x8040090C: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x80400910: lwc1        $f16, 0x13C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X13C);
    // 0x80400914: b           L_80400A00
    // 0x80400918: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
        goto L_80400A00;
    // 0x80400918: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
L_8040091C:
    // 0x8040091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80400920: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400924: jal         0x80400068
    // 0x80400928: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    func_80400068(rdram, ctx);
        goto after_51;
    // 0x80400928: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_51:
    // 0x8040092C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80400930: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80400934: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x80400938: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8040093C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80400940: swc1        $f18, 0x138($t4)
    MEM_W(0X138, ctx->r12) = ctx->f18.u32l;
    // 0x80400944: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80400948: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8040094C: lwc1        $f4, 0x138($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X138);
    // 0x80400950: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    // 0x80400954: swc1        $f6, 0x13C($v1)
    MEM_W(0X13C, ctx->r3) = ctx->f6.u32l;
    // 0x80400958: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040095C: lwc1        $f8, 0x13C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X13C);
    // 0x80400960: b           L_80400A00
    // 0x80400964: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
        goto L_80400A00;
    // 0x80400964: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
L_80400968:
    // 0x80400968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040096C: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x80400970: jal         0x80400068
    // 0x80400974: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    func_80400068(rdram, ctx);
        goto after_52;
    // 0x80400974: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_52:
    // 0x80400978: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8040097C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80400980: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80400984: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80400988: swc1        $f10, 0x138($t6)
    MEM_W(0X138, ctx->r14) = ctx->f10.u32l;
    // 0x8040098C: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x80400990: lwc1        $f16, 0x138($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X138);
    // 0x80400994: b           L_80400A00
    // 0x80400998: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
        goto L_80400A00;
    // 0x80400998: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
L_8040099C:
    // 0x8040099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804009A0: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x804009A4: jal         0x80400068
    // 0x804009A8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_80400068(rdram, ctx);
        goto after_53;
    // 0x804009A8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_53:
    // 0x804009AC: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x804009B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804009B4: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x804009B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804009BC: swc1        $f18, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->f18.u32l;
    // 0x804009C0: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x804009C4: lwc1        $f4, 0x138($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X138);
    // 0x804009C8: b           L_80400A00
    // 0x804009CC: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
        goto L_80400A00;
    // 0x804009CC: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
L_804009D0:
    // 0x804009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804009D4: addiu       $a1, $zero, 0x41CE
    ctx->r5 = ADD32(0, 0X41CE);
    // 0x804009D8: jal         0x80400068
    // 0x804009DC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80400068(rdram, ctx);
        goto after_54;
    // 0x804009DC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_54:
    // 0x804009E0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x804009E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804009E8: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x804009EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804009F0: swc1        $f6, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->f6.u32l;
    // 0x804009F4: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804009F8: lwc1        $f8, 0x138($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X138);
    // 0x804009FC: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
L_80400A00:
    // 0x80400A00: bnel        $a0, $zero, L_80400A14
    if (ctx->r4 != 0) {
        // 0x80400A04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80400A14;
    }
    goto skip_0;
    // 0x80400A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80400A08: jal         0x800445A4
    // 0x80400A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_55;
    // 0x80400A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80400A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80400A14:
    // 0x80400A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80400A18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80400A1C: jr          $ra
    // 0x80400A20: nop

    return;
    // 0x80400A20: nop

;}
RECOMP_FUNC void func_80580568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580568: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8058056C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580570: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80580574: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80580578: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8058057C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80580580: jal         0x8006C67C
    // 0x80580584: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    func_8006C67C(rdram, ctx);
        goto after_0;
    // 0x80580584: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_0:
    // 0x80580588: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8058058C: jal         0x80047AB8
    // 0x80580590: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80580590: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x80580594: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80580598: jal         0x80058CC0
    // 0x8058059C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80058CC0(rdram, ctx);
        goto after_2;
    // 0x8058059C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x805805A0: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x805805A4: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805805A8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x805805AC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805805B0: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805805B4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805805B8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805805BC: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    // 0x805805C0: jal         0x80081E8C
    // 0x805805C4: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    fatan2(rdram, ctx);
        goto after_3;
    // 0x805805C4: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x805805C8: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47E0) << 16);
    // 0x805805CC: lwc1        $f16, 0x35F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47E0));
    // 0x805805D0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x805805D4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x805805D8: swc1        $f18, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f18.u32l;
    // 0x805805DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805805E0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x805805E4: jr          $ra
    // 0x805805E8: nop

    return;
    // 0x805805E8: nop

;}
RECOMP_FUNC void func_80567DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80567DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80567DDC: jal         0x8004700C
    // 0x80567DE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80567DE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80567DE4: beq         $v0, $zero, L_80567E50
    if (ctx->r2 == 0) {
        // 0x80567DE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80567E50;
    }
    // 0x80567DE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80567DEC: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x80567DF0: lw          $a1, 0x18($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X18);
    // 0x80567DF4: beq         $a1, $zero, L_80567E00
    if (ctx->r5 == 0) {
        // 0x80567DF8: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80567E00;
    }
    // 0x80567DF8: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80567DFC: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
L_80567E00:
    // 0x80567E00: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x80567E04: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80567E08: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x80567E0C: beql        $t8, $zero, L_80567E3C
    if (ctx->r24 == 0) {
        // 0x80567E10: lw          $t2, 0x174($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X174);
            goto L_80567E3C;
    }
    goto skip_0;
    // 0x80567E10: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    skip_0:
    // 0x80567E14: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80567E18: beql        $t9, $zero, L_80567E54
    if (ctx->r25 == 0) {
        // 0x80567E1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80567E54;
    }
    goto skip_1;
    // 0x80567E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80567E20: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x80567E24: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80567E28: jal         0x800610A0
    // 0x80567E2C: sw          $t0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r8;
    func_800610A0(rdram, ctx);
        goto after_1;
    // 0x80567E2C: sw          $t0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r8;
    after_1:
    // 0x80567E30: b           L_80567E54
    // 0x80567E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80567E54;
    // 0x80567E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80567E38: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
L_80567E3C:
    // 0x80567E3C: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80567E40: bnel        $t3, $zero, L_80567E54
    if (ctx->r11 != 0) {
        // 0x80567E44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80567E54;
    }
    goto skip_2;
    // 0x80567E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80567E48: jal         0x80062748
    // 0x80567E4C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_2;
    // 0x80567E4C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
L_80567E50:
    // 0x80567E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80567E54:
    // 0x80567E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80567E58: jr          $ra
    // 0x80567E5C: nop

    return;
    // 0x80567E5C: nop

;}
RECOMP_FUNC void func_8069EC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069EC04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8069EC08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069EC0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069EC10: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8069EC14: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8069EC18: lui         $t9, 0x806A
    ctx->r25 = S32(RELOC_HI16(577, 0X8F0) << 16);
    // 0x8069EC1C: addiu       $t7, $t6, -0x40E3
    ctx->r15 = ADD32(ctx->r14, -0X40E3);
    // 0x8069EC20: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8069EC24: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x8069EC28: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8069EC2C: addiu       $t9, $t9, -0x1340
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(577, 0X8F0));
    // 0x8069EC30: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8069EC34: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(577, 0X80C) << 16);
    // 0x8069EC38: addiu       $t1, $t1, -0x1424
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(577, 0X80C));
    // 0x8069EC3C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8069EC40: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8069EC44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069EC48: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8069EC4C: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x8069EC50: sh          $t2, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r10;
    // 0x8069EC54: sb          $t3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r11;
    // 0x8069EC58: jal         0x8069EC9C
    // 0x8069EC5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8069EC9C(rdram, ctx);
        goto after_0;
    // 0x8069EC5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8069EC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069EC64: jal         0x8069E3E0
    // 0x8069EC68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8069E3E0(rdram, ctx);
        goto after_1;
    // 0x8069EC68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8069EC6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069EC70: jal         0x8069EAE4
    // 0x8069EC74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8069EAE4(rdram, ctx);
        goto after_2;
    // 0x8069EC74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8069EC78: jal         0x8069EBB0
    // 0x8069EC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8069EBB0(rdram, ctx);
        goto after_3;
    // 0x8069EC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8069EC80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069EC84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8069EC88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8069EC8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069EC90: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    // 0x8069EC94: jr          $ra
    // 0x8069EC98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8069EC98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000CAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CAB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000CABC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000CAC0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000CAC4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000CAC8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000CACC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000CAD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000CAD4: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    // 0x8000CAD8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000CADC: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x8000CAE0: beq         $t6, $zero, L_8000CB78
    if (ctx->r14 == 0) {
        // 0x8000CAE4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000CB78;
    }
    // 0x8000CAE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000CAE8: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000CAEC: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8000CAF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CAF4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000CAF8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000CAFC: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8000CB00: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x8000CB04: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000CB08: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x8000CB0C: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8000CB10: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8000CB14: nop

    // 0x8000CB18: bc1fl       L_8000CB2C
    if (!c1cs) {
        // 0x8000CB1C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8000CB2C;
    }
    goto skip_0;
    // 0x8000CB1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x8000CB20: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x8000CB24: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000CB28: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8000CB2C:
    // 0x8000CB2C: nop

    // 0x8000CB30: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8000CB34: nop

    // 0x8000CB38: bc1fl       L_8000CB48
    if (!c1cs) {
        // 0x8000CB3C: lhu         $t0, 0x12($s2)
        ctx->r8 = MEM_HU(ctx->r18, 0X12);
            goto L_8000CB48;
    }
    goto skip_1;
    // 0x8000CB3C: lhu         $t0, 0x12($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X12);
    skip_1:
    // 0x8000CB40: swc1        $f2, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f2.u32l;
    // 0x8000CB44: lhu         $t0, 0x12($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X12);
L_8000CB48:
    // 0x8000CB48: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000CB4C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8000CB50: bne         $t2, $zero, L_8000CB78
    if (ctx->r10 != 0) {
        // 0x8000CB54: sh          $t1, 0x12($s2)
        MEM_H(0X12, ctx->r18) = ctx->r9;
            goto L_8000CB78;
    }
    // 0x8000CB54: sh          $t1, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r9;
    // 0x8000CB58: lbu         $t3, 0x1($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X1);
    // 0x8000CB5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000CB60: bnel        $t3, $at, L_8000CB7C
    if (ctx->r11 != ctx->r1) {
        // 0x8000CB64: lw          $t4, 0x0($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X0);
            goto L_8000CB7C;
    }
    goto skip_2;
    // 0x8000CB64: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    skip_2:
    // 0x8000CB68: jal         0x8000DAE8
    // 0x8000CB6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DAE8(rdram, ctx);
        goto after_0;
    // 0x8000CB6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8000CB70: b           L_8000CBE0
    // 0x8000CB74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8000CBE0;
    // 0x8000CB74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000CB78:
    // 0x8000CB78: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_8000CB7C:
    // 0x8000CB7C: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x8000CB80: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000CB84: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x8000CB88: bgez        $t6, L_8000CBA0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000CB8C: nop
    
            goto L_8000CBA0;
    }
    // 0x8000CB8C: nop

    // 0x8000CB90: lwc1        $f10, 0x1C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8000CB94: lwc1        $f16, 0x2C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x8000CB98: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000CB9C: swc1        $f18, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f18.u32l;
L_8000CBA0:
    // 0x8000CBA0: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8000CBA4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000CBA8: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8000CBAC: bnel        $s3, $t8, L_8000CBC8
    if (ctx->r19 != ctx->r24) {
        // 0x8000CBB0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000CBC8;
    }
    goto skip_3;
    // 0x8000CBB0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_3:
    // 0x8000CBB4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8000CBB8: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x8000CBBC: jal         0x8000C910
    // 0x8000CBC0: srl         $a1, $a1, 31
    ctx->r5 = S32(U32(ctx->r5) >> 31);
    func_8000C910(rdram, ctx);
        goto after_1;
    // 0x8000CBC0: srl         $a1, $a1, 31
    ctx->r5 = S32(U32(ctx->r5) >> 31);
    after_1:
    // 0x8000CBC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000CBC8:
    // 0x8000CBC8: bne         $s0, $s4, L_8000CBA0
    if (ctx->r16 != ctx->r20) {
        // 0x8000CBCC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000CBA0;
    }
    // 0x8000CBCC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000CBD0: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x8000CBD4: andi        $t0, $t9, 0xFFFB
    ctx->r8 = ctx->r25 & 0XFFFB;
    // 0x8000CBD8: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    // 0x8000CBDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000CBE0:
    // 0x8000CBE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000CBE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000CBE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000CBEC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000CBF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000CBF4: jr          $ra
    // 0x8000CBF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000CBF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806744E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806744E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806744E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806744E8: jal         0x806741B8
    // 0x806744EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806741B8(rdram, ctx);
        goto after_0;
    // 0x806744EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806744F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806744F4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x806744F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806744FC: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80674500: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80674504: blez        $v0, L_80674514
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80674508: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80674514;
    }
    // 0x80674508: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8067450C: b           L_80674524
    // 0x80674510: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_80674524;
    // 0x80674510: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80674514:
    // 0x80674514: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x80674518: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8067451C: jal         0x806748E4
    // 0x80674520: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    func_806748E4(rdram, ctx);
        goto after_1;
    // 0x80674520: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    after_1:
L_80674524:
    // 0x80674524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80674528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067452C: jr          $ra
    // 0x80674530: nop

    return;
    // 0x80674530: nop

;}
RECOMP_FUNC void func_8064A8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A8A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064A8A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064A8AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064A8B0: lh          $t6, 0xC2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC2);
    // 0x8064A8B4: lui         $at, 0xC32E
    ctx->r1 = S32(0XC32E << 16);
    // 0x8064A8B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8064A8BC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8064A8C0: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8064A8C4: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8064A8C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064A8CC: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064A8D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064A8D4: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8064A8D8: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8064A8DC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8064A8E0: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8064A8E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064A8E8: swc1        $f10, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f10.u32l;
    // 0x8064A8EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8064A8F0: jal         0x8064A848
    // 0x8064A8F4: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    func_8064A848(rdram, ctx);
        goto after_0;
    // 0x8064A8F4: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    after_0:
    // 0x8064A8F8: bne         $v0, $zero, L_8064A910
    if (ctx->r2 != 0) {
        // 0x8064A8FC: lui         $t9, 0x8065
        ctx->r25 = S32(RELOC_HI16(495, 0X6F0) << 16);
            goto L_8064A910;
    }
    // 0x8064A8FC: lui         $t9, 0x8065
    ctx->r25 = S32(RELOC_HI16(495, 0X6F0) << 16);
    // 0x8064A900: jal         0x800445A4
    // 0x8064A904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8064A904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8064A908: b           L_8064A96C
    // 0x8064A90C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064A96C;
    // 0x8064A90C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064A910:
    // 0x8064A910: addiu       $t9, $t9, -0x5840
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(495, 0X6F0));
    // 0x8064A914: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8064A918: jal         0x8064A468
    // 0x8064A91C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A468(rdram, ctx);
        goto after_2;
    // 0x8064A91C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064A920: jal         0x8064A88C
    // 0x8064A924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A88C(rdram, ctx);
        goto after_3;
    // 0x8064A924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8064A928: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8064A92C: lui         $t0, 0x8065
    ctx->r8 = S32(RELOC_HI16(495, 0X2DC0) << 16);
    // 0x8064A930: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8064A934: addiu       $t0, $t0, -0x3170
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(495, 0X2DC0));
    // 0x8064A938: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8064A93C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8064A940: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064A944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064A948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064A94C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064A950: jal         0x8064A97C
    // 0x8064A954: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8064A97C(rdram, ctx);
        goto after_4;
    // 0x8064A954: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8064A958: jal         0x8064A158
    // 0x8064A95C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A158(rdram, ctx);
        goto after_5;
    // 0x8064A95C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8064A960: jal         0x8064A40C
    // 0x8064A964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A40C(rdram, ctx);
        goto after_6;
    // 0x8064A964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8064A968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064A96C:
    // 0x8064A96C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064A970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064A974: jr          $ra
    // 0x8064A978: nop

    return;
    // 0x8064A978: nop

;}
RECOMP_FUNC void func_8079A890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A890: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079A894: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079A898: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8079A89C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079A8A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8079A8A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8079A8A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8079A8AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8079A8B0: jal         0x8079A860
    // 0x8079A8B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8079A860(rdram, ctx);
        goto after_0;
    // 0x8079A8B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8079A8B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079A8BC: beq         $v0, $at, L_8079A8D8
    if (ctx->r2 == ctx->r1) {
        // 0x8079A8C0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8079A8D8;
    }
    // 0x8079A8C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8079A8C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8079A8C8: beq         $v0, $at, L_8079A9F4
    if (ctx->r2 == ctx->r1) {
        // 0x8079A8CC: nop
    
            goto L_8079A9F4;
    }
    // 0x8079A8CC: nop

    // 0x8079A8D0: b           L_8079AB0C
    // 0x8079A8D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079AB0C;
    // 0x8079A8D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079A8D8:
    // 0x8079A8D8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2740) << 16);
    // 0x8079A8DC: lwc1        $f4, -0x4DA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2740));
    // 0x8079A8E0: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8079A8E4: lui         $a1, 0x3DE1
    ctx->r5 = S32(0X3DE1 << 16);
    // 0x8079A8E8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8079A8EC: nop

    // 0x8079A8F0: bc1fl       L_8079A950
    if (!c1cs) {
        // 0x8079A8F4: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_8079A950;
    }
    goto skip_0;
    // 0x8079A8F4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x8079A8F8: jal         0x8079A65C
    // 0x8079A8FC: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    func_8079A65C(rdram, ctx);
        goto after_1;
    // 0x8079A8FC: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_1:
    // 0x8079A900: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8079A904: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x8079A908: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x8079A90C: beql        $t7, $zero, L_8079A934
    if (ctx->r15 == 0) {
        // 0x8079A910: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8079A934;
    }
    goto skip_1;
    // 0x8079A910: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x8079A914: lbu         $t8, 0xF4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF4);
    // 0x8079A918: bnel        $t8, $zero, L_8079A934
    if (ctx->r24 != 0) {
        // 0x8079A91C: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8079A934;
    }
    goto skip_2;
    // 0x8079A91C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_2:
    // 0x8079A920: jal         0x8002F9D4
    // 0x8079A924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F9D4(rdram, ctx);
        goto after_2;
    // 0x8079A924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8079A928: b           L_8079A964
    // 0x8079A92C: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
        goto L_8079A964;
    // 0x8079A92C: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x8079A930: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8079A934:
    // 0x8079A934: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8079A938: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x8079A93C: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x8079A940: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8079A944: b           L_8079A960
    // 0x8079A948: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
        goto L_8079A960;
    // 0x8079A948: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x8079A94C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8079A950:
    // 0x8079A950: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8079A954: lw          $t1, 0x34($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X34);
    // 0x8079A958: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8079A95C: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
L_8079A960:
    // 0x8079A960: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
L_8079A964:
    // 0x8079A964: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8079A968: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x8079A96C: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x8079A970: bne         $t4, $zero, L_8079AB08
    if (ctx->r12 != 0) {
        // 0x8079A974: lui         $at, 0xF
        ctx->r1 = S32(0XF << 16);
            goto L_8079AB08;
    }
    // 0x8079A974: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8079A978: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x8079A97C: bne         $t5, $zero, L_8079AB08
    if (ctx->r13 != 0) {
        // 0x8079A980: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_8079AB08;
    }
    // 0x8079A980: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8079A984: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8079A988: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8079A98C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079A990: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8079A994: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8079A998: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8079A99C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8079A9A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8079A9A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079A9A8: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8079A9AC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8079A9B0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8079A9B4: nop

    // 0x8079A9B8: bc1fl       L_8079A9CC
    if (!c1cs) {
        // 0x8079A9BC: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8079A9CC;
    }
    goto skip_3;
    // 0x8079A9BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_3:
    // 0x8079A9C0: b           L_8079A9E4
    // 0x8079A9C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8079A9E4;
    // 0x8079A9C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8079A9C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8079A9CC:
    // 0x8079A9CC: nop

    // 0x8079A9D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8079A9D4: nop

    // 0x8079A9D8: bc1fl       L_8079A9E8
    if (!c1cs) {
        // 0x8079A9DC: lwc1        $f6, 0x3C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_8079A9E8;
    }
    goto skip_4;
    // 0x8079A9DC: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    skip_4:
    // 0x8079A9E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8079A9E4:
    // 0x8079A9E4: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
L_8079A9E8:
    // 0x8079A9E8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8079A9EC: b           L_8079AB08
    // 0x8079A9F0: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
        goto L_8079AB08;
    // 0x8079A9F0: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
L_8079A9F4:
    // 0x8079A9F4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2744) << 16);
    // 0x8079A9F8: lwc1        $f16, -0x4D9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2744));
    // 0x8079A9FC: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8079AA00: lui         $a1, 0xBDE1
    ctx->r5 = S32(0XBDE1 << 16);
    // 0x8079AA04: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8079AA08: nop

    // 0x8079AA0C: bc1fl       L_8079AA6C
    if (!c1cs) {
        // 0x8079AA10: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_8079AA6C;
    }
    goto skip_5;
    // 0x8079AA10: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_5:
    // 0x8079AA14: jal         0x8079A65C
    // 0x8079AA18: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    func_8079A65C(rdram, ctx);
        goto after_3;
    // 0x8079AA18: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_3:
    // 0x8079AA1C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8079AA20: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x8079AA24: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x8079AA28: beql        $t9, $zero, L_8079AA50
    if (ctx->r25 == 0) {
        // 0x8079AA2C: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8079AA50;
    }
    goto skip_6;
    // 0x8079AA2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_6:
    // 0x8079AA30: lbu         $t0, 0xF4($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF4);
    // 0x8079AA34: bnel        $t0, $zero, L_8079AA50
    if (ctx->r8 != 0) {
        // 0x8079AA38: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8079AA50;
    }
    goto skip_7;
    // 0x8079AA38: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_7:
    // 0x8079AA3C: jal         0x8002F9D4
    // 0x8079AA40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F9D4(rdram, ctx);
        goto after_4;
    // 0x8079AA40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8079AA44: b           L_8079AA80
    // 0x8079AA48: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
        goto L_8079AA80;
    // 0x8079AA48: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x8079AA4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_8079AA50:
    // 0x8079AA50: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8079AA54: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x8079AA58: lw          $t1, 0x34($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X34);
    // 0x8079AA5C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8079AA60: b           L_8079AA7C
    // 0x8079AA64: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
        goto L_8079AA7C;
    // 0x8079AA64: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x8079AA68: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8079AA6C:
    // 0x8079AA6C: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8079AA70: lw          $t3, 0x34($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X34);
    // 0x8079AA74: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8079AA78: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
L_8079AA7C:
    // 0x8079AA7C: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
L_8079AA80:
    // 0x8079AA80: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8079AA84: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x8079AA88: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8079AA8C: bne         $t6, $zero, L_8079AB08
    if (ctx->r14 != 0) {
        // 0x8079AA90: lui         $at, 0xF
        ctx->r1 = S32(0XF << 16);
            goto L_8079AB08;
    }
    // 0x8079AA90: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8079AA94: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x8079AA98: bne         $t7, $zero, L_8079AB08
    if (ctx->r15 != 0) {
        // 0x8079AA9C: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_8079AB08;
    }
    // 0x8079AA9C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8079AAA0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8079AAA4: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8079AAA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079AAAC: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8079AAB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8079AAB4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8079AAB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8079AABC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8079AAC0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079AAC4: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8079AAC8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8079AACC: nop

    // 0x8079AAD0: bc1fl       L_8079AAE4
    if (!c1cs) {
        // 0x8079AAD4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8079AAE4;
    }
    goto skip_8;
    // 0x8079AAD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_8:
    // 0x8079AAD8: b           L_8079AAFC
    // 0x8079AADC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8079AAFC;
    // 0x8079AADC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8079AAE0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8079AAE4:
    // 0x8079AAE4: nop

    // 0x8079AAE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8079AAEC: nop

    // 0x8079AAF0: bc1fl       L_8079AB00
    if (!c1cs) {
        // 0x8079AAF4: lwc1        $f16, 0x3C($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_8079AB00;
    }
    goto skip_9;
    // 0x8079AAF4: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    skip_9:
    // 0x8079AAF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8079AAFC:
    // 0x8079AAFC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
L_8079AB00:
    // 0x8079AB00: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8079AB04: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
L_8079AB08:
    // 0x8079AB08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079AB0C:
    // 0x8079AB0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079AB10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079AB14: jr          $ra
    // 0x8079AB18: nop

    return;
    // 0x8079AB18: nop

;}
RECOMP_FUNC void func_80460634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460634: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80460638: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046063C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80460640: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80460644: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x80460648: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8046064C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80460650: bne         $a2, $at, L_80460674
    if (ctx->r6 != ctx->r1) {
        // 0x80460654: sll         $a1, $a2, 16
        ctx->r5 = S32(ctx->r6 << 16);
            goto L_80460674;
    }
    // 0x80460654: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80460658: jal         0x80067E78
    // 0x8046065C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067E78(rdram, ctx);
        goto after_0;
    // 0x8046065C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80460660: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80460664: jal         0x80067F78
    // 0x80460668: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80460668: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8046066C: b           L_804606C8
    // 0x80460670: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_804606C8;
    // 0x80460670: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_80460674:
    // 0x80460674: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80460678: jal         0x80067930
    // 0x8046067C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x8046067C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_2:
    // 0x80460680: beq         $v0, $zero, L_804606B0
    if (ctx->r2 == 0) {
        // 0x80460684: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_804606B0;
    }
    // 0x80460684: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80460688: bnel        $v0, $at, L_804606CC
    if (ctx->r2 != ctx->r1) {
        // 0x8046068C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804606CC;
    }
    goto skip_0;
    // 0x8046068C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80460690: jal         0x80067E78
    // 0x80460694: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_3;
    // 0x80460694: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x80460698: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8046069C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x804606A0: jal         0x800678F0
    // 0x804606A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x804606A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x804606A8: b           L_804606CC
    // 0x804606AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804606CC;
    // 0x804606AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804606B0:
    // 0x804606B0: jal         0x80067E78
    // 0x804606B4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_5;
    // 0x804606B4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x804606B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804606BC: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x804606C0: jal         0x80067838
    // 0x804606C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x804606C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_804606C8:
    // 0x804606C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804606CC:
    // 0x804606CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804606D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804606D4: jr          $ra
    // 0x804606D8: nop

    return;
    // 0x804606D8: nop

;}
RECOMP_FUNC void func_8001A3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A3E8: beq         $a0, $zero, L_8001A418
    if (ctx->r4 == 0) {
        // 0x8001A3EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8001A418;
    }
    // 0x8001A3EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A3F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001A3F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001A3F8: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x8001A3FC: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    // 0x8001A400: sh          $zero, 0x22($a0)
    MEM_H(0X22, ctx->r4) = 0;
    // 0x8001A404: sh          $zero, 0x32($a0)
    MEM_H(0X32, ctx->r4) = 0;
    // 0x8001A408: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // 0x8001A40C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8001A410: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001A414: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
L_8001A418:
    // 0x8001A418: jr          $ra
    // 0x8001A41C: nop

    return;
    // 0x8001A41C: nop

;}
RECOMP_FUNC void func_8005DB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DB34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8005DB38: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x8005DB3C: lbu         $t6, 0xA80($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XA80);
    // 0x8005DB40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DB44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005DB48: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005DB4C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8005DB50: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8005DB54: bne         $at, $zero, L_8005DB60
    if (ctx->r1 != 0) {
        // 0x8005DB58: sb          $t7, 0xA80($a0)
        MEM_B(0XA80, ctx->r4) = ctx->r15;
            goto L_8005DB60;
    }
    // 0x8005DB58: sb          $t7, 0xA80($a0)
    MEM_B(0XA80, ctx->r4) = ctx->r15;
    // 0x8005DB5C: sb          $zero, 0xA80($a0)
    MEM_B(0XA80, ctx->r4) = 0;
L_8005DB60:
    // 0x8005DB60: jal         0x8005DAE4
    // 0x8005DB64: nop

    func_8005DAE4(rdram, ctx);
        goto after_0;
    // 0x8005DB64: nop

    after_0:
    // 0x8005DB68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005DB6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005DB70: jr          $ra
    // 0x8005DB74: nop

    return;
    // 0x8005DB74: nop

;}
RECOMP_FUNC void func_80048C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048C18: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80048C1C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80048C20: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x80048C24: jr          $ra
    // 0x80048C28: swc1        $f14, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x80048C28: swc1        $f14, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_807882CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807882CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807882D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807882D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807882D8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807882DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807882E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807882E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807882E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807882EC: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x807882F0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x807882F4: lh          $t6, 0x52C6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X52C6);
    // 0x807882F8: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x807882FC: beql        $t6, $zero, L_80788310
    if (ctx->r14 == 0) {
        // 0x80788300: lw          $v0, 0xED0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0XED0);
            goto L_80788310;
    }
    goto skip_0;
    // 0x80788300: lw          $v0, 0xED0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XED0);
    skip_0:
    // 0x80788304: b           L_80788380
    // 0x80788308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80788380;
    // 0x80788308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8078830C: lw          $v0, 0xED0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XED0);
L_80788310:
    // 0x80788310: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80788314: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80788318: lbu         $t7, 0x41($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X41);
    // 0x8078831C: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x80788320: beql        $t7, $zero, L_80788380
    if (ctx->r15 == 0) {
        // 0x80788324: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_80788380;
    }
    goto skip_1;
    // 0x80788324: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    skip_1:
    // 0x80788328: sb          $s3, 0x42($v0)
    MEM_B(0X42, ctx->r2) = ctx->r19;
    // 0x8078832C: lw          $t8, 0xED0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XED0);
L_80788330:
    // 0x80788330: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80788334: lw          $a0, 0x38($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X38);
    // 0x80788338: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8078833C: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x80788340: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x80788344: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80788348: bne         $at, $zero, L_80788358
    if (ctx->r1 != 0) {
        // 0x8078834C: addiu       $t0, $v1, -0x4
        ctx->r8 = ADD32(ctx->r3, -0X4);
            goto L_80788358;
    }
    // 0x8078834C: addiu       $t0, $v1, -0x4
    ctx->r8 = ADD32(ctx->r3, -0X4);
    // 0x80788350: b           L_80788370
    // 0x80788354: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
        goto L_80788370;
    // 0x80788354: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
L_80788358:
    // 0x80788358: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x8078835C: lw          $t1, 0xED0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XED0);
    // 0x80788360: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80788364: sb          $zero, 0x42($t1)
    MEM_B(0X42, ctx->r9) = 0;
    // 0x80788368: jal         0x80048D4C
    // 0x8078836C: sb          $s3, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r19;
    func_80048D4C(rdram, ctx);
        goto after_0;
    // 0x8078836C: sb          $s3, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r19;
    after_0:
L_80788370:
    // 0x80788370: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80788374: bnel        $s0, $s2, L_80788330
    if (ctx->r16 != ctx->r18) {
        // 0x80788378: lw          $t8, 0xED0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0XED0);
            goto L_80788330;
    }
    goto skip_2;
    // 0x80788378: lw          $t8, 0xED0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XED0);
    skip_2:
    // 0x8078837C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80788380:
    // 0x80788380: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80788384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80788388: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8078838C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80788390: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80788394: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80788398: jr          $ra
    // 0x8078839C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8078839C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80737B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737B98: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80737B9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80737BA0: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80737BA4: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80737BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80737BAC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80737BB0: nop

    // 0x80737BB4: bc1f        L_80737BC0
    if (!c1cs) {
        // 0x80737BB8: nop
    
            goto L_80737BC0;
    }
    // 0x80737BB8: nop

    // 0x80737BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80737BC0:
    // 0x80737BC0: bne         $v0, $zero, L_80737BE4
    if (ctx->r2 != 0) {
        // 0x80737BC4: nop
    
            goto L_80737BE4;
    }
    // 0x80737BC4: nop

    // 0x80737BC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80737BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80737BD0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80737BD4: nop

    // 0x80737BD8: bc1f        L_80737BE4
    if (!c1cs) {
        // 0x80737BDC: nop
    
            goto L_80737BE4;
    }
    // 0x80737BDC: nop

    // 0x80737BE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80737BE4:
    // 0x80737BE4: jr          $ra
    // 0x80737BE8: nop

    return;
    // 0x80737BE8: nop

;}
RECOMP_FUNC void func_80447744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447744: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447748: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8044774C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447750: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447754: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447758: bne         $a2, $zero, L_804477A4
    if (ctx->r6 != 0) {
        // 0x8044775C: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_804477A4;
    }
    // 0x8044775C: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x80447760: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80447764: lw          $v0, 0x38($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X38);
    // 0x80447768: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8044776C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80447770: beq         $at, $zero, L_80447780
    if (ctx->r1 == 0) {
        // 0x80447774: addu        $t7, $a1, $a3
        ctx->r15 = ADD32(ctx->r5, ctx->r7);
            goto L_80447780;
    }
    // 0x80447774: addu        $t7, $a1, $a3
    ctx->r15 = ADD32(ctx->r5, ctx->r7);
    // 0x80447778: b           L_804477E8
    // 0x8044777C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_804477E8;
    // 0x8044777C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80447780:
    // 0x80447780: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447784: jal         0x8044610C
    // 0x80447788: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044610C(rdram, ctx);
        goto after_0;
    // 0x80447788: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044778C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80447790: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447794: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80447798: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8044779C: b           L_804477E8
    // 0x804477A0: sw          $t8, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r24;
        goto L_804477E8;
    // 0x804477A0: sw          $t8, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r24;
L_804477A4:
    // 0x804477A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804477A8: bne         $a2, $at, L_804477D0
    if (ctx->r6 != ctx->r1) {
        // 0x804477AC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_804477D0;
    }
    // 0x804477AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804477B0: jal         0x8044610C
    // 0x804477B4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044610C(rdram, ctx);
        goto after_1;
    // 0x804477B4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x804477B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804477BC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804477C0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x804477C4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804477C8: b           L_804477E8
    // 0x804477CC: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_804477E8;
    // 0x804477CC: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_804477D0:
    // 0x804477D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804477D4: bne         $a2, $at, L_804477E8
    if (ctx->r6 != ctx->r1) {
        // 0x804477D8: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_804477E8;
    }
    // 0x804477D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804477DC: jal         0x80446164
    // 0x804477E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80446164(rdram, ctx);
        goto after_2;
    // 0x804477E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x804477E4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_804477E8:
    // 0x804477E8: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x804477EC: jal         0x804475C0
    // 0x804477F0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_804475C0(rdram, ctx);
        goto after_3;
    // 0x804477F0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x804477F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804477F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804477FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447800: jr          $ra
    // 0x80447804: nop

    return;
    // 0x80447804: nop

;}
RECOMP_FUNC void func_804D8FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D8FF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D8FFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D9000: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x804D9004: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x804D9008: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x804D900C: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x804D9010: bne         $at, $zero, L_804D9060
    if (ctx->r1 != 0) {
        // 0x804D9014: sw          $v0, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->r2;
            goto L_804D9060;
    }
    // 0x804D9014: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x804D9018: lw          $v0, 0x34($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X34);
    // 0x804D901C: blez        $v0, L_804D902C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x804D9020: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_804D902C;
    }
    // 0x804D9020: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x804D9024: sw          $t9, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r25;
    // 0x804D9028: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_804D902C:
    // 0x804D902C: bne         $v0, $zero, L_804D9058
    if (ctx->r2 != 0) {
        // 0x804D9030: nop
    
            goto L_804D9058;
    }
    // 0x804D9030: nop

    // 0x804D9034: jal         0x804D8FDC
    // 0x804D9038: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_804D8FDC(rdram, ctx);
        goto after_0;
    // 0x804D9038: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x804D903C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D9040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D9044: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804D9048: jal         0x804D9108
    // 0x804D904C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_804D9108(rdram, ctx);
        goto after_1;
    // 0x804D904C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x804D9050: b           L_804D907C
    // 0x804D9054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804D907C;
    // 0x804D9054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D9058:
    // 0x804D9058: b           L_804D9078
    // 0x804D905C: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
        goto L_804D9078;
    // 0x804D905C: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
L_804D9060:
    // 0x804D9060: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x804D9064: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x804D9068: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x804D906C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x804D9070: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x804D9074: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_804D9078:
    // 0x804D9078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D907C:
    // 0x804D907C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D9080: jr          $ra
    // 0x804D9084: nop

    return;
    // 0x804D9084: nop

;}
RECOMP_FUNC void func_806E3FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3FE4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x806E3FE8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x806E3FEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806E3FF0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E3FF4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x806E3FF8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x806E3FFC: bc1fl       L_806E4014
    if (!c1cs) {
        // 0x806E4000: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_806E4014;
    }
    goto skip_0;
    // 0x806E4000: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x806E4004: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806E4008: nop

    // 0x806E400C: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x806E4010: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_806E4014:
    // 0x806E4014: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806E4018: nop

    // 0x806E401C: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x806E4020: nop

    // 0x806E4024: bc1fl       L_806E4034
    if (!c1cs) {
        // 0x806E4028: lwc1        $f0, 0xC($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
            goto L_806E4034;
    }
    goto skip_1;
    // 0x806E4028: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    skip_1:
    // 0x806E402C: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x806E4030: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
L_806E4034:
    // 0x806E4034: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x806E4038: nop

    // 0x806E403C: bc1fl       L_806E40E0
    if (!c1cs) {
        // 0x806E4040: lwc1        $f2, 0x50($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
            goto L_806E40E0;
    }
    goto skip_2;
    // 0x806E4040: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    skip_2:
    // 0x806E4044: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806E4048: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806E404C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806E4050: nop

    // 0x806E4054: bc1fl       L_806E4098
    if (!c1cs) {
        // 0x806E4058: sub.s       $f0, $f12, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_806E4098;
    }
    goto skip_3;
    // 0x806E4058: sub.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
    skip_3:
    // 0x806E405C: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x806E4060: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806E4064: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806E4068: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806E406C: nop

    // 0x806E4070: bc1fl       L_806E408C
    if (!c1cs) {
        // 0x806E4074: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_806E408C;
    }
    goto skip_4;
    // 0x806E4074: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x806E4078: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806E407C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806E4080: b           L_806E40D4
    // 0x806E4084: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
        goto L_806E40D4;
    // 0x806E4084: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x806E4088: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_806E408C:
    // 0x806E408C: b           L_806E40D4
    // 0x806E4090: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
        goto L_806E40D4;
    // 0x806E4090: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x806E4094: sub.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
L_806E4098:
    // 0x806E4098: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806E409C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E40A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806E40A4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E40A8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806E40AC: nop

    // 0x806E40B0: bc1fl       L_806E40CC
    if (!c1cs) {
        // 0x806E40B4: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_806E40CC;
    }
    goto skip_5;
    // 0x806E40B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_5:
    // 0x806E40B8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806E40BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E40C0: b           L_806E40D4
    // 0x806E40C4: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
        goto L_806E40D4;
    // 0x806E40C4: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x806E40C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_806E40CC:
    // 0x806E40CC: nop

    // 0x806E40D0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
L_806E40D4:
    // 0x806E40D4: jr          $ra
    // 0x806E40D8: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    return;
    // 0x806E40D8: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x806E40DC: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
L_806E40E0:
    // 0x806E40E0: add.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x806E40E4: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x806E40E8: nop

    // 0x806E40EC: bc1fl       L_806E40FC
    if (!c1cs) {
        // 0x806E40F0: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_806E40FC;
    }
    goto skip_6;
    // 0x806E40F0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_6:
    // 0x806E40F4: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x806E40F8: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_806E40FC:
    // 0x806E40FC: nop

    // 0x806E4100: bc1fl       L_806E4110
    if (!c1cs) {
        // 0x806E4104: lwc1        $f10, 0x10($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
            goto L_806E4110;
    }
    goto skip_7;
    // 0x806E4104: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    skip_7:
    // 0x806E4108: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x806E410C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
L_806E4110:
    // 0x806E4110: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806E4114: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806E4118: sub.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x806E411C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E4120: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x806E4124: nop

    // 0x806E4128: bc1fl       L_806E413C
    if (!c1cs) {
        // 0x806E412C: swc1        $f12, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
            goto L_806E413C;
    }
    goto skip_8;
    // 0x806E412C: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    skip_8:
    // 0x806E4130: jr          $ra
    // 0x806E4134: swc1        $f14, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f14.u32l;
    return;
    // 0x806E4134: swc1        $f14, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f14.u32l;
    // 0x806E4138: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
L_806E413C:
    // 0x806E413C: jr          $ra
    // 0x806E4140: nop

    return;
    // 0x806E4140: nop

;}
RECOMP_FUNC void func_80427D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427DA0: jal         0x80427BEC
    // 0x80427DA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80427BEC(rdram, ctx);
        goto after_0;
    // 0x80427DA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80427DA8: jal         0x80427D4C
    // 0x80427DAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80427D4C(rdram, ctx);
        goto after_1;
    // 0x80427DAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80427DB0: jal         0x80045BD8
    // 0x80427DB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_2;
    // 0x80427DB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80427DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427DC0: jr          $ra
    // 0x80427DC4: nop

    return;
    // 0x80427DC4: nop

;}
RECOMP_FUNC void func_80703E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703E8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80703E90: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80703E94: beq         $at, $zero, L_80703EA4
    if (ctx->r1 == 0) {
        // 0x80703E98: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80703EA4;
    }
    // 0x80703E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80703E9C: b           L_80703F00
    // 0x80703EA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80703F00;
    // 0x80703EA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80703EA4:
    // 0x80703EA4: bnel        $a0, $a1, L_80703EB8
    if (ctx->r4 != ctx->r5) {
        // 0x80703EA8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80703EB8;
    }
    goto skip_0;
    // 0x80703EA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80703EAC: b           L_80703F00
    // 0x80703EB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80703F00;
    // 0x80703EB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80703EB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80703EB8:
    // 0x80703EB8: jal         0x800653D8
    // 0x80703EBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80703EBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80703EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80703EC4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80703EC8: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x80703ECC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80703ED0: div         $zero, $v0, $t7
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r15)));
    // 0x80703ED4: mfhi        $t8
    ctx->r24 = hi;
    // 0x80703ED8: bne         $t7, $zero, L_80703EE4
    if (ctx->r15 != 0) {
        // 0x80703EDC: nop
    
            goto L_80703EE4;
    }
    // 0x80703EDC: nop

    // 0x80703EE0: break       7
    do_break(2154839776);
L_80703EE4:
    // 0x80703EE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80703EE8: bne         $t7, $at, L_80703EFC
    if (ctx->r15 != ctx->r1) {
        // 0x80703EEC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80703EFC;
    }
    // 0x80703EEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80703EF0: bne         $v0, $at, L_80703EFC
    if (ctx->r2 != ctx->r1) {
        // 0x80703EF4: nop
    
            goto L_80703EFC;
    }
    // 0x80703EF4: nop

    // 0x80703EF8: break       6
    do_break(2154839800);
L_80703EFC:
    // 0x80703EFC: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
L_80703F00:
    // 0x80703F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80703F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80703F08: jr          $ra
    // 0x80703F0C: nop

    return;
    // 0x80703F0C: nop

;}
RECOMP_FUNC void func_80735AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735AE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80735AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80735AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80735AF4: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x80735AF8: nop

    // 0x80735AFC: bc1fl       L_80735B10
    if (!c1cs) {
        // 0x80735B00: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_80735B10;
    }
    goto skip_0;
    // 0x80735B00: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x80735B04: b           L_80735B34
    // 0x80735B08: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80735B34;
    // 0x80735B08: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80735B0C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_80735B10:
    // 0x80735B10: jal         0x80065414
    // 0x80735B14: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x80735B14: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80735B18: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x80735B1C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80735B20: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80735B24: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80735B28: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80735B2C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80735B30: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_80735B34:
    // 0x80735B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80735B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80735B3C: jr          $ra
    // 0x80735B40: nop

    return;
    // 0x80735B40: nop

;}
RECOMP_FUNC void func_806AAC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AAC54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AAC58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AAC5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806AAC60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806AAC64: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806AAC68: jal         0x80067BBC
    // 0x806AAC6C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806AAC6C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806AAC70: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806AAC74: jal         0x80067818
    // 0x806AAC78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806AAC78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806AAC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AAC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AAC84: jr          $ra
    // 0x806AAC88: nop

    return;
    // 0x806AAC88: nop

;}
RECOMP_FUNC void func_80453AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453ACC: jal         0x804539F0
    // 0x80453AD0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_804539F0(rdram, ctx);
        goto after_0;
    // 0x80453AD0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80453AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453ADC: jr          $ra
    // 0x80453AE0: nop

    return;
    // 0x80453AE0: nop

;}
RECOMP_FUNC void func_804CC9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC9B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CC9B4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x804CC9B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804CC9BC: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x804CC9C0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x804CC9C4: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x804CC9C8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x804CC9CC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x804CC9D0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x804CC9D4: beq         $a1, $zero, L_804CCA14
    if (ctx->r5 == 0) {
        // 0x804CC9D8: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_804CCA14;
    }
    // 0x804CC9D8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x804CC9DC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x804CC9E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804CC9E4: nop

L_804CC9E8:
    // 0x804CC9E8: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x804CC9EC: swc1        $f12, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f12.u32l;
    // 0x804CC9F0: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x804CC9F4: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x804CC9F8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x804CC9FC: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x804CCA00: sltu        $at, $t0, $t6
    ctx->r1 = ctx->r8 < ctx->r14 ? 1 : 0;
    // 0x804CCA04: bne         $at, $zero, L_804CC9E8
    if (ctx->r1 != 0) {
        // 0x804CCA08: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_804CC9E8;
    }
    // 0x804CCA08: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x804CCA0C: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x804CCA10: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_804CCA14:
    // 0x804CCA14: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x804CCA18: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x804CCA1C: addu        $a1, $a3, $t7
    ctx->r5 = ADD32(ctx->r7, ctx->r15);
    // 0x804CCA20: srl         $a0, $v1, 1
    ctx->r4 = S32(U32(ctx->r3) >> 1);
    // 0x804CCA24: beq         $a0, $zero, L_804CCAAC
    if (ctx->r4 == 0) {
        // 0x804CCA28: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_804CCAAC;
    }
    // 0x804CCA28: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x804CCA2C: andi        $v1, $a0, 0x3
    ctx->r3 = ctx->r4 & 0X3;
    // 0x804CCA30: beq         $v1, $zero, L_804CCA60
    if (ctx->r3 == 0) {
        // 0x804CCA34: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_804CCA60;
    }
    // 0x804CCA34: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x804CCA38: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CCA3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_804CCA40:
    // 0x804CCA40: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x804CCA44: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x804CCA48: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x804CCA4C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804CCA50: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x804CCA54: bne         $v0, $t0, L_804CCA40
    if (ctx->r2 != ctx->r8) {
        // 0x804CCA58: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_804CCA40;
    }
    // 0x804CCA58: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x804CCA5C: beq         $t0, $a0, L_804CCAAC
    if (ctx->r8 == ctx->r4) {
        // 0x804CCA60: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_804CCAAC;
    }
L_804CCA60:
    // 0x804CCA60: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x804CCA64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CCA68: nop

L_804CCA6C:
    // 0x804CCA6C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x804CCA70: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x804CCA74: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804CCA78: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x804CCA7C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x804CCA80: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x804CCA84: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x804CCA88: swc1        $f0, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f0.u32l;
    // 0x804CCA8C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804CCA90: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x804CCA94: swc1        $f0, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f0.u32l;
    // 0x804CCA98: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804CCA9C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x804CCAA0: swc1        $f0, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f0.u32l;
    // 0x804CCAA4: bne         $t0, $a0, L_804CCA6C
    if (ctx->r8 != ctx->r4) {
        // 0x804CCAA8: add.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_804CCA6C;
    }
    // 0x804CCAA8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_804CCAAC:
    // 0x804CCAAC: jr          $ra
    // 0x804CCAB0: nop

    return;
    // 0x804CCAB0: nop

;}
RECOMP_FUNC void func_804D2DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2DD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804D2DDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804D2DE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804D2DE4: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x804D2DE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804D2DEC: lbu         $a0, 0x10($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X10);
    // 0x804D2DF0: jal         0x804D2DB4
    // 0x804D2DF4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804D2DB4(rdram, ctx);
        goto after_0;
    // 0x804D2DF4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x804D2DF8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804D2DFC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804D2E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804D2E04: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    // 0x804D2E08: jal         0x80048F84
    // 0x804D2E0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804D2E0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x804D2E10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804D2E14: jal         0x80048F84
    // 0x804D2E18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x804D2E18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x804D2E1C: jal         0x804D2C18
    // 0x804D2E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804D2C18(rdram, ctx);
        goto after_3;
    // 0x804D2E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804D2E24: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x804D2E28: bne         $v0, $at, L_804D2E4C
    if (ctx->r2 != ctx->r1) {
        // 0x804D2E2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804D2E4C;
    }
    // 0x804D2E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804D2E30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804D2E34: sb          $v0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r2;
    // 0x804D2E38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804D2E3C: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x804D2E40: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x804D2E44: jal         0x804D2E60
    // 0x804D2E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804D2E60(rdram, ctx);
        goto after_4;
    // 0x804D2E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_804D2E4C:
    // 0x804D2E4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804D2E50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804D2E54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804D2E58: jr          $ra
    // 0x804D2E5C: nop

    return;
    // 0x804D2E5C: nop

;}
RECOMP_FUNC void func_80067E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067E2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067E30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067E34: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80067E38: jal         0x80067BBC
    // 0x80067E3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067E3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80067E40: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067E44: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067E48: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067E4C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80067E50: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80067E54: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x80067E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067E60: jr          $ra
    // 0x80067E64: nop

    return;
    // 0x80067E64: nop

;}
RECOMP_FUNC void func_8040D59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D59C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040D5A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8040D5A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040D5A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040D5AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8040D5B0: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D5B4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8040D5B8: jal         0x80048F84
    // 0x8040D5BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8040D5BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8040D5C0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8040D5C4: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8040D5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D5CC: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8040D5D0: nop

    // 0x8040D5D4: bc1f        L_8040D628
    if (!c1cs) {
        // 0x8040D5D8: nop
    
            goto L_8040D628;
    }
    // 0x8040D5D8: nop

    // 0x8040D5DC: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8040D5E0: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    // 0x8040D5E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8040D5E8: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8040D5EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040D5F0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8040D5F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D5F8: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x8040D5FC: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8040D600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D604: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8040D608: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8040D60C: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x8040D610: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040D614: swc1        $f12, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f12.u32l;
    // 0x8040D618: jal         0x8040E254
    // 0x8040D61C: swc1        $f12, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f12.u32l;
    func_8040E254(rdram, ctx);
        goto after_1;
    // 0x8040D61C: swc1        $f12, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f12.u32l;
    after_1:
    // 0x8040D620: b           L_8040D664
    // 0x8040D624: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
        goto L_8040D664;
    // 0x8040D624: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
L_8040D628:
    // 0x8040D628: jal         0x8040CBE8
    // 0x8040D62C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8040CBE8(rdram, ctx);
        goto after_2;
    // 0x8040D62C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8040D630: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040D634: bne         $v0, $at, L_8040D644
    if (ctx->r2 != ctx->r1) {
        // 0x8040D638: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8040D644;
    }
    // 0x8040D638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D63C: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8040D640: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
L_8040D644:
    // 0x8040D644: jal         0x8040CBE8
    // 0x8040D648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8040CBE8(rdram, ctx);
        goto after_3;
    // 0x8040D648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8040D64C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040D650: bnel        $v0, $at, L_8040D664
    if (ctx->r2 != ctx->r1) {
        // 0x8040D654: lw          $t6, 0x2C($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X2C);
            goto L_8040D664;
    }
    goto skip_0;
    // 0x8040D654: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
    skip_0:
    // 0x8040D658: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8040D65C: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8040D660: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
L_8040D664:
    // 0x8040D664: beql        $t6, $zero, L_8040D6B0
    if (ctx->r14 == 0) {
        // 0x8040D668: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040D6B0;
    }
    goto skip_1;
    // 0x8040D668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8040D66C: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8040D670: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8040D674: nop

    // 0x8040D678: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8040D67C: nop

    // 0x8040D680: bc1fl       L_8040D6B0
    if (!c1cs) {
        // 0x8040D684: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040D6B0;
    }
    goto skip_2;
    // 0x8040D684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8040D688: lwc1        $f10, 0xD4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x8040D68C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8040D690: nop

    // 0x8040D694: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8040D698: nop

    // 0x8040D69C: bc1fl       L_8040D6B0
    if (!c1cs) {
        // 0x8040D6A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040D6B0;
    }
    goto skip_3;
    // 0x8040D6A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8040D6A4: jal         0x8040D0EC
    // 0x8040D6A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040D0EC(rdram, ctx);
        goto after_4;
    // 0x8040D6A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8040D6AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040D6B0:
    // 0x8040D6B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8040D6B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8040D6B8: jr          $ra
    // 0x8040D6BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8040D6BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8079ABE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079ABE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079ABE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079ABEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079ABF0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8079ABF4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8079ABF8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8079ABFC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8079AC00: beq         $v0, $at, L_8079AC18
    if (ctx->r2 == ctx->r1) {
        // 0x8079AC04: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_8079AC18;
    }
    // 0x8079AC04: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8079AC08: beq         $v0, $at, L_8079AC80
    if (ctx->r2 == ctx->r1) {
        // 0x8079AC0C: nop
    
            goto L_8079AC80;
    }
    // 0x8079AC0C: nop

    // 0x8079AC10: b           L_8079AC8C
    // 0x8079AC14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079AC8C;
    // 0x8079AC14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079AC18:
    // 0x8079AC18: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x8079AC1C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8079AC20: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8079AC24: beq         $v0, $at, L_8079AC38
    if (ctx->r2 == ctx->r1) {
        // 0x8079AC28: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8079AC38;
    }
    // 0x8079AC28: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8079AC2C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8079AC30: bnel        $v0, $at, L_8079AC4C
    if (ctx->r2 != ctx->r1) {
        // 0x8079AC34: lw          $t6, 0x1F4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1F4);
            goto L_8079AC4C;
    }
    goto skip_0;
    // 0x8079AC34: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
L_8079AC38:
    // 0x8079AC38: jal         0x8079A6CC
    // 0x8079AC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079A6CC(rdram, ctx);
        goto after_0;
    // 0x8079AC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8079AC40: b           L_8079AC8C
    // 0x8079AC44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079AC8C;
    // 0x8079AC44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079AC48: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
L_8079AC4C:
    // 0x8079AC4C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8079AC50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8079AC54: lbu         $t7, 0x111($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X111);
    // 0x8079AC58: beq         $t7, $zero, L_8079AC70
    if (ctx->r15 == 0) {
        // 0x8079AC5C: nop
    
            goto L_8079AC70;
    }
    // 0x8079AC5C: nop

    // 0x8079AC60: jal         0x8079AB1C
    // 0x8079AC64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8079AB1C(rdram, ctx);
        goto after_1;
    // 0x8079AC64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8079AC68: b           L_8079AC8C
    // 0x8079AC6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079AC8C;
    // 0x8079AC6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079AC70:
    // 0x8079AC70: jal         0x8079A890
    // 0x8079AC74: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_8079A890(rdram, ctx);
        goto after_2;
    // 0x8079AC74: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8079AC78: b           L_8079AC8C
    // 0x8079AC7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079AC8C;
    // 0x8079AC7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079AC80:
    // 0x8079AC80: jal         0x8079A7F8
    // 0x8079AC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079A7F8(rdram, ctx);
        goto after_3;
    // 0x8079AC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8079AC88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079AC8C:
    // 0x8079AC8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079AC90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079AC94: jr          $ra
    // 0x8079AC98: nop

    return;
    // 0x8079AC98: nop

;}
RECOMP_FUNC void func_80445D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445D10: jal         0x80445A34
    // 0x80445D14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80445A34(rdram, ctx);
        goto after_0;
    // 0x80445D14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80445D18: jal         0x80445CC4
    // 0x80445D1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80445CC4(rdram, ctx);
        goto after_1;
    // 0x80445D1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80445D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445D24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445D28: jr          $ra
    // 0x80445D2C: nop

    return;
    // 0x80445D2C: nop

;}
RECOMP_FUNC void func_804411A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804411A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804411A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804411A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804411AC: jal         0x8004700C
    // 0x804411B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804411B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804411B4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x804411B8: beq         $v0, $zero, L_804412A8
    if (ctx->r2 == 0) {
        // 0x804411BC: lw          $v1, 0x1F4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1F4);
            goto L_804412A8;
    }
    // 0x804411BC: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x804411C0: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x804411C4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x804411C8: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x804411CC: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x804411D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x804411D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804411D8: bne         $t7, $at, L_804411F8
    if (ctx->r15 != ctx->r1) {
        // 0x804411DC: sub.s       $f12, $f4, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_804411F8;
    }
    // 0x804411DC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804411E0: jal         0x80440950
    // 0x804411E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80440950(rdram, ctx);
        goto after_1;
    // 0x804411E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804411E8: jal         0x8043F6F4
    // 0x804411EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F6F4(rdram, ctx);
        goto after_2;
    // 0x804411EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804411F0: b           L_804412AC
    // 0x804411F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_804412AC;
    // 0x804411F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804411F8:
    // 0x804411F8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x804411FC: jal         0x80440950
    // 0x80441200: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80440950(rdram, ctx);
        goto after_3;
    // 0x80441200: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80441204: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80441208: bne         $v0, $zero, L_80441240
    if (ctx->r2 != 0) {
        // 0x8044120C: lwc1        $f12, 0x34($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80441240;
    }
    // 0x8044120C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80441210: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80441214: nop

    // 0x80441218: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x8044121C: lw          $t8, 0x2628($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2628);
    // 0x80441220: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80441224: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x80441228: bne         $at, $zero, L_80441284
    if (ctx->r1 != 0) {
        // 0x8044122C: sw          $t9, 0x2628($v1)
        MEM_W(0X2628, ctx->r3) = ctx->r25;
            goto L_80441284;
    }
    // 0x8044122C: sw          $t9, 0x2628($v1)
    MEM_W(0X2628, ctx->r3) = ctx->r25;
    // 0x80441230: jal         0x8043F5E4
    // 0x80441234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F5E4(rdram, ctx);
        goto after_4;
    // 0x80441234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80441238: b           L_80441288
    // 0x8044123C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
        goto L_80441288;
    // 0x8044123C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_80441240:
    // 0x80441240: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80441244: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80441248: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8044124C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80441250: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x80441254: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80441258: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8044125C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80441260: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80441264: jal         0x804410DC
    // 0x80441268: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_804410DC(rdram, ctx);
        goto after_5;
    // 0x80441268: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x8044126C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80441270: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80441274: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80441278: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8044127C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80441280: sw          $zero, 0x2628($v1)
    MEM_W(0X2628, ctx->r3) = 0;
L_80441284:
    // 0x80441284: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_80441288:
    // 0x80441288: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8044128C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4ED8) << 16);
    // 0x80441290: lwc1        $f6, 0x40($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X40);
    // 0x80441294: lwc1        $f4, 0x3DD8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4ED8));
    // 0x80441298: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8044129C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804412A0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x804412A4: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
L_804412A8:
    // 0x804412A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804412AC:
    // 0x804412AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804412B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804412B4: jr          $ra
    // 0x804412B8: nop

    return;
    // 0x804412B8: nop

;}
RECOMP_FUNC void func_8070FE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FE20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8070FE24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070FE28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070FE2C: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8070FE30: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8070FE34: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070FE38: lbu         $t6, 0x34($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X34);
    // 0x8070FE3C: lbu         $v1, -0x7204($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7204);
    // 0x8070FE40: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8070FE44: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8070FE48: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8070FE4C: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x8070FE50: sll         $a2, $v1, 4
    ctx->r6 = S32(ctx->r3 << 4);
    // 0x8070FE54: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8070FE58: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8070FE5C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8070FE60: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8070FE64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8070FE68: jal         0x8070FC30
    // 0x8070FE6C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8070FC30(rdram, ctx);
        goto after_0;
    // 0x8070FE6C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8070FE70: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8070FE74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8070FE78: jal         0x8070FCFC
    // 0x8070FE7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8070FCFC(rdram, ctx);
        goto after_1;
    // 0x8070FE7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8070FE80: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8070FE84: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8070FE88: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8070FE8C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8070FE90: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8070FE94: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8070FE98: jal         0x8070FDDC
    // 0x8070FE9C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    func_8070FDDC(rdram, ctx);
        goto after_2;
    // 0x8070FE9C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x8070FEA0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8070FEA4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8070FEA8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8070FEAC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8070FEB0: lw          $t5, 0x1E0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X1E0);
    // 0x8070FEB4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8070FEB8: slti        $at, $t6, 0x3C
    ctx->r1 = SIGNED(ctx->r14) < 0X3C ? 1 : 0;
    // 0x8070FEBC: bne         $at, $zero, L_8070FEDC
    if (ctx->r1 != 0) {
        // 0x8070FEC0: sw          $t6, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r14;
            goto L_8070FEDC;
    }
    // 0x8070FEC0: sw          $t6, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r14;
    // 0x8070FEC4: lw          $t8, 0x1E4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1E4);
    // 0x8070FEC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8070FECC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8070FED0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8070FED4: jal         0x80710C50
    // 0x8070FED8: sw          $t9, 0x1E4($a3)
    MEM_W(0X1E4, ctx->r7) = ctx->r25;
    func_80710C50(rdram, ctx);
        goto after_3;
    // 0x8070FED8: sw          $t9, 0x1E4($a3)
    MEM_W(0X1E4, ctx->r7) = ctx->r25;
    after_3:
L_8070FEDC:
    // 0x8070FEDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8070FEE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8070FEE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8070FEE8: jr          $ra
    // 0x8070FEEC: nop

    return;
    // 0x8070FEEC: nop

;}
RECOMP_FUNC void func_805A4678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A4678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A467C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805A4680: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805A4684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A4688: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805A468C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805A4690: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805A4694: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x805A4698: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805A469C: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(414, 0X1D58) << 16);
    // 0x805A46A0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805A46A4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805A46A8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805A46AC: lw          $t1, 0x50E8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(414, 0X1D58));
    // 0x805A46B0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805A46B4: jal         0x80048378
    // 0x805A46B8: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x805A46B8: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    after_0:
    // 0x805A46BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A46C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A46C4: jr          $ra
    // 0x805A46C8: nop

    return;
    // 0x805A46C8: nop

;}
RECOMP_FUNC void func_8073C6EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073C6EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8073C6F0: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(742, 0XF84) << 16);
    // 0x8073C6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073C6F8: addiu       $t7, $t7, -0x2F1C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(742, 0XF84));
    // 0x8073C6FC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8073C700: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073C704: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8073C708: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8073C70C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8073C710: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8073C714: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8073C718: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8073C71C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8073C720: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8073C724: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8073C728: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8073C72C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8073C730: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8073C734: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8073C738: nop

    // 0x8073C73C: bc1fl       L_8073C774
    if (!c1cs) {
        // 0x8073C740: lw          $v1, 0x10($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10);
            goto L_8073C774;
    }
    goto skip_0;
    // 0x8073C740: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x8073C744: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x8073C748: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8073C74C: bnel        $t0, $zero, L_8073C774
    if (ctx->r8 != 0) {
        // 0x8073C750: lw          $v1, 0x10($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10);
            goto L_8073C774;
    }
    goto skip_1;
    // 0x8073C750: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    skip_1:
    // 0x8073C754: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8073C758: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8073C75C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8073C760: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8073C764: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8073C768: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8073C76C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8073C770: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_8073C774:
    // 0x8073C774: beq         $v1, $zero, L_8073C784
    if (ctx->r3 == 0) {
        // 0x8073C778: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_8073C784;
    }
    // 0x8073C778: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8073C77C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8073C780: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_8073C784:
    // 0x8073C784: bnel        $v1, $zero, L_8073C7BC
    if (ctx->r3 != 0) {
        // 0x8073C788: addiu       $a0, $a2, 0xC4
        ctx->r4 = ADD32(ctx->r6, 0XC4);
            goto L_8073C7BC;
    }
    goto skip_2;
    // 0x8073C788: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    skip_2:
    // 0x8073C78C: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x8073C790: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8073C794: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x8073C798: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8073C79C: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x8073C7A0: bne         $at, $zero, L_8073C7B8
    if (ctx->r1 != 0) {
        // 0x8073C7A4: sw          $t5, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r13;
            goto L_8073C7B8;
    }
    // 0x8073C7A4: sw          $t5, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r13;
    // 0x8073C7A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8073C7AC: jal         0x80044658
    // 0x8073C7B0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_80044658(rdram, ctx);
        goto after_0;
    // 0x8073C7B0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x8073C7B4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
L_8073C7B8:
    // 0x8073C7B8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
L_8073C7BC:
    // 0x8073C7BC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8073C7C0: jal         0x80048F84
    // 0x8073C7C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8073C7C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8073C7C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8073C7CC: jal         0x80048F84
    // 0x8073C7D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8073C7D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8073C7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073C7D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8073C7DC: jr          $ra
    // 0x8073C7E0: nop

    return;
    // 0x8073C7E0: nop

;}
RECOMP_FUNC void func_80536624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536624: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536628: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053662C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536630: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536634: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536638: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053663C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536640: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536644: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536648: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053664C: jr          $ra
    // 0x80536650: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536650: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80473A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473A78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80473A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80473A80: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1490) << 16);
    // 0x80473A84: lwc1        $f14, 0x4620($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1490));
    // 0x80473A88: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80473A8C: lwc1        $f12, 0x78($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80473A90: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80473A94: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80473A98: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80473A9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80473AA0: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80473AA4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80473AA8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80473AAC: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80473AB0: bc1f        L_80473ABC
    if (!c1cs) {
        // 0x80473AB4: sub.s       $f16, $f4, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_80473ABC;
    }
    // 0x80473AB4: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80473AB8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80473ABC:
    // 0x80473ABC: lwc1        $f12, 0x7C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80473AC0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80473AC4: nop

    // 0x80473AC8: bc1fl       L_80473AD8
    if (!c1cs) {
        // 0x80473ACC: swc1        $f0, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
            goto L_80473AD8;
    }
    goto skip_0;
    // 0x80473ACC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x80473AD0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80473AD4: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
L_80473AD8:
    // 0x80473AD8: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x80473ADC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80473AE0: jal         0x804736C0
    // 0x80473AE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_804736C0(rdram, ctx);
        goto after_0;
    // 0x80473AE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80473AE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80473AEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80473AF0: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80473AF4: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80473AF8: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80473AFC: nop

    // 0x80473B00: bc1fl       L_80473B28
    if (!c1cs) {
        // 0x80473B04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80473B28;
    }
    goto skip_1;
    // 0x80473B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80473B08: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x80473B0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80473B10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80473B14: bc1fl       L_80473B28
    if (!c1cs) {
        // 0x80473B18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80473B28;
    }
    goto skip_2;
    // 0x80473B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80473B1C: jal         0x80473DF8
    // 0x80473B20: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_80473DF8(rdram, ctx);
        goto after_1;
    // 0x80473B20: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x80473B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80473B28:
    // 0x80473B28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80473B2C: jr          $ra
    // 0x80473B30: nop

    return;
    // 0x80473B30: nop

;}
RECOMP_FUNC void func_80060274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006027C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80060284: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x80060288: jal         0x8005FEBC
    // 0x8006028C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_8005FEBC(rdram, ctx);
        goto after_0;
    // 0x8006028C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80060290: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80060294: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80060298: jal         0x80065954
    // 0x8006029C: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8006029C: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    after_1:
    // 0x800602A0: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800602A4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800602A8: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800602AC: bc1f        L_800603D0
    if (!c1cs) {
        // 0x800602B0: swc1        $f6, 0x64($s0)
        MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
            goto L_800603D0;
    }
    // 0x800602B0: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x800602B4: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    // 0x800602B8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x800602BC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800602C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800602C4: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x800602C8: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x800602CC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800602D0: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800602D4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800602D8: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800602DC: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x800602E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800602E4: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800602E8: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800602EC: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800602F0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800602F4: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800602F8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800602FC: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80060300: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80060304: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80060308: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8006030C: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80060310: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80060314: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x80060318: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8006031C: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80060320: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80060324: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80060328: bc1f        L_800603D0
    if (!c1cs) {
        // 0x8006032C: swc1        $f16, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
            goto L_800603D0;
    }
    // 0x8006032C: swc1        $f16, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
    // 0x80060330: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80060334: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80060338: nop

    // 0x8006033C: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80060340: nop

    // 0x80060344: bc1fl       L_800603D4
    if (!c1cs) {
        // 0x80060348: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800603D4;
    }
    goto skip_0;
    // 0x80060348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8006034C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060350: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x80060354: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x80060358: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8006035C: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80060360: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060364: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80060368: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x8006036C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060370: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80060374: lh          $t3, 0x8($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X8);
    // 0x80060378: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x8006037C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80060380: lwc1        $f18, 0x8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80060384: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060388: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8006038C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80060390: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060394: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x80060398: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8006039C: jal         0x80065954
    // 0x800603A0: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x800603A0: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    after_2:
    // 0x800603A4: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800603A8: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800603AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800603B0: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800603B4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800603B8: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800603BC: bc1f        L_800603D4
    if (!c1cs) {
        // 0x800603C0: swc1        $f8, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
            goto L_800603D4;
    }
    // 0x800603C0: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x800603C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800603C8: b           L_800603D8
    // 0x800603CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800603D8;
    // 0x800603CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800603D0:
    // 0x800603D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800603D4:
    // 0x800603D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800603D8:
    // 0x800603D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800603DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800603E0: jr          $ra
    // 0x800603E4: nop

    return;
    // 0x800603E4: nop

;}
RECOMP_FUNC void func_8046038C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046038C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80460390: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80460394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046039C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804603A0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x804603A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804603A8: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x804603AC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804603B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804603B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804603B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804603BC: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x804603C0: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x804603C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804603C8: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x804603CC: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x804603D0: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x804603D4: lhu         $t6, 0x64($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X64);
    // 0x804603D8: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x804603DC: bnel        $t7, $zero, L_804603F0
    if (ctx->r15 != 0) {
        // 0x804603E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804603F0;
    }
    goto skip_0;
    // 0x804603E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804603E4: jal         0x80460470
    // 0x804603E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80460470(rdram, ctx);
        goto after_0;
    // 0x804603E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x804603EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804603F0:
    // 0x804603F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804603F4: jr          $ra
    // 0x804603F8: nop

    return;
    // 0x804603F8: nop

;}
RECOMP_FUNC void func_80051684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051684: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80051688: lw          $t6, -0x57C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X57C4);
    // 0x8005168C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80051690: addiu       $t8, $t8, -0x57C0
    ctx->r24 = ADD32(ctx->r24, -0X57C0);
    // 0x80051694: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80051698: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8005169C: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800516A0: jr          $ra
    // 0x800516A4: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    return;
    // 0x800516A4: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_807B9DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9DBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B9DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9DC4: jal         0x807B9D48
    // 0x807B9DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807B9D48(rdram, ctx);
        goto after_0;
    // 0x807B9DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B9DCC: bne         $v0, $zero, L_807B9DF4
    if (ctx->r2 != 0) {
        // 0x807B9DD0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807B9DF4;
    }
    // 0x807B9DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B9DD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807B9DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B9DDC: jal         0x8006E0FC
    // 0x807B9DE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x807B9DE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x807B9DE4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x807B9DE8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9DEC: b           L_807B9E1C
    // 0x807B9DF0: sw          $t6, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = ctx->r14;
        goto L_807B9E1C;
    // 0x807B9DF0: sw          $t6, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = ctx->r14;
L_807B9DF4:
    // 0x807B9DF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807B9DF8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807B9DFC: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x807B9E00: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807B9E04: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807B9E08: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807B9E0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9E10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B9E14: jal         0x807B9E2C
    // 0x807B9E18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B9E2C(rdram, ctx);
        goto after_2;
    // 0x807B9E18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_807B9E1C:
    // 0x807B9E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B9E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B9E24: jr          $ra
    // 0x807B9E28: nop

    return;
    // 0x807B9E28: nop

;}
RECOMP_FUNC void func_805340C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805340C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805340C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805340C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805340CC: jal         0x80533D84
    // 0x805340D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80533D84(rdram, ctx);
        goto after_0;
    // 0x805340D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805340D4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x805340D8: bnel        $at, $zero, L_80534134
    if (ctx->r1 != 0) {
        // 0x805340DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80534134;
    }
    goto skip_0;
    // 0x805340DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805340E0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x805340E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805340E8: jal         0x80533DD8
    // 0x805340EC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80533DD8(rdram, ctx);
        goto after_1;
    // 0x805340EC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x805340F0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x805340F4: bne         $at, $zero, L_80534128
    if (ctx->r1 != 0) {
        // 0x805340F8: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80534128;
    }
    // 0x805340F8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805340FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80534100: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    // 0x80534104: lw          $a2, 0x34($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X34);
    // 0x80534108: jal         0x80533FC0
    // 0x8053410C: addiu       $a3, $zero, 0x4034
    ctx->r7 = ADD32(0, 0X4034);
    func_80533FC0(rdram, ctx);
        goto after_2;
    // 0x8053410C: addiu       $a3, $zero, 0x4034
    ctx->r7 = ADD32(0, 0X4034);
    after_2:
    // 0x80534110: jal         0x80533B34
    // 0x80534114: nop

    func_80533B34(rdram, ctx);
        goto after_3;
    // 0x80534114: nop

    after_3:
    // 0x80534118: jal         0x800447C8
    // 0x8053411C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x8053411C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80534120: b           L_80534134
    // 0x80534124: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80534134;
    // 0x80534124: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80534128:
    // 0x80534128: jal         0x800447C8
    // 0x8053412C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x8053412C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80534130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80534134:
    // 0x80534134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80534138: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8053413C: jr          $ra
    // 0x80534140: nop

    return;
    // 0x80534140: nop

;}
RECOMP_FUNC void func_806815FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806815FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80681600: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80681604: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80681608: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8068160C: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x80681610: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80681614: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80681618: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8068161C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80681620: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80681624: jal         0x80062AEC
    // 0x80681628: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x80681628: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x8068162C: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x80681630: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80681634: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80681638: bne         $t7, $at, L_80681830
    if (ctx->r15 != ctx->r1) {
        // 0x8068163C: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_80681830;
    }
    // 0x8068163C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80681640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80681644: beq         $v0, $at, L_80681664
    if (ctx->r2 == ctx->r1) {
        // 0x80681648: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80681664;
    }
    // 0x80681648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8068164C: beq         $v0, $at, L_806816BC
    if (ctx->r2 == ctx->r1) {
        // 0x80681650: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_806816BC;
    }
    // 0x80681650: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80681654: beql        $v0, $at, L_80681718
    if (ctx->r2 == ctx->r1) {
        // 0x80681658: lw          $t2, 0x174($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X174);
            goto L_80681718;
    }
    goto skip_0;
    // 0x80681658: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    skip_0:
    // 0x8068165C: b           L_80681834
    // 0x80681660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80681834;
    // 0x80681660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80681664:
    // 0x80681664: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2268) << 16);
    // 0x80681668: lwc1        $f4, 0x2678($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2268));
    // 0x8068166C: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80681670: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80681674: nop

    // 0x80681678: bc1fl       L_806816A8
    if (!c1cs) {
        // 0x8068167C: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806816A8;
    }
    goto skip_1;
    // 0x8068167C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x80681680: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80681684: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80681688: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8068168C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80681690: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80681694: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80681698: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8068169C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x806816A0: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x806816A4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806816A8:
    // 0x806816A8: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x806816AC: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x806816B0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x806816B4: b           L_80681830
    // 0x806816B8: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_80681830;
    // 0x806816B8: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_806816BC:
    // 0x806816BC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X226C) << 16);
    // 0x806816C0: lwc1        $f16, 0x267C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X226C));
    // 0x806816C4: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806816C8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806816CC: nop

    // 0x806816D0: bc1fl       L_80681700
    if (!c1cs) {
        // 0x806816D4: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80681700;
    }
    goto skip_2;
    // 0x806816D4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_2:
    // 0x806816D8: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x806816DC: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806816E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806816E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806816E8: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x806816EC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806816F0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x806816F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806816F8: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x806816FC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80681700:
    // 0x80681700: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80681704: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x80681708: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8068170C: b           L_80681830
    // 0x80681710: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
        goto L_80681830;
    // 0x80681710: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x80681714: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
L_80681718:
    // 0x80681718: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    // 0x8068171C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80681720: beq         $t3, $zero, L_806817AC
    if (ctx->r11 == 0) {
        // 0x80681724: nop
    
            goto L_806817AC;
    }
    // 0x80681724: nop

    // 0x80681728: beq         $v1, $zero, L_806817AC
    if (ctx->r3 == 0) {
        // 0x8068172C: nop
    
            goto L_806817AC;
    }
    // 0x8068172C: nop

    // 0x80681730: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80681734: addiu       $at, $zero, 0x4578
    ctx->r1 = ADD32(0, 0X4578);
    // 0x80681738: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8068173C: beq         $v0, $at, L_80681754
    if (ctx->r2 == ctx->r1) {
        // 0x80681740: addiu       $at, $zero, 0x4579
        ctx->r1 = ADD32(0, 0X4579);
            goto L_80681754;
    }
    // 0x80681740: addiu       $at, $zero, 0x4579
    ctx->r1 = ADD32(0, 0X4579);
    // 0x80681744: beq         $v0, $at, L_80681754
    if (ctx->r2 == ctx->r1) {
        // 0x80681748: addiu       $at, $zero, 0x457A
        ctx->r1 = ADD32(0, 0X457A);
            goto L_80681754;
    }
    // 0x80681748: addiu       $at, $zero, 0x457A
    ctx->r1 = ADD32(0, 0X457A);
    // 0x8068174C: bne         $v0, $at, L_806817AC
    if (ctx->r2 != ctx->r1) {
        // 0x80681750: nop
    
            goto L_806817AC;
    }
    // 0x80681750: nop

L_80681754:
    // 0x80681754: lwc1        $f6, 0x84($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X84);
    // 0x80681758: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8068175C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80681760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80681764: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80681768: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8068176C: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80681770: nop

    // 0x80681774: bc1f        L_806817AC
    if (!c1cs) {
        // 0x80681778: nop
    
            goto L_806817AC;
    }
    // 0x80681778: nop

    // 0x8068177C: jal         0x8002FBFC
    // 0x80681780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002FBFC(rdram, ctx);
        goto after_1;
    // 0x80681780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80681784: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x80681788: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8068178C: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x80681790: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80681794: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80681798: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x8068179C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806817A0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x806817A4: b           L_80681830
    // 0x806817A8: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
        goto L_80681830;
    // 0x806817A8: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
L_806817AC:
    // 0x806817AC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2270) << 16);
    // 0x806817B0: lwc1        $f10, 0x2680($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2270));
    // 0x806817B4: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806817B8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806817BC: nop

    // 0x806817C0: bc1fl       L_806817F4
    if (!c1cs) {
        // 0x806817C4: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_806817F4;
    }
    goto skip_3;
    // 0x806817C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    skip_3:
    // 0x806817C8: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806817CC: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806817D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806817D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806817D8: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806817DC: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806817E0: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806817E4: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x806817E8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806817EC: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x806817F0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_806817F4:
    // 0x806817F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806817F8: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2274) << 16);
    // 0x806817FC: lwc1        $f18, 0x2684($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2274));
    // 0x80681800: add.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80681804: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80681808: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8068180C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80681810: nop

    // 0x80681814: bc1fl       L_80681824
    if (!c1cs) {
        // 0x80681818: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80681824;
    }
    goto skip_4;
    // 0x80681818: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_4:
    // 0x8068181C: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
    // 0x80681820: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80681824:
    // 0x80681824: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80681828: ori         $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 | 0X3000;
    // 0x8068182C: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_80681830:
    // 0x80681830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80681834:
    // 0x80681834: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80681838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8068183C: jr          $ra
    // 0x80681840: nop

    return;
    // 0x80681840: nop

;}
RECOMP_FUNC void func_8040F6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040F6F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040F6FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040F700: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8040F704: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8040F708: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8040F70C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8040F710: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x8040F714: jal         0x80410234
    // 0x8040F718: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_80410234(rdram, ctx);
        goto after_0;
    // 0x8040F718: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x8040F71C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8040F720: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8040F724: jal         0x80410AF4
    // 0x8040F728: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    func_80410AF4(rdram, ctx);
        goto after_1;
    // 0x8040F728: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8040F72C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8040F730: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8040F734: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8040F738: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8040F73C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8040F740: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8040F744: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8040F748: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8040F74C: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x8040F750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040F754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040F758: jr          $ra
    // 0x8040F75C: nop

    return;
    // 0x8040F75C: nop

;}
RECOMP_FUNC void func_805ADB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADB14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ADB18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805ADB1C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805ADB20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ADB24: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805ADB28: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805ADB2C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805ADB30: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805ADB34: addiu       $t6, $zero, 0x1C98
    ctx->r14 = ADD32(0, 0X1C98);
    // 0x805ADB38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805ADB3C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805ADB40: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805ADB44: addiu       $a1, $zero, 0x294
    ctx->r5 = ADD32(0, 0X294);
    // 0x805ADB48: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x805ADB4C: jal         0x805AD70C
    // 0x805ADB50: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_805AD70C(rdram, ctx);
        goto after_0;
    // 0x805ADB50: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805ADB54: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ADB58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADB5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805ADB60: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805ADB64: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805ADB68: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x805ADB6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ADB70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ADB74: jr          $ra
    // 0x805ADB78: nop

    return;
    // 0x805ADB78: nop

;}
RECOMP_FUNC void func_8052C6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C6F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8052C6F4: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x8052C6F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052C6FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052C700: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8052C704: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8052C708: jal         0x8052D6E4
    // 0x8052C70C: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    func_8052D6E4(rdram, ctx);
        goto after_0;
    // 0x8052C70C: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x8052C710: beq         $v0, $zero, L_8052C90C
    if (ctx->r2 == 0) {
        // 0x8052C714: nop
    
            goto L_8052C90C;
    }
    // 0x8052C714: nop

    // 0x8052C718: jal         0x8052D71C
    // 0x8052C71C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052D71C(rdram, ctx);
        goto after_1;
    // 0x8052C71C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8052C720: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8052C724: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8052C728: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8052C72C: lui         $t7, 0x8053
    ctx->r15 = S32(RELOC_HI16(330, 0X16B0) << 16);
    // 0x8052C730: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8052C734: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8052C738: addiu       $t7, $t7, -0x2380
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(330, 0X16B0));
    // 0x8052C73C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8052C740: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8052C744: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8052C748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052C74C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8052C750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8052C754: jal         0x8052DC40
    // 0x8052C758: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8052DC40(rdram, ctx);
        goto after_2;
    // 0x8052C758: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8052C75C: jal         0x80047090
    // 0x8052C760: addiu       $a0, $zero, 0x414D
    ctx->r4 = ADD32(0, 0X414D);
    func_80047090(rdram, ctx);
        goto after_3;
    // 0x8052C760: addiu       $a0, $zero, 0x414D
    ctx->r4 = ADD32(0, 0X414D);
    after_3:
    // 0x8052C764: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8052C768: bne         $v0, $at, L_8052C780
    if (ctx->r2 != ctx->r1) {
        // 0x8052C76C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8052C780;
    }
    // 0x8052C76C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8052C770: jal         0x800445A4
    // 0x8052C774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8052C774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8052C778: b           L_8052C918
    // 0x8052C77C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052C918;
    // 0x8052C77C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052C780:
    // 0x8052C780: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8052C784: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8052C788: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8052C78C: lui         $at, 0x414D
    ctx->r1 = S32(0X414D << 16);
    // 0x8052C790: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8052C794: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x8052C798: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x8052C79C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8052C7A0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8052C7A4: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8052C7A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8052C7AC: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8052C7B0: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8052C7B4: jal         0x8004613C
    // 0x8052C7B8: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x8052C7B8: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8052C7BC: bne         $v0, $zero, L_8052C7D4
    if (ctx->r2 != 0) {
        // 0x8052C7C0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8052C7D4;
    }
    // 0x8052C7C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8052C7C4: jal         0x800445A4
    // 0x8052C7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x8052C7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8052C7CC: b           L_8052C918
    // 0x8052C7D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052C918;
    // 0x8052C7D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052C7D4:
    // 0x8052C7D4: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8052C7D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8052C7DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052C7E0: jal         0x80047F9C
    // 0x8052C7E4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x8052C7E4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_7:
    // 0x8052C7E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8052C7EC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8052C7F0: jal         0x8052C928
    // 0x8052C7F4: sw          $a0, 0xF04($t0)
    MEM_W(0XF04, ctx->r8) = ctx->r4;
    func_8052C928(rdram, ctx);
        goto after_8;
    // 0x8052C7F4: sw          $a0, 0xF04($t0)
    MEM_W(0XF04, ctx->r8) = ctx->r4;
    after_8:
    // 0x8052C7F8: bne         $v0, $zero, L_8052C810
    if (ctx->r2 != 0) {
        // 0x8052C7FC: nop
    
            goto L_8052C810;
    }
    // 0x8052C7FC: nop

    // 0x8052C800: jal         0x800445A4
    // 0x8052C804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x8052C804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8052C808: b           L_8052C918
    // 0x8052C80C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052C918;
    // 0x8052C80C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052C810:
    // 0x8052C810: jal         0x80047090
    // 0x8052C814: addiu       $a0, $zero, 0x414E
    ctx->r4 = ADD32(0, 0X414E);
    func_80047090(rdram, ctx);
        goto after_10;
    // 0x8052C814: addiu       $a0, $zero, 0x414E
    ctx->r4 = ADD32(0, 0X414E);
    after_10:
    // 0x8052C818: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8052C81C: bne         $v0, $at, L_8052C834
    if (ctx->r2 != ctx->r1) {
        // 0x8052C820: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8052C834;
    }
    // 0x8052C820: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8052C824: jal         0x800445A4
    // 0x8052C828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_11;
    // 0x8052C828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8052C82C: b           L_8052C918
    // 0x8052C830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052C918;
    // 0x8052C830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052C834:
    // 0x8052C834: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8052C838: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8052C83C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8052C840: lui         $at, 0x414E
    ctx->r1 = S32(0X414E << 16);
    // 0x8052C844: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8052C848: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x8052C84C: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x8052C850: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8052C854: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8052C858: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8052C85C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8052C860: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8052C864: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8052C868: jal         0x8004613C
    // 0x8052C86C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_8004613C(rdram, ctx);
        goto after_12;
    // 0x8052C86C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x8052C870: bne         $v0, $zero, L_8052C888
    if (ctx->r2 != 0) {
        // 0x8052C874: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8052C888;
    }
    // 0x8052C874: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8052C878: jal         0x800445A4
    // 0x8052C87C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_13;
    // 0x8052C87C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8052C880: b           L_8052C918
    // 0x8052C884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8052C918;
    // 0x8052C884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052C888:
    // 0x8052C888: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x8052C88C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8052C890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052C894: jal         0x80047F9C
    // 0x8052C898: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_80047F9C(rdram, ctx);
        goto after_14;
    // 0x8052C898: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_14:
    // 0x8052C89C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8052C8A0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8052C8A4: jal         0x8052D658
    // 0x8052C8A8: sw          $a0, 0xF08($t2)
    MEM_W(0XF08, ctx->r10) = ctx->r4;
    func_8052D658(rdram, ctx);
        goto after_15;
    // 0x8052C8A8: sw          $a0, 0xF08($t2)
    MEM_W(0XF08, ctx->r10) = ctx->r4;
    after_15:
    // 0x8052C8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052C8B0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8052C8B4: jal         0x8052D7C8
    // 0x8052C8B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_8052D7C8(rdram, ctx);
        goto after_16;
    // 0x8052C8B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x8052C8BC: jal         0x80066E88
    // 0x8052C8C0: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80066E88(rdram, ctx);
        goto after_17;
    // 0x8052C8C0: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_17:
    // 0x8052C8C4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8052C8C8: lui         $t3, 0x8053
    ctx->r11 = S32(RELOC_HI16(330, 0XEC) << 16);
    // 0x8052C8CC: addiu       $t3, $t3, -0x3944
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(330, 0XEC));
    // 0x8052C8D0: lwc1        $f10, 0xF14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XF14);
    // 0x8052C8D4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8052C8D8: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x8052C8DC: lwc1        $f18, 0xC4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8052C8E0: swc1        $f18, 0xF1C($v0)
    MEM_W(0XF1C, ctx->r2) = ctx->f18.u32l;
    // 0x8052C8E4: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    // 0x8052C8E8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8052C8EC: jal         0x80067BBC
    // 0x8052C8F0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_18;
    // 0x8052C8F0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_18:
    // 0x8052C8F4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8052C8F8: jal         0x80067F78
    // 0x8052C8FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_19;
    // 0x8052C8FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_19:
    // 0x8052C900: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8052C904: b           L_8052C914
    // 0x8052C908: sh          $v0, 0xF28($t4)
    MEM_H(0XF28, ctx->r12) = ctx->r2;
        goto L_8052C914;
    // 0x8052C908: sh          $v0, 0xF28($t4)
    MEM_H(0XF28, ctx->r12) = ctx->r2;
L_8052C90C:
    // 0x8052C90C: jal         0x800445A4
    // 0x8052C910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_20;
    // 0x8052C910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_8052C914:
    // 0x8052C914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052C918:
    // 0x8052C918: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8052C91C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8052C920: jr          $ra
    // 0x8052C924: nop

    return;
    // 0x8052C924: nop

;}
RECOMP_FUNC void func_8000A8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A8F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A8FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A900: jal         0x8000A8A4
    // 0x8000A904: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8000A8A4(rdram, ctx);
        goto after_0;
    // 0x8000A904: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000A908: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8000A90C: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x8000A910: lbu         $v0, 0x2A22($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2A22);
    // 0x8000A914: beq         $v0, $zero, L_8000A964
    if (ctx->r2 == 0) {
        // 0x8000A918: nop
    
            goto L_8000A964;
    }
    // 0x8000A918: nop

    // 0x8000A91C: jal         0x8000A468
    // 0x8000A920: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8000A468(rdram, ctx);
        goto after_1;
    // 0x8000A920: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000A924: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8000A928: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x8000A92C: lbu         $t7, 0x2A23($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2A23);
    // 0x8000A930: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000A934: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A938: bne         $t6, $t7, L_8000A948
    if (ctx->r14 != ctx->r15) {
        // 0x8000A93C: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8000A948;
    }
    // 0x8000A93C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000A940: b           L_8000A980
    // 0x8000A944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000A980;
    // 0x8000A944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A948:
    // 0x8000A948: bne         $at, $zero, L_8000A958
    if (ctx->r1 != 0) {
        // 0x8000A94C: addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
            goto L_8000A958;
    }
    // 0x8000A94C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8000A950: b           L_8000A980
    // 0x8000A954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000A980;
    // 0x8000A954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A958:
    // 0x8000A958: lw          $a0, 0x4F88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4F88);
    // 0x8000A95C: jal         0x800824B0
    // 0x8000A960: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8000A960: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_8000A964:
    // 0x8000A964: jal         0x8000A8A4
    // 0x8000A968: nop

    func_8000A8A4(rdram, ctx);
        goto after_3;
    // 0x8000A968: nop

    after_3:
    // 0x8000A96C: lui         $a0, 0xF900
    ctx->r4 = S32(0XF900 << 16);
    // 0x8000A970: jal         0x8000A364
    // 0x8000A974: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8000A364(rdram, ctx);
        goto after_4;
    // 0x8000A974: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8000A978: jal         0x8000A3E8
    // 0x8000A97C: nop

    func_8000A3E8(rdram, ctx);
        goto after_5;
    // 0x8000A97C: nop

    after_5:
L_8000A980:
    // 0x8000A980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A984: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A988: jr          $ra
    // 0x8000A98C: nop

    return;
    // 0x8000A98C: nop

;}
RECOMP_FUNC void func_806CC2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CC2F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806CC2FC: lui         $t3, 0x806D
    ctx->r11 = S32(RELOC_HI16(604, 0X3A3C) << 16);
    // 0x806CC300: lw          $t3, -0xEA4($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(604, 0X3A3C));
    // 0x806CC304: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806CC308: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806CC30C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806CC310: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CC314: lb          $t6, 0x0($t3)
    ctx->r14 = MEM_B(ctx->r11, 0X0);
    // 0x806CC318: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806CC31C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806CC320: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806CC324: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CC328: lui         $t4, 0x806D
    ctx->r12 = S32(RELOC_HI16(604, 0X3A58) << 16);
    // 0x806CC32C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CC330: lw          $t4, -0xE88($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(604, 0X3A58));
    // 0x806CC334: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x806CC338: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806CC33C: addiu       $a3, $zero, 0x3B
    ctx->r7 = ADD32(0, 0X3B);
    // 0x806CC340: addiu       $a1, $t3, 0x3
    ctx->r5 = ADD32(ctx->r11, 0X3);
    // 0x806CC344: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CC348: addiu       $a0, $t1, 0xC
    ctx->r4 = ADD32(ctx->r9, 0XC);
    // 0x806CC34C: addiu       $v0, $t1, 0x18
    ctx->r2 = ADD32(ctx->r9, 0X18);
    // 0x806CC350: addiu       $v1, $t4, 0x3
    ctx->r3 = ADD32(ctx->r12, 0X3);
    // 0x806CC354: swc1        $f8, 0x590($t1)
    MEM_W(0X590, ctx->r9) = ctx->f8.u32l;
    // 0x806CC358: lb          $t7, 0x0($t4)
    ctx->r15 = MEM_B(ctx->r12, 0X0);
    // 0x806CC35C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x806CC360: nop

    // 0x806CC364: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806CC368: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC36C: swc1        $f18, 0x67C($t1)
    MEM_W(0X67C, ctx->r9) = ctx->f18.u32l;
    // 0x806CC370: lb          $t8, 0x0($t4)
    ctx->r24 = MEM_B(ctx->r12, 0X0);
    // 0x806CC374: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x806CC378: nop

    // 0x806CC37C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CC380: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CC384: swc1        $f8, 0x680($t1)
    MEM_W(0X680, ctx->r9) = ctx->f8.u32l;
    // 0x806CC388: lb          $t9, 0x1($t3)
    ctx->r25 = MEM_B(ctx->r11, 0X1);
    // 0x806CC38C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x806CC390: nop

    // 0x806CC394: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806CC398: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC39C: swc1        $f18, 0x594($t1)
    MEM_W(0X594, ctx->r9) = ctx->f18.u32l;
    // 0x806CC3A0: lb          $t5, 0x1($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X1);
    // 0x806CC3A4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x806CC3A8: nop

    // 0x806CC3AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CC3B0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CC3B4: swc1        $f8, 0x684($t1)
    MEM_W(0X684, ctx->r9) = ctx->f8.u32l;
    // 0x806CC3B8: lb          $t6, 0x1($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X1);
    // 0x806CC3BC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x806CC3C0: nop

    // 0x806CC3C4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806CC3C8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC3CC: swc1        $f18, 0x688($t1)
    MEM_W(0X688, ctx->r9) = ctx->f18.u32l;
    // 0x806CC3D0: lb          $t7, 0x2($t3)
    ctx->r15 = MEM_B(ctx->r11, 0X2);
    // 0x806CC3D4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806CC3D8: nop

    // 0x806CC3DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CC3E0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CC3E4: swc1        $f8, 0x598($t1)
    MEM_W(0X598, ctx->r9) = ctx->f8.u32l;
    // 0x806CC3E8: lb          $t8, 0x2($t4)
    ctx->r24 = MEM_B(ctx->r12, 0X2);
    // 0x806CC3EC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x806CC3F0: nop

    // 0x806CC3F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806CC3F8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC3FC: swc1        $f18, 0x68C($t1)
    MEM_W(0X68C, ctx->r9) = ctx->f18.u32l;
    // 0x806CC400: lb          $t9, 0x2($t4)
    ctx->r25 = MEM_B(ctx->r12, 0X2);
    // 0x806CC404: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x806CC408: nop

    // 0x806CC40C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CC410: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CC414: swc1        $f8, 0x690($t1)
    MEM_W(0X690, ctx->r9) = ctx->f8.u32l;
    // 0x806CC418: lb          $t5, 0x0($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X0);
    // 0x806CC41C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x806CC420: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x806CC424: nop

    // 0x806CC428: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC42C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC430: beql        $a2, $a3, L_806CC574
    if (ctx->r6 == ctx->r7) {
        // 0x806CC434: swc1        $f18, 0x590($a0)
        MEM_W(0X590, ctx->r4) = ctx->f18.u32l;
            goto L_806CC574;
    }
    goto skip_0;
    // 0x806CC434: swc1        $f18, 0x590($a0)
    MEM_W(0X590, ctx->r4) = ctx->f18.u32l;
    skip_0:
    // 0x806CC438: swc1        $f18, 0x590($a0)
    MEM_W(0X590, ctx->r4) = ctx->f18.u32l;
L_806CC43C:
    // 0x806CC43C: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x806CC440: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x806CC444: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x806CC448: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806CC44C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806CC450: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x806CC454: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC458: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806CC45C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC460: swc1        $f16, 0x65C($v0)
    MEM_W(0X65C, ctx->r2) = ctx->f16.u32l;
    // 0x806CC464: lb          $t7, -0x4($v1)
    ctx->r15 = MEM_B(ctx->r3, -0X4);
    // 0x806CC468: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806CC46C: nop

    // 0x806CC470: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC474: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC478: swc1        $f16, 0x660($v0)
    MEM_W(0X660, ctx->r2) = ctx->f16.u32l;
    // 0x806CC47C: lb          $t8, -0x3($a1)
    ctx->r24 = MEM_B(ctx->r5, -0X3);
    // 0x806CC480: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x806CC484: nop

    // 0x806CC488: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC48C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC490: swc1        $f16, 0x584($a0)
    MEM_W(0X584, ctx->r4) = ctx->f16.u32l;
    // 0x806CC494: lb          $t9, -0x3($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X3);
    // 0x806CC498: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x806CC49C: nop

    // 0x806CC4A0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC4A4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC4A8: swc1        $f16, 0x664($v0)
    MEM_W(0X664, ctx->r2) = ctx->f16.u32l;
    // 0x806CC4AC: lb          $t5, -0x3($v1)
    ctx->r13 = MEM_B(ctx->r3, -0X3);
    // 0x806CC4B0: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x806CC4B4: nop

    // 0x806CC4B8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC4BC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC4C0: swc1        $f16, 0x668($v0)
    MEM_W(0X668, ctx->r2) = ctx->f16.u32l;
    // 0x806CC4C4: lb          $t6, -0x2($a1)
    ctx->r14 = MEM_B(ctx->r5, -0X2);
    // 0x806CC4C8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806CC4CC: nop

    // 0x806CC4D0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC4D4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC4D8: swc1        $f16, 0x588($a0)
    MEM_W(0X588, ctx->r4) = ctx->f16.u32l;
    // 0x806CC4DC: lb          $t7, -0x2($v1)
    ctx->r15 = MEM_B(ctx->r3, -0X2);
    // 0x806CC4E0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806CC4E4: nop

    // 0x806CC4E8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC4EC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC4F0: swc1        $f16, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f16.u32l;
    // 0x806CC4F4: lb          $t8, -0x2($v1)
    ctx->r24 = MEM_B(ctx->r3, -0X2);
    // 0x806CC4F8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x806CC4FC: nop

    // 0x806CC500: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC504: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC508: swc1        $f16, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f16.u32l;
    // 0x806CC50C: lb          $t9, -0x1($a1)
    ctx->r25 = MEM_B(ctx->r5, -0X1);
    // 0x806CC510: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x806CC514: nop

    // 0x806CC518: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC51C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC520: swc1        $f16, 0x58C($a0)
    MEM_W(0X58C, ctx->r4) = ctx->f16.u32l;
    // 0x806CC524: lb          $t5, -0x1($v1)
    ctx->r13 = MEM_B(ctx->r3, -0X1);
    // 0x806CC528: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x806CC52C: nop

    // 0x806CC530: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC534: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC538: swc1        $f16, 0x674($v0)
    MEM_W(0X674, ctx->r2) = ctx->f16.u32l;
    // 0x806CC53C: lb          $t6, -0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, -0X1);
    // 0x806CC540: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806CC544: nop

    // 0x806CC548: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC54C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC550: swc1        $f16, 0x678($v0)
    MEM_W(0X678, ctx->r2) = ctx->f16.u32l;
    // 0x806CC554: lb          $t5, 0x0($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X0);
    // 0x806CC558: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x806CC55C: nop

    // 0x806CC560: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC564: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC568: bnel        $a2, $a3, L_806CC43C
    if (ctx->r6 != ctx->r7) {
        // 0x806CC56C: swc1        $f18, 0x590($a0)
        MEM_W(0X590, ctx->r4) = ctx->f18.u32l;
            goto L_806CC43C;
    }
    goto skip_1;
    // 0x806CC56C: swc1        $f18, 0x590($a0)
    MEM_W(0X590, ctx->r4) = ctx->f18.u32l;
    skip_1:
    // 0x806CC570: swc1        $f18, 0x590($a0)
    MEM_W(0X590, ctx->r4) = ctx->f18.u32l;
L_806CC574:
    // 0x806CC574: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x806CC578: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x806CC57C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806CC580: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806CC584: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x806CC588: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806CC58C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC590: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC594: swc1        $f16, 0x65C($v0)
    MEM_W(0X65C, ctx->r2) = ctx->f16.u32l;
    // 0x806CC598: lb          $t7, -0x4($v1)
    ctx->r15 = MEM_B(ctx->r3, -0X4);
    // 0x806CC59C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806CC5A0: nop

    // 0x806CC5A4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC5A8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC5AC: swc1        $f16, 0x660($v0)
    MEM_W(0X660, ctx->r2) = ctx->f16.u32l;
    // 0x806CC5B0: lb          $t8, -0x3($a1)
    ctx->r24 = MEM_B(ctx->r5, -0X3);
    // 0x806CC5B4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x806CC5B8: nop

    // 0x806CC5BC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC5C0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC5C4: swc1        $f16, 0x584($a0)
    MEM_W(0X584, ctx->r4) = ctx->f16.u32l;
    // 0x806CC5C8: lb          $t9, -0x3($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X3);
    // 0x806CC5CC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x806CC5D0: nop

    // 0x806CC5D4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC5D8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC5DC: swc1        $f16, 0x664($v0)
    MEM_W(0X664, ctx->r2) = ctx->f16.u32l;
    // 0x806CC5E0: lb          $t5, -0x3($v1)
    ctx->r13 = MEM_B(ctx->r3, -0X3);
    // 0x806CC5E4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x806CC5E8: nop

    // 0x806CC5EC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC5F0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC5F4: swc1        $f16, 0x668($v0)
    MEM_W(0X668, ctx->r2) = ctx->f16.u32l;
    // 0x806CC5F8: lb          $t6, -0x2($a1)
    ctx->r14 = MEM_B(ctx->r5, -0X2);
    // 0x806CC5FC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806CC600: nop

    // 0x806CC604: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC608: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC60C: swc1        $f16, 0x588($a0)
    MEM_W(0X588, ctx->r4) = ctx->f16.u32l;
    // 0x806CC610: lb          $t7, -0x2($v1)
    ctx->r15 = MEM_B(ctx->r3, -0X2);
    // 0x806CC614: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806CC618: nop

    // 0x806CC61C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC620: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC624: swc1        $f16, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f16.u32l;
    // 0x806CC628: lb          $t8, -0x2($v1)
    ctx->r24 = MEM_B(ctx->r3, -0X2);
    // 0x806CC62C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x806CC630: nop

    // 0x806CC634: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC638: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC63C: swc1        $f16, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f16.u32l;
    // 0x806CC640: lb          $t9, -0x1($a1)
    ctx->r25 = MEM_B(ctx->r5, -0X1);
    // 0x806CC644: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x806CC648: nop

    // 0x806CC64C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC650: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC654: swc1        $f16, 0x58C($a0)
    MEM_W(0X58C, ctx->r4) = ctx->f16.u32l;
    // 0x806CC658: lb          $t5, -0x1($v1)
    ctx->r13 = MEM_B(ctx->r3, -0X1);
    // 0x806CC65C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x806CC660: nop

    // 0x806CC664: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC668: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC66C: swc1        $f16, 0x674($v0)
    MEM_W(0X674, ctx->r2) = ctx->f16.u32l;
    // 0x806CC670: lb          $t6, -0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, -0X1);
    // 0x806CC674: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806CC678: nop

    // 0x806CC67C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CC680: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806CC684: swc1        $f16, 0x678($v0)
    MEM_W(0X678, ctx->r2) = ctx->f16.u32l;
    // 0x806CC688: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CC68C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806CC690: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806CC694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806CC698: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806CC69C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x806CC6A0: sw          $zero, 0x58C($t1)
    MEM_W(0X58C, ctx->r9) = 0;
    // 0x806CC6A4: sw          $zero, 0x588($t1)
    MEM_W(0X588, ctx->r9) = 0;
    // 0x806CC6A8: sh          $zero, 0x888($t1)
    MEM_H(0X888, ctx->r9) = 0;
    // 0x806CC6AC: sb          $t7, 0x86D($t1)
    MEM_B(0X86D, ctx->r9) = ctx->r15;
    // 0x806CC6B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806CC6B4: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x806CC6B8: swc1        $f0, 0x85C($t1)
    MEM_W(0X85C, ctx->r9) = ctx->f0.u32l;
    // 0x806CC6BC: swc1        $f0, 0x860($t1)
    MEM_W(0X860, ctx->r9) = ctx->f0.u32l;
    // 0x806CC6C0: swc1        $f10, 0x854($t1)
    MEM_W(0X854, ctx->r9) = ctx->f10.u32l;
    // 0x806CC6C4: swc1        $f16, 0x858($t1)
    MEM_W(0X858, ctx->r9) = ctx->f16.u32l;
    // 0x806CC6C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_806CC6CC:
    // 0x806CC6CC: jal         0x806CBA6C
    // 0x806CC6D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_806CBA6C(rdram, ctx);
        goto after_0;
    // 0x806CC6D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x806CC6D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806CC6D8: bnel        $s0, $s1, L_806CC6CC
    if (ctx->r16 != ctx->r17) {
        // 0x806CC6DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_806CC6CC;
    }
    goto skip_2;
    // 0x806CC6DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
    // 0x806CC6E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806CC6E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CC6E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806CC6EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806CC6F0: jr          $ra
    // 0x806CC6F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806CC6F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8070FB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FB04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070FB08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070FB0C: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8070FB10: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8070FB14: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x8070FB18: bne         $at, $zero, L_8070FB38
    if (ctx->r1 != 0) {
        // 0x8070FB1C: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8070FB38;
    }
    // 0x8070FB1C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8070FB20: jal         0x80710C50
    // 0x8070FB24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80710C50(rdram, ctx);
        goto after_0;
    // 0x8070FB24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8070FB28: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8070FB2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8070FB30: jal         0x80067838
    // 0x8070FB34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80067838(rdram, ctx);
        goto after_1;
    // 0x8070FB34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_8070FB38:
    // 0x8070FB38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070FB3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070FB40: jr          $ra
    // 0x8070FB44: nop

    return;
    // 0x8070FB44: nop

;}
RECOMP_FUNC void func_804A1404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1404: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804A1408: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A140C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A1410: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A1414: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A1418: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804A141C: lh          $a1, 0x184($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X184);
    // 0x804A1420: addiu       $a3, $v0, 0x188
    ctx->r7 = ADD32(ctx->r2, 0X188);
    // 0x804A1424: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x804A1428: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x804A142C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x804A1430: jal         0x800653D8
    // 0x804A1434: sh          $a1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804A1434: sh          $a1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r5;
    after_0:
    // 0x804A1438: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x804A143C: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x804A1440: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x804A1444: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x804A1448: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x804A144C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x804A1450: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x804A1454: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x804A1458: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    // 0x804A145C: sw          $zero, 0xC($t1)
    MEM_W(0XC, ctx->r9) = 0;
    // 0x804A1460: addu        $v0, $t1, $t6
    ctx->r2 = ADD32(ctx->r9, ctx->r14);
    // 0x804A1464: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x804A1468: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x804A146C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x804A1470: beq         $a1, $zero, L_804A14C0
    if (ctx->r5 == 0) {
        // 0x804A1474: sw          $zero, 0xC($v0)
        MEM_W(0XC, ctx->r2) = 0;
            goto L_804A14C0;
    }
    // 0x804A1474: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x804A1478: addiu       $t0, $zero, 0x41F9
    ctx->r8 = ADD32(0, 0X41F9);
L_804A147C:
    // 0x804A147C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x804A1480: beq         $v0, $zero, L_804A14B8
    if (ctx->r2 == 0) {
        // 0x804A1484: nop
    
            goto L_804A14B8;
    }
    // 0x804A1484: nop

    // 0x804A1488: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    // 0x804A148C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x804A1490: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x804A1494: beq         $t0, $a0, L_804A14B8
    if (ctx->r8 == ctx->r4) {
        // 0x804A1498: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_804A14B8;
    }
    // 0x804A1498: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x804A149C: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x804A14A0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A14A4: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x804A14A8: beq         $t7, $a0, L_804A14B8
    if (ctx->r15 == ctx->r4) {
        // 0x804A14AC: nop
    
            goto L_804A14B8;
    }
    // 0x804A14AC: nop

    // 0x804A14B0: sw          $v0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r2;
    // 0x804A14B4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_804A14B8:
    // 0x804A14B8: bne         $a1, $zero, L_804A147C
    if (ctx->r5 != 0) {
        // 0x804A14BC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_804A147C;
    }
    // 0x804A14BC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_804A14C0:
    // 0x804A14C0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x804A14C4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x804A14C8: lw          $v0, 0xF80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XF80);
    // 0x804A14CC: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
    // 0x804A14D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A14D4: beql        $v0, $zero, L_804A154C
    if (ctx->r2 == 0) {
        // 0x804A14D8: lh          $t5, 0x184($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X184);
            goto L_804A154C;
    }
    goto skip_0;
    // 0x804A14D8: lh          $t5, 0x184($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X184);
    skip_0:
    // 0x804A14DC: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x804A14E0: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x804A14E4: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X317C) << 16);
    // 0x804A14E8: addiu       $a0, $a0, -0x41F0
    ctx->r4 = ADD32(ctx->r4, -0X41F0);
    // 0x804A14EC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x804A14F0: bnel        $v0, $a0, L_804A1518
    if (ctx->r2 != ctx->r4) {
        // 0x804A14F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804A1518;
    }
    goto skip_1;
    // 0x804A14F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x804A14F8: lwc1        $f0, 0x35BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X317C));
    // 0x804A14FC: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x804A1500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A1504: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x804A1508: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x804A150C: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x804A1510: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x804A1514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_804A1518:
    // 0x804A1518: jal         0x804A27A0
    // 0x804A151C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    func_804A27A0(rdram, ctx);
        goto after_1;
    // 0x804A151C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_1:
    // 0x804A1520: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x804A1524: lui         $t4, 0x804A
    ctx->r12 = S32(RELOC_HI16(173, 0X2AA8) << 16);
    // 0x804A1528: andi        $t2, $t2, 0x7
    ctx->r10 = ctx->r10 & 0X7;
    // 0x804A152C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x804A1530: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x804A1534: sw          $t2, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r10;
    // 0x804A1538: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x804A153C: lhu         $t4, 0x2EE8($t4)
    ctx->r12 = MEM_HU(ctx->r12, (int16_t)RELOC_LO16(173, 0X2AA8));
    // 0x804A1540: b           L_804A157C
    // 0x804A1544: sh          $t4, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r12;
        goto L_804A157C;
    // 0x804A1544: sh          $t4, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r12;
    // 0x804A1548: lh          $t5, 0x184($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X184);
L_804A154C:
    // 0x804A154C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x804A1550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A1554: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x804A1558: bne         $at, $zero, L_804A1574
    if (ctx->r1 != 0) {
        // 0x804A155C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_804A1574;
    }
    // 0x804A155C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A1560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A1564: jal         0x804A27A0
    // 0x804A1568: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_2;
    // 0x804A1568: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x804A156C: b           L_804A1580
    // 0x804A1570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804A1580;
    // 0x804A1570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A1574:
    // 0x804A1574: jal         0x804A27A0
    // 0x804A1578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_3;
    // 0x804A1578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_804A157C:
    // 0x804A157C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A1580:
    // 0x804A1580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A1584: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804A1588: jr          $ra
    // 0x804A158C: nop

    return;
    // 0x804A158C: nop

;}
RECOMP_FUNC void func_80535CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80535CD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80535CD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80535CDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80535CE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80535CE8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80535CEC: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(351, 0X1350) << 16);
    // 0x80535CF0: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(351, 0X1364) << 16);
    // 0x80535CF4: addiu       $a1, $a1, 0x6BF4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(351, 0X1364));
    // 0x80535CF8: addiu       $a2, $a2, 0x6BE0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(351, 0X1350));
    // 0x80535CFC: jal         0x80535958
    // 0x80535D00: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80535958(rdram, ctx);
        goto after_0;
    // 0x80535D00: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x80535D04: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80535D08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535D0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535D10: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535D14: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80535D18: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535D24: jr          $ra
    // 0x80535D28: nop

    return;
    // 0x80535D28: nop

;}
RECOMP_FUNC void func_805D7DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7DE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D7DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D7DE8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805D7DEC: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(474, 0X24DC) << 16);
    // 0x805D7DF0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805D7DF4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805D7DF8: addiu       $t6, $t6, -0x6224
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(474, 0X24DC));
    // 0x805D7DFC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805D7E00: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D7E04: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x805D7E08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D7E0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805D7E10: jal         0x805D7E30
    // 0x805D7E14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805D7E30(rdram, ctx);
        goto after_0;
    // 0x805D7E14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x805D7E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D7E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D7E20: jr          $ra
    // 0x805D7E24: nop

    return;
    // 0x805D7E24: nop

;}
RECOMP_FUNC void func_8051F454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051F458: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(303, 0X900) << 16);
    // 0x8051F45C: addiu       $v0, $v0, -0x680
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(303, 0X900));
    // 0x8051F460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051F464: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8051F468: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8051F46C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8051F470: jalr        $t9
    // 0x8051F474: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8051F474: nop

    after_0:
    // 0x8051F478: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051F47C: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8051F480: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x8051F484: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8051F488: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8051F48C: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8051F490: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8051F494: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x8051F498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051F49C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051F4A0: jr          $ra
    // 0x8051F4A4: nop

    return;
    // 0x8051F4A4: nop

;}
RECOMP_FUNC void func_80453868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045386C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453870: jal         0x80453784
    // 0x80453874: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80453784(rdram, ctx);
        goto after_0;
    // 0x80453874: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80453878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045387C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453880: jr          $ra
    // 0x80453884: nop

    return;
    // 0x80453884: nop

;}
RECOMP_FUNC void func_80533980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533980: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80533984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80533988: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8053398C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80533990: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80533994: lui         $t7, 0x8053
    ctx->r15 = S32(RELOC_HI16(345, 0X1850) << 16);
    // 0x80533998: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8053399C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805339A0: addiu       $t7, $t7, 0x4320
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(345, 0X1850));
    // 0x805339A4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805339A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805339AC: jal         0x80533840
    // 0x805339B0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_80533840(rdram, ctx);
        goto after_0;
    // 0x805339B0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_0:
    // 0x805339B4: bne         $v0, $zero, L_805339CC
    if (ctx->r2 != 0) {
        // 0x805339B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805339CC;
    }
    // 0x805339B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805339BC: jal         0x800445A4
    // 0x805339C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805339C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805339C4: b           L_80533A6C
    // 0x805339C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80533A6C;
    // 0x805339C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805339CC:
    // 0x805339CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805339D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805339D4: jal         0x80533878
    // 0x805339D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80533878(rdram, ctx);
        goto after_2;
    // 0x805339D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x805339DC: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805339E0: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805339E4: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x805339E8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805339EC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x805339F0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805339F4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x805339F8: sw          $t9, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r25;
    // 0x805339FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80533A00: jal         0x8053319C
    // 0x80533A04: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    func_8053319C(rdram, ctx);
        goto after_3;
    // 0x80533A04: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    after_3:
    // 0x80533A08: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80533A0C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80533A10: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80533A14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80533A18: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80533A1C: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80533A20: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80533A24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80533A28: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80533A2C: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80533A30: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80533A34: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(345, 0X12C) << 16);
    // 0x80533A38: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80533A3C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80533A40: addiu       $t1, $t1, 0x2BFC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(345, 0X12C));
    // 0x80533A44: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80533A48: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x80533A4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80533A50: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80533A54: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x80533A58: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x80533A5C: sh          $t0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r8;
    // 0x80533A60: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x80533A64: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x80533A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80533A6C:
    // 0x80533A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80533A70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80533A74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80533A78: jr          $ra
    // 0x80533A7C: nop

    return;
    // 0x80533A7C: nop

;}
