#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80438CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438CE0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80438CE4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80438CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80438CEC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80438CF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80438CF4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80438CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80438CFC: jal         0x8004921C
    // 0x80438D00: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80438D00: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x80438D04: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80438D08: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80438D0C: jal         0x8004921C
    // 0x80438D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80438D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80438D14: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80438D18: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80438D1C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80438D20: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80438D24: lbu         $t8, 0x4B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4B);
    // 0x80438D28: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80438D2C: lw          $t3, 0x168($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X168);
    // 0x80438D30: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80438D34: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80438D38: lw          $t4, 0x80($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X80);
    // 0x80438D3C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80438D40: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80438D44: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80438D48: mflo        $t7
    ctx->r15 = lo;
    // 0x80438D4C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80438D50: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x80438D54: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80438D58: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80438D5C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80438D60: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x80438D64: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80438D68: lui         $t2, 0xF570
    ctx->r10 = S32(0XF570 << 16);
    // 0x80438D6C: lui         $t7, 0x71F
    ctx->r15 = S32(0X71F << 16);
    // 0x80438D70: ori         $t7, $t7, 0xF200
    ctx->r15 = ctx->r15 | 0XF200;
    // 0x80438D74: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80438D78: mflo        $t9
    ctx->r25 = lo;
    // 0x80438D7C: addu        $t0, $t9, $t4
    ctx->r8 = ADD32(ctx->r25, ctx->r12);
    // 0x80438D80: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80438D84: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80438D88: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80438D8C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80438D90: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80438D94: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80438D98: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80438D9C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80438DA0: lui         $t3, 0xF568
    ctx->r11 = S32(0XF568 << 16);
    // 0x80438DA4: ori         $t3, $t3, 0x800
    ctx->r11 = ctx->r11 | 0X800;
    // 0x80438DA8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80438DAC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80438DB0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80438DB4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80438DB8: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80438DBC: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x80438DC0: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80438DC4: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80438DC8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80438DCC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80438DD0: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80438DD4: lui         $t5, 0x7
    ctx->r13 = S32(0X7 << 16);
    // 0x80438DD8: ori         $t5, $t5, 0xC07C
    ctx->r13 = ctx->r13 | 0XC07C;
    // 0x80438DDC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80438DE0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80438DE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80438DE8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80438DEC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80438DF0: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80438DF4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80438DF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80438DFC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80438E00: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80438E04: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80438E08: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80438E0C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80438E10: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80438E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438E18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80438E1C: jr          $ra
    // 0x80438E20: nop

    return;
    // 0x80438E20: nop

;}
RECOMP_FUNC void func_804D63C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D63C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D63CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D63D0: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x804D63D4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x804D63D8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804D63DC: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x804D63E0: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(252, 0X574) << 16);
    // 0x804D63E4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804D63E8: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x804D63EC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804D63F0: addiu       $t8, $t8, 0x6874
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(252, 0X574));
    // 0x804D63F4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804D63F8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804D63FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D6400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804D6404: jal         0x804D6620
    // 0x804D6408: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804D6620(rdram, ctx);
        goto after_0;
    // 0x804D6408: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804D640C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D6410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D6414: jr          $ra
    // 0x804D6418: nop

    return;
    // 0x804D6418: nop

;}
RECOMP_FUNC void func_80737FAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737FAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80737FB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80737FB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80737FB8: jal         0x80737F40
    // 0x80737FBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80737F40(rdram, ctx);
        goto after_0;
    // 0x80737FBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80737FC0: bne         $v0, $zero, L_80737FD8
    if (ctx->r2 != 0) {
        // 0x80737FC4: nop
    
            goto L_80737FD8;
    }
    // 0x80737FC4: nop

    // 0x80737FC8: jal         0x800445A4
    // 0x80737FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80737FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80737FD0: b           L_80738040
    // 0x80737FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80738040;
    // 0x80737FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80737FD8:
    // 0x80737FD8: jal         0x80737020
    // 0x80737FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80737020(rdram, ctx);
        goto after_2;
    // 0x80737FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80737FE0: bne         $v0, $zero, L_80737FF8
    if (ctx->r2 != 0) {
        // 0x80737FE4: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_80737FF8;
    }
    // 0x80737FE4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80737FE8: jal         0x800445A4
    // 0x80737FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x80737FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80737FF0: b           L_80738040
    // 0x80737FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80738040;
    // 0x80737FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80737FF8:
    // 0x80737FF8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80737FFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80738000: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80738004: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    // 0x80738008: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8073800C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80738010: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x80738014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80738018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073801C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80738020: jal         0x80738050
    // 0x80738024: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80738050(rdram, ctx);
        goto after_4;
    // 0x80738024: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80738028: lui         $t9, 0x8073
    ctx->r25 = S32(RELOC_HI16(736, 0X2524) << 16);
    // 0x8073802C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80738030: addiu       $t9, $t9, 0x7F84
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(736, 0X2524));
    // 0x80738034: sh          $t8, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r24;
    // 0x80738038: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x8073803C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80738040:
    // 0x80738040: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80738044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80738048: jr          $ra
    // 0x8073804C: nop

    return;
    // 0x8073804C: nop

;}
RECOMP_FUNC void func_8064AF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AF88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AF8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AF90: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064AF94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8064AF98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064AF9C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064AFA0: nop

    // 0x8064AFA4: bc1fl       L_8064AFEC
    if (!c1cs) {
        // 0x8064AFA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064AFEC;
    }
    goto skip_0;
    // 0x8064AFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064AFAC: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064AFB0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064AFB4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8064AFB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064AFBC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064AFC0: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8064AFC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064AFC8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064AFCC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064AFD0: nop

    // 0x8064AFD4: bc1fl       L_8064AFEC
    if (!c1cs) {
        // 0x8064AFD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064AFEC;
    }
    goto skip_1;
    // 0x8064AFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064AFDC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064AFE0: jal         0x8064B3E0
    // 0x8064AFE4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064B3E0(rdram, ctx);
        goto after_0;
    // 0x8064AFE4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064AFE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064AFEC:
    // 0x8064AFEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064AFF0: jr          $ra
    // 0x8064AFF4: nop

    return;
    // 0x8064AFF4: nop

;}
RECOMP_FUNC void func_80433BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433BD8: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80433BDC: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80433BE0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80433BE4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80433BE8: nop

    // 0x80433BEC: bc1t        L_80433C04
    if (c1cs) {
        // 0x80433BF0: nop
    
            goto L_80433C04;
    }
    // 0x80433BF0: nop

    // 0x80433BF4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80433BF8: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80433BFC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80433C00: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_80433C04:
    // 0x80433C04: jr          $ra
    // 0x80433C08: nop

    return;
    // 0x80433C08: nop

;}
RECOMP_FUNC void func_8006E248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E24C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E250: jal         0x8006E1B0
    // 0x8006E254: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006E1B0(rdram, ctx);
        goto after_0;
    // 0x8006E254: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006E258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E25C: jal         0x80081C64
    // 0x8006E260: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x8006E260: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    after_1:
    // 0x8006E264: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006E268: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8006E26C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8006E270: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E274: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006E278: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8006E27C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E280: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006E284: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8006E288: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8006E28C: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8006E290: div.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8006E294: div.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8006E298: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x8006E29C: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x8006E2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E2A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E2A8: jr          $ra
    // 0x8006E2AC: nop

    return;
    // 0x8006E2AC: nop

;}
RECOMP_FUNC void func_804C2084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C2088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C208C: jal         0x804C2028
    // 0x804C2090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C2028(rdram, ctx);
        goto after_0;
    // 0x804C2090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C2094: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804C2098: bne         $v0, $at, L_804C20C4
    if (ctx->r2 != ctx->r1) {
        // 0x804C209C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C20C4;
    }
    // 0x804C209C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C20A0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804C20A4: bne         $t6, $zero, L_804C20BC
    if (ctx->r14 != 0) {
        // 0x804C20A8: nop
    
            goto L_804C20BC;
    }
    // 0x804C20A8: nop

    // 0x804C20AC: jal         0x804C227C
    // 0x804C20B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804C227C(rdram, ctx);
        goto after_1;
    // 0x804C20B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804C20B4: b           L_804C20C8
    // 0x804C20B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C20C8;
    // 0x804C20B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C20BC:
    // 0x804C20BC: jal         0x804C227C
    // 0x804C20C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804C227C(rdram, ctx);
        goto after_2;
    // 0x804C20C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_804C20C4:
    // 0x804C20C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C20C8:
    // 0x804C20C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C20CC: jr          $ra
    // 0x804C20D0: nop

    return;
    // 0x804C20D0: nop

;}
RECOMP_FUNC void func_806CFF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFF8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CFF90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CFF94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806CFF98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CFF9C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x806CFFA0: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x806CFFA4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806CFFA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806CFFAC: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x806CFFB0: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x806CFFB4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806CFFB8: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x806CFFBC: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806CFFC0: jal         0x800659EC
    // 0x806CFFC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x806CFFC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x806CFFC8: lui         $at, 0x43A2
    ctx->r1 = S32(0X43A2 << 16);
    // 0x806CFFCC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806CFFD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806CFFD4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806CFFD8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806CFFDC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x806CFFE0: swc1        $f6, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f6.u32l;
    // 0x806CFFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CFFE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CFFEC: jr          $ra
    // 0x806CFFF0: nop

    return;
    // 0x806CFFF0: nop

;}
RECOMP_FUNC void func_80579C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80579C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80579C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80579C20: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80579C24: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80579C28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80579C2C: bne         $a1, $at, L_80579C50
    if (ctx->r5 != ctx->r1) {
        // 0x80579C30: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80579C50;
    }
    // 0x80579C30: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80579C34: lw          $a0, 0x48C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48C);
    // 0x80579C38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80579C3C: jal         0x80067F78
    // 0x80579C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067F78(rdram, ctx);
        goto after_0;
    // 0x80579C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80579C44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80579C48: b           L_80579C5C
    // 0x80579C4C: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
        goto L_80579C5C;
    // 0x80579C4C: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
L_80579C50:
    // 0x80579C50: lw          $a0, 0x48C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48C);
    // 0x80579C54: jal         0x800678F0
    // 0x80579C58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800678F0(rdram, ctx);
        goto after_1;
    // 0x80579C58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80579C5C:
    // 0x80579C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80579C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80579C64: jr          $ra
    // 0x80579C68: nop

    return;
    // 0x80579C68: nop

;}
RECOMP_FUNC void func_8042F868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F868: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042F86C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8042F870: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8042F874: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8042F878: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8042F87C: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x8042F880: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042F884: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8042F888: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8042F88C: jr          $ra
    // 0x8042F890: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x8042F890: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8056934C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056934C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80569350: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x80569354: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80569358: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8056935C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80569360: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x80569364: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80569368: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8056936C: slti        $at, $t7, 0x96
    ctx->r1 = SIGNED(ctx->r15) < 0X96 ? 1 : 0;
    // 0x80569370: bne         $at, $zero, L_80569380
    if (ctx->r1 != 0) {
        // 0x80569374: addiu       $a0, $zero, 0x4159
        ctx->r4 = ADD32(0, 0X4159);
            goto L_80569380;
    }
    // 0x80569374: addiu       $a0, $zero, 0x4159
    ctx->r4 = ADD32(0, 0X4159);
    // 0x80569378: b           L_805694DC
    // 0x8056937C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805694DC;
    // 0x8056937C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80569380:
    // 0x80569380: jal         0x80047090
    // 0x80569384: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80569384: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x80569388: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x8056938C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80569390: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80569394: addiu       $t9, $t8, -0x4159
    ctx->r25 = ADD32(ctx->r24, -0X4159);
    // 0x80569398: sltiu       $at, $t9, 0x25
    ctx->r1 = ctx->r25 < 0X25 ? 1 : 0;
    // 0x8056939C: beq         $at, $zero, L_80569414
    if (ctx->r1 == 0) {
        // 0x805693A0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80569414;
    }
    // 0x805693A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805693A4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2228) << 16);
    // 0x805693A8: addu        $at, $at, $t9
    gpr jr_addend_805693B0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x805693AC: lw          $t9, -0x6828($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(378, 0X2228));
    // 0x805693B0: jr          $t9
    // 0x805693B4: nop

    switch (jr_addend_805693B0 >> 2) {
        case 0: goto L_80569414; break;
        case 1: goto L_805693C8; break;
        case 2: goto L_80569414; break;
        case 3: goto L_80569414; break;
        case 4: goto L_80569414; break;
        case 5: goto L_80569414; break;
        case 6: goto L_80569414; break;
        case 7: goto L_80569414; break;
        case 8: goto L_80569414; break;
        case 9: goto L_80569414; break;
        case 10: goto L_80569414; break;
        case 11: goto L_80569414; break;
        case 12: goto L_805693B8; break;
        case 13: goto L_805693D0; break;
        case 14: goto L_80569414; break;
        case 15: goto L_80569414; break;
        case 16: goto L_80569414; break;
        case 17: goto L_80569414; break;
        case 18: goto L_80569414; break;
        case 19: goto L_80569414; break;
        case 20: goto L_80569414; break;
        case 21: goto L_80569414; break;
        case 22: goto L_80569414; break;
        case 23: goto L_80569414; break;
        case 24: goto L_805693C0; break;
        case 25: goto L_805693D8; break;
        case 26: goto L_80569414; break;
        case 27: goto L_80569414; break;
        case 28: goto L_80569414; break;
        case 29: goto L_80569414; break;
        case 30: goto L_80569414; break;
        case 31: goto L_80569414; break;
        case 32: goto L_80569414; break;
        case 33: goto L_80569414; break;
        case 34: goto L_80569414; break;
        case 35: goto L_805693E0; break;
        case 36: goto L_805693FC; break;
        default: switch_error(__func__, 0x805693B0, 0x805697D8);
    }
    // 0x805693B4: nop

L_805693B8:
    // 0x805693B8: b           L_80569414
    // 0x805693BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80569414;
    // 0x805693BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805693C0:
    // 0x805693C0: b           L_80569414
    // 0x805693C4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80569414;
    // 0x805693C4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_805693C8:
    // 0x805693C8: b           L_80569414
    // 0x805693CC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80569414;
    // 0x805693CC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_805693D0:
    // 0x805693D0: b           L_80569414
    // 0x805693D4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80569414;
    // 0x805693D4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_805693D8:
    // 0x805693D8: b           L_80569414
    // 0x805693DC: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80569414;
    // 0x805693DC: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_805693E0:
    // 0x805693E0: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x805693E4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x805693E8: jal         0x80047090
    // 0x805693EC: addiu       $a0, $zero, 0x417C
    ctx->r4 = ADD32(0, 0X417C);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x805693EC: addiu       $a0, $zero, 0x417C
    ctx->r4 = ADD32(0, 0X417C);
    after_1:
    // 0x805693F0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x805693F4: b           L_80569414
    // 0x805693F8: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
        goto L_80569414;
    // 0x805693F8: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
L_805693FC:
    // 0x805693FC: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80569400: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80569404: jal         0x80047090
    // 0x80569408: addiu       $a0, $zero, 0x417D
    ctx->r4 = ADD32(0, 0X417D);
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x80569408: addiu       $a0, $zero, 0x417D
    ctx->r4 = ADD32(0, 0X417D);
    after_2:
    // 0x8056940C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80569410: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
L_80569414:
    // 0x80569414: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80569418: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8056941C: beq         $t1, $at, L_805694D8
    if (ctx->r9 == ctx->r1) {
        // 0x80569420: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_805694D8;
    }
    // 0x80569420: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80569424: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80569428: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
    // 0x8056942C: sll         $t2, $t2, 6
    ctx->r10 = S32(ctx->r10 << 6);
    // 0x80569430: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80569434: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80569438: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8056943C: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80569440: lui         $t3, 0x8057
    ctx->r11 = S32(RELOC_HI16(378, 0X2880) << 16);
    // 0x80569444: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80569448: ori         $t6, $t5, 0x400
    ctx->r14 = ctx->r13 | 0X400;
    // 0x8056944C: addiu       $t3, $t3, -0x61D0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(378, 0X2880));
    // 0x80569450: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80569454: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80569458: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8056945C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80569460: or          $a1, $t6, $t0
    ctx->r5 = ctx->r14 | ctx->r8;
    // 0x80569464: jal         0x80046804
    // 0x80569468: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_3;
    // 0x80569468: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8056946C: beql        $v0, $zero, L_805694DC
    if (ctx->r2 == 0) {
        // 0x80569470: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805694DC;
    }
    goto skip_0;
    // 0x80569470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80569474: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80569478: addiu       $a1, $v0, 0xC4
    ctx->r5 = ADD32(ctx->r2, 0XC4);
    // 0x8056947C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80569480: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x80569484: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80569488: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x8056948C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80569490: jal         0x80048378
    // 0x80569494: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80048378(rdram, ctx);
        goto after_4;
    // 0x80569494: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_4:
    // 0x80569498: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8056949C: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x805694A0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x805694A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805694A8: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x805694AC: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x805694B0: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x805694B4: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x805694B8: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x805694BC: swc1        $f18, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f18.u32l;
    // 0x805694C0: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x805694C4: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x805694C8: jal         0x80044194
    // 0x805694CC: swc1        $f4, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f4.u32l;
    func_80044194(rdram, ctx);
        goto after_5;
    // 0x805694CC: swc1        $f4, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f4.u32l;
    after_5:
    // 0x805694D0: b           L_805694DC
    // 0x805694D4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_805694DC;
    // 0x805694D4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_805694D8:
    // 0x805694D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805694DC:
    // 0x805694DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805694E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805694E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805694E8: jr          $ra
    // 0x805694EC: nop

    return;
    // 0x805694EC: nop

;}
RECOMP_FUNC void func_804BA638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BA63C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BA640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BA644: jal         0x80045A34
    // 0x804BA648: addiu       $a1, $zero, 0xB70
    ctx->r5 = ADD32(0, 0XB70);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804BA648: addiu       $a1, $zero, 0xB70
    ctx->r5 = ADD32(0, 0XB70);
    after_0:
    // 0x804BA64C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BA650: bne         $v0, $zero, L_804BA660
    if (ctx->r2 != 0) {
        // 0x804BA654: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804BA660;
    }
    // 0x804BA654: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804BA658: b           L_804BA66C
    // 0x804BA65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BA66C;
    // 0x804BA65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BA660:
    // 0x804BA660: jal         0x804BA5DC
    // 0x804BA664: nop

    func_804BA5DC(rdram, ctx);
        goto after_1;
    // 0x804BA664: nop

    after_1:
    // 0x804BA668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804BA66C:
    // 0x804BA66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BA670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BA674: jr          $ra
    // 0x804BA678: nop

    return;
    // 0x804BA678: nop

;}
RECOMP_FUNC void func_80517944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051794C: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80517950: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(288, 0X5F0) << 16);
    // 0x80517954: addiu       $t8, $t8, 0x7B70
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(288, 0X5F0));
    // 0x80517958: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8051795C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80517960: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80517964: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80517968: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8051796C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80517970: beql        $v1, $zero, L_805179A4
    if (ctx->r3 == 0) {
        // 0x80517974: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805179A4;
    }
    goto skip_0;
    // 0x80517974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80517978: jalr        $v1
    // 0x8051797C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8051797C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80517980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80517984: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x80517988: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x8051798C: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80517990: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80517994: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80517998: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8051799C: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x805179A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805179A4:
    // 0x805179A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805179A8: jr          $ra
    // 0x805179AC: nop

    return;
    // 0x805179AC: nop

;}
RECOMP_FUNC void func_8044F178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044F178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044F17C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044F180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8044F184: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044F188: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F18C: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
    // 0x8044F190: addu        $t0, $a3, $at
    ctx->r8 = ADD32(ctx->r7, ctx->r1);
    // 0x8044F194: lw          $a2, 0x6A28($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X6A28);
    // 0x8044F198: beql        $a2, $v0, L_8044F280
    if (ctx->r6 == ctx->r2) {
        // 0x8044F19C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044F280;
    }
    goto skip_0;
    // 0x8044F19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044F1A0: lw          $t7, 0x6A40($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X6A40);
    // 0x8044F1A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8044F1A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8044F1AC: bne         $v0, $t7, L_8044F27C
    if (ctx->r2 != ctx->r15) {
        // 0x8044F1B0: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8044F27C;
    }
    // 0x8044F1B0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F1B4: addu        $v0, $a3, $at
    ctx->r2 = ADD32(ctx->r7, ctx->r1);
    // 0x8044F1B8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8044F1BC:
    // 0x8044F1BC: lw          $t8, 0x6A4C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X6A4C);
    // 0x8044F1C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8044F1C4: beql        $t8, $zero, L_8044F214
    if (ctx->r24 == 0) {
        // 0x8044F1C8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8044F214;
    }
    goto skip_1;
    // 0x8044F1C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x8044F1CC: beq         $a1, $a2, L_8044F210
    if (ctx->r5 == ctx->r6) {
        // 0x8044F1D0: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8044F210;
    }
    // 0x8044F1D0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F1D4: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8044F1D8: sw          $a1, 0x6A40($at)
    MEM_W(0X6A40, ctx->r1) = ctx->r5;
    // 0x8044F1DC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F1E0: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8044F1E4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8044F1E8: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X131A4) << 16);
    // 0x8044F1EC: sw          $t9, 0x6A48($at)
    MEM_W(0X6A48, ctx->r1) = ctx->r25;
    // 0x8044F1F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8044F1F4: lw          $v0, 0x7584($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(98, 0X131A4));
    // 0x8044F1F8: beql        $v0, $zero, L_8044F280
    if (ctx->r2 == 0) {
        // 0x8044F1FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044F280;
    }
    goto skip_2;
    // 0x8044F1FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8044F200: jalr        $v0
    // 0x8044F204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8044F204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x8044F208: b           L_8044F280
    // 0x8044F20C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044F280;
    // 0x8044F20C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044F210:
    // 0x8044F210: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8044F214:
    // 0x8044F214: bne         $a1, $a0, L_8044F1BC
    if (ctx->r5 != ctx->r4) {
        // 0x8044F218: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8044F1BC;
    }
    // 0x8044F218: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8044F21C: lw          $t1, 0x6A90($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6A90);
    // 0x8044F220: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8044F224: beql        $t1, $zero, L_8044F254
    if (ctx->r9 == 0) {
        // 0x8044F228: lw          $t3, 0x6A8C($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X6A8C);
            goto L_8044F254;
    }
    goto skip_3;
    // 0x8044F228: lw          $t3, 0x6A8C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X6A8C);
    skip_3:
    // 0x8044F22C: beq         $a2, $v0, L_8044F250
    if (ctx->r6 == ctx->r2) {
        // 0x8044F230: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8044F250;
    }
    // 0x8044F230: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F234: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8044F238: sw          $v0, 0x6A40($at)
    MEM_W(0X6A40, ctx->r1) = ctx->r2;
    // 0x8044F23C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F240: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8044F244: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8044F248: b           L_8044F27C
    // 0x8044F24C: sw          $t2, 0x6A48($at)
    MEM_W(0X6A48, ctx->r1) = ctx->r10;
        goto L_8044F27C;
    // 0x8044F24C: sw          $t2, 0x6A48($at)
    MEM_W(0X6A48, ctx->r1) = ctx->r10;
L_8044F250:
    // 0x8044F250: lw          $t3, 0x6A8C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X6A8C);
L_8044F254:
    // 0x8044F254: beql        $t3, $zero, L_8044F280
    if (ctx->r11 == 0) {
        // 0x8044F258: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044F280;
    }
    goto skip_4;
    // 0x8044F258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8044F25C: beq         $a2, $a0, L_8044F27C
    if (ctx->r6 == ctx->r4) {
        // 0x8044F260: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8044F27C;
    }
    // 0x8044F260: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F264: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8044F268: sw          $a0, 0x6A40($at)
    MEM_W(0X6A40, ctx->r1) = ctx->r4;
    // 0x8044F26C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F270: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8044F274: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8044F278: sw          $t4, 0x6A48($at)
    MEM_W(0X6A48, ctx->r1) = ctx->r12;
L_8044F27C:
    // 0x8044F27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044F280:
    // 0x8044F280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044F284: jr          $ra
    // 0x8044F288: nop

    return;
    // 0x8044F288: nop

;}
RECOMP_FUNC void func_80453AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453AA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453AAC: jal         0x804539F0
    // 0x80453AB0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_804539F0(rdram, ctx);
        goto after_0;
    // 0x80453AB0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80453AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453AB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453ABC: jr          $ra
    // 0x80453AC0: nop

    return;
    // 0x80453AC0: nop

;}
RECOMP_FUNC void func_80040FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040FDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80040FE0: jal         0x80065954
    // 0x80040FE4: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80040FE4: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x80040FE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80040FEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040FF0: nop

    // 0x80040FF4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80040FF8: nop

    // 0x80040FFC: bc1f        L_8004100C
    if (!c1cs) {
        // 0x80041000: nop
    
            goto L_8004100C;
    }
    // 0x80041000: nop

    // 0x80041004: b           L_80041014
    // 0x80041008: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80041014;
    // 0x80041008: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8004100C:
    // 0x8004100C: jal         0x80040F5C
    // 0x80041010: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80040F5C(rdram, ctx);
        goto after_1;
    // 0x80041010: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80041014:
    // 0x80041014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004101C: jr          $ra
    // 0x80041020: nop

    return;
    // 0x80041020: nop

;}
RECOMP_FUNC void func_80039F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039F00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80039F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039F08: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80039F0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80039F10: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80039F14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80039F18: sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
    // 0x80039F1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80039F20: jal         0x8003B540
    // 0x80039F24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8003B540(rdram, ctx);
        goto after_0;
    // 0x80039F24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80039F28: jal         0x8003AF4C
    // 0x80039F2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8003AF4C(rdram, ctx);
        goto after_1;
    // 0x80039F2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80039F30: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80039F34: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
    // 0x80039F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039F3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80039F40: jr          $ra
    // 0x80039F44: nop

    return;
    // 0x80039F44: nop

;}
RECOMP_FUNC void func_806E5BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5BE0: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(652, 0X18) << 16);
    // 0x806E5BE4: addiu       $v0, $v0, 0x5BF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(652, 0X18));
    // 0x806E5BE8: jr          $ra
    // 0x806E5BEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806E5BEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80584A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584A8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584A90: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584A94: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584A98: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584A9C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584AA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584AA4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584AA8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584AAC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584AB0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584AB4: jr          $ra
    // 0x80584AB8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584AB8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80448574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448578: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044857C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80448580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448584: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80448588: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8044858C: bne         $a2, $zero, L_804485F4
    if (ctx->r6 != 0) {
        // 0x80448590: lw          $t0, 0x1F4($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X1F4);
            goto L_804485F4;
    }
    // 0x80448590: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448594: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X13248) << 16);
    // 0x80448598: lw          $v0, 0x7628($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(98, 0X13248));
    // 0x8044859C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x804485A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804485A4: beq         $v0, $zero, L_804485C4
    if (ctx->r2 == 0) {
        // 0x804485A8: nop
    
            goto L_804485C4;
    }
    // 0x804485A8: nop

    // 0x804485AC: jalr        $v0
    // 0x804485B0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x804485B0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x804485B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804485B8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x804485BC: b           L_804485C4
    // 0x804485C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_804485C4;
    // 0x804485C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_804485C4:
    // 0x804485C4: bne         $v1, $zero, L_804485D4
    if (ctx->r3 != 0) {
        // 0x804485C8: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_804485D4;
    }
    // 0x804485C8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x804485CC: b           L_80448638
    // 0x804485D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80448638;
    // 0x804485D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804485D4:
    // 0x804485D4: lw          $t6, 0x14($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X14);
    // 0x804485D8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x804485DC: bgtz        $t8, L_80448634
    if (SIGNED(ctx->r24) > 0) {
        // 0x804485E0: sw          $t8, 0x14($t0)
        MEM_W(0X14, ctx->r8) = ctx->r24;
            goto L_80448634;
    }
    // 0x804485E0: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
    // 0x804485E4: jal         0x8044650C
    // 0x804485E8: nop

    func_8044650C(rdram, ctx);
        goto after_1;
    // 0x804485E8: nop

    after_1:
    // 0x804485EC: b           L_80448638
    // 0x804485F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80448638;
    // 0x804485F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804485F4:
    // 0x804485F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804485F8: bnel        $a2, $at, L_80448624
    if (ctx->r6 != ctx->r1) {
        // 0x804485FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80448624;
    }
    goto skip_0;
    // 0x804485FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448600: jal         0x804464B4
    // 0x80448604: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_804464B4(rdram, ctx);
        goto after_2;
    // 0x80448604: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80448608: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044860C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448610: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80448614: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80448618: b           L_80448634
    // 0x8044861C: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
        goto L_80448634;
    // 0x8044861C: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
    // 0x80448620: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80448624:
    // 0x80448624: bnel        $a2, $at, L_80448638
    if (ctx->r6 != ctx->r1) {
        // 0x80448628: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80448638;
    }
    goto skip_1;
    // 0x80448628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8044862C: jal         0x8044650C
    // 0x80448630: nop

    func_8044650C(rdram, ctx);
        goto after_3;
    // 0x80448630: nop

    after_3:
L_80448634:
    // 0x80448634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80448638:
    // 0x80448638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044863C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80448640: jr          $ra
    // 0x80448644: nop

    return;
    // 0x80448644: nop

;}
RECOMP_FUNC void func_8003C764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C764: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003C768: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8003C76C: srl         $t6, $a0, 6
    ctx->r14 = S32(U32(ctx->r4) >> 6);
    // 0x8003C770: andi        $t8, $a0, 0x3F
    ctx->r24 = ctx->r4 & 0X3F;
    // 0x8003C774: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003C778: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8003C77C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8003C780: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8003C784: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8003C788: andi        $t2, $a2, 0xF
    ctx->r10 = ctx->r6 & 0XF;
    // 0x8003C78C: lw          $t1, 0xA24($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XA24);
    // 0x8003C790: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8003C794: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8003C798: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8003C79C: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8003C7A0: andi        $t7, $a1, 0xF
    ctx->r15 = ctx->r5 & 0XF;
    // 0x8003C7A4: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x8003C7A8: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x8003C7AC: subu        $t0, $t9, $t7
    ctx->r8 = SUB32(ctx->r25, ctx->r15);
    // 0x8003C7B0: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x8003C7B4: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8003C7B8: srav        $v0, $t8, $t3
    ctx->r2 = S32(SIGNED(ctx->r24) >> (ctx->r11 & 31));
    // 0x8003C7BC: jr          $ra
    // 0x8003C7C0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    return;
    // 0x8003C7C0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
;}
RECOMP_FUNC void func_80425638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042563C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80425640: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80425644: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80425648: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(35, 0X2D50) << 16);
    // 0x8042564C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80425650: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80425654: addiu       $t7, $t7, 0x5750
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(35, 0X2D50));
    // 0x80425658: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8042565C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80425660: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80425664: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80425668: jal         0x80425680
    // 0x8042566C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80425680(rdram, ctx);
        goto after_0;
    // 0x8042566C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80425670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80425674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80425678: jr          $ra
    // 0x8042567C: nop

    return;
    // 0x8042567C: nop

;}
RECOMP_FUNC void func_804BE788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE788: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BE78C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BE790: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804BE794: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BE798: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BE79C: lw          $t8, 0x370($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X370);
    // 0x804BE7A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804BE7A4: jal         0x8004700C
    // 0x804BE7A8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804BE7A8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x804BE7AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804BE7B0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804BE7B4: lh          $t9, 0x2A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2A);
    // 0x804BE7B8: bne         $v0, $zero, L_804BE7CC
    if (ctx->r2 != 0) {
        // 0x804BE7BC: sh          $t9, 0x2C($a0)
        MEM_H(0X2C, ctx->r4) = ctx->r25;
            goto L_804BE7CC;
    }
    // 0x804BE7BC: sh          $t9, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r25;
    // 0x804BE7C0: sh          $zero, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = 0;
    // 0x804BE7C4: b           L_804BE818
    // 0x804BE7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BE818;
    // 0x804BE7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BE7CC:
    // 0x804BE7CC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x804BE7D0: lw          $t1, 0x180($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X180);
    // 0x804BE7D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804BE7D8: bnel        $t0, $t1, L_804BE818
    if (ctx->r8 != ctx->r9) {
        // 0x804BE7DC: sh          $zero, 0x2A($a0)
        MEM_H(0X2A, ctx->r4) = 0;
            goto L_804BE818;
    }
    goto skip_0;
    // 0x804BE7DC: sh          $zero, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = 0;
    skip_0:
    // 0x804BE7E0: lh          $t3, 0x2C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2C);
    // 0x804BE7E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x804BE7E8: sh          $t2, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r10;
    // 0x804BE7EC: beq         $t3, $zero, L_804BE80C
    if (ctx->r11 == 0) {
        // 0x804BE7F0: nop
    
            goto L_804BE80C;
    }
    // 0x804BE7F0: nop

    // 0x804BE7F4: lw          $a0, 0x34($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X34);
    // 0x804BE7F8: jal         0x80067BBC
    // 0x804BE7FC: lw          $a1, 0x38($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x804BE7FC: lw          $a1, 0x38($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X38);
    after_1:
    // 0x804BE800: addiu       $a0, $zero, 0x20C
    ctx->r4 = ADD32(0, 0X20C);
    // 0x804BE804: jal         0x80067818
    // 0x804BE808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x804BE808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_804BE80C:
    // 0x804BE80C: b           L_804BE818
    // 0x804BE810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804BE818;
    // 0x804BE810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804BE814: sh          $zero, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = 0;
L_804BE818:
    // 0x804BE818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BE81C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BE820: jr          $ra
    // 0x804BE824: nop

    return;
    // 0x804BE824: nop

;}
RECOMP_FUNC void func_806B0934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0934: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806B0938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806B093C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806B0940: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806B0944: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806B0948: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806B094C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x806B0950: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806B0954: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x806B0958: lw          $s0, 0x108($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X108);
    // 0x806B095C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806B0960: bc1t        L_806B0978
    if (c1cs) {
        // 0x806B0964: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_806B0978;
    }
    // 0x806B0964: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806B0968: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x806B096C: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x806B0970: bnel        $t7, $zero, L_806B09D8
    if (ctx->r15 != 0) {
        // 0x806B0974: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806B09D8;
    }
    goto skip_0;
    // 0x806B0974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
L_806B0978:
    // 0x806B0978: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x806B097C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x806B0980: jal         0x806B005C
    // 0x806B0984: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    func_806B005C(rdram, ctx);
        goto after_0;
    // 0x806B0984: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x806B0988: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x806B098C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806B0990: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x806B0994: bne         $t9, $at, L_806B09AC
    if (ctx->r25 != ctx->r1) {
        // 0x806B0998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806B09AC;
    }
    // 0x806B0998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806B099C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806B09A0: jal         0x806B04B8
    // 0x806B09A4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_806B04B8(rdram, ctx);
        goto after_1;
    // 0x806B09A4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x806B09A8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_806B09AC:
    // 0x806B09AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806B09B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806B09B4: jal         0x806B07E8
    // 0x806B09B8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_806B07E8(rdram, ctx);
        goto after_2;
    // 0x806B09B8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x806B09BC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x806B09C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806B09C4: jal         0x806B08E8
    // 0x806B09C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_806B08E8(rdram, ctx);
        goto after_3;
    // 0x806B09C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x806B09CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806B09D0: nop

    // 0x806B09D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_806B09D8:
    // 0x806B09D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B09DC: swc1        $f2, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f2.u32l;
    // 0x806B09E0: swc1        $f2, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f2.u32l;
    // 0x806B09E4: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
    // 0x806B09E8: swc1        $f0, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f0.u32l;
    // 0x806B09EC: swc1        $f0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f0.u32l;
    // 0x806B09F0: swc1        $f0, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f0.u32l;
    // 0x806B09F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806B09F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806B09FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806B0A00: jr          $ra
    // 0x806B0A04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806B0A04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806A9E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9E6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806A9E70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806A9E74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806A9E78: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A9E7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806A9E80: jal         0x806A9A30
    // 0x806A9E84: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_806A9A30(rdram, ctx);
        goto after_0;
    // 0x806A9E84: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x806A9E88: bne         $v0, $zero, L_806A9EB8
    if (ctx->r2 != 0) {
        // 0x806A9E8C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_806A9EB8;
    }
    // 0x806A9E8C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x806A9E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A9E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9E98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806A9E9C: jal         0x806AA784
    // 0x806A9EA0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806A9EA0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x806A9EA4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x806A9EA8: lhu         $t6, 0x1C0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1C0);
    // 0x806A9EAC: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x806A9EB0: b           L_806A9F40
    // 0x806A9EB4: sh          $t7, 0x1C0($v0)
    MEM_H(0X1C0, ctx->r2) = ctx->r15;
        goto L_806A9F40;
    // 0x806A9EB4: sh          $t7, 0x1C0($v0)
    MEM_H(0X1C0, ctx->r2) = ctx->r15;
L_806A9EB8:
    // 0x806A9EB8: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x806A9EBC: lh          $t2, 0x1BE($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X1BE);
    // 0x806A9EC0: lh          $t8, 0x144($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X144);
    // 0x806A9EC4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x806A9EC8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x806A9ECC: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x806A9ED0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806A9ED4: sh          $t1, 0x12C($t4)
    MEM_H(0X12C, ctx->r12) = ctx->r9;
    // 0x806A9ED8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806A9EDC: lw          $t5, 0x68($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X68);
    // 0x806A9EE0: bnel        $t5, $zero, L_806A9F1C
    if (ctx->r13 != 0) {
        // 0x806A9EE4: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_806A9F1C;
    }
    goto skip_0;
    // 0x806A9EE4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x806A9EE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806A9EEC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806A9EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A9EF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9EF8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806A9EFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806A9F00: bc1f        L_806A9F40
    if (!c1cs) {
        // 0x806A9F04: nop
    
            goto L_806A9F40;
    }
    // 0x806A9F04: nop

    // 0x806A9F08: jal         0x806AA784
    // 0x806A9F0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806AA784(rdram, ctx);
        goto after_2;
    // 0x806A9F0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x806A9F10: b           L_806A9F40
    // 0x806A9F14: nop

        goto L_806A9F40;
    // 0x806A9F14: nop

    // 0x806A9F18: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_806A9F1C:
    // 0x806A9F1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806A9F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A9F24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9F28: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806A9F2C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806A9F30: bc1f        L_806A9F40
    if (!c1cs) {
        // 0x806A9F34: nop
    
            goto L_806A9F40;
    }
    // 0x806A9F34: nop

    // 0x806A9F38: jal         0x806AA784
    // 0x806A9F3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806AA784(rdram, ctx);
        goto after_3;
    // 0x806A9F3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_806A9F40:
    // 0x806A9F40: jal         0x806A99EC
    // 0x806A9F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A99EC(rdram, ctx);
        goto after_4;
    // 0x806A9F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806A9F48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806A9F4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806A9F50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806A9F54: jr          $ra
    // 0x806A9F58: nop

    return;
    // 0x806A9F58: nop

;}
RECOMP_FUNC void func_8043CC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043CC10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043CC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043CC18: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043CC1C: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043CC20: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8043CC24: lwc1        $f6, 0x324($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X324);
    // 0x8043CC28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8043CC2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8043CC30: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043CC34: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8043CC38: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8043CC3C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043CC40: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8043CC44: nop

    // 0x8043CC48: bc1fl       L_8043CC68
    if (!c1cs) {
        // 0x8043CC4C: c.lt.s      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
            goto L_8043CC68;
    }
    goto skip_0;
    // 0x8043CC4C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    skip_0:
    // 0x8043CC50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043CC54: nop

    // 0x8043CC58: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8043CC5C: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x8043CC60: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043CC64: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
L_8043CC68:
    // 0x8043CC68: nop

    // 0x8043CC6C: bc1f        L_8043CC7C
    if (!c1cs) {
        // 0x8043CC70: nop
    
            goto L_8043CC7C;
    }
    // 0x8043CC70: nop

    // 0x8043CC74: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8043CC78: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
L_8043CC7C:
    // 0x8043CC7C: jal         0x8043C984
    // 0x8043CC80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043C984(rdram, ctx);
        goto after_0;
    // 0x8043CC80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043CC84: jal         0x8043C818
    // 0x8043CC88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043C818(rdram, ctx);
        goto after_1;
    // 0x8043CC88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043CC8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043CC90: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8043CC94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043CC98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043CC9C: jr          $ra
    // 0x8043CCA0: nop

    return;
    // 0x8043CCA0: nop

;}
RECOMP_FUNC void func_806F95BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F95BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F95C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F95C4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806F95C8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806F95CC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806F95D0: beq         $v0, $at, L_806F95FC
    if (ctx->r2 == ctx->r1) {
        // 0x806F95D4: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_806F95FC;
    }
    // 0x806F95D4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F95D8: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x806F95DC: bne         $v0, $at, L_806F965C
    if (ctx->r2 != ctx->r1) {
        // 0x806F95E0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_806F965C;
    }
    // 0x806F95E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F95E4: jal         0x806F9A9C
    // 0x806F95E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_806F9A9C(rdram, ctx);
        goto after_0;
    // 0x806F95E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806F95EC: jal         0x8005FE48
    // 0x806F95F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x806F95F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x806F95F4: b           L_806F9660
    // 0x806F95F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F9660;
    // 0x806F95F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F95FC:
    // 0x806F95FC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x806F9600: bnel        $t6, $zero, L_806F9660
    if (ctx->r14 != 0) {
        // 0x806F9604: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F9660;
    }
    goto skip_0;
    // 0x806F9604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F9608: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x806F960C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806F9610: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x806F9614: beql        $at, $zero, L_806F9660
    if (ctx->r1 == 0) {
        // 0x806F9618: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F9660;
    }
    goto skip_1;
    // 0x806F9618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806F961C: lbu         $t8, -0x764C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X764C);
    // 0x806F9620: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806F9624: bnel        $t8, $zero, L_806F9660
    if (ctx->r24 != 0) {
        // 0x806F9628: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F9660;
    }
    goto skip_2;
    // 0x806F9628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x806F962C: jal         0x8004012C
    // 0x806F9630: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8004012C(rdram, ctx);
        goto after_2;
    // 0x806F9630: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x806F9634: jal         0x8001D770
    // 0x806F9638: nop

    func_8001D770(rdram, ctx);
        goto after_3;
    // 0x806F9638: nop

    after_3:
    // 0x806F963C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806F9640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806F9644: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x806F9648: jal         0x80067BF8
    // 0x806F964C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_4;
    // 0x806F964C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_4:
    // 0x806F9650: addiu       $a0, $zero, 0x21B
    ctx->r4 = ADD32(0, 0X21B);
    // 0x806F9654: jal         0x80067818
    // 0x806F9658: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806F9658: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
L_806F965C:
    // 0x806F965C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F9660:
    // 0x806F9660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9664: jr          $ra
    // 0x806F9668: nop

    return;
    // 0x806F9668: nop

;}
RECOMP_FUNC void func_80711664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80711664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80711668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8071166C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80711670: beql        $a1, $zero, L_80711684
    if (ctx->r5 == 0) {
        // 0x80711674: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80711684;
    }
    goto skip_0;
    // 0x80711674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80711678: jal         0x800545F4
    // 0x8071167C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800545F4(rdram, ctx);
        goto after_0;
    // 0x8071167C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80711680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80711684:
    // 0x80711684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80711688: jr          $ra
    // 0x8071168C: nop

    return;
    // 0x8071168C: nop

;}
RECOMP_FUNC void pad_logical_stick_x(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FBB4: jr          $ra
    // 0x8007FBB8: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    return;
    // 0x8007FBB8: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
;}
RECOMP_FUNC void func_8064E1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E1E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064E1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064E1F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8064E1F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064E1F8: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8064E1FC: jal         0x80066DE4
    // 0x8064E200: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8064E200: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8064E204: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8064E208: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8064E20C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8064E210: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8064E214: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8064E218: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8064E21C: jal         0x80066E88
    // 0x8064E220: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8064E220: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8064E224: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8064E228: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8064E22C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8064E230: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8064E234: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8064E238: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x8064E23C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8064E240: add.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8064E244: swc1        $f2, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f2.u32l;
    // 0x8064E248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064E24C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064E250: jr          $ra
    // 0x8064E254: nop

    return;
    // 0x8064E254: nop

;}
RECOMP_FUNC void func_806F6800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6800: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806F6804: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x806F6808: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x806F680C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x806F6810: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x806F6814: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806F6818: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806F681C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806F6820: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(688, 0X644) << 16);
    // 0x806F6824: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806F6828: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x806F682C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F6830: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806F6834: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F6838: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F683C: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x806F6840: lwc1        $f16, 0x6CE4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(688, 0X644));
    // 0x806F6844: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F6848: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806F684C: jal         0x800653D8
    // 0x806F6850: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x806F6850: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    after_0:
    // 0x806F6854: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x806F6858: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806F685C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(688, 0X648) << 16);
    // 0x806F6860: lwc1        $f2, 0x6CE8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(688, 0X648));
    // 0x806F6864: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806F6868: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    // 0x806F686C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806F6870: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x806F6874: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806F6878: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F687C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x806F6880: lwc1        $f6, 0x7C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x806F6884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F6888: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806F688C: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806F6890: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    // 0x806F6894: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806F6898: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806F689C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806F68A0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(688, 0X64C) << 16);
    // 0x806F68A4: swc1        $f10, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f10.u32l;
    // 0x806F68A8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x806F68AC: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806F68B0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x806F68B4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x806F68B8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806F68BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806F68C0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x806F68C4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x806F68C8: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x806F68CC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x806F68D0: lwc1        $f4, 0x6CEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(688, 0X64C));
    // 0x806F68D4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806F68D8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x806F68DC: jal         0x80049D74
    // 0x806F68E0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80049D74(rdram, ctx);
        goto after_1;
    // 0x806F68E0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x806F68E4: addiu       $s2, $s1, 0xC4
    ctx->r18 = ADD32(ctx->r17, 0XC4);
    // 0x806F68E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806F68EC: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x806F68F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F68F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x806F68F8: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x806F68FC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806F6900: bc1fl       L_806F6984
    if (!c1cs) {
        // 0x806F6904: mfc1        $a3, $f20
        ctx->r7 = (int32_t)ctx->f20.u32l;
            goto L_806F6984;
    }
    goto skip_0;
    // 0x806F6904: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    skip_0:
    // 0x806F6908: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806F690C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806F6910: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x806F6914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F6918: jal         0x8004D150
    // 0x806F691C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004D150(rdram, ctx);
        goto after_2;
    // 0x806F691C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x806F6920: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x806F6924: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x806F6928: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x806F692C: lbu         $t1, 0x44($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X44);
    // 0x806F6930: beql        $t1, $zero, L_806F69EC
    if (ctx->r9 == 0) {
        // 0x806F6934: lwc1        $f18, 0x4($s2)
        ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
            goto L_806F69EC;
    }
    goto skip_1;
    // 0x806F6934: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    skip_1:
    // 0x806F6938: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x806F693C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F6940: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x806F6944: jal         0x806F67C4
    // 0x806F6948: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    func_806F67C4(rdram, ctx);
        goto after_3;
    // 0x806F6948: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    after_3:
    // 0x806F694C: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x806F6950: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x806F6954: nop

    // 0x806F6958: bc1fl       L_806F6974
    if (!c1cs) {
        // 0x806F695C: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_806F6974;
    }
    goto skip_2;
    // 0x806F695C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x806F6960: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F6964: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x806F6968: b           L_806F69E8
    // 0x806F696C: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_806F69E8;
    // 0x806F696C: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x806F6970: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
L_806F6974:
    // 0x806F6974: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x806F6978: b           L_806F69E8
    // 0x806F697C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_806F69E8;
    // 0x806F697C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x806F6980: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_806F6984:
    // 0x806F6984: jal         0x8004D150
    // 0x806F6988: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    func_8004D150(rdram, ctx);
        goto after_4;
    // 0x806F6988: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    after_4:
    // 0x806F698C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x806F6990: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x806F6994: lw          $t4, 0x40($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X40);
    // 0x806F6998: lbu         $t5, 0x5C($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X5C);
    // 0x806F699C: beql        $t5, $zero, L_806F69EC
    if (ctx->r13 == 0) {
        // 0x806F69A0: lwc1        $f18, 0x4($s2)
        ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
            goto L_806F69EC;
    }
    goto skip_3;
    // 0x806F69A0: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    skip_3:
    // 0x806F69A4: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x806F69A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F69AC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x806F69B0: jal         0x806F67C4
    // 0x806F69B4: swc1        $f18, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f18.u32l;
    func_806F67C4(rdram, ctx);
        goto after_5;
    // 0x806F69B4: swc1        $f18, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f18.u32l;
    after_5:
    // 0x806F69B8: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x806F69BC: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x806F69C0: nop

    // 0x806F69C4: bc1fl       L_806F69E0
    if (!c1cs) {
        // 0x806F69C8: lwc1        $f10, 0x0($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
            goto L_806F69E0;
    }
    goto skip_4;
    // 0x806F69C8: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x806F69CC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F69D0: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x806F69D4: b           L_806F69E8
    // 0x806F69D8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_806F69E8;
    // 0x806F69D8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x806F69DC: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
L_806F69E0:
    // 0x806F69E0: sub.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x806F69E4: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
L_806F69E8:
    // 0x806F69E8: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
L_806F69EC:
    // 0x806F69EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F69F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806F69F4: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x806F69F8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806F69FC: bc1fl       L_806F6A80
    if (!c1cs) {
        // 0x806F6A00: mfc1        $a3, $f20
        ctx->r7 = (int32_t)ctx->f20.u32l;
            goto L_806F6A80;
    }
    goto skip_5;
    // 0x806F6A00: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    skip_5:
    // 0x806F6A04: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806F6A08: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x806F6A0C: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806F6A10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F6A14: jal         0x8004D150
    // 0x806F6A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004D150(rdram, ctx);
        goto after_6;
    // 0x806F6A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x806F6A1C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x806F6A20: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806F6A24: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x806F6A28: lbu         $t9, 0x2C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2C);
    // 0x806F6A2C: beql        $t9, $zero, L_806F6AE8
    if (ctx->r25 == 0) {
        // 0x806F6A30: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_806F6AE8;
    }
    goto skip_6;
    // 0x806F6A30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x806F6A34: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x806F6A38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F6A3C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806F6A40: jal         0x806F67C4
    // 0x806F6A44: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    func_806F67C4(rdram, ctx);
        goto after_7;
    // 0x806F6A44: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    after_7:
    // 0x806F6A48: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x806F6A4C: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x806F6A50: nop

    // 0x806F6A54: bc1fl       L_806F6A70
    if (!c1cs) {
        // 0x806F6A58: lwc1        $f18, 0x0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
            goto L_806F6A70;
    }
    goto skip_7;
    // 0x806F6A58: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    skip_7:
    // 0x806F6A5C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F6A60: add.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x806F6A64: b           L_806F6AE4
    // 0x806F6A68: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
        goto L_806F6AE4;
    // 0x806F6A68: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x806F6A6C: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
L_806F6A70:
    // 0x806F6A70: sub.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f22.fl;
    // 0x806F6A74: b           L_806F6AE4
    // 0x806F6A78: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
        goto L_806F6AE4;
    // 0x806F6A78: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x806F6A7C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_806F6A80:
    // 0x806F6A80: jal         0x8004D150
    // 0x806F6A84: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    func_8004D150(rdram, ctx);
        goto after_8;
    // 0x806F6A84: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    after_8:
    // 0x806F6A88: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x806F6A8C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806F6A90: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x806F6A94: lbu         $t3, 0x14($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X14);
    // 0x806F6A98: beql        $t3, $zero, L_806F6AE8
    if (ctx->r11 == 0) {
        // 0x806F6A9C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_806F6AE8;
    }
    goto skip_8;
    // 0x806F6A9C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_8:
    // 0x806F6AA0: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x806F6AA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F6AA8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x806F6AAC: jal         0x806F67C4
    // 0x806F6AB0: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    func_806F67C4(rdram, ctx);
        goto after_9;
    // 0x806F6AB0: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    after_9:
    // 0x806F6AB4: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x806F6AB8: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x806F6ABC: nop

    // 0x806F6AC0: bc1fl       L_806F6ADC
    if (!c1cs) {
        // 0x806F6AC4: lwc1        $f4, 0x0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
            goto L_806F6ADC;
    }
    goto skip_9;
    // 0x806F6AC4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x806F6AC8: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F6ACC: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x806F6AD0: b           L_806F6AE4
    // 0x806F6AD4: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
        goto L_806F6AE4;
    // 0x806F6AD4: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x806F6AD8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
L_806F6ADC:
    // 0x806F6ADC: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x806F6AE0: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_806F6AE4:
    // 0x806F6AE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_806F6AE8:
    // 0x806F6AE8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806F6AEC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806F6AF0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x806F6AF4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x806F6AF8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x806F6AFC: jr          $ra
    // 0x806F6B00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x806F6B00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8078AB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078AB10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078AB14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078AB18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078AB1C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8078AB20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078AB24: addiu       $a1, $zero, 0x26C
    ctx->r5 = ADD32(0, 0X26C);
    // 0x8078AB28: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x8078AB2C: jal         0x80045A34
    // 0x8078AB30: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078AB30: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8078AB34: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8078AB38: bne         $v0, $zero, L_8078AB50
    if (ctx->r2 != 0) {
        // 0x8078AB3C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8078AB50;
    }
    // 0x8078AB3C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8078AB40: jal         0x800445A4
    // 0x8078AB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8078AB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8078AB48: b           L_8078AB8C
    // 0x8078AB4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078AB8C;
    // 0x8078AB4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078AB50:
    // 0x8078AB50: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8078AB54: addiu       $a1, $zero, 0x26C
    ctx->r5 = ADD32(0, 0X26C);
    // 0x8078AB58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8078AB5C: jal         0x80065728
    // 0x8078AB60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8078AB60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x8078AB64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8078AB68: jal         0x8005D730
    // 0x8078AB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005D730(rdram, ctx);
        goto after_3;
    // 0x8078AB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8078AB70: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8078AB74: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8078AB78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8078AB7C: sw          $t8, 0x260($a3)
    MEM_W(0X260, ctx->r7) = ctx->r24;
    // 0x8078AB80: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8078AB84: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x8078AB88: sh          $t0, 0x25C($a3)
    MEM_H(0X25C, ctx->r7) = ctx->r8;
L_8078AB8C:
    // 0x8078AB8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078AB90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078AB94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078AB98: jr          $ra
    // 0x8078AB9C: nop

    return;
    // 0x8078AB9C: nop

;}
RECOMP_FUNC void func_8003F004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003F008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003F00C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003F010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003F014: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003F018: jal         0x8003EC84
    // 0x8003F01C: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    func_8003EC84(rdram, ctx);
        goto after_0;
    // 0x8003F01C: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    after_0:
    // 0x8003F020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003F024: jal         0x8003E7E0
    // 0x8003F028: lhu         $a1, 0x22($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X22);
    func_8003E7E0(rdram, ctx);
        goto after_1;
    // 0x8003F028: lhu         $a1, 0x22($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X22);
    after_1:
    // 0x8003F02C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003F030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003F034: jr          $ra
    // 0x8003F038: nop

    return;
    // 0x8003F038: nop

;}
RECOMP_FUNC void func_8041F804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F804: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8041F808: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041F80C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041F810: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041F814: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041F818: jal         0x8041E9A8
    // 0x8041F81C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8041E9A8(rdram, ctx);
        goto after_0;
    // 0x8041F81C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8041F820: beql        $v0, $zero, L_8041F940
    if (ctx->r2 == 0) {
        // 0x8041F824: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F940;
    }
    goto skip_0;
    // 0x8041F824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8041F828: jal         0x8041E5E8
    // 0x8041F82C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_1;
    // 0x8041F82C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8041F830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F834: jal         0x8041E430
    // 0x8041F838: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8041E430(rdram, ctx);
        goto after_2;
    // 0x8041F838: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8041F83C: jal         0x8041F594
    // 0x8041F840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041F594(rdram, ctx);
        goto after_3;
    // 0x8041F840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8041F844: jal         0x8041F770
    // 0x8041F848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041F770(rdram, ctx);
        goto after_4;
    // 0x8041F848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8041F84C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8041F850: addiu       $at, $zero, 0x45F0
    ctx->r1 = ADD32(0, 0X45F0);
    // 0x8041F854: beq         $v0, $at, L_8041F86C
    if (ctx->r2 == ctx->r1) {
        // 0x8041F858: addiu       $at, $zero, 0x4638
        ctx->r1 = ADD32(0, 0X4638);
            goto L_8041F86C;
    }
    // 0x8041F858: addiu       $at, $zero, 0x4638
    ctx->r1 = ADD32(0, 0X4638);
    // 0x8041F85C: beql        $v0, $at, L_8041F890
    if (ctx->r2 == ctx->r1) {
        // 0x8041F860: lw          $t7, 0x34($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X34);
            goto L_8041F890;
    }
    goto skip_1;
    // 0x8041F860: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x8041F864: b           L_8041F8A8
    // 0x8041F868: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8041F8A8;
    // 0x8041F868: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8041F86C:
    // 0x8041F86C: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x8041F870: slti        $at, $t6, -0x50
    ctx->r1 = SIGNED(ctx->r14) < -0X50 ? 1 : 0;
    // 0x8041F874: beql        $at, $zero, L_8041F8A8
    if (ctx->r1 == 0) {
        // 0x8041F878: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8041F8A8;
    }
    goto skip_2;
    // 0x8041F878: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8041F87C: jal         0x8041DEAC
    // 0x8041F880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041DEAC(rdram, ctx);
        goto after_5;
    // 0x8041F880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8041F884: b           L_8041F8A8
    // 0x8041F888: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8041F8A8;
    // 0x8041F888: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8041F88C: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
L_8041F890:
    // 0x8041F890: slti        $at, $t7, 0x191
    ctx->r1 = SIGNED(ctx->r15) < 0X191 ? 1 : 0;
    // 0x8041F894: bnel        $at, $zero, L_8041F8A8
    if (ctx->r1 != 0) {
        // 0x8041F898: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8041F8A8;
    }
    goto skip_3;
    // 0x8041F898: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8041F89C: jal         0x8041DEAC
    // 0x8041F8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041DEAC(rdram, ctx);
        goto after_6;
    // 0x8041F8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8041F8A4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8041F8A8:
    // 0x8041F8A8: lh          $v0, 0x2E($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2E);
    // 0x8041F8AC: bltz        $v0, L_8041F8BC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8041F8B0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8041F8BC;
    }
    // 0x8041F8B0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8041F8B4: b           L_8041F93C
    // 0x8041F8B8: sh          $t8, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r24;
        goto L_8041F93C;
    // 0x8041F8B8: sh          $t8, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r24;
L_8041F8BC:
    // 0x8041F8BC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8041F8C0: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8041F8C4: blez        $v0, L_8041F938
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8041F8C8: slti        $at, $v0, 0x140
        ctx->r1 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
            goto L_8041F938;
    }
    // 0x8041F8C8: slti        $at, $v0, 0x140
    ctx->r1 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x8041F8CC: beq         $at, $zero, L_8041F938
    if (ctx->r1 == 0) {
        // 0x8041F8D0: lui         $t9, 0x8042
        ctx->r25 = S32(RELOC_HI16(29, 0X2FE0) << 16);
            goto L_8041F938;
    }
    // 0x8041F8D0: lui         $t9, 0x8042
    ctx->r25 = S32(RELOC_HI16(29, 0X2FE0) << 16);
    // 0x8041F8D4: lw          $t9, 0x640($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(29, 0X2FE0));
    // 0x8041F8D8: blezl       $t9, L_8041F920
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8041F8DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041F920;
    }
    goto skip_4;
    // 0x8041F8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8041F8E0: jal         0x800653D8
    // 0x8041F8E4: nop

    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x8041F8E4: nop

    after_7:
    // 0x8041F8E8: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x8041F8EC: bne         $t0, $zero, L_8041F91C
    if (ctx->r8 != 0) {
        // 0x8041F8F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041F91C;
    }
    // 0x8041F8F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F8F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041F8F8: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8041F8FC: jal         0x8041FE10
    // 0x8041F900: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_8;
    // 0x8041F900: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_8:
    // 0x8041F904: lui         $v0, 0x8042
    ctx->r2 = S32(RELOC_HI16(29, 0X2FE0) << 16);
    // 0x8041F908: addiu       $v0, $v0, 0x640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(29, 0X2FE0));
    // 0x8041F90C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8041F910: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8041F914: b           L_8041F93C
    // 0x8041F918: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_8041F93C;
    // 0x8041F918: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_8041F91C:
    // 0x8041F91C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8041F920:
    // 0x8041F920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041F924: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8041F928: jal         0x8041FE10
    // 0x8041F92C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_9;
    // 0x8041F92C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_9:
    // 0x8041F930: b           L_8041F940
    // 0x8041F934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041F940;
    // 0x8041F934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041F938:
    // 0x8041F938: sh          $t3, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r11;
L_8041F93C:
    // 0x8041F93C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041F940:
    // 0x8041F940: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041F944: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8041F948: jr          $ra
    // 0x8041F94C: nop

    return;
    // 0x8041F94C: nop

;}
RECOMP_FUNC void func_8001AEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AEC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001AEC8: beq         $a0, $zero, L_8001AED4
    if (ctx->r4 == 0) {
        // 0x8001AECC: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8001AED4;
    }
    // 0x8001AECC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8001AED0: sh          $a1, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r5;
L_8001AED4:
    // 0x8001AED4: jr          $ra
    // 0x8001AED8: nop

    return;
    // 0x8001AED8: nop

;}
RECOMP_FUNC void func_80527038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527038: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6168) << 16);
    // 0x8052703C: lwc1        $f4, -0x3F98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6168));
    // 0x80527040: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527044: lui         $v1, 0x8053
    ctx->r3 = S32(RELOC_HI16(327, 0X40C8) << 16);
    // 0x80527048: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(327, 0X11E8) << 16);
    // 0x8052704C: addiu       $v1, $v1, -0x6038
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(327, 0X40C8));
    // 0x80527050: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80527054: addiu       $t6, $t6, 0x70E8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(327, 0X11E8));
    // 0x80527058: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8052705C: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80527060: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80527064: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80527068: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
    // 0x8052706C: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80527070: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x80527074: jr          $ra
    // 0x80527078: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80527078: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_805C70B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C70B0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x805C70B4: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x805C70B8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C70BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805C70C0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x805C70C4: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x805C70C8: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x805C70CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805C70D0: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x805C70D4: nop

    // 0x805C70D8: bc1fl       L_805C7164
    if (!c1cs) {
        // 0x805C70DC: lwc1        $f12, 0x50($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
            goto L_805C7164;
    }
    goto skip_0;
    // 0x805C70DC: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    skip_0:
    // 0x805C70E0: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x805C70E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805C70E8: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x805C70EC: nop

    // 0x805C70F0: bc1fl       L_805C712C
    if (!c1cs) {
        // 0x805C70F4: sub.s       $f0, $f14, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f12.fl;
            goto L_805C712C;
    }
    goto skip_1;
    // 0x805C70F4: sub.s       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f12.fl;
    skip_1:
    // 0x805C70F8: sub.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x805C70FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C7100: nop

    // 0x805C7104: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x805C7108: nop

    // 0x805C710C: bc1fl       L_805C7120
    if (!c1cs) {
        // 0x805C7110: neg.s       $f10, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
            goto L_805C7120;
    }
    goto skip_2;
    // 0x805C7110: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    skip_2:
    // 0x805C7114: b           L_805C7158
    // 0x805C7118: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
        goto L_805C7158;
    // 0x805C7118: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
    // 0x805C711C: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
L_805C7120:
    // 0x805C7120: b           L_805C7158
    // 0x805C7124: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
        goto L_805C7158;
    // 0x805C7124: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x805C7128: sub.s       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f12.fl;
L_805C712C:
    // 0x805C712C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805C7130: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C7134: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C7138: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x805C713C: nop

    // 0x805C7140: bc1fl       L_805C7158
    if (!c1cs) {
        // 0x805C7144: swc1        $f20, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
            goto L_805C7158;
    }
    goto skip_3;
    // 0x805C7144: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
    skip_3:
    // 0x805C7148: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x805C714C: b           L_805C7158
    // 0x805C7150: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
        goto L_805C7158;
    // 0x805C7150: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x805C7154: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
L_805C7158:
    // 0x805C7158: b           L_805C71C8
    // 0x805C715C: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
        goto L_805C71C8;
    // 0x805C715C: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
    // 0x805C7160: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
L_805C7164:
    // 0x805C7164: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805C7168: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805C716C: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x805C7170: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x805C7174: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x805C7178: nop

    // 0x805C717C: bc1fl       L_805C718C
    if (!c1cs) {
        // 0x805C7180: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_805C718C;
    }
    goto skip_4;
    // 0x805C7180: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_4:
    // 0x805C7184: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x805C7188: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_805C718C:
    // 0x805C718C: nop

    // 0x805C7190: bc1fl       L_805C71A0
    if (!c1cs) {
        // 0x805C7194: lwc1        $f6, 0x4($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
            goto L_805C71A0;
    }
    goto skip_5;
    // 0x805C7194: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    skip_5:
    // 0x805C7198: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x805C719C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
L_805C71A0:
    // 0x805C71A0: sub.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x805C71A4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C71A8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x805C71AC: nop

    // 0x805C71B0: bc1fl       L_805C71C8
    if (!c1cs) {
        // 0x805C71B4: swc1        $f2, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
            goto L_805C71C8;
    }
    goto skip_6;
    // 0x805C71B4: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
    skip_6:
    // 0x805C71B8: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x805C71BC: b           L_805C71C8
    // 0x805C71C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805C71C8;
    // 0x805C71C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805C71C4: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
L_805C71C8:
    // 0x805C71C8: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x805C71CC: jr          $ra
    // 0x805C71D0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x805C71D0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80067DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067DE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067DE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067DE8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067DEC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80067DF0: jal         0x80067BBC
    // 0x80067DF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067DF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80067DF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80067DFC: jal         0x80067D48
    // 0x80067E00: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80067D48(rdram, ctx);
        goto after_1;
    // 0x80067E00: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80067E04: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067E08: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067E0C: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067E10: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80067E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067E1C: jr          $ra
    // 0x80067E20: nop

    return;
    // 0x80067E20: nop

;}
RECOMP_FUNC void func_8001F99C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F99C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F9A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F9A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001F9A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001F9AC: jal         0x8001F560
    // 0x8001F9B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8001F560(rdram, ctx);
        goto after_0;
    // 0x8001F9B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001F9B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F9B8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8001F9BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001F9C0: lbu         $t6, 0x12($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X12);
    // 0x8001F9C4: lw          $t2, 0x2C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X2C);
    // 0x8001F9C8: lbu         $t9, 0x111($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X111);
    // 0x8001F9CC: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x8001F9D0: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8001F9D4: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    // 0x8001F9D8: andi        $t3, $t2, 0x700
    ctx->r11 = ctx->r10 & 0X700;
    // 0x8001F9DC: sltu        $t4, $zero, $t3
    ctx->r12 = 0 < ctx->r11 ? 1 : 0;
    // 0x8001F9E0: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8001F9E4: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x8001F9E8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8001F9EC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8001F9F0: andi        $t9, $t7, 0x700
    ctx->r25 = ctx->r15 & 0X700;
    // 0x8001F9F4: sltu        $t8, $zero, $t9
    ctx->r24 = 0 < ctx->r25 ? 1 : 0;
    // 0x8001F9F8: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x8001F9FC: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x8001FA00: sltu        $t4, $zero, $t3
    ctx->r12 = 0 < ctx->r11 ? 1 : 0;
    // 0x8001FA04: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8001FA08: addu        $t2, $t6, $t0
    ctx->r10 = ADD32(ctx->r14, ctx->r8);
    // 0x8001FA0C: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x8001FA10: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8001FA14: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8001FA18: lw          $t9, -0x65E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X65E8);
    // 0x8001FA1C: jalr        $t9
    // 0x8001FA20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8001FA20: nop

    after_1:
    // 0x8001FA24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FA28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FA2C: jr          $ra
    // 0x8001FA30: nop

    return;
    // 0x8001FA30: nop

;}
RECOMP_FUNC void func_806F37A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F37A8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X9A8) << 16);
    // 0x806F37AC: lwc1        $f0, 0x3DF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X9A8));
    // 0x806F37B0: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x806F37B4: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(682, 0X434) << 16);
    // 0x806F37B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x806F37BC: addiu       $t7, $t7, 0x3884
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(682, 0X434));
    // 0x806F37C0: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x806F37C4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806F37C8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806F37CC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X9AC) << 16);
    // 0x806F37D0: sb          $t8, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r24;
    // 0x806F37D4: lwc1        $f4, 0x3DFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X9AC));
    // 0x806F37D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F37DC: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x806F37E0: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x806F37E4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x806F37E8: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    // 0x806F37EC: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x806F37F0: jr          $ra
    // 0x806F37F4: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x806F37F4: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80046B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046B78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80046B7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80046B80: jal         0x80046978
    // 0x80046B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80046978(rdram, ctx);
        goto after_0;
    // 0x80046B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80046B88: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80046B8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80046B90: lbu         $t7, 0x170($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X170);
    // 0x80046B94: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80046B98: beq         $t8, $zero, L_80046BC8
    if (ctx->r24 == 0) {
        // 0x80046B9C: sb          $t7, 0x170($a0)
        MEM_B(0X170, ctx->r4) = ctx->r15;
            goto L_80046BC8;
    }
    // 0x80046B9C: sb          $t7, 0x170($a0)
    MEM_B(0X170, ctx->r4) = ctx->r15;
    // 0x80046BA0: jal         0x80052B04
    // 0x80046BA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80052B04(rdram, ctx);
        goto after_1;
    // 0x80046BA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80046BA8: bne         $v0, $zero, L_80046BC8
    if (ctx->r2 != 0) {
        // 0x80046BAC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80046BC8;
    }
    // 0x80046BAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80046BB0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80046BB4: addiu       $a0, $a0, 0x780
    ctx->r4 = ADD32(ctx->r4, 0X780);
    // 0x80046BB8: jal         0x80071380
    // 0x80046BBC: addiu       $a1, $zero, 0x68D
    ctx->r5 = ADD32(0, 0X68D);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x80046BBC: addiu       $a1, $zero, 0x68D
    ctx->r5 = ADD32(0, 0X68D);
    after_2:
    // 0x80046BC0: b           L_80046BD4
    // 0x80046BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046BD4;
    // 0x80046BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046BC8:
    // 0x80046BC8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80046BCC: jal         0x80046A38
    // 0x80046BD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    func_80046A38(rdram, ctx);
        goto after_3;
    // 0x80046BD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    after_3:
L_80046BD4:
    // 0x80046BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046BDC: jr          $ra
    // 0x80046BE0: nop

    return;
    // 0x80046BE0: nop

;}
RECOMP_FUNC void func_80031A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031A5C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80031A60: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80031A64: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80031A68: bne         $v0, $zero, L_80031A98
    if (ctx->r2 != 0) {
        // 0x80031A6C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80031A98;
    }
    // 0x80031A6C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80031A70: jal         0x80062DD4
    // 0x80031A74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80062DD4(rdram, ctx);
        goto after_0;
    // 0x80031A74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031A78: beq         $v0, $zero, L_80031A9C
    if (ctx->r2 == 0) {
        // 0x80031A7C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80031A9C;
    }
    // 0x80031A7C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80031A80: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x80031A84: addiu       $t6, $t6, 0x1AAC
    ctx->r14 = ADD32(ctx->r14, 0X1AAC);
    // 0x80031A88: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80031A8C: sw          $t6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r14;
    // 0x80031A90: b           L_80031A9C
    // 0x80031A94: sw          $t7, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r15;
        goto L_80031A9C;
    // 0x80031A94: sw          $t7, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r15;
L_80031A98:
    // 0x80031A98: sw          $t8, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r24;
L_80031A9C:
    // 0x80031A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031AA4: jr          $ra
    // 0x80031AA8: nop

    return;
    // 0x80031AA8: nop

;}
RECOMP_FUNC void func_80709620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709620: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80709624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80709628: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070962C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80709630: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x80709634: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80709638: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8070963C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80709640: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80709644: lhu         $t9, 0x18($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X18);
    // 0x80709648: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x8070964C: lbu         $t0, 0x26($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X26);
    // 0x80709650: andi        $t1, $t0, 0xF8
    ctx->r9 = ctx->r8 & 0XF8;
    // 0x80709654: bnel        $t1, $at, L_807096E8
    if (ctx->r9 != ctx->r1) {
        // 0x80709658: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_807096E8;
    }
    goto skip_0;
    // 0x80709658: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8070965C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80709660: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80709664: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80709668: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8070966C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80709670: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80709674: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(718, 0X1534) << 16);
    // 0x80709678: lwc1        $f10, -0x58EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(718, 0X1534));
    // 0x8070967C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80709680: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80709684: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80709688: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8070968C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80709690: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x80709694: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80709698: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8070969C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807096A0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x807096A4: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807096A8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x807096AC: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x807096B0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807096B4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x807096B8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x807096BC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x807096C0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x807096C4: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x807096C8: lw          $t9, 0x28($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X28);
    // 0x807096CC: jalr        $t9
    // 0x807096D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807096D0: nop

    after_0:
    // 0x807096D4: jal         0x800447C8
    // 0x807096D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x807096D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807096DC: b           L_80709730
    // 0x807096E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80709730;
    // 0x807096E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807096E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_807096E8:
    // 0x807096E8: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x807096EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807096F0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807096F4: nop

    // 0x807096F8: bc1f        L_80709730
    if (!c1cs) {
        // 0x807096FC: nop
    
            goto L_80709730;
    }
    // 0x807096FC: nop

    // 0x80709700: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x80709704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80709708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070970C: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80709710: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80709714: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x80709718: beq         $t7, $zero, L_80709730
    if (ctx->r15 == 0) {
        // 0x8070971C: nop
    
            goto L_80709730;
    }
    // 0x8070971C: nop

    // 0x80709720: jal         0x80709CB8
    // 0x80709724: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80709CB8(rdram, ctx);
        goto after_2;
    // 0x80709724: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x80709728: b           L_80709730
    // 0x8070972C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80709730;
    // 0x8070972C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80709730:
    // 0x80709730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80709734: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80709738: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8070973C: jr          $ra
    // 0x80709740: nop

    return;
    // 0x80709740: nop

;}
RECOMP_FUNC void func_80716B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716B18: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716B1C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716B20: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716B24: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716B28: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716B2C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716B30: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716B34: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716B38: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716B3C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716B40: jr          $ra
    // 0x80716B44: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716B44: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8002C650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C654: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C658: addiu       $a1, $a1, -0x2AB0
    ctx->r5 = ADD32(ctx->r5, -0X2AB0);
    // 0x8002C65C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C664: jal         0x80028118
    // 0x8002C668: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C668: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C66C: jal         0x8002C600
    // 0x8002C670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002C600(rdram, ctx);
        goto after_1;
    // 0x8002C670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002C674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C67C: jr          $ra
    // 0x8002C680: nop

    return;
    // 0x8002C680: nop

;}
RECOMP_FUNC void func_8007CDA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CDA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007CDA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007CDA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007CDAC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007CDB0: jal         0x800744B0
    // 0x8007CDB4: lw          $a0, 0x218($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X218);
    func_800744B0(rdram, ctx);
        goto after_0;
    // 0x8007CDB4: lw          $a0, 0x218($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X218);
    after_0:
    // 0x8007CDB8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007CDBC: sw          $v0, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r2;
    // 0x8007CDC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CDC4: jr          $ra
    // 0x8007CDC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007CDC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8076D134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D134: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8076D138: beq         $v0, $zero, L_8076D14C
    if (ctx->r2 == 0) {
        // 0x8076D13C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8076D14C;
    }
    // 0x8076D13C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8076D140: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8076D144: jr          $ra
    // 0x8076D148: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    return;
    // 0x8076D148: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
L_8076D14C:
    // 0x8076D14C: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8076D150: addiu       $v1, $t7, 0x1
    ctx->r3 = ADD32(ctx->r15, 0X1);
    // 0x8076D154: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8076D158: bne         $at, $zero, L_8076D168
    if (ctx->r1 != 0) {
        // 0x8076D15C: sw          $v1, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r3;
            goto L_8076D168;
    }
    // 0x8076D15C: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x8076D160: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8076D164: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8076D168:
    // 0x8076D168: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8076D16C: addu        $a2, $a1, $t9
    ctx->r6 = ADD32(ctx->r5, ctx->r25);
    // 0x8076D170: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8076D174: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x8076D178: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x8076D17C: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x8076D180: jr          $ra
    // 0x8076D184: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8076D184: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8006C95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C95C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C960: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006C964: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006C968: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8006C96C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006C970: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C974: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    // 0x8006C978: jal         0x80065728
    // 0x8006C97C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8006C97C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006C980: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006C984: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006C988: lw          $t6, 0x3EC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3EC);
    // 0x8006C98C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006C990: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x8006C994: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8006C998: addiu       $t9, $t8, 0x3F8
    ctx->r25 = ADD32(ctx->r24, 0X3F8);
    // 0x8006C99C: sw          $t9, 0x3F4($v0)
    MEM_W(0X3F4, ctx->r2) = ctx->r25;
    // 0x8006C9A0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8006C9A4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8006C9A8:
    // 0x8006C9A8: jal         0x8006C380
    // 0x8006C9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006C380(rdram, ctx);
        goto after_1;
    // 0x8006C9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006C9B0: jal         0x8006C910
    // 0x8006C9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006C910(rdram, ctx);
        goto after_2;
    // 0x8006C9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006C9B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006C9BC: bne         $s1, $s2, L_8006C9A8
    if (ctx->r17 != ctx->r18) {
        // 0x8006C9C0: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_8006C9A8;
    }
    // 0x8006C9C0: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8006C9C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006C9C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C9CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C9D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006C9D4: jr          $ra
    // 0x8006C9D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006C9D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80557B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80557B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80557B68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80557B6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80557B70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80557B74: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80557B78: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x80557B7C: jal         0x80067D5C
    // 0x80557B80: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80557B80: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    after_0:
    // 0x80557B84: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80557B88: jal         0x80067818
    // 0x80557B8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80557B8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80557B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80557B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80557B98: jr          $ra
    // 0x80557B9C: nop

    return;
    // 0x80557B9C: nop

;}
RECOMP_FUNC void func_8004312C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004312C: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x80043130: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80043134: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80043138: mfhi        $t9
    ctx->r25 = hi;
    // 0x8004313C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80043140: addiu       $t4, $a3, 0x1
    ctx->r12 = ADD32(ctx->r7, 0X1);
    // 0x80043144: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x80043148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004314C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80043150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80043154: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043158: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8004315C: sw          $a2, 0x12F0($t7)
    MEM_W(0X12F0, ctx->r15) = ctx->r6;
    // 0x80043160: lw          $t0, 0x1300($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1300);
    // 0x80043164: lw          $t2, 0x130C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X130C);
    // 0x80043168: mfhi        $t5
    ctx->r13 = hi;
    // 0x8004316C: addiu       $v1, $t0, 0x1
    ctx->r3 = ADD32(ctx->r8, 0X1);
    // 0x80043170: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80043174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80043178: sw          $t9, 0x12FC($a0)
    MEM_W(0X12FC, ctx->r4) = ctx->r25;
    // 0x8004317C: sw          $v1, 0x1300($a0)
    MEM_W(0X1300, ctx->r4) = ctx->r3;
    // 0x80043180: sw          $t3, 0x130C($a0)
    MEM_W(0X130C, ctx->r4) = ctx->r11;
    // 0x80043184: beq         $v1, $zero, L_800431B8
    if (ctx->r3 == 0) {
        // 0x80043188: sw          $t5, 0x1308($a0)
        MEM_W(0X1308, ctx->r4) = ctx->r13;
            goto L_800431B8;
    }
    // 0x80043188: sw          $t5, 0x1308($a0)
    MEM_W(0X1308, ctx->r4) = ctx->r13;
    // 0x8004318C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80043190: lwc1        $f0, 0x318($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X318);
L_80043194:
    // 0x80043194: lw          $v0, 0x12F0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12F0);
    // 0x80043198: beq         $v0, $zero, L_800431B0
    if (ctx->r2 == 0) {
        // 0x8004319C: nop
    
            goto L_800431B0;
    }
    // 0x8004319C: nop

    // 0x800431A0: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800431A4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800431A8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800431AC: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
L_800431B0:
    // 0x800431B0: bne         $v1, $zero, L_80043194
    if (ctx->r3 != 0) {
        // 0x800431B4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80043194;
    }
    // 0x800431B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800431B8:
    // 0x800431B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800431BC: jal         0x800430E4
    // 0x800431C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800430E4(rdram, ctx);
        goto after_0;
    // 0x800431C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800431C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800431C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800431CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800431D0: jr          $ra
    // 0x800431D4: nop

    return;
    // 0x800431D4: nop

;}
RECOMP_FUNC void func_8005D388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D388: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8005D38C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D390: addiu       $t6, $t6, -0x788C
    ctx->r14 = ADD32(ctx->r14, -0X788C);
    // 0x8005D394: bne         $t6, $zero, L_8005D3B4
    if (ctx->r14 != 0) {
        // 0x8005D398: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8005D3B4;
    }
    // 0x8005D398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D39C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005D3A0: addiu       $a0, $a0, 0xCD0
    ctx->r4 = ADD32(ctx->r4, 0XCD0);
    // 0x8005D3A4: jal         0x80071380
    // 0x8005D3A8: addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005D3A8: addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    after_0:
    // 0x8005D3AC: b           L_8005D414
    // 0x8005D3B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005D414;
    // 0x8005D3B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D3B4:
    // 0x8005D3B4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8005D3B8: lw          $t7, -0x7814($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7814);
    // 0x8005D3BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005D3C0: addiu       $a0, $a0, 0xCE0
    ctx->r4 = ADD32(ctx->r4, 0XCE0);
    // 0x8005D3C4: bne         $t7, $zero, L_8005D3DC
    if (ctx->r15 != 0) {
        // 0x8005D3C8: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_8005D3DC;
    }
    // 0x8005D3C8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8005D3CC: jal         0x80071380
    // 0x8005D3D0: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8005D3D0: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    after_1:
    // 0x8005D3D4: b           L_8005D414
    // 0x8005D3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005D414;
    // 0x8005D3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D3DC:
    // 0x8005D3DC: lw          $t8, -0x7814($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7814);
    // 0x8005D3E0: addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    // 0x8005D3E4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8005D3E8: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x8005D3EC: bne         $t9, $zero, L_8005D408
    if (ctx->r25 != 0) {
        // 0x8005D3F0: nop
    
            goto L_8005D408;
    }
    // 0x8005D3F0: nop

    // 0x8005D3F4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005D3F8: jal         0x80071380
    // 0x8005D3FC: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8005D3FC: addiu       $a0, $a0, 0xCF0
    ctx->r4 = ADD32(ctx->r4, 0XCF0);
    after_2:
    // 0x8005D400: b           L_8005D414
    // 0x8005D404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005D414;
    // 0x8005D404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D408:
    // 0x8005D408: jal         0x8005D320
    // 0x8005D40C: lw          $a0, -0x780C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X780C);
    func_8005D320(rdram, ctx);
        goto after_3;
    // 0x8005D40C: lw          $a0, -0x780C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X780C);
    after_3:
    // 0x8005D410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D414:
    // 0x8005D414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D418: jr          $ra
    // 0x8005D41C: nop

    return;
    // 0x8005D41C: nop

;}
RECOMP_FUNC void func_8078B1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B1C8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8078B1CC: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(796, 0X1A0) << 16);
    // 0x8078B1D0: addiu       $t6, $t6, -0x4CD0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(796, 0X1A0));
    // 0x8078B1D4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8078B1D8: jr          $ra
    // 0x8078B1DC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8078B1DC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80034F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034F3C: jal         0x80021958
    // 0x80034F40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80034F40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034F44: bne         $v0, $zero, L_80034F54
    if (ctx->r2 != 0) {
        // 0x80034F48: nop
    
            goto L_80034F54;
    }
    // 0x80034F48: nop

    // 0x80034F4C: b           L_80034F70
    // 0x80034F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034F70;
    // 0x80034F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034F54:
    // 0x80034F54: jal         0x80034570
    // 0x80034F58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80034570(rdram, ctx);
        goto after_1;
    // 0x80034F58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80034F5C: bnel        $v0, $zero, L_80034F70
    if (ctx->r2 != 0) {
        // 0x80034F60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80034F70;
    }
    goto skip_0;
    // 0x80034F60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80034F64: b           L_80034F70
    // 0x80034F68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034F70;
    // 0x80034F68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80034F70:
    // 0x80034F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034F78: jr          $ra
    // 0x80034F7C: nop

    return;
    // 0x80034F7C: nop

;}
RECOMP_FUNC void func_8000363C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000363C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003644: jal         0x80003698
    // 0x80003648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x80003648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000364C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80003650: beq         $v0, $zero, L_80003684
    if (ctx->r2 == 0) {
        // 0x80003654: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80003684;
    }
    // 0x80003654: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003658: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8000365C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80003660: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x80003664: beql        $at, $zero, L_80003688
    if (ctx->r1 == 0) {
        // 0x80003668: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80003688;
    }
    goto skip_0;
    // 0x80003668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000366C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80003670:
    // 0x80003670: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80003674: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80003678: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x8000367C: bnel        $at, $zero, L_80003670
    if (ctx->r1 != 0) {
        // 0x80003680: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_80003670;
    }
    goto skip_1;
    // 0x80003680: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_1:
L_80003684:
    // 0x80003684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80003688:
    // 0x80003688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000368C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80003690: jr          $ra
    // 0x80003694: nop

    return;
    // 0x80003694: nop

;}
RECOMP_FUNC void func_806FDBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDBD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FDBDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FDBE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FDBE4: jal         0x80057754
    // 0x806FDBE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80057754(rdram, ctx);
        goto after_0;
    // 0x806FDBE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806FDBEC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806FDBF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806FDBF4: jal         0x806FD60C
    // 0x806FDBF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806FD60C(rdram, ctx);
        goto after_1;
    // 0x806FDBF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x806FDBFC: jal         0x806FD854
    // 0x806FDC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD854(rdram, ctx);
        goto after_2;
    // 0x806FDC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806FDC04: jal         0x806FD7F8
    // 0x806FDC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD7F8(rdram, ctx);
        goto after_3;
    // 0x806FDC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806FDC0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806FDC10: bne         $v0, $at, L_806FDC84
    if (ctx->r2 != ctx->r1) {
        // 0x806FDC14: nop
    
            goto L_806FDC84;
    }
    // 0x806FDC14: nop

    // 0x806FDC18: jal         0x800653D8
    // 0x806FDC1C: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x806FDC1C: nop

    after_4:
    // 0x806FDC20: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x806FDC24: bnel        $t6, $zero, L_806FDC40
    if (ctx->r14 != 0) {
        // 0x806FDC28: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_806FDC40;
    }
    goto skip_0;
    // 0x806FDC28: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x806FDC2C: jal         0x806FD8DC
    // 0x806FDC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD8DC(rdram, ctx);
        goto after_5;
    // 0x806FDC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806FDC34: bne         $v0, $zero, L_806FDC5C
    if (ctx->r2 != 0) {
        // 0x806FDC38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806FDC5C;
    }
    // 0x806FDC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDC3C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_806FDC40:
    // 0x806FDC40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDC48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806FDC4C: jal         0x806FE468
    // 0x806FDC50: lw          $a3, 0x68($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X68);
    func_806FE468(rdram, ctx);
        goto after_6;
    // 0x806FDC50: lw          $a3, 0x68($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X68);
    after_6:
    // 0x806FDC54: b           L_806FDC84
    // 0x806FDC58: nop

        goto L_806FDC84;
    // 0x806FDC58: nop

L_806FDC5C:
    // 0x806FDC5C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x806FDC60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDC64: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806FDC68: jal         0x806FE468
    // 0x806FDC6C: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    func_806FE468(rdram, ctx);
        goto after_7;
    // 0x806FDC6C: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    after_7:
    // 0x806FDC70: jal         0x806FD9C4
    // 0x806FDC74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FD9C4(rdram, ctx);
        goto after_8;
    // 0x806FDC74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806FDC78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDC7C: jal         0x806FD4FC
    // 0x806FDC80: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    func_806FD4FC(rdram, ctx);
        goto after_9;
    // 0x806FDC80: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    after_9:
L_806FDC84:
    // 0x806FDC84: jal         0x806FDAE8
    // 0x806FDC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FDAE8(rdram, ctx);
        goto after_10;
    // 0x806FDC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x806FDC8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FDC90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FDC94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FDC98: jr          $ra
    // 0x806FDC9C: nop

    return;
    // 0x806FDC9C: nop

;}
RECOMP_FUNC void func_80533574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533574: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80533578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8053357C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80533580: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80533584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80533588: jal         0x800692D4
    // 0x8053358C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x8053358C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80533590: jal         0x80532CFC
    // 0x80533594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532CFC(rdram, ctx);
        goto after_1;
    // 0x80533594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80533598: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8053359C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x805335A0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x805335A4: sltiu       $at, $a0, 0xA1
    ctx->r1 = ctx->r4 < 0XA1 ? 1 : 0;
    // 0x805335A8: beq         $at, $zero, L_80533610
    if (ctx->r1 == 0) {
        // 0x805335AC: addiu       $t6, $a0, 0x1
        ctx->r14 = ADD32(ctx->r4, 0X1);
            goto L_80533610;
    }
    // 0x805335AC: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x805335B0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x805335B4: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x805335B8: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805335BC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805335C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805335C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805335C8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x805335CC: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x805335D0: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x805335D4: nop

    // 0x805335D8: bc1f        L_805335E8
    if (!c1cs) {
        // 0x805335DC: nop
    
            goto L_805335E8;
    }
    // 0x805335DC: nop

    // 0x805335E0: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    // 0x805335E4: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
L_805335E8:
    // 0x805335E8: jal         0x80066DE4
    // 0x805335EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x805335EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x805335F0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x805335F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805335F8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x805335FC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80533600: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80533604: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80533608: b           L_80533618
    // 0x8053360C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
        goto L_80533618;
    // 0x8053360C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
L_80533610:
    // 0x80533610: jal         0x805333A4
    // 0x80533614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805333A4(rdram, ctx);
        goto after_3;
    // 0x80533614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80533618:
    // 0x80533618: jal         0x80533170
    // 0x8053361C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80533170(rdram, ctx);
        goto after_4;
    // 0x8053361C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80533620: jal         0x80532B50
    // 0x80533624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532B50(rdram, ctx);
        goto after_5;
    // 0x80533624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80533628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8053362C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80533630: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80533634: jr          $ra
    // 0x80533638: nop

    return;
    // 0x80533638: nop

;}
RECOMP_FUNC void func_8000B9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B9C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B9C4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8000B9C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B9CC: beq         $a0, $a2, L_8000BBE4
    if (ctx->r4 == ctx->r6) {
        // 0x8000B9D0: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8000BBE4;
    }
    // 0x8000B9D0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000B9D4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8000B9D8: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000B9DC: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x8000B9E0: beq         $v0, $zero, L_8000BBE4
    if (ctx->r2 == 0) {
        // 0x8000B9E4: sb          $t7, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r15;
            goto L_8000BBE4;
    }
    // 0x8000B9E4: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8000B9E8: lw          $t8, 0x48($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X48);
    // 0x8000B9EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000B9F0: bnel        $a0, $t8, L_8000BA00
    if (ctx->r4 != ctx->r24) {
        // 0x8000B9F4: lw          $v0, 0x44($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X44);
            goto L_8000BA00;
    }
    goto skip_0;
    // 0x8000B9F4: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
    skip_0:
    // 0x8000B9F8: sw          $a2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r6;
    // 0x8000B9FC: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
L_8000BA00:
    // 0x8000BA00: beql        $a0, $v0, L_8000BA54
    if (ctx->r4 == ctx->r2) {
        // 0x8000BA04: lbu         $t5, 0x60($a1)
        ctx->r13 = MEM_BU(ctx->r5, 0X60);
            goto L_8000BA54;
    }
    goto skip_1;
    // 0x8000BA04: lbu         $t5, 0x60($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X60);
    skip_1:
    // 0x8000BA08: bnel        $a2, $v0, L_8000BBE8
    if (ctx->r6 != ctx->r2) {
        // 0x8000BA0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000BBE8;
    }
    goto skip_2;
    // 0x8000BA0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8000BA10: lw          $t9, 0x48($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X48);
    // 0x8000BA14: bnel        $a2, $t9, L_8000BBE8
    if (ctx->r6 != ctx->r25) {
        // 0x8000BA18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000BBE8;
    }
    goto skip_3;
    // 0x8000BA18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8000BA1C: lw          $t1, 0x40($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X40);
    // 0x8000BA20: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8000BA24: bnel        $a0, $t1, L_8000BBE8
    if (ctx->r4 != ctx->r9) {
        // 0x8000BA28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000BBE8;
    }
    goto skip_4;
    // 0x8000BA28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8000BA2C: beql        $a3, $t0, L_8000BBE8
    if (ctx->r7 == ctx->r8) {
        // 0x8000BA30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000BBE8;
    }
    goto skip_5;
    // 0x8000BA30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8000BA34: lbu         $t3, 0x60($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X60);
    // 0x8000BA38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BA3C: lwc1        $f4, 0x6AA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6AA8);
    // 0x8000BA40: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x8000BA44: sb          $t4, 0x60($a1)
    MEM_B(0X60, ctx->r5) = ctx->r12;
    // 0x8000BA48: b           L_8000BBE4
    // 0x8000BA4C: swc1        $f4, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f4.u32l;
        goto L_8000BBE4;
    // 0x8000BA4C: swc1        $f4, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f4.u32l;
    // 0x8000BA50: lbu         $t5, 0x60($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X60);
L_8000BA54:
    // 0x8000BA54: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8000BA58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000BA5C: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x8000BA60: beq         $t0, $t6, L_8000BBC4
    if (ctx->r8 == ctx->r14) {
        // 0x8000BA64: nop
    
            goto L_8000BBC4;
    }
    // 0x8000BA64: nop

    // 0x8000BA68: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8000BA6C: addiu       $v0, $a1, 0x4C
    ctx->r2 = ADD32(ctx->r5, 0X4C);
    // 0x8000BA70: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8000BA74: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8000BA78: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8000BA7C: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x8000BA80: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x8000BA84: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8000BA88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000BA8C: sb          $t9, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r25;
    // 0x8000BA90: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x8000BA94: beql        $v1, $zero, L_8000BB04
    if (ctx->r3 == 0) {
        // 0x8000BA98: sb          $t7, 0x30($a1)
        MEM_B(0X30, ctx->r5) = ctx->r15;
            goto L_8000BB04;
    }
    goto skip_6;
    // 0x8000BA98: sb          $t7, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r15;
    skip_6:
    // 0x8000BA9C: lbu         $t1, 0x4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4);
    // 0x8000BAA0: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8000BAA4: lw          $t2, 0x50($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X50);
    // 0x8000BAA8: lbu         $t3, 0xC($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XC);
    // 0x8000BAAC: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    // 0x8000BAB0: lw          $t4, 0x50($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X50);
    // 0x8000BAB4: lw          $t5, 0xD4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XD4);
    // 0x8000BAB8: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x8000BABC: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x8000BAC0: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x8000BAC4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000BAC8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000BACC: bgezl       $t9, L_8000BAF8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000BAD0: lbu         $t6, 0x6($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X6);
            goto L_8000BAF8;
    }
    goto skip_7;
    // 0x8000BAD0: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    skip_7:
    // 0x8000BAD4: lbu         $t1, 0x3($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X3);
    // 0x8000BAD8: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x8000BADC: beql        $t2, $zero, L_8000BAF8
    if (ctx->r10 == 0) {
        // 0x8000BAE0: lbu         $t6, 0x6($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X6);
            goto L_8000BAF8;
    }
    goto skip_8;
    // 0x8000BAE0: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    skip_8:
    // 0x8000BAE4: lbu         $t4, 0xB0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XB0);
    // 0x8000BAE8: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x8000BAEC: sb          $t5, 0xB0($a1)
    MEM_B(0XB0, ctx->r5) = ctx->r13;
    // 0x8000BAF0: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x8000BAF4: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
L_8000BAF8:
    // 0x8000BAF8: b           L_8000BB04
    // 0x8000BAFC: sb          $t6, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r14;
        goto L_8000BB04;
    // 0x8000BAFC: sb          $t6, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r14;
    // 0x8000BB00: sb          $t7, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r15;
L_8000BB04:
    // 0x8000BB04: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x8000BB08: sw          $a2, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r6;
    // 0x8000BB0C: bne         $a3, $at, L_8000BB38
    if (ctx->r7 != ctx->r1) {
        // 0x8000BB10: sw          $t8, 0x40($a1)
        MEM_W(0X40, ctx->r5) = ctx->r24;
            goto L_8000BB38;
    }
    // 0x8000BB10: sw          $t8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r24;
    // 0x8000BB14: lbu         $t1, 0x60($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X60);
    // 0x8000BB18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000BB1C: lwc1        $f10, 0x6AA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6AA8);
    // 0x8000BB20: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8000BB24: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8000BB28: sb          $t2, 0x60($a1)
    MEM_B(0X60, ctx->r5) = ctx->r10;
    // 0x8000BB2C: sb          $t3, 0x34($a1)
    MEM_B(0X34, ctx->r5) = ctx->r11;
    // 0x8000BB30: b           L_8000BBC4
    // 0x8000BB34: swc1        $f10, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f10.u32l;
        goto L_8000BBC4;
    // 0x8000BB34: swc1        $f10, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f10.u32l;
L_8000BB38:
    // 0x8000BB38: lbu         $t6, 0x60($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X60);
    // 0x8000BB3C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000BB40: sb          $t4, 0x34($a1)
    MEM_B(0X34, ctx->r5) = ctx->r12;
    // 0x8000BB44: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8000BB48: sb          $t7, 0x60($a1)
    MEM_B(0X60, ctx->r5) = ctx->r15;
    // 0x8000BB4C: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x8000BB50: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x8000BB54: bne         $v0, $zero, L_8000BB80
    if (ctx->r2 != 0) {
        // 0x8000BB58: nop
    
            goto L_8000BB80;
    }
    // 0x8000BB58: nop

    // 0x8000BB5C: lw          $t9, 0x50($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X50);
    // 0x8000BB60: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x8000BB64: lw          $t8, 0x7738($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7738);
    // 0x8000BB68: lbu         $t1, 0x84($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X84);
    // 0x8000BB6C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000BB70: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x8000BB74: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8000BB78: b           L_8000BB94
    // 0x8000BB7C: swc1        $f16, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f16.u32l;
        goto L_8000BB94;
    // 0x8000BB7C: swc1        $f16, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f16.u32l;
L_8000BB80:
    // 0x8000BB80: lw          $t4, 0x7738($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7738);
    // 0x8000BB84: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000BB88: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8000BB8C: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8000BB90: swc1        $f18, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f18.u32l;
L_8000BB94:
    // 0x8000BB94: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x8000BB98: lwc1        $f8, 0x70($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X70);
    // 0x8000BB9C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8000BBA0: lbu         $t9, 0x85($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X85);
    // 0x8000BBA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000BBA8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8000BBAC: nop

    // 0x8000BBB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000BBB4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000BBB8: nop

    // 0x8000BBBC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000BBC0: swc1        $f18, 0x64($a1)
    MEM_W(0X64, ctx->r5) = ctx->f18.u32l;
L_8000BBC4:
    // 0x8000BBC4: bne         $a3, $t0, L_8000BBE4
    if (ctx->r7 != ctx->r8) {
        // 0x8000BBC8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8000BBE4;
    }
    // 0x8000BBC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000BBCC: jal         0x8000C170
    // 0x8000BBD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8000C170(rdram, ctx);
        goto after_0;
    // 0x8000BBD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000BBD4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BBD8: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x8000BBDC: jal         0x8000C130
    // 0x8000BBE0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_8000C130(rdram, ctx);
        goto after_1;
    // 0x8000BBE0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
L_8000BBE4:
    // 0x8000BBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000BBE8:
    // 0x8000BBE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BBEC: jr          $ra
    // 0x8000BBF0: nop

    return;
    // 0x8000BBF0: nop

;}
RECOMP_FUNC void func_80452A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452A6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80452A70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80452A74: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80452A78: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140F8) << 16);
    // 0x80452A7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80452A80: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80452A84: lwc1        $f10, -0x7B28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140F8));
    // 0x80452A88: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80452A8C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140FC) << 16);
    // 0x80452A90: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80452A94: nop

    // 0x80452A98: bc1f        L_80452AA8
    if (!c1cs) {
        // 0x80452A9C: nop
    
            goto L_80452AA8;
    }
    // 0x80452A9C: nop

    // 0x80452AA0: b           L_80452B90
    // 0x80452AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80452B90;
    // 0x80452AA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80452AA8:
    // 0x80452AA8: lwc1        $f16, -0x7B24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140FC));
    // 0x80452AAC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14100) << 16);
    // 0x80452AB0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80452AB4: nop

    // 0x80452AB8: bc1f        L_80452AE0
    if (!c1cs) {
        // 0x80452ABC: nop
    
            goto L_80452AE0;
    }
    // 0x80452ABC: nop

    // 0x80452AC0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80452AC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80452AC8: beql        $t6, $zero, L_80452B90
    if (ctx->r14 == 0) {
        // 0x80452ACC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80452B90;
    }
    goto skip_0;
    // 0x80452ACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80452AD0: jal         0x80450B18
    // 0x80452AD4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    func_80450B18(rdram, ctx);
        goto after_0;
    // 0x80452AD4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    after_0:
    // 0x80452AD8: b           L_80452B90
    // 0x80452ADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80452B90;
    // 0x80452ADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80452AE0:
    // 0x80452AE0: lwc1        $f18, -0x7B20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14100));
    // 0x80452AE4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80452AE8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80452AEC: nop

    // 0x80452AF0: bc1fl       L_80452B20
    if (!c1cs) {
        // 0x80452AF4: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80452B20;
    }
    goto skip_1;
    // 0x80452AF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x80452AF8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80452AFC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80452B00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80452B04: beql        $v0, $t7, L_80452B90
    if (ctx->r2 == ctx->r15) {
        // 0x80452B08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80452B90;
    }
    goto skip_2;
    // 0x80452B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80452B0C: jal         0x80450B18
    // 0x80452B10: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80450B18(rdram, ctx);
        goto after_1;
    // 0x80452B10: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_1:
    // 0x80452B14: b           L_80452B90
    // 0x80452B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80452B90;
    // 0x80452B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80452B1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80452B20:
    // 0x80452B20: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80452B24: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80452B28: nop

    // 0x80452B2C: bc1fl       L_80452B5C
    if (!c1cs) {
        // 0x80452B30: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80452B5C;
    }
    goto skip_3;
    // 0x80452B30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_3:
    // 0x80452B34: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80452B38: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80452B3C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80452B40: beql        $v0, $t8, L_80452B90
    if (ctx->r2 == ctx->r24) {
        // 0x80452B44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80452B90;
    }
    goto skip_4;
    // 0x80452B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80452B48: jal         0x80450B18
    // 0x80452B4C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80450B18(rdram, ctx);
        goto after_2;
    // 0x80452B4C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_2:
    // 0x80452B50: b           L_80452B90
    // 0x80452B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80452B90;
    // 0x80452B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80452B58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80452B5C:
    // 0x80452B5C: nop

    // 0x80452B60: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80452B64: nop

    // 0x80452B68: bc1fl       L_80452B90
    if (!c1cs) {
        // 0x80452B6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80452B90;
    }
    goto skip_5;
    // 0x80452B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80452B70: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80452B74: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80452B78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80452B7C: beql        $v0, $t9, L_80452B90
    if (ctx->r2 == ctx->r25) {
        // 0x80452B80: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80452B90;
    }
    goto skip_6;
    // 0x80452B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x80452B84: jal         0x80450B18
    // 0x80452B88: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80452B88: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_3:
    // 0x80452B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80452B90:
    // 0x80452B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452B98: jr          $ra
    // 0x80452B9C: nop

    return;
    // 0x80452B9C: nop

;}
RECOMP_FUNC void func_8006806C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006806C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068070: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80068074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068078: addiu       $t6, $t6, -0x7B20
    ctx->r14 = ADD32(ctx->r14, -0X7B20);
    // 0x8006807C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80068080: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80068084: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80068088: beq         $t7, $zero, L_800680A0
    if (ctx->r15 == 0) {
        // 0x8006808C: addiu       $v1, $v1, 0x7EA0
        ctx->r3 = ADD32(ctx->r3, 0X7EA0);
            goto L_800680A0;
    }
    // 0x8006808C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80068090: addiu       $t8, $t8, 0x7FF4
    ctx->r24 = ADD32(ctx->r24, 0X7FF4);
    // 0x80068094: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x80068098: b           L_80068180
    // 0x8006809C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80068180;
    // 0x8006809C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800680A0:
    // 0x800680A0: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x800680A4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800680A8: beq         $v0, $at, L_800680C0
    if (ctx->r2 == ctx->r1) {
        // 0x800680AC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800680C0;
    }
    // 0x800680AC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800680B0: beq         $v0, $at, L_800680C0
    if (ctx->r2 == ctx->r1) {
        // 0x800680B4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800680C0;
    }
    // 0x800680B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800680B8: bnel        $v0, $at, L_80068180
    if (ctx->r2 != ctx->r1) {
        // 0x800680BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80068180;
    }
    goto skip_0;
    // 0x800680BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_800680C0:
    // 0x800680C0: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x800680C4: bnel        $t9, $zero, L_80068180
    if (ctx->r25 != 0) {
        // 0x800680C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80068180;
    }
    goto skip_1;
    // 0x800680C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800680CC: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800680D0: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x800680D4: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800680D8: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x800680DC: bnel        $t1, $at, L_80068180
    if (ctx->r9 != ctx->r1) {
        // 0x800680E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80068180;
    }
    goto skip_2;
    // 0x800680E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800680E4: lhu         $t2, 0xC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XC);
    // 0x800680E8: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x800680EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800680F0: andi        $t3, $t2, 0x1000
    ctx->r11 = ctx->r10 & 0X1000;
    // 0x800680F4: bnel        $t3, $at, L_80068180
    if (ctx->r11 != ctx->r1) {
        // 0x800680F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80068180;
    }
    goto skip_3;
    // 0x800680F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x800680FC: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // 0x80068100: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068104: sb          $zero, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = 0;
    // 0x80068108: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006810C: sb          $zero, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = 0;
    // 0x80068110: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068114: jal         0x800678D0
    // 0x80068118: sb          $v0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r2;
    func_800678D0(rdram, ctx);
        goto after_0;
    // 0x80068118: sb          $v0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r2;
    after_0:
    // 0x8006811C: jal         0x800679B0
    // 0x80068120: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    func_800679B0(rdram, ctx);
        goto after_1;
    // 0x80068120: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_1:
    // 0x80068124: jal         0x80068D24
    // 0x80068128: nop

    func_80068D24(rdram, ctx);
        goto after_2;
    // 0x80068128: nop

    after_2:
    // 0x8006812C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80068130: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80068134: lw          $t4, 0xFB8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XFB8);
    // 0x80068138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006813C: sw          $zero, 0x3F0($v1)
    MEM_W(0X3F0, ctx->r3) = 0;
    // 0x80068140: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80068144: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x80068148: bne         $t6, $at, L_80068168
    if (ctx->r14 != ctx->r1) {
        // 0x8006814C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80068168;
    }
    // 0x8006814C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80068150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80068154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068158: jal         0x8006E0FC
    // 0x8006815C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8006E0FC(rdram, ctx);
        goto after_3;
    // 0x8006815C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_3:
    // 0x80068160: b           L_80068180
    // 0x80068164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80068180;
    // 0x80068164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80068168:
    // 0x80068168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006816C: jal         0x8006E0FC
    // 0x80068170: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    func_8006E0FC(rdram, ctx);
        goto after_4;
    // 0x80068170: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    after_4:
    // 0x80068174: b           L_80068180
    // 0x80068178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80068180;
    // 0x80068178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006817C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80068180:
    // 0x80068180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068188: jr          $ra
    // 0x8006818C: nop

    return;
    // 0x8006818C: nop

;}
RECOMP_FUNC void func_8046CCC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CCC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046CCC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046CCCC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046CCD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046CCD4: jal         0x80048F84
    // 0x8046CCD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046CCD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8046CCDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046CCE0: jal         0x80048F84
    // 0x8046CCE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8046CCE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8046CCE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046CCEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046CCF0: jr          $ra
    // 0x8046CCF4: nop

    return;
    // 0x8046CCF4: nop

;}
RECOMP_FUNC void func_805ADD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADD38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805ADD3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805ADD40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805ADD44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805ADD48: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805ADD4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805ADD50: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805ADD54: lui         $a2, 0x805B
    ctx->r6 = S32(RELOC_HI16(444, 0X1208) << 16);
    // 0x805ADD58: lui         $a1, 0x805B
    ctx->r5 = S32(RELOC_HI16(444, 0X125C) << 16);
    // 0x805ADD5C: addiu       $a1, $a1, -0x16A4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(444, 0X125C));
    // 0x805ADD60: addiu       $a2, $a2, -0x16F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(444, 0X1208));
    // 0x805ADD64: jal         0x805AD7C8
    // 0x805ADD68: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    func_805AD7C8(rdram, ctx);
        goto after_0;
    // 0x805ADD68: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    after_0:
    // 0x805ADD6C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805ADD70: lui         $a1, 0x805B
    ctx->r5 = S32(RELOC_HI16(444, 0X12B0) << 16);
    // 0x805ADD74: lui         $a2, 0x805B
    ctx->r6 = S32(RELOC_HI16(444, 0X1208) << 16);
    // 0x805ADD78: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x805ADD7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805ADD80: addiu       $a2, $a2, -0x16F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(444, 0X1208));
    // 0x805ADD84: addiu       $a1, $a1, -0x1650
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(444, 0X12B0));
    // 0x805ADD88: jal         0x805AD7C8
    // 0x805ADD8C: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    func_805AD7C8(rdram, ctx);
        goto after_1;
    // 0x805ADD8C: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    after_1:
    // 0x805ADD90: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x805ADD94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADD98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805ADD9C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805ADDA0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x805ADDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805ADDA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805ADDAC: jr          $ra
    // 0x805ADDB0: nop

    return;
    // 0x805ADDB0: nop

;}
RECOMP_FUNC void func_804C60A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C60A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C60A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804C60AC: jr          $ra
    // 0x804C60B0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x804C60B0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80475330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475330: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475334: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475338: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047533C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475340: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475344: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475348: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047534C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475350: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475354: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475358: jr          $ra
    // 0x8047535C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047535C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806E511C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E511C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806E5120: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E5124: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806E5128: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806E512C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806E5130: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806E5134: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806E5138: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x806E513C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806E5140: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(649, 0X21B0) << 16);
    // 0x806E5144: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806E5148: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806E514C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E5150: lw          $t1, 0x59B0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(649, 0X21B0));
    // 0x806E5154: jr          $ra
    // 0x806E5158: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806E5158: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x806E515C: nop

;}
RECOMP_FUNC void func_8064B59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B59C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B5A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B5A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064B5A8: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B5AC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8064B5B0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B5B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064B5B8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064B5BC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064B5C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B5C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8064B5C8: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064B5CC: nop

    // 0x8064B5D0: bc1fl       L_8064B5E8
    if (!c1cs) {
        // 0x8064B5D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064B5E8;
    }
    goto skip_0;
    // 0x8064B5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064B5D8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064B5DC: jal         0x8064B918
    // 0x8064B5E0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064B918(rdram, ctx);
        goto after_0;
    // 0x8064B5E0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064B5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064B5E8:
    // 0x8064B5E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B5EC: jr          $ra
    // 0x8064B5F0: nop

    return;
    // 0x8064B5F0: nop

;}
RECOMP_FUNC void func_80465B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465B04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80465B08: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80465B0C: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80465B10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80465B14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80465B18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80465B1C: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80465B20: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80465B24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80465B28: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x80465B2C: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80465B30: addiu       $v0, $s0, 0x285C
    ctx->r2 = ADD32(ctx->r16, 0X285C);
    // 0x80465B34: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80465B38: lw          $t6, 0x285C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X285C);
    // 0x80465B3C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80465B40: bnel        $at, $zero, L_80465B70
    if (ctx->r1 != 0) {
        // 0x80465B44: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_80465B70;
    }
    goto skip_0;
    // 0x80465B44: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80465B48: lw          $t7, 0x2858($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2858);
    // 0x80465B4C: sw          $zero, 0x285C($s0)
    MEM_W(0X285C, ctx->r16) = 0;
    // 0x80465B50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80465B54: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80465B58: sw          $t8, 0x2858($s0)
    MEM_W(0X2858, ctx->r16) = ctx->r24;
    // 0x80465B5C: jal         0x80465A10
    // 0x80465B60: addiu       $a0, $t8, -0x1
    ctx->r4 = ADD32(ctx->r24, -0X1);
    func_80465A10(rdram, ctx);
        goto after_0;
    // 0x80465B60: addiu       $a0, $t8, -0x1
    ctx->r4 = ADD32(ctx->r24, -0X1);
    after_0:
    // 0x80465B64: b           L_80465B78
    // 0x80465B68: nop

        goto L_80465B78;
    // 0x80465B68: nop

    // 0x80465B6C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_80465B70:
    // 0x80465B70: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80465B74: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_80465B78:
    // 0x80465B78: jal         0x804654F8
    // 0x80465B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804654F8(rdram, ctx);
        goto after_1;
    // 0x80465B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80465B80: jal         0x80465708
    // 0x80465B84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80465708(rdram, ctx);
        goto after_2;
    // 0x80465B84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80465B88: jal         0x80465AE8
    // 0x80465B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80465AE8(rdram, ctx);
        goto after_3;
    // 0x80465B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80465B90: lw          $t1, 0x2858($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2858);
    // 0x80465B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80465B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80465B9C: slti        $at, $t1, 0x20
    ctx->r1 = SIGNED(ctx->r9) < 0X20 ? 1 : 0;
    // 0x80465BA0: bne         $at, $zero, L_80465BD0
    if (ctx->r1 != 0) {
        // 0x80465BA4: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80465BD0;
    }
    // 0x80465BA4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80465BA8: jal         0x80465FA4
    // 0x80465BAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80465FA4(rdram, ctx);
        goto after_4;
    // 0x80465BAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80465BB0: addiu       $v0, $s1, 0xC4
    ctx->r2 = ADD32(ctx->r17, 0XC4);
    // 0x80465BB4: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80465BB8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80465BBC: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80465BC0: nop

    // 0x80465BC4: bc1tl       L_80465BD4
    if (c1cs) {
        // 0x80465BC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80465BD4;
    }
    goto skip_1;
    // 0x80465BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80465BCC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_80465BD0:
    // 0x80465BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80465BD4:
    // 0x80465BD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80465BD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80465BDC: jr          $ra
    // 0x80465BE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80465BE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8064AEA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AEA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AEAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064AEB0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8064AEB4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8064AEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AEBC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8064AEC0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8064AEC4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8064AEC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064AECC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8064AED0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8064AED4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8064AED8: lui         $t2, 0x8065
    ctx->r10 = S32(RELOC_HI16(495, 0X2EC0) << 16);
    // 0x8064AEDC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8064AEE0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8064AEE4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8064AEE8: lw          $t2, -0x3070($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(495, 0X2EC0));
    // 0x8064AEEC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064AEF0: jal         0x8064AC90
    // 0x8064AEF4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8064AC90(rdram, ctx);
        goto after_0;
    // 0x8064AEF4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8064AEF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064AEFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064AF00: jr          $ra
    // 0x8064AF04: nop

    return;
    // 0x8064AF04: nop

;}
RECOMP_FUNC void func_8001EFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EFDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EFE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EFE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001EFE8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001EFEC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001EFF0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8001EFF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001EFF8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001EFFC: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001F000: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001F004: jal         0x8001ED3C
    // 0x8001F008: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_8001ED3C(rdram, ctx);
        goto after_0;
    // 0x8001F008: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8001F00C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001F010: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F014: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8001F018: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x8001F01C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001F020: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001F024: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8001F028: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8001F02C: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001F030: jal         0x8001EB3C
    // 0x8001F034: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_8001EB3C(rdram, ctx);
        goto after_1;
    // 0x8001F034: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8001F038: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8001F03C: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x8001F040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F048: jr          $ra
    // 0x8001F04C: nop

    return;
    // 0x8001F04C: nop

;}
RECOMP_FUNC void func_800659EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800659EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800659F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800659F4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800659F8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800659FC: nop

    // 0x80065A00: bc1fl       L_80065A28
    if (!c1cs) {
        // 0x80065A04: c.le.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
            goto L_80065A28;
    }
    goto skip_0;
    // 0x80065A04: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    skip_0:
    // 0x80065A08: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80065A0C: nop

    // 0x80065A10: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
L_80065A14:
    // 0x80065A14: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80065A18: nop

    // 0x80065A1C: bc1tl       L_80065A14
    if (c1cs) {
        // 0x80065A20: add.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
            goto L_80065A14;
    }
    goto skip_1;
    // 0x80065A20: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    skip_1:
    // 0x80065A24: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
L_80065A28:
    // 0x80065A28: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80065A2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80065A30: bc1f        L_80065A4C
    if (!c1cs) {
        // 0x80065A34: nop
    
            goto L_80065A4C;
    }
    // 0x80065A34: nop

    // 0x80065A38: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
L_80065A3C:
    // 0x80065A3C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80065A40: nop

    // 0x80065A44: bc1tl       L_80065A3C
    if (c1cs) {
        // 0x80065A48: sub.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80065A3C;
    }
    goto skip_2;
    // 0x80065A48: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    skip_2:
L_80065A4C:
    // 0x80065A4C: jr          $ra
    // 0x80065A50: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80065A50: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_8006AE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AE28: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006AE2C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006AE30: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8006AE34: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8006AE38: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8006AE3C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8006AE40: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8006AE44: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8006AE48: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006AE4C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006AE50: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006AE54: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006AE58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006AE5C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8006AE60: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8006AE64: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006AE68: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8006AE6C: sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6 << 16);
    // 0x8006AE70: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8006AE74: sll         $s6, $a1, 16
    ctx->r22 = S32(ctx->r5 << 16);
    // 0x8006AE78: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8006AE7C: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8006AE80: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8006AE84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006AE88: lw          $t0, 0x1B0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1B0);
    // 0x8006AE8C: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8006AE90: addiu       $a1, $zero, 0x3FE
    ctx->r5 = ADD32(0, 0X3FE);
    // 0x8006AE94: lw          $s3, 0x20($t0)
    ctx->r19 = MEM_W(ctx->r8, 0X20);
    // 0x8006AE98: sh          $t1, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r9;
    // 0x8006AE9C: bne         $a0, $zero, L_8006AEB8
    if (ctx->r4 != 0) {
        // 0x8006AEA0: lh          $s4, 0x16($s3)
        ctx->r20 = MEM_H(ctx->r19, 0X16);
            goto L_8006AEB8;
    }
    // 0x8006AEA0: lh          $s4, 0x16($s3)
    ctx->r20 = MEM_H(ctx->r19, 0X16);
    // 0x8006AEA4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006AEA8: jal         0x80071380
    // 0x8006AEAC: addiu       $a0, $a0, 0x1030
    ctx->r4 = ADD32(ctx->r4, 0X1030);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006AEAC: addiu       $a0, $a0, 0x1030
    ctx->r4 = ADD32(ctx->r4, 0X1030);
    after_0:
    // 0x8006AEB0: b           L_8006AF70
    // 0x8006AEB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006AF70;
    // 0x8006AEB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006AEB8:
    // 0x8006AEB8: blez        $s5, L_8006AF6C
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8006AEBC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8006AF6C;
    }
    // 0x8006AEBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006AEC0: addiu       $fp, $sp, 0x5A
    ctx->r30 = ADD32(ctx->r29, 0X5A);
    // 0x8006AEC4: lhu         $s7, 0x72($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X72);
    // 0x8006AEC8: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_8006AECC:
    // 0x8006AECC: lh          $t2, 0x58($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X58);
    // 0x8006AED0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8006AED4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8006AED8: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x8006AEDC: bne         $at, $zero, L_8006AF28
    if (ctx->r1 != 0) {
        // 0x8006AEE0: addiu       $a2, $sp, 0x58
        ctx->r6 = ADD32(ctx->r29, 0X58);
            goto L_8006AF28;
    }
    // 0x8006AEE0: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8006AEE4: sll         $a3, $s6, 16
    ctx->r7 = S32(ctx->r22 << 16);
    // 0x8006AEE8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006AEEC: jal         0x8006AB7C
    // 0x8006AEF0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8006AB7C(rdram, ctx);
        goto after_1;
    // 0x8006AEF0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // 0x8006AEF4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006AEF8: bne         $v0, $at, L_8006AF08
    if (ctx->r2 != ctx->r1) {
        // 0x8006AEFC: lh          $t7, 0x58($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X58);
            goto L_8006AF08;
    }
    // 0x8006AEFC: lh          $t7, 0x58($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X58);
    // 0x8006AF00: b           L_8006AF70
    // 0x8006AF04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006AF70;
    // 0x8006AF04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006AF08:
    // 0x8006AF08: multu       $s4, $t7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AF0C: lh          $t4, 0x5A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X5A);
    // 0x8006AF10: lw          $t3, 0x24($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X24);
    // 0x8006AF14: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8006AF18: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8006AF1C: mflo        $t8
    ctx->r24 = lo;
    // 0x8006AF20: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8006AF24: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
L_8006AF28:
    // 0x8006AF28: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x8006AF2C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8006AF30: sll         $t2, $s4, 1
    ctx->r10 = S32(ctx->r20 << 1);
    // 0x8006AF34: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8006AF38: xor         $v0, $s7, $t1
    ctx->r2 = ctx->r23 ^ ctx->r9;
    // 0x8006AF3C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006AF40: beq         $v0, $zero, L_8006AF50
    if (ctx->r2 == 0) {
        // 0x8006AF44: sh          $t0, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r8;
            goto L_8006AF50;
    }
    // 0x8006AF44: sh          $t0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r8;
    // 0x8006AF48: b           L_8006AF70
    // 0x8006AF4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006AF70;
    // 0x8006AF4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006AF50:
    // 0x8006AF50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006AF54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AF58: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x8006AF5C: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8006AF60: bne         $s1, $s5, L_8006AECC
    if (ctx->r17 != ctx->r21) {
        // 0x8006AF64: sra         $s2, $s2, 16
        ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
            goto L_8006AECC;
    }
    // 0x8006AF64: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8006AF68: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8006AF6C:
    // 0x8006AF6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006AF70:
    // 0x8006AF70: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8006AF74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006AF78: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006AF7C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006AF80: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006AF84: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006AF88: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8006AF8C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8006AF90: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8006AF94: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8006AF98: jr          $ra
    // 0x8006AF9C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006AF9C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8003AAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AAB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003AABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003AAC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003AAC4: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8003AAC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003AACC: jal         0x8003A620
    // 0x8003AAD0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    func_8003A620(rdram, ctx);
        goto after_0;
    // 0x8003AAD0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8003AAD4: jal         0x8003A524
    // 0x8003AAD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A524(rdram, ctx);
        goto after_1;
    // 0x8003AAD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003AADC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8003AAE0: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8003AAE4: beq         $t7, $zero, L_8003AB94
    if (ctx->r15 == 0) {
        // 0x8003AAE8: nop
    
            goto L_8003AB94;
    }
    // 0x8003AAE8: nop

    // 0x8003AAEC: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8003AAF0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8003AAF4: bne         $t8, $zero, L_8003AB94
    if (ctx->r24 != 0) {
        // 0x8003AAF8: nop
    
            goto L_8003AB94;
    }
    // 0x8003AAF8: nop

    // 0x8003AAFC: lw          $v0, -0x72E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E8);
    // 0x8003AB00: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003AB04: beq         $v0, $zero, L_8003AB7C
    if (ctx->r2 == 0) {
        // 0x8003AB08: nop
    
            goto L_8003AB7C;
    }
    // 0x8003AB08: nop

    // 0x8003AB0C: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x8003AB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AB14: jalr        $v0
    // 0x8003AB18: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8003AB18: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_2:
    // 0x8003AB1C: jal         0x8004700C
    // 0x8003AB20: nop

    func_8004700C(rdram, ctx);
        goto after_3;
    // 0x8003AB20: nop

    after_3:
    // 0x8003AB24: beq         $v0, $zero, L_8003AB60
    if (ctx->r2 == 0) {
        // 0x8003AB28: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8003AB60;
    }
    // 0x8003AB28: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003AB2C: jal         0x8001D770
    // 0x8003AB30: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x8003AB30: nop

    after_4:
    // 0x8003AB34: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003AB38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003AB3C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8003AB40: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8003AB44: jal         0x80067D94
    // 0x8003AB48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_80067D94(rdram, ctx);
        goto after_5;
    // 0x8003AB48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_5:
    // 0x8003AB4C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x8003AB50: jal         0x80067818
    // 0x8003AB54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8003AB54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8003AB58: b           L_8003AB7C
    // 0x8003AB5C: nop

        goto L_8003AB7C;
    // 0x8003AB5C: nop

L_8003AB60:
    // 0x8003AB60: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003AB64: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8003AB68: jal         0x80067D5C
    // 0x8003AB6C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_7;
    // 0x8003AB6C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_7:
    // 0x8003AB70: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x8003AB74: jal         0x80067818
    // 0x8003AB78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x8003AB78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
L_8003AB7C:
    // 0x8003AB7C: jal         0x800447C8
    // 0x8003AB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_9;
    // 0x8003AB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8003AB84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003AB88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003AB8C: b           L_8003ACD8
    // 0x8003AB90: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
        goto L_8003ACD8;
    // 0x8003AB90: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
L_8003AB94:
    // 0x8003AB94: jal         0x8003A7B0
    // 0x8003AB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A7B0(rdram, ctx);
        goto after_10;
    // 0x8003AB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8003AB9C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003ABA0: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8003ABA4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003ABA8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8003ABAC: jal         0x80065954
    // 0x8003ABB0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_11;
    // 0x8003ABB0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_11:
    // 0x8003ABB4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8003ABB8: jal         0x80065954
    // 0x8003ABBC: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_12;
    // 0x8003ABBC: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_12:
    // 0x8003ABC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003ABC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003ABC8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003ABCC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003ABD0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8003ABD4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8003ABD8: bc1fl       L_8003ABE8
    if (!c1cs) {
        // 0x8003ABDC: c.le.s      $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
            goto L_8003ABE8;
    }
    goto skip_0;
    // 0x8003ABDC: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    skip_0:
    // 0x8003ABE0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8003ABE4: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
L_8003ABE8:
    // 0x8003ABE8: nop

    // 0x8003ABEC: bc1fl       L_8003ACDC
    if (!c1cs) {
        // 0x8003ABF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003ACDC;
    }
    goto skip_1;
    // 0x8003ABF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8003ABF4: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8003ABF8: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8003ABFC: jal         0x80065954
    // 0x8003AC00: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    func_80065954(rdram, ctx);
        goto after_13;
    // 0x8003AC00: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_13:
    // 0x8003AC04: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8003AC08: jal         0x80065954
    // 0x8003AC0C: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    func_80065954(rdram, ctx);
        goto after_14;
    // 0x8003AC0C: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    after_14:
    // 0x8003AC10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003AC14: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003AC18: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003AC1C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003AC20: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8003AC24: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8003AC28: bc1fl       L_8003AC38
    if (!c1cs) {
        // 0x8003AC2C: c.le.s      $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
            goto L_8003AC38;
    }
    goto skip_2;
    // 0x8003AC2C: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    skip_2:
    // 0x8003AC30: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8003AC34: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
L_8003AC38:
    // 0x8003AC38: nop

    // 0x8003AC3C: bc1fl       L_8003ACDC
    if (!c1cs) {
        // 0x8003AC40: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003ACDC;
    }
    goto skip_3;
    // 0x8003AC40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8003AC44: lw          $v0, -0x72E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E8);
    // 0x8003AC48: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AC4C: beq         $v0, $zero, L_8003ACC4
    if (ctx->r2 == 0) {
        // 0x8003AC50: nop
    
            goto L_8003ACC4;
    }
    // 0x8003AC50: nop

    // 0x8003AC54: lw          $a1, 0x10($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X10);
    // 0x8003AC58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AC5C: jalr        $v0
    // 0x8003AC60: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_15;
    // 0x8003AC60: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_15:
    // 0x8003AC64: jal         0x8004700C
    // 0x8003AC68: nop

    func_8004700C(rdram, ctx);
        goto after_16;
    // 0x8003AC68: nop

    after_16:
    // 0x8003AC6C: beq         $v0, $zero, L_8003ACA8
    if (ctx->r2 == 0) {
        // 0x8003AC70: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8003ACA8;
    }
    // 0x8003AC70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003AC74: jal         0x8001D770
    // 0x8003AC78: nop

    func_8001D770(rdram, ctx);
        goto after_17;
    // 0x8003AC78: nop

    after_17:
    // 0x8003AC7C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8003AC80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003AC84: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8003AC88: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8003AC8C: jal         0x80067D94
    // 0x8003AC90: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_80067D94(rdram, ctx);
        goto after_18;
    // 0x8003AC90: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_18:
    // 0x8003AC94: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x8003AC98: jal         0x80067818
    // 0x8003AC9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_19;
    // 0x8003AC9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_19:
    // 0x8003ACA0: b           L_8003ACC4
    // 0x8003ACA4: nop

        goto L_8003ACC4;
    // 0x8003ACA4: nop

L_8003ACA8:
    // 0x8003ACA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003ACAC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8003ACB0: jal         0x80067D5C
    // 0x8003ACB4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_20;
    // 0x8003ACB4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_20:
    // 0x8003ACB8: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x8003ACBC: jal         0x80067818
    // 0x8003ACC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_21;
    // 0x8003ACC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
L_8003ACC4:
    // 0x8003ACC4: jal         0x800447C8
    // 0x8003ACC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_22;
    // 0x8003ACC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8003ACCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003ACD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003ACD4: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
L_8003ACD8:
    // 0x8003ACD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003ACDC:
    // 0x8003ACDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003ACE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8003ACE4: jr          $ra
    // 0x8003ACE8: nop

    return;
    // 0x8003ACE8: nop

;}
RECOMP_FUNC void func_804F536C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F536C: lui         $v0, 0x8050
    ctx->r2 = S32(RELOC_HI16(273, 0X94A0) << 16);
    // 0x804F5370: addiu       $v0, $v0, -0x28D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X94A0));
    // 0x804F5374: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x804F5378: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x804F537C: jr          $ra
    // 0x804F5380: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x804F5380: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800581F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800581F0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800581F4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800581F8: lw          $t6, 0x13B8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X13B8);
    // 0x800581FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80058200: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80058204: sw          $zero, 0x34($t6)
    MEM_W(0X34, ctx->r14) = 0;
    // 0x80058208: lw          $t7, 0x13B8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X13B8);
    // 0x8005820C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80058210: sw          $zero, 0x38($t7)
    MEM_W(0X38, ctx->r15) = 0;
    // 0x80058214: lw          $t8, 0x13B8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X13B8);
    // 0x80058218: swc1        $f0, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f0.u32l;
    // 0x8005821C: lw          $t9, 0x13B8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X13B8);
    // 0x80058220: swc1        $f0, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f0.u32l;
    // 0x80058224: lw          $t0, 0x13B8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X13B8);
    // 0x80058228: swc1        $f0, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f0.u32l;
    // 0x8005822C: lw          $t1, 0x13B8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X13B8);
    // 0x80058230: swc1        $f2, 0x48($t1)
    MEM_W(0X48, ctx->r9) = ctx->f2.u32l;
    // 0x80058234: lw          $t2, 0x13B8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X13B8);
    // 0x80058238: swc1        $f2, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->f2.u32l;
    // 0x8005823C: lw          $t3, 0x13B8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X13B8);
    // 0x80058240: jr          $ra
    // 0x80058244: swc1        $f2, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f2.u32l;
    return;
    // 0x80058244: swc1        $f2, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_8064A664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A66C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064A670: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8064A674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064A678: blez        $v0, L_8064A68C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064A67C: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8064A68C;
    }
    // 0x8064A67C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8064A680: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064A684: b           L_8064A69C
    // 0x8064A688: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064A69C;
    // 0x8064A688: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064A68C:
    // 0x8064A68C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064A690: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064A694: jal         0x8064A97C
    // 0x8064A698: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    func_8064A97C(rdram, ctx);
        goto after_0;
    // 0x8064A698: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    after_0:
L_8064A69C:
    // 0x8064A69C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064A6A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A6A4: jr          $ra
    // 0x8064A6A8: nop

    return;
    // 0x8064A6A8: nop

;}
RECOMP_FUNC void func_806B0DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0DE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B0DE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806B0DE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806B0DEC: jal         0x8004700C
    // 0x806B0DF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806B0DF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806B0DF4: beq         $v0, $zero, L_806B0F54
    if (ctx->r2 == 0) {
        // 0x806B0DF8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806B0F54;
    }
    // 0x806B0DF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806B0DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806B0E00: jal         0x806B0A70
    // 0x806B0E04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_806B0A70(rdram, ctx);
        goto after_1;
    // 0x806B0E04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x806B0E08: bne         $v0, $zero, L_806B0F54
    if (ctx->r2 != 0) {
        // 0x806B0E0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806B0F54;
    }
    // 0x806B0E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806B0E10: jal         0x806B0404
    // 0x806B0E14: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_806B0404(rdram, ctx);
        goto after_2;
    // 0x806B0E14: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x806B0E18: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1758) << 16);
    // 0x806B0E1C: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x806B0E20: lwc1        $f4, 0x16E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1758));
    // 0x806B0E24: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806B0E28: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x806B0E2C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806B0E30: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1760) << 16);
    // 0x806B0E34: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x806B0E38: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806B0E3C: nop

    // 0x806B0E40: bc1fl       L_806B0E50
    if (!c1cs) {
        // 0x806B0E44: lwc1        $f12, 0xC8($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_806B0E50;
    }
    goto skip_0;
    // 0x806B0E44: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x806B0E48: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806B0E4C: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
L_806B0E50:
    // 0x806B0E50: lui         $t8, 0x806B
    ctx->r24 = S32(RELOC_HI16(598, 0XDE8) << 16);
    // 0x806B0E54: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x806B0E58: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x806B0E5C: lwc1        $f2, 0xC4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806B0E60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x806B0E64: addiu       $t8, $t8, 0xD78
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(598, 0XDE8));
    // 0x806B0E68: bc1f        L_806B0E84
    if (!c1cs) {
        // 0x806B0E6C: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_806B0E84;
    }
    // 0x806B0E6C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x806B0E70: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X175C) << 16);
    // 0x806B0E74: lwc1        $f8, 0x16EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X175C));
    // 0x806B0E78: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x806B0E7C: b           L_806B0E90
    // 0x806B0E80: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
        goto L_806B0E90;
    // 0x806B0E80: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
L_806B0E84:
    // 0x806B0E84: lwc1        $f16, 0x16F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1760));
    // 0x806B0E88: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x806B0E8C: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
L_806B0E90:
    // 0x806B0E90: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x806B0E94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B0E98: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806B0E9C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806B0EA0: nop

    // 0x806B0EA4: bc1fl       L_806B0EB8
    if (!c1cs) {
        // 0x806B0EA8: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_806B0EB8;
    }
    goto skip_1;
    // 0x806B0EA8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_1:
    // 0x806B0EAC: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806B0EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806B0EB4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_806B0EB8:
    // 0x806B0EB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806B0EBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B0EC0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X16D8) << 16);
    // 0x806B0EC4: bc1f        L_806B0ED0
    if (!c1cs) {
        // 0x806B0EC8: or          $t6, $zero, $zero
        ctx->r14 = 0 | 0;
            goto L_806B0ED0;
    }
    // 0x806B0EC8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x806B0ECC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_806B0ED0:
    // 0x806B0ED0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806B0ED4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x806B0ED8: lwc1        $f6, 0x1668($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X16D8));
    // 0x806B0EDC: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x806B0EE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806B0EE4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806B0EE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B0EEC: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x806B0EF0: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x806B0EF4: nop

    // 0x806B0EF8: bc1f        L_806B0F18
    if (!c1cs) {
        // 0x806B0EFC: nop
    
            goto L_806B0F18;
    }
    // 0x806B0EFC: nop

    // 0x806B0F00: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x806B0F04: nop

    // 0x806B0F08: bc1f        L_806B0F18
    if (!c1cs) {
        // 0x806B0F0C: nop
    
            goto L_806B0F18;
    }
    // 0x806B0F0C: nop

    // 0x806B0F10: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x806B0F14: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_806B0F18:
    // 0x806B0F18: bne         $v0, $zero, L_806B0F4C
    if (ctx->r2 != 0) {
        // 0x806B0F1C: swc1        $f2, 0xC4($s0)
        MEM_W(0XC4, ctx->r16) = ctx->f2.u32l;
            goto L_806B0F4C;
    }
    // 0x806B0F1C: swc1        $f2, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f2.u32l;
    // 0x806B0F20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B0F24: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x806B0F28: sb          $t9, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r25;
    // 0x806B0F2C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1764) << 16);
    // 0x806B0F30: lwc1        $f16, 0x16F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1764));
    // 0x806B0F34: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1768) << 16);
    // 0x806B0F38: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x806B0F3C: lwc1        $f18, 0x16F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1768));
    // 0x806B0F40: swc1        $f0, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f0.u32l;
    // 0x806B0F44: swc1        $f0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f0.u32l;
    // 0x806B0F48: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
L_806B0F4C:
    // 0x806B0F4C: jal         0x806AFFC8
    // 0x806B0F50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_806AFFC8(rdram, ctx);
        goto after_3;
    // 0x806B0F50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
L_806B0F54:
    // 0x806B0F54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806B0F58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806B0F5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B0F60: jr          $ra
    // 0x806B0F64: nop

    return;
    // 0x806B0F64: nop

;}
RECOMP_FUNC void func_807ADF10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADF10: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807ADF14: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x807ADF18: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x807ADF1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807ADF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807ADF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ADF28: jal         0x8005A52C
    // 0x807ADF2C: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    func_8005A52C(rdram, ctx);
        goto after_0;
    // 0x807ADF2C: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x807ADF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ADF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807ADF38: jr          $ra
    // 0x807ADF3C: nop

    return;
    // 0x807ADF3C: nop

;}
RECOMP_FUNC void func_807C3FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C3FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3FE4: jal         0x807C3FB4
    // 0x807C3FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807C3FB4(rdram, ctx);
        goto after_0;
    // 0x807C3FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807C3FEC: jal         0x80045BD8
    // 0x807C3FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x807C3FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807C3FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C3FF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C3FFC: jr          $ra
    // 0x807C4000: nop

    return;
    // 0x807C4000: nop

;}
RECOMP_FUNC void func_80027A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027A4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80027A50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80027A54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80027A58: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80027A5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80027A60: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80027A64: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x80027A68: jal         0x80024680
    // 0x80027A6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80027A6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80027A70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80027A74: bne         $v0, $at, L_80027A84
    if (ctx->r2 != ctx->r1) {
        // 0x80027A78: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80027A84;
    }
    // 0x80027A78: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80027A7C: b           L_80027AD4
    // 0x80027A80: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80027AD4;
    // 0x80027A80: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80027A84:
    // 0x80027A84: lw          $t6, 0x14C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14C);
    // 0x80027A88: addiu       $at, $zero, 0x84
    ctx->r1 = ADD32(0, 0X84);
    // 0x80027A8C: bnel        $t6, $at, L_80027AD4
    if (ctx->r14 != ctx->r1) {
        // 0x80027A90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80027AD4;
    }
    goto skip_0;
    // 0x80027A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80027A94: lw          $t7, 0x154($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X154);
    // 0x80027A98: addiu       $a0, $zero, 0x20D
    ctx->r4 = ADD32(0, 0X20D);
    // 0x80027A9C: bnel        $t7, $zero, L_80027AD4
    if (ctx->r15 != 0) {
        // 0x80027AA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80027AD4;
    }
    goto skip_1;
    // 0x80027AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80027AA4: jal         0x80067818
    // 0x80027AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80027AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80027AAC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80027AB0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80027AB4: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x80027AB8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80027ABC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80027AC0: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x80027AC4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80027AC8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80027ACC: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x80027AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027AD4:
    // 0x80027AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80027AD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80027ADC: jr          $ra
    // 0x80027AE0: nop

    return;
    // 0x80027AE0: nop

;}
RECOMP_FUNC void func_804CF594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF594: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CF598: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CF59C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CF5A0: jal         0x8004700C
    // 0x804CF5A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CF5A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804CF5A8: beq         $v0, $zero, L_804CF5F4
    if (ctx->r2 == 0) {
        // 0x804CF5AC: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804CF5F4;
    }
    // 0x804CF5AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804CF5B0: jal         0x804CF4E4
    // 0x804CF5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF4E4(rdram, ctx);
        goto after_1;
    // 0x804CF5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CF5B8: jal         0x804CF450
    // 0x804CF5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF450(rdram, ctx);
        goto after_2;
    // 0x804CF5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804CF5C0: jal         0x804CF440
    // 0x804CF5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF440(rdram, ctx);
        goto after_3;
    // 0x804CF5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CF5C8: jal         0x804CF3A4
    // 0x804CF5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF3A4(rdram, ctx);
        goto after_4;
    // 0x804CF5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804CF5D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804CF5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CF5D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CF5DC: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x804CF5E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CF5E4: bnel        $s0, $t7, L_804CF5F8
    if (ctx->r16 != ctx->r15) {
        // 0x804CF5E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CF5F8;
    }
    goto skip_0;
    // 0x804CF5E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804CF5EC: jal         0x804CFBB8
    // 0x804CF5F0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804CFBB8(rdram, ctx);
        goto after_5;
    // 0x804CF5F0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
L_804CF5F4:
    // 0x804CF5F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CF5F8:
    // 0x804CF5F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CF5FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CF600: jr          $ra
    // 0x804CF604: nop

    return;
    // 0x804CF604: nop

;}
RECOMP_FUNC void func_805E4C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4C80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4C84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4C88: jal         0x805E4BB8
    // 0x805E4C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805E4BB8(rdram, ctx);
        goto after_0;
    // 0x805E4C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4C90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E4C94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4C98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805E4C9C: jal         0x805E4D78
    // 0x805E4CA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805E4D78(rdram, ctx);
        goto after_1;
    // 0x805E4CA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805E4CA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E4CA8: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(486, 0X1010) << 16);
    // 0x805E4CAC: lwc1        $f4, 0x5150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(486, 0X1010));
    // 0x805E4CB0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4CB4: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805E4CB8: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x805E4CBC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x805E4CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4CC8: jr          $ra
    // 0x805E4CCC: nop

    return;
    // 0x805E4CCC: nop

;}
RECOMP_FUNC void func_80739A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80739A30: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(739, 0XB14) << 16);
    // 0x80739A34: addiu       $v0, $v0, -0x5ABC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(739, 0XB14));
    // 0x80739A38: jr          $ra
    // 0x80739A3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80739A3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804F5598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5598: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804F559C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804F55A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F55A4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F55A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804F55AC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x804F55B0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x804F55B4: jal         0x80067BBC
    // 0x804F55B8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x804F55B8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x804F55BC: addiu       $a0, $zero, 0x1FD
    ctx->r4 = ADD32(0, 0X1FD);
    // 0x804F55C0: jal         0x80067818
    // 0x804F55C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x804F55C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x804F55C8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804F55CC: lui         $v0, 0x8050
    ctx->r2 = S32(RELOC_HI16(273, 0XDED0) << 16);
    // 0x804F55D0: addiu       $v0, $v0, 0x2160
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0XDED0));
    // 0x804F55D4: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x804F55D8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x804F55DC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x804F55E0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x804F55E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F55E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F55EC: jal         0x804F5CE8
    // 0x804F55F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_804F5CE8(rdram, ctx);
        goto after_2;
    // 0x804F55F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x804F55F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804F55F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804F55FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804F5600: jr          $ra
    // 0x804F5604: nop

    return;
    // 0x804F5604: nop

;}
RECOMP_FUNC void func_80553B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553B08: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80553B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80553B10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80553B14: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80553B18: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x80553B1C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80553B20: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80553B24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80553B28: bne         $t7, $at, L_80553CCC
    if (ctx->r15 != ctx->r1) {
        // 0x80553B2C: or          $t6, $a0, $zero
        ctx->r14 = ctx->r4 | 0;
            goto L_80553CCC;
    }
    // 0x80553B2C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80553B30: addiu       $a0, $v0, 0x918
    ctx->r4 = ADD32(ctx->r2, 0X918);
    // 0x80553B34: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80553B38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80553B3C: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x80553B40: jal         0x805539DC
    // 0x80553B44: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_805539DC(rdram, ctx);
        goto after_0;
    // 0x80553B44: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80553B48: beql        $v0, $zero, L_80553D1C
    if (ctx->r2 == 0) {
        // 0x80553B4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80553D1C;
    }
    goto skip_0;
    // 0x80553B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80553B50: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80553B54: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80553B58: beq         $v0, $at, L_80553BAC
    if (ctx->r2 == ctx->r1) {
        // 0x80553B5C: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_80553BAC;
    }
    // 0x80553B5C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80553B60: bnel        $v0, $at, L_80553CB8
    if (ctx->r2 != ctx->r1) {
        // 0x80553B64: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80553CB8;
    }
    goto skip_1;
    // 0x80553B64: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_1:
    // 0x80553B68: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80553B6C: jal         0x80067BBC
    // 0x80553B70: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x80553B70: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x80553B74: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80553B78: jal         0x80067818
    // 0x80553B7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80553B7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80553B80: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80553B84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80553B88: sb          $t8, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r24;
    // 0x80553B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80553B90: jalr        $t9
    // 0x80553B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80553B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80553B98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80553B9C: nop

    // 0x80553BA0: swc1        $f2, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f2.u32l;
    // 0x80553BA4: b           L_80553CB4
    // 0x80553BA8: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
        goto L_80553CB4;
    // 0x80553BA8: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
L_80553BAC:
    // 0x80553BAC: jal         0x80065954
    // 0x80553BB0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x80553BB0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x80553BB4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80553BB8: jal         0x80065954
    // 0x80553BBC: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x80553BBC: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x80553BC0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80553BC4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80553BC8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80553BCC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80553BD0: bc1fl       L_80553C4C
    if (!c1cs) {
        // 0x80553BD4: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80553C4C;
    }
    goto skip_2;
    // 0x80553BD4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_2:
    // 0x80553BD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80553BDC: nop

    // 0x80553BE0: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80553BE4: nop

    // 0x80553BE8: bc1fl       L_80553C20
    if (!c1cs) {
        // 0x80553BEC: lwc1        $f0, 0xC8($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80553C20;
    }
    goto skip_3;
    // 0x80553BEC: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    skip_3:
    // 0x80553BF0: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80553BF4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80553BF8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80553BFC: nop

    // 0x80553C00: bc1fl       L_80553CB8
    if (!c1cs) {
        // 0x80553C04: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80553CB8;
    }
    goto skip_4;
    // 0x80553C04: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_4:
    // 0x80553C08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80553C0C: nop

    // 0x80553C10: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80553C14: b           L_80553CB4
    // 0x80553C18: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
        goto L_80553CB4;
    // 0x80553C18: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x80553C1C: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
L_80553C20:
    // 0x80553C20: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80553C24: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80553C28: nop

    // 0x80553C2C: bc1fl       L_80553CB8
    if (!c1cs) {
        // 0x80553C30: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80553CB8;
    }
    goto skip_5;
    // 0x80553C30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_5:
    // 0x80553C34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80553C38: nop

    // 0x80553C3C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80553C40: b           L_80553CB4
    // 0x80553C44: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
        goto L_80553CB4;
    // 0x80553C44: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    // 0x80553C48: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80553C4C:
    // 0x80553C4C: nop

    // 0x80553C50: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80553C54: nop

    // 0x80553C58: bc1fl       L_80553C90
    if (!c1cs) {
        // 0x80553C5C: lwc1        $f0, 0xC4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_80553C90;
    }
    goto skip_6;
    // 0x80553C5C: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    skip_6:
    // 0x80553C60: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80553C64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80553C68: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80553C6C: nop

    // 0x80553C70: bc1fl       L_80553CB8
    if (!c1cs) {
        // 0x80553C74: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80553CB8;
    }
    goto skip_7;
    // 0x80553C74: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_7:
    // 0x80553C78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80553C7C: nop

    // 0x80553C80: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80553C84: b           L_80553CB4
    // 0x80553C88: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
        goto L_80553CB4;
    // 0x80553C88: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x80553C8C: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
L_80553C90:
    // 0x80553C90: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80553C94: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80553C98: nop

    // 0x80553C9C: bc1fl       L_80553CB8
    if (!c1cs) {
        // 0x80553CA0: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80553CB8;
    }
    goto skip_8;
    // 0x80553CA0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_8:
    // 0x80553CA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80553CA8: nop

    // 0x80553CAC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80553CB0: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
L_80553CB4:
    // 0x80553CB4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_80553CB8:
    // 0x80553CB8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80553CBC: jal         0x8055394C
    // 0x80553CC0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_8055394C(rdram, ctx);
        goto after_6;
    // 0x80553CC0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_6:
    // 0x80553CC4: b           L_80553D1C
    // 0x80553CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80553D1C;
    // 0x80553CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80553CCC:
    // 0x80553CCC: lhu         $t0, 0xC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC);
    // 0x80553CD0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80553CD4: addiu       $a0, $v0, 0x918
    ctx->r4 = ADD32(ctx->r2, 0X918);
    // 0x80553CD8: bne         $t0, $at, L_80553D18
    if (ctx->r8 != ctx->r1) {
        // 0x80553CDC: lw          $a1, 0x48($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X48);
            goto L_80553D18;
    }
    // 0x80553CDC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80553CE0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80553CE4: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x80553CE8: jal         0x805539DC
    // 0x80553CEC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_805539DC(rdram, ctx);
        goto after_7;
    // 0x80553CEC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_7:
    // 0x80553CF0: beq         $v0, $zero, L_80553D18
    if (ctx->r2 == 0) {
        // 0x80553CF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80553D18;
    }
    // 0x80553CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80553CF8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80553CFC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80553D00: jal         0x8002F6E4
    // 0x80553D04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_8;
    // 0x80553D04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80553D08: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80553D0C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80553D10: jal         0x8055394C
    // 0x80553D14: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_8055394C(rdram, ctx);
        goto after_9;
    // 0x80553D14: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_9:
L_80553D18:
    // 0x80553D18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80553D1C:
    // 0x80553D1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80553D20: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80553D24: jr          $ra
    // 0x80553D28: nop

    return;
    // 0x80553D28: nop

;}
RECOMP_FUNC void func_80715864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80715868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8071586C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80715870: jal         0x807155F8
    // 0x80715874: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807155F8(rdram, ctx);
        goto after_0;
    // 0x80715874: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80715878: beq         $v0, $zero, L_807158BC
    if (ctx->r2 == 0) {
        // 0x8071587C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807158BC;
    }
    // 0x8071587C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80715880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80715884: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80715888: jal         0x80715C24
    // 0x8071588C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80715C24(rdram, ctx);
        goto after_1;
    // 0x8071588C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80715890: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80715894: jal         0x80714A38
    // 0x80715898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80714A38(rdram, ctx);
        goto after_2;
    // 0x80715898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8071589C: jal         0x8071568C
    // 0x807158A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8071568C(rdram, ctx);
        goto after_3;
    // 0x807158A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807158A4: beql        $v0, $zero, L_807158C0
    if (ctx->r2 == 0) {
        // 0x807158A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807158C0;
    }
    goto skip_0;
    // 0x807158A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807158AC: jal         0x80715840
    // 0x807158B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80715840(rdram, ctx);
        goto after_4;
    // 0x807158B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807158B4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x807158B8: sw          $zero, 0x5F8($v0)
    MEM_W(0X5F8, ctx->r2) = 0;
L_807158BC:
    // 0x807158BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807158C0:
    // 0x807158C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807158C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807158C8: jr          $ra
    // 0x807158CC: nop

    return;
    // 0x807158CC: nop

;}
RECOMP_FUNC void func_805A0790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A0790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A0794: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805A0798: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805A079C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805A07A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A07A4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805A07A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805A07AC: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x805A07B0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805A07B4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805A07B8: lui         $t2, 0x805A
    ctx->r10 = S32(RELOC_HI16(408, 0X1DB4) << 16);
    // 0x805A07BC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805A07C0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805A07C4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805A07C8: lw          $t2, 0x1114($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(408, 0X1DB4));
    // 0x805A07CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805A07D0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x805A07D4: jal         0x805A071C
    // 0x805A07D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A071C(rdram, ctx);
        goto after_0;
    // 0x805A07D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A07DC: jal         0x805A0768
    // 0x805A07E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805A0768(rdram, ctx);
        goto after_1;
    // 0x805A07E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A07E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A07E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A07EC: jr          $ra
    // 0x805A07F0: nop

    return;
    // 0x805A07F0: nop

    // 0x805A07F4: nop

    // 0x805A07F8: nop

    // 0x805A07FC: nop

;}
RECOMP_FUNC void func_8043CEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043CEDC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8043CEE0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8043CEE4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8043CEE8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8043CEEC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8043CEF0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8043CEF4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8043CEF8: lui         $t1, 0x8044
    ctx->r9 = S32(RELOC_HI16(89, 0X12E0) << 16);
    // 0x8043CEFC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8043CF00: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8043CF04: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8043CF08: lw          $t1, -0x30E0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(89, 0X12E0));
    // 0x8043CF0C: jr          $ra
    // 0x8043CF10: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8043CF10: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8043CF14: nop

    // 0x8043CF18: nop

    // 0x8043CF1C: nop

;}
RECOMP_FUNC void func_8046D218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046D218: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8046D21C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046D220: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(143, 0X15A8) << 16);
    // 0x8046D224: lwc1        $f14, -0x2608($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(143, 0X15A8));
    // 0x8046D228: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8046D22C: lwc1        $f12, 0x78($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8046D230: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8046D234: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8046D238: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8046D23C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8046D240: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8046D244: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8046D248: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8046D24C: bc1fl       L_8046D25C
    if (!c1cs) {
        // 0x8046D250: lwc1        $f12, 0x7C($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
            goto L_8046D25C;
    }
    goto skip_0;
    // 0x8046D250: lwc1        $f12, 0x7C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
    skip_0:
    // 0x8046D254: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8046D258: lwc1        $f12, 0x7C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
L_8046D25C:
    // 0x8046D25C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8046D260: nop

    // 0x8046D264: bc1fl       L_8046D274
    if (!c1cs) {
        // 0x8046D268: swc1        $f0, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
            goto L_8046D274;
    }
    goto skip_1;
    // 0x8046D268: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x8046D26C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8046D270: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
L_8046D274:
    // 0x8046D274: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x8046D278: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8046D27C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8046D280: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8046D284: lw          $t6, 0x68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X68);
    // 0x8046D288: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(143, 0X139C) << 16);
    // 0x8046D28C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046D290: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8046D294: lw          $t9, -0x2814($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(143, 0X139C));
    // 0x8046D298: jalr        $t9
    // 0x8046D29C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8046D29C: nop

    after_0:
    // 0x8046D2A0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8046D2A4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8046D2A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8046D2AC: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8046D2B0: andi        $t0, $t8, 0xF00
    ctx->r8 = ctx->r24 & 0XF00;
    // 0x8046D2B4: beql        $t0, $zero, L_8046D2FC
    if (ctx->r8 == 0) {
        // 0x8046D2B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046D2FC;
    }
    goto skip_2;
    // 0x8046D2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8046D2BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8046D2C0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046D2C4: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8046D2C8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8046D2CC: nop

    // 0x8046D2D0: bc1fl       L_8046D2FC
    if (!c1cs) {
        // 0x8046D2D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046D2FC;
    }
    goto skip_3;
    // 0x8046D2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8046D2D8: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046D2DC: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8046D2E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046D2E4: sb          $t1, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r9;
    // 0x8046D2E8: lw          $t4, 0x1F4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046D2EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8046D2F0: jal         0x8046D3E8
    // 0x8046D2F4: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    func_8046D3E8(rdram, ctx);
        goto after_1;
    // 0x8046D2F4: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    after_1:
    // 0x8046D2F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046D2FC:
    // 0x8046D2FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8046D300: jr          $ra
    // 0x8046D304: nop

    return;
    // 0x8046D304: nop

;}
RECOMP_FUNC void func_8003DD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DD18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DD1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DD20: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8003DD24: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8003DD28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003DD2C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003DD30: lwc1        $f10, 0x7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003DD34: addiu       $t6, $v0, -0x20
    ctx->r14 = ADD32(ctx->r2, -0X20);
    // 0x8003DD38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003DD3C: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8003DD40: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8003DD44: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003DD48: nop

    // 0x8003DD4C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003DD50: beq         $at, $zero, L_8003DD60
    if (ctx->r1 == 0) {
        // 0x8003DD54: swc1        $f16, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
            goto L_8003DD60;
    }
    // 0x8003DD54: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x8003DD58: jal         0x8003DB3C
    // 0x8003DD5C: nop

    func_8003DB3C(rdram, ctx);
        goto after_0;
    // 0x8003DD5C: nop

    after_0:
L_8003DD60:
    // 0x8003DD60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DD64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DD68: jr          $ra
    // 0x8003DD6C: nop

    return;
    // 0x8003DD6C: nop

;}
RECOMP_FUNC void func_80455210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80455214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455218: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13918) << 16);
    // 0x8045521C: jal         0x804547C0
    // 0x80455220: lw          $a1, 0x7CF8($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13918));
    func_804547C0(rdram, ctx);
        goto after_0;
    // 0x80455220: lw          $a1, 0x7CF8($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13918));
    after_0:
    // 0x80455224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045522C: jr          $ra
    // 0x80455230: nop

    return;
    // 0x80455230: nop

;}
RECOMP_FUNC void func_8043E0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E0F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043E0FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8043E100: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8043E104: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8043E108: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(92, 0X1B10) << 16);
    // 0x8043E10C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8043E110: lw          $t6, -0x14B0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(92, 0X1B10));
    // 0x8043E114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E118: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8043E11C: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8043E120: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8043E124: jal         0x8043DD2C
    // 0x8043E128: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8043DD2C(rdram, ctx);
        goto after_0;
    // 0x8043E128: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043E12C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E130: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(92, 0X1B20) << 16);
    // 0x8043E134: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043E138: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8043E13C: lw          $t9, -0x14A0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(92, 0X1B20));
    // 0x8043E140: jalr        $t9
    // 0x8043E144: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8043E144: nop

    after_1:
    // 0x8043E148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E14C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043E150: jr          $ra
    // 0x8043E154: nop

    return;
    // 0x8043E154: nop

;}
RECOMP_FUNC void func_804C32A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C32A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C32AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C32B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C32B4: jal         0x804C319C
    // 0x804C32B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804C319C(rdram, ctx);
        goto after_0;
    // 0x804C32B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804C32BC: jal         0x804C2AC0
    // 0x804C32C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C2AC0(rdram, ctx);
        goto after_1;
    // 0x804C32C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C32C4: jal         0x804C2E14
    // 0x804C32C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C2E14(rdram, ctx);
        goto after_2;
    // 0x804C32C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804C32CC: jal         0x804C31FC
    // 0x804C32D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C31FC(rdram, ctx);
        goto after_3;
    // 0x804C32D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804C32D4: bne         $v0, $zero, L_804C32FC
    if (ctx->r2 != 0) {
        // 0x804C32D8: lui         $t6, 0x804C
        ctx->r14 = S32(RELOC_HI16(206, 0X710) << 16);
            goto L_804C32FC;
    }
    // 0x804C32D8: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(206, 0X710) << 16);
    // 0x804C32DC: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804C32E0: addiu       $t6, $t6, 0x3190
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(206, 0X710));
    // 0x804C32E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C32E8: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x804C32EC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x804C32F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C32F4: jal         0x804C3618
    // 0x804C32F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804C3618(rdram, ctx);
        goto after_4;
    // 0x804C32F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
L_804C32FC:
    // 0x804C32FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C3300: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C3304: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C3308: jr          $ra
    // 0x804C330C: nop

    return;
    // 0x804C330C: nop

;}
RECOMP_FUNC void func_8044D140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D140: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8044D144: div         $zero, $a3, $t0
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r8)));
    // 0x8044D148: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8044D14C: or          $t7, $a3, $zero
    ctx->r15 = ctx->r7 | 0;
    // 0x8044D150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044D154: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8044D158: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8044D15C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8044D160: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x8044D164: lw          $a2, 0x4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4);
    // 0x8044D168: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x8044D16C: mflo        $a3
    ctx->r7 = lo;
    // 0x8044D170: mfhi        $v1
    ctx->r3 = hi;
    // 0x8044D174: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x8044D178: bne         $t0, $zero, L_8044D184
    if (ctx->r8 != 0) {
        // 0x8044D17C: nop
    
            goto L_8044D184;
    }
    // 0x8044D17C: nop

    // 0x8044D180: break       7
    do_break(2151993728);
L_8044D184:
    // 0x8044D184: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8044D188: bne         $t0, $at, L_8044D19C
    if (ctx->r8 != ctx->r1) {
        // 0x8044D18C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8044D19C;
    }
    // 0x8044D18C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044D190: bne         $t7, $at, L_8044D19C
    if (ctx->r15 != ctx->r1) {
        // 0x8044D194: nop
    
            goto L_8044D19C;
    }
    // 0x8044D194: nop

    // 0x8044D198: break       6
    do_break(2151993752);
L_8044D19C:
    // 0x8044D19C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8044D1A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8044D1A4: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8044D1A8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8044D1AC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8044D1B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8044D1B4: jal         0x8044CD4C
    // 0x8044D1B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8044CD4C(rdram, ctx);
        goto after_0;
    // 0x8044D1B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8044D1BC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8044D1C0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8044D1C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044D1C8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8044D1CC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8044D1D0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8044D1D4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8044D1D8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8044D1DC: jal         0x8044CED4
    // 0x8044D1E0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_8044CED4(rdram, ctx);
        goto after_1;
    // 0x8044D1E0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_1:
    // 0x8044D1E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044D1E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8044D1EC: jr          $ra
    // 0x8044D1F0: nop

    return;
    // 0x8044D1F0: nop

;}
RECOMP_FUNC void func_80050C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050C48: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80050C4C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80050C50: or          $a0, $sp, $zero
    ctx->r4 = ctx->r29 | 0;
    // 0x80050C54: addiu       $a0, $a0, 0x2F
    ctx->r4 = ADD32(ctx->r4, 0X2F);
    // 0x80050C58: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x80050C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050C60: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80050C64: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80050C68: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x80050C6C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80050C70: jal         0x800675D0
    // 0x80050C74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x80050C74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80050C78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80050C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050C80: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80050C84: jr          $ra
    // 0x80050C88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80050C88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80080FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080FCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80080FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080FD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80080FD8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80080FDC: jal         0x80082730
    // 0x80080FE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fsin(rdram, ctx);
        goto after_0;
    // 0x80080FE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80080FE4: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80080FE8: jal         0x8008D250
    // 0x80080FEC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80080FEC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80080FF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80080FF4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80080FF8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80080FFC: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80081000: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081004: nop

    // 0x80081008: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8008100C: nop

    // 0x80081010: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80081014: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80081018: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8008101C: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80081020: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80081024: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081028: nop

    // 0x8008102C: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80081030: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80081034: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081038: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8008103C: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80081040: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081044: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80081048: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8008104C: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081050: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80081054: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80081058: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x8008105C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081060: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80081064: lwc1        $f2, 0x30($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80081068: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8008106C: lwc1        $f12, 0x34($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80081070: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80081074: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80081078: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8008107C: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80081080: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x80081084: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081088: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8008108C: nop

    // 0x80081090: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081094: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80081098: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8008109C: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x800810A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800810A4: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x800810A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800810AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800810B0: jr          $ra
    // 0x800810B4: nop

    return;
    // 0x800810B4: nop

;}
RECOMP_FUNC void func_80531774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531774: lwc1        $f0, 0x270($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X270);
    // 0x80531778: lwc1        $f4, 0x26C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X26C);
    // 0x8053177C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80531780: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80531784: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80531788: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8053178C: addiu       $v0, $a1, 0x26C
    ctx->r2 = ADD32(ctx->r5, 0X26C);
    // 0x80531790: swc1        $f6, 0x26C($a1)
    MEM_W(0X26C, ctx->r5) = ctx->f6.u32l;
    // 0x80531794: lwc1        $f8, 0x26C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X26C);
    // 0x80531798: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8053179C: nop

    // 0x805317A0: bc1fl       L_805317BC
    if (!c1cs) {
        // 0x805317A4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_805317BC;
    }
    goto skip_0;
    // 0x805317A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x805317A8: addiu       $v0, $a1, 0x26C
    ctx->r2 = ADD32(ctx->r5, 0X26C);
    // 0x805317AC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x805317B0: b           L_805317D8
    // 0x805317B4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
        goto L_805317D8;
    // 0x805317B4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805317B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_805317BC:
    // 0x805317BC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805317C0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805317C4: nop

    // 0x805317C8: bc1fl       L_805317DC
    if (!c1cs) {
        // 0x805317CC: addiu       $v0, $a0, 0x40
        ctx->r2 = ADD32(ctx->r4, 0X40);
            goto L_805317DC;
    }
    goto skip_1;
    // 0x805317CC: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
    skip_1:
    // 0x805317D0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x805317D4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_805317D8:
    // 0x805317D8: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
L_805317DC:
    // 0x805317DC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805317E0: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x805317E4: jr          $ra
    // 0x805317E8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x805317E8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_805361D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805361D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805361D8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805361DC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805361E0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805361E4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805361E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805361EC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805361F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805361F4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805361F8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805361FC: jr          $ra
    // 0x80536200: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536200: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8069EC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069EC9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8069ECA0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8069ECA4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8069ECA8: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(577, 0X9CC) << 16);
    // 0x8069ECAC: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8069ECB0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8069ECB4: lw          $t7, -0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(577, 0X9CC));
    // 0x8069ECB8: jr          $ra
    // 0x8069ECBC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x8069ECBC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8003B8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B8F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003B8F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B8F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003B8FC: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8003B900: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8003B904: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003B908: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003B90C: jal         0x80047090
    // 0x8003B910: addiu       $a0, $zero, 0x4002
    ctx->r4 = ADD32(0, 0X4002);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8003B910: addiu       $a0, $zero, 0x4002
    ctx->r4 = ADD32(0, 0X4002);
    after_0:
    // 0x8003B914: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003B918: lui         $at, 0x4002
    ctx->r1 = S32(0X4002 << 16);
    // 0x8003B91C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8003B920: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8003B924: lw          $a0, 0x4268($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4268);
    // 0x8003B928: or          $a1, $v0, $at
    ctx->r5 = ctx->r2 | ctx->r1;
    // 0x8003B92C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8003B930: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B934: jal         0x80046804
    // 0x8003B938: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x8003B938: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8003B93C: beq         $v0, $zero, L_8003B9C4
    if (ctx->r2 == 0) {
        // 0x8003B940: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003B9C4;
    }
    // 0x8003B940: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003B944: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8003B948: addiu       $t6, $t6, -0x7218
    ctx->r14 = ADD32(ctx->r14, -0X7218);
    // 0x8003B94C: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x8003B950: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003B954: jal         0x8003B8B0
    // 0x8003B958: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8003B8B0(rdram, ctx);
        goto after_2;
    // 0x8003B958: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8003B95C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003B960: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
    // 0x8003B964: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x8003B968: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x8003B96C: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x8003B970: swc1        $f0, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f0.u32l;
    // 0x8003B974: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8003B978: beq         $v0, $zero, L_8003B9C4
    if (ctx->r2 == 0) {
        // 0x8003B97C: swc1        $f0, 0xC4($s0)
        MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
            goto L_8003B9C4;
    }
    // 0x8003B97C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8003B980: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003B984: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003B988: addiu       $t0, $zero, 0x112
    ctx->r8 = ADD32(0, 0X112);
    // 0x8003B98C: sh          $v1, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r3;
    // 0x8003B990: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003B994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003B998: sh          $v1, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r3;
    // 0x8003B99C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003B9A0: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8003B9A4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8003B9A8: jal         0x8004A73C
    // 0x8003B9AC: sh          $t0, 0x4C($t1)
    MEM_H(0X4C, ctx->r9) = ctx->r8;
    func_8004A73C(rdram, ctx);
        goto after_3;
    // 0x8003B9AC: sh          $t0, 0x4C($t1)
    MEM_H(0X4C, ctx->r9) = ctx->r8;
    after_3:
    // 0x8003B9B0: lw          $a0, 0x174($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X174);
    // 0x8003B9B4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8003B9B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B9BC: jal         0x800657CC
    // 0x8003B9C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800657CC(rdram, ctx);
        goto after_4;
    // 0x8003B9C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
L_8003B9C4:
    // 0x8003B9C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003B9C8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003B9CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003B9D0: jr          $ra
    // 0x8003B9D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003B9D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80030CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030CD8: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80030CDC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80030CE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030CE4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80030CE8: nop

    // 0x80030CEC: bc1f        L_80030D04
    if (!c1cs) {
        // 0x80030CF0: nop
    
            goto L_80030D04;
    }
    // 0x80030CF0: nop

    // 0x80030CF4: jal         0x8002CA68
    // 0x80030CF8: nop

    func_8002CA68(rdram, ctx);
        goto after_0;
    // 0x80030CF8: nop

    after_0:
    // 0x80030CFC: b           L_80030D04
    // 0x80030D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030D04;
    // 0x80030D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80030D04:
    // 0x80030D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030D0C: jr          $ra
    // 0x80030D10: nop

    return;
    // 0x80030D10: nop

;}
RECOMP_FUNC void func_8078A5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A5D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078A5D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078A5DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8078A5E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8078A5E4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8078A5E8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8078A5EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078A5F0: bne         $t6, $at, L_8078A734
    if (ctx->r14 != ctx->r1) {
        // 0x8078A5F4: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8078A734;
    }
    // 0x8078A5F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8078A5F8: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x8078A5FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8078A600: bnel        $t7, $at, L_8078A738
    if (ctx->r15 != ctx->r1) {
        // 0x8078A604: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_0;
    // 0x8078A604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8078A608: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x8078A60C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8078A610: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x8078A614: beql        $t0, $zero, L_8078A738
    if (ctx->r8 == 0) {
        // 0x8078A618: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_1;
    // 0x8078A618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8078A61C: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8078A620: lwc1        $f6, 0x88($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8078A624: lui         $t2, 0x8079
    ctx->r10 = S32(RELOC_HI16(793, 0XC10) << 16);
    // 0x8078A628: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8078A62C: nop

    // 0x8078A630: bc1fl       L_8078A738
    if (!c1cs) {
        // 0x8078A634: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_2;
    // 0x8078A634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8078A638: lw          $v1, 0x134($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X134);
    // 0x8078A63C: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8078A640: lh          $t3, -0x7682($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X7682);
    // 0x8078A644: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x8078A648: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8078A64C: lh          $t2, -0x51B0($t2)
    ctx->r10 = MEM_H(ctx->r10, (int16_t)RELOC_LO16(793, 0XC10));
    // 0x8078A650: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8078A654: mflo        $t4
    ctx->r12 = lo;
    // 0x8078A658: blezl       $t4, L_8078A738
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8078A65C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_3;
    // 0x8078A65C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8078A660: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8078A664: lw          $t5, 0x12EC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X12EC);
    // 0x8078A668: bnel        $t5, $zero, L_8078A738
    if (ctx->r13 != 0) {
        // 0x8078A66C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_4;
    // 0x8078A66C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8078A670: lbu         $t6, 0xF4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF4);
    // 0x8078A674: bnel        $t6, $zero, L_8078A738
    if (ctx->r14 != 0) {
        // 0x8078A678: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_5;
    // 0x8078A678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8078A67C: lbu         $t7, 0x154($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X154);
    // 0x8078A680: bnel        $t7, $zero, L_8078A738
    if (ctx->r15 != 0) {
        // 0x8078A684: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_6;
    // 0x8078A684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8078A688: lbu         $t8, 0x155($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X155);
    // 0x8078A68C: bnel        $t8, $zero, L_8078A738
    if (ctx->r24 != 0) {
        // 0x8078A690: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_7;
    // 0x8078A690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8078A694: lbu         $t9, 0x1F8($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1F8);
    // 0x8078A698: bnel        $t9, $zero, L_8078A738
    if (ctx->r25 != 0) {
        // 0x8078A69C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078A738;
    }
    goto skip_8;
    // 0x8078A69C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8078A6A0: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078A6A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A6A8: beq         $v1, $zero, L_8078A6CC
    if (ctx->r3 == 0) {
        // 0x8078A6AC: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_8078A6CC;
    }
    // 0x8078A6AC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8078A6B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8078A6B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8078A6B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8078A6BC: jal         0x8002F7AC
    // 0x8078A6C0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_8002F7AC(rdram, ctx);
        goto after_0;
    // 0x8078A6C0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_0:
    // 0x8078A6C4: b           L_8078A6E0
    // 0x8078A6C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8078A6E0;
    // 0x8078A6C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8078A6CC:
    // 0x8078A6CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8078A6D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8078A6D4: jal         0x8002F7AC
    // 0x8078A6D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8002F7AC(rdram, ctx);
        goto after_1;
    // 0x8078A6D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_1:
    // 0x8078A6DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8078A6E0:
    // 0x8078A6E0: jal         0x8078ACF0
    // 0x8078A6E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8078ACF0(rdram, ctx);
        goto after_2;
    // 0x8078A6E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8078A6E8: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8078A6EC: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
    // 0x8078A6F0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDE0) << 16);
    // 0x8078A6F4: lwc1        $f10, -0x4FE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDE0));
    // 0x8078A6F8: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8078A6FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078A700: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8078A704: jal         0x8005FE48
    // 0x8078A708: swc1        $f16, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f16.u32l;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x8078A708: swc1        $f16, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f16.u32l;
    after_3:
    // 0x8078A70C: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x8078A710: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078A714: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8078A718: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8078A71C: addiu       $a0, $zero, 0x22B
    ctx->r4 = ADD32(0, 0X22B);
    // 0x8078A720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8078A724: sb          $zero, 0x74($t3)
    MEM_B(0X74, ctx->r11) = 0;
    // 0x8078A728: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8078A72C: jal         0x80067818
    // 0x8078A730: swc1        $f18, 0x268($t4)
    MEM_W(0X268, ctx->r12) = ctx->f18.u32l;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8078A730: swc1        $f18, 0x268($t4)
    MEM_W(0X268, ctx->r12) = ctx->f18.u32l;
    after_4:
L_8078A734:
    // 0x8078A734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078A738:
    // 0x8078A738: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8078A73C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8078A740: jr          $ra
    // 0x8078A744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8078A744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
